#!/usr/bin/env python3
"""Known values for gpnae_model's fp32 lane: negative sigmoid words the RTL produced (fp32_down's truncation), fp32_down against fpAdder, tanh's T_TINY by exhaustive scan."""
import os
import sys

import numpy as np

import gpnae_model as gm

fpu = gm.fpu  # AriL's fpu, on the path gpnae_model sets up

errs = 0


def eq(what, got, want):
    global errs
    if got != want:
        errs += 1
        print(f"[FAIL] {what}: got {got}, want {want}")


lane = gm.Lane(fpu.FP32, gm.read_rom(os.path.join(gm.ROOT, "poly_coeffs.mem")))

# gpnae_poly's outputs in TB_gpnae_poly (fp32, act_edge and act_negative, seed 1): fpAdder(P, -1) gave each one 2, 4, 8 or 16 ulp lower.
RTL = [(0xbf800000, 0x3e89afcc), (0xbf000000, 0x3ec14c18), (0xbfee832e, 0x3e098988), (0xbff41da2, 0x3e0466d8),
       (0xc022b529, 0x3d9559b0), (0xc0259465, 0x3d8f4370), (0xc0400000, 0x3d426020),
       (0xc0000000, 0x3df418d0), (0x80800000, 0x3effe948)]  # the last two: P's last bit clear, where both models agree
for x, want in RTL:
    eq(f"sigmoid({x:08x}) is the RTL's word", f"{lane.element(x, 2):08x}", f"{want:08x}")

p = np.arange(0x3f000000, 0x3f800000, 0x1235, dtype=np.int64)  # P in [0.5, 1), the sigmoid polynomial's range
ref = fpu.add(fpu.FP32, p, np.full_like(p, gm.NEG_ONE))[0]
dn = gm.fp32_down(p)
eq("fp32_down equals fpAdder(P, -1) where P's last bit is clear", bool((dn[(p & 1) == 0] == ref[(p & 1) == 0]).all()), True)
val = lambda b: np.asarray(b, dtype=np.int64).astype(np.uint32).view(np.float32).astype(np.float64)
odd = (p & 1) == 1
eq("fp32_down drops P's last bit where it is set: P - 2^-24 - 1", bool((val(dn[odd]) == val(p[odd]) - 2.0 ** -24 - 1.0).all()), True)
eq("both kinds of P were checked", (int((~odd).sum()) > 100, int(odd.sum()) > 100), (True, True))
# T_TINY: every fp32 pattern in [2^-14, 2^-10), tanh in float64 rounded to fp32 (nearest even); below 2^-14, x^2/3 < 2^-29 is under half an ulp.
first, n, n_bad = None, 0, 0  # the scan is ascending, so every pattern before the first mismatch rounds to itself
for a in range(0x38800000, 0x3A800000, 1 << 22):
    p = np.arange(a, a + (1 << 22), dtype=np.int64)
    bad = p[np.tanh(val(p)).astype(np.float32).view(np.uint32).astype(np.int64) != p]
    n, n_bad = n + p.size, n_bad + bad.size
    if first is None and bad.size:
        first = int(bad[0])
eq("tanh's T_TINY is the first fp32 pattern from 2^-14 where tanh(x) does not round to x (every pattern below it does), in the model and its lane",
   (None if first is None else f"{first:08x}", f"{gm.TANH_TINY[23]:08x}", f"{lane.tiny:08x}"), ("39b89ba3", "39b89ba3", "39b89ba3"))
print(f"T_TINY scan: {n} patterns in [2^-14, 2^-10), {n_bad} where tanh(x) does not round to x, the first {first:#010x}")
print(f"check_gpnae_model_fp32: {errs} errors")
print(f"RESULT: {'PASSED' if errs == 0 else 'FAILED'}")
sys.exit(1 if errs else 0)
