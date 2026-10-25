#!/usr/bin/env python3
"""Fits every accuracy tier of the gpnae lane's coefficient memory and writes its reset default.

Tier 0 (1%) is the design of record, gpnae_fit_study.log section 4 (D'): its sets are taken as fitted there and re-measured here.
Tiers 1 (5%) and 2 (10%) are fitted here at their lowest Horner degree: per activation and side, candidate piece layouts in order of
cost (rounds, then words); each piece fitted by float64 minimax (relative; absolute in Q4.11 for int8 sigmoid and tanh), rounded to the
format, then coordinate descent on its bits against the bit-exact lane (gpnae_model) under the decimal rule at the tier's tolerance.
A candidate is kept when every input of the gate set passes within MARGIN of the tolerance (fp32: a dense and random sample, so a
tighter margin; bf16 every input; int8 every code at 144 scales and every Q4.11 input).
Writes gpnae_coef_default.json, the literal tables in src/gpnae_coef_mem.sv between its markers, and fit_poly_coeffs.log (a report).
Usage: fit_poly_coeffs.py [--fmt fp32,bf16,int8] [--jobs N] [--check] (--check: re-measure the written default, change nothing)."""
import argparse
import itertools
import json
import multiprocessing as mp
import os
import re
import sys
import time

import numpy as np

import gpnae_model as gm
from gpnae_model import fpu, ipu

sys.path.insert(0, os.path.join(gm.ROOT, "ArithmeticLibrary", "Common", "models"))
import truefn  # noqa: E402

ROOT = gm.ROOT
SV = os.path.join(ROOT, "src", "gpnae_coef_mem.sv")
REPORT = os.path.join(ROOT, "fit_poly_coeffs.log")
MARGIN = {"fp32": 0.85, "bf16": 0.97, "int8": 0.97}  # a kept candidate's worst, as a share of its tier's tolerance
FMT = {"fp32": fpu.FP32, "bf16": fpu.BF16, "int8": gm.INT8}
FUNCS = (gm.SELU, gm.SIGMOID, gm.TANH)
REFS = {gm.SELU: truefn.truth.selu, gm.SIGMOID: truefn.truth.sigmoid, gm.TANH: truefn.truth.tanh}

# ── tier 0: the design of record (gpnae_fit_study.log 4.4; design_cfg.json, dprime.json and int8.json of the fit study, kept outside the repository) ──
H = lambda *v: [int(x, 16) for x in v]
EXP2_FP32_DEG4 = H("3f7fffd4", "bf316a6d", "3e7515d4", "bd596432", "3bddbe6a")  # 2^-f on [0, 1], expx.fit_exp2(4)
RECORD = {
    "fp32": {
        gm.SELU: dict(bounds=[6.0], deg=6, sets=[H("3fe0fe85", "3f5fe8d5", "3e908be4", "3d8054e1", "3c168b63", "3a4ee01c", "37f886e7")]),
        "sigp": dict(bounds=[6.0], deg=7, sets=[H("3f00002e", "3e7c3d80", "3c70145b", "bd2ac250", "3c65bce5", "bb1494c4", "39440e4e",
                                                  "b6d41e7f")]),
        "sign": dict(share=True, reflect=1, bounds=[6.0], exp=EXP2_FP32_DEG4),  # 1 - P on the x >= 0 set to -6, then E (1 - E)
        gm.TANH: dict(bounds=[3.0], deg=6, sets=[H("3f7fafa0", "bea318d5", "3dce3207", "bcb6b819", "3b45ce9f", "b966a716", "36dc6977")]),
    },
    "bf16": {
        gm.SELU: dict(bounds=[1.0, 2.0, 3.0, 4.625], deg=2, sets=[H("3fe2", "3f5a", "3e4f"), H("3fd4", "3f25", "3dca"), H("3fbc", "3eeb", "3d54"),
                                                                    H("3f9b", "3e94", "3cc0")]),
        "sigp": dict(bounds=[5.0], deg=4, sets=[H("3f00", "3e8b", "bd15", "bb5a", "3a40")]),
        "sign": dict(reflect=0, bounds=[1.5], deg=3, sets=[H("3f00", "be83", "3c63", "3c24")],  # the Q set: P ~ sigmoid(-|x|)
                     tail=dict(deg=4, newton=2, coef=EXP2_FP32_DEG4)),
        gm.TANH: dict(bounds=[0.5, 1.0, 1.5, 2.0, 2.65625], deg=2, sets=[H("3f81", "bebe", "3dec"), H("3f80", "be9d", "3d91"),
                                                                         H("3f75", "be66", "3cf8"), H("3f5d", "be12", "3c43"),
                                                                         H("3f3d", "bda5", "3b85")]),
    },
    "int8": {  # centered operand: x - c (SELU) or |x| - c, fixedPointMultiplyAdd at 11 + frac
        # SELU: [-5.25, 0] at the study's degree 4 (try_int8 over S 4.75 to 6.5, rs3_b2_f1_refit2): the study's S 4.75 misses 1% (1.023%) on
        # regression.py's case sets, S 5.0 on the held-out sets (1.084%); 5.25 measures 0.688% on the fit sets, 0.678% held out; same cycles
        gm.SELU: dict(bounds=[10752], deg=4, center=-5376, frac=2, sets=[[1271, 1510, 1576, 1634, 1011]]),
        "sigp": dict(bounds=[12800], deg=5, center=6400, frac=2, sets=[[1965, 322, -692, 770, -31, -373]]),
        "sign": dict(share=True, reflect=1, bounds=[12800]),  # 1 - P on the x >= 0 set
        gm.TANH: dict(bounds=[6144], deg=5, center=3072, frac=1, sets=[[1858, 728, -1505, 1610, 12, -867]]),
    },
}
STUDY_WORST = {"fp32": {gm.SELU: 0.249, gm.SIGMOID: 0.248, gm.TANH: 0.497}, "bf16": {gm.SELU: 0.747, gm.SIGMOID: 0.775, gm.TANH: 0.792},
               "int8": {}}  # gpnae_fit_study.log 4.4, % (fp32 sampled on 1.47e7 inputs, bf16 every input)


# ── words, inputs and the rule ──

def word(fmt, v):
    """A real value as a word of the format: fp32 and bf16 rounded to nearest; int8 in Q4.11."""
    if fmt == "int8":
        return int(np.clip(np.floor(v * 2048 + 0.5), -32768, 32767))
    return int(truefn.encode(fmt, np.array([v]))[0])


def value(fmt, w):
    if fmt == "int8":
        return ipu.sx(w, 16) / 2048.0
    return float(truefn.decode(fmt, np.array([w]))[0])


def fp32_bits(v):
    return np.asarray(np.asarray(v, dtype=np.float64).astype(np.float32)).view(np.uint32).astype(np.int64)


def fp32_inputs(seed=1, lo=-110.0, hi=110.0, scale=1):
    """fp32 gate inputs: a grid, uniform reals, 1024 per binade (both signs), random bit patterns, and each integer and half's 2 ulps."""
    rs = np.random.RandomState(seed)
    n = 1 << 20
    mant = np.linspace(1, 2, 1024 // scale, endpoint=False)
    mag = np.concatenate([mant * 2.0 ** e for e in range(-126, 128)])
    pb = rs.randint(0, 1 << 31, size=n // scale).astype(np.int64) | (rs.randint(0, 2, size=n // scale).astype(np.int64) << 31)
    pb = pb[((pb >> 23) & 0xFF) != 0xFF]
    edge = fp32_bits(np.arange(-110, 110.5, 0.5))
    edge = np.concatenate([edge + d for d in (-2, -1, 0, 1, 2)])
    x = np.concatenate([fp32_bits(np.linspace(lo, hi, n // scale)), fp32_bits(np.linspace(-8, 8, n // scale)),
                        fp32_bits(rs.uniform(lo, hi, n // scale)), fp32_bits(mag), fp32_bits(-mag), pb, edge, [0, 1 << 31]])
    x = x & 0xFFFFFFFF
    return np.unique(x[((x >> 23) & 0xFF) != 0xFF])


def float_inputs(fmt, train=False):
    """The verdict inputs: every bf16 input; fp32 this script's sample and regression.py's gate inputs together (the training set alone
    for descent)."""
    if fmt == "bf16":
        return gm.finite_inputs(fpu.BF16)
    if train:
        return fp32_inputs(seed=11, scale=64)
    import regression
    return np.unique(np.concatenate([fp32_inputs(seed=1), regression.fp32_dense_inputs(1)]))


def int8_cases(code, seed=5, n=72):
    """The study's int8 sweep: 72 log-uniform input scales in [1e-4, 8] (random z_in, then z_in = 0); SELU's output calibrated."""
    rs = np.random.RandomState(seed)
    s = np.sort(np.exp(rs.uniform(np.log(1e-4), np.log(8.0), n - 2)))
    s = np.concatenate([[1e-4], s, [8.0]])
    z = rs.randint(-128, 128, size=s.size)
    out = []
    for a, b in list(zip(s, z)) + [(a, 0) for a in s]:
        out.append(gm.selu_case(float(a), int(b)) if code == gm.SELU else
                   gm.Case(float(a), int(b), *({gm.SIGMOID: (1 / 256, -128), gm.TANH: (1 / 128, 0)}[code]), True))
    return out


def dense_cases(code):
    """Every Q4.11 input with an identity rescale; SELU at four calibrated output scales."""
    if code != gm.SELU:
        return [gm.Case(1 / 2048, 0, *({gm.SIGMOID: (1 / 256, -128), gm.TANH: (1 / 128, 0)}[code]), True)]
    return [gm.Case(1 / 2048, 0, c.s_out, c.z_out, True) for c in (gm.selu_case(s, 0) for s in (4 / 128, 4 / 64, 4 / 256, 16 / 128))]


DENSE = np.arange(-32768, 32768, dtype=np.int64)


def int8_ratio(code, q, out, case, tol):
    """The decimal rule in int8 as truefn.check_activation applies it, as e / tol per input (0 within one output step)."""
    if np.isinf(case.s_out):  # a zero multiplier: every code is the zero point
        return np.where(out == case.z_out, 0.0, np.inf)
    t = REFS[code](case.s_in * (q.astype(np.float64) - case.z_in))
    tc = np.clip(t, case.s_out * (-128 - case.z_out), case.s_out * (127 - case.z_out))
    hw = case.s_out * (out.astype(np.float64) - case.z_out)
    err = np.abs(hw - tc)
    e = np.where(err <= case.s_out, 0.0, np.where(tc != 0, err / np.abs(np.where(tc != 0, tc, 1.0)), np.inf))
    return e / tol


def float_ratio(fmt, code, x, out, tol):
    v = truefn.ftz(truefn.decode(fmt, x))
    _, e = truefn.float_rule(REFS[code](v), truefn.decode(fmt, out), truefn.FMAX[fmt], tol)
    return e / tol


# ── a memory from a design: allocate words, fill descriptors ──

def build_mem(fmt, tiers):
    """tiers: per tier {code or 'sigp'/'sign': design}; a design has bounds (reals), deg, sets (words per piece), and for 'sign' share
    (the x >= 0 set), reflect, exp (fp32's 2^-f set) or tail (bf16's)."""
    m = gm.Mem(fmt)
    nxt = 0

    def alloc(words):
        nonlocal nxt
        base = nxt
        for w in words:
            if nxt >= gm.COEF_WORDS:
                raise ValueError(f"{fmt}: coefficient memory full")
            m.words[nxt] = w & ((1 << m.act_w) - 1)
            nxt += 1
        return base

    for t, tier in enumerate(tiers):
        if tier is None:  # a tier left empty (fitting another)
            continue
        meta = {}
        for key, d in (("selu", tier[gm.SELU]), ("sigp", tier["sigp"]), ("sign", tier["sign"]), ("tanh", tier[gm.TANH])):
            idx = {"selu": gm.D_SELU, "sigp": gm.D_SIGP, "sign": gm.D_SIGN, "tanh": gm.D_TANH}[key]
            ds = m.desc[t][idx]
            if d.get("share"):
                src = m.desc[t][gm.D_SIGP]
                ds.base, ds.deg, ds.center, ds.frac = src.base, src.deg, src.center, src.frac
                ds.np = len(d["bounds"])
            else:
                ds.deg = d["deg"]
                ds.np = len(d["bounds"])
                ds.base = alloc([w for s in d["sets"] for w in s])
                ds.center, ds.frac = d.get("center", 0) & 0xFFFF, d.get("frac", 0)
            ds.bounds = [(b if fmt == "int8" else word(fmt, b)) for b in d["bounds"]] + [0] * (gm.PMAX - len(d["bounds"]))
            ds.reflect = d.get("reflect", 0)
            if "exp" in d:
                ds.exp_base, ds.exp_deg = alloc(d["exp"]), len(d["exp"]) - 1
            if "tail" in d:
                tl = d["tail"]
                m.tail[t] = gm.Tail(deg=tl["deg"], newton=tl["newton"], coef=list(tl["coef"]) + [0] * (gm.TAIL_MAXC - len(tl["coef"])))
            meta[key] = {k: v for k, v in d.items() if k not in ("sets", "exp")}
        m.meta[f"tier{t}"] = meta
    m.meta["words_used"] = nxt
    return m


def single_tier(fmt, design, tier):
    """A memory holding one design in one tier's slot (for fitting that tier)."""
    tiers = [None] * gm.NUM_TIERS
    tiers[tier] = design
    return build_mem(fmt, tiers)


# ── measuring a memory ──

def measure(fmt, mem, tier, code, x=None):
    """Per-input ratios e / tol (tol the tier's) of one activation over the gate set, and the worst relative error in % (finite)."""
    tol = gm.TIER_TOL[tier]
    if fmt == "int8":
        lane = gm.Lane(gm.INT8, mem)
        q = np.arange(-128, 128, dtype=np.int64)
        rs, worst = [], 0.0
        for case in int8_cases(code):
            par = gm.int8_params(case, code)
            r = int8_ratio(code, q, lane.run(q, code, par, tier), case, tol)
            rs.append(r)
        for case in dense_cases(code):
            mo, so = gm.selu_out_params(case.s_in, 1, case.s_out) if code == gm.SELU else (0, 0)
            par = gm.Int8Params(1, 0, 0, mo, so, case.z_out if code == gm.SELU else 0)
            rs.append(int8_ratio(code, DENSE, lane.run(DENSE, code, par, tier), case, tol))
        import regression  # and regression.py's int8 gate sets and a scale sweep of seed 2 (the held-out gate is seed 1's, never read here)
        for kind, case, p, qq in regression.int8_sets(1)[gm.NAME[code]] + regression.int8_held_sets(2)[gm.NAME[code]]:
            c = gm.Case(*regression.int8_quant(code, case, p), True)  # the gate's own scales (int8_quant: sigmoid's and tanh's fixed output)
            rs.append(int8_ratio(code, qq, lane.run(qq, code, p, tier), c, tol))
        r = np.concatenate(rs)
    else:
        f = FMT[fmt]
        x = float_inputs(fmt) if x is None else x
        r = float_ratio(fmt, code, x, gm.Lane(f, mem).run(x, code, tier), tol)
    fin = r[np.isfinite(r)]
    return r, 100 * tol * float(fin.max(initial=0.0)), int((r > 1).sum())


# ── fitting one piece ──

def target(key, t):
    """What a piece's P approximates on its operand t: SELU lambda alpha (e^t - 1)/t, sigmoid(t), sigmoid(-t) (Q form), tanh(sqrt u)/sqrt u."""
    t = np.asarray(t, dtype=np.float64)
    if key == "selu":
        return np.where(np.abs(t) < 1e-8, gm.LA_F * (1 + t / 2), gm.LA_F * np.expm1(t) / np.where(t == 0, 1, t))
    if key in ("sigp", "refl"):
        return 1 / (1 + np.exp(-t))
    if key == "q":
        return 1 / (1 + np.exp(t))
    s = np.sqrt(np.maximum(t, 0))
    return np.where(t < 1e-12, 1 - t / 3, np.tanh(s) / np.where(s == 0, 1, s))


def minimax(t, g, scale, deg, it=300):
    """Weighted minimax of g by a degree-deg polynomial in t (Lawson IRLS), error |p - g| / scale; power coefficients, lowest first."""
    h = max(abs(t.min()), abs(t.max()), 1e-30)
    V = np.vander(t / h, deg + 1, increasing=True)
    w = np.full(t.size, 1.0 / t.size)
    best = None
    for _ in range(it):
        sw = np.sqrt(w) / scale
        c, *_ = np.linalg.lstsq(V * sw[:, None], g * sw, rcond=None)
        e = np.abs(V @ c - g) / scale
        if best is None or e.max() < best[0]:
            best = (e.max(), c.copy())
        w = w * (e + 1e-300)
        w /= w.sum()
    return best[1] / h ** np.arange(deg + 1)


def float_piece(fmt, key, a, b, deg):
    """The rounded minimax set of one float piece |x| in [a, b]: SELU on x in [-b, -a], sigmoid t in [a, b], tanh u in [a^2, b^2]."""
    lo, hi = {"selu": (-b, -a), "tanh": (a * a, b * b)}.get(key, (a, b))
    n = 4000
    t = (lo + hi) / 2 + (hi - lo) / 2 * np.cos(np.pi * (np.arange(n) + 0.5) / n)
    t = np.concatenate([t, [lo, hi]])
    g = target(key, t)
    scale = target("q", t) if key == "refl" else np.abs(g)  # 1 - P binds where sigmoid(-t) is small
    return [word(fmt, v) for v in minimax(t, g, scale, deg)]


def int8_piece(key, S, deg, c, F):
    """The study's int8 fit: Q4.11 power coefficients of P(s), s = (x - c) / 2^(F - 11); relative for SELU, absolute otherwise."""
    lo, hi = (-S, 0.0) if key == "selu" else (0.0, S)
    n = 6000
    xx = (lo + hi) / 2 + (hi - lo) / 2 * np.cos(np.pi * (np.arange(n) + 0.5) / n)
    g = target("selu", xx) if key == "selu" else (1 / (1 + np.exp(-xx)) if key == "sigp" else np.tanh(xx))
    sc = np.abs(g) if key == "selu" else np.ones_like(xx)
    cf = minimax((xx - c / 2048) / 2.0 ** (F - 11), g, sc, deg)
    return [int(np.clip(np.floor(v * 2048 + 0.5), -32768, 32767)) for v in cf]


def descend(objective, c, steps, passes=6):
    """Coordinate descent on the coefficient words: +-steps on each (floats: the magnitude bits of a sign-magnitude word)."""
    c = list(c)
    best = objective(c)
    for _ in range(passes):
        improved = False
        for i in range(len(c)):
            for s in steps:
                for d in (s, -s):
                    tr = list(c)
                    tr[i] = c[i] + d
                    v = objective(tr)
                    if v < best:
                        best, c, improved = v, tr, True
                        break
        if not improved:
            break
    return c, best


# ── candidates per tier ──

def thr(code, side, tol):
    """The smallest |x| from which the limit passes the rule at tol (closed forms, gpnae_fit_study.log 2.1)."""
    if code == gm.TANH:
        return 0.5 * np.log((2 + tol) / tol)
    if code == gm.SIGMOID:
        return np.log(1 / tol)
    return np.log(1 / tol + 1)


def up(v, q=0.125):
    return float(np.ceil(v / q) * q)


def design_eval(fmt, tier, code, design, x=None):
    """ratios over code's gate set with design for that activation (sigmoid: the {'sigp', 'sign'} pair) and tier 0's for the rest."""
    base = record_design(fmt)
    d = dict(base)
    d.update(design)
    mem = single_tier(fmt, d, tier)
    return measure(fmt, mem, tier, code, x)


def record_design(fmt):
    return {k: dict(v) for k, v in RECORD[fmt].items()}


def piece_bounds(S, n):
    """n pieces over [0, S]: equal widths in quarter steps."""
    if n == 1:
        return [S]
    return [up(S * (i + 1) / n, 0.25) for i in range(n - 1)] + [S]


def fit_float_side(fmt, tier, code, side, S, npieces, deg, train, extra=None):
    """One float side's design: npieces pieces of degree deg over [0, S], descended on train (the side's inputs)."""
    key = {gm.SELU: "selu", gm.TANH: "tanh"}.get(code, side)
    bounds = piece_bounds(S, npieces)
    edges = [0.0] + bounds
    sets = [float_piece(fmt, "refl" if key == "refl" else key, edges[i], edges[i + 1], deg) for i in range(npieces)]
    dkey = {gm.SELU: gm.SELU, gm.TANH: gm.TANH}.get(code, "sigp" if side == "sigp" else "sign")

    def mk(ss):
        d = dict(bounds=bounds, deg=deg, sets=ss)
        if side in ("refl", "q"):
            d["reflect"] = 1 if side == "refl" else 0
            d.update(extra or {})
        return {dkey: d}

    tol = gm.TIER_TOL[tier]
    steps = (1, 2, 4, 8, 16, 64) if fmt == "fp32" else (1, 2, 3, 4)
    for i in range(npieces):
        def obj(c, i=i):
            ss = list(sets)
            ss[i] = c
            r, _, _ = design_eval(fmt, tier, code, mk(ss), train[i])
            return float(np.max(r, initial=0.0))
        if train[i].size:
            sets[i], _ = descend(obj, sets[i], steps)
    return mk(sets)


def side_inputs(fmt, code, side, S, npieces, x):
    """The inputs of x in each piece of a side (by |x| and sign), for descent."""
    v = truefn.ftz(truefn.decode(fmt, x))
    a = np.abs(v)
    edges = [0.0] + piece_bounds(S, npieces)
    if code == gm.SELU or side in ("refl", "q"):
        sel = v < 0
    elif side == "sigp":
        sel = v >= 0
    else:
        sel = np.ones(x.shape, dtype=bool)
    out = []
    for i in range(npieces):
        hi_ok = a <= edges[i + 1] if i == npieces - 1 else a < edges[i + 1]
        out.append(x[sel & (a >= edges[i]) & hi_ok])
    return out


def try_float(job):
    """One candidate of a float side at a tier: fit, descend, measure on the full gate set; returns its record."""
    fmt, tier, code, side, S, npieces, deg, extra = job
    t0 = time.time()
    xt = float_inputs(fmt, train=True)
    train = side_inputs(fmt, code, side, S, npieces, xt)
    d = fit_float_side(fmt, tier, code, side, S, npieces, deg, train, extra)
    r, worst, fails = design_eval(fmt, tier, code, d)
    sl = side_mask(fmt, code, side)
    rr = r[sl] if sl is not None else r
    fin = rr[np.isfinite(rr)]
    return dict(fmt=fmt, tier=tier, code=code, side=side, S=S, np=npieces, deg=deg, extra=extra, design=d,
                ratio=float(rr.max(initial=0.0)), worst=100 * gm.TIER_TOL[tier] * float(fin.max(initial=0.0)), fails=int((rr > 1).sum()),
                secs=round(time.time() - t0, 1))


_MASKS = {}


def side_mask(fmt, code, side):
    """The gate inputs a side's verdict counts: sigmoid x >= 0 or x < 0; None for the whole activation."""
    if code != gm.SIGMOID:
        return None
    if fmt not in _MASKS:
        v = truefn.ftz(truefn.decode(fmt, float_inputs(fmt)))
        _MASKS[fmt] = v
    v = _MASKS[fmt]
    return v >= 0 if side == "sigp" else v < 0


def float_jobs(fmt, tier):
    """Candidate float sides for a tier, cheapest first per (code, side): (rounds, words)."""
    tol = gm.TIER_TOL[tier]
    J = []
    for code, side in ((gm.SELU, "selu"), (gm.SIGMOID, "sigp"), (gm.TANH, "tanh")):
        t = thr(code, side, tol)
        for S in sorted({up(t), up(t + 0.5), up(t + 1.0)}):
            for deg in range(1, 7):
                for npieces in ((1,) if fmt == "fp32" else (1, 2, 3)):
                    J.append((fmt, tier, code, side, S, npieces, deg, None))
    for a in (1.0, 1.5, 2.0, 3.0):  # sigmoid x < 0: pieces on [0, a], then fp32's E (1 - E) or bf16's tail past a
        if fmt == "fp32":
            for ed in (2, 3, 4):
                for side in ("q", "refl"):
                    for deg in range(1, 6):
                        J.append((fmt, tier, gm.SIGMOID, side, a, 1, deg, dict(exp=fit_exp2(ed))))
        else:
            for td, nw in ((2, 0), (3, 0), (2, 1), (3, 1), (4, 1), (4, 2)):
                for deg in range(1, 5):
                    J.append((fmt, tier, gm.SIGMOID, "q", a, 1, deg, dict(tail=dict(deg=td, newton=nw, coef=fit_exp2(td)))))
    return J


def fit_exp2(deg):
    """2^-f on [0, 1], relative minimax, fp32 words (gpnae_fit_study.log 4.1's P(f))."""
    t = 0.5 + 0.5 * np.cos(np.pi * (np.arange(4000) + 0.5) / 4000)
    t = np.concatenate([t, [0.0, 1.0]])
    g = 2.0 ** -t
    return [word("fp32", v) for v in minimax(t, g, g, deg)]


def cost(rec):
    """Horner rounds, then the tail's ops (bf16), then coefficient words."""
    ex = rec["extra"] or {}
    tl = ex.get("tail")
    tail_ops = 0 if tl is None else (tl["deg"] + 1) * 2 + 3 * tl["newton"] + 4
    exp_r = len(ex.get("exp", [])) if "exp" in ex else 0
    return (max(rec["deg"] + 1, exp_r), tail_ops, rec["np"] * (rec["deg"] + 1) + exp_r)


def int8_jobs(tier):
    J = []
    for code, key, Ss in ((gm.SELU, "selu", (2.5, 3.0, 3.5, 4.0, 4.75)), (gm.SIGMOID, "sigp", (3.0, 3.5, 4.0, 4.5, 5.0, 5.6, 6.25)),
                          (gm.TANH, "tanh", (1.5, 2.0, 2.4, 2.6, 3.0))):
        for S in Ss:
            for deg in range(1, 6):
                J.append(("int8", tier, code, key, S, 1, deg, None))
    return J


def try_int8(job):
    fmt, tier, code, key, S, _, deg, _ = job
    t0 = time.time()
    c = -S / 2 if code == gm.SELU else S / 2
    F = 11 + max(0, int(np.ceil(np.log2(S / 2))))
    cq, thr_q = int(round(c * 2048)), int(round(S * 2048))
    co = int8_piece(key, S, deg, cq, F)
    dkey = {gm.SELU: gm.SELU, gm.TANH: gm.TANH, gm.SIGMOID: "sigp"}[code]

    def mk(cc):
        d = {dkey: dict(bounds=[thr_q], deg=deg, center=cq, frac=F - 11, sets=[cc])}
        if code == gm.SIGMOID:
            d["sign"] = dict(share=True, reflect=1, bounds=[thr_q])
        return d

    def obj(cc):
        r, _, _ = design_eval("int8", tier, code, mk(cc))
        return (int((r > 1).sum()), float(r[np.isfinite(r)].max(initial=0.0)) if np.isfinite(r).any() else np.inf)
    co, _ = descend(obj, co, (1, 2, 4, 8), passes=4)
    d = mk(co)
    r, worst, fails = design_eval("int8", tier, code, d)
    return dict(fmt=fmt, tier=tier, code=code, side=key, S=S, np=1, deg=deg, extra=None, design=d, ratio=float(r.max(initial=0.0)),
                worst=worst, fails=fails, secs=round(time.time() - t0, 1))


def choose(fmt, recs):
    """Per (code, side): the cheapest record within MARGIN; a side with none keeps tier 0's design and is reported."""
    best = {}
    for r in recs:
        if r["ratio"] > MARGIN[fmt]:
            continue
        k = (r["code"], "sigp" if r["side"] == "sigp" else ("sign" if r["code"] == gm.SIGMOID else r["side"]))
        if k not in best or cost(r) < cost(best[k]):
            best[k] = r
    return best


# ── the RTL literal tables ──

def sv_tables(mems):
    """The literal section of gpnae_coef_mem.sv: per format the reset words, descriptors and tail sets as flat packed constants."""
    L = ["  // ── reset default: generated by fit_poly_coeffs.py from gpnae_coef_default.json; do not edit by hand ──"]
    for fmt, kw in (("int8", "`ifdef FMT_INT8"), ("bf16", "`elsif FMT_BF16"), ("fp32", "`else")):
        m = mems[fmt]
        L.append(kw)
        aw = m.act_w
        words = "".join(f"{w & ((1 << aw) - 1):0{aw // 4}x}" for w in reversed(m.words))
        L.append(f"  localparam logic [{gm.COEF_WORDS}*{aw}-1:0] DEF_WORDS = {gm.COEF_WORDS * aw}'h{words};")
        dw = dict((a, d) for a, d in m.writes() if a >= gm.A_DESC)
        rows = []
        for a in reversed(range(gm.A_DESC, gm.A_TAIL + gm.NUM_TIERS * gm.TAIL_STRIDE)):
            rows.append(f"{dw.get(a, 0) & 0xFFFFFFFF:08x}")
        n = gm.A_TAIL + gm.NUM_TIERS * gm.TAIL_STRIDE - gm.A_DESC
        L.append(f"  localparam logic [{n}*32-1:0] DEF_FIELDS = {n * 32}'h{''.join(rows)};  // field word a at [(a - {gm.A_DESC})*32 +: 32]")
    L.append("`endif")
    L.append("  // ── end of the generated reset default ──")
    return "\n".join(L)


def write_sv(mems):
    src = open(SV).read()
    a, b = src.index("  // ── reset default: generated"), src.index("  // ── end of the generated reset default ──")
    b += len("  // ── end of the generated reset default ──")
    new = src[:a] + sv_tables(mems) + src[b:]
    with open(SV, "w") as fh:
        fh.write(new)


def sv_check(mems):
    """The literal tables in gpnae_coef_mem.sv equal the JSON default (a selftest)."""
    src = open(SV).read()
    a, b = src.index("  // ── reset default: generated"), src.index("  // ── end of the generated reset default ──")
    return src[a:b + len("  // ── end of the generated reset default ──")] == sv_tables(mems)


# ── main ──

def report_lines(fmt, mem):
    L = []
    for t in range(gm.NUM_TIERS):
        for code in FUNCS:
            _, worst, fails = measure(fmt, mem, t, code)
            L.append(f"{fmt} tier {t} ({100 * gm.TIER_TOL[t]:g}%) {gm.NAME[code]:8} worst {worst:.4f}%  over the tolerance {fails}"
                     + (f"  (study {STUDY_WORST[fmt].get(code)}%)" if t == 0 and STUDY_WORST[fmt].get(code) else "")
                     + f"  design {json.dumps(mem.meta[f'tier{t}'].get({gm.SELU: 'selu', gm.SIGMOID: 'sigp', gm.TANH: 'tanh'}[code]))}"
                     + (f" neg {json.dumps(mem.meta[f'tier{t}'].get('sign'))}" if code == gm.SIGMOID else ""))
    return L


def main():
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("--fmt", default="fp32,bf16,int8")
    p.add_argument("--jobs", type=int, default=os.cpu_count())
    p.add_argument("--check", action="store_true", help="re-measure the written default and check the RTL literals; change nothing")
    p.add_argument("--record-only", action="store_true", help="tier 0's design in every tier slot (no fits)")
    a = p.parse_args()
    fmts = a.fmt.split(",")
    if a.check:
        mems = {f: gm.default_mem(f) for f in ("fp32", "bf16", "int8")}
        L = [ln for f in fmts for ln in report_lines(f, mems[f])]
        ok = sv_check(mems)
        L.append(f"RTL literal tables {'equal' if ok else 'DIFFER FROM'} gpnae_coef_default.json")
        print("\n".join(L))
        sys.exit(0 if ok and all("over the tolerance 0 " in ln for ln in L if "worst" in ln) else 1)
    old = json.load(open(gm.DEFAULT_JSON)) if os.path.exists(gm.DEFAULT_JSON) else {}
    mems, log = {}, []
    for fmt in fmts:
        rec = record_design(fmt)
        tiers = [rec]
        for tier in (1, 2):
            if a.record_only:
                tiers.append(rec)
                continue
            jobs = int8_jobs(tier) if fmt == "int8" else float_jobs(fmt, tier)
            fn = try_int8 if fmt == "int8" else try_float
            t0 = time.time()
            with mp.Pool(a.jobs) as pool:
                recs = pool.map(fn, jobs, chunksize=1)
            best = choose(fmt, recs)
            log.append(f"{fmt} tier {tier}: {len(jobs)} candidates in {time.time() - t0:.0f} s")
            for r in sorted(recs, key=lambda r: (r["code"], r["side"], cost(r))):
                log.append(f"  cand {gm.NAME[r['code']]:8} {r['side']:5} S {r['S']:<6g} pieces {r['np']} deg {r['deg']} "
                           f"{json.dumps({k: v for k, v in (r['extra'] or {}).items() if k != 'exp'} or None)} ratio {r['ratio']:.3f} "
                           f"worst {r['worst']:.3f}% fails {r['fails']} ({r['secs']} s)")
            d = record_design(fmt)
            for (code, side), r in best.items():
                d.update(r["design"])
            for k in ((gm.SELU, "selu"), (gm.SIGMOID, "sigp"), (gm.SIGMOID, "sign"), (gm.TANH, "tanh")):
                log.append(f"  CHOSEN {fmt} tier {tier} {gm.NAME[k[0]]} {k[1]}: " + (f"S {best[k]['S']} pieces {best[k]['np']} deg {best[k]['deg']} "
                           f"ratio {best[k]['ratio']:.3f}" if k in best else "NONE within the margin: tier 0's design kept"))
            tiers.append(d)
        mems[fmt] = build_mem(fmt, tiers)
        log += report_lines(fmt, mems[fmt])
    for f in ("fp32", "bf16", "int8"):
        if f not in mems:
            mems[f] = gm.Mem.from_dict(old[f]) if f in old else build_mem(f, [record_design(f)] * 3)
    with open(gm.DEFAULT_JSON, "w") as fh:
        json.dump({f: mems[f].to_dict() for f in ("fp32", "bf16", "int8")}, fh, indent=1)
    gm._DEFAULTS.clear()
    if os.path.exists(SV):
        write_sv(mems)
    with open(REPORT, "w") as fh:
        fh.write("\n".join(log) + "\n")
    print("\n".join(ln for ln in log if not ln.startswith("  cand")))


if __name__ == "__main__":
    main()
