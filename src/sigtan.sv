`timescale 1ns / 100ps

module sigtan (
    input  wire        clk_i,
    input  wire        rstn_i,
    input  wire        valid_i,
    input  wire [31:0] mac_result,
    input  wire [ 1:0] select_sub,
    output wire [31:0] final_result_o,
    output wire        done_o
);

  wire [31:0] add_result, sub_result;
  wire done_fp32_add_sub;
  wire [31:0] mux_output;

  // Instantiate FP32 Add/Sub module
  fp32_up_down u_fp32_add_sub (
      .clk_i(clk_i),
      .rstn_i(rstn_i),
      .valid_i(valid_i),
      .A(mac_result),
      .Result1(add_result),
      .Result2(sub_result),
      .done_o(done_fp32_add_sub)
  );

  // Numerator select: sigmoid uses e^x, tanh uses e^2x - 1.
  // Was two continuous assigns resolving through 'bz, which drove X into the divider for any other select.
  assign mux_output = (select_sub == 2'b01) ? sub_result : mac_result;

  fp32Divider u_fp32Divider (
      .clk_i  (clk_i),
      .rstn_i (rstn_i),
      .valid_i(done_fp32_add_sub),
      .A      (mux_output),
      .B      (add_result),
      .Result (final_result_o),
      .done_o (done_o)
  );

endmodule
