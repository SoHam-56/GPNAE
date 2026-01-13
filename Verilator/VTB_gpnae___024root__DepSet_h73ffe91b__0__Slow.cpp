// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae__Syms.h"
#include "VTB_gpnae___024root.h"

VL_ATTR_COLD void VTB_gpnae___024root___eval_static__TOP(VTB_gpnae___024root* vlSelf);
VL_ATTR_COLD void VTB_gpnae___024root____Vm_traceActivitySetAll(VTB_gpnae___024root* vlSelf);

VL_ATTR_COLD void VTB_gpnae___024root___eval_static(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_static\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTB_gpnae___024root___eval_static__TOP(vlSelf);
    VTB_gpnae___024root____Vm_traceActivitySetAll(vlSelf);
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
}

VL_ATTR_COLD void VTB_gpnae___024root___eval_initial__TOP(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_initial__TOP\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x706e6165U;
    __Vtemp_1[2U] = 0x74625f67U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    __Vtemp_2[0U] = 0x2e6d656dU;
    __Vtemp_2[1U] = 0x65666673U;
    __Vtemp_2[2U] = 0x725f636fU;
    __Vtemp_2[3U] = 0x61796c6fU;
    __Vtemp_2[4U] = 0x74U;
    VL_READMEM_N(false, 32, 32, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_2)
                 ,  &(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM)
                 , 0, ~0ULL);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTB_gpnae___024root___dump_triggers__stl(VTB_gpnae___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTB_gpnae___024root___eval_triggers__stl(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_triggers__stl\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTB_gpnae___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void VTB_gpnae___024root___stl_sequent__TOP__0(VTB_gpnae___024root* vlSelf);
VL_ATTR_COLD void VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae_multiply_32* vlSelf);
VL_ATTR_COLD void VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae_multiply_32* vlSelf);
void VTB_gpnae___024root___act_comb__TOP__1(VTB_gpnae___024root* vlSelf);

VL_ATTR_COLD void VTB_gpnae___024root___eval_stl(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___eval_stl\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VTB_gpnae___024root___stl_sequent__TOP__0(vlSelf);
        VTB_gpnae___024root____Vm_traceActivitySetAll(vlSelf);
        VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst));
        VTB_gpnae_multiply_32___stl_sequent__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0((&vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL));
        VTB_gpnae___024root___act_comb__TOP__1(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 256> VTB_gpnae__ConstPool__TABLE_he6d3ea54_0;

VL_ATTR_COLD void VTB_gpnae___024root___stl_sequent__TOP__0(VTB_gpnae___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root___stl_sequent__TOP__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*7:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*7:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*7:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*7:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    CData/*7:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    CData/*7:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    CData/*7:0*/ __Vtableidx10;
    __Vtableidx10 = 0;
    CData/*7:0*/ __Vtableidx11;
    __Vtableidx11 = 0;
    CData/*7:0*/ __Vtableidx12;
    __Vtableidx12 = 0;
    // Body
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_comb = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__rd_en_coeff = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_rd_en = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__add_valid = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__load_result = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__wr_ptr 
        = ((((1U == (1U & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
             | (2U == (3U & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
            | (((4U == (7U & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                | (8U == (0xfU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
               | ((0x10U == (0x1fU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                  | ((0x20U == (0x3fU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                     | ((0x40U == (0x7fU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                        | (0x80U == (0xffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))))))))
            ? ((1U == (1U & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                ? 0U : ((2U == (3U & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                         ? 1U : ((4U == (7U & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                  ? 2U : ((8U == (0xfU 
                                                  & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                           ? 3U : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                    ? 4U
                                                    : 
                                                   ((0x20U 
                                                     == 
                                                     (0x3fU 
                                                      & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                     ? 5U
                                                     : 
                                                    ((0x40U 
                                                      == 
                                                      (0x7fU 
                                                       & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                      ? 6U
                                                      : 7U)))))))
            : ((((0x100U == (0x1ffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                 | (0x200U == (0x3ffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
                | (((0x400U == (0x7ffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                    | (0x800U == (0xfffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
                   | ((0x1000U == (0x1fffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                      | ((0x2000U == (0x3fffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                         | ((0x4000U == (0x7fffU & 
                                         (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                            | (0x8000U == (0xffffU 
                                           & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))))))))
                ? ((0x100U == (0x1ffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                    ? 8U : ((0x200U == (0x3ffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                             ? 9U : ((0x400U == (0x7ffU 
                                                 & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                      ? 0xaU : ((0x800U 
                                                 == 
                                                 (0xfffU 
                                                  & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                 ? 0xbU
                                                 : 
                                                ((0x1000U 
                                                  == 
                                                  (0x1fffU 
                                                   & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                  ? 0xcU
                                                  : 
                                                 ((0x2000U 
                                                   == 
                                                   (0x3fffU 
                                                    & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                   ? 0xdU
                                                   : 
                                                  ((0x4000U 
                                                    == 
                                                    (0x7fffU 
                                                     & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                    ? 0xeU
                                                    : 0xfU)))))))
                : ((((0x10000U == (0x1ffffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                     | (0x20000U == (0x3ffffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
                    | (((0x40000U == (0x7ffffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                        | (0x80000U == (0xfffffU & 
                                        (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
                       | ((0x100000U == (0x1fffffU 
                                         & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                          | ((0x200000U == (0x3fffffU 
                                            & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                             | ((0x400000U == (0x7fffffU 
                                               & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                                | (0x800000U == (0xffffffU 
                                                 & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))))))))
                    ? ((0x10000U == (0x1ffffU & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                        ? 0x10U : ((0x20000U == (0x3ffffU 
                                                 & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                    ? 0x11U : ((0x40000U 
                                                == 
                                                (0x7ffffU 
                                                 & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                ? 0x12U
                                                : (
                                                   (0x80000U 
                                                    == 
                                                    (0xfffffU 
                                                     & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                    ? 0x13U
                                                    : 
                                                   ((0x100000U 
                                                     == 
                                                     (0x1fffffU 
                                                      & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                     ? 0x14U
                                                     : 
                                                    ((0x200000U 
                                                      == 
                                                      (0x3fffffU 
                                                       & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                      ? 0x15U
                                                      : 
                                                     ((0x400000U 
                                                       == 
                                                       (0x7fffffU 
                                                        & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                       ? 0x16U
                                                       : 0x17U)))))))
                    : ((((0x1000000U == (0x1ffffffU 
                                         & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                         | (0x2000000U == (0x3ffffffU 
                                           & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
                        | (((0x4000000U == (0x7ffffffU 
                                            & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                            | (0x8000000U == (0xfffffffU 
                                              & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))) 
                           | ((0x10000000U == (0x1fffffffU 
                                               & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                              | ((0x20000000U == (0x3fffffffU 
                                                  & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                                 | ((0x40000000U == 
                                     (0x7fffffffU & 
                                      (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                                    | (0x80000000U 
                                       == (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))))))
                        ? ((0x1000000U == (0x1ffffffU 
                                           & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                            ? 0x18U : ((0x2000000U 
                                        == (0x3ffffffU 
                                            & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                        ? 0x19U : (
                                                   (0x4000000U 
                                                    == 
                                                    (0x7ffffffU 
                                                     & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                    ? 0x1aU
                                                    : 
                                                   ((0x8000000U 
                                                     == 
                                                     (0xfffffffU 
                                                      & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                     ? 0x1bU
                                                     : 
                                                    ((0x10000000U 
                                                      == 
                                                      (0x1fffffffU 
                                                       & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                      ? 0x1cU
                                                      : 
                                                     ((0x20000000U 
                                                       == 
                                                       (0x3fffffffU 
                                                        & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                       ? 0x1dU
                                                       : 
                                                      ((0x40000000U 
                                                        == 
                                                        (0x7fffffffU 
                                                         & (~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))
                                                        ? 0x1eU
                                                        : 0x1fU)))))))
                        : 0U))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr 
        = ((((1U == (1U & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
             | (2U == (3U & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
            | (((4U == (7U & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                | (8U == (0xfU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
               | ((0x10U == (0x1fU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                  | ((0x20U == (0x3fU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                     | ((0x40U == (0x7fU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                        | (0x80U == (0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))))))
            ? ((1U == (1U & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                ? 0U : ((2U == (3U & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                         ? 1U : ((4U == (7U & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                  ? 2U : ((8U == (0xfU 
                                                  & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                           ? 3U : (
                                                   (0x10U 
                                                    == 
                                                    (0x1fU 
                                                     & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                    ? 4U
                                                    : 
                                                   ((0x20U 
                                                     == 
                                                     (0x3fU 
                                                      & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                     ? 5U
                                                     : 
                                                    ((0x40U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                      ? 6U
                                                      : 7U)))))))
            : ((((0x100U == (0x1ffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                 | (0x200U == (0x3ffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                | (((0x400U == (0x7ffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                    | (0x800U == (0xfffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                   | ((0x1000U == (0x1fffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                      | ((0x2000U == (0x3fffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                         | ((0x4000U == (0x7fffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                            | (0x8000U == (0xffffU 
                                           & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))))))
                ? ((0x100U == (0x1ffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                    ? 8U : ((0x200U == (0x3ffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                             ? 9U : ((0x400U == (0x7ffU 
                                                 & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                      ? 0xaU : ((0x800U 
                                                 == 
                                                 (0xfffU 
                                                  & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                 ? 0xbU
                                                 : 
                                                ((0x1000U 
                                                  == 
                                                  (0x1fffU 
                                                   & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                  ? 0xcU
                                                  : 
                                                 ((0x2000U 
                                                   == 
                                                   (0x3fffU 
                                                    & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                   ? 0xdU
                                                   : 
                                                  ((0x4000U 
                                                    == 
                                                    (0x7fffU 
                                                     & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                    ? 0xeU
                                                    : 0xfU)))))))
                : ((((0x10000U == (0x1ffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                     | (0x20000U == (0x3ffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                    | (((0x40000U == (0x7ffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                        | (0x80000U == (0xfffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                       | ((0x100000U == (0x1fffffU 
                                         & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                          | ((0x200000U == (0x3fffffU 
                                            & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                             | ((0x400000U == (0x7fffffU 
                                               & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                                | (0x800000U == (0xffffffU 
                                                 & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)))))))
                    ? ((0x10000U == (0x1ffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                        ? 0x10U : ((0x20000U == (0x3ffffU 
                                                 & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                    ? 0x11U : ((0x40000U 
                                                == 
                                                (0x7ffffU 
                                                 & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                ? 0x12U
                                                : (
                                                   (0x80000U 
                                                    == 
                                                    (0xfffffU 
                                                     & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                    ? 0x13U
                                                    : 
                                                   ((0x100000U 
                                                     == 
                                                     (0x1fffffU 
                                                      & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                     ? 0x14U
                                                     : 
                                                    ((0x200000U 
                                                      == 
                                                      (0x3fffffU 
                                                       & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                      ? 0x15U
                                                      : 
                                                     ((0x400000U 
                                                       == 
                                                       (0x7fffffU 
                                                        & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                       ? 0x16U
                                                       : 0x17U)))))))
                    : ((((0x1000000U == (0x1ffffffU 
                                         & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                         | (0x2000000U == (0x3ffffffU 
                                           & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                        | (((0x4000000U == (0x7ffffffU 
                                            & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                            | (0x8000000U == (0xfffffffU 
                                              & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))) 
                           | ((0x10000000U == (0x1fffffffU 
                                               & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                              | ((0x20000000U == (0x3fffffffU 
                                                  & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                                 | ((0x40000000U == 
                                     (0x7fffffffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)) 
                                    | (0x80000000U 
                                       == vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))))))
                        ? ((0x1000000U == (0x1ffffffU 
                                           & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                            ? 0x18U : ((0x2000000U 
                                        == (0x3ffffffU 
                                            & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                        ? 0x19U : (
                                                   (0x4000000U 
                                                    == 
                                                    (0x7ffffffU 
                                                     & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                    ? 0x1aU
                                                    : 
                                                   ((0x8000000U 
                                                     == 
                                                     (0xfffffffU 
                                                      & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                     ? 0x1bU
                                                     : 
                                                    ((0x10000000U 
                                                      == 
                                                      (0x1fffffffU 
                                                       & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                      ? 0x1cU
                                                      : 
                                                     ((0x20000000U 
                                                       == 
                                                       (0x3fffffffU 
                                                        & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                       ? 0x1dU
                                                       : 
                                                      ((0x40000000U 
                                                        == 
                                                        (0x7fffffffU 
                                                         & vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status))
                                                        ? 0x1eU
                                                        : 0x1fU)))))))
                        : 0U))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__fsm_rd_en = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk = 
        ((IData)(vlSelfRef.TB_gpnae__DOT__clk) & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__sigtan_enable));
    vlSelfRef.TB_gpnae__DOT__idle_o = (1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal) 
                                                | (IData)(vlSelfRef.TB_gpnae__DOT__wr_en_i))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__comp 
        = ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Exp) 
           > (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Exp));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zero 
        = (1U & (~ ((0U != (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Exp)) 
                    | (0U != vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Man))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__comp 
        = ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Exp) 
           > (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__comp2 
        = ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Exp) 
           > (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Exp));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zero 
        = (1U & (~ ((0U != (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Exp)) 
                    | (0U != vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Man))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__adder_result 
        = (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Sign) 
            << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Exponent) 
                          << 0x17U) | vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Mantissa));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__add_result 
        = (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign1) 
            << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent1) 
                          << 0x17U) | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa1));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__magcheck 
        = ((~ (0U != ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Exp) 
                      ^ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Exp)))) 
           & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Man 
              > vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Man));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__magcheck 
        = ((~ (0U != ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Exp) 
                      ^ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp)))) 
           & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Man 
              > vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Man));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zero 
        = (1U & (~ ((0U != (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Exp)) 
                    | ((0U != vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Man) 
                       | ((0U != (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp)) 
                          | (0U != vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Man))))));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__magcheck2 
        = ((~ (0U != ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Exp) 
                      ^ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Exp)))) 
           & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Man 
              > vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Man));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__rd_en_coeff = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state)))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_rd_en = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o = 1U;
                }
            }
        }
        if ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state))) {
                if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state)))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__add_valid = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state)))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid = 1U;
                }
            }
        }
    }
    if ((vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc 
         >= vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__b1)) {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next 
            = (0x1ffffffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc 
                             - vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__b1));
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT____Vconcswap_1_h879be175__0 
            = ((0x1fffffeU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next 
                              << 1U)) | (1U & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo 
                                               >> 0x17U)));
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next 
            = vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT____Vconcswap_1_h879be175__0;
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT____Vconcswap_1_h74def98f__0 
            = (1U | (0xfffffeU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo 
                                  << 1U)));
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo_next 
            = vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT____Vconcswap_1_h74def98f__0;
    } else {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next 
            = (0x1ffffffU & (IData)((0x1ffffffULL & 
                                     (VL_SHIFTL_QQI(49,49,32, 
                                                    (((QData)((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc)) 
                                                      << 0x18U) 
                                                     | (QData)((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo))), 1U) 
                                      >> 0x18U))));
        vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo_next 
            = (0xffffffU & (IData)((0x1ffffffffffffULL 
                                    & VL_SHIFTL_QQI(49,49,32, 
                                                    (((QData)((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc)) 
                                                      << 0x18U) 
                                                     | (QData)((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo))), 1U))));
    }
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid = 0U;
    vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan = 3U;
    if ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
        if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                if (vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__fsm_rd_en = 1U;
                }
            }
            if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                if ((0x10U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg))) {
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid = 1U;
                }
            }
        }
        if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
                    = ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                        ? 2U : 7U);
                vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan = 1U;
            } else {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
                    = ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                        ? 2U : 6U);
                vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan = 0U;
            }
        } else {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
                = ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                    ? ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                        ? 2U : 5U) : ((4U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay))
                                       ? 2U : 4U));
        }
    } else if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
            if (vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu) {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state = 4U;
                vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid = 1U;
            } else {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state = 5U;
            }
        } else {
            vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
                = ((1U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                    ? 3U : ((2U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                             ? 6U : ((3U == (IData)(vlSelfRef.TB_gpnae__DOT__control_word_i))
                                      ? 7U : 0U)));
        }
    } else {
        vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state 
            = ((1U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))
                ? 2U : ((IData)(vlSelfRef.TB_gpnae__DOT__start_i)
                         ? 1U : 0U));
    }
    __Vtableidx1 = (0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan);
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt1 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx1];
    __Vtableidx2 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                             >> 8U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt2 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx2];
    __Vtableidx3 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                             >> 0x10U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt3 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx3];
    __Vtableidx4 = (0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan);
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt1 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx4];
    __Vtableidx5 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                             >> 8U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt2 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx5];
    __Vtableidx6 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                             >> 0x10U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt3 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx6];
    __Vtableidx7 = (0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1);
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt1 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx7];
    __Vtableidx8 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                             >> 8U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt2 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx8];
    __Vtableidx9 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                             >> 0x10U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt3 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx9];
    __Vtableidx10 = (0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2);
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt1 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx10];
    __Vtableidx11 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                              >> 8U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt2 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx11];
    __Vtableidx12 = (0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                              >> 0x10U));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt3 
        = VTB_gpnae__ConstPool__TABLE_he6d3ea54_0[__Vtableidx12];
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_input = 
        ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)
          ? vlSelfRef.TB_gpnae__DOT__dut__DOT__fifo_data_registered
          : vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_result);
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
            if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid = 1U;
            }
        }
    }
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n 
        = ((~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o)) 
           & (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__valid_i 
        = ((~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)) 
           & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__mux_output 
        = ((((0U == (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan))
              ? vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_result
              : 0U) & ((0U == (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan))
                        ? 0xffffffffU : 0U)) | (((1U 
                                                  == (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan))
                                                  ? 
                                                 (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2) 
                                                      << 0x17U) 
                                                     | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2))
                                                  : 0U) 
                                                & ((1U 
                                                    == (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan))
                                                    ? 0xffffffffU
                                                    : 0U)));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zerocount 
        = (0x1fU & ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt3))
                     ? ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt2))
                         ? ((IData)(0x10U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt1))
                         : ((IData)(8U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt2)))
                     : (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt3)));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zerocount 
        = (0x1fU & ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt3))
                     ? ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt2))
                         ? ((IData)(0x10U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt1))
                         : ((IData)(8U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt2)))
                     : (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt3)));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount1 
        = (0x1fU & ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt3))
                     ? ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt2))
                         ? ((IData)(0x10U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt1))
                         : ((IData)(8U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt2)))
                     : (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt3)));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount2 
        = (0x1fU & ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt3))
                     ? ((8U & (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt2))
                         ? ((IData)(0x10U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt1))
                         : ((IData)(8U) + (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt2)))
                     : (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt3)));
    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o = 0U;
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
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_comb = 1U;
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__load_result = 1U;
                    if ((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid)))) {
                        if ((0U < (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count))) {
                            vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o = 1U;
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
                    vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o = 1U;
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
}
