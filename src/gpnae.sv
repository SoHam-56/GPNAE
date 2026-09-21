`default_nettype wire
`timescale 1ns / 100ps

// GPNAE lane built on barrel_mac.
//
// The previous per-element lane ran one element at a time, leaving the MAC's pipelined
// units at about 6% utilisation. This version
// pulls a group of up to K elements, runs them through barrel_mac in lockstep, then
// streams the group through the existing SeLu / sigtan post-processing one at a time.
// Each element sees the same arithmetic in the same order, so results are bit-identical.
//
// SELU positives go through the MAC too and their exponential is discarded. It costs
// nothing now the MAC is not the bottleneck, and it removes SELU's data-dependent cost.
module gpnae #(
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

    input  logic [   ADDR_LINES-1:0] terms_i,
    input  logic [CONTROL_WIDTH-1:0] control_word_i,

    output logic full_o,
    output logic empty_o,
    output logic idle_o,

    output logic [DATA_WIDTH-1:0] final_result_o,
    output logic                  done_o
);

  localparam int SW = $clog2(K);
  // data_o trails a pop by three cycles: rd_ptr, then ram_data_b, then doutb_reg.
  localparam int FIFO_RD_LAT = 3;

  localparam logic [DATA_WIDTH-1:0] LAMDA       = 32'h3F867D5F;
  localparam logic [DATA_WIDTH-1:0] LAMDA_ALPHA = 32'h3FE10966;

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
      .count_o(),  // occupancy is only used by the streaming reader in gpnae_poly
      .data_i (signal_i),
      .data_o (fifo_data_o)
  );

  // tanh evaluates e^2x, so the exponent is incremented on the way into the MAC.
  logic [DATA_WIDTH-1:0] mac_in;
  always_comb begin
    if (control_word_i == 2'b11) begin
      if (fifo_data_o[30:23] == 8'h00)      mac_in = {fifo_data_o[31], 31'b0};
      else if (fifo_data_o[30:23] == 8'hFF) mac_in = fifo_data_o;
      else mac_in = {fifo_data_o[31], fifo_data_o[30:23] + 8'd1, fifo_data_o[22:0]};
    end else begin
      mac_in = fifo_data_o;
    end
  end

  logic                  ld_valid, mac_start;
  logic                  mac_res_valid, mac_busy, mac_done;
  logic [DATA_WIDTH-1:0] mac_res;

  barrel_mac #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES),
      .K         (K)
  ) barrel_mac_inst (
      .clk_i      (clk_i),
      .rstn_i     (rstn_i),
      .ld_valid_i (ld_valid),
      .ld_data_i  (mac_in),
      .start_i    (mac_start),
      .terms_i     (terms_i),
      .coeff_base_i(5'd0),
      .res_valid_o(mac_res_valid),
      .res_data_o (mac_res),
      .busy_o     (mac_busy),
      .done_o     (mac_done)
  );

  logic [DATA_WIDTH-1:0] sig_buf [K];   // raw operand, needed by the SELU positive path
  logic                  pos_buf [K];
  logic [DATA_WIDTH-1:0] exp_buf [K];   // the MAC's exponential for that element
  logic [SW:0]           n_elems, ld_idx, rx_idx, post_idx;
  logic [1:0]            wait_cnt;

  logic sig_is_pos;
  assign sig_is_pos = ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == '0);

  logic [DATA_WIDTH-1:0] selu_in, selu_const, selu_res, sigtan_res;
  logic                  post_valid, done_selu, done_sigtan;
  logic                  cur_pos;

  assign cur_pos = pos_buf[post_idx[SW-1:0]];

  always_comb begin
    if (cur_pos) begin
      selu_in    = sig_buf[post_idx[SW-1:0]];
      selu_const = LAMDA;
    end else begin
      selu_in    = exp_buf[post_idx[SW-1:0]];
      selu_const = LAMDA_ALPHA;
    end
  end

  SeLu selu_inst (
      .clk_i           (clk_i),
      .rstn_i          (rstn_i),
      .valid_i         (post_valid && (control_word_i == 2'b01)),
      .is_positive_selu(cur_pos),
      .A               (selu_in),
      .selu_const      (selu_const),
      .Result          (selu_res),
      .done_o          (done_selu)
  );

  sigtan sigtan_inst (
      .clk_i         (clk_i),
      .rstn_i        (rstn_i),
      .valid_i       (post_valid && control_word_i[1]),
      .mac_result    (exp_buf[post_idx[SW-1:0]]),
      .select_sub    (control_word_i == 2'b11 ? 2'b01 : 2'b00),
      .final_result_o(sigtan_res),
      .done_o        (done_sigtan)
  );

  logic post_done;
  assign post_done = (control_word_i == 2'b01) ? done_selu : done_sigtan;

  typedef enum logic [2:0] {
    G_IDLE, G_CAP, G_WAIT, G_RUN, G_RECV, G_POST_START, G_POST_WAIT, G_NEXT
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
      post_valid     <= 1'b0;
      done_o         <= 1'b0;
      final_result_o <= '0;
    end else begin
      ld_valid   <= 1'b0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      post_valid <= 1'b0;
      done_o     <= 1'b0;

      case (gstate)
        G_IDLE: begin
          ld_idx <= '0;
          if (last_i) gstate <= G_CAP;
        end

        // Capture the head, hand it to the MAC, pop, then let the FIFO catch up.
        G_CAP: begin
          if (!empty_o && (ld_idx < K[SW:0])) begin
            sig_buf[ld_idx[SW-1:0]] <= fifo_data_o;
            pos_buf[ld_idx[SW-1:0]] <= sig_is_pos;
            ld_valid                <= 1'b1;
            fifo_rd_en              <= 1'b1;
            ld_idx                  <= ld_idx + 1;
            wait_cnt                <= '0;
            gstate                  <= G_WAIT;
          end else if (ld_idx != '0) begin
            n_elems   <= ld_idx;
            mac_start <= 1'b1;
            rx_idx    <= '0;
            gstate    <= G_RUN;
          end else begin
            gstate <= G_IDLE;
          end
        end

        G_WAIT: begin
          if (wait_cnt == FIFO_RD_LAT[1:0]) gstate <= G_CAP;
          else wait_cnt <= wait_cnt + 1;
        end

        G_RUN: begin
          if (mac_res_valid) begin
            exp_buf[rx_idx[SW-1:0]] <= mac_res;
            rx_idx                  <= rx_idx + 1;
            gstate                  <= G_RECV;
          end
        end

        // Collect the group's exponentials as the MAC streams them out.
        G_RECV: begin
          if (mac_res_valid) begin
            exp_buf[rx_idx[SW-1:0]] <= mac_res;
            rx_idx                  <= rx_idx + 1;
          end
          if (mac_done) begin
            post_idx <= '0;
            gstate   <= G_POST_START;
          end
        end

        G_POST_START: begin
          post_valid <= 1'b1;
          gstate     <= G_POST_WAIT;
        end

        G_POST_WAIT: begin
          if (post_done) begin
            final_result_o <= control_word_i[1] ? sigtan_res : selu_res;
            done_o         <= 1'b1;
            if (post_idx + 1 == n_elems) begin
              gstate <= G_NEXT;
            end else begin
              post_idx <= post_idx + 1;
              gstate   <= G_POST_START;
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
