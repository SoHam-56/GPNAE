`default_nettype wire
`timescale 1ns / 100ps

// GPNAE lane that evaluates each activation as a polynomial in x directly, instead of
// computing e^x and reshaping it. Same barrel MAC, different coefficient table.
//
// The engine approximates the target function itself rather than always computing e^x and
// then reshaping it. Only the coefficients differ per activation, so the divider, the +/-1
// adders and the per-function mux tree are all gone. Adding an activation means adding a
// coefficient set, not hardware.
//
//   SELU     x >= 0  lambda * x
//            x <  0  x * P_selu(x)      P approximates lambda*alpha*(e^x - 1)/x
//   sigmoid  x >= 0  P_sig(|x|)
//            x <  0  1 - P_sig(|x|)     computed as -(P - 1), a sign flip on fp32_down
//   tanh             x * P_tanh(x^2)    P approximates tanh(sqrt u)/sqrt u
//
// Elements run in groups of K so the MAC's pipelined units stay busy; see barrel_mac.sv.
module gpnae_poly #(
    parameter int DATA_WIDTH    = 32,
    parameter int ADDR_LINES    = 5,
    parameter int CONTROL_WIDTH = 2,
    parameter int K             = 16
) (
    input logic clk_i,
    input logic rstn_i,

    input logic [DATA_WIDTH-1:0] signal_i,
    input logic                  wr_en_i,
    input logic                  last_i,

    input  logic [   ADDR_LINES-1:0] terms_i,         // unused: degree comes from the table
    input  logic [CONTROL_WIDTH-1:0] control_word_i,

    output logic full_o,
    output logic empty_o,
    output logic idle_o,

    output logic [DATA_WIDTH-1:0] final_result_o,
    output logic                  done_o
);

  localparam int SW = $clog2(K);
  localparam int FIFO_RD_LAT = 3;  // data_o trails a pop: rd_ptr, ram_data_b, doutb_reg

  localparam logic [DATA_WIDTH-1:0] LAMDA = 32'h3F867D5F;

  // Coefficient sets packed into one ROM. Keep in step with poly_coeffs.mem.
  localparam logic [ADDR_LINES-1:0] BASE_SELU = 5'd0,  DEG_SELU = 5'd8;
  localparam logic [ADDR_LINES-1:0] BASE_SIG  = 5'd9,  DEG_SIG  = 5'd6;
  localparam logic [ADDR_LINES-1:0] BASE_TANH = 5'd16, DEG_TANH = 5'd8;

  logic [DATA_WIDTH-1:0] fifo_data_o;
  logic                  fifo_rd_en;

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
      .rd_en_i(fifo_rd_en),
      .data_i (signal_i),
      .data_o (fifo_data_o)
  );

  logic [ADDR_LINES-1:0] poly_base, poly_deg;
  always_comb begin
    case (control_word_i)
      2'b01:   begin poly_base = BASE_SELU; poly_deg = DEG_SELU; end
      2'b10:   begin poly_base = BASE_SIG;  poly_deg = DEG_SIG;  end
      default: begin poly_base = BASE_TANH; poly_deg = DEG_TANH; end
    endcase
  end

  // Polynomial variable: |x| for sigmoid, x*x for tanh, x as it stands for SELU.
  logic [DATA_WIDTH-1:0] sq_a, sq_res, mac_in;
  logic                  sq_valid, sq_done;

  fp32Multiplier SQ (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(sq_valid),
      .A(sq_a), .B(sq_a), .result_o(sq_res), .done_o(sq_done),
      .overflow_o(), .underflow_o(), .invalid_o()
  );

  logic                  ld_valid, mac_start;
  logic                  mac_res_valid, mac_busy, mac_done;
  logic [DATA_WIDTH-1:0] mac_res;

  barrel_mac #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES),
      .K         (K),
      .INIT_FILE ("poly_coeffs.mem")
  ) barrel_mac_inst (
      .clk_i       (clk_i),
      .rstn_i      (rstn_i),
      .ld_valid_i  (ld_valid),
      .ld_data_i   (mac_in),
      .start_i     (mac_start),
      .terms_i     (poly_deg),
      .coeff_base_i(poly_base),
      .res_valid_o (mac_res_valid),
      .res_data_o  (mac_res),
      .busy_o      (mac_busy),
      .done_o      (mac_done)
  );

  logic [DATA_WIDTH-1:0] sig_buf [K];
  logic                  pos_buf [K];
  logic [DATA_WIDTH-1:0] pol_buf [K];
  logic [SW:0]           n_elems, ld_idx, rx_idx, post_idx;
  logic [1:0]            wait_cnt;

  logic sig_is_pos;
  assign sig_is_pos = ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == '0);

  // Post stage: one multiply, or fp32_down plus a sign flip. No divider.
  logic [DATA_WIDTH-1:0] mul_a, mul_b, mul_res, dn_a, dn_res;
  logic                  mul_valid, mul_done, dn_valid, dn_done;

  fp32Multiplier POST (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(mul_valid),
      .A(mul_a), .B(mul_b), .result_o(mul_res), .done_o(mul_done),
      .overflow_o(), .underflow_o(), .invalid_o()
  );

  fp32_down POSTD (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(dn_valid),
      .A(dn_a), .Result(dn_res), .done_o(dn_done)
  );

  logic cur_pos;
  logic [DATA_WIDTH-1:0] cur_x, cur_p;
  assign cur_pos = pos_buf[post_idx[SW-1:0]];
  assign cur_x   = sig_buf[post_idx[SW-1:0]];
  assign cur_p   = pol_buf[post_idx[SW-1:0]];

  // sigmoid on a non-negative input needs no post-processing at all.
  logic post_passthru;
  assign post_passthru = (control_word_i == 2'b10) && cur_pos;

  typedef enum logic [3:0] {
    G_IDLE, G_CAP, G_WAIT, G_SQ, G_SQW, G_RUN, G_RECV, G_POST, G_POSTW, G_NEXT
  } gstate_t;
  gstate_t gstate;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      gstate         <= G_IDLE;
      n_elems        <= '0;
      ld_idx         <= '0;
      rx_idx         <= '0;
      post_idx       <= '0;
      wait_cnt       <= '0;
      ld_valid       <= 1'b0;
      mac_start      <= 1'b0;
      fifo_rd_en     <= 1'b0;
      sq_valid       <= 1'b0;
      mul_valid      <= 1'b0;
      dn_valid       <= 1'b0;
      done_o         <= 1'b0;
      final_result_o <= '0;
    end else begin
      ld_valid   <= 1'b0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      sq_valid   <= 1'b0;
      mul_valid  <= 1'b0;
      dn_valid   <= 1'b0;
      done_o     <= 1'b0;

      case (gstate)
        G_IDLE: begin
          ld_idx <= '0;
          if (last_i) gstate <= G_CAP;
        end

        G_CAP: begin
          if (!empty_o && (ld_idx < K[SW:0])) begin
            sig_buf[ld_idx[SW-1:0]] <= fifo_data_o;
            pos_buf[ld_idx[SW-1:0]] <= sig_is_pos;
            fifo_rd_en              <= 1'b1;
            if (control_word_i == 2'b11) begin
              sq_a     <= fifo_data_o;  // tanh works in x^2
              sq_valid <= 1'b1;
              gstate   <= G_SQ;
            end else begin
              mac_in   <= (control_word_i == 2'b10)
                          ? {1'b0, fifo_data_o[DATA_WIDTH-2:0]}  // sigmoid uses |x|
                          : fifo_data_o;
              ld_valid <= 1'b1;
              ld_idx   <= ld_idx + 1;
              wait_cnt <= '0;
              gstate   <= G_WAIT;
            end
          end else if (ld_idx != '0) begin
            n_elems   <= ld_idx;
            mac_start <= 1'b1;
            rx_idx    <= '0;
            gstate    <= G_RUN;
          end else begin
            gstate <= G_IDLE;
          end
        end

        G_SQ: gstate <= G_SQW;

        G_SQW: begin
          if (sq_done) begin
            mac_in   <= sq_res;
            ld_valid <= 1'b1;
            ld_idx   <= ld_idx + 1;
            wait_cnt <= '0;
            gstate   <= G_WAIT;
          end
        end

        G_WAIT: begin
          if (wait_cnt == FIFO_RD_LAT[1:0]) gstate <= G_CAP;
          else wait_cnt <= wait_cnt + 1;
        end

        G_RUN: begin
          if (mac_res_valid) begin
            pol_buf[rx_idx[SW-1:0]] <= mac_res;
            rx_idx                  <= rx_idx + 1;
            gstate                  <= G_RECV;
          end
        end

        G_RECV: begin
          if (mac_res_valid) begin
            pol_buf[rx_idx[SW-1:0]] <= mac_res;
            rx_idx                  <= rx_idx + 1;
          end
          if (mac_done) begin
            post_idx <= '0;
            gstate   <= G_POST;
          end
        end

        G_POST: begin
          if (post_passthru) begin
            gstate <= G_POSTW;  // the polynomial is already the answer
          end else if (control_word_i == 2'b10) begin
            dn_a     <= cur_p;  // sigmoid, x < 0: 1 - P computed as -(P - 1)
            dn_valid <= 1'b1;
            gstate   <= G_POSTW;
          end else begin
            mul_a     <= cur_x;  // SELU x<0 and tanh: x * P; SELU x>=0: lambda * x
            mul_b     <= (control_word_i == 2'b01 && cur_pos) ? LAMDA : cur_p;
            mul_valid <= 1'b1;
            gstate    <= G_POSTW;
          end
        end

        G_POSTW: begin
          if (post_passthru || mul_done || dn_done) begin
            if (post_passthru) final_result_o <= cur_p;
            else if (control_word_i == 2'b10)
              final_result_o <= {~dn_res[DATA_WIDTH-1], dn_res[DATA_WIDTH-2:0]};
            else final_result_o <= mul_res;
            done_o <= 1'b1;
            if (post_idx + 1 == n_elems) begin
              gstate <= G_NEXT;
            end else begin
              post_idx <= post_idx + 1;
              gstate   <= G_POST;
            end
          end
        end

        G_NEXT: begin
          ld_idx <= '0;
          gstate <= empty_o ? G_IDLE : G_CAP;
        end

        default: gstate <= G_IDLE;
      endcase
    end
  end

endmodule
