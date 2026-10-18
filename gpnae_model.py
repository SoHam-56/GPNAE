#!/usr/bin/env python3
"""Bit-exact model of gpnae_poly and gpnae_tail, op for op and operand for operand, in the lane's format; built on AriL's fpu.py; the int8 lane (gpnae_poly_int8) on AriL's ipu.py.
fp32's negative sigmoid goes through fp32_down, modelled stage for stage (fp32_down below): it truncates the aligned operand, unlike fpAdder.
bf16's tail runs in fp32 (x widened, the result narrowed to nearest) and takes every sigmoid x < 0, with NEWTON_BF16 Newton steps for 1/(1 + E)."""
import os
import sys
from collections import namedtuple

import numpy as np

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "Common", "models"))
import fpu  # noqa: E402
import ipu  # noqa: E402
from number_formats import suggested_rel_tol  # noqa: E402  GPNAE root, the float regression's tolerance rule

SETS = {1: (0, 8), 2: (9, 6), 3: (16, 8)}  # control word: (ROM base, degree), gpnae_poly's BASE_* and DEG_*
LAMBDA, LA, ONE, TWO, NEG_ONE = 0x3F867D5F, 0x3FE10966, 0x3F800000, 0x40000000, 0xBF800000
LAMBDA_NARROW = 0x3F870000  # bf16's lambda 1.0546875, rounded up (nearest is 0x3F86): its multiplier truncates, and 0x3F86 x 0x7F73 gave 0x7F7E, below bf16's max, where lambda x lies above the max
TANH_TINY = {23: 0x39B89BA3, 7: 0x3DB90000}  # the first |x| where tanh(x) does not round to x (fp32 3.5211e-4, bf16 0.0903); below it the lane returns x
FOUR, THREE_HALF, BIG = 0x40800000, 0x40600000, 0x42D00000
NEWTON_Y0, NEWTON_BF16 = 0x3FC00000, 2  # 1.5, the Newton seed's constant; gpnae_poly's bf16 branch sets gpnae_tail's NEWTON to NEWTON_BF16
CINV = [0x3F800000, 0x3F000000, 0x3E2AAAAB, 0x3D2AAAAB, 0x3C088889, 0x3AB60B61,
        0x39500D01, 0x37D00D01, 0x3638EF1D, 0x3493F27E, 0x32D7322B]  # 1/(k+1)!, gpnae_tail's cinv


def coeff_file(f) -> str:
    return "poly_coeffs.mem" if f.name == "fp32" else f"poly_coeffs_{f.name}.mem"


def read_rom(path: str) -> list:
    return [int(ln.strip(), 2) for ln in open(path) if ln.strip()]


def fp32_down(a):
    """fp32_down.sv, A + (-1.0) for fp32 bit patterns: the smaller operand is shifted right and truncated (no guard bits), then exact add or subtract and normalize."""
    a = np.asarray(a, dtype=np.int64)
    s, e, m = (a >> 31) & 1, (a >> 23) & 0xFF, a & 0x7FFFFF
    comp, mag, zero = e > 127, (e == 127) & (m > 0), (e == 0) & (m == 0)  # C = -1.0: exponent 127, mantissa 0
    sign = np.where(comp | mag, s, np.where(zero, 0, 1))
    bexp = np.where(zero, 0, np.where(comp, e, 127))
    sexp = np.where(zero, 0, np.where(comp, 127, e))
    bman = np.where(zero, 0, (1 << 23) | np.where(comp | mag, m, 0))
    sman = np.where(zero, 0, (1 << 23) | np.where(comp | mag, 0, m))
    d = (bexp - sexp) & 0xFF
    tot = np.where(s == 0, bman - (sman >> np.minimum(d, 24)), bman + (sman >> np.minimum(d, 24))) & 0x1FFFFFF  # {carry, TempMan}
    carry, tm = (tot >> 24) & 1, tot & 0xFFFFFF
    zc = np.where(tm == 0, 24, 24 - np.frexp(tm.astype(np.float64))[1]).astype(np.int64)  # cntlz24
    lo = tm & 0x7FFFFF
    conds = [carry == 1, lo != 0, tm == 0]
    man = np.select(conds, [(tm >> 1) & 0x7FFFFF, (lo << np.minimum(zc, 23)) & 0x7FFFFF, 0], default=lo)
    exp = np.select(conds, [(bexp + 1) & 0xFF, (bexp - zc) & 0xFF, 0], default=bexp)
    return (np.where((carry == 0) & (tm == 0), 0, sign) << 31) | (exp << 23) | man


class Lane:
    def __new__(cls, f, rom, *args, **kwargs):
        if cls is Lane and f is INT8:  # the int8 build's lane
            return super().__new__(LaneInt8)
        return super().__new__(cls)

    def __init__(self, f, rom, newton=None, neg_tail=None, tiny=True, lam=None):
        """newton: gpnae_tail's NEWTON (default NEWTON_BF16 in bf16, 0 in fp32); a bf16 lane with newton > 0 runs its tail in fp32; neg_tail sends every sigmoid x < 0 to it; tiny=False: tanh x * P at every |x|, and lam: SELU's lambda as fp32 bits, as before Task 1.16."""
        self.f, self.rom = f, rom
        self.newton = (NEWTON_BF16 if f.w < 32 else 0) if newton is None else newton
        self.wide = f.w < 32 and self.newton > 0  # gpnae_poly's bf16 branch: gpnae_tail in fp32, x widened, the result narrowed to nearest
        self.neg_tail = self.wide if neg_tail is None else neg_tail
        self.t32 = Lane(fpu.FP32, rom, newton=self.newton) if self.wide else None
        k = lambda v: fpu.from_fp32(v, f.m)
        self.lam, self.la, self.one, self.two, self.neg_one, self.y0 = map(k, ((LAMBDA if f.w == 32 else LAMBDA_NARROW) if lam is None else lam, LA, ONE, TWO, NEG_ONE, NEWTON_Y0))
        self.tiny = k(TANH_TINY[f.m]) if tiny else 0  # gpnae_poly's T_TINY: tanh's post multiply takes 1.0 in place of P below it
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

    def in_tail(self, x, code):
        """gpnae_poly's sig_in_tail, for an int (a bool back) or an array."""
        x = np.asarray(x, dtype=np.int64)
        mag, neg = x & self.MAG, (x & self.S) != 0
        if code == 1:
            r = neg & (mag > self.four)
        elif code == 2:
            r = (mag > self.three_half) | (self.neg_tail & neg & (mag != 0))
        elif code == 3:
            r = mag > self.four
        else:
            r = np.zeros(x.shape, dtype=bool)
        return bool(r) if r.ndim == 0 else r

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
            down = fp32_down(acc) if (self.f.e, self.f.m) == (8, 23) else self._add(acc, np.full_like(x, self.neg_one))  # gpnae_poly's POSTD
            return np.where(pos, acc, down ^ S)
        if code == 1:
            return self._mul(x, np.where(pos, self.lam, acc))
        return self._mul(x, np.where((x & MAG) < self.tiny, self.one, acc))  # tanh: x * 1.0 = x where tanh(x) rounds to x

    def newton_s(self, e):
        """gpnae_tail's T_ND..T_NS: s = E y with y -> 1/D, D = 1 + E, from y = 1.5 - D/2 (an exponent decrement, D >= 1), each step y = y (2 - D y)."""
        e = np.asarray(e, dtype=np.int64)
        full = lambda c: np.full_like(e, c)
        d = self._add(full(self.one), e)
        y = self._add(full(self.y0), (d - (1 << self.f.m)) ^ self.S)
        for _ in range(self.newton):
            y = self._mul(y, self._add(full(self.two), self._mul(d, y) ^ self.S))
        return self._mul(e, y)

    def tail(self, x, code) -> int:
        if self.wide:
            return int(fpu.narrow(self.f, self.t32.tail(int(fpu.widen(self.f, x)), code)))
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
        if code == 2 and self.newton and (x & S):
            return int(self.newton_s(e))
        s = mul(e, add(self.one, neg(mul(e, add(self.one, neg(e))))))
        if code == 2:
            return s if (x & S) else add(self.one, neg(s))
        two_s = S if (s & MAG) == 0 else S | (((E(s) + 1) & f.emax) << f.m) | (s & f.mmask)
        return (x & S) | (add(self.one, two_s) & MAG)

    def tail_v(self, x, code):
        """tail() over an array, op for op."""
        x = np.asarray(x, dtype=np.int64)
        if self.wide:
            return fpu.narrow(self.f, self.t32.tail_v(fpu.widen(self.f, x), code))
        f, S, MAG, E = self.f, self.S, self.MAG, self._e
        full = lambda c: np.full_like(x, c)
        if code == 1:
            a = x
        elif code == 2:
            a = S | (x & MAG)
        else:
            a = np.where(E(x) >= f.bias + 6, S | (self.big + 1), S | (((E(x) + 1) & f.emax) << f.m) | (x & f.mmask))
        under = (a & MAG) > self.big
        small = E(a) < f.bias
        z = np.where(small, a, (a & S) | ((f.bias - 1) << f.m) | (a & f.mmask))
        m = np.where(small | under, 0, E(a) - (f.bias - 1))
        acc = full(self.cinv[10])
        for k in range(9, -1, -1):
            acc = self._add(self._mul(acc, z), full(self.cinv[k]))
        d = self._mul(z, acc)
        if code == 1:
            for i in range(int(m.max(initial=0))):
                d = np.where(i < m, self._mul(d, self._add(d, full(self.two))), d)
            return self._mul(full(self.la), np.where(under, S | self.one, d))
        e = self._add(full(self.one), d)
        zeroed = np.zeros(x.shape, dtype=bool)
        for i in range(int(m.max(initial=0))):
            act = (i < m) & ~zeroed
            low = act & (E(e) < (f.bias + 1) // 2)  # E^2 would fall below the normal range: 0, and the squarings stop
            zeroed |= low
            e = np.where(low, 0, np.where(act, self._mul(e, e), e))
        e = np.where(under, 0, e)
        s = self._mul(e, self._add(full(self.one), self._mul(e, self._add(full(self.one), e ^ S)) ^ S))
        neg = (x & S) != 0
        if code == 2:
            out = np.where(neg, s, self._add(full(self.one), s ^ S))
            return np.where(neg, self.newton_s(e), out) if self.newton else out
        two_s = np.where((s & MAG) == 0, S, S | (((E(s) + 1) & f.emax) << f.m) | (s & f.mmask))
        return (x & S) | (self._add(full(self.one), two_s) & MAG)

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
        """element() over an array: the polynomial path and the tail (tail_v) vectorized."""
        x = np.asarray(x, dtype=np.int64)
        code = code if code in (1, 2, 4, 5) else 3
        if code == 4:
            return np.where((x & self.S) != 0, 0, x)
        if code == 5:
            return x.copy()
        out = np.asarray(self.poly(x, code), dtype=np.int64).copy()
        t = np.asarray(self.in_tail(x, code), dtype=bool)
        if t.any():
            out[t] = self.tail_v(x[t], code)
        return out


def golden(values, code, fmt):
    """Hardware outputs for FloatFormat values, as floats of the same format."""
    f = fpu.FORMATS[fmt.name]
    lane = Lane(f, read_rom(os.path.join(ROOT, coeff_file(f))))
    out = lane.run(np.array([fmt.encode(v) for v in values], dtype=np.int64), code)
    return [fmt.decode(int(b)) for b in out]


# bf16 sigmoid gate (spec Decision 5): every finite input, relative error <= 1% where sigmoid >= 2^-126, |out| <= 2^-126 below.
MIN_NORMAL = 2.0 ** -126
SIG_BOUND = 0.01
Gate = namedtuple("Gate", "ok worst at over flush n n_sub worst_sub")


def finite_inputs(f):
    """Every finite bit pattern of an 8-exponent-bit format: normals, zeros and subnormals."""
    b = np.arange(1 << f.w, dtype=np.int64)
    return b[((b >> f.m) & f.emax) != f.emax]


def to_float(f, b):
    """Bit patterns of an 8-exponent-bit format as float64, exactly."""
    return (fpu.widen(f, b) & 0xFFFFFFFF).astype(np.uint32).view(np.float32).astype(np.float64)


def sigmoid_gate(f, x, out, bound=SIG_BOUND):
    """The gate on sigmoid outputs: the reference is float64 sigmoid of x as the units read it (a subnormal reads as zero)."""
    x = np.asarray(x, dtype=np.int64)
    sub = (((x >> f.m) & f.emax) == 0) & ((x & ((1 << (f.w - 1)) - 1)) != 0)
    v = np.where(sub, 0.0, to_float(f, x))
    a = np.exp(-np.abs(v))
    ref = np.where(v >= 0, 1 / (1 + a), a / (1 + a))
    got = to_float(f, out)
    big = ref >= MIN_NORMAL
    rel = np.where(np.isfinite(got), np.where(big, np.abs(got - ref) / np.where(big, ref, 1.0), 0.0), np.inf)  # a NaN or infinite word is over
    flush = ~big & ~(np.abs(got) <= MIN_NORMAL)  # NaN fails this too
    i = int(np.argmax(rel))
    over = int((rel > bound).sum())
    return Gate(over == 0 and not flush.any(), float(rel[i]), float(v[i]), over, int(flush.sum()), int(x.size), int(sub.sum()),
                float(rel[sub].max(initial=0.0)))


# int8 lane: the float lane's forms on integer units (fxMac Horner in Q4.11, integer products), then int8 quantization.


class Int8Fmt:
    """The int8 build as the lane sees it: 8-bit ports, Q4.11 inside; eps 2^-7 for GPNAE's tolerance rule."""
    name, w, frac, iw, eps = "int8", 8, 11, 16, 2.0 ** -7


INT8 = Int8Fmt()
FORMATS = dict(fpu.FORMATS, int8=INT8)
REL_TOL_INT8 = suggested_rel_tol(INT8)  # max(1%, 8 eps) = 6.25%, bf16's value (L2-4)
ABS_TOL_LSB = 1  # the int8 analog of --abs-tol: one output LSB

Q = 11  # Q4.11
SETS_INT8 = {1: (0, 2), 2: (9, 3), 3: (16, 3)}  # (ROM base, degree) per control word; Task 10's fit sets it
T_SELU, T_SIG, T_TANH = -8192, 7168, 8192  # the float lane's thresholds in Q4.11: SELU x < -4, sigmoid |x| > 3.5, tanh |x| > 4
THRESH = {1: T_SELU, 2: T_SIG, 3: T_TANH}
SIG_LAD_X0 = 5120  # sigmoid from |x| >= 2.5 (Q4.11) is the exact ladder below, not the polynomial
SIG_LAD_T = (5228, 5350, 5479, 5616, 5761, 5916, 6082, 6261, 6456, 6669, 6905, 7170, 7471, 7821, 8240, 8763, 9460, 10515,
             12773)  # where round(256 sigmoid(-|x|)) steps; fit_poly_coeffs.sig_ladder_thresholds() derives them
SELU_SAT, ONE_Q11, LAMBDA_Q14 = -3601, 2048, 17215  # -lambda*alpha and 1.0 in Q4.11, lambda in Q1.14
XW = 24  # gpnae_poly_int8's post multiplier: |q - z_in| <= 255 and mx < 2^15 keep the rescale product r = (q - z_in) * mx below 2^23
SELU_SH_LAMBDA, SELU_SH_P = 7, 4  # SELU's accumulator in 2^-(shx + 18): r * lambda (2^-(shx + 25)) >>> 7; r * P and the x < -4 constant (2^-(shx + 22)) >>> 4
LAMBDA_F, LA_F = 1.0507009873554805, 1.7580993408473766


Int8Params = namedtuple("Int8Params", "mx shx zin mout shout zout")
Case = namedtuple("Case", "s_in z_in s_out z_out gated")


def rescale_product(q, zin, mx):
    """The rescale's exact product r = (q - z_in) * mx (gpnae_poly_int8's rm_res): x in units of 2^-(shx + 11), |r| < 2^23."""
    assert 0 <= mx <= 32767, "gp_mx_i must be below 2^15"
    q = np.asarray(q, dtype=np.int64)
    return ipu.int_mul(q - zin, np.full_like(q, mx), w=16)


def rescale(q, zin, mx, s):
    """(q - z_in) * mx rounded half up by 2^s, saturated to Q4.11 (gpnae_poly_int8 rescale())."""
    p = rescale_product(q, zin, mx)
    return np.clip(p if s == 0 else (p + (1 << (s - 1))) >> s, -32768, 32767)


def selu_acc(q, zin, mx, shx, p):
    """SELU's int32 accumulator in 2^-(shx + 18), x block-floating: r * lambda (r >= 0), r * P (x >= -4), -lambda*alpha 2^shx * 1.0 (x < -4); the sign is r's."""
    r = rescale_product(q, zin, mx)
    sat = rescale(q, zin, mx, shx) < T_SELU  # x < -4 needs |r| > 2^(shx + 13), so shx <= 9 there and SELU_SAT << shx fits 24 bits
    pm_a = np.where(sat, ipu.sx(np.int64(SELU_SAT) << shx, XW), r)
    pm_b = np.where(r >= 0, LAMBDA_Q14, np.where(sat, ONE_Q11, p))
    pm = ipu.int_mul(pm_a, pm_b, w=XW)
    return ipu.sx(np.where(r >= 0, pm >> SELU_SH_LAMBDA, pm >> SELU_SH_P), 32)  # pm_res[38:7] and [35:4]; |acc| < 2^31 for |q - z_in| <= 255, mx < 2^15


def selu_out_params(s_in, mx, s_out):
    """SELU's (mout, shout): the output code is acc s_in / (2^7 mx s_out), that scale as ipu.encode_scale's 24-bit mantissa and right shift."""
    if mx == 0:
        return 0, ipu.REQ_MAX_SHIFT  # s_in below 2^-43: every r is 0 and every output z_out (the flush code)
    return ipu.encode_scale(s_in / (2.0 ** SELU_SH_LAMBDA * mx * s_out))


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


def sig_ladder(x, t=SIG_LAD_T):
    """sigmoid for |x| >= SIG_LAD_X0: k = len(t) - #{t_i <= |x|} = round(256 sigmoid(-|x|)); k - 128 for x < 0, min(127, 128 - k) for x > 0."""
    x = np.asarray(x, dtype=np.int64)
    ax = np.minimum(np.abs(x), 32767)
    k = len(t) - (ax[..., None] >= np.asarray(t, dtype=np.int64)).sum(axis=-1)
    return np.where(x < 0, k - 128, np.minimum(127, 128 - k))


def rescale_params(s_in):
    """(mx, shx) with mx / 2^shx = s_in * 2^11, the largest shx <= 31 that keeps mx <= 32767."""
    m = s_in * (1 << Q)
    for shx in range(31, -1, -1):
        mx = int(np.floor(m * 2.0 ** shx + 0.5))
        if mx <= 32767:
            return mx, shx
    raise ValueError(f"input scale {s_in} is too large for Q4.11")


def calib_out(y_lo, y_hi):
    """Asymmetric min/max int8 output quantization of [y_lo, y_hi], widened to hold 0."""
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
        mout, shout = selu_out_params(case.s_in, mx, case.s_out)  # the SELU accumulator is in units of 2^-(shx + 18)
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
        return np.where(r >= 0, LAMBDA_F * r, LA_F * np.expm1(np.minimum(r, 0))) / case.s_out, case.z_out
    return q.astype(float), 0


def exact_int8(q, code, case):
    """The exact function at the real input, quantized with round half up and clamped: the golden the lane is judged against."""
    if code not in (1, 2, 3):
        return np.asarray(q, dtype=np.int64).copy()
    y, z = exact_lsb(q, code, case)
    return np.clip(np.floor(y + 0.5) + z, -128, 127).astype(np.int64)


Acc = namedtuple("Acc", "ok fail worst_rel worst_lsb real_lsb differ")


def accuracy_int8(out, q, code, case):
    """One case on the decimal rule at GPNAE's tolerance: the decoded output within max(REL_TOL_INT8 |t|, one step) of t, the exact
    value clamped to the output range (in steps: |out - tc| <= max(REL_TOL_INT8 |tc - z|, 1)); worst_lsb is the codes off round(t)."""
    y, z = exact_lsb(q, code, case)
    g = exact_int8(q, code, case)
    out = np.asarray(out, dtype=np.int64)
    tc = np.clip(y + z, -128, 127)
    d = np.abs(out - tc)
    mag = np.abs(tc - z)
    rel = np.where(mag > 0, d / np.where(mag > 0, mag, 1.0), np.where(d > 0, np.inf, 0.0))
    ok = d <= np.maximum(REL_TOL_INT8 * mag, ABS_TOL_LSB)
    far = rel[d > ABS_TOL_LSB]  # the outputs past one step, where the relative bound decides
    return Acc(bool(ok.all()), int((~ok).sum()), float(far.max()) if far.size else 0.0, int(np.abs(out - g).max()),
               float(np.abs(out - z - y).max()), int((out != g).sum()))


def merge_acc(accs):
    """Several cases' Acc as one: every output within the tolerance, counts summed, worst values the maximum."""
    a = list(accs)
    return Acc(all(x.ok for x in a), sum(x.fail for x in a), max(x.worst_rel for x in a), max(x.worst_lsb for x in a),
               max(x.real_lsb for x in a), sum(x.differ for x in a))


class LaneInt8(Lane):
    """Bit-exact model of gpnae_poly_int8; ladder=False is the 2a lane (sigmoid saturated past 3.5), which fit_poly_coeffs scores tables on."""

    def __init__(self, f, rom, sets=None, thresh=None, ladder=True, lad_x0=SIG_LAD_X0):
        assert lad_x0 >= SIG_LAD_X0, "the ladder's thresholds start at x = 2.5"
        self.f = f
        self.rom = [v - (1 << 16) if v >= (1 << 15) else v for v in rom]
        self.sets = {**SETS_INT8, **(sets or {})}
        self.thresh = {**THRESH, **(thresh or {})}
        self.ladder, self.lad_x0 = ladder, lad_x0

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
        if code == 4:
            return np.maximum(q, par.zin)  # ReLU: max(q, z_in), the input's zero point being its real 0
        if code == 5:
            return q.copy()
        x = rescale(q, par.zin, par.mx, par.shx)
        neg = x < 0
        p = self.poly(x, code)
        if code == 2:
            y = quant_sig(np.where(neg, ONE_Q11 - p, p))
            if self.ladder:  # |x| >= 2.5: the exact ladder, gpnae_poly_int8's sat_buf for sigmoid; thresh[2] is ignored here
                return np.where(np.abs(x) >= self.lad_x0, sig_ladder(x), y)
            sat = np.abs(x) > self.thresh[2]
            return np.where(sat, np.where(neg, -128, 127), y)
        if code == 3:
            sat = np.abs(x) > self.thresh[3]
            return np.where(sat, np.where(neg, -128, 127), quant_tanh(ipu.int_mul(x, p, w=16)))
        assert self.thresh[1] == T_SELU, "SELU: the x < -4 constant is placed for T_SELU"
        v = selu_acc(q, par.zin, par.mx, par.shx, p)
        full = lambda c: np.full_like(v, c)
        return ipu.requantize(v, full(par.mout), full(par.shout), full(par.zout), full(-128), full(127))

    def element(self, q, code, par) -> int:
        return int(self.run(np.array([q]), code, par)[0])
