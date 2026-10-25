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
    assert reg.SPEC.points(False, ["fp32", "bf16", "int8"]) == once + ["fp32/lane", "fp32/lane-accuracy", "bf16/lane", "bf16/lane-accuracy", "int8/lane"]
    assert reg.SPEC.points(False, ["bf16"]) == once + ["bf16/lane", "bf16/lane-accuracy"]
    assert reg.SPEC.points(True, ["int8"]) == once + ["int8/lane"] and reg.SPEC.points(False, []) == []
    assert reg.SPEC.reported == frozenset()  # nothing is reported only
    for bad in ("fp16/lane", "int8/lane-accuracy", "fp32/N8_T2/lane", "fp32/check-model-fp32", "fp32/taylor", "bf16/taylor", "nosuch"):
        try:
            reg.SPEC.parse(bad)
        except ValueError:
            continue
        raise AssertionError(f"parse accepted {bad}")


def test_commands():
    py, lane = sys.executable, [sys.executable, "regression.py", "--lane", "poly", "--format"]
    assert reg.SPEC.argv("bf16/lane", None) == lane + ["bf16", "--model", "hw"]  # bit-exact against the lane model, gated
    assert reg.SPEC.argv("bf16/lane-accuracy", None) == lane + ["bf16", "--model", "exact"]  # against the functions, gated
    assert reg.SPEC.argv("fp32/lane", None) == lane + ["fp32", "--model", "hw"]  # fp32 too: gpnae_model models fp32_down's P - 1
    assert reg.SPEC.argv("fp32/lane-accuracy", None) == lane + ["fp32", "--model", "exact"]
    assert reg.SPEC.argv("check-model-fp32", None) == [py, "check_gpnae_model_fp32.py"] and reg.SPEC.argv("check-model-int8", None) == [py, "check_gpnae_model_int8.py"] and reg.SPEC.argv("check-model-bf16", None) == [py, "check_gpnae_model_bf16.py"]
    assert reg.SPEC.argv("int8/lane", None) == lane + ["int8", "--model", "exact"] and reg.SPEC.argv("selftest", None) == [py, "test_regression_sweep.py"]


def test_lane_threads():
    """A lane point simulates on one thread under any make -jN; other points keep the engine's share of the cores."""
    for flags in ("-j2", "-j", "", "-j8"):
        for p in ("fp32/lane", "bf16/lane-accuracy", "int8/lane"):
            assert reg.regress.point_env(reg.SPEC, p, flags, 8).get("SIM_THREADS") == "1", (p, flags)


def test_verdicts():
    v = lambda p, t, rc=0: reg.SPEC.verdict(p, t, rc)
    fl = "  Element checks : 7200\n  Worst rel error: 0.0000%\n\x1b[92mACCURACY: PASS (true function)\x1b[0m\n\n  Verdict : \x1b[92mAll patterns passed\x1b[0m\n"
    assert v("fp32/lane", fl) == "PASS" and v("fp32/lane", fl, 1) == "FAIL (exit 1)" and v("fp32/lane", fl.replace("7200", "0")) == "FAIL (0 element checks)"
    assert v("fp32/lane-accuracy", fl.replace("ACCURACY: PASS", "ACCURACY: NONE")) == "FAIL (no 'ACCURACY: PASS')"  # the gate must have run
    assert v("bf16/lane", fl.replace("ACCURACY: PASS", "ACCURACY: FAIL")).startswith("FAIL (log: ACCURACY: FAIL")
    assert v("bf16/lane", fl.replace("All patterns passed", "2 pattern(s) failed")) == "FAIL (no 'Verdict : All patterns passed')"
    assert v("bf16/lane", fl + "%Error: x\n") == "FAIL (log: %Error: x)"
    i8 = ("ACCURACY: PASS (true function)\nBITEXACT: PASS (diagnostic; also required)  selu 64512/64512  sigmoid 64512/64512  tanh 64512/64512"
          "  relu 64512/64512  linear 64512/64512  stream 2098/2098\nMODEL ACCURACY: MISSED (...; reported, not gated)\n")
    assert v("int8/lane", i8) == "PASS" and v("int8/lane", i8.replace("BITEXACT: PASS", "BITEXACT: FAIL")) == "FAIL (no 'BITEXACT: PASS')"
    assert v("int8/lane", i8.replace("ACCURACY: PASS (true", "ACCURACY: FAIL (true")).startswith("FAIL (log: ACCURACY: FAIL")
    assert v("int8/lane", i8, 1) == "FAIL (exit 1)"  # a clean int8 log does not excuse a failing exit
    assert v("int8/lane", i8.replace("ACCURACY: PASS (true", "ACCURACY: FAIL (true"), 1) == "FAIL (exit 1)"  # regression.py exits 1 on ACCURACY: FAIL
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
    assert f"--threads 1 -j {reg.regress._cores()} --build-jobs {reg.regress._cores()} " in run("verilator").stdout  # one simulation thread, every core to Verilator and the C++ build
    assert "--trace" not in run("verilator").stdout and "--trace -DENABLE_TRACE" in run("verilator", "TRACE=1").stdout  # no waveform by default
    assert "--trace-fst -DENABLE_TRACE -DTRACE_FST" in run("verilator", "TRACE=fst").stdout  # SIENNA's make gpnae-verilator TRACE=fst
    assert run("verilator", "TRACE=bogus").returncode != 0
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
        keep = reg.truth_verdict
        reg.truth_verdict = lambda f, runs: ("ACCURACY: FAIL (planted)", True)  # every pattern passes, the verdict alone fails
        reg.run_make = fake_tb(rnd)
        try:
            code, out = main_exit(["--lane", "poly", "--format", "bf16", "--model", "hw", "--test", "act_sweep"])
        finally:
            reg.truth_verdict = keep
        assert code == 1 and "ACCURACY: FAIL (planted)" in out and "Verdict : All patterns passed" in out, out[-400:]
    v, n = reg.truth_verdict("bf16", {})
    assert n and v.startswith("ACCURACY: FAIL") and "no gated run" in v  # nothing gated is not a pass


def test_int8_sets():
    """int8_sets is the TB's stimulus order and size; a set's scales: a case's own, else what its integers encode."""
    import gpnae_model as gm
    sets = reg.int8_sets(1)
    for act, code in reg.INT8_ACTS:
        kinds = [k for k, _, _, _ in sets[act]]
        assert kinds == ["case"] * 5 + ["random"] * reg.N_RAND_INT8 + ["large"] * reg.N_LARGE_INT8 + ["ladder"] * reg.N_LAD_INT8 \
            + ["sweep"] * reg.N_SWEEP_INT8 + ["fine"] * reg.N_FINE_INT8 + ["edge"] * reg.N_EDGE_INT8, act
        assert all(sorted(q.tolist()) == list(range(-128, 128)) for _, _, _, q in sets[act]), act  # every input once per set
    for case in gm.INT8_CASES["selu"]:  # the integers' scales are the case's within mx's rounding (2^-15), which the decoded s_in carries into s_out
        p = gm.int8_params(case, 1)
        s_in, z_in, s_out, z_out = reg.int8_quant(1, None, p)
        assert abs(s_out / case.s_out - 1) < 2 ** -14 and abs(s_in / case.s_in - 1) < 2 ** -14 and (z_in, z_out) == (case.z_in, case.z_out), case
    sel = [(k, c, p) for k, c, p, _ in sets["selu"]]
    assert all(0 <= p.shout <= gm.ipu.REQ_MAX_SHIFT and p.mout < 1 << 24 for _, _, p in sel) and \
        all(c is not None for k, c, _ in sel if k in ("large", "fine", "edge")), "SELU: a 24-bit mantissa and a shift in [0, 55], own scales"
    assert sum(p.mout == (1 << 24) - 1 and p.shout == 16 for k, _, p in sel if k == "edge") == 1, "one edge set (s_out << s_in, scale >= 2^8) takes the saturating code"
    big = [c.s_in for k, c, _ in sel if k == "large"] + [c.s_in for k, c, _ in sel if k == "fine"]
    assert min(big) == 1e-7 and max(big) == 15.99 and all(c is None for a, _ in reg.INT8_ACTS[1:] for k, c, _, _ in sets[a] if k in ("large", "fine", "edge"))
    p = gm.int8_params(gm.INT8_CASES["tanh"][0], 3)
    assert reg.int8_quant(3, None, p)[2:] == (1 / 128, 0) and reg.int8_quant(2, None, p)[2:] == (1 / 256, -128)
    assert reg.int8_quant(1, None, p._replace(mout=0))[2] == np.inf and reg.int8_quant(4, None, p)[2:] == reg.int8_quant(4, None, p)[:2]
    x = reg.fp32_dense_inputs(1)
    v = reg.truth.decode("fp32", x)
    assert x.size % reg.MAX_SIGNALS == 0 and x.size >= reg.N_FP32_GRID + reg.N_FP32_RAND and np.isfinite(v).all()
    assert {0.0, 2.0 ** -149, -2.0 ** -149, 3.5, -4.0} <= set(v.tolist()) and v.max() == np.finfo(np.float32).max
    assert {gm.TANH_TINY[23] + d for d in (-1, 0, 1)} <= set(x.tolist()), "tanh's tiny-|x| threshold and its neighbours"
    assert np.array_equal(x, reg.fp32_dense_inputs(1)) and not np.array_equal(x, reg.fp32_dense_inputs(2))


def test_stream_gate():
    """The protocol stream's words are gated per function with their segment's scales: the model's words pass where the sets do, a word 15 LSB off fails."""
    import gpnae_model as gm
    lane = gm.Lane(gm.INT8, gm.read_rom(os.path.join(reg.ROOT, gm.coeff_file(gm.INT8))))
    with scratch_dirs():
        st = reg.write_stream_int8(lane, np.random.default_rng([1, 13]))
        y = reg.read_words(os.path.join(reg.STIM_DIR, "stream_exp.mem"))
    assert st["q"].size == st["func"].size == y.size == st["elements"] and set(st["func"]) == {a for a, _ in reg.INT8_ACTS}
    with contextlib.redirect_stdout(io.StringIO()):
        res, _ = reg.truth_stream(st, y)
        lin = np.flatnonzero(st["func"] == "linear")[3]
        bad, _ = reg.truth_stream(st, np.where(np.arange(y.size) == lin, (y + 15 + 128) % 256 - 128, y))
        none, _ = reg.truth_stream(st, None)
    assert all(r.ok for r in res.values()) and not bad["linear"].ok and bad["linear"].over == 1 and none["selu"] is None


def test_int8_model_passes_the_gate():
    """The lane model's words over every int8 set pass truth.py (the RTL must equal them bit for bit); SELU's old table on the edge sets, and ReLU passed through, fail."""
    import gpnae_model as gm
    rom = gm.read_rom(os.path.join(reg.ROOT, gm.coeff_file(gm.INT8)))
    sets = reg.int8_sets(1)
    lane, old = gm.Lane(gm.INT8, rom), gm.Lane(gm.INT8, [3454, 1288, 167] + rom[3:])
    with contextlib.redirect_stdout(io.StringIO()):
        res, _ = reg.truth_int8(sets, {act: np.concatenate([lane.run(q, code, p) for _, _, p, q in sets[act]]) for act, code in reg.INT8_ACTS})
        edge = [s for s in sets["selu"] if s[0] == "edge"][:4]  # the table witnesses
        r_old = reg.truth.gate("int8", "selu", np.concatenate([q for *_, q in edge]), np.concatenate([old.run(q, 1, p) for _, _, p, q in edge]),
                               quant=[np.repeat([c[k] for _, c, _, _ in edge], 256) for k in range(4)])
        relu = sets["relu"]
        r_pass = reg.truth.gate("int8", "relu", np.concatenate([q for *_, q in relu]), np.concatenate([q for *_, q in relu]),
                                quant=[np.repeat([reg.int8_quant(4, c, p)[k] for _, c, p, _ in relu], 256) for k in range(4)])
    assert all(r.ok for r in res.values()), {a: (r.over, r.worst_lsb) for a, r in res.items()}
    assert not r_old.ok and r_old.over >= 10 and not r_pass.ok and r_pass.over > 10000, (r_old.over, r_pass.over)


MIN_TESTS = 9  # tests this file holds; fewer run means one was lost, which is a failure

if __name__ == "__main__":
    tests = [v for k, v in list(globals().items()) if k.startswith("test_")]
    for t in tests:
        t()
        print(f"PASS {t.__name__}")
    if len(tests) < MIN_TESTS:
        print(f"FAIL: {len(tests)} tests ran, fewer than MIN_TESTS {MIN_TESTS}")
        sys.exit(1)
    print(f"ALL {len(tests)} PASSED")
