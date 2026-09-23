`timescale 1ns / 100ps

// Activation tails for gpnae_poly, for inputs past the fitted polynomials' range.
// Computes e^a for a <= 0 without cancellation: halve to |z| <= 1, Taylor e^z - 1, then double back.
// SELU x < -4: lambda*alpha*(e^x - 1).  sigmoid |x| > 3.5: E(1 - E(1 - E)), E = e^-|x|.
// tanh |x| > 4: 1 - 2*E(1 - E(1 - E)), E = e^-2|x|, with the sign of x.
module gpnae_tail (
    input logic clk_i,
    input logic rstn_i,

    input logic        start_i,
    input logic [31:0] x_i,
    input logic [ 1:0] func_i,  // 01 SELU, 10 sigmoid, 11 tanh

    output logic [31:0] result_o,
    output logic        done_o,
    output logic        busy_o
);

  localparam logic [31:0] ONE = 32'h3F800000;
  localparam logic [31:0] TWO = 32'h40000000;
  localparam logic [31:0] LA = 32'h3FE10966;  // lambda * alpha
  localparam logic [30:0] BIG = 31'h42D00000;  // |a| > 104: e^a is below every fp32 value

  // 1/(k+1)! for k = 0..10
  logic [31:0] cinv[11];
  assign cinv[0]  = 32'h3F800000;
  assign cinv[1]  = 32'h3F000000;
  assign cinv[2]  = 32'h3E2AAAAB;
  assign cinv[3]  = 32'h3D2AAAAB;
  assign cinv[4]  = 32'h3C088889;
  assign cinv[5]  = 32'h3AB60B61;
  assign cinv[6]  = 32'h39500D01;
  assign cinv[7]  = 32'h37D00D01;
  assign cinv[8]  = 32'h3638EF1D;
  assign cinv[9]  = 32'h3493F27E;
  assign cinv[10] = 32'h32D7322B;

  typedef enum logic [4:0] {
    T_IDLE,
    T_TAY_MUL,   // acc * z
    T_TAY_ADD,   // + 1/(k+1)!
    T_TAY_FIN,   // d = z * acc
    T_SELU_ADD,  // t = d + 2
    T_SELU_MUL,  // d = d * t
    T_SELU_OUT,  // lambda * alpha * d
    T_E1,        // E = 1 + d
    T_SQ,        // E = E * E
    T_U,         // u = 1 - E
    T_V,         // v = E * u
    T_W,         // w = 1 - v
    T_S,         // s = E * w
    T_SIG_OUT,   // 1 - s
    T_TANH_OUT,  // 1 - 2 s
    T_DONE
  } tstate_t;
  tstate_t st;

  logic [31:0] x, z, acc, d, e, s, tmp;
  logic [ 1:0] fn;
  logic [ 3:0] k;
  logic [ 3:0] m;
  logic        issued;

  logic [31:0] mul_a, mul_b, mul_res, add_a, add_b, add_res;
  logic mul_valid, mul_done, add_valid, add_done;

  fp32Multiplier TMUL (
      .clk_i      (clk_i),
      .rstn_i     (rstn_i),
      .valid_i    (mul_valid),
      .A          (mul_a),
      .B          (mul_b),
      .result_o   (mul_res),
      .done_o     (mul_done),
      .overflow_o (),
      .underflow_o(),
      .invalid_o  ()
  );

  fp32Adder TADD (
      .clk_i      (clk_i),
      .rstn_i     (rstn_i),
      .valid_i    (add_valid),
      .A          (add_a),
      .B          (add_b),
      .result_o   (add_res),
      .done_o     (add_done),
      .overflow_o (),
      .underflow_o(),
      .invalid_o  ()
  );

  assign busy_o = (st != T_IDLE);

  // Negate for subtraction.
  function automatic logic [31:0] neg(input logic [31:0] v);
    return {~v[31], v[30:0]};
  endfunction

  always_ff @(posedge clk_i or negedge rstn_i) begin
    if (!rstn_i) begin
      st        <= T_IDLE;
      issued    <= 1'b0;
      mul_valid <= 1'b0;
      add_valid <= 1'b0;
      done_o    <= 1'b0;
      result_o  <= '0;
      {x, z, acc, d, e, s, tmp} <= '0;
      fn <= '0;
      k  <= '0;
      m  <= '0;
    end else begin
      mul_valid <= 1'b0;
      add_valid <= 1'b0;
      done_o    <= 1'b0;

      case (st)
        T_IDLE: begin
          if (start_i) begin
            automatic logic [31:0] a;
            // a = x (SELU), -|x| (sigmoid), -2|x| (tanh)
            case (func_i)
              2'b01:   a = x_i;
              2'b10:   a = {1'b1, x_i[30:0]};
              default: a = (x_i[30:23] >= 8'd133) ? {1'b1, BIG + 31'd1} : {1'b1, x_i[30:23] + 8'd1, x_i[22:0]};
            endcase
            x  <= x_i;
            fn <= func_i;
            if (a[30:0] > BIG) begin
              // e^a underflows: e^a - 1 = -1 and e^a = 0
              d  <= {1'b1, ONE[30:0]};
              e  <= '0;
              st <= (func_i == 2'b01) ? T_SELU_OUT : T_U;
            end else begin
              if (a[30:23] < 8'd127) begin
                z <= a;
                m <= '0;
              end else begin
                z <= {a[31], 8'd126, a[22:0]};  // |z| in [0.5, 1)
                m <= 4'(a[30:23] - 8'd126);
              end
              acc <= cinv[10];
              k   <= 4'd9;
              st  <= T_TAY_MUL;
            end
            issued <= 1'b0;
          end
        end

        T_TAY_MUL: begin
          if (!issued) begin
            mul_a <= acc;
            mul_b <= z;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            tmp <= mul_res;
            issued <= 1'b0;
            st <= T_TAY_ADD;
          end
        end

        T_TAY_ADD: begin
          if (!issued) begin
            add_a <= tmp;
            add_b <= cinv[k];
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            acc <= add_res;
            issued <= 1'b0;
            if (k == 0) st <= T_TAY_FIN;
            else begin
              k  <= k - 1'b1;
              st <= T_TAY_MUL;
            end
          end
        end

        T_TAY_FIN: begin
          if (!issued) begin
            mul_a <= z;
            mul_b <= acc;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            d <= mul_res;
            issued <= 1'b0;
            if (fn == 2'b01) st <= (m == 0) ? T_SELU_OUT : T_SELU_ADD;
            else st <= T_E1;
          end
        end

        T_SELU_ADD: begin
          if (!issued) begin
            add_a <= d;
            add_b <= TWO;
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            tmp <= add_res;
            issued <= 1'b0;
            st <= T_SELU_MUL;
          end
        end

        T_SELU_MUL: begin
          if (!issued) begin
            mul_a <= d;
            mul_b <= tmp;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            d <= mul_res;
            issued <= 1'b0;
            m <= m - 1'b1;
            st <= (m == 4'd1) ? T_SELU_OUT : T_SELU_ADD;
          end
        end

        T_SELU_OUT: begin
          if (!issued) begin
            mul_a <= LA;
            mul_b <= d;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            result_o <= mul_res;
            issued <= 1'b0;
            st <= T_DONE;
          end
        end

        T_E1: begin
          if (!issued) begin
            add_a <= ONE;
            add_b <= d;
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            e <= add_res;
            issued <= 1'b0;
            st <= (m == 0) ? T_U : T_SQ;
          end
        end

        T_SQ: begin
          if (e[30:23] < 8'd64) begin
            // E^2 would fall below the fp32 normal range, and the chain is exact at 0
            e  <= '0;
            m  <= '0;
            st <= T_U;
          end else if (!issued) begin
            mul_a <= e;
            mul_b <= e;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            e <= mul_res;
            issued <= 1'b0;
            m <= m - 1'b1;
            st <= (m == 4'd1) ? T_U : T_SQ;
          end
        end

        T_U: begin
          if (!issued) begin
            add_a <= ONE;
            add_b <= neg(e);
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            tmp <= add_res;
            issued <= 1'b0;
            st <= T_V;
          end
        end

        T_V: begin
          if (!issued) begin
            mul_a <= e;
            mul_b <= tmp;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            tmp <= mul_res;
            issued <= 1'b0;
            st <= T_W;
          end
        end

        T_W: begin
          if (!issued) begin
            add_a <= ONE;
            add_b <= neg(tmp);
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            tmp <= add_res;
            issued <= 1'b0;
            st <= T_S;
          end
        end

        T_S: begin
          if (!issued) begin
            mul_a <= e;
            mul_b <= tmp;
            mul_valid <= 1'b1;
            issued <= 1'b1;
          end else if (mul_done) begin
            s <= mul_res;
            issued <= 1'b0;
            if (fn == 2'b10) begin
              if (x[31]) begin
                result_o <= mul_res;
                st <= T_DONE;
              end else st <= T_SIG_OUT;
            end else st <= T_TANH_OUT;
          end
        end

        T_SIG_OUT: begin
          if (!issued) begin
            add_a <= ONE;
            add_b <= neg(s);
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            result_o <= add_res;
            issued <= 1'b0;
            st <= T_DONE;
          end
        end

        T_TANH_OUT: begin
          if (!issued) begin
            add_a <= ONE;
            // 2s as an exponent increment
            add_b <= (s[30:0] == '0) ? 32'h80000000 : {1'b1, s[30:23] + 8'd1, s[22:0]};
            add_valid <= 1'b1;
            issued <= 1'b1;
          end else if (add_done) begin
            result_o <= {x[31], add_res[30:0]};
            issued <= 1'b0;
            st <= T_DONE;
          end
        end

        T_DONE: begin
          done_o <= 1'b1;
          st     <= T_IDLE;
        end

        default: st <= T_IDLE;
      endcase
    end
  end

endmodule
