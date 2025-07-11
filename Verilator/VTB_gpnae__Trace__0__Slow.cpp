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
    tracep->declBus(c+860,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+861,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+862,0,"CONTROL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+757,9,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,1,"signal_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+95,1,"wr_en_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,1,"last_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,1,"start_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,1,"terms_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+99,1,"control_word_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+516,6,"full_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,6,"empty_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,9,"idle_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+281,3,"final_result_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+282,3,"done_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+759,9,"processed_signals",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+760,9,"cycle_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+761,9,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+100,1,"num_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+101,1,"buffer_write_start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+102,1,"buffer_write_end_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+103,1,"processing_start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+104,1,"processing_end_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("cycles_per_input", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+105+i*1,1,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+137,1,"total_buffer_write_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+138,1,"total_processing_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+139,1,"total_operation_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+140,1,"total_input_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+141,1,"avg_cycles_per_input",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
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
    tracep->declBus(c+762,9,"current_phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+865,0,"CONTROL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+757,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,1,"signal_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+95,1,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,1,"last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,1,"terms_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+99,1,"control_word_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+516,6,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,6,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,9,"idle_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+281,3,"final_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+282,3,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+528,6,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+763,9,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+529,6,"rd_en_signal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+764,9,"fsm_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+765,9,"mac_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"fifo_data_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+767,9,"selu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+768,9,"mac_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+769,9,"sigtan_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+770,9,"done_selu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+771,9,"done_mac",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+425,5,"done_sigtan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,3,"selu_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+284,3,"mac_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+285,3,"sigtan_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,9,"selu_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,9,"mac_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+774,9,"sigtan_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,6,"select_sigtan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+775,9,"selu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,6,"mac_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+532,6,"done_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+776,9,"fifo_data_registered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+533,6,"is_positive_selu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+866,0,"lamda",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+867,0,"lamda_alpha",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+777,9,"selu_input",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+778,9,"selu_const",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("input_fifo_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+861,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+757,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,1,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,6,"rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,1,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+516,6,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,6,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,9,"idle_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,6,"status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+779,9,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+780,9,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("FIFO", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+861,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+860,0,"RAM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+779,9,"addra",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+780,9,"addrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+94,1,"dina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+757,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,1,"wea",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+519,6,"ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+781,9,"enb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstnb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,6,"regceb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"doutb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("BRAM", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+539+i*1,6,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+782,9,"ram_data_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,9,"doutb_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("cntr_read", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+518,6,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+780,9,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("cntr_write", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+520,6,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+779,9,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("mac_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+863,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"signal_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+765,9,"rd_signal_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,6,"last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,1,"terms_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+517,6,"empty_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+768,9,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+771,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+679,8,"coeff_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+783,9,"rd_en_coeff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,3,"load_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,3,"dp_reset_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+784,9,"add_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,9,"mul_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,1,"add_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+717,9,"mul_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+786,9,"coeff_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+787,9,"datapath_reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("coeff_rom_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+861,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+868,0,"INIT_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 135,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+783,9,"rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+786,9,"coeff_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+679,8,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ROM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+861,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+868,0,"INIT_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 135,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+786,9,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+783,9,"rd_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+679,8,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ROM", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+61+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("controller_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+864,0,"ADDR_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,6,"start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,6,"empty_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+142,1,"terms_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+717,9,"mul_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,1,"add_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,9,"mul_valid_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+784,9,"add_valid_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,3,"dp_reset_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+765,9,"rd_signal_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+783,9,"rd_coeff_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,3,"load_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+786,9,"coeff_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+771,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+788,9,"reload_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+293,3,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+789,10,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+790,10,"term_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+791,10,"term_count_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+792,10,"done_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+793,10,"done_shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("datapath_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,9,"signal_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+679,8,"coeff_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+291,3,"load_result_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+784,9,"add_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,9,"mul_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,1,"add_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+717,9,"mul_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+768,9,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+513,6,"mul_in1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+692,8,"mul_in2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+680,8,"add_in1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+684,8,"add_in2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+794,10,"adder_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+795,10,"mul_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("MUL", VerilatedTracePrefixType::SCOPE_MODULE);
    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ADD", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+784,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+680,8,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+684,8,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+794,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+160,1,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+693,8,"zerocount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+796,10,"Sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+797,10,"Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+798,10,"Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+704,8,"comp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+705,8,"magcheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+706,8,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+206,2,"carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+571,7,"check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+572,7,"check_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+573,7,"check_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,6,"BigExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+483,6,"BigExp_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+484,6,"BigExp_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+485,6,"BigExp_delayed_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+486,6,"SmallExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+207,2,"DifferenceExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+477,6,"BigMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+478,6,"BigMan_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+479,6,"BigMan_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+480,6,"SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+481,6,"SmallMan_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+208,2,"Temp_SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+209,2,"TempMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+627,7,"valid_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+628,7,"valid_stage2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+629,7,"valid_stage3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+630,7,"valid_stage4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+631,7,"valid_stage5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+160,1,"valid_stage6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+681,8,"A_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+574,7,"B_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+575,7,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+576,7,"sign_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+577,7,"sign_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+578,7,"sign_delayed_delayed_delayed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+682,8,"A_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+487,6,"B_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+683,8,"A_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+685,8,"B_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("stage_31", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,2,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+693,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+694,8,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+695,8,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+696,8,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+210,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+694,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+211,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+695,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+696,8,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("selu_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+772,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+775,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+533,6,"is_positive_selu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+777,9,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+778,9,"selu_const",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+767,9,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+770,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+799,10,"fp32_down_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+800,10,"done_fp32_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,10,"valid_multiply",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+802,10,"multiply_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+642,7,"done_multiply",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("multiply_32_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("fp32_down_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+803,10,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+804,10,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+777,9,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+799,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+800,10,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+873,0,"CONST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+603,7,"zerocount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+805,10,"Sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+806,10,"Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+807,10,"Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+604,7,"comp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+605,7,"magcheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+606,7,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,2,"carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+448,5,"check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+449,5,"BigExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+450,5,"SmallExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+186,2,"DifferenceExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+451,5,"BigMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+452,5,"SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+187,2,"Temp_SmallMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+188,2,"TempMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+808,10,"valid_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+444,5,"valid_stage2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+445,5,"valid_stage3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+446,5,"valid_stage4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+447,5,"valid_stage5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,10,"valid_stage6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+453,5,"A_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+454,5,"C_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+809,10,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+455,5,"A_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+456,5,"C_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+457,5,"A_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+607,7,"C_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("stage_31", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+188,2,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+603,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+608,7,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+609,7,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+610,7,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+189,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+608,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+190,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+609,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+191,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+610,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sigtan_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+774,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+771,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+768,9,"mac_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+530,6,"select_sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+769,9,"final_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+425,5,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+810,10,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+811,10,"sub_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+812,10,"done_fp32_add_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+813,10,"mux_output",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+874,0,"mux_output_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fp32_add_sub_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+774,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+771,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+768,9,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+810,10,"Result1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+811,10,"Result2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+812,10,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+875,0,"CONST_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+873,0,"CONST_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+611,7,"zerocount1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+612,7,"zerocount2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+814,10,"Sign1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+815,10,"Sign2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,2,"Exponent1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+193,2,"Exponent2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+194,2,"Mantissa1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+195,2,"Mantissa2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+488,6,"comp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+488,6,"comp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,6,"magcheck1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,6,"magcheck2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,6,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,2,"carry1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,2,"carry2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+431,5,"check1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+432,5,"check2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+467,5,"BigExp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+468,5,"BigExp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+469,5,"SmallExp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+470,5,"SmallExp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+471,5,"DifferenceExp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+472,5,"DifferenceExp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+433,5,"BigMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+434,5,"BigMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+473,6,"SmallMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+474,6,"SmallMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+475,6,"Temp_SmallMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+476,6,"Temp_SmallMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+198,2,"TempMan1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+199,2,"TempMan2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+534,6,"valid_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+535,6,"valid_stage2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+536,6,"valid_stage3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+537,6,"valid_stage4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+538,6,"valid_stage5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+812,10,"valid_stage6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+435,5,"A_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+436,5,"C1_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+437,5,"C2_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+438,5,"sign1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+439,5,"sign2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+491,6,"A_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+492,6,"C1_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+492,6,"C2_Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+493,6,"A_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+494,6,"C1_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+494,6,"C2_Man",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("stage_31_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+198,2,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+611,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+613,7,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+614,7,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+615,7,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+200,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+613,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+201,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+614,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+202,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+615,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("stage_31_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+199,2,"i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+612,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+616,7,"cnt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+617,7,"cnt2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+618,7,"cnt3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+203,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+616,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+204,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+617,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+205,2,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+618,7,"o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_divide_32", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+774,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+812,10,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+813,10,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+810,10,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+769,9,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+425,5,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+458,5,"A_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+459,5,"B_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+816,10,"A_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+817,10,"B_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+818,10,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+460,5,"sign_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+461,5,"sign_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+819,10,"Temp_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+426,5,"Temp_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+820,10,"intermediateMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+821,10,"intermediateExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+822,10,"intermediateSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+876,0,"bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+877,0,"shiftStages",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 26; ++i) {
        tracep->declBit(c+652+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+823,10,"dbz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+425,5,"div_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+824,10,"capture_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+825,10,"A_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+826,10,"B_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+827,10,"lowest_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+828,10,"second_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+829,10,"third_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+830,10,"final_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+831,10,"lowest_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+832,10,"second_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+833,10,"third_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+834,10,"final_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("pipe_sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 24; ++i) {
        tracep->declBit(c+401+i*1,5,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1));
    }
    tracep->popPrefix();
    tracep->pushPrefix("pipe_Exponent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 24; ++i) {
        tracep->declBus(c+377+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("divu_mantissa", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+877,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+878,0,"FBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+774,9,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,1,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+678,8,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+619,7,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+425,5,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+427,5,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+823,10,"dbz",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+428,5,"ovf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+458,5,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+459,5,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+426,5,"val",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+878,0,"FBITSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+835,10,"b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+429,5,"quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+620,7,"quo_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+430,5,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+621,7,"acc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+879,0,"ITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+622,7,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+836,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+837,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+838,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("perform_test__Vstatic__unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+144,1,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("wait_for_processing__Vstatic__unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,1,"processed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+146,1,"last_done_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+147,1,"current_done_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("write_signal__Vstatic__unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+148,1,"start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
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
    tracep->declBit(c+772,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,10,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+839,10,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+778,9,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+802,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+642,7,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+840,10,"A_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+841,10,"B_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+842,10,"A_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+843,10,"B_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+149,1,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,1,"sign_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,1,"sign_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+167,2,"Temp_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+844,10,"Temp_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+462,5,"intermediateMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+463,5,"ManChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+464,5,"ManChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+465,5,"intermediateExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+623,7,"ExpChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+624,7,"ExpChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+625,7,"intermediateSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+626,7,"signChoice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+466,5,"choice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+876,0,"bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+861,0,"shiftStages",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 9; ++i) {
        tracep->declBit(c+643+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+174,2,"capture_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,2,"A_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+169,2,"B_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+175,2,"lowest_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,2,"second_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,2,"third_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,2,"final_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+170,2,"lowest_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+171,2,"second_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+172,2,"third_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+173,2,"final_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("pipe_sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBit(c+632+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1));
    }
    tracep->popPrefix();
    tracep->pushPrefix("pipe_Exponent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+637+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("karatsuba", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+877,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+772,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+840,10,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+841,10,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declQuad(c+844,10,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+880,0,"HALF_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+881,0,"MID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+371,4,"A_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+372,4,"A_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+373,4,"B_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+374,4,"B_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+521,6,"P_low_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+522,6,"P_high_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+507,6,"P_middle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+375,4,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+376,4,"temp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+523,6,"P_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+524,6,"P_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+508,6,"temp3_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+525,6,"P_low2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+509,6,"temp3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declQuad(c+495,6,"P_high_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+497,6,"P_high_shifted1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+499,6,"P_high_shifted2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+510,6,"temp3_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+846,10,"partial_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+501,6,"P_low_extended",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+503,6,"P_low_extended1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+505,6,"P_low_extended2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->pushPrefix("booth_mult1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+772,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+372,4,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+374,4,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+521,6,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+294+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+219+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+301+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+226+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+229+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+179,2,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+180,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+232,2,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+526,6,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+848,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+772,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+371,4,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+373,4,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+522,6,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+308+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+233+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+315+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+240+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+243+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+181,2,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+182,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+246,3,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+527,6,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+849,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+881,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+772,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,1,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+375,4,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+376,4,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+507,6,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+322+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+247+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+329+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+254+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+257+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+183,2,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+184,2,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+260,3,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+512,6,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+850,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+851,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+852,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+853,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0(VTB_gpnae___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTB_gpnae___024root__trace_init_sub__TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL__0\n"); );
    VTB_gpnae__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,9,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+513,6,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+692,8,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+795,10,"Result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+717,9,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+854,10,"A_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+855,10,"B_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+364,4,"A_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+514,6,"B_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+164,1,"sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,2,"sign_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,2,"sign_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+365,4,"Temp_Exponent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+728,9,"Temp_Mantissa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+686,8,"intermediateMan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+688,8,"ManChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+701,8,"ManChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+687,8,"intermediateExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+689,8,"ExpChoice1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+690,8,"ExpChoice2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+702,8,"intermediateSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+703,8,"signChoice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+691,8,"choice",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+876,0,"bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+861,0,"shiftStages",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 9; ++i) {
        tracep->declBit(c+718+i*1,9,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+727,9,"capture_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+366,4,"A_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+515,6,"B_Exponent_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+697,8,"lowest_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,8,"second_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,8,"third_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+700,8,"final_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+367,4,"lowest_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+368,4,"second_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+369,4,"third_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+370,4,"final_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("pipe_sign", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBit(c+707+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1));
    }
    tracep->popPrefix();
    tracep->pushPrefix("pipe_Exponent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+712+i*1,8,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("karatsuba", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+877,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+854,10,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+855,10,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declQuad(c+728,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+880,0,"HALF_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+881,0,"MID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,1,"A_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+153,1,"A_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+440,5,"B_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+441,5,"B_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+745,9,"P_low_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+736,9,"P_high_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+746,9,"P_middle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+154,1,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+442,5,"temp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+737,9,"P_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+747,9,"P_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+730,9,"temp3_stage1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+748,9,"P_low2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+731,9,"temp3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declQuad(c+738,9,"P_high_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+740,9,"P_high_shifted1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+742,9,"P_high_shifted2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+732,9,"temp3_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+734,9,"partial_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+749,9,"P_low_extended",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+751,9,"P_low_extended1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declQuad(c+753,9,"P_low_extended2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->pushPrefix("booth_mult1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,1,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+441,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+745,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+336+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+261+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+343+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+268+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+213+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+155,1,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+156,1,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+161,1,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+755,9,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+856,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+880,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,1,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+440,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+736,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+350+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+271+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+357+i*1,4,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+278+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+216+i*1,2,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 23,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+157,1,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+158,1,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+162,1,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+744,9,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+857,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("booth_mult3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+881,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+773,9,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,9,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+154,1,"multiplicand",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+442,5,"multiplier",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+746,9,"product",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("partial_product", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+589+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("partial_product_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+579+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("mul_mod", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+596+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 2,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+586+i*1,7,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("val_next", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+286+i*1,3,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+159,1,"multiplicand_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+443,5,"multiplier_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+163,1,"partial_product_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+756,9,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+858,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+289,3,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+290,3,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+859,10,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
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
    bufp->fullIData(oldp+860,(0x20U),32);
    bufp->fullIData(oldp+861,(5U),32);
    bufp->fullIData(oldp+862,(2U),32);
    bufp->fullIData(oldp+863,(0x20U),32);
    bufp->fullIData(oldp+864,(5U),32);
    bufp->fullIData(oldp+865,(2U),32);
    bufp->fullIData(oldp+866,(0x3f867d5fU),32);
    bufp->fullIData(oldp+867,(0x3fd62d7dU),32);
    __Vtemp_1[0U] = 0x2e6d656dU;
    __Vtemp_1[1U] = 0x65666673U;
    __Vtemp_1[2U] = 0x725f636fU;
    __Vtemp_1[3U] = 0x61796c6fU;
    __Vtemp_1[4U] = 0x74U;
    bufp->fullWData(oldp+868,(__Vtemp_1),136);
    bufp->fullIData(oldp+873,(0xbf800000U),32);
    bufp->fullIData(oldp+874,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__mux_output_reg),32);
    bufp->fullIData(oldp+875,(0x3f800000U),32);
    bufp->fullCData(oldp+876,(0x7fU),7);
    bufp->fullIData(oldp+877,(0x18U),32);
    bufp->fullIData(oldp+878,(0x17U),32);
    bufp->fullIData(oldp+879,(0x2fU),32);
    bufp->fullIData(oldp+880,(0xcU),32);
    bufp->fullIData(oldp+881,(0xdU),32);
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
    bufp->fullCData(oldp+100,(vlSelfRef.TB_gpnae__DOT__num_sig),5);
    bufp->fullIData(oldp+101,(vlSelfRef.TB_gpnae__DOT__buffer_write_start_cycle),32);
    bufp->fullIData(oldp+102,(vlSelfRef.TB_gpnae__DOT__buffer_write_end_cycle),32);
    bufp->fullIData(oldp+103,(vlSelfRef.TB_gpnae__DOT__processing_start_cycle),32);
    bufp->fullIData(oldp+104,(vlSelfRef.TB_gpnae__DOT__processing_end_cycle),32);
    bufp->fullIData(oldp+105,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[0]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[1]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[2]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[3]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[4]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[5]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[6]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[7]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[8]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[9]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[10]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[11]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[12]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[13]),32);
    bufp->fullIData(oldp+119,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[14]),32);
    bufp->fullIData(oldp+120,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[15]),32);
    bufp->fullIData(oldp+121,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[16]),32);
    bufp->fullIData(oldp+122,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[17]),32);
    bufp->fullIData(oldp+123,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[18]),32);
    bufp->fullIData(oldp+124,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[19]),32);
    bufp->fullIData(oldp+125,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[20]),32);
    bufp->fullIData(oldp+126,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[21]),32);
    bufp->fullIData(oldp+127,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[22]),32);
    bufp->fullIData(oldp+128,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[23]),32);
    bufp->fullIData(oldp+129,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[24]),32);
    bufp->fullIData(oldp+130,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[25]),32);
    bufp->fullIData(oldp+131,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[26]),32);
    bufp->fullIData(oldp+132,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[27]),32);
    bufp->fullIData(oldp+133,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[28]),32);
    bufp->fullIData(oldp+134,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[29]),32);
    bufp->fullIData(oldp+135,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[30]),32);
    bufp->fullIData(oldp+136,(vlSelfRef.TB_gpnae__DOT__cycles_per_input[31]),32);
    bufp->fullIData(oldp+137,(vlSelfRef.TB_gpnae__DOT__total_buffer_write_cycles),32);
    bufp->fullIData(oldp+138,(vlSelfRef.TB_gpnae__DOT__total_processing_cycles),32);
    bufp->fullIData(oldp+139,(vlSelfRef.TB_gpnae__DOT__total_operation_cycles),32);
    bufp->fullIData(oldp+140,(vlSelfRef.TB_gpnae__DOT__total_input_cycles),32);
    bufp->fullIData(oldp+141,(vlSelfRef.TB_gpnae__DOT__avg_cycles_per_input),32);
    bufp->fullCData(oldp+142,((0x1fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.TB_gpnae__DOT__terms_i)))),5);
    bufp->fullBit(oldp+143,((1U & (~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)))));
    bufp->fullIData(oldp+144,(vlSelfRef.TB_gpnae__DOT__perform_test__Vstatic__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+145,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__processed),32);
    bufp->fullIData(oldp+146,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__last_done_cycle),32);
    bufp->fullIData(oldp+147,(vlSelfRef.TB_gpnae__DOT__wait_for_processing__Vstatic__unnamedblk4__DOT__current_done_cycle),32);
    bufp->fullIData(oldp+148,(vlSelfRef.TB_gpnae__DOT__write_signal__Vstatic__unnamedblk2__DOT__start_cycle),32);
    bufp->fullBit(oldp+149,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign));
    bufp->fullBit(oldp+150,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign_A));
    bufp->fullBit(oldp+151,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__sign_B));
    bufp->fullSData(oldp+152,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__A_high),12);
    bufp->fullSData(oldp+153,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__A_low),12);
    bufp->fullSData(oldp+154,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp1),13);
    bufp->fullSData(oldp+155,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+156,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+157,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+158,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+159,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold),13);
    bufp->fullBit(oldp+160,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage6));
    bufp->fullIData(oldp+161,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last),24);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last),24);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last),26);
    bufp->fullBit(oldp+164,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign));
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
    bufp->fullBit(oldp+165,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign_A));
    bufp->fullBit(oldp+166,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__sign_B));
    bufp->fullCData(oldp+167,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__Temp_Exponent),8);
    bufp->fullCData(oldp+168,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Exponent_reg),8);
    bufp->fullCData(oldp+169,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Exponent_reg),8);
    bufp->fullCData(oldp+170,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__lowest_sum),3);
    bufp->fullCData(oldp+171,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__second_sum),3);
    bufp->fullCData(oldp+172,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__third_sum),3);
    bufp->fullCData(oldp+173,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__final_sum),5);
    bufp->fullBit(oldp+174,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__capture_valid));
    bufp->fullBit(oldp+175,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__lowest_valid));
    bufp->fullBit(oldp+176,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__second_valid));
    bufp->fullBit(oldp+177,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__third_valid));
    bufp->fullBit(oldp+178,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__final_valid));
    bufp->fullSData(oldp+179,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+180,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+181,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplicand_hold),12);
    bufp->fullSData(oldp+182,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__multiplier_hold),12);
    bufp->fullSData(oldp+183,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplicand_hold),13);
    bufp->fullSData(oldp+184,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold),13);
    bufp->fullBit(oldp+185,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__carry));
    bufp->fullCData(oldp+186,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__DifferenceExp),8);
    bufp->fullIData(oldp+187,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Temp_SmallMan),24);
    bufp->fullIData(oldp+188,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan),24);
    bufp->fullCData(oldp+189,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan)),8);
    bufp->fullCData(oldp+190,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                                        >> 8U))),8);
    bufp->fullCData(oldp+191,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__TempMan 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+192,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent1),8);
    bufp->fullCData(oldp+193,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2),8);
    bufp->fullIData(oldp+194,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa1),23);
    bufp->fullIData(oldp+195,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2),23);
    bufp->fullBit(oldp+196,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__carry1));
    bufp->fullBit(oldp+197,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__carry2));
    bufp->fullIData(oldp+198,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1),24);
    bufp->fullIData(oldp+199,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2),24);
    bufp->fullCData(oldp+200,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1)),8);
    bufp->fullCData(oldp+201,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                                        >> 8U))),8);
    bufp->fullCData(oldp+202,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan1 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+203,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2)),8);
    bufp->fullCData(oldp+204,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                                        >> 8U))),8);
    bufp->fullCData(oldp+205,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__TempMan2 
                                        >> 0x10U))),8);
    bufp->fullBit(oldp+206,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__carry));
    bufp->fullCData(oldp+207,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__DifferenceExp),8);
    bufp->fullIData(oldp+208,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Temp_SmallMan),24);
    bufp->fullIData(oldp+209,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan),24);
    bufp->fullCData(oldp+210,((0xffU & vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan)),8);
    bufp->fullCData(oldp+211,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                                        >> 8U))),8);
    bufp->fullCData(oldp+212,((0xffU & (vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__TempMan 
                                        >> 0x10U))),8);
    bufp->fullIData(oldp+213,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0]),24);
    bufp->fullIData(oldp+214,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1]),24);
    bufp->fullIData(oldp+215,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2]),24);
    bufp->fullIData(oldp+216,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0]),24);
    bufp->fullIData(oldp+217,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1]),24);
    bufp->fullIData(oldp+218,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2]),24);
    bufp->fullIData(oldp+219,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+220,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+221,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+222,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+223,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+224,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+225,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+226,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0]),24);
    bufp->fullIData(oldp+227,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1]),24);
    bufp->fullIData(oldp+228,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2]),24);
    bufp->fullIData(oldp+229,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[0]),24);
    bufp->fullIData(oldp+230,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[1]),24);
    bufp->fullIData(oldp+231,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__val_next[2]),24);
    bufp->fullIData(oldp+232,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_last),24);
    bufp->fullIData(oldp+233,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+234,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+235,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+236,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+237,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+238,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+239,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6]),24);
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
    bufp->fullIData(oldp+240,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0]),24);
    bufp->fullIData(oldp+241,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1]),24);
    bufp->fullIData(oldp+242,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2]),24);
    bufp->fullIData(oldp+243,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[0]),24);
    bufp->fullIData(oldp+244,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[1]),24);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__val_next[2]),24);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_last),24);
    bufp->fullIData(oldp+247,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0]),26);
    bufp->fullIData(oldp+248,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1]),26);
    bufp->fullIData(oldp+249,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2]),26);
    bufp->fullIData(oldp+250,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3]),26);
    bufp->fullIData(oldp+251,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4]),26);
    bufp->fullIData(oldp+252,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5]),26);
    bufp->fullIData(oldp+253,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6]),26);
    bufp->fullIData(oldp+254,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0]),26);
    bufp->fullIData(oldp+255,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1]),26);
    bufp->fullIData(oldp+256,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2]),26);
    bufp->fullIData(oldp+257,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0]),26);
    bufp->fullIData(oldp+258,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1]),26);
    bufp->fullIData(oldp+259,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2]),26);
    bufp->fullIData(oldp+260,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_last),26);
    bufp->fullIData(oldp+261,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+262,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+263,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+264,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+265,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+266,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+267,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+268,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[0]),24);
    bufp->fullIData(oldp+269,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[1]),24);
    bufp->fullIData(oldp+270,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__val[2]),24);
    bufp->fullIData(oldp+271,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[0]),24);
    bufp->fullIData(oldp+272,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[1]),24);
    bufp->fullIData(oldp+273,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[2]),24);
    bufp->fullIData(oldp+274,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[3]),24);
    bufp->fullIData(oldp+275,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[4]),24);
    bufp->fullIData(oldp+276,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[5]),24);
    bufp->fullIData(oldp+277,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product_hold[6]),24);
    bufp->fullIData(oldp+278,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[0]),24);
    bufp->fullIData(oldp+279,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[1]),24);
    bufp->fullIData(oldp+280,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__val[2]),24);
    bufp->fullIData(oldp+281,(vlSelfRef.TB_gpnae__DOT__final_result_o),32);
    bufp->fullBit(oldp+282,(vlSelfRef.TB_gpnae__DOT__done_o));
    bufp->fullBit(oldp+283,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_enable));
    bufp->fullBit(oldp+284,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_enable));
    bufp->fullBit(oldp+285,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_enable));
    bufp->fullIData(oldp+286,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[0]),26);
    bufp->fullIData(oldp+287,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[1]),26);
    bufp->fullIData(oldp+288,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val_next[2]),26);
    bufp->fullIData(oldp+289,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+290,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+291,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__load_result));
    bufp->fullBit(oldp+292,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__dp_reset_o));
    bufp->fullCData(oldp+293,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__current_state),4);
    bufp->fullIData(oldp+294,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+295,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+296,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+297,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+298,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+299,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+300,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6]),24);
    bufp->fullCData(oldp+301,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+302,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+303,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+304,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+305,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+306,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+307,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+308,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+309,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+310,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+311,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+312,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+313,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+314,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6]),24);
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
    bufp->fullCData(oldp+315,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+316,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+317,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+318,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+319,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+320,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+321,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+322,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0]),26);
    bufp->fullIData(oldp+323,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1]),26);
    bufp->fullIData(oldp+324,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2]),26);
    bufp->fullIData(oldp+325,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3]),26);
    bufp->fullIData(oldp+326,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4]),26);
    bufp->fullIData(oldp+327,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5]),26);
    bufp->fullIData(oldp+328,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6]),26);
    bufp->fullCData(oldp+329,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+330,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+331,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+332,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+333,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+334,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+335,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+336,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+337,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+338,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+339,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+340,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+341,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+342,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__partial_product[6]),24);
    bufp->fullCData(oldp+343,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+344,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+345,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+346,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+347,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+348,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+349,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__mul_mod[6]),3);
    bufp->fullIData(oldp+350,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[0]),24);
    bufp->fullIData(oldp+351,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[1]),24);
    bufp->fullIData(oldp+352,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[2]),24);
    bufp->fullIData(oldp+353,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[3]),24);
    bufp->fullIData(oldp+354,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[4]),24);
    bufp->fullIData(oldp+355,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[5]),24);
    bufp->fullIData(oldp+356,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__partial_product[6]),24);
    bufp->fullCData(oldp+357,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+358,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+359,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+360,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+361,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+362,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+363,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__mul_mod[6]),3);
    bufp->fullCData(oldp+364,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Exponent),8);
    bufp->fullCData(oldp+365,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__Temp_Exponent),8);
    bufp->fullCData(oldp+366,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Exponent_reg),8);
    bufp->fullCData(oldp+367,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__lowest_sum),3);
    bufp->fullCData(oldp+368,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__second_sum),3);
    bufp->fullCData(oldp+369,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__third_sum),3);
    bufp->fullCData(oldp+370,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__final_sum),5);
    bufp->fullSData(oldp+371,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__A_high),12);
    bufp->fullSData(oldp+372,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__A_low),12);
    bufp->fullSData(oldp+373,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__B_high),12);
    bufp->fullSData(oldp+374,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__B_low),12);
    bufp->fullSData(oldp+375,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp1),13);
    bufp->fullSData(oldp+376,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp2),13);
    bufp->fullCData(oldp+377,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[0]),8);
    bufp->fullCData(oldp+378,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[1]),8);
    bufp->fullCData(oldp+379,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[2]),8);
    bufp->fullCData(oldp+380,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[3]),8);
    bufp->fullCData(oldp+381,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[4]),8);
    bufp->fullCData(oldp+382,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[5]),8);
    bufp->fullCData(oldp+383,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[6]),8);
    bufp->fullCData(oldp+384,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[7]),8);
    bufp->fullCData(oldp+385,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[8]),8);
    bufp->fullCData(oldp+386,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[9]),8);
    bufp->fullCData(oldp+387,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[10]),8);
    bufp->fullCData(oldp+388,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[11]),8);
    bufp->fullCData(oldp+389,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[12]),8);
    bufp->fullCData(oldp+390,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[13]),8);
    bufp->fullCData(oldp+391,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[14]),8);
    bufp->fullCData(oldp+392,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[15]),8);
    bufp->fullCData(oldp+393,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[16]),8);
    bufp->fullCData(oldp+394,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[17]),8);
    bufp->fullCData(oldp+395,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[18]),8);
    bufp->fullCData(oldp+396,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[19]),8);
    bufp->fullCData(oldp+397,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[20]),8);
    bufp->fullCData(oldp+398,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[21]),8);
    bufp->fullCData(oldp+399,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[22]),8);
    bufp->fullCData(oldp+400,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_Exponent[23]),8);
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
    bufp->fullBit(oldp+401,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[0]));
    bufp->fullBit(oldp+402,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[1]));
    bufp->fullBit(oldp+403,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[2]));
    bufp->fullBit(oldp+404,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[3]));
    bufp->fullBit(oldp+405,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[4]));
    bufp->fullBit(oldp+406,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[5]));
    bufp->fullBit(oldp+407,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[6]));
    bufp->fullBit(oldp+408,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[7]));
    bufp->fullBit(oldp+409,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[8]));
    bufp->fullBit(oldp+410,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[9]));
    bufp->fullBit(oldp+411,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[10]));
    bufp->fullBit(oldp+412,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[11]));
    bufp->fullBit(oldp+413,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[12]));
    bufp->fullBit(oldp+414,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[13]));
    bufp->fullBit(oldp+415,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[14]));
    bufp->fullBit(oldp+416,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[15]));
    bufp->fullBit(oldp+417,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[16]));
    bufp->fullBit(oldp+418,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[17]));
    bufp->fullBit(oldp+419,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[18]));
    bufp->fullBit(oldp+420,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[19]));
    bufp->fullBit(oldp+421,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[20]));
    bufp->fullBit(oldp+422,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[21]));
    bufp->fullBit(oldp+423,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[22]));
    bufp->fullBit(oldp+424,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__pipe_sign[23]));
    bufp->fullBit(oldp+425,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__div_done));
    bufp->fullIData(oldp+426,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__Temp_Mantissa),24);
    bufp->fullBit(oldp+427,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__valid));
    bufp->fullBit(oldp+428,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__ovf));
    bufp->fullIData(oldp+429,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo),24);
    bufp->fullIData(oldp+430,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc),25);
    bufp->fullBit(oldp+431,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__check1));
    bufp->fullBit(oldp+432,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__check2));
    bufp->fullIData(oldp+433,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigMan1),24);
    bufp->fullIData(oldp+434,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigMan2),24);
    bufp->fullBit(oldp+435,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_sign));
    bufp->fullBit(oldp+436,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C1_sign));
    bufp->fullBit(oldp+437,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_sign));
    bufp->fullBit(oldp+438,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__sign1));
    bufp->fullBit(oldp+439,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__sign2));
    bufp->fullSData(oldp+440,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__B_high),12);
    bufp->fullSData(oldp+441,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__B_low),12);
    bufp->fullSData(oldp+442,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp2),13);
    bufp->fullSData(oldp+443,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__multiplier_hold),13);
    bufp->fullBit(oldp+444,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage2));
    bufp->fullBit(oldp+445,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage3));
    bufp->fullBit(oldp+446,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage4));
    bufp->fullBit(oldp+447,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage5));
    bufp->fullBit(oldp+448,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__check));
    bufp->fullCData(oldp+449,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__BigExp),8);
    bufp->fullCData(oldp+450,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__SmallExp),8);
    bufp->fullIData(oldp+451,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__BigMan),24);
    bufp->fullIData(oldp+452,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__SmallMan),24);
    bufp->fullBit(oldp+453,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_sign));
    bufp->fullBit(oldp+454,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_sign));
    bufp->fullCData(oldp+455,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Exp),8);
    bufp->fullCData(oldp+456,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Exp),8);
    bufp->fullIData(oldp+457,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__A_Man),23);
    bufp->fullIData(oldp+458,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Mantissa),24);
    bufp->fullIData(oldp+459,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Mantissa),24);
    bufp->fullBit(oldp+460,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign_A));
    bufp->fullBit(oldp+461,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign_B));
    bufp->fullIData(oldp+462,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan),23);
    bufp->fullIData(oldp+463,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ManChoice1),23);
    bufp->fullIData(oldp+464,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ManChoice2),23);
    bufp->fullCData(oldp+465,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp),8);
    bufp->fullBit(oldp+466,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__choice));
    bufp->fullCData(oldp+467,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigExp1),8);
    bufp->fullCData(oldp+468,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__BigExp2),8);
    bufp->fullCData(oldp+469,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallExp1),8);
    bufp->fullCData(oldp+470,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallExp2),8);
    bufp->fullCData(oldp+471,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__DifferenceExp1),8);
    bufp->fullCData(oldp+472,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__DifferenceExp2),8);
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
    bufp->fullIData(oldp+473,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallMan1),24);
    bufp->fullIData(oldp+474,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__SmallMan2),24);
    bufp->fullIData(oldp+475,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Temp_SmallMan1),24);
    bufp->fullIData(oldp+476,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Temp_SmallMan2),24);
    bufp->fullIData(oldp+477,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan),24);
    bufp->fullIData(oldp+478,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan_delayed),24);
    bufp->fullIData(oldp+479,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigMan_delayed_delayed),24);
    bufp->fullIData(oldp+480,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallMan),24);
    bufp->fullIData(oldp+481,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallMan_delayed),24);
    bufp->fullCData(oldp+482,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp),8);
    bufp->fullCData(oldp+483,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed),8);
    bufp->fullCData(oldp+484,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed_delayed),8);
    bufp->fullCData(oldp+485,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__BigExp_delayed_delayed_delayed),8);
    bufp->fullCData(oldp+486,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__SmallExp),8);
    bufp->fullCData(oldp+487,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Exp),8);
    bufp->fullBit(oldp+488,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__comp2));
    bufp->fullBit(oldp+489,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__magcheck2));
    bufp->fullBit(oldp+490,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zero));
    bufp->fullCData(oldp+491,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Exp),8);
    bufp->fullCData(oldp+492,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Exp),8);
    bufp->fullIData(oldp+493,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__A_Man),23);
    bufp->fullIData(oldp+494,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__C2_Man),23);
    bufp->fullQData(oldp+495,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted),48);
    bufp->fullQData(oldp+497,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted1),48);
    bufp->fullQData(oldp+499,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_shifted2),48);
    bufp->fullQData(oldp+501,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended),48);
    bufp->fullQData(oldp+503,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended1),48);
    bufp->fullQData(oldp+505,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_extended2),48);
    bufp->fullIData(oldp+507,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_middle),26);
    bufp->fullIData(oldp+508,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3_stage1),26);
    bufp->fullIData(oldp+509,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3),25);
    bufp->fullQData(oldp+510,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__temp3_shifted),48);
    bufp->fullIData(oldp+512,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__accum),26);
    bufp->fullIData(oldp+513,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in1),32);
    bufp->fullCData(oldp+514,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Exponent),8);
    bufp->fullCData(oldp+515,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Exponent_reg),8);
    bufp->fullBit(oldp+516,((vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                             >> 0x1fU)));
    bufp->fullBit(oldp+517,((0U == vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)));
    bufp->fullIData(oldp+518,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status),32);
    bufp->fullBit(oldp+519,((1U & (~ (vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                      >> 0x1fU)))));
    bufp->fullIData(oldp+520,((~ vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status)),32);
    bufp->fullIData(oldp+521,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low_raw),24);
    bufp->fullIData(oldp+522,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high_raw),24);
    bufp->fullIData(oldp+523,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_high),24);
    bufp->fullIData(oldp+524,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low),24);
    bufp->fullIData(oldp+525,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__P_low2),26);
    bufp->fullIData(oldp+526,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__accum),24);
    bufp->fullIData(oldp+527,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__accum),24);
    bufp->fullCData(oldp+528,(vlSelfRef.TB_gpnae__DOT__dut__DOT__current_state),3);
    bufp->fullBit(oldp+529,(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal));
    bufp->fullCData(oldp+530,(vlSelfRef.TB_gpnae__DOT__dut__DOT__select_sigtan),2);
    bufp->fullBit(oldp+531,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_valid));
    bufp->fullCData(oldp+532,(vlSelfRef.TB_gpnae__DOT__dut__DOT__done_delay),3);
    bufp->fullBit(oldp+533,(vlSelfRef.TB_gpnae__DOT__dut__DOT__is_positive_selu));
    bufp->fullBit(oldp+534,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage1));
    bufp->fullBit(oldp+535,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage2));
    bufp->fullBit(oldp+536,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage3));
    bufp->fullBit(oldp+537,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage4));
    bufp->fullBit(oldp+538,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage5));
    bufp->fullIData(oldp+539,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[0]),32);
    bufp->fullIData(oldp+540,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[1]),32);
    bufp->fullIData(oldp+541,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[2]),32);
    bufp->fullIData(oldp+542,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[3]),32);
    bufp->fullIData(oldp+543,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[4]),32);
    bufp->fullIData(oldp+544,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[5]),32);
    bufp->fullIData(oldp+545,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[6]),32);
    bufp->fullIData(oldp+546,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[7]),32);
    bufp->fullIData(oldp+547,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[8]),32);
    bufp->fullIData(oldp+548,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[9]),32);
    bufp->fullIData(oldp+549,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[10]),32);
    bufp->fullIData(oldp+550,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[11]),32);
    bufp->fullIData(oldp+551,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[12]),32);
    bufp->fullIData(oldp+552,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[13]),32);
    bufp->fullIData(oldp+553,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[14]),32);
    bufp->fullIData(oldp+554,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[15]),32);
    bufp->fullIData(oldp+555,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[16]),32);
    bufp->fullIData(oldp+556,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[17]),32);
    bufp->fullIData(oldp+557,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[18]),32);
    bufp->fullIData(oldp+558,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[19]),32);
    bufp->fullIData(oldp+559,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[20]),32);
    bufp->fullIData(oldp+560,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[21]),32);
    bufp->fullIData(oldp+561,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[22]),32);
    bufp->fullIData(oldp+562,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[23]),32);
    bufp->fullIData(oldp+563,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[24]),32);
    bufp->fullIData(oldp+564,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[25]),32);
    bufp->fullIData(oldp+565,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[26]),32);
    bufp->fullIData(oldp+566,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[27]),32);
    bufp->fullIData(oldp+567,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[28]),32);
    bufp->fullIData(oldp+568,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[29]),32);
    bufp->fullIData(oldp+569,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[30]),32);
    bufp->fullIData(oldp+570,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__BRAM[31]),32);
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
    bufp->fullBit(oldp+571,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check));
    bufp->fullBit(oldp+572,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check_delayed));
    bufp->fullBit(oldp+573,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__check_delayed_delayed));
    bufp->fullBit(oldp+574,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_sign));
    bufp->fullBit(oldp+575,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign));
    bufp->fullBit(oldp+576,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed));
    bufp->fullBit(oldp+577,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed_delayed));
    bufp->fullBit(oldp+578,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__sign_delayed_delayed_delayed));
    bufp->fullIData(oldp+579,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[0]),26);
    bufp->fullIData(oldp+580,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[1]),26);
    bufp->fullIData(oldp+581,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[2]),26);
    bufp->fullIData(oldp+582,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[3]),26);
    bufp->fullIData(oldp+583,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[4]),26);
    bufp->fullIData(oldp+584,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[5]),26);
    bufp->fullIData(oldp+585,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product_hold[6]),26);
    bufp->fullIData(oldp+586,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[0]),26);
    bufp->fullIData(oldp+587,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[1]),26);
    bufp->fullIData(oldp+588,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__val[2]),26);
    bufp->fullIData(oldp+589,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[0]),26);
    bufp->fullIData(oldp+590,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[1]),26);
    bufp->fullIData(oldp+591,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[2]),26);
    bufp->fullIData(oldp+592,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[3]),26);
    bufp->fullIData(oldp+593,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[4]),26);
    bufp->fullIData(oldp+594,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[5]),26);
    bufp->fullIData(oldp+595,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__partial_product[6]),26);
    bufp->fullCData(oldp+596,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[0]),3);
    bufp->fullCData(oldp+597,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[1]),3);
    bufp->fullCData(oldp+598,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[2]),3);
    bufp->fullCData(oldp+599,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[3]),3);
    bufp->fullCData(oldp+600,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[4]),3);
    bufp->fullCData(oldp+601,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[5]),3);
    bufp->fullCData(oldp+602,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__mul_mod[6]),3);
    bufp->fullCData(oldp+603,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zerocount),5);
    bufp->fullBit(oldp+604,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__comp));
    bufp->fullBit(oldp+605,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__magcheck));
    bufp->fullBit(oldp+606,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__zero));
    bufp->fullIData(oldp+607,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__C_Man),23);
    bufp->fullCData(oldp+608,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt1),4);
    bufp->fullCData(oldp+609,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt2),4);
    bufp->fullCData(oldp+610,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__stage_31__DOT__cnt3),4);
    bufp->fullCData(oldp+611,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount1),5);
    bufp->fullCData(oldp+612,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__zerocount2),5);
    bufp->fullCData(oldp+613,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt1),4);
    bufp->fullCData(oldp+614,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt2),4);
    bufp->fullCData(oldp+615,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_1__DOT__cnt3),4);
    bufp->fullCData(oldp+616,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt1),4);
    bufp->fullCData(oldp+617,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt2),4);
    bufp->fullCData(oldp+618,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__stage_31_2__DOT__cnt3),4);
    bufp->fullBit(oldp+619,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__busy));
    bufp->fullIData(oldp+620,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__quo_next),24);
    bufp->fullIData(oldp+621,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__acc_next),25);
    bufp->fullCData(oldp+622,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__i),6);
    bufp->fullCData(oldp+623,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ExpChoice1),8);
    bufp->fullCData(oldp+624,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__ExpChoice2),8);
    bufp->fullBit(oldp+625,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign));
    bufp->fullBit(oldp+626,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__signChoice));
    bufp->fullBit(oldp+627,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage1));
    bufp->fullBit(oldp+628,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage2));
    bufp->fullBit(oldp+629,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage3));
    bufp->fullBit(oldp+630,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage4));
    bufp->fullBit(oldp+631,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__valid_stage5));
    bufp->fullBit(oldp+632,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[0]));
    bufp->fullBit(oldp+633,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[1]));
    bufp->fullBit(oldp+634,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[2]));
    bufp->fullBit(oldp+635,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[3]));
    bufp->fullBit(oldp+636,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_sign[4]));
    bufp->fullCData(oldp+637,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[0]),8);
    bufp->fullCData(oldp+638,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[1]),8);
    bufp->fullCData(oldp+639,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[2]),8);
    bufp->fullCData(oldp+640,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[3]),8);
    bufp->fullCData(oldp+641,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__pipe_Exponent[4]),8);
    bufp->fullBit(oldp+642,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage
                            [8U]));
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
    bufp->fullBit(oldp+643,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[0]));
    bufp->fullBit(oldp+644,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[1]));
    bufp->fullBit(oldp+645,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[2]));
    bufp->fullBit(oldp+646,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[3]));
    bufp->fullBit(oldp+647,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[4]));
    bufp->fullBit(oldp+648,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[5]));
    bufp->fullBit(oldp+649,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[6]));
    bufp->fullBit(oldp+650,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[7]));
    bufp->fullBit(oldp+651,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__valid_stage[8]));
    bufp->fullBit(oldp+652,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[0]));
    bufp->fullBit(oldp+653,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[1]));
    bufp->fullBit(oldp+654,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[2]));
    bufp->fullBit(oldp+655,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[3]));
    bufp->fullBit(oldp+656,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[4]));
    bufp->fullBit(oldp+657,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[5]));
    bufp->fullBit(oldp+658,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[6]));
    bufp->fullBit(oldp+659,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[7]));
    bufp->fullBit(oldp+660,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[8]));
    bufp->fullBit(oldp+661,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[9]));
    bufp->fullBit(oldp+662,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[10]));
    bufp->fullBit(oldp+663,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[11]));
    bufp->fullBit(oldp+664,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[12]));
    bufp->fullBit(oldp+665,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[13]));
    bufp->fullBit(oldp+666,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[14]));
    bufp->fullBit(oldp+667,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[15]));
    bufp->fullBit(oldp+668,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[16]));
    bufp->fullBit(oldp+669,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[17]));
    bufp->fullBit(oldp+670,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[18]));
    bufp->fullBit(oldp+671,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[19]));
    bufp->fullBit(oldp+672,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[20]));
    bufp->fullBit(oldp+673,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[21]));
    bufp->fullBit(oldp+674,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[22]));
    bufp->fullBit(oldp+675,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[23]));
    bufp->fullBit(oldp+676,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[24]));
    bufp->fullBit(oldp+677,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage[25]));
    bufp->fullBit(oldp+678,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__valid_stage
                            [0U]));
    bufp->fullIData(oldp+679,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__coeff_data),32);
    bufp->fullIData(oldp+680,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in1),32);
    bufp->fullBit(oldp+681,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_sign));
    bufp->fullCData(oldp+682,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Exp),8);
    bufp->fullIData(oldp+683,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__A_Man),23);
    bufp->fullIData(oldp+684,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__add_in2),32);
    bufp->fullIData(oldp+685,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__B_Man),23);
    bufp->fullIData(oldp+686,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan),23);
    bufp->fullCData(oldp+687,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp),8);
    bufp->fullIData(oldp+688,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ManChoice1),23);
    bufp->fullCData(oldp+689,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ExpChoice1),8);
    bufp->fullCData(oldp+690,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ExpChoice2),8);
    bufp->fullBit(oldp+691,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__choice));
    bufp->fullIData(oldp+692,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__mul_in2),32);
    bufp->fullCData(oldp+693,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zerocount),5);
    bufp->fullCData(oldp+694,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt1),4);
    bufp->fullCData(oldp+695,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt2),4);
    bufp->fullCData(oldp+696,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__stage_31__DOT__cnt3),4);
    bufp->fullBit(oldp+697,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__lowest_valid));
    bufp->fullBit(oldp+698,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__second_valid));
    bufp->fullBit(oldp+699,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__third_valid));
    bufp->fullBit(oldp+700,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__final_valid));
    bufp->fullIData(oldp+701,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__ManChoice2),23);
    bufp->fullBit(oldp+702,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign));
    bufp->fullBit(oldp+703,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__signChoice));
    bufp->fullBit(oldp+704,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__comp));
    bufp->fullBit(oldp+705,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__magcheck));
    bufp->fullBit(oldp+706,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__zero));
    bufp->fullBit(oldp+707,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[0]));
    bufp->fullBit(oldp+708,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[1]));
    bufp->fullBit(oldp+709,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[2]));
    bufp->fullBit(oldp+710,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[3]));
    bufp->fullBit(oldp+711,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_sign[4]));
    bufp->fullCData(oldp+712,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[0]),8);
    bufp->fullCData(oldp+713,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[1]),8);
    bufp->fullCData(oldp+714,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[2]),8);
    bufp->fullCData(oldp+715,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[3]),8);
    bufp->fullCData(oldp+716,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__pipe_Exponent[4]),8);
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
    bufp->fullBit(oldp+717,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage
                            [8U]));
    bufp->fullBit(oldp+718,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[0]));
    bufp->fullBit(oldp+719,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[1]));
    bufp->fullBit(oldp+720,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[2]));
    bufp->fullBit(oldp+721,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[3]));
    bufp->fullBit(oldp+722,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[4]));
    bufp->fullBit(oldp+723,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[5]));
    bufp->fullBit(oldp+724,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[6]));
    bufp->fullBit(oldp+725,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[7]));
    bufp->fullBit(oldp+726,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__valid_stage[8]));
    bufp->fullBit(oldp+727,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__capture_valid));
    bufp->fullQData(oldp+728,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__Temp_Mantissa),48);
    bufp->fullIData(oldp+730,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3_stage1),26);
    bufp->fullIData(oldp+731,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3),25);
    bufp->fullQData(oldp+732,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__temp3_shifted),48);
    bufp->fullQData(oldp+734,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__partial_product),48);
    bufp->fullIData(oldp+736,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_raw),24);
    bufp->fullIData(oldp+737,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high),24);
    bufp->fullQData(oldp+738,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted),48);
    bufp->fullQData(oldp+740,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted1),48);
    bufp->fullQData(oldp+742,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_high_shifted2),48);
    bufp->fullIData(oldp+744,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__accum),24);
    bufp->fullIData(oldp+745,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_raw),24);
    bufp->fullIData(oldp+746,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_middle),26);
    bufp->fullIData(oldp+747,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low),24);
    bufp->fullIData(oldp+748,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low2),26);
    bufp->fullQData(oldp+749,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended),48);
    bufp->fullQData(oldp+751,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended1),48);
    bufp->fullQData(oldp+753,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__P_low_extended2),48);
    bufp->fullIData(oldp+755,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__accum),24);
    bufp->fullIData(oldp+756,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__accum),26);
    bufp->fullBit(oldp+757,(vlSelfRef.TB_gpnae__DOT__clk));
    bufp->fullBit(oldp+758,((1U & (~ ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__rd_en_signal) 
                                      | (IData)(vlSelfRef.TB_gpnae__DOT__wr_en_i))))));
    bufp->fullIData(oldp+759,(vlSelfRef.TB_gpnae__DOT__processed_signals),32);
    bufp->fullIData(oldp+760,(vlSelfRef.TB_gpnae__DOT__cycle_counter),32);
    bufp->fullCData(oldp+761,(vlSelfRef.TB_gpnae__DOT__current_state),2);
    bufp->fullIData(oldp+762,(vlSelfRef.TB_gpnae__DOT__current_phase),32);
    bufp->fullCData(oldp+763,(vlSelfRef.TB_gpnae__DOT__dut__DOT__next_state),3);
    bufp->fullBit(oldp+764,(vlSelfRef.TB_gpnae__DOT__dut__DOT__fsm_rd_en));
    bufp->fullBit(oldp+765,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_rd_en));
    bufp->fullIData(oldp+766,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__doutb_reg),32);
    bufp->fullIData(oldp+767,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_result),32);
    bufp->fullIData(oldp+768,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_result),32);
    bufp->fullIData(oldp+769,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateSign) 
                                << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateExp) 
                                              << 0x17U) 
                                             | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateMan))),32);
    bufp->fullBit(oldp+770,(vlSelfRef.TB_gpnae__DOT__dut__DOT__done_selu));
    bufp->fullBit(oldp+771,((1U & ((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg) 
                                   >> 4U))));
    bufp->fullBit(oldp+772,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_clk));
    bufp->fullBit(oldp+773,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_clk));
    bufp->fullBit(oldp+774,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_clk));
    bufp->fullBit(oldp+775,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_valid));
    bufp->fullIData(oldp+776,(vlSelfRef.TB_gpnae__DOT__dut__DOT__fifo_data_registered),32);
    bufp->fullIData(oldp+777,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_input),32);
    bufp->fullIData(oldp+778,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_const),32);
    bufp->fullCData(oldp+779,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__wr_ptr),5);
    bufp->fullCData(oldp+780,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr),5);
    bufp->fullBit(oldp+781,((1U & (vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__status 
                                   >> (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__rd_ptr)))));
    bufp->fullIData(oldp+782,(vlSelfRef.TB_gpnae__DOT__dut__DOT__input_fifo_inst__DOT__FIFO__DOT__ram_data_b),32);
    bufp->fullBit(oldp+783,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__rd_en_coeff));
    bufp->fullBit(oldp+784,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__add_valid));
    bufp->fullBit(oldp+785,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__mul_valid));
    bufp->fullCData(oldp+786,((0x1fU & ((1U & ((~ (IData)(vlSelfRef.TB_gpnae__DOT__rstn_i)) 
                                               | (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o)))
                                         ? (IData)(vlSelfRef.TB_gpnae__DOT__terms_i)
                                         : ((IData)(vlSelfRef.TB_gpnae__DOT__terms_i) 
                                            - (IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count))))),5);
    bufp->fullBit(oldp+787,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_reset_n));
    bufp->fullBit(oldp+788,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__reload_o));
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
    bufp->fullCData(oldp+789,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__next_state),4);
    bufp->fullCData(oldp+790,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count),5);
    bufp->fullCData(oldp+791,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__term_count_next),5);
    bufp->fullBit(oldp+792,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_comb));
    bufp->fullCData(oldp+793,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__controller_inst__DOT__done_shift_reg),5);
    bufp->fullIData(oldp+794,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__adder_result),32);
    bufp->fullIData(oldp+795,((((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateSign) 
                                << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateExp) 
                                              << 0x17U) 
                                             | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__intermediateMan))),32);
    bufp->fullBit(oldp+796,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Sign));
    bufp->fullCData(oldp+797,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Exponent),8);
    bufp->fullIData(oldp+798,(vlSelfRef.TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__ADD__DOT__Mantissa),23);
    bufp->fullIData(oldp+799,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign) 
                                << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent) 
                                              << 0x17U) 
                                             | vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa))),32);
    bufp->fullBit(oldp+800,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage6));
    bufp->fullBit(oldp+801,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__valid_multiply));
    bufp->fullIData(oldp+802,((((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateSign) 
                                << 0x1fU) | (((IData)(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateExp) 
                                              << 0x17U) 
                                             | vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__intermediateMan))),32);
    bufp->fullBit(oldp+803,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__clk_i));
    bufp->fullBit(oldp+804,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__fp32_down_inst__valid_i));
    bufp->fullBit(oldp+805,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Sign));
    bufp->fullCData(oldp+806,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Exponent),8);
    bufp->fullIData(oldp+807,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__Mantissa),23);
    bufp->fullBit(oldp+808,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__valid_stage1));
    bufp->fullBit(oldp+809,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT__fp32_down_inst__DOT__sign));
    bufp->fullIData(oldp+810,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__add_result),32);
    bufp->fullIData(oldp+811,((((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2) 
                                << 0x1fU) | (((IData)(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Exponent2) 
                                              << 0x17U) 
                                             | vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Mantissa2))),32);
    bufp->fullBit(oldp+812,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__valid_stage6));
    bufp->fullIData(oldp+813,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__mux_output),32);
    bufp->fullBit(oldp+814,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign1));
    bufp->fullBit(oldp+815,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__fp32_add_sub_inst__DOT__Sign2));
    bufp->fullCData(oldp+816,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Exponent),8);
    bufp->fullCData(oldp+817,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Exponent),8);
    bufp->fullBit(oldp+818,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__sign));
    bufp->fullCData(oldp+819,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__Temp_Exponent),8);
    bufp->fullIData(oldp+820,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateMan),23);
    bufp->fullCData(oldp+821,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateExp),8);
    bufp->fullBit(oldp+822,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__intermediateSign));
    bufp->fullBit(oldp+823,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__dbz));
    bufp->fullBit(oldp+824,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__capture_valid));
    bufp->fullCData(oldp+825,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__A_Exponent_reg),8);
    bufp->fullCData(oldp+826,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__B_Exponent_reg),8);
    bufp->fullBit(oldp+827,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__lowest_valid));
    bufp->fullBit(oldp+828,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__second_valid));
    bufp->fullBit(oldp+829,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__third_valid));
    bufp->fullBit(oldp+830,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__final_valid));
    bufp->fullCData(oldp+831,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__lowest_diff),3);
    bufp->fullCData(oldp+832,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__second_diff),3);
    bufp->fullCData(oldp+833,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__third_diff),3);
    bufp->fullCData(oldp+834,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__final_diff),5);
    bufp->fullIData(oldp+835,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__divu_mantissa__DOT__b1),24);
    bufp->fullIData(oldp+836,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+837,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+838,(vlSelfRef.TB_gpnae__DOT__dut__DOT__sigtan_inst__DOT__u_divide_32__DOT__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+839,(vlSelfRef.TB_gpnae__DOT__dut__DOT__selu_inst__DOT____Vcellinp__multiply_32_inst__A),32);
    bufp->fullIData(oldp+840,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Mantissa),24);
    bufp->fullIData(oldp+841,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Mantissa),24);
    bufp->fullCData(oldp+842,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__A_Exponent),8);
    bufp->fullCData(oldp+843,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__B_Exponent),8);
    bufp->fullQData(oldp+844,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__Temp_Mantissa),48);
    bufp->fullQData(oldp+846,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__partial_product),48);
    bufp->fullIData(oldp+848,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult1__DOT__i),32);
    bufp->fullIData(oldp+849,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult2__DOT__i),32);
    bufp->fullIData(oldp+850,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__karatsuba__DOT__booth_mult3__DOT__i),32);
    bufp->fullIData(oldp+851,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+852,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+853,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__PVT__unnamedblk3__DOT__i),32);
    bufp->fullIData(oldp+854,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__A_Mantissa),24);
    bufp->fullIData(oldp+855,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__B_Mantissa),24);
    bufp->fullIData(oldp+856,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult1__DOT__i),32);
    bufp->fullIData(oldp+857,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult2__DOT__i),32);
    bufp->fullIData(oldp+858,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__karatsuba__DOT__booth_mult3__DOT__i),32);
    bufp->fullIData(oldp+859,(vlSymsp->TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__PVT__unnamedblk3__DOT__i),32);
}
