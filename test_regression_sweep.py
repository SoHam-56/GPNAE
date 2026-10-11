#!/usr/bin/env python3
"""make regression's list, commands and verdicts, and the true-function gate's wiring: every gpnae_poly point needs ACCURACY: PASS."""
import contextlib
import io
import os
import subprocess
import sys
import tempfile

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import regression as reg  # noqa: E402


def test_points():
    once = ["selftest", "check-model-fp32", "check-model-bf16", "check-model-int8"]
    assert reg.SPEC.points(False, ["fp32", "bf16", "int8"]) == once + ["fp32/taylor", "fp32/lane", "fp32/lane-accuracy", "bf16/lane", "bf16/lane-accuracy", "int8/lane"]
    assert reg.SPEC.points(False, ["bf16"]) == once + ["bf16/lane", "bf16/lane-accuracy"]  # the published Taylor lane is fp32 only
    assert reg.SPEC.points(True, ["int8"]) == once + ["int8/lane"] and reg.SPEC.points(False, []) == []
    assert reg.SPEC.reported == {"bf16/lane-accuracy"}  # the TB's 6.25% check; bf16/lane gates every bf16 input on the true function
    for bad in ("fp16/lane", "int8/lane-accuracy", "fp32/N8_T2/lane", "fp32/check-model-fp32", "bf16/taylor", "int8/taylor", "nosuch"):
        try:
            reg.SPEC.parse(bad)
        except ValueError:
            continue
        raise AssertionError(f"parse accepted {bad}")


def test_commands():
    py, lane = sys.executable, [sys.executable, "regression.py", "--lane", "poly", "--format"]
    assert reg.SPEC.argv("bf16/lane", None) == lane + ["bf16", "--model", "hw"]  # bit-exact against the lane model, gated
    assert reg.SPEC.argv("bf16/lane-accuracy", None) == lane + ["bf16", "--model", "exact"]  # against the functions, reported
    assert reg.SPEC.argv("fp32/lane", None) == lane + ["fp32", "--model", "hw"]  # fp32 too: gpnae_model models fp32_down's P - 1
    assert reg.SPEC.argv("fp32/lane-accuracy", None) == lane + ["fp32", "--model", "exact"]
    assert reg.SPEC.argv("fp32/taylor", None) == [py, "regression.py", "--lane", "gpnae", "--format", "fp32"]  # the published lane, its tests unchanged
    assert reg.SPEC.argv("check-model-fp32", None) == [py, "check_gpnae_model_fp32.py"] and reg.SPEC.argv("check-model-int8", None) == [py, "check_gpnae_model_int8.py"] and reg.SPEC.argv("check-model-bf16", None) == [py, "check_gpnae_model_bf16.py"]
    assert reg.SPEC.argv("int8/lane", None) == lane + ["int8", "--model", "exact"] and reg.SPEC.argv("selftest", None) == [py, "test_regression_sweep.py"]


def test_verdicts():
    v = lambda p, t, rc=0: reg.SPEC.verdict(p, t, rc)
    fl = "  Element checks : 7200\n  Worst rel error: 0.0000%\n\x1b[92mACCURACY: PASS (true function)\x1b[0m\n\n  Verdict : \x1b[92mAll patterns passed\x1b[0m\n"
    assert v("fp32/lane", fl) == "PASS" and v("fp32/lane", fl, 1) == "FAIL (exit 1)" and v("fp32/lane", fl.replace("7200", "0")) == "FAIL (0 element checks)"
    assert v("fp32/lane-accuracy", fl.replace("ACCURACY: PASS", "ACCURACY: NONE")) == "FAIL (no 'ACCURACY: PASS')"  # the gate must have run
    assert v("bf16/lane", fl.replace("ACCURACY: PASS", "ACCURACY: FAIL")).startswith("FAIL (log: ACCURACY: FAIL")
    assert v("fp32/taylor", fl.replace("ACCURACY: PASS (true function)", "")) == "PASS"  # the published Taylor lane is not gpnae_poly
    assert v("bf16/lane", fl.replace("All patterns passed", "2 pattern(s) failed")) == "FAIL (no 'Verdict : All patterns passed')"
    assert v("bf16/lane", fl + "%Error: x\n") == "FAIL (log: %Error: x)"
    i8 = "ACCURACY: PASS (true function)\nBITEXACT: PASS (diagnostic; also required)  selu 25856/25856\nMODEL ACCURACY: MISSED (...; reported, not gated)\n"
    assert v("int8/lane", i8) == "PASS" and v("int8/lane", i8.replace("BITEXACT: PASS", "BITEXACT: FAIL")) == "FAIL (no 'BITEXACT: PASS')"
    assert v("int8/lane", i8.replace("ACCURACY: PASS (true", "ACCURACY: FAIL (true")).startswith("FAIL (log: ACCURACY: FAIL")
    assert v("int8/lane", i8.replace("ACCURACY: PASS (true function)\n", "")) == "FAIL (no 'ACCURACY: PASS')"
    assert v("selftest", "ALL 4 PASSED\n") == "PASS" and v("selftest", "done\n").startswith("FAIL")
    chk = "check_gpnae_model_fp32: 0 errors\nRESULT: PASSED\n"
    assert v("check-model-fp32", chk) == "PASS" and v("check-model-fp32", chk.replace("PASSED", "FAILED")).startswith("FAIL") and v("check-model-int8", "done\n").startswith("FAIL")


def test_regression_target():
    env = {k: x for k, x in os.environ.items() if not k.startswith("MAKE")}
    run = lambda *a: subprocess.run(["make", "-s", "-n", *a, f"PYTHON={sys.executable}"], cwd=reg.ROOT, capture_output=True, text=True, env=env)
    for args, pts in (((), reg.SPEC.points(False, ["fp32", "bf16", "int8"])), (("FMT=bf16",), reg.SPEC.points(False, ["bf16"]))):
        r = run("regression", *args)
        lines = r.stdout.splitlines()
        names = [x.split("--name ")[1].split()[0] for x in lines if "--action point " in x]
        assert r.returncode == 0 and names == pts, (args, r.stderr[-200:], names)
        assert all(x.rstrip().endswith("--keep-going") for x in lines if "--action point " in x) and "--action summary" in lines[-1], lines[-1]
    one = run("regression/int8/lane").stdout.splitlines()
    assert len(one) == 1 and "--keep-going" not in one[0], one
    assert run("regression", "FMT=fp16").returncode != 0
    assert run("regression/int8/lane", "FMT=fp16").returncode != 0
    lint = run("lint_fmt", "TOP=barrel_mac", "FMT=-GEXP_W=8 -GMAN_W=7")  # lint_fmt's FMT is Verilator -G overrides, not a regression format
    assert lint.returncode == 0 and "--top-module barrel_mac -GEXP_W=8 -GMAN_W=7" in lint.stdout, ("lint_fmt", lint.stderr[-200:])
    assert "--threads 3" in run("verilator", "SIM_THREADS=3").stdout
    assert "--trace" not in run("verilator").stdout and "--trace -DENABLE_TRACE" in run("verilator", "TRACE=1").stdout  # no waveform by default
    assert run("verilator", "TRACE=fst").returncode != 0
    for fmt in ("int8", "fp16"):  # an exported FMT does not narrow make regression (only FMT= on its command line does)
        r = subprocess.run(["make", "-s", "-n", "regression", f"PYTHON={sys.executable}"], cwd=reg.ROOT, capture_output=True, text=True, env=dict(env, FMT=fmt))
        names = [x.split("--name ")[1].split()[0] for x in r.stdout.splitlines() if "--action point " in x]
        assert r.returncode == 0 and names == reg.SPEC.points(False, ["fp32", "bf16", "int8"]), (fmt, r.stderr[-200:], names)


@contextlib.contextmanager
def scratch_dirs():
    """regression.py's stimulus, testbench and results directories moved to a temporary one (the tracked stimulus stays clean)."""
    keep = reg.STIM_DIR, reg.TB_DIR, reg.RESULTS_DIR, reg.run_make
    with tempfile.TemporaryDirectory() as d:
        reg.STIM_DIR, reg.TB_DIR, reg.RESULTS_DIR = os.path.join(d, "stimulus"), d, os.path.join(d, "results")
        os.makedirs(reg.STIM_DIR)
        try:
            yield d
        finally:
            reg.STIM_DIR, reg.TB_DIR, reg.RESULTS_DIR, reg.run_make = keep


def fake_tb(words_fn):
    """A run_make that answers like the TB: bit-exact RESULT lines, and words_fn(act, inputs) dumped as <act>_got.mem."""
    def run(lane="gpnae", sim_args=""):
        acts = reg.ALL_ACTS if "all_acts" in sim_args else reg.FLOAT_ACTS
        log = []
        for a in acts:
            x = reg.read_words(os.path.join(reg.STIM_DIR, f"{a}_in.mem"))
            if "dump_got" in sim_args:
                with open(os.path.join(reg.STIM_DIR, f"{a}_got.mem"), "w") as fh:
                    fh.write("".join(f"{int(w) & 0xFFFF:04x}\n" for w in words_fn(a, x)))
            log.append(f"  RESULT {a} : total {x.size}  exact {x.size}  tol 0  failed 0  missing 0")
        return "\n".join(log + [" RESULT: PASSED"]) + "\n", 0.0
    return run


def main_exit(argv):
    """(exit code, output without colour) of regression.py's main()."""
    keep = sys.argv
    sys.argv = ["regression.py"] + argv
    try:
        with contextlib.redirect_stdout(io.StringIO()) as out:
            try:
                reg.main()
                code = 0
            except SystemExit as e:
                code = e.code
    finally:
        sys.argv = keep
    return code, reg.regress.ANSI.sub("", out.getvalue())


def test_truth_wiring():
    """A float run gates the TB's dumped words on truth.py: rounded true values pass; one wrong word, or a missing dump, fails it."""
    rnd = lambda a, x: reg.truth.encode("bf16", reg.truth.ref(a, reg.truth.decode("bf16", x)))
    with scratch_dirs():
        reg.run_make = fake_tb(rnd)
        code, out = main_exit(["--lane", "poly", "--format", "bf16", "--model", "hw", "--test", "act_sweep"])
        assert code == 0 and "ACCURACY: PASS" in out and "Verdict : All patterns passed" in out, out[-600:]
        bad = lambda a, x: np.where(np.arange(x.size) == 5, 0x7FC0, rnd(a, x)) if a == "tanh" else rnd(a, x)  # one NaN word
        reg.run_make = fake_tb(bad)
        code, out = main_exit(["--lane", "poly", "--format", "bf16", "--model", "hw", "--test", "act_sweep"])
        assert code == 1 and "ACCURACY: FAIL" in out and "TRUTH bf16 tanh: FAIL" in out and "TRUTH bf16 selu: PASS" in out, out[-600:]
        reg.run_make = lambda lane="gpnae", sim_args="": fake_tb(rnd)(lane, "")  # the TB wrote no dump
        code, out = main_exit(["--lane", "poly", "--format", "bf16", "--model", "exact", "--test", "act_sweep"])
        assert code == 1 and "no RTL words" in out and "ACCURACY: FAIL" in out and "NO RTL WORDS" in out, out[-600:]
    v, n = reg.truth_verdict("bf16", {})
    assert n and v.startswith("ACCURACY: FAIL") and "no gated run" in v  # nothing gated is not a pass


def test_int8_sets():
    """int8_sets is the TB's stimulus order and size; a set's scales: a case's own, else what its integers encode."""
    import gpnae_model as gm
    sets = reg.int8_sets(1)
    for act, code in reg.INT8_ACTS:
        kinds = [k for k, _, _, _ in sets[act]]
        assert kinds == ["case"] * 5 + ["random"] * reg.N_RAND_INT8 + ["positive"] * reg.N_POS_INT8 + ["ladder"] * reg.N_LAD_INT8 \
            + ["sweep"] * reg.N_SWEEP_INT8, act
        assert all(sorted(q.tolist()) == list(range(-128, 128)) for _, _, _, q in sets[act]), act  # every input once per set
    for case in gm.INT8_CASES["selu"]:  # the integers' s_out is the case's within the multiplier's 31 bits
        p = gm.int8_params(case, 1)
        s_in, z_in, s_out, z_out = reg.int8_quant(1, None, p)
        assert abs(s_out / case.s_out - 1) < 2 ** -29 and abs(s_in / case.s_in - 1) < 2 ** -14 and (z_in, z_out) == (case.z_in, case.z_out), case
    p = gm.int8_params(gm.INT8_CASES["tanh"][0], 3)
    assert reg.int8_quant(3, None, p)[2:] == (1 / 128, 0) and reg.int8_quant(2, None, p)[2:] == (1 / 256, -128)
    assert reg.int8_quant(1, None, p._replace(mout=0))[2] == np.inf and reg.int8_quant(4, None, p)[2:] == reg.int8_quant(4, None, p)[:2]
    x = reg.fp32_dense_inputs(1)
    v = reg.truth.decode("fp32", x)
    assert x.size % reg.MAX_SIGNALS == 0 and x.size >= reg.N_FP32_GRID + reg.N_FP32_RAND and np.isfinite(v).all()
    assert {0.0, 2.0 ** -149, -2.0 ** -149, 3.5, -4.0} <= set(v.tolist()) and v.max() == np.finfo(np.float32).max
    assert np.array_equal(x, reg.fp32_dense_inputs(1)) and not np.array_equal(x, reg.fp32_dense_inputs(2))


MIN_TESTS = 6  # tests this file holds; fewer run means one was lost, which is a failure

if __name__ == "__main__":
    tests = [v for k, v in list(globals().items()) if k.startswith("test_")]
    for t in tests:
        t()
        print(f"PASS {t.__name__}")
    if len(tests) < MIN_TESTS:
        print(f"FAIL: {len(tests)} tests ran, fewer than MIN_TESTS {MIN_TESTS}")
        sys.exit(1)
    print(f"ALL {len(tests)} PASSED")
