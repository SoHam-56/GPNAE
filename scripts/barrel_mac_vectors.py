#!/usr/bin/env python3
"""Vectors for TB_barrel_mac in a format: a random coefficient memory, 256 groups of slots each with its own set (base, degree) and, in
int8, fraction shift, and each slot's Horner result on gpnae_model's step (fpu in floats, fixedPointMultiplyAdd in int8). Usage: FMT [SEED]."""
import os
import sys

import numpy as np

import gpnae_model as gm

K, NG = 16, 256
OUT = os.path.join(gm.ROOT, "testbenches", "stimulus")


def main():
    fmt = sys.argv[1]
    rs = np.random.RandomState(int(sys.argv[2]) if len(sys.argv) > 2 else 1)
    w = 32 if fmt == "fp32" else 16
    if fmt == "int8":
        words = rs.randint(-32768, 32768, gm.COEF_WORDS).astype(np.int64)
        words[:8] = [32767, -32768, 0, 1, -1, 2048, -2048, 16384]  # extremes, zero, one ulp, +-1.0, 8.0
        step = lambda a, acc, c, fr: gm.fxp_mac(a, acc, c, fr)
    else:
        f = gm.fpu.FORMATS[fmt]
        v = rs.uniform(-2.0, 2.0, gm.COEF_WORDS) * 2.0 ** rs.randint(-6, 3, gm.COEF_WORDS)
        words = gm.fpu.narrow(f, np.asarray(np.float32(v)).view(np.uint32).astype(np.int64)) if w == 16 else \
            np.asarray(np.float32(v)).view(np.uint32).astype(np.int64)
        words[:4] = [0, gm.fpu.from_fp32(0x3F800000, f.m), gm.fpu.from_fp32(0xBF800000, f.m), 1 << (w - 1)]  # +0, 1.0, -1.0, -0
        step = lambda a, acc, c, fr: gm.fpu.add(f, c, gm.fpu.mul(f, a, acc)[0])[0]
    sizes = [1, 2, 3, 4, 5, 8, 9, 13, 14, 15, 16]  # below, at and above the minimum round in every format, and a full barrel
    hdr, slots, exp = [], [], []
    for g in range(NG):
        n = sizes[g] if g < len(sizes) else int(rs.randint(1, K + 1))
        deg = rs.randint(0, 9, n) if g % 4 else np.full(n, rs.randint(0, 9))  # a group of one degree every fourth
        base = np.array([rs.randint(0, gm.COEF_WORDS - d) for d in deg], dtype=np.int64)
        frac = rs.randint(0, 4, n) if fmt == "int8" else np.zeros(n, dtype=np.int64)
        if fmt == "int8":
            x = rs.randint(-32768, 32768, n) if g % 3 == 0 else (rs.randint(-4096, 4097, n) if g % 3 == 1 else
                                                                 rs.choice([32767, -32768, 0, 1, -1, 2048, -2048], n))
        else:
            f = gm.fpu.FORMATS[fmt]
            xv = rs.uniform(-3.0, 3.0, n) * (2.0 ** rs.randint(-20, 4, n) if g % 3 == 0 else 1.0)
            x = np.asarray(np.float32(xv)).view(np.uint32).astype(np.int64)
            x = gm.fpu.narrow(f, x) if w == 16 else x
        x = np.asarray(x, dtype=np.int64)
        acc = np.zeros_like(x)
        for j in range(int(deg.max()), -1, -1):  # each slot joins at its own degree
            act = deg >= j
            c = words[(base + j) & 127]
            acc = np.where(act, step(x, acc, c, frac) if fmt == "int8" else step(x, acc, c, None), acc)
        hdr.append(n)
        for i in range(K):
            if i < n:
                slots.append((int(x[i]) & ((1 << w) - 1), int(base[i]), int(deg[i]), int(frac[i])))
                exp.append(int(acc[i]) & ((1 << w) - 1))
            else:
                slots.append((0, 0, 0, 0))
                exp.append(0)
    os.makedirs(OUT, exist_ok=True)
    nd = w // 4
    with open(os.path.join(OUT, f"bm_{fmt}_mem.mem"), "w") as fh:
        fh.write("".join(f"{int(v) & ((1 << w) - 1):0{nd}x}\n" for v in words))
    with open(os.path.join(OUT, f"bm_{fmt}_hdr.mem"), "w") as fh:
        fh.write("".join(f"{h:02x}\n" for h in hdr))
    with open(os.path.join(OUT, f"bm_{fmt}_slot.mem"), "w") as fh:  # {frac, deg, base, operand}
        fh.write("".join(f"{fr:01x}{d:01x}{b:02x}{op:0{nd}x}\n" for op, b, d, fr in slots))
    with open(os.path.join(OUT, f"bm_{fmt}_exp.mem"), "w") as fh:
        fh.write("".join(f"{v:0{nd}x}\n" for v in exp))
    print(f"bm vectors {fmt}: {NG} groups, the memory, slots and results in {OUT}")


if __name__ == "__main__":
    main()
