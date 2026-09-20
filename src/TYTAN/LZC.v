// cntlz8 comes from ArithmeticLibrary/Adders/FP32/src/LZC.sv; the copy here was a duplicate definition.

module cntlz24 (
    input  [23:0] i,
    output [ 4:0] o
);

  wire [3:0] cnt1, cnt2, cnt3;

  cntlz8 u1 (
      i[7:0],
      cnt1
  );
  cntlz8 u2 (
      i[15:8],
      cnt2
  );
  cntlz8 u3 (
      i[23:16],
      cnt3
  );

  assign o = !cnt3[3] ? {1'b0, cnt3} : !cnt2[3] ? {1'b0, cnt2} + 4'b1000 : {1'b0, cnt1} + 5'b10000;

endmodule
