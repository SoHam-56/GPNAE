// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTB_gpnae__pch.h"
#include "VTB_gpnae.h"
#include "VTB_gpnae___024root.h"
#include "VTB_gpnae_multiply_32.h"

// FUNCTIONS
VTB_gpnae__Syms::~VTB_gpnae__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void VTB_gpnae__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void VTB_gpnae__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void VTB_gpnae__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

VTB_gpnae__Syms::VTB_gpnae__Syms(VerilatedContext* contextp, const char* namep, VTB_gpnae* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_threadPoolp{static_cast<VlThreadPool*>(contextp->threadPoolp())}
    // Setup module instances
    , TOP{this, namep}
    , TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL{this, Verilated::catName(namep, "TB_gpnae.dut.mac_inst.datapath_inst.MUL")}
    , TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst{this, Verilated::catName(namep, "TB_gpnae.dut.selu_inst.multiply_32_inst")}
{
        // Check resources
        Verilated::stackCheck(448);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL = &TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL;
    TOP.__PVT__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst = &TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__TB_gpnae__DOT__dut__DOT__mac_inst__DOT__datapath_inst__DOT__MUL.__Vconfigure(true);
    TOP__TB_gpnae__DOT__dut__DOT__selu_inst__DOT__multiply_32_inst.__Vconfigure(false);
}
