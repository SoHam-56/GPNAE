`timescale 1ns / 100ps

// barrel_mac's int8 branch against ipu.fx_mac Horner (barrel_mac_int8_vectors.py), bit for bit, with done/busy checks.
module TB_barrel_mac_int8;
  localparam int NG = 256;  // groups, as the vector script writes them
  localparam int K = 16;
  localparam int W = 16;

  logic clk = 1'b0;
  logic rstn = 1'b0;  // reset held from power-up
  logic ld_valid = 1'b0, start = 1'b0;
  logic [W-1:0] ld_data = '0;
  logic [4:0] terms = '0, base = '0;
  logic res_valid, busy, done;
  logic [W-1:0] res_data;

  logic [31:0] hdr[NG];
  logic [W-1:0] opd[NG*K];
  logic [W-1:0] want[NG*K];

  barrel_mac #(
      .EXP_W(0), .MAN_W(7), .DATA_WIDTH(W), .ADDR_LINES(5), .K(K),
      .INIT_FILE("testbenches/stimulus/bm_int8_rom.mem")
  ) dut (
      .clk_i(clk), .rstn_i(rstn), .ld_valid_i(ld_valid), .ld_data_i(ld_data), .start_i(start),
      .terms_i(terms), .coeff_base_i(base), .res_valid_o(res_valid), .res_data_o(res_data),
      .busy_o(busy), .done_o(done)
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
    $readmemh("testbenches/stimulus/bm_int8_hdr.mem", hdr);
    $readmemh("testbenches/stimulus/bm_int8_in.mem", opd);
    $readmemh("testbenches/stimulus/bm_int8_exp.mem", want);
    repeat (8) tick();
    rstn = 1'b1;
    tick();
    t0 = $time;
    for (int g = 0; g < NG; g++) begin
      n     = int'(hdr[g][23:16]);
      terms = hdr[g][12:8];
      base  = hdr[g][4:0];
      for (int i = 0; i < n; i++) begin
        ld_valid = 1'b1;
        ld_data  = opd[g*K+i];
        tick();
      end
      ld_valid = 1'b0;
      start    = 1'b1;
      tick();
      start = 1'b0;
      got   = 0;
      guard = 0;
      while (got < n && guard < 1000) begin
        tick();
        guard++;
        if (res_valid) begin
          if (res_data !== want[g*K+got]) begin
            errs++;
            if (shown++ < 20)
              $display("[FAIL] group %0d slot %0d (n %0d degree %0d base %0d operand %h): got %h, want %h", g, got, n,
                       terms, base, opd[g*K+got], res_data, want[g*K+got]);
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
    $display("TB_barrel_mac_int8: %0d groups, %0d errors, %0d cycles", NG, errs, ($time - t0) / 10);
    $display("RESULT: %s", errs == 0 ? "PASSED" : "FAILED");
    $finish;
  end
endmodule
