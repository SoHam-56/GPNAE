`timescale 1ns / 100ps

// The lane's input stage, one element per cycle: from its word and the tier's descriptors, the element's kind (the post stage's case),
// its coefficient set (base, degree) and the barrel MAC's operand. Its outputs come sienna_fmt_pkg::ACT_IN_LATENCY cycles after valid_i.
// Floats (LANE_MUL_LATENCY + 2): SELU x, sigmoid |x| (fp32 beyond its pieces for x < 0: f of k = |x| log2 e, with n), tanh x^2, on one fmt_mul.
// int8 (LANE_MUL_LATENCY + 5): x = rescale(q) on int16Multiplier, then over four stages the product rounded by the shift, x saturated with its
// sign and magnitude, the piece and kind with the centered operand x - c (SELU) or |x| - c, and the coefficient base, with the descriptor's
// fraction shift.
module gpnae_act_in
  import gpnae_pkg::*;
#(
    parameter int  IW         = 4,  // the element tag's width
    localparam int DATA_WIDTH = sienna_fmt_pkg::DATA_WIDTH
) (
    input logic                          clk_i,
    input logic                          rstn_i,
    input logic                          valid_i,
    input logic [                IW-1:0] idx_i,
    input logic [        DATA_WIDTH-1:0] word_i,  // the element as captured
    input logic [                   1:0] fn_i,  // 0 SELU, 1 sigmoid, 2 tanh
    input desc_t                         desc_i[NUM_DESC],
    input sienna_fmt_pkg::lane_params_t  par_i,  // int8: the input rescale; floats: a 1-bit dummy

    output logic                   valid_o,
    output logic [         IW-1:0] idx_o,
    output logic [      ACT_W-1:0] op_o,  // the MAC operand
    output logic [COEF_ADDR_W-1:0] base_o,
    output logic [            3:0] deg_o,  // 0 for an element that ignores P, so it never lengthens its group
    output logic [            1:0] frac_o,
    output kind_t                  kind_o,
    output logic                   neg_o,  // x < 0 (floats: sign set and magnitude nonzero)
    output logic [            7:0] n_o,  // fp32 K_EXP: E = P 2^-n
    output logic                   under_o,  // fp32 K_EXP: E is 0
    output logic [           23:0] aux_o  // int8: the rescale product r, SELU's post operand; floats 0
);
  localparam int MUL_LAT = sienna_fmt_pkg::LANE_MUL_LATENCY;
  /* verilator lint_off UNUSEDPARAM */
  localparam int FN_SELU = 0, FN_SIG = 1, FN_TANH = 2;  // int8 runs tanh in the else
  /* verilator lint_on UNUSEDPARAM */

  // The piece of |x| (mag, the magnitude bits of a bound): how many of the first np - 1 bounds it reaches; and whether it is past the last bound.
  function automatic logic [2:0] piece_idx(input logic [PMAX-1:0][ACT_W-1:0] bound, input logic [2:0] np, input logic [ACT_W-2:0] mag);
    int n;
    logic [2:0] p;
    n = (np == 3'd0) ? 1 : ((int'(np) > PMAX) ? PMAX : int'(np));
    p = '0;
    for (int j = 0; j < PMAX - 1; j++) if (j < n - 1 && mag >= bound[j][ACT_W-2:0]) p = p + 3'd1;
    return p;
  endfunction
  // piece_idx's compares, uncounted: bit j is set where the magnitude reaches bound j, j below np - 1.
  function automatic logic [PMAX-2:0] piece_ge(input logic [PMAX-1:0][ACT_W-1:0] bound, input logic [2:0] np, input logic [ACT_W-2:0] mag);
    int n;
    logic [PMAX-2:0] g;
    n = (np == 3'd0) ? 1 : ((int'(np) > PMAX) ? PMAX : int'(np));
    for (int j = 0; j < PMAX - 1; j++) g[j] = (j < n - 1) && (mag >= bound[j][ACT_W-2:0]);
    return g;
  endfunction
  function automatic logic beyond_of(input logic [PMAX-1:0][ACT_W-1:0] bound, input logic [2:0] np, input logic [ACT_W-2:0] mag);
    int n;
    logic [PMAX-1:0] gt;  // every bound compared at once, then the last one picked: np's select ahead of the compare was fp32's 1.08 ns
    n = (np == 3'd0) ? 1 : ((int'(np) > PMAX) ? PMAX : int'(np));
    for (int j = 0; j < PMAX; j++) gt[j] = mag > bound[j][ACT_W-2:0];
    return gt[n-1];
  endfunction

  function automatic logic uses_p(input kind_t k);
    return (k == K_MUL) || (k == K_PASS) || (k == K_REFL) || (k == K_EXP);
  endfunction

`ifdef FMT_INT8
  // ── int8: rescale on int16Multiplier, then round (stage R), saturate (A), classify and center (B), the base (C) ──
  // The rescale: q - z_in, its product r.
  logic signed [15:0] d_q;
  logic signed [31:0] r;
  logic               rm_done;
  // The index, function and shift ride beside the product for its MUL_LAT cycles.
  logic          s_v;
  logic [IW-1:0] s_idx;
  logic [   1:0] s_fn;
  logic [   4:0] s_shx;
  logic [MUL_LAT-1:0] sv_d;
  logic [IW-1:0] idx_d[MUL_LAT];
  logic [   1:0] fn_d[MUL_LAT];
  logic [   4:0] shx_d[MUL_LAT];
  // Stage R: r rounded half up by 2^shx.
  logic signed [32:0] rw, xr, xs;  // r plus the round bit fits 33 bits; xs = rw >>> shx
  logic xb;  // rw's bit just below the cut: the round half up
  logic               r_v, r_r31;
  logic [IW-1:0]      r_idx;
  logic [1:0]         r_fn;
  logic signed [32:0] r_xr;
  logic [23:0]        r_aux;
  // x = the rounded product saturated to Q4.11, its sign and magnitude.
  logic signed [15:0] x;
  logic        [14:0] mag;
  logic               neg;
  // Stage Q: q - z_in and the rescale words registered ahead of the multiply (the subtract into the multiplier's first tree stage was the
  // int8 lane's input path).
  logic               q_v;
  logic signed [15:0] q_d;
  logic        [15:0] q_mx;
  logic [IW-1:0]      q_idx;
  logic [1:0]         q_fn;
  logic [4:0]         q_shx;
  // Stage A: x, its sign and magnitude, r's sign and low bits.
  logic               a_v, a_neg, a_r31;
  logic [IW-1:0]      a_idx;
  logic [1:0]         a_fn;
  logic               a_selu;  // a_fn == FN_SELU, decoded a stage early (its decode into the operand select began int8's 1.18 ns a_fn -> b_op path)
  logic signed [15:0] a_x;
  logic [14:0]        a_mag;
  logic [23:0]        a_aux;
  desc_t              a_d;  // the function's descriptor by the sign, registered (the tier select into the bound compares was 1.24 ns at 45 nm)
  // Stage B: the descriptor's piece, kind, degree, fraction and base, and the centered operand.
  logic                   b_v, b_neg;
  logic [IW-1:0]          b_idx;
  logic [2:0]             b_p;
  kind_t                  b_kind;
  logic [3:0]             b_deg;
  logic [1:0]             b_frac;
  logic [COEF_ADDR_W-1:0] b_base;
  logic signed [16:0]     b_t;  // the centered operand before its saturate to 16 bits, which stage C does (centre subtract and saturate in one stage were 1.18 ns)
  logic [23:0]            b_aux;
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_desc;
  logic unused_par;
`ifdef SYNTHESIS
  logic unused_done;  // rm_done is checked in simulation only
`endif
  /* verilator lint_on UNUSEDSIGNAL */

  if (MUL_LAT < 1 || sienna_fmt_pkg::ACT_IN_LATENCY != MUL_LAT + 5) begin : G_BAD_LAT
    $fatal(1, "gpnae_act_in: int8's rescale is a register, int16Multiplier's LANE_MUL_LATENCY cycles, then four stages; LANE_MUL_LATENCY %0d, ACT_IN_LATENCY %0d", MUL_LAT,
           sienna_fmt_pkg::ACT_IN_LATENCY);
  end

  assign unused_desc = ^{desc_i[0].exp_base, desc_i[0].exp_deg, desc_i[1].exp_base, desc_i[1].exp_deg, desc_i[2].exp_base,
                         desc_i[2].exp_deg, desc_i[3].exp_base, desc_i[3].exp_deg, desc_i[0].reflect, desc_i[1].reflect, desc_i[3].reflect};
  assign unused_par = ^{par_i.selu_out_mantissa, par_i.selu_out_shift, par_i.selu_out_zero_point};

  assign d_q = 16'($signed(word_i)) - 16'($signed(par_i.in_zero_point));  // q - z_in
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) q_v <= 1'b0;
    else q_v <= valid_i;
  always_ff @(posedge clk_i)
    if (valid_i) begin
      q_d   <= d_q;
      q_mx  <= par_i.in_rescale_mantissa;
      q_idx <= idx_i;
      q_fn  <= fn_i;
      q_shx <= par_i.in_rescale_shift;
    end
  int16Multiplier RESC (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(q_v), .a_i(q_d), .b_i(q_mx), .result_o(r), .done_o(rm_done));

  // The index, function and shift ride beside the product for its MUL_LAT cycles.
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) sv_d <= '0;
    else sv_d <= MUL_LAT'({sv_d, q_v});
  always_ff @(posedge clk_i) begin
    if (q_v) begin
      idx_d[0] <= q_idx;
      fn_d[0]  <= q_fn;
      shx_d[0] <= q_shx;
    end
    for (int i = 1; i < MUL_LAT; i++)
      if (sv_d[i-1]) begin
        idx_d[i] <= idx_d[i-1];
        fn_d[i]  <= fn_d[i-1];
        shx_d[i] <= shx_d[i-1];
      end
  end
  assign s_v   = sv_d[MUL_LAT-1];
  assign s_idx = idx_d[MUL_LAT-1];
  assign s_fn  = fn_d[MUL_LAT-1];
  assign s_shx = shx_d[MUL_LAT-1];

  // Stage R: r rounded half up by 2^shx (the variable shift and its round add alone: with the saturate it was the int8 lane's 1.9 ns path at 45 nm).
  assign rw = 33'(r);
  assign xs = rw >>> s_shx;
  assign xb = (s_shx != 5'd0) && r[s_shx-5'd1];  // rw[s-1] is r[s-1] for s = 1 to 31
  assign xr = xs + 33'(xb);  // (rw + 2^(s-1)) >>> s == (rw >>> s) + rw[s-1]: the shift, then an increment (the round constant and its add ahead of the shift were 1.27 ns)
  always_ff @(posedge clk_i)
    if (s_v) begin
      r_idx <= s_idx;
      r_fn  <= s_fn;
      r_xr  <= xr;
      r_r31 <= r[31];
      r_aux <= r[23:0];  // |q - z_in| <= 255 and mx < 2^15 keep r below 2^23
    end

  // x = the rounded product saturated to Q4.11.
  assign x   = (r_xr > 33'sd32767) ? 16'sh7FFF : ((r_xr < -33'sd32768) ? -16'sh8000 : r_xr[15:0]);
  assign neg = x[15];
  assign mag = (x == -16'sh8000) ? 15'h7FFF : 15'(neg ? -x : x);

  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) {r_v, a_v, b_v, valid_o} <= '0;
    else {r_v, a_v, b_v, valid_o} <= {s_v, r_v, a_v, b_v};

  // Stage A: x, its sign and magnitude, r's sign and low bits.
  always_ff @(posedge clk_i)
    if (r_v) begin
      a_idx <= r_idx;
      a_fn  <= r_fn;
      a_selu <= r_fn == 2'(FN_SELU);
      a_x   <= x;
      a_mag <= mag;
      a_neg <= neg;
      a_r31 <= r_r31;
      a_aux <= r_aux;
      a_d   <= desc_i[(r_fn == 2'(FN_SELU)) ? D_SELU : (r_fn == 2'(FN_SIG)) ? (neg ? D_SIGN : D_SIGP) : D_TANH];
    end

  // Stage B: the descriptor's piece, kind, degree, fraction and base, and the centered operand.
  always_ff @(posedge clk_i)
    if (a_v) begin
      /* verilator lint_off UNUSEDSIGNAL */
      automatic desc_t d = a_d;
      /* verilator lint_on UNUSEDSIGNAL */
      automatic logic beyond = beyond_of(d.bound, d.np, a_mag);
      automatic kind_t k;
      automatic logic signed [16:0] t;
      if (a_selu) begin
        k = !a_r31 ? K_LIN : ((beyond && a_neg) ? K_SAT : K_MUL);  // SELU's sign is r's: an x < 0 that rounds to 0 stays negative
        t = 17'(a_x) - 17'($signed(d.center));
      end else begin
        k = beyond ? K_SAT : ((a_fn == 2'(FN_SIG) && a_neg && d.reflect) ? K_REFL : K_PASS);
        t = 17'({2'b00, a_mag}) - 17'($signed(d.center));
      end
      b_idx  <= a_idx;
      b_p    <= piece_idx(d.bound, d.np, a_mag);
      b_kind <= k;
      b_deg  <= d.deg;
      b_frac <= d.frac;
      b_base <= d.base;
      b_t    <= t;
      b_neg  <= a_neg;
      b_aux  <= a_aux;
    end

  // Stage C: the base.
  always_ff @(posedge clk_i)
    if (b_v) begin
      idx_o   <= b_idx;
      op_o    <= (b_t > 17'sd32767) ? 16'h7FFF : ((b_t < -17'sd32768) ? 16'h8000 : b_t[15:0]);
      base_o  <= b_base + COEF_ADDR_W'(int'(b_p) * (int'(b_deg) + 1));
      deg_o   <= uses_p(b_kind) ? b_deg : 4'd0;
      frac_o  <= b_frac;
      kind_o  <= b_kind;
      neg_o   <= b_neg;
      n_o     <= '0;
      under_o <= 1'b0;
      aux_o   <= b_aux;
    end

`ifdef SYNTHESIS
  assign unused_done = rm_done;
`else
  a_rescale_latency: assert property (@(posedge clk_i) disable iff (!rstn_i) rm_done == s_v)
    else $error("gpnae_act_in: a_rescale_latency: int16Multiplier is not LANE_MUL_LATENCY = %0d cycles", MUL_LAT);
  a_mx_range: assert property (@(posedge clk_i) disable iff (!rstn_i) valid_i |-> !par_i.in_rescale_mantissa[15])
    else $error("gpnae_act_in: a_mx_range: the rescale mantissa %h is not below 2^15", par_i.in_rescale_mantissa);
`endif

`else
  // ── floats: classify at once, square or scale on fmt_mul beside it, then the operand ──
`ifdef FMT_BF16
  localparam logic [ACT_W-1:0] T_TINY = 16'h3DB9;  // tanh(x) rounds to x below 0.0903 in bf16
  localparam logic [ACT_W-1:0] LOG2E = 16'h3FB9;  // bf16's sigmoid product is unused: its exp path is the fp32 tail
`else
  localparam logic [ACT_W-1:0] T_TINY = 32'h39B89BA3;  // and below 3.5211e-4 in fp32
  localparam logic [ACT_W-1:0] LOG2E = 32'h3FB8AA3B;
`endif
  localparam bit EXP_ON_MAC = !sienna_fmt_pkg::HAS_FLOAT_TAIL;  // fp32: beyond its pieces, negative sigmoid is 2^-n P(f) on the MAC
  localparam int SPLIT_LAT = EXP_ON_MAC ? 1 : 0;  // one more stage for the split's second register (its two shifts and priority find were 1.27 ns at 45 nm)

  // The class that rides beside the multiply.
  typedef struct packed {
    logic [IW-1:0]          idx;
    logic [1:0]             fn;
    logic [ACT_W-1:0]       word;
    logic [COEF_ADDR_W-1:0] base;
    logic [3:0]             deg;
    logic [COEF_ADDR_W-1:0] exp_base;
    logic [3:0]             exp_deg;
    kind_t                  kind;
    logic                   neg;
  } cls_t;

  // The word's magnitude and sign.
  logic [ACT_W-2:0] mag;
  logic             neg;
  // The class over the first three stages: the descriptor, then the piece and degree.
  /* verilator lint_off UNUSEDSIGNAL */
  desc_t c_d;  // stage 0: the descriptor of the function and sign; floats leave center and frac
  /* verilator lint_on UNUSEDSIGNAL */
  logic [PMAX-2:0] c_ge;  // stage 1: the bounds the magnitude reaches; stage 2 counts them into the piece (compares and count in one stage were bf16's 1.18 ns)
  logic [COEF_ADDR_W-1:0] c_base[PMAX];  // stage 1: base + k (deg + 1) for each piece k, so stage 2 is the count and a select
  // x^2 for tanh, |x| log2 e for sigmoid; registered once more before the split and the operand mux (that mux after the split was the
  // fp32 lane's path).
  logic [ACT_W-1:0] sq, sq_q, sq_op;  // the square, registered, and as the output mux reads it (a cycle later with the split)
  logic             sq_done;
  // The class beside the multiply and its register, and the one that leaves.
  logic [MUL_LAT+SPLIT_LAT:0] p_v;
  cls_t             p_c[MUL_LAT+SPLIT_LAT+1];
  cls_t             l;
  // k's split, fp32's negative sigmoid beyond its pieces.
  logic [      7:0] sp_n;
  logic [ACT_W-1:0] sp_f;
  logic             sp_under;
  /* verilator lint_off UNUSEDSIGNAL */
  logic unused_in;
`ifdef SYNTHESIS
  logic unused_done;  // sq_done is checked in simulation only
`endif
  /* verilator lint_on UNUSEDSIGNAL */

  // The element's class takes the first three stages beside the multiply (timing): stage 0 the word and its descriptor, stage 1 its piece
  // and kind, stage 2 its coefficient base; the multiply is at least that long in every float format.
  if (MUL_LAT < 3) begin : G_BAD_LAT
    $fatal(1, "gpnae_act_in: the class takes 3 stages beside the multiply, LANE_MUL_LATENCY is %0d", MUL_LAT);
  end
  if (sienna_fmt_pkg::ACT_IN_LATENCY != MUL_LAT + 2 + SPLIT_LAT) begin : G_BAD_ACT_LAT
    $fatal(1, "gpnae_act_in: the float path is LANE_MUL_LATENCY + 2 + %0d, not ACT_IN_LATENCY %0d", SPLIT_LAT, sienna_fmt_pkg::ACT_IN_LATENCY);
  end

  assign unused_in = ^{par_i, desc_i[0].center, desc_i[0].frac, desc_i[1].center, desc_i[1].frac, desc_i[2].center, desc_i[2].frac,
                       desc_i[3].center, desc_i[3].frac};

  assign mag = word_i[ACT_W-2:0];
  assign neg = word_i[ACT_W-1] && (mag != '0);

  always_ff @(posedge clk_i) c_d <= desc_i[(fn_i == 2'(FN_SELU)) ? D_SELU : (fn_i == 2'(FN_SIG)) ? (neg ? D_SIGN : D_SIGP) : D_TANH];

  // x^2 for tanh, |x| log2 e for sigmoid (fp32's exp elements take its split), nothing else.
  fmt_mul #(.DATA_WIDTH(ACT_W), .EXT_DATA_WIDTH(ACT_W)) SQ (.clk_i(clk_i), .rstn_i(rstn_i), .valid_i(valid_i && fn_i != 2'(FN_SELU)),
      .a_i(fn_i == 2'(FN_TANH) ? word_i : {1'b0, mag}), .b_i(fn_i == 2'(FN_TANH) ? word_i : LOG2E), .product_o(sq), .done_o(sq_done));

  // The class rides beside the multiply.
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) p_v <= '0;
    else p_v <= {p_v[MUL_LAT+SPLIT_LAT-1:0], valid_i};
  always_ff @(posedge clk_i)
    if (p_v[MUL_LAT-1]) sq_q <= sq;
  always_ff @(posedge clk_i) begin
    automatic logic [ACT_W-2:0] m1 = p_c[0].word[ACT_W-2:0];  // stage 1 reads stage 0's word
    automatic logic beyond1;
    automatic kind_t k1;
    p_c[0] <= '{idx: idx_i, fn: fn_i, word: word_i, base: '0, deg: '0, exp_base: '0, exp_deg: '0, kind: K_PASS, neg: neg};
    beyond1 = beyond_of(c_d.bound, c_d.np, m1);
    if (p_c[0].fn == 2'(FN_SELU)) k1 = !p_c[0].neg ? K_LIN : (beyond1 ? K_SAT : K_MUL);
    else if (p_c[0].fn == 2'(FN_SIG))
      k1 = !p_c[0].neg ? (beyond1 ? K_SAT : K_PASS) : (beyond1 ? (EXP_ON_MAC ? K_EXP : K_TAIL) : (c_d.reflect ? K_REFL : K_PASS));
    else k1 = (m1 < T_TINY[ACT_W-2:0]) ? K_ONE : (beyond1 ? K_SAT : K_MUL);
    p_c[1] <= '{idx: p_c[0].idx, fn: p_c[0].fn, word: p_c[0].word, base: c_d.base, deg: c_d.deg, exp_base: c_d.exp_base, exp_deg: c_d.exp_deg,
                kind: k1, neg: p_c[0].neg};
    c_ge  <= piece_ge(c_d.bound, c_d.np, m1);
    for (int q = 0; q < PMAX; q++) c_base[q] <= c_d.base + COEF_ADDR_W'(q * (int'(c_d.deg) + 1));
    p_c[2] <= p_c[1];
    p_c[2].base <= c_base[$countones(c_ge)];  // p_c[1].base is c_d.base; the count is at most PMAX - 1
    for (int i = 3; i <= MUL_LAT + SPLIT_LAT; i++) p_c[i] <= p_c[i-1];
  end

  if (EXP_ON_MAC) begin : G_SPLIT
    if (ACT_W != 32) begin : G_BAD_W
      $fatal(1, "gpnae_act_in: the exp split is fp32, not %0d bits", ACT_W);
    end
    logic [ACT_W-1:0] sq_qq;  // the square held a cycle more, as the split's second stage lands
    gpnae_exp_split SPLIT (.clk_i(clk_i), .k_i(32'(sq)), .n_o(sp_n), .f_o(sp_f), .under_o(sp_under));  // from the multiplier's register: lands at p_v[MUL_LAT+1]
    always_ff @(posedge clk_i)
      if (p_v[MUL_LAT]) sq_qq <= sq_q;
    assign sq_op = sq_qq;
  end else begin : G_NO_SPLIT
    assign sp_n = '0;
    assign sp_f = '0;
    assign sp_under = 1'b0;
    assign sq_op = sq_q;
  end

  assign l = p_c[MUL_LAT+SPLIT_LAT];
  always_ff @(posedge clk_i or negedge rstn_i)
    if (!rstn_i) valid_o <= 1'b0;
    else valid_o <= p_v[MUL_LAT+SPLIT_LAT];
  always_ff @(posedge clk_i)
    if (p_v[MUL_LAT+SPLIT_LAT]) begin
      automatic logic ex = (l.kind == K_EXP);
      idx_o   <= l.idx;
      op_o    <= (l.fn == 2'(FN_TANH)) ? sq_op : (ex ? sp_f : ((l.fn == 2'(FN_SIG)) ? {1'b0, l.word[ACT_W-2:0]} : l.word));
      base_o  <= ex ? l.exp_base : l.base;
      deg_o   <= uses_p(l.kind) ? (ex ? l.exp_deg : l.deg) : 4'd0;
      frac_o  <= '0;
      kind_o  <= l.kind;
      neg_o   <= l.neg;
      n_o     <= ex ? sp_n : 8'd0;
      under_o <= ex && sp_under;
      aux_o   <= '0;
    end

`ifdef SYNTHESIS
  assign unused_done = sq_done;
`else
  a_square_latency: assert property (@(posedge clk_i) disable iff (!rstn_i) (p_v[MUL_LAT-1] && p_c[MUL_LAT-1].fn != 2'(FN_SELU)) == sq_done)
    else $error("gpnae_act_in: a_square_latency: the operand multiplier is not LANE_MUL_LATENCY = %0d cycles", MUL_LAT);
`endif
`endif
endmodule
