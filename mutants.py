#!/usr/bin/env python3
"""Planted faults: each assertion the lane added, and each new feature (the load path, the tier select), shown failing on a fault of its own.
Each mutant edits one line of a copy of this tree, runs one regression.py run there and passes only when the run shows the expected failure
(the assertion's name in a TB log, or the run's FAIL verdict). Usage: mutants.py [--only NAME,...] [--jobs N]; prints MUTANT lines and a total."""
import argparse
import concurrent.futures as cf
import glob
import os
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.abspath(__file__))

# (name, file, old text, new text, format, run, what must show: an assertion name, or a run verdict)
MUTANTS = (
    ("horner_add_early", "src/gpnae_horner.sv", ".rstn_i(rstn_i), .valid_i(prod_v), .a_i(c_i)", ".rstn_i(rstn_i), .valid_i(valid_i), .a_i(c_i)",
     "bf16", "protocol", "a_step_latency"),
    ("barrel_pipe_drops_round0", "src/TYTAN/barrel_mac.sv", "      v_dly[0]    <= step_valid;", "      v_dly[0]    <= step_valid && round != '0;",
     "fp32", "protocol", "a_step_pairs"),
    ("start_before_last_load", "src/gpnae.sv", "if (drain_cnt == 4'(ACT_IN_LAT - 2)) begin", "if (drain_cnt == 4'(ACT_IN_LAT - 3)) begin",
     "bf16", "protocol", "a_load_room"),
    ("rescale_valid_drops", "src/gpnae_act_in.sv", "    else s_v <= valid_i;", "    else s_v <= valid_i && !s_v;", "int8", "protocol",
     "a_rescale_latency"),
    ("rescale_mantissa_top_bit", "src/gpnae.sv", ".desc_i(desc), .par_i(par_i), .valid_o(ai_v)",
     ".desc_i(desc), .par_i(par_i | (67'd1 << 66)), .valid_o(ai_v)", "int8", "protocol", "a_mx_range"),
    ("square_class_drops_tanh", "src/gpnae_act_in.sv", "    else p_v <= {p_v[MUL_LAT-2:0], valid_i};",
     "    else p_v <= {p_v[MUL_LAT-2:0], valid_i && fn_i != 2'(FN_TANH)};", "fp32", "protocol", "a_square_latency"),
    ("post_mul_drops_lin", "src/gpnae_post.sv", "      m_v  <= m_go;", "      m_v  <= m_go && kind_i != K_LIN;", "bf16", "protocol", "a_post_latency"),
    ("selu_mul_drops_lin", "src/gpnae_post.sv", "      pm_v <= issue_i && fn_i == 2'(FN_SELU);", "      pm_v <= issue_i && fn_i == 2'(FN_SELU) && kind_i != K_LIN;",
     "int8", "protocol", "a_selu_latency"),
    ("tail_tag_off_by_one", "src/gpnae.sv", "        .idx_i   (tail_next),", "        .idx_i   (tail_next + 1'b1),", "bf16", "protocol", "a_tail_pair"),
    ("tail_start_ignores_ready", "src/gpnae.sv", "  assign tail_start = tail_ready && (|tail_pend);", "  assign tail_start = |tail_pend;", "bf16", "protocol",
     "a_start_free"),
    ("tail_context_retakes_x", "src/gpnae_tail.sv", "        automatic logic ares = add_done && (a_owner == CW'(c));",
     "        automatic logic ares = add_done && (a_owner == CW'(c));\n        if (start_i && st[c] != T_IDLE && st[c] != T_DONE) x[c] <= x_i;", "bf16", "protocol",
     "a_ctx_hold"),
    ("tail_set_changes", "src/gpnae.sv", "        .set_i   (tset),", "        .set_i   (tail_start ? '0 : tset),", "bf16", "protocol", "a_set_stable"),
    ("load_drops_descriptor_writes", "src/gpnae_coef_mem.sv", "  assign w_desc = wr_i && (int'(waddr_i) >= A_DESC) && (int'(waddr_i) < A_TAIL);",
     "  assign w_desc = 1'b0;", "fp32", "load", "LOAD fp32: FAIL"),
    ("load_gate_dropped", "src/gpnae.sv", "  assign coef_we   = coef_wr_i && lane_idle;", "  assign coef_we   = coef_wr_i;", "bf16", "fault4",
     "a_load_idle"),
    ("load_drops_tail_writes", "src/gpnae_coef_mem.sv",
     "  assign w_tail = wr_i && (int'(waddr_i) >= A_TAIL) && (int'(waddr_i) < A_TAIL + NUM_TIERS * TAIL_STRIDE);", "  assign w_tail = 1'b0;", "bf16",
     "load", "LOAD bf16: FAIL"),
    ("load_drops_word_writes", "src/gpnae_coef_mem.sv", "  assign w_coef = wr_i && (int'(waddr_i) < A_DESC);", "  assign w_coef = 1'b0;", "int8", "load",
     "LOAD int8: FAIL"),
    ("tier_ignored", "src/gpnae.sv", "            tier_q <= tier_i;", "            tier_q <= 2'd0;", "bf16", "protocol", "PROTOCOL bf16: FAIL"),
)


def run(m):
    name, f, old, new, fmt, what, want = m
    d = tempfile.mkdtemp(prefix=f"mut_{name}_")
    try:
        shutil.copytree(ROOT, os.path.join(d, "g"), symlinks=True, ignore=shutil.ignore_patterns("Verilator*", "results", "__pycache__", ".git"))
        g = os.path.join(d, "g")
        p = os.path.join(g, f)
        src = open(p).read()
        n = src.count(old)
        if n == 0:
            return name, False, f"the line to change is not in {f}"
        open(p, "w").write(src.replace(old, new))
        r = subprocess.run([sys.executable, "regression.py", "--format", fmt, "--run", what], cwd=g, capture_output=True, text=True,
                           env=dict(os.environ, SIM_THREADS="1", SIM_ARGS="+verilator+error+limit+100"))  # assertions that fire on one cycle all print
        text = r.stdout + r.stderr + "".join(open(x, errors="replace").read() for x in glob.glob(os.path.join(g, "testbenches", "results", "*.log")))
        hit = re.search(re.escape(want), text)
        return name, bool(hit), (f"{fmt} {what}: '{want}' shown ({n} line{'s' if n > 1 else ''} changed)" if hit else
                                 f"{fmt} {what}: SURVIVED, no '{want}' (exit {r.returncode}; {text.strip().splitlines()[-1][:80] if text.strip() else ''})")
    finally:
        shutil.rmtree(d, ignore_errors=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--only", default="")
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    a = ap.parse_args()
    ms = [m for m in MUTANTS if not a.only or m[0] in a.only.split(",")]
    with cf.ThreadPoolExecutor(max_workers=a.jobs) as ex:
        res = list(ex.map(run, ms))
    for name, ok, why in res:
        print(f"MUTANT {name}: {'CAUGHT' if ok else 'SURVIVED'}: {why}")
    caught = sum(ok for _, ok, _ in res)
    print(f"MUTANTS: {caught} of {len(res)} caught")
    sys.exit(0 if caught == len(res) == len(ms) else 1)


if __name__ == "__main__":
    main()
