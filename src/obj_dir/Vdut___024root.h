// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(uio_oe,7,0);
    CData/*7:0*/ testing__DOT__ui_in;
    CData/*7:0*/ testing__DOT__uo_out;
    CData/*7:0*/ testing__DOT__uio_in;
    CData/*7:0*/ testing__DOT__uio_out;
    CData/*4:0*/ testing__DOT__ram_addr;
    CData/*4:0*/ testing__DOT__main_cpu__DOT__memaddr;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__flagztocp;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__regfiledin;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__general_data;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aludout;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aluen;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__shiften;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__extenden;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__jumpen;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memldr;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memstr;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__inverttoaddsub;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__cintoaddsub;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__secondinput;
    CData/*4:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__adderout;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp;
    CData/*3:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp;
    CData/*1:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__extactive;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz;
    CData/*5:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc;
    CData/*5:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pcx;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_taken;
    CData/*5:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jsr;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jumpen;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagcwen;
    CData/*0:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagzwen;
    CData/*5:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset;
    CData/*5:0*/ testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_reg;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*7:0*/ __Vchglast__TOP__testing__DOT__uo_out;
    CData/*3:0*/ __Vchglast__TOP__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput;
    IData/*31:0*/ testing__DOT__main_memory__DOT__unnamedblk1__DOT__i;
    VlUnpacked<CData/*3:0*/, 32> testing__DOT__main_memory__DOT__ram_mem;
    VlUnpacked<CData/*7:0*/, 64> testing__DOT__main_memory__DOT__rom_mem;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
