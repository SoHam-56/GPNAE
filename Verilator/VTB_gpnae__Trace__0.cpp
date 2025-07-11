// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTB_gpnae__Syms.h"


void VTB_gpnae___024root__trace_chg_0_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_0\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_0_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_0_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[4]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[5]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[6]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[7]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[8]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[9]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[10]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[11]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[12]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[13]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[14]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[15]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[16]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[17]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[18]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[19]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[20]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[21]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[22]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[23]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[24]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[25]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[26]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[27]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[28]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[29]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.TB_gpnae__DOT__signal_tanh[0]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.TB_gpnae__DOT__signal_tanh[1]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.TB_gpnae__DOT__signal_tanh[2]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.TB_gpnae__DOT__signal_tanh[3]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.TB_gpnae__DOT__signal_tanh[4]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.TB_gpnae__DOT__signal_tanh[5]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.TB_gpnae__DOT__signal_tanh[6]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.TB_gpnae__DOT__signal_tanh[7]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.TB_gpnae__DOT__signal_tanh[8]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.TB_gpnae__DOT__signal_tanh[9]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.TB_gpnae__DOT__signal_tanh[10]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.TB_gpnae__DOT__signal_tanh[11]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.TB_gpnae__DOT__signal_tanh[12]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.TB_gpnae__DOT__signal_tanh[13]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.TB_gpnae__DOT__signal_tanh[14]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.TB_gpnae__DOT__signal_tanh[15]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.TB_gpnae__DOT__signal_tanh[16]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.TB_gpnae__DOT__signal_tanh[17]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.TB_gpnae__DOT__signal_tanh[18]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.TB_gpnae__DOT__signal_tanh[19]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.TB_gpnae__DOT__signal_tanh[20]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.TB_gpnae__DOT__signal_tanh[21]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.TB_gpnae__DOT__signal_tanh[22]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.TB_gpnae__DOT__signal_tanh[23]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.TB_gpnae__DOT__signal_tanh[24]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.TB_gpnae__DOT__signal_tanh[25]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.TB_gpnae__DOT__signal_tanh[26]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.TB_gpnae__DOT__signal_tanh[27]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.TB_gpnae__DOT__signal_tanh[28]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.TB_gpnae__DOT__signal_tanh[29]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+60,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[0]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[1]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[2]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[3]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[4]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[5]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[6]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[7]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[8]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[9]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[10]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[11]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[12]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[13]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[14]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[15]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[16]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[17]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[18]),32);
        bufp->chgIData(oldp+79,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[19]),32);
        bufp->chgIData(oldp+80,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[20]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[21]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[22]),32);
        bufp->chgIData(oldp+83,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[23]),32);
        bufp->chgIData(oldp+84,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[24]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[25]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[26]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[27]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[28]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[29]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[30]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[31]),32);
    }
}

void VTB_gpnae___024root__trace_chg_1_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_1(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_1\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_1_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_1_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_1_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 93);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.TB_gpnae__DOT__rstn_i));
        bufp->chgIData(oldp+1,(vlSelfRef.TB_gpnae__DOT__signal_i),32);
        bufp->chgBit(oldp+2,(vlSelfRef.TB_gpnae__DOT__wr_en_i));
        bufp->chgBit(oldp+3,(vlSelfRef.TB_gpnae__DOT__last_i));
        bufp->chgBit(oldp+4,(vlSelfRef.TB_gpnae__DOT__start_i));
        bufp->chgCData(oldp+5,(vlSelfRef.TB_gpnae__DOT__terms_i),5);
        bufp->chgCData(oldp+6,(vlSelfRef.TB_gpnae__DOT__control_word_i),2);
        bufp->chgCData(oldp+7,(vlSelfRef.TB_gpnae__DOT__num_sig),5);
        bufp->chgIData(oldp+8,(vlSelfRef.TB_gpnae__DOT__buffer_write_start_cycle),32);
        bufp->chgIData(oldp+9,(vlSelfRef.TB_gpnae__DOT__buffer_write_end_cycle),32);
        bufp->chgIData(oldp+10,(vlSelfRef.TB_gpnae__DOT__processing_start_cycle),32);
        bufp->chgIData(oldp+11,(vlSelfRef.TB_gpnae__DOT__processing_end_cycle),32);
        bufp->chgIData(oldp+12,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[0]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[1]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[2]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[3]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[4]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[5]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[6]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[7]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[8]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[9]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[10]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[11]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[12]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[13]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[14]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[15]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[16]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[17]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[18]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[19]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[20]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[21]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[22]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[23]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[24]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[25]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[26]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[27]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[28]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[29]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[30]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[31]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.TB_gpnae__DOT__total_buffer_write_cycles),32);
        bufp->chgIData(oldp+45,(vlSelfRef.TB_gpnae__DOT__total_processing_cycles),32);
        bufp->chgIData(oldp+46,(vlSelfRef.TB_gpnae__DOT__total_operation_cycles),32);
        bufp->chgIData(oldp+47,(vlSelfRef.TB_gpnae__DOT__total_input_cycles),32);
        bufp->chgIData(oldp+48,(vlSelfRef.TB_gpnae__DOT__avg_cycles_per_input),32);
        bufp->chgCData(oldp+49,((0x1fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.TB_gpnae__DOT__terms_i)))),5);
        bufp->chgBit(oldp+50,((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)))));
        bufp->chgIData(oldp+51,(vlSelfRef.TB_gpnae__DOT__perform_test__Vstatic__unnamedblk3__DOT__i),32);
        bufp->chgIData(oldp+52,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__processed),32);
        bufp->chgIData(oldp+53,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__last_done_cycle),32);
        bufp->chgIData(oldp+54,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__current_done_cycle),32);
        bufp->chgIData(oldp+55,(vlSelfRef.TB_gpnae__DOT__write_signal__Vstatic__unnamedblk2__DOT__start_cycle),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+56,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign));
        bufp->chgBit(oldp+57,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign_A));
        bufp->chgBit(oldp+58,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign_B));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+59,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__A_high),12);
        bufp->chgSData(oldp+60,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__A_low),12);
        bufp->chgSData(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp1),13);
        bufp->chgSData(oldp+62,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold),12);
        bufp->chgSData(oldp+63,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold),12);
        bufp->chgSData(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold),12);
        bufp->chgSData(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold),12);
        bufp->chgSData(oldp+66,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold),13);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage6));
        bufp->chgIData(oldp+68,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last),24);
        bufp->chgIData(oldp+69,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last),24);
        bufp->chgIData(oldp+70,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last),26);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+71,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign));
    }
}

void VTB_gpnae___024root__trace_chg_2_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_2(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_2\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_2_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_2_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_2_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 165);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign_A));
        bufp->chgBit(oldp+1,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign_B));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgCData(oldp+2,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__Temp_Exponent),8);
        bufp->chgCData(oldp+3,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Exponent_reg),8);
        bufp->chgCData(oldp+4,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Exponent_reg),8);
        bufp->chgCData(oldp+5,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__lowest_sum),3);
        bufp->chgCData(oldp+6,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__second_sum),3);
        bufp->chgCData(oldp+7,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__third_sum),3);
        bufp->chgCData(oldp+8,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__final_sum),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgBit(oldp+9,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__capture_valid));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__lowest_valid));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__second_valid));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__third_valid));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__final_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgSData(oldp+14,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold),12);
        bufp->chgSData(oldp+15,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold),12);
        bufp->chgSData(oldp+16,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold),12);
        bufp->chgSData(oldp+17,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold),12);
        bufp->chgSData(oldp+18,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold),13);
        bufp->chgSData(oldp+19,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold),13);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xaU]))) {
        bufp->chgBit(oldp+20,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__carry));
        bufp->chgCData(oldp+21,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__DifferenceExp),8);
        bufp->chgIData(oldp+22,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Temp_SmallMan),24);
        bufp->chgIData(oldp+23,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan),24);
        bufp->chgCData(oldp+24,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan)),8);
        bufp->chgCData(oldp+25,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                                          >> 8U))),8);
        bufp->chgCData(oldp+26,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                                          >> 0x10U))),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xbU]))) {
        bufp->chgCData(oldp+27,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent1),8);
        bufp->chgCData(oldp+28,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2),8);
        bufp->chgIData(oldp+29,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa1),23);
        bufp->chgIData(oldp+30,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2),23);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xcU]))) {
        bufp->chgBit(oldp+31,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__carry1));
        bufp->chgBit(oldp+32,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__carry2));
        bufp->chgIData(oldp+33,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1),24);
        bufp->chgIData(oldp+34,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2),24);
        bufp->chgCData(oldp+35,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1)),8);
        bufp->chgCData(oldp+36,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                                          >> 8U))),8);
        bufp->chgCData(oldp+37,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                                          >> 0x10U))),8);
        bufp->chgCData(oldp+38,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2)),8);
        bufp->chgCData(oldp+39,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                                          >> 8U))),8);
        bufp->chgCData(oldp+40,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                                          >> 0x10U))),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xdU]))) {
        bufp->chgBit(oldp+41,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__carry));
        bufp->chgCData(oldp+42,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__DifferenceExp),8);
        bufp->chgIData(oldp+43,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Temp_SmallMan),24);
        bufp->chgIData(oldp+44,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan),24);
        bufp->chgCData(oldp+45,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan)),8);
        bufp->chgCData(oldp+46,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                                          >> 8U))),8);
        bufp->chgCData(oldp+47,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                                          >> 0x10U))),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xeU]))) {
        bufp->chgIData(oldp+48,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0]),24);
        bufp->chgIData(oldp+49,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1]),24);
        bufp->chgIData(oldp+50,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2]),24);
        bufp->chgIData(oldp+51,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0]),24);
        bufp->chgIData(oldp+52,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1]),24);
        bufp->chgIData(oldp+53,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2]),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xfU]))) {
        bufp->chgIData(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0]),24);
        bufp->chgIData(oldp+55,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1]),24);
        bufp->chgIData(oldp+56,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2]),24);
        bufp->chgIData(oldp+57,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3]),24);
        bufp->chgIData(oldp+58,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4]),24);
        bufp->chgIData(oldp+59,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5]),24);
        bufp->chgIData(oldp+60,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6]),24);
        bufp->chgIData(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0]),24);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1]),24);
        bufp->chgIData(oldp+63,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2]),24);
        bufp->chgIData(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0]),24);
        bufp->chgIData(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1]),24);
        bufp->chgIData(oldp+66,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2]),24);
        bufp->chgIData(oldp+67,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x10U]))) {
        bufp->chgIData(oldp+68,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0]),24);
        bufp->chgIData(oldp+69,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1]),24);
        bufp->chgIData(oldp+70,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2]),24);
        bufp->chgIData(oldp+71,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3]),24);
        bufp->chgIData(oldp+72,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4]),24);
        bufp->chgIData(oldp+73,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5]),24);
        bufp->chgIData(oldp+74,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6]),24);
    }
}

void VTB_gpnae___024root__trace_chg_3_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_3(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_3\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_3_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_3_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_3_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 240);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x10U]))) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0]),24);
        bufp->chgIData(oldp+1,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1]),24);
        bufp->chgIData(oldp+2,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2]),24);
        bufp->chgIData(oldp+3,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0]),24);
        bufp->chgIData(oldp+4,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1]),24);
        bufp->chgIData(oldp+5,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2]),24);
        bufp->chgIData(oldp+6,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x11U]))) {
        bufp->chgIData(oldp+7,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0]),26);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1]),26);
        bufp->chgIData(oldp+9,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2]),26);
        bufp->chgIData(oldp+10,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3]),26);
        bufp->chgIData(oldp+11,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4]),26);
        bufp->chgIData(oldp+12,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5]),26);
        bufp->chgIData(oldp+13,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6]),26);
        bufp->chgIData(oldp+14,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0]),26);
        bufp->chgIData(oldp+15,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1]),26);
        bufp->chgIData(oldp+16,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2]),26);
        bufp->chgIData(oldp+17,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0]),26);
        bufp->chgIData(oldp+18,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1]),26);
        bufp->chgIData(oldp+19,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2]),26);
        bufp->chgIData(oldp+20,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last),26);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x12U]))) {
        bufp->chgIData(oldp+21,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0]),24);
        bufp->chgIData(oldp+22,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1]),24);
        bufp->chgIData(oldp+23,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2]),24);
        bufp->chgIData(oldp+24,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3]),24);
        bufp->chgIData(oldp+25,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4]),24);
        bufp->chgIData(oldp+26,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5]),24);
        bufp->chgIData(oldp+27,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6]),24);
        bufp->chgIData(oldp+28,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0]),24);
        bufp->chgIData(oldp+29,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1]),24);
        bufp->chgIData(oldp+30,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2]),24);
        bufp->chgIData(oldp+31,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0]),24);
        bufp->chgIData(oldp+32,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1]),24);
        bufp->chgIData(oldp+33,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2]),24);
        bufp->chgIData(oldp+34,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3]),24);
        bufp->chgIData(oldp+35,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4]),24);
        bufp->chgIData(oldp+36,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5]),24);
        bufp->chgIData(oldp+37,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6]),24);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0]),24);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1]),24);
        bufp->chgIData(oldp+40,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2]),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x13U]))) {
        bufp->chgIData(oldp+41,(vlSelfRef.TB_gpnae__DOT__final_result_o),32);
        bufp->chgBit(oldp+42,(vlSelfRef.TB_gpnae__DOT__done_o));
        bufp->chgBit(oldp+43,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_enable));
        bufp->chgBit(oldp+44,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_enable));
        bufp->chgBit(oldp+45,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_enable));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x14U]))) {
        bufp->chgIData(oldp+46,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0]),26);
        bufp->chgIData(oldp+47,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1]),26);
        bufp->chgIData(oldp+48,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2]),26);
        bufp->chgIData(oldp+49,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+50,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk2__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x15U]))) {
        bufp->chgBit(oldp+51,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__load_result));
        bufp->chgBit(oldp+52,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o));
        bufp->chgCData(oldp+53,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x16U]))) {
        bufp->chgIData(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0]),24);
        bufp->chgIData(oldp+55,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1]),24);
        bufp->chgIData(oldp+56,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2]),24);
        bufp->chgIData(oldp+57,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3]),24);
        bufp->chgIData(oldp+58,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4]),24);
        bufp->chgIData(oldp+59,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5]),24);
        bufp->chgIData(oldp+60,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6]),24);
        bufp->chgCData(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0]),3);
        bufp->chgCData(oldp+62,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1]),3);
        bufp->chgCData(oldp+63,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2]),3);
        bufp->chgCData(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3]),3);
        bufp->chgCData(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4]),3);
        bufp->chgCData(oldp+66,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5]),3);
        bufp->chgCData(oldp+67,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6]),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x17U]))) {
        bufp->chgIData(oldp+68,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0]),24);
        bufp->chgIData(oldp+69,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1]),24);
        bufp->chgIData(oldp+70,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2]),24);
        bufp->chgIData(oldp+71,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3]),24);
        bufp->chgIData(oldp+72,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4]),24);
        bufp->chgIData(oldp+73,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5]),24);
        bufp->chgIData(oldp+74,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6]),24);
    }
}

void VTB_gpnae___024root__trace_chg_4_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_4(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_4\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_4_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_4_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_4_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 315);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x17U]))) {
        bufp->chgCData(oldp+0,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0]),3);
        bufp->chgCData(oldp+1,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1]),3);
        bufp->chgCData(oldp+2,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2]),3);
        bufp->chgCData(oldp+3,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3]),3);
        bufp->chgCData(oldp+4,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4]),3);
        bufp->chgCData(oldp+5,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5]),3);
        bufp->chgCData(oldp+6,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6]),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x18U]))) {
        bufp->chgIData(oldp+7,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0]),26);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1]),26);
        bufp->chgIData(oldp+9,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2]),26);
        bufp->chgIData(oldp+10,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3]),26);
        bufp->chgIData(oldp+11,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4]),26);
        bufp->chgIData(oldp+12,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5]),26);
        bufp->chgIData(oldp+13,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6]),26);
        bufp->chgCData(oldp+14,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0]),3);
        bufp->chgCData(oldp+15,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1]),3);
        bufp->chgCData(oldp+16,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2]),3);
        bufp->chgCData(oldp+17,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3]),3);
        bufp->chgCData(oldp+18,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4]),3);
        bufp->chgCData(oldp+19,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5]),3);
        bufp->chgCData(oldp+20,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6]),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x19U]))) {
        bufp->chgIData(oldp+21,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0]),24);
        bufp->chgIData(oldp+22,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1]),24);
        bufp->chgIData(oldp+23,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2]),24);
        bufp->chgIData(oldp+24,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3]),24);
        bufp->chgIData(oldp+25,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4]),24);
        bufp->chgIData(oldp+26,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5]),24);
        bufp->chgIData(oldp+27,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6]),24);
        bufp->chgCData(oldp+28,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0]),3);
        bufp->chgCData(oldp+29,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1]),3);
        bufp->chgCData(oldp+30,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2]),3);
        bufp->chgCData(oldp+31,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3]),3);
        bufp->chgCData(oldp+32,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4]),3);
        bufp->chgCData(oldp+33,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5]),3);
        bufp->chgCData(oldp+34,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6]),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1aU]))) {
        bufp->chgIData(oldp+35,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0]),24);
        bufp->chgIData(oldp+36,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1]),24);
        bufp->chgIData(oldp+37,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2]),24);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3]),24);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4]),24);
        bufp->chgIData(oldp+40,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5]),24);
        bufp->chgIData(oldp+41,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6]),24);
        bufp->chgCData(oldp+42,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0]),3);
        bufp->chgCData(oldp+43,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1]),3);
        bufp->chgCData(oldp+44,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2]),3);
        bufp->chgCData(oldp+45,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3]),3);
        bufp->chgCData(oldp+46,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4]),3);
        bufp->chgCData(oldp+47,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5]),3);
        bufp->chgCData(oldp+48,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6]),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1bU]))) {
        bufp->chgCData(oldp+49,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Exponent),8);
        bufp->chgCData(oldp+50,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__Temp_Exponent),8);
        bufp->chgCData(oldp+51,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Exponent_reg),8);
        bufp->chgCData(oldp+52,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__lowest_sum),3);
        bufp->chgCData(oldp+53,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__second_sum),3);
        bufp->chgCData(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__third_sum),3);
        bufp->chgCData(oldp+55,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__final_sum),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1cU]))) {
        bufp->chgSData(oldp+56,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__A_high),12);
        bufp->chgSData(oldp+57,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__A_low),12);
        bufp->chgSData(oldp+58,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__B_high),12);
        bufp->chgSData(oldp+59,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__B_low),12);
        bufp->chgSData(oldp+60,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp1),13);
        bufp->chgSData(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp2),13);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1dU]))) {
        bufp->chgCData(oldp+62,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[0]),8);
        bufp->chgCData(oldp+63,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[1]),8);
        bufp->chgCData(oldp+64,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[2]),8);
        bufp->chgCData(oldp+65,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[3]),8);
        bufp->chgCData(oldp+66,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[4]),8);
        bufp->chgCData(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[5]),8);
        bufp->chgCData(oldp+68,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[6]),8);
        bufp->chgCData(oldp+69,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[7]),8);
        bufp->chgCData(oldp+70,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[8]),8);
        bufp->chgCData(oldp+71,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[9]),8);
        bufp->chgCData(oldp+72,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[10]),8);
        bufp->chgCData(oldp+73,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[11]),8);
        bufp->chgCData(oldp+74,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[12]),8);
        bufp->chgCData(oldp+75,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[13]),8);
        bufp->chgCData(oldp+76,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[14]),8);
        bufp->chgCData(oldp+77,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[15]),8);
        bufp->chgCData(oldp+78,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[16]),8);
        bufp->chgCData(oldp+79,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[17]),8);
        bufp->chgCData(oldp+80,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[18]),8);
        bufp->chgCData(oldp+81,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[19]),8);
        bufp->chgCData(oldp+82,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[20]),8);
        bufp->chgCData(oldp+83,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[21]),8);
        bufp->chgCData(oldp+84,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[22]),8);
        bufp->chgCData(oldp+85,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[23]),8);
    }
}

void VTB_gpnae___024root__trace_chg_5_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_5(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_5\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_5_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_5_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_5_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 401);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1eU]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[0]));
        bufp->chgBit(oldp+1,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[1]));
        bufp->chgBit(oldp+2,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[2]));
        bufp->chgBit(oldp+3,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[3]));
        bufp->chgBit(oldp+4,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[4]));
        bufp->chgBit(oldp+5,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[5]));
        bufp->chgBit(oldp+6,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[6]));
        bufp->chgBit(oldp+7,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[7]));
        bufp->chgBit(oldp+8,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[8]));
        bufp->chgBit(oldp+9,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[9]));
        bufp->chgBit(oldp+10,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[10]));
        bufp->chgBit(oldp+11,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[11]));
        bufp->chgBit(oldp+12,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[12]));
        bufp->chgBit(oldp+13,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[13]));
        bufp->chgBit(oldp+14,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[14]));
        bufp->chgBit(oldp+15,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[15]));
        bufp->chgBit(oldp+16,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[16]));
        bufp->chgBit(oldp+17,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[17]));
        bufp->chgBit(oldp+18,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[18]));
        bufp->chgBit(oldp+19,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[19]));
        bufp->chgBit(oldp+20,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[20]));
        bufp->chgBit(oldp+21,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[21]));
        bufp->chgBit(oldp+22,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[22]));
        bufp->chgBit(oldp+23,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[23]));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1fU]))) {
        bufp->chgBit(oldp+24,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__div_done));
        bufp->chgIData(oldp+25,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__Temp_Mantissa),24);
        bufp->chgBit(oldp+26,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__valid));
        bufp->chgBit(oldp+27,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__ovf));
        bufp->chgIData(oldp+28,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo),24);
        bufp->chgIData(oldp+29,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc),25);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x20U]))) {
        bufp->chgBit(oldp+30,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__check1));
        bufp->chgBit(oldp+31,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__check2));
        bufp->chgIData(oldp+32,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigMan1),24);
        bufp->chgIData(oldp+33,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigMan2),24);
        bufp->chgBit(oldp+34,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_sign));
        bufp->chgBit(oldp+35,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C1_sign));
        bufp->chgBit(oldp+36,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_sign));
        bufp->chgBit(oldp+37,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__sign1));
        bufp->chgBit(oldp+38,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__sign2));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x21U]))) {
        bufp->chgSData(oldp+39,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__B_high),12);
        bufp->chgSData(oldp+40,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__B_low),12);
        bufp->chgSData(oldp+41,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp2),13);
        bufp->chgSData(oldp+42,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold),13);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x22U]))) {
        bufp->chgBit(oldp+43,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage2));
        bufp->chgBit(oldp+44,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage3));
        bufp->chgBit(oldp+45,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage4));
        bufp->chgBit(oldp+46,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage5));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x23U]))) {
        bufp->chgBit(oldp+47,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__check));
        bufp->chgCData(oldp+48,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__BigExp),8);
        bufp->chgCData(oldp+49,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__SmallExp),8);
        bufp->chgIData(oldp+50,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__BigMan),24);
        bufp->chgIData(oldp+51,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__SmallMan),24);
        bufp->chgBit(oldp+52,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_sign));
        bufp->chgBit(oldp+53,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_sign));
        bufp->chgCData(oldp+54,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Exp),8);
        bufp->chgCData(oldp+55,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Exp),8);
        bufp->chgIData(oldp+56,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Man),23);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x24U]))) {
        bufp->chgIData(oldp+57,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Mantissa),24);
        bufp->chgIData(oldp+58,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Mantissa),24);
        bufp->chgBit(oldp+59,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign_A));
        bufp->chgBit(oldp+60,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign_B));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x25U]))) {
        bufp->chgIData(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan),23);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ManChoice1),23);
        bufp->chgIData(oldp+63,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ManChoice2),23);
        bufp->chgCData(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp),8);
        bufp->chgBit(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__choice));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x26U]))) {
        bufp->chgCData(oldp+66,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigExp1),8);
        bufp->chgCData(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigExp2),8);
        bufp->chgCData(oldp+68,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallExp1),8);
        bufp->chgCData(oldp+69,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallExp2),8);
        bufp->chgCData(oldp+70,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__DifferenceExp1),8);
        bufp->chgCData(oldp+71,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__DifferenceExp2),8);
    }
}

void VTB_gpnae___024root__trace_chg_6_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_6(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_6\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_6_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_6_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_6_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 473);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x26U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallMan1),24);
        bufp->chgIData(oldp+1,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallMan2),24);
        bufp->chgIData(oldp+2,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Temp_SmallMan1),24);
        bufp->chgIData(oldp+3,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Temp_SmallMan2),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x27U]))) {
        bufp->chgIData(oldp+4,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan),24);
        bufp->chgIData(oldp+5,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan_delayed),24);
        bufp->chgIData(oldp+6,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan_delayed_delayed),24);
        bufp->chgIData(oldp+7,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallMan),24);
        bufp->chgIData(oldp+8,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallMan_delayed),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x28U]))) {
        bufp->chgCData(oldp+9,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp),8);
        bufp->chgCData(oldp+10,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed),8);
        bufp->chgCData(oldp+11,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed_delayed),8);
        bufp->chgCData(oldp+12,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed_delayed_delayed),8);
        bufp->chgCData(oldp+13,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallExp),8);
        bufp->chgCData(oldp+14,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x29U]))) {
        bufp->chgBit(oldp+15,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__comp2));
        bufp->chgBit(oldp+16,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__magcheck2));
        bufp->chgBit(oldp+17,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zero));
        bufp->chgCData(oldp+18,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Exp),8);
        bufp->chgCData(oldp+19,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Exp),8);
        bufp->chgIData(oldp+20,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Man),23);
        bufp->chgIData(oldp+21,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Man),23);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x2aU]))) {
        bufp->chgQData(oldp+22,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted),48);
        bufp->chgQData(oldp+24,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted1),48);
        bufp->chgQData(oldp+26,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted2),48);
        bufp->chgQData(oldp+28,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended),48);
        bufp->chgQData(oldp+30,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended1),48);
        bufp->chgQData(oldp+32,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended2),48);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x2bU]))) {
        bufp->chgIData(oldp+34,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_middle),26);
        bufp->chgIData(oldp+35,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3_stage1),26);
        bufp->chgIData(oldp+36,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3),25);
        bufp->chgQData(oldp+37,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3_shifted),48);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__accum),26);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x2cU]))) {
        bufp->chgIData(oldp+40,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1),32);
        bufp->chgCData(oldp+41,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Exponent),8);
        bufp->chgCData(oldp+42,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Exponent_reg),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x2dU]))) {
        bufp->chgBit(oldp+43,((vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                               >> 0x1fU)));
        bufp->chgBit(oldp+44,((0U == vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)));
        bufp->chgIData(oldp+45,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status),32);
        bufp->chgBit(oldp+46,((1U & (~ (vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                        >> 0x1fU)))));
        bufp->chgIData(oldp+47,((~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x2eU]))) {
        bufp->chgIData(oldp+48,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_raw),24);
        bufp->chgIData(oldp+49,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_raw),24);
        bufp->chgIData(oldp+50,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high),24);
        bufp->chgIData(oldp+51,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low),24);
        bufp->chgIData(oldp+52,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low2),26);
        bufp->chgIData(oldp+53,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__accum),24);
        bufp->chgIData(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__accum),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x2fU]))) {
        bufp->chgCData(oldp+55,(vlSelfRef.TB_gpnae__DOT__dut__DOT__current_state),3);
        bufp->chgBit(oldp+56,(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal));
        bufp->chgCData(oldp+57,(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan),2);
        bufp->chgBit(oldp+58,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid));
        bufp->chgCData(oldp+59,(vlSelfRef.TB_gpnae__DOT__dut__DOT__done_delay),3);
        bufp->chgBit(oldp+60,(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x30U]))) {
        bufp->chgBit(oldp+61,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage1));
        bufp->chgBit(oldp+62,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage2));
        bufp->chgBit(oldp+63,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage3));
        bufp->chgBit(oldp+64,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage4));
        bufp->chgBit(oldp+65,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage5));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x31U]))) {
        bufp->chgIData(oldp+66,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[0]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[1]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[2]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[3]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[4]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[5]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[6]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[7]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[8]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[9]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[10]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[11]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[12]),32);
        bufp->chgIData(oldp+79,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[13]),32);
        bufp->chgIData(oldp+80,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[14]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[15]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[16]),32);
        bufp->chgIData(oldp+83,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[17]),32);
        bufp->chgIData(oldp+84,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[18]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[19]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[20]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[21]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[22]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[23]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[24]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[25]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[26]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[27]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[28]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[29]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[30]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[31]),32);
    }
}

void VTB_gpnae___024root__trace_chg_7_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_7(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_7\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_7_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_7_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_7_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 571);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x32U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check));
        bufp->chgBit(oldp+1,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check_delayed));
        bufp->chgBit(oldp+2,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check_delayed_delayed));
        bufp->chgBit(oldp+3,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_sign));
        bufp->chgBit(oldp+4,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign));
        bufp->chgBit(oldp+5,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed));
        bufp->chgBit(oldp+6,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed_delayed));
        bufp->chgBit(oldp+7,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed_delayed_delayed));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x33U]))) {
        bufp->chgIData(oldp+8,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0]),26);
        bufp->chgIData(oldp+9,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1]),26);
        bufp->chgIData(oldp+10,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2]),26);
        bufp->chgIData(oldp+11,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3]),26);
        bufp->chgIData(oldp+12,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4]),26);
        bufp->chgIData(oldp+13,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5]),26);
        bufp->chgIData(oldp+14,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6]),26);
        bufp->chgIData(oldp+15,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0]),26);
        bufp->chgIData(oldp+16,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1]),26);
        bufp->chgIData(oldp+17,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2]),26);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x34U]))) {
        bufp->chgIData(oldp+18,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0]),26);
        bufp->chgIData(oldp+19,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1]),26);
        bufp->chgIData(oldp+20,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2]),26);
        bufp->chgIData(oldp+21,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3]),26);
        bufp->chgIData(oldp+22,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4]),26);
        bufp->chgIData(oldp+23,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5]),26);
        bufp->chgIData(oldp+24,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6]),26);
        bufp->chgCData(oldp+25,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0]),3);
        bufp->chgCData(oldp+26,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1]),3);
        bufp->chgCData(oldp+27,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2]),3);
        bufp->chgCData(oldp+28,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3]),3);
        bufp->chgCData(oldp+29,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4]),3);
        bufp->chgCData(oldp+30,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5]),3);
        bufp->chgCData(oldp+31,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6]),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x35U]))) {
        bufp->chgCData(oldp+32,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zerocount),5);
        bufp->chgBit(oldp+33,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__comp));
        bufp->chgBit(oldp+34,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__magcheck));
        bufp->chgBit(oldp+35,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zero));
        bufp->chgIData(oldp+36,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Man),23);
        bufp->chgCData(oldp+37,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt1),4);
        bufp->chgCData(oldp+38,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt2),4);
        bufp->chgCData(oldp+39,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt3),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x36U]))) {
        bufp->chgCData(oldp+40,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount1),5);
        bufp->chgCData(oldp+41,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount2),5);
        bufp->chgCData(oldp+42,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt1),4);
        bufp->chgCData(oldp+43,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt2),4);
        bufp->chgCData(oldp+44,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt3),4);
        bufp->chgCData(oldp+45,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt1),4);
        bufp->chgCData(oldp+46,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt2),4);
        bufp->chgCData(oldp+47,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt3),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x37U]))) {
        bufp->chgBit(oldp+48,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__busy));
        bufp->chgIData(oldp+49,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo_next),24);
        bufp->chgIData(oldp+50,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next),25);
        bufp->chgCData(oldp+51,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__i),6);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x38U]))) {
        bufp->chgCData(oldp+52,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ExpChoice1),8);
        bufp->chgCData(oldp+53,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ExpChoice2),8);
        bufp->chgBit(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign));
        bufp->chgBit(oldp+55,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__signChoice));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x39U]))) {
        bufp->chgBit(oldp+56,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage1));
        bufp->chgBit(oldp+57,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage2));
        bufp->chgBit(oldp+58,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage3));
        bufp->chgBit(oldp+59,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage4));
        bufp->chgBit(oldp+60,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage5));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3aU]))) {
        bufp->chgBit(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[0]));
        bufp->chgBit(oldp+62,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[1]));
        bufp->chgBit(oldp+63,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[2]));
        bufp->chgBit(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[3]));
        bufp->chgBit(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[4]));
        bufp->chgCData(oldp+66,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[0]),8);
        bufp->chgCData(oldp+67,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[1]),8);
        bufp->chgCData(oldp+68,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[2]),8);
        bufp->chgCData(oldp+69,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[3]),8);
        bufp->chgCData(oldp+70,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[4]),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3bU]))) {
        bufp->chgBit(oldp+71,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage
                              [8U]));
    }
}

void VTB_gpnae___024root__trace_chg_8_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_8(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_8\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_8_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_8_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_8_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 643);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3bU]))) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[0]));
        bufp->chgBit(oldp+1,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[1]));
        bufp->chgBit(oldp+2,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[2]));
        bufp->chgBit(oldp+3,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[3]));
        bufp->chgBit(oldp+4,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[4]));
        bufp->chgBit(oldp+5,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[5]));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[6]));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[7]));
        bufp->chgBit(oldp+8,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[8]));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3cU]))) {
        bufp->chgBit(oldp+9,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[0]));
        bufp->chgBit(oldp+10,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[1]));
        bufp->chgBit(oldp+11,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[2]));
        bufp->chgBit(oldp+12,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[3]));
        bufp->chgBit(oldp+13,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[4]));
        bufp->chgBit(oldp+14,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[5]));
        bufp->chgBit(oldp+15,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[6]));
        bufp->chgBit(oldp+16,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[7]));
        bufp->chgBit(oldp+17,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[8]));
        bufp->chgBit(oldp+18,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[9]));
        bufp->chgBit(oldp+19,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[10]));
        bufp->chgBit(oldp+20,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[11]));
        bufp->chgBit(oldp+21,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[12]));
        bufp->chgBit(oldp+22,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[13]));
        bufp->chgBit(oldp+23,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[14]));
        bufp->chgBit(oldp+24,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[15]));
        bufp->chgBit(oldp+25,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[16]));
        bufp->chgBit(oldp+26,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[17]));
        bufp->chgBit(oldp+27,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[18]));
        bufp->chgBit(oldp+28,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[19]));
        bufp->chgBit(oldp+29,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[20]));
        bufp->chgBit(oldp+30,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[21]));
        bufp->chgBit(oldp+31,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[22]));
        bufp->chgBit(oldp+32,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[23]));
        bufp->chgBit(oldp+33,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[24]));
        bufp->chgBit(oldp+34,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[25]));
        bufp->chgBit(oldp+35,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage
                              [0U]));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3dU]))) {
        bufp->chgIData(oldp+36,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_data),32);
        bufp->chgIData(oldp+37,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in1),32);
        bufp->chgBit(oldp+38,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_sign));
        bufp->chgCData(oldp+39,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Exp),8);
        bufp->chgIData(oldp+40,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Man),23);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3eU]))) {
        bufp->chgIData(oldp+41,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in2),32);
        bufp->chgIData(oldp+42,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Man),23);
        bufp->chgIData(oldp+43,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan),23);
        bufp->chgCData(oldp+44,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x3fU]))) {
        bufp->chgIData(oldp+45,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ManChoice1),23);
        bufp->chgCData(oldp+46,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ExpChoice1),8);
        bufp->chgCData(oldp+47,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ExpChoice2),8);
        bufp->chgBit(oldp+48,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__choice));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x40U]))) {
        bufp->chgIData(oldp+49,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2),32);
        bufp->chgCData(oldp+50,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zerocount),5);
        bufp->chgCData(oldp+51,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt1),4);
        bufp->chgCData(oldp+52,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt2),4);
        bufp->chgCData(oldp+53,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt3),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x41U]))) {
        bufp->chgBit(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__lowest_valid));
        bufp->chgBit(oldp+55,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__second_valid));
        bufp->chgBit(oldp+56,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__third_valid));
        bufp->chgBit(oldp+57,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__final_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x42U]))) {
        bufp->chgIData(oldp+58,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ManChoice2),23);
        bufp->chgBit(oldp+59,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign));
        bufp->chgBit(oldp+60,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__signChoice));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x43U]))) {
        bufp->chgBit(oldp+61,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__comp));
        bufp->chgBit(oldp+62,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__magcheck));
        bufp->chgBit(oldp+63,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zero));
        bufp->chgBit(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[0]));
        bufp->chgBit(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[1]));
        bufp->chgBit(oldp+66,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[2]));
        bufp->chgBit(oldp+67,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[3]));
        bufp->chgBit(oldp+68,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[4]));
        bufp->chgCData(oldp+69,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[0]),8);
        bufp->chgCData(oldp+70,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[1]),8);
        bufp->chgCData(oldp+71,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[2]),8);
        bufp->chgCData(oldp+72,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[3]),8);
        bufp->chgCData(oldp+73,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[4]),8);
    }
}

void VTB_gpnae___024root__trace_chg_9_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_9(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_9\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_9_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_9_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_9_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 717);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x44U]))) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage
                             [8U]));
        bufp->chgBit(oldp+1,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[0]));
        bufp->chgBit(oldp+2,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[1]));
        bufp->chgBit(oldp+3,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[2]));
        bufp->chgBit(oldp+4,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[3]));
        bufp->chgBit(oldp+5,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[4]));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[5]));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[6]));
        bufp->chgBit(oldp+8,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[7]));
        bufp->chgBit(oldp+9,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[8]));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__capture_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x45U]))) {
        bufp->chgQData(oldp+11,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__Temp_Mantissa),48);
        bufp->chgIData(oldp+13,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3_stage1),26);
        bufp->chgIData(oldp+14,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3),25);
        bufp->chgQData(oldp+15,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3_shifted),48);
        bufp->chgQData(oldp+17,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__partial_product),48);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x46U]))) {
        bufp->chgIData(oldp+19,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_raw),24);
        bufp->chgIData(oldp+20,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high),24);
        bufp->chgQData(oldp+21,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted),48);
        bufp->chgQData(oldp+23,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted1),48);
        bufp->chgQData(oldp+25,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted2),48);
        bufp->chgIData(oldp+27,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__accum),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x47U]))) {
        bufp->chgIData(oldp+28,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_raw),24);
        bufp->chgIData(oldp+29,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_middle),26);
        bufp->chgIData(oldp+30,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low),24);
        bufp->chgIData(oldp+31,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low2),26);
        bufp->chgQData(oldp+32,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended),48);
        bufp->chgQData(oldp+34,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended1),48);
        bufp->chgQData(oldp+36,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended2),48);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__accum),24);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__accum),26);
    }
    bufp->chgBit(oldp+40,(vlSelfRef.TB_gpnae__DOT__clk));
    bufp->chgBit(oldp+41,((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal) 
                                    | (IData)(vlSelfRef.TB_gpnae__DOT__wr_en_i))))));
    bufp->chgIData(oldp+42,(vlSelfRef.TB_gpnae__DOT__processed_signals),32);
    bufp->chgIData(oldp+43,(vlSelfRef.TB_gpnae__DOT__cycle_counter),32);
    bufp->chgCData(oldp+44,(vlSelfRef.TB_gpnae__DOT__current_state),2);
    bufp->chgIData(oldp+45,(vlSelfRef.TB_gpnae__DOT__current_phase),32);
    bufp->chgCData(oldp+46,(vlSelfRef.TB_gpnae__DOT__dut__DOT__next_state),3);
    bufp->chgBit(oldp+47,(vlSelfRef.TB_gpnae__DOT__dut__DOT__fsm_rd_en));
    bufp->chgBit(oldp+48,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_rd_en));
    bufp->chgIData(oldp+49,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__doutb_reg),32);
    bufp->chgIData(oldp+50,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_result),32);
    bufp->chgIData(oldp+51,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_result),32);
    bufp->chgIData(oldp+52,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateSign) 
                              << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateExp) 
                                            << 0x17U) 
                                           | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateMan))),32);
    bufp->chgBit(oldp+53,(vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu));
    bufp->chgBit(oldp+54,((1U & ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg) 
                                 >> 4U))));
    bufp->chgBit(oldp+55,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_clk));
    bufp->chgBit(oldp+56,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_clk));
    bufp->chgBit(oldp+57,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk));
    bufp->chgBit(oldp+58,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid));
    bufp->chgIData(oldp+59,(vlSelfRef.TB_gpnae__DOT__dut__DOT__fifo_data_registered),32);
    bufp->chgIData(oldp+60,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_input),32);
    bufp->chgIData(oldp+61,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_const),32);
    bufp->chgCData(oldp+62,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__wr_ptr),5);
    bufp->chgCData(oldp+63,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr),5);
    bufp->chgBit(oldp+64,((1U & (vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                 >> (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr)))));
    bufp->chgIData(oldp+65,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__ram_data_b),32);
    bufp->chgBit(oldp+66,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__rd_en_coeff));
    bufp->chgBit(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__add_valid));
    bufp->chgBit(oldp+68,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid));
    bufp->chgCData(oldp+69,((0x1fU & ((1U & ((~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)) 
                                             | (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o)))
                                       ? (IData)(vlSelfRef.TB_gpnae__DOT__terms_i)
                                       : ((IData)(vlSelfRef.TB_gpnae__DOT__terms_i) 
                                          - (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count))))),5);
    bufp->chgBit(oldp+70,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n));
    bufp->chgBit(oldp+71,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o));
}

void VTB_gpnae___024root__trace_chg_10_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTB_gpnae___024root__trace_chg_10(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_10\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTB_gpnae___024root__trace_chg_10_sub_0((&vlSymsp->TOP), bufp);
}

void VTB_gpnae___024root__trace_chg_10_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_chg_10_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 789);
    // Body
    bufp->chgCData(oldp+0,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state),4);
    bufp->chgCData(oldp+1,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count),5);
    bufp->chgCData(oldp+2,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next),5);
    bufp->chgBit(oldp+3,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_comb));
    bufp->chgCData(oldp+4,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg),5);
    bufp->chgIData(oldp+5,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__adder_result),32);
    bufp->chgIData(oldp+6,((((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign) 
                             << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp) 
                                           << 0x17U) 
                                          | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan))),32);
    bufp->chgBit(oldp+7,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Sign));
    bufp->chgCData(oldp+8,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Exponent),8);
    bufp->chgIData(oldp+9,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Mantissa),23);
    bufp->chgIData(oldp+10,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign) 
                              << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent) 
                                            << 0x17U) 
                                           | vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa))),32);
    bufp->chgBit(oldp+11,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage6));
    bufp->chgBit(oldp+12,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply));
    bufp->chgIData(oldp+13,((((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign) 
                              << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp) 
                                            << 0x17U) 
                                           | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan))),32);
    bufp->chgBit(oldp+14,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i));
    bufp->chgBit(oldp+15,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__valid_i));
    bufp->chgBit(oldp+16,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign));
    bufp->chgCData(oldp+17,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent),8);
    bufp->chgIData(oldp+18,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa),23);
    bufp->chgBit(oldp+19,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage1));
    bufp->chgBit(oldp+20,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__sign));
    bufp->chgIData(oldp+21,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__add_result),32);
    bufp->chgIData(oldp+22,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2) 
                              << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2) 
                                            << 0x17U) 
                                           | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2))),32);
    bufp->chgBit(oldp+23,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage6));
    bufp->chgIData(oldp+24,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__mux_output),32);
    bufp->chgBit(oldp+25,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign1));
    bufp->chgBit(oldp+26,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2));
    bufp->chgCData(oldp+27,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Exponent),8);
    bufp->chgCData(oldp+28,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Exponent),8);
    bufp->chgBit(oldp+29,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign));
    bufp->chgCData(oldp+30,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__Temp_Exponent),8);
    bufp->chgIData(oldp+31,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateMan),23);
    bufp->chgCData(oldp+32,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateExp),8);
    bufp->chgBit(oldp+33,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateSign));
    bufp->chgBit(oldp+34,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__dbz));
    bufp->chgBit(oldp+35,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__capture_valid));
    bufp->chgCData(oldp+36,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Exponent_reg),8);
    bufp->chgCData(oldp+37,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Exponent_reg),8);
    bufp->chgBit(oldp+38,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__lowest_valid));
    bufp->chgBit(oldp+39,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__second_valid));
    bufp->chgBit(oldp+40,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__third_valid));
    bufp->chgBit(oldp+41,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__final_valid));
    bufp->chgCData(oldp+42,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__lowest_diff),3);
    bufp->chgCData(oldp+43,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__second_diff),3);
    bufp->chgCData(oldp+44,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__third_diff),3);
    bufp->chgCData(oldp+45,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__final_diff),5);
    bufp->chgIData(oldp+46,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__b1),24);
    bufp->chgIData(oldp+47,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk1__DOT__i),32);
    bufp->chgIData(oldp+48,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk2__DOT__i),32);
    bufp->chgIData(oldp+49,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk3__DOT__i),32);
    bufp->chgIData(oldp+50,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A),32);
    bufp->chgIData(oldp+51,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Mantissa),24);
    bufp->chgIData(oldp+52,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Mantissa),24);
    bufp->chgCData(oldp+53,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Exponent),8);
    bufp->chgCData(oldp+54,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Exponent),8);
    bufp->chgQData(oldp+55,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__Temp_Mantissa),48);
    bufp->chgQData(oldp+57,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__partial_product),48);
    bufp->chgIData(oldp+59,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__i),32);
    bufp->chgIData(oldp+60,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__i),32);
    bufp->chgIData(oldp+61,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__i),32);
    bufp->chgIData(oldp+62,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk1__DOT__i),32);
    bufp->chgIData(oldp+63,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk2__DOT__i),32);
    bufp->chgIData(oldp+64,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk3__DOT__i),32);
    bufp->chgIData(oldp+65,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Mantissa),24);
    bufp->chgIData(oldp+66,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Mantissa),24);
    bufp->chgIData(oldp+67,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__i),32);
    bufp->chgIData(oldp+68,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__i),32);
    bufp->chgIData(oldp+69,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__i),32);
    bufp->chgIData(oldp+70,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk3__DOT__i),32);
}

void VTB_gpnae___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_cleanup\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x47U)) {
        vlSymsp->TOP.__Vm_traceActivity[__Vilp1] = 0U;
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
}
