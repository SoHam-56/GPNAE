`timescale 1ns / 100ps

module sigtan (
    input wire          clk_i,
    input wire          rstn_i,
    input wire          valid_i,
    input wire [31:0]   mac_result,
    input wire [1:0]    select_sub,
    output wire [31:0]  final_result_o,
    output wire         done_o
);

    wire [31:0] add_result, sub_result;
    wire done_fp32_add_sub;
    wire [31:0] mux_output;
    reg [31:0] mux_output_reg;

    // Instantiate FP32 Add/Sub module
    fp32_up_down fp32_add_sub_inst (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .valid_i(valid_i),
        .A(mac_result),
        .Result1(add_result),
        .Result2(sub_result),
        .done_o(done_fp32_add_sub)
    );

    // Mux to switch between sub_result and mac_result
    assign mux_output = (select_sub == 2'b00) ? mac_result : 'bz;  // SIGMOID case
    assign mux_output = (select_sub == 2'b01) ? sub_result : 'bz;  // TANH case
//    always_ff @(posedge clk_i or negedge rstn_i) begin
//        if (!rstn_i) begin
//            mux_output_reg <= '0; // Reset value
//        end else begin
//            case (select_sub)
//                2'b00: mux_output_reg <= mac_result;  // SIGMOID case
//                2'b01: mux_output_reg <= sub_result;  // TANH case
//                default: mux_output_reg <= mux_output_reg; // Hold previous value
//            endcase
//        end
//    end
    
//    assign mux_output = mux_output_reg;

    divide_32 u_divide_32 (
        .clk_i    (clk_i),
        .rstn_i   (rstn_i),
        .valid_i  (done_fp32_add_sub),
        .A        (mux_output),
        .B        (add_result),
        .Result   (final_result_o),
        .done_o   (done_o)
    );

endmodule
