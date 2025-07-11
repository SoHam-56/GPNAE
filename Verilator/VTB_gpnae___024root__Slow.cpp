// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae__Syms.h"
#include "VTB_gpnae___024root.h"

void VTB_gpnae___024root___ctor_var_reset(VTB_gpnae___024root* vlSelf);

VTB_gpnae___024root::VTB_gpnae___024root(VTB_gpnae__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , __Vm_mtaskstate_123(3U)
    , __Vm_mtaskstate_125(1U)
    , __Vm_mtaskstate_137(1U)
    , __Vm_mtaskstate_150(6U)
    , __Vm_mtaskstate_88(2U)
    , __Vm_mtaskstate_112(3U)
    , __Vm_mtaskstate_142(3U)
    , __Vm_mtaskstate_151(5U)
    , __Vm_mtaskstate_75(2U)
    , __Vm_mtaskstate_154(2U)
    , __Vm_mtaskstate_147(3U)
    , __Vm_mtaskstate_81(1U)
    , __Vm_mtaskstate_138(4U)
    , __Vm_mtaskstate_74(1U)
    , __Vm_mtaskstate_119(1U)
    , __Vm_mtaskstate_87(2U)
    , __Vm_mtaskstate_107(1U)
    , __Vm_mtaskstate_82(1U)
    , __Vm_mtaskstate_65(1U)
    , __Vm_mtaskstate_73(1U)
    , __Vm_mtaskstate_133(2U)
    , __Vm_mtaskstate_136(1U)
    , __Vm_mtaskstate_105(1U)
    , __Vm_mtaskstate_53(0x10U)
    , __Vm_mtaskstate_134(1U)
    , __Vm_mtaskstate_120(2U)
    , __Vm_mtaskstate_121(2U)
    , __Vm_mtaskstate_126(1U)
    , __Vm_mtaskstate_68(3U)
    , __Vm_mtaskstate_143(3U)
    , __Vm_mtaskstate_149(1U)
    , __Vm_mtaskstate_135(2U)
    , __Vm_mtaskstate_101(2U)
    , __Vm_mtaskstate_110(1U)
    , __Vm_mtaskstate_116(1U)
    , __Vm_mtaskstate_153(5U)
    , __Vm_mtaskstate_106(1U)
    , __Vm_mtaskstate_83(1U)
    , __Vm_mtaskstate_80(2U)
    , __Vm_mtaskstate_92(1U)
    , __Vm_mtaskstate_129(5U)
    , __Vm_mtaskstate_140(3U)
    , __Vm_mtaskstate_55(0x16U)
    , __Vm_mtaskstate_128(1U)
    , __Vm_mtaskstate_77(2U)
    , __Vm_mtaskstate_155(3U)
    , __Vm_mtaskstate_124(4U)
    , __Vm_mtaskstate_144(1U)
    , __Vm_mtaskstate_130(1U)
    , __Vm_mtaskstate_152(1U)
    , __Vm_mtaskstate_76(1U)
    , __Vm_mtaskstate_127(1U)
    , __Vm_mtaskstate_71(1U)
    , __Vm_mtaskstate_100(2U)
    , __Vm_mtaskstate_93(3U)
    , __Vm_mtaskstate_118(1U)
    , __Vm_mtaskstate_102(3U)
    , __Vm_mtaskstate_148(3U)
    , __Vm_mtaskstate_146(3U)
    , __Vm_mtaskstate_103(1U)
    , __Vm_mtaskstate_94(4U)
    , __Vm_mtaskstate_145(3U)
    , __Vm_mtaskstate_139(3U)
    , __Vm_mtaskstate_132(5U)
    , __Vm_mtaskstate_141(7U)
    , __Vm_mtaskstate_156(3U)
    , __Vm_mtaskstate_final__0nba(0xcU)
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTB_gpnae___024root___ctor_var_reset(this);
}

void VTB_gpnae___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTB_gpnae___024root::~VTB_gpnae___024root() {
}
