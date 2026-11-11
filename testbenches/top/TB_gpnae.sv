`timescale 1ns / 100ps

// TB_gpnae: the gpnae lane in the build's format against gpnae_model, bit for bit, every output dumped for regression.py's true-function
// gate. Stimulus and expected words come from regression.py (testbenches/stimulus/<act>_{in,exp,par}.mem); the run's size comes from
// +batches=B +per_batch=P (P <= 32, B * P <= MAX_TOTAL), so one build serves every run of a format.
// SELU, sigmoid and tanh always; ReLU and linear in int8 or with +all_acts. Per activation: batches with a reset before each, then every
// batch streamed with no reset (the overlap run); floats also run each element of the last batch as a one-element group; int8 also runs
// the protocol stream (stream_*.mem). +tier=N runs tier N (default the config's TIER). +load writes coef_load.mem's (address, data) pairs
// through the load path after every reset, so the run is of that image. +overlap_only runs only the overlap runs (the cycles point);
// +no_stream leaves out int8's stream; +timeout=C (default 400000) cycles to wait for a batch.
// The bench drives the lane's input link as a producer and takes its results as a consumer of +out_slots (default 64), +stall_pct
// withholding credits.
// After every reset and load the coefficient memory, read hierarchically, must equal regression.py's image (coef_default.mem, coef_loaded.mem).
// FAULT 1: puts with no credit into a full FIFO, 2: a credited put while the lane pops, 3: an output link one bit wide, 4: a coefficient
// write while the lane works (the interlock must refuse it: the batch stays the reset image's), 5: tier 3 (a_tier_valid).
module TB_gpnae #(parameter int FAULT = 0, parameter int OUT_CAP = 64);  // OUT_CAP: the most +out_slots, and the lane's OUT_MAX

  localparam string STIM_DIR = "testbenches/stimulus/";
  localparam int MAX_TOTAL = 1 << 21;  // the most inputs per activation
  localparam int MAX_BATCHES = MAX_TOTAL / 8;
  int NUM_BATCHES = 1, SIGNALS_PER_BATCH = 32, TIMEOUT_CYCLES = 400000, TIER = 0, TOTAL = 32;
  localparam int DATA_WIDTH = sienna_fmt_pkg::DATA_WIDTH;
  localparam string FMT_NAME = sienna_fmt_pkg::FORMAT_NAME;
  localparam bit IS_INT = sienna_fmt_pkg::HAS_REQUANT_EPILOGUE;  // int8: lane parameters per batch, ReLU and linear always, the stream
  localparam int ADDR_LINES = 5;
  localparam int CONTROL_WIDTH = 3;  // as SIENNA drives the lane: 001 SELU .. 101 linear
  localparam int IN_SLOTS = 1 << ADDR_LINES;  // the lane advertises its FIFO
  localparam int LANE_K = 16;  // the lane's group size: it needs that many output credits to start one
  localparam int LOADS = 1024;  // the most load-path writes in coef_load.mem

  reg clk;
  reg rstn_i = 1'b0;  // reset held from power-up, as the hardware sees it
  reg in_put = 1'b0, in_last = 1'b0;
  reg [DATA_WIDTH-1:0] in_sig = '0;
  reg [CONTROL_WIDTH-1:0] control_word_i;
  reg [1:0] tier = '0;
  reg [15:0] gp_mx = '0;  // int8 lane parameters, one set per batch from <act>_par.mem
  reg [7:0] gp_shx = '0, gp_zin = '0, gp_shout = '0, gp_zout = '0;
  reg [31:0] gp_mout = '0;
  reg [79:0] par[0:MAX_BATCHES-1];
  sienna_fmt_pkg::lane_params_t lane_par;
  assign lane_par = IS_INT ? $bits(lane_par)'({gp_mx, gp_shx[4:0], gp_zin, gp_mout[23:0], gp_shout[5:0], gp_zout}) : '0;
  reg cwr = 1'b0;
  logic lane_idle;  // the lane's idle_o: a write is taken only while it is high
  int coef_refused = 0;  // writes driven while the lane was busy
  always @(posedge clk) if (cwr && !lane_idle) coef_refused++;
  reg [8:0] caddr = '0;
  reg [31:0] cdata = '0;
  reg [43:0] loads[0:LOADS-1];  // {address, data} per write; an address of fff ends the list
  bit do_load;
  int n_loads;

  // The coefficient-image check: the memory's registered state against the image the host meant it to hold.
  localparam int IMG_N = gpnae_pkg::COEF_WORDS + gpnae_pkg::NUM_TIERS * gpnae_pkg::NUM_DESC * (gpnae_pkg::PMAX + 8)
                         + gpnae_pkg::NUM_TIERS * (gpnae_pkg::TAIL_MAXC + 2);
  localparam logic [31:0] IMG_END = 32'hC0EF_1A5E;  // the line after the last field, so a short or missing file fails
  reg [31:0] img_def[0:IMG_N], img_load[0:IMG_N];  // the reset default's and the loaded image's fields, Mem.contents() order
  int coef_checks = 0, coef_bad = 0;
  gpnae_pkg::tail_t cc_tail[gpnae_pkg::NUM_TIERS];
  if (sienna_fmt_pkg::HAS_FLOAT_TAIL) begin : G_CC_TAIL
    for (genvar t = 0; t < gpnae_pkg::NUM_TIERS; t++) begin : G_T
      assign cc_tail[t] = dut.COEF.G_TAIL.tail[t];
    end
  end else begin : G_CC_NO_TAIL
    for (genvar t = 0; t < gpnae_pkg::NUM_TIERS; t++) begin : G_T
      assign cc_tail[t] = '0;
    end
  end

  // One field: what the memory holds against the image's word; a difference is counted and named with its load address.
  task automatic coef_field(input string where, input string what, input int addr, input logic [31:0] got, input logic [31:0] want, inout int bad);
    if (got !== want) begin
      if (bad < 20) $display("  COEF IMAGE %s: %s (load address %0d) holds %h, the image has %h", where, what, addr, got, want);
      bad++;
    end
  endtask

  // The whole memory against an image: every word, every descriptor field and, with the float tail, every tail field.
  task automatic coef_check(input string where, input bit loaded);
    int bad, k, ab;
    logic [31:0] w;
    gpnae_pkg::desc_t q;
    bad = 0;
    for (int a = 0; a < gpnae_pkg::COEF_WORDS; a++) begin
      w = loaded ? img_load[a] : img_def[a];
      coef_field(where, $sformatf("word %0d", a), a, 32'(dut.COEF.words[a]), w, bad);
    end
    k = gpnae_pkg::COEF_WORDS;
    for (int t = 0; t < gpnae_pkg::NUM_TIERS; t++)
      for (int d = 0; d < gpnae_pkg::NUM_DESC; d++) begin
        q  = dut.COEF.desc[t][d];
        ab = gpnae_pkg::A_DESC + gpnae_pkg::DESC_STRIDE * (t * gpnae_pkg::NUM_DESC + d);
        for (int j = 0; j < gpnae_pkg::PMAX; j++)
          coef_field(where, $sformatf("tier %0d descriptor %0d bound %0d", t, d, j), ab + j, 32'(q.bound[j]), loaded ? img_load[k+j] : img_def[k+j], bad);
        k += gpnae_pkg::PMAX;
        coef_field(where, $sformatf("tier %0d descriptor %0d np", t, d), ab + gpnae_pkg::F_SET, 32'(q.np), loaded ? img_load[k] : img_def[k], bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d deg", t, d), ab + gpnae_pkg::F_SET, 32'(q.deg), loaded ? img_load[k+1] : img_def[k+1], bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d base", t, d), ab + gpnae_pkg::F_SET, 32'(q.base), loaded ? img_load[k+2] : img_def[k+2], bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d reflect", t, d), ab + gpnae_pkg::F_SET, 32'(q.reflect), loaded ? img_load[k+3] : img_def[k+3],
                   bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d exp_base", t, d), ab + gpnae_pkg::F_EXP, 32'(q.exp_base), loaded ? img_load[k+4] : img_def[k+4],
                   bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d exp_deg", t, d), ab + gpnae_pkg::F_EXP, 32'(q.exp_deg), loaded ? img_load[k+5] : img_def[k+5],
                   bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d center", t, d), ab + gpnae_pkg::F_CENTER, 32'(q.center), loaded ? img_load[k+6] : img_def[k+6],
                   bad);
        coef_field(where, $sformatf("tier %0d descriptor %0d frac", t, d), ab + gpnae_pkg::F_FRAC, 32'(q.frac), loaded ? img_load[k+7] : img_def[k+7], bad);
        k += 8;
      end
    if (sienna_fmt_pkg::HAS_FLOAT_TAIL)
      for (int t = 0; t < gpnae_pkg::NUM_TIERS; t++) begin
        ab = gpnae_pkg::A_TAIL + gpnae_pkg::TAIL_STRIDE * t;
        for (int j = 0; j < gpnae_pkg::TAIL_MAXC; j++)
          coef_field(where, $sformatf("tail %0d coef %0d", t, j), ab + j, cc_tail[t].coef[j], loaded ? img_load[k+j] : img_def[k+j], bad);
        coef_field(where, $sformatf("tail %0d deg", t), ab + gpnae_pkg::TAIL_MAXC, 32'(cc_tail[t].deg), loaded ? img_load[k+6] : img_def[k+6], bad);
        coef_field(where, $sformatf("tail %0d newton", t), ab + gpnae_pkg::TAIL_MAXC, 32'(cc_tail[t].newton), loaded ? img_load[k+7] : img_def[k+7], bad);
        k += gpnae_pkg::TAIL_MAXC + 2;
      end
    coef_checks++;
    if (bad > 0) begin
      $display("  COEF IMAGE %s: %0d fields differ from the %s image", where, bad, loaded ? "loaded" : "default");
      coef_bad++;
    end
  endtask

  // Input link: the testbench is the producer, counting the lane's credits.
  credit_link_if #(.DATA_W(DATA_WIDTH + 1), .CRW(1)) lin ();
  credit_link_if #(.DATA_W(DATA_WIDTH + ((FAULT == 3) ? 1 : 0)), .CRW(1)) lout ();
  wire in_has;
  wire [$clog2(IN_SLOTS + 1)-1:0] in_cnt;
  assign lin.put  = in_put;
  assign lin.data = {in_last, in_sig};
  credit_counter #(.MAX(IN_SLOTS), .CRW(1)) in_cc (.clk_i(clk), .rstn_i(rstn_i), .put_i(lin.put), .credit_i(lin.credit),
                                                    .has_credit_o(in_has), .count_o(in_cnt));

  // Output link: the testbench is the consumer; a captured result frees its slot at once, its credit goes back unless stalled.
  int out_slots = OUT_CAP, stall_pct = 0;
  int owed;  // freed slots not yet credited; the advertisement after reset is the first out_slots of them
  reg ocred;
  assign lout.credit = ocred;
  always @(posedge clk) begin
    if (!rstn_i) begin
      owed  <= out_slots;
      ocred <= 1'b0;
    end else if (owed > 0 && (stall_pct == 0 || $urandom_range(0, 99) >= stall_pct)) begin
      owed  <= owed - 1 + int'(lout.put);
      ocred <= 1'b1;
    end else begin
      owed  <= owed + int'(lout.put);
      ocred <= 1'b0;
    end
  end

  // Both links checked; the output checker's drain test needs the full advertisement.
  reg drained = 1'b0;
  int drain_bad = 0;
  credit_link_checker #(.SLOTS(IN_SLOTS)) chk_in (.clk_i(clk), .rstn_i(rstn_i), .drained_i(drained), .lnk(lin));
  credit_link_checker #(.SLOTS(OUT_CAP)) chk_out (.clk_i(clk), .rstn_i(rstn_i), .drained_i(drained && out_slots == OUT_CAP),
                                                  .lnk(lout));

  time clk_period;  // measured once, in the same context that reads it

  reg [DATA_WIDTH-1:0] stim[0:MAX_TOTAL-1];
  reg [DATA_WIDTH-1:0] gold[0:MAX_TOTAL-1];
  reg [DATA_WIDTH-1:0] got [0:31];
  reg [DATA_WIDTH-1:0] got_all[0:MAX_TOTAL-1];  // every batch's outputs, for +dump_got
  reg [DATA_WIDTH-1:0] ov_got[0:MAX_TOTAL-1];
  integer n_captured;
  int ov_n, ov_mid;  // overlap outputs, and puts made while the lane was popping
  reg ov_on = 1'b0, ov_clear = 1'b0;
  reg cap_clear;

  integer total_checked, total_exact, total_failed, total_missing;

  gpnae #(
      .ADDR_LINES(ADDR_LINES),
      .CONTROL_WIDTH(CONTROL_WIDTH),
      .OUT_MAX(OUT_CAP),
      .OUT_CRW(1)
  ) dut (
      .clk_i(clk),
      .rstn_i(rstn_i),
      .in(lin),
      .out(lout),
      .control_word_i(control_word_i),
      .tier_i(tier),
      .par_i(lane_par),
      .coef_wr_i(cwr),
      .coef_addr_i(caddr),
      .coef_data_i(cdata),
      .idle_o(lane_idle)
  );

  always #5 clk = ~clk;

  // Cycles come from $time, not a clocked counter: Verilator's threaded scheduler gives the coroutine a stale view of one.

  localparam logic [3:0] GS_IDLE = 4'd0, GS_CAP = 4'd1, GS_NEXT = 4'd9;  // gpnae's gstate_t encoding
  logic [3:0] lane_gs;  // the lane's state, FIFO count and group size
  logic [ADDR_LINES:0] lane_cnt;
  logic [4:0] lane_grp;
  logic [$clog2(OUT_CAP + 1)-1:0] lane_ocnt;  // the lane's output credits
  logic lane_pend, lane_ook;  // a last put waits, and K output credits are held
  assign lane_gs   = dut.gstate;
  assign lane_cnt  = dut.fifo_count;
  assign lane_grp  = 5'(dut.grp_n);
  assign lane_ocnt = dut.out_cnt;
  assign lane_pend = dut.last_pend;
  assign lane_ook  = dut.out_ok;

  // The lane has words to start but waits for K output credits while every credit the consumer advertised is back: below K, a deadlock.
  logic starved;
  assign starved = (lane_cnt != '0) && !lane_ook && ((lane_gs == GS_IDLE && lane_pend) || lane_gs == GS_NEXT) && owed == 0 && !ocred
                   && int'(lane_ocnt) == out_slots && out_slots < LANE_K;
  a_out_starved: assert property (@(posedge clk) disable iff (!rstn_i) !$rose(starved))
    else $error("a_out_starved: the lane waits for %0d output credits and holds all %0d the consumer advertised", LANE_K, out_slots);

  // Sole writer of ov_n, ov_got[] and ov_mid.
  always @(posedge clk) begin
    if (ov_clear) begin
      ov_n   <= 0;
      ov_mid <= 0;
    end else if (ov_on) begin
      if (lout.put && ov_n < TOTAL) begin
        ov_got[ov_n] <= lout.data;
        ov_n         <= ov_n + 1;
      end
      if (lin.put && lane_gs == GS_CAP) ov_mid <= ov_mid + 1;
    end
  end

  // Every link input changes 1 ns after an edge, so the lane and the assertions see the same value.
  task automatic tick();
    @(posedge clk);
    #1;
  endtask

  // coef_load.mem's writes, one per cycle, while the lane is idle.
  task automatic load_image();
    for (int i = 0; i < n_loads; i++) begin
      cwr   = 1'b1;
      caddr = loads[i][40:32];
      cdata = loads[i][31:0];
      tick();
    end
    cwr = 1'b0;
    tick();  // a taken write lands at the edge after it was taken
  endtask

  task automatic reset_sequence();
    begin
      rstn_i = 0;
      in_put = 0;
      in_last = 0;
      in_sig = '0;
      control_word_i = '0;
      cwr = 1'b0;
      cap_clear = 1;          // the capture block owns n_captured; pulse a clear
      repeat (8) @(posedge clk);  // fp32Adder's unreset valid stages need 4+ cycles of reset to flush (D-7)
      cap_clear = 0;
      @(negedge clk);
      rstn_i = 1;  // released between edges, so the first credits are seen with the assertions enabled
      tick();
      coef_check("reset", 1'b0);  // the reset default, read a cycle after reset ends
      if (do_load) begin
        load_image();
        coef_check("load", 1'b1);  // read after the last write's edge
      end
    end
  endtask

  // One element on the input link, once a credit is held; last marks the set's final element.
  task automatic put_in(input [DATA_WIDTH-1:0] d, input bit last);
    while (!in_has) tick();
    in_sig  = d;
    in_last = last;
    in_put  = 1;
    tick();
    in_put  = 0;
    in_last = 0;
  endtask

  // Both links drained: every input credit back with the producer, every output credit back with the lane; then the checkers test it.
  task automatic drain_check(input string where);
    int guard;
    guard = 0;
    tick();
    while (!(int'(in_cnt) == IN_SLOTS && owed == 0 && !ocred && int'(lane_ocnt) == out_slots) && guard < 4 * OUT_CAP) begin
      tick();
      guard++;
    end
    if (guard >= 4 * OUT_CAP) begin
      drain_bad++;
      $display("  DRAIN %s: input credits %0d of %0d, output credits %0d of %0d, %0d owed", where, in_cnt, IN_SLOTS, lane_ocnt,
               out_slots, owed);
    end else begin
      drained = 1;
      tick();
      drained = 0;
    end
  endtask

  // Sole writer of n_captured and got[]: Verilator's threaded scheduler does not tolerate cross-context writes.
  always @(posedge clk) begin
    if (!rstn_i || cap_clear) begin
      n_captured <= 0;
    end else if (lout.put && n_captured < SIGNALS_PER_BATCH) begin
      got[n_captured] <= lout.data;
      n_captured      <= n_captured + 1;
    end
  end

  task automatic run_activation(input [CONTROL_WIDTH-1:0] ctrl, input string act_name);
    int exact_n, fail_n, miss_n, guard, base, shown, bfail;
    time t0;
    begin
      exact_n = 0; fail_n = 0; miss_n = 0; shown = 0;
      $display("\n==============================================");
      $display(" %s  control=%03b  tier %0d  %0d batches x %0d signals", act_name.toupper(), ctrl, tier, NUM_BATCHES, SIGNALS_PER_BATCH);
      $display("==============================================");

      t0 = $time;
      for (int b = 0; b < NUM_BATCHES; b++) begin
        base = b * SIGNALS_PER_BATCH;

        reset_sequence();
        control_word_i = ctrl;
        if (IS_INT) {gp_mx, gp_shx, gp_zin, gp_mout, gp_shout, gp_zout} = par[b];

        // FAULT 1: one put past the FIFO's depth, none of them credited; a reset then starts the batch clean.
        if (FAULT == 1 && b == 0 && act_name == "selu") begin
          in_sig = stim[base];
          in_put = 1;
          repeat (IN_SLOTS + 1) tick();
          in_put = 0;
          reset_sequence();
          control_word_i = ctrl;
        end
        if (FAULT == 5 && b == 0 && act_name == "selu") tier = 2'd3;

        for (int i = 0; i < SIGNALS_PER_BATCH; i++)
          put_in(stim[base+i], (i == SIGNALS_PER_BATCH - 1));

        // FAULT 2: a credited put once the lane has popped part of the batch; it must come out after the batch, in order.
        if (FAULT == 2 && b == 0 && act_name == "selu") begin
          while (!(lane_gs == GS_CAP && int'(lane_cnt) < SIGNALS_PER_BATCH && in_has)) tick();
          put_in(stim[base], 1'b0);
        end
        // FAULT 4: coefficient writes while the lane works on the batch: words 0 and 1 and SELU's descriptor, which would change its words.
        if (FAULT == 4 && b == 0 && act_name == "selu") begin
          while (lane_gs == GS_IDLE) tick();
          for (int w = 0; w < 4; w++) begin
            cwr   = 1'b1;
            caddr = (w < 2) ? 9'(w) : 9'(128 + w);
            cdata = 32'h4120_0000;
            tick();
          end
          cwr = 1'b0;
          coef_check("refused writes", do_load);  // every write refused: the memory is still the image
        end

        guard = 0;
        while (n_captured < SIGNALS_PER_BATCH && guard < TIMEOUT_CYCLES) begin
          @(posedge clk);
          guard = guard + 1;
        end
        drain_check({act_name, " batch"});
        if (FAULT == 5) tier = 2'(TIER);

        bfail = fail_n + miss_n;
        for (int i = 0; i < SIGNALS_PER_BATCH; i++) begin
          got_all[base+i] = (i < n_captured) ? got[i] : 'x;
          if (i >= n_captured) begin
            miss_n++;
            if (shown < 40) begin
              $display("  b%0d i%0d  in %0h  expected %0h  MISSING", b, i, stim[base+i], gold[base+i]);
              shown++;
            end
          end else if (got[i] === gold[base+i]) exact_n++;
          else begin
            fail_n++;
            if (shown < 40) begin
              $display("  b%0d i%0d  in %0h  expected %0h  got %0h  FAIL", b, i, stim[base+i], gold[base+i], got[i]);
              shown++;
            end
          end
        end
        // Batches with a wrong or missing output, so regression.py can split the parameter sets.
        if (fail_n + miss_n > bfail) $display("  BATCHFAIL %s b%0d : %0d", act_name, b, fail_n + miss_n - bfail);
      end

      // +dump_got: every output of the batch runs goes to <act>_got.mem, so regression.py judges the RTL's own words.
      if ($test$plusargs("dump_got")) begin
        int dump_h;
        dump_h = $fopen({STIM_DIR, act_name, "_got.mem"}, "w");
        if (dump_h == 0) $fatal(1, "cannot write %s_got.mem", act_name);
        for (int i = 0; i < TOTAL; i++) $fwrite(dump_h, "%h\n", got_all[i]);
        $fclose(dump_h);
      end

      $display("  ----------------------------------------------");
      $display("  RESULT %s : total %0d  exact %0d  failed %0d  missing %0d", act_name, TOTAL, exact_n, fail_n, miss_n);
      $display("  CYCLES %s : total %0d  per-input %0d", act_name, ($time - t0) / clk_period,
               (($time - t0) / clk_period) / (TOTAL > 0 ? TOTAL : 1));
      total_checked += TOTAL;
      total_exact   += exact_n;
      total_failed  += fail_n;
      total_missing += miss_n;
    end
  endtask

  // int8 protocol edges (stream_*.mem): groups streamed with no reset, outputs checked bit for bit, group starts checked.
  localparam int S_SEG = 64, S_GRP = 1024, S_EL = 8192, S_BND = 2048;  // stream capacities
  localparam int M_HOLD = 1, M_BUSY = 2;  // mode 0: puts, last on the final one; 1: the final put held back 8 cycles; 2: puts while busy
  reg [31:0] s_cnt[0:3];  // segments, groups, elements, expected group starts
  reg [95:0] s_seg[0:S_SEG-1];  // {control word, groups, lane parameters as in <act>_par.mem}
  reg [31:0] s_grp[0:S_GRP-1];  // {mode, elements, group starts expected before this group}
  reg [7:0] s_in[0:S_EL-1], s_exp[0:S_EL-1];
  reg [DATA_WIDTH-1:0] s_got[0:S_EL-1];  // also the float lane's one-element groups
  reg [15:0] s_bnd[0:S_BND-1], s_obs[0:S_BND-1];  // {state the group started from, size} per group start
  integer s_n, s_nobs;
  reg s_on = 1'b0, s_clear = 1'b0, s_abort = 1'b0;

  // Sole writer of s_n and s_got[].
  always @(posedge clk) begin
    if (s_clear) s_n <= 0;
    else if (s_on && lout.put && s_n < S_EL) begin
      s_got[s_n] <= lout.data;
      s_n        <= s_n + 1;
    end
  end

  logic [3:0] gs_q;
  // Sole writer of s_nobs and s_obs[]: a group starts where the lane enters G_CAP, from G_IDLE or G_NEXT.
  always @(posedge clk) begin
    gs_q <= lane_gs;
    if (s_clear) s_nobs <= 0;
    else if (s_on && lane_gs == GS_CAP && gs_q != GS_CAP && s_nobs < S_BND) begin
      s_obs[s_nobs] <= {4'd0, gs_q, 3'd0, lane_grp};
      s_nobs        <= s_nobs + 1;
    end
  end

  // Every output written so far is back and the lane is in G_IDLE with an empty FIFO.
  task automatic s_quiet(input int want);
    int guard;
    guard = 0;
    while (!(s_n >= want && lane_gs == GS_IDLE && lane_cnt == 0) && guard < TIMEOUT_CYCLES) begin
      tick();
      guard++;
    end
    if (guard >= TIMEOUT_CYCLES) begin
      s_abort = 1;
      $display("  STREAM timeout: %0d of %0d outputs, lane state %0d, FIFO %0d", s_n, want, lane_gs, lane_cnt);
    end
  endtask

  task automatic run_stream();
    int n_seg, n_grp, n_el, n_bnd, g, wr, mode, n, n_prev, guard, fails, missing, extra, wrong, edge_err, shown;
    logic [7:0] ctrl, n_groups;
    time t0;
    begin
      $readmemh({STIM_DIR, "stream_cnt.mem"}, s_cnt);
      $readmemh({STIM_DIR, "stream_seg.mem"}, s_seg);
      $readmemh({STIM_DIR, "stream_grp.mem"}, s_grp);
      $readmemh({STIM_DIR, "stream_in.mem"}, s_in);
      $readmemh({STIM_DIR, "stream_exp.mem"}, s_exp);
      $readmemh({STIM_DIR, "stream_bnd.mem"}, s_bnd);
      n_seg = s_cnt[0];
      n_grp = s_cnt[1];
      n_el  = s_cnt[2];
      n_bnd = s_cnt[3];
      $display("\n==============================================");
      $display(" STREAM  %0d segments  %0d groups  %0d elements, no reset between groups", n_seg, n_grp, n_el);
      $display("==============================================");
      reset_sequence();
      s_clear = 1;
      s_on    = 1;
      tick();
      s_clear  = 0;
      g        = 0;
      wr       = 0;
      edge_err = 0;
      t0       = $time;
      for (int s = 0; s < n_seg && !s_abort; s++) begin
        s_quiet(wr);  // the lane parameters change only while the lane is idle
        {ctrl, n_groups, gp_mx, gp_shx, gp_zin, gp_mout, gp_shout, gp_zout} = s_seg[s];
        control_word_i = ctrl[CONTROL_WIDTH-1:0];
        tick();
        for (int k = 0; k < int'(n_groups) && !s_abort; k++) begin
          mode   = int'(s_grp[g][31:24]);
          n      = int'(s_grp[g][23:16]);
          n_prev = int'(s_grp[g][15:0]);
          g++;
          if (mode == M_BUSY) begin
            // The previous group has started and left G_CAP, so its words are out of the FIFO; the lane still works on it.
            guard = 0;
            while (!(s_nobs >= n_prev && lane_gs != GS_IDLE && lane_gs != GS_CAP && lane_cnt == 0) && guard < TIMEOUT_CYCLES) begin
              tick();
              guard++;
            end
            if (guard >= TIMEOUT_CYCLES) begin
              s_abort = 1;
              $display("  STREAM timeout before busy group %0d: lane state %0d, FIFO %0d", g - 1, lane_gs, lane_cnt);
            end
          end else s_quiet(wr);
          if (s_abort) break;
          for (int i = 0; i < n - 1; i++) begin
            put_in(s_in[wr], 1'b0);
            wr++;
          end
          if (mode == M_HOLD) begin
            // Without its last put the set waits in the FIFO.
            repeat (8) tick();
            if (lane_gs !== GS_IDLE || $isunknown(lane_cnt) || int'(lane_cnt) != n - 1) begin
              edge_err++;
              $display("  STREAM group %0d: expected %0d elements to wait in the FIFO for the last put, lane state %0d, FIFO %0d",
                       g - 1, n - 1, lane_gs, lane_cnt);
            end
          end
          put_in(s_in[wr], 1'b1);
          wr++;
          if (mode == M_BUSY && ($isunknown(lane_gs) || lane_gs == GS_IDLE)) begin
            edge_err++;
            $display("  STREAM group %0d: the last put did not arrive while the lane was busy", g - 1);
          end
        end
      end
      if (!s_abort) s_quiet(wr);
      repeat (20) tick();  // a spurious put would show up in s_n
      drain_check("stream");
      fails = 0;
      shown = 0;
      for (int i = 0; i < n_el && i < s_n; i++)
        if (s_got[i] !== s_exp[i]) begin
          fails++;
          if (shown < 40) begin
            $display("  STREAM e%0d  in %0h  expected %0h  got %0h  FAIL", i, s_in[i], s_exp[i], s_got[i]);
            shown++;
          end
        end
      missing = (s_n < n_el) ? n_el - s_n : 0;
      extra   = (s_n > n_el) ? s_n - n_el : 0;
      wrong   = 0;
      for (int i = 0; (i < n_bnd || i < s_nobs) && i < S_BND; i++)
        if (i >= n_bnd || i >= s_nobs || s_obs[i] !== s_bnd[i]) begin
          wrong++;
          if (shown < 80) begin
            $display("  STREAM group start %0d: expected %0h, observed %0h (state << 8 | size)", i,
                     (i < n_bnd) ? s_bnd[i] : 16'hFFFF, (i < s_nobs) ? s_obs[i] : 16'hFFFF);
            shown++;
          end
        end
      s_on = 0;
      // +dump_got: the stream's outputs go to stream_got.mem, so regression.py gates them on the true function.
      if ($test$plusargs("dump_got")) begin
        int dump_h;
        dump_h = $fopen({STIM_DIR, "stream_got.mem"}, "w");
        if (dump_h == 0) $fatal(1, "cannot write stream_got.mem");
        for (int i = 0; i < s_n && i < S_EL; i++) $fwrite(dump_h, "%h\n", s_got[i]);
        $fclose(dump_h);
      end
      $display("  ----------------------------------------------");
      $display("  STREAM : elements %0d  exact %0d  failed %0d  missing %0d  extra %0d", n_el, n_el - fails - missing, fails,
               missing, extra);
      $display("  STREAM boundaries : expected %0d  observed %0d  wrong %0d  edge errors %0d", n_bnd, s_nobs, wrong, edge_err);
      $display("  STREAM cycles : %0d", ($time - t0) / clk_period);
      total_checked += n_el;
      total_exact   += n_el - fails - missing;
      total_failed  += fails + extra + wrong + edge_err + (s_abort ? 1 : 0);
      total_missing += missing;
    end
  endtask

  // Every batch of an activation streamed with no reset, each set's words put as credits allow, so the next set fills while the lane pops;
  // the outputs against the model's, and the cycles per element (the steady state the cycles point reports).
  task automatic run_overlap(input [CONTROL_WIDTH-1:0] ctrl, input string act_name);
    int guard, differ, missing;
    time t0;
    begin
      reset_sequence();
      control_word_i = ctrl;
      ov_clear = 1;
      ov_on    = 1;
      tick();
      ov_clear = 0;
      t0 = $time;
      for (int b = 0; b < NUM_BATCHES; b++) begin
        // int8 lane parameters change only while the lane is idle, so a new set waits for the old one to finish.
        if (IS_INT && (b == 0 || par[b] != par[b-1])) begin
          guard = 0;
          while (!(ov_n >= b * SIGNALS_PER_BATCH && lane_gs == GS_IDLE && lane_cnt == 0) && guard < TIMEOUT_CYCLES) begin
            tick();
            guard++;
          end
          {gp_mx, gp_shx, gp_zin, gp_mout, gp_shout, gp_zout} = par[b];
          tick();
        end
        for (int i = 0; i < SIGNALS_PER_BATCH; i++) begin
          if (stall_pct != 0 && $urandom_range(0, 99) < stall_pct) tick();  // the producer stalls too
          put_in(stim[b*SIGNALS_PER_BATCH+i], (i == SIGNALS_PER_BATCH - 1));
        end
      end
      guard = 0;
      while (ov_n < TOTAL && guard < TIMEOUT_CYCLES) begin
        tick();
        guard++;
      end
      $display("  OVERLAP %s : cycles to the last result %0d", act_name, ($time - t0) / clk_period);
      repeat (20) tick();  // a spurious put would show up in ov_n
      drain_check({act_name, " overlap"});
      ov_on   = 0;
      differ  = 0;
      missing = (ov_n < TOTAL) ? TOTAL - ov_n : 0;
      for (int i = 0; i < TOTAL && i < ov_n; i++)
        if (ov_got[i] !== gold[i]) begin
          if (differ < 12) $display("  OVERLAP %s e%0d  in %0h  expected %0h  got %0h  DIFFER", act_name, i, stim[i], gold[i], ov_got[i]);
          differ++;
        end
      $display("  OVERLAP %s : elements %0d  identical %0d  differ %0d  missing %0d  puts while popping %0d", act_name, TOTAL,
               TOTAL - differ - missing, differ, missing, ov_mid);
      // No put during a pop would leave the overlap untested.
      total_failed += differ + missing + (ov_n > TOTAL ? 1 : 0) + (ov_mid == 0 ? 1 : 0);
    end
  endtask

  // Floats: each element of the last batch alone as a one-element group, no reset; checked against the model.
  task automatic run_single(input string act_name);
    int base, fails, missing, extra, wrong, shown;
    begin
      base    = (NUM_BATCHES - 1) * SIGNALS_PER_BATCH;
      s_abort = 0;
      s_clear = 1;
      s_on    = 1;
      tick();
      s_clear = 0;
      for (int i = 0; i < SIGNALS_PER_BATCH && !s_abort; i++) begin
        s_quiet(i);  // the previous group is out and the lane is idle with an empty FIFO
        if (s_abort) break;
        put_in(stim[base+i], 1'b1);
      end
      if (!s_abort) s_quiet(SIGNALS_PER_BATCH);
      repeat (20) tick();  // a spurious put would show up in s_n
      drain_check({act_name, " single"});
      fails = 0;
      shown = 0;
      for (int i = 0; i < SIGNALS_PER_BATCH && i < s_n; i++)
        if (s_got[i] !== gold[base+i]) begin
          fails++;
          if (shown < 12) begin
            $display("  SINGLE i%0d  in %0h  expected %0h  got %0h  FAIL", i, stim[base+i], gold[base+i], s_got[i]);
            shown++;
          end
        end
      missing = (s_n < SIGNALS_PER_BATCH) ? SIGNALS_PER_BATCH - s_n : 0;
      extra   = (s_n > SIGNALS_PER_BATCH) ? s_n - SIGNALS_PER_BATCH : 0;
      wrong   = (s_nobs > s_n) ? s_nobs - s_n : s_n - s_nobs;  // one group start per output
      for (int i = 0; i < s_nobs && i < S_BND; i++) if (s_obs[i][4:0] !== 5'd1) wrong++;
      s_on = 0;
      $display("  SINGLE %s : groups of one %0d  passed %0d  failed %0d  missing %0d  extra %0d  wrong size %0d", act_name,
               SIGNALS_PER_BATCH, SIGNALS_PER_BATCH - fails - missing, fails, missing, extra, wrong);
      total_failed  += fails + extra + wrong + (s_abort ? 1 : 0);
      total_missing += missing;
      @(posedge clk);  // back on a clock edge, so the next activation's CYCLES count is unchanged
    end
  endtask

  task automatic run_one(input [CONTROL_WIDTH-1:0] ctrl, input string act_name);
    $readmemh({STIM_DIR, act_name, "_in.mem"}, stim);
    $readmemh({STIM_DIR, act_name, "_exp.mem"}, gold);
    if (IS_INT) $readmemh({STIM_DIR, act_name, "_par.mem"}, par);
    if (!$test$plusargs("overlap_only")) begin
      run_activation(ctrl, act_name);
      if (!IS_INT) run_single(act_name);
    end
    run_overlap(ctrl, act_name);
  endtask

  initial begin
    int t;
    clk = 0;
    total_checked = 0; total_exact = 0; total_failed = 0; total_missing = 0;
    cap_clear = 0;
    n_captured = 0;
    if (!$value$plusargs("out_slots=%d", out_slots)) out_slots = OUT_CAP;
    if (!$value$plusargs("stall_pct=%d", stall_pct)) stall_pct = 0;
    if (out_slots < 1 || out_slots > OUT_CAP) $fatal(1, "+out_slots=%0d: 1 to %0d", out_slots, OUT_CAP);  // below K the lane deadlocks
    if (stall_pct < 0 || stall_pct > 99) $fatal(1, "+stall_pct=%0d: 0 to 99", stall_pct);
    void'($value$plusargs("batches=%d", NUM_BATCHES));
    void'($value$plusargs("per_batch=%d", SIGNALS_PER_BATCH));
    void'($value$plusargs("timeout=%d", TIMEOUT_CYCLES));
    TOTAL = NUM_BATCHES * SIGNALS_PER_BATCH;
    if (SIGNALS_PER_BATCH < 1 || SIGNALS_PER_BATCH > 32 || NUM_BATCHES < 1 || TOTAL > MAX_TOTAL || NUM_BATCHES > MAX_BATCHES)
      $fatal(1, "+batches=%0d +per_batch=%0d: per_batch 1..32 and at most %0d inputs", NUM_BATCHES, SIGNALS_PER_BATCH, MAX_TOTAL);
    if ($value$plusargs("tier=%d", t)) TIER = t;
    tier = 2'(TIER);
    do_load = $test$plusargs("load");
    n_loads = 0;
    $readmemh({STIM_DIR, "coef_default.mem"}, img_def);
    if (img_def[IMG_N] !== IMG_END) $fatal(1, "coef_default.mem: not %0d fields and the end word (regression.py writes it with every run)", IMG_N);
    if (do_load) begin
      $readmemh({STIM_DIR, "coef_loaded.mem"}, img_load);
      if (img_load[IMG_N] !== IMG_END) $fatal(1, "coef_loaded.mem: not %0d fields and the end word (regression.py writes it with the load file)", IMG_N);
      for (int i = 0; i < LOADS; i++) loads[i] = '1;
      $readmemh({STIM_DIR, "coef_load.mem"}, loads);
      while (n_loads < LOADS && loads[n_loads][43:32] != 12'hFFF) n_loads++;
    end

    $display("==============================================");
    $display(" GPNAE ACTIVATION VERIFICATION");
    $display("==============================================");
    $display(" Format       : %s  (%0d bits)", FMT_NAME, DATA_WIDTH);
    $display(" Batches      : %0d x %0d signals = %0d per activation", NUM_BATCHES, SIGNALS_PER_BATCH, TOTAL);
    $display(" Tier         : %0d%s", tier, do_load ? $sformatf(", of the image loaded from coef_load.mem (%0d writes)", n_loads) : "");
    $display(" Reference    : gpnae_model, bit for bit");
    $display(" Output link  : %0d slots, %0d%% of credit returns stalled", out_slots, stall_pct);

    // Measure the clock period here, in the context that later divides by it.
    @(posedge clk);
    clk_period = $time;
    @(posedge clk);
    clk_period = $time - clk_period;

    run_one(3'b001, "selu");
    run_one(3'b010, "sigmoid");
    run_one(3'b011, "tanh");
    if (IS_INT || $test$plusargs("all_acts")) begin  // +all_acts: a float run also takes ReLU and linear
      run_one(3'b100, "relu");
      run_one(3'b101, "linear");
      if (IS_INT && !$test$plusargs("overlap_only") && !$test$plusargs("no_stream")) run_stream();
    end

    $display("\n==============================================");
    $display(" SUMMARY");
    $display("==============================================");
    $display(" Total    : %0d", total_checked);
    $display(" Exact    : %0d", total_exact);
    total_failed += drain_bad;  // a drain point with a credit missing fails the run
    total_failed += coef_bad;  // a coefficient image that differs fails the run
    $display(" COEF IMAGE : checks %0d  differ %0d", coef_checks, coef_bad);
    $display(" Failed   : %0d", total_failed);
    $display(" Missing  : %0d", total_missing);
    if (FAULT == 4) $display(" LOAD REFUSED: %0d coefficient writes while the lane was busy", coef_refused);
    $display("----------------------------------------------");
    if (total_failed == 0 && total_missing == 0) $display(" RESULT: PASSED");
    else $display(" RESULT: FAILED (%0d mismatches, %0d missing)", total_failed, total_missing);
    $display("==============================================");

    #100 $finish;
  end

  // ── Protocol assertions ───────────────────────────────────────────────
  // A result and its put share an edge, so the output word may change only on a put.
  property valid_done_signal;
    @(posedge clk) disable iff (!rstn_i) !$stable(lout.data) |-> lout.put;  // reset clears it silently
  endproperty
  assert property (valid_done_signal)
  else $error("Final result changed without a done pulse!");

  // 0.5 s, or 4 us (400 cycles) per input per activation when that is longer.
  initial begin
    longint tmo;
    #1;
    tmo = (longint'(TOTAL) * 20000 > 500000000) ? longint'(TOTAL) * 20000 : 500000000;
    #(tmo) $error("Testbench timeout!");
    $finish;
  end

  // Waveforms only in a TRACE=1 build (ENABLE_TRACE), scoped to the DUT: dumping the whole TB crashes Verilator's trace_init.
`ifdef ENABLE_TRACE
  initial begin
`ifdef TRACE_FST
    $dumpfile("tb_gpnae.fst");
`else
    $dumpfile("tb_gpnae.vcd");
`endif
    $dumpvars(1, dut);
  end
`endif

endmodule
