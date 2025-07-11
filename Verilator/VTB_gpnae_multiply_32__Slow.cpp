// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTB_gpnae.h for the primary calling header

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae__Syms.h"
#include "VTB_gpnae_multiply_32.h"

void VTB_gpnae_multiply_32___ctor_var_reset(VTB_gpnae_multiply_32* vlSelf);

VTB_gpnae_multiply_32::VTB_gpnae_multiply_32(VTB_gpnae__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTB_gpnae_multiply_32___ctor_var_reset(this);
}

void VTB_gpnae_multiply_32::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTB_gpnae_multiply_32::~VTB_gpnae_multiply_32() {
}
