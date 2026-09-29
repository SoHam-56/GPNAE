`default_nettype wire
`timescale 1ns / 100ps

// int8 GPNAE lane (gpnae_poly's G_INT8 branch): the float lane's forms on fxMac (Q4.11) and integer products, int8 out; no gpnae_tail.
module gpnae_poly_int8 #(
    parameter int DATA_WIDTH    = 8,
    parameter int ADDR_LINES    = 5,
    parameter int CONTROL_WIDTH = 3,  // 001 SELU, 010 sigmoid, 011 tanh, 100 ReLU, 101 linear
    parameter int K             = 16
) (
    input logic clk_i,
    input logic rstn_i,

    input logic [DATA_WIDTH-1:0] signal_i,
    input logic                  wr_en_i,
    input logic                  last_i,

    input logic [   ADDR_LINES-1:0] terms_i,         // unused: degree comes from the table
    input logic [CONTROL_WIDTH-1:0] control_word_i,

    input logic [15:0] gp_mx_i,     // input rescale: x = round((q - z_in) * mx / 2^shx) in Q4.11, mx below 2^15
    input logic [ 4:0] gp_shx_i,
    input logic [ 7:0] gp_zin_i,    // input zero point
    input logic [31:0] gp_mout_i,   // SELU output: TFLite multiplier and shift of 2^-25 / s_out
    input logic [ 7:0] gp_shout_i,
    input logic [ 7:0] gp_zout_i,   // SELU output zero point

    output logic full_o,
    output logic empty_o,
    output logic idle_o,

    output logic [DATA_WIDTH-1:0] final_result_o,
    output logic                  done_o
);

  localparam int SW = $clog2(K);
  localparam int CAP_LAG = 3;  // as gpnae_poly: a pop's word appears three cycles later
  localparam int W = 16;  // Q4.11
  localparam int MUL_LAT = sienna_fmt_pkg::mul_lat(0, 7);  // intMultiplier
  localparam int FX_LAT = sienna_fmt_pkg::fx_lat();  // fxMac: the tanh squarer
  localparam int RQ_LAT = sienna_fmt_pkg::req_lat();  // tfliteRequant
  localparam int PS_LAT = MUL_LAT + RQ_LAT;  // SELU post stage: multiply, then requantize

  localparam logic signed [W-1:0] T_SELU = -16'sd8192;  // saturation in Q4.11, the float lane's thresholds: SELU x < -4
  localparam logic signed [W-1:0] T_SIG = 16'sd7168;  // sigmoid |x| > 3.5
  localparam logic signed [W-1:0] T_TANH = 16'sd8192;  // tanh |x| > 4
  localparam logic signed [W-1:0] SELU_SAT = -16'sd3601;  // -lambda*alpha in Q4.11
  localparam logic signed [W-1:0] ONE_Q11 = 16'sd2048;  // 1.0 in Q4.11
  localparam logic signed [W-1:0] LAMBDA_Q14 = 16'sd17215;  // lambda in Q1.14

  // Coefficient sets: gpnae_model.SETS_INT8 from Task 10's fit.
  localparam logic [ADDR_LINES-1:0] BASE_SELU = 5'd0, DEG_SELU = 5'd2;
  localparam logic [ADDR_LINES-1:0] BASE_SIG = 5'd9, DEG_SIG = 5'd3;
  localparam logic [ADDR_LINES-1:0] BASE_TANH = 5'd16, DEG_TANH = 5'd3;

  if (DATA_WIDTH != 8) begin : G_BAD_WIDTH
    $fatal(1, "gpnae_poly_int8: DATA_WIDTH must be 8, not %0d", DATA_WIDTH);
  end

  // Input rescale: (q - z_in) * mx rounded half up by 2^s, saturated to Q4.11.
  function automatic logic [W-1:0] rescale(input logic [31:0] p, input logic [4:0] s);
    logic signed [39:0] pw, r;
    pw = {{8{p[31]}}, p};
    r  = (s == 5'd0) ? pw : ((pw + (40'sd1 <<< (s - 5'd1))) >>> s);
    if (r > 40'sd32767) return 16'h7FFF;
    if (r < -40'sd32768) return 16'h8000;
    return r[W-1:0];
  endfunction

  // |x|, saturated: sigmoid's MAC operand.
  function automatic logic [W-1:0] abs_sat(input logic [W-1:0] x);
    if (x == 16'h8000) return 16'h7FFF;
    return x[W-1] ? -x : x;
  endfunction

  // sigmoid output: round(256 y) - 128 = ((y + 4) >> 3) - 128 for y in Q4.11, clamped to int8.
  function automatic logic [7:0] quant_sig(input logic signed [W:0] y);
    logic signed [W:0] r;
    r = ((y + 17'sd4) >>> 3) - 17'sd128;
    if (r > 17'sd127) return 8'h7F;
    if (r < -17'sd128) return 8'h80;
    return r[7:0];
  endfunction

  // tanh output from x * P in units of 2^-22: round(128 y) = (p + 2^14) >> 15, clamped to int8.
  function automatic logic [7:0] quant_tanh(input logic [31:0] p);
    logic signed [32:0] r;
    r = ($signed({p[31], p}) + 33'sd16384) >>> 15;
    if (r > 33'sd127) return 8'h7F;
    if (r < -33'sd128) return 8'h80;
    return r[7:0];
  endfunction

  logic [DATA_WIDTH-1:0] fifo_data_o;
  logic                  fifo_rd_en;
  logic [ADDR_LINES:0]   fifo_count;

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
      .count_o(fifo_count),
      .data_i (signal_i),
      .data_o (fifo_data_o)
  );

  logic is_selu, is_sig, is_byp, is_tanh;
  assign is_selu = (control_word_i == 3'b001);
  assign is_sig  = (control_word_i == 3'b010);
  assign is_byp  = (control_word_i == 3'b100) || (control_word_i == 3'b101);  // ReLU and linear pass through
  assign is_tanh = !is_selu && !is_sig && !is_byp;  // every other control word runs tanh, as in the float lane

  logic [ADDR_LINES-1:0] poly_base, poly_deg;
  assign poly_base = is_selu ? BASE_SELU : (is_sig ? BASE_SIG : BASE_TANH);
  assign poly_deg  = is_selu ? DEG_SELU : (is_sig ? DEG_SIG : DEG_TANH);

  logic         ld_valid, mac_start;
  logic [W-1:0] mac_in;
  logic         mac_res_valid, mac_busy, mac_done;
  logic [W-1:0] mac_res;

  // The int8 table as a literal: a string parameter passed down to the ROM's $readmemb is not found.
  barrel_mac #(
      .EXP_W     (0),
      .MAN_W     (7),
      .DATA_WIDTH(W),
      .ADDR_LINES(ADDR_LINES),
      .K         (K),
      .INIT_FILE ("poly_coeffs_int8.mem")
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

  // Rescale multiplier: (q - z_in) * mx.
  logic           rm_valid, rm_done;
  logic [W-1:0]   rm_a, rm_b;
  logic [2*W-1:0] rm_res;
  intMultiplier #(.W(W)) RESC (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(rm_valid), .A(rm_a), .B(rm_b), .result_o(rm_res),
                               .done_o(rm_done));

  // tanh's squaring unit, as the float lane's SQ: u = sat((x * x) >>> 11).
  logic         sq_valid, sq_done;
  logic [W-1:0] sq_a, sq_res;
  fxMac #(.W(W), .FRAC(11)) SQ (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(sq_valid), .A(sq_a), .X(sq_a), .C('0),
                                .result_o(sq_res), .done_o(sq_done));

  // Post multiply, as the float lane's POST: tanh x * P; SELU x * P, x * lambda, or -lambda*alpha * 1.0.
  logic           pm_valid, pm_done, rq_done;
  logic [W-1:0]   pm_a, pm_b;
  logic [2*W-1:0] pm_res, rq_acc;
  logic [7:0]     rq_res;
  intMultiplier #(.W(W)) POSTM (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(pm_valid), .A(pm_a), .B(pm_b), .result_o(pm_res),
                                .done_o(pm_done));

  logic [DATA_WIDTH-1:0] q_buf[K];    // captured int8 inputs
  logic [W-1:0]          x_buf[K];    // rescaled inputs, Q4.11
  logic [K-1:0]          neg_buf, sat_buf;
  logic [W-1:0]          pol_buf[K];
  logic [DATA_WIDTH-1:0] res_buf[K];
  logic [K-1:0]          res_rdy;

  logic [SW:0] n_elems, ld_idx, rx_idx, iss_idx, emit_idx;
  logic [SW:0] pop_idx, grp_n;
  logic [CAP_LAG-1:0] cap_v;
  logic [3:0]  drain_cnt;

  // Result pipelines; bit n lines up with a unit's done_o n cycles after valid_i, and each carries its element index.
  logic [MUL_LAT:0] rs_v;  // rescale
  logic [SW-1:0]    rs_p[MUL_LAT+1];
  logic [FX_LAT:0]  sq_v;  // tanh square, in load order
  logic [MUL_LAT:0] pt_v;  // tanh post multiply
  logic [SW-1:0]    pt_p[MUL_LAT+1];
  logic [PS_LAT:0]  ps_v;  // SELU post multiply and requantize
  logic [SW-1:0]    ps_p[PS_LAT+1];

  // SELU requantize: x * P and -lambda*alpha * 1.0 are in 2^-22, x * lambda in 2^-25.
  assign rq_acc = neg_buf[ps_p[MUL_LAT]] ? {pm_res[2*W-4:0], 3'b000} : pm_res;
  tfliteRequant #(.ROUNDING(sienna_fmt_pkg::REQ_ROUNDING)) POSTQ (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(ps_v[MUL_LAT]), .acc_i(rq_acc), .mult_i(gp_mout_i), .shift_i(gp_shout_i),
      .zp_i(gp_zout_i), .act_min_i(8'h80), .act_max_i(8'h7F), .result_o(rq_res), .done_o(rq_done)
  );

  logic [DATA_WIDTH-1:0] q_cur;
  logic [W-1:0]          d_cur, x_new, p_cur, x_cur;
  logic                  x_sat;
  logic signed [W:0]     p_ext, y_s;
  assign q_cur = q_buf[iss_idx[SW-1:0]];
  assign d_cur = {{(W - 8) {q_cur[7]}}, q_cur} - {{(W - 8) {gp_zin_i[7]}}, gp_zin_i};  // q - z_in
  assign x_new = rescale(rm_res, gp_shx_i);
  assign x_sat = is_selu ? ($signed(x_new) < T_SELU)
               : is_sig  ? (($signed(x_new) > T_SIG) || ($signed(x_new) < -T_SIG))
                         : (($signed(x_new) > T_TANH) || ($signed(x_new) < -T_TANH));
  assign p_cur = pol_buf[iss_idx[SW-1:0]];
  assign x_cur = x_buf[iss_idx[SW-1:0]];
  assign p_ext = {p_cur[W-1], p_cur};
  assign y_s   = neg_buf[iss_idx[SW-1:0]] ? (17'sd2048 - p_ext) : p_ext;  // sigmoid: P, or 1 - P for x < 0

  typedef enum logic [3:0] {
    G_IDLE,
    G_CAP,
    G_LOAD,
    G_LDRAIN,
    G_RUN,
    G_RECV,
    G_POST,
    G_EMIT,
    G_NEXT
  } gstate_t;
  gstate_t gstate;

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      gstate         <= G_IDLE;
      n_elems        <= '0;
      ld_idx         <= '0;
      rx_idx         <= '0;
      iss_idx        <= '0;
      emit_idx       <= '0;
      pop_idx        <= '0;
      grp_n          <= '0;
      cap_v          <= '0;
      drain_cnt      <= '0;
      ld_valid       <= 1'b0;
      mac_start      <= 1'b0;
      fifo_rd_en     <= 1'b0;
      rm_valid       <= 1'b0;
      sq_valid       <= 1'b0;
      pm_valid       <= 1'b0;
      done_o         <= 1'b0;
      final_result_o <= '0;
      rs_v           <= '0;
      sq_v           <= '0;
      pt_v           <= '0;
      ps_v           <= '0;
      res_rdy        <= '0;
      neg_buf        <= '0;
      sat_buf        <= '0;
      for (int i = 0; i <= MUL_LAT; i++) begin
        rs_p[i] <= '0;
        pt_p[i] <= '0;
      end
      for (int i = 0; i <= PS_LAT; i++) ps_p[i] <= '0;
    end else begin
      ld_valid   <= 1'b0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      rm_valid   <= 1'b0;
      sq_valid   <= 1'b0;
      pm_valid   <= 1'b0;
      done_o     <= 1'b0;

      rs_v <= {rs_v[MUL_LAT-1:0], 1'b0};
      sq_v <= {sq_v[FX_LAT-1:0], 1'b0};
      pt_v <= {pt_v[MUL_LAT-1:0], 1'b0};
      ps_v <= {ps_v[PS_LAT-1:0], 1'b0};
      for (int i = 1; i <= MUL_LAT; i++) begin
        rs_p[i] <= rs_p[i-1];
        pt_p[i] <= pt_p[i-1];
      end
      for (int i = 1; i <= PS_LAT; i++) ps_p[i] <= ps_p[i-1];

      // A rescaled input: kept for the post stage; its MAC operand is x (SELU), |x| (sigmoid) or x^2 (tanh, via SQ).
      if (rs_v[MUL_LAT]) begin
        x_buf[rs_p[MUL_LAT]]   <= x_new;
        neg_buf[rs_p[MUL_LAT]] <= x_new[W-1];
        sat_buf[rs_p[MUL_LAT]] <= x_sat;
        if (is_tanh) begin
          sq_a     <= x_new;
          sq_valid <= 1'b1;
          sq_v[0]  <= 1'b1;
        end else begin
          mac_in   <= is_sig ? abs_sat(x_new) : x_new;
          ld_valid <= 1'b1;
        end
      end
      if (sq_v[FX_LAT]) begin
        mac_in   <= sq_res;
        ld_valid <= 1'b1;
      end

      // Post results come back tagged with their element: tanh after the multiply, SELU after the requantizer.
      if (pt_v[MUL_LAT]) begin
        res_buf[pt_p[MUL_LAT]] <= quant_tanh(pm_res);
        res_rdy[pt_p[MUL_LAT]] <= 1'b1;
      end
      if (ps_v[PS_LAT]) begin
        res_buf[ps_p[PS_LAT]] <= rq_res;
        res_rdy[ps_p[PS_LAT]] <= 1'b1;
      end

      case (gstate)
        G_IDLE: begin
          ld_idx  <= '0;
          pop_idx <= '0;
          if (last_i) begin
            grp_n  <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
            gstate <= (fifo_count == '0) ? G_IDLE : G_CAP;
          end
        end

        // One pop per cycle; captures trail by CAP_LAG, as in gpnae_poly.
        G_CAP: begin
          if (pop_idx < grp_n) begin
            fifo_rd_en <= 1'b1;
            pop_idx    <= pop_idx + 1;
          end
          cap_v <= {cap_v[CAP_LAG-2:0], (pop_idx < grp_n)};
          if (cap_v[CAP_LAG-1]) begin
            q_buf[ld_idx[SW-1:0]] <= fifo_data_o;
            ld_idx                <= ld_idx + 1;
            if (is_byp) begin
              res_buf[ld_idx[SW-1:0]] <= fifo_data_o;  // the requantize clamp already applied ReLU
              res_rdy[ld_idx[SW-1:0]] <= 1'b1;
            end
            if (ld_idx + 1 == grp_n) begin
              n_elems   <= grp_n;
              iss_idx   <= '0;
              drain_cnt <= '0;
              emit_idx  <= '0;
              gstate    <= is_byp ? G_EMIT : G_LOAD;
            end
          end
        end

        // Rescale one element per cycle.
        G_LOAD: begin
          rm_a     <= d_cur;
          rm_b     <= gp_mx_i;
          rm_valid <= 1'b1;
          rs_v[0]  <= 1'b1;
          rs_p[0]  <= iss_idx[SW-1:0];
          if (iss_idx + 1 == n_elems) begin
            drain_cnt <= '0;
            gstate    <= G_LDRAIN;
          end else begin
            iss_idx <= iss_idx + 1;
          end
        end

        G_LDRAIN: begin
          // Start two cycles after the last operand was loaded; tanh's operands pass the squarer first.
          if (drain_cnt == (is_tanh ? 4'(MUL_LAT + FX_LAT + 3) : 4'(MUL_LAT + 2))) begin
            mac_start <= 1'b1;
            rx_idx    <= '0;
            gstate    <= G_RUN;
          end else begin
            drain_cnt <= drain_cnt + 1;
          end
        end

        G_RUN: begin
          if (mac_res_valid) begin
            pol_buf[rx_idx[SW-1:0]] <= mac_res;
            rx_idx                  <= rx_idx + 1;
            gstate                  <= G_RECV;
          end
          // A one-element group: barrel_mac's only result and its done_o arrive together.
          if (mac_done) begin
            iss_idx  <= '0;
            emit_idx <= '0;
            res_rdy  <= '0;
            gstate   <= G_POST;
          end
        end

        G_RECV: begin
          if (mac_res_valid) begin
            pol_buf[rx_idx[SW-1:0]] <= mac_res;
            rx_idx                  <= rx_idx + 1;
          end
          if (mac_done) begin
            iss_idx  <= '0;
            emit_idx <= '0;
            res_rdy  <= '0;
            gstate   <= G_POST;
          end
        end

        // sigmoid and saturated tanh quantize in place; tanh multiplies; SELU multiplies and requantizes.
        G_POST: begin
          if (is_sig || (is_tanh && sat_buf[iss_idx[SW-1:0]])) begin
            res_buf[iss_idx[SW-1:0]] <= sat_buf[iss_idx[SW-1:0]] ? (neg_buf[iss_idx[SW-1:0]] ? 8'h80 : 8'h7F)
                                                                 : quant_sig(y_s);
            res_rdy[iss_idx[SW-1:0]] <= 1'b1;
          end else begin
            pm_a     <= (is_selu && sat_buf[iss_idx[SW-1:0]]) ? SELU_SAT : x_cur;
            pm_b     <= (is_selu && !neg_buf[iss_idx[SW-1:0]]) ? LAMBDA_Q14
                      : (is_selu && sat_buf[iss_idx[SW-1:0]]) ? ONE_Q11 : p_cur;
            pm_valid <= 1'b1;
            if (is_selu) begin
              ps_v[0] <= 1'b1;
              ps_p[0] <= iss_idx[SW-1:0];
            end else begin
              pt_v[0] <= 1'b1;
              pt_p[0] <= iss_idx[SW-1:0];
            end
          end
          if (iss_idx + 1 == n_elems) gstate <= G_EMIT;
          else iss_idx <= iss_idx + 1;
        end

        // Retire in index order, one done_o per element.
        G_EMIT: begin
          if (res_rdy[emit_idx[SW-1:0]]) begin
            final_result_o <= res_buf[emit_idx[SW-1:0]];
            done_o         <= 1'b1;
            if (emit_idx + 1 == n_elems) gstate <= G_NEXT;
            else emit_idx <= emit_idx + 1;
          end
        end

        G_NEXT: begin
          ld_idx  <= '0;
          pop_idx <= '0;
          cap_v   <= '0;
          grp_n   <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
          gstate  <= (fifo_count == '0) ? G_IDLE : G_CAP;
        end

        default: gstate <= G_IDLE;
      endcase
    end
  end

`ifndef SYNTHESIS
  // The pipelines assume the package's unit latencies; a unit that differs would corrupt results silently.
  always @(posedge clk_i)
    if (rstn_i) begin
      if (rs_v[MUL_LAT] != rm_done) $fatal(1, "gpnae_poly_int8: rescale intMultiplier latency is not %0d", MUL_LAT);
      if (sq_v[FX_LAT] != sq_done) $fatal(1, "gpnae_poly_int8: squaring fxMac latency is not %0d", FX_LAT);
      if ((pt_v[MUL_LAT] | ps_v[MUL_LAT]) != pm_done) $fatal(1, "gpnae_poly_int8: post intMultiplier latency is not %0d", MUL_LAT);
      if (ps_v[PS_LAT] != rq_done) $fatal(1, "gpnae_poly_int8: tfliteRequant latency is not %0d", RQ_LAT);
      if (rm_valid && rm_b[W-1]) $fatal(1, "gpnae_poly_int8: gp_mx_i must be below 2^15");
    end
`endif

endmodule
