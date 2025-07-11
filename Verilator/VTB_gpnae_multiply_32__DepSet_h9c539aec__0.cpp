// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae__Syms.h"
#include "VTB_gpnae_multiply_32.h"

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__pipe_sign__v0 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v1 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v2 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v3 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v4 = 0U;
    if (vlSelfRef.__PVT__valid_stage[1U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__sign;
        vlSelfRef.__VdlyVal__pipe_sign__v0 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v0 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[2U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [0U];
        vlSelfRef.__VdlyVal__pipe_sign__v1 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v1 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[3U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [1U];
        vlSelfRef.__VdlyVal__pipe_sign__v2 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v2 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[4U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [2U];
        vlSelfRef.__VdlyVal__pipe_sign__v3 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v3 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[5U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [3U];
        vlSelfRef.__VdlyVal__pipe_sign__v4 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v4 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[0U]) {
        vlSelfRef.__PVT__sign = ((IData)(vlSelfRef.__PVT__sign_A) 
                                 ^ (IData)(vlSelfRef.__PVT__sign_B));
    }
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply) {
        vlSelfRef.__PVT__sign_A = ((1U & (~ ((~ (IData)(
                                                        (0U 
                                                         != 
                                                         (0x7fffffffU 
                                                          & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A)))) 
                                             | (~ (IData)(
                                                          (0U 
                                                           != 
                                                           (0x7fffffffU 
                                                            & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const))))))) 
                                   && (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A 
                                       >> 0x1fU));
        vlSelfRef.__PVT__sign_B = ((1U & (~ ((~ (IData)(
                                                        (0U 
                                                         != 
                                                         (0x7fffffffU 
                                                          & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A)))) 
                                             | (~ (IData)(
                                                          (0U 
                                                           != 
                                                           (0x7fffffffU 
                                                            & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const))))))) 
                                   && (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const 
                                       >> 0x1fU));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__1(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__1\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__i = 3U;
    vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__i = 3U;
    vlSelfRef.__VdlyVal__valid_stage__v1 = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                            && (IData)(vlSelfRef.__PVT__final_valid));
    vlSelfRef.__VdlySet__valid_stage__v1 = 1U;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__3(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__3\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__final_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                    && (IData)(vlSelfRef.__PVT__third_valid));
    vlSelfRef.__PVT__third_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                    && (IData)(vlSelfRef.__PVT__second_valid));
    vlSelfRef.__PVT__second_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                     && (IData)(vlSelfRef.__PVT__lowest_valid));
    vlSelfRef.__PVT__lowest_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                     && (IData)(vlSelfRef.__PVT__capture_valid));
    vlSelfRef.__PVT__capture_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                      && vlSelfRef.__PVT__valid_stage
                                      [0U]);
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__4(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__4\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [0U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [1U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [2U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [3U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [4U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [5U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [6U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__A_low;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__B_low;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__A_high;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__B_high;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__temp1;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__temp2;
    } else {
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__5(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__5\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult1__DOT____Vlvbound_h9d6bf90e__0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0;
    __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1;
    __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2;
    __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3 = 0;
    // Body
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last 
            = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                         [6U], 0xcU));
    } else {
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last = 0U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2U] = 0U;
    }
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
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0;
    karatsuba__DOT__booth_mult2__DOT____Vlvbound_h9d6bf90e__0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3 = 0;
    // Body
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [3U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [4U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [5U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [6U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last 
            = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                         [6U], 0xcU));
    } else {
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3 = 1U;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last = 0U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2U] = 0U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6U] = 0U;
    }
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
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*25:0*/ karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0;
    karatsuba__DOT__booth_mult3__DOT____Vlvbound_ha2fa815d__0 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3 = 0;
    // Body
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [3U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [4U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [5U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [6U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, 
                                          vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                          [6U], 0xcU));
    } else {
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3 = 1U;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last = 0U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2U] = 0U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6U] = 0U;
    }
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
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__11(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__11\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlyVal__valid_stage__v0 = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i) 
                                            && (IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply));
    vlSelfRef.__VdlySet__valid_stage__v0 = 1U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__PVT__karatsuba__DOT__temp1 = (0x1fffU 
                                                  & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__A_high) 
                                                     + (IData)(vlSelfRef.__PVT__karatsuba__DOT__A_low)));
        vlSelfRef.__PVT__karatsuba__DOT__temp2 = (0x1fffU 
                                                  & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__B_high) 
                                                     + (IData)(vlSelfRef.__PVT__karatsuba__DOT__B_low)));
        vlSelfRef.__PVT__karatsuba__DOT__A_low = (0xfffU 
                                                  & vlSelfRef.__PVT__A_Mantissa);
        vlSelfRef.__PVT__karatsuba__DOT__A_high = (0xfffU 
                                                   & (vlSelfRef.__PVT__A_Mantissa 
                                                      >> 0xcU));
        vlSelfRef.__PVT__karatsuba__DOT__B_low = (0xfffU 
                                                  & vlSelfRef.__PVT__B_Mantissa);
        vlSelfRef.__PVT__karatsuba__DOT__B_high = (0xfffU 
                                                   & (vlSelfRef.__PVT__B_Mantissa 
                                                      >> 0xcU));
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__temp1 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__temp2 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__A_low = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__A_high = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__B_low = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__B_high = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__12(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__12\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply) {
        if ((1U & ((~ (IData)((0U != (0x7fffffffU & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A)))) 
                   | (~ (IData)((0U != (0x7fffffffU 
                                        & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const))))))) {
            vlSelfRef.__PVT__A_Mantissa = 0U;
            vlSelfRef.__PVT__B_Mantissa = 0U;
        } else {
            vlSelfRef.__PVT__A_Mantissa = (0x800000U 
                                           | (0x7fffffU 
                                              & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A));
            vlSelfRef.__PVT__B_Mantissa = (0x800000U 
                                           | (0x7fffffU 
                                              & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const));
        }
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__14(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__14\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__PVT__Temp_Mantissa = (0xffffffffffffULL 
                                          & (vlSelfRef.__PVT__karatsuba__DOT__partial_product 
                                             + vlSelfRef.__PVT__karatsuba__DOT__P_low_extended2));
        vlSelfRef.__PVT__karatsuba__DOT__partial_product 
            = (0xffffffffffffULL & (vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted2 
                                    + vlSelfRef.__PVT__karatsuba__DOT__temp3_shifted));
    } else {
        vlSelfRef.__PVT__Temp_Mantissa = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__partial_product = 0ULL;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__15(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__15\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended2 
            = vlSelfRef.__PVT__karatsuba__DOT__P_low_extended1;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted2 
            = vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted1;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended1 
            = vlSelfRef.__PVT__karatsuba__DOT__P_low_extended;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted1 
            = vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended 
            = (QData)((IData)(vlSelfRef.__PVT__karatsuba__DOT__P_low2));
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted 
            = (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, (QData)((IData)(vlSelfRef.__PVT__karatsuba__DOT__P_high)), 0x18U));
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended2 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted2 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended1 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted1 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted = 0ULL;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__16(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__16\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__PVT__karatsuba__DOT__temp3_shifted 
            = (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, (QData)((IData)(vlSelfRef.__PVT__karatsuba__DOT__temp3)), 0xcU));
        vlSelfRef.__PVT__karatsuba__DOT__temp3 = (0x1ffffffU 
                                                  & (vlSelfRef.__PVT__karatsuba__DOT__temp3_stage1 
                                                     - vlSelfRef.__PVT__karatsuba__DOT__P_low2));
        vlSelfRef.__PVT__karatsuba__DOT__temp3_stage1 
            = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__P_middle 
                             - vlSelfRef.__PVT__karatsuba__DOT__P_high));
        vlSelfRef.__PVT__karatsuba__DOT__P_middle = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__temp3_shifted = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__temp3 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__temp3_stage1 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_middle = 0U;
    }
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
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__17(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__17\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__PVT__karatsuba__DOT__P_low2 = vlSelfRef.__PVT__karatsuba__DOT__P_low;
        vlSelfRef.__PVT__karatsuba__DOT__P_high = vlSelfRef.__PVT__karatsuba__DOT__P_high_raw;
        vlSelfRef.__PVT__karatsuba__DOT__P_low = vlSelfRef.__PVT__karatsuba__DOT__P_low_raw;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_raw 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_raw 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__P_low2 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_high = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_low = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_raw = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_raw = 0U;
    }
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
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__18(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__18\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply) {
        if ((1U & ((~ (IData)((0U != (0x7fffffffU & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A)))) 
                   | (~ (IData)((0U != (0x7fffffffU 
                                        & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const))))))) {
            vlSelfRef.__PVT__A_Exponent = 0U;
            vlSelfRef.__PVT__B_Exponent = 0U;
        } else {
            vlSelfRef.__PVT__A_Exponent = (0xffU & 
                                           ((vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A 
                                             >> 0x17U) 
                                            - (IData)(0x7fU)));
            vlSelfRef.__PVT__B_Exponent = (0xffU & 
                                           (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__selu_const 
                                            >> 0x17U));
        }
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__PVT__unnamedblk2__DOT__i = 6U;
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.TB_gpnae__DOT__rstn_i)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 6U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__21(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__21\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__valid_stage__v12 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v14 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__VdlyVal__valid_stage__v12 = vlSelfRef.__PVT__valid_stage
            [6U];
        vlSelfRef.__VdlySet__valid_stage__v12 = 1U;
        vlSelfRef.__VdlyVal__valid_stage__v13 = vlSelfRef.__PVT__valid_stage
            [7U];
    } else {
        vlSelfRef.__VdlySet__valid_stage__v14 = 1U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__24(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__24\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlyVal__valid_stage__v2;
    __VdlyVal__valid_stage__v2 = 0;
    CData/*0:0*/ __VdlySet__valid_stage__v2;
    __VdlySet__valid_stage__v2 = 0;
    CData/*0:0*/ __VdlyVal__valid_stage__v3;
    __VdlyVal__valid_stage__v3 = 0;
    CData/*0:0*/ __VdlySet__valid_stage__v3;
    __VdlySet__valid_stage__v3 = 0;
    CData/*0:0*/ __VdlyVal__valid_stage__v4;
    __VdlyVal__valid_stage__v4 = 0;
    CData/*0:0*/ __VdlySet__valid_stage__v4;
    __VdlySet__valid_stage__v4 = 0;
    CData/*0:0*/ __VdlyVal__valid_stage__v5;
    __VdlyVal__valid_stage__v5 = 0;
    CData/*0:0*/ __VdlySet__valid_stage__v5;
    __VdlySet__valid_stage__v5 = 0;
    CData/*0:0*/ __VdlyVal__valid_stage__v6;
    __VdlyVal__valid_stage__v6 = 0;
    CData/*0:0*/ __VdlySet__valid_stage__v6;
    __VdlySet__valid_stage__v6 = 0;
    CData/*0:0*/ __VdlySet__valid_stage__v7;
    __VdlySet__valid_stage__v7 = 0;
    // Body
    __VdlySet__valid_stage__v2 = 0U;
    __VdlySet__valid_stage__v3 = 0U;
    __VdlySet__valid_stage__v4 = 0U;
    __VdlySet__valid_stage__v5 = 0U;
    __VdlySet__valid_stage__v6 = 0U;
    __VdlySet__valid_stage__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [1U];
        __VdlyVal__valid_stage__v2 = vlSelfRef.__Vlvbound_hedd21e86__0;
        __VdlySet__valid_stage__v2 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [2U];
        __VdlyVal__valid_stage__v3 = vlSelfRef.__Vlvbound_hedd21e86__0;
        __VdlySet__valid_stage__v3 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [3U];
        __VdlyVal__valid_stage__v4 = vlSelfRef.__Vlvbound_hedd21e86__0;
        __VdlySet__valid_stage__v4 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [4U];
        __VdlyVal__valid_stage__v5 = vlSelfRef.__Vlvbound_hedd21e86__0;
        __VdlySet__valid_stage__v5 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [5U];
        __VdlyVal__valid_stage__v6 = vlSelfRef.__Vlvbound_hedd21e86__0;
        __VdlySet__valid_stage__v6 = 1U;
    } else {
        __VdlySet__valid_stage__v7 = 1U;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v0) {
        vlSelfRef.__PVT__valid_stage[0U] = vlSelfRef.__VdlyVal__valid_stage__v0;
    }
    if (vlSelfRef.__VdlySet__valid_stage__v1) {
        vlSelfRef.__PVT__valid_stage[1U] = vlSelfRef.__VdlyVal__valid_stage__v1;
    }
    if (__VdlySet__valid_stage__v2) {
        vlSelfRef.__PVT__valid_stage[2U] = __VdlyVal__valid_stage__v2;
    }
    if (__VdlySet__valid_stage__v3) {
        vlSelfRef.__PVT__valid_stage[3U] = __VdlyVal__valid_stage__v3;
    }
    if (__VdlySet__valid_stage__v4) {
        vlSelfRef.__PVT__valid_stage[4U] = __VdlyVal__valid_stage__v4;
    }
    if (__VdlySet__valid_stage__v5) {
        vlSelfRef.__PVT__valid_stage[5U] = __VdlyVal__valid_stage__v5;
    }
    if (__VdlySet__valid_stage__v6) {
        vlSelfRef.__PVT__valid_stage[6U] = __VdlyVal__valid_stage__v6;
    }
    if (__VdlySet__valid_stage__v7) {
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

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [0U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [1U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [2U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [3U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v3 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [4U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v4 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [5U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v5 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product
            [6U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v6 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__A_low;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__B_low;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__A_high;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__B_high;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__temp1;
        vlSelfRef.__PVT__karatsuba__DOT__temp1 = (0x1fffU 
                                                  & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__A_high) 
                                                     + (IData)(vlSelfRef.__PVT__karatsuba__DOT__A_low)));
        vlSelfRef.__PVT__karatsuba__DOT__A_low = (0xfffU 
                                                  & vlSelfRef.__PVT__A_Mantissa);
        vlSelfRef.__PVT__karatsuba__DOT__A_high = (0xfffU 
                                                   & (vlSelfRef.__PVT__A_Mantissa 
                                                      >> 0xcU));
    } else {
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult1__DOT__partial_product_hold__v7 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__temp1 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__A_low = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__A_high = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__1(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__1\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid) {
        vlSelfRef.__PVT__A_Mantissa = ((1U & ((~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffffU 
                                                           & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)))) 
                                              | (~ (IData)(
                                                           (0U 
                                                            != 
                                                            (0x7fffffffU 
                                                             & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2))))))
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__2(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__2\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [0U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [1U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [2U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [3U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v3 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [4U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v4 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [5U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v5 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product
            [6U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h6d6588c2__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v6 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last 
            = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold
                                         [6U], 0xcU));
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last 
            = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                         vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold
                                         [6U], 0xcU));
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, 
                                          vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold
                                          [6U], 0xcU));
    } else {
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult2__DOT__partial_product_hold__v7 = 1U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last = 0U;
    }
    vlSelfRef.__VdlyVal__valid_stage__v1 = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                            && (IData)(vlSelfRef.__PVT__final_valid));
    vlSelfRef.__VdlySet__valid_stage__v1 = 1U;
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__3(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__3\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 0U;
    vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [0U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [1U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [2U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [3U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v3 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [4U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v4 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [5U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v5 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product
            [6U];
        vlSelfRef.__VdlyVal__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_hce111824__0;
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v6 = 1U;
    } else {
        vlSelfRef.__VdlySet__karatsuba__DOT__booth_mult3__DOT__partial_product_hold__v7 = 1U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__4(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__4\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__pipe_sign__v0 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v1 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v2 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v3 = 0U;
    vlSelfRef.__VdlySet__pipe_sign__v4 = 0U;
    if (vlSelfRef.__PVT__valid_stage[1U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__sign;
        vlSelfRef.__VdlyVal__pipe_sign__v0 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v0 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[2U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [0U];
        vlSelfRef.__VdlyVal__pipe_sign__v1 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v1 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[3U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [1U];
        vlSelfRef.__VdlyVal__pipe_sign__v2 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v2 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[4U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [2U];
        vlSelfRef.__VdlyVal__pipe_sign__v3 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v3 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[5U]) {
        vlSelfRef.__Vlvbound_h0e63f286__0 = vlSelfRef.__PVT__pipe_sign
            [3U];
        vlSelfRef.__VdlyVal__pipe_sign__v4 = vlSelfRef.__Vlvbound_h0e63f286__0;
        vlSelfRef.__VdlySet__pipe_sign__v4 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[0U]) {
        vlSelfRef.__PVT__sign = ((IData)(vlSelfRef.__PVT__sign_A) 
                                 ^ (IData)(vlSelfRef.__PVT__sign_B));
    }
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid) {
        vlSelfRef.__PVT__sign_A = ((1U & (~ ((~ (IData)(
                                                        (0U 
                                                         != 
                                                         (0x7fffffffU 
                                                          & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)))) 
                                             | (~ (IData)(
                                                          (0U 
                                                           != 
                                                           (0x7fffffffU 
                                                            & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2))))))) 
                                   && (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1 
                                       >> 0x1fU));
        vlSelfRef.__PVT__sign_B = ((1U & (~ ((~ (IData)(
                                                        (0U 
                                                         != 
                                                         (0x7fffffffU 
                                                          & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)))) 
                                             | (~ (IData)(
                                                          (0U 
                                                           != 
                                                           (0x7fffffffU 
                                                            & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2))))))) 
                                   && (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2 
                                       >> 0x1fU));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__6(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__6\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0;
    __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1;
    __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2;
    __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 0;
    IData/*23:0*/ __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2;
    __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3 = 0;
    // Body
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v2 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v3 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v4 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v5 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v6 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v7 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult1__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult2__DOT____Vlvbound_h5ccf9398__0;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [1U];
        vlSelfRef.__VdlyVal__valid_stage__v2 = vlSelfRef.__Vlvbound_hedd21e86__0;
        vlSelfRef.__VdlySet__valid_stage__v2 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [2U];
        vlSelfRef.__VdlyVal__valid_stage__v3 = vlSelfRef.__Vlvbound_hedd21e86__0;
        vlSelfRef.__VdlySet__valid_stage__v3 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [3U];
        vlSelfRef.__VdlyVal__valid_stage__v4 = vlSelfRef.__Vlvbound_hedd21e86__0;
        vlSelfRef.__VdlySet__valid_stage__v4 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [4U];
        vlSelfRef.__VdlyVal__valid_stage__v5 = vlSelfRef.__Vlvbound_hedd21e86__0;
        vlSelfRef.__VdlySet__valid_stage__v5 = 1U;
        vlSelfRef.__Vlvbound_hedd21e86__0 = vlSelfRef.__PVT__valid_stage
            [5U];
        vlSelfRef.__VdlyVal__valid_stage__v6 = vlSelfRef.__Vlvbound_hedd21e86__0;
        vlSelfRef.__VdlySet__valid_stage__v6 = 1U;
    } else {
        __VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3 = 1U;
        __VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3 = 1U;
        vlSelfRef.__VdlySet__valid_stage__v7 = 1U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult1__DOT__val_next__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult1__DOT__val_next__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2U] = 0U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult2__DOT__val_next__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult2__DOT__val_next__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2U] = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__8(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__8\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 0;
    IData/*25:0*/ __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2;
    __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 0;
    CData/*0:0*/ __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3 = 0;
    // Body
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 0U;
    __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3 = 0U;
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.__PVT__unnamedblk2__DOT__i = 6U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val
            [0U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val
            [1U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1 = 1U;
        vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val
            [2U];
        __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2 
            = vlSelfRef.karatsuba__DOT__booth_mult3__DOT____Vlvbound_h5c820c32__0;
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2 = 1U;
    } else {
        __VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3 = 1U;
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n)))) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 6U;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v0) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v0;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v1) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v1;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v2) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2U] 
            = __VdlyVal__karatsuba__DOT__booth_mult3__DOT__val_next__v2;
    }
    if (__VdlySet__karatsuba__DOT__booth_mult3__DOT__val_next__v3) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1U] = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2U] = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__11(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__11\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__pipe_Exponent__v0 = 0U;
    vlSelfRef.__VdlySet__pipe_Exponent__v1 = 0U;
    vlSelfRef.__VdlySet__pipe_Exponent__v2 = 0U;
    vlSelfRef.__VdlySet__pipe_Exponent__v3 = 0U;
    vlSelfRef.__VdlySet__pipe_Exponent__v4 = 0U;
    if (vlSelfRef.__PVT__valid_stage[1U]) {
        vlSelfRef.__Vlvbound_h75c9bc77__0 = vlSelfRef.__PVT__Temp_Exponent;
        vlSelfRef.__VdlyVal__pipe_Exponent__v0 = vlSelfRef.__Vlvbound_h75c9bc77__0;
        vlSelfRef.__VdlySet__pipe_Exponent__v0 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[2U]) {
        vlSelfRef.__Vlvbound_h75c9bc77__0 = vlSelfRef.__PVT__pipe_Exponent
            [0U];
        vlSelfRef.__VdlyVal__pipe_Exponent__v1 = vlSelfRef.__Vlvbound_h75c9bc77__0;
        vlSelfRef.__VdlySet__pipe_Exponent__v1 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[3U]) {
        vlSelfRef.__Vlvbound_h75c9bc77__0 = vlSelfRef.__PVT__pipe_Exponent
            [1U];
        vlSelfRef.__VdlyVal__pipe_Exponent__v2 = vlSelfRef.__Vlvbound_h75c9bc77__0;
        vlSelfRef.__VdlySet__pipe_Exponent__v2 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[4U]) {
        vlSelfRef.__Vlvbound_h75c9bc77__0 = vlSelfRef.__PVT__pipe_Exponent
            [2U];
        vlSelfRef.__VdlyVal__pipe_Exponent__v3 = vlSelfRef.__Vlvbound_h75c9bc77__0;
        vlSelfRef.__VdlySet__pipe_Exponent__v3 = 1U;
    }
    if (vlSelfRef.__PVT__valid_stage[5U]) {
        vlSelfRef.__Vlvbound_h75c9bc77__0 = vlSelfRef.__PVT__pipe_Exponent
            [3U];
        vlSelfRef.__VdlyVal__pipe_Exponent__v4 = vlSelfRef.__Vlvbound_h75c9bc77__0;
        vlSelfRef.__VdlySet__pipe_Exponent__v4 = 1U;
    }
    if (vlSelfRef.__PVT__final_valid) {
        vlSelfRef.__PVT__Temp_Exponent = (((0xc0U & 
                                            ((IData)(vlSelfRef.__PVT__final_sum) 
                                             << 6U)) 
                                           | (0x30U 
                                              & ((IData)(vlSelfRef.__PVT__third_sum) 
                                                 << 4U))) 
                                          | ((0xcU 
                                              & ((IData)(vlSelfRef.__PVT__second_sum) 
                                                 << 2U)) 
                                             | (3U 
                                                & (IData)(vlSelfRef.__PVT__lowest_sum))));
    }
    if (vlSelfRef.__PVT__third_valid) {
        vlSelfRef.__PVT__final_sum = (0x1fU & (((3U 
                                                 & ((IData)(vlSelfRef.__PVT__A_Exponent_reg) 
                                                    >> 6U)) 
                                                + (3U 
                                                   & ((IData)(vlSelfRef.__PVT__B_Exponent_reg) 
                                                      >> 6U))) 
                                               + (1U 
                                                  & ((IData)(vlSelfRef.__PVT__third_sum) 
                                                     >> 2U))));
    }
    if (vlSelfRef.__PVT__second_valid) {
        vlSelfRef.__PVT__third_sum = (7U & (((3U & 
                                              ((IData)(vlSelfRef.__PVT__A_Exponent_reg) 
                                               >> 4U)) 
                                             + (3U 
                                                & ((IData)(vlSelfRef.__PVT__B_Exponent_reg) 
                                                   >> 4U))) 
                                            + (1U & 
                                               ((IData)(vlSelfRef.__PVT__second_sum) 
                                                >> 2U))));
    }
    if (vlSelfRef.__PVT__lowest_valid) {
        vlSelfRef.__PVT__second_sum = (7U & (((3U & 
                                               ((IData)(vlSelfRef.__PVT__A_Exponent_reg) 
                                                >> 2U)) 
                                              + (3U 
                                                 & ((IData)(vlSelfRef.__PVT__B_Exponent_reg) 
                                                    >> 2U))) 
                                             + (1U 
                                                & ((IData)(vlSelfRef.__PVT__lowest_sum) 
                                                   >> 2U))));
    }
    if (vlSelfRef.__PVT__capture_valid) {
        vlSelfRef.__PVT__lowest_sum = (7U & ((3U & (IData)(vlSelfRef.__PVT__A_Exponent_reg)) 
                                             + (3U 
                                                & (IData)(vlSelfRef.__PVT__B_Exponent_reg))));
    }
    if (vlSelfRef.__PVT__valid_stage[0U]) {
        vlSelfRef.__PVT__A_Exponent_reg = vlSelfRef.__PVT__A_Exponent;
    }
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid) {
        vlSelfRef.__PVT__A_Exponent = ((1U & ((~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffffU 
                                                           & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)))) 
                                              | (~ (IData)(
                                                           (0U 
                                                            != 
                                                            (0x7fffffffU 
                                                             & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2))))))
                                        ? 0U : (0xffU 
                                                & ((vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1 
                                                    >> 0x17U) 
                                                   - (IData)(0x7fU))));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__12(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__12\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold 
            = vlSelfRef.__PVT__karatsuba__DOT__temp2;
        vlSelfRef.__PVT__karatsuba__DOT__temp2 = (0x1fffU 
                                                  & ((IData)(vlSelfRef.__PVT__karatsuba__DOT__B_high) 
                                                     + (IData)(vlSelfRef.__PVT__karatsuba__DOT__B_low)));
        vlSelfRef.__PVT__karatsuba__DOT__B_low = (0xfffU 
                                                  & vlSelfRef.__PVT__B_Mantissa);
        vlSelfRef.__PVT__karatsuba__DOT__B_high = (0xfffU 
                                                   & (vlSelfRef.__PVT__B_Mantissa 
                                                      >> 0xcU));
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__temp2 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__B_low = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__B_high = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__13(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__13\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid) {
        vlSelfRef.__PVT__B_Mantissa = ((1U & ((~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffffU 
                                                           & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)))) 
                                              | (~ (IData)(
                                                           (0U 
                                                            != 
                                                            (0x7fffffffU 
                                                             & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2))))))
                                        ? 0U : (0x800000U 
                                                | (0x7fffffU 
                                                   & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2)));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__14(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__14\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__valid_stage[0U]) {
        vlSelfRef.__PVT__B_Exponent_reg = vlSelfRef.__PVT__B_Exponent;
    }
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid) {
        vlSelfRef.__PVT__B_Exponent = ((1U & ((~ (IData)(
                                                         (0U 
                                                          != 
                                                          (0x7fffffffU 
                                                           & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1)))) 
                                              | (~ (IData)(
                                                           (0U 
                                                            != 
                                                            (0x7fffffffU 
                                                             & vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2))))))
                                        ? 0U : (0xffU 
                                                & (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2 
                                                   >> 0x17U)));
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__18(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__18\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__valid_stage__v12 = 0U;
    vlSelfRef.__VdlySet__valid_stage__v14 = 0U;
    vlSelfRef.__VdlyVal__valid_stage__v0 = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                            && (IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid));
    vlSelfRef.__VdlySet__valid_stage__v0 = 1U;
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.__VdlyVal__valid_stage__v12 = vlSelfRef.__PVT__valid_stage
            [6U];
        vlSelfRef.__VdlySet__valid_stage__v12 = 1U;
        vlSelfRef.__VdlyVal__valid_stage__v13 = vlSelfRef.__PVT__valid_stage
            [7U];
    } else {
        vlSelfRef.__VdlySet__valid_stage__v14 = 1U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__21(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__21\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__final_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                    && (IData)(vlSelfRef.__PVT__third_valid));
    vlSelfRef.__PVT__third_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                    && (IData)(vlSelfRef.__PVT__second_valid));
    vlSelfRef.__PVT__second_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                     && (IData)(vlSelfRef.__PVT__lowest_valid));
    vlSelfRef.__PVT__lowest_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                     && (IData)(vlSelfRef.__PVT__capture_valid));
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__24(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__24\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__capture_valid = ((IData)(vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) 
                                      && vlSelfRef.__PVT__valid_stage
                                      [0U]);
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

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__25(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__25\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.__PVT__Temp_Mantissa = (0xffffffffffffULL 
                                          & (vlSelfRef.__PVT__karatsuba__DOT__partial_product 
                                             + vlSelfRef.__PVT__karatsuba__DOT__P_low_extended2));
        vlSelfRef.__PVT__karatsuba__DOT__partial_product 
            = (0xffffffffffffULL & (vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted2 
                                    + vlSelfRef.__PVT__karatsuba__DOT__temp3_shifted));
        vlSelfRef.__PVT__karatsuba__DOT__temp3_shifted 
            = (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, (QData)((IData)(vlSelfRef.__PVT__karatsuba__DOT__temp3)), 0xcU));
        vlSelfRef.__PVT__karatsuba__DOT__temp3 = (0x1ffffffU 
                                                  & (vlSelfRef.__PVT__karatsuba__DOT__temp3_stage1 
                                                     - vlSelfRef.__PVT__karatsuba__DOT__P_low2));
        vlSelfRef.__PVT__karatsuba__DOT__temp3_stage1 
            = (0x3ffffffU & (vlSelfRef.__PVT__karatsuba__DOT__P_middle 
                             - vlSelfRef.__PVT__karatsuba__DOT__P_high));
    } else {
        vlSelfRef.__PVT__Temp_Mantissa = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__partial_product = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__temp3_shifted = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__temp3 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__temp3_stage1 = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__26(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__26\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted2 
            = vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted1;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted1 
            = vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted 
            = (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, (QData)((IData)(vlSelfRef.__PVT__karatsuba__DOT__P_high)), 0x18U));
        vlSelfRef.__PVT__karatsuba__DOT__P_high = vlSelfRef.__PVT__karatsuba__DOT__P_high_raw;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_raw 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult2__DOT__accum;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted2 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted1 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_shifted = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_high = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_high_raw = 0U;
    }
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
}

VL_INLINE_OPT void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__27(VTB_gpnae_multiply_32* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__27\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n) {
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended2 
            = vlSelfRef.__PVT__karatsuba__DOT__P_low_extended1;
        vlSelfRef.__PVT__karatsuba__DOT__P_middle = vlSelfRef.__PVT__karatsuba__DOT__booth_mult3__DOT__accum;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended1 
            = vlSelfRef.__PVT__karatsuba__DOT__P_low_extended;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended 
            = (QData)((IData)(vlSelfRef.__PVT__karatsuba__DOT__P_low2));
        vlSelfRef.__PVT__karatsuba__DOT__P_low2 = vlSelfRef.__PVT__karatsuba__DOT__P_low;
        vlSelfRef.__PVT__karatsuba__DOT__P_low = vlSelfRef.__PVT__karatsuba__DOT__P_low_raw;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_raw 
            = vlSelfRef.__PVT__karatsuba__DOT__booth_mult1__DOT__accum;
    } else {
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended2 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_middle = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended1 = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_extended = 0ULL;
        vlSelfRef.__PVT__karatsuba__DOT__P_low2 = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_low = 0U;
        vlSelfRef.__PVT__karatsuba__DOT__P_low_raw = 0U;
    }
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
}
