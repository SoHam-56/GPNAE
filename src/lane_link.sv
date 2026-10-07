`timescale 1ns / 100ps

// A poly lane's credit front end: input credits per FIFO slot, the last bit, the K-credit group gate, output credits and the link checks.
module lane_link #(
    parameter int DATA_WIDTH = 32,
    parameter int ADDR_LINES = 5,
    parameter int K          = 16,
    parameter int OUT_MAX    = 64,  // the most output credits the downstream consumer may advertise
    parameter int OUT_CRW    = 1    // out.credit width
) (
    input logic clk_i,
    input logic rstn_i,

    credit_link_if.consumer in,   // the lane's FIFO takes put and data; the credits go back from here
    credit_link_if.producer out,  // the lane's results, one per put

    input  logic                           fifo_pop_i,    // a word leaves the FIFO this cycle
    input  logic [           ADDR_LINES:0] fifo_count_i,
    input  logic                           idle_i,        // the lane is in G_IDLE
    input  logic                           next_i,        // the lane is in G_NEXT
    input  logic                           res_put_i,     // a result this cycle
    input  logic [         DATA_WIDTH-1:0] res_data_i,
    input  logic                           cap_i,         // a word is captured from the FIFO this cycle
    input  logic [         DATA_WIDTH-1:0] cap_data_i,
    output logic                           grp_go_o,      // start a group this cycle
    output logic                           out_ok_o,      // K output credits held, past this cycle's put
    output logic                           last_pend_o,   // a last put waits for its group to start
    output logic [$clog2(OUT_MAX + 1)-1:0] out_cnt_o
);

  if (OUT_MAX < K) begin : G_BAD_OUT_MAX
    $fatal(1, "lane_link: OUT_MAX %0d is below K %0d, so no group could start", OUT_MAX, K);
  end
`ifndef SYNTHESIS
  // Interface widths are not elaboration constants in Verilator, so the link widths are checked at time 0.
  initial
    if ($bits(in.data) != DATA_WIDTH + 1 || $bits(out.data) != DATA_WIDTH || $bits(out.credit) != OUT_CRW)
      $fatal(1, "lane_link: links need in.data %0d bits, out.data %0d, out.credit OUT_CRW %0d", DATA_WIDTH + 1, DATA_WIDTH, OUT_CRW);
`endif

  // Input link: one credit per free FIFO slot, 2**ADDR_LINES after reset, then one per pop, at most one a cycle.
  logic [ADDR_LINES:0] in_owed;  // freed slots not yet credited
  logic in_cr, last_pend;
  assign in.credit   = in_cr;
  assign last_pend_o = last_pend;

  // Output link: a group of up to K starts only with K credits, so nothing in flight waits on the consumer mid-group.
  localparam int OCW = $clog2(OUT_MAX + 1);
  logic [OCW-1:0] out_cnt;
  credit_counter #(.MAX(OUT_MAX), .CRW(OUT_CRW)) out_cc (.clk_i(clk_i), .rstn_i(rstn_i), .put_i(res_put_i), .credit_i(out.credit),
                                                        .has_credit_o(), .count_o(out_cnt));
  assign out_cnt_o = out_cnt;
  assign out_ok_o  = int'(out_cnt) >= K + int'(res_put_i);  // a put this cycle spends its credit at this edge
  assign out.put   = res_put_i;
  assign out.data  = res_data_i;

  // A set waits in the FIFO for its last put; G_NEXT then takes whatever is queued.
  assign grp_go_o = (fifo_count_i != '0) && out_ok_o && ((idle_i && last_pend) || next_i);

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      in_owed   <= (ADDR_LINES + 1)'(1 << ADDR_LINES);
      in_cr     <= 1'b0;
      last_pend <= 1'b0;
    end else begin
      in_owed   <= in_owed + (ADDR_LINES + 1)'(fifo_pop_i) - (ADDR_LINES + 1)'(in_owed != '0);
      in_cr     <= in_owed != '0;
      // A last put sets it, a group start clears it; the start counts the FIFO before a put in the same cycle.
      if (in.put && in.data[DATA_WIDTH]) last_pend <= 1'b1;
      else if (grp_go_o) last_pend <= 1'b0;
    end
  end

`ifndef SYNTHESIS
  // A put needs a free slot: with 32 words held no credit can be outstanding.
  a_in_room: assert property (@(posedge clk_i) disable iff (!rstn_i) in.put |-> int'(fifo_count_i) < (1 << ADDR_LINES))
    else $error("lane_link: a_in_room: put into a full input FIFO");
  // Every captured word is the oldest one put and not yet captured: no reorder, loss or overwrite in the FIFO.
  logic [DATA_WIDTH-1:0] in_shadow[$];
  always @(posedge clk_i)
    if (!rstn_i) in_shadow.delete();
    else begin
      if (cap_i) begin
        a_in_order: assert (in_shadow.size() != 0 && cap_data_i == in_shadow[0])
        else $error("lane_link: a_in_order: captured %h, the oldest word put is %h", cap_data_i,
                    (in_shadow.size() != 0) ? in_shadow[0] : '0);
        if (in_shadow.size() != 0) void'(in_shadow.pop_front());
      end
      if (in.put) in_shadow.push_back(in.data[DATA_WIDTH-1:0]);
    end
`endif
endmodule
