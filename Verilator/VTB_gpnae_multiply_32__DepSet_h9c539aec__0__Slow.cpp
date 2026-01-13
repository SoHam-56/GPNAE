// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae__Syms.h"
#include "VTB_gpnae_multiply_32.h"

VL_ATTR_COLD void VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 = 0;
    IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0 = 0;
    CData/*2:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 = 0;
    IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0 = 0;
    CData/*2:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 = 0;
    IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 = 0;
    // Body
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
                        + vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next
                        [0U]));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next
                                        [1U], 4U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next
                                        [2U], 8U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
                        + vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next
                        [0U]));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next
                                        [1U], 4U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next
                                        [2U], 8U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
                         + vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next
                         [0U]));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
                         + VL_SHIFTL_III(26,26,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next
                                         [1U], 4U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
                         + VL_SHIFTL_III(26,26,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next
                                         [2U], 8U)));
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
    vlSelfRef.clk_i = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__clk) 
                       & (IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__selu_enable));
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
    vlSelfRef.A = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__is_positive_selu)
                    ? vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_input
                    : (((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent) 
                                      << 0x17U) | vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa)));
}

VL_ATTR_COLD void VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h2602336d__0 = 0;
    IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9a091006__0 = 0;
    CData/*2:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h2602336d__0 = 0;
    IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9a091006__0 = 0;
    CData/*2:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h2602336d__0 = 0;
    IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h79b8ac56__0 = 0;
    // Body
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
                        + vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next
                        [0U]));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next
                                        [1U], 4U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next
                                        [2U], 8U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
                        + vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next
                        [0U]));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next
                                        [1U], 4U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum 
                        + VL_SHIFTL_III(24,24,32, vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next
                                        [2U], 8U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
                         + vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next
                         [0U]));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
                         + VL_SHIFTL_III(26,26,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next
                                         [1U], 4U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum 
                         + VL_SHIFTL_III(26,26,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next
                                         [2U], 8U)));
    vlSelfRef.clk_i = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__clk) 
                       & (IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__mac_enable));
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
