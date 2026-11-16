`timescale 1ns / 100ps

// e^-t = 2^-k with k = t log2 e split into its integer n and fraction f, on fp32 words: n = floor(k), f = k - n as an fp32 word
// (exact), under where k >= 256, so that 2^-n P(f) with P(f) in (0.5, 1] lies below every normal fp32 value. k >= 0 (a NaN or infinite
// k is under). Two register stages, no valid: the outputs follow k_i two cycles later (the caller keeps k_i on a register and reads them
// then). Stage A: n, the fraction bits and under; stage B: the fraction's leading one and its normalization (the two shifts and the
// priority find in one cycle were 1.27 ns at 45 nm). Used by fp32's negative sigmoid on the barrel MAC and by bf16's tail; always fp32,
// so no format here.
module gpnae_exp_split (
    input  logic        clk_i,
    input  logic [31:0] k_i,
    output logic [ 7:0] n_o,
    output logic [31:0] f_o,
    output logic        under_o
);
  logic [7:0] e;
  logic [2:0] sh;
  logic [23:0] sig;
  logic [22:0] fr;  // k's fraction bits, below its binary point
  logic big, under;
  logic [7:0] n;
  logic [31:0] f_small;  // k below 1: f is k itself (0 for a zero or subnormal k)
  // Stage A.
  logic [7:0] a_n;
  logic [22:0] a_fr;
  logic a_big, a_under;
  logic [31:0] a_f_small;
  // Stage B.
  logic [4:0] lead;  // the fraction's leading one

  assign e   = k_i[30:23];
  assign big = e >= 8'd127;
  assign sh  = 3'(e - 8'd127);
  assign sig = {1'b1, k_i[22:0]};
  assign under = e >= 8'd135;  // k >= 2^8
  assign n   = (big && !under) ? 8'(sig >> (5'd23 - 5'(sh))) : 8'd0;
  assign fr  = big ? 23'(sig << sh) : 23'd0;
  assign f_small = (e == 8'd0) ? 32'd0 : k_i;

  always_ff @(posedge clk_i) begin
    a_n       <= n;
    a_fr      <= fr;
    a_big     <= big;
    a_under   <= under;
    a_f_small <= f_small;
  end

  always_comb begin
    lead = '0;
    for (int i = 0; i < 23; i++) if (a_fr[i]) lead = 5'(i);
  end

  always_ff @(posedge clk_i) begin
    n_o     <= a_n;
    under_o <= a_under;
    if (!a_big) f_o <= a_f_small;
    else if (a_fr == '0) f_o <= 32'd0;
    else f_o <= {1'b0, 8'(8'd104 + 8'(lead)), 23'(a_fr << (5'd23 - lead))};
  end
endmodule
