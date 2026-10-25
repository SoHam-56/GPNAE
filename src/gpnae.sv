`default_nettype wire
`timescale 1ns / 100ps

// GPNAE, the activation lane: each activation as polynomial pieces, its coefficient sets and piece bounds data in a host-writable memory.
//   SELU     x >= 0  lambda x;  x < 0  x P_p(x) on piece p of |x|, -lambda*alpha past the last bound
//   sigmoid  x >= 0  P_p(|x|), 1 past the last bound;  x < 0  1 - P_p(|x|) or a set of its own, then e^-|x| past the last bound:
//                    fp32 E (1 - E) with E = 2^-n P(f) on the same MAC, bf16 E / (1 + E) in fp32 on the tail
//   tanh             x P_p(x^2), x at tiny |x|, +-1 past the last bound
//   int8 runs each in Q4.11 on a centered operand (x - c, or |x| - c with P ~ tanh(|x|)), with int8 out; ReLU and linear pass at capture.
// One accuracy tier, within 1%; the define picks the math (sienna_fmt_pkg).
// Elements run in groups of up to K: captured from the FIFO, classified (gpnae_act_in) on the way into the barrel MAC, post-processed
// one per cycle (gpnae_post), and retired in order on the output link once K output credits are held.
module gpnae
  import gpnae_pkg::*;
#(
    parameter int ADDR_LINES    = 5,
    parameter int CONTROL_WIDTH = 3,   // 001 SELU, 010 sigmoid, 100 ReLU, 101 linear; every other word runs tanh
    parameter int K             = 16,
    parameter int TAIL_CONTEXTS = 8,   // bf16: elements the fp32 tail works on at once
    parameter int OUT_MAX       = 64,  // the most output credits the downstream consumer may advertise
    parameter int OUT_CRW       = 1    // out.credit width
) (
    input logic clk_i,
    input logic rstn_i,

    credit_link_if.consumer in,   // {last, word}, last on a set's final element; the lane advertises its 2**ADDR_LINES FIFO slots
    credit_link_if.producer out,  // one result per put; a group starts only with K output credits

    input logic [CONTROL_WIDTH-1:0] control_word_i,
    input sienna_fmt_pkg::lane_params_t par_i,  // int8: the input rescale and SELU's output requantize; floats: a 1-bit dummy

    // The coefficient memory's load path: a 32-bit word per cycle at gpnae_pkg's word address, taken only while idle_o.
    input logic                   coef_wr_i,
    input logic [LOAD_ADDR_W-1:0] coef_addr_i,
    input logic [           31:0] coef_data_i,
    output logic                  idle_o  // no element in the lane: a coefficient write now is taken, one while it is low is refused
);
  localparam int DATA_WIDTH = sienna_fmt_pkg::DATA_WIDTH;
  localparam int SW = $clog2(K);
  // Pop issued at cycle c -> rd_en at c+1 -> status clear visible c+2 -> data_o(t+2)=mem[rd_ptr(t)], so the word appears at c+3.
  localparam int CAP_LAG = 3;
  localparam int ACT_IN_LAT = sienna_fmt_pkg::LANE_MUL_LATENCY + 1;  // gpnae_act_in, valid_i to valid_o
  localparam int AL = sienna_fmt_pkg::LANE_ADD_LATENCY;  // gpnae_post's add path, before the second pass reads it
  localparam bit TAIL = sienna_fmt_pkg::HAS_FLOAT_TAIL;
  localparam int FN_SELU = 0, FN_SIG = 1, FN_TANH = 2;

  if (ACT_IN_LAT < 2) begin : G_BAD_ACT_IN
    $fatal(1, "gpnae: gpnae_act_in's latency %0d is below 2", ACT_IN_LAT);
  end

  logic [DATA_WIDTH-1:0] fifo_data_o;
  logic                  fifo_rd_en;
  logic [ADDR_LINES:0]   fifo_count;

  // A circular FIFO: credits let the producer write while the lane pops.
  lane_fifo #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES)
  ) input_fifo_inst (
      .clk_i  (clk_i),
      .rstn_i (rstn_i),
      .wr_en_i(in.put),
      .rd_en_i(fifo_rd_en),
      .count_o(fifo_count),
      .data_i (in.data[DATA_WIDTH-1:0]),
      .data_o (fifo_data_o)
  );

  logic fifo_pop, last_pend, grp_go, out_ok, res_put;
  logic [DATA_WIDTH-1:0] res_data;
  logic [$clog2(OUT_MAX + 1)-1:0] out_cnt;  // output credits held, from lane_link
  assign fifo_pop = fifo_rd_en && (fifo_count != '0);
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_link;
  assign unused_link = last_pend ^ out_ok ^ ^out_cnt;  // lane_link's own state: grp_go already holds it
  /* verilator lint_on UNUSEDSIGNAL */

  typedef enum logic [3:0] {
    G_IDLE,
    G_CAP,
    G_LDRAIN,
    G_RUN,
    G_RECV,
    G_POST,
    G_XWAIT,
    G_POST2,
    G_EMIT,
    G_NEXT
  } gstate_t;
  gstate_t gstate;

  // The credit front end: input credits, the last bit, the K-credit group gate, output credits and the link checks.
  lane_link #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES),
      .K         (K),
      .OUT_MAX   (OUT_MAX),
      .OUT_CRW   (OUT_CRW)
  ) link (
      .clk_i       (clk_i),
      .rstn_i      (rstn_i),
      .in          (in),
      .out         (out),
      .fifo_pop_i  (fifo_pop),
      .fifo_count_i(fifo_count),
      .idle_i      (gstate == G_IDLE),
      .next_i      (gstate == G_NEXT),
      .res_put_i   (res_put),
      .res_data_i  (res_data),
      .cap_i       (gstate == G_CAP && cap_v[CAP_LAG-1]),
      .cap_data_i  (fifo_data_o),
      .grp_go_o    (grp_go),
      .out_ok_o    (out_ok),
      .last_pend_o (last_pend),
      .out_cnt_o   (out_cnt)
  );

  // The group's function, taken as it starts.
  logic [1:0] fn_q;
  logic       byp_q, relu_q;
  logic [1:0] fn_c;
  logic       byp_c, relu_c;
  assign relu_c = (control_word_i == CONTROL_WIDTH'(3'b100));
  assign byp_c  = relu_c || (control_word_i == CONTROL_WIDTH'(3'b101));
  assign fn_c   = (control_word_i == CONTROL_WIDTH'(3'b001)) ? 2'(FN_SELU) : (control_word_i == CONTROL_WIDTH'(3'b010)) ? 2'(FN_SIG) : 2'(FN_TANH);

  // ── the coefficient memory ──
  desc_t            desc[NUM_DESC];
  tail_t            tset;
  logic [COEF_ADDR_W-1:0] coef_raddr;
  logic [ACT_W-1:0] coef_rdata;
  logic             lane_idle, coef_we;  // a write lands only while the lane holds no element (set below)
  gpnae_coef_mem COEF (.clk_i(clk_i), .rstn_i(rstn_i), .wr_i(coef_we), .waddr_i(coef_addr_i), .wdata_i(coef_data_i), .raddr_i(coef_raddr),
                       .rdata_o(coef_rdata), .desc_o(desc), .tail_o(tset));

  // ── per-element state ──
  logic [DATA_WIDTH-1:0] in_buf[K];  // the captured words
  kind_t                 kind_buf[K];
  logic [K-1:0]          neg_buf, under_buf;
  logic [7:0]            n_buf[K];
  logic [23:0]           aux_buf[K];
  logic [ACT_W-1:0]      pol_buf[K];  // P from the MAC
  logic [DATA_WIDTH-1:0] res_buf[K];
  logic [K-1:0]          res_rdy;
  logic                  has_exp;  // the group has a K_EXP element: a second post pass

  logic [SW:0] n_elems, ld_idx, rx_idx, iss_idx, emit_idx;
  logic [SW:0] pop_idx, grp_n;
  logic [CAP_LAG-1:0] cap_v;
  logic [3:0]  drain_cnt;
  logic        cap_now;
  assign cap_now = (gstate == G_CAP) && cap_v[CAP_LAG-1];

  // ── input stage: every non-bypass element as it is captured ──
  logic                   ai_v;
  logic [SW-1:0]          ai_idx;
  logic [ACT_W-1:0]       ai_op;
  logic [COEF_ADDR_W-1:0] ai_base;
  logic [3:0]             ai_deg;
  logic [1:0]             ai_frac;
  kind_t                  ai_kind;
  logic                   ai_neg, ai_under;
  logic [7:0]             ai_n;
  logic [23:0]            ai_aux;
  gpnae_act_in #(.IW(SW)) ACTIN (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(cap_now && !byp_q), .idx_i(ld_idx[SW-1:0]), .word_i(fifo_data_o),
                                 .fn_i(fn_q), .desc_i(desc), .par_i(par_i), .valid_o(ai_v), .idx_o(ai_idx), .op_o(ai_op), .base_o(ai_base),
                                 .deg_o(ai_deg), .frac_o(ai_frac), .kind_o(ai_kind), .neg_o(ai_neg), .n_o(ai_n), .under_o(ai_under),
                                 .aux_o(ai_aux));

  // ── the barrel MAC, loaded straight from the input stage ──
  logic             mac_start, mac_res_valid, mac_done;
  logic [ACT_W-1:0] mac_res;
  /* verilator lint_off PINCONNECTEMPTY */
  barrel_mac #(.K(K), .COEF_ADDR_W(COEF_ADDR_W)) barrel_mac_inst (
      .clk_i       (clk_i),
      .rstn_i      (rstn_i),
      .ld_valid_i  (ai_v),
      .ld_data_i   (ai_op),
      .ld_base_i   (ai_base),
      .ld_deg_i    (ai_deg),
      .ld_frac_i   (ai_frac),
      .start_i     (mac_start),
      .coeff_addr_o(coef_raddr),
      .coeff_data_i(coef_rdata),
      .res_valid_o (mac_res_valid),
      .res_data_o  (mac_res),
      .busy_o      (),
      .done_o      (mac_done)
  );
  /* verilator lint_on PINCONNECTEMPTY */

  // ── post stage ──
  logic                  post_issue, post_pass2;
  logic                  pa_v, pb_v, pc_v;
  logic [SW-1:0]         pa_idx, pb_idx, pc_idx;
  logic [DATA_WIDTH-1:0] pa_data, pb_data, pc_data, byp_y;
  logic [SW-1:0]         pi;
  assign pi         = iss_idx[SW-1:0];
  assign post_issue = (gstate == G_POST);
  assign post_pass2 = (gstate == G_POST2) && (kind_buf[pi] == K_EXP);
  gpnae_post #(.IW(SW), .K(K)) POSTS (.clk_i(clk_i), .rstn_i(rstn_i), .issue_i(post_issue), .pass2_i(post_pass2), .idx_i(pi),
                                      .kind_i(kind_buf[pi]), .neg_i(neg_buf[pi]), .fn_i(fn_q), .x_i(in_buf[pi]), .aux_i(aux_buf[pi]),
                                      .p_i(pol_buf[pi]), .n_i(n_buf[pi]), .under_i(under_buf[pi]), .par_i(par_i), .byp_x_i(fifo_data_o),
                                      .byp_relu_i(relu_q), .byp_y_o(byp_y), .a_v_o(pa_v), .a_idx_o(pa_idx), .a_data_o(pa_data),
                                      .b_v_o(pb_v), .b_idx_o(pb_idx), .b_data_o(pb_data), .c_v_o(pc_v), .c_idx_o(pc_idx), .c_data_o(pc_data));

  // ── bf16's fp32 tail for negative sigmoid past its Q set; its elements run beside the group, results parked until emit ──
  logic [K-1:0]          tail_buf, tail_pend, trdy;
  logic [DATA_WIDTH-1:0] tres_buf[K];
  logic                  tail_start, tail_done, tail_ready, tail_busy;
  logic [SW-1:0]         tail_idx, tail_next;
  logic [DATA_WIDTH-1:0] tail_res;
  always_comb begin
    tail_next = '0;
    for (int ts = K - 1; ts >= 0; ts--) if (tail_pend[ts]) tail_next = SW'(ts);  // not i: bf16Adder's function loop would hide it (VARHIDDEN)
  end
  assign tail_start = tail_ready && (|tail_pend);

  if (TAIL) begin : G_TAIL
    if (DATA_WIDTH != 16) begin : G_BAD_W
      $fatal(1, "gpnae: the fp32 tail narrows to bf16, not %0d bits", DATA_WIDTH);
    end
    logic [31:0] tail_res32;
    gpnae_tail #(.CONTEXTS(TAIL_CONTEXTS), .IW(SW)) TAILU (
        .clk_i   (clk_i),
        .rstn_i  (rstn_i),
        .start_i (tail_start),
        .x_i     ({1'b0, in_buf[tail_next][DATA_WIDTH-2:0], {(32 - DATA_WIDTH) {1'b0}}}),  // |x| widened exactly
        .idx_i   (tail_next),
        .set_i   (tset),
        .ready_o (tail_ready),
        .result_o(tail_res32),
        .idx_o   (tail_idx),
        .done_o  (tail_done),
        .busy_o  (tail_busy)
    );
    fp32ToBf16 TNARROW (.fp32_i(tail_res32), .bf16_o(tail_res));  // to nearest even
`ifndef SYNTHESIS
    // A tail result returns to an element of this group that is waiting for it, and was computed from that element's x.
    a_tail_pair: assert property (@(posedge clk_i) disable iff (!rstn_i)
        tail_done |-> (tail_buf[tail_idx] && !tail_pend[tail_idx] && !trdy[tail_idx]
                       && TAILU.x_out == {1'b0, in_buf[tail_idx][DATA_WIDTH-2:0], {(32 - DATA_WIDTH) {1'b0}}}))
      else $error("gpnae: a_tail_pair: tail result for element %0d (x %h) came from x %h, or it is not waiting for one", tail_idx,
                  in_buf[tail_idx], TAILU.x_out);
`endif
  end else begin : G_NO_TAIL
    assign tail_ready = 1'b0;
    assign tail_done  = 1'b0;
    assign tail_busy  = 1'b0;
    assign tail_idx   = '0;
    assign tail_res   = '0;
    /* verilator lint_off UNUSEDSIGNAL */
    tail_t unused_tset;
    assign unused_tset = tset;
    /* verilator lint_on UNUSEDSIGNAL */
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      gstate     <= G_IDLE;
      n_elems    <= '0;
      ld_idx     <= '0;
      rx_idx     <= '0;
      iss_idx    <= '0;
      emit_idx   <= '0;
      pop_idx    <= '0;
      grp_n      <= '0;
      cap_v      <= '0;
      drain_cnt  <= '0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      res_put    <= 1'b0;
      res_data   <= '0;
      res_rdy    <= '0;
      tail_buf   <= '0;
      tail_pend  <= '0;
      trdy       <= '0;
      has_exp    <= 1'b0;
      fn_q       <= '0;
      byp_q      <= 1'b0;
      relu_q     <= 1'b0;
    end else begin
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      res_put    <= 1'b0;

      // Post results land in res_buf out of order; emit takes them in order.
      if (pa_v) res_rdy[pa_idx] <= 1'b1;
      if (pb_v) res_rdy[pb_idx] <= 1'b1;
      if (pc_v) res_rdy[pc_idx] <= 1'b1;

      // Classified elements: tail elements wait for a context; an exp element asks for the second pass.
      if (ai_v) begin
        if (ai_kind == K_TAIL) begin
          tail_buf[ai_idx]  <= 1'b1;
          tail_pend[ai_idx] <= 1'b1;
        end
        if (ai_kind == K_EXP) has_exp <= 1'b1;
      end
      if (tail_start) tail_pend[tail_next] <= 1'b0;
      if (tail_done) trdy[tail_idx] <= 1'b1;

      case (gstate)
        G_IDLE: begin
          ld_idx  <= '0;
          pop_idx <= '0;
          if (grp_go) begin
            // The FIFO reports its own occupancy, so the whole group is popped back to back.
            grp_n  <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
            fn_q   <= fn_c;
            byp_q  <= byp_c;
            relu_q <= relu_c;
            gstate <= G_CAP;
          end
        end

        // One pop per cycle; captures trail by CAP_LAG; each non-bypass capture enters the input stage.
        G_CAP: begin
          if (pop_idx < grp_n) begin
            fifo_rd_en <= 1'b1;
            pop_idx    <= pop_idx + 1;
          end
          cap_v <= {cap_v[CAP_LAG-2:0], (pop_idx < grp_n)};
          if (cap_v[CAP_LAG-1]) begin
            tail_buf[ld_idx[SW-1:0]]  <= 1'b0;
            tail_pend[ld_idx[SW-1:0]] <= 1'b0;
            trdy[ld_idx[SW-1:0]]      <= 1'b0;
            ld_idx                    <= ld_idx + 1;
            if (ld_idx == '0) has_exp <= 1'b0;
            if (byp_q) res_rdy[ld_idx[SW-1:0]] <= 1'b1;  // ReLU and linear are ready at capture
            if (ld_idx + 1 == grp_n) begin
              n_elems   <= grp_n;
              iss_idx   <= '0;
              drain_cnt <= '0;
              emit_idx  <= '0;
              gstate    <= byp_q ? G_EMIT : G_LDRAIN;
            end
          end
        end

        // The last element reaches the MAC ACT_IN_LAT cycles after its capture; the start rides with that load.
        G_LDRAIN: begin
          if (drain_cnt == 4'(ACT_IN_LAT - 2)) begin
            mac_start <= 1'b1;
            rx_idx    <= '0;
            gstate    <= G_RUN;
          end else begin
            drain_cnt <= drain_cnt + 1;
          end
        end

        G_RUN: begin
          if (mac_res_valid) begin
            rx_idx <= rx_idx + 1;
            gstate <= G_RECV;
          end
          // A one-element group: barrel_mac's only result and its done_o arrive together.
          if (mac_done) begin
            iss_idx  <= '0;
            emit_idx <= '0;
            res_rdy  <= '0;
            gstate   <= G_POST;
          end
        end

        G_RECV: begin
          if (mac_res_valid) rx_idx <= rx_idx + 1;
          if (mac_done) begin
            iss_idx  <= '0;
            emit_idx <= '0;
            res_rdy  <= '0;
            gstate   <= G_POST;
          end
        end

        // One post issue per cycle; results land in res_buf out of order.
        G_POST: begin
          if (iss_idx + 1 == n_elems) begin
            iss_idx   <= '0;
            drain_cnt <= '0;
            gstate    <= has_exp ? G_XWAIT : G_EMIT;
          end else iss_idx <= iss_idx + 1;
        end

        // fp32: the first pass's 1 - E is back before the second pass reads it.
        G_XWAIT: begin
          if (drain_cnt == 4'(AL + 1)) gstate <= G_POST2;
          else drain_cnt <= drain_cnt + 1;
        end

        G_POST2: begin
          if (iss_idx + 1 == n_elems) gstate <= G_EMIT;
          else iss_idx <= iss_idx + 1;
        end

        // Retire in index order, one put per element in sequence.
        G_EMIT: begin
          if (tail_buf[emit_idx[SW-1:0]]) begin
            if (trdy[emit_idx[SW-1:0]]) begin
              res_data <= tres_buf[emit_idx[SW-1:0]];
              res_put  <= 1'b1;
              if (emit_idx + 1 == n_elems) gstate <= G_NEXT;
              else emit_idx <= emit_idx + 1;
            end
          end else if (res_rdy[emit_idx[SW-1:0]]) begin
            res_data <= res_buf[emit_idx[SW-1:0]];
            res_put  <= 1'b1;
            if (emit_idx + 1 == n_elems) gstate <= G_NEXT;
            else emit_idx <= emit_idx + 1;
          end
        end

        // Waits here while queued words lack K output credits.
        G_NEXT: begin
          ld_idx  <= '0;
          pop_idx <= '0;
          cap_v   <= '0;
          grp_n   <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
          if (fifo_count == '0) gstate <= G_IDLE;
          else if (grp_go) begin
            fn_q   <= fn_c;
            byp_q  <= byp_c;
            relu_q <= relu_c;
            gstate <= G_CAP;
          end
        end

        default: gstate <= G_IDLE;
      endcase
    end
  end

  // Data: buffers loaded beside the control above and never reset (D-8).
  always_ff @(posedge clk_i) begin
    if (cap_now) begin
      in_buf[ld_idx[SW-1:0]] <= fifo_data_o;
      if (byp_q) res_buf[ld_idx[SW-1:0]] <= byp_y;
    end
    if (ai_v) begin
      kind_buf[ai_idx]  <= ai_kind;
      neg_buf[ai_idx]   <= ai_neg;
      under_buf[ai_idx] <= ai_under;
      n_buf[ai_idx]     <= ai_n;
      aux_buf[ai_idx]   <= ai_aux;
    end
    if ((gstate == G_RUN || gstate == G_RECV) && mac_res_valid) pol_buf[rx_idx[SW-1:0]] <= mac_res;
    if (pa_v) res_buf[pa_idx] <= pa_data;
    if (pb_v) res_buf[pb_idx] <= pb_data;
    if (pc_v) res_buf[pc_idx] <= pc_data;
    if (tail_done) tres_buf[tail_idx] <= tail_res;
  end

  // The load interlock: a group in flight reads the memory every cycle, so a write lands only while the lane holds no element.
  assign lane_idle = (gstate == G_IDLE) && (fifo_count == '0) && !tail_busy;
  assign coef_we   = coef_wr_i && lane_idle;
  assign idle_o    = lane_idle;

`ifndef SYNTHESIS
  // No write reaches the memory while the lane holds an element. Both terms are registered.
  logic we_seen, idle_seen;
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) begin
      we_seen   <= 1'b0;
      idle_seen <= 1'b1;
    end else begin
      we_seen   <= coef_we;
      idle_seen <= lane_idle;
    end
  a_load_idle: assert property (@(posedge clk_i) disable iff (!rstn_i) we_seen |-> idle_seen)
    else $error("gpnae: a_load_idle: a coefficient memory write landed while the lane is busy");
`endif
endmodule
