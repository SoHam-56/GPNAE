//`timescale 1ns / 1ps

//module fp32_down (
//    input wire clk_i,
//    input wire rstn_i,
//    input wire valid_i,
//    input wire [31:0] A,
//    output wire [31:0] Result,  // A - bf800000
//    output wire done_o
//);
//    // Constants
//    localparam [31:0] CONST = 32'hbf800000;

//    // Pipeline stage registers
//    reg [31:0] A_reg;
//    reg valid_pipe [0:5];

//    // Stage 1: Input and component extraction
//    reg a_sign, b_sign;
//    reg [7:0] a_exp, b_exp;
//    reg [23:0] a_mantissa, b_mantissa;

//    // Stage 2: Exponent comparison and mantissa alignment
//    reg [7:0] exp_diff;
//    reg [23:0] aligned_mantissa;
//    reg [7:0] result_exp;
//    reg larger_exp;

//    // Stage 3: Subtraction
//    reg [24:0] sum_mantissa;
//    reg result_sign;

//    // Stage 4: Leading zero count
//    reg [4:0] leading_zeros;

//    // Stage 5: Normalization
//    reg [7:0] final_exp;
//    reg [22:0] final_mantissa;

//    // Stage 6: Final result composition
//    reg [31:0] Result_reg;

//    // Stage 1: Input Registration and component extraction
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            A_reg <= 32'b0;
//            valid_pipe[0] <= 1'b0;
//            {a_sign, b_sign} <= 2'b0;
//            {a_exp, b_exp} <= 16'b0;
//            {a_mantissa, b_mantissa} <= 48'b0;
//        end else begin
//            valid_pipe[0] <= valid_i;
//            if (valid_i) begin
//                A_reg <= A;
//                a_sign <= A[31];
//                b_sign <= CONST[31];
//                a_exp <= A[30:23];
//                b_exp <= CONST[30:23];
//                a_mantissa <= {1'b1, A[22:0]};
//                b_mantissa <= {1'b1, CONST[22:0]};
//            end
//        end
//    end

//    // Stage 2: Exponent comparison and mantissa alignment
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            {exp_diff, aligned_mantissa, result_exp} <= 40'b0;
//            larger_exp <= 1'b0;
//            valid_pipe[1] <= 1'b0;
//        end else begin
//            valid_pipe[1] <= valid_pipe[0];
//            if (valid_pipe[0]) begin
//                if (a_exp > b_exp) begin
//                    exp_diff <= a_exp - b_exp;
//                    aligned_mantissa <= b_mantissa >> (a_exp - b_exp);
//                    result_exp <= a_exp;
//                    larger_exp <= 1'b1;
//                end else begin
//                    exp_diff <= b_exp - a_exp;
//                    aligned_mantissa <= a_mantissa >> (b_exp - a_exp);
//                    result_exp <= b_exp;
//                    larger_exp <= 1'b0;
//                end
//            end
//        end
//    end

//    // Stage 3: Subtraction
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            sum_mantissa <= 25'b0;
//            result_sign <= 1'b0;
//            valid_pipe[2] <= 1'b0;
//        end else begin
//            valid_pipe[2] <= valid_pipe[1];
//            if (valid_pipe[1]) begin
//                if (a_sign == b_sign) begin
//                    sum_mantissa <= (larger_exp ? {1'b0, a_mantissa} : {1'b0, b_mantissa}) - {1'b0, aligned_mantissa};
//                    result_sign <= a_sign;
//                end else begin
//                    sum_mantissa <= (larger_exp ? {1'b0, a_mantissa} : {1'b0, b_mantissa}) + {1'b0, aligned_mantissa};
//                    result_sign <= larger_exp ? a_sign : b_sign;
//                end
//            end
//        end
//    end

//    // Stage 4: Leading zero count
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            leading_zeros <= 5'b0;
//            valid_pipe[3] <= 1'b0;
//        end else begin
//            valid_pipe[3] <= valid_pipe[2];
//            if (valid_pipe[2]) begin
//                casez (sum_mantissa[23:0])
//                    24'b1???????????????????????: leading_zeros = 5'd0;
//                    24'b01??????????????????????: leading_zeros = 5'd1;
//                    24'b001?????????????????????: leading_zeros = 5'd2;
//                    24'b0001????????????????????: leading_zeros = 5'd3;
//                    24'b00001???????????????????: leading_zeros = 5'd4;
//                    24'b000001??????????????????: leading_zeros = 5'd5;
//                    24'b0000001?????????????????: leading_zeros = 5'd6;
//                    24'b00000001????????????????: leading_zeros = 5'd7;
//                    24'b000000001???????????????: leading_zeros = 5'd8;
//                    24'b0000000001??????????????: leading_zeros = 5'd9;
//                    24'b00000000001?????????????: leading_zeros = 5'd10;
//                    24'b000000000001????????????: leading_zeros = 5'd11;
//                    24'b0000000000001???????????: leading_zeros = 5'd12;
//                    24'b00000000000001??????????: leading_zeros = 5'd13;
//                    24'b000000000000001?????????: leading_zeros = 5'd14;
//                    24'b0000000000000001????????: leading_zeros = 5'd15;
//                    24'b00000000000000001???????: leading_zeros = 5'd16;
//                    24'b000000000000000001??????: leading_zeros = 5'd17;
//                    24'b0000000000000000001?????: leading_zeros = 5'd18;
//                    24'b00000000000000000001????: leading_zeros = 5'd19;
//                    24'b000000000000000000001???: leading_zeros = 5'd20;
//                    24'b0000000000000000000001??: leading_zeros = 5'd21;
//                    24'b00000000000000000000001?: leading_zeros = 5'd22;
//                    24'b000000000000000000000001: leading_zeros = 5'd23;
//                    default: leading_zeros = 5'd24;
//                endcase
//            end
//        end
//    end

//    // Stage 5: Normalization
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            final_exp <= 8'b0;
//            final_mantissa <= 23'b0;
//            valid_pipe[4] <= 1'b0;
//        end else begin
//            valid_pipe[4] <= valid_pipe[3];
//            if (valid_pipe[3]) begin
//                if (sum_mantissa[24]) begin
//                    final_exp <= result_exp + 1;
//                    final_mantissa <= sum_mantissa[23:1];
//                end else if (sum_mantissa == 25'b0) begin
//                    final_exp <= 8'b0;
//                    final_mantissa <= 23'b0;
//                end else begin
//                    final_exp <= result_exp - leading_zeros;
//                    final_mantissa <= sum_mantissa[22:0] << leading_zeros;
//                end
//            end
//        end
//    end

//    // Stage 6: Final result composition
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            Result_reg <= 32'b0;
//            valid_pipe[5] <= 1'b0;
//        end else begin
//            valid_pipe[5] <= valid_pipe[4];
//            if (valid_pipe[4]) begin
//                Result_reg <= {result_sign, final_exp, final_mantissa};
//            end
//        end
//    end

//    assign Result = Result_reg;
//    assign done_o = valid_pipe[5];

//endmodule

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
            A_Exp <= A[30:23];
            C_Exp <= CONST[30:23];
            A_Man <= A[22:0];
            C_Man <= CONST[22:0];
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
            sign <= (comp | magcheck) ? A_sign : (zero ? 1'b0 : C_sign);

            if (zero) begin
                BigExp <= 8'b0;
                SmallExp <= 8'b0;
                BigMan <= 24'b0;
                SmallMan <= 24'b0;
            end else begin
                BigExp <= comp ? A_Exp : C_Exp;
                SmallExp <= comp ? C_Exp : A_Exp;

                BigMan <= {1'b1, (comp | magcheck) ? A_Man : C_Man};
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
            Temp_SmallMan <= SmallMan >> DifferenceExp;
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
            {carry, TempMan} <= check ? (BigMan - Temp_SmallMan) : (BigMan + Temp_SmallMan);
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
                    Exponent <= BigExp + 1;
                end
                else if (|TempMan[22:0]) begin
                    Mantissa <= TempMan[22:0] << zerocount;
                    Exponent <= BigExp - {3'b0, zerocount};
                end else begin
                    Mantissa <= TempMan[22:0];
                    Exponent <= BigExp;
                end
                Sign <= sign;
            end
        end
    end

    // Output assignments
    assign Result = {Sign, Exponent, Mantissa};
    assign done_o = valid_stage6;

endmodule