#!/usr/bin/env python3
"""Stimulus generators and golden model for GPNAE: SELU (01), sigmoid (10), tanh (11).

e^x comes from the TYTAN MAC: Horner over 1/k! from taylor_coeffs.mem. `terms` is the polynomial degree,
and the controller reads terms+1 coefficients. Run with --accuracy for the range each term count holds.
"""

import argparse
import math
import os

import numpy as np

from number_formats import FORMATS, get_format, suggested_rel_tol

# --------------------------------------------------------------------------
# Activation configuration. default_range is the bound where the term count still tracks the true function.
# --------------------------------------------------------------------------
ACTIVATIONS = {
    "selu":    dict(code=1, terms=14, default_range=3.5),
    "sigmoid": dict(code=2, terms=15, default_range=3.0),
    "tanh":    dict(code=3, terms=30, default_range=4.0),
}

LAMBDA = 1.0507009873554804934193349852946
ALPHA = 1.6732632423543772848170429916717

MAX_SIGNALS = 32          # GPNAE input FIFO depth, 2**ADDR_LINES


# --------------------------------------------------------------------------
# File helpers
# --------------------------------------------------------------------------

def write_mem(path: str, values, fmt) -> None:
    """One hex word per line, width set by the format, as $readmemh expects."""
    with open(path, "w") as fh:
        for v in values:
            fh.write(fmt.to_hex(v) + "\n")


def write_coeff_rom(path: str, terms: int, fmt, depth: int = 32) -> None:
    """Emit the 1/k! coefficient table for `fmt`, binary for $readmemb."""
    with open(path, "w") as fh:
        for k in range(depth):
            c = 1.0 / math.factorial(k) if k <= terms else 0.0
            bits = fmt.encode(c)
            fh.write(format(bits, f"0{fmt.width}b") + "\n")


# --------------------------------------------------------------------------
# Reference models
# --------------------------------------------------------------------------

def exp_series(x: float, terms: int, fmt=None) -> float:
    """e^x as the MAC evaluates it: Horner over 1/k!, k = 0..terms."""
    if fmt is None:
        return sum(x ** k / math.factorial(k) for k in range(terms + 1))
    acc = fmt.quantize(1.0 / math.factorial(terms))
    for k in range(terms - 1, -1, -1):
        acc = fmt.quantize(fmt.quantize(x * acc) + fmt.quantize(1.0 / math.factorial(k)))
    return acc


def activate(x: float, act: str, model: str = "exact", terms: int = None, fmt=None) -> float:
    """Reference output for one input."""
    act = act.lower()
    if terms is None:
        terms = ACTIVATIONS[act]["terms"]
    q = (lambda v: v) if (fmt is None or model == "exact") else fmt.quantize

    def _exp(v):
        return math.exp(v) if model == "exact" else exp_series(v, terms, fmt)

    # Series model quantises at every point the RTL produces a value, so the cancellation in e-1 is modelled.
    if act == "selu":
        if x >= 0.0:
            return q(LAMBDA * x)                      # single multiply by LAMDA
        e = _exp(x)
        return q(q(e - 1.0) * q(LAMBDA * ALPHA))      # fp32_down, then one multiply
    if act == "sigmoid":
        e = _exp(x)
        return q(e / q(e + 1.0))                      # numerator is mac_result itself
    if act == "tanh":
        e = _exp(q(2.0 * x))       # RTL doubles the input via exponent increment
        return q(q(e - 1.0) / q(e + 1.0))             # both from fp32_up_down
    raise ValueError(f"unknown activation {act!r}")


def golden(stim, act: str, model: str, fmt):
    """Golden vector, each value representable in the target format."""
    work = fmt.with_rounding("trunc") if model == "series" else fmt
    return [fmt.quantize(activate(float(x), act, model, None, work)) for x in stim]


# --------------------------------------------------------------------------
# Stimulus generators: gen_*(act, n, rng, fmt, rs) -> list of floats in `fmt`. `rs` seeds reproducibly.
# --------------------------------------------------------------------------

def _q(vals, fmt):
    return [fmt.quantize(float(v)) for v in vals]


def gen_act_sweep(act, n, rng, fmt, rs):
    """Even sweep across the range. Deterministic, easy to eyeball."""
    return _q(np.linspace(-rng, rng, n), fmt)


def gen_act_random(act, n, rng, fmt, rs):
    """Uniform random across the range."""
    return _q(rs.uniform(-rng, rng, n), fmt)


def gen_act_normal(act, n, rng, fmt, rs):
    """Normally distributed, clipped to the range."""
    return _q(np.clip(rs.normal(0.0, rng / 3.0, n), -rng, rng), fmt)


def gen_act_log_uniform(act, n, rng, fmt, rs):
    """Log-uniform magnitudes with random signs."""
    lo = math.log10(max(rng * 1e-5, 1e-30))
    mag = 10.0 ** rs.uniform(lo, math.log10(rng), n)
    sign = rs.choice([-1.0, 1.0], n)
    return _q(mag * sign, fmt)


def gen_act_negative(act, n, rng, fmt, rs):
    """Negative inputs only."""
    return _q(-rs.uniform(rng * 1e-3, rng, n), fmt)


def gen_act_positive(act, n, rng, fmt, rs):
    """Positive inputs only. For SELU this is the single-multiply branch."""
    return _q(rs.uniform(rng * 1e-3, rng, n), fmt)


def gen_act_near_zero(act, n, rng, fmt, rs):
    """Clustered hard against zero, including exact +0.0 and -0.0."""
    vals = [0.0, -0.0]
    vals += list(rs.uniform(-1e-3, 1e-3, max(0, n - 2)))
    return _q(vals[:n], fmt)


def gen_act_edge(act, n, rng, fmt, rs):
    """Representable-boundary values: zero, unit, the format's min normal,"""
    e = fmt.eps
    vals = [0.0, 1.0, -1.0, fmt.min_normal, -fmt.min_normal,
            1.0 + e, 1.0 - e / 2, rng, -rng, 0.5, -0.5, 2.0, -2.0]
    while len(vals) < n:
        vals.append(float(rs.uniform(-rng, rng)))
    return _q(vals[:n], fmt)


def gen_act_mixed_stress(act, n, rng, fmt, rs):
    """Adversarial mix: a quarter each of normal, log-uniform, near-zero and"""
    k = max(1, n // 4)
    vals = (gen_act_normal(act, k, rng, fmt, rs)
            + gen_act_log_uniform(act, k, rng, fmt, rs)
            + gen_act_near_zero(act, k, rng, fmt, rs)
            + gen_act_edge(act, n - 3 * k, rng, fmt, rs))
    rs.shuffle(vals)
    return vals[:n]


TESTS = [
    dict(name="act_sweep",        description="Even sweep across the range (baseline)",   gen_fn=gen_act_sweep),
    dict(name="act_random",       description="Uniform random across the range",          gen_fn=gen_act_random),
    dict(name="act_normal",       description="Normal distribution, real-tensor shaped",  gen_fn=gen_act_normal),
    dict(name="act_log_uniform",  description="Log-uniform magnitudes, exponent coverage", gen_fn=gen_act_log_uniform),
    dict(name="act_negative",     description="Negative only (SELU exponential branch)",  gen_fn=gen_act_negative),
    dict(name="act_positive",     description="Positive only (SELU linear branch)",       gen_fn=gen_act_positive),
    dict(name="act_near_zero",    description="Hard against zero, includes exact +/-0",   gen_fn=gen_act_near_zero),
    dict(name="act_edge",         description="Representable-boundary values",            gen_fn=gen_act_edge),
    dict(name="act_mixed_stress", description="Adversarial shuffled mix (hard default)",  gen_fn=gen_act_mixed_stress),
]


def get_test(name: str) -> dict:
    for t in TESTS:
        if t["name"] == name:
            return t
    raise ValueError(f"unknown test {name!r}; use --list")


# --------------------------------------------------------------------------
# Accuracy table
# --------------------------------------------------------------------------

def accuracy_table(fmt) -> None:
    """Where the configured term count stops tracking the true function."""
    print(f"\n  Series-vs-exact error, format {fmt.name} "
          f"(eps {fmt.eps:.2e}, suggested tol {suggested_rel_tol(fmt)*100:.2f}%)")
    print(f"  {'activation':<10} {'terms':>6}   " + "".join(f"{f'|x|<={r}':>11}" for r in (1, 2, 3, 4, 5)))
    print("  " + "-" * 70)
    for act, cfg in ACTIVATIONS.items():
        cells = []
        for r in (1, 2, 3, 4, 5):
            worst = 0.0
            for x in np.linspace(-r, r, 41):
                ex = activate(float(x), act, "exact")
                se = activate(float(x), act, "series", None, fmt)
                if abs(ex) > 1e-12:
                    worst = max(worst, abs(se - ex) / abs(ex))
            cells.append(f"{worst*100:10.3f}%")
        print(f"  {act:<10} {cfg['terms']:>6}   " + "".join(cells))
    print("\n  Default ranges: " + ", ".join(
        f"{a} +/-{c['default_range']}" for a, c in ACTIVATIONS.items()) + "\n")


# --------------------------------------------------------------------------
# Standalone entry point
# --------------------------------------------------------------------------

def _list_tests() -> None:
    print(f"\n  {'Name':<18}  Description")
    print("  " + "-" * 66)
    for t in TESTS:
        print(f"  {t['name']:<18}  {t['description']}")
    print(f"\n  Activations : {', '.join(ACTIVATIONS)}")
    print(f"  Formats     : {', '.join(FORMATS)}")
    print(f"  Max signals per batch: {MAX_SIGNALS} (input FIFO depth)\n")


def main() -> None:
    p = argparse.ArgumentParser(description="GPNAE stimulus generator / golden model")
    p.add_argument("--gen", default=None)
    p.add_argument("--activation", default="selu", choices=sorted(ACTIVATIONS))
    p.add_argument("--format", default="fp32", choices=sorted(FORMATS))
    p.add_argument("--n", type=int, default=30)
    p.add_argument("--range", type=float, default=None)
    p.add_argument("--model", default="exact", choices=["exact", "series"])
    p.add_argument("--seed", type=int, default=1)
    p.add_argument("--dir", default="testbenches/stimulus")
    p.add_argument("--list", action="store_true")
    p.add_argument("--accuracy", action="store_true")
    p.add_argument("--coeffs", action="store_true", help="write a coefficient ROM for --format")
    args = p.parse_args()

    fmt = get_format(args.format)

    if args.accuracy:
        accuracy_table(fmt)
        return
    if args.coeffs:
        terms = max(c["terms"] for c in ACTIVATIONS.values())
        path = f"taylor_coeffs_{fmt.name}.mem"
        write_coeff_rom(path, terms, fmt)
        print(f"\n  wrote {path}: {terms+1} coefficients, {fmt.width}-bit binary\n")
        return
    if args.list or args.gen is None:
        _list_tests()
        return

    act = args.activation
    rng = args.range if args.range is not None else ACTIVATIONS[act]["default_range"]
    test = get_test(args.gen)
    rs = np.random.RandomState(args.seed)

    stim = test["gen_fn"](act, args.n, rng, fmt, rs)
    gold = golden(stim, act, args.model, fmt)

    os.makedirs(args.dir, exist_ok=True)
    write_mem(os.path.join(args.dir, f"{act}_in.mem"), stim, fmt)
    write_mem(os.path.join(args.dir, f"{act}_exp.mem"), gold, fmt)
    print(f"\n  {test['name']} / {act} / {fmt.name}: {args.n} signals, "
          f"range +/-{rng}, model={args.model}, seed={args.seed}")
    print(f"  -> {args.dir}/{act}_in.mem, {args.dir}/{act}_exp.mem\n")


if __name__ == "__main__":
    main()
