`timescale 1ns / 100ps

// bf16's negative sigmoid past its Q set, in fp32: E = e^-t = 2^-n P(f), k = t log2 e split into n and f, P(f) ~ 2^-f by Horner on the
// tier's fp32 set; then sigmoid(-t) = E y, y -> 1/(1 + E) from 1.5 - (1 + E)/2 by NEWTON steps y (2 - (1 + E) y). The result is fp32;
// the lane narrows it to nearest. CONTEXTS elements run at once, each with its own registers, sharing one fp32Multiplier and one
// fp32Adder; every element sees the same operations on the same operands whatever its timing.
module gpnae_tail
  import gpnae_pkg::*;
#(
    parameter int CONTEXTS = 8,
    parameter int IW       = 4  // width of the caller's element tag
) (
    input logic clk_i,
    input logic rstn_i,

    input  logic          start_i,  // taken on a cycle ready_o is high
    input  logic [31:0]   x_i,  // t = |x| as an fp32 word
    input  logic [IW-1:0] idx_i,  // returned with the result
    input  tail_t         set_i,  // the tier's set, held while busy_o
    output logic          ready_o,  // a context is free

    output logic [  31:0] result_o,
    output logic [IW-1:0] idx_o,
    output logic          done_o,
    output logic          busy_o
);
  localparam int C = CONTEXTS;
  localparam int CW = (C > 1) ? $clog2(C) : 1;
  localparam logic [31:0] ONE = 32'h3F800000, TWO = 32'h40000000, Y0 = 32'h3FC00000, LOG2E = 32'h3FB8AA3B, S = 32'h80000000;

  typedef enum logic [3:0] {
    T_IDLE,
    T_K,     // k = t log2 e
    T_HMUL,  // tmp = f acc
    T_HADD,  // acc = c_j + tmp
    T_ND,    // D = 1 + E
    T_NY0,   // y = 1.5 - D/2
    T_NDY,   // tmp = D y
    T_NT,    // tmp = 2 - tmp
    T_NYT,   // y = y tmp
    T_NS,    // s = E y
    T_DONE
  } tstate_t;

  tstate_t st[C];
  logic [31:0] x[C], f[C], acc[C], e[C], d[C], y[C], tmp[C], res[C];
  logic [7:0] n[C];
  logic [2:0] j[C];  // the Horner coefficient index
  logic [1:0] k[C];  // Newton steps left
  logic issued[C];  // this context has an operation in a shared unit
  logic [IW-1:0] id[C];

  // E = P 2^-n by an exponent subtract: 0 where that leaves the normal range.
  /* verilator lint_off UNUSEDSIGNAL */
  function automatic logic [31:0] scale(input logic [31:0] p, input logic [7:0] nn);  // P > 0: its sign is not read
    logic signed [9:0] ep;
    ep = 10'(p[30:23]) - 10'(nn);
    return (ep <= 10'sd0) ? 32'd0 : {1'b0, ep[7:0], p[22:0]};
  endfunction
  /* verilator lint_on UNUSEDSIGNAL */

  // What each context wants from the shared units this cycle.
  logic mreq[C], areq[C];
  logic [31:0] ma[C], mb[C], aa[C], ab[C];
  always_comb begin
    for (int c = 0; c < C; c++) begin
      mreq[c] = 1'b0;
      areq[c] = 1'b0;
      ma[c] = '0;
      mb[c] = '0;
      aa[c] = '0;
      ab[c] = '0;
      if (!issued[c]) begin
        case (st[c])
          T_K:    begin mreq[c] = 1'b1; ma[c] = x[c]; mb[c] = LOG2E; end
          T_HMUL: begin mreq[c] = 1'b1; ma[c] = f[c]; mb[c] = acc[c]; end
          T_HADD: begin areq[c] = 1'b1; aa[c] = set_i.coef[j[c]]; ab[c] = tmp[c]; end
          T_ND:   begin areq[c] = 1'b1; aa[c] = ONE; ab[c] = e[c]; end
          T_NY0:  begin areq[c] = 1'b1; aa[c] = Y0; ab[c] = {1'b1, d[c][30:23] - 8'd1, d[c][22:0]}; end  // -D/2, D >= 1
          T_NDY:  begin mreq[c] = 1'b1; ma[c] = d[c]; mb[c] = y[c]; end
          T_NT:   begin areq[c] = 1'b1; aa[c] = TWO; ab[c] = tmp[c] ^ S; end
          T_NYT:  begin mreq[c] = 1'b1; ma[c] = y[c]; mb[c] = tmp[c]; end
          T_NS:   begin mreq[c] = 1'b1; ma[c] = e[c]; mb[c] = y[c]; end
          default: ;
        endcase
      end
    end
  end

  // The lowest requesting context wins each unit; a context asks again only after its result is back, so none starves.
  logic mgnt_v, agnt_v, free_v, out_v;
  logic [CW-1:0] mgnt, agnt, free_c, out_c;
  always_comb begin
    mgnt_v = 1'b0; mgnt = '0;
    agnt_v = 1'b0; agnt = '0;
    free_v = 1'b0; free_c = '0;
    out_v  = 1'b0; out_c = '0;
    for (int c = C - 1; c >= 0; c--) begin
      if (mreq[c]) begin mgnt_v = 1'b1; mgnt = CW'(c); end
      if (areq[c]) begin agnt_v = 1'b1; agnt = CW'(c); end
      if (st[c] == T_IDLE) begin free_v = 1'b1; free_c = CW'(c); end
      if (st[c] == T_DONE) begin out_v = 1'b1; out_c = CW'(c); end
    end
  end
  assign ready_o = free_v;

  logic [31:0] mul_a, mul_b, mul_res, add_a, add_b, add_res;
  logic mul_valid, mul_done, add_valid, add_done;
  /* verilator lint_off PINCONNECTEMPTY */
  fp32Multiplier TMUL (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(mul_valid), .A(mul_a), .B(mul_b), .result_o(mul_res), .done_o(mul_done),
                       .overflow_o(), .underflow_o(), .invalid_o());
  fp32Adder TADD (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(add_valid), .A(add_a), .B(add_b), .result_o(add_res), .done_o(add_done),
                  .overflow_o(), .underflow_o(), .invalid_o());
  /* verilator lint_on PINCONNECTEMPTY */

  // k's split, on the multiplier's result.
  logic [ 7:0] sp_n;
  logic [31:0] sp_f;
  logic        sp_under;
  gpnae_exp_split SPLIT (.k_i(mul_res), .n_o(sp_n), .f_o(sp_f), .under_o(sp_under));

  // In-order units: a FIFO of issuing contexts pairs each result with its owner, whatever the latency.
  logic [CW-1:0] mq[C], aq[C];
  logic [CW:0] mq_wr, mq_rd, aq_wr, aq_rd;
  logic [CW-1:0] m_owner, a_owner;
  assign m_owner = mq[mq_rd[CW-1:0]];
  assign a_owner = aq[aq_rd[CW-1:0]];

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      mul_valid <= 1'b0;
      add_valid <= 1'b0;
      mul_a <= '0; mul_b <= '0; add_a <= '0; add_b <= '0;
      mq_wr <= '0; mq_rd <= '0; aq_wr <= '0; aq_rd <= '0;
      for (int c = 0; c < C; c++) begin
        mq[c] <= '0;
        aq[c] <= '0;
      end
    end else begin
      mul_valid <= mgnt_v;
      add_valid <= agnt_v;
      if (mgnt_v) begin
        mul_a <= ma[mgnt];
        mul_b <= mb[mgnt];
        mq[mq_wr[CW-1:0]] <= mgnt;
        mq_wr <= (mq_wr == (CW+1)'(C - 1)) ? '0 : mq_wr + 1'b1;
      end
      if (agnt_v) begin
        add_a <= aa[agnt];
        add_b <= ab[agnt];
        aq[aq_wr[CW-1:0]] <= agnt;
        aq_wr <= (aq_wr == (CW+1)'(C - 1)) ? '0 : aq_wr + 1'b1;
      end
      if (mul_done) mq_rd <= (mq_rd == (CW+1)'(C - 1)) ? '0 : mq_rd + 1'b1;
      if (add_done) aq_rd <= (aq_rd == (CW+1)'(C - 1)) ? '0 : aq_rd + 1'b1;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      done_o   <= 1'b0;
      result_o <= '0;
      idx_o    <= '0;
      for (int c = 0; c < C; c++) begin
        st[c] <= T_IDLE;
        issued[c] <= 1'b0;
        {x[c], f[c], acc[c], e[c], d[c], y[c], tmp[c], res[c]} <= '0;
        n[c]  <= '0;
        j[c]  <= '0;
        k[c]  <= '0;
        id[c] <= '0;
      end
    end else begin
      done_o <= 1'b0;
      if (out_v) begin
        done_o   <= 1'b1;
        result_o <= res[out_c];
        idx_o    <= id[out_c];
      end
      for (int c = 0; c < C; c++) begin
        automatic logic mres = mul_done && (m_owner == CW'(c));
        automatic logic ares = add_done && (a_owner == CW'(c));
        if ((mgnt_v && mgnt == CW'(c)) || (agnt_v && agnt == CW'(c))) issued[c] <= 1'b1;
        case (st[c])
          T_IDLE:
            if (start_i && free_v && free_c == CW'(c)) begin
              x[c]      <= x_i;
              id[c]     <= idx_i;
              issued[c] <= 1'b0;
              st[c]     <= T_K;
            end

          T_K: if (mres) begin
            issued[c] <= 1'b0;
            n[c]      <= sp_n;
            f[c]      <= sp_f;
            acc[c]    <= '0;
            j[c]      <= set_i.deg;
            e[c]      <= '0;
            st[c]     <= sp_under ? T_ND : T_HMUL;  // E below every normal value: 0
          end

          T_HMUL: if (mres) begin
            tmp[c] <= mul_res; issued[c] <= 1'b0; st[c] <= T_HADD;
          end

          T_HADD: if (ares) begin
            issued[c] <= 1'b0;
            if (j[c] == 3'd0) begin
              e[c]  <= scale(add_res, n[c]);
              st[c] <= T_ND;
            end else begin
              acc[c] <= add_res;
              j[c]   <= j[c] - 3'd1;
              st[c]  <= T_HMUL;
            end
          end

          T_ND: if (ares) begin
            d[c] <= add_res; issued[c] <= 1'b0; st[c] <= T_NY0;
          end

          T_NY0: if (ares) begin
            y[c]      <= add_res;
            k[c]      <= set_i.newton;
            issued[c] <= 1'b0;
            st[c]     <= (set_i.newton == 2'd0) ? T_NS : T_NDY;
          end

          T_NDY: if (mres) begin
            tmp[c] <= mul_res; issued[c] <= 1'b0; st[c] <= T_NT;
          end

          T_NT: if (ares) begin
            tmp[c] <= add_res; issued[c] <= 1'b0; st[c] <= T_NYT;
          end

          T_NYT: if (mres) begin
            y[c]      <= mul_res;
            issued[c] <= 1'b0;
            k[c]      <= k[c] - 2'd1;
            st[c]     <= (k[c] == 2'd1) ? T_NS : T_NDY;
          end

          T_NS: if (mres) begin
            res[c] <= mul_res; issued[c] <= 1'b0; st[c] <= T_DONE;
          end

          // One result leaves per cycle, lowest context first.
          T_DONE: if (out_v && out_c == CW'(c)) st[c] <= T_IDLE;

          default: st[c] <= T_IDLE;
        endcase
      end
    end
  end

  always_comb begin
    busy_o = 1'b0;
    for (int c = 0; c < C; c++) if (st[c] != T_IDLE) busy_o = 1'b1;
  end

`ifndef SYNTHESIS
  // x of the element whose result done_o returns, beside idx_o, for the caller's pairing check.
  /* verilator lint_off UNUSEDSIGNAL */
  logic [31:0] x_out;  // gpnae's a_tail_pair reads it
  /* verilator lint_on UNUSEDSIGNAL */
  always_ff @(posedge clk_i) if (out_v) x_out <= x[out_c];

  a_start_free: assert property (@(posedge clk_i) disable iff (!rstn_i) start_i |-> ready_o)
    else $error("gpnae_tail: a_start_free: a start with no free context");
  // A busy context keeps its element's x and tag through every state, and the set it computes with does not change under it.
  for (genvar c = 0; c < C; c++) begin : G_CTX
    a_ctx_hold: assert property (@(posedge clk_i) disable iff (!rstn_i)
        (st[c] != T_IDLE && $past(st[c]) != T_IDLE) |-> ($stable(x[c]) && $stable(id[c])))
      else $error("gpnae_tail: a_ctx_hold: context %0d changed its element while busy", c);
  end
  a_set_stable: assert property (@(posedge clk_i) disable iff (!rstn_i) (busy_o && $past(busy_o)) |-> $stable(set_i))
    else $error("gpnae_tail: a_set_stable: the tier's set changed while an element was in the tail");
`endif
endmodule
