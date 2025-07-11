`default_nettype wire
`timescale 1ns / 100ps

module gpnae #(
    parameter int DATA_WIDTH    = 32,
    parameter int ADDR_LINES    = 5,
    parameter int CONTROL_WIDTH = 2
) (
    // Clock and reset
    input  logic                        clk_i,
    input  logic                        rstn_i,
    // Signal input interface
    input  logic [DATA_WIDTH-1:0]       signal_i,
    input  logic                        wr_en_i,
    input  logic                        last_i,
    // Configuration
    input  logic [ADDR_LINES-1:0]       terms_i,
    input  logic [CONTROL_WIDTH-1:0]    control_word_i,
    // Status outputs
    output logic                        full_o,
    output logic                        empty_o,
    output logic                        idle_o,
    // Final output
    output logic [DATA_WIDTH-1:0]       final_result_o,
    output logic                        done_o
);

    // FSM states
    typedef enum logic [2:0] {
        IDLE,
        WAIT_LAST,
        OP,
        SELU_CHECK,
        SELU_POS,
        SELU_NEG,
        SIGMOID,
        TANH
    } state_t;

    // State registers
    state_t current_state, next_state;

    // Internal signals
    logic rd_en_signal, fsm_rd_en, mac_rd_en;
    logic [DATA_WIDTH-1:0] fifo_data_o, selu_result, mac_result, sigtan_result;
    logic done_selu, done_mac, done_sigtan;
    logic selu_enable, mac_enable, sigtan_enable;
    logic selu_clk, mac_clk, sigtan_clk;
    logic [1:0] select_sigtan;
    logic selu_valid, mac_valid;
    logic [2:0] done_delay;
    
    // Pipeline registers for FIFO data
    logic [DATA_WIDTH-1:0] fifo_data_registered;
    logic is_positive_selu;

    localparam logic [DATA_WIDTH-1:0] lamda = 32'h3F867D5F, lamda_alpha = 32'h3FD62D7D;    
    logic [DATA_WIDTH-1:0] selu_input, selu_const;

    // Register FIFO data and compute is_positive_selu
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            fifo_data_registered <= '0;
            is_positive_selu <= 1'b0;
        end else begin
            if (rd_en_signal) begin
                fifo_data_registered <= fifo_data_o;
                is_positive_selu <= ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == 'b0);
            end
        end
    end
    
//    assign is_positive_selu = ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == 'b0);
    
    // Clock gating
    assign selu_clk = clk_i & selu_enable;
    assign mac_clk = clk_i & mac_enable;
    assign sigtan_clk = clk_i & sigtan_enable;

    // Mux for selu_input and selu_const
    always_comb begin
        if (is_positive_selu) begin
            selu_input = fifo_data_registered;  // Use registered data
            selu_const = lamda;
        end else begin
            selu_input = mac_result;
            selu_const = lamda_alpha;
        end
    end

    // Input FIFO (always enabled)
    InputFIFO #(
        .DATA_WIDTH  (DATA_WIDTH),
        .ADDR_LINES  (ADDR_LINES)
    ) input_fifo_inst (
        .clk_i      (clk_i),
        .rstn_i     (rstn_i),
        .full_o     (full_o),
        .empty_o    (empty_o),
        .idle_o     (idle_o),
        .wr_en_i    (wr_en_i),
        .rd_en_i    (rd_en_signal),
        .data_i     (signal_i),
        .data_o     (fifo_data_o)
    );
    
    SeLu selu_inst (
        .clk_i(selu_clk),
        .rstn_i(rstn_i),
        .valid_i(selu_valid),
        .is_positive_selu(is_positive_selu),
        .A(selu_input),
        .selu_const(selu_const),
        .Result(selu_result),
        .done_o(done_selu)
    );
    
    mac #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_LINES(ADDR_LINES)
    ) mac_inst (
        .clk_i(mac_clk),
        .rstn_i(rstn_i),
        .signal_i(fifo_data_o),
        .rd_signal_o(mac_rd_en),
        .last_i(mac_valid),
        .terms_i(terms_i),
        .empty_i(empty_o),
        .result_o(mac_result),
        .done_o(done_mac)
    );

    sigtan sigtan_inst (
        .clk_i(sigtan_clk),
        .rstn_i(rstn_i),
        .valid_i(done_mac),
        .mac_result(mac_result),
        .select_sub(select_sigtan),
        .final_result_o(sigtan_result),
        .done_o(done_sigtan)
    );

    // Rest of the state machine logic remains the same
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            current_state <= IDLE;
            final_result_o <= 'b0;
            
            // Clock Gates
            selu_enable <= 1'b0;
            mac_enable <= 1'b0;
            sigtan_enable <= 1'b0;
            
            done_delay <= 3'b000;
            done_o <= 1'b0;
        end else begin
            current_state <= next_state;
    
            case (current_state)
                IDLE: begin
                    done_delay <= 3'b000;
                    done_o <= 1'b0;
                    
                    selu_enable <= 1'b0;
                    mac_enable <= 1'b0;
                    sigtan_enable <= 1'b0;
                end
                
                WAIT_LAST: begin
                    mac_enable <= 1'b1;
                    case (control_word_i)
                        2'b01: begin
                            selu_enable <= 1'b1;
                        end
                        2'b10, 2'b11: begin     // SIGMOID and TANH
                            sigtan_enable <= 1'b1;
                        end
                    endcase 
                end
                
                SELU_CHECK: begin
                    if (is_positive_selu) begin
                        mac_enable <= 1'b0;
                    end
                end
                
                SELU_POS: begin
//                    mac_enable <= 1'b0;
                    if (done_selu) begin
                        final_result_o <= selu_result;
                        done_delay <= 3'b001;
                    end
                end
                
                SELU_NEG: begin
                    if (done_selu) begin
                        final_result_o <= selu_result;
                        done_delay <= 3'b001;
                    end
                end
    
                SIGMOID, TANH: begin
                    if (done_sigtan) begin
                        final_result_o <= sigtan_result;
                        done_delay <= 3'b001;
                    end
                end
                
            endcase
    
            if (|done_delay) begin
                done_delay <= {done_delay[1:0], 1'b0};
            end
    
            done_o <= done_delay[2];
        end
    end

    always_comb begin
        fsm_rd_en = 1'b0;
        selu_valid = 1'b0;
        mac_valid = 1'b0;
        select_sigtan = 2'b11;
        next_state = IDLE;

        case (current_state)
            IDLE: begin
                if (last_i) begin
                    next_state = WAIT_LAST;
                end else begin
                    next_state = IDLE;
                end
            end

            WAIT_LAST: begin
//                mac_valid = 1'b1;
                next_state = OP;
            end
            
            OP: begin
               mac_valid = 1'b1;
                case (control_word_i)
                     2'b01: next_state = SELU_CHECK;
                     2'b10: next_state = SIGMOID;
                     2'b11: next_state = TANH;
                    default: next_state = IDLE;
                endcase                    
            end
            
            SELU_CHECK: begin
                if (is_positive_selu) begin
                    selu_valid = 1'b1;
                    next_state = SELU_POS;
                end else begin
                    next_state = SELU_NEG;
                end
            end
            
            SELU_POS: begin
                if (done_selu) begin 
                    fsm_rd_en = 1'b1;
                end
                
                if (done_delay[2]) begin
//                    fsm_rd_en = 1'b1;
                    next_state = OP;
                end 

            end
            
            SELU_NEG: begin
                if (done_mac) begin 
                    selu_valid = 1'b1;
                end
                
                if (done_delay[2]) begin
                    next_state = OP;
                end else begin
                    next_state = SELU_NEG;
                end
            end
            
            SIGMOID: begin                
                select_sigtan = 2'b00;
                    
                if (done_delay[2]) begin
                    next_state = OP;
                end else begin
                    next_state = SIGMOID;
                end
            end

            TANH: begin
                select_sigtan = 2'b01;
                
                if (done_delay[2]) begin
                    next_state = OP;
                end else begin
                    next_state = TANH;
                end
            end

            default: next_state = IDLE;
        endcase
    end

    // Synchronous read enable signal
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            rd_en_signal <= 1'b0;
        end else begin
            rd_en_signal <= ((current_state == SELU_POS) && is_positive_selu) ? fsm_rd_en : mac_rd_en;
        end
    end
//    assign rd_en_signal = ((current_state == SELU_POS) && is_positive_selu) ? fsm_rd_en : mac_rd_en;
endmodule
