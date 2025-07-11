// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae_multiply_32.h"

VL_ATTR_COLD void VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 = 0;
    IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0 = 0;
    CData/*2:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 = 0;
    IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0 = 0;
    CData/*2:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 = 0;
    IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0 = 0;
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
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                        [0U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                             [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                        [2U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                             [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                        [4U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                             [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                        [0U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                             [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                        [2U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                             [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0 
        = (0xffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                        [4U] + VL_SHIFTL_III(24,24,32, 
                                             vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                             [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [0U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [1U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [2U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [3U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0 
        = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                         [4U] + VL_SHIFTL_III(26,26,32, 
                                              vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                              [5U], 2U)));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 << 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 3U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 5U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 7U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 9U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold) 
                 >> 0xbU));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6U] 
        = karatsuba__DOT__booth_mult1__DOT____Vlvbound_h1954e1f8__0;
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
         [0U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [0U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                 [0U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [0U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [0U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [1U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [1U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [2U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [2U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [3U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [3U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [4U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [4U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [5U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [5U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                    [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [6U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
             [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod
                [6U])) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6U] = 0U;
    }
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 << 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 3U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 5U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 7U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 9U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold) 
                 >> 0xbU));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6U] 
        = karatsuba__DOT__booth_mult2__DOT____Vlvbound_h1954e1f8__0;
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
         [0U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [0U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                 [0U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [0U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [0U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [1U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [1U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [2U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [2U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [3U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [3U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [4U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [4U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [5U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [5U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 
                    = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                    [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 
                = (0xffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 
                = (0xffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [6U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
             [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod
                [6U])) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6U] = 0U;
    }
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 << 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 1U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 3U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 5U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 7U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 9U));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0 
        = (7U & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold) 
                 >> 0xbU));
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6U] 
        = karatsuba__DOT__booth_mult3__DOT____Vlvbound_h1954e1f8__0;
    if ((4U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
         [0U])) {
        if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [0U])) {
            if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                 [0U])) {
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] = 0U;
            } else {
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [0U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [0U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [0U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [1U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [1U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [1U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [2U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [2U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [2U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [3U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [3U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [3U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [4U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [4U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [4U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [5U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [5U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [5U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
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
                vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 
                    = (0x3ffffffU & ((IData)(1U) + 
                                     (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
                vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                    = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6;
            }
        } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                    [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 
                = (0x3ffffffU & ((IData)(1U) + (~ (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 
                = (0x3ffffffU & ((IData)(1U) + (~ VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U))));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4;
        }
    } else if ((2U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [6U])) {
        if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
             [6U])) {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, (IData)(vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold), 1U));
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3;
        } else {
            vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 
                = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
            vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
                = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2;
        }
    } else if ((1U & vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod
                [6U])) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6U] = 0U;
    }
}

VL_ATTR_COLD void VTB_gpnae_multiply_32___ctor_var_reset(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___ctor_var_reset\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rstn_i = VL_RAND_RESET_I(1);
    vlSelf->valid_i = VL_RAND_RESET_I(1);
    vlSelf->A = VL_RAND_RESET_I(32);
    vlSelf->B = VL_RAND_RESET_I(32);
    vlSelf->Result = VL_RAND_RESET_I(32);
    vlSelf->done_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__A_Mantissa = VL_RAND_RESET_I(24);
    vlSelf->__PVT__B_Mantissa = VL_RAND_RESET_I(24);
    vlSelf->__PVT__A_Exponent = VL_RAND_RESET_I(8);
    vlSelf->__PVT__B_Exponent = VL_RAND_RESET_I(8);
    vlSelf->__PVT__sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sign_A = VL_RAND_RESET_I(1);
    vlSelf->__PVT__sign_B = VL_RAND_RESET_I(1);
    vlSelf->__PVT__Temp_Exponent = VL_RAND_RESET_I(8);
    vlSelf->__PVT__Temp_Mantissa = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__intermediateMan = VL_RAND_RESET_I(23);
    vlSelf->__PVT__ManChoice1 = VL_RAND_RESET_I(23);
    vlSelf->__PVT__ManChoice2 = VL_RAND_RESET_I(23);
    vlSelf->__PVT__intermediateExp = VL_RAND_RESET_I(8);
    vlSelf->__PVT__ExpChoice1 = VL_RAND_RESET_I(8);
    vlSelf->__PVT__ExpChoice2 = VL_RAND_RESET_I(8);
    vlSelf->__PVT__intermediateSign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__signChoice = VL_RAND_RESET_I(1);
    vlSelf->__PVT__choice = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__PVT__valid_stage[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__PVT__capture_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__A_Exponent_reg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__B_Exponent_reg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__lowest_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__second_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__third_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__final_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__lowest_sum = VL_RAND_RESET_I(3);
    vlSelf->__PVT__second_sum = VL_RAND_RESET_I(3);
    vlSelf->__PVT__third_sum = VL_RAND_RESET_I(3);
    vlSelf->__PVT__final_sum = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__pipe_sign[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__pipe_Exponent[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__PVT__unnamedblk2__DOT__i = 0;
    vlSelf->__PVT__unnamedblk1__DOT__i = 0;
    vlSelf->__PVT__unnamedblk3__DOT__i = 0;
    vlSelf->__Vlvbound_hedd21e86__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vlvbound_h0e63f286__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vlvbound_h75c9bc77__0 = VL_RAND_RESET_I(8);
    vlSelf->__PVT__karatsuba__DOT__A_high = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__A_low = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__B_high = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__B_low = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__P_low_raw = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__P_high_raw = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__P_middle = VL_RAND_RESET_I(26);
    vlSelf->__PVT__karatsuba__DOT__temp1 = VL_RAND_RESET_I(13);
    vlSelf->__PVT__karatsuba__DOT__temp2 = VL_RAND_RESET_I(13);
    vlSelf->__PVT__karatsuba__DOT__P_high = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__P_low = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__temp3_stage1 = VL_RAND_RESET_I(26);
    vlSelf->__PVT__karatsuba__DOT__P_low2 = VL_RAND_RESET_I(26);
    vlSelf->__PVT__karatsuba__DOT__temp3 = VL_RAND_RESET_I(25);
    vlSelf->__PVT__karatsuba__DOT__P_high_shifted = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__P_high_shifted1 = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__P_high_shifted2 = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__temp3_shifted = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__partial_product = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__P_low_extended = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__P_low_extended1 = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__karatsuba__DOT__P_low_extended2 = VL_RAND_RESET_Q(48);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__val[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__accum = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__booth_mult1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__1 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__2 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__3 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__4 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__5 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h46fff653__6 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 = VL_RAND_RESET_I(24);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__val[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold = VL_RAND_RESET_I(12);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__accum = VL_RAND_RESET_I(24);
    vlSelf->__PVT__karatsuba__DOT__booth_mult2__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__1 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__2 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__3 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__4 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__5 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h46fff653__6 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 = VL_RAND_RESET_I(24);
    vlSelf->karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 = VL_RAND_RESET_I(24);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[__Vi0] = VL_RAND_RESET_I(26);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[__Vi0] = VL_RAND_RESET_I(26);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__val[__Vi0] = VL_RAND_RESET_I(26);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[__Vi0] = VL_RAND_RESET_I(26);
    }
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold = VL_RAND_RESET_I(13);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold = VL_RAND_RESET_I(13);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last = VL_RAND_RESET_I(26);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__accum = VL_RAND_RESET_I(26);
    vlSelf->__PVT__karatsuba__DOT__booth_mult3__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__1 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__2 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__3 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__4 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__5 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h947e3c62__6 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 = VL_RAND_RESET_I(26);
    vlSelf->karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 = VL_RAND_RESET_I(26);
    vlSelf->__VdlyVal__valid_stage__v0 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v0 = 0;
    vlSelf->__VdlyVal__valid_stage__v1 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v1 = 0;
    vlSelf->__VdlyVal__valid_stage__v2 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v2 = 0;
    vlSelf->__VdlyVal__valid_stage__v3 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v3 = 0;
    vlSelf->__VdlyVal__valid_stage__v4 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v4 = 0;
    vlSelf->__VdlyVal__valid_stage__v5 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v5 = 0;
    vlSelf->__VdlyVal__valid_stage__v6 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v6 = 0;
    vlSelf->__VdlySet__valid_stage__v7 = 0;
    vlSelf->__VdlyVal__valid_stage__v12 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v12 = 0;
    vlSelf->__VdlyVal__valid_stage__v13 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__valid_stage__v14 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = 0;
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = VL_RAND_RESET_I(24);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 0;
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 0;
    vlSelf->__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = VL_RAND_RESET_I(26);
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 0;
    vlSelf->__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 0;
    vlSelf->__VdlyVal__pipe_sign__v0 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__pipe_sign__v0 = 0;
    vlSelf->__VdlyVal__pipe_sign__v1 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__pipe_sign__v1 = 0;
    vlSelf->__VdlyVal__pipe_sign__v2 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__pipe_sign__v2 = 0;
    vlSelf->__VdlyVal__pipe_sign__v3 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__pipe_sign__v3 = 0;
    vlSelf->__VdlyVal__pipe_sign__v4 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__pipe_sign__v4 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v0 = VL_RAND_RESET_I(8);
    vlSelf->__VdlySet__pipe_Exponent__v0 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v1 = VL_RAND_RESET_I(8);
    vlSelf->__VdlySet__pipe_Exponent__v1 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v2 = VL_RAND_RESET_I(8);
    vlSelf->__VdlySet__pipe_Exponent__v2 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v3 = VL_RAND_RESET_I(8);
    vlSelf->__VdlySet__pipe_Exponent__v3 = 0;
    vlSelf->__VdlyVal__pipe_Exponent__v4 = VL_RAND_RESET_I(8);
    vlSelf->__VdlySet__pipe_Exponent__v4 = 0;
}
