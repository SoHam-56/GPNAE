// GPNAE's equivalence harness over eq_gpnae.sv's tops. eq_fxp: --mode pairs --frac F --hi H (a's high byte H, every a low byte and every
// x: 2^24 vectors, c a hash of the pair), or --mode random --n N --seed S (every operand and frac random); done compared every cycle.
// eq_down: --mode unary --hi H (every fp32 word with high byte H: 2^24), results compared in issue order (the latencies differ).
// Every mode has valid gaps (every 13th cycle). Built with -DVTOP=V<top>.
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <string>

#include "verilated.h"
#define STR2(x) #x
#define STR(x) STR2(x)
#include STR(VTOP.h)

static uint64_t rs = 0x9E3779B97F4A7C15ULL;
static inline uint64_t rnd() {
  rs ^= rs >> 12, rs ^= rs << 25, rs ^= rs >> 27;
  return rs * 0x2545F4914F6CDD1DULL;
}
static inline uint32_t mix(uint64_t v) {
  v ^= v >> 33, v *= 0xFF51AFD7ED558CCDULL, v ^= v >> 33;
  return (uint32_t)v;
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  std::string mode = "random";
  uint64_t n = 0, hi = 0, seed = 1, frac = 0;
  for (int k = 1; k + 1 < argc; k += 2) {
    std::string a = argv[k];
    uint64_t v = strtoull(argv[k + 1], 0, 0);
    if (a == "--mode") mode = argv[k + 1];
    else if (a == "--n") n = v;
    else if (a == "--hi") hi = v;
    else if (a == "--seed") seed = v;
    else if (a == "--frac") frac = v;
  }
  rs ^= seed * 0xD1B54A32D192ED03ULL;
  if (mode == "pairs" || mode == "unary") n = 1ULL << 24;
  if (n == 0) {
    fprintf(stderr, "eq: no vectors\n");
    return 2;
  }
  VerilatedContext* ctx = new VerilatedContext;
  VTOP* t = new VTOP{ctx};
  uint64_t issued = 0, checked = 0, result_diffs = 0, done_diffs = 0, got_new = 0;
  std::deque<uint64_t> qn, qg;
  char first[8][200];
  int n_first = 0;
  t->rstn_i = 0, t->valid_i = 0, t->clk_i = 0;
  t->eval();
  for (int k = 0; k < 3; k++) t->clk_i = 1, t->eval(), t->clk_i = 0, t->eval();
  t->rstn_i = 1;
  for (uint64_t cyc = 0; cyc < 4 * n + 64; cyc++) {
    bool v = issued < n && (cyc % 13 != 12);
    t->valid_i = v;
    if (v) {
      uint64_t k = issued;
#ifdef EQ_FXP
      uint64_t a, x, c, f;
      if (mode == "pairs") a = (hi << 8) | (k >> 16), x = k & 0xFFFF, c = mix((a << 16) | x) & 0xFFFF, f = frac;
      else a = rnd() & 0xFFFF, x = rnd() & 0xFFFF, c = rnd() & 0xFFFF, f = rnd() & 3;
      if (mode == "pairs" && (k & 0xFF) == 0x55) c = (k & 0x100) ? 0x7FFF : 0x8000;  // the saturating addends too
      t->a_i = a, t->x_i = x, t->c_i = c, t->frac_i = f;
#else
      t->a_i = (uint32_t)((hi << 24) | k);
#endif
      issued++;
    }
    t->clk_i = 0, t->eval();
    t->clk_i = 1, t->eval();
#ifdef EQ_FXP
    if (t->done_new != t->done_generic) {
      if (n_first < 8) snprintf(first[n_first++], 200, "EQ_DONE cycle %" PRIu64 ": new %d, generic %d", cyc, (int)t->done_new, (int)t->done_generic);
      done_diffs++;
    }
    if (t->done_generic) {
      checked++;
      if (t->result_new != t->result_generic) {
        if (n_first < 8) snprintf(first[n_first++], 200, "EQ_DIFF cycle %" PRIu64 ": new %#x, generic %#x", cyc, (unsigned)t->result_new,
                                  (unsigned)t->result_generic);
        result_diffs++;
      }
    }
#else
    if (t->done_new) qn.push_back(t->result_new), got_new++;
    if (t->done_generic) qg.push_back(t->result_generic);
    while (!qn.empty() && !qg.empty()) {
      uint64_t a = qn.front(), b = qg.front();
      if (a != b) {
        if (n_first < 8) snprintf(first[n_first++], 200, "EQ_DIFF element %" PRIu64 " (A %#" PRIx64 "): fp32Adder %#" PRIx64 ", fp32_down %#" PRIx64,
                                  checked, (hi << 24) | checked, a, b);
        result_diffs++;
      }
      qn.pop_front(), qg.pop_front(), checked++;
    }
#endif
    if (issued == n && checked == n) break;
  }
  for (int k = 0; k < n_first; k++) printf("%s\n", first[k]);
  printf("EQ %s %s hi %" PRIu64 " frac %" PRIu64 ": n %" PRIu64 " checked %" PRIu64 " result_diff %" PRIu64 " done_diff %" PRIu64 "\n", STR(VTOP),
         mode.c_str(), hi, frac, n, checked, result_diffs, done_diffs);
  printf("RESULT: %s\n", (checked == n && result_diffs == 0 && done_diffs == 0) ? "PASSED" : "FAILED");
  t->final();
  delete t;
  delete ctx;
  return 0;
}
