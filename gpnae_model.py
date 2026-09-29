#!/usr/bin/env python3
"""Bit-exact model of gpnae_poly and gpnae_tail, op for op and operand for operand, in the lane's format; built on AriL's fpu.py; the int8 lane (gpnae_poly_int8) on AriL's ipu.py.
fp32's negative sigmoid goes through fp32_down, modelled as fpAdder(P, -1); Task 11 measures whether that holds."""
import os
import sys
from collections import namedtuple

import numpy as np

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "Common", "models"))
import fpu  # noqa: E402
import ipu  # noqa: E402
from ipu import quantize_multiplier  # noqa: E402,F401  TFLite's QuantizeMultiplier, AriL's one copy
from number_formats import suggested_rel_tol  # noqa: E402  GPNAE root, the float regression's tolerance rule

SETS = {1: (0, 8), 2: (9, 6), 3: (16, 8)}  # control word: (ROM base, degree), gpnae_poly's BASE_* and DEG_*
LAMBDA, LA, ONE, TWO, NEG_ONE = 0x3F867D5F, 0x3FE10966, 0x3F800000, 0x40000000, 0xBF800000
FOUR, THREE_HALF, BIG = 0x40800000, 0x40600000, 0x42D00000
CINV = [0x3F800000, 0x3F000000, 0x3E2AAAAB, 0x3D2AAAAB, 0x3C088889, 0x3AB60B61,
        0x39500D01, 0x37D00D01, 0x3638EF1D, 0x3493F27E, 0x32D7322B]  # 1/(k+1)!, gpnae_tail's cinv


def coeff_file(f) -> str:
    return "poly_coeffs.mem" if f.name == "fp32" else f"poly_coeffs_{f.name}.mem"


def read_rom(path: str) -> list:
    return [int(ln.strip(), 2) for ln in open(path) if ln.strip()]


class Lane:
    def __new__(cls, f, rom, *args, **kwargs):
        if cls is Lane and f is INT8:  # the int8 build's lane
            return super().__new__(LaneInt8)
        return super().__new__(cls)

    def __init__(self, f, rom):
        self.f, self.rom = f, rom
        k = lambda v: fpu.from_fp32(v, f.m)
        self.lam, self.la, self.one, self.two, self.neg_one = map(k, (LAMBDA, LA, ONE, TWO, NEG_ONE))
        self.four, self.three_half, self.big = (k(v) & ((1 << (f.w - 1)) - 1) for v in (FOUR, THREE_HALF, BIG))
        self.cinv = [k(v) for v in CINV]
        self.S = 1 << (f.w - 1)
        self.MAG = self.S - 1

    def _mul(self, a, b):
        return fpu.mul(self.f, a, b)[0]

    def _add(self, a, b):
        return fpu.add(self.f, a, b)[0]

    def _e(self, v):
        return (v >> self.f.m) & self.f.emax

    def in_tail(self, x, code) -> bool:
        mag = x & self.MAG
        if code == 1:
            return bool(x & self.S) and mag > self.four
        if code == 2:
            return mag > self.three_half
        if code == 3:
            return mag > self.four
        return False

    def poly(self, x, code, rom=None):
        """Polynomial path for an array of inputs: MAC operand, Horner in the barrel MAC, post stage."""
        rom = self.rom if rom is None else rom
        S, MAG = self.S, self.MAG
        x = np.asarray(x, dtype=np.int64)
        base, deg = SETS[code]
        t = x if code == 1 else (x & MAG) if code == 2 else self._mul(x, x)
        acc = np.zeros_like(x)
        for r in range(deg + 1):  # mul(A=operand, B=acc), then add(A=coefficient, B=product)
            acc = self._add(np.full_like(x, rom[base + deg - r]), self._mul(t, acc))
        pos = ((x & S) == 0) | ((x & MAG) == 0)
        if code == 2:
            return np.where(pos, acc, self._add(acc, np.full_like(x, self.neg_one)) ^ S)
        if code == 1:
            return self._mul(x, np.where(pos, self.lam, acc))
        return self._mul(x, acc)

    def tail(self, x, code) -> int:
        f, S, MAG, E = self.f, self.S, self.MAG, self._e
        mul = lambda a, b: int(self._mul(a, b))
        add = lambda a, b: int(self._add(a, b))
        neg = lambda v: v ^ S
        if code == 1:
            a = x
        elif code == 2:
            a = S | (x & MAG)
        else:
            a = (S | (self.big + 1)) if E(x) >= f.bias + 6 else S | (((E(x) + 1) & f.emax) << f.m) | (x & f.mmask)
        if (a & MAG) > self.big:  # e^a underflows: e^a - 1 = -1, e^a = 0
            d, e = S | self.one, 0
            if code == 1:
                return mul(self.la, d)
        else:
            if E(a) < f.bias:
                z, m = a, 0
            else:
                z, m = (a & S) | ((f.bias - 1) << f.m) | (a & f.mmask), E(a) - (f.bias - 1)
            acc = self.cinv[10]
            for k in range(9, -1, -1):
                acc = add(mul(acc, z), self.cinv[k])
            d = mul(z, acc)
            if code == 1:
                for _ in range(m):
                    d = mul(d, add(d, self.two))
                return mul(self.la, d)
            e = add(self.one, d)
            for _ in range(m):
                if E(e) < (f.bias + 1) // 2:
                    e = 0
                    break
                e = mul(e, e)
        s = mul(e, add(self.one, neg(mul(e, add(self.one, neg(e))))))
        if code == 2:
            return s if (x & S) else add(self.one, neg(s))
        two_s = S if (s & MAG) == 0 else S | (((E(s) + 1) & f.emax) << f.m) | (s & f.mmask)
        return (x & S) | (add(self.one, two_s) & MAG)

    def element(self, x, code) -> int:
        code = code if code in (1, 2, 4, 5) else 3  # gpnae_poly runs tanh for every other control word (is_tanh)
        if code == 4:
            return 0 if (x & self.S) else x  # ReLU: every negative, -0 too, gives +0
        if code == 5:
            return x
        if self.in_tail(x, code):
            return self.tail(x, code)
        return int(self.poly(np.array([x]), code)[0])

    def run(self, x, code):
        """element() over an array: the polynomial path vectorized, tail elements one at a time."""
        x = np.asarray(x, dtype=np.int64)
        code = code if code in (1, 2, 4, 5) else 3
        if code == 4:
            return np.where((x & self.S) != 0, 0, x)
        if code == 5:
            return x.copy()
        out = np.asarray(self.poly(x, code), dtype=np.int64).copy()
        for i in range(x.size):
            v = int(x.flat[i])
            if self.in_tail(v, code):
                out.flat[i] = self.tail(v, code)
        return out


def golden(values, code, fmt):
    """Hardware outputs for FloatFormat values, as floats of the same format."""
    f = fpu.FORMATS[fmt.name]
    lane = Lane(f, read_rom(os.path.join(ROOT, coeff_file(f))))
    out = lane.run(np.array([fmt.encode(v) for v in values], dtype=np.int64), code)
    return [fmt.decode(int(b)) for b in out]


# int8 lane: the float lane's forms on integer units (fxMac Horner in Q4.11, integer products), then int8 quantization.


class Int8Fmt:
    """The int8 build as the lane sees it: 8-bit ports, Q4.11 inside; eps 2^-7 for GPNAE's tolerance rule."""
    name, w, frac, iw, eps = "int8", 8, 11, 16, 2.0 ** -7


INT8 = Int8Fmt()
FORMATS = dict(fpu.FORMATS, int8=INT8)
REL_TOL_INT8 = suggested_rel_tol(INT8)  # max(1%, 8 eps) = 6.25%, bf16's value (L2-4)
ABS_TOL_LSB = 1  # the int8 analog of --abs-tol: one output LSB

Q = 11  # Q4.11
SETS_INT8 = {1: (0, 3), 2: (9, 3), 3: (16, 11)}  # (ROM base, degree) per control word; Task 10's fit sets it
T_SELU, T_SIG, T_TANH = -8192, 7168, 8192  # the float lane's thresholds in Q4.11: SELU x < -4, sigmoid |x| > 3.5, tanh |x| > 4
THRESH = {1: T_SELU, 2: T_SIG, 3: T_TANH}
SELU_SAT, ONE_Q11, LAMBDA_Q14 = -3601, 2048, 17215  # -lambda*alpha and 1.0 in Q4.11, lambda in Q1.14
LAMBDA_F, LA_F = 1.0507009873554805, 1.7580993408473766
Int8Params = namedtuple("Int8Params", "mx shx zin mout shout zout")
Case = namedtuple("Case", "s_in z_in s_out z_out gated")


def rescale(q, zin, mx, s):
    """(q - z_in) * mx rounded half up by 2^s, saturated to Q4.11 (gpnae_poly_int8 rescale())."""
    assert 0 <= mx <= 32767, "gp_mx_i must be below 2^15"
    q = np.asarray(q, dtype=np.int64)
    p = ipu.int_mul(q - zin, np.full_like(q, mx), w=16)
    r = p if s == 0 else (p + (1 << (s - 1))) >> s
    return np.clip(r, -32768, 32767)


def mac_operand(x, code):
    """The float lane's MAC operand in Q4.11: SELU x, sigmoid |x| (saturated), tanh x^2 on an fxMac with C = 0."""
    x = np.asarray(x, dtype=np.int64)
    if code == 1:
        return x
    if code == 2:
        return np.minimum(np.abs(x), 32767)
    return ipu.fx_mac(x, x, np.zeros_like(x), w=16, frac=Q)


def horner(t, rom, base, deg):
    """barrel_mac's int8 rounds: fxMac(A=operand, X=acc, C=coefficient), highest coefficient first, acc from 0."""
    t = np.asarray(t, dtype=np.int64)
    acc = np.zeros_like(t)
    for r in range(deg + 1):
        acc = ipu.fx_mac(t, acc, np.full_like(t, rom[base + deg - r]), w=16, frac=Q)
    return acc


def quant_sig(y):
    """sigmoid output from y in Q4.11: round(256 y) - 128 = ((y + 4) >> 3) - 128, clamped to int8."""
    return np.clip(((np.asarray(y, dtype=np.int64) + 4) >> 3) - 128, -128, 127)


def quant_tanh(p):
    """tanh output from the product x * P in units of 2^-22: round(128 y) = (p + 2^14) >> 15, clamped to int8."""
    return np.clip((np.asarray(p, dtype=np.int64) + (1 << 14)) >> 15, -128, 127)


def rescale_params(s_in):
    """(mx, shx) with mx / 2^shx = s_in * 2^11, the largest shx <= 31 that keeps mx <= 32767."""
    m = s_in * (1 << Q)
    for shx in range(31, -1, -1):
        mx = int(np.floor(m * 2.0 ** shx + 0.5))
        if mx <= 32767:
            return mx, shx
    raise ValueError(f"input scale {s_in} is too large for Q4.11")


def calib_out(y_lo, y_hi):
    """TFLite-style int8 output quantization of [y_lo, y_hi], widened to hold 0."""
    lo, hi = min(y_lo, 0.0), max(y_hi, 0.0)
    s = (hi - lo) / 255.0
    return s, int(np.clip(np.floor(-128 - lo / s + 0.5), -128, 127))


def selu_case(s_in, z_in, gated=True):
    """A SELU case whose output scale is calibrated from the inputs' range, as post-training quantization would."""
    r = s_in * (np.array([-128.0, 127.0]) - z_in)
    y = np.where(r >= 0, LAMBDA_F * r, LA_F * np.expm1(r))
    s_out, z_out = calib_out(float(y[0]), float(y[1]))
    return Case(s_in, z_in, s_out, z_out, gated)


# Scales put the fitted range at 128, 32 and 8 int8 steps (SELU 128, 64, 256); SELU at 7/32 passes Q4.11 and is checked bit-exact only.
INT8_CASES = {
    "tanh": [Case(4.0 / n, z, 1 / 128, 0, True) for n, z in ((128, 0), (32, 0), (8, 0), (32, -37), (64, 100))],
    "sigmoid": [Case(3.5 / n, z, 1 / 256, -128, True) for n, z in ((128, 0), (32, 0), (8, 0), (32, 25), (64, -100))],
    "selu": [selu_case(4 / 128, 0), selu_case(4 / 64, 0), selu_case(4 / 256, 0), selu_case(4 / 128, 120),
             selu_case(7 / 32, 0, gated=False)],
    "relu": [Case(0.05, z, 0.05, z, False) for z in (0, -20, 20, 100, -100)],
    "linear": [Case(0.05, z, 0.05, z, False) for z in (0, -20, 20, 100, -100)],
}


def int8_params(case, code):
    """The lane's per-layer inputs for a case: rescale always, SELU's output requantize for code 1."""
    mx, shx = rescale_params(case.s_in)
    if code == 1:
        mout, shout = quantize_multiplier(2.0 ** -25 / case.s_out)  # the SELU value is in units of 2^-25
        return Int8Params(mx, shx, case.z_in, mout, shout, case.z_out)
    return Int8Params(mx, shx, case.z_in, 0, 0, 0)


def exact_lsb(q, code, case):
    """The exact function at the real input in output LSB, before zero point, rounding and clamp; and the output zero point."""
    q = np.asarray(q, dtype=np.int64)
    r = case.s_in * (q.astype(float) - case.z_in)
    if code == 3:
        return np.tanh(r) / (1 / 128), 0
    if code == 2:
        return (1 / (1 + np.exp(-r))) / (1 / 256), -128
    if code == 1:
        return np.where(r >= 0, LAMBDA_F * r, LA_F * np.expm1(r)) / case.s_out, case.z_out
    return q.astype(float), 0


def exact_int8(q, code, case):
    """The exact function at the real input, quantized with round half up and clamped: the golden the lane is judged against."""
    if code not in (1, 2, 3):
        return np.asarray(q, dtype=np.int64).copy()
    y, z = exact_lsb(q, code, case)
    return np.clip(np.floor(y + 0.5) + z, -128, 127).astype(np.int64)


Acc = namedtuple("Acc", "ok fail worst_rel worst_lsb real_lsb differ")


def accuracy_int8(out, q, code, case):
    """One case against GPNAE's tolerance: d = out - exact_int8 passes if abs(d) <= 1 LSB or abs(d) / abs(golden - z) <= 6.25%."""
    y, z = exact_lsb(q, code, case)
    g = exact_int8(q, code, case)
    out = np.asarray(out, dtype=np.int64)
    d = np.abs(out - g)
    mag = np.abs(g - z)
    rel = np.where(mag > 0, d / np.maximum(mag, 1), np.where(d > 0, np.inf, 0.0))  # a zero golden: the absolute bound only, as TB_gpnae_poly
    ok = (d <= ABS_TOL_LSB) | (rel <= REL_TOL_INT8)
    far = rel[d > ABS_TOL_LSB]  # the outputs where the relative bound decides
    return Acc(bool(ok.all()), int((~ok).sum()), float(far.max()) if far.size else 0.0, int(d.max()),
               float(np.abs(out - z - y).max()), int((d > 0).sum()))


def merge_acc(accs):
    """Several cases' Acc as one: every output within the tolerance, counts summed, worst values the maximum."""
    a = list(accs)
    return Acc(all(x.ok for x in a), sum(x.fail for x in a), max(x.worst_rel for x in a), max(x.worst_lsb for x in a),
               max(x.real_lsb for x in a), sum(x.differ for x in a))


class LaneInt8(Lane):
    """Bit-exact model of gpnae_poly_int8."""

    def __init__(self, f, rom, sets=None, thresh=None):
        self.f = f
        self.rom = [v - (1 << 16) if v >= (1 << 15) else v for v in rom]
        self.sets = {**SETS_INT8, **(sets or {})}
        self.thresh = {**THRESH, **(thresh or {})}

    def poly(self, x, code):
        """P at the float lane's MAC operand."""
        base, deg = self.sets[code]
        return horner(mac_operand(x, code), self.rom, base, deg)

    def value(self, x, code):
        """The unsaturated path as a real number before quantizing: x * P for SELU (x < 0) and tanh; P or 1 - P for sigmoid."""
        x = np.asarray(x, dtype=np.int64)
        p = self.poly(x, code)
        if code == 2:
            return np.where(x < 0, ONE_Q11 - p, p) / 2048.0
        return ipu.int_mul(x, p, w=16) * 2.0 ** -22

    def run(self, q, code, par):
        q = np.asarray(q, dtype=np.int64)
        code = code if code in (1, 2, 4, 5) else 3  # every other control word runs tanh, as in the float lane
        if code in (4, 5):
            return q.copy()  # ReLU and linear pass through: the requantize clamp applied them
        x = rescale(q, par.zin, par.mx, par.shx)
        neg = x < 0
        p = self.poly(x, code)
        if code == 2:
            sat = np.abs(x) > self.thresh[2]
            return np.where(sat, np.where(neg, -128, 127), quant_sig(np.where(neg, ONE_Q11 - p, p)))
        if code == 3:
            sat = np.abs(x) > self.thresh[3]
            return np.where(sat, np.where(neg, -128, 127), quant_tanh(ipu.int_mul(x, p, w=16)))
        sat = x < self.thresh[1]
        a = np.where(sat, SELU_SAT, x)
        b = np.where(neg, np.where(sat, ONE_Q11, p), LAMBDA_Q14)
        prod = ipu.int_mul(a, b, w=16)
        v = np.where(neg, prod << 3, prod)  # x * P and -lambda*alpha * 1.0 are in 2^-22, x * lambda in 2^-25
        full = lambda c: np.full_like(v, c)
        return ipu.requant(v, full(par.mout), full(par.shout), full(par.zout), full(-128), full(127), ipu.REQ_ROUNDING)

    def element(self, q, code, par) -> int:
        return int(self.run(np.array([q]), code, par)[0])
