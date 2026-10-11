#!/usr/bin/env python3
"""make regression's list, commands and verdicts: the model checks once, gpnae_poly bit-exact in fp32, bf16 and int8, and its accuracy against the functions (fp32 gated, bf16 reported)."""
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import regression as reg  # noqa: E402


def test_points():
    once = ["selftest", "check-model-fp32", "check-model-int8"]
    assert reg.SPEC.points(False, ["fp32", "bf16", "int8"]) == once + ["fp32/taylor", "fp32/lane", "fp32/lane-accuracy", "bf16/lane", "bf16/lane-accuracy", "int8/lane"]
    assert reg.SPEC.points(False, ["bf16"]) == once + ["bf16/lane", "bf16/lane-accuracy"]  # the published Taylor lane is fp32 only
    assert reg.SPEC.points(True, ["int8"]) == once + ["int8/lane"] and reg.SPEC.points(False, []) == []
    assert reg.SPEC.reported == {"bf16/lane-accuracy"}  # fp32's accuracy is gated at its 1% bound
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
    assert reg.SPEC.argv("check-model-fp32", None) == [py, "check_gpnae_model_fp32.py"] and reg.SPEC.argv("check-model-int8", None) == [py, "check_gpnae_model_int8.py"]
    assert reg.SPEC.argv("int8/lane", None) == lane + ["int8", "--model", "exact"] and reg.SPEC.argv("selftest", None) == [py, "test_regression_sweep.py"]


def test_verdicts():
    v = lambda p, t, rc=0: reg.SPEC.verdict(p, t, rc)
    fl = "  Element checks : 7200\n  Worst rel error: 0.0000%\n\n  Verdict : \x1b[92mAll patterns passed\x1b[0m\n"
    assert v("fp32/lane", fl) == "PASS" and v("fp32/lane", fl, 1) == "FAIL (exit 1)" and v("fp32/lane", fl.replace("7200", "0")) == "FAIL (0 element checks)"
    assert v("bf16/lane", fl.replace("All patterns passed", "2 pattern(s) failed")) == "FAIL (no 'Verdict : All patterns passed')"
    assert v("bf16/lane", fl + "%Error: x\n") == "FAIL (log: %Error: x)"
    i8 = "BITEXACT: PASS  selu 25856/25856\nACCURACY: MISSED (...; reported, not gated)\n"
    assert v("int8/lane", i8) == "PASS" and v("int8/lane", i8.replace("BITEXACT: PASS", "BITEXACT: FAIL")) == "FAIL (no 'BITEXACT: PASS')"
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
    assert "--threads 3" in run("verilator", "SIM_THREADS=3").stdout
    for fmt in ("int8", "fp16"):  # an exported FMT does not narrow make regression (only FMT= on its command line does)
        r = subprocess.run(["make", "-s", "-n", "regression", f"PYTHON={sys.executable}"], cwd=reg.ROOT, capture_output=True, text=True, env=dict(env, FMT=fmt))
        names = [x.split("--name ")[1].split()[0] for x in r.stdout.splitlines() if "--action point " in x]
        assert r.returncode == 0 and names == reg.SPEC.points(False, ["fp32", "bf16", "int8"]), (fmt, r.stderr[-200:], names)


MIN_TESTS = 4  # tests this file holds; fewer run means one was lost, which is a failure

if __name__ == "__main__":
    tests = [v for k, v in list(globals().items()) if k.startswith("test_")]
    for t in tests:
        t()
        print(f"PASS {t.__name__}")
    if len(tests) < MIN_TESTS:
        print(f"FAIL: {len(tests)} tests ran, fewer than MIN_TESTS {MIN_TESTS}")
        sys.exit(1)
    print(f"ALL {len(tests)} PASSED")
