#!/usr/bin/env python3
"""Hierarchy check: at each define the arithmetic units elaborated under gpnae (TB_gpnae's dut) are exactly that precision's; args: --files DESIGN_FILES."""
import argparse
import json
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))  # the GPNAE repository
UNITS = {  # every arithmetic unit of ArithmeticLibrary and GPNAE's own: per-format units, the generic integer units and the int8-only units
    "fp32Multiplier", "fp32Adder", "fp32Divider", "bf16Multiplier", "bf16Adder", "bf16WideMultiplier", "fp32ToBf16",
    "int8Multiplier", "int16Multiplier", "int24Multiplier", "int32Adder", "intMultiplier", "intAdder", "fixedPointMultiplyAdd",
    "int8Requantizer", "int8QuantizedAdder",
}
EXPECTED = {  # the lane's units per precision
    "fp32": {"fp32Multiplier", "fp32Adder"},  # the Horner step, the operand and post multiplies, the post add
    "bf16": {"bf16Multiplier", "bf16Adder", "fp32Multiplier", "fp32Adder", "fp32ToBf16"},  # and the fp32 tail with its narrowing
    "int8": {"int16Multiplier", "int24Multiplier", "int8Requantizer", "fixedPointMultiplyAdd"},  # rescale, SELU's post, the Horner step
}
EXPECTED["default"] = EXPECTED["fp32"]  # no define elaborates fp32


def hier_cells(tree: dict, top: str) -> list:
    """Every instance below the top module as (hierarchical name, origName of the module it instantiates), from Verilator's --json-only
    tree: a MODULE holds its CELLs, inside any named generate block (GENBLOCK), and a CELL's modp names the MODULE it instantiates."""
    modules = {m["addr"]: m for m in tree["modulesp"] if m.get("type") == "MODULE"}

    def cells(node, path):  # the CELLs in a module's body with their generate-block path, not descending into another module
        if isinstance(node, dict):
            t = node.get("type")
            if t == "CELL":
                yield node, path
                return
            if t == "GENBLOCK" and node.get("name"):
                path = f"{path}.{node['name']}"
            for v in node.values():
                if isinstance(v, (list, dict)):
                    yield from cells(v, path)
        elif isinstance(node, list):
            for v in node:
                yield from cells(v, path)

    root = next((m for m in modules.values() if m.get("origName") == top), None)
    if root is None:
        raise RuntimeError(f"no {top} module in the JSON")
    out, stack = [], [(root, top)]
    while stack:
        mod, path = stack.pop()
        for body in (v for k, v in mod.items() if isinstance(v, (list, dict))):
            for c, p in cells(body, path):
                child = modules.get(c.get("modp"))
                if child is None:
                    continue
                h = f"{p}.{c['origName']}"
                out.append((h, child.get("origName", child["name"])))
                stack.append((child, h))
    return out


def units_by_place(tree: dict) -> tuple:
    """(origNames of the modules instantiated under the lane instance dut, origNames of every other one)."""
    under, other = set(), set()
    for h, u in hier_cells(tree, "TB_gpnae"):
        (under if h.startswith("TB_gpnae.dut.") else other).add(u)
    if not under:
        raise RuntimeError("no cell under TB_gpnae.dut in the JSON")
    return under, other


def elaborate(fmt: str, files: list, verilator: str, out: str) -> dict:
    d = [] if fmt == "default" else [f"+define+FMT_{fmt.upper()}"]
    x = os.path.join(out, f"hier_{fmt}.json")
    # the bench is the top: Verilator cannot elaborate a top with interface ports, and the bench instantiates no arithmetic unit
    # (Verilator 5.054 has --json-only; --xml-only is gone)
    cmd = [verilator, "--json-only", "--json-only-output", x, "--json-only-meta-output", os.path.join(out, f"hier_{fmt}.meta.json"), "--timing",
           "-Wno-fatal", "-Wno-lint", "-Wno-style", *d, "--top-module", "TB_gpnae",
           f"-I{os.path.join(ROOT, 'testbenches')}", "--Mdir", os.path.join(out, f"obj_{fmt}"), *files, os.path.join(ROOT, "testbenches", "top", "TB_gpnae.sv")]
    r = subprocess.run(cmd, cwd=os.path.join(ROOT, "src"), capture_output=True, text=True)
    if r.returncode != 0:
        errs = [ln for ln in (r.stdout + r.stderr).splitlines() if ln.startswith("%Error")]
        raise RuntimeError(f"{fmt}: verilator exit {r.returncode}: {' | '.join(errs[:3]) or (r.stdout + r.stderr)[-400:]}")
    with open(x) as fh:
        return json.load(fh)


def judge(fmt: str, units: set) -> tuple:
    got = units & UNITS
    return got == EXPECTED[fmt], got


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--files", nargs="+", required=True)
    ap.add_argument("--verilator", default="verilator")
    ap.add_argument("--out", default=os.path.join(ROOT, "Verilator_hier"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    fmts = ("fp32", "bf16", "int8", "default")
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 1) as ex:  # one elaboration per core
        trees = dict(zip(fmts, ex.map(lambda f: elaborate(f, a.files, a.verilator, a.out), fmts)))
    places = {f: units_by_place(t) for f, t in trees.items()}
    bad = 0
    for f, (under, other) in places.items():
        ok, got = judge(f, under)
        ok = ok and not (other & UNITS)  # a unit beside the lane would be the bench's, and the bench has none
        bad += not ok
        print(f"check-hier {f}: {'OK' if ok else 'FAIL'}: units {', '.join(sorted(got)) or 'none'}" + ("" if ok else f" (want {', '.join(sorted(EXPECTED[f]))})"))
    ok, _ = judge("fp32", places["int8"][0])  # control: int8's hierarchy is not fp32's
    print(f"check-hier control (int8 hierarchy judged as fp32): {'FAIL, as it must' if not ok else 'PASSED: the check cannot fail'}")
    bad += ok
    print(f"check-hier: {len(places)} elaborations, {bad} failing")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
