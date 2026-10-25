`timescale 1ns / 100ps

// The gpnae lane's coefficient memory layout and element kinds, shared by its modules and the host's loader (gpnae_model.py mirrors it).
package gpnae_pkg;
  /* verilator lint_save */
  /* verilator lint_off UNUSEDPARAM */  // a package of constants: no single module reads every one
  /* verilator lint_off UNUSEDSIGNAL */  // the field decodes take the load path's 32-bit word
  localparam int ACT_W = sienna_fmt_pkg::ACTIVATION_DATA_WIDTH;
  localparam int COEF_WORDS = 128;  // coefficient words, ACT_W bits each
  localparam int COEF_ADDR_W = 7;
  localparam int NUM_TIERS = 3;  // accuracy tiers: 0 within 1%, 1 within 5%, 2 within 10%
  localparam int NUM_DESC = 4;  // per tier: SELU's x < 0 side, sigmoid x >= 0, sigmoid x < 0, tanh
  localparam int D_SELU = 0, D_SIGP = 1, D_SIGN = 2, D_TANH = 3;
  localparam int PMAX = 6;  // pieces per descriptor
  localparam int TAIL_MAXC = 6;  // coefficients of the fp32 tail's set (bf16)
  localparam int LOAD_ADDR_W = 9;  // the load path's word address
  localparam int A_DESC = COEF_WORDS;  // descriptor fields from here, 16 words per descriptor in tier-major order
  localparam int DESC_STRIDE = 16;
  localparam int A_TAIL = A_DESC + NUM_TIERS * NUM_DESC * DESC_STRIDE;  // the tail sets from here, 8 words per tier
  localparam int TAIL_STRIDE = 8;
  localparam int N_FIELDS = A_TAIL + NUM_TIERS * TAIL_STRIDE - A_DESC;  // field words after the coefficients
  localparam int F_SET = PMAX, F_EXP = PMAX + 1, F_CENTER = PMAX + 2, F_FRAC = PMAX + 3;  // a descriptor's words after its bounds

  // One descriptor: piece p of np at base + p (deg + 1) for bound[p - 1] <= |x| < bound[p]; past bound[np - 1], the region beyond.
  typedef struct packed {
    logic [PMAX-1:0][ACT_W-1:0] bound;  // floats compare the magnitude bits, int8 the Q4.11 magnitude
    logic [2:0]  np;
    logic [3:0]  deg;
    logic [COEF_ADDR_W-1:0] base;
    logic        reflect;  // sigmoid x < 0: the pieces give 1 - P
    logic [COEF_ADDR_W-1:0] exp_base;  // fp32 sigmoid x < 0 beyond the pieces: 2^-n P(f) with this set
    logic [3:0]  exp_deg;
    logic [ACT_W-1:0] center;  // int8: the operand is x - center (SELU) or |x| - center
    logic [1:0]  frac;  // int8: fixedPointMultiplyAdd's extra fraction bits
  } desc_t;

  // bf16's fp32 tail set for a tier: P(f) ~ 2^-f, lowest coefficient first, and the reciprocal's Newton steps.
  typedef struct packed {
    logic [TAIL_MAXC-1:0][31:0] coef;
    logic [2:0] deg;
    logic [1:0] newton;
  } tail_t;

  // Element kinds, the post stage's cases.
  typedef enum logic [2:0] {
    K_LIN  = 3'd0,  // SELU x >= 0: lambda x
    K_MUL  = 3'd1,  // x P: SELU x < 0, tanh (int8 tanh: the signed P)
    K_ONE  = 3'd2,  // floats' tanh at tiny |x|: x 1.0
    K_PASS = 3'd3,  // P: sigmoid x >= 0, a Q set for x < 0; int8 tanh's signed P
    K_REFL = 3'd4,  // 1 - P: sigmoid x < 0 on a reflected set
    K_SAT  = 3'd5,  // the function's limit
    K_EXP  = 3'd6,  // fp32 sigmoid x < 0 beyond: E (1 - E), E = 2^-n P(f)
    K_TAIL = 3'd7   // bf16 sigmoid x < 0 beyond: the fp32 tail's result
  } kind_t;

  // A field word written into a descriptor: j < PMAX a bound, then {reflect[16], base[14:8], deg[7:4], np[2:0]}, {exp_deg, exp_base},
  // the center, the frac.
  function automatic desc_t desc_field(input desc_t d, input int j, input logic [31:0] v);
    desc_t r = d;
    if (j < PMAX) r.bound[j] = v[ACT_W-1:0];
    else if (j == F_SET) begin
      r.np      = v[2:0];
      r.deg     = v[7:4];
      r.base    = v[8+:COEF_ADDR_W];
      r.reflect = v[16];
    end else if (j == F_EXP) begin
      r.exp_base = v[0+:COEF_ADDR_W];
      r.exp_deg  = v[11:8];
    end else if (j == F_CENTER) r.center = v[ACT_W-1:0];
    else if (j == F_FRAC) r.frac = v[1:0];
    return r;
  endfunction

  // A field word written into a tail set: j < TAIL_MAXC a coefficient, j = TAIL_MAXC {newton[5:4], deg[2:0]}.
  function automatic tail_t tail_field(input tail_t t, input int j, input logic [31:0] v);
    tail_t r = t;
    if (j < TAIL_MAXC) r.coef[j] = v;
    else if (j == TAIL_MAXC) begin
      r.deg    = v[2:0];
      r.newton = v[5:4];
    end
    return r;
  endfunction
  /* verilator lint_restore */
endpackage
