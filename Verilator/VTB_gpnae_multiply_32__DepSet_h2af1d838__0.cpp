// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae_multiply_32.h"

VL_INLINE_OPT void VTB_gpnae_multiply_32___eval_initial__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___eval_initial__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__i = 7U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__i = 7U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__i = 7U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__i = 3U;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__5(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__5\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 = 0;
    // Body
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6U] = 0U;
    }
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [0U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [2U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [4U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 = 0;
    // Body
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 << 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 3U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 5U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 7U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 9U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 0xbU));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [0U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [0U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [0U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [0U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [0U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [1U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [1U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [1U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [1U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [1U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [2U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [2U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [2U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [2U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [2U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [3U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [3U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [3U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [3U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [3U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [4U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [4U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [4U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [4U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [4U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [5U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [5U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [5U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [5U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [5U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [6U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [6U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [6U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [6U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [6U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 = 0;
    // Body
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 << 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 3U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 5U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 7U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 9U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 0xbU));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [0U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [0U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [0U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [0U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [0U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [1U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [1U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [1U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [1U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [1U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [2U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [2U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [2U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [2U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [2U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [3U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [3U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [3U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [3U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [3U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [4U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [4U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [4U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [4U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [4U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [5U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [5U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [5U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [5U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [5U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [6U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [6U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [6U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [6U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [6U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h05f0e1c5__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__8(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__8\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 = 0;
    // Body
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 << 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 3U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 5U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 7U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 9U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 0xbU));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [0U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [0U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [0U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [0U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [0U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [1U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [1U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [1U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [1U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [1U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [2U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [2U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [2U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [2U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [2U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [3U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [3U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [3U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [3U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [3U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [4U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [4U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [4U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [4U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [4U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [5U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [5U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [5U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [5U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [5U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] = 0U;
    }
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [6U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [6U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [6U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [6U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [6U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h23364de6__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__14(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__14\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__valid_stage[7U]) {
        if (vlSelfRef.__PVT__choice) {
            vlSelfRef.__PVT__intermediateExp = vlSelfRef.__PVT__ExpChoice1;
            vlSelfRef.__PVT__intermediateMan = vlSelfRef.__PVT__ManChoice1;
        } else {
            vlSelfRef.__PVT__intermediateExp = vlSelfRef.__PVT__ExpChoice2;
            vlSelfRef.__PVT__intermediateMan = vlSelfRef.__PVT__ManChoice2;
        }
    }
    if (vlSelfRef.__PVT__valid_stage[6U]) {
        vlSelfRef.__PVT__choice = (1U & (IData)((vlSelfRef.__PVT__Temp_Mantissa 
                                                 >> 0x2fU)));
        vlSelfRef.__PVT__ManChoice1 = (0x7fffffU & (IData)(
                                                           (vlSelfRef.__PVT__Temp_Mantissa 
                                                            >> 0x18U)));
        vlSelfRef.__PVT__ManChoice2 = (0x7fffffU & (IData)(
                                                           (vlSelfRef.__PVT__Temp_Mantissa 
                                                            >> 0x17U)));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__19(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__19\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__valid_stage[7U]) {
        vlSelfRef.__PVT__intermediateSign = vlSelfRef.__PVT__signChoice;
    }
    if (vlSelfRef.__PVT__valid_stage[6U]) {
        vlSelfRef.__PVT__ExpChoice1 = (0xffU & ((IData)(1U) 
                                                + vlSelfRef.__PVT__pipe_Exponent
                                                [4U]));
        vlSelfRef.__PVT__ExpChoice2 = vlSelfRef.__PVT__pipe_Exponent
            [4U];
        vlSelfRef.__PVT__signChoice = vlSelfRef.__PVT__pipe_sign
            [4U];
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__unnamedblk3__DOT__i = 6U;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__22(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__22\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__pipe_sign__v0) {
        vlSelfRef.__PVT__pipe_sign[0U] = vlSelfRef.__VdlyVal__pipe_sign__v0;
    }
    if (vlSelfRef.__VdlySet__pipe_sign__v1) {
        vlSelfRef.__PVT__pipe_sign[1U] = vlSelfRef.__VdlyVal__pipe_sign__v1;
    }
    if (vlSelfRef.__VdlySet__pipe_sign__v2) {
        vlSelfRef.__PVT__pipe_sign[2U] = vlSelfRef.__VdlyVal__pipe_sign__v2;
    }
    if (vlSelfRef.__VdlySet__pipe_sign__v3) {
        vlSelfRef.__PVT__pipe_sign[3U] = vlSelfRef.__VdlyVal__pipe_sign__v3;
    }
    if (vlSelfRef.__VdlySet__pipe_sign__v4) {
        vlSelfRef.__PVT__pipe_sign[4U] = vlSelfRef.__VdlyVal__pipe_sign__v4;
    }
    if (vlSelfRef.__VdlySet__pipe_Exponent__v0) {
        vlSelfRef.__PVT__pipe_Exponent[0U] = vlSelfRef.__VdlyVal__pipe_Exponent__v0;
    }
    if (vlSelfRef.__VdlySet__pipe_Exponent__v1) {
        vlSelfRef.__PVT__pipe_Exponent[1U] = vlSelfRef.__VdlyVal__pipe_Exponent__v1;
    }
    if (vlSelfRef.__VdlySet__pipe_Exponent__v2) {
        vlSelfRef.__PVT__pipe_Exponent[2U] = vlSelfRef.__VdlyVal__pipe_Exponent__v2;
    }
    if (vlSelfRef.__VdlySet__pipe_Exponent__v3) {
        vlSelfRef.__PVT__pipe_Exponent[3U] = vlSelfRef.__VdlyVal__pipe_Exponent__v3;
    }
    if (vlSelfRef.__VdlySet__pipe_Exponent__v4) {
        vlSelfRef.__PVT__pipe_Exponent[4U] = vlSelfRef.__VdlyVal__pipe_Exponent__v4;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__23(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__23\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__valid_stage__v0) {
        vlSelfRef.__PVT__valid_stage[0U] = vlSelfRef.__VdlyVal__valid_stage__v0;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v1) {
        vlSelfRef.__PVT__valid_stage[1U] = vlSelfRef.__VdlyVal__valid_stage__v1;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v2) {
        vlSelfRef.__PVT__valid_stage[2U] = vlSelfRef.__VdlyVal__valid_stage__v2;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v3) {
        vlSelfRef.__PVT__valid_stage[3U] = vlSelfRef.__VdlyVal__valid_stage__v3;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v4) {
        vlSelfRef.__PVT__valid_stage[4U] = vlSelfRef.__VdlyVal__valid_stage__v4;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v5) {
        vlSelfRef.__PVT__valid_stage[5U] = vlSelfRef.__VdlyVal__valid_stage__v5;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v6) {
        vlSelfRef.__PVT__valid_stage[6U] = vlSelfRef.__VdlyVal__valid_stage__v6;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v7) {
        vlSelfRef.__PVT__valid_stage[2U] = 0U;
        vlSelfRef.__PVT__valid_stage[3U] = 0U;
        vlSelfRef.__PVT__valid_stage[4U] = 0U;
        vlSelfRef.__PVT__valid_stage[5U] = 0U;
        vlSelfRef.__PVT__valid_stage[6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v12) {
        vlSelfRef.__PVT__valid_stage[7U] = vlSelfRef.__VdlyVal__valid_stage__v12;
        vlSelfRef.__PVT__valid_stage[8U] = vlSelfRef.__VdlyVal__valid_stage__v13;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v14) {
        vlSelfRef.__PVT__valid_stage[7U] = 0U;
        vlSelfRef.__PVT__valid_stage[8U] = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__5(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__5\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0 = 0;
    // Body
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6U] = 0U;
    }
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                        [0U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                             [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                        [2U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                             [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                        [4U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                             [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__15(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__15\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__i = 3U;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__17(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__17\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0 = 0;
    IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 = 0;
    // Body
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6U] 
            = vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
    }
    if (vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6U] = 0U;
    }
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                        [0U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                             [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                        [2U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                             [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                        [4U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                             [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [0U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [2U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [4U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__19(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__19\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__valid_stage[7U]) {
        if (vlSelfRef.__PVT__choice) {
            vlSelfRef.__PVT__intermediateExp = vlSelfRef.__PVT__ExpChoice1;
            vlSelfRef.__PVT__intermediateMan = vlSelfRef.__PVT__ManChoice1;
        } else {
            vlSelfRef.__PVT__intermediateExp = vlSelfRef.__PVT__ExpChoice2;
            vlSelfRef.__PVT__intermediateMan = vlSelfRef.__PVT__ManChoice2;
        }
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__21(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__21\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__valid_stage[6U]) {
        vlSelfRef.__PVT__ExpChoice1 = (0xffU & ((IData)(1U) 
                                                + vlSelfRef.__PVT__pipe_Exponent
                                                [4U]));
        vlSelfRef.__PVT__ExpChoice2 = vlSelfRef.__PVT__pipe_Exponent
            [4U];
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__23(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__23\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__valid_stage[7U]) {
        vlSelfRef.__PVT__intermediateSign = vlSelfRef.__PVT__signChoice;
    }
    if (vlSelfRef.__PVT__valid_stage[6U]) {
        vlSelfRef.__PVT__choice = (1U & (IData)((vlSelfRef.__PVT__Temp_Mantissa 
                                                 >> 0x2fU)));
        vlSelfRef.__PVT__ManChoice1 = (0x7fffffU & (IData)(
                                                           (vlSelfRef.__PVT__Temp_Mantissa 
                                                            >> 0x18U)));
        vlSelfRef.__PVT__ManChoice2 = (0x7fffffU & (IData)(
                                                           (vlSelfRef.__PVT__Temp_Mantissa 
                                                            >> 0x17U)));
        vlSelfRef.__PVT__signChoice = vlSelfRef.__PVT__pipe_sign
            [4U];
    }
}
