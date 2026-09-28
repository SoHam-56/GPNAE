#!/usr/bin/env python3
"""Bit-exact model of gpnae_poly and gpnae_tail, op for op and operand for operand, in the lane's format; built on AriL's fpu.py.
fp32's negative sigmoid goes through fp32_down, modelled as fpAdder(P, -1); Task 11 measures whether that holds."""
import os
import sys

import numpy as np

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "Common", "models"))
import fpu  # noqa: E402

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
