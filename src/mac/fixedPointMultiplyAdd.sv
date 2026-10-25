`timescale 1ns / 100ps

// The int8 lane's Horner step on Q4.11 words: result_o = sat16(floor(a_i * x_i / 2^(11 + frac_i)) + c_i); done_o two cycles after valid_i.
// ArithmeticLibrary's fxMac at FRAC = 11 + frac_i (proven equal at each), with the shift as an input; only the valid bits reset (D-8).
module fixedPointMultiplyAdd #(
    localparam int DATA_WIDTH = 16
) (
    input  logic                         clk_i,
    input  logic                         rstn_i,
    input  logic                         valid_i,
    input  logic signed [DATA_WIDTH-1:0] a_i,
    input  logic signed [DATA_WIDTH-1:0] x_i,
    input  logic signed [DATA_WIDTH-1:0] c_i,
    input  logic        [           1:0] frac_i,  // the product's fraction bits beyond Q4.11's 11
    output logic signed [DATA_WIDTH-1:0] result_o,
    output logic                         done_o
);
  localparam int PW = 2 * DATA_WIDTH;

  // Stage 1: the exact product (|a x| <= 2^(2W-2)), the addend and the shift.
  logic                 s1_v;
  logic signed [PW-1:0] s1_p;
  logic signed [DATA_WIDTH-1:0] s1_c;
  logic [1:0]           s1_f;

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) s1_v <= 1'b0;
    else s1_v <= valid_i;

  always_ff @(posedge clk_i)
    if (valid_i) begin
      s1_p <= PW'(a_i) * PW'(x_i);
      s1_c <= c_i;
      s1_f <= frac_i;
    end

  // Stage 2: the sum fits 2W bits; it fits W bits when its top W+1 bits agree, else it saturates.
  logic signed [PW-1:0] sum;
  logic                 fits;
  assign sum  = (s1_p >>> (5'd11 + 5'(s1_f))) + PW'(s1_c);
  assign fits = (sum[PW-1:DATA_WIDTH-1] == '0) || (sum[PW-1:DATA_WIDTH-1] == '1);

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) done_o <= 1'b0;
    else done_o <= s1_v;

  always_ff @(posedge clk_i)
    if (s1_v) result_o <= fits ? sum[DATA_WIDTH-1:0] : {sum[PW-1], {(DATA_WIDTH - 1) {~sum[PW-1]}}};

endmodule
