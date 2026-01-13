// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae__Syms.h"
#include "VTB_gpnae___024root.h"

VL_ATTR_COLD void VTB_gpnae___024root___eval_initial__TOP(VTB_gpnae___024root* vlSelf);
VlCoroutine VTB_gpnae___024root___eval_initial__TOP__Vtiming__0(VTB_gpnae___024root* vlSelf);
VlCoroutine VTB_gpnae___024root___eval_initial__TOP__Vtiming__1(VTB_gpnae___024root* vlSelf);
VlCoroutine VTB_gpnae___024root___eval_initial__TOP__Vtiming__2(VTB_gpnae___024root* vlSelf);
void VTB_gpnae_multiply_32___eval_initial__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root___eval_initial(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_initial\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTB_gpnae___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    VTB_gpnae___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    VTB_gpnae___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    VTB_gpnae___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    VTB_gpnae_multiply_32___eval_initial__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    VTB_gpnae_multiply_32___eval_initial__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
}

VL_INLINE_OPT VlCoroutine VTB_gpnae___024root___eval_initial__TOP__Vtiming__1(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_initial__TOP__Vtiming__1\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x2540be400ULL, 
                                         nullptr, "/home/admin/Desktop/GPNAE/testbenches/TB_gpnae.sv", 
                                         358);
    VL_WRITEF_NX("[%0t] %%Error: TB_gpnae.sv:358: Assertion failed in %NTB_gpnae: Testbench timeout!\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("/home/admin/Desktop/GPNAE/testbenches/TB_gpnae.sv", 358, "");
    VL_FINISH_MT("/home/admin/Desktop/GPNAE/testbenches/TB_gpnae.sv", 359, "");
}

VL_INLINE_OPT VlCoroutine VTB_gpnae___024root___eval_initial__TOP__Vtiming__2(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_initial__TOP__Vtiming__2\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "/home/admin/Desktop/GPNAE/testbenches/TB_gpnae.sv", 
                                             137);
        vlSelfRef.TB_gpnae__DOT__clk = (1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTB_gpnae___024root___dump_triggers__act(VTB_gpnae___024root* vlSelf);
#endif  // VL_DEBUG

void VTB_gpnae___024root___eval_triggers__act(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_triggers__act\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.TB_gpnae__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__rstn_i__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(5U, ((~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__sigtan_clk__0))));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSelfRef.TB_gpnae__DOT__idle_o) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__idle_o__0)));
    vlSelfRef.__VactTriggered.setBit(8U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__clk__0 
        = vlSelfRef.TB_gpnae__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__rstn_i__0 
        = vlSelfRef.TB_gpnae__DOT__rstn_i;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__clk_i__0 
        = vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i__0 
        = vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__clk_i__0 
        = vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n__0 
        = vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__dut__DOT__sigtan_clk__0 
        = vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__TB_gpnae__DOT__idle_o__0 
        = vlSelfRef.TB_gpnae__DOT__idle_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTB_gpnae___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void VTB_gpnae___024root___act_comb__TOP__0(VTB_gpnae___024root* vlSelf);
void VTB_gpnae_multiply_32___act_comb__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___act_comb__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae___024root___act_comb__TOP__1(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root___eval_act(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_act\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x181ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VTB_gpnae___024root___act_comb__TOP__0(vlSelf);
        VTB_gpnae_multiply_32___act_comb__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        VTB_gpnae_multiply_32___act_comb__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        VTB_gpnae___024root___act_comb__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void VTB_gpnae___024root___act_comb__TOP__0(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___act_comb__TOP__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk = 
        ((IData)(vlSelfRef.TB_gpnae__DOT__clk) & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__sigtan_enable));
    vlSelfRef.TB_gpnae__DOT__idle_o = (1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal) 
                                                | (IData)(vlSelfRef.TB_gpnae__DOT__wr_en_i))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
        = ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
            ? ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                ? ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                    ? ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                        ? 2U : 7U) : ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                                       ? 2U : 6U)) : 
               ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                 ? ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                     ? 2U : 5U) : ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                                    ? 2U : 4U))) : 
           ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
             ? ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                 ? ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)
                     ? 4U : 5U) : ((1U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                    ? 3U : ((2U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                             ? 6U : 
                                            ((3U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                              ? 7U : 0U))))
             : ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                 ? 2U : ((IData)(vlSelfRef.TB_gpnae__DOT__start_i)
                          ? 1U : 0U))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next 
        = vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state 
        = vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state;
    if ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
        if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                    if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid)))) {
                        if ((0U < (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count))) {
                            vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next = 0U;
                        }
                    }
                } else if (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count) 
                            < ((0x1fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.TB_gpnae__DOT__terms_i))) 
                               - (IData)(1U)))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count)));
                }
            }
        }
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state 
            = ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                ? 0U : ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                         ? 0U : ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                                  ? ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid)
                                      ? 0U : ((0U < (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count))
                                               ? 1U
                                               : 0U))
                                  : (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count) 
                                      < ((0x1fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.TB_gpnae__DOT__terms_i))) 
                                         - (IData)(1U)))
                                      ? 3U : 9U))));
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state)))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next = 0U;
                }
            }
        }
        if ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                    if (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage6) {
                        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 8U;
                    }
                } else {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                if (vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage
                    [8U]) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 6U;
                }
            } else {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state 
                = ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                    ? 4U : 3U);
        } else if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 2U;
        } else if (((0U < (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count)) 
                    & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid)))) {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 1U;
        }
    }
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n 
        = ((~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o)) 
           & (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i));
}

VL_INLINE_OPT void VTB_gpnae___024root___act_comb__TOP__1(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___act_comb__TOP__1\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i 
        = ((~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)) 
           & (IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.clk_i));
}

void VTB_gpnae___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t1(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t2(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t3(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t4(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t5(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t6(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t7(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t8(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t9(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t10(void* voidSelf, bool even_cycle);
void VTB_gpnae___024root____Vthread__nba__s0__t11(void* voidSelf, bool even_cycle);

void VTB_gpnae___024root___eval_nba(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_nba\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->__Vm_even_cycle__nba = !vlSymsp->__Vm_even_cycle__nba;
    vlSymsp->__Vm_threadPoolp->workerp(0)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t0, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(1)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t1, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(2)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t2, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(3)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t3, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(4)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t4, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(5)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t5, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(6)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t6, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(7)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t7, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(8)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t8, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(9)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t9, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(10)->addTask(&VTB_gpnae___024root____Vthread__nba__s0__t10, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    VTB_gpnae___024root____Vthread__nba__s0__t11(vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSelf->__Vm_mtaskstate_final__0nba.waitUntilUpstreamDone(vlSymsp->__Vm_even_cycle__nba);
    Verilated::mtaskId(0);
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_sequent__TOP__60(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_sequent__TOP__60\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.TB_gpnae__DOT__rstn_i) {
        if (vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage
            [8U]) {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_result 
                = (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign) 
                    << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp) 
                                  << 0x17U) | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan));
        }
    } else {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_result = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_sequent__TOP__78(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_sequent__TOP__78\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (vlSelfRef.__Vsampled_TOP__TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                       >> 0x1fU)) | 
                                   (~ (IData)(vlSelfRef.__Vsampled_TOP__TB_gpnae__DOT__wr_en_i)))))))) {
            VL_WRITEF_NX("[%0t] %%Error: TB_gpnae.sv:340: Assertion failed in %NTB_gpnae: Writing when module is full!\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("/home/admin/Desktop/GPNAE/testbenches/TB_gpnae.sv", 340, "");
        }
    }
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_sequent__TOP__97(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_sequent__TOP__97\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.TB_gpnae__DOT__rstn_i) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu = 0U;
        if (vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage
            [8U]) {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu = 1U;
        }
    } else {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu = 0U;
    }
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_sequent__TOP__101(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_sequent__TOP__101\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__add_valid) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Man 
            = (0x7fffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in2);
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp 
            = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in2 
                        >> 0x17U));
    }
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in2 
        = (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign) 
            << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp) 
                          << 0x17U) | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan));
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_sequent__TOP__110(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_sequent__TOP__110\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__TB_gpnae__DOT__done_o)) 
                                   | (vlSelfRef.__Vsampled_TOP__TB_gpnae__DOT___Vpast_3_0 
                                      == vlSelfRef.__Vsampled_TOP__TB_gpnae__DOT__final_result_o))))))) {
            VL_WRITEF_NX("[%0t] %%Error: TB_gpnae.sv:354: Assertion failed in %NTB_gpnae: Final result changed after done signal!\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("/home/admin/Desktop/GPNAE/testbenches/TB_gpnae.sv", 354, "");
        }
    }
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_comb__TOP__2(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_comb__TOP__2\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i 
        = ((~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)) 
           & (IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.clk_i));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
        = ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
            ? ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                ? ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                    ? ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                        ? 2U : 7U) : ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                                       ? 2U : 6U)) : 
               ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                 ? ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                     ? 2U : 5U) : ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                                    ? 2U : 4U))) : 
           ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
             ? ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                 ? ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)
                     ? 4U : 5U) : ((1U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                    ? 3U : ((2U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                             ? 6U : 
                                            ((3U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                              ? 7U : 0U))))
             : ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                 ? 2U : ((IData)(vlSelfRef.TB_gpnae__DOT__start_i)
                          ? 1U : 0U))));
}

VL_INLINE_OPT void VTB_gpnae___024root___nba_comb__TOP__4(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___nba_comb__TOP__4\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state 
        = vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state;
    if ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state 
            = ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                ? 0U : ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                         ? 0U : ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                                  ? ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid)
                                      ? 0U : ((0U < (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count))
                                               ? 1U
                                               : 0U))
                                  : (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count) 
                                      < ((0x1fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.TB_gpnae__DOT__terms_i))) 
                                         - (IData)(1U)))
                                      ? 3U : 9U))));
    } else if ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
        if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                if (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage6) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 8U;
                }
            } else {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 7U;
            }
        } else if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
            if (vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage
                [8U]) {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 6U;
            }
        } else {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 5U;
        }
    } else if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state 
            = ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))
                ? 4U : 3U);
    } else if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 2U;
    } else if (((0U < (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count)) 
                & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid)))) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state = 1U;
    }
}

void VTB_gpnae___024root___nba_sequent__TOP__0(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask0(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 0;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__0(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__1(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask1(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask1\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 1;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__1(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__2(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask2(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask2\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 2;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__2(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__3(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask3(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask3\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 3;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__3(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__4(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask4(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask4\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 4;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__4(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__5(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask5(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask5\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 5;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__5(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__6(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask6(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask6\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 6;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__6(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__7(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask7(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask7\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 7;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__7(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__8(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask8(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask8\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 8;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__8(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__9(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask9(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask9\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 9;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__9(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__10(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask10(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask10\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 10;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__10(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__11(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask11(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask11\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 11;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__11(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__12(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask12(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask12\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 12;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__12(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__13(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask13(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask13\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 13;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__13(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__14(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask14(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask14\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 14;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__14(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__15(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask15(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask15\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 15;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__15(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__16(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask16(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask16\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 16;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__16(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__17(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask17(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask17\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 17;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__17(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__18(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask18(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask18\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 18;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__18(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__19(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask19(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask19\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 19;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__19(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__20(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask20(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask20\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 20;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__20(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__21(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask21(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask21\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 21;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__21(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__22(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask22(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask22\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 22;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__22(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__23(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask23(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask23\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 23;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__23(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__24(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask24(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask24\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 24;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__24(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__25(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask25(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask25\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 25;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__25(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__26(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask26(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask26\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 26;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__26(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__27(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask27(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask27\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 27;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__27(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__28(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask28(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask28\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 28;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__28(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__29(VTB_gpnae___024root* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask29(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask29\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 29;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__29(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask30(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask30\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 30;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__30(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__31(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__32(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__33(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__34(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask31(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask31\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 31;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__30(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__31(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__32(vlSelf);
    }
    if ((0xaULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__33(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__34(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__1(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask32(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask32\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 32;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__1((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__35(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask33(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask33\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 33;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__35(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__36(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask34(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask34\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 34;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__36(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__37(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask35(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask35\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 35;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__37(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__2(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask36(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask36\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 36;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__2((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__1(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask37(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask37\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 37;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__1((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__38(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__39(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask38(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask38\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 38;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__38(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__39(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__3(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__40(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__41(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask39(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask39\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 39;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__3((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
        VTB_gpnae___024root___nba_sequent__TOP__40(vlSelf);
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__41(vlSelf);
        vlSelfRef.__Vm_traceActivity[0xaU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__42(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask40(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask40\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 40;
    Verilated::mtaskId(taskId);
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__42(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__43(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask41(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask41\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 41;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__43(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__4(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__2(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask42(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask42\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 42;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__4((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0xbU] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__2((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0xcU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__3(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask44(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask44\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 44;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__3((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0xdU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__4(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask45(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask45\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 45;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__4((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0xeU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__5(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__5(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask46(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask46\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 46;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__5((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0xfU] = 1U;
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__5((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x10U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__45(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask47(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask47\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 47;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__45(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask48(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask48\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 48;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x11U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask49(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask49\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 49;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x12U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__8(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask50(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask50\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 50;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__8((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x13U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root__nba_mtask51(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask51\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 51;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__6((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x14U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root__nba_mtask52(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask52\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 52;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__7((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x15U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__46(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask53(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask53\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 53;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__46(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x16U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__49(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask56(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask56\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 56;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__49(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x17U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__50(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask57(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask57\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 57;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__50(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x18U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__51(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask58(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask58\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 58;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__51(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__52(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask59(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask59\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 59;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__52(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__8(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask60(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask60\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 60;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__8((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x19U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__53(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask61(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask61\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 61;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__53(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__9(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__10(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask62(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask62\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 62;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__9((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x1aU] = 1U;
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__10((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__56(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask65(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask65\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 65;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__56(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__11(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__12(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__13(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask66(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask66\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 66;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__11((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__12((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x1bU] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__13((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x1cU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__57(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask67(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask67\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 67;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__57(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__58(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__59(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask68(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask68\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 68;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__58(vlSelf);
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__59(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x1dU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__9(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__10(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask69(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask69\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 69;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__9((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x1eU] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__10((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__11(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__12(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask70(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask70\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 70;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__11((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x1fU] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__12((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__14(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__15(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask71(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask71\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 71;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__60(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__14((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x20U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__15((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__61(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask72(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask72\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 72;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__61(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x21U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__64(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask75(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask75\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 75;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__64(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__65(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask76(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask76\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 76;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__65(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__66(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask77(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask77\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 77;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__66(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x22U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__67(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask78(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask78\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 78;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__67(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x23U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__70(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask81(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask81\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 81;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__70(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__71(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask82(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask82\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 82;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__71(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__75(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask86(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask86\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 86;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__75(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__76(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask87(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask87\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 87;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__76(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__77(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask88(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask88\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 88;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__77(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__13(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask89(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask89\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 89;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__13((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__16(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask90(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask90\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 90;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__16((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x24U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__17(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask91(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask91\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 91;
    Verilated::mtaskId(taskId);
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__17((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x25U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__18(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__19(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask92(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask92\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 92;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__78(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__18((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__19((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x26U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__81(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__82(VTB_gpnae___024root* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__21(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__15(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__83(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask93(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask93\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 93;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__81(vlSelf);
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__82(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__20((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__21((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__15((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__83(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__16(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__84(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__85(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask94(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask94\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 94;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__16((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        VTB_gpnae___024root___nba_sequent__TOP__84(vlSelf);
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__85(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x27U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__86(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__87(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__88(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask95(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask95\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 95;
    Verilated::mtaskId(taskId);
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__86(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x28U] = 1U;
    }
    if ((0xaULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__87(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__88(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x29U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__17(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask96(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask96\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 96;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__17((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x2aU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root__nba_mtask97(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask97\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 97;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__8((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x2bU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__90(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask98(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask98\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 98;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__90(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x2cU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__91(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask99(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask99\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 99;
    Verilated::mtaskId(taskId);
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__91(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x2dU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__92(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask100(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask100\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 100;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__92(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x2eU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__93(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask101(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask101\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 101;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__93(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x2fU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__94(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask102(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask102\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 102;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__94(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x30U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__96(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__98(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__0(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask103(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask103\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 103;
    Verilated::mtaskId(taskId);
    if ((0xaULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__96(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__97(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__98(vlSelf);
    }
    if ((0x183ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___act_comb__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        VTB_gpnae___024root___nba_comb__TOP__0(vlSelf);
        VTB_gpnae_multiply_32___act_comb__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__99(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask104(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask104\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 104;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__99(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__100(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask105(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask105\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 105;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__100(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x31U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__19(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask106(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask106\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 106;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__101(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x32U] = 1U;
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__19((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__102(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__103(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask107(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask107\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 107;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__102(vlSelf);
    }
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__103(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x33U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__20(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__21(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask108(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask108\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 108;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__20((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x34U] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__21((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__104(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__105(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__106(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask109(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask109\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 109;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__104(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__105(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__106(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x35U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__107(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask110(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask110\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 110;
    Verilated::mtaskId(taskId);
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__107(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__108(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__109(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask111(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask111\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 111;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__108(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x36U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__109(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__111(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__112(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask112(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask112\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 112;
    Verilated::mtaskId(taskId);
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__110(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__111(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x37U] = 1U;
    }
    if ((0xaULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__112(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x38U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__113(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__114(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__115(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__117(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask113(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask113\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 113;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__113(vlSelf);
    }
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__114(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__115(vlSelf);
    }
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__117(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x39U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__22(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__23(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask114(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask114\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 114;
    Verilated::mtaskId(taskId);
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__22((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x3aU] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__23((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        vlSelfRef.__Vm_traceActivity[0x3bU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__119(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask115(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask115\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 115;
    Verilated::mtaskId(taskId);
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__119(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x3cU] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__121(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__122(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__123(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask116(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask116\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 116;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__121(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x3dU] = 1U;
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__122(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x3eU] = 1U;
    }
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__123(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__125(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__126(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__1(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__127(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask117(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask117\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 117;
    Verilated::mtaskId(taskId);
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__125(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x3fU] = 1U;
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__126(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x40U] = 1U;
    }
    if ((0x183ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__127(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__128(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__129(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__3(VTB_gpnae___024root* vlSelf);
void VTB_gpnae_multiply_32___nba_comb__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__1(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask118(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask118\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 118;
    Verilated::mtaskId(taskId);
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__128(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x41U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__129(vlSelf);
    }
    if ((0x183ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x13ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x1bULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_comb__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__1((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__23(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__24(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask119(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask119\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 119;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__23((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x42U] = 1U;
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__24((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x43U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__25(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask120(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask120\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 120;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__25((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x44U] = 1U;
    }
    if ((0x1b3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__4(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__130(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__5(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__6(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__7(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask121(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask121\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 121;
    Verilated::mtaskId(taskId);
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__130(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x13ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x193ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__7(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__131(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__8(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask122(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask122\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 122;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__131(vlSelf);
    }
    if ((0x53ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__8(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__132(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__133(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_comb__TOP__9(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask123(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask123\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 123;
    Verilated::mtaskId(taskId);
    if ((0x42ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__132(vlSelf);
    }
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__133(vlSelf);
    }
    if ((0x13ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__9(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__26(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask124(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask124\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 124;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__26((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x45U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__27(VTB_gpnae_multiply_32* vlSelf);

void VTB_gpnae___024root__nba_mtask125(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask125\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 125;
    Verilated::mtaskId(taskId);
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__27((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        vlSelfRef.__Vm_traceActivity[0x46U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_comb__TOP__10(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask126(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask126\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 126;
    Verilated::mtaskId(taskId);
    if ((0x193ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_comb__TOP__10(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__135(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__136(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__137(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask127(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask127\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 127;
    Verilated::mtaskId(taskId);
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__135(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x47U] = 1U;
    }
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__136(vlSelf);
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__137(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__138(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask128(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask128\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 128;
    Verilated::mtaskId(taskId);
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__138(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x48U] = 1U;
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root___nba_sequent__TOP__140(VTB_gpnae___024root* vlSelf);
void VTB_gpnae___024root___nba_sequent__TOP__141(VTB_gpnae___024root* vlSelf);

void VTB_gpnae___024root__nba_mtask129(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__nba_mtask129\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 129;
    Verilated::mtaskId(taskId);
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__140(vlSelf);
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTB_gpnae___024root___nba_sequent__TOP__141(vlSelf);
        vlSelfRef.__Vm_traceActivity[0x49U] = 1U;
        VTB_gpnae_multiply_32___nba_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__22((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void VTB_gpnae___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t0\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask31(vlSelf);
    vlSelf->__Vm_mtaskstate_99.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_109.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_78.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask78(vlSelf);
    vlSelf->__Vm_mtaskstate_106.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_116.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_103.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask103(vlSelf);
    vlSelf->__Vm_mtaskstate_114.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_115.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_121.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_112.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask112(vlSelf);
    vlSelf->__Vm_mtaskstate_123.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_124.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask124(vlSelf);
    vlSelf->__Vm_mtaskstate_126.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_122.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask122(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t1(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t1\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask41(vlSelf);
    vlSelf->__Vm_mtaskstate_72.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask94(vlSelf);
    vlSelf->__Vm_mtaskstate_96.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_104.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_113.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_70.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask70(vlSelf);
    vlSelf->__Vm_mtaskstate_97.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_109.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_77.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask77(vlSelf);
    vlSelf->__Vm_mtaskstate_107.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_116.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask116(vlSelf);
    vlSelf->__Vm_mtaskstate_120.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_121.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_127.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_129.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_46.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask46(vlSelf);
    vlSelf->__Vm_mtaskstate_51.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask51(vlSelf);
    vlSelf->__Vm_mtaskstate_118.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask118(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t2(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t2\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask39(vlSelf);
    vlSelf->__Vm_mtaskstate_51.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_52.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_70.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_101.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask69(vlSelf);
    vlSelf->__Vm_mtaskstate_97.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_109.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_113.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask113(vlSelf);
    vlSelf->__Vm_mtaskstate_120.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_121.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_127.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_129.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_98.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask98(vlSelf);
    vlSelf->__Vm_mtaskstate_122.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask117(vlSelf);
    vlSelf->__Vm_mtaskstate_118.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_122.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_123.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_128.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_114.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask114(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t3(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t3\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask40(vlSelf);
    vlSelf->__Vm_mtaskstate_53.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask95(vlSelf);
    vlSelf->__Vm_mtaskstate_99.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_100.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_103.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_109.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask3(vlSelf);
    vlSelf->__Vm_mtaskstate_34.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask71(vlSelf);
    vlSelf->__Vm_mtaskstate_90.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_92.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_58.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask58(vlSelf);
    vlSelf->__Vm_mtaskstate_65.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask65(vlSelf);
    vlSelf->__Vm_mtaskstate_75.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask75(vlSelf);
    vlSelf->__Vm_mtaskstate_81.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask81(vlSelf);
    vlSelf->__Vm_mtaskstate_86.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask86(vlSelf);
    vlSelf->__Vm_mtaskstate_105.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_128.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_120.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask120(vlSelf);
    vlSelf->__Vm_mtaskstate_126.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_56.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask56(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t4(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t4\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask60(vlSelf);
    vlSelf->__Vm_mtaskstate_93.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_108.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask26(vlSelf);
    VTB_gpnae___024root__nba_mtask89(vlSelf);
    vlSelf->__Vm_mtaskstate_109.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_35.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask35(vlSelf);
    vlSelf->__Vm_mtaskstate_56.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask47(vlSelf);
    vlSelf->__Vm_mtaskstate_58.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask61(vlSelf);
    vlSelf->__Vm_mtaskstate_65.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask67(vlSelf);
    vlSelf->__Vm_mtaskstate_75.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask76(vlSelf);
    vlSelf->__Vm_mtaskstate_81.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask82(vlSelf);
    vlSelf->__Vm_mtaskstate_86.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_88.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask87(vlSelf);
    vlSelf->__Vm_mtaskstate_105.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_107.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_128.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_49.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask49(vlSelf);
    vlSelf->__Vm_mtaskstate_52.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask52(vlSelf);
    vlSelf->__Vm_mtaskstate_91.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask91(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t5(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t5\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask5(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask12(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask19(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask27(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_72.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask72(vlSelf);
    vlSelf->__Vm_mtaskstate_78.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_101.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask4(vlSelf);
    vlSelf->__Vm_mtaskstate_34.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_104.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask104(vlSelf);
    vlSelf->__Vm_mtaskstate_106.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_116.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_109.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask109(vlSelf);
    vlSelf->__Vm_mtaskstate_110.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_111.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_120.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_121.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_127.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_92.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask92(vlSelf);
    vlSelf->__Vm_mtaskstate_114.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_50.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask50(vlSelf);
    vlSelf->__Vm_mtaskstate_105.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask105(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t6(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t6\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask6(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask13(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask20(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask28(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask0(vlSelf);
    vlSelf->__Vm_mtaskstate_34.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask2(vlSelf);
    vlSelf->__Vm_mtaskstate_34.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_101.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask101(vlSelf);
    vlSelf->__Vm_mtaskstate_106.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_116.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_99.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask99(vlSelf);
    vlSelf->__Vm_mtaskstate_112.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_115.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask30(vlSelf);
    vlSelf->__Vm_mtaskstate_52.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_96.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_97.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_124.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_44.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask44(vlSelf);
    vlSelf->__Vm_mtaskstate_91.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_127.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask127(vlSelf);
    vlSelf->__Vm_mtaskstate_125.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask125(vlSelf);
    vlSelf->__Vm_mtaskstate_126.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_57.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask57(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t7(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t7\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask7(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask14(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask21(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask38(vlSelf);
    vlSelf->__Vm_mtaskstate_77.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_58.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask68(vlSelf);
    vlSelf->__Vm_mtaskstate_98.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_107.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask36(vlSelf);
    vlSelf->__Vm_mtaskstate_46.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_51.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_96.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_120.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_124.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_125.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_127.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask33(vlSelf);
    vlSelf->__Vm_mtaskstate_105.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_48.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask48(vlSelf);
    vlSelf->__Vm_mtaskstate_115.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask115(vlSelf);
    vlSelf->__Vm_mtaskstate_118.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_123.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_97.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask97(vlSelf);
    vlSelf->__Vm_mtaskstate_126.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask126(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t8(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t8\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask8(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask15(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask22(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask32(vlSelf);
    vlSelf->__Vm_mtaskstate_93.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_109.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask1(vlSelf);
    vlSelf->__Vm_mtaskstate_34.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_53.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask53(vlSelf);
    vlSelf->__Vm_mtaskstate_56.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_57.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_92.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_93.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_100.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask100(vlSelf);
    vlSelf->__Vm_mtaskstate_105.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask102(vlSelf);
    vlSelf->__Vm_mtaskstate_107.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask45(vlSelf);
    vlSelf->__Vm_mtaskstate_49.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_91.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_90.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask90(vlSelf);
    vlSelf->__Vm_mtaskstate_91.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_129.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask129(vlSelf);
    vlSelf->__Vm_mtaskstate_123.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask123(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t9(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t9\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask9(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask16(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask23(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask66(vlSelf);
    vlSelf->__Vm_mtaskstate_93.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_114.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_106.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask106(vlSelf);
    vlSelf->__Vm_mtaskstate_108.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask119(vlSelf);
    vlSelf->__Vm_mtaskstate_120.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_124.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_125.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_129.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_111.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask111(vlSelf);
    vlSelf->__Vm_mtaskstate_121.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask121(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t10(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t10\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask10(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask17(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask24(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask37(vlSelf);
    vlSelf->__Vm_mtaskstate_44.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_48.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_49.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_50.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask62(vlSelf);
    vlSelf->__Vm_mtaskstate_114.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_34.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask34(vlSelf);
    vlSelf->__Vm_mtaskstate_57.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_105.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask59(vlSelf);
    vlSelf->__Vm_mtaskstate_108.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask108(vlSelf);
    vlSelf->__Vm_mtaskstate_120.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_129.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_88.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask88(vlSelf);
    vlSelf->__Vm_mtaskstate_105.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_107.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask107(vlSelf);
    vlSelf->__Vm_mtaskstate_122.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_123.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_110.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask110(vlSelf);
    vlSelf->__Vm_mtaskstate_128.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask128(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void VTB_gpnae___024root____Vthread__nba__s0__t11(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root____Vthread__nba__s0__t11\n"); );
    // Body
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTB_gpnae___024root__nba_mtask11(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask18(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask25(vlSelf);
    vlSelf->__Vm_mtaskstate_35.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask29(vlSelf);
    vlSelf->__Vm_mtaskstate_114.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_117.signalUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask42(vlSelf);
    vlSelf->__Vm_mtaskstate_46.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_50.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_90.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_125.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_93.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask93(vlSelf);
    vlSelf->__Vm_mtaskstate_96.waitUntilUpstreamDone(even_cycle);
    VTB_gpnae___024root__nba_mtask96(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}
