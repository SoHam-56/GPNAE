#!/usr/bin/env python3
"""gpnae_model's bf16 lane: the sigmoid gate over every finite bf16 input (spec Decision 5), the lanes it must fail on, the vectorized tail, the RTL's literals."""
import os
import re
import sys

import numpy as np

import gpnae_model as gm

fpu = gm.fpu
BF16 = fpu.BF16
errs = 0


def eq(what, got, want):
    global errs
    if got != want:
        errs += 1
        print(f"[FAIL] {what}: got {got}, want {want}")


def show(name, g):
    print(f"{name:<40} worst {100 * g.worst:8.3f}% at x = {g.at:<11.5g} over {100 * gm.SIG_BOUND:g}%: {g.over:5d}  "
          f"below-normal misses {g.flush}  inputs {g.n} ({g.n_sub} subnormal, worst {100 * g.worst_sub:.3f}%)")
    return g


def rel_worst(code, x, out, mask):
    """Worst relative error of tanh (3) or SELU (1) over mask, where the exact value is at least 2^-126."""
    v = np.where(((x >> BF16.m) & BF16.emax) == 0, 0.0, gm.to_float(BF16, x))
    ref = np.tanh(v) if code == 3 else np.where(v >= 0, gm.LAMBDA_F * v, gm.LA_F * np.expm1(np.minimum(v, 0)))
    m = mask & (np.abs(ref) >= gm.MIN_NORMAL) & (np.abs(ref) < 3.3e38)
    return float((np.abs(gm.to_float(BF16, out) - ref)[m] / np.abs(ref[m])).max())


ROM = gm.read_rom(os.path.join(gm.ROOT, "poly_coeffs_bf16.mem"))
X = gm.finite_inputs(BF16)
lane = gm.Lane(BF16, ROM)
eq("every finite bf16 input judged", X.size, 65280)

# The lane: d3 of the study (sienna_report/bf16_sigmoid_study.log), whose worst is P's final truncation at x > 0.
g = show("sigmoid, the lane", gm.sigmoid_gate(BF16, X, lane.run(X, 2)))
eq("sigmoid meets the gate", g.ok, True)
eq("sigmoid worst as the study's d3: 0.772% at x = 0.015564", (round(100 * g.worst, 3), round(g.at, 6)), (0.772, 0.015564))

# The gate fails on the lane as built, on one Newton step and on the tail's old start (the RTL mutants' models).
for name, kw, want in (("sigmoid, as built (no Newton)", dict(newton=0), (106.554, -59.75, 698)),
                       ("sigmoid, one Newton step", dict(newton=1), (1.834, -0.789062, 254)),
                       ("sigmoid, x < 0 not sent to the tail", dict(neg_tail=False), (18.064, -3.375, 176))):
    b = show(name, gm.sigmoid_gate(BF16, X, gm.Lane(BF16, ROM, **kw).run(X, 2)))
    eq(f"{name} fails the gate", (b.ok, round(100 * b.worst, 3), round(b.at, 6), b.over), (False, *want))

# A NaN word fails the gate: every word NaN, and the lane's words with one of them NaN.
out = lane.run(X, 2)
one_nan = out.copy()
one_nan[int(np.flatnonzero(X == 0xBF80)[0])] = BF16.qnan  # x = -1
for name, o, want in (("sigmoid, every word NaN", np.full_like(out, BF16.qnan), X.size), ("sigmoid, one NaN word (x = -1)", one_nan, 1)):
    b = show(name, gm.sigmoid_gate(BF16, X, o))
    eq(f"{name} fails the gate", (b.ok, b.over), (False, want))

# tanh and SELU take the fp32 tail too: their tail outputs may only get better.
old = gm.Lane(BF16, ROM, newton=0)
for code, name in ((3, "tanh"), (1, "SELU")):
    t = np.asarray(lane.in_tail(X, code))
    new_o, old_o = lane.run(X, code), old.run(X, code)
    w_new, w_old = rel_worst(code, X, new_o, t), rel_worst(code, X, old_o, t)
    print(f"{name:<6} tail inputs {int(t.sum())}: {int((new_o != old_o).sum())} words change, tail worst {100 * w_old:.3f}% -> {100 * w_new:.3f}%; "
          f"overall {100 * rel_worst(code, X, old_o, t | ~t):.3f}% -> {100 * rel_worst(code, X, new_o, t | ~t):.3f}%")
    eq(f"{name}: the poly path is unchanged", bool((new_o[~t] == old_o[~t]).all()), True)
    eq(f"{name}: the fp32 tail is no worse", w_new <= w_old, True)

# run() takes the vectorized tail: equal to tail(), op for op, on every 16th tail input of each function, bf16 and fp32.
l32 = gm.Lane(fpu.FP32, gm.read_rom(os.path.join(gm.ROOT, "poly_coeffs.mem")))
x32 = fpu.widen(BF16, X) | (X * 40503 & 0xFFFF)  # every bf16 value with low bits filled in: fp32 inputs at every exponent
for ln, xs, tag in ((lane, X, "bf16"), (old, X, "bf16 as built"), (l32, x32, "fp32")):
    for code in (1, 2, 3):
        i = np.flatnonzero(np.asarray(ln.in_tail(xs, code)))[::16]
        vec, one = ln.tail_v(xs[i], code), np.array([ln.tail(int(v), code) for v in xs[i]])
        eq(f"{tag} code {code}: tail_v equals tail on {i.size} inputs", int((vec != one).sum()), 0)

# fp32 is untouched: no Newton, its own tail, sigmoid x < 0 inside 3.5 on the polynomial.
eq("fp32 lane: no Newton, no wide tail, x = -1 not a tail input", (l32.newton, l32.wide, l32.in_tail(0xBF800000, 2)), (0, False, False))
eq("bf16 lane: Newton 2 in an fp32 tail, every x < 0 a tail input, -0 not", (lane.newton, lane.wide, lane.in_tail(0x8001, 2),
                                                                             lane.in_tail(0xBF80, 2), lane.in_tail(0x8000, 2)),
   (2, True, True, True, False))

# The RTL's literals equal the model's: the bf16 branch's NEWTON and the seed constant.
poly_sv = open(os.path.join(gm.ROOT, "src", "gpnae_poly.sv")).read()
tail_sv = open(os.path.join(gm.ROOT, "src", "gpnae_tail.sv")).read()
eq("gpnae_poly's bf16 tail NEWTON", [int(v) for v in re.findall(r"localparam int TAIL_NEWTON = FP32 \? 0 : (\d+);", poly_sv)], [gm.NEWTON_BF16])
eq("gpnae_tail's Y0", re.findall(r"Y0\s*=\s*K_\(32'h([0-9A-Fa-f]+)\)", tail_sv), [f"{gm.NEWTON_Y0:08X}"])

print(f"check_gpnae_model_bf16: {errs} errors")
print(f"RESULT: {'PASSED' if errs == 0 else 'FAILED'}")
sys.exit(1 if errs else 0)
