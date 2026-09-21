`timescale 1ns / 100ps

module InputFIFO #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_LINES = 5
) (
    input wire clk_i,
    input wire rstn_i,
    input wire wr_en_i,   // Write Enable
    input wire rd_en_i,   // Read Enable
    input wire [DATA_WIDTH-1:0] data_i,
    
    output wire full_o, empty_o, idle_o,
    output wire [ADDR_LINES:0] count_o,

    output wire [DATA_WIDTH-1:0] data_o
);

    reg [(1 << ADDR_LINES)-1:0] status;
    wire [ADDR_LINES - 1:0] wr_ptr, rd_ptr;
     
     PE5B cntr_write (      // Status reg's zeroes-detector
         .in(~status),
         .out(wr_ptr)
     );

     PE5B cntr_read (       // Status reg's ones-detector
         .in(status),
         .out(rd_ptr)
     );

    always @ (posedge clk_i or negedge rstn_i) begin
        if (~rstn_i)
            status <= 'b0;
        else begin
            // Independent set/clear: wr_ptr and rd_ptr never alias, and "else if" dropped a pop coinciding with a push.
            if (wr_en_i && ~status[wr_ptr])
                status[wr_ptr] <= 1'b1;
            if (rd_en_i && status[rd_ptr])
                status[rd_ptr] <= 1'b0;
        end
    end
    
    // FIFO status Flags
    assign full_o = status[(1 << ADDR_LINES)-1];
    assign empty_o = (status == 'b0);
    
    assign idle_o = ~(wr_en_i | rd_en_i);

    // Occupancy, so a consumer can pop a known number of words back to back. empty_o lags a pop
    // by a cycle, so a streaming reader cannot use it to decide when to stop without over-popping.
    reg [ADDR_LINES:0] occ;
    integer si;
    always @(*) begin
        occ = 0;
        for (si = 0; si < (1 << ADDR_LINES); si = si + 1) occ = occ + status[si];
    end
    assign count_o = occ;

    // regceb held high so data_o tracks rd_ptr; gating it on rd_en_i made the first pop re-present the same word.

    // PORT A --> Write
    // PORT B --> Read
    dual_port_ram #(
        .DATA_WIDTH(DATA_WIDTH),    // Specify RAM data width
        .ADDR_LINES(ADDR_LINES)     // Specify RAM (number of) address bits
    ) FIFO (
        .addra(wr_ptr),             // Port A address bus, width determined from RAM_DEPTH
        .addrb(rd_ptr),             // Port B address bus, width determined from RAM_DEPTH
        .dina(data_i),              // Port A RAM input data, width determined from DATA_WIDTH

        .clk_i(clk_i),              // Clock

        .wea(wr_en_i),                // Port A write enable
        .ena(~full_o),              // Port A RAM Enable, for additional power savings, disable port when not in use
        .enb(status[rd_ptr]),       // Port B RAM Enable, for additional power savings, disable port when not in use

        .rstnb(rstn_i),             // Port B output reset (does not affect memory contents)
        .regceb(1'b1),              // Port B output register enable (see above)

        .doutb(data_o)              // Port B RAM output data, width determined from DATA_WIDTH
    );
endmodule
