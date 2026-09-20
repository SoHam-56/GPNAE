`default_nettype wire
`timescale 1ns / 100ps

module gpnae #(
    parameter int DATA_WIDTH    = 32,
    parameter int ADDR_LINES    = 5,
    parameter int CONTROL_WIDTH = 2
) (

    input logic clk_i,
    input logic rstn_i,

    input logic [DATA_WIDTH-1:0] signal_i,
    input logic                  wr_en_i,
    input logic                  last_i,

    input  logic [   ADDR_LINES-1:0] terms_i,
    input  logic [CONTROL_WIDTH-1:0] control_word_i,

    output logic full_o,
    output logic empty_o,
    output logic idle_o,

    output logic [DATA_WIDTH-1:0] final_result_o,
    output logic                  done_o
);

  logic selu_clk, mac_clk, sigtan_clk;
  logic mac_credit_clk;
  assign mac_credit_clk = clk_i;

  logic [DATA_WIDTH-1:0] fifo_data_o;
  logic [DATA_WIDTH-1:0] mac_result;
  logic [DATA_WIDTH-1:0] selu_result;
  logic [DATA_WIDTH-1:0] sigtan_result;

  // SeLu Constants/Mux Signals
  logic [DATA_WIDTH-1:0] selu_input, selu_const;
  localparam logic [DATA_WIDTH-1:0] LAMDA = 32'h3F867D5F;
  localparam logic [DATA_WIDTH-1:0] LAMDA_ALPHA = 32'h3FE10966;  // lambda*alpha

  logic rd_en_signal;
  logic selu_valid, mac_valid;
  logic [1:0] select_sigtan;
  logic mac_rd_en;
  logic done_selu, done_mac, done_sigtan;
  logic update_result;

  logic current_is_positive;
  assign current_is_positive = ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == 'b0);

  gpnae_control_unit #(
      .CONTROL_WIDTH(CONTROL_WIDTH)
  ) u_control_unit (

      .clk_i (clk_i),
      .rstn_i(rstn_i),

      .last_i        (last_i),
      .control_word_i(control_word_i),

      .is_positive_selu_i(captured_is_positive),
      .current_is_positive_i(current_is_positive),
      .mac_rd_en_i       (mac_rd_en),
      .done_selu_i       (done_selu),
      .done_mac_i        (done_mac),
      .done_sigtan_i     (done_sigtan),

      .selu_clk_o  (selu_clk),
      .mac_clk_o   (mac_clk),
      .sigtan_clk_o(sigtan_clk),

      .selu_valid_o   (selu_valid),
      .mac_valid_o    (mac_valid),
      .select_sigtan_o(select_sigtan),
      .fifo_rd_en_o   (rd_en_signal),
      .update_result_o(update_result),
      .capture_data_o (capture_data),
      .done_o         (done_o)
  );

  logic [DATA_WIDTH-1:0] captured_signal;
  logic captured_is_positive;
  logic capture_data;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      captured_signal <= '0;
      captured_is_positive <= 1'b0;
    end else if (capture_data) begin
      captured_signal <= fifo_data_o;
      captured_is_positive <= ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == 'b0);
    end
  end

  // SeLu Input Muxing
  always_comb begin
    if (captured_is_positive) begin
      selu_input = captured_signal;
      selu_const = LAMDA;
    end else begin
      selu_input = mac_result;
      selu_const = LAMDA_ALPHA;
    end
  end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      final_result_o <= 'b0;
    end else if (update_result) begin
      if (control_word_i[1]) final_result_o <= sigtan_result;
      else final_result_o <= selu_result;
    end
  end

  InputFIFO #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES)
  ) input_fifo_inst (
      .clk_i  (clk_i),
      .rstn_i (rstn_i),
      .full_o (full_o),
      .empty_o(empty_o),
      .idle_o (idle_o),
      .wr_en_i(wr_en_i),
      .rd_en_i(rd_en_signal),
      .data_i (signal_i),
      .data_o (fifo_data_o)
  );

  SeLu selu_inst (
      .clk_i(selu_clk),
      .rstn_i(rstn_i),
      .valid_i(selu_valid),
      .is_positive_selu(captured_is_positive),
      .A(selu_input),
      .selu_const(selu_const),
      .Result(selu_result),
      .done_o(done_selu)
  );

  // MAC reads the per-element snapshot: fifo_data_o moves on any pop, mid-recursion.
  logic [DATA_WIDTH-1:0] mac_input;
  always_comb begin
    if (control_word_i == 2'b11) begin
      // TANH requires input to be doubled (2x)
      if (captured_signal[30:23] == 8'h00) begin
        mac_input = {captured_signal[31], 31'b0};
      end else if (captured_signal[30:23] == 8'hFF) begin
        mac_input = captured_signal;
      end else begin
        mac_input = {captured_signal[31], captured_signal[30:23] + 8'd1, captured_signal[22:0]};
      end
    end else begin
      mac_input = captured_signal;
    end
  end

  mac #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES)
  ) mac_inst (
      .clk_i(mac_clk),
      .mac_credit_clk_i(mac_credit_clk),
      .rstn_i(rstn_i),
      .signal_i(mac_input),
      .fifo_wr_i(wr_en_i),
      .rd_signal_o(mac_rd_en),
      .start_i(mac_valid),
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


endmodule

module gpnae_control_unit #(
    parameter int CONTROL_WIDTH = 2
) (

    input logic clk_i,
    input logic rstn_i,

    input logic                     last_i,
    input logic [CONTROL_WIDTH-1:0] control_word_i,

    input logic is_positive_selu_i,
    input logic current_is_positive_i,
    input logic mac_rd_en_i,
    input logic done_selu_i,
    input logic done_mac_i,
    input logic done_sigtan_i,

    output logic selu_clk_o,
    output logic mac_clk_o,
    output logic sigtan_clk_o,

    output logic       selu_valid_o,
    output logic       mac_valid_o,
    output logic [1:0] select_sigtan_o,
    output logic       fifo_rd_en_o,
    output logic       update_result_o,
    output logic       capture_data_o,
    output logic       done_o
);

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

  state_t current_state, next_state;

  logic selu_enable, mac_enable, sigtan_enable;
  logic fsm_rd_en;
  logic [3:0] done_delay;

  assign selu_clk_o   = clk_i & selu_enable;
  assign mac_clk_o    = clk_i & mac_enable;
  assign sigtan_clk_o = clk_i & sigtan_enable;


  always_comb begin
    fsm_rd_en       = 1'b0;
    selu_valid_o    = 1'b0;
    mac_valid_o     = 1'b0;
    capture_data_o  = 1'b0;
    select_sigtan_o = 2'b11;
    next_state      = IDLE;

    case (current_state)
      IDLE: begin
        if (last_i) next_state = WAIT_LAST;
        else next_state = IDLE;
      end

      WAIT_LAST: begin
        next_state = OP;
      end

      OP: begin
        capture_data_o = 1'b1;
        case (control_word_i)
          2'b01: begin
            if (!current_is_positive_i) mac_valid_o = 1'b1;
            next_state = SELU_CHECK;
          end
          2'b10: begin
            mac_valid_o = 1'b1;
            next_state = SIGMOID;
          end
          2'b11: begin
            mac_valid_o = 1'b1;
            next_state = TANH;
          end
          default: next_state = IDLE;
        endcase
      end

      SELU_CHECK: begin
        if (is_positive_selu_i) begin
          selu_valid_o = 1'b1;
          next_state   = SELU_POS;
        end else begin
          next_state = SELU_NEG;
        end
      end

      // Each terminal state pops once, on its own done pulse; done_delay covers the FIFO read latency.
      SELU_POS: begin
        if (done_selu_i) fsm_rd_en = 1'b1;

        if (done_delay[3]) next_state = OP;
        else next_state = SELU_POS;
      end

      SELU_NEG: begin
        if (done_mac_i) selu_valid_o = 1'b1;
        if (done_selu_i) fsm_rd_en = 1'b1;

        if (done_delay[3]) next_state = OP;
        else next_state = SELU_NEG;
      end

      SIGMOID: begin
        select_sigtan_o = 2'b00;
        if (done_sigtan_i) fsm_rd_en = 1'b1;

        if (done_delay[3]) next_state = OP;
        else next_state = SIGMOID;
      end

      TANH: begin
        select_sigtan_o = 2'b01;
        if (done_sigtan_i) fsm_rd_en = 1'b1;

        if (done_delay[3]) next_state = OP;
        else next_state = TANH;
      end

      default: next_state = IDLE;
    endcase
  end


  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      current_state   <= IDLE;
      selu_enable     <= 1'b0;
      mac_enable      <= 1'b0;
      sigtan_enable   <= 1'b0;
      done_delay      <= 4'b0000;
      done_o          <= 1'b0;
      update_result_o <= 1'b0;
    end else begin
      current_state   <= next_state;

      // Default Pulse reset
      update_result_o <= 1'b0;

      case (current_state)
        IDLE: begin
          done_delay    <= 4'b0000;
          done_o        <= 1'b0;
          selu_enable   <= 1'b0;
          mac_enable    <= 1'b0;
          sigtan_enable <= 1'b0;
        end

        WAIT_LAST: begin
          mac_enable <= 1'b1;
          case (control_word_i)
            2'b01: selu_enable <= 1'b1;
            2'b10, 2'b11: sigtan_enable <= 1'b1;
          endcase
        end

        SELU_CHECK: begin
          // MAC is no longer started for positive inputs, so no need to disable it.
        end

        SELU_POS, SELU_NEG: begin
          if (done_selu_i) begin
            update_result_o <= 1'b1;
            done_delay      <= 4'b0001;
          end
        end

        SIGMOID, TANH: begin
          if (done_sigtan_i) begin
            update_result_o <= 1'b1;
            done_delay      <= 4'b0001;
          end
        end
      endcase

      if (|done_delay) begin
        done_delay <= {done_delay[2:0], 1'b0};
      end
      done_o <= done_delay[3];
    end
  end


  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (~rstn_i) begin
      fifo_rd_en_o <= 1'b0;
    end else begin
      // Single owner of the read pointer; the MAC popped too, so elements were popped twice.
      fifo_rd_en_o <= fsm_rd_en;
    end
  end

endmodule
