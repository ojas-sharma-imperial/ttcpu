// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->testing__DOT__ui_in),8);
        bufp->chgCData(oldp+1,(vlSelf->testing__DOT__uo_out),8);
        bufp->chgCData(oldp+2,(vlSelf->testing__DOT__uio_in),8);
        bufp->chgCData(oldp+3,(vlSelf->testing__DOT__uio_out),8);
        bufp->chgCData(oldp+4,(vlSelf->testing__DOT__ram_addr),5);
        bufp->chgCData(oldp+5,(vlSelf->testing__DOT__main_cpu__DOT__memaddr),5);
        bufp->chgCData(oldp+6,((0xfU & (IData)(vlSelf->testing__DOT__uio_in))),4);
        bufp->chgCData(oldp+7,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu),4);
        bufp->chgBit(oldp+8,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memstr));
        bufp->chgBit(oldp+9,((1U & ((7U == (7U & (IData)(vlSelf->testing__DOT__ui_in)))
                                     ? ((0x40U & (IData)(vlSelf->testing__DOT__ui_in))
                                         ? ((0x10U 
                                             & (IData)(vlSelf->testing__DOT__ui_in))
                                             ? ((8U 
                                                 & (IData)(vlSelf->testing__DOT__ui_in))
                                                 ? 
                                                ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 1U)
                                                 : 
                                                ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 1U))
                                             : ((8U 
                                                 & (IData)(vlSelf->testing__DOT__ui_in))
                                                 ? 
                                                ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 1U)
                                                 : 
                                                ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 3U)))
                                         : (((IData)(vlSelf->testing__DOT__ui_in) 
                                             >> 5U) 
                                            & ((0x10U 
                                                & (IData)(vlSelf->testing__DOT__ui_in))
                                                ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->testing__DOT__ui_in))
                                                    ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                    : 
                                                   ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                    >> 3U)))))
                                     : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout)))));
        bufp->chgBit(oldp+10,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__flagztocp));
        bufp->chgBit(oldp+11,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_taken));
        bufp->chgCData(oldp+12,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination),6);
        bufp->chgBit(oldp+13,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jsr));
        bufp->chgBit(oldp+14,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jumpen));
        bufp->chgBit(oldp+15,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagcwen));
        bufp->chgBit(oldp+16,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagzwen));
        bufp->chgCData(oldp+17,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                       >> 4U))),2);
        bufp->chgBit(oldp+18,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                     >> 3U))));
        bufp->chgCData(oldp+19,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                       >> 1U))),2);
        bufp->chgCData(oldp+20,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                       >> 6U))),2);
        bufp->chgCData(oldp+21,((7U & (IData)(vlSelf->testing__DOT__ui_in))),3);
        bufp->chgCData(oldp+22,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                       >> 5U))),4);
        bufp->chgCData(oldp+23,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset),6);
        bufp->chgCData(oldp+24,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_reg),6);
        bufp->chgBit(oldp+25,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile));
        bufp->chgBit(oldp+26,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                     >> 4U))));
        bufp->chgBit(oldp+27,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile));
        bufp->chgCData(oldp+28,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu),4);
        bufp->chgCData(oldp+29,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__regfiledin),4);
        bufp->chgCData(oldp+30,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__general_data),4);
        bufp->chgCData(oldp+31,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aludout),4);
        bufp->chgCData(oldp+32,((0xfU & ((IData)(vlSelf->testing__DOT__ui_in) 
                                         >> 3U))),4);
        bufp->chgCData(oldp+33,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                       >> 5U))),2);
        bufp->chgCData(oldp+34,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                       >> 3U))),2);
        bufp->chgBit(oldp+35,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                     >> 5U))));
        bufp->chgBit(oldp+36,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aluen));
        bufp->chgBit(oldp+37,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__shiften));
        bufp->chgBit(oldp+38,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__extenden));
        bufp->chgBit(oldp+39,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel));
        bufp->chgBit(oldp+40,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__jumpen));
        bufp->chgBit(oldp+41,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memldr));
        bufp->chgBit(oldp+42,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__inverttoaddsub));
        bufp->chgBit(oldp+43,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__cintoaddsub));
        bufp->chgCData(oldp+44,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput),4);
        bufp->chgCData(oldp+45,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout),4);
        bufp->chgBit(oldp+46,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout));
        bufp->chgCData(oldp+47,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout),4);
        bufp->chgBit(oldp+48,((1U & ((0x40U & (IData)(vlSelf->testing__DOT__ui_in))
                                      ? ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))
                                          ? ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                              ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 1U)
                                              : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 1U))
                                          : ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                              ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 1U)
                                              : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                 >> 3U)))
                                      : (((IData)(vlSelf->testing__DOT__ui_in) 
                                          >> 5U) & 
                                         ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))
                                           ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                           : ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                               ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                               : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                  >> 3U))))))));
        bufp->chgCData(oldp+49,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data),4);
        bufp->chgBit(oldp+50,((1U & (((IData)(vlSelf->testing__DOT__ui_in) 
                                      >> 5U) & ((0x10U 
                                                 & (IData)(vlSelf->testing__DOT__ui_in))
                                                 ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                 : 
                                                ((8U 
                                                  & (IData)(vlSelf->testing__DOT__ui_in))
                                                  ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                  : 
                                                 ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                  >> 3U)))))));
        bufp->chgBit(oldp+51,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                     >> 5U))));
        bufp->chgCData(oldp+52,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp),4);
        bufp->chgBit(oldp+53,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                     >> 6U))));
        bufp->chgCData(oldp+54,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp),4);
        bufp->chgCData(oldp+55,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__secondinput),4);
        bufp->chgCData(oldp+56,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__adderout),5);
        bufp->chgCData(oldp+57,((0xfU & (IData)(vlSelf->testing__DOT__uio_out))),4);
        bufp->chgBit(oldp+58,((1U & ((IData)(vlSelf->testing__DOT__uo_out) 
                                     >> 7U))));
        bufp->chgCData(oldp+59,((0x3fU & (IData)(vlSelf->testing__DOT__uo_out))),6);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+60,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc),6);
        bufp->chgBit(oldp+61,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc));
        bufp->chgCData(oldp+62,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX),2);
        bufp->chgBit(oldp+63,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz));
        bufp->chgCData(oldp+64,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pcx),6);
        bufp->chgBit(oldp+65,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__extactive));
        bufp->chgCData(oldp+66,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA),4);
        bufp->chgCData(oldp+67,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB),4);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+68,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[0]),4);
        bufp->chgCData(oldp+69,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[1]),4);
        bufp->chgCData(oldp+70,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[2]),4);
        bufp->chgCData(oldp+71,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[3]),4);
        bufp->chgCData(oldp+72,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[4]),4);
        bufp->chgCData(oldp+73,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[5]),4);
        bufp->chgCData(oldp+74,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[6]),4);
        bufp->chgCData(oldp+75,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[7]),4);
        bufp->chgCData(oldp+76,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[8]),4);
        bufp->chgCData(oldp+77,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[9]),4);
        bufp->chgCData(oldp+78,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[10]),4);
        bufp->chgCData(oldp+79,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[11]),4);
        bufp->chgCData(oldp+80,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[12]),4);
        bufp->chgCData(oldp+81,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[13]),4);
        bufp->chgCData(oldp+82,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[14]),4);
        bufp->chgCData(oldp+83,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[15]),4);
        bufp->chgCData(oldp+84,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[16]),4);
        bufp->chgCData(oldp+85,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[17]),4);
        bufp->chgCData(oldp+86,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[18]),4);
        bufp->chgCData(oldp+87,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[19]),4);
        bufp->chgCData(oldp+88,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[20]),4);
        bufp->chgCData(oldp+89,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[21]),4);
        bufp->chgCData(oldp+90,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[22]),4);
        bufp->chgCData(oldp+91,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[23]),4);
        bufp->chgCData(oldp+92,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[24]),4);
        bufp->chgCData(oldp+93,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[25]),4);
        bufp->chgCData(oldp+94,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[26]),4);
        bufp->chgCData(oldp+95,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[27]),4);
        bufp->chgCData(oldp+96,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[28]),4);
        bufp->chgCData(oldp+97,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[29]),4);
        bufp->chgCData(oldp+98,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[30]),4);
        bufp->chgCData(oldp+99,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[31]),4);
        bufp->chgIData(oldp+100,(vlSelf->testing__DOT__main_memory__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+101,(vlSelf->clk));
    bufp->chgBit(oldp+102,(vlSelf->reset));
    bufp->chgCData(oldp+103,(vlSelf->uio_oe),8);
    bufp->chgBit(oldp+104,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->chgCData(oldp+105,(vlSelf->testing__DOT__main_memory__DOT__ram_mem
                             [vlSelf->testing__DOT__ram_addr]),4);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
