`timescale 1ns / 100ps

// One Horner step, y = c + x * acc, in the build's activation arithmetic: floats fmt_mul then fmt_add (the add's A the coefficient),
// int8 one register then fixedPointMultiplyAdd. x_i, acc_i and frac_i are taken with valid_i; c_i is sampled HORNER_COEFFICIENT_LAG
// cycles later; y_o and done_o come HORNER_STEP_LATENCY cycles after valid_i. A new step may start every cycle.
module gpnae_horner #(
    localparam int ACT_W = sienna_fmt_pkg::ACTIVATION_DATA_WIDTH
) (
    input  logic             clk_i,
    input  logic             rstn_i,
    input  logic             valid_i,
    input  logic [ACT_W-1:0] x_i,
    input  logic [ACT_W-1:0] acc_i,
    input  logic [      1:0] frac_i,  // int8: the product's fraction bits beyond 11; floats ignore it
    input  logic [ACT_W-1:0] c_i,
    output logic [ACT_W-1:0] y_o,
    output logic             done_o
);
  localparam int LAG = sienna_fmt_pkg::HORNER_COEFFICIENT_LAG;
  localparam int LOOP = sienna_fmt_pkg::HORNER_STEP_LATENCY;

`ifdef FMT_INT8
  // One register, so the coefficient arrives with the operands a cycle after valid_i, then the fixed-point multiply-add.
  logic             r_v;
  logic [ACT_W-1:0] r_x, r_acc;
  logic [      1:0] r_f;
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) r_v <= 1'b0;
    else r_v <= valid_i;
  always_ff @(posedge clk_i)
    if (valid_i) begin
      r_x   <= x_i;
      r_acc <= acc_i;
      r_f   <= frac_i;
    end
  fixedPointMultiplyAdd MAC (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(r_v), .a_i(r_x), .x_i(r_acc), .c_i(c_i), .frac_i(r_f),
                             .result_o(y_o), .done_o(done_o));
  if (LAG != 1 || LOOP != 3) begin : G_BAD_LATENCY
    $fatal(1, "gpnae_horner: int8 is a register then fixedPointMultiplyAdd's 2 cycles (lag 1, loop 3), not lag %0d loop %0d", LAG, LOOP);
  end
`else
  // The product's done lines up with the coefficient: the add issues as the product lands.
  logic [ACT_W-1:0] prod;
  logic             prod_v;
  /* verilator lint_off UNUSEDSIGNAL */
  logic [1:0] frac_unused;
  /* verilator lint_on UNUSEDSIGNAL */
  assign frac_unused = frac_i;
  fmt_mul #(.DATA_WIDTH(ACT_W), .EXT_DATA_WIDTH(ACT_W)) MUL (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(valid_i), .a_i(x_i), .b_i(acc_i),
                                                            .product_o(prod), .done_o(prod_v));
  fmt_add #(.DATA_WIDTH(ACT_W)) ADD (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(prod_v), .a_i(c_i), .b_i(prod), .sum_o(y_o),
                                     .done_o(done_o));
  if (LAG != sienna_fmt_pkg::LANE_MUL_LATENCY || LOOP != LAG + sienna_fmt_pkg::LANE_ADD_LATENCY) begin : G_BAD_LATENCY
    $fatal(1, "gpnae_horner: the float step is the lane multiply (%0d) then add (%0d), not lag %0d loop %0d", sienna_fmt_pkg::LANE_MUL_LATENCY,
           sienna_fmt_pkg::LANE_ADD_LATENCY, LAG, LOOP);
  end
`endif

`ifndef SYNTHESIS
  // The step's latency is the package's: a unit that differs would pair a result with the wrong slot silently.
  logic [LOOP:0] v_q;
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) v_q <= '0;
    else v_q <= {v_q[LOOP-1:0], valid_i};
  a_step_latency: assert property (@(posedge clk_i) disable iff (!rstn_i) done_o == v_q[LOOP-1])
    else $error("gpnae_horner: a_step_latency: done_o does not come HORNER_STEP_LATENCY = %0d cycles after valid_i", LOOP);
`endif
endmodule
