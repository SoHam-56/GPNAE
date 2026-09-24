`timescale 1ns / 100ps

// Activation tails for gpnae_poly, for inputs past the fitted polynomials' range.
// Computes e^a for a <= 0 without cancellation: halve to |z| <= 1, Taylor e^z - 1, then double back.
// SELU x < -4: lambda*alpha*(e^x - 1).  sigmoid |x| > 3.5: E(1 - E(1 - E)), E = e^-|x|.
// tanh |x| > 4: 1 - 2*E(1 - E(1 - E)), E = e^-2|x|, with the sign of x.
// CONTEXTS elements run at once, each with its own registers, sharing one multiplier and one adder.
// Every element sees the same operations on the same operands as when they ran one at a time; only the timing differs.
module gpnae_tail #(
    parameter int CONTEXTS = 4,
    parameter int IW       = 4   // width of the caller's element index
) (
    input logic clk_i,
    input logic rstn_i,

    input  logic          start_i,  // taken on a cycle ready_o is high
    input  logic [  31:0] x_i,
    input  logic [   1:0] func_i,   // 01 SELU, 10 sigmoid, 11 tanh
    input  logic [IW-1:0] idx_i,    // returned with the result
    output logic          ready_o,  // a context is free

    output logic [  31:0] result_o,
    output logic [IW-1:0] idx_o,
    output logic          done_o,
    output logic          busy_o
);

  localparam int C = CONTEXTS;
  localparam int CW = (C > 1) ? $clog2(C) : 1;

  localparam logic [31:0] ONE = 32'h3F800000;
  localparam logic [31:0] TWO = 32'h40000000;
  localparam logic [31:0] LA = 32'h3FE10966;  // lambda * alpha
  localparam logic [30:0] BIG = 31'h42D00000;  // |a| > 104: e^a is below every fp32 value

  // 1/(k+1)! for k = 0..10
  logic [31:0] cinv[11];
  assign cinv[0]  = 32'h3F800000;
  assign cinv[1]  = 32'h3F000000;
  assign cinv[2]  = 32'h3E2AAAAB;
  assign cinv[3]  = 32'h3D2AAAAB;
  assign cinv[4]  = 32'h3C088889;
  assign cinv[5]  = 32'h3AB60B61;
  assign cinv[6]  = 32'h39500D01;
  assign cinv[7]  = 32'h37D00D01;
  assign cinv[8]  = 32'h3638EF1D;
  assign cinv[9]  = 32'h3493F27E;
  assign cinv[10] = 32'h32D7322B;

  typedef enum logic [4:0] {
    T_IDLE,
    T_TAY_MUL,   // acc * z
    T_TAY_ADD,   // + 1/(k+1)!
    T_TAY_FIN,   // d = z * acc
    T_SELU_ADD,  // t = d + 2
    T_SELU_MUL,  // d = d * t
    T_SELU_OUT,  // lambda * alpha * d
    T_E1,        // E = 1 + d
    T_SQ,        // E = E * E
    T_U,         // u = 1 - E
    T_V,         // v = E * u
    T_W,         // w = 1 - v
    T_S,         // s = E * w
    T_SIG_OUT,   // 1 - s
    T_TANH_OUT,  // 1 - 2 s
    T_DONE
  } tstate_t;

  tstate_t st[C];
  logic [31:0] x[C], z[C], acc[C], d[C], e[C], s[C], tmp[C], res[C];
  logic [1:0] fn[C];
  logic [3:0] k[C], m[C];
  logic issued[C];  // this context has an operation in a shared unit
  logic [IW-1:0] id[C];

  // Negate for subtraction.
  function automatic logic [31:0] neg(input logic [31:0] v);
    return {~v[31], v[30:0]};
  endfunction

  // What each context wants from the shared units this cycle, exactly the operands the one-context version issued.
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
          T_TAY_MUL:  begin mreq[c] = 1'b1; ma[c] = acc[c]; mb[c] = z[c]; end
          T_TAY_ADD:  begin areq[c] = 1'b1; aa[c] = tmp[c]; ab[c] = cinv[k[c]]; end
          T_TAY_FIN:  begin mreq[c] = 1'b1; ma[c] = z[c]; mb[c] = acc[c]; end
          T_SELU_ADD: begin areq[c] = 1'b1; aa[c] = d[c]; ab[c] = TWO; end
          T_SELU_MUL: begin mreq[c] = 1'b1; ma[c] = d[c]; mb[c] = tmp[c]; end
          T_SELU_OUT: begin mreq[c] = 1'b1; ma[c] = LA; mb[c] = d[c]; end
          T_E1:       begin areq[c] = 1'b1; aa[c] = ONE; ab[c] = d[c]; end
          T_SQ:       if (!(e[c][30:23] < 8'd64)) begin mreq[c] = 1'b1; ma[c] = e[c]; mb[c] = e[c]; end
          T_U:        begin areq[c] = 1'b1; aa[c] = ONE; ab[c] = neg(e[c]); end
          T_V:        begin mreq[c] = 1'b1; ma[c] = e[c]; mb[c] = tmp[c]; end
          T_W:        begin areq[c] = 1'b1; aa[c] = ONE; ab[c] = neg(tmp[c]); end
          T_S:        begin mreq[c] = 1'b1; ma[c] = e[c]; mb[c] = tmp[c]; end
          T_SIG_OUT:  begin areq[c] = 1'b1; aa[c] = ONE; ab[c] = neg(s[c]); end
          T_TANH_OUT: begin
            areq[c] = 1'b1;
            aa[c] = ONE;
            ab[c] = (s[c][30:0] == '0) ? 32'h80000000 : {1'b1, s[c][30:23] + 8'd1, s[c][22:0]};  // 2s as an exponent increment
          end
          default: ;
        endcase
      end
    end
  end

  // Lowest requesting context wins each unit; a context asks again only after its result is back, so none starves.
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

  fp32Multiplier TMUL (
      .clk_i      (clk_i),
      .rstn_i     (rstn_i),
      .valid_i    (mul_valid),
      .A          (mul_a),
      .B          (mul_b),
      .result_o   (mul_res),
      .done_o     (mul_done),
      .overflow_o (),
      .underflow_o(),
      .invalid_o  ()
  );

  fp32Adder TADD (
      .clk_i      (clk_i),
      .rstn_i     (rstn_i),
      .valid_i    (add_valid),
      .A          (add_a),
      .B          (add_b),
      .result_o   (add_res),
      .done_o     (add_done),
      .overflow_o (),
      .underflow_o(),
      .invalid_o  ()
  );

  // In-order units: a FIFO of issuing contexts pairs each result with its owner, whatever the latency.
  logic [CW-1:0] mq[C], aq[C];
  logic [CW:0] mq_wr, mq_rd, aq_wr, aq_rd;
  logic [CW-1:0] m_owner, a_owner;
  assign m_owner = mq[mq_rd[CW-1:0] % C];
  assign a_owner = aq[aq_rd[CW-1:0] % C];

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
        mq[mq_wr[CW-1:0] % C] <= mgnt;
        mq_wr <= (mq_wr == (CW+1)'(C - 1)) ? '0 : mq_wr + 1'b1;
      end
      if (agnt_v) begin
        add_a <= aa[agnt];
        add_b <= ab[agnt];
        aq[aq_wr[CW-1:0] % C] <= agnt;
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
        {x[c], z[c], acc[c], d[c], e[c], s[c], tmp[c], res[c]} <= '0;
        fn[c] <= '0;
        k[c]  <= '0;
        m[c]  <= '0;
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
          T_IDLE: begin
            if (start_i && free_v && free_c == CW'(c)) begin
              automatic logic [31:0] a;
              // a = x (SELU), -|x| (sigmoid), -2|x| (tanh)
              case (func_i)
                2'b01:   a = x_i;
                2'b10:   a = {1'b1, x_i[30:0]};
                default: a = (x_i[30:23] >= 8'd133) ? {1'b1, BIG + 31'd1} : {1'b1, x_i[30:23] + 8'd1, x_i[22:0]};
              endcase
              x[c]  <= x_i;
              fn[c] <= func_i;
              id[c] <= idx_i;
              if (a[30:0] > BIG) begin
                // e^a underflows: e^a - 1 = -1 and e^a = 0
                d[c]  <= {1'b1, ONE[30:0]};
                e[c]  <= '0;
                st[c] <= (func_i == 2'b01) ? T_SELU_OUT : T_U;
              end else begin
                if (a[30:23] < 8'd127) begin
                  z[c] <= a;
                  m[c] <= '0;
                end else begin
                  z[c] <= {a[31], 8'd126, a[22:0]};  // |z| in [0.5, 1)
                  m[c] <= 4'(a[30:23] - 8'd126);
                end
                acc[c] <= cinv[10];
                k[c]   <= 4'd9;
                st[c]  <= T_TAY_MUL;
              end
              issued[c] <= 1'b0;
            end
          end

          T_TAY_MUL: if (mres) begin
            tmp[c] <= mul_res; issued[c] <= 1'b0; st[c] <= T_TAY_ADD;
          end

          T_TAY_ADD: if (ares) begin
            acc[c] <= add_res;
            issued[c] <= 1'b0;
            if (k[c] == 0) st[c] <= T_TAY_FIN;
            else begin
              k[c]  <= k[c] - 1'b1;
              st[c] <= T_TAY_MUL;
            end
          end

          T_TAY_FIN: if (mres) begin
            d[c] <= mul_res;
            issued[c] <= 1'b0;
            if (fn[c] == 2'b01) st[c] <= (m[c] == 0) ? T_SELU_OUT : T_SELU_ADD;
            else st[c] <= T_E1;
          end

          T_SELU_ADD: if (ares) begin
            tmp[c] <= add_res; issued[c] <= 1'b0; st[c] <= T_SELU_MUL;
          end

          T_SELU_MUL: if (mres) begin
            d[c] <= mul_res;
            issued[c] <= 1'b0;
            m[c] <= m[c] - 1'b1;
            st[c] <= (m[c] == 4'd1) ? T_SELU_OUT : T_SELU_ADD;
          end

          T_SELU_OUT: if (mres) begin
            res[c] <= mul_res; issued[c] <= 1'b0; st[c] <= T_DONE;
          end

          T_E1: if (ares) begin
            e[c] <= add_res; issued[c] <= 1'b0; st[c] <= (m[c] == 0) ? T_U : T_SQ;
          end

          T_SQ: begin
            if (!issued[c] && e[c][30:23] < 8'd64) begin
              // E^2 would fall below the fp32 normal range, and the chain is exact at 0
              e[c]  <= '0;
              m[c]  <= '0;
              st[c] <= T_U;
            end else if (mres) begin
              e[c] <= mul_res;
              issued[c] <= 1'b0;
              m[c] <= m[c] - 1'b1;
              st[c] <= (m[c] == 4'd1) ? T_U : T_SQ;
            end
          end

          T_U: if (ares) begin
            tmp[c] <= add_res; issued[c] <= 1'b0; st[c] <= T_V;
          end

          T_V: if (mres) begin
            tmp[c] <= mul_res; issued[c] <= 1'b0; st[c] <= T_W;
          end

          T_W: if (ares) begin
            tmp[c] <= add_res; issued[c] <= 1'b0; st[c] <= T_S;
          end

          T_S: if (mres) begin
            s[c] <= mul_res;
            issued[c] <= 1'b0;
            if (fn[c] == 2'b10) begin
              if (x[c][31]) begin
                res[c] <= mul_res;
                st[c]  <= T_DONE;
              end else st[c] <= T_SIG_OUT;
            end else st[c] <= T_TANH_OUT;
          end

          T_SIG_OUT: if (ares) begin
            res[c] <= add_res; issued[c] <= 1'b0; st[c] <= T_DONE;
          end

          T_TANH_OUT: if (ares) begin
            res[c] <= {x[c][31], add_res[30:0]}; issued[c] <= 1'b0; st[c] <= T_DONE;
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
  a_start_free: assert property (@(posedge clk_i) disable iff (!rstn_i) start_i |-> ready_o)
    else $error("gpnae_tail: start with no free context");
`endif

endmodule
