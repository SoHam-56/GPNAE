// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTB_gpnae.h for the primary calling header

#ifndef VERILATED_VTB_GPNAE_MULTIPLY_32_H_
#define VERILATED_VTB_GPNAE_MULTIPLY_32_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
#include "verilated_timing.h"


class VTB_gpnae__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTB_gpnae_multiply_32 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VlUnpacked<CData/*0:0*/, 9> __PVT__valid_stage;
        CData/*0:0*/ __PVT__intermediateSign;
        CData/*0:0*/ __PVT__signChoice;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_low_extended2;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_high_shifted2;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_high;
        IData/*25:0*/ __PVT__karatsuba__DOT__P_low2;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_low_extended;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_low_extended1;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last;
        VL_IN(A,31,0);
        VL_IN8(clk_i,0,0);
        IData/*31:0*/ __PVT__unnamedblk3__DOT__i;
        IData/*31:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__i;
        IData/*31:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__i;
        IData/*31:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__i;
        IData/*31:0*/ __PVT__unnamedblk2__DOT__i;
        IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h55a11ffb__0;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult1__DOT__val;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h18691515__0;
        CData/*0:0*/ __Vlvbound_h673e5fa3__0;
        CData/*7:0*/ __PVT__B_Exponent;
        CData/*7:0*/ __PVT__B_Exponent_reg;
        CData/*7:0*/ __PVT__A_Exponent;
        CData/*7:0*/ __PVT__Temp_Exponent;
        CData/*7:0*/ __PVT__A_Exponent_reg;
        CData/*2:0*/ __PVT__lowest_sum;
        CData/*2:0*/ __PVT__second_sum;
        CData/*2:0*/ __PVT__third_sum;
        CData/*4:0*/ __PVT__final_sum;
        CData/*7:0*/ __Vlvbound_h2883e456__0;
        CData/*0:0*/ __PVT__lowest_valid;
        CData/*0:0*/ __PVT__second_valid;
        CData/*0:0*/ __PVT__third_valid;
        CData/*0:0*/ __PVT__capture_valid;
        CData/*0:0*/ __PVT__final_valid;
        CData/*7:0*/ __VdlyVal__pipe_Exponent__v0;
        CData/*0:0*/ __VdlySet__pipe_Exponent__v0;
        CData/*7:0*/ __VdlyVal__pipe_Exponent__v1;
        CData/*0:0*/ __VdlySet__pipe_Exponent__v1;
        CData/*7:0*/ __VdlyVal__pipe_Exponent__v2;
        CData/*0:0*/ __VdlySet__pipe_Exponent__v2;
        CData/*7:0*/ __VdlyVal__pipe_Exponent__v3;
        CData/*0:0*/ __VdlySet__pipe_Exponent__v3;
        CData/*7:0*/ __VdlyVal__pipe_Exponent__v4;
        CData/*0:0*/ __VdlySet__pipe_Exponent__v4;
        VlUnpacked<CData/*7:0*/, 5> __PVT__pipe_Exponent;
    };
    struct {
        CData/*7:0*/ __PVT__ExpChoice1;
        CData/*7:0*/ __PVT__ExpChoice2;
        CData/*7:0*/ __PVT__intermediateExp;
        IData/*22:0*/ __PVT__intermediateMan;
        CData/*0:0*/ __PVT__choice;
        IData/*22:0*/ __PVT__ManChoice1;
        IData/*22:0*/ __PVT__ManChoice2;
        QData/*47:0*/ __PVT__Temp_Mantissa;
        QData/*47:0*/ __PVT__karatsuba__DOT__partial_product;
        QData/*47:0*/ __PVT__karatsuba__DOT__temp3_shifted;
        IData/*25:0*/ __PVT__karatsuba__DOT__temp3_stage1;
        IData/*24:0*/ __PVT__karatsuba__DOT__temp3;
        IData/*25:0*/ __PVT__karatsuba__DOT__P_middle;
        IData/*25:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__accum;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_high_shifted;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_high_shifted1;
        IData/*25:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last;
        VlUnpacked<IData/*25:0*/, 3> __PVT__karatsuba__DOT__booth_mult3__DOT__val_next;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_high_raw;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__accum;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult2__DOT__val_next;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_low_raw;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_low;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__accum;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult1__DOT__val_next;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h08726fad__0;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h40082228__0;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5;
        IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult2__DOT__val;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h18691515__0;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h55a11ffb__0;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult2__DOT__partial_product;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
        VlUnpacked<CData/*2:0*/, 7> __PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
    };
    struct {
        VlUnpacked<CData/*2:0*/, 7> __PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult1__DOT__partial_product;
        CData/*0:0*/ __VdlyVal__valid_stage__v2;
        CData/*0:0*/ __VdlySet__valid_stage__v2;
        CData/*0:0*/ __VdlyVal__valid_stage__v3;
        CData/*0:0*/ __VdlySet__valid_stage__v3;
        CData/*0:0*/ __VdlyVal__valid_stage__v4;
        CData/*0:0*/ __VdlySet__valid_stage__v4;
        CData/*0:0*/ __VdlyVal__valid_stage__v5;
        CData/*0:0*/ __VdlySet__valid_stage__v5;
        CData/*0:0*/ __VdlyVal__valid_stage__v6;
        CData/*0:0*/ __VdlySet__valid_stage__v6;
        CData/*0:0*/ __VdlySet__valid_stage__v7;
        CData/*0:0*/ __VdlyVal__valid_stage__v1;
        CData/*0:0*/ __VdlySet__valid_stage__v1;
        CData/*0:0*/ __VdlyVal__valid_stage__v12;
        CData/*0:0*/ __VdlySet__valid_stage__v12;
        CData/*0:0*/ __VdlyVal__valid_stage__v13;
        CData/*0:0*/ __VdlySet__valid_stage__v14;
        CData/*0:0*/ __VdlyVal__valid_stage__v0;
        CData/*0:0*/ __VdlySet__valid_stage__v0;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
        CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
        IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
        VlUnpacked<IData/*25:0*/, 3> __PVT__karatsuba__DOT__booth_mult3__DOT__val;
        VlUnpacked<IData/*25:0*/, 7> __PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold;
        VlUnpacked<IData/*25:0*/, 7> __PVT__karatsuba__DOT__booth_mult3__DOT__partial_product;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
        VlUnpacked<CData/*2:0*/, 7> __PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod;
        SData/*12:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold;
        SData/*12:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        SData/*11:0*/ __PVT__karatsuba__DOT__A_high;
        SData/*11:0*/ __PVT__karatsuba__DOT__A_low;
        SData/*12:0*/ __PVT__karatsuba__DOT__temp1;
        IData/*23:0*/ __PVT__A_Mantissa;
        IData/*23:0*/ __PVT__B_Mantissa;
        SData/*12:0*/ __PVT__karatsuba__DOT__temp2;
        SData/*11:0*/ __PVT__karatsuba__DOT__B_high;
        SData/*11:0*/ __PVT__karatsuba__DOT__B_low;
        CData/*0:0*/ __PVT__sign;
        CData/*0:0*/ __PVT__sign_A;
        CData/*0:0*/ __PVT__sign_B;
        CData/*0:0*/ __Vlvbound_h13242171__0;
        CData/*0:0*/ __VdlyVal__pipe_sign__v0;
        CData/*0:0*/ __VdlySet__pipe_sign__v0;
        CData/*0:0*/ __VdlyVal__pipe_sign__v1;
    };
    struct {
        CData/*0:0*/ __VdlySet__pipe_sign__v1;
        CData/*0:0*/ __VdlyVal__pipe_sign__v2;
        CData/*0:0*/ __VdlySet__pipe_sign__v2;
        CData/*0:0*/ __VdlyVal__pipe_sign__v3;
        CData/*0:0*/ __VdlySet__pipe_sign__v3;
        CData/*0:0*/ __VdlyVal__pipe_sign__v4;
        CData/*0:0*/ __VdlySet__pipe_sign__v4;
        VlUnpacked<CData/*0:0*/, 5> __PVT__pipe_sign;
        VL_IN8(rstn_i,0,0);
        VL_IN8(valid_i,0,0);
        VL_OUT8(done_o,0,0);
        VL_IN(B,31,0);
        VL_OUT(Result,31,0);
    };

    // INTERNAL VARIABLES
    VTB_gpnae__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTB_gpnae_multiply_32(VTB_gpnae__Syms* symsp, const char* v__name);
    ~VTB_gpnae_multiply_32();
    VL_UNCOPYABLE(VTB_gpnae_multiply_32);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
