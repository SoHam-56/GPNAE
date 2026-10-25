`timescale 1ns / 100ps

// Barrel TYTAN MAC: up to K elements share one Horner step (gpnae_horner), round-robin, in lockstep on the round index, like a barrel
// processor that rotates through contexts to fill the step's pipeline. Each slot has its own coefficient set (base and degree) and,
// in int8, its own fraction shift; a round issues one step per slot, so it costs max(n, LOOP + 1) cycles. The group runs
// max(degree) + 1 rounds; a slot of lower degree joins at its own degree, its earlier rounds writing its accumulator back as 0, so its
// result never depends on its group. Coefficients come from the lane's memory on coeff_addr_o, read back on coeff_data_i a cycle later.
// No format here: the step's latency and coefficient lag are the package's.
module barrel_mac #(
    parameter int  K           = 16,
    parameter int  COEF_ADDR_W = 7,
    localparam int ACT_W       = sienna_fmt_pkg::ACTIVATION_DATA_WIDTH
) (
    input logic clk_i,
    input logic rstn_i,

    // Load phase: one operand and its set per ld_valid_i, then a start_i pulse to run the group.
    input logic                   ld_valid_i,
    input logic [      ACT_W-1:0] ld_data_i,
    input logic [COEF_ADDR_W-1:0] ld_base_i,  // the slot's coefficient set: c_j at base + j
    input logic [            3:0] ld_deg_i,
    input logic [            1:0] ld_frac_i,  // int8: fixedPointMultiplyAdd's extra fraction bits; floats ignore it
    input logic                   start_i,

    // Coefficient memory read: the word at coeff_addr_o is on coeff_data_i the next cycle.
    output logic [COEF_ADDR_W-1:0] coeff_addr_o,
    input  logic [      ACT_W-1:0] coeff_data_i,

    // Result phase: one per cycle, in load order.
    output logic             res_valid_o,
    output logic [ACT_W-1:0] res_data_o,
    output logic             busy_o,
    output logic             done_o
);
  localparam int LOOP    = sienna_fmt_pkg::HORNER_STEP_LATENCY;  // the Horner recurrence: issue to write-back
  localparam int LAG     = sienna_fmt_pkg::HORNER_COEFFICIENT_LAG;  // the coefficient is wanted this long after the issue
  localparam int MIN_PER = LOOP + 1;  // write-back lands a cycle after that
  localparam int SW      = $clog2(K);

  if (K < MIN_PER) begin : G_BAD_K
    $fatal(1, "barrel_mac: K %0d is below %0d, so a slot's accumulator would not be back before its next round", K, MIN_PER);
  end
  if (LAG < 1 || LAG >= LOOP) begin : G_BAD_LAG
    $fatal(1, "barrel_mac: the coefficient lag %0d must be 1 to %0d", LAG, LOOP - 1);
  end

  logic [      ACT_W-1:0] xop  [K];  // operands, one per slot
  logic [      ACT_W-1:0] acc  [K];  // accumulators, one per slot
  logic [COEF_ADDR_W-1:0] sbase[K];
  logic [            3:0] sdeg [K];
  logic [            1:0] sfrac[K];

  logic [SW:0] n_elems;  // how many slots this group uses
  logic [ 3:0] max_deg;  // the group's highest degree: it runs max_deg + 1 rounds

  typedef enum logic [1:0] {LOAD, RUN, DRAIN, EMIT} state_t;
  state_t state;

  logic [SW:0]   slot;  // slot being issued this cycle
  logic [SW+1:0] period;  // max(n_elems, LOOP + 1): a round never shortens below the recurrence
  logic [   3:0] round;  // 0 .. max_deg; round r reads c_(max_deg - r)
  logic [  SW:0] emit_idx;
  logic [$clog2(LOOP+2):0] drain_cnt;

  // Issue pipeline: slot, round and pad ride with each step, to address its coefficient at stage LAG - 1 and write back at LOOP - 1.
  logic          v_dly   [LOOP];
  logic [SW-1:0] slot_dly[LOOP];
  logic [   3:0] rnd_dly [LOOP];
  logic          pad_dly [LOOP];  // the step is a round before the slot's own degree: its result is replaced by 0

  logic             step_valid, step_done;
  logic [ACT_W-1:0] step_y, step_c;

  // The issuing slot's coefficient index is max_deg - round; a round whose index is above the slot's degree is a pad.
  logic iss_pad;
  assign step_valid = (state == RUN) && (slot < n_elems);
  assign iss_pad    = (max_deg - round) > sdeg[slot[SW-1:0]];

  // The coefficient for the step issued LAG cycles ago, addressed at stage LAG - 1 so the memory's registered read lands at LAG.
  logic [SW-1:0] a_slot;
  logic [   3:0] a_round;
  logic          a_pad, c_pad;
  if (LAG == 1) begin : G_ADDR_AT_ISSUE
    assign a_slot  = slot[SW-1:0];
    assign a_round = round;
    assign a_pad   = iss_pad;
  end else begin : G_ADDR_DELAYED
    assign a_slot  = slot_dly[LAG-2];
    assign a_round = rnd_dly[LAG-2];
    assign a_pad   = pad_dly[LAG-2];
  end
  assign coeff_addr_o = sbase[a_slot] + COEF_ADDR_W'(max_deg - a_round);
  always_ff @(posedge clk_i) c_pad <= a_pad;
  assign step_c = c_pad ? '0 : coeff_data_i;

  gpnae_horner STEP (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(step_valid), .x_i(xop[slot[SW-1:0]]), .acc_i(acc[slot[SW-1:0]]),
                     .frac_i(sfrac[slot[SW-1:0]]), .c_i(step_c), .y_o(step_y), .done_o(step_done));

  assign busy_o = (state != LOAD);
  assign period = (n_elems >= MIN_PER[SW:0]) ? {1'b0, n_elems} : MIN_PER[SW+1:0];

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      state       <= LOAD;
      n_elems     <= '0;
      max_deg     <= '0;
      slot        <= '0;
      round       <= '0;
      emit_idx    <= '0;
      drain_cnt   <= '0;
      res_valid_o <= 1'b0;
      res_data_o  <= '0;
      done_o      <= 1'b0;
      for (int i = 0; i < K; i++) begin
        xop[i]   <= '0;
        acc[i]   <= '0;
        sbase[i] <= '0;
        sdeg[i]  <= '0;
        sfrac[i] <= '0;
      end
      for (int i = 0; i < LOOP; i++) begin
        v_dly[i]    <= 1'b0;
        slot_dly[i] <= '0;
        rnd_dly[i]  <= '0;
        pad_dly[i]  <= 1'b0;
      end
    end else begin
      res_valid_o <= 1'b0;
      done_o      <= 1'b0;

      // The issue pipeline advances every cycle.
      v_dly[0]    <= step_valid;
      slot_dly[0] <= slot[SW-1:0];
      rnd_dly[0]  <= round;
      pad_dly[0]  <= iss_pad;
      for (int i = 1; i < LOOP; i++) begin
        v_dly[i]    <= v_dly[i-1];
        slot_dly[i] <= slot_dly[i-1];
        rnd_dly[i]  <= rnd_dly[i-1];
        pad_dly[i]  <= pad_dly[i-1];
      end

      // Accumulator write-back, LOOP cycles after the issue; a pad round writes 0, the accumulator's start.
      if (v_dly[LOOP-1]) acc[slot_dly[LOOP-1]] <= pad_dly[LOOP-1] ? '0 : step_y;

      case (state)
        LOAD: begin
          if (ld_valid_i) begin
            xop[n_elems[SW-1:0]]   <= ld_data_i;
            acc[n_elems[SW-1:0]]   <= '0;  // the first product is x * 0
            sbase[n_elems[SW-1:0]] <= ld_base_i;
            sdeg[n_elems[SW-1:0]]  <= ld_deg_i;
            sfrac[n_elems[SW-1:0]] <= ld_frac_i;
            n_elems                <= n_elems + 1;
            if (n_elems == '0 || ld_deg_i > max_deg) max_deg <= ld_deg_i;
          end
          if (start_i && (n_elems != '0 || ld_valid_i)) begin
            state <= RUN;
            slot  <= '0;
            round <= '0;
          end
        end

        RUN: begin
          // One slot per cycle, padded to `period` so a round is never shorter than the recurrence.
          if ({1'b0, slot} == period - 1) begin
            slot <= '0;
            if (round == max_deg) state <= DRAIN;
            else round <= round + 1;
          end else begin
            slot <= slot + 1;
          end
        end

        DRAIN: begin
          // Count out the in-flight steps rather than watching the valid pipeline.
          if (int'(drain_cnt) == LOOP + 1) begin
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

`ifdef SYNTHESIS
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_done;
  assign unused_done = step_done;  // checked below in simulation only
  /* verilator lint_on UNUSEDSIGNAL */
`else
  // The step's done is the write-back's valid: a step whose result landed on another cycle would pair it with the wrong slot.
  a_step_pairs: assert property (@(posedge clk_i) disable iff (!rstn_i) step_done == v_dly[LOOP-1])
    else $error("barrel_mac: a_step_pairs: the Horner step's done_o is not the write-back's valid");
  // A load comes only while loading, and a group never takes more than K slots.
  a_load_room: assert property (@(posedge clk_i) disable iff (!rstn_i) ld_valid_i |-> (state == LOAD && int'(n_elems) < K))
    else $error("barrel_mac: a_load_room: a load while busy or into a full group (%0d slots)", n_elems);
`endif
endmodule
