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
    T_SC,    // E = P 2^-n, from P registered (the adder's result into the subtract and the state's enable was bf16's 1.20 ns)
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
  // What each context wants from the shared units this cycle: registered as the context enters a state, decoded from the values its
  // registers load (st -> request and operand decode, with the coefficient select, -> grant -> add_a was bf16's LANE path, 1.05-1.12 ns).
  logic mreq[C], areq[C];
  logic [31:0] ma[C], mb[C], aa[C], ab[C];
  logic mreq_r[C], areq_r[C];  // the state's request, before issued
  // Each context's registers as they load this edge.
  tstate_t st_n[C];
  logic [31:0] x_n[C], f_n[C], acc_n[C], e_n[C], d_n[C], y_n[C], tmp_n[C], res_n[C];
  logic [7:0] n_n[C];
  logic [2:0] j_n[C];
  logic [1:0] k_n[C];
  logic issued_n[C];
  logic [IW-1:0] id_n[C];
  // The grants: the lowest requesting context wins each unit; the free and the finished context.
  logic mgnt_v, agnt_v, free_v, out_v;
  logic [CW-1:0] mgnt, agnt, free_c, out_c;
  logic [C-1:0] mgoh, agoh;  // the same grants one-hot, so each unit's operands are an AND-OR beside the grant, not a mux after it
  logic [31:0] mul_a_n, mul_b_n, add_a_n, add_b_n;  // the granted context's operands (st -> encoded grant -> mux into add_a was bf16's 1.17 ns)
  // The shared units' operands and results.
  logic [31:0] mul_a, mul_b, mul_res, add_a, add_b, add_res;
  logic mul_valid, mul_done, add_valid, add_done;
  logic [31:0] mul_res_q, mul_res_qq;  // the multiplier's result registered twice more: the contexts read the second, with the split's outputs
  logic mul_done_q, mul_done_qq;
  // k's split, on the multiplier's result: two register stages inside, so it lands with mul_res_qq.
  logic [ 7:0] sp_n;
  logic [31:0] sp_f;
  logic        sp_under;
  // In-order units: a FIFO of issuing contexts pairs each result with its owner, whatever the latency.
  logic [CW-1:0] mq[C], aq[C];
  logic [CW:0] mq_wr, mq_rd, aq_wr, aq_rd;
  logic [CW-1:0] m_owner, a_owner;

  // E = P 2^-n by an exponent subtract: 0 where that leaves the normal range.
  /* verilator lint_off UNUSEDSIGNAL */
  function automatic logic [31:0] scale(input logic [31:0] p, input logic [7:0] nn);  // P > 0: its sign is not read
    logic signed [9:0] ep;
    ep = 10'(p[30:23]) - 10'(nn);
    return (ep <= 10'sd0) ? 32'd0 : {1'b0, ep[7:0], p[22:0]};
  endfunction
  /* verilator lint_on UNUSEDSIGNAL */

  // A state's request and operands from the context's registers: {mreq, areq, ma, mb, aa, ab}.
  function automatic logic [129:0] request(input tstate_t st_v, input logic [31:0] x_v, f_v, acc_v, e_v, d_v, y_v, tmp_v, input logic [2:0] j_v);
    logic mr, ar;
    logic [31:0] mav, mbv, aav, abv;
    {mr, ar, mav, mbv, aav, abv} = '0;
    case (st_v)
      T_K:    begin mr = 1'b1; mav = x_v; mbv = LOG2E; end
      T_HMUL: begin mr = 1'b1; mav = f_v; mbv = acc_v; end
      T_HADD: begin ar = 1'b1; aav = set_i.coef[j_v]; abv = tmp_v; end  // set_i is held while busy_o (a_set_stable)
      T_ND:   begin ar = 1'b1; aav = ONE; abv = e_v; end
      T_NY0:  begin ar = 1'b1; aav = Y0; abv = {1'b1, d_v[30:23] - 8'd1, d_v[22:0]}; end  // -D/2, D >= 1
      T_NDY:  begin mr = 1'b1; mav = d_v; mbv = y_v; end
      T_NT:   begin ar = 1'b1; aav = TWO; abv = tmp_v ^ S; end
      T_NYT:  begin mr = 1'b1; mav = y_v; mbv = tmp_v; end
      T_NS:   begin mr = 1'b1; mav = e_v; mbv = y_v; end
      default: ;
    endcase
    return {mr, ar, mav, mbv, aav, abv};
  endfunction

  // What each context wants this cycle: its state's registered request, until issued.
  always_comb
    for (int c = 0; c < C; c++) begin
      mreq[c] = mreq_r[c] && !issued[c];
      areq[c] = areq_r[c] && !issued[c];
    end

  // The lowest requesting context wins each unit; a context asks again only after its result is back, so none starves.
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

  // The same lowest-requesting grants, one-hot, and the granted context's operands.
  always_comb begin
    automatic logic mtaken = 1'b0, ataken = 1'b0;
    mul_a_n = '0; mul_b_n = '0; add_a_n = '0; add_b_n = '0;
    for (int c = 0; c < C; c++) begin
      mgoh[c] = mreq[c] && !mtaken;
      agoh[c] = areq[c] && !ataken;
      mtaken  = mtaken || mreq[c];
      ataken  = ataken || areq[c];
      mul_a_n |= {32{mgoh[c]}} & ma[c];
      mul_b_n |= {32{mgoh[c]}} & mb[c];
      add_a_n |= {32{agoh[c]}} & aa[c];
      add_b_n |= {32{agoh[c]}} & ab[c];
    end
  end

  /* verilator lint_off PINCONNECTEMPTY */
  fp32Multiplier TMUL (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(mul_valid), .A(mul_a), .B(mul_b), .result_o(mul_res), .done_o(mul_done),
                       .overflow_o(), .underflow_o(), .invalid_o());
  fp32Adder TADD (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(add_valid), .A(add_a), .B(add_b), .result_o(add_res), .done_o(add_done),
                  .overflow_o(), .underflow_o(), .invalid_o());
  /* verilator lint_on PINCONNECTEMPTY */
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) {mul_done_q, mul_done_qq} <= '0;
    else {mul_done_q, mul_done_qq} <= {mul_done, mul_done_q};
  always_ff @(posedge clk_i)
    if (mul_done) mul_res_q <= mul_res;
  always_ff @(posedge clk_i)
    if (mul_done_q) mul_res_qq <= mul_res_q;

  // k's split, on the multiplier's result.
  gpnae_exp_split SPLIT (.clk_i(clk_i), .k_i(mul_res), .n_o(sp_n), .f_o(sp_f), .under_o(sp_under));

  // The in-order FIFOs' heads: the owner of each unit's next result.
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
        mul_a <= mul_a_n;
        mul_b <= mul_b_n;
        mq[mq_wr[CW-1:0]] <= mgnt;
        mq_wr <= (mq_wr == (CW+1)'(C - 1)) ? '0 : mq_wr + 1'b1;
      end
      if (agnt_v) begin
        add_a <= add_a_n;
        add_b <= add_b_n;
        aq[aq_wr[CW-1:0]] <= agnt;
        aq_wr <= (aq_wr == (CW+1)'(C - 1)) ? '0 : aq_wr + 1'b1;
      end
      if (mul_done_qq) mq_rd <= (mq_rd == (CW+1)'(C - 1)) ? '0 : mq_rd + 1'b1;
      if (add_done) aq_rd <= (aq_rd == (CW+1)'(C - 1)) ? '0 : aq_rd + 1'b1;
    end
  end

  // Each context's next registers: the states' updates, on the registers as they are now.
  always_comb
    for (int c = 0; c < C; c++) begin
      automatic logic mres = mul_done_qq && (m_owner == CW'(c));
      automatic logic ares = add_done && (a_owner == CW'(c));
      {st_n[c], x_n[c], f_n[c], acc_n[c], e_n[c], d_n[c], y_n[c], tmp_n[c], res_n[c]} = {st[c], x[c], f[c], acc[c], e[c], d[c], y[c], tmp[c], res[c]};
      {n_n[c], j_n[c], k_n[c], issued_n[c], id_n[c]} = {n[c], j[c], k[c], issued[c], id[c]};
      if ((mgnt_v && mgnt == CW'(c)) || (agnt_v && agnt == CW'(c))) issued_n[c] = 1'b1;
      case (st[c])
        T_IDLE:
          if (start_i && free_v && free_c == CW'(c)) begin
            x_n[c] = x_i;
            id_n[c] = idx_i;
            issued_n[c] = 1'b0;
            st_n[c] = T_K;
          end

        T_K: if (mres) begin
          issued_n[c] = 1'b0;
          n_n[c] = sp_n;
          f_n[c] = sp_f;
          acc_n[c] = '0;
          j_n[c] = set_i.deg;
          e_n[c] = '0;
          st_n[c] = sp_under ? T_ND : T_HMUL;  // E below every normal value: 0
        end

        T_HMUL: if (mres) begin
          tmp_n[c] = mul_res_qq; issued_n[c] = 1'b0; st_n[c] = T_HADD;
        end

        T_HADD: if (ares) begin
          issued_n[c] = 1'b0;
          if (j[c] == 3'd0) begin
            e_n[c] = add_res;  // P, scaled in T_SC
            st_n[c] = T_SC;
          end else begin
            acc_n[c] = add_res;
            j_n[c] = j[c] - 3'd1;
            st_n[c] = T_HMUL;
          end
        end

        T_SC: begin
          e_n[c] = scale(e[c], n[c]); st_n[c] = T_ND;
        end

        T_ND: if (ares) begin
          d_n[c] = add_res; issued_n[c] = 1'b0; st_n[c] = T_NY0;
        end

        T_NY0: if (ares) begin
          y_n[c] = add_res;
          k_n[c] = set_i.newton;
          issued_n[c] = 1'b0;
          st_n[c] = (set_i.newton == 2'd0) ? T_NS : T_NDY;
        end

        T_NDY: if (mres) begin
          tmp_n[c] = mul_res_qq; issued_n[c] = 1'b0; st_n[c] = T_NT;
        end

        T_NT: if (ares) begin
          tmp_n[c] = add_res; issued_n[c] = 1'b0; st_n[c] = T_NYT;
        end

        T_NYT: if (mres) begin
          y_n[c] = mul_res_qq;
          issued_n[c] = 1'b0;
          k_n[c] = k[c] - 2'd1;
          st_n[c] = (k[c] == 2'd1) ? T_NS : T_NDY;
        end

        T_NS: if (mres) begin
          res_n[c] = mul_res_qq; issued_n[c] = 1'b0; st_n[c] = T_DONE;
        end

        // One result leaves per cycle, lowest context first.
        T_DONE: if (out_v && out_c == CW'(c)) st_n[c] = T_IDLE;

        default: st_n[c] = T_IDLE;
      endcase
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
        {mreq_r[c], areq_r[c], ma[c], mb[c], aa[c], ab[c]} <= '0;  // T_IDLE's request: none
      end
    end else begin
      done_o <= 1'b0;
      if (out_v) begin
        done_o   <= 1'b1;
        result_o <= res[out_c];
        idx_o    <= id[out_c];
      end
      for (int c = 0; c < C; c++) begin
        {st[c], x[c], f[c], acc[c], e[c], d[c], y[c], tmp[c], res[c]} <= {st_n[c], x_n[c], f_n[c], acc_n[c], e_n[c], d_n[c], y_n[c], tmp_n[c], res_n[c]};
        {n[c], j[c], k[c], issued[c], id[c]} <= {n_n[c], j_n[c], k_n[c], issued_n[c], id_n[c]};
        {mreq_r[c], areq_r[c], ma[c], mb[c], aa[c], ab[c]} <= request(st_n[c], x_n[c], f_n[c], acc_n[c], e_n[c], d_n[c], y_n[c], tmp_n[c], j_n[c]);
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
