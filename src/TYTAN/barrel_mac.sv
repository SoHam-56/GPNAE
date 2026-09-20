`timescale 1ns / 100ps

// Barrel TYTAN MAC: K elements share one datapath, round-robin, in lockstep on the term
// index. Same idea as a barrel processor -- rotate through contexts to fill pipeline latency.
//
// fp32Multiplier and fp32Adder accept a new operation every cycle (II=1) but the original
// controller issues one every 15, so the multiplier runs at ~6%. Horner carries a 13-cycle
// loop dependency WITHIN an element (8 multiply + 5 add), but elements are independent, so K
// of them can share the units in lockstep on the term index.
//
// Per round every slot issues one multiply and one add, so a round costs K cycles instead of
// 15 per element. The arithmetic each element sees is unchanged in value and in order, so
// results are bit-identical to mac.sv.
//
// K must be >= 14 or a slot's accumulator would not be back before it is needed again.
module barrel_mac #(
    parameter int DATA_WIDTH = 32,
    parameter int ADDR_LINES = 5,
    parameter int K          = 16
) (
    input logic clk_i,
    input logic rstn_i,

    // Load phase: one operand per ld_valid_i, then a start_i pulse to run the group.
    input logic                  ld_valid_i,
    input logic [DATA_WIDTH-1:0] ld_data_i,
    input logic                  start_i,

    input logic [ADDR_LINES-1:0] terms_i,  // polynomial degree; NCOEF = terms_i + 1

    // Result phase: one per cycle, in load order.
    output logic                  res_valid_o,
    output logic [DATA_WIDTH-1:0] res_data_o,
    output logic                  busy_o,
    output logic                  done_o
);

  localparam int MUL_LAT = 8;   // measured, valid_i -> done_o
  localparam int ADD_LAT = 5;   // measured
  localparam int LOOP    = MUL_LAT + ADD_LAT;      // 13, the Horner recurrence
  localparam int MIN_PER = LOOP + 1;               // write-back lands a cycle after that
  localparam int SW      = $clog2(K);

  initial if (K < MIN_PER) $error("barrel_mac: K must be >= %0d", MIN_PER);

  logic [DATA_WIDTH-1:0] xop  [K];  // operands, one per slot
  logic [DATA_WIDTH-1:0] acc  [K];  // accumulators, one per slot

  logic [SW:0] n_elems;             // how many slots this group actually uses
  logic [ADDR_LINES:0] ncoef;
  assign ncoef = {1'b0, terms_i} + 1;

  typedef enum logic [1:0] {LOAD, RUN, DRAIN, EMIT} state_t;
  state_t state;

  logic [SW:0]         slot;        // slot being issued this cycle
  logic [SW+1:0]       period;      // max(n_elems, LOOP): a round never shortens below LOOP
  logic [ADDR_LINES:0] round;       // coefficient round, 0 .. ncoef-1
  logic [SW:0]         emit_idx;
  logic [$clog2(LOOP+2):0] drain_cnt;

  // Issue pipeline. Stage 7 addresses the ROM so the value lands for the add at stage 8;
  // stage 13 is when the sum is back and the accumulator is rewritten.
  logic                v_dly    [LOOP+1];
  logic [SW:0]         slot_dly [LOOP+1];
  logic [ADDR_LINES:0] rnd_dly  [LOOP+1];

  logic                  mul_valid, add_valid;
  logic [DATA_WIDTH-1:0] mul_a, mul_b, add_a, add_b;
  logic [DATA_WIDTH-1:0] mul_res, add_res;
  logic                  mul_done, add_done;
  logic [DATA_WIDTH-1:0] coeff_data;
  logic [ADDR_LINES-1:0] coeff_addr;

  // ROM address comes from stage 7 so coeff_data is valid at stage 8, where the add issues.
  logic [ADDR_LINES:0] coeff_addr_full;
  assign coeff_addr_full = ncoef - 1 - rnd_dly[MUL_LAT-2];
  assign coeff_addr      = coeff_addr_full[ADDR_LINES-1:0];

  CoeffROM #(
      .DATA_WIDTH(DATA_WIDTH),
      .ADDR_LINES(ADDR_LINES),
      .INIT_FILE ("taylor_coeffs.mem")
  ) coeff_rom_inst (
      .clk_i       (clk_i),
      .rd_en_i     (1'b1),
      .coeff_addr_i(coeff_addr),
      .data_o      (coeff_data)
  );

  fp32Multiplier MUL (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(mul_valid),
      .A(mul_a), .B(mul_b), .result_o(mul_res), .done_o(mul_done),
      .overflow_o(), .underflow_o(), .invalid_o()
  );

  fp32Adder ADD (
      .clk_i(clk_i), .rstn_i(rstn_i), .valid_i(add_valid),
      .A(add_a), .B(add_b), .result_o(add_res), .done_o(add_done),
      .overflow_o(), .underflow_o(), .invalid_o()
  );

  // Issue: multiply x[slot] by acc[slot] every cycle while running.
  assign mul_valid = (state == RUN) && (slot < n_elems);
  assign mul_a     = xop[slot[SW-1:0]];
  assign mul_b     = acc[slot[SW-1:0]];

  // Add: coeff for this slot's round, plus the product issued MUL_LAT cycles ago.
  assign add_valid = v_dly[MUL_LAT-1];
  assign add_a     = coeff_data;
  assign add_b     = mul_res;

  assign busy_o = (state != LOAD);
  assign period = (n_elems >= MIN_PER[SW:0]) ? {1'b0, n_elems} : MIN_PER[SW+1:0];

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      state       <= LOAD;
      n_elems     <= '0;
      slot        <= '0;
      round       <= '0;
      emit_idx    <= '0;
      drain_cnt   <= '0;
      res_valid_o <= 1'b0;
      res_data_o  <= '0;
      done_o      <= 1'b0;
      for (int i = 0; i < K; i++) begin
        xop[i] <= '0;
        acc[i] <= '0;
      end
      for (int i = 0; i <= LOOP; i++) v_dly[i] <= 1'b0;
    end else begin
      res_valid_o <= 1'b0;
      done_o      <= 1'b0;

      // Issue pipeline advances every cycle.
      v_dly[0]    <= mul_valid;
      slot_dly[0] <= slot;
      rnd_dly[0]  <= round;
      for (int i = 1; i <= LOOP; i++) begin
        v_dly[i]    <= v_dly[i-1];
        slot_dly[i] <= slot_dly[i-1];
        rnd_dly[i]  <= rnd_dly[i-1];
      end

      // Accumulator write-back, LOOP cycles after the multiply was issued.
      if (v_dly[LOOP-1]) acc[slot_dly[LOOP-1][SW-1:0]] <= add_res;

      case (state)
        LOAD: begin
          if (ld_valid_i) begin
            xop[n_elems[SW-1:0]] <= ld_data_i;
            acc[n_elems[SW-1:0]] <= '0;   // matches mac.sv: first product is x*0
            n_elems              <= n_elems + 1;
          end
          if (start_i && (n_elems != '0 || ld_valid_i)) begin
            state <= RUN;
            slot  <= '0;
            round <= '0;
          end
        end

        RUN: begin
          // One slot per cycle, padded to `period` so a round is never shorter than LOOP.
          if ({1'b0, slot} == period - 1) begin
            slot <= '0;
            if (round == ncoef - 1) state <= DRAIN;
            else round <= round + 1;
          end else begin
            slot <= slot + 1;
          end
        end

        DRAIN: begin
          // Count out the in-flight operations rather than watching the valid pipeline.
          if (drain_cnt == LOOP + 1) begin
            state     <= EMIT;
            emit_idx  <= '0;
            drain_cnt <= '0;
          end else drain_cnt <= drain_cnt + 1;
        end

        EMIT: begin
          res_valid_o <= 1'b1;
          res_data_o  <= acc[emit_idx[SW-1:0]];
          if (emit_idx == n_elems - 1) begin
            state   <= LOAD;
            n_elems <= '0;
            done_o  <= 1'b1;
          end else begin
            emit_idx <= emit_idx + 1;
          end
        end

        default: state <= LOAD;
      endcase
    end
  end

endmodule
