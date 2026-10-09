`default_nettype wire
`timescale 1ns / 100ps

// int8 GPNAE lane (gpnae_poly's G_INT8 branch): the float lane's forms on fxMac (Q4.11) and integer products, int8 out; no gpnae_tail.
module gpnae_poly_int8 #(
    parameter int DATA_WIDTH    = 8,
    parameter int ADDR_LINES    = 5,
    parameter int CONTROL_WIDTH = 3,  // 001 SELU, 010 sigmoid, 011 tanh, 100 ReLU, 101 linear
    parameter int K             = 16,
    parameter int OUT_MAX       = 64,  // the most output credits the downstream consumer may advertise
    parameter int OUT_CRW       = 1    // out.credit width
) (
    input logic clk_i,
    input logic rstn_i,

    credit_link_if.consumer in,   // {last, q}, last on a set's final element; the lane advertises its 2**ADDR_LINES FIFO slots
    credit_link_if.producer out,  // one int8 result per put; a group starts only with K output credits

    input logic [CONTROL_WIDTH-1:0] control_word_i,

    input logic [15:0] gp_mx_i,     // input rescale: x = round((q - z_in) * mx / 2^shx) in Q4.11, mx below 2^15
    input logic [ 4:0] gp_shx_i,
    input logic [ 7:0] gp_zin_i,    // input zero point
    input logic [31:0] gp_mout_i,   // SELU output: TFLite multiplier and shift of 2^-22 / s_out
    input logic [ 7:0] gp_shout_i,
    input logic [ 7:0] gp_zout_i    // SELU output zero point
);

  localparam int SW = $clog2(K);
  localparam int CAP_LAG = 3;  // as gpnae_poly: a pop's word appears three cycles later
  localparam int W = 16;  // Q4.11
  localparam int XW = 24;  // x unsaturated: |q - z_in| <= 255 and mx < 2^15 keep |(q - z_in) * mx| below 2^23
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

  // Input rescale: (q - z_in) * mx rounded half up by 2^s; below 2^23 in magnitude, so its low XW bits are SELU's unsaturated x.
  function automatic logic signed [39:0] rescale_raw(input logic [31:0] p, input logic [4:0] s);
    logic signed [39:0] pw;
    pw = {{8{p[31]}}, p};
    return (s == 5'd0) ? pw : ((pw + (40'sd1 <<< (s - 5'd1))) >>> s);
  endfunction

  // The rescale saturated to Q4.11.
  function automatic logic [W-1:0] rescale(input logic signed [39:0] r);
    if (r > 40'sd32767) return 16'h7FFF;
    if (r < -40'sd32768) return 16'h8000;
    return r[W-1:0];
  endfunction

  // A Q4.11 word sign-extended to the post multiplier's width.
  function automatic logic [XW-1:0] sx_xw(input logic [W-1:0] v);
    return {{(XW - W) {v[W-1]}}, v};
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

  // A circular FIFO: credits let the producer write while the lane pops, which InputFIFO's lowest-free-slot order would reorder.
  lane_fifo #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES)
  ) input_fifo_inst (
      .clk_i  (clk_i),
      .rstn_i (rstn_i),
      .wr_en_i(in.put),
      .rd_en_i(fifo_rd_en),
      .count_o(fifo_count),
      .data_i (in.data[DATA_WIDTH-1:0]),
      .data_o (fifo_data_o)
  );

  logic fifo_pop, last_pend, grp_go, out_ok, res_put;
  logic [DATA_WIDTH-1:0] res_data;
  logic [$clog2(OUT_MAX + 1)-1:0] out_cnt;  // output credits held, from lane_link
  assign fifo_pop = fifo_rd_en && (fifo_count != '0);

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
  logic         mac_res_valid, mac_done;
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
      .busy_o      (),
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
  logic            pm_valid, pm_done, rq_done;
  logic [XW-1:0]   pm_a, pm_b;  // XW wide for lambda * x unsaturated; the other products are of sign-extended 16-bit operands
  logic [2*XW-1:0] pm_res;
  logic [2*W-1:0]  rq_acc;
  logic [7:0]      rq_res;
  intMultiplier #(.W(XW)) POSTM (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(pm_valid), .A(pm_a), .B(pm_b), .result_o(pm_res),
                                 .done_o(pm_done));

  logic [DATA_WIDTH-1:0] q_buf[K];    // captured int8 inputs
  logic [W-1:0]          x_buf[K];    // rescaled inputs, Q4.11
  logic [XW-1:0]         xw_buf[K];   // the same, unsaturated: SELU's positive branch
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

  // SELU requantize in 2^-22: x * P and -lambda*alpha * 1.0 as they are; lambda * x (2^-25) floored by 2^3, saturated to int32.
  localparam logic signed [2*XW-1:0] I32_MAX = (2*XW)'(32'sh7FFFFFFF), I32_MIN = (2*XW)'(32'sh80000000);
  logic signed [2*XW-1:0] pm_sh;
  assign pm_sh  = $signed(pm_res) >>> 3;
  assign rq_acc = neg_buf[ps_p[MUL_LAT]] ? pm_res[2*W-1:0]
                : (pm_sh > I32_MAX) ? 32'h7FFFFFFF : (pm_sh < I32_MIN) ? 32'h80000000 : pm_sh[2*W-1:0];
  tfliteRequant #(.ROUNDING(sienna_fmt_pkg::REQ_ROUNDING)) POSTQ (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(ps_v[MUL_LAT]), .acc_i(rq_acc), .mult_i(gp_mout_i), .shift_i(gp_shout_i),
      .zp_i(gp_zout_i), .act_min_i(8'h80), .act_max_i(8'h7F), .result_o(rq_res), .done_o(rq_done)
  );

  logic [DATA_WIDTH-1:0] q_cur;
  logic [W-1:0]          d_cur, x_new, p_cur, x_cur;
  logic signed [39:0]    x_raw;
  logic                  x_sat;
  logic signed [W:0]     p_ext, y_s;
  assign q_cur = q_buf[iss_idx[SW-1:0]];
  assign d_cur = {{(W - 8) {q_cur[7]}}, q_cur} - {{(W - 8) {gp_zin_i[7]}}, gp_zin_i};  // q - z_in
  assign x_raw = rescale_raw(rm_res, gp_shx_i);
  assign x_new = rescale(x_raw);
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

  // The credit front end: input credits, the last bit, the K-credit group gate, output credits and the link checks.
  lane_link #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES),
      .K         (K),
      .OUT_MAX   (OUT_MAX),
      .OUT_CRW   (OUT_CRW)
  ) link (
      .clk_i       (clk_i),
      .rstn_i      (rstn_i),
      .in          (in),
      .out         (out),
      .fifo_pop_i  (fifo_pop),
      .fifo_count_i(fifo_count),
      .idle_i      (gstate == G_IDLE),
      .next_i      (gstate == G_NEXT),
      .res_put_i   (res_put),
      .res_data_i  (res_data),
      .cap_i       (gstate == G_CAP && cap_v[CAP_LAG-1]),
      .cap_data_i  (fifo_data_o),
      .grp_go_o    (grp_go),
      .out_ok_o    (out_ok),
      .last_pend_o (last_pend),
      .out_cnt_o   (out_cnt)
  );

  // Control: FSM state, counters and valid bits, the only registers under reset (D-8).
  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      gstate     <= G_IDLE;
      n_elems    <= '0;
      ld_idx     <= '0;
      rx_idx     <= '0;
      iss_idx    <= '0;
      emit_idx   <= '0;
      pop_idx    <= '0;
      grp_n      <= '0;
      cap_v      <= '0;
      drain_cnt  <= '0;
      ld_valid   <= 1'b0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      rm_valid   <= 1'b0;
      sq_valid   <= 1'b0;
      pm_valid   <= 1'b0;
      res_put    <= 1'b0;
      rs_v       <= '0;
      sq_v       <= '0;
      pt_v       <= '0;
      ps_v       <= '0;
      res_rdy    <= '0;
    end else begin
      ld_valid   <= 1'b0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      rm_valid   <= 1'b0;
      sq_valid   <= 1'b0;
      pm_valid   <= 1'b0;
      res_put    <= 1'b0;

      rs_v <= {rs_v[MUL_LAT-1:0], 1'b0};
      sq_v <= {sq_v[FX_LAT-1:0], 1'b0};
      pt_v <= {pt_v[MUL_LAT-1:0], 1'b0};
      ps_v <= {ps_v[PS_LAT-1:0], 1'b0};

      // A rescaled input goes to the MAC as x (SELU), |x| (sigmoid) or, via SQ, x^2 (tanh).
      if (rs_v[MUL_LAT]) begin
        if (is_tanh) begin
          sq_valid <= 1'b1;
          sq_v[0]  <= 1'b1;
        end else begin
          ld_valid <= 1'b1;
        end
      end
      if (sq_v[FX_LAT]) ld_valid <= 1'b1;

      // Post results come back tagged with their element: tanh after the multiply, SELU after the requantizer.
      if (pt_v[MUL_LAT]) res_rdy[pt_p[MUL_LAT]] <= 1'b1;
      if (ps_v[PS_LAT]) res_rdy[ps_p[PS_LAT]] <= 1'b1;

      case (gstate)
        G_IDLE: begin
          ld_idx  <= '0;
          pop_idx <= '0;
          if (grp_go) begin
            grp_n  <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
            gstate <= G_CAP;
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
            ld_idx <= ld_idx + 1;
            if (is_byp) res_rdy[ld_idx[SW-1:0]] <= 1'b1;  // the requantize clamp already applied ReLU
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
          rm_valid <= 1'b1;
          rs_v[0]  <= 1'b1;
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
            rx_idx <= rx_idx + 1;
            gstate <= G_RECV;
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
          if (mac_res_valid) rx_idx <= rx_idx + 1;
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
            res_rdy[iss_idx[SW-1:0]] <= 1'b1;
          end else begin
            pm_valid <= 1'b1;
            if (is_selu) ps_v[0] <= 1'b1;
            else pt_v[0] <= 1'b1;
          end
          if (iss_idx + 1 == n_elems) gstate <= G_EMIT;
          else iss_idx <= iss_idx + 1;
        end

        // Retire in index order, one put per element.
        G_EMIT: begin
          if (res_rdy[emit_idx[SW-1:0]]) begin
            res_put <= 1'b1;
            if (emit_idx + 1 == n_elems) gstate <= G_NEXT;
            else emit_idx <= emit_idx + 1;
          end
        end

        // Waits here while queued words lack K output credits.
        G_NEXT: begin
          ld_idx  <= '0;
          pop_idx <= '0;
          cap_v   <= '0;
          grp_n   <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
          if (fifo_count == '0) gstate <= G_IDLE;
          else if (grp_go) gstate <= G_CAP;
        end

        default: gstate <= G_IDLE;
      endcase
    end
  end

  // Data: buffers, unit operands, element tags and the output word, loaded beside the control above and never reset (D-8).
  always_ff @(posedge clk_i) begin
    for (int i = 1; i <= MUL_LAT; i++) begin
      rs_p[i] <= rs_p[i-1];
      pt_p[i] <= pt_p[i-1];
    end
    for (int i = 1; i <= PS_LAT; i++) ps_p[i] <= ps_p[i-1];

    // A rescaled input: kept for the post stage, and the MAC's or SQ's operand.
    if (rs_v[MUL_LAT]) begin
      x_buf[rs_p[MUL_LAT]]   <= x_new;
      xw_buf[rs_p[MUL_LAT]]  <= x_raw[XW-1:0];
      neg_buf[rs_p[MUL_LAT]] <= x_new[W-1];
      sat_buf[rs_p[MUL_LAT]] <= x_sat;
      if (is_tanh) sq_a <= x_new;
      else mac_in <= is_sig ? abs_sat(x_new) : x_new;
    end
    if (sq_v[FX_LAT]) mac_in <= sq_res;

    if (pt_v[MUL_LAT]) res_buf[pt_p[MUL_LAT]] <= quant_tanh(pm_res[2*W-1:0]);
    if (ps_v[PS_LAT]) res_buf[ps_p[PS_LAT]] <= rq_res;

    case (gstate)
      G_CAP:
        if (cap_v[CAP_LAG-1]) begin
          q_buf[ld_idx[SW-1:0]] <= fifo_data_o;
          if (is_byp) res_buf[ld_idx[SW-1:0]] <= fifo_data_o;
        end

      G_LOAD: begin
        rm_a    <= d_cur;
        rm_b    <= gp_mx_i;
        rs_p[0] <= iss_idx[SW-1:0];
      end

      G_RUN, G_RECV: if (mac_res_valid) pol_buf[rx_idx[SW-1:0]] <= mac_res;

      G_POST:
        if (is_sig || (is_tanh && sat_buf[iss_idx[SW-1:0]])) begin
          res_buf[iss_idx[SW-1:0]] <= sat_buf[iss_idx[SW-1:0]] ? (neg_buf[iss_idx[SW-1:0]] ? 8'h80 : 8'h7F)
                                                               : quant_sig(y_s);
        end else begin
          pm_a <= (is_selu && !neg_buf[iss_idx[SW-1:0]]) ? xw_buf[iss_idx[SW-1:0]]
                : sx_xw((is_selu && sat_buf[iss_idx[SW-1:0]]) ? SELU_SAT : x_cur);
          pm_b <= sx_xw((is_selu && !neg_buf[iss_idx[SW-1:0]]) ? LAMBDA_Q14
                      : (is_selu && sat_buf[iss_idx[SW-1:0]]) ? ONE_Q11 : p_cur);
          if (is_selu) ps_p[0] <= iss_idx[SW-1:0];
          else pt_p[0] <= iss_idx[SW-1:0];
        end

      G_EMIT: if (res_rdy[emit_idx[SW-1:0]]) res_data <= res_buf[emit_idx[SW-1:0]];

      default: ;
    endcase
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
