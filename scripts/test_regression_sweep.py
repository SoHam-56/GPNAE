#!/usr/bin/env python3
"""make regression's list, commands and verdicts, and the true-function gate's wiring: every lane run gates the RTL's words at its tier."""
import contextlib
import io
import os
import subprocess
import sys
import tempfile

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))  # regression.py, at the repository root
import regression as reg  # noqa: E402
import gpnae_model as gm  # noqa: E402


def test_points():
    once = ["selftest", "check-model", "check-fmt", "check-hier"]
    per = lambda f: [f"{f}/{r}" for r in reg.runs_of(f)]
    assert reg.SPEC.points(False, ["fp32", "bf16", "int8"]) == once + per("fp32") + per("bf16") + per("int8")
    assert reg.SPEC.points(True, ["bf16"]) == once + per("bf16") and reg.SPEC.points(False, []) == []
    assert reg.RUNS == ("lint", "barrel-mac", "lane-t0", "lane-t1", "lane-t2", "held-t0", "held-t1", "held-t2", "protocol", "load", "cycles", "fault-load",
                        "fault-tier") and "bf16/held-t0" not in reg.SPEC.points(False, ["bf16"])
    assert reg.SPEC.reported == frozenset()  # nothing is reported only
    for bad in ("bf16/held-t0", "fp16/lane-t0", "int8/lane-t3", "fp32/taylor", "fp32/lane", "bf16/N8_T2/lane-t0", "nosuch"):
        try:
            reg.SPEC.parse(bad)
        except ValueError:
            continue
        raise AssertionError(f"parse accepted {bad}")


def test_commands():
    py, rg = sys.executable, [sys.executable, "regression.py", "--format"]
    assert reg.SPEC.argv("bf16/lane-t1", None) == rg + ["bf16", "--run", "gate", "--tier", "1"]
    assert reg.SPEC.argv("int8/held-t2", None) == rg + ["int8", "--run", "held", "--tier", "2"]
    assert reg.SPEC.argv("int8/load", None) == rg + ["int8", "--run", "load"] and reg.SPEC.argv("fp32/cycles", None) == rg + ["fp32", "--run", "cycles"]
    assert reg.SPEC.argv("fp32/fault-load", None) == rg + ["fp32", "--run", "fault4"] and reg.SPEC.argv("bf16/fault-tier", None) == rg + ["bf16", "--run", "fault5"]
    assert reg.SPEC.argv("int8/barrel-mac", None) == ["make", "barrel-mac", "FMT=int8", f"PYTHON={py}"]
    assert reg.SPEC.argv("selftest", None) == [py, "scripts/test_regression_sweep.py"] and reg.SPEC.argv("check-model", None) == [py, "scripts/check_gpnae_model.py"]
    assert reg.SPEC.argv("check-hier", None) == ["make", "check-hier", f"PYTHON={py}"] and reg.SPEC.argv("bf16/lint", None) == ["make", "lint", "FMT=bf16"]
    mk = open(os.path.join(reg.ROOT, "Makefile")).read()
    assert reg.LINT_TOPS == tuple(mk.split("LINT_TOPS = ")[1].split("\n")[0].split()), "regression.py's LINT_TOPS is the Makefile's"


def test_lane_threads():
    """A lane point simulates on one thread under any make -jN; the barrel bench keeps the engine's share of the cores."""
    for flags in ("-j2", "-j", "", "-j8"):
        for p in ("fp32/lane-t0", "bf16/protocol", "int8/cycles"):
            assert reg.regress.point_env(reg.SPEC, p, flags, 8).get("SIM_THREADS") == "1", (p, flags)


def test_verdicts():
    v = lambda p, t, rc=0: reg.SPEC.verdict(p, t, rc)
    ok = "    TRUTH bf16 tanh: PASS  n 65280  worst 0.9602%  over 1%: 0  over 1%: 0\nGATE bf16: PASS (3 s)\n"
    assert v("bf16/lane-t0", ok) == "PASS" and v("bf16/lane-t0", ok, 1) == "FAIL (exit 1)"
    assert v("bf16/lane-t0", ok.replace("GATE bf16: PASS", "GATE bf16: FAIL")).startswith("FAIL (log: GATE bf16: FAIL")
    assert v("bf16/lane-t0", ok.replace("tanh: PASS", "tanh: FAIL")).startswith("FAIL (log: TRUTH bf16 tanh: FAIL")
    assert v("bf16/lane-t0", "nothing\n") == "FAIL (no 'GATE bf16: PASS')"  # the gate must have run
    assert v("bf16/lane-t0", ok + "%Error: x\n") == "FAIL (log: %Error: x)"
    assert v("int8/held-t0", "HELD int8: PASS (9 s)\n") == "PASS" and v("int8/held-t0", "GATE int8: PASS (9 s)\n").startswith("FAIL")
    assert v("int8/load", "LOAD int8: PASS (1 s)\n") == "PASS" and v("int8/load", "PROTOCOL int8: PASS\n").startswith("FAIL")
    f = "%Error: gpnae.sv:1: Assertion failed in TB_gpnae.dut: a_load_idle\nFAULT 4 (a_load_idle): CAUGHT, 1 lines name the assertion\nFAULT fp32: PASS (1 s)\n"
    assert v("fp32/fault-load", f) == "PASS" and v("fp32/fault-load", f.replace("CAUGHT", "NOT CAUGHT").replace("PASS", "FAIL")).startswith("FAIL")
    assert v("selftest", "ALL 4 PASSED\n") == "PASS" and v("check-model", "RESULT: PASSED\n") == "PASS" and v("check-model", "RESULT: FAILED\n").startswith("FAIL")
    assert v("int8/barrel-mac", "TB_barrel_mac int8: 256 groups, 0 errors\nRESULT: PASSED\n") == "PASS"
    lint = "".join(f"lint {t} int8{s}: 0 warnings, 0 errors\n" for t in reg.LINT_TOPS for s in ("", " sim")) + "lint control OK: a warning planted in gpnae.sv shows through the waivers\n" + \
        "lint control OK (sim): a warning planted in gpnae.sv shows through the waivers without SYNTHESIS\n"
    assert v("int8/lint", lint) == "PASS" and v("int8/lint", "lint control OK: x\nlint control OK (sim): x\n") == f"FAIL (0 of {2 * len(reg.LINT_TOPS)} lint tops clean)"
    assert v("int8/lint", lint.replace("lint gpnae int8 sim: 0", "lint gpnae int8 sim: 3")).startswith("FAIL (log: lint gpnae int8 sim: 3 warnings")
    assert v("int8/lint", lint.replace("lint control OK: a warning", "lint control FAIL: a warning")).startswith("FAIL")
    assert v("int8/lint", lint.replace("lint control OK (sim): a warning", "lint control FAIL (sim): a warning")).startswith("FAIL")
    assert v("int8/lint", lint.replace("lint control OK (sim)", "lint control skipped (sim)")).startswith("FAIL")  # both controls must report
    assert v("int8/lint", lint.replace("gpnae int8: 0 warnings", "gpnae int8: 2 warnings")).startswith("FAIL (log: lint gpnae int8: 2 warnings")
    assert v("bf16/lint", lint.replace("int8", "bf16")) == f"FAIL ({2 * len(reg.LINT_TOPS)} of {2 * len(reg.LINT_TOPS) + 2} lint tops clean)"  # bf16 also lints gpnae_tail
    hier = "check-hier fp32: OK: units fp32Adder, fp32Multiplier\ncheck-hier control (int8 hierarchy judged as fp32): FAIL, as it must\ncheck-hier: 3 elaborations, 0 failing\n"
    assert v("check-hier", hier) == "PASS" and v("check-hier", hier.replace("fp32: OK", "fp32: FAIL")).startswith("FAIL (log: check-hier fp32: FAIL")
    assert v("check-hier", hier.replace("FAIL, as it must", "PASSED: the check cannot fail")).startswith("FAIL (no")
    cf = "check-fmt OK: the tree passes\ncheck-fmt OK: C4 planted EXP_W in gpnae.sv fails\n"
    assert v("check-fmt", cf) == "PASS" and v("check-fmt", cf.replace("OK: C4", "FAIL: C4")).startswith("FAIL")


def test_regression_target():
    env = {k: x for k, x in os.environ.items() if not k.startswith("MAKE")}
    run = lambda *a: subprocess.run(["make", "-s", "-n", *a, f"PYTHON={sys.executable}"], cwd=reg.ROOT, capture_output=True, text=True, env=env)
    for args, pts in (((), reg.SPEC.points(False, ["fp32", "bf16", "int8"])), (("FMT=bf16",), reg.SPEC.points(False, ["bf16"]))):
        r = run("regression", *args)
        lines = r.stdout.splitlines()
        names = [x.split("--name ")[1].split()[0] for x in lines if "--action point " in x]
        assert r.returncode == 0 and names == pts, (args, r.stderr[-200:], names)
        assert all(x.rstrip().endswith("--keep-going") for x in lines if "--action point " in x) and "--action summary" in lines[-1], lines[-1]
    assert run("regression", "FMT=fp16").returncode != 0
    assert "+define+FMT_BF16" in run("verilator", "FMT=bf16").stdout and "+define+FMT_FP32" in run("verilator").stdout
    assert "--threads 3" in run("verilator", "SIM_THREADS=3").stdout
    assert "--trace" not in run("verilator").stdout and "--trace -DENABLE_TRACE" in run("verilator", "TRACE=1").stdout
    assert run("verilator", "TRACE=bogus").returncode != 0
    for fmt in ("int8", "fp16"):  # an exported FMT does not narrow make regression (only FMT= on its command line does); fp16 stops fmt.mk
        r = subprocess.run(["make", "-s", "-n", "regression", f"PYTHON={sys.executable}"], cwd=reg.ROOT, capture_output=True, text=True, env=dict(env, FMT=fmt))
        names = [x.split("--name ")[1].split()[0] for x in r.stdout.splitlines() if "--action point " in x]
        assert (r.returncode == 0 and names == reg.SPEC.points(False, ["fp32", "bf16", "int8"])) if fmt == "int8" else r.returncode != 0, (fmt, names)


@contextlib.contextmanager
def scratch_dirs():
    """regression.py's stimulus, testbench and results directories moved to a temporary one (the tracked config stays clean)."""
    keep = reg.STIM_DIR, reg.TB_DIR, reg.RESULTS_DIR, reg.run_make
    with tempfile.TemporaryDirectory() as d:
        reg.STIM_DIR, reg.TB_DIR, reg.RESULTS_DIR = os.path.join(d, "stimulus"), d, os.path.join(d, "results")
        os.makedirs(reg.STIM_DIR)
        os.makedirs(reg.RESULTS_DIR)
        try:
            yield d
        finally:
            reg.STIM_DIR, reg.TB_DIR, reg.RESULTS_DIR, reg.run_make = keep


def fake_tb(fmt, words_fn):
    """A run_make that answers like the TB: bit-exact RESULT lines, and words_fn(act, inputs, expected) dumped as <act>_got.mem."""
    def run(f, sim_args="", extra=""):
        acts = reg.ALL_ACTS if "all_acts" in sim_args or fmt == "int8" else reg.FLOAT_ACTS
        log = []
        for a in acts:
            x = reg.read_words(os.path.join(reg.STIM_DIR, f"{a}_in.mem"))
            e = reg.read_words(os.path.join(reg.STIM_DIR, f"{a}_exp.mem"))
            if "dump_got" in sim_args:
                reg.write_words(os.path.join(reg.STIM_DIR, f"{a}_got.mem"), words_fn(a, x, e), reg.width(fmt))
            log.append(f"  RESULT {a} : total {x.size}  exact {x.size}  failed 0  missing 0")
        return "\n".join(log + [" RESULT: PASSED"]) + "\n", 0.0
    return run


def test_truth_wiring():
    """A run gates the dumped words: the model's words pass at their tier; one wrong word, or a missing dump, fails it."""
    x = gm.finite_inputs(gm.fpu.BF16)[::64][:320]
    with scratch_dirs():
        reg.run_make = fake_tb("bf16", lambda a, x, e: e)
        ok, lines, res = reg.run_float("bf16", 0, x, list(reg.ALL_ACTS))
        assert ok and all(r.ok for r in res.values()), lines
        reg.run_make = fake_tb("bf16", lambda a, x, e: np.where(np.arange(x.size) == 5, 0x7FC0, e) if a == "tanh" else e)  # one NaN word
        ok, lines, res = reg.run_float("bf16", 0, x, list(reg.ALL_ACTS))
        assert not ok and not res["tanh"].ok and res["selu"].ok, lines
        keep = reg.rtl_words
        reg.rtl_words = lambda a, n, *t: None  # the TB wrote no dump
        reg.run_make = fake_tb("bf16", lambda a, x, e: e)
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                ok, lines, res = reg.run_float("bf16", 0, x, list(reg.ALL_ACTS))
        finally:
            reg.rtl_words = keep
        assert not ok and not res, lines


def test_tier_gate():
    """A tier's gate is at its own tolerance: tier 2's words pass at 10% and fail at 1% somewhere."""
    x = gm.finite_inputs(gm.fpu.BF16)
    lane = gm.Lane(gm.fpu.BF16)
    y = lane.run(x, 3, 2)
    assert reg.gate("bf16", "tanh", x, y, 0.10).ok
    assert not reg.gate("bf16", "tanh", x, y, 0.01).ok, "tier 2's tanh passes 1%: the tier gate could not tell the tiers apart"


def test_int8_sets():
    """int8_sets is the TB's stimulus order and size; every activation the same number of sets, every set every code once."""
    sets = reg.int8_sets(1)
    n = len(sets["tanh"])
    assert all(len(sets[a]) == n for a, _ in reg.INT8_ACTS) and n * 256 % reg.MAX_SIGNALS == 0
    assert all(sorted(q.tolist()) == list(range(-128, 128)) for a, _ in reg.INT8_ACTS for _, _, _, q in sets[a])
    kinds = [k for k, _, _, _ in sets["selu"]]
    assert kinds.count("study") == reg.N_STUDY_INT8 and kinds.count("case") == 5 and kinds.count("random") == reg.N_RAND_INT8


def test_int8_model_passes_the_gate():
    """The model's words over every int8 set pass the tier-0 gate (the RTL must equal them bit for bit)."""
    sets = reg.int8_sets(1)
    lane = gm.Lane(gm.INT8)
    for act, code in reg.INT8_ACTS:
        q = np.concatenate([q for *_, q in sets[act]])
        got = np.concatenate([lane.run(q, code, p, 0) for _, _, p, q in sets[act]])
        quant = [np.concatenate([np.full(256, reg.int8_quant(code, c, p)[k]) for _, c, p, _ in sets[act]]) for k in range(4)]
        r = reg.gate("int8", act, q, got, 0.01, quant)
        assert r.ok, (act, r.miss, r.worst, r.first[:2])


def test_loaded_image():
    """The load point's image fits, round-trips through the load path and changes tier 0."""
    for f in ("fp32", "bf16", "int8"):
        m = reg.loaded_image(f)
        e = gm.Mem(f)
        for a, d in m.writes():
            e.load(a, d)
        assert e.words == m.words and [[vars(d) for d in r] for r in e.desc] == [[vars(d) for d in r] for r in m.desc]
        assert m.desc[0][3].base != gm.default_mem(f).desc[0][3].base


def test_held_sets_disjoint_from_the_fit():
    """The held-out int8 sets: their forced ends are not the fit sweep's, and no scale is one the fit reads (int8_held_sets asserts it)."""
    held, sweep = reg.int8_held_sets(1), reg.int8_held_sets(2, reg.SWEEP_ENDS)
    hs = {round(c.s_in, 15) for v in held.values() for _, c, _, _ in v}
    assert reg.HELD_ENDS != reg.SWEEP_ENDS and not set(reg.SWEEP_ENDS) & set(reg.HELD_ENDS)
    assert {round(x, 15) for x in reg.HELD_ENDS} <= hs and not {round(x, 15) for x in reg.SWEEP_ENDS} & hs


def test_vcs_commands():
    """SIM=vcs: each lane run asks regression.py for VCS, each make point names SIM=vcs, check-hier is N/A, a VCS lint reports until recorded."""
    import copy
    spec = copy.copy(reg.SPEC)
    spec.sim = "vcs"
    py, rg = sys.executable, [sys.executable, "regression.py", "--format"]
    assert spec.argv("bf16/lane-t1", None) == rg + ["bf16", "--run", "gate", "--tier", "1", "--sim", "vcs"]
    assert spec.argv("int8/barrel-mac", None) == ["make", "barrel-mac", "FMT=int8", f"PYTHON={py}", "SIM=vcs"]
    assert spec.argv("selftest", None) == [py, "scripts/test_regression_sweep.py"] and spec.argv("check-model", None) == [py, "scripts/check_gpnae_model.py"]
    assert spec.not_applicable("check-hier") and not reg.SPEC.not_applicable("check-hier") and not spec.not_applicable("check-fmt")
    assert reg.SPEC.argv("bf16/lane-t1", None)[-1] == "1"  # Verilator's commands as before
    env = {k: x for k, x in os.environ.items() if not k.startswith("MAKE") and k != "SIM"}
    run = lambda *a: subprocess.run(["make", "-s", "-n", *a, f"PYTHON={py}"], cwd=reg.ROOT, capture_output=True, text=True, env=env)
    for args in (("vcs", "FMT=int8", "EXTRA_FLAGS=-GFAULT=5", "SIM_ARGS=+no_stream"), ("barrel-mac", "SIM=vcs"), ("lint", "SIM=vcs", "FMT=bf16")):
        r = run(*args)
        assert r.returncode == 0 and "verilator " not in r.stdout.replace("--lint-only", "") and ("vcs -full64" in r.stdout), (args, r.stdout[-300:])
    r = run("vcs", "FMT=int8", "EXTRA_FLAGS=-GFAULT=5", "SIM_ARGS=+no_stream")
    assert "-pvalue+TB_gpnae.FAULT=5" in r.stdout and "+define+FMT_INT8" in r.stdout and "/VCS/sim  +vcs+dumpvarsoff +no_stream" in r.stdout, r.stdout
    assert "-debug" not in r.stdout and "-debug_access+all" in run("vcs", "TRACE=1").stdout
    r = run("lint", "SIM=vcs", "FMT=bf16")
    assert r.stdout.count("vcs_lint.py") == 2 and "gpnae_tail" in r.stdout and "lint_waivers.vlt" not in r.stdout, r.stdout[-300:]
    lint = "".join(f"vcs lint {x}: 3 warnings, 0 errors\n" for x in reg.vcs_lint_labels("int8"))
    assert spec.verdict("int8/lint", lint, 0) == "PASS" and spec.verdict("int8/lint", lint.split("\n", 1)[1], 0).startswith("FAIL (")
    assert spec.gated("int8/lint") == reg.vcs_lint_recorded(reg.vcs_lint_labels("int8")) and reg.SPEC.gated("int8/lint") and spec.gated("int8/lane-t0")
    r = run("regression", "SIM=vcs")
    assert all(x.split("--name ")[1].split()[0] and " --sim vcs" in x for x in r.stdout.splitlines() if "--action point " in x), r.stdout[-300:]


def test_x_words():
    """A 4-state simulator's x or z: a dumped word, a result count or a cycle count fails its test by name, never a crash."""
    x = gm.finite_inputs(gm.fpu.BF16)[::64][:64]
    with scratch_dirs():
        def tb(fmt):
            run = fake_tb(fmt, lambda a, x, e: e)

            def bad(f, sim_args="", extra=""):
                out = run(f, sim_args, extra)
                p = os.path.join(reg.STIM_DIR, "tanh_got.mem")
                if os.path.exists(p):
                    w = open(p).read().splitlines()
                    w[37] = "xxxx"
                    open(p, "w").write("\n".join(w) + "\n")
                return out
            return bad
        reg.run_make = tb("bf16")
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            ok, lines, res = reg.run_float("bf16", 0, x, list(reg.ALL_ACTS))
        assert not ok and "tanh" not in res and "FAIL: X in output word 37 of test run bf16 tier 0 tanh" in buf.getvalue(), buf.getvalue()
    r = reg.parse_log("  RESULT tanh : total 32  exact x  failed 0  missing 0\n RESULT: PASSED\n", 32, ["tanh"])
    assert r["status"] == "FAIL" and r["short"] == ["FAIL: X in result count of test tanh ('x')"], r
    assert reg.parse_log("  RESULT tanh : total 32  exact 32  failed 0  missing 0\n RESULT: PASSED\n", 32, ["tanh"])["status"] == "PASS"
    import fourstate
    try:
        with tempfile.NamedTemporaryFile("w", suffix=".mem", delete=False) as fh:
            fh.write("0001\n00z2\n")
        reg.read_words(fh.name, "load fp32")
        raise AssertionError("read_words accepted a z word")
    except fourstate.Unknown as e:
        assert str(e).startswith("Z in output word 1 of test load fp32"), e
    finally:
        os.remove(fh.name)
    assert fourstate.field(rf"OVERLAP tanh : cycles to the last result ({fourstate.DEC})", "OVERLAP tanh : cycles to the last result 812", "t", "c") == 812


MIN_TESTS = 13  # tests this file holds; fewer run means one was lost, which is a failure

if __name__ == "__main__":
    tests = [v for k, v in list(globals().items()) if k.startswith("test_")]
    for t in tests:
        t()
        print(f"PASS {t.__name__}")
    if len(tests) < MIN_TESTS:
        print(f"FAIL: {len(tests)} tests ran, fewer than MIN_TESTS {MIN_TESTS}")
        sys.exit(1)
    print(f"ALL {len(tests)} PASSED")
