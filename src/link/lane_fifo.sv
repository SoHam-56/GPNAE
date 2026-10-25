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
    output logic [DATA_WIDTH-1:0] data_o    // the word at the read pointer two cycles earlier
);
  localparam int DEPTH = 1 << ADDR_LINES;

  logic [DATA_WIDTH-1:0] mem[DEPTH];
  logic [ADDR_LINES-1:0] wp, rp;
  logic [ADDR_LINES:0] cnt;
  logic [DATA_WIDTH-1:0] ram_q, dout_q;
  logic wr, rd;

  assign rd      = rd_en_i && (cnt != '0);
  assign wr      = wr_en_i && ((cnt != (ADDR_LINES + 1)'(DEPTH)) || rd);
  assign count_o = cnt;
  assign data_o  = dout_q;

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
    if (wr) mem[wp] <= data_i;
    if (cnt != '0) ram_q <= mem[rp];
    dout_q <= ram_q;
  end
endmodule
