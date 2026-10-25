#!/usr/bin/env python3
"""GPNAE regression: the gpnae lane under Verilator, in a format and a tier, bit for bit against gpnae_model (required: SIENNA's goldens
compose the model) and every RTL output gated on the true function at the tier's tolerance (truefn, the decimal rule
|hw - t| <= max(tol |t|, one step)). Writes testbenches/stimulus/*, runs make verilator FMT=<f> with the run's size and tier as plusargs.

Runs (--run): gate (the gate inputs: every finite bf16 input; fp32 a dense grid, random patterns and every bound's neighbours; int8 every
code at every set, the scale sweeps included, and the protocol stream), protocol (random batches of 30 under output back-pressure, ReLU
and linear too), load (the image of loaded_image() written through the load path after every reset), cycles (steady-state cycles per
element on N(0,1), U[-8, 8] and the slowest inputs, against gpnae_fit_study.log's estimates), fault4 and fault5 (FAULT 4 and 5 must
fire their assertions). make regression runs its points through ArithmeticLibrary's engine (--action)."""

import argparse
import os
import re
import subprocess
import sys
import time

import numpy as np

import gpnae_model as gm

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(ROOT, "ArithmeticLibrary", "Common", "models"))
import truefn  # noqa: E402  the true-function gate library
TB_DIR = os.path.join(ROOT, "testbenches")
STIM_DIR = os.path.join(TB_DIR, "stimulus")
RESULTS_DIR = os.path.join(TB_DIR, "results")
MAX_SIGNALS = 32  # the lane's FIFO depth: one batch at most
FORMATS = ("fp32", "bf16", "int8")
FLOAT_ACTS = ("selu", "sigmoid", "tanh")
ALL_ACTS = FLOAT_ACTS + ("relu", "linear")
CODES = {"selu": 1, "sigmoid": 2, "tanh": 3, "relu": 4, "linear": 5}
INT8_ACTS = tuple((a, CODES[a]) for a in ALL_ACTS)  # the TB's order


def run_args(batches, per_batch, tier=0, timeout=400000):
    """The run's size and tier, as TB_gpnae's plusargs (one build serves every run of a format)."""
    return f"+batches={batches} +per_batch={per_batch} +tier={tier} +timeout={timeout}"


def width(fmt):
    return {"fp32": 32, "bf16": 16, "int8": 8}[fmt]


def write_words(path, v, w):
    nd, m = w // 4, (1 << w) - 1
    with open(path, "w") as fh:
        fh.write("".join(f"{int(b) & m:0{nd}x}\n" for b in v))


def read_words(path):
    with open(path) as fh:
        return np.array([int(ln, 16) for ln in fh if ln.strip()], dtype=np.int64)


def run_make(fmt, sim_args="", extra=""):
    """Build (once per format and EXTRA_FLAGS: Verilator skips an identical rebuild) and run TB_gpnae in fmt through make verilator; returns
    (log, seconds)."""
    t0 = time.time()
    cmd = ["make", "verilator", f"FMT={fmt}", f"SIM_ARGS={(os.environ.get('SIM_ARGS', '') + ' ' + sim_args).strip()}"]
    if extra:
        cmd.append(f"EXTRA_FLAGS={extra}")
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    return r.stdout + r.stderr, time.time() - t0


def parse_log(raw, expect_total, acts):
    """The per-activation RESULT lines and the overall verdict; a short or absent run is NO-RESULTS."""
    per = {}
    for m in re.finditer(r"RESULT (\w+) : total (\d+)\s+exact (\d+)\s+failed (\d+)\s+missing (\d+)", raw):
        a, tot, ex, fail, miss = m.groups()
        per[a] = dict(total=int(tot), exact=int(ex), failed=int(fail), missing=int(miss))
    short = [f"{len(per)} of {len(acts)} activations reported"] if set(per) != set(acts) else []
    short += [f"{a} checked {p['total']} of {expect_total}" for a, p in per.items() if p["total"] != expect_total]
    status = "NO-RESULTS" if short else ("PASS" if "RESULT: PASSED" in raw and all(p["failed"] + p["missing"] == 0 for p in per.values())
                                         else "FAIL")
    if not per and "%Error" in raw:
        status = "BUILD-ERROR"
    return dict(status=status, per=per, short=short)


# ── the true-function gate ──

def gate(fmt, act, x, got, tol, quant=None):
    """truefn's activation gate at tol on the RTL's words; quant = (s_in, z_in, s_out, z_out) per input in int8."""
    return truefn.check_activation(fmt, act, x, got, quant=quant, bound=tol)


def gate_line(r, tol):
    w = f"{100 * r.worst:.4f}%" if np.isfinite(r.worst) else "unbounded"
    return f"TRUTH {r.fmt} {r.kind}: {'PASS' if r.ok else 'FAIL'}  n {r.n}  worst {w}  over {100 * tol:g}%: {r.miss}  over 1%: {r.over_target}"


def show_misses(r):
    return [f"        miss: element {f[0]}  in {f[1]}  out {f[-1]}" for f in r.first[:4]]


# ── gate inputs ──

def bounds_edges(fmt):
    """Every descriptor bound of every tier in the default image and tanh's tiny threshold, +-2 words, both signs (fp32 words)."""
    m = gm.default_mem(fmt)
    b = {d.bounds[j] for row in m.desc for d in row for j in range(min(max(d.np, 1), gm.PMAX))}
    b.add(gm.TANH_TINY[23])
    e = [v + k for v in b for k in (-2, -1, 0, 1, 2)]
    return np.array(e + [v | (1 << 31) for v in e], dtype=np.int64)


N_FP32_GRID, N_FP32_RAND = 1 << 17, 1 << 20


def fp32_dense_inputs(seed):
    """fp32's gate inputs: a 2^17 + 1 point grid over [-16, 16], 2^19 random finite bit patterns, 2^19 uniform in [-20, 20], 2^17 uniform in
    [-110, 110], powers of two, the format's ends and every bound's neighbours, padded to whole batches."""
    rng = np.random.default_rng([seed, 17])
    grid = truefn.encode("fp32", np.linspace(-16.0, 16.0, N_FP32_GRID + 1))
    pat = rng.integers(0, 1 << 32, N_FP32_RAND, dtype=np.int64)
    pat = pat[((pat >> 23) & 0xFF) != 0xFF][:N_FP32_RAND // 2]
    uni = truefn.encode("fp32", rng.uniform(-20.0, 20.0, N_FP32_RAND // 2))
    far = truefn.encode("fp32", rng.uniform(-110.0, 110.0, N_FP32_RAND // 8))
    pow2 = [1 << k for k in range(23)] + [e << 23 for e in range(1, 255)]
    tops = [0x7F7FFFFF - k for k in range(4)] + [0x007FFFFF - k for k in range(4)] + [0x00800000 + k for k in range(4)] + [0]
    edges = np.array(pow2 + tops, dtype=np.int64)
    x = np.concatenate([grid, pat, uni, far, edges, edges | (1 << 31), bounds_edges("fp32")]) & 0xFFFFFFFF
    pad = -x.size % MAX_SIGNALS
    return np.concatenate([x, truefn.encode("fp32", rng.uniform(-16.0, 16.0, pad))])


def float_gate_inputs(fmt, seed=1):
    if fmt == "bf16":
        return gm.finite_inputs(gm.fpu.BF16)  # 65280, a whole number of batches
    return fp32_dense_inputs(seed)


# ── int8 sets: (kind, case or None, params, the 256 inputs) per activation ──

N_RAND_INT8, N_SAT_INT8 = 32, 8  # random lane parameter sets per activation, and how many saturate the rescale
N_LARGE_INT8 = 64  # SELU's large-scale sets: z_in -128, s_in 1 to 15.99 (Q4.11's limit), calibrated, half clamping at the top
N_SWEEP_INT8 = 64  # s_in log-spaced 1/128 to 1/8, every int8 input
N_FINE_INT8 = 40  # s_in log-spaced 1e-7 to 1e-2, below and around Q4.11's step 2^-11
N_STUDY_INT8 = 144  # gpnae_fit_study.log 2.6's sweep: 72 log-uniform scales in [1e-4, 8], random z_in, then z_in = 0
EDGE_SELU = ((0.016, 127, 0.1125, 0), (0.0171, 127, 0.0908, 127), (0.0256, 63, 0.1055, 0), (0.0219, 64, 0.128, -36),
             (0.05, 0, 0.05 * 2.0 ** -27, 0), (3.0, -128, 3.0 * 2.0 ** -30, 127))  # SELU near its saturation, then s_out << s_in
N_EDGE_INT8 = len(EDGE_SELU)
INT8_OUT = {2: (1 / 256, -128), 3: (1 / 128, 0)}  # sigmoid's and tanh's fixed output quantization (a convention of the converters)
STREAM_POLY = ((0, 20), (0, 17), (0, 1), (0, 16), (2, 16), (2, 16), (2, 5), (1, 16), (1, 5), (1, 1), (1, 32), (0, 32), (1, 2),
               (0, 16), (2, 1))  # (mode, elements): 0 puts with last on the final one, 1 the final put held back, 2 puts while busy
STREAM_BYP = ((0, 20), (0, 17), (0, 1), (0, 16), (2, 8), (1, 16), (1, 5), (1, 1), (1, 32), (0, 32), (1, 2), (0, 16),
              (2, 1))  # ReLU and linear emit soon after capture, so a busy group is at most 8
S_IDLE, S_NEXT, LANE_K = 0, 9, 16  # gpnae's G_IDLE and G_NEXT encodings, and its group size


def rand_params_int8(rng, code, sat):
    """A random lane parameter set; sat makes mx / 2^shx >= 256, so inputs with |q - z_in| >= 128 saturate Q4.11."""
    mx = int(rng.integers(1 << 14, 1 << 15)) if sat else int(rng.integers(0, 1 << 15))
    shx = int(rng.integers(0, 7)) if sat else int(rng.integers(8, 21))
    zin = int(rng.integers(-128, 128))
    if code == 1:
        return gm.Int8Params(mx, shx, zin, int(rng.integers(1 << 23, 1 << 24)), int(rng.integers(24, 56)), int(rng.integers(-128, 128)))
    return gm.Int8Params(mx, shx, zin, 0, 0, 0)


def study_case(code, k):
    """The study's sweep, case k of 144 (int8.py's scales())."""
    rs = np.random.RandomState(5)
    s = np.sort(np.exp(rs.uniform(np.log(1e-4), np.log(8.0), 70)))
    s = np.concatenate([[1e-4], s, [8.0]])
    z = rs.randint(-128, 128, size=s.size)
    a, b = (s[k], z[k]) if k < 72 else (s[k - 72], 0)
    return gm.selu_case(float(a), int(b)) if code == 1 else gm.Case(float(a), int(b), *INT8_OUT[code], True)


def int8_sets(seed):
    """Every lane parameter set the int8 gate run drives, per activation in stimulus order."""
    rs = np.random.RandomState(seed)
    rr = np.random.default_rng([seed, 12])
    rp = np.random.default_rng([seed, 14])
    rf = np.random.default_rng([seed, 17])
    rw = np.random.default_rng([seed, 16])
    large = [gm.Case(float(s), -128, *gm.calib_out(0.0, gm.LAMBDA_F * 255 * float(s) * (1.0 if k % 2 else float(rp.uniform(0.25, 1.0)))), True)
             for k, s in enumerate(np.geomspace(1.0, 15.99, N_LARGE_INT8))]
    large_q = [rp.permutation(256).astype(np.int64) - 128 for _ in large]
    fine = [gm.selu_case(float(s), int(rf.integers(-128, 128))) for s in np.geomspace(1e-7, 1e-2, N_FINE_INT8)] + [gm.Case(*e, True) for e in EDGE_SELU]
    fine_q = [rf.permutation(256).astype(np.int64) - 128 for _ in fine]
    sweep = [gm.Int8Params(*gm.rescale_params(float(s)), int(rw.integers(-64, 65)), 0, 0, 0) for s in np.geomspace(1 / 128, 1 / 8, N_SWEEP_INT8)]
    sweep_q = [rw.permutation(256).astype(np.int64) - 128 for _ in sweep]
    out = {}
    for act, code in INT8_ACTS:
        sets = [("case", c, gm.int8_params(c, code), rs.permutation(256).astype(np.int64) - 128) for c in gm.INT8_CASES[act]]
        sets += [("random", None, rand_params_int8(rr, code, k < N_SAT_INT8), rr.permutation(256).astype(np.int64) - 128) for k in range(N_RAND_INT8)]
        own = lambda c: c  # every activation gates on the set's float scales (int8_quant), never on the rescale the hardware encodes
        sets += [("large", own(c), gm.int8_params(c, code), q) for c, q in zip(large, large_q)]
        sets += [("sweep", None, p, q) for p, q in zip(sweep, sweep_q)]
        sets += [("fine" if k < N_FINE_INT8 else "edge", own(c), gm.int8_params(c, code), q) for k, (c, q) in enumerate(zip(fine, fine_q))]
        if code <= 3:
            for k in range(N_STUDY_INT8):
                c = study_case(code, k)
                sets.append(("study", c, gm.int8_params(c, code), np.random.default_rng([seed, 18, k]).permutation(256).astype(np.int64) - 128))
        else:  # ReLU and linear: as many sets, so every activation runs the same batches
            sets += [("study", None, gm.Int8Params(*gm.rescale_params(0.05), z, 0, 0, 0), np.arange(-128, 128, dtype=np.int64))
                     for z in (0, 77)] * (N_STUDY_INT8 // 2)
        out[act] = sets
    return out


N_HELD_INT8 = 256  # held-out sets per activation: every z_in once, each at its own log-uniform s_in in [2^-20, 15.99] (both ends included)
SWEEP_ENDS = (2.0 ** -20, 15.99)  # the forced ends of fit_poly_coeffs' seed-2 sweep, which the fit reads
HELD_ENDS = (1.5 * 2.0 ** -20, 15.98)  # the held-out gate's forced ends: as extreme, at scales no fit set reads


def int8_held_sets(seed, ends=HELD_ENDS):
    """The held-out int8 sets: no fit or gate set chose them (fit_poly_coeffs.py reads int8_sets(1) and int8_held_sets(2, SWEEP_ENDS), never
    these); with ends=SWEEP_ENDS, the fit's own sweep, which skips the check."""
    rng = np.random.default_rng([seed, 31])
    s = np.exp(rng.uniform(np.log(2.0 ** -20), np.log(15.99), N_HELD_INT8))
    s[:2] = ends
    z = rng.permutation(256) - 128
    seen, seen_s = set(), set()
    if ends != SWEEP_ENDS:  # disjoint from every set the fit reads: the gate's and the seed-2 sweep's, by (s_in, z_in) and by scale
        fit = [c for v in int8_sets(1).values() for _, c, _, _ in v if c is not None]
        fit += [c for v in int8_held_sets(2, SWEEP_ENDS).values() for _, c, _, _ in v]
        seen, seen_s = {(round(c.s_in, 12), c.z_in) for c in fit}, {float(c.s_in) for c in fit}
        assert not {float(x) for x in s} & seen_s, "a held-out scale is one the fit reads"
    out = {}
    for act, code in INT8_ACTS:
        sets = []
        for k in range(N_HELD_INT8):
            c = (gm.selu_case(float(s[k]), int(z[k])) if code == 1 else gm.Case(float(s[k]), int(z[k]), *INT8_OUT[code], True)) if code <= 3 \
                else gm.Case(float(s[k]), int(z[k]), float(s[k]), int(z[k]), True)
            assert (round(c.s_in, 12), c.z_in) not in seen, "a held-out set is a gate set"
            sets.append(("held", c, gm.int8_params(c, code) if code <= 3 else gm.Int8Params(*gm.rescale_params(float(s[k])), int(z[k]), 0, 0, 0),
                         rng.permutation(256).astype(np.int64) - 128))
        out[act] = sets
    return out


def fp32_held_inputs(seed):
    """The held-out fp32 inputs: fresh random words (2^19 finite bit patterns, 2^18 uniform in [-20, 20], 2^16 in [-110, 110]) of another seed."""
    rng = np.random.default_rng([seed, 41])
    pat = rng.integers(0, 1 << 32, N_FP32_RAND, dtype=np.int64)
    pat = pat[((pat >> 23) & 0xFF) != 0xFF][:N_FP32_RAND // 2]
    x = np.concatenate([pat, truefn.encode("fp32", rng.uniform(-20.0, 20.0, N_FP32_RAND // 2)),
                        truefn.encode("fp32", rng.uniform(-110.0, 110.0, N_FP32_RAND // 8))]) & 0xFFFFFFFF
    return np.concatenate([x, truefn.encode("fp32", rng.uniform(-16.0, 16.0, -x.size % MAX_SIGNALS))])


def int8_quant(code, case, p):
    """(s_in, z_in, s_out, z_out) of a set: a case's own float scales (sigmoid's and tanh's output their fixed quantization, ReLU and linear
    their input's); otherwise the scales its integers encode."""
    if case is not None:
        if code in INT8_OUT:
            return (case.s_in, case.z_in) + INT8_OUT[code]
        if code != 1:
            return case.s_in, case.z_in, case.s_in, case.z_in
        return case.s_in, case.z_in, case.s_out, case.z_out
    s_in = p.mx * 2.0 ** -p.shx / 2048
    if code == 1:  # requantize: q = acc mout 2^-shout, acc = x 2^(shx + 18), x = (q - z_in) s_in, s_in = mx 2^-(shx + 11)
        s_out = s_in * 2.0 ** (p.shout - 7) / (p.mx * p.mout) if p.mout and p.mx else np.inf
        return s_in, p.zin, s_out, p.zout
    if code in INT8_OUT:
        return (s_in, p.zin) + INT8_OUT[code]
    return s_in, p.zin, s_in, p.zin  # ReLU and linear pass the code through


def stream_starts(mode, n):
    """The group starts one stream group should produce, as (state it starts from, size)."""
    first, via = min(LANE_K, n), (S_NEXT if mode == 2 else S_IDLE)
    out, left = [(via, first)], n - first
    while left:
        out.append((S_NEXT, min(LANE_K, left)))
        left -= out[-1][1]
    return out


def par_line(p):
    return f"{p.mx:04x}{p.shx:02x}{p.zin & 0xFF:02x}{p.mout:08x}{p.shout & 0xFF:02x}{p.zout & 0xFF:02x}\n"


def write_stream_int8(lane, rng, tier):
    """stream_*.mem for TB_gpnae's protocol edges: every control word, a gated case and a saturating random set each."""
    segs = []
    for act, code in INT8_ACTS:
        segs.append((code, gm.int8_params(gm.INT8_CASES[act][0], code), gm.INT8_CASES[act][0]))
        if code <= 3:
            segs.append((code, rand_params_int8(rng, code, True), None))
    tc = gm.INT8_CASES["tanh"][1]
    segs += [(cw, gm.int8_params(tc, 3), tc) for cw in (0, 6, 7)]  # every other control word runs tanh
    seg_l, grp_l, bnd, q_all, y_all, funcs, quants = [], [], [], [], [], [], []
    for cw, p, case in segs:
        script = STREAM_BYP if cw in (4, 5) else STREAM_POLY
        n_el = sum(n for _, n in script)
        q = np.concatenate([rng.permutation(256) for _ in range(-(-n_el // 256))]).astype(np.int64)[:n_el] - 128
        q_all += [int(v) for v in q]
        y_all += [int(v) for v in lane.run(q, cw, p, tier)]
        code = cw if cw in (1, 2, 4, 5) else 3
        funcs += [INT8_ACTS[code - 1][0]] * n_el
        quants += [int8_quant(code, case, p)] * n_el
        seg_l.append(f"{cw:02x}{len(script):02x}" + par_line(p))
        for mode, n in script:
            grp_l.append(f"{mode:02x}{n:02x}{len(bnd):04x}\n")
            bnd += stream_starts(mode, n)
    files = {"stream_seg.mem": seg_l, "stream_grp.mem": grp_l, "stream_in.mem": [f"{v & 0xFF:02x}\n" for v in q_all],
             "stream_exp.mem": [f"{v & 0xFF:02x}\n" for v in y_all], "stream_bnd.mem": [f"{v:02x}{s:02x}\n" for v, s in bnd],
             "stream_cnt.mem": [f"{v:08x}\n" for v in (len(seg_l), len(grp_l), len(q_all), len(bnd))]}
    for name, lines in files.items():
        with open(os.path.join(STIM_DIR, name), "w") as fh:
            fh.write("".join(lines))
    return {"elements": len(q_all), "starts": len(bnd), "q": np.array(q_all), "func": np.array(funcs),
            "quant": [np.array([x[k] for x in quants]) for k in range(4)]}


# ── one TB run ──

def rtl_words(act, n):
    try:
        got = read_words(os.path.join(STIM_DIR, f"{act}_got.mem"))
    except (OSError, ValueError) as e:
        print(f"      TRUTH {act}: FAIL, no RTL words ({e})")
        return None
    if got.size != n:
        print(f"      TRUTH {act}: FAIL, {got.size} RTL words for {n} inputs")
        return None
    return got


def clear_got(names):
    for a in names:
        p = os.path.join(STIM_DIR, f"{a}_got.mem")
        if os.path.exists(p):
            os.remove(p)


def lane_for(fmt, mem=None):
    return gm.Lane(gm.FORMATS[fmt], mem)


def save_log(name, raw):
    with open(os.path.join(RESULTS_DIR, name), "w") as fh:
        fh.write(raw)


def run_float(fmt, tier, x, acts, mem=None, sim_args="", tol=None, label="run", per_batch=MAX_SIGNALS):
    """One float TB run of inputs x (a whole number of batches) through acts at tier: the expected words from the model of mem; the RTL's
    words gated at tol (default the tier's). Returns (ok, lines, results)."""
    tol = gm.TIER_TOL[tier] if tol is None else tol
    lane = lane_for(fmt, mem)
    w = width(fmt)
    sz = run_args(x.size // per_batch, per_batch, tier)
    for a in acts:
        write_words(os.path.join(STIM_DIR, f"{a}_in.mem"), x, w)
        write_words(os.path.join(STIM_DIR, f"{a}_exp.mem"), lane.run(x, CODES[a], tier), w)
    clear_got(acts)
    raw, wall = run_make(fmt, sz + " +dump_got" + (" +all_acts" if len(acts) > 3 else "") + (" " + sim_args if sim_args else ""))
    save_log(f"{label}_{fmt}_t{tier}.log", raw)
    parsed = parse_log(raw, x.size, acts)
    lines = [f"  {label} {fmt} tier {tier}: {x.size} inputs x {len(acts)} activations, {wall:.0f} s, TB {parsed['status']}"]
    lines += [f"    BITEXACT {a}: {p['exact']}/{p['total']} exact, {p['failed']} wrong, {p['missing']} missing" for a, p in parsed["per"].items()]
    lines += [f"    {s}" for s in parsed["short"]]
    ok = parsed["status"] == "PASS"
    res = {}
    for a in acts:
        got = rtl_words(a, x.size)
        if got is None:
            ok = False
            continue
        r = gate(fmt, a, x, got, tol)
        res[a] = r
        lines.append("    " + gate_line(r, tol))
        lines += show_misses(r) if not r.ok else []
        ok &= r.ok
    return ok, lines, res


def write_int8_stim(lane, sets, tier):
    per = MAX_SIGNALS
    for act, code in INT8_ACTS:
        stim, gold, par = [], [], []
        for _, _, p, q in sets[act]:
            stim += [int(v) for v in q]
            gold += [int(v) for v in lane.run(q, code, p, tier)]
            par += [p] * (q.size // per)
        write_words(os.path.join(STIM_DIR, f"{act}_in.mem"), stim, 8)
        write_words(os.path.join(STIM_DIR, f"{act}_exp.mem"), gold, 8)
        with open(os.path.join(STIM_DIR, f"{act}_par.mem"), "w") as fh:
            fh.write("".join(par_line(p) for p in par))


def run_int8(tier, mem=None, sets=None, sim_args="", tol=None, label="int8", stream=True, seed=1):
    """One int8 TB run of every set (sets: int8_sets) through every control word at tier, then the protocol stream."""
    tol = gm.TIER_TOL[tier] if tol is None else tol
    lane = lane_for("int8", mem)
    sets = int8_sets(seed) if sets is None else sets
    n_sets = len(sets["tanh"])
    assert all(len(sets[a]) == n_sets for a, _ in INT8_ACTS)
    batches = n_sets * 256 // MAX_SIGNALS
    sz = run_args(batches, MAX_SIGNALS, tier)
    write_int8_stim(lane, sets, tier)
    st = write_stream_int8(lane, np.random.default_rng([seed, 13]), tier) if stream else None
    clear_got(ALL_ACTS + ("stream",))
    raw, wall = run_make("int8", sz + " +dump_got" + ("" if stream else " +no_stream") + (" " + sim_args if sim_args else ""))
    save_log(f"{label}_int8_t{tier}.log", raw)
    parsed = parse_log(raw, batches * MAX_SIGNALS, ALL_ACTS)
    lines = [f"  {label} int8 tier {tier}: {n_sets} sets x 256 codes x 5 activations, {wall:.0f} s, TB {parsed['status']}"]
    lines += [f"    BITEXACT {a}: {p['exact']}/{p['total']} exact, {p['failed']} wrong, {p['missing']} missing" for a, p in parsed["per"].items()]
    lines += [f"    {s}" for s in parsed["short"]]
    ok = parsed["status"] == "PASS"
    if stream:
        se = re.search(r"STREAM : elements (\d+)\s+exact (\d+)\s+failed (\d+)\s+missing (\d+)\s+extra (\d+)", raw)
        sb = re.search(r"STREAM boundaries : expected (\d+)\s+observed (\d+)\s+wrong (\d+)\s+edge errors (\d+)", raw)
        s_ok = bool(se and sb) and int(se.group(1)) == st["elements"] == int(se.group(2)) and int(se.group(5)) == 0 and \
            int(sb.group(1)) == st["starts"] == int(sb.group(2)) and int(sb.group(3)) == 0 and int(sb.group(4)) == 0
        lines.append(f"    STREAM: {'PASS' if s_ok else 'FAIL'} " + (f"exact {se.group(2)}/{se.group(1)}, group starts {sb.group(2)}/{sb.group(1)}, "
                                                                     f"{sb.group(3)} wrong, {sb.group(4)} edge errors" if se and sb else "no stream lines"))
        ok &= s_ok
    res = {}
    for act, code in INT8_ACTS:
        got = rtl_words(act, batches * MAX_SIGNALS)
        if got is None:
            ok = False
            continue
        rows = [(kind, q, int8_quant(code, case, p)) for kind, case, p, q in sets[act]]
        q = np.concatenate([r[1] for r in rows])
        quant = [np.concatenate([np.full(r[1].size, r[2][k]) for r in rows]) for k in range(4)]
        kinds = np.concatenate([np.full(r[1].size, r[0]) for r in rows])
        r = gate("int8", act, q, got, tol, quant)
        res[act] = r
        lines.append("    " + gate_line(r, tol))
        for kind in dict.fromkeys(kinds):
            m = kinds == kind
            lines.append(f"      {kind:<7}" + gate_line(gate("int8", act, q[m], got[m], tol, [v[m] for v in quant]), tol))
        lines += show_misses(r) if not r.ok else []
        ok &= r.ok
    if stream:
        got = rtl_words("stream", st["elements"])
        ok &= got is not None
        for act, _ in INT8_ACTS:
            if got is None:
                break
            m = st["func"] == act
            r = gate("int8", act, st["q"][m], got[m], tol, [v[m] for v in st["quant"]])
            lines.append("    stream " + gate_line(r, tol))
            ok &= r.ok
    return ok, lines, res


# ── runs ──

def worst_line(fmt, tier, res):
    tol = gm.TIER_TOL[tier]
    parts = [f"{a} {100 * r.worst:.4f}%" for a, r in res.items() if a in FLOAT_ACTS]
    over1 = sum(r.over_target for a, r in res.items() if a in FLOAT_ACTS)
    return f"WORST {fmt} tier {tier} ({100 * tol:g}%): " + ", ".join(parts) + f"; outputs over 1%: {over1}"


def do_gate(fmt, tier, seed):
    if fmt == "int8":
        ok, lines, res = run_int8(tier, seed=seed, label="gate")
    else:
        ok, lines, res = run_float(fmt, tier, float_gate_inputs(fmt, seed), list(ALL_ACTS), label="gate")
    return ok, lines + [worst_line(fmt, tier, res)]


def do_held(fmt, tier, seed):
    """The held-out gate: int8_held_sets or fp32_held_inputs at tier, at its tolerance."""
    if fmt == "int8":
        ok, lines, res = run_int8(tier, sets=int8_held_sets(seed), label="held", stream=False, seed=seed)
    else:
        ok, lines, res = run_float(fmt, tier, fp32_held_inputs(seed), list(ALL_ACTS), label="held")
    return ok, lines + [worst_line(fmt, tier, res).replace("WORST", "HELD WORST", 1)]


def do_protocol(fmt, seed):
    """Random batches of 30 at every tier, under output back-pressure (16 slots, 25% of returns stalled) and without; ReLU and linear too."""
    ok, L = True, []
    for tier in range(gm.NUM_TIERS):
        for args in ("+out_slots=16 +stall_pct=25", "+out_slots=64 +stall_pct=0"):
            if fmt == "int8":
                sets = {a: [s for s in v if s[0] in ("case", "random")][:8] for a, v in int8_sets(seed).items()}
                o, lines, _ = run_int8(tier, sets=sets, sim_args=args, label="protocol", stream=False, seed=seed)
            else:
                rng = np.random.default_rng([seed, 21, tier])
                x = truefn.encode(fmt, np.concatenate([rng.normal(0, 2, 120), rng.uniform(-8, 8, 120)]))
                o, lines, _ = run_float(fmt, tier, x, list(ALL_ACTS), sim_args=args, label="protocol", per_batch=30)
            ok &= o
            L += [f"  [{args}]"] + lines
    return ok, L


def loaded_image(fmt):
    """The load point's image: the default with tiers 0 and 2 swapped (descriptors and tail sets) and every coefficient word moved up by 3
    (the descriptors' bases with them), so word, field and tail writes all change what the lane computes."""
    m = gm.default_mem(fmt)
    m.desc[0], m.desc[2] = m.desc[2], m.desc[0]
    m.tail[0], m.tail[2] = m.tail[2], m.tail[0]
    used = m.meta.get("words_used", gm.COEF_WORDS)
    assert used + 3 <= gm.COEF_WORDS, "the moved image must fit"
    m.words = [0, 0, 0] + m.words[:gm.COEF_WORDS - 3]
    for row in m.desc:
        for d in row:
            d.base, d.exp_base = d.base + 3, d.exp_base + 3
    return m


def write_load(mem):
    with open(os.path.join(STIM_DIR, "coef_load.mem"), "w") as fh:
        fh.write("".join(f"{a:03x}{d & 0xFFFFFFFF:08x}\n" for a, d in mem.writes()) + "fff00000000\n")


def do_load(fmt, seed):
    """The loaded image at tier 0 (it holds the default's 10% design: gated at 10%) and tier 2 (the 1% design: gated at 1%); the model of
    the loaded image is the bit-exact reference, so a write the lane drops or misdecodes fails the run."""
    mem = loaded_image(fmt)
    write_load(mem)
    ok, L = True, [f"  the image: {len(mem.writes())} load-path writes after every reset"]
    for tier, tol in ((0, gm.TIER_TOL[2]), (2, gm.TIER_TOL[0])):
        if fmt == "int8":
            sets = {a: [s for s in v if s[0] in ("case", "random", "study")][::3] for a, v in int8_sets(seed).items()}
            o, lines, _ = run_int8(tier, mem=mem, sets=sets, sim_args="+load", tol=tol, label="load", stream=False, seed=seed)
        else:
            rng = np.random.default_rng([seed, 22, tier])
            extra = bounds_edges(fmt) if fmt == "fp32" else gm.finite_inputs(gm.fpu.BF16)[::16]
            x = np.concatenate([truefn.encode(fmt, np.concatenate([rng.normal(0, 2, 1024), rng.uniform(-8, 8, 1024), rng.uniform(-100, 100, 512)])),
                                extra])
            x = x[:x.size - x.size % MAX_SIGNALS]
            o, lines, _ = run_float(fmt, tier, x, list(ALL_ACTS), mem=mem, sim_args="+load", tol=tol, label="load")
        ok &= o
        L += lines
    # the image matters: the loaded lane's words are not the default's at tier 0, so a run that ignored the load would fail
    if fmt == "int8":
        q, p = np.arange(-128, 128), gm.int8_params(gm.INT8_CASES["tanh"][1], 3)
        differ = int((lane_for(fmt, mem).run(q, 3, p, 0) != lane_for(fmt).run(q, 3, p, 0)).sum())
        n = q.size
    else:
        x = truefn.encode(fmt, np.linspace(-6, 6, 257))
        differ, n = int((lane_for(fmt, mem).run(x, 3, 0) != lane_for(fmt).run(x, 3, 0)).sum()), 257
    L.append(f"  the loaded tier 0 differs from the default's on {differ} of {n} tanh inputs")
    ok &= differ > 0
    return ok, L


STUDY_CYCLES = {  # gpnae_fit_study.log 4.4: estimated cycles per element (N(0,1), U[-8,8], worst: the far inputs) of D' at its 1% design
    "fp32": {"tanh": (15.0, 15.0, 15.0), "selu": (13.0, 13.0, 13.0), "sigmoid": (17.0, 17.0, 17.0)},
    "bf16": {"tanh": (10, 10, 10), "selu": (9, 9, 9), "sigmoid": (11.9, 14.5, 26.1)},
    "int8": {"selu": (12, 12, 12), "sigmoid": (13, 13, 13), "tanh": (13, 13, 13)},
}
DISTS = ("N(0,1)", "U[-8,8]", "far")  # far: x = -100 (tanh 50), the study's slowest inputs, now saturated or on the tail


def do_cycles(fmt, seed):
    """Steady-state cycles per element: 6400 elements (128 far past the fit) streamed with no reset (the TB's overlap run), per
    activation, distribution and tier; N(0,1), U[-8, 8] and far (x = -100 for SELU and sigmoid, 50 for tanh: the study's slowest inputs).
    The words are checked bit for bit as in every run. int8 maps the reals to codes at s_in = 8/127 (100/127 far)."""
    ok, L, table = True, [], []
    n = 6400
    rng = np.random.default_rng([seed, 23])
    dv = {"N(0,1)": rng.normal(0, 1, n), "U[-8,8]": rng.uniform(-8, 8, n)}
    for tier in range(gm.NUM_TIERS):
        row = {}
        for dn in DISTS:
            for act in FLOAT_ACTS:
                v = np.full(128, -100.0 if act != "tanh" else 50.0) if dn == "far" else dv[dn]
                code = CODES[act]
                if fmt == "int8":
                    s_in = 100.0 / 127 if dn == "far" else 8.0 / 127
                    q = np.clip(np.round(v / s_in), -128, 127).astype(np.int64)
                    case = gm.selu_case(s_in, 0) if code == 1 else gm.Case(s_in, 0, *INT8_OUT[code], True)
                    p = gm.int8_params(case, code)
                    sz = run_args(q.size // MAX_SIGNALS, MAX_SIGNALS, tier)
                    write_int8_stim(lane_for("int8"), {a: [("cyc", case, p, q)] for a, _ in INT8_ACTS}, tier)
                    tot = q.size
                else:
                    x = truefn.encode(fmt, v)
                    sz = run_args(x.size // MAX_SIGNALS, MAX_SIGNALS, tier)
                    for a in FLOAT_ACTS:
                        write_words(os.path.join(STIM_DIR, f"{a}_in.mem"), x, width(fmt))
                        write_words(os.path.join(STIM_DIR, f"{a}_exp.mem"), lane_for(fmt).run(x, CODES[a], tier), width(fmt))
                    tot = x.size
                raw, _ = run_make(fmt, sz + " +overlap_only")
                save_log(f"cycles_{fmt}_t{tier}_{act}_{DISTS.index(dn)}.log", raw)
                m = re.search(rf"OVERLAP {act} : cycles to the last result (\d+)", raw)
                d = re.search(rf"OVERLAP {act} : elements (\d+)\s+identical (\d+)\s+differ (\d+)\s+missing (\d+)", raw)
                good = bool(m and d) and int(d.group(3)) == 0 and int(d.group(4)) == 0 and "RESULT: PASSED" in raw
                ok &= good
                row[(act, dn)] = int(m.group(1)) / tot if m else float("nan")
                if not good:
                    L.append(f"  CYCLES {fmt} tier {tier} {act} {dn}: FAIL (" + (d.group(0) if d else "no overlap result") + ")")
        for act in FLOAT_ACTS:
            est = STUDY_CYCLES[fmt][act]
            table.append(f"CYCLES {fmt} tier {tier} {act:8} " + "  ".join(f"{dn} {row[(act, dn)]:.2f}" for dn in DISTS)
                         + (f"   study estimate {est[0]} / {est[1]} / {est[2]}" if tier == 0 else ""))
    return ok, L + table


def do_fault(fmt, which):
    """FAULT 4: coefficient writes while the lane works must be refused (none lands: no a_load_idle or a_coef_quiet, every word still the reset image's, the
    TB counts them); FAULT 5 (tier 3) must fire a_tier_valid."""
    name = {4: "a_load_idle", 5: "a_tier_valid"}[which]
    if fmt == "int8":
        sets = {a: v[:2] for a, v in int8_sets(1).items()}
        sz = run_args(16, MAX_SIGNALS, 0)
        write_int8_stim(lane_for("int8"), sets, 0)
    else:
        x = truefn.encode(fmt, np.linspace(-6, 6, 4 * MAX_SIGNALS))
        sz = run_args(4, MAX_SIGNALS, 0)
        for a in FLOAT_ACTS:
            write_words(os.path.join(STIM_DIR, f"{a}_in.mem"), x, width(fmt))
            write_words(os.path.join(STIM_DIR, f"{a}_exp.mem"), lane_for(fmt).run(x, CODES[a], 0), width(fmt))
    raw, _ = run_make(fmt, sz + " +no_stream", f"-GFAULT={which}")
    save_log(f"fault{which}_{fmt}.log", raw)
    fired = len(re.findall(name, raw))
    if which == 4:  # the interlock: the writes are refused, so the batch passes bit for bit against the reset image
        m = re.search(r"LOAD REFUSED: (\d+) coefficient writes", raw)
        refused = int(m.group(1)) if m else 0
        quiet = len(re.findall("a_coef_quiet", raw))  # the occupancy check, apart from the interlock's own terms
        ok = refused == 4 and fired == 0 and quiet == 0 and "RESULT: PASSED" in raw
        return ok, [f"FAULT 4 (writes while busy refused): {'CAUGHT' if ok else 'NOT CAUGHT'}, {refused} of 4 writes refused, "
                    f"{fired} lines name {name}, {quiet} name a_coef_quiet, the batch {'matches' if 'RESULT: PASSED' in raw else 'does not match'} the reset image"]
    return fired > 0, [f"FAULT {which} ({name}): {'CAUGHT' if fired else 'NOT CAUGHT'}, {fired} lines name the assertion"]


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("--format", required=True, choices=FORMATS)
    p.add_argument("--run", required=True, choices=("gate", "held", "protocol", "load", "cycles", "fault4", "fault5"))
    p.add_argument("--tier", type=int, default=0, choices=range(gm.NUM_TIERS))
    p.add_argument("--seed", type=int, default=1)
    a = p.parse_args()
    os.makedirs(RESULTS_DIR, exist_ok=True)
    os.makedirs(STIM_DIR, exist_ok=True)
    t0 = time.time()
    print(f"GPNAE {a.run} run, {a.format}" + (f", tier {a.tier} ({100 * gm.TIER_TOL[a.tier]:g}%)" if a.run in ("gate", "held") else "") + f", seed {a.seed}")
    if a.run == "gate":
        ok, L = do_gate(a.format, a.tier, a.seed)
    elif a.run == "held":
        if a.format == "bf16":
            p.error("bf16's gate is every input already: no held-out run")
        ok, L = do_held(a.format, a.tier, a.seed)
    elif a.run == "protocol":
        ok, L = do_protocol(a.format, a.seed)
    elif a.run == "load":
        ok, L = do_load(a.format, a.seed)
    elif a.run == "cycles":
        ok, L = do_cycles(a.format, a.seed)
    else:
        ok, L = do_fault(a.format, int(a.run[-1]))
    print("\n".join(L))
    save_log(f"{a.run}_{a.format}{'_t' + str(a.tier) if a.run in ('gate', 'held') else ''}_report.log", "\n".join(L) + "\n")
    print(f"{'FAULT' if a.run.startswith('fault') else a.run.upper()} {a.format}: {'PASS' if ok else 'FAIL'} ({time.time() - t0:.0f} s)")
    sys.exit(0 if ok else 1)


# ── make regression: points through ArithmeticLibrary's engine ──

def _engine():
    """The library's make regression engine, under its own name (SIENNA and SystolicMesh each have a regression.py too)."""
    import importlib.util
    s = importlib.util.spec_from_file_location("aril_regress", os.path.join(ROOT, "ArithmeticLibrary", "Common", "regress.py"))
    m = importlib.util.module_from_spec(s)
    s.loader.exec_module(m)
    return m


regress = _engine()
RUNS = ("lint", "barrel-mac", "lane-t0", "lane-t1", "lane-t2", "held-t0", "held-t1", "held-t2", "protocol", "load", "cycles", "fault-load", "fault-tier")
HELD_FORMATS = ("fp32", "int8")  # held-out gates: bf16's gate is every input already


def runs_of(f):
    return [r for r in RUNS if not r.startswith("held") or f in HELD_FORMATS]
ONCE = ("selftest", "check-model", "check-fmt", "check-hier")
LINT_TOPS = ("fixedPointMultiplyAdd", "gpnae_horner", "barrel_mac", "gpnae_exp_split", "gpnae_coef_mem", "gpnae_act_in", "gpnae_post", "gpnae")  # the Makefile's, and gpnae_tail in bf16


class LaneSpec(regress.Spec):
    title = "GPNAE REGRESSION"
    formats = FORMATS
    reported = frozenset()  # every point gates

    def points(self, small, formats):
        if not formats:
            return []
        return list(ONCE) + [f"{f}/{r}" for f in formats for r in runs_of(f)]

    def parse(self, name):
        if name in ONCE:
            return {"n": 0, "fmt": None}
        f, _, r = name.partition("/")
        if f in FORMATS and r in runs_of(f):
            return {"n": 0, "fmt": f}
        raise ValueError(f"{name}: points are {', '.join(ONCE)} and <fmt>/<run>, fmt one of {', '.join(FORMATS)}, run one of {', '.join(RUNS)}")

    def env(self, name, env):
        if "/" in name and not name.endswith("barrel-mac"):  # one lane is too small to share: one simulation thread; make -jN runs points side by side
            env = dict(env, SIM_THREADS="1")
        return env

    def argv(self, name, opts):
        py = sys.executable
        if name == "selftest":
            return [py, "test_regression_sweep.py"]
        if name == "check-model":
            return [py, "check_gpnae_model.py"]
        if name in ("check-fmt", "check-hier"):
            return ["make", name, f"PYTHON={py}"]
        f, _, r = name.partition("/")
        if r == "lint":
            return ["make", "lint", f"FMT={f}"]
        if r == "barrel-mac":
            return ["make", "barrel-mac", f"FMT={f}", f"PYTHON={py}"]
        if r.startswith("lane-t") or r.startswith("held-t"):
            return [py, "regression.py", "--format", f, "--run", "gate" if r.startswith("lane") else "held", "--tier", r[-1]]
        return [py, "regression.py", "--format", f, "--run", {"fault-load": "fault4", "fault-tier": "fault5"}.get(r, r)]

    def verdict(self, name, text, rc):
        if name == "selftest":
            return regress.marker_verdict(text, rc, (r"^ALL \d+ PASSED$",))
        if name == "check-model":
            return regress.marker_verdict(text, rc, (r"^RESULT: PASSED$",), (r"RESULT: FAILED",))
        if name == "check-fmt":
            return regress.marker_verdict(text, rc, (r"^check-fmt OK: the tree passes$", r"^check-fmt OK: C4 "), (r"check-fmt FAIL",))
        if name == "check-hier":
            return regress.marker_verdict(text, rc, (r"^check-hier: \d+ elaborations, 0 failing$", r"^check-hier control .*: FAIL, as it must$"),
                                          (r"^check-hier \w+: FAIL",))
        f, _, r = name.partition("/")
        if r == "lint":  # a clean exit is not a lint: each top's count line, 0 warnings and 0 errors
            v = regress.marker_verdict(text, rc, (r"^lint control OK: ", r"^lint control OK \(sim\): "), (r"^lint .*: [1-9]\d* warnings", r"^lint .*: \d+ warnings, [1-9]\d* errors", r"lint control FAIL"))
            want = [f"lint {t} {f}{s}" for t in LINT_TOPS + (("gpnae_tail",) if f == "bf16" else ()) for s in ("", " sim")]  # with and without SYNTHESIS
            got = re.findall(r"^(lint \S+ \w+(?: sim)?): 0 warnings, 0 errors$", regress.ANSI.sub("", text), re.M)
            return v if v != "PASS" else ("PASS" if sorted(got) == sorted(want) else f"FAIL ({len(got)} of {len(want)} lint tops clean)")
        if r == "barrel-mac":
            return regress.marker_verdict(text, rc, (r"RESULT: PASSED",), (r"RESULT: FAILED",))
        if r.startswith("fault"):  # the point provokes the assertion it looks for
            return regress.marker_verdict(text, rc, (rf"^FAULT {f}: PASS", r"^FAULT \d .*: CAUGHT"), (r"NOT CAUGHT",), firing=False)
        run = "GATE" if r.startswith("lane-t") else "HELD" if r.startswith("held-t") else r.upper()
        return regress.marker_verdict(text, rc, (rf"^{run} {f}: PASS",), (rf"^{run} {f}: FAIL", r"TRUTH \w+ \w+: FAIL"))


SPEC = LaneSpec(ROOT, os.path.join(RESULTS_DIR, "regression"))


if __name__ == "__main__":
    if "--action" in sys.argv[1:]:
        regress.main(SPEC)
    else:
        main()
