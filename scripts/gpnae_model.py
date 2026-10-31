#!/usr/bin/env python3
"""Bit-exact model of the gpnae lane (src/lane/gpnae.sv), element for element: the region each input falls in (the coefficient memory's
descriptors for the activation and tier), the operand, Horner on the barrel MAC with the region's coefficient set, the post stage;
bf16's fp32 tail for negative sigmoid past its Q set; int8 in Q4.11 on fixedPointMultiplyAdd. Built on AriL's fpu.py and ipu.py.
The coefficient memory's reset default is gpnae_coef_default.json, which fit_poly_coeffs.py writes with the RTL's literal tables."""
import json
import os
import sys
from collections import namedtuple
from dataclasses import dataclass, field

import numpy as np

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))  # the GPNAE repository
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "models"))
import fpu  # noqa: E402
import ipu  # noqa: E402

DEFAULT_JSON = os.path.join(ROOT, "scripts", "gpnae_coef_default.json")

# Control words, as SIENNA drives them: 001 SELU, 010 sigmoid, 100 ReLU, 101 linear; every other word runs tanh.
SELU, SIGMOID, TANH, RELU, LINEAR = 1, 2, 3, 4, 5
NAME = {SELU: "selu", SIGMOID: "sigmoid", TANH: "tanh", RELU: "relu", LINEAR: "linear"}

# The memory: per tier four descriptors (SELU's x < 0 side, sigmoid x >= 0, sigmoid x < 0, tanh), each up to PMAX pieces by |x|.
NUM_TIERS, NUM_DESC, PMAX, COEF_WORDS, TAIL_MAXC = 3, 4, 6, 128, 6
D_SELU, D_SIGP, D_SIGN, D_TANH = 0, 1, 2, 3
TIER_TOL = (0.01, 0.05, 0.10)  # each tier's tolerance; its gate holds every input to it

# Load path word addresses (coef_addr_i, 9 bits; data 32 bits): coefficient words, descriptor fields, bf16's tail sets.
ADDR_W = 9
A_DESC, DESC_STRIDE = COEF_WORDS, 16
A_TAIL, TAIL_STRIDE = COEF_WORDS + NUM_TIERS * NUM_DESC * DESC_STRIDE, 8
F_SET, F_EXP, F_CENTER, F_FRAC = PMAX, PMAX + 1, PMAX + 2, PMAX + 3  # descriptor field words after the PMAX bounds
T_CTRL = TAIL_MAXC  # tail set word after its coefficients: {newton[5:4], degree[2:0]}
IMAGE_END = 0xC0EF1A5E  # the word after Mem.contents() in an image file, so a bench can tell a short file

# Element kinds, the post stage's cases (gpnae_act_in.sv's kind_o).
K_LIN, K_MUL, K_ONE, K_PASS, K_REFL, K_SAT, K_EXP, K_TAIL = range(8)

# fp32 constants (bf16 takes them rounded to nearest, as sienna_fmt_pkg::from_fp32 does).
LAMBDA, NEG_LA, ONE, NEG_ONE, TWO, Y0, LOG2E = 0x3F867D5F, 0xBFE10966, 0x3F800000, 0xBF800000, 0x40000000, 0x3FC00000, 0x3FB8AA3B
LAMBDA_BF16 = 0x3F87  # bf16's lambda rounded up: its multiplier truncates, and 0x3F86 x 0x7F73 gave 0x7F7E, below bf16's max
TANH_TINY = {23: 0x39B89BA3, 7: 0x3DB9}  # below this |x|, tanh(x) rounds to x: the lane multiplies x by 1.0
LAMBDA_F, LA_F = 1.0507009873554805, 1.7580993408473766


@dataclass
class Desc:
    """One descriptor: piece p at base + p (deg + 1) for bound[p - 1] <= |x| < bound[p]; past bound[np - 1], the region beyond."""
    bounds: list = field(default_factory=lambda: [0] * PMAX)  # words of the lane's format (floats: magnitude bits compared)
    np: int = 1
    deg: int = 0
    base: int = 0
    reflect: int = 0  # sigmoid x < 0: the pieces give 1 - P instead of P
    exp_base: int = 0  # fp32 sigmoid x < 0 past the pieces: 2^-n P(f) on the barrel MAC with this set
    exp_deg: int = 0
    center: int = 0  # int8: the operand is x - center (SELU) or |x| - center, in Q4.11
    frac: int = 0  # int8: fixedPointMultiplyAdd shifts by 11 + frac

    def set_word(self):
        return (self.np & 7) | ((self.deg & 15) << 4) | ((self.base & 127) << 8) | ((self.reflect & 1) << 16)

    def exp_word(self):
        return (self.exp_base & 127) | ((self.exp_deg & 15) << 8)


@dataclass
class Tail:
    """bf16's fp32 tail set per tier: P(f) ~ 2^-f of degree deg (fp32 words, lowest first), and its reciprocal's Newton steps."""
    deg: int = 0
    newton: int = 0
    coef: list = field(default_factory=lambda: [0] * TAIL_MAXC)


class Mem:
    """The coefficient memory as the host loads it: words, descriptors per tier and the tail sets; load() is the RTL's write decode."""

    def __init__(self, fmt):
        self.fmt = fmt
        self.words = [0] * COEF_WORDS
        self.desc = [[Desc() for _ in range(NUM_DESC)] for _ in range(NUM_TIERS)]
        self.tail = [Tail() for _ in range(NUM_TIERS)]
        self.meta = {}

    @property
    def act_w(self):
        return 32 if self.fmt == "fp32" else 16

    def load(self, addr, data):
        """One load-path write: what the RTL keeps of a 32-bit word at a 9-bit address; an address past the map is ignored."""
        m = (1 << self.act_w) - 1
        if addr < A_DESC:
            self.words[addr] = data & m
        elif addr < A_TAIL:
            i, j = divmod(addr - A_DESC, DESC_STRIDE)
            d = self.desc[i // NUM_DESC][i % NUM_DESC]
            if j < PMAX:
                d.bounds[j] = data & m
            elif j == F_SET:
                d.np, d.deg, d.base, d.reflect = data & 7, (data >> 4) & 15, (data >> 8) & 127, (data >> 16) & 1
            elif j == F_EXP:
                d.exp_base, d.exp_deg = data & 127, (data >> 8) & 15
            elif j == F_CENTER:
                d.center = data & m
            elif j == F_FRAC:
                d.frac = data & 3
        elif addr < A_TAIL + NUM_TIERS * TAIL_STRIDE:
            t, j = divmod(addr - A_TAIL, TAIL_STRIDE)
            if j < TAIL_MAXC:
                self.tail[t].coef[j] = data & 0xFFFFFFFF
            elif j == T_CTRL:
                self.tail[t].deg, self.tail[t].newton = data & 7, (data >> 4) & 3

    def writes(self):
        """The whole image as load-path writes (address, data), in address order."""
        out = list(enumerate(self.words))
        for t in range(NUM_TIERS):
            for d in range(NUM_DESC):
                ds, b = self.desc[t][d], A_DESC + DESC_STRIDE * (t * NUM_DESC + d)
                out += [(b + j, ds.bounds[j]) for j in range(PMAX)]
                out += [(b + F_SET, ds.set_word()), (b + F_EXP, ds.exp_word()), (b + F_CENTER, ds.center), (b + F_FRAC, ds.frac)]
        for t in range(NUM_TIERS):
            b, ts = A_TAIL + TAIL_STRIDE * t, self.tail[t]
            out += [(b + j, ts.coef[j]) for j in range(TAIL_MAXC)] + [(b + T_CTRL, ts.deg | (ts.newton << 4))]
        return out

    def contents(self):
        """The memory field by field, the order the benches' image check reads: words, per descriptor its fields, per tier its tail set."""
        out = list(self.words)
        for row in self.desc:
            for d in row:
                out += list(d.bounds) + [d.np, d.deg, d.base, d.reflect, d.exp_base, d.exp_deg, d.center, d.frac]
        for t in self.tail:
            out += list(t.coef) + [t.deg, t.newton]
        return out

    def write_contents(self, path):
        """contents() as a $readmemh file, one 32-bit word a line, then the end word the benches look for."""
        with open(path, "w") as fh:
            fh.write("".join(f"{v & 0xFFFFFFFF:08x}\n" for v in self.contents() + [IMAGE_END]))

    def to_dict(self):
        return {"fmt": self.fmt, "words": list(self.words), "desc": [[dict(vars(d)) for d in row] for row in self.desc],
                "tail": [dict(vars(t)) for t in self.tail], "meta": self.meta}

    @classmethod
    def from_dict(cls, js):
        m = cls(js["fmt"])
        conv = lambda v: [int(u) for u in v] if isinstance(v, list) else int(v)
        m.words = [int(v) for v in js["words"]]
        m.desc = [[Desc(**{k: conv(v) for k, v in d.items()}) for d in row] for row in js["desc"]]
        m.tail = [Tail(**{k: conv(v) for k, v in t.items()}) for t in js["tail"]]
        m.meta = js.get("meta", {})
        return m

    def copy(self):
        return Mem.from_dict(json.loads(json.dumps(self.to_dict())))


_DEFAULTS = {}


def default_mem(fmt: str) -> Mem:
    """The reset default of a format's coefficient memory, as fit_poly_coeffs.py wrote it (a copy: callers may load it)."""
    if fmt not in _DEFAULTS:
        with open(DEFAULT_JSON) as fh:
            _DEFAULTS.update({k: Mem.from_dict(v) for k, v in json.load(fh).items()})
    return _DEFAULTS[fmt].copy()


def desc_index(code, neg):
    """The descriptor an element of control word code uses: SELU, sigmoid by its sign, tanh."""
    if code == SELU:
        return np.full(np.shape(neg), D_SELU)
    if code == SIGMOID:
        return np.where(neg, D_SIGN, D_SIGP)
    return np.full(np.shape(neg), D_TANH)


def regions(mem, tier, code, mag, neg):
    """Per element: the piece's (base, degree), whether |x| is past the last bound, and its descriptor's reflect, exp set, center, frac."""
    dsel = desc_index(code, neg)
    mask = 0x7FFF if mem.fmt == "int8" else (1 << (mem.act_w - 1)) - 1
    z = lambda: np.zeros(mag.shape, dtype=np.int64)
    beyond = np.zeros(mag.shape, dtype=bool)
    base, deg, refl, eb, ed, center, frac = z(), z(), z(), z(), z(), z(), z()
    for d in range(NUM_DESC):
        m = dsel == d
        if not m.any():
            continue
        ds = mem.desc[tier][d]
        n = min(max(1, ds.np), PMAX)
        b = [v & mask for v in ds.bounds]
        p = np.zeros(int(m.sum()), dtype=np.int64)
        for j in range(n - 1):
            p += mag[m] >= b[j]
        beyond[m] = mag[m] > b[n - 1]
        base[m] = (ds.base + p * (ds.deg + 1)) & 127
        deg[m] = ds.deg
        refl[m], eb[m], ed[m], center[m], frac[m] = ds.reflect, ds.exp_base, ds.exp_deg, ds.center, ds.frac
    return beyond, base, deg, refl, eb, ed, center, frac


def horner(step, op, words, base, deg):
    """barrel_mac per slot: acc = 0, then highest coefficient first acc = step(operand, acc, c), each slot on its own set."""
    op = np.asarray(op, dtype=np.int64)
    acc = np.zeros_like(op)
    w = np.asarray(words, dtype=np.int64)
    for j in range(int(np.max(deg, initial=0)), -1, -1):
        act = deg >= j  # a slot joins at its own degree; its pad rounds before that write its accumulator back as 0
        acc = np.where(act, step(op, acc, w[(base + j) & 127]), acc)
    return acc


# ── floats ──

def exp_split(k):
    """gpnae_exp_split.sv on fp32 words k >= 0: n = floor(k), f = k - n as an fp32 word, and under where k >= 256 (2^-n P < 2^-126)."""
    k = np.asarray(k, dtype=np.int64)
    e, m = (k >> 23) & 0xFF, k & 0x7FFFFF
    under = e >= 127 + 8
    big = e >= 127
    sh = np.clip(e - 127, 0, 7)
    sig = (1 << 23) | m
    n = np.where(big & ~under, sig >> (23 - sh), 0)
    fr = np.where(big, (sig << sh) & 0x7FFFFF, 0)
    p = np.where(fr == 0, 0, np.frexp(fr.astype(np.float64))[1] - 1)  # the fraction's leading one
    fw = np.where(fr == 0, 0, ((127 + p - 23) << 23) | ((fr << np.maximum(23 - p, 0)) & 0x7FFFFF))
    f = np.where(big, fw, np.where(e == 0, 0, k))
    return n, f, under


def exp_scale(p, n, under):
    """E = P 2^-n by an exponent subtract (P > 0); 0 where that leaves the normal range, or under."""
    p = np.asarray(p, dtype=np.int64)
    ep = ((p >> 23) & 0xFF) - n
    return np.where(under | (ep <= 0), 0, (ep << 23) | (p & 0x7FFFFF))


class Lane:
    """The float lane (fp32, bf16), or with f = INT8 the int8 lane; mem the coefficient memory (default: the reset image)."""

    def __new__(cls, f, mem=None, *args, **kwargs):
        if cls is Lane and f is INT8:
            return super().__new__(LaneInt8)
        return super().__new__(cls)

    def __init__(self, f, mem=None):
        self.f = f
        self.mem = default_mem(f.name) if mem is None else mem
        k = lambda v: fpu.from_fp32(v, f.m)
        self.S, self.MAG = 1 << (f.w - 1), (1 << (f.w - 1)) - 1
        self.lam = LAMBDA if f.w == 32 else LAMBDA_BF16
        self.neg_la, self.one, self.neg_one = k(NEG_LA), k(ONE), k(NEG_ONE)
        self.tiny = TANH_TINY[f.m]
        self.tail_fp32 = f.w != 32  # bf16: negative sigmoid past its pieces runs in fp32 on the tail

    def mul(self, a, b):
        return fpu.mul(self.f, a, b)[0]

    def add(self, a, b):
        return fpu.add(self.f, a, b)[0]

    def classify(self, x, code, tier):
        """gpnae_act_in: kind, MAC operand, coefficient set and exp split per element."""
        S, MAG = self.S, self.MAG
        x = np.asarray(x, dtype=np.int64)
        mag = x & MAG
        neg = ((x & S) != 0) & (mag != 0)
        beyond, base, deg, refl, eb, ed, _, _ = regions(self.mem, tier, code, mag, neg)
        n = np.zeros_like(x)
        under = np.zeros(x.shape, dtype=bool)
        if code == SELU:
            op = x
            kind = np.where(~neg, K_LIN, np.where(beyond, K_SAT, K_MUL))
        elif code == SIGMOID:
            op = mag
            kind = np.where(~neg, np.where(beyond, K_SAT, K_PASS),
                            np.where(beyond, K_TAIL if self.tail_fp32 else K_EXP, np.where(refl == 1, K_REFL, K_PASS)))
            if not self.tail_fp32:  # fp32: k = |x| log2 e on the operand multiplier, split for the exp elements
                ne, fe, ue = exp_split(fpu.mul(fpu.FP32, mag, np.full_like(x, LOG2E))[0])
                ex = kind == K_EXP
                op = np.where(ex, fe, op)
                n, under = np.where(ex, ne, 0), ex & ue
                base, deg = np.where(ex, eb, base), np.where(ex, ed, deg)
        else:
            op = self.mul(x, x)
            kind = np.where(mag < self.tiny, K_ONE, np.where(beyond, K_SAT, K_MUL))
        uses_p = np.isin(kind, (K_MUL, K_PASS, K_REFL, K_EXP))
        deg = np.where(uses_p, deg, 0)  # an element that ignores P runs one round, so it never lengthens its group
        return kind, op, base, deg, n, under

    def poly(self, op, base, deg):
        return horner(lambda a, acc, c: self.add(c, self.mul(a, acc)), op, self.mem.words, base, deg)

    def tail(self, x, tier):
        """gpnae_tail: x widened to fp32, E = 2^-n P(f) in fp32, sigmoid = E y with y -> 1/(1 + E) by Newton steps, narrowed to nearest."""
        F = fpu.FP32
        mul = lambda a, b: fpu.mul(F, a, b)[0]
        add = lambda a, b: fpu.add(F, a, b)[0]
        ts = self.mem.tail[tier]
        x32 = fpu.widen(self.f, np.asarray(x, dtype=np.int64)) & 0x7FFFFFFF  # t = |x|
        full = lambda c: np.full_like(x32, c)
        n, fr, under = exp_split(mul(x32, full(LOG2E)))
        acc = np.zeros_like(x32)
        for j in range(min(ts.deg, TAIL_MAXC - 1), -1, -1):
            acc = add(full(ts.coef[j]), mul(fr, acc))
        e = exp_scale(acc, n, under)
        d = add(full(ONE), e)
        y = add(full(Y0), (d - (1 << 23)) | (1 << 31))  # 1.5 - D/2: D >= 1, so the half is an exponent decrement
        for _ in range(ts.newton):
            y = mul(y, add(full(TWO), mul(d, y) ^ (1 << 31)))
        return fpu.narrow(self.f, mul(e, y))

    def run(self, x, code, tier=0):
        """The lane's outputs for input words x under control word code and tier."""
        x = np.asarray(x, dtype=np.int64)
        code = code if code in (SELU, SIGMOID, RELU, LINEAR) else TANH
        if code == RELU:
            return np.where((x & self.S) != 0, 0, x)
        if code == LINEAR:
            return x.copy()
        S = self.S
        kind, op, base, deg, n, under = self.classify(x, code, tier)
        p = self.poly(op, base, deg)
        full = lambda c: np.full_like(x, c)
        out = np.zeros_like(x)
        out = np.where(kind == K_LIN, self.mul(x, full(self.lam)), out)
        out = np.where(kind == K_MUL, self.mul(x, p), out)
        out = np.where(kind == K_ONE, self.mul(x, full(self.one)), out)
        out = np.where(kind == K_PASS, p, out)
        out = np.where(kind == K_REFL, self.add(p, full(self.neg_one)) ^ S, out)  # 1 - P as -(P - 1)
        sat = {SELU: full(self.neg_la), SIGMOID: full(self.one), TANH: (x & S) | self.one}[code]
        out = np.where(kind == K_SAT, sat, out)
        ex = kind == K_EXP
        if ex.any():
            e = exp_scale(p, n, under)
            out = np.where(ex, self.mul(e, self.add(full(self.one), e ^ S)), out)  # E (1 - E)
        t = kind == K_TAIL
        if t.any():
            out[t] = self.tail(x[t], tier)
        return out

    def rounds(self, x, code, tier=0):
        """Each element's kind and Horner rounds (degree + 1), what its group's cycles depend on; bypass codes give kind -1."""
        code = code if code in (SELU, SIGMOID, RELU, LINEAR) else TANH
        if code in (RELU, LINEAR):
            return np.full(np.shape(x), -1), np.zeros(np.shape(x), dtype=np.int64)
        kind, _, _, deg, _, _ = self.classify(x, code, tier)
        return kind, deg + 1


def finite_inputs(f):
    """Every finite bit pattern of an 8-exponent-bit format: normals, zeros and subnormals."""
    b = np.arange(1 << f.w, dtype=np.int64)
    return b[((b >> f.m) & f.emax) != f.emax]


def to_float(f, b):
    """Bit patterns of an 8-exponent-bit format as float64, exactly."""
    return (fpu.widen(f, b) & 0xFFFFFFFF).astype(np.uint32).view(np.float32).astype(np.float64)


# ── int8: the lane in Q4.11 on fixedPointMultiplyAdd and integer products, int8 out ──

class Int8Fmt:
    """The int8 build as the lane sees it: 8-bit ports, Q4.11 inside."""
    name, w, frac, iw, eps = "int8", 8, 11, 16, 2.0 ** -7


INT8 = Int8Fmt()
FORMATS = dict(fpu.FORMATS, int8=INT8)
Q = 11  # Q4.11
SELU_SAT, ONE_Q11, LAMBDA_Q14 = -3601, 2048, 17215  # -lambda*alpha and 1.0 in Q4.11, lambda in Q1.14
XW = 24  # the post multiplier: |q - z_in| <= 255 and mx < 2^15 keep the rescale product below 2^23
SELU_SH_LAMBDA, SELU_SH_P = 7, 4  # SELU's accumulator in 2^-(shx + 18): r * lambda >>> 7; r * P and the saturated constant >>> 4

Int8Params = namedtuple("Int8Params", "mx shx zin mout shout zout")
Case = namedtuple("Case", "s_in z_in s_out z_out gated")


def fxp_mac(a, x, c, frac):
    """fixedPointMultiplyAdd: sat16(floor(a x / 2^(11 + frac)) + c) on Q4.11 words."""
    p = (ipu.sx(a, 16) * ipu.sx(x, 16)) >> (Q + np.asarray(frac, dtype=np.int64))
    return np.clip(p + ipu.sx(c, 16), -32768, 32767)


def rescale_product(q, zin, mx):
    """The rescale's exact product r = (q - z_in) * mx on int16Multiplier: x in units of 2^-(shx + 11), |r| < 2^23."""
    assert 0 <= mx <= 32767, "gp_mx_i must be below 2^15"
    q = np.asarray(q, dtype=np.int64)
    return ipu.sx(q - zin, 16) * mx


def rescale(q, zin, mx, s):
    """(q - z_in) * mx rounded half up by 2^s, saturated to Q4.11."""
    p = rescale_product(q, zin, mx)
    return np.clip(p if s == 0 else (p + (1 << (s - 1))) >> s, -32768, 32767)


def quant_sig(y):
    """sigmoid output from y in Q4.11: round(256 y) - 128 = ((y + 4) >> 3) - 128, clamped to int8."""
    return np.clip(((np.asarray(y, dtype=np.int64) + 4) >> 3) - 128, -128, 127)


def quant_tanh(p, neg):
    """tanh output from P ~ tanh(|x|) in Q4.11: m = round(128 P) = (P + 8) >> 4 in [0, 128], the sign restored, clamped to int8."""
    m = np.clip((np.asarray(p, dtype=np.int64) + 8) >> 4, 0, 128)
    return np.clip(np.where(neg, -m, m), -128, 127)


def rescale_params(s_in):
    """(mx, shx) with mx / 2^shx = s_in * 2^11, the largest shx <= 31 that keeps mx <= 32767."""
    m = s_in * (1 << Q)
    for shx in range(31, -1, -1):
        mx = int(np.floor(m * 2.0 ** shx + 0.5))
        if mx <= 32767:
            return mx, shx
    raise ValueError(f"input scale {s_in} is too large for Q4.11")


def selu_out_params(s_in, mx, s_out):
    """SELU's (mout, shout): the output code is acc s_in / (2^7 mx s_out), that scale as ipu.encode_scale's mantissa and right shift."""
    if mx == 0:
        return 0, ipu.REQ_MAX_SHIFT  # s_in below 2^-43: every r is 0 and every output z_out
    return ipu.encode_scale(s_in / (2.0 ** SELU_SH_LAMBDA * mx * s_out))


def calib_out(y_lo, y_hi):
    """Asymmetric min/max int8 output quantization of [y_lo, y_hi], widened to hold 0."""
    lo, hi = min(y_lo, 0.0), max(y_hi, 0.0)
    s = (hi - lo) / 255.0
    return s, int(np.clip(np.floor(-128 - lo / s + 0.5), -128, 127))


def selu_case(s_in, z_in, gated=True):
    """A SELU case whose output scale is calibrated from the inputs' range, as post-training quantization would."""
    r = s_in * (np.array([-128.0, 127.0]) - z_in)
    y = np.where(r >= 0, LAMBDA_F * r, LA_F * np.expm1(np.minimum(r, 0.0)))  # min: no overflow warning where r >= 0 takes LAMBDA_F r
    s_out, z_out = calib_out(float(y[0]), float(y[1]))
    return Case(s_in, z_in, s_out, z_out, gated)


# Scales put 4.0 (tanh), 3.5 (sigmoid) and 4.0 (SELU) at 128, 32 and 8 int8 steps; SELU at 7/32 runs past Q4.11's rescale.
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
    if code == SELU:
        mout, shout = selu_out_params(case.s_in, mx, case.s_out)
        return Int8Params(mx, shx, case.z_in, mout, shout, case.z_out)
    return Int8Params(mx, shx, case.z_in, 0, 0, 0)


def exact_lsb(q, code, case):
    """The exact function at the real input in output steps, before zero point, rounding and clamp; and the output zero point."""
    q = np.asarray(q, dtype=np.int64)
    r = case.s_in * (q.astype(float) - case.z_in)
    if code == TANH:
        return np.tanh(r) / (1 / 128), 0
    if code == SIGMOID:
        return (1 / (1 + np.exp(-r))) / (1 / 256), -128
    if code == SELU:
        return np.where(r >= 0, LAMBDA_F * r, LA_F * np.expm1(np.minimum(r, 0))) / case.s_out, case.z_out
    return q.astype(float), 0


def exact_int8(q, code, case):
    """The exact function at the real input, quantized with round half up and clamped."""
    if code not in (SELU, SIGMOID, TANH):
        return np.asarray(q, dtype=np.int64).copy()
    y, z = exact_lsb(q, code, case)
    return np.clip(np.floor(y + 0.5) + z, -128, 127).astype(np.int64)


class LaneInt8(Lane):
    """The int8 lane: x = rescale(q), the region from |x|, P at the centered operand on fixedPointMultiplyAdd, the int8 post stage."""

    def __init__(self, f, mem=None):
        self.f = f
        self.mem = default_mem("int8") if mem is None else mem

    def classify(self, q, code, tier, par):
        x = rescale(q, par.zin, par.mx, par.shx)
        r = rescale_product(q, par.zin, par.mx)
        neg = x < 0
        mag = np.minimum(np.abs(x), 32767)
        beyond, base, deg, refl, _, _, center, frac = regions(self.mem, tier, code, mag, neg)
        c = ipu.sx(center, 16)
        if code == SELU:
            op = np.clip(x - c, -32768, 32767)
            kind = np.where(r >= 0, K_LIN, np.where(beyond & neg, K_SAT, K_MUL))
        elif code == SIGMOID:
            op = np.clip(mag - c, -32768, 32767)
            kind = np.where(beyond, K_SAT, np.where(neg & (refl == 1), K_REFL, K_PASS))
        else:
            op = np.clip(mag - c, -32768, 32767)
            kind = np.where(beyond, K_SAT, K_PASS)
        uses_p = np.isin(kind, (K_MUL, K_PASS, K_REFL))
        return x, r, neg, kind, op, base, np.where(uses_p, deg, 0), frac

    def run(self, q, code, par, tier=0):
        q = np.asarray(q, dtype=np.int64)
        code = code if code in (SELU, SIGMOID, RELU, LINEAR) else TANH
        if code == RELU:
            return np.maximum(q, par.zin)  # max(q, z_in), z_in the input's real 0
        if code == LINEAR:
            return q.copy()
        x, r, neg, kind, op, base, deg, frac = self.classify(q, code, tier, par)
        p = horner(lambda a, acc, c: fxp_mac(a, acc, c, frac), op, [ipu.sx(w, 16) for w in self.mem.words], base, deg)
        if code == SIGMOID:
            y = quant_sig(np.where(kind == K_REFL, ONE_Q11 - p, p))
            return np.where(kind == K_SAT, np.where(neg, -128, 127), y)
        if code == TANH:
            return np.where(kind == K_SAT, np.where(neg, -128, 127), quant_tanh(p, neg))
        sat = kind == K_SAT  # x past the last bound: -lambda*alpha 2^shx in Q4.11 times 1.0; shx <= 9 there, so it fits 24 bits
        pm_a = np.where(sat, ipu.sx(np.int64(SELU_SAT) << par.shx, XW), r)
        pm_b = np.where(kind == K_LIN, LAMBDA_Q14, np.where(sat, ONE_Q11, p))
        pm = ipu.sx(pm_a, XW) * ipu.sx(pm_b, XW)
        v = ipu.sx(np.where(kind == K_LIN, pm >> SELU_SH_LAMBDA, pm >> SELU_SH_P), 32)
        full = lambda c: np.full_like(v, c)
        return ipu.requantize(v, full(par.mout), full(par.shout), full(par.zout), full(-128), full(127))

    def rounds(self, q, code, par, tier=0):
        code = code if code in (SELU, SIGMOID, RELU, LINEAR) else TANH
        if code in (RELU, LINEAR):
            return np.full(np.shape(q), -1), np.zeros(np.shape(q), dtype=np.int64)
        _, _, _, kind, _, _, deg, _ = self.classify(np.asarray(q, dtype=np.int64), code, tier, par)
        return kind, deg + 1

    def element(self, q, code, par, tier=0) -> int:
        return int(self.run(np.array([q]), code, par, tier)[0])


if __name__ == "__main__":  # gpnae_model.py contents FMT PATH: the reset default's image file, for the benches' coefficient-image check
    if len(sys.argv) != 4 or sys.argv[1] != "contents" or sys.argv[2] not in ("fp32", "bf16", "int8"):
        sys.exit("usage: gpnae_model.py contents fp32|bf16|int8 PATH")
    default_mem(sys.argv[2]).write_contents(sys.argv[3])
