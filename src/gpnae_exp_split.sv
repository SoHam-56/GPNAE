`timescale 1ns / 100ps

// e^-t = 2^-k with k = t log2 e split into its integer n and fraction f, on fp32 words (combinational): n = floor(k), f = k - n as an
// fp32 word (exact), under where k >= 256, so that 2^-n P(f) with P(f) in (0.5, 1] lies below every normal fp32 value. k >= 0 (a NaN
// or infinite k is under). Used by fp32's negative sigmoid on the barrel MAC and by bf16's tail; always fp32, so no format here.
module gpnae_exp_split (
    input  logic [31:0] k_i,
    output logic [ 7:0] n_o,
    output logic [31:0] f_o,
    output logic        under_o
);
  logic [7:0] e;
  logic [2:0] sh;
  logic [23:0] sig;
  logic [22:0] fr;  // k's fraction bits, below its binary point
  logic [4:0] lead;  // the fraction's leading one
  logic big;
  assign e   = k_i[30:23];
  assign big = e >= 8'd127;
  assign sh  = 3'(e - 8'd127);
  assign sig = {1'b1, k_i[22:0]};
  assign under_o = e >= 8'd135;  // k >= 2^8
  assign n_o = (big && !under_o) ? 8'(sig >> (5'd23 - 5'(sh))) : 8'd0;
  assign fr  = big ? 23'(sig << sh) : 23'd0;

  always_comb begin
    lead = '0;
    for (int i = 0; i < 23; i++) if (fr[i]) lead = 5'(i);
  end

  // f = fr 2^-23, normalized: exponent 127 + lead - 23, the bits below the leading one as its mantissa. k < 1 is its own fraction.
  always_comb begin
    if (!big) f_o = (e == 8'd0) ? 32'd0 : k_i;
    else if (fr == '0) f_o = 32'd0;
    else f_o = {1'b0, 8'(8'd104 + 8'(lead)), 23'(fr << (5'd23 - lead))};
  end
endmodule
