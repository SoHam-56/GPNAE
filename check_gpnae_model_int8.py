#!/usr/bin/env python3
"""Known values for gpnae_model's int8 lane: rounding and saturation of each step, the fixed output quantizations, SELU through the requantizer."""
import os
import re
import sys

import numpy as np

import gpnae_model as gm

errs = 0


def eq(what, got, want):
    global errs
    got = got if isinstance(got, tuple) else [int(v) for v in np.atleast_1d(got)]
    if got != want:
        errs += 1
        print(f"[FAIL] {what}: got {got}, want {want}")


eq("rescale rounds half up", gm.rescale(np.array([3, -3, 1, -1]), 0, 1, 1), [2, -1, 1, 0])
eq("rescale saturates to Q4.11", gm.rescale(np.array([127, -128]), 0, 32767, 0), [32767, -32768])
eq("rescale subtracts the zero point", gm.rescale(np.array([5]), 5, 1000, 3), [0])
eq("rescale by 2^31", gm.rescale(np.array([127]), -128, 32767, 31), [0])
eq("SELU MAC operand is x", gm.mac_operand(np.array([-5, 7]), 1), [-5, 7])
eq("sigmoid MAC operand is |x|, saturated", gm.mac_operand(np.array([-32768, -5, 5]), 2), [32767, 5, 5])
eq("tanh MAC operand is x^2 on fxMac", gm.mac_operand(np.array([2048, -2048, 6400, 8192, 32767]), 3), [2048, 2048, 20000, 32767, 32767])
eq("sigmoid output rounding and clamp", gm.quant_sig(np.array([2048, 0, 4, 3, -9])), [127, -128, -127, -128, -128])
eq("tanh output from x*P", gm.quant_tanh(np.array([16384, 16383, -16384, -16385, 1 << 30])), [1, 0, 0, -1, 127])
eq("rescale_params(1/128)", gm.rescale_params(1 / 128), (16384, 10))
eq("rescale_params(0.05)", gm.rescale_params(0.05), (26214, 8))
eq("quantize_multiplier(0.5)", gm.quantize_multiplier(0.5), (1 << 30, 0))
eq("quantize_multiplier(1.0)", gm.quantize_multiplier(1.0), (1 << 30, 1))
eq("quantize_multiplier(0.75)", gm.quantize_multiplier(0.75), (1610612736, 0))
eq("16-bit ROM words read as two's complement", gm.Lane(gm.INT8, [0xFFFF] + [0] * 31).rom[:2], [-1, 0])

zero = gm.Lane(gm.INT8, [0] * 32)  # P = 0 everywhere, so only the non-polynomial paths show
p = gm.Int8Params(mx=26214, shx=8, zin=0, mout=0, shout=0, zout=0)  # s_in = 0.05: x = 102.4 q in Q4.11
eq("tanh, zero table: x * 0 inside +/-4, saturated outside", zero.run(np.array([0, 80, 81, -80, -81]), 3, p), [0, 0, 127, 0, -128])
zero_2a = gm.Lane(gm.INT8, [0] * 32, ladder=False)  # 2a's sigmoid, which saturates past 3.5 (the ladder takes over from 2.5)
eq("sigmoid, zero table, ladder off: P = 0, 1 - P = 1 inside +/-3.5, saturated outside", zero_2a.run(np.array([70, 71, -70, -71]), 2, p), [-128, 127, 127, -128])
eq("sigmoid, zero table, ladder on: the ladder at x = +-7168, +-7270 whatever the table", zero.run(np.array([70, 71, -70, -71]), 2, p), [120, 121, -120, -121])
p2 = gm.Int8Params(mx=26214, shx=8, zin=0, mout=1 << 30, shout=-17, zout=3)  # output multiplier 2^-18: 1/16 per LSB in 2^-22
eq("SELU x >= 0: lambda x, requantized", zero.run(np.array([10, 0]), 1, p2), [11, 3])
eq("SELU -4 <= x < 0: x * P = 0 with a zero table", zero.run(np.array([-5]), 1, p2), [3])
p3 = gm.Int8Params(mx=26214, shx=7, zin=0, mout=1 << 30, shout=-17, zout=3)  # s_in = 0.1
eq("SELU x = -4 inside, x < -4: -lambda*alpha, requantized", zero.run(np.array([-40, -41, -71]), 1, p3), [3, -25, -25])
eq("rescale_wide does not saturate", gm.rescale_wide(np.array([127, -128]), 0, 32767, 0), [4161409, -4194176])
eq("SELU x >= 0 in 2^-22: lambda * x floored by 2^3, int32 from x = 997960", gm.selu_pos(np.array([1024, 997959, 997960])),
   [2203520, 2147483023, (1 << 31) - 1])
eq("SELU_POS_SAT is the first saturating x", (gm.SELU_POS_SAT,), (997960,))
p4 = gm.Int8Params(mx=32767, shx=0, zin=0, mout=1 << 30, shout=-24, zout=0)  # x = 16 q, output multiplier 2^-25: 8 per LSB
eq("SELU x = 160 and 480 exact past Q4.11, x = 496 saturates lambda * x to 2^31 - 1", zero.run(np.array([10, 30, 31]), 1, p4), [21, 63, 64])
eq("lane rounding is sienna_fmt_pkg's REQ_ROUNDING", (gm.REQ_ROUNDING,), ("DOUBLE",))
flat = gm.Lane(gm.INT8, [192] + [0] * 31, sets={1: (0, 0)})  # P = 192 everywhere: x = -2048 gives v = -3 * 2^20, a -1.5 LSB tie
eq("SELU requantize rounds the -1.5 tie away from zero (DOUBLE; SINGLE gives 2)", flat.run(np.array([-20]), 1, p2), [1])
eq("ReLU and linear pass through", [int(v) for v in zero.run(np.array([-5, 7]), 4, p)] + [int(v) for v in zero.run(np.array([-5, 7]), 5, p)], [-5, 7, -5, 7])
eq("every case's rescale is normalized and within half a step", [int((16384 <= p.mx <= 32767 or p.shx == 31) and abs(p.mx - c.s_in * 2048 * 2.0 ** p.shx) <= 0.5) for a in ("tanh", "sigmoid", "selu") for c in gm.INT8_CASES[a] for p in [gm.int8_params(c, 3)]], [1] * 15)
eq("REL_TOL_INT8 is GPNAE's max(1%, 8 * 2^-7)", (gm.REL_TOL_INT8, gm.ABS_TOL_LSB), (0.0625, 1))
ct = gm.Case(1 / 32, 0, 1 / 128, 0, True)  # tanh golden: q = 0 -> 0, q = 32 -> 97, q = 1 -> 4
a = gm.accuracy_int8(np.array([1, 98, 99, 110, 5, 6]), np.array([0, 32, 32, 32, 1, 1]), 3, ct)
eq("tolerance: 1 LSB passes, 2/97 passes, 13/97 and 2/4 fail", (a.ok, a.fail, a.worst_rel, a.worst_lsb, round(a.real_lsb, 3), a.differ), (False, 2, 0.5, 13, 12.516, 6))
m = gm.merge_acc([a, a])
eq("merge_acc sums counts, keeps the worst", (m.ok, m.fail, m.worst_rel, m.worst_lsb, m.differ), (False, 4, 0.5, 13, 12))
cs = gm.Case(1 / 32, 0, 1 / 256, -128, True)  # sigmoid golden at q = 0: 0, i.e. 128 LSB above the zero point -128
a = gm.accuracy_int8(np.array([4, 9]), np.array([0, 0]), 2, cs)
eq("tolerance measured from the output zero point", (a.ok, a.fail, a.worst_rel, a.worst_lsb), (False, 1, 0.0703125, 9))

ROM = gm.read_rom(os.path.join(gm.ROOT, gm.coeff_file(gm.INT8)))
lad, off = gm.Lane(gm.INT8, ROM), gm.Lane(gm.INT8, ROM, ladder=False)  # the lane as built, and 2a's
eq("ladder constants: 19 rising codes from 5228 to 12773, from x = 5120",
   (gm.SIG_LAD_X0, len(gm.SIG_LAD_T), gm.SIG_LAD_T[0], gm.SIG_LAD_T[-1], int(all(np.diff(gm.SIG_LAD_T) > 0))), (5120, 19, 5228, 12773, 1))
eq("sig_ladder at its edges and the Q4.11 rail",
   gm.sig_ladder(np.array([5120, 5227, 5228, 12772, 12773, 32767, -5120, -5227, -5228, -12772, -12773, -32768])),
   [109, 109, 110, 127, 127, 127, -109, -109, -110, -127, -128, -128])
dense = gm.Case(1 / 2048, 0, 1 / 256, -128, True)  # identity rescale, sigmoid's fixed output quantization
X = np.arange(-32768, 32768, dtype=np.int64)
p_id = gm.int8_params(dense, 2)
eq("the dense sweep's rescale is the identity", int(np.sum(gm.rescale(X, 0, p_id.mx, p_id.shx) != X)), [0])
ax = np.abs(X) >= gm.SIG_LAD_X0
eq("ladder = exact_int8 at every |x| >= 2.5", int(np.sum(gm.sig_ladder(X[ax]) != gm.exact_int8(X[ax], 2, dense))), [0])
y_lad, y_off = lad.run(X, 2, p_id), off.run(X, 2, p_id)
eq("continuity at the hand-over: the ladder at +-5120 and the polynomial at +-5119 agree with the lane",
   [int(y_lad[X == v][0] == gm.sig_ladder(np.array([v]))[0]) for v in (5120, -5120)] + [int(y_lad[X == v][0] == y_off[X == v][0]) for v in (5119, -5119)],
   [1, 1, 1, 1])
eq("the lane is the ladder at every |x| >= 2.5", int(np.sum(y_lad[ax] != gm.sig_ladder(X[ax]))), [0])
eq("below 2.5 the lane is 2a's polynomial, unchanged", int(np.sum(y_lad[~ax] != y_off[~ax])), [0])
a = gm.accuracy_int8(y_lad, X, 2, dense)
eq("sigmoid dense with the ladder: 0 of 65536 outside, worst 2 LSB", (a.fail, a.worst_lsb), (0, 2))
eq("sigmoid dense without it: 2a's 3370 outside", (gm.accuracy_int8(y_off, X, 2, dense).fail,), (3370,))
q = np.arange(-128, 128, dtype=np.int64)
gated = [c for c in gm.INT8_CASES["sigmoid"] if c.gated]
g = gm.merge_acc(gm.accuracy_int8(lad.run(q, 2, gm.int8_params(c, 2)), q, 2, c) for c in gated)
eq("sigmoid gated with the ladder: 0 of 1280 outside", (g.fail, 256 * len(gated)), (0, 1280))
late = gm.Lane(gm.INT8, ROM, lad_x0=7168)  # the spec's rejected start at 3.5
eq("a ladder from 3.5 leaves 24 dense misses (spec)", (gm.accuracy_int8(late.run(X, 2, p_id), X, 2, dense).fail,), (24,))
for code, name in ((1, "selu"), (3, "tanh")):
    for c in gm.INT8_CASES[name]:
        eq(f"{name} unchanged by the ladder ({c.s_in:.4f}, {c.z_in})",
           int(np.sum(lad.run(q, code, gm.int8_params(c, code)) != off.run(q, code, gm.int8_params(c, code)))), [0])


def rtl_ladder(path=os.path.join(gm.ROOT, "src", "gpnae_poly_int8.sv")):
    """gpnae_poly_int8's SIG_LAD_X0, SIG_LAD_T (in index order; a flat vector, t_0 rightmost) and SIG_LAD_N literals."""
    s = open(path).read()
    x0 = re.findall(r"localparam\s+logic\s+signed\s+\[W-1:0\]\s+SIG_LAD_X0\s*=\s*16'sd(\d+);", s)
    n = re.findall(r"localparam\s+int\s+SIG_LAD_N\s*=\s*(\d+);", s)
    m = re.findall(r"localparam\s+logic\s+\[SIG_LAD_N\s*\*\s*W\s*-\s*1:0\]\s+SIG_LAD_T\s*=\s*\{([^}]*)\}\s*;", s)
    t = tuple(int(v) for v in reversed(re.findall(r"16'd(\d+)", m[0]))) if len(m) == 1 else None
    return (int(x0[0]) if len(x0) == 1 else None, t, int(n[0]) if len(n) == 1 else None)


# SIG_LAD_T equal to the model's fixes the literal count, so SIG_LAD_N = len(gm.SIG_LAD_T) pins it to both.
eq("gpnae_poly_int8's ladder literals are gpnae_model's (SIG_LAD_X0, SIG_LAD_T, SIG_LAD_N)", rtl_ladder(),
   (gm.SIG_LAD_X0, gm.SIG_LAD_T, len(gm.SIG_LAD_T)))

print(f"check_gpnae_model_int8: {errs} errors")
print(f"RESULT: {'PASSED' if errs == 0 else 'FAILED'}")
sys.exit(1 if errs else 0)
