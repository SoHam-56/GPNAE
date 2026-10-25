`timescale 1ns / 100ps

// The lane's post stage: from an element's kind, P and its input, the output word, on three result ports in tag order of their own:
// A (registered, a cycle after the issue), B (the multiply path) and C (the add path). Floats: B is x lambda, x P, x 1.0 and fp32's
// E (1 - E) second pass on one fmt_mul; C is 1 - P as -(P - 1) on one fmt_add, which also makes fp32's 1 - E (kept here for the second
// pass, not put on C). int8: A is sigmoid's and tanh's quantized P and every rail; B is SELU's int24 product, then int8Requantizer.
// Also the bypass: ReLU in the build's format (byp_y_o, combinational).
module gpnae_post
  import gpnae_pkg::*;
#(
    parameter int  IW         = 4,
    parameter int  K          = 16,
    localparam int DATA_WIDTH = sienna_fmt_pkg::DATA_WIDTH
) (
    input logic clk_i,
    input logic rstn_i,

    input logic                         issue_i,  // the first pass of an element
    input logic                         pass2_i,  // fp32 K_EXP's second pass: E (1 - E)
    input logic [               IW-1:0] idx_i,
    input kind_t                        kind_i,
    input logic                         neg_i,
    input logic [                  1:0] fn_i,  // 0 SELU, 1 sigmoid, 2 tanh
    input logic [       DATA_WIDTH-1:0] x_i,  // the element's word as captured
    input logic [                 23:0] aux_i,  // int8: the rescale product r
    input logic [            ACT_W-1:0] p_i,  // P from the barrel MAC
    input logic [                  7:0] n_i,  // fp32 K_EXP: E = P 2^-n
    input logic                         under_i,
    input sienna_fmt_pkg::lane_params_t par_i,

    input  logic [DATA_WIDTH-1:0] byp_x_i,
    input  logic                  byp_relu_i,  // ReLU, else linear
    output logic [DATA_WIDTH-1:0] byp_y_o,

    output logic                  a_v_o,
    output logic [        IW-1:0] a_idx_o,
    output logic [DATA_WIDTH-1:0] a_data_o,
    output logic                  b_v_o,
    output logic [        IW-1:0] b_idx_o,
    output logic [DATA_WIDTH-1:0] b_data_o,
    output logic                  c_v_o,
    output logic [        IW-1:0] c_idx_o,
    output logic [DATA_WIDTH-1:0] c_data_o
);
  /* verilator lint_off UNUSEDPARAM */
  localparam int FN_SELU = 0, FN_SIG = 1, FN_TANH = 2;  // tanh is the else
  /* verilator lint_on UNUSEDPARAM */

`ifdef FMT_INT8
  // ── int8 ──
  localparam logic signed [15:0] SELU_SAT = -16'sd3601;  // -lambda*alpha in Q4.11
  localparam logic signed [15:0] ONE_Q11 = 16'sd2048;
  localparam logic signed [15:0] LAMBDA_Q14 = 16'sd17215;  // lambda in Q1.14
  localparam int RQ_LAT = sienna_fmt_pkg::REQUANT_LATENCY;
  localparam int PM_LAT = sienna_fmt_pkg::LANE_MUL_LATENCY;
  localparam int B_LAT = PM_LAT + RQ_LAT;  // after the operand register: int24Multiplier, then int8Requantizer
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_in;
  assign unused_in = ^{pass2_i, n_i, under_i, x_i, par_i.in_rescale_mantissa, K};
  /* verilator lint_on UNUSEDSIGNAL */

  assign byp_y_o = byp_relu_i ? sienna_fmt_pkg::fmt_relu(byp_x_i, par_i.in_zero_point) : byp_x_i;  // ReLU: max(q, z_in)

  // sigmoid: round(256 y) - 128 = ((y + 4) >> 3) - 128 for y in Q4.11, clamped to int8.
  function automatic logic [7:0] quant_sig(input logic signed [16:0] y);
    logic signed [16:0] r;
    r = ((y + 17'sd4) >>> 3) - 17'sd128;
    if (r > 17'sd127) return 8'h7F;
    if (r < -17'sd128) return 8'h80;
    return r[7:0];
  endfunction

  // tanh from P ~ tanh(|x|) in Q4.11: m = round(128 P) = (P + 8) >> 4 in [0, 128], the sign restored, clamped to int8.
  function automatic logic [7:0] quant_tanh(input logic signed [15:0] p, input logic neg);
    logic signed [16:0] m;
    m = (17'(p) + 17'sd8) >>> 4;
    if (m < 17'sd0) m = 17'sd0;
    if (m > 17'sd128) m = 17'sd128;
    if (neg) return 8'(-m);
    return (m > 17'sd127) ? 8'h7F : m[7:0];
  endfunction

  logic signed [16:0] pe;
  assign pe = 17'($signed(p_i));
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) a_v_o <= 1'b0;
    else a_v_o <= issue_i && fn_i != 2'(FN_SELU);
  always_ff @(posedge clk_i)
    if (issue_i) begin
      a_idx_o  <= idx_i;
      a_data_o <= (kind_i == K_SAT) ? (neg_i ? 8'h80 : 8'h7F)
                : (fn_i == 2'(FN_SIG)) ? quant_sig((kind_i == K_REFL) ? (17'sd2048 - pe) : pe) : quant_tanh(p_i, neg_i);
    end

  // SELU: r lambda (x >= 0), r P, or -lambda*alpha 2^shx 1.0 past the last bound; then the output requantize.
  logic [23:0] pm_a, pm_b;
  /* verilator lint_off UNUSEDSIGNAL */
  logic [47:0] pm;  // rq_acc takes [38:7] or [35:4]
  /* verilator lint_on UNUSEDSIGNAL */
  logic        pm_v, pm_done, rq_done;
  logic [31:0] rq_acc;
  logic [ 7:0] rq_res;
  logic [B_LAT:0] t_v;
  logic [IW-1:0]  t_idx[B_LAT+1];
  logic [PM_LAT:0] t_lin;
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) begin
      pm_v <= 1'b0;
      t_v  <= '0;
    end else begin
      pm_v <= issue_i && fn_i == 2'(FN_SELU);
      t_v  <= {t_v[B_LAT-1:0], issue_i && fn_i == 2'(FN_SELU)};
    end
  always_ff @(posedge clk_i) begin
    if (issue_i) begin
      pm_a <= (kind_i == K_SAT) ? (24'($signed(SELU_SAT)) << par_i.in_rescale_shift) : aux_i;  // past -bound, shx <= 9: it fits 24 bits
      pm_b <= 24'($signed((kind_i == K_LIN) ? LAMBDA_Q14 : (kind_i == K_SAT) ? ONE_Q11 : $signed(p_i)));
    end
    t_idx[0] <= idx_i;
    for (int i = 1; i <= B_LAT; i++) t_idx[i] <= t_idx[i-1];
    t_lin <= {t_lin[PM_LAT-1:0], kind_i == K_LIN};
  end
  int24Multiplier POSTM (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(pm_v), .a_i(pm_a), .b_i(pm_b), .result_o(pm), .done_o(pm_done));
  // In 2^-(shx + 18): r lambda >>> 7, r P and the saturated constant >>> 4; each fits int32 for every legal r.
  assign rq_acc = t_lin[PM_LAT] ? pm[38:7] : pm[35:4];
  int8Requantizer POSTQ (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(pm_done), .acc_i(rq_acc), .mult_i(par_i.selu_out_mantissa),
                         .shift_i(par_i.selu_out_shift), .zp_i(par_i.selu_out_zero_point), .act_min_i(8'h80), .act_max_i(8'h7F),
                         .result_o(rq_res), .done_o(rq_done));
  assign b_v_o    = t_v[B_LAT];
  assign b_idx_o  = t_idx[B_LAT];
  assign b_data_o = rq_res;
  assign c_v_o    = 1'b0;
  assign c_idx_o  = '0;
  assign c_data_o = '0;

`ifdef SYNTHESIS
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_done;
  assign unused_done = rq_done;  // checked below in simulation only
  /* verilator lint_on UNUSEDSIGNAL */
`else
  a_selu_latency: assert property (@(posedge clk_i) disable iff (!rstn_i) (pm_done == t_v[PM_LAT]) && (rq_done == t_v[B_LAT]))
    else $error("gpnae_post: a_selu_latency: int24Multiplier is not %0d cycles or int8Requantizer not %0d", PM_LAT, RQ_LAT);
`endif

`else
  // ── floats ──
`ifdef FMT_BF16
  localparam logic [ACT_W-1:0] LAMBDA = 16'h3F87;  // rounded up: the multiplier truncates, and 0x3F86 x 0x7F73 fell below bf16's max
  localparam logic [ACT_W-1:0] NEG_LA = 16'hBFE1;  // -lambda*alpha
  localparam logic [ACT_W-1:0] ONE = 16'h3F80;
  localparam logic [ACT_W-1:0] NEG_ONE = 16'hBF80;
`else
  localparam logic [ACT_W-1:0] LAMBDA = 32'h3F867D5F;
  localparam logic [ACT_W-1:0] NEG_LA = 32'hBFE10966;
  localparam logic [ACT_W-1:0] ONE = 32'h3F800000;
  localparam logic [ACT_W-1:0] NEG_ONE = 32'hBF800000;
`endif
  localparam int ML = sienna_fmt_pkg::LANE_MUL_LATENCY;
  localparam int AL = sienna_fmt_pkg::LANE_ADD_LATENCY;
  localparam logic [ACT_W-1:0] S = {1'b1, {(ACT_W - 1) {1'b0}}};
  localparam int SW = $clog2(K);
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_in;
  assign unused_in = ^{aux_i, par_i, neg_i};
  /* verilator lint_on UNUSEDSIGNAL */

  assign byp_y_o = byp_relu_i ? sienna_fmt_pkg::fmt_relu(byp_x_i, '0) : byp_x_i;  // ReLU: +0 for a negative word

  // E = P 2^-n by an exponent subtract (P > 0): 0 below the normal range or under.
  logic [ACT_W-1:0] e;
  logic signed [9:0] ep;
  assign ep = 10'(p_i[ACT_W-2-:8]) - 10'(n_i);
  assign e  = (under_i || ep <= 10'sd0) ? '0 : {1'b0, ep[7:0], p_i[ACT_W-10:0]};

  // A: P, or the limit.
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) a_v_o <= 1'b0;
    else a_v_o <= issue_i && (kind_i == K_PASS || kind_i == K_SAT);
  always_ff @(posedge clk_i)
    if (issue_i) begin
      a_idx_o  <= idx_i;
      a_data_o <= (kind_i == K_PASS) ? p_i : (fn_i == 2'(FN_SELU)) ? NEG_LA : (fn_i == 2'(FN_SIG)) ? ONE : {x_i[ACT_W-1], ONE[ACT_W-2:0]};
    end

  // B: one multiply per issue, a cycle after it; the second pass multiplies E by the 1 - E its first pass left in d_buf.
  logic [ACT_W-1:0] d_buf[K];
  logic [ACT_W-1:0] m_a, m_b, m_y;
  logic             m_v, m_done;
  logic [ML:0]      mt_v;
  logic [IW-1:0]    mt_idx[ML+1];
  logic             m_go;
  assign m_go = (issue_i && (kind_i == K_LIN || kind_i == K_MUL || kind_i == K_ONE)) || pass2_i;
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) begin
      m_v  <= 1'b0;
      mt_v <= '0;
    end else begin
      m_v  <= m_go;
      mt_v <= {mt_v[ML-1:0], m_go};
    end
  always_ff @(posedge clk_i) begin
    if (m_go) begin
      m_a <= pass2_i ? e : x_i;
      m_b <= pass2_i ? d_buf[idx_i[SW-1:0]] : (kind_i == K_LIN) ? LAMBDA : (kind_i == K_ONE) ? ONE : p_i;
    end
    mt_idx[0] <= idx_i;
    for (int i = 1; i <= ML; i++) mt_idx[i] <= mt_idx[i-1];
  end
  fmt_mul #(.DATA_WIDTH(ACT_W), .EXT_DATA_WIDTH(ACT_W)) POST (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(m_v), .a_i(m_a), .b_i(m_b),
                                                             .product_o(m_y), .done_o(m_done));
  assign b_v_o    = mt_v[ML];
  assign b_idx_o  = mt_idx[ML];
  assign b_data_o = m_y;

  // C: one add per issue, a cycle after it: P - 1 with the sign flipped (1 - P), or fp32's 1 - E into d_buf.
  logic [ACT_W-1:0] d_a, d_b, d_y;
  logic             d_v, d_done, d_go;
  logic [AL:0]      dt_v, dt_keep;  // dt_keep: the result is 1 - E for the second pass, not an output
  logic [IW-1:0]    dt_idx[AL+1];
  assign d_go = issue_i && (kind_i == K_REFL || kind_i == K_EXP);
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) begin
      d_v     <= 1'b0;
      dt_v    <= '0;
      dt_keep <= '0;
    end else begin
      d_v     <= d_go;
      dt_v    <= {dt_v[AL-1:0], d_go};
      dt_keep <= {dt_keep[AL-1:0], kind_i == K_EXP};
    end
  always_ff @(posedge clk_i) begin
    if (d_go) begin
      d_a <= (kind_i == K_EXP) ? ONE : p_i;
      d_b <= (kind_i == K_EXP) ? (e ^ S) : NEG_ONE;
    end
    dt_idx[0] <= idx_i;
    for (int i = 1; i <= AL; i++) dt_idx[i] <= dt_idx[i-1];
    if (dt_v[AL] && dt_keep[AL]) d_buf[dt_idx[AL][SW-1:0]] <= d_y;
  end
  fmt_add #(.DATA_WIDTH(ACT_W)) POSTD (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(d_v), .a_i(d_a), .b_i(d_b), .sum_o(d_y), .done_o(d_done));
  assign c_v_o    = dt_v[AL] && !dt_keep[AL];
  assign c_idx_o  = dt_idx[AL];
  assign c_data_o = d_y ^ S;  // -(P - 1)

`ifdef SYNTHESIS
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_done;
  assign unused_done = m_done ^ d_done;  // checked below in simulation only
  /* verilator lint_on UNUSEDSIGNAL */
`else
  a_post_latency: assert property (@(posedge clk_i) disable iff (!rstn_i) (m_done == mt_v[ML]) && (d_done == dt_v[AL]))
    else $error("gpnae_post: a_post_latency: the post multiply is not %0d cycles after its operands or the add not %0d", ML, AL);
`endif
`endif
endmodule
