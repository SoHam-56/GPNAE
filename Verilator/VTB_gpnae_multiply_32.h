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
        CData/*0:0*/ __VdlyVal__valid_stage__v12;
        CData/*0:0*/ __VdlySet__valid_stage__v12;
        CData/*0:0*/ __VdlyVal__valid_stage__v13;
        CData/*0:0*/ __VdlySet__valid_stage__v14;
        CData/*0:0*/ __VdlyVal__valid_stage__v0;
        CData/*0:0*/ __VdlySet__valid_stage__v0;
        CData/*0:0*/ __PVT__signChoice;
        CData/*0:0*/ __PVT__intermediateSign;
        IData/*22:0*/ __PVT__ManChoice2;
        CData/*7:0*/ __PVT__intermediateExp;
        IData/*22:0*/ __PVT__intermediateMan;
        CData/*0:0*/ __PVT__choice;
        IData/*22:0*/ __PVT__ManChoice1;
        CData/*7:0*/ __PVT__ExpChoice1;
        CData/*7:0*/ __PVT__ExpChoice2;
        QData/*47:0*/ __PVT__karatsuba__DOT__partial_product;
        QData/*47:0*/ __PVT__Temp_Mantissa;
        QData/*47:0*/ __PVT__karatsuba__DOT__temp3_shifted;
        IData/*25:0*/ __PVT__karatsuba__DOT__temp3_stage1;
        IData/*24:0*/ __PVT__karatsuba__DOT__temp3;
        IData/*25:0*/ __PVT__karatsuba__DOT__P_middle;
        IData/*25:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__accum;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_low_raw;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_low;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__accum;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_high_raw;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__accum;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_high_shifted;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_high_shifted1;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_high_shifted2;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_low_extended2;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_low_extended;
        QData/*47:0*/ __PVT__karatsuba__DOT__P_low_extended1;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult1__DOT__val_next;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold;
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
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult2__DOT__val;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult1__DOT__val;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        CData/*0:0*/ __VdlyVal__valid_stage__v2;
        CData/*0:0*/ __VdlySet__valid_stage__v2;
        CData/*0:0*/ __VdlyVal__valid_stage__v3;
        CData/*0:0*/ __VdlySet__valid_stage__v3;
        CData/*0:0*/ __VdlyVal__valid_stage__v4;
        CData/*0:0*/ __VdlySet__valid_stage__v4;
    };
    struct {
        CData/*0:0*/ __VdlyVal__valid_stage__v5;
        CData/*0:0*/ __VdlySet__valid_stage__v5;
        CData/*0:0*/ __VdlyVal__valid_stage__v6;
        CData/*0:0*/ __VdlySet__valid_stage__v6;
        CData/*0:0*/ __VdlySet__valid_stage__v7;
        CData/*0:0*/ __Vlvbound_hedd21e86__0;
        VlUnpacked<IData/*23:0*/, 3> __PVT__karatsuba__DOT__booth_mult2__DOT__val_next;
        IData/*23:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult2__DOT__partial_product;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
        VlUnpacked<CData/*2:0*/, 7> __PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold;
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
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        SData/*11:0*/ __PVT__karatsuba__DOT__A_high;
        SData/*11:0*/ __PVT__karatsuba__DOT__A_low;
        SData/*12:0*/ __PVT__karatsuba__DOT__temp1;
        IData/*23:0*/ __PVT__A_Mantissa;
        SData/*11:0*/ __PVT__karatsuba__DOT__B_high;
        SData/*11:0*/ __PVT__karatsuba__DOT__B_low;
        SData/*12:0*/ __PVT__karatsuba__DOT__temp2;
        IData/*23:0*/ __PVT__B_Mantissa;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
        VlUnpacked<CData/*2:0*/, 7> __PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        SData/*11:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold;
        VlUnpacked<IData/*23:0*/, 7> __PVT__karatsuba__DOT__booth_mult1__DOT__partial_product;
        SData/*12:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
        VlUnpacked<CData/*2:0*/, 7> __PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod;
        SData/*12:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold;
        VlUnpacked<IData/*25:0*/, 7> __PVT__karatsuba__DOT__booth_mult3__DOT__partial_product;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
    };
    struct {
        VlUnpacked<IData/*25:0*/, 3> __PVT__karatsuba__DOT__booth_mult3__DOT__val_next;
        IData/*25:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last;
        IData/*25:0*/ __PVT__karatsuba__DOT__P_low2;
        IData/*23:0*/ __PVT__karatsuba__DOT__P_high;
        CData/*0:0*/ __VdlyVal__valid_stage__v1;
        CData/*0:0*/ __VdlySet__valid_stage__v1;
        IData/*31:0*/ __PVT__karatsuba__DOT__booth_mult1__DOT__i;
        IData/*31:0*/ __PVT__karatsuba__DOT__booth_mult2__DOT__i;
        IData/*31:0*/ __PVT__karatsuba__DOT__booth_mult3__DOT__i;
        CData/*7:0*/ __PVT__Temp_Exponent;
        CData/*7:0*/ __PVT__A_Exponent_reg;
        CData/*2:0*/ __PVT__lowest_sum;
        CData/*2:0*/ __PVT__second_sum;
        CData/*2:0*/ __PVT__third_sum;
        CData/*4:0*/ __PVT__final_sum;
        CData/*7:0*/ __Vlvbound_h75c9bc77__0;
        CData/*7:0*/ __PVT__B_Exponent_reg;
        VlUnpacked<CData/*7:0*/, 5> __PVT__pipe_Exponent;
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
        CData/*0:0*/ __PVT__lowest_valid;
        CData/*0:0*/ __PVT__second_valid;
        CData/*0:0*/ __PVT__third_valid;
        CData/*0:0*/ __PVT__capture_valid;
        CData/*0:0*/ __PVT__final_valid;
        CData/*7:0*/ __PVT__A_Exponent;
        CData/*7:0*/ __PVT__B_Exponent;
        IData/*31:0*/ __PVT__unnamedblk3__DOT__i;
        IData/*31:0*/ __PVT__unnamedblk2__DOT__i;
        IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
        VlUnpacked<IData/*25:0*/, 3> __PVT__karatsuba__DOT__booth_mult3__DOT__val;
        VlUnpacked<IData/*25:0*/, 7> __PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold;
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
        CData/*0:0*/ __PVT__sign;
        CData/*0:0*/ __PVT__sign_A;
        CData/*0:0*/ __PVT__sign_B;
        CData/*0:0*/ __Vlvbound_h0e63f286__0;
        CData/*0:0*/ __VdlyVal__pipe_sign__v0;
        CData/*0:0*/ __VdlySet__pipe_sign__v0;
        CData/*0:0*/ __VdlyVal__pipe_sign__v1;
        CData/*0:0*/ __VdlySet__pipe_sign__v1;
        CData/*0:0*/ __VdlyVal__pipe_sign__v2;
    };
    struct {
        CData/*0:0*/ __VdlySet__pipe_sign__v2;
        CData/*0:0*/ __VdlyVal__pipe_sign__v3;
        CData/*0:0*/ __VdlySet__pipe_sign__v3;
        CData/*0:0*/ __VdlyVal__pipe_sign__v4;
        CData/*0:0*/ __VdlySet__pipe_sign__v4;
        VlUnpacked<CData/*0:0*/, 5> __PVT__pipe_sign;
        VL_IN8(clk_i,0,0);
        VL_IN8(rstn_i,0,0);
        VL_IN8(valid_i,0,0);
        VL_OUT8(done_o,0,0);
        VL_IN(A,31,0);
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
