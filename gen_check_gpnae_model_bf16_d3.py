#!/usr/bin/env python3
"""Writes check_gpnae_model_bf16_d3.mem: the bf16 sigmoid study's d3 words for every finite x < 0 (its cand_d.py s_fp32_newton, narrowed), from fpu alone; --check compares instead."""
import argparse
import os
import sys

import numpy as np

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "Common", "models"))
import fpu  # noqa: E402

F32, BF16 = fpu.FP32, fpu.BF16
S, MAG = 1 << 31, (1 << 31) - 1
ONE, TWO, Y0, BIG = 0x3F800000, 0x40000000, 0x3FC00000, 0x42D00000  # 1, 2, Newton's 1.5, |a| past which e^a underflows (104)
CINV = [0x3F800000, 0x3F000000, 0x3E2AAAAB, 0x3D2AAAAB, 0x3C088889, 0x3AB60B61,
        0x39500D01, 0x37D00D01, 0x3638EF1D, 0x3493F27E, 0x32D7322B]  # 1/(k+1)!, gpnae_tail's cinv
OUT = os.path.join(ROOT, "check_gpnae_model_bf16_d3.mem")


def mul(a, b):
    return fpu.mul(F32, a, b)[0]


def add(a, b):
    return fpu.add(F32, a, b)[0]


def exp_neg(a):
    """e^a for fp32 a <= 0 as gpnae_tail: a range-reduced to |z| < 1, a degree-10 series for e^z - 1, 1 + d, then m squarings, the early zero below half the normal range."""
    full = lambda c: np.full_like(a, c)
    e_of = lambda v: (v >> 23) & 0xFF
    under = (a & MAG) > BIG
    small = e_of(a) < 127
    z = np.where(small, a, (a & S) | (126 << 23) | (a & 0x7FFFFF))
    m = np.where(small | under, 0, e_of(a) - 126)
    acc = full(CINV[10])
    for k in range(9, -1, -1):
        acc = add(mul(acc, z), full(CINV[k]))
    e = add(full(ONE), mul(z, acc))
    zeroed = np.zeros(a.shape, dtype=bool)
    for i in range(int(m.max(initial=0))):
        act = (i < m) & ~zeroed
        low = act & (e_of(e) < 64)
        zeroed |= low
        e = np.where(low, 0, np.where(act, mul(e, e), e))
    return np.where(under, 0, e)


def d3_words():
    """sigmoid(x) for every finite bf16 x < 0: E = e^-|x| in fp32, y -> 1/(1 + E) by two Newton steps from 1.5 - D/2, E y narrowed to nearest."""
    b = np.arange(1 << 16, dtype=np.int64)
    x = b[(((b >> 7) & 0xFF) != 0xFF) & (((b >> 15) & 1) == 1) & ((b & 0x7FFF) != 0)]
    e = exp_neg(S | (fpu.widen(BF16, x) & MAG))
    full = lambda c: np.full_like(e, c)
    d = add(full(ONE), e)
    y = add(full(Y0), np.where((d & MAG) == 0, 0, d - (1 << 23)) ^ S)  # 1.5 - D/2, D/2 an exponent decrement
    for _ in range(2):
        y = mul(y, add(full(TWO), mul(d, y) ^ S))
    return fpu.narrow(BF16, mul(e, y))


if __name__ == "__main__":
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--check", action="store_true", help="compare with the committed file instead of writing it")
    a = p.parse_args()
    text = "".join(f"{int(v):04x}\n" for v in d3_words())
    if a.check:
        same = open(OUT).read() == text
        print(f"{os.path.basename(OUT)}: {'equal to' if same else 'DIFFERENT FROM'} the generated {text.count(chr(10))} words")
        sys.exit(0 if same else 1)
    open(OUT, "w").write(text)
    print(f"wrote {OUT}: {text.count(chr(10))} words")
