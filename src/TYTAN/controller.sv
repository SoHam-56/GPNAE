`timescale 1ns / 100ps

module controller #(
    parameter int ADDR_LINES = 5
) (
    // Clock and reset
    input logic clk_i,
    input logic mac_credit_clk_i,
    input logic rstn_i,

    // Control inputs
    input logic                  fifo_wr_i,  // NEW: Connect to the FIFO's write enable signal
    input logic                  start_i,    // last_i from top (Stop condition)
    input logic                  empty_i,    // FIFO empty status (kept for safety/backup)
    input logic [ADDR_LINES-1:0] terms_i,    // Number of terms to process

    // Datapath handshaking
    input  logic mul_done_i,
    input  logic add_done_i,
    output logic mul_valid_i,
    output logic add_valid_i,
    output logic dp_reset_o,

    // Memory interface
    output logic                  rd_signal_o,
    output logic                  rd_coeff_o,
    output logic                  load_result_o,
    output logic [ADDR_LINES-1:0] coeff_addr_o,

    // Status outputs
    output logic done_o
);

  // State encoding
  typedef enum logic [3:0] {
    IDLE,
    RESET_DATAPATH,
    LOAD_SIGNAL,
    LOAD_COEFF,
    MULTIPLY,
    WAIT_MUL,
    ADD,
    WAIT_ADD,
    CHECK_TERMS,
    STORE_RESULT
  } state_t;

  logic reload_o;
  state_t current_state, next_state;

  // Term counter
  logic [ADDR_LINES-1:0] term_count;
  logic [ADDR_LINES-1:0] term_count_next;

  // Done signal logic
  logic done_comb;
  logic [4:0] done_shift_reg;

  // ---------------------------------------------------------
  // NEW: Credit Counter Logic
  // ---------------------------------------------------------
  // Width is ADDR_LINES + 1 to prevent overflow if FIFO is fully packed
  logic [ADDR_LINES:0] item_credit_count;

  always_ff @(posedge mac_credit_clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      item_credit_count <= '0;
    end else begin
      // Decrement logic: Happens exactly when we decide to read from FIFO
      logic dec_en;
      dec_en = (current_state == LOAD_SIGNAL);

      case ({
        fifo_wr_i, dec_en
      })
        2'b10:   item_credit_count <= item_credit_count + 1'b1;
        2'b01:   item_credit_count <= item_credit_count - 1'b1;
        default: item_credit_count <= item_credit_count;
      endcase
    end
  end
  // ---------------------------------------------------------

  // State register
  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      current_state <= IDLE;
      term_count <= '0;
      done_shift_reg <= 5'b0;
    end else begin
      current_state <= next_state;
      term_count <= term_count_next;
      done_shift_reg <= {done_shift_reg[3:0], done_comb};
    end
  end

  assign done_o = done_shift_reg[4];

  // Coefficient address generation
  always_comb begin
    if (!rstn_i || reload_o) begin
      coeff_addr_o = terms_i - 1;
    end else begin
      coeff_addr_o = terms_i - 1 - term_count;
    end
  end

  // Next state and output logic
  always_comb begin
    next_state = current_state;
    term_count_next = term_count;
    mul_valid_i = 1'b0;
    add_valid_i = 1'b0;
    rd_signal_o = 1'b0;
    rd_coeff_o = 1'b0;
    reload_o = 1'b0;
    load_result_o = 1'b0;
    dp_reset_o = 1'b0;
    done_comb = 1'b0;

    case (current_state)
      IDLE: begin
        term_count_next = '0;
        reload_o = 1'b1;

        // Only start if we have credits (data waiting) AND not stopped by start_i
        // (Assuming start_i is acting as a "Last" or "Stop" signal based on previous context)
        if (item_credit_count > 0 && !start_i) begin
          next_state = RESET_DATAPATH;
        end
      end

      RESET_DATAPATH: begin
        dp_reset_o = 1'b1;
        next_state = LOAD_SIGNAL;
      end

      LOAD_SIGNAL: begin
        rd_signal_o = 1'b1;  // This triggers the credit decrement
        next_state  = LOAD_COEFF;
      end

      LOAD_COEFF: begin
        rd_coeff_o = 1'b1;
        next_state = MULTIPLY;
      end

      MULTIPLY: begin
        mul_valid_i = 1'b1;
        next_state  = WAIT_MUL;
      end

      WAIT_MUL: begin
        if (mul_done_i) begin
          next_state = ADD;
        end
      end

      ADD: begin
        add_valid_i = 1'b1;
        next_state  = WAIT_ADD;
      end

      WAIT_ADD: begin
        if (add_done_i) begin
          next_state = CHECK_TERMS;
        end
      end

      CHECK_TERMS: begin
        if (term_count < terms_i - 1) begin
          term_count_next = term_count + 1'b1;
          next_state = LOAD_COEFF;
        end else begin
          next_state = STORE_RESULT;
        end
      end

      STORE_RESULT: begin
        load_result_o = 1'b1;

        // If 'start_i' (last_i) is high, we force stop.
        if (start_i) begin
          next_state = IDLE;
          done_comb  = 1'b1;

          // REPLACED !empty_i WITH item_credit_count CHECK
        end else if (item_credit_count > 0) begin
          reload_o = 1'b1;
          term_count_next = '0;
          done_comb = 1'b1;
          next_state = RESET_DATAPATH;

        end else begin
          // No credits left, go to IDLE
          next_state = IDLE;
          done_comb  = 1'b1;
        end
      end

      default: begin
        next_state = IDLE;
      end
    endcase
  end

endmodule

