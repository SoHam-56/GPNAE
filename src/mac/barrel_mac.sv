`timescale 1ns / 100ps

// Barrel TYTAN MAC: up to K elements share one Horner step (gpnae_horner), round-robin, in lockstep on the round index, like a barrel
// processor that rotates through contexts to fill the step's pipeline. Each slot has its own coefficient set (base and degree) and,
// in int8, its own fraction shift; a round issues one step per slot, so it costs max(n, LOOP + 1) cycles. The group runs
// max(degree) + 1 rounds; a slot of lower degree joins at its own degree, its earlier rounds writing its accumulator back as 0, so its
// result never depends on its group. Coefficients come from the lane's memory on coeff_addr_o, read back on coeff_data_i
// gpnae_pkg::COEF_READ_LATENCY cycles later. No format here: the step's latency and coefficient lag are the package's.
module barrel_mac #(
    parameter int  K           = 32,
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

    // Coefficient memory read: the word at coeff_addr_o is on coeff_data_i READ cycles later.
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
  localparam int READ    = gpnae_pkg::COEF_READ_LATENCY;  // the memory's address-to-data cycles
  localparam int MIN_PER = LOOP + 1;  // write-back lands a cycle after that
  localparam int SW      = $clog2(K);
  localparam int ADDR_AT = LAG - READ;  // cycles after the issue the address is on coeff_addr_o

  typedef enum logic [1:0] {LOAD, RUN, DRAIN, EMIT} state_t;

  // The slots.
  logic [      ACT_W-1:0] xop  [K];  // operands, one per slot
  logic [      ACT_W-1:0] acc  [K];  // accumulators, one per slot
  logic [COEF_ADDR_W-1:0] sbase[K];
  logic [            3:0] sdeg [K];
  logic [            1:0] sfrac[K];
  // The group.
  logic [SW:0] n_elems;  // how many slots this group uses
  logic [ 3:0] max_deg;  // the group's highest degree: it runs max_deg + 1 rounds
  state_t state;
  logic [SW:0]   slot;  // slot being issued this cycle
  // The issuing slot's operands and degree, read a cycle early from slot_ahead (the next slot, a register): the K:1 selects off the
  // counter in front of the step were the K = 32 lanes' limit (fp32 top 1.02, s1_man_a). A write-back landing in that cycle for that
  // slot is forwarded, so a round stays max(n, LOOP + 1) cycles; the group's start forwards a word loaded in its own cycle.
  logic [SW:0]        slot_ahead;
  logic [ACT_W-1:0]   p_x, p_acc;
  logic [      1:0]   p_frac;
  logic [      3:0]   p_deg;
  logic [COEF_ADDR_W-1:0] p_base;  // the issuing slot's coefficient base, read a cycle early with the operands
  logic [SW+1:0] period;  // max(n_elems, LOOP + 1): a round never shortens below the recurrence
  logic [   3:0] round;  // 0 .. max_deg; round r reads c_(max_deg - r)
  logic [  SW:0] emit_idx;
  logic [$clog2(LOOP+2):0] drain_cnt;
  // Issue pipeline: slot, round and pad ride with each step, to address its coefficient READ cycles before stage LAG and write back at
  // LOOP - 1.
  logic          v_dly   [LOOP];
  logic [SW-1:0] slot_dly[LOOP];
  logic [   3:0] rnd_dly [LOOP];
  logic          pad_dly [LOOP];  // the step is a round before the slot's own degree: its result is replaced by 0
  // The step: its issue, pad, coefficient and result.
  logic             step_valid, step_done;
  logic [ACT_W-1:0] step_y, step_c;
  logic             iss_pad;  // the issuing round's index is above the slot's degree
  logic             c_pad;  // the coefficient's step is a pad, with the data at issue + LAG
`ifdef SYNTHESIS
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_done;  // step_done is checked in simulation only
  /* verilator lint_on UNUSEDSIGNAL */
`endif

  if (K < MIN_PER) begin : G_BAD_K
    $fatal(1, "barrel_mac: K %0d is below %0d, so a slot's accumulator would not be back before its next round", K, MIN_PER);
  end
  if (LAG < READ || LAG >= LOOP) begin : G_BAD_LAG
    $fatal(1, "barrel_mac: the coefficient lag %0d must be %0d (the memory read) to %0d", LAG, READ, LOOP - 1);
  end

  // The issuing slot's coefficient index is max_deg - round; a round whose index is above the slot's degree is a pad.
  assign step_valid = (state == RUN) && (slot < n_elems);
  assign iss_pad    = (max_deg - round) > p_deg;

  // The coefficient for the step issued LAG cycles ago: the address goes out READ cycles before, at issue + LAG - READ. When that is the
  // issue itself the address is combinational from the issue; otherwise it is registered the cycle before, from the issue when that is
  // the cycle before, else from the issue pipeline (the slot's base mux and the index add in one cycle with the memory's read mux was
  // the float lanes' worst path, so neither shares a cycle with the other).
  // The address from the prefetched base: computed once at the issue, then delayed to the address cycle (a K:1 base select off the
  // issue pipeline's slot, then the index add, was the int8 K = 32 top's 0.95, slot_dly -> coeff_addr_o).
  logic [COEF_ADDR_W-1:0] iss_addr;
  assign iss_addr = p_base + COEF_ADDR_W'(max_deg - round);
  if (ADDR_AT == 0) begin : G_ADDR_AT_ISSUE
    assign coeff_addr_o = iss_addr;
  end else if (ADDR_AT == 1) begin : G_ADDR_NEXT
    always_ff @(posedge clk_i) coeff_addr_o <= iss_addr;
  end else begin : G_ADDR_REGISTERED
    logic [COEF_ADDR_W-1:0] adr_dly[ADDR_AT-1];
    always_ff @(posedge clk_i) begin
      adr_dly[0] <= iss_addr;
      for (int i = 1; i < ADDR_AT - 1; i++) adr_dly[i] <= adr_dly[i-1];
      coeff_addr_o <= adr_dly[ADDR_AT-2];
    end
  end
  always_ff @(posedge clk_i) c_pad <= pad_dly[LAG-2];  // with the data, at issue + LAG
  assign step_c = c_pad ? '0 : coeff_data_i;

  gpnae_horner STEP (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(step_valid), .x_i(p_x), .acc_i(p_acc), .frac_i(p_frac), .c_i(step_c),
                     .y_o(step_y), .done_o(step_done));

  assign busy_o = (state != LOAD);
  assign period = (n_elems >= MIN_PER[SW:0]) ? {1'b0, n_elems} : MIN_PER[SW+1:0];

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      state       <= LOAD;
      n_elems     <= '0;
      max_deg     <= '0;
      slot        <= '0;
      slot_ahead  <= '0;
      {p_x, p_acc, p_frac, p_deg, p_base} <= '0;
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
            state      <= RUN;
            slot       <= '0;
            slot_ahead <= (SW + 1)'(1);  // a round is at least MIN_PER > 1 slots
            round      <= '0;
            // slot 0's operands for the first issue: round 0's accumulator is 0; a group of one loads its word in this cycle
            p_x    <= (ld_valid_i && n_elems == '0) ? ld_data_i : xop[0];
            p_acc  <= '0;
            p_frac <= (ld_valid_i && n_elems == '0) ? ld_frac_i : sfrac[0];
            p_deg  <= (ld_valid_i && n_elems == '0) ? ld_deg_i : sdeg[0];
            p_base <= (ld_valid_i && n_elems == '0) ? ld_base_i : sbase[0];
          end
        end

        RUN: begin
          // Next cycle's slot and its operands, the write-back landing now forwarded.
          slot_ahead <= ({1'b0, slot_ahead} == period - 1) ? '0 : slot_ahead + 1;
          p_x    <= xop[slot_ahead[SW-1:0]];
          p_acc  <= (v_dly[LOOP-1] && slot_dly[LOOP-1] == slot_ahead[SW-1:0]) ? (pad_dly[LOOP-1] ? '0 : step_y) : acc[slot_ahead[SW-1:0]];
          p_frac <= sfrac[slot_ahead[SW-1:0]];
          p_deg  <= sdeg[slot_ahead[SW-1:0]];
          p_base <= sbase[slot_ahead[SW-1:0]];
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
  assign unused_done = step_done;
`else
  // The step's done is the write-back's valid: a step whose result landed on another cycle would pair it with the wrong slot.
  a_step_pairs: assert property (@(posedge clk_i) disable iff (!rstn_i) step_done == v_dly[LOOP-1])
    else $error("barrel_mac: a_step_pairs: the Horner step's done_o is not the write-back's valid");
  // A load comes only while loading, and a group never takes more than K slots.
  a_load_room: assert property (@(posedge clk_i) disable iff (!rstn_i) ld_valid_i |-> (state == LOAD && int'(n_elems) < K))
    else $error("barrel_mac: a_load_room: a load while busy or into a full group (%0d slots)", n_elems);
  // The prefetch: slot_ahead is the next slot, and every issue's operands are what the slot holds when it issues.
  a_slot_ahead: assert property (@(posedge clk_i) disable iff (!rstn_i) state == RUN |->
      int'(slot_ahead) == ((int'(slot) == int'(period) - 1) ? 0 : int'(slot) + 1))
    else $error("barrel_mac: a_slot_ahead: slot_ahead %0d is not the slot after %0d (period %0d)", slot_ahead, slot, period);
  a_prefetch: assert property (@(posedge clk_i) disable iff (!rstn_i) step_valid |->
      p_x == xop[slot[SW-1:0]] && p_acc == acc[slot[SW-1:0]] && p_frac == sfrac[slot[SW-1:0]] && p_deg == sdeg[slot[SW-1:0]] &&
      p_base == sbase[slot[SW-1:0]])
    else $error("barrel_mac: a_prefetch: slot %0d issued with prefetched operands that are not its own", slot);
`endif
endmodule
