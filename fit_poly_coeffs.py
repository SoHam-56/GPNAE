#!/usr/bin/env python3
"""Fits gpnae_poly's coefficient table for a narrow format and measures it as the hardware evaluates it (gpnae_model, bit-exact).
Fits as behind poly_coeffs.mem (Chebyshev, 4001 points; SELU on [-4, 0], the lane's range, where fp32 used [-3.5, 0]); sigmoid on [0, 4],
tanh(sqrt u)/sqrt u on [0, 16]; rounded to the format or fixed one at a time lowest first; degree chosen by the polynomial's own error.
Writes poly_coeffs_<fmt>.mem in the GPNAE root and in src/TYTAN/Memory. Never writes the fp32 or bf16 files; int8 fits the same forms in Q4.11 and measures them against GPNAE's tolerance."""
import argparse
import os
import sys
from collections import namedtuple

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


NAME_INT8 = {1: "selu", 2: "sigmoid", 3: "tanh"}
RANGE_INT8 = {c: abs(gpnae_model.THRESH[c]) / 2048 for c in (1, 2, 3)}  # the float lane's thresholds: SELU 4, sigmoid 3.5, tanh 4
DEGREES_INT8 = range(2, 13)
OPTIONS_INT8 = [
    "",
    "OPTIONS FOR SOHAM for an activation outside the tolerance (none implemented; the lane keeps the float lanes' forms):",
    "A. Centred, scaled operands. Evaluate each function directly on t = (x - c) / h with |t| <= 1: tanh P((|x| - 2) / 2)",
    "   on [0, 4] with the sign restored; SELU P((x + 2) / 2) on [-4, 0]; sigmoid P((|x| - 1.75) / 1.75) on [0, 3.5].",
    "   Why: fixed-point Horner multiplies each step's floor error by the operand in every later step (bound: the sum of",
    "   |t|^j ULP), and one Q4.11 step in coefficient k moves P by 2^-11 |t|^k at the range's end; the float forms'",
    "   operands reach 16 (tanh u), 3.5 (sigmoid) and 4 (SELU). With |t| <= 1 the bound is at most degree + 1 ULP, and the",
    "   power coefficients stay within Q4.11 because each function's nearest singularity is farther from the interval's",
    "   centre than its half-length (estimate, not measured). RTL: a constant subtract and a shift on the MAC operand in",
    "   place of the squarer and abs; the rest of the lane is unchanged.",
    "B. Higher degree. The rows above cover degrees 2 to 12; where the error stops falling with degree, more terms do not",
    "   help at Q4.11. Degrees past the ROM's 32 entries need a 64-entry ROM, whose address width the lane now shares",
    "   with its FIFO depth (ADDR_LINES), so the two would have to be split.",
    "C. Q-format change. Keep the operand in Q4.11 and hold coefficients and accumulator in Q1.14 (range +/-2, enough",
    "   for P of all three forms: at most 1.76): fxMac's FRAC stays 11 (Q4.11 x Q1.14 >> 11 is Q1.14), so this is a",
    "   coefficient and post-stage scaling change only; it gains 3 bits everywhere but not the operand's amplification,",
    "   and needs the partial sums within +/-2 (the max |c| column shows the coefficients' size). Or a 32-bit",
    "   accumulator (fxMac W = 32), which changes Level 1's unit and DV.",
    "D. Accept the measured accuracy for int8.",
]


def fit_form(code, r, deg):
    """The float lane's fit (target(): (e^x - 1)/x form, sigmoid, tanh(sqrt u)/sqrt u) on the operand's range, rounded to Q4.11."""
    lo, hi = {1: (-r, 0.0), 2: (0.0, r), 3: (0.0, r * r)}[code]
    t = np.linspace(lo, hi, 4001)
    c = np.polynomial.chebyshev.Chebyshev.fit(t, target(code, t), deg).convert(kind=np.polynomial.Polynomial).coef
    ints = [int(np.floor(v * 2048 + 0.5)) for v in c]
    return ints if all(-32768 <= v <= 32767 for v in ints) else None


def lane_for(code, coeffs):
    """The bit-exact lane with one coefficient set at base 0 and the model's saturation thresholds (THRESH)."""
    rom = [0] * 32
    rom[:len(coeffs)] = coeffs
    return gpnae_model.Lane(gpnae_model.INT8, [v & 0xFFFF for v in rom], sets={code: (0, len(coeffs) - 1)})


def lsb(code):
    """Output LSB per unit: tanh 128, sigmoid 256, SELU the tightest gated case's 1/s_out."""
    if code == 1:
        return 1.0 / min(c.s_out for c in gpnae_model.INT8_CASES["selu"] if c.gated)
    return 256.0 if code == 2 else 128.0


def measure_cont(code, r, coeffs):
    """Worst and mean error, in output LSB, of the unsaturated path over every Q4.11 input of the fitted range."""
    th = int(round(r * 2048))
    x = np.arange(-th, 1 if code == 1 else th + 1, dtype=np.int64)
    e = np.abs(lane_for(code, coeffs).value(x, code) - exact_act(code, x / 2048.0)) * lsb(code)
    return float(e.max()), float(e.mean())


def measure_cases(lane, code):
    """Every int8 input of every gated case against GPNAE's tolerance (gpnae_model.accuracy_int8), merged into one Acc."""
    q = np.arange(-128, 128, dtype=np.int64)
    return gpnae_model.merge_acc(gpnae_model.accuracy_int8(lane.run(q, code, gpnae_model.int8_params(c, code)), q, code, c)
                                 for c in gpnae_model.INT8_CASES[NAME_INT8[code]] if c.gated)


DENSE_X = np.arange(-8192, 8193, dtype=np.int64)  # every Q4.11 input from -4 to 4, as the lane sees it after its rescale
Cand = namedtuple("Cand", "d c dense grid nominal hsat rail")  # d, the effective degree; dense and grid, Acc; rail, the lane's


def dense_cases(code):
    """The dense sweep's output quantizations: tanh's and sigmoid's fixed one, SELU's of every gated case; s_in = 2^-11 rescales by 1."""
    if code != 1:
        return [gpnae_model.Case(1 / 2048, 0, 0.0, 0, True)]
    return [gpnae_model.Case(1 / 2048, 0, c.s_out, c.z_out, True) for c in gpnae_model.INT8_CASES["selu"] if c.gated]


def dense_run(lane, code, case):
    """The lane's int8 outputs at every DENSE_X input, through run() with an identity rescale."""
    p = gpnae_model.int8_params(case, code)
    assert (gpnae_model.rescale(DENSE_X, 0, p.mx, p.shx) == DENSE_X).all(), "the dense sweep's rescale must be the identity"
    return lane.run(DENSE_X, code, p)


def measure_dense(lane, code):
    """Every DENSE_X input against GPNAE's tolerance (gpnae_model.accuracy_int8), merged over dense_cases."""
    return gpnae_model.merge_acc(gpnae_model.accuracy_int8(dense_run(lane, code, c), DENSE_X, code, c) for c in dense_cases(code))


def uses_poly(code):
    """The DENSE_X inputs whose output comes from P: SELU -4 <= x < 0, sigmoid |x| <= 3.5, tanh |x| <= 4."""
    if code == 1:
        return (DENSE_X < 0) & (DENSE_X >= gpnae_model.T_SELU)
    return np.abs(DENSE_X) <= gpnae_model.THRESH[code]


def horner_sat(code, coeffs):
    """How many inputs whose output uses P have a Horner step whose sum leaves 16 bits, which fxMac saturates."""
    t = gpnae_model.mac_operand(DENSE_X, code)
    acc, sat = np.zeros_like(t), np.zeros(t.shape, dtype=bool)
    for c in reversed(coeffs):  # highest first, as gpnae_model.horner
        raw = ((t * acc) >> gpnae_model.Q) + c
        sat |= (raw > 32767) | (raw < -32768)
        acc = gpnae_model.ipu.fx_mac(t, acc, np.full_like(t, c), w=16, frac=gpnae_model.Q)
    return int((sat & uses_poly(code)).sum())


def rail(lane, code):
    """The smallest |x| where the lane's output is -128 or 127, and where exact_int8's is, over dense_cases; inf if never."""
    ax, lane_r, exact_r = np.abs(DENSE_X) / 2048.0, np.inf, np.inf
    for c in dense_cases(code):
        out, g = dense_run(lane, code, c), gpnae_model.exact_int8(DENSE_X, code, c)
        lane_r = min(lane_r, float(ax[(out == -128) | (out == 127)].min(initial=np.inf)))
        exact_r = min(exact_r, float(ax[(g == -128) | (g == 127)].min(initial=np.inf)))
    return lane_r, exact_r


def fmt_rail(v):
    """A rail point for the log: none if the output never rails."""
    return "none" if v == np.inf else f"{v:.4f}"


def score_dense(code, coeffs):
    """refine_int8's score: dense tolerance misses, then the worst dense |d| in LSB."""
    a = measure_dense(lane_for(code, coeffs), code)
    return a.fail, a.worst_lsb


def refine_int8(code, c, passes=10):
    """Coordinate descent on the integer coefficients by score_dense; the result is kept only if it misses fewer dense inputs."""
    start = best = score_dense(code, c)
    orig = c
    for _ in range(passes):
        improved = False
        for k in range(len(c)):
            for d in (-2, -1, 1, 2):
                trial = list(c)
                trial[k] += d
                if not -32768 <= trial[k] <= 32767:
                    continue
                w = score_dense(code, trial)
                if w < best:
                    best, c, improved = w, trial, True
        if not improved:
            break
    return c if best[0] < start[0] else orig


def strip_int8(c):
    """Zero leading (highest) coefficients removed: fx_mac(t, 0, 0) = 0, so the effective degree evaluates bit-identically."""
    c = list(c)
    while len(c) > 1 and c[-1] == 0:
        c.pop()
    return c


def pick_int8(cands):
    """The lowest degree within the tolerance, else the best measured: fewest outputs outside, then worst relative error."""
    ok = [c for c in cands if c[2].ok]
    return min(ok, key=lambda c: c[0]) if ok else min(cands, key=lambda c: (c[2].fail, c[2].worst_rel, c[0]))


def layout_int8(deg):
    """The fp32 table's layout when the degrees fit it, else the three sets packed in order; None if they exceed 32 entries."""
    d1, d2, d3 = deg[1], deg[2], deg[3]
    if d1 <= 8 and d2 <= 6 and d3 <= 15:
        return {1: (0, d1), 2: (9, d2), 3: (16, d3)}
    if d1 + d2 + d3 + 3 <= 32:
        return {1: (0, d1), 2: (d1 + 1, d2), 3: (d1 + d2 + 2, d3)}
    return None


def main_int8(a):
    out = gpnae_model.coeff_file(gpnae_model.INT8)
    assert out not in ("poly_coeffs.mem", "poly_coeffs_bf16.mem", "taylor_coeffs.mem")
    tol = f"rel <= {100 * gpnae_model.REL_TOL_INT8:.2f}% or abs <= {gpnae_model.ABS_TOL_LSB} LSB"
    L, cands, chosen = [], {}, {}
    n_dense = {c: DENSE_X.size * len(dense_cases(c)) for c in (1, 2, 3)}
    n_grid = {c: 256 * sum(k.gated for k in gpnae_model.INT8_CASES[NAME_INT8[c]]) for c in (1, 2, 3)}
    L.append("gpnae_poly int8: the float lanes' forms in Q4.11 (fxMac Horner, floor; integer post products), bit-exact model;")
    L.append("the float lane's ranges (SELU x >= -4, sigmoid |x| <= 3.5, tanh |x| <= 4), the saturated value beyond them.")
    L.append(f"GPNAE's tolerance ({tol}) on the DENSE sweep decides the choice and the verdict: every Q4.11 input x in")
    L.append("[-8192, 8192] as the lane sees it after its rescale; tanh and sigmoid at their fixed output quantization, SELU at every")
    L.append(f"gated case's (inputs: SELU {n_dense[1]}, sigmoid {n_dense[2]}, tanh {n_dense[3]}). GRID: the int8 inputs of every gated")
    L.append(f"case (Task 12's measure; SELU {n_grid[1]}, sigmoid {n_grid[2]}, tanh {n_grid[3]} inputs), kept alongside. Each degree is")
    L.append("fitted, refined by coordinate descent on the dense tolerance (kept only if it misses fewer), then stripped of zero leading")
    L.append("coefficients: deg, the fitted degree; eff, the effective one, which evaluates bit-identically. fail, outputs outside the tolerance; rel, the worst relative")
    L.append("error where |d| > 1 LSB; LSB, the worst |d| against exact_int8; real, the worst error against the unquantized function;")
    L.append("hsat, inputs whose output uses P with a Horner step that saturates; rail, the smallest |x| with output -128 or 127.")
    L.append("range max and mean: the unsaturated, unclamped path's error over the fitted range in output LSB.")
    L.append("Dense real includes the int8 clamp: SELU's s_out covers only its case's inputs, so large x rails (exact_int8 rails too).")
    L.append(f"{'activation':<10}{'deg':>4}{'eff':>4}{'dense fail':>11}{'rel %':>8}{'LSB':>5}{'real':>8}{'hsat':>6}{'rail':>7}"
             f"{'grid fail':>10}{'rel %':>8}{'LSB':>5}{'range max':>10}{'mean':>9}{'max |c|':>8}")
    for code in (1, 2, 3):
        r, cands[code] = RANGE_INT8[code], []
        for d in DEGREES_INT8:
            c = fit_form(code, r, d)
            if c is None:
                L.append(f"{NAME_INT8[code]:<10}{d:>4}  coefficients beyond Q4.11")
                continue
            c = refine_int8(code, c)
            s = strip_int8(c)
            lane = lane_for(code, s)
            dense, grid = measure_dense(lane, code), measure_cases(lane, code)
            full = lane_for(code, c)
            assert (dense, grid) == (measure_dense(full, code), measure_cases(full, code)), "stripping must not change any output"
            k = Cand(len(s) - 1, s, dense, grid, d, horner_sat(code, s), rail(lane, code)[0])
            cands[code].append(k)
            cw, cm = measure_cont(code, r, s)
            L.append(f"{NAME_INT8[code]:<10}{d:>4}{k.d:>4}{dense.fail:>11}{100 * dense.worst_rel:>8.2f}{dense.worst_lsb:>5}"
                     f"{dense.real_lsb:>8.2f}{k.hsat:>6}{fmt_rail(k.rail):>7}{grid.fail:>10}{100 * grid.worst_rel:>8.2f}"
                     f"{grid.worst_lsb:>5}{cw:>10.2f}{cm:>9.2f}{max(abs(v) for v in s) / 2048:>8.3f}")
        assert cands[code], f"{NAME_INT8[code]}: no degree from 2 to 12 has coefficients within Q4.11"
        chosen[code] = pick_int8(cands[code])
    while layout_int8({k: v[0] for k, v in chosen.items()}) is None:  # more than the ROM's 32 entries
        k = max(chosen, key=lambda c: (not chosen[c][2].ok, chosen[c][0]))  # one outside the tolerance first, then the highest degree
        lower = [c for c in cands[k] if c[0] < chosen[k][0]]
        assert lower, "degree 2 everywhere fits the ROM"
        L.append(f"{NAME_INT8[k]:<10} degree {chosen[k][0]} does not fit the 32-entry ROM beside the others: lowered")
        cands[k], chosen[k] = lower, pick_int8(lower)
    missed = [NAME_INT8[c] for c in (1, 2, 3) if not chosen[c].dense.ok]
    for code in (1, 2, 3):
        k = chosen[code]
        dn, gr = k.dense, k.grid
        fig = (f"dense {dn.fail} of {n_dense[code]} outside, worst {100 * dn.worst_rel:.2f}% where |d| > 1 LSB, worst {dn.worst_lsb} LSB,"
               f" {dn.real_lsb:.2f} LSB against the unquantized function; grid {gr.fail} of {n_grid[code]} outside, worst"
               f" {100 * gr.worst_rel:.2f}%, worst {gr.worst_lsb} LSB")
        if dn.ok:
            L.append(f"{NAME_INT8[code]:<10} chosen: degree {k.d} (fitted at {k.nominal}), the lowest within the tolerance: MEETS TOLERANCE ({fig})")
        else:
            L.append(f"{NAME_INT8[code]:<10} chosen: degree {k.d} (fitted at {k.nominal}), the best by dense misses: MISSES TOLERANCE ({fig}):"
                     " open accuracy item")
    lay = layout_int8({k: v[0] for k, v in chosen.items()})
    table = [0] * 32
    for code, (base, d) in lay.items():
        table[base:base + d + 1] = chosen[code].c
    lane = gpnae_model.Lane(gpnae_model.INT8, [v & 0xFFFF for v in table], sets=lay)
    L.append("")
    L.append(f"whole table, SETS_INT8 = {lay}, dense sweep (the verdict's figures): every Q4.11 input in [-8192, 8192]")
    L.append(f"{'activation':<10}{'inputs':>8}{'fail':>6}{'rel %':>8}{'LSB':>5}{'real':>8}{'differ':>7}{'hsat':>6}{'lane rail':>10}"
             f"{'exact rail':>11}")
    for code in (1, 2, 3):
        dn = measure_dense(lane, code)
        assert dn == chosen[code].dense, "the packed table must reproduce each activation's dense measurement"
        lr, er = rail(lane, code)
        L.append(f"{NAME_INT8[code]:<10}{n_dense[code]:>8}{dn.fail:>6}{100 * dn.worst_rel:>8.2f}{dn.worst_lsb:>5}{dn.real_lsb:>8.2f}"
                 f"{dn.differ:>7}{horner_sat(code, chosen[code].c):>6}{fmt_rail(lr):>10}{fmt_rail(er):>11}")
    L.append("")
    L.append(f"whole table, SETS_INT8 = {lay}, grid: every int8 input of every case against the tolerance (int8 LSB)")
    L.append(f"{'activation':<10}{'s_in':>11}{'z_in':>6}{'s_out':>11}{'z_out':>6}{'fail':>6}{'rel %':>8}{'LSB':>5}"
             f"{'real':>7}{'differ':>7}{'gated':>7}")
    q = np.arange(-128, 128, dtype=np.int64)
    for code in (1, 2, 3):
        gated = []
        for case in gpnae_model.INT8_CASES[NAME_INT8[code]]:
            acc = gpnae_model.accuracy_int8(lane.run(q, code, gpnae_model.int8_params(case, code)), q, code, case)
            L.append(f"{NAME_INT8[code]:<10}{case.s_in:>11.6f}{case.z_in:>6}{case.s_out:>11.6f}{case.z_out:>6}{acc.fail:>6}"
                     f"{100 * acc.worst_rel:>8.2f}{acc.worst_lsb:>5}{acc.real_lsb:>7.2f}{acc.differ:>7}"
                     f"{'yes' if case.gated else 'no':>7}")
            if case.gated:
                gated.append(acc)
        assert gpnae_model.merge_acc(gated) == chosen[code].grid, "the packed table must reproduce each activation's grid measurement"
    L.append("VERDICT: TOLERANCE MET for every activation on the dense sweep" if not missed else
             f"VERDICT: TOLERANCE MISSED for {', '.join(missed)} on the dense sweep: best degrees kept; open accuracy item for Soham, not a stop")
    if missed:
        L += OPTIONS_INT8
    for path in (os.path.join(ROOT, out), os.path.join(ROOT, "src", "TYTAN", "Memory", out)):
        with open(path, "w") as fh:
            fh.write("".join(format(v & 0xFFFF, "016b") + "\n" for v in table))
    os.makedirs(os.path.dirname(os.path.abspath(a.report)), exist_ok=True)
    open(a.report, "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    if lay != gpnae_model.SETS_INT8:
        print(f"UPDATE gpnae_model.SETS_INT8 = {lay} and gpnae_poly_int8's BASE_*/DEG_*, then rerun")
        return 3
    return 0


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--format", required=True, choices=sorted(gpnae_model.FORMATS))
    p.add_argument("--report", default=os.path.join(ROOT, "testbenches", "results", "poly_coeffs_fit.log"))
    a = p.parse_args()
    if a.format in ("fp32", "bf16"):
        name = gpnae_model.coeff_file(gpnae_model.FORMATS[a.format])
        print(f"refusing to write {a.format} coefficients: {name} is published and fixed")
        sys.exit(1)
    if a.format == "int8":
        sys.exit(main_int8(a))
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
