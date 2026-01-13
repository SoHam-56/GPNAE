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
    , __Vm_mtaskstate_78(1U)
    , __Vm_mtaskstate_103(1U)
    , __Vm_mtaskstate_112(1U)
    , __Vm_mtaskstate_124(3U)
    , __Vm_mtaskstate_122(3U)
    , __Vm_mtaskstate_70(1U)
    , __Vm_mtaskstate_77(1U)
    , __Vm_mtaskstate_116(3U)
    , __Vm_mtaskstate_46(2U)
    , __Vm_mtaskstate_51(2U)
    , __Vm_mtaskstate_118(2U)
    , __Vm_mtaskstate_113(1U)
    , __Vm_mtaskstate_98(1U)
    , __Vm_mtaskstate_117(6U)
    , __Vm_mtaskstate_114(5U)
    , __Vm_mtaskstate_58(2U)
    , __Vm_mtaskstate_65(1U)
    , __Vm_mtaskstate_75(1U)
    , __Vm_mtaskstate_81(1U)
    , __Vm_mtaskstate_86(1U)
    , __Vm_mtaskstate_120(6U)
    , __Vm_mtaskstate_56(2U)
    , __Vm_mtaskstate_35(0x17U)
    , __Vm_mtaskstate_49(2U)
    , __Vm_mtaskstate_52(2U)
    , __Vm_mtaskstate_91(3U)
    , __Vm_mtaskstate_72(1U)
    , __Vm_mtaskstate_104(1U)
    , __Vm_mtaskstate_109(6U)
    , __Vm_mtaskstate_92(2U)
    , __Vm_mtaskstate_50(2U)
    , __Vm_mtaskstate_105(6U)
    , __Vm_mtaskstate_101(2U)
    , __Vm_mtaskstate_99(2U)
    , __Vm_mtaskstate_44(1U)
    , __Vm_mtaskstate_127(4U)
    , __Vm_mtaskstate_125(3U)
    , __Vm_mtaskstate_57(2U)
    , __Vm_mtaskstate_48(1U)
    , __Vm_mtaskstate_115(2U)
    , __Vm_mtaskstate_97(3U)
    , __Vm_mtaskstate_126(3U)
    , __Vm_mtaskstate_53(1U)
    , __Vm_mtaskstate_100(1U)
    , __Vm_mtaskstate_90(2U)
    , __Vm_mtaskstate_129(4U)
    , __Vm_mtaskstate_123(4U)
    , __Vm_mtaskstate_106(3U)
    , __Vm_mtaskstate_111(1U)
    , __Vm_mtaskstate_121(4U)
    , __Vm_mtaskstate_34(5U)
    , __Vm_mtaskstate_108(2U)
    , __Vm_mtaskstate_88(1U)
    , __Vm_mtaskstate_107(4U)
    , __Vm_mtaskstate_110(1U)
    , __Vm_mtaskstate_128(3U)
    , __Vm_mtaskstate_93(4U)
    , __Vm_mtaskstate_96(3U)
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
