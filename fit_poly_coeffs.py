#!/usr/bin/env python3
"""Fits gpnae_poly's coefficient table for a narrow format and measures it as the hardware evaluates it (gpnae_model, bit-exact).
Fits as behind poly_coeffs.mem (Chebyshev, 4001 points; SELU on [-4, 0], the lane's range, where fp32 used [-3.5, 0]); sigmoid on [0, 4],
tanh(sqrt u)/sqrt u on [0, 16]; rounded to the format or fixed one at a time lowest first; degree chosen by the polynomial's own error.
Writes poly_coeffs_<fmt>.mem in the GPNAE root and in src/TYTAN/Memory. Never writes the fp32 files."""
import argparse
import os
import sys

import numpy as np

import gpnae_model
from gpnae_model import ROOT, SETS, fpu

LA = 1.7580993408473766  # lambda * alpha
DOMAIN = {1: (-4.0, 0.0), 2: (0.0, 4.0), 3: (0.0, 16.0)}  # SELU to -4, where the lane's tail starts
NAME = {1: "selu", 2: "sigmoid", 3: "tanh"}


def target(code, t):
    t = np.asarray(t, float)
    if code == 1:
        return np.where(np.abs(t) < 1e-8, LA * (1 + t / 2), LA * np.expm1(t) / np.where(t == 0, 1, t))
    if code == 2:
        return 1 / (1 + np.exp(-t))
    s = np.sqrt(np.maximum(t, 0))
    return np.where(t < 1e-12, 1 - t / 3, np.tanh(s) / np.where(s == 0, 1, s))


def exact_act(code, x):
    x = np.asarray(x, float)
    if code == 1:
        return np.where(x >= 0, 1.0507009873554805 * x, LA * np.expm1(x))
    if code == 2:
        return 1 / (1 + np.exp(-x))
    return np.tanh(x)


def to_fmt(f, v):
    """float -> format bits: fp32 nearest, then nearest at the format's width."""
    return fpu.from_fp32(int(np.float32(v).view(np.uint32)), f.m)


def to_float(f, bits):
    return np.asarray((np.asarray(bits, dtype=np.int64) << (23 - f.m)).astype(np.uint32)).view(np.float32).astype(np.float64)


def fit_plain(f, code, deg):
    lo, hi = DOMAIN[code]
    x = np.linspace(lo, hi, 4001)
    c = np.polynomial.chebyshev.Chebyshev.fit(x, target(code, x), deg).convert(kind=np.polynomial.Polynomial).coef
    return [to_fmt(f, v) for v in c]


def fit_greedy(f, code, deg):
    lo, hi = DOMAIN[code]
    x = np.linspace(lo, hi, 4001)
    y = target(code, x)
    w = 1 / np.maximum(np.abs(y), 1e-6)  # relative error
    fixed = []
    for j in range(deg + 1):
        r = y - sum(to_float(f, c) * x**i for i, c in enumerate(fixed))
        V = np.vstack([x**i for i in range(j, deg + 1)]).T
        sol = np.linalg.lstsq(V * w[:, None], r * w, rcond=None)[0]
        fixed.append(to_fmt(f, sol[0]))
    return fixed


def inputs(f, code):
    """Every format value the polynomial path sees: negative SELU inputs, sigmoid and tanh inputs within the thresholds."""
    b = np.arange(1 << f.w, dtype=np.int64)
    e = (b >> f.m) & f.emax
    lane = gpnae_model.Lane(f, [0] * 32)
    finite = (e != f.emax) & (e != 0)
    mag = b & lane.MAG
    keep = finite & (((code == 1) & (b >= lane.S) & (mag <= lane.four)) | ((code == 2) & (mag <= lane.three_half)) |
                     ((code == 3) & (mag <= lane.four)))
    return b[keep]


def measure(f, code, coeffs):
    base, deg = SETS[code]
    rom = [0] * 32
    rom[base:base + deg + 1] = coeffs
    x = inputs(f, code)
    hw = to_float(f, gpnae_model.Lane(f, rom).poly(x, code))
    ref = exact_act(code, to_float(f, x))
    rel = np.abs(hw - ref) / np.maximum(np.abs(ref), 1e-30)
    return float(rel.max()), float(rel.mean()), len(x)


def measure_poly(f, code, coeffs):
    """Error of the barrel MAC's Horner result against the fitted function, before the post stage, over the same inputs."""
    base, deg = SETS[code]
    lane = gpnae_model.Lane(f, [0] * 32)
    x = inputs(f, code)
    t = x if code == 1 else (x & lane.MAG) if code == 2 else fpu.mul(f, x, x)[0]
    acc = np.zeros_like(x)
    for c in reversed(coeffs):  # mul(A=operand, B=acc), then add(A=coefficient, B=product), as barrel_mac
        acc = fpu.add(f, np.full_like(x, c), fpu.mul(f, t, acc)[0])[0]
    g = target(code, to_float(f, t))
    rel = np.abs(to_float(f, acc) - g) / np.maximum(np.abs(g), 1e-30)
    return float(rel.max()), float(rel.mean())


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--format", required=True, choices=sorted(fpu.FORMATS))
    p.add_argument("--report", default=os.path.join(ROOT, "testbenches", "results", "poly_coeffs_fit.log"))
    a = p.parse_args()
    if a.format == "fp32":
        print("refusing to write fp32 coefficients: poly_coeffs.mem is published and fixed")
        sys.exit(1)
    f = fpu.FORMATS[a.format]
    out = gpnae_model.coeff_file(f)
    assert out not in ("poly_coeffs.mem", "taylor_coeffs.mem")
    L, table = [], [0] * 32
    L.append(f"gpnae_poly coefficients for {a.format}, bit-exact hardware arithmetic; polynomial: the MAC's Horner result against")
    L.append("the fitted function; activation: the lane's output (post stage included) against the exact activation.")
    L.append("A degree below the table's is stored with zero leading coefficients, which Horner evaluates bit-identically.")
    L.append(f"{'activation':<10}{'degree':>7}{'method':>8}{'poly worst':>12}{'poly mean':>11}{'act worst':>11}{'act mean':>10}{'inputs':>8}")
    for code in (1, 2, 3):
        base, deg = SETS[code]
        best = None
        for d in range(2, deg + 1):
            for name, fn in (("plain", fit_plain), ("greedy", fit_greedy)):
                c = fn(f, code, d) + [0] * (deg - d)
                pw, pm = measure_poly(f, code, c)
                worst, mean, n = measure(f, code, c)
                L.append(f"{NAME[code]:<10}{d:>7}{name:>8}{pw:>12.4%}{pm:>11.4%}{worst:>11.4%}{mean:>10.4%}{n:>8}")
                if best is None or (pw, pm) < best[0]:
                    best = ((pw, pm), d, name, c, worst, mean)
        (pw, pm), d, name, c, worst, mean = best
        table[base:base + deg + 1] = c
        L.append(f"{NAME[code]:<10} chosen by polynomial worst error: degree {d}, {name}; poly worst {pw:.4%}, "
                 f"activation worst {worst:.4%} mean {mean:.4%}")
    for path in (os.path.join(ROOT, out), os.path.join(ROOT, "src", "TYTAN", "Memory", out)):
        with open(path, "w") as fh:
            fh.write("".join(format(v, f"0{f.w}b") + "\n" for v in table))
    os.makedirs(os.path.dirname(a.report), exist_ok=True)
    open(a.report, "w").write("\n".join(L) + "\n")
    print("\n".join(L))


if __name__ == "__main__":
    main()
