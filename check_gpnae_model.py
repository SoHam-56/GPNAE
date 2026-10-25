#!/usr/bin/env python3
"""gpnae_model's own checks, no simulator: the reset default (gpnae_coef_default.json) passes every tier's tolerance in the model and
equals gpnae_coef_mem.sv's literal tables (fit_poly_coeffs.py --check); the load path's decode round-trips every field; the exp split is
floor and fraction exactly; a slot's Horner result does not depend on its group's degree; fxp_mac at frac 0 is ipu.fx_mac."""
import os
import subprocess
import sys

import numpy as np

import gpnae_model as gm

errs = 0


def eq(what, got, want):
    global errs
    ok = np.array_equal(np.asarray(got), np.asarray(want))
    if not ok:
        errs += 1
        print(f"[FAIL] {what}: got {got!r}, want {want!r}")
    return ok


# the default image passes and the RTL holds it
r = subprocess.run([sys.executable, os.path.join(gm.ROOT, "fit_poly_coeffs.py"), "--check"], capture_output=True, text=True)
print(r.stdout, end="")
eq("fit_poly_coeffs.py --check exit", r.returncode, 0)

# the load path: every write of an image, replayed into an empty memory, gives the image back
for f in ("fp32", "bf16", "int8"):
    m = gm.default_mem(f)
    e = gm.Mem(f)
    for a, d in m.writes():
        e.load(a, d)
    eq(f"{f} load round trip", e.to_dict() | {"meta": {}}, m.to_dict() | {"meta": {}})
    e.load(gm.A_TAIL + gm.NUM_TIERS * gm.TAIL_STRIDE + 5, 0xFFFFFFFF)  # past the map: ignored
    eq(f"{f} write past the map", e.to_dict() | {"meta": {}}, m.to_dict() | {"meta": {}})

# the exp split: n = floor(k), f = k - n exactly, under from 256 up
k = np.concatenate([np.array([0, 0x3F000000, 0x3F800000, 0x40000000, 0x41200000, 0x437F0000, 0x43800000, 0x7F800000]),
                    np.random.default_rng(1).integers(0x3F800000, 0x43800000, 4096)])
n, fr, under = gm.exp_split(k)
kv = gm.to_float(gm.fpu.FP32, k)
fv = gm.to_float(gm.fpu.FP32, fr)
fin = ~under
eq("exp_split n", n[fin], np.floor(kv[fin]).astype(np.int64))
eq("exp_split f", fv[fin], kv[fin] - np.floor(kv[fin]))
eq("exp_split under", under, (kv >= 256) | ~np.isfinite(kv))

# a slot's result is its own Horner, whatever the group's top degree: padding with zero rounds changes nothing
f = gm.fpu.BF16
step = lambda a, acc, c: gm.fpu.add(f, c, gm.fpu.mul(f, a, acc)[0])[0]
w = list(gm.default_mem("bf16").words)
x = gm.finite_inputs(f)[::97]
alone = gm.horner(step, x, w, np.full(x.size, 10), np.full(x.size, 2))
mixed = gm.horner(step, np.concatenate([x, [0x3F80]]), w, np.concatenate([np.full(x.size, 10), [0]]), np.concatenate([np.full(x.size, 2), [9]]))[:-1]
eq("a slot's result does not depend on its group", mixed, alone)

# fixedPointMultiplyAdd at frac f is ipu.fx_mac at FRAC 11 + f (fxMac's model, proven equal to the RTL before fxMac left)
rng = np.random.default_rng(2)
a, xx, c = (rng.integers(-32768, 32768, 10000) for _ in range(3))
eq("fxp_mac frac 0 == ipu.fx_mac", gm.fxp_mac(a, xx, c, 0), gm.ipu.fx_mac(a, xx, c, w=16, frac=11))
eq("fxp_mac frac 2 == ipu.fx_mac FRAC 13", gm.fxp_mac(a, xx, c, 2), gm.ipu.fx_mac(a, xx, c, w=16, frac=13))

print(f"check_gpnae_model: {errs} errors")
print("RESULT: PASSED" if errs == 0 else "RESULT: FAILED")
sys.exit(1 if errs else 0)
