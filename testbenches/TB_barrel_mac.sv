`timescale 1ns / 100ps

// barrel_mac in the build's format against barrel_mac_vectors.py (gpnae_model's Horner step), bit for bit, each slot on its own set,
// with done and busy checks; the coefficient memory is the bench's, read registered as gpnae_coef_mem reads.
module TB_barrel_mac;
  localparam int NG = 256;  // groups, as the vector script writes them
  localparam int K = 16;
  localparam int W = sienna_fmt_pkg::ACTIVATION_DATA_WIDTH;
  localparam int AW = 7;
  localparam string FMT = sienna_fmt_pkg::FORMAT_NAME;

  logic clk = 1'b0;
  logic rstn = 1'b0;  // reset held from power-up
  logic ld_valid = 1'b0, start = 1'b0;
  logic [W-1:0] ld_data = '0;
  logic [AW-1:0] ld_base = '0;
  logic [3:0] ld_deg = '0;
  logic [1:0] ld_frac = '0;
  logic res_valid, busy, done;
  logic [W-1:0] res_data;
  logic [AW-1:0] caddr;
  logic [W-1:0] cdata;

  logic [W-1:0] mem[1 << AW];
  logic [7:0] hdr[NG];
  logic [W+15:0] slot[NG*K];  // {frac, deg, base, operand}
  logic [W-1:0] want[NG*K];

  always_ff @(posedge clk) cdata <= mem[caddr];

  barrel_mac #(.K(K), .COEF_ADDR_W(AW)) dut (
      .clk_i(clk), .rstn_i(rstn), .ld_valid_i(ld_valid), .ld_data_i(ld_data), .ld_base_i(ld_base), .ld_deg_i(ld_deg), .ld_frac_i(ld_frac),
      .start_i(start), .coeff_addr_o(caddr), .coeff_data_i(cdata), .res_valid_o(res_valid), .res_data_o(res_data), .busy_o(busy),
      .done_o(done)
  );

  always #5 clk = ~clk;

  // One context drives and samples, 1 ns after each edge: Verilator's threaded scheduler is not coherent across contexts.
  task automatic tick();
    @(posedge clk);
    #1;
  endtask

  initial begin
    int n, errs, got, guard, shown;
    time t0;
    errs = 0;
    shown = 0;
    $readmemh({"testbenches/stimulus/bm_", FMT, "_mem.mem"}, mem);
    $readmemh({"testbenches/stimulus/bm_", FMT, "_hdr.mem"}, hdr);
    $readmemh({"testbenches/stimulus/bm_", FMT, "_slot.mem"}, slot);
    $readmemh({"testbenches/stimulus/bm_", FMT, "_exp.mem"}, want);
    repeat (8) tick();
    rstn = 1'b1;
    tick();
    t0 = $time;
    for (int g = 0; g < NG; g++) begin
      n = int'(hdr[g]);
      for (int i = 0; i < n; i++) begin
        ld_valid = 1'b1;
        {ld_frac, ld_deg, ld_base, ld_data} = {slot[g*K+i][W+13:W+12], slot[g*K+i][W+11:W+8], slot[g*K+i][W+6:W], slot[g*K+i][W-1:0]};
        tick();
      end
      ld_valid = 1'b0;
      start    = 1'b1;
      tick();
      start = 1'b0;
      got   = 0;
      guard = 0;
      while (got < n && guard < 4000) begin
        tick();
        guard++;
        if (res_valid) begin
          if (res_data !== want[g*K+got]) begin
            errs++;
            if (shown++ < 20)
              $display("[FAIL] group %0d slot %0d (n %0d, operand %h base %0d degree %0d frac %0d): got %h, want %h", g, got, n,
                       slot[g*K+got][W-1:0], slot[g*K+got][W+6:W], slot[g*K+got][W+11:W+8], slot[g*K+got][W+13:W+12], res_data, want[g*K+got]);
          end
          if ((got == n - 1) != done) begin
            errs++;
            if (shown++ < 20) $display("[FAIL] group %0d slot %0d: done_o %b", g, got, done);
          end
          got++;
        end
      end
      if (got != n) begin
        errs++;
        $display("[FAIL] group %0d: %0d of %0d results", g, got, n);
      end
      tick();
      if (busy) begin
        errs++;
        $display("[FAIL] group %0d: busy_o high after the last result", g);
      end
    end
    $display("TB_barrel_mac %s: %0d groups, %0d errors, %0d cycles", FMT, NG, errs, ($time - t0) / 10);
    $display("RESULT: %s", errs == 0 ? "PASSED" : "FAILED");
    $finish;
  end
endmodule
