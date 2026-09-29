#!/usr/bin/env python3
"""Vectors for TB_barrel_mac_int8: a random Q4.11 coefficient ROM, 256 operand groups, and each slot's Horner result on ipu.fx_mac."""
import os
import sys

import numpy as np

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "Common", "models"))
import ipu  # noqa: E402

K, NG = 16, 256
OUT = os.path.join(ROOT, "testbenches", "stimulus")


def main():
    rs = np.random.RandomState(int(sys.argv[1]) if len(sys.argv) > 1 else 1)
    rom = rs.randint(-32768, 32768, 32).astype(np.int64)
    rom[:8] = [32767, -32768, 0, 1, -1, 2048, -2048, 16384]  # extremes, zero, one ULP, +/-1.0, 8.0
    sizes = [1, 2, 3, 4, 5, 8, 15, 16]  # below, at and above the 4-cycle minimum round, and a full barrel
    hdr, opd, exp = [], [], []
    for g in range(NG):
        n = sizes[g] if g < len(sizes) else int(rs.randint(1, K + 1))
        deg = int(rs.randint(0, 9))
        base = int(rs.randint(0, 32 - deg))
        if g % 3 == 0:
            x = rs.randint(-32768, 32768, n)  # full range: products and sums saturate
        elif g % 3 == 1:
            x = rs.randint(-2048, 2049, n)  # abs(t) <= 1, the lane's operands
        else:
            x = rs.choice([32767, -32768, 0, 1, -1, 2048, -2048, 16384, -16384], n)
        x = np.asarray(x, dtype=np.int64)
        acc = np.zeros_like(x)
        for r in range(deg + 1):  # barrel_mac: fxMac(A=operand, X=acc, C=coefficient), highest coefficient first
            acc = ipu.fx_mac(x, acc, np.full_like(x, rom[base + deg - r]), w=16, frac=11)
        hdr.append((n << 16) | (deg << 8) | base)
        opd += [int(v) for v in x] + [0] * (K - n)
        exp += [int(v) for v in acc] + [0] * (K - n)
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, "bm_int8_rom.mem"), "w") as f:
        f.write("".join(format(int(v) & 0xFFFF, "016b") + "\n" for v in rom))
    with open(os.path.join(OUT, "bm_int8_hdr.mem"), "w") as f:
        f.write("".join(f"{h:08x}\n" for h in hdr))
    for name, vals in (("in", opd), ("exp", exp)):
        with open(os.path.join(OUT, f"bm_int8_{name}.mem"), "w") as f:
            f.write("".join(f"{v & 0xFFFF:04x}\n" for v in vals))
    print(f"bm_int8 vectors: {NG} groups, ROM, operands and results in {OUT}")


if __name__ == "__main__":
    main()
