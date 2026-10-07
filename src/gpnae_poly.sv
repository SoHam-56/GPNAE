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
// The squaring and the post stage stream one element per cycle for the same reason: both
// units accept a new operand every cycle, so waiting out their latency per element wasted
// most of the lane's time. Elements are captured from the FIFO first, then streamed from
// registers, which keeps the FIFO's read-pointer timing untouched.
module gpnae_poly #(
    parameter int    EXP_W         = 8,   // the build's number format: fp32 8/23, bf16 8/7, int8 0/7
    parameter int    MAN_W         = 23,
    parameter int    DATA_WIDTH    = 1 + EXP_W + MAN_W,
    parameter int    ADDR_LINES    = 5,
    parameter int    CONTROL_WIDTH = 3,  // 001 SELU, 010 sigmoid, 011 tanh, 100 ReLU, 101 linear
    parameter int    K             = 16,
    parameter int    TAIL_CONTEXTS = 4,  // tail elements gpnae_tail works on at once
    parameter int    OUT_MAX       = 64,  // the most output credits the downstream consumer may advertise
    parameter int    OUT_CRW       = 1    // out.credit width
) (
    input logic clk_i,
    input logic rstn_i,

    credit_link_if.consumer in,   // {last, signal}, last on a set's final element; the lane advertises its 2**ADDR_LINES FIFO slots
    credit_link_if.producer out,  // one result per put; a group starts only with K output credits

    input  logic [   ADDR_LINES-1:0] terms_i,         // unused: degree comes from the table
    input  logic [CONTROL_WIDTH-1:0] control_word_i,

    input logic [15:0] gp_mx_i,     // int8 only (D-2): input rescale multiplier, below 2^15
    input logic [ 4:0] gp_shx_i,    // int8: input rescale shift
    input logic [ 7:0] gp_zin_i,    // int8: input zero point
    input logic [31:0] gp_mout_i,   // int8: SELU output multiplier
    input logic [ 7:0] gp_shout_i,  // int8: SELU output shift
    input logic [ 7:0] gp_zout_i    // int8: SELU output zero point
);

  localparam int SW = $clog2(K);
  localparam int FIFO_RD_LAT = 3;  // data_o trails a pop: rd_ptr, ram_data_b, doutb_reg
  // Pop issued at cycle c -> rd_en at c+1 -> status clear visible c+2 -> data_o(t+2)=mem[rd_ptr(t)],
  // so the word for that pop appears at c+3 and one per cycle after.
  localparam int CAP_LAG = 3;
  localparam bit FP32 = sienna_fmt_pkg::is_fp32(EXP_W, MAN_W);
  localparam int MUL_LAT = sienna_fmt_pkg::mul_lat(EXP_W, MAN_W);  // the format's multiplier, valid_i at t, done_o at t+MUL_LAT
  localparam int DN_LAT = FP32 ? 6 : sienna_fmt_pkg::add_lat(EXP_W, MAN_W);  // fp32_down: done_o = valid_stage6; else fpAdder

  localparam logic [DATA_WIDTH-1:0] LAMDA = DATA_WIDTH'(sienna_fmt_pkg::from_fp32(32'h3F867D5F, MAN_W));
  localparam logic [DATA_WIDTH-1:0] NEG_ONE = DATA_WIDTH'(sienna_fmt_pkg::from_fp32(32'hBF800000, MAN_W));
  localparam logic [DATA_WIDTH-1:0] T4_W = DATA_WIDTH'(sienna_fmt_pkg::from_fp32(32'h40800000, MAN_W));  // 4.0
  localparam logic [DATA_WIDTH-1:0] T35_W = DATA_WIDTH'(sienna_fmt_pkg::from_fp32(32'h40600000, MAN_W));  // 3.5
  localparam logic [DATA_WIDTH-2:0] T4 = T4_W[DATA_WIDTH-2:0];
  localparam logic [DATA_WIDTH-2:0] T35 = T35_W[DATA_WIDTH-2:0];

  if (!sienna_fmt_pkg::supported(EXP_W, MAN_W)) begin : G_BAD_FORMAT
    $fatal(1, "gpnae_poly: unsupported format EXP_W=%0d MAN_W=%0d", EXP_W, MAN_W);
  end
  if (OUT_MAX < K) begin : G_BAD_OUT_MAX
    $fatal(1, "gpnae_poly: OUT_MAX %0d is below K %0d, so no group could start", OUT_MAX, K);
  end
`ifndef SYNTHESIS
  // Interface widths are not elaboration constants in Verilator, so the link widths are checked at time 0.
  initial
    if ($bits(in.data) != DATA_WIDTH + 1 || $bits(out.data) != DATA_WIDTH || $bits(out.credit) != OUT_CRW)
      $fatal(1, "gpnae_poly: links need in.data %0d bits, out.data %0d, out.credit OUT_CRW %0d", DATA_WIDTH + 1, DATA_WIDTH, OUT_CRW);
`endif

  // int8 builds use the fixed-point lane; the float lane below is unchanged, only wrapped in G_FLOAT.
  if (sienna_fmt_pkg::is_int(EXP_W)) begin : G_INT8
    gpnae_poly_int8 #(
        .DATA_WIDTH   (DATA_WIDTH),
        .ADDR_LINES   (ADDR_LINES),
        .CONTROL_WIDTH(CONTROL_WIDTH),
        .K            (K),
        .OUT_MAX      (OUT_MAX),
        .OUT_CRW      (OUT_CRW)
    ) lane_inst (
        .clk_i         (clk_i),
        .rstn_i        (rstn_i),
        .in            (in),
        .out           (out),
        .terms_i       (terms_i),
        .control_word_i(control_word_i),
        .gp_mx_i       (gp_mx_i),
        .gp_shx_i      (gp_shx_i),
        .gp_zin_i      (gp_zin_i),
        .gp_mout_i     (gp_mout_i),
        .gp_shout_i    (gp_shout_i),
        .gp_zout_i     (gp_zout_i)
    );
  end else begin : G_FLOAT

  // Coefficient sets packed into one ROM. Keep in step with poly_coeffs.mem.
  localparam logic [ADDR_LINES-1:0] BASE_SELU = 5'd0, DEG_SELU = 5'd8;
  localparam logic [ADDR_LINES-1:0] BASE_SIG = 5'd9, DEG_SIG = 5'd6;
  localparam logic [ADDR_LINES-1:0] BASE_TANH = 5'd16, DEG_TANH = 5'd8;

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

  // Input link: one credit per free FIFO slot, 2**ADDR_LINES after reset, then one per pop, at most one a cycle.
  logic [ADDR_LINES:0] in_owed;  // freed slots not yet credited
  logic in_cr, fifo_pop, last_pend, grp_go, out_ok, res_put;
  logic [DATA_WIDTH-1:0] res_data;
  assign fifo_pop  = fifo_rd_en && (fifo_count != '0);
  assign in.credit = in_cr;

  // Output link: a group of up to K starts only with K credits, so the barrel MAC never waits on the consumer mid-group.
  localparam int OCW = $clog2(OUT_MAX + 1);
  logic [OCW-1:0] out_cnt;
  credit_counter #(.MAX(OUT_MAX), .CRW(OUT_CRW)) out_cc (.clk_i(clk_i), .rstn_i(rstn_i), .put_i(res_put), .credit_i(out.credit),
                                                        .has_credit_o(), .count_o(out_cnt));
  assign out_ok   = int'(out_cnt) >= K + int'(res_put);  // a put this cycle spends its credit at this edge
  assign out.put  = res_put;
  assign out.data = res_data;

  logic [ADDR_LINES-1:0] poly_base, poly_deg;
  logic is_tanh, is_sig, is_selu, is_relu, is_byp;
  assign is_selu = (control_word_i == 3'b001);
  assign is_sig  = (control_word_i == 3'b010);
  assign is_relu = (control_word_i == 3'b100);
  // ReLU and linear skip the polynomial: each element is written straight to res_buf as it is captured.
  assign is_byp  = is_relu || (control_word_i == 3'b101);
  assign is_tanh = ~is_selu & ~is_sig & ~is_byp;

  always_comb begin
    case (control_word_i)
      2'b01: begin
        poly_base = BASE_SELU;
        poly_deg  = DEG_SELU;
      end
      2'b10: begin
        poly_base = BASE_SIG;
        poly_deg  = DEG_SIG;
      end
      default: begin
        poly_base = BASE_TANH;
        poly_deg  = DEG_TANH;
      end
    endcase
  end

  logic [DATA_WIDTH-1:0] sq_a, sq_res;
  logic                  sq_valid, sq_done;

  logic                  ld_valid, mac_start;
  logic [DATA_WIDTH-1:0] mac_in;
  logic                  mac_res_valid, mac_busy, mac_done;
  logic [DATA_WIDTH-1:0] mac_res;

  // The format's coefficient table, as a literal: a string parameter passed down to the ROM's $readmemb is not found.
  localparam bit FP32_TABLE = sienna_fmt_pkg::is_fp32(EXP_W, MAN_W);
  if (FP32_TABLE) begin : G_MAC
    barrel_mac #(
        .EXP_W     (EXP_W),
        .MAN_W     (MAN_W),
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
  end else begin : G_MAC
    barrel_mac #(
        .EXP_W     (EXP_W),
        .MAN_W     (MAN_W),
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_LINES(ADDR_LINES),
        .K         (K),
        .INIT_FILE ("poly_coeffs_bf16.mem")
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
  end

  logic [DATA_WIDTH-1:0] sig_buf[K];
  logic [        K-1:0]  pos_buf;
  logic [DATA_WIDTH-1:0] pol_buf[K];
  logic [DATA_WIDTH-1:0] res_buf[K];
  logic [        K-1:0]  res_rdy;

  logic [SW:0] n_elems, ld_idx, rx_idx, iss_idx, emit_idx;
  logic [SW:0] pop_idx, grp_n;
  logic [CAP_LAG-1:0] cap_v;
  logic [3:0]  drain_cnt;

  logic sig_is_pos;
  assign sig_is_pos = ~fifo_data_o[DATA_WIDTH-1] || (fifo_data_o[DATA_WIDTH-2:0] == '0);

  // Past these bounds the fitted polynomials diverge, so gpnae_tail computes the element instead.
  logic sig_in_tail;
  always_comb begin
    case (control_word_i)
      3'b001:         sig_in_tail = fifo_data_o[DATA_WIDTH-1] && (fifo_data_o[DATA_WIDTH-2:0] > T4);  // SELU x < -4
      3'b010:         sig_in_tail = (fifo_data_o[DATA_WIDTH-2:0] > T35);  // sigmoid |x| > 3.5
      3'b100, 3'b101: sig_in_tail = 1'b0;  // ReLU and linear are exact
      default:        sig_in_tail = (fifo_data_o[DATA_WIDTH-2:0] > T4);  // tanh |x| > 4
    endcase
  end

  logic [K-1:0] tail_buf;
  logic tail_start, tail_done, tail_busy, tail_ready;
  logic [DATA_WIDTH-1:0] tail_res;
  // Tail elements start as they are captured and run beside the polynomial; results park in tres_buf until emit.
  logic [K-1:0] tail_pend, trdy;
  logic [DATA_WIDTH-1:0] tres_buf[K];
  logic [SW-1:0] tail_idx;  // element a finished tail result belongs to
  logic [SW-1:0] tail_next;
  always_comb begin
    tail_next = '0;
    for (int i = K - 1; i >= 0; i--) if (tail_pend[i]) tail_next = SW'(i);
  end

  // A pending element starts whenever a tail context is free, lowest index first.
  assign tail_start = tail_ready && (|tail_pend);

  gpnae_tail #(
      .EXP_W   (EXP_W),
      .MAN_W   (MAN_W),
      .CONTEXTS(TAIL_CONTEXTS),
      .IW      (SW)
  ) TAIL (
      .clk_i   (clk_i),
      .rstn_i  (rstn_i),
      .start_i (tail_start),
      .x_i     (sig_buf[tail_next]),
      .func_i  (control_word_i[1:0]),
      .idx_i   (tail_next),
      .ready_o (tail_ready),
      .result_o(tail_res),
      .idx_o   (tail_idx),
      .done_o  (tail_done),
      .busy_o  (tail_busy)
  );

  // Post stage: one multiply, or P - 1 (fp32_down, or an adder with -1) plus a sign flip. No divider.
  logic [DATA_WIDTH-1:0] mul_a, mul_b, mul_res, dn_a, dn_res;
  logic                  mul_valid, mul_done, dn_valid, dn_done;

  // The squaring unit and the post stage in the build's format.
  if (FP32) begin : G_FP32
    fp32Multiplier SQ (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(sq_valid), .A(sq_a), .B(sq_a), .result_o(sq_res),
                       .done_o(sq_done), .overflow_o(), .underflow_o(), .invalid_o());
    fp32Multiplier POST (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(mul_valid), .A(mul_a), .B(mul_b), .result_o(mul_res),
                         .done_o(mul_done), .overflow_o(), .underflow_o(), .invalid_o());
    fp32_down POSTD (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(dn_valid), .A(dn_a), .Result(dn_res), .done_o(dn_done));
  end else begin : G_FP
    fpMultiplier #(.EXP_W(EXP_W), .MAN_W(MAN_W)) SQ (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(sq_valid), .A(sq_a), .B(sq_a),
        .result_o(sq_res), .done_o(sq_done), .overflow_o(), .underflow_o(), .invalid_o());
    fpMultiplier #(.EXP_W(EXP_W), .MAN_W(MAN_W)) POST (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(mul_valid), .A(mul_a),
        .B(mul_b), .result_o(mul_res), .done_o(mul_done), .overflow_o(), .underflow_o(), .invalid_o());
    // P - 1 for negative sigmoid inputs: an adder with the constant -1, as fp32_down is in fp32.
    fpAdder #(.EXP_W(EXP_W), .MAN_W(MAN_W)) POSTD (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(dn_valid), .A(dn_a), .B(NEG_ONE),
        .result_o(dn_res), .done_o(dn_done), .overflow_o(), .underflow_o(), .invalid_o());
  end

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

  // A set waits in the FIFO for its last put; G_NEXT then takes whatever is queued, as before.
  assign grp_go = (fifo_count != '0) && out_ok && ((gstate == G_IDLE && last_pend) || gstate == G_NEXT);

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      in_owed   <= (ADDR_LINES + 1)'(1 << ADDR_LINES);
      in_cr     <= 1'b0;
      last_pend <= 1'b0;
    end else begin
      in_owed   <= in_owed + (ADDR_LINES + 1)'(fifo_pop) - (ADDR_LINES + 1)'(in_owed != '0);
      in_cr     <= in_owed != '0;
      // A last put sets it, a group start clears it; the start counts the FIFO before a put in the same cycle.
      if (in.put && in.data[DATA_WIDTH]) last_pend <= 1'b1;
      else if (grp_go) last_pend <= 1'b0;
    end
  end

  // Squaring pipeline: index of the element whose square is in flight. Bit 0 lines up with
  // the cycle valid_i is high, so the result lands at bit MUL_LAT, not MUL_LAT-1.
  logic [MUL_LAT:0] sq_v;
  logic [SW-1:0] sq_p[MUL_LAT+1];

  // Post pipelines: the multiply and fp32_down paths have different latencies, so each
  // carries its own element index and results are parked in res_buf until emitted in order.
  logic [MUL_LAT:0] pm_v;
  logic [SW-1:0] pm_p[MUL_LAT+1];
  logic [DN_LAT:0] pd_v;
  logic [SW-1:0] pd_p[DN_LAT+1];

  logic post_pass, post_down;
  assign post_pass = is_sig && pos_buf[iss_idx[SW-1:0]];
  assign post_down = is_sig && !pos_buf[iss_idx[SW-1:0]];

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
      sq_valid       <= 1'b0;
      mul_valid      <= 1'b0;
      dn_valid       <= 1'b0;
      res_put        <= 1'b0;
      res_data       <= '0;
      sq_v           <= '0;
      pm_v           <= '0;
      pd_v           <= '0;
      res_rdy        <= '0;
      pos_buf        <= '0;
      tail_buf       <= '0;
      tail_pend      <= '0;
      trdy           <= '0;
      for (int i = 0; i <= MUL_LAT; i++) begin
        sq_p[i] <= '0;
        pm_p[i] <= '0;
      end
      for (int i = 0; i <= DN_LAT; i++) pd_p[i] <= '0;
    end else begin
      ld_valid   <= 1'b0;
      mac_start  <= 1'b0;
      fifo_rd_en <= 1'b0;
      sq_valid   <= 1'b0;
      mul_valid  <= 1'b0;
      dn_valid   <= 1'b0;
      res_put    <= 1'b0;

      // Shift the three result pipelines every cycle; their tails write back below.
      sq_v <= {sq_v[MUL_LAT-1:0], 1'b0};
      pm_v <= {pm_v[MUL_LAT-1:0], 1'b0};
      pd_v <= {pd_v[DN_LAT-1:0], 1'b0};
      for (int i = 1; i <= MUL_LAT; i++) begin
        sq_p[i] <= sq_p[i-1];
        pm_p[i] <= pm_p[i-1];
      end
      for (int i = 1; i <= DN_LAT; i++) pd_p[i] <= pd_p[i-1];

      // A finished square is the MAC operand for its element, in load order.
      if (sq_v[MUL_LAT]) begin
        mac_in   <= sq_res;
        ld_valid <= 1'b1;
      end

      if (pm_v[MUL_LAT]) begin
        res_buf[pm_p[MUL_LAT]] <= mul_res;
        res_rdy[pm_p[MUL_LAT]] <= 1'b1;
      end
      if (pd_v[DN_LAT]) begin
        res_buf[pd_p[DN_LAT]] <= {~dn_res[DATA_WIDTH-1], dn_res[DATA_WIDTH-2:0]};
        res_rdy[pd_p[DN_LAT]] <= 1'b1;
      end

      // Tail results come back tagged with their element; the group cannot move on until every one is back.
      if (tail_start) tail_pend[tail_next] <= 1'b0;
      if (tail_done) begin
        tres_buf[tail_idx] <= tail_res;
        trdy[tail_idx]     <= 1'b1;
      end

      case (gstate)
        G_IDLE: begin
          ld_idx <= '0;
          pop_idx <= '0;
          if (grp_go) begin
            // The FIFO reports its own occupancy, so the whole group can be popped back to back
            // instead of one element every FIFO_RD_LAT+1 cycles. empty_o lags a pop by a cycle
            // and cannot be used to stop a streaming read without discarding a word.
            grp_n  <= (fifo_count > K[ADDR_LINES:0]) ? K[SW:0] : fifo_count[SW:0];
            gstate <= G_CAP;
          end
        end

        // One pop per cycle; captures trail by CAP_LAG and reuse the same counter space.
        G_CAP: begin
          if (pop_idx < grp_n) begin
            fifo_rd_en <= 1'b1;
            pop_idx    <= pop_idx + 1;
          end

          cap_v <= {cap_v[CAP_LAG-2:0], (pop_idx < grp_n)};

          if (cap_v[CAP_LAG-1]) begin
            sig_buf[ld_idx[SW-1:0]] <= fifo_data_o;
            pos_buf[ld_idx[SW-1:0]] <= sig_is_pos;
            tail_buf[ld_idx[SW-1:0]] <= sig_in_tail;
            tail_pend[ld_idx[SW-1:0]] <= sig_in_tail;
            trdy[ld_idx[SW-1:0]] <= 1'b0;
            ld_idx                  <= ld_idx + 1;
            if (is_byp) begin
              res_buf[ld_idx[SW-1:0]] <= (is_relu && fifo_data_o[DATA_WIDTH-1]) ? '0 : fifo_data_o;
              res_rdy[ld_idx[SW-1:0]] <= 1'b1;
            end
            // Only tanh needs a second pass; the others can feed the MAC as they arrive.
            else if (!is_tanh) begin
              mac_in   <= is_sig ? {1'b0, fifo_data_o[DATA_WIDTH-2:0]} : fifo_data_o;
              ld_valid <= 1'b1;
            end
            if (ld_idx + 1 == grp_n) begin
              n_elems   <= grp_n;
              iss_idx   <= '0;
              drain_cnt <= '0;
              emit_idx  <= '0;
              gstate    <= is_byp ? G_EMIT : (is_tanh ? G_LOAD : G_LDRAIN);
            end
          end
        end

        // Feed the MAC one element per cycle, squaring on the way for tanh.
        G_LOAD: begin
          if (is_tanh) begin
            sq_a              <= sig_buf[iss_idx[SW-1:0]];
            sq_valid          <= 1'b1;
            sq_v[0]           <= 1'b1;
            sq_p[0]           <= iss_idx[SW-1:0];
          end else begin
            mac_in   <= is_sig ? {1'b0, sig_buf[iss_idx[SW-1:0]][DATA_WIDTH-2:0]}
                               : sig_buf[iss_idx[SW-1:0]];
            ld_valid <= 1'b1;
          end
          if (iss_idx + 1 == n_elems) begin
            drain_cnt <= '0;
            gstate    <= G_LDRAIN;
          end else begin
            iss_idx <= iss_idx + 1;
          end
        end

        G_LDRAIN: begin
          // tanh still has squares in flight; start one cycle clear of the last load.
          if (!is_tanh || (drain_cnt == MUL_LAT[3:0] + 2)) begin
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

        // Issue one post operation per cycle; results land in res_buf out of order.
        G_POST: begin
          if (post_pass) begin
            res_buf[iss_idx[SW-1:0]] <= pol_buf[iss_idx[SW-1:0]];
            res_rdy[iss_idx[SW-1:0]] <= 1'b1;
          end else if (post_down) begin
            dn_a     <= pol_buf[iss_idx[SW-1:0]];
            dn_valid <= 1'b1;
            pd_v[0]  <= 1'b1;
            pd_p[0]  <= iss_idx[SW-1:0];
          end else begin
            mul_a     <= sig_buf[iss_idx[SW-1:0]];
            mul_b     <= (is_selu && pos_buf[iss_idx[SW-1:0]]) ? LAMDA
                                                              : pol_buf[iss_idx[SW-1:0]];
            mul_valid <= 1'b1;
            pm_v[0]   <= 1'b1;
            pm_p[0]   <= iss_idx[SW-1:0];
          end
          if (iss_idx + 1 == n_elems) gstate <= G_EMIT;
          else iss_idx <= iss_idx + 1;
        end

        // Retire in index order, one put per element in sequence.
        G_EMIT: begin
          if (tail_buf[emit_idx[SW-1:0]]) begin
            // A tail element takes gpnae_tail's result; its polynomial result is discarded.
            if (trdy[emit_idx[SW-1:0]]) begin
              res_data <= tres_buf[emit_idx[SW-1:0]];
              res_put  <= 1'b1;
              if (emit_idx + 1 == n_elems) gstate <= G_NEXT;
              else emit_idx <= emit_idx + 1;
            end
          end else if (res_rdy[emit_idx[SW-1:0]]) begin
            res_data <= res_buf[emit_idx[SW-1:0]];
            res_put  <= 1'b1;
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

`ifndef SYNTHESIS
  // A put needs a free slot: with 32 words held no credit can be outstanding.
  a_in_room: assert property (@(posedge clk_i) disable iff (!rstn_i) in.put |-> int'(fifo_count) < (1 << ADDR_LINES))
    else $error("gpnae_poly: a_in_room: put into a full input FIFO");
  // Every captured word is the oldest one put and not yet captured: no reorder, loss or overwrite in the FIFO.
  logic [DATA_WIDTH-1:0] in_shadow[$];
  always @(posedge clk_i)
    if (!rstn_i) in_shadow.delete();
    else begin
      if (gstate == G_CAP && cap_v[CAP_LAG-1]) begin
        a_in_order: assert (in_shadow.size() != 0 && fifo_data_o == in_shadow[0])
        else $error("gpnae_poly: a_in_order: captured %h, the oldest word put is %h", fifo_data_o,
                    (in_shadow.size() != 0) ? in_shadow[0] : '0);
        if (in_shadow.size() != 0) void'(in_shadow.pop_front());
      end
      if (in.put) in_shadow.push_back(in.data[DATA_WIDTH-1:0]);
    end
`endif

  end  // G_FLOAT

endmodule
