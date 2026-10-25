`timescale 1ns / 100ps

// Equivalence tops for eq_gpnae.cpp: a unit beside the one it replaces, done and result compared every cycle.

// fixedPointMultiplyAdd against fxMac at FRAC = 11 + frac_i, the four FRACs it takes.
module eq_fxp (input logic clk_i, rstn_i, valid_i, input logic [15:0] a_i, x_i, c_i, input logic [1:0] frac_i,
               output logic [15:0] result_new, result_generic, output logic done_new, done_generic);
  logic [15:0] r[4];
  logic d[4];
  logic [1:0] f1, f2;
  fixedPointMultiplyAdd NEW (.clk_i, .rstn_i, .valid_i, .a_i(a_i), .x_i(x_i), .c_i(c_i), .frac_i(frac_i), .result_o(result_new), .done_o(done_new));
  for (genvar k = 0; k < 4; k++) begin : G_GEN
    fxMac #(.W(16), .FRAC(11 + k)) GEN (.clk_i, .rstn_i, .valid_i(valid_i && frac_i == 2'(k)), .A(a_i), .X(x_i), .C(c_i), .result_o(r[k]),
                                        .done_o(d[k]));
  end
  always_ff @(posedge clk_i) begin
    f1 <= frac_i;
    f2 <= f1;
  end
  assign result_generic = r[f2];
  assign done_generic = d[0] | d[1] | d[2] | d[3];
endmodule

// fp32_down, B's P - 1 for fp32's negative sigmoid, against fp32Adder(A, -1.0), its replacement; results in issue order (latencies 6 and 5).
module eq_down (input logic clk_i, rstn_i, valid_i, input logic [31:0] a_i, output logic [31:0] result_new, result_generic,
                output logic done_new, done_generic);
  fp32Adder NEW (.clk_i, .rstn_i, .valid_i, .A(a_i), .B(32'hBF800000), .result_o(result_new), .done_o(done_new), .overflow_o(), .underflow_o(),
                 .invalid_o());
  fp32_down GEN (.clk_i, .rstn_i, .valid_i, .A(a_i), .Result(result_generic), .done_o(done_generic));
endmodule
