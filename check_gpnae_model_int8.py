#!/usr/bin/env python3
"""Known values for gpnae_model's int8 lane: rounding and saturation of each step, the fixed output quantizations, SELU through the requantizer."""
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
eq("sigmoid, zero table: P = 0, 1 - P = 1 inside +/-3.5, saturated outside", zero.run(np.array([70, 71, -70, -71]), 2, p), [-128, 127, 127, -128])
p2 = gm.Int8Params(mx=26214, shx=8, zin=0, mout=1 << 30, shout=-20, zout=3)  # output multiplier 2^-21
eq("SELU x >= 0: lambda x, requantized", zero.run(np.array([10, 0]), 1, p2), [11, 3])
eq("SELU -4 <= x < 0: x * P = 0 with a zero table", zero.run(np.array([-5]), 1, p2), [3])
p3 = gm.Int8Params(mx=26214, shx=7, zin=0, mout=1 << 30, shout=-20, zout=3)  # s_in = 0.1
eq("SELU x = -4 inside, x < -4: -lambda*alpha, requantized", zero.run(np.array([-40, -41, -71]), 1, p3), [3, -25, -25])
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

print(f"check_gpnae_model_int8: {errs} errors")
print(f"RESULT: {'PASSED' if errs == 0 else 'FAILED'}")
sys.exit(1 if errs else 0)
