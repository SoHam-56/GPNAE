`timescale 1ns / 100ps

// Q4.11 multiply-add for the int8 Horner step: a_i * x_i over intMulPipe's three cycles (the 16-row carry-save tree registered halfway,
// as int16Multiplier), then the product shifted by 11 + frac_i on its own stage, then plus the coefficient, saturated to 16 bits. c_i is
// sampled as the shifted product lands, four cycles after valid_i (the shift select into the add into the saturation was 1.09 ns at 45 nm).
// Five cycles from valid_i to done_o.
module fixedPointMultiplyAdd #(
    localparam int DATA_WIDTH = 16
) (
    input  logic                         clk_i,
    input  logic                         rstn_i,
    input  logic                         valid_i,
    input  logic signed [DATA_WIDTH-1:0] a_i,
    input  logic signed [DATA_WIDTH-1:0] x_i,
    input  logic signed [DATA_WIDTH-1:0] c_i,  // sampled four cycles after valid_i
    input  logic        [           1:0] frac_i,  // the product's fraction bits beyond Q4.11's 11
    output logic signed [DATA_WIDTH-1:0] result_o,
    output logic                         done_o
);
  localparam int PW = 2 * DATA_WIDTH;
  localparam int MUL_STAGES = 3;

  // The product, and the fraction riding beside it.
  logic                 p_v;
  logic signed [PW-1:0] p;
  logic [MUL_STAGES-1:0] fv;
  logic [1:0] f_d[MUL_STAGES];
  // The shifted product, registered.
  logic                 s_v;
  logic signed [PW-1:0] s_p;
  // The shifted product plus the coefficient, and whether it fits 16 bits.
  logic signed [PW-1:0] sum;
  logic                 fits;

  intMulPipe #(.AW(DATA_WIDTH), .BW(DATA_WIDTH), .STAGES(MUL_STAGES)) MUL (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(valid_i), .a_i(a_i), .b_i(x_i), .result_o(p), .done_o(p_v));

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) fv <= '0;
    else fv <= {fv[MUL_STAGES-2:0], valid_i};
  always_ff @(posedge clk_i) begin
    if (valid_i) f_d[0] <= frac_i;
    for (int i = 1; i < MUL_STAGES; i++) if (fv[i-1]) f_d[i] <= f_d[i-1];
  end

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) s_v <= 1'b0;
    else s_v <= p_v;
  always_ff @(posedge clk_i)
    if (p_v) s_p <= p >>> (5'd11 + 5'(f_d[MUL_STAGES-1]));

  assign sum  = s_p + PW'(c_i);
  assign fits = (sum[PW-1:DATA_WIDTH-1] == '0) || (sum[PW-1:DATA_WIDTH-1] == '1);

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) done_o <= 1'b0;
    else done_o <= s_v;
  always_ff @(posedge clk_i)
    if (s_v) result_o <= fits ? sum[DATA_WIDTH-1:0] : {sum[PW-1], {(DATA_WIDTH - 1) {~sum[PW-1]}}};

endmodule
