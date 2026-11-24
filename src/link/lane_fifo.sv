`timescale 1ns / 100ps

// The poly lanes' input FIFO: circular, so order holds under any mix of writes and pops; read timing as InputFIFO's.
module lane_fifo #(
    parameter int DATA_WIDTH = 32,
    parameter int ADDR_LINES = 5
) (
    input  logic                  clk_i,
    input  logic                  rstn_i,
    input  logic                  wr_en_i,  // a write while full is taken only beside a pop
    input  logic                  rd_en_i,  // a pop while empty is ignored
    input  logic [DATA_WIDTH-1:0] data_i,
    output logic [  ADDR_LINES:0] count_o,
    output logic [DATA_WIDTH-1:0] data_o,   // the word at the read pointer two cycles earlier
    output logic [DATA_WIDTH-1:0] next_o    // the word data_o shows at the next cycle
);
  localparam int DEPTH = 1 << ADDR_LINES;

  logic [DATA_WIDTH-1:0] mem[DEPTH];
  logic [ADDR_LINES-1:0] wp, rp;
  logic [ADDR_LINES:0] cnt;
  logic [DATA_WIDTH-1:0] ram_q, dout_q;
  logic wr, rd;
  // The write a cycle on, from registers (in_put_i -> the full check -> every slot's write enable was the lanes' input path, 0.94-1.07 ns
  // at 0.8); the read of the slot it lands in takes the registered word instead, so every word reaches ram_q on the same cycle as before.
  logic                  wr_q;
  logic [ADDR_LINES-1:0] wp_q;
  logic [DATA_WIDTH-1:0] wd_q;

  assign rd      = rd_en_i && (cnt != '0);
  assign wr      = wr_en_i && ((cnt != (ADDR_LINES + 1)'(DEPTH)) || rd);
  assign count_o = cnt;
  assign data_o  = dout_q;
  assign next_o  = ram_q;

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) wr_q <= 1'b0;
    else wr_q <= wr;
  always_ff @(posedge clk_i)
    if (wr) begin  // no reset: used only with wr_q
      wp_q <= wp;
      wd_q <= data_i;
    end

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      wp  <= '0;
      rp  <= '0;
      cnt <= '0;
    end else begin
      if (wr) wp <= wp + 1'b1;
      if (rd) rp <= rp + 1'b1;
      cnt <= cnt + (ADDR_LINES + 1)'(wr) - (ADDR_LINES + 1)'(rd);
    end
  end

  // As InputFIFO's dual_port_ram: port B reads the head while a word is held, then an output register.
  always_ff @(posedge clk_i) begin
    if (wr_q) mem[wp_q] <= wd_q;
    if (cnt != '0) ram_q <= (wr_q && wp_q == rp) ? wd_q : mem[rp];
    dout_q <= ram_q;
  end

`ifndef SYNTHESIS
  // The words as the write-at-once FIFO held them: ram_q must be what it read whenever the FIFO holds a word.
  logic [DATA_WIDTH-1:0] ref_mem[DEPTH];
  logic [DATA_WIDTH-1:0] ref_ram;
  logic                  ref_v;
  always_ff @(posedge clk_i) begin
    if (wr) ref_mem[wp] <= data_i;
    if (cnt != '0) ref_ram <= ref_mem[rp];
    ref_v <= rstn_i && (cnt != '0);
  end
  a_ram_ref: assert property (@(posedge clk_i) disable iff (!rstn_i) ref_v |-> ram_q == ref_ram)
    else $error("lane_fifo: a_ram_ref: the head read %h is not the write-at-once read %h", ram_q, ref_ram);
`endif
endmodule
