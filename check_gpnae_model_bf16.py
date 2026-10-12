#!/usr/bin/env python3
"""gpnae_model's bf16 lane: the sigmoid gate over every finite bf16 input (spec Decision 5), the lanes it must fail on, the study's d3 words, 3efe6f6's outputs, tanh's tiny |x|, the vectorized tail, the RTL's literals."""
import hashlib
import os
import re
import sys

import numpy as np

import gpnae_model as gm
import truth  # AriL's true-function gate, on the path gpnae_model sets up

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
    rest = np.ones(X.shape, dtype=bool)
    print(f"{name:<6} tail inputs {int(t.sum())}: {int((new_o != old_o).sum())} words change, tail worst {100 * w_old:.3f}% -> {100 * w_new:.3f}%; "
          f"overall {100 * rel_worst(code, X, old_o, rest):.3f}% -> {100 * rel_worst(code, X, new_o, rest):.3f}%")
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

# x < 0 words equal the study's d3 bit for bit: its cand_d.py (s_fp32_newton, narrowed) wrote check_gpnae_model_bf16_d3.mem; gen_check_gpnae_model_bf16_d3.py regenerates it from fpu.
neg = (((X >> 15) & 1) == 1) & ((X & 0x7FFF) != 0)
d3 = np.array([int(v, 16) for v in open(os.path.join(gm.ROOT, "check_gpnae_model_bf16_d3.mem")) if v.strip()], dtype=np.int64)
eq("the study's d3 words: one per x < 0 input", (d3.size, int(neg.sum())), (32639, 32639))
eq("x < 0 sigmoid words equal the study's d3", int((out[neg] != d3).sum()), 0)
import gen_check_gpnae_model_bf16_d3 as gen_d3  # noqa: E402
eq("the d3 file is gen_check_gpnae_model_bf16_d3's words", int((np.asarray(gen_d3.d3_words(), dtype=np.int64) != d3).sum()), 0)

# fp32 and the as-built bf16 lane equal 3efe6f6's gpnae_model: digests of its outputs on the same inputs.
OLD = {("bf16", 1): "1e4e3426ffc8616d", ("bf16", 2): "352049b8db595585", ("bf16", 3): "3c0feb455c9459c0", ("bf16", 4): "2bdacb7c6abe05e6",
       ("bf16", 5): "1dc1e23df86425b9", ("fp32", 1): "0373827d49a64d0b", ("fp32", 2): "b77b0fdc7958ac0f", ("fp32", 3): "8809e320cfb6bb98"}
digest = lambda a: hashlib.sha256(np.asarray(a, dtype="<i8").tobytes()).hexdigest()[:16]
built = {"bf16": gm.Lane(BF16, ROM, newton=0, tiny=False, lam=gm.LAMBDA), "fp32": gm.Lane(fpu.FP32, l32.rom, tiny=False)}  # 3efe6f6's lanes: tanh x * P at every |x|, bf16 lambda 0x3F86
for (tag, code), want in OLD.items():
    ln, xs = (built[tag], X) if tag == "bf16" else (built[tag], x32)
    eq(f"{tag}{' as built' if tag == 'bf16' else ''} code {code} on {xs.size} inputs equals 3efe6f6's model", digest(ln.run(xs, code)), want)

# tanh below T_TINY returns x: the only words it changes are there, and each is x (a subnormal x reads as zero, as before); the gate passes.
for tag, ln, xs in (("bf16", gm.Lane(BF16, ROM, newton=0), X), ("fp32", l32, x32)):
    f = ln.f
    new_o, old_o = ln.run(xs, 3), built[tag].run(xs, 3)
    tiny = (xs & ln.MAG) < ln.tiny
    normal = ((xs >> f.m) & f.emax) != 0
    eq(f"{tag} tanh: T_TINY is the first |x| where tanh(x) does not round to x", (ln.tiny, int(truth.encode(tag, np.tanh(truth.decode(tag, ln.tiny)))) != ln.tiny,
                                                                                bool((truth.encode(tag, np.tanh(truth.decode(tag, xs[tiny & normal]))) == xs[tiny & normal]).all())),
       (fpu.from_fp32(gm.TANH_TINY[f.m], f.m), True, True))
    eq(f"{tag} tanh: words change only below T_TINY, and there each normal x gives x", (bool((new_o[~tiny] == old_o[~tiny]).all()),
                                                                                       bool((new_o[tiny & normal] == xs[tiny & normal]).all())), (True, True))
    print(f"{tag} tanh: {int((new_o != old_o).sum())} of {xs.size} words change below T_TINY {truth.decode(tag, ln.tiny):.5g}")
for tag, ln, xs in (("bf16", lane, X), ("fp32", l32, x32)):
    r, r_old = truth.gate(tag, "tanh", xs, ln.run(xs, 3)), truth.gate(tag, "tanh", xs, built[tag].run(xs, 3))
    print(f"{tag} tanh as built before: {truth.line(r_old)}")
    print(f"{tag} tanh now:             {truth.line(r)}")
    eq(f"{tag} tanh meets the true-function gate on {xs.size} inputs (it missed {r_old.over} before)", (r.ok, r_old.ok), (True, False))

# bf16 SELU's lambda is 0x3F87, rounded up: x >= 0 words change, 0x7F73 overflows to +Inf (it gave 0x7F7E), and every positive word is within 0.38%.
old_l = gm.Lane(BF16, ROM, lam=gm.LAMBDA)
new_o, old_o = lane.run(X, 1), old_l.run(X, 1)
pos = ((X >> 15) & 1) == 0
eq("bf16 SELU lambda: 0x3F87, and fp32's is LAMBDA's", (lane.lam, l32.lam), (0x3F87, gm.LAMBDA))
eq("bf16 SELU: words change only at x >= 0, and 0x7F73 gives +Inf (0x7F7E before)", (bool((new_o[~pos] == old_o[~pos]).all()),
   int(new_o[X == 0x7F73][0]), int(old_o[X == 0x7F73][0])), (True, 0x7F80, 0x7F7E))
r, r_old = truth.gate("bf16", "selu", X, new_o), truth.gate("bf16", "selu", X, old_o)
rp = truth.gate("bf16", "selu", X[pos], new_o[pos])
print(f"bf16 SELU before: {truth.line(r_old)}")
print(f"bf16 SELU now:    {truth.line(r)}")
print(f"bf16 SELU x >= 0: {truth.line(rp)}; {int((new_o != old_o).sum())} words change")
eq("bf16 SELU meets the true-function gate (1 miss before); x >= 0 within 0.38%, none over 1%", (r.ok, r_old.ok, rp.worst < 0.0038, rp.over_target),
   (True, False, True, 0))

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
