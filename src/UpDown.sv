//module fp32_up_down (
//    input wire clk_i,
//    input wire rstn_i,
//    input wire valid_i,
//    input wire [31:0] A,
//    output wire [31:0] Result1,  // A + 3f800000
//    output wire [31:0] Result2,  // A + bf800000
//    output wire done_o
//);
//    // Constants
//    localparam [31:0] CONST_1 = 32'h3f800000;
//    localparam [31:0] CONST_2 = 32'hbf800000;

//    // Pipeline stage registers
//    reg [31:0] A_reg;
//    reg valid_pipe [0:5];

//    // Stage 1: Input and component extraction
//    reg a_sign1, b_sign1, a_sign2, b_sign2;
//    reg [7:0] a_exp1, b_exp1, a_exp2, b_exp2;
//    reg [23:0] a_mantissa1, b_mantissa1, a_mantissa2, b_mantissa2;

//    // Stage 2: Exponent comparison and mantissa alignment
//    reg [7:0] exp_diff1, exp_diff2;
//    reg [23:0] aligned_mantissa1, aligned_mantissa2;
//    reg [7:0] result_exp1, result_exp2;
//    reg larger_exp1, larger_exp2;

//    // Stage 3: Addition/Subtraction
//    reg [24:0] sum_mantissa1, sum_mantissa2;
//    reg result_sign1, result_sign2;

//    // Stage 4: Leading zero count
//    reg [4:0] leading_zeros1, leading_zeros2;

//    // Stage 5: Normalization
//    reg [7:0] final_exp1, final_exp2;
//    reg [22:0] final_mantissa1, final_mantissa2;

//    // Stage 6: Final result composition
//    reg [31:0] Result1_reg, Result2_reg;

//    // Stage 1: Input Registration and component extraction
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            A_reg <= 32'b0;
//            valid_pipe[0] <= 1'b0;
//            {a_sign1, a_sign2, b_sign1, b_sign2} <= 4'b0;
//            {a_exp1, a_exp2, b_exp1, b_exp2} <= 32'b0;
//            {a_mantissa1, a_mantissa2, b_mantissa1, b_mantissa2} <= 96'b0;
//        end else begin
//            valid_pipe[0] <= valid_i;
//            if (valid_i) begin
//                A_reg <= A;
//                // For A + CONST_1
//                a_sign1 <= A[31];
//                b_sign1 <= CONST_1[31];
//                a_exp1 <= A[30:23];
//                b_exp1 <= CONST_1[30:23];
//                a_mantissa1 <= {1'b1, A[22:0]};
//                b_mantissa1 <= {1'b1, CONST_1[22:0]};
//                // For A + CONST_2
//                a_sign2 <= A[31];
//                b_sign2 <= CONST_2[31];
//                a_exp2 <= A[30:23];
//                b_exp2 <= CONST_2[30:23];
//                a_mantissa2 <= {1'b1, A[22:0]};
//                b_mantissa2 <= {1'b1, CONST_2[22:0]};
//            end
//        end
//    end

//    // Stage 2: Exponent comparison and mantissa alignment
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            {exp_diff1, exp_diff2, aligned_mantissa1, aligned_mantissa2, result_exp1, result_exp2} <= 72'b0;
//            {larger_exp1, larger_exp2} <= 2'b0;
//            valid_pipe[1] <= 1'b0;
//        end else begin
//            valid_pipe[1] <= valid_pipe[0];
//            if (valid_pipe[0]) begin
//                // For A + CONST_1
//                if (a_exp1 > b_exp1) begin
//                    exp_diff1 <= a_exp1 - b_exp1;
//                    aligned_mantissa1 <= b_mantissa1 >> (a_exp1 - b_exp1);
//                    result_exp1 <= a_exp1;
//                    larger_exp1 <= 1'b1;
//                end else begin
//                    exp_diff1 <= b_exp1 - a_exp1;
//                    aligned_mantissa1 <= a_mantissa1 >> (b_exp1 - a_exp1);
//                    result_exp1 <= b_exp1;
//                    larger_exp1 <= 1'b0;
//                end
//                // For A + CONST_2
//                if (a_exp2 > b_exp2) begin
//                    exp_diff2 <= a_exp2 - b_exp2;
//                    aligned_mantissa2 <= b_mantissa2 >> (a_exp2 - b_exp2);
//                    result_exp2 <= a_exp2;
//                    larger_exp2 <= 1'b1;
//                end else begin
//                    exp_diff2 <= b_exp2 - a_exp2;
//                    aligned_mantissa2 <= a_mantissa2 >> (b_exp2 - a_exp2);
//                    result_exp2 <= b_exp2;
//                    larger_exp2 <= 1'b0;
//                end
//            end
//        end
//    end

//    // Stage 3: Addition/Subtraction
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            {sum_mantissa1, sum_mantissa2} <= 50'b0;
//            {result_sign1, result_sign2} <= 2'b0;
//            valid_pipe[2] <= 1'b0;
//        end else begin
//            valid_pipe[2] <= valid_pipe[1];
//            if (valid_pipe[1]) begin
//                // For A + CONST_1
//                if (a_sign1 == b_sign1) begin
//                    sum_mantissa1 <= (larger_exp1 ? {1'b0, a_mantissa1} : {1'b0, b_mantissa1}) + {1'b0, aligned_mantissa1};
//                    result_sign1 <= a_sign1;
//                end else begin
//                    sum_mantissa1 <= (larger_exp1 ? {1'b0, a_mantissa1} : {1'b0, b_mantissa1}) - {1'b0, aligned_mantissa1};
//                    result_sign1 <= larger_exp1 ? a_sign1 : b_sign1;
//                end
//                // For A + CONST_2
//                if (a_sign2 == b_sign2) begin
//                    sum_mantissa2 <= (larger_exp2 ? {1'b0, a_mantissa2} : {1'b0, b_mantissa2}) + {1'b0, aligned_mantissa2};
//                    result_sign2 <= a_sign2;
//                end else begin
//                    sum_mantissa2 <= (larger_exp2 ? {1'b0, a_mantissa2} : {1'b0, b_mantissa2}) - {1'b0, aligned_mantissa2};
//                    result_sign2 <= larger_exp2 ? a_sign2 : b_sign2;
//                end
//            end
//        end
//    end

//    // Stage 4: Leading zero count
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            {leading_zeros1, leading_zeros2} <= 10'b0;
//            valid_pipe[3] <= 1'b0;
//        end else begin
//            valid_pipe[3] <= valid_pipe[2];
//            if (valid_pipe[2]) begin
//                // For A + CONST_1
//                casez (sum_mantissa1[23:0])
//                    24'b1???????????????????????: leading_zeros1 = 5'd0;
//                    24'b01??????????????????????: leading_zeros1 = 5'd1;
//                    24'b001?????????????????????: leading_zeros1 = 5'd2;
//                    24'b0001????????????????????: leading_zeros1 = 5'd3;
//                    24'b00001???????????????????: leading_zeros1 = 5'd4;
//                    24'b000001??????????????????: leading_zeros1 = 5'd5;
//                    24'b0000001?????????????????: leading_zeros1 = 5'd6;
//                    24'b00000001????????????????: leading_zeros1 = 5'd7;
//                    24'b000000001???????????????: leading_zeros1 = 5'd8;
//                    24'b0000000001??????????????: leading_zeros1 = 5'd9;
//                    24'b00000000001?????????????: leading_zeros1 = 5'd10;
//                    24'b000000000001????????????: leading_zeros1 = 5'd11;
//                    24'b0000000000001???????????: leading_zeros1 = 5'd12;
//                    24'b00000000000001??????????: leading_zeros1 = 5'd13;
//                    24'b000000000000001?????????: leading_zeros1 = 5'd14;
//                    24'b0000000000000001????????: leading_zeros1 = 5'd15;
//                    24'b00000000000000001???????: leading_zeros1 = 5'd16;
//                    24'b000000000000000001??????: leading_zeros1 = 5'd17;
//                    24'b0000000000000000001?????: leading_zeros1 = 5'd18;
//                    24'b00000000000000000001????: leading_zeros1 = 5'd19;
//                    24'b000000000000000000001???: leading_zeros1 = 5'd20;
//                    24'b0000000000000000000001??: leading_zeros1 = 5'd21;
//                    24'b00000000000000000000001?: leading_zeros1 = 5'd22;
//                    24'b000000000000000000000001: leading_zeros1 = 5'd23;
//                    default: leading_zeros1 = 5'd24;
//                endcase

//                // For A + CONST_2
//                casez (sum_mantissa2[23:0])
//                    24'b1???????????????????????: leading_zeros2 = 5'd0;
//                    24'b01??????????????????????: leading_zeros2 = 5'd1;
//                    24'b001?????????????????????: leading_zeros2 = 5'd2;
//                    24'b0001????????????????????: leading_zeros2 = 5'd3;
//                    24'b00001???????????????????: leading_zeros2 = 5'd4;
//                    24'b000001??????????????????: leading_zeros2 = 5'd5;
//                    24'b0000001?????????????????: leading_zeros2 = 5'd6;
//                    24'b00000001????????????????: leading_zeros2 = 5'd7;
//                    24'b000000001???????????????: leading_zeros2 = 5'd8;
//                    24'b0000000001??????????????: leading_zeros2 = 5'd9;
//                    24'b00000000001?????????????: leading_zeros2 = 5'd10;
//                    24'b000000000001????????????: leading_zeros2 = 5'd11;
//                    24'b0000000000001???????????: leading_zeros2 = 5'd12;
//                    24'b00000000000001??????????: leading_zeros2 = 5'd13;
//                    24'b000000000000001?????????: leading_zeros2 = 5'd14;
//                    24'b0000000000000001????????: leading_zeros2 = 5'd15;
//                    24'b00000000000000001???????: leading_zeros2 = 5'd16;
//                    24'b000000000000000001??????: leading_zeros2 = 5'd17;
//                    24'b0000000000000000001?????: leading_zeros2 = 5'd18;
//                    24'b00000000000000000001????: leading_zeros2 = 5'd19;
//                    24'b000000000000000000001???: leading_zeros2 = 5'd20;
//                    24'b0000000000000000000001??: leading_zeros2 = 5'd21;
//                    24'b00000000000000000000001?: leading_zeros2 = 5'd22;
//                    24'b000000000000000000000001: leading_zeros2 = 5'd23;
//                    default: leading_zeros2 = 5'd24;
//                endcase
//            end
//        end
//    end

//    // Stage 5: Normalization
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            {final_exp1, final_exp2} <= 16'b0;
//            {final_mantissa1, final_mantissa2} <= 46'b0;
//            valid_pipe[4] <= 1'b0;
//        end else begin
//            valid_pipe[4] <= valid_pipe[3];
//            if (valid_pipe[3]) begin
//                // For A + CONST_1
//                if (sum_mantissa1[24]) begin
//                    final_exp1 <= result_exp1 + 1;
//                    final_mantissa1 <= sum_mantissa1[23:1];
//                end else if (sum_mantissa1 == 25'b0) begin
//                    final_exp1 <= 8'b0;
//                    final_mantissa1 <= 23'b0;
//                end else begin
//                    final_exp1 <= result_exp1 - leading_zeros1;
//                    final_mantissa1 <= sum_mantissa1[22:0] << leading_zeros1;
//                end

//                // For A + CONST_2
//                if (sum_mantissa2[24]) begin
//                    final_exp2 <= result_exp2 + 1;
//                    final_mantissa2 <= sum_mantissa2[23:1];
//                end else if (sum_mantissa2 == 25'b0) begin
//                    final_exp2 <= 8'b0;
//                    final_mantissa2 <= 23'b0;
//                end else begin
//                    final_exp2 <= result_exp2 - leading_zeros2;
//                    final_mantissa2 <= sum_mantissa2[22:0] << leading_zeros2;
//                end
//            end
//        end
//    end

//    // Stage 6: Final result composition
//    always @(posedge clk_i or negedge rstn_i) begin
//        if (~rstn_i) begin
//            Result1_reg <= 32'b0;
//            Result2_reg <= 32'b0;
//            valid_pipe[5] <= 1'b0;
//        end else begin
//            valid_pipe[5] <= valid_pipe[4];
//            if (valid_pipe[4]) begin
//                Result1_reg <= {result_sign1, final_exp1, final_mantissa1};
//                Result2_reg <= {result_sign2, final_exp2, final_mantissa2};
//            end
//        end
//    end

//    // Output assignments
//    assign Result1 = Result1_reg;
//    assign Result2 = Result2_reg;
//    assign done_o = valid_pipe[5];

//endmodule


module fp32_up_down (
    input wire clk_i,
    input wire rstn_i,
    input wire valid_i,
    input wire [31:0] A,
    output wire [31:0] Result1,
    output wire [31:0] Result2,
    output wire done_o
);
    localparam [31:0] CONST_1 = 32'h3f800000;  // 1.0 in FP32
    localparam [31:0] CONST_2 = 32'hbf800000;  // -1.0 in FP32

    wire [4:0] zerocount1, zerocount2;
    reg Sign1, Sign2;
    reg [7:0] Exponent1, Exponent2;
    reg [22:0] Mantissa1, Mantissa2;

    wire comp1, comp2, magcheck1, magcheck2, zero;
    reg carry1, carry2, check1, check2;
    reg [7:0] BigExp1, BigExp2, SmallExp1, SmallExp2, DifferenceExp1, DifferenceExp2;
    reg [23:0] BigMan1, BigMan2, SmallMan1, SmallMan2;
    reg [23:0] Temp_SmallMan1, Temp_SmallMan2, TempMan1, TempMan2;

    // Control path - valid signal pipeline registers
    reg valid_stage1, valid_stage2, valid_stage3, valid_stage4, valid_stage5, valid_stage6;

    reg A_sign, C1_sign, C2_sign;
    reg sign1, sign2;
    reg [7:0] A_Exp, C1_Exp, C2_Exp;
    reg [22:0] A_Man, C1_Man, C2_Man;

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
            C1_sign <= CONST_1[31];
            C2_sign <= CONST_2[31];
            A_Exp <= A[30:23];
            C1_Exp <= CONST_1[30:23];
            C2_Exp <= CONST_2[30:23];
            A_Man <= A[22:0];
            C1_Man <= CONST_1[22:0];
            C2_Man <= CONST_2[22:0];
        end
    end

    assign comp1 = (A_Exp > C1_Exp) ? 1'b1 : 1'b0;
    assign comp2 = (A_Exp > C2_Exp) ? 1'b1 : 1'b0;
    assign magcheck1 = (A_Exp ^ C1_Exp) ? 1'b0 : ((A_Man > C1_Man) ? 1'b1 : 1'b0);
    assign magcheck2 = (A_Exp ^ C2_Exp) ? 1'b0 : ((A_Man > C2_Man) ? 1'b1 : 1'b0);
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
            check1 <= A_sign ^ C1_sign;
            check2 <= A_sign ^ C2_sign;
            sign1 <= (comp1 | magcheck1) ? A_sign : (zero ? 1'b0 : C1_sign);
            sign2 <= (comp2 | magcheck2) ? A_sign : (zero ? 1'b0 : C2_sign);

            if (zero) begin
                BigExp1 <= 8'b0;
                BigExp2 <= 8'b0;
                SmallExp1 <= 8'b0;
                SmallExp2 <= 8'b0;
                BigMan1 <= 24'b0;
                BigMan2 <= 24'b0;
                SmallMan1 <= 24'b0;
                SmallMan2 <= 24'b0;
            end else begin
                BigExp1 <= comp1 ? A_Exp : C1_Exp;
                BigExp2 <= comp2 ? A_Exp : C2_Exp;
                SmallExp1 <= comp1 ? C1_Exp : A_Exp;
                SmallExp2 <= comp2 ? C2_Exp : A_Exp;

                BigMan1 <= {1'b1, (comp1 | magcheck1) ? A_Man : C1_Man};
                BigMan2 <= {1'b1, (comp2 | magcheck2) ? A_Man : C2_Man};
                SmallMan1 <= {1'b1, (comp1 | magcheck1) ? C1_Man : A_Man};
                SmallMan2 <= {1'b1, (comp2 | magcheck2) ? C2_Man : A_Man};
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
            DifferenceExp1 <= BigExp1 - SmallExp1;
            DifferenceExp2 <= BigExp2 - SmallExp2;
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
            Temp_SmallMan1 <= SmallMan1 >> DifferenceExp1;
            Temp_SmallMan2 <= SmallMan2 >> DifferenceExp2;
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
            {carry1, TempMan1} <= check1 ? (BigMan1 - Temp_SmallMan1) : (BigMan1 + Temp_SmallMan1);
            {carry2, TempMan2} <= check2 ? (BigMan2 - Temp_SmallMan2) : (BigMan2 + Temp_SmallMan2);
        end
    end

    cntlz24 stage_31_1 (
        .i(TempMan1),
        .o(zerocount1)
    );

    cntlz24 stage_31_2 (
        .i(TempMan2),
        .o(zerocount2)
    );

    // Control path - Final Stage valid signal
    always @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            valid_stage6 <= 1'b0;
            Sign1 <= 1'b0;
            Sign2 <= 1'b0;
            Exponent1 <= 8'b0;
            Exponent2 <= 8'b0;
            Mantissa1 <= 23'b0;
            Mantissa2 <= 23'b0;
        end else begin
            valid_stage6 <= valid_stage5;
            if (valid_stage5) begin
                if (carry1) begin
                    Mantissa1 <= TempMan1[23:1];
                    Exponent1 <= BigExp1 + 1;
                end
                else if (|TempMan1[22:0]) begin
                    Mantissa1 <= TempMan1[22:0] << zerocount1;
                    Exponent1 <= BigExp1 - {3'b0, zerocount1};
                end else begin
                    Mantissa1 <= TempMan1[22:0];
                    Exponent1 <= BigExp1;
                end
                Sign1 <= sign1;

                if (carry2) begin
                    Mantissa2 <= TempMan2[23:1];
                    Exponent2 <= BigExp2 + 1;
                end
                else if (|TempMan2[22:0]) begin
                    Mantissa2 <= TempMan2[22:0] << zerocount2;
                    Exponent2 <= BigExp2 - {3'b0, zerocount2};
                end else begin
                    Mantissa2 <= TempMan2[22:0];
                    Exponent2 <= BigExp2;
                end
                Sign2 <= sign2;
            end
        end
    end

    // Output assignments
    assign Result1 = {Sign1, Exponent1, Mantissa1};
    assign Result2 = {Sign2, Exponent2, Mantissa2};
    assign done_o = valid_stage6;

endmodule