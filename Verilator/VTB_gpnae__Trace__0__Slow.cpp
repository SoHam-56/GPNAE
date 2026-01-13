// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTB_gpnae__Syms.h"


VL_ATTR_COLD void VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VTB_gpnae___024root__trace_init_sub__TOP__0(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_init_sub__TOP__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("TB_gpnae", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+865,0,"CONTROL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+753,9,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,1,"signal_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+95,1,"wr_en_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,1,"last_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,1,"start_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,1,"terms_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+99,1,"control_word_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+591,7,"full_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,7,"empty_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+754,9,"idle_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+755,9,"final_result_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+475,6,"done_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,1,"processed_signals",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+756,9,"cycle_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+757,9,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+101,1,"num_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,1,"buffer_write_start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+103,1,"buffer_write_end_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+104,1,"processing_start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+105,1,"processing_end_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("cycles_per_input", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+106+i*1,1,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+138,1,"total_buffer_write_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+139,1,"total_processing_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+140,1,"total_operation_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+141,1,"total_input_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+142,1,"avg_cycles_per_input",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("signal_sigmoid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 30; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("signal_tanh", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 30; ++i) {
        tracep->declBus(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+758,9,"current_phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+866,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+867,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+868,0,"CONTROL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+753,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,1,"signal_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+95,1,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,1,"last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,1,"terms_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+99,1,"control_word_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+591,7,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,7,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+754,9,"idle_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+755,9,"final_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+475,6,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+759,9,"selu_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+760,9,"mac_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+761,9,"sigtan_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+753,9,"mac_credit_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,9,"fifo_data_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+763,9,"fifo_data_registered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+764,9,"mac_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+765,9,"selu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+318,4,"sigtan_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,9,"selu_input",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+676,8,"selu_const",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+869,0,"LAMDA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+870,0,"LAMDA_ALPHA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+593,7,"rd_en_signal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+677,8,"is_positive_selu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+767,9,"selu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+594,7,"mac_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+678,8,"select_sigtan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+768,9,"mac_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+769,9,"done_selu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+770,9,"done_mac",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,7,"done_sigtan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,6,"update_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("input_fifo_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+753,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,1,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+593,7,"rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,1,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+591,7,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,7,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+754,9,"idle_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,9,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+595,7,"status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+771,9,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+772,9,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("FIFO", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+863,0,"RAM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+771,9,"addra",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+772,9,"addrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+94,1,"dina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+753,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,1,"wea",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+596,7,"ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,9,"enb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstnb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+593,7,"regceb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,9,"doutb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("BRAM", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+599+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+774,9,"ram_data_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+762,9,"doutb_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("cntr_read", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+595,7,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+772,9,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("cntr_write", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+597,7,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+771,9,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("mac_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+866,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+867,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+753,9,"mac_credit_clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,1,"fifo_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,9,"signal_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+768,9,"rd_signal_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+594,7,"start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,1,"terms_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+592,7,"empty_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+764,9,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+770,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+671,8,"coeff_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+775,9,"rd_en_coeff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+638,8,"load_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+639,8,"dp_reset_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+776,9,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,9,"mul_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+778,9,"add_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+700,8,"mul_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+779,9,"coeff_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+780,9,"datapath_reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("coeff_rom_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+871,0,"INIT_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 135,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+775,9,"rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+779,9,"coeff_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+671,8,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ROM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+871,0,"INIT_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 135,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+779,9,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+775,9,"rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+671,8,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ROM", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+61+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("controller_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+867,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+753,9,"mac_credit_clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,1,"fifo_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+594,7,"start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,7,"empty_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+143,1,"terms_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+700,8,"mul_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+778,9,"add_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,9,"mul_valid_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+776,9,"add_valid_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+639,8,"dp_reset_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+768,9,"rd_signal_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+775,9,"rd_coeff_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+638,8,"load_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+779,9,"coeff_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+770,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+781,9,"reload_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+640,8,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+782,10,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+783,10,"term_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+784,10,"term_count_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+641,8,"done_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+785,10,"done_shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+786,10,"item_credit_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+787,10,"dec_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("datapath_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,9,"signal_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+671,8,"coeff_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+638,8,"load_result_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+776,9,"add_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,9,"mul_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+778,9,"add_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+700,8,"mul_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+764,9,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+788,10,"mul_in1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+732,9,"mul_in2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+672,8,"add_in1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+578,7,"add_in2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+789,10,"adder_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+790,10,"mul_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("MUL", VerilatedTracePrefixType::SCOPE_MODULE);
    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ADD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+776,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+672,8,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+578,7,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+789,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+778,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+733,9,"zerocount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+182,2,"Sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,10,"Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+792,10,"Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+740,9,"comp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+741,9,"magcheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+742,9,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+421,5,"carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+541,7,"check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+542,7,"check_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+543,7,"check_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+793,10,"BigExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+472,6,"BigExp_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+473,6,"BigExp_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+474,6,"BigExp_delayed_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+794,10,"SmallExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+422,5,"DifferenceExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+438,5,"BigMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+439,5,"BigMan_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+440,5,"BigMan_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+441,5,"SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+442,5,"SmallMan_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+423,5,"Temp_SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+424,5,"TempMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+666,8,"valid_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+667,8,"valid_stage2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+668,8,"valid_stage3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+669,8,"valid_stage4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+670,8,"valid_stage5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+778,9,"valid_stage6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+673,8,"A_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+544,7,"B_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,2,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,2,"sign_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,2,"sign_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,2,"sign_delayed_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+674,8,"A_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+579,7,"B_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+675,8,"A_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+580,7,"B_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("stage_31", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+424,5,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+733,9,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+734,9,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+735,9,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+736,9,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+425,5,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+734,9,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+426,5,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+735,9,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+427,5,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+736,9,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("selu_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+759,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+767,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+677,8,"is_positive_selu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+676,8,"selu_const",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+765,9,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+769,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+795,10,"fp32_down_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+796,10,"done_fp32_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+797,10,"valid_multiply",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+798,10,"multiply_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+652,8,"done_multiply",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("multiply_32_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("fp32_down_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+799,10,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,10,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+795,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+796,10,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+876,0,"CONST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+631,8,"zerocount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+801,10,"Sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+802,10,"Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+803,10,"Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+684,8,"comp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+685,8,"magcheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+686,8,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,6,"carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,7,"check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,7,"BigExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+804,10,"SmallExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+481,6,"DifferenceExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+531,7,"BigMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+532,7,"SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+482,6,"Temp_SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+483,6,"TempMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+635,8,"valid_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+636,8,"valid_stage2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+637,8,"valid_stage3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+805,10,"valid_stage4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+806,10,"valid_stage5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+796,10,"valid_stage6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+533,7,"A_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+534,7,"C_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+807,10,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+662,8,"A_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+663,8,"C_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+664,8,"A_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+665,8,"C_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("stage_31", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+483,6,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+631,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+632,8,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+633,8,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+634,8,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+484,6,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+632,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+485,6,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+633,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+486,6,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+634,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sigtan_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+761,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+770,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+764,9,"mac_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+678,8,"select_sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+318,4,"final_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+535,7,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+808,10,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+809,10,"sub_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+583,7,"done_fp32_add_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+810,10,"mux_output",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+877,0,"mux_output_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fp32_add_sub_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+761,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+770,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+764,9,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+808,10,"Result1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+809,10,"Result2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+583,7,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+878,0,"CONST_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+876,0,"CONST_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+521,6,"zerocount1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+522,6,"zerocount2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+811,10,"Sign1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+812,10,"Sign2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,2,"Exponent1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+169,2,"Exponent2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+170,2,"Mantissa1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+171,2,"Mantissa2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+737,9,"comp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,9,"comp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+738,9,"magcheck1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+738,9,"magcheck2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+739,9,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,2,"carry1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,2,"carry2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+399,5,"check1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,5,"check2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+428,5,"BigExp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+429,5,"BigExp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+430,5,"SmallExp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+431,5,"SmallExp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+432,5,"DifferenceExp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+433,5,"DifferenceExp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+401,5,"BigMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+402,5,"BigMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+434,5,"SmallMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+435,5,"SmallMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+436,5,"Temp_SmallMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+437,5,"Temp_SmallMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+174,2,"TempMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+175,2,"TempMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+813,10,"valid_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+814,10,"valid_stage2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+584,7,"valid_stage3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+585,7,"valid_stage4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+586,7,"valid_stage5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+583,7,"valid_stage6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+403,5,"A_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+404,5,"C1_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+405,5,"C2_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+406,5,"sign1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,5,"sign2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+680,8,"A_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+681,8,"C1_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+681,8,"C2_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+682,8,"A_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+683,8,"C1_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+683,8,"C2_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("stage_31_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+174,2,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+521,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+523,6,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+524,6,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+525,6,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+176,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+523,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+177,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+524,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+178,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+525,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage_31_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+175,2,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+522,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+526,6,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+527,6,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+528,7,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+179,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+526,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+180,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+527,6,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+181,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+528,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_divide_32", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+761,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+583,7,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+810,10,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+808,10,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+318,4,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+535,7,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+545,7,"A_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+546,7,"B_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+815,10,"A_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+816,10,"B_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+817,10,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+818,10,"sign_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+819,10,"sign_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,10,"Temp_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+536,7,"Temp_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+319,4,"intermediateMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+320,4,"intermediateExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+321,4,"intermediateSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+879,0,"bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+880,0,"shiftStages",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 26; ++i) {
        tracep->declBit(c+551+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+322,4,"dbz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,7,"div_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,10,"capture_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+822,10,"A_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+823,10,"B_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+824,10,"lowest_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+825,10,"second_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+826,10,"third_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+827,10,"final_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+828,10,"lowest_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+829,10,"second_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+830,10,"third_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+831,10,"final_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("pipe_sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 24; ++i) {
        tracep->declBit(c+348+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1));
    }
    tracep->popPrefix();
    tracep->pushPrefix("pipe_Exponent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 24; ++i) {
        tracep->declBus(c+324+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("divu_mantissa", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+881,0,"FBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+761,9,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,1,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+577,7,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+547,7,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,7,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+537,7,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,4,"dbz",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+538,7,"ovf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+545,7,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+546,7,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+536,7,"val",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+881,0,"FBITSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+323,4,"b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+539,7,"quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+548,7,"quo_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+540,7,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+549,7,"acc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+882,0,"ITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+550,7,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+832,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+833,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+834,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_control_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+868,0,"CONTROL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+753,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,1,"last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,1,"control_word_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+677,8,"is_positive_selu_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+768,9,"mac_rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+769,9,"done_selu_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+770,9,"done_mac_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,7,"done_sigtan_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+759,9,"selu_clk_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+760,9,"mac_clk_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+761,9,"sigtan_clk_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+767,9,"selu_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+594,7,"mac_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+678,8,"select_sigtan_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+593,7,"fifo_rd_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,6,"update_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+475,6,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+598,7,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+835,10,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+477,6,"selu_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+478,6,"mac_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,6,"sigtan_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+836,10,"fsm_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+679,8,"done_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("perform_test__Vstatic__unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,1,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("wait_for_processing__Vstatic__unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+146,1,"processed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+147,1,"last_done_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+148,1,"current_done_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("write_signal__Vstatic__unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+149,1,"start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+759,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+797,10,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+837,10,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+676,8,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+798,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+652,8,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+838,10,"A_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+839,10,"B_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+385,5,"A_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+386,5,"B_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+150,1,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,1,"sign_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,1,"sign_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+387,5,"Temp_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+840,10,"Temp_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+416,5,"intermediateMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+417,5,"ManChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+418,5,"ManChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+419,5,"intermediateExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+468,6,"ExpChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+469,6,"ExpChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+470,6,"intermediateSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+471,6,"signChoice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+420,5,"choice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+879,0,"bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+864,0,"shiftStages",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 9; ++i) {
        tracep->declBit(c+653+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+394,5,"capture_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+388,5,"A_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+389,5,"B_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+395,5,"lowest_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+396,5,"second_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,5,"third_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+398,5,"final_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+390,5,"lowest_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+391,5,"second_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+392,5,"third_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+393,5,"final_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("pipe_sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBit(c+642+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1));
    }
    tracep->popPrefix();
    tracep->pushPrefix("pipe_Exponent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+647+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("karatsuba", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+759,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+838,10,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+839,10,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declQuad(c+840,10,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+883,0,"HALF_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+884,0,"MID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+379,4,"A_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+380,4,"A_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+381,4,"B_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+382,4,"B_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+461,6,"P_low_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+462,6,"P_high_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+443,5,"P_middle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+383,5,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+384,5,"temp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+463,6,"P_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+464,6,"P_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+444,5,"temp3_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+465,6,"P_low2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+445,5,"temp3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declQuad(c+446,5,"P_high_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+448,5,"P_high_shifted1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+450,5,"P_high_shifted2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+452,5,"temp3_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+842,10,"partial_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+454,5,"P_low_extended",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+456,6,"P_low_extended1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+458,6,"P_low_extended2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->pushPrefix("booth_mult1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+883,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+759,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+380,4,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+382,4,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+461,6,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+248+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+200+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+255+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+207+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+210+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+162,1,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+163,1,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+213,2,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+466,6,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+844,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+883,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+759,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+379,4,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+381,4,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+462,6,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+262+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+214+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+269+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+221+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+224+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+164,1,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+165,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+227,2,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+467,6,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+845,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+884,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+759,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+383,5,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+384,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+443,5,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+276+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+228+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+283+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+235+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+196+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+166,2,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+167,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+199,2,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+460,6,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+846,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+848,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+849,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+788,10,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+732,9,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+790,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+700,8,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+850,10,"A_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+851,10,"B_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+372,4,"A_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+852,10,"B_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+159,1,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,1,"sign_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,1,"sign_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+373,4,"Temp_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+692,8,"Temp_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+581,7,"intermediateMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+687,8,"ManChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+688,8,"ManChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+582,7,"intermediateExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+853,10,"ExpChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+854,11,"ExpChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+689,8,"intermediateSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+690,8,"signChoice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+691,8,"choice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+879,0,"bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+864,0,"shiftStages",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 9; ++i) {
        tracep->declBit(c+701+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+710,9,"capture_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+374,4,"A_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+855,11,"B_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+587,7,"lowest_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+588,7,"second_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+589,7,"third_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+590,7,"final_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+375,4,"lowest_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+376,4,"second_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+377,4,"third_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+378,4,"final_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("pipe_sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBit(c+743+i*1,9,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1));
    }
    tracep->popPrefix();
    tracep->pushPrefix("pipe_Exponent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+748+i*1,9,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("karatsuba", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+850,10,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+851,10,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declQuad(c+692,8,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+883,0,"HALF_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+884,0,"MID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+408,5,"A_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+409,5,"A_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+412,5,"B_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+413,5,"B_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+722,9,"P_low_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+711,9,"P_high_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+712,9,"P_middle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+410,5,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+414,5,"temp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+713,9,"P_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+723,9,"P_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+694,8,"temp3_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+724,9,"P_low2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+695,8,"temp3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declQuad(c+714,9,"P_high_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+716,9,"P_high_shifted1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+718,9,"P_high_shifted2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+696,8,"temp3_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+698,8,"partial_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+725,9,"P_low_extended",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+727,9,"P_low_extended1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+729,9,"P_low_extended2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->pushPrefix("booth_mult1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+883,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+409,5,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+413,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+722,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+290+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+238+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+297+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+245+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+191+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+183,2,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+184,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+856,11,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+731,9,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+857,11,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+883,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+408,5,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+412,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+711,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+304+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+487+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+311+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+494+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+153+i*1,1,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+185,2,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+186,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+858,11,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+720,9,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+859,11,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+884,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+760,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+410,5,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+414,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+712,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+507+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+497+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+514+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+504+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+156+i*1,1,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+411,5,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+415,5,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+860,11,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+721,9,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+861,11,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+194,2,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+195,2,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+862,11,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_init_top(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_init_top\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTB_gpnae___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_1(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_1(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_2(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_2(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_3(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_3(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_4(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_4(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_5(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_5(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_6(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_6(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_7(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_7(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_8(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_8(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_9(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_9(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_10(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_10(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTB_gpnae___024root__trace_full_11(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_chg_11(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTB_gpnae___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTB_gpnae___024root__trace_register(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_register\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VTB_gpnae___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_0, 0U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_1, 1U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_1, 1U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_2, 2U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_2, 2U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_3, 3U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_3, 3U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_4, 4U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_4, 4U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_5, 5U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_5, 5U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_6, 6U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_6, 6U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_7, 7U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_7, 7U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_8, 8U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_8, 8U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_9, 9U, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_9, 9U, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_10, 0xaU, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_10, 0xaU, vlSelf);
    tracep->addFullCb(&VTB_gpnae___024root__trace_full_11, 0xbU, vlSelf);
    tracep->addChgCb(&VTB_gpnae___024root__trace_chg_11, 0xbU, vlSelf);
    tracep->addCleanupCb(&VTB_gpnae___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_const_0_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_const_0\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_const_0_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_const_0_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    bufp->fullIData(oldp+863,(0x20U),32);
    bufp->fullIData(oldp+864,(5U),32);
    bufp->fullIData(oldp+865,(2U),32);
    bufp->fullIData(oldp+866,(0x20U),32);
    bufp->fullIData(oldp+867,(5U),32);
    bufp->fullIData(oldp+868,(2U),32);
    bufp->fullIData(oldp+869,(0x3f867d5fU),32);
    bufp->fullIData(oldp+870,(0x3fd62d7dU),32);
    __Vtemp_1[0U] = 0x2e6d656dU;
    __Vtemp_1[1U] = 0x65666673U;
    __Vtemp_1[2U] = 0x725f636fU;
    __Vtemp_1[3U] = 0x61796c6fU;
    __Vtemp_1[4U] = 0x74U;
    bufp->fullWData(oldp+871,(__Vtemp_1),136);
    bufp->fullIData(oldp+876,(0xbf800000U),32);
    bufp->fullIData(oldp+877,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__mux_output_reg),32);
    bufp->fullIData(oldp+878,(0x3f800000U),32);
    bufp->fullCData(oldp+879,(0x7fU),7);
    bufp->fullIData(oldp+880,(0x18U),32);
    bufp->fullIData(oldp+881,(0x17U),32);
    bufp->fullIData(oldp+882,(0x2fU),32);
    bufp->fullIData(oldp+883,(0xcU),32);
    bufp->fullIData(oldp+884,(0xdU),32);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_0_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_0\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_0_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_0_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[1]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[2]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[3]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[4]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[5]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[6]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[7]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[8]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[9]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[10]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[11]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[12]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[13]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[14]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[15]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[16]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[17]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[18]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[19]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[20]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[21]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[22]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[23]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[24]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[25]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[26]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[27]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[28]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.TB_gpnae__DOT__signal_sigmoid[29]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.TB_gpnae__DOT__signal_tanh[0]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.TB_gpnae__DOT__signal_tanh[1]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.TB_gpnae__DOT__signal_tanh[2]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.TB_gpnae__DOT__signal_tanh[3]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.TB_gpnae__DOT__signal_tanh[4]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.TB_gpnae__DOT__signal_tanh[5]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.TB_gpnae__DOT__signal_tanh[6]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.TB_gpnae__DOT__signal_tanh[7]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.TB_gpnae__DOT__signal_tanh[8]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.TB_gpnae__DOT__signal_tanh[9]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.TB_gpnae__DOT__signal_tanh[10]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.TB_gpnae__DOT__signal_tanh[11]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.TB_gpnae__DOT__signal_tanh[12]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.TB_gpnae__DOT__signal_tanh[13]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.TB_gpnae__DOT__signal_tanh[14]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.TB_gpnae__DOT__signal_tanh[15]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.TB_gpnae__DOT__signal_tanh[16]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.TB_gpnae__DOT__signal_tanh[17]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.TB_gpnae__DOT__signal_tanh[18]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.TB_gpnae__DOT__signal_tanh[19]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.TB_gpnae__DOT__signal_tanh[20]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.TB_gpnae__DOT__signal_tanh[21]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.TB_gpnae__DOT__signal_tanh[22]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.TB_gpnae__DOT__signal_tanh[23]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.TB_gpnae__DOT__signal_tanh[24]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.TB_gpnae__DOT__signal_tanh[25]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.TB_gpnae__DOT__signal_tanh[26]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.TB_gpnae__DOT__signal_tanh[27]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.TB_gpnae__DOT__signal_tanh[28]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.TB_gpnae__DOT__signal_tanh[29]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[0]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[1]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[2]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[3]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[4]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[5]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[6]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[7]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[8]),32);
    bufp->fullIData(oldp+70,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[9]),32);
    bufp->fullIData(oldp+71,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[10]),32);
    bufp->fullIData(oldp+72,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[11]),32);
    bufp->fullIData(oldp+73,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[12]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[13]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[14]),32);
    bufp->fullIData(oldp+76,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[15]),32);
    bufp->fullIData(oldp+77,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[16]),32);
    bufp->fullIData(oldp+78,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[17]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[18]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[19]),32);
    bufp->fullIData(oldp+81,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[20]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[21]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[22]),32);
    bufp->fullIData(oldp+84,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[23]),32);
    bufp->fullIData(oldp+85,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[24]),32);
    bufp->fullIData(oldp+86,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[25]),32);
    bufp->fullIData(oldp+87,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[26]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[27]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[28]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[29]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[30]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_rom_inst__DOT__ROM__DOT__ROM[31]),32);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_1_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_1(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_1\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_1_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_1_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_1_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+93,(vlSelfRef.TB_gpnae__DOT__rstn_i));
    bufp->fullIData(oldp+94,(vlSelfRef.TB_gpnae__DOT__signal_i),32);
    bufp->fullBit(oldp+95,(vlSelfRef.TB_gpnae__DOT__wr_en_i));
    bufp->fullBit(oldp+96,(vlSelfRef.TB_gpnae__DOT__last_i));
    bufp->fullBit(oldp+97,(vlSelfRef.TB_gpnae__DOT__start_i));
    bufp->fullCData(oldp+98,(vlSelfRef.TB_gpnae__DOT__terms_i),5);
    bufp->fullCData(oldp+99,(vlSelfRef.TB_gpnae__DOT__control_word_i),2);
    bufp->fullIData(oldp+100,(vlSelfRef.TB_gpnae__DOT__processed_signals),32);
    bufp->fullCData(oldp+101,(vlSelfRef.TB_gpnae__DOT__num_sig),5);
    bufp->fullIData(oldp+102,(vlSelfRef.TB_gpnae__DOT__buffer_write_start_cycle),32);
    bufp->fullIData(oldp+103,(vlSelfRef.TB_gpnae__DOT__buffer_write_end_cycle),32);
    bufp->fullIData(oldp+104,(vlSelfRef.TB_gpnae__DOT__processing_start_cycle),32);
    bufp->fullIData(oldp+105,(vlSelfRef.TB_gpnae__DOT__processing_end_cycle),32);
    bufp->fullIData(oldp+106,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[0]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[1]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[2]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[3]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[4]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[5]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[6]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[7]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[8]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[9]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[10]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[11]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[12]),32);
    bufp->fullIData(oldp+119,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[13]),32);
    bufp->fullIData(oldp+120,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[14]),32);
    bufp->fullIData(oldp+121,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[15]),32);
    bufp->fullIData(oldp+122,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[16]),32);
    bufp->fullIData(oldp+123,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[17]),32);
    bufp->fullIData(oldp+124,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[18]),32);
    bufp->fullIData(oldp+125,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[19]),32);
    bufp->fullIData(oldp+126,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[20]),32);
    bufp->fullIData(oldp+127,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[21]),32);
    bufp->fullIData(oldp+128,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[22]),32);
    bufp->fullIData(oldp+129,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[23]),32);
    bufp->fullIData(oldp+130,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[24]),32);
    bufp->fullIData(oldp+131,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[25]),32);
    bufp->fullIData(oldp+132,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[26]),32);
    bufp->fullIData(oldp+133,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[27]),32);
    bufp->fullIData(oldp+134,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[28]),32);
    bufp->fullIData(oldp+135,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[29]),32);
    bufp->fullIData(oldp+136,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[30]),32);
    bufp->fullIData(oldp+137,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[31]),32);
    bufp->fullIData(oldp+138,(vlSelfRef.TB_gpnae__DOT__total_buffer_write_cycles),32);
    bufp->fullIData(oldp+139,(vlSelfRef.TB_gpnae__DOT__total_processing_cycles),32);
    bufp->fullIData(oldp+140,(vlSelfRef.TB_gpnae__DOT__total_operation_cycles),32);
    bufp->fullIData(oldp+141,(vlSelfRef.TB_gpnae__DOT__total_input_cycles),32);
    bufp->fullIData(oldp+142,(vlSelfRef.TB_gpnae__DOT__avg_cycles_per_input),32);
    bufp->fullCData(oldp+143,((0x1fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.TB_gpnae__DOT__terms_i)))),5);
    bufp->fullBit(oldp+144,((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)))));
    bufp->fullIData(oldp+145,(vlSelfRef.TB_gpnae__DOT__perform_test__Vstatic__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+146,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__processed),32);
    bufp->fullIData(oldp+147,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__last_done_cycle),32);
    bufp->fullIData(oldp+148,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__current_done_cycle),32);
    bufp->fullIData(oldp+149,(vlSelfRef.TB_gpnae__DOT__write_signal__Vstatic__unnamedblk2__DOT__start_cycle),32);
    bufp->fullBit(oldp+150,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign));
    bufp->fullBit(oldp+151,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign_A));
    bufp->fullBit(oldp+152,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign_B));
    bufp->fullIData(oldp+153,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0]),24);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1]),24);
    bufp->fullIData(oldp+155,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2]),24);
    bufp->fullIData(oldp+156,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0]),26);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1]),26);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2]),26);
    bufp->fullBit(oldp+159,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign));
    bufp->fullBit(oldp+160,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign_A));
    bufp->fullBit(oldp+161,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign_B));
    bufp->fullSData(oldp+162,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+163,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+164,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold),12);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_2_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_2(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_2\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_2_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_2_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_2_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+165,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+166,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold),13);
    bufp->fullSData(oldp+167,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold),13);
    bufp->fullCData(oldp+168,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent1),8);
    bufp->fullCData(oldp+169,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2),8);
    bufp->fullIData(oldp+170,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa1),23);
    bufp->fullIData(oldp+171,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2),23);
    bufp->fullBit(oldp+172,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__carry1));
    bufp->fullBit(oldp+173,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__carry2));
    bufp->fullIData(oldp+174,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1),24);
    bufp->fullIData(oldp+175,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2),24);
    bufp->fullCData(oldp+176,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1)),8);
    bufp->fullCData(oldp+177,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                                        >> 8U))),8);
    bufp->fullCData(oldp+178,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+179,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2)),8);
    bufp->fullCData(oldp+180,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                                        >> 8U))),8);
    bufp->fullCData(oldp+181,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                                        >> 0x10U))),8);
    bufp->fullBit(oldp+182,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Sign));
    bufp->fullSData(oldp+183,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+184,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+185,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+186,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold),12);
    bufp->fullBit(oldp+187,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign));
    bufp->fullBit(oldp+188,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed));
    bufp->fullBit(oldp+189,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed_delayed));
    bufp->fullBit(oldp+190,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed_delayed_delayed));
    bufp->fullIData(oldp+191,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0]),24);
    bufp->fullIData(oldp+192,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1]),24);
    bufp->fullIData(oldp+193,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2]),24);
    bufp->fullIData(oldp+194,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+195,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+196,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0]),26);
    bufp->fullIData(oldp+197,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1]),26);
    bufp->fullIData(oldp+198,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2]),26);
    bufp->fullIData(oldp+199,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last),26);
    bufp->fullIData(oldp+200,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+201,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+202,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+203,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+204,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+205,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+206,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+207,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0]),24);
    bufp->fullIData(oldp+208,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1]),24);
    bufp->fullIData(oldp+209,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2]),24);
    bufp->fullIData(oldp+210,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0]),24);
    bufp->fullIData(oldp+211,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1]),24);
    bufp->fullIData(oldp+212,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2]),24);
    bufp->fullIData(oldp+213,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last),24);
    bufp->fullIData(oldp+214,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+215,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+216,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+217,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+218,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+219,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+220,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+221,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0]),24);
    bufp->fullIData(oldp+222,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1]),24);
    bufp->fullIData(oldp+223,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2]),24);
    bufp->fullIData(oldp+224,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0]),24);
    bufp->fullIData(oldp+225,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1]),24);
    bufp->fullIData(oldp+226,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2]),24);
    bufp->fullIData(oldp+227,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last),24);
    bufp->fullIData(oldp+228,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0]),26);
    bufp->fullIData(oldp+229,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1]),26);
    bufp->fullIData(oldp+230,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2]),26);
    bufp->fullIData(oldp+231,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3]),26);
    bufp->fullIData(oldp+232,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4]),26);
    bufp->fullIData(oldp+233,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5]),26);
    bufp->fullIData(oldp+234,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6]),26);
    bufp->fullIData(oldp+235,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0]),26);
    bufp->fullIData(oldp+236,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1]),26);
    bufp->fullIData(oldp+237,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2]),26);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_3_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_3(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_3\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_3_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_3_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_3_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+238,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+239,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+240,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+241,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+242,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+243,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+244,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0]),24);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1]),24);
    bufp->fullIData(oldp+247,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2]),24);
    bufp->fullIData(oldp+248,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+249,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+250,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+251,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+252,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+253,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+254,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6]),24);
    bufp->fullCData(oldp+255,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+256,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+257,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+258,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+259,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+260,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+261,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+262,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+263,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+264,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+265,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+266,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+267,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+268,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6]),24);
    bufp->fullCData(oldp+269,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+270,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+271,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+272,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+273,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+274,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+275,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+276,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0]),26);
    bufp->fullIData(oldp+277,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1]),26);
    bufp->fullIData(oldp+278,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2]),26);
    bufp->fullIData(oldp+279,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3]),26);
    bufp->fullIData(oldp+280,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4]),26);
    bufp->fullIData(oldp+281,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5]),26);
    bufp->fullIData(oldp+282,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6]),26);
    bufp->fullCData(oldp+283,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+284,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+285,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+286,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+287,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+288,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+289,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+290,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+291,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+292,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+293,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+294,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+295,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+296,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6]),24);
    bufp->fullCData(oldp+297,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+298,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+299,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+300,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+301,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+302,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+303,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+304,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+305,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+306,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+307,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+308,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+309,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+310,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6]),24);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_4_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_4(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_4\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_4_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_4_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_4_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+311,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+312,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+313,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+314,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+315,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+316,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+317,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+318,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateSign) 
                                << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateExp) 
                                              << 0x17U) 
                                             | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateMan))),32);
    bufp->fullIData(oldp+319,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateMan),23);
    bufp->fullCData(oldp+320,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateExp),8);
    bufp->fullBit(oldp+321,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateSign));
    bufp->fullBit(oldp+322,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__dbz));
    bufp->fullIData(oldp+323,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__b1),24);
    bufp->fullCData(oldp+324,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[0]),8);
    bufp->fullCData(oldp+325,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[1]),8);
    bufp->fullCData(oldp+326,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[2]),8);
    bufp->fullCData(oldp+327,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[3]),8);
    bufp->fullCData(oldp+328,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[4]),8);
    bufp->fullCData(oldp+329,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[5]),8);
    bufp->fullCData(oldp+330,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[6]),8);
    bufp->fullCData(oldp+331,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[7]),8);
    bufp->fullCData(oldp+332,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[8]),8);
    bufp->fullCData(oldp+333,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[9]),8);
    bufp->fullCData(oldp+334,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[10]),8);
    bufp->fullCData(oldp+335,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[11]),8);
    bufp->fullCData(oldp+336,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[12]),8);
    bufp->fullCData(oldp+337,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[13]),8);
    bufp->fullCData(oldp+338,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[14]),8);
    bufp->fullCData(oldp+339,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[15]),8);
    bufp->fullCData(oldp+340,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[16]),8);
    bufp->fullCData(oldp+341,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[17]),8);
    bufp->fullCData(oldp+342,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[18]),8);
    bufp->fullCData(oldp+343,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[19]),8);
    bufp->fullCData(oldp+344,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[20]),8);
    bufp->fullCData(oldp+345,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[21]),8);
    bufp->fullCData(oldp+346,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[22]),8);
    bufp->fullCData(oldp+347,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[23]),8);
    bufp->fullBit(oldp+348,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[0]));
    bufp->fullBit(oldp+349,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[1]));
    bufp->fullBit(oldp+350,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[2]));
    bufp->fullBit(oldp+351,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[3]));
    bufp->fullBit(oldp+352,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[4]));
    bufp->fullBit(oldp+353,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[5]));
    bufp->fullBit(oldp+354,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[6]));
    bufp->fullBit(oldp+355,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[7]));
    bufp->fullBit(oldp+356,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[8]));
    bufp->fullBit(oldp+357,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[9]));
    bufp->fullBit(oldp+358,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[10]));
    bufp->fullBit(oldp+359,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[11]));
    bufp->fullBit(oldp+360,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[12]));
    bufp->fullBit(oldp+361,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[13]));
    bufp->fullBit(oldp+362,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[14]));
    bufp->fullBit(oldp+363,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[15]));
    bufp->fullBit(oldp+364,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[16]));
    bufp->fullBit(oldp+365,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[17]));
    bufp->fullBit(oldp+366,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[18]));
    bufp->fullBit(oldp+367,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[19]));
    bufp->fullBit(oldp+368,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[20]));
    bufp->fullBit(oldp+369,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[21]));
    bufp->fullBit(oldp+370,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[22]));
    bufp->fullBit(oldp+371,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[23]));
    bufp->fullCData(oldp+372,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Exponent),8);
    bufp->fullCData(oldp+373,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__Temp_Exponent),8);
    bufp->fullCData(oldp+374,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Exponent_reg),8);
    bufp->fullCData(oldp+375,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__lowest_sum),3);
    bufp->fullCData(oldp+376,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__second_sum),3);
    bufp->fullCData(oldp+377,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__third_sum),3);
    bufp->fullCData(oldp+378,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__final_sum),5);
    bufp->fullSData(oldp+379,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__A_high),12);
    bufp->fullSData(oldp+380,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__A_low),12);
    bufp->fullSData(oldp+381,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__B_high),12);
    bufp->fullSData(oldp+382,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__B_low),12);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_5_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_5(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_5\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_5_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_5_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_5_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+383,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp1),13);
    bufp->fullSData(oldp+384,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp2),13);
    bufp->fullCData(oldp+385,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Exponent),8);
    bufp->fullCData(oldp+386,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Exponent),8);
    bufp->fullCData(oldp+387,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__Temp_Exponent),8);
    bufp->fullCData(oldp+388,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Exponent_reg),8);
    bufp->fullCData(oldp+389,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Exponent_reg),8);
    bufp->fullCData(oldp+390,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__lowest_sum),3);
    bufp->fullCData(oldp+391,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__second_sum),3);
    bufp->fullCData(oldp+392,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__third_sum),3);
    bufp->fullCData(oldp+393,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__final_sum),5);
    bufp->fullBit(oldp+394,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__capture_valid));
    bufp->fullBit(oldp+395,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__lowest_valid));
    bufp->fullBit(oldp+396,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__second_valid));
    bufp->fullBit(oldp+397,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__third_valid));
    bufp->fullBit(oldp+398,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__final_valid));
    bufp->fullBit(oldp+399,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__check1));
    bufp->fullBit(oldp+400,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__check2));
    bufp->fullIData(oldp+401,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigMan1),24);
    bufp->fullIData(oldp+402,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigMan2),24);
    bufp->fullBit(oldp+403,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_sign));
    bufp->fullBit(oldp+404,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C1_sign));
    bufp->fullBit(oldp+405,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_sign));
    bufp->fullBit(oldp+406,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__sign1));
    bufp->fullBit(oldp+407,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__sign2));
    bufp->fullSData(oldp+408,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__A_high),12);
    bufp->fullSData(oldp+409,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__A_low),12);
    bufp->fullSData(oldp+410,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp1),13);
    bufp->fullSData(oldp+411,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold),13);
    bufp->fullSData(oldp+412,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__B_high),12);
    bufp->fullSData(oldp+413,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__B_low),12);
    bufp->fullSData(oldp+414,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp2),13);
    bufp->fullSData(oldp+415,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold),13);
    bufp->fullIData(oldp+416,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan),23);
    bufp->fullIData(oldp+417,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ManChoice1),23);
    bufp->fullIData(oldp+418,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ManChoice2),23);
    bufp->fullCData(oldp+419,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp),8);
    bufp->fullBit(oldp+420,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__choice));
    bufp->fullBit(oldp+421,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__carry));
    bufp->fullCData(oldp+422,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__DifferenceExp),8);
    bufp->fullIData(oldp+423,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Temp_SmallMan),24);
    bufp->fullIData(oldp+424,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan),24);
    bufp->fullCData(oldp+425,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan)),8);
    bufp->fullCData(oldp+426,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                                        >> 8U))),8);
    bufp->fullCData(oldp+427,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+428,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigExp1),8);
    bufp->fullCData(oldp+429,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigExp2),8);
    bufp->fullCData(oldp+430,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallExp1),8);
    bufp->fullCData(oldp+431,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallExp2),8);
    bufp->fullCData(oldp+432,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__DifferenceExp1),8);
    bufp->fullCData(oldp+433,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__DifferenceExp2),8);
    bufp->fullIData(oldp+434,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallMan1),24);
    bufp->fullIData(oldp+435,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallMan2),24);
    bufp->fullIData(oldp+436,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Temp_SmallMan1),24);
    bufp->fullIData(oldp+437,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Temp_SmallMan2),24);
    bufp->fullIData(oldp+438,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan),24);
    bufp->fullIData(oldp+439,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan_delayed),24);
    bufp->fullIData(oldp+440,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan_delayed_delayed),24);
    bufp->fullIData(oldp+441,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallMan),24);
    bufp->fullIData(oldp+442,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallMan_delayed),24);
    bufp->fullIData(oldp+443,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_middle),26);
    bufp->fullIData(oldp+444,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3_stage1),26);
    bufp->fullIData(oldp+445,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3),25);
    bufp->fullQData(oldp+446,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted),48);
    bufp->fullQData(oldp+448,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted1),48);
    bufp->fullQData(oldp+450,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted2),48);
    bufp->fullQData(oldp+452,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3_shifted),48);
    bufp->fullQData(oldp+454,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended),48);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_6_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_6(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_6\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_6_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_6_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_6_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullQData(oldp+456,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended1),48);
    bufp->fullQData(oldp+458,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended2),48);
    bufp->fullIData(oldp+460,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__accum),26);
    bufp->fullIData(oldp+461,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_raw),24);
    bufp->fullIData(oldp+462,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_raw),24);
    bufp->fullIData(oldp+463,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high),24);
    bufp->fullIData(oldp+464,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low),24);
    bufp->fullIData(oldp+465,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low2),26);
    bufp->fullIData(oldp+466,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__accum),24);
    bufp->fullIData(oldp+467,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__accum),24);
    bufp->fullCData(oldp+468,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ExpChoice1),8);
    bufp->fullCData(oldp+469,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ExpChoice2),8);
    bufp->fullBit(oldp+470,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign));
    bufp->fullBit(oldp+471,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__signChoice));
    bufp->fullCData(oldp+472,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed),8);
    bufp->fullCData(oldp+473,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed_delayed),8);
    bufp->fullCData(oldp+474,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed_delayed_delayed),8);
    bufp->fullBit(oldp+475,(vlSelfRef.TB_gpnae__DOT__done_o));
    bufp->fullBit(oldp+476,(vlSelfRef.TB_gpnae__DOT__dut__DOT__update_result));
    bufp->fullBit(oldp+477,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__selu_enable));
    bufp->fullBit(oldp+478,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__mac_enable));
    bufp->fullBit(oldp+479,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__sigtan_enable));
    bufp->fullBit(oldp+480,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__carry));
    bufp->fullCData(oldp+481,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__DifferenceExp),8);
    bufp->fullIData(oldp+482,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Temp_SmallMan),24);
    bufp->fullIData(oldp+483,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan),24);
    bufp->fullCData(oldp+484,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan)),8);
    bufp->fullCData(oldp+485,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                                        >> 8U))),8);
    bufp->fullCData(oldp+486,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                                        >> 0x10U))),8);
    bufp->fullIData(oldp+487,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+488,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+489,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+490,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+491,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+492,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+493,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+494,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0]),24);
    bufp->fullIData(oldp+495,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1]),24);
    bufp->fullIData(oldp+496,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2]),24);
    bufp->fullIData(oldp+497,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0]),26);
    bufp->fullIData(oldp+498,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1]),26);
    bufp->fullIData(oldp+499,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2]),26);
    bufp->fullIData(oldp+500,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3]),26);
    bufp->fullIData(oldp+501,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4]),26);
    bufp->fullIData(oldp+502,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5]),26);
    bufp->fullIData(oldp+503,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6]),26);
    bufp->fullIData(oldp+504,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0]),26);
    bufp->fullIData(oldp+505,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1]),26);
    bufp->fullIData(oldp+506,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2]),26);
    bufp->fullIData(oldp+507,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0]),26);
    bufp->fullIData(oldp+508,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1]),26);
    bufp->fullIData(oldp+509,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2]),26);
    bufp->fullIData(oldp+510,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3]),26);
    bufp->fullIData(oldp+511,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4]),26);
    bufp->fullIData(oldp+512,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5]),26);
    bufp->fullIData(oldp+513,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6]),26);
    bufp->fullCData(oldp+514,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+515,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+516,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+517,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+518,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+519,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+520,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6]),3);
    bufp->fullCData(oldp+521,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount1),5);
    bufp->fullCData(oldp+522,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount2),5);
    bufp->fullCData(oldp+523,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt1),4);
    bufp->fullCData(oldp+524,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt2),4);
    bufp->fullCData(oldp+525,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt3),4);
    bufp->fullCData(oldp+526,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt1),4);
    bufp->fullCData(oldp+527,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt2),4);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_7_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_7(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_7\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_7_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_7_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_7_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+528,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt3),4);
    bufp->fullBit(oldp+529,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__check));
    bufp->fullCData(oldp+530,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__BigExp),8);
    bufp->fullIData(oldp+531,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__BigMan),24);
    bufp->fullIData(oldp+532,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__SmallMan),24);
    bufp->fullBit(oldp+533,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_sign));
    bufp->fullBit(oldp+534,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_sign));
    bufp->fullBit(oldp+535,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__div_done));
    bufp->fullIData(oldp+536,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__Temp_Mantissa),24);
    bufp->fullBit(oldp+537,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__valid));
    bufp->fullBit(oldp+538,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__ovf));
    bufp->fullIData(oldp+539,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo),24);
    bufp->fullIData(oldp+540,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc),25);
    bufp->fullBit(oldp+541,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check));
    bufp->fullBit(oldp+542,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check_delayed));
    bufp->fullBit(oldp+543,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check_delayed_delayed));
    bufp->fullBit(oldp+544,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_sign));
    bufp->fullIData(oldp+545,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Mantissa),24);
    bufp->fullIData(oldp+546,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Mantissa),24);
    bufp->fullBit(oldp+547,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__busy));
    bufp->fullIData(oldp+548,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo_next),24);
    bufp->fullIData(oldp+549,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next),25);
    bufp->fullCData(oldp+550,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__i),6);
    bufp->fullBit(oldp+551,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[0]));
    bufp->fullBit(oldp+552,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[1]));
    bufp->fullBit(oldp+553,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[2]));
    bufp->fullBit(oldp+554,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[3]));
    bufp->fullBit(oldp+555,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[4]));
    bufp->fullBit(oldp+556,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[5]));
    bufp->fullBit(oldp+557,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[6]));
    bufp->fullBit(oldp+558,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[7]));
    bufp->fullBit(oldp+559,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[8]));
    bufp->fullBit(oldp+560,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[9]));
    bufp->fullBit(oldp+561,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[10]));
    bufp->fullBit(oldp+562,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[11]));
    bufp->fullBit(oldp+563,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[12]));
    bufp->fullBit(oldp+564,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[13]));
    bufp->fullBit(oldp+565,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[14]));
    bufp->fullBit(oldp+566,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[15]));
    bufp->fullBit(oldp+567,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[16]));
    bufp->fullBit(oldp+568,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[17]));
    bufp->fullBit(oldp+569,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[18]));
    bufp->fullBit(oldp+570,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[19]));
    bufp->fullBit(oldp+571,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[20]));
    bufp->fullBit(oldp+572,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[21]));
    bufp->fullBit(oldp+573,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[22]));
    bufp->fullBit(oldp+574,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[23]));
    bufp->fullBit(oldp+575,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[24]));
    bufp->fullBit(oldp+576,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[25]));
    bufp->fullBit(oldp+577,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage
                            [0U]));
    bufp->fullIData(oldp+578,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in2),32);
    bufp->fullCData(oldp+579,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp),8);
    bufp->fullIData(oldp+580,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Man),23);
    bufp->fullIData(oldp+581,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan),23);
    bufp->fullCData(oldp+582,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp),8);
    bufp->fullBit(oldp+583,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage6));
    bufp->fullBit(oldp+584,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage3));
    bufp->fullBit(oldp+585,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage4));
    bufp->fullBit(oldp+586,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage5));
    bufp->fullBit(oldp+587,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__lowest_valid));
    bufp->fullBit(oldp+588,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__second_valid));
    bufp->fullBit(oldp+589,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__third_valid));
    bufp->fullBit(oldp+590,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__final_valid));
    bufp->fullBit(oldp+591,((vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                             >> 0x1fU)));
    bufp->fullBit(oldp+592,((0U == vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)));
    bufp->fullBit(oldp+593,(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal));
    bufp->fullBit(oldp+594,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid));
    bufp->fullIData(oldp+595,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status),32);
    bufp->fullBit(oldp+596,((1U & (~ (vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                      >> 0x1fU)))));
    bufp->fullIData(oldp+597,((~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)),32);
    bufp->fullCData(oldp+598,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__current_state),3);
    bufp->fullIData(oldp+599,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[0]),32);
    bufp->fullIData(oldp+600,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[1]),32);
    bufp->fullIData(oldp+601,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[2]),32);
    bufp->fullIData(oldp+602,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[3]),32);
    bufp->fullIData(oldp+603,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[4]),32);
    bufp->fullIData(oldp+604,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[5]),32);
    bufp->fullIData(oldp+605,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[6]),32);
    bufp->fullIData(oldp+606,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[7]),32);
    bufp->fullIData(oldp+607,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[8]),32);
    bufp->fullIData(oldp+608,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[9]),32);
    bufp->fullIData(oldp+609,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[10]),32);
    bufp->fullIData(oldp+610,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[11]),32);
    bufp->fullIData(oldp+611,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[12]),32);
    bufp->fullIData(oldp+612,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[13]),32);
    bufp->fullIData(oldp+613,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[14]),32);
    bufp->fullIData(oldp+614,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[15]),32);
    bufp->fullIData(oldp+615,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[16]),32);
    bufp->fullIData(oldp+616,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[17]),32);
    bufp->fullIData(oldp+617,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[18]),32);
    bufp->fullIData(oldp+618,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[19]),32);
    bufp->fullIData(oldp+619,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[20]),32);
    bufp->fullIData(oldp+620,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[21]),32);
    bufp->fullIData(oldp+621,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[22]),32);
    bufp->fullIData(oldp+622,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[23]),32);
    bufp->fullIData(oldp+623,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[24]),32);
    bufp->fullIData(oldp+624,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[25]),32);
    bufp->fullIData(oldp+625,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[26]),32);
    bufp->fullIData(oldp+626,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[27]),32);
    bufp->fullIData(oldp+627,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[28]),32);
    bufp->fullIData(oldp+628,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[29]),32);
    bufp->fullIData(oldp+629,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[30]),32);
    bufp->fullIData(oldp+630,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[31]),32);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_8_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_8(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_8\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_8_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_8_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_8_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+631,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zerocount),5);
    bufp->fullCData(oldp+632,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt1),4);
    bufp->fullCData(oldp+633,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt2),4);
    bufp->fullCData(oldp+634,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt3),4);
    bufp->fullBit(oldp+635,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage1));
    bufp->fullBit(oldp+636,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage2));
    bufp->fullBit(oldp+637,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage3));
    bufp->fullBit(oldp+638,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__load_result));
    bufp->fullBit(oldp+639,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o));
    bufp->fullCData(oldp+640,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state),4);
    bufp->fullBit(oldp+641,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_comb));
    bufp->fullBit(oldp+642,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[0]));
    bufp->fullBit(oldp+643,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[1]));
    bufp->fullBit(oldp+644,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[2]));
    bufp->fullBit(oldp+645,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[3]));
    bufp->fullBit(oldp+646,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[4]));
    bufp->fullCData(oldp+647,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[0]),8);
    bufp->fullCData(oldp+648,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[1]),8);
    bufp->fullCData(oldp+649,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[2]),8);
    bufp->fullCData(oldp+650,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[3]),8);
    bufp->fullCData(oldp+651,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[4]),8);
    bufp->fullBit(oldp+652,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage
                            [8U]));
    bufp->fullBit(oldp+653,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[0]));
    bufp->fullBit(oldp+654,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[1]));
    bufp->fullBit(oldp+655,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[2]));
    bufp->fullBit(oldp+656,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[3]));
    bufp->fullBit(oldp+657,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[4]));
    bufp->fullBit(oldp+658,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[5]));
    bufp->fullBit(oldp+659,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[6]));
    bufp->fullBit(oldp+660,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[7]));
    bufp->fullBit(oldp+661,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[8]));
    bufp->fullCData(oldp+662,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Exp),8);
    bufp->fullCData(oldp+663,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Exp),8);
    bufp->fullIData(oldp+664,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Man),23);
    bufp->fullIData(oldp+665,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Man),23);
    bufp->fullBit(oldp+666,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage1));
    bufp->fullBit(oldp+667,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage2));
    bufp->fullBit(oldp+668,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage3));
    bufp->fullBit(oldp+669,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage4));
    bufp->fullBit(oldp+670,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage5));
    bufp->fullIData(oldp+671,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_data),32);
    bufp->fullIData(oldp+672,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in1),32);
    bufp->fullBit(oldp+673,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_sign));
    bufp->fullCData(oldp+674,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Exp),8);
    bufp->fullIData(oldp+675,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Man),23);
    bufp->fullIData(oldp+676,(((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu)
                                ? 0x3f867d5fU : 0x3fd62d7dU)),32);
    bufp->fullBit(oldp+677,(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu));
    bufp->fullCData(oldp+678,(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan),2);
    bufp->fullCData(oldp+679,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__done_delay),3);
    bufp->fullCData(oldp+680,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Exp),8);
    bufp->fullCData(oldp+681,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Exp),8);
    bufp->fullIData(oldp+682,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Man),23);
    bufp->fullIData(oldp+683,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Man),23);
    bufp->fullBit(oldp+684,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__comp));
    bufp->fullBit(oldp+685,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__magcheck));
    bufp->fullBit(oldp+686,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zero));
    bufp->fullIData(oldp+687,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ManChoice1),23);
    bufp->fullIData(oldp+688,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ManChoice2),23);
    bufp->fullBit(oldp+689,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign));
    bufp->fullBit(oldp+690,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__signChoice));
    bufp->fullBit(oldp+691,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__choice));
    bufp->fullQData(oldp+692,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__Temp_Mantissa),48);
    bufp->fullIData(oldp+694,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3_stage1),26);
    bufp->fullIData(oldp+695,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3),25);
    bufp->fullQData(oldp+696,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3_shifted),48);
    bufp->fullQData(oldp+698,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__partial_product),48);
    bufp->fullBit(oldp+700,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage
                            [8U]));
    bufp->fullBit(oldp+701,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[0]));
    bufp->fullBit(oldp+702,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[1]));
    bufp->fullBit(oldp+703,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[2]));
    bufp->fullBit(oldp+704,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[3]));
    bufp->fullBit(oldp+705,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[4]));
    bufp->fullBit(oldp+706,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[5]));
    bufp->fullBit(oldp+707,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[6]));
    bufp->fullBit(oldp+708,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[7]));
    bufp->fullBit(oldp+709,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[8]));
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_9_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_9(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_9\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_9_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_9_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_9_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+710,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__capture_valid));
    bufp->fullIData(oldp+711,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_raw),24);
    bufp->fullIData(oldp+712,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_middle),26);
    bufp->fullIData(oldp+713,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high),24);
    bufp->fullQData(oldp+714,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted),48);
    bufp->fullQData(oldp+716,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted1),48);
    bufp->fullQData(oldp+718,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted2),48);
    bufp->fullIData(oldp+720,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__accum),24);
    bufp->fullIData(oldp+721,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__accum),26);
    bufp->fullIData(oldp+722,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_raw),24);
    bufp->fullIData(oldp+723,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low),24);
    bufp->fullIData(oldp+724,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low2),26);
    bufp->fullQData(oldp+725,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended),48);
    bufp->fullQData(oldp+727,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended1),48);
    bufp->fullQData(oldp+729,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended2),48);
    bufp->fullIData(oldp+731,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__accum),24);
    bufp->fullIData(oldp+732,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2),32);
    bufp->fullCData(oldp+733,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zerocount),5);
    bufp->fullCData(oldp+734,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt1),4);
    bufp->fullCData(oldp+735,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt2),4);
    bufp->fullCData(oldp+736,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt3),4);
    bufp->fullBit(oldp+737,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__comp2));
    bufp->fullBit(oldp+738,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__magcheck2));
    bufp->fullBit(oldp+739,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zero));
    bufp->fullBit(oldp+740,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__comp));
    bufp->fullBit(oldp+741,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__magcheck));
    bufp->fullBit(oldp+742,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zero));
    bufp->fullBit(oldp+743,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[0]));
    bufp->fullBit(oldp+744,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[1]));
    bufp->fullBit(oldp+745,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[2]));
    bufp->fullBit(oldp+746,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[3]));
    bufp->fullBit(oldp+747,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[4]));
    bufp->fullCData(oldp+748,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[0]),8);
    bufp->fullCData(oldp+749,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[1]),8);
    bufp->fullCData(oldp+750,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[2]),8);
    bufp->fullCData(oldp+751,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[3]),8);
    bufp->fullCData(oldp+752,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[4]),8);
    bufp->fullBit(oldp+753,(vlSelfRef.TB_gpnae__DOT__clk));
    bufp->fullBit(oldp+754,((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal) 
                                      | (IData)(vlSelfRef.TB_gpnae__DOT__wr_en_i))))));
    bufp->fullIData(oldp+755,(vlSelfRef.TB_gpnae__DOT__final_result_o),32);
    bufp->fullIData(oldp+756,(vlSelfRef.TB_gpnae__DOT__cycle_counter),32);
    bufp->fullCData(oldp+757,(vlSelfRef.TB_gpnae__DOT__current_state),2);
    bufp->fullIData(oldp+758,(vlSelfRef.TB_gpnae__DOT__current_phase),32);
    bufp->fullBit(oldp+759,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.clk_i));
    bufp->fullBit(oldp+760,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.clk_i));
    bufp->fullBit(oldp+761,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk));
    bufp->fullIData(oldp+762,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__doutb_reg),32);
    bufp->fullIData(oldp+763,(vlSelfRef.TB_gpnae__DOT__dut__DOT__fifo_data_registered),32);
    bufp->fullIData(oldp+764,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_result),32);
    bufp->fullIData(oldp+765,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_result),32);
    bufp->fullIData(oldp+766,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_input),32);
    bufp->fullBit(oldp+767,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid));
    bufp->fullBit(oldp+768,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_rd_en));
    bufp->fullBit(oldp+769,(vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu));
    bufp->fullBit(oldp+770,((1U & ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg) 
                                   >> 4U))));
    bufp->fullCData(oldp+771,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__wr_ptr),5);
    bufp->fullCData(oldp+772,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr),5);
    bufp->fullBit(oldp+773,((1U & (vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                   >> (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr)))));
    bufp->fullIData(oldp+774,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__ram_data_b),32);
    bufp->fullBit(oldp+775,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__rd_en_coeff));
    bufp->fullBit(oldp+776,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__add_valid));
    bufp->fullBit(oldp+777,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid));
    bufp->fullBit(oldp+778,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage6));
    bufp->fullCData(oldp+779,((0x1fU & ((1U & ((~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)) 
                                               | (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o)))
                                         ? (IData)(vlSelfRef.TB_gpnae__DOT__terms_i)
                                         : ((IData)(vlSelfRef.TB_gpnae__DOT__terms_i) 
                                            - (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count))))),5);
    bufp->fullBit(oldp+780,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n));
    bufp->fullBit(oldp+781,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o));
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_10_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_10(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_10\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_10_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_10_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_10_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+782,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state),4);
    bufp->fullCData(oldp+783,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count),5);
    bufp->fullCData(oldp+784,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next),5);
    bufp->fullCData(oldp+785,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg),5);
    bufp->fullCData(oldp+786,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__item_credit_count),6);
    bufp->fullBit(oldp+787,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__unnamedblk1__DOT__dec_en));
    bufp->fullIData(oldp+788,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1),32);
    bufp->fullIData(oldp+789,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__adder_result),32);
    bufp->fullIData(oldp+790,((((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign) 
                                << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp) 
                                              << 0x17U) 
                                             | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan))),32);
    bufp->fullCData(oldp+791,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Exponent),8);
    bufp->fullIData(oldp+792,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Mantissa),23);
    bufp->fullCData(oldp+793,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp),8);
    bufp->fullCData(oldp+794,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallExp),8);
    bufp->fullIData(oldp+795,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign) 
                                << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent) 
                                              << 0x17U) 
                                             | vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa))),32);
    bufp->fullBit(oldp+796,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage6));
    bufp->fullBit(oldp+797,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply));
    bufp->fullIData(oldp+798,((((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign) 
                                << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp) 
                                              << 0x17U) 
                                             | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan))),32);
    bufp->fullBit(oldp+799,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i));
    bufp->fullBit(oldp+800,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__valid_i));
    bufp->fullBit(oldp+801,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign));
    bufp->fullCData(oldp+802,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent),8);
    bufp->fullIData(oldp+803,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa),23);
    bufp->fullCData(oldp+804,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__SmallExp),8);
    bufp->fullBit(oldp+805,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage4));
    bufp->fullBit(oldp+806,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage5));
    bufp->fullBit(oldp+807,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__sign));
    bufp->fullIData(oldp+808,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__add_result),32);
    bufp->fullIData(oldp+809,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2) 
                                << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2) 
                                              << 0x17U) 
                                             | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2))),32);
    bufp->fullIData(oldp+810,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__mux_output),32);
    bufp->fullBit(oldp+811,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign1));
    bufp->fullBit(oldp+812,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2));
    bufp->fullBit(oldp+813,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage1));
    bufp->fullBit(oldp+814,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage2));
    bufp->fullCData(oldp+815,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Exponent),8);
    bufp->fullCData(oldp+816,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Exponent),8);
    bufp->fullBit(oldp+817,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign));
    bufp->fullBit(oldp+818,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign_A));
    bufp->fullBit(oldp+819,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign_B));
    bufp->fullCData(oldp+820,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__Temp_Exponent),8);
    bufp->fullBit(oldp+821,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__capture_valid));
    bufp->fullCData(oldp+822,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Exponent_reg),8);
    bufp->fullCData(oldp+823,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Exponent_reg),8);
    bufp->fullBit(oldp+824,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__lowest_valid));
    bufp->fullBit(oldp+825,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__second_valid));
    bufp->fullBit(oldp+826,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__third_valid));
    bufp->fullBit(oldp+827,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__final_valid));
    bufp->fullCData(oldp+828,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__lowest_diff),3);
    bufp->fullCData(oldp+829,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__second_diff),3);
    bufp->fullCData(oldp+830,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__third_diff),3);
    bufp->fullCData(oldp+831,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__final_diff),5);
    bufp->fullIData(oldp+832,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+833,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+834,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk3__DOT__i),32);
    bufp->fullCData(oldp+835,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__next_state),3);
    bufp->fullBit(oldp+836,(vlSelfRef.TB_gpnae__DOT__dut__DOT__u_control_unit__DOT__fsm_rd_en));
    bufp->fullIData(oldp+837,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.A),32);
    bufp->fullIData(oldp+838,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Mantissa),24);
    bufp->fullIData(oldp+839,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Mantissa),24);
    bufp->fullQData(oldp+840,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__Temp_Mantissa),48);
    bufp->fullQData(oldp+842,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__partial_product),48);
    bufp->fullIData(oldp+844,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__i),32);
    bufp->fullIData(oldp+845,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__i),32);
    bufp->fullIData(oldp+846,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__i),32);
    bufp->fullIData(oldp+847,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+848,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+849,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+850,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Mantissa),24);
    bufp->fullIData(oldp+851,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Mantissa),24);
    bufp->fullCData(oldp+852,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Exponent),8);
    bufp->fullCData(oldp+853,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ExpChoice1),8);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_11_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_11(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_11\n"); );
    // Init
    VTB_gpnae___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTB_gpnae___024root*>(voidSelf);
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTB_gpnae___024root__trace_full_11_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_full_11_sub_0(VTB_gpnae___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_full_11_sub_0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+854,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ExpChoice2),8);
    bufp->fullCData(oldp+855,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Exponent_reg),8);
    bufp->fullIData(oldp+856,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last),24);
    bufp->fullIData(oldp+857,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__i),32);
    bufp->fullIData(oldp+858,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last),24);
    bufp->fullIData(oldp+859,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__i),32);
    bufp->fullIData(oldp+860,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last),26);
    bufp->fullIData(oldp+861,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__i),32);
    bufp->fullIData(oldp+862,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk3__DOT__i),32);
}
