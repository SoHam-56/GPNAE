#!/usr/bin/env python3
"""Known values for gpnae_model's int8 lane: rounding and saturation of each step, the fixed output quantizations, SELU's block-floating x through the requantizer."""
import os
import re
import sys

import numpy as np

import gpnae_model as gm
import fit_poly_coeffs as fpc

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
p2 = gm.Int8Params(26214, 8, 0, *gm.selu_out_params(0.05, 26214, 0.05), 3)  # s_in = s_out = 0.05: lambda * 0.5 / 0.05 = 10.5 -> 11, + 3
eq("selu_out_params(0.05, 26214, 0.05) is QuantizeMultiplier(s_in / (2^7 mx s_out))", gm.selu_out_params(0.05, 26214, 0.05), (1342197760, -21))
eq("SELU x >= 0: r * lambda >>> 7, requantized", zero.run(np.array([10, 0]), 1, p2), [14, 3])
eq("SELU -4 <= x < 0: r * P = 0 with a zero table", zero.run(np.array([-5]), 1, p2), [3])
p3 = gm.Int8Params(mx=26214, shx=7, zin=0, mout=1 << 30, shout=-19, zout=3)  # s_in = 0.1; output multiplier 2^-20
eq("SELU x = -4 inside, x < -4: -lambda*alpha 2^shx * 1.0 >>> 4 = -3601 * 2^14, times 2^-20 is -56.3", zero.run(np.array([-40, -41, -71]), 1, p3), [3, -53, -53])
eq("rescale_product is exact", gm.rescale_product(np.array([127, -128]), 0, 32767), [4161409, -4194176])
eq("selu_acc at the extremes stays inside int32: d 255 at any shx, d -255 at shx 0, 9 (x < -4) and 31 (r * P)",
   [int(gm.selu_acc(np.array([127]), -128, 32767, s, np.array([3451]))[0]) for s in (0, 31)]
   + [int(gm.selu_acc(np.array([-128]), 127, 32767, s, np.array([3451]))[0]) for s in (0, 9, 31)],
   [1123760904, 1123760904, -460928, -235995136, -1802195240])
p4 = gm.Int8Params(32767, 0, 0, *gm.selu_out_params(32767 / 2048, 32767, 8.0), 0)  # x = 16 q, s_out 8
eq("SELU past 512 is exact: x = 160, 480 and 496 give 21, 63 and 65 (the int32 saturation gave 64)", zero.run(np.array([10, 30, 31]), 1, p4), [21, 63, 65])
eq("lane rounding is sienna_fmt_pkg's REQ_ROUNDING", (gm.REQ_ROUNDING,), ("DOUBLE",))
flat = gm.Lane(gm.INT8, [192] + [0] * 31, sets={1: (0, 0)})  # P = 192 everywhere: r = -16 * 2^14 gives acc -3 * 2^20, a -1.5 LSB tie at 2^-21
eq("SELU requantize rounds the -1.5 tie away from zero (DOUBLE; SINGLE gives 2)", flat.run(np.array([-16]), 1, gm.Int8Params(16384, 5, 0, 1 << 30, -20, 3)), [1])
eq("selu_out_params: a left shift becomes (2^31 - 1, 0); mx 0 gives (0, 0)", gm.selu_out_params(0.05, 26214, 0.05 * 2.0 ** -27) + gm.selu_out_params(1e-14, 0, 1e-14),
   ((1 << 31) - 1, 0, 0, 0))
eq("ReLU is max(q, z_in), linear passes through", [int(v) for v in zero.run(np.array([-5, 7, -128, 127]), 4, p._replace(zin=-3))]
   + [int(v) for v in zero.run(np.array([-5, 7, 3, 4]), 4, p._replace(zin=4))] + [int(v) for v in zero.run(np.array([-5, 7]), 5, p._replace(zin=4))],
   [-3, 7, -3, 127, 4, 7, 4, 4, -5, 7])
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
eq("SELU's table (ROM 0-2) is fit_poly_coeffs' relative-minimax fit, 4.16% worst", (lad.rom[:3], fpc.fit_selu_rel(2), round(100 * fpc.selu_rel_err(lad.rom[:3]), 2)),
   ([3451, 1238, 151], [3451, 1238, 151], 4.16))
fine = gm.selu_case(1e-5, 0)  # s_out 1.405e-5, z_out 32: one Q4.11 step of x is 35 output LSB
eq("SELU at s_in 1e-5, below Q4.11's step: q -25, -24, 24, 25 give 2, 3, 50, 51 (true 1, 2, 50, 51; the rounded x gave -27, 32, 32, 69)",
   lad.run(np.array([-25, -24, 24, 25]), 1, gm.int8_params(fine, 1)), [2, 3, 50, 51])
big = gm.Case(6609 / 2048, -128, 2.801, -128, True)  # the old regression's positive set 99
eq("SELU past lambda x = 512: set 99's q 48 and 100 give 85 and 127, as exact_int8 (the saturation gave 55)",
   [int(v) for v in lad.run(np.array([48, 100]), 1, gm.int8_params(big, 1))] + [int(v) for v in gm.exact_int8(np.array([48, 100]), 1, big)], [85, 127, 85, 127])
eq("ladder constants: 19 rising codes from 5228 to 12773, from x = 5120",
   (gm.SIG_LAD_X0, len(gm.SIG_LAD_T), gm.SIG_LAD_T[0], gm.SIG_LAD_T[-1], int(all(np.diff(gm.SIG_LAD_T) > 0))), (5120, 19, 5228, 12773, 1))
eq("the ladder's thresholds, computed from sigmoid, are gpnae_model's", fpc.sig_ladder_thresholds(), gm.SIG_LAD_T)
def raises(f):
    try:
        f()
    except RuntimeError as e:
        return str(e)
    return None


np_exp = fpc.np.exp
try:
    fpc.np.exp = lambda a, e=np_exp: e(100 * a)  # a wrong sigmoid: steps larger than 1
    with np.errstate(over="ignore"):  # exp(100 x) overflows to inf, as a wrong sigmoid would
        bad = raises(lambda: fpc.sig_ladder_thresholds(0))
finally:
    fpc.np.exp = np_exp
eq("sig_ladder_thresholds raises on a step larger than 1, and np.exp is restored", (bad is not None and "steps" in bad, fpc.np.exp is np_exp), (True, True))
eq("sig_ladder_thresholds raises RuntimeError for x0 > 32766", (raises(lambda: fpc.sig_ladder_thresholds(32767)) is not None,), (True,))
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
sv = open(os.path.join(gm.ROOT, "src", "gpnae_poly_int8.sv")).read()
eq("gpnae_poly_int8's SELU accumulator slices are gpnae_model's shifts (pm_res[31 + 4 : 4] for P, [31 + 7 : 7] for lambda)",
   tuple(re.findall(r"assign rq_acc = neg_buf\[ps_p\[MUL_LAT\]\] \? pm_res\[(\d+):(\d+)\] : pm_res\[(\d+):(\d+)\];", sv)),
   (tuple(str(v) for v in (31 + gm.SELU_SH_P, gm.SELU_SH_P, 31 + gm.SELU_SH_LAMBDA, gm.SELU_SH_LAMBDA)),))

print(f"check_gpnae_model_int8: {errs} errors")
print(f"RESULT: {'PASSED' if errs == 0 else 'FAILED'}")
sys.exit(1 if errs else 0)
