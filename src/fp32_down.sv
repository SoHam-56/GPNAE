`timescale 1ns / 100ps

module fp32_down (
    input wire clk_i,
    input wire rstn_i,
    input wire valid_i,
    input wire [31:0] A,
    output wire [31:0] Result,
    output wire done_o
);
  localparam [31:0] CONST = 32'hbf800000;  // -1.0 in FP32

  wire [4:0] zerocount;
  reg Sign;
  reg [7:0] Exponent;
  reg [22:0] Mantissa;

  wire comp, magcheck, zero;
  reg carry, check;
  reg [7:0] BigExp, SmallExp, DifferenceExp;
  reg [23:0] BigMan, SmallMan;
  reg [23:0] Temp_SmallMan, TempMan;

  // Control path - valid signal pipeline registers
  reg valid_stage1, valid_stage2, valid_stage3, valid_stage4, valid_stage5, valid_stage6;

  reg A_sign, C_sign;
  reg sign;
  reg [7:0] A_Exp, C_Exp;
  reg [22:0] A_Man, C_Man;

  // Stage 2 produces these but stages 4, 5 and 6 consume them, so they have to travel with
  // their operation. Without these copies a new input every cycle overwrites them under the
  // one still in flight, which is why this block only ever worked one operation at a time.
  reg [7:0] BigExp_d1, BigExp_d2, BigExp_d3;
  reg sign_d1, sign_d2, sign_d3;
  reg check_d1, check_d2;
  reg [23:0] BigMan_d1, BigMan_d2;
  reg [23:0] SmallMan_d1;

  always @(posedge clk_i) begin
    BigExp_d1 <= BigExp;
    BigExp_d2 <= BigExp_d1;
    BigExp_d3 <= BigExp_d2;
    sign_d1 <= sign;
    sign_d2 <= sign_d1;
    sign_d3 <= sign_d2;
    check_d1 <= check;
    check_d2 <= check_d1;
    BigMan_d1 <= BigMan;
    BigMan_d2 <= BigMan_d1;
    SmallMan_d1 <= SmallMan;
  end

  // Control path - Stage 1 valid signal
  always @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      valid_stage1 <= 1'b0;
    end else begin
      valid_stage1 <= valid_i;
    end
  end

  // Data path - Stage 1: Input Registration
  always @(posedge clk_i) begin
    if (valid_i) begin
      A_sign <= A[31];
      C_sign <= CONST[31];
      A_Exp  <= A[30:23];
      C_Exp  <= CONST[30:23];
      A_Man  <= A[22:0];
      C_Man  <= CONST[22:0];
    end
  end

  assign comp = (A_Exp > C_Exp) ? 1'b1 : 1'b0;
  assign magcheck = (A_Exp ^ C_Exp) ? 1'b0 : ((A_Man > C_Man) ? 1'b1 : 1'b0);
  assign zero = ~|{A_Exp, A_Man};

  // Control path - Stage 2 valid signal
  always @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      valid_stage2 <= 1'b0;
    end else begin
      valid_stage2 <= valid_stage1;
    end
  end

  // Data path - Stage 2
  always @(posedge clk_i) begin
    if (valid_stage1) begin
      check <= A_sign ^ C_sign;
      sign  <= (comp | magcheck) ? A_sign : (zero ? 1'b0 : C_sign);

      if (zero) begin
        BigExp   <= 8'b0;
        SmallExp <= 8'b0;
        BigMan   <= 24'b0;
        SmallMan <= 24'b0;
      end else begin
        BigExp   <= comp ? A_Exp : C_Exp;
        SmallExp <= comp ? C_Exp : A_Exp;

        BigMan   <= {1'b1, (comp | magcheck) ? A_Man : C_Man};
        SmallMan <= {1'b1, (comp | magcheck) ? C_Man : A_Man};
      end
    end
  end

  // Control path - Stage 3 valid signal
  always @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      valid_stage3 <= 1'b0;
    end else begin
      valid_stage3 <= valid_stage2;
    end
  end

  // Data path - Stage 3
  always @(posedge clk_i) begin
    if (valid_stage2) begin
      DifferenceExp <= BigExp - SmallExp;
    end
  end

  // Control path - Stage 4 valid signal
  always @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      valid_stage4 <= 1'b0;
    end else begin
      valid_stage4 <= valid_stage3;
    end
  end

  // Data path - Stage 4
  always @(posedge clk_i) begin
    if (valid_stage3) begin
      Temp_SmallMan <= SmallMan_d1 >> DifferenceExp;
    end
  end

  // Control path - Stage 5 valid signal
  always @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      valid_stage5 <= 1'b0;
    end else begin
      valid_stage5 <= valid_stage4;
    end
  end

  // Data path - Stage 5
  always @(posedge clk_i) begin
    if (valid_stage4) begin
      {carry, TempMan} <= check_d2 ? (BigMan_d2 - Temp_SmallMan) : (BigMan_d2 + Temp_SmallMan);
    end
  end

  cntlz24 stage_31 (
      .i(TempMan),
      .o(zerocount)
  );

  // Control path - Final Stage valid signal
  always @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      valid_stage6 <= 1'b0;
      Sign <= 1'b0;
      Exponent <= 8'b0;
      Mantissa <= 23'b0;
    end else begin
      valid_stage6 <= valid_stage5;
      if (valid_stage5) begin
        if (carry) begin
          Mantissa <= TempMan[23:1];
          Exponent <= BigExp_d3 + 1;
        end else if (|TempMan[22:0]) begin
          Mantissa <= TempMan[22:0] << zerocount;
          Exponent <= BigExp_d3 - {3'b0, zerocount};
        end else if (TempMan == 24'b0) begin
          // Exact cancellation -> zero. See fp32_up_down.sv.
          Mantissa <= 23'b0;
          Exponent <= 8'b0;
        end else begin
          // TempMan == 24'h800000: already normalised.
          Mantissa <= TempMan[22:0];
          Exponent <= BigExp_d3;
        end
        // IEEE 754: exact cancellation yields +0, not the operand sign.
        Sign <= (!carry && TempMan == 24'b0) ? 1'b0 : sign_d3;
      end
    end
  end

  // Output assignments
  assign Result = {Sign, Exponent, Mantissa};
  assign done_o = valid_stage6;

endmodule

