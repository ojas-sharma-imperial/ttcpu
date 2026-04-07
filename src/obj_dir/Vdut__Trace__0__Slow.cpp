// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBus(c+105,"uio_oe", false,-1, 7,0);
    tracep->pushNamePrefix("testing ");
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBus(c+105,"uio_oe", false,-1, 7,0);
    tracep->declBus(c+1,"ui_in", false,-1, 7,0);
    tracep->declBus(c+2,"uo_out", false,-1, 7,0);
    tracep->declBus(c+3,"uio_in", false,-1, 7,0);
    tracep->declBus(c+4,"uio_out", false,-1, 7,0);
    tracep->declBus(c+5,"ram_addr", false,-1, 4,0);
    tracep->pushNamePrefix("main_cpu ");
    tracep->declBus(c+1,"ui_in", false,-1, 7,0);
    tracep->declBus(c+2,"uo_out", false,-1, 7,0);
    tracep->declBus(c+3,"uio_in", false,-1, 7,0);
    tracep->declBus(c+4,"uio_out", false,-1, 7,0);
    tracep->declBus(c+105,"uio_oe", false,-1, 7,0);
    tracep->declBit(c+108,"ena", false,-1);
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+106,"rst_n", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBus(c+6,"memaddr", false,-1, 4,0);
    tracep->pushNamePrefix("main_cpu ");
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBus(c+7,"memdin", false,-1, 3,0);
    tracep->declBus(c+6,"memaddr", false,-1, 4,0);
    tracep->declBus(c+8,"memdout", false,-1, 3,0);
    tracep->declBit(c+9,"memwen", false,-1);
    tracep->declBus(c+1,"romdin", false,-1, 7,0);
    tracep->declBus(c+62,"romaddr", false,-1, 5,0);
    tracep->declBus(c+1,"instruction", false,-1, 7,0);
    tracep->declBit(c+10,"flagctocp", false,-1);
    tracep->declBit(c+11,"flagztocp", false,-1);
    tracep->declBit(c+63,"flagctoalu", false,-1);
    tracep->declBus(c+64,"address_extension", false,-1, 1,0);
    tracep->declBus(c+8,"Ratocp", false,-1, 3,0);
    tracep->declBit(c+65,"extactive", false,-1);
    tracep->pushNamePrefix("main_controlpath ");
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBit(c+11,"flagzin", false,-1);
    tracep->declBit(c+10,"flagcin", false,-1);
    tracep->declBus(c+8,"Ra", false,-1, 3,0);
    tracep->declBus(c+64,"addr_extension", false,-1, 1,0);
    tracep->declBus(c+1,"romdin", false,-1, 7,0);
    tracep->declBit(c+65,"extactive", false,-1);
    tracep->declBus(c+62,"romaddr", false,-1, 5,0);
    tracep->declBus(c+1,"instruction", false,-1, 7,0);
    tracep->declBit(c+63,"flagcout", false,-1);
    tracep->declBit(c+63,"flagc", false,-1);
    tracep->declBit(c+66,"flagz", false,-1);
    tracep->declBus(c+62,"pc", false,-1, 5,0);
    tracep->declBus(c+67,"pcx", false,-1, 5,0);
    tracep->declBit(c+12,"jump_taken", false,-1);
    tracep->declBus(c+13,"destination", false,-1, 5,0);
    tracep->declBit(c+14,"saveaddress", false,-1);
    tracep->declBit(c+15,"jumpen", false,-1);
    tracep->declBit(c+16,"flagcwen", false,-1);
    tracep->declBit(c+17,"flagzwen", false,-1);
    tracep->declBus(c+18,"immc2", false,-1, 1,0);
    tracep->declBit(c+19,"jumpinv", false,-1);
    tracep->declBus(c+20,"jumpopc", false,-1, 1,0);
    tracep->pushNamePrefix("controlpath_decode ");
    tracep->declBus(c+1,"instruction", false,-1, 7,0);
    tracep->declBit(c+15,"jumpen", false,-1);
    tracep->declBit(c+16,"flagcwen", false,-1);
    tracep->declBit(c+17,"flagzwen", false,-1);
    tracep->declBus(c+18,"immc2", false,-1, 1,0);
    tracep->declBit(c+19,"jumpinv", false,-1);
    tracep->declBus(c+20,"jumpopc", false,-1, 1,0);
    tracep->declBus(c+21,"sectionopc", false,-1, 1,0);
    tracep->declBus(c+22,"aluopc", false,-1, 2,0);
    tracep->declBus(c+23,"Ra", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("jump_conditions ");
    tracep->declBit(c+66,"flagz", false,-1);
    tracep->declBit(c+63,"flagc", false,-1);
    tracep->declBit(c+15,"jumpen", false,-1);
    tracep->declBus(c+20,"jumpopc", false,-1, 1,0);
    tracep->declBit(c+19,"jumpinv", false,-1);
    tracep->declBus(c+18,"immc2", false,-1, 1,0);
    tracep->declBus(c+8,"Ra", false,-1, 3,0);
    tracep->declBus(c+64,"addr_extension", false,-1, 1,0);
    tracep->declBus(c+62,"pcin", false,-1, 5,0);
    tracep->declBus(c+67,"pcxin", false,-1, 5,0);
    tracep->declBit(c+24,"extended_select", false,-1);
    tracep->declBit(c+65,"extend_active", false,-1);
    tracep->declBit(c+12,"jump", false,-1);
    tracep->declBus(c+13,"destination", false,-1, 5,0);
    tracep->declBit(c+14,"saveadress", false,-1);
    tracep->declBus(c+25,"offset", false,-1, 5,0);
    tracep->declBus(c+26,"extended_reg", false,-1, 5,0);
    tracep->declBus(c+27,"extended_offset", false,-1, 5,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("main_datapath ");
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBus(c+1,"instruction", false,-1, 7,0);
    tracep->declBit(c+63,"flagcin", false,-1);
    tracep->declBit(c+10,"flagc", false,-1);
    tracep->declBit(c+11,"flagz", false,-1);
    tracep->declBit(c+9,"memwen", false,-1);
    tracep->declBus(c+64,"addr_extension", false,-1, 1,0);
    tracep->declBus(c+6,"memaddr", false,-1, 4,0);
    tracep->declBus(c+7,"memdin", false,-1, 3,0);
    tracep->declBus(c+8,"memdout", false,-1, 3,0);
    tracep->declBus(c+8,"Raout", false,-1, 3,0);
    tracep->declBit(c+65,"extactive", false,-1);
    tracep->declBit(c+28,"ad1toregfile", false,-1);
    tracep->declBit(c+24,"ad2toregfile", false,-1);
    tracep->declBit(c+29,"wen1toregfile", false,-1);
    tracep->declBus(c+8,"din1toalu", false,-1, 3,0);
    tracep->declBus(c+30,"din2toalu", false,-1, 3,0);
    tracep->declBus(c+31,"regfiledin", false,-1, 3,0);
    tracep->declBus(c+32,"general_data", false,-1, 3,0);
    tracep->declBus(c+33,"aludout", false,-1, 3,0);
    tracep->declBus(c+21,"sectionopc", false,-1, 1,0);
    tracep->declBus(c+22,"aluopc", false,-1, 2,0);
    tracep->declBus(c+34,"imms4", false,-1, 3,0);
    tracep->declBus(c+35,"shiftcount", false,-1, 1,0);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBit(c+37,"imm1", false,-1);
    tracep->declBus(c+36,"imm2", false,-1, 1,0);
    tracep->declBus(c+18,"immc2", false,-1, 1,0);
    tracep->declBit(c+19,"jumpinv", false,-1);
    tracep->declBus(c+20,"jumpopc", false,-1, 1,0);
    tracep->declBit(c+38,"aluen", false,-1);
    tracep->declBit(c+39,"shiften", false,-1);
    tracep->declBit(c+40,"extenden", false,-1);
    tracep->declBit(c+41,"op2sel", false,-1);
    tracep->declBit(c+42,"jumpen", false,-1);
    tracep->declBit(c+43,"memldr", false,-1);
    tracep->declBit(c+9,"memstr", false,-1);
    tracep->pushNamePrefix("addr_ext ");
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBit(c+40,"extenden", false,-1);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBus(c+8,"Ra", false,-1, 3,0);
    tracep->declBit(c+37,"imm1", false,-1);
    tracep->declBus(c+18,"imm2", false,-1, 1,0);
    tracep->declBus(c+64,"extension", false,-1, 1,0);
    tracep->declBit(c+65,"extactive", false,-1);
    tracep->declBus(c+64,"regX", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("datapath_decode ");
    tracep->declBus(c+1,"instruction", false,-1, 7,0);
    tracep->declBus(c+21,"sectionopc", false,-1, 1,0);
    tracep->declBus(c+22,"aluopc", false,-1, 2,0);
    tracep->declBus(c+34,"imms4", false,-1, 3,0);
    tracep->declBus(c+35,"shiftcount", false,-1, 1,0);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBit(c+28,"Ra", false,-1);
    tracep->declBit(c+24,"Rb", false,-1);
    tracep->declBit(c+37,"imm1", false,-1);
    tracep->declBus(c+36,"imm2", false,-1, 1,0);
    tracep->declBus(c+18,"immc2", false,-1, 1,0);
    tracep->declBit(c+19,"jumpinv", false,-1);
    tracep->declBus(c+20,"jumpopc", false,-1, 1,0);
    tracep->declBit(c+38,"aluen", false,-1);
    tracep->declBit(c+39,"shiften", false,-1);
    tracep->declBit(c+40,"extenden", false,-1);
    tracep->declBit(c+29,"wen1", false,-1);
    tracep->declBit(c+41,"op2sel", false,-1);
    tracep->declBit(c+42,"jumpen", false,-1);
    tracep->declBit(c+43,"memldr", false,-1);
    tracep->declBit(c+9,"memstr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("main_alu ");
    tracep->declBus(c+8,"Ra", false,-1, 3,0);
    tracep->declBus(c+30,"Rb", false,-1, 3,0);
    tracep->declBus(c+34,"imms4", false,-1, 3,0);
    tracep->declBus(c+22,"aluopc", false,-1, 2,0);
    tracep->declBus(c+35,"shiftcount", false,-1, 1,0);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBit(c+41,"op2sel", false,-1);
    tracep->declBit(c+63,"flagcin", false,-1);
    tracep->declBus(c+33,"out", false,-1, 3,0);
    tracep->declBit(c+10,"flagc", false,-1);
    tracep->declBit(c+44,"inverttoaddsub", false,-1);
    tracep->declBit(c+45,"cintoaddsub", false,-1);
    tracep->declBus(c+46,"secondinput", false,-1, 3,0);
    tracep->declBus(c+47,"addsubdout", false,-1, 3,0);
    tracep->declBit(c+48,"addsubcout", false,-1);
    tracep->declBus(c+49,"shiftdout", false,-1, 3,0);
    tracep->declBit(c+50,"shiftcout", false,-1);
    tracep->pushNamePrefix("decoder ");
    tracep->declBit(c+63,"flagcin", false,-1);
    tracep->declBus(c+22,"aluopc", false,-1, 2,0);
    tracep->declBit(c+44,"invert", false,-1);
    tracep->declBit(c+45,"addsubcin", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mainShifter ");
    tracep->declBus(c+35,"shiftcount", false,-1, 1,0);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBus(c+30,"din", false,-1, 3,0);
    tracep->declBit(c+63,"shiftin", false,-1);
    tracep->declBus(c+49,"dout", false,-1, 3,0);
    tracep->declBit(c+50,"shiftout", false,-1);
    tracep->declBus(c+51,"shift1toshift2data", false,-1, 3,0);
    tracep->declBit(c+52,"shift1toshift2out", false,-1);
    tracep->pushNamePrefix("shift_1 ");
    tracep->declBus(c+109,"SHIFT_COUNT", false,-1, 31,0);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBus(c+30,"din", false,-1, 3,0);
    tracep->declBit(c+63,"shiftin", false,-1);
    tracep->declBit(c+110,"shiftinc", false,-1);
    tracep->declBit(c+53,"en", false,-1);
    tracep->declBus(c+51,"dout", false,-1, 3,0);
    tracep->declBit(c+52,"shiftoutc", false,-1);
    tracep->declBus(c+54,"temp", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift_2 ");
    tracep->declBus(c+111,"SHIFT_COUNT", false,-1, 31,0);
    tracep->declBus(c+36,"shiftopc", false,-1, 1,0);
    tracep->declBus(c+51,"din", false,-1, 3,0);
    tracep->declBit(c+63,"shiftin", false,-1);
    tracep->declBit(c+52,"shiftinc", false,-1);
    tracep->declBit(c+55,"en", false,-1);
    tracep->declBus(c+49,"dout", false,-1, 3,0);
    tracep->declBit(c+50,"shiftoutc", false,-1);
    tracep->declBus(c+56,"temp", false,-1, 3,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("main_adder ");
    tracep->declBus(c+8,"din1", false,-1, 3,0);
    tracep->declBus(c+46,"din2", false,-1, 3,0);
    tracep->declBit(c+45,"carryin", false,-1);
    tracep->declBit(c+44,"invert", false,-1);
    tracep->declBus(c+47,"dout", false,-1, 3,0);
    tracep->declBit(c+48,"carryout", false,-1);
    tracep->declBus(c+57,"secondinput", false,-1, 3,0);
    tracep->declBus(c+58,"adderout", false,-1, 4,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("main_registers ");
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBit(c+28,"ad1", false,-1);
    tracep->declBit(c+24,"ad2", false,-1);
    tracep->declBit(c+29,"wen1", false,-1);
    tracep->declBus(c+31,"din1", false,-1, 3,0);
    tracep->declBus(c+8,"dout1", false,-1, 3,0);
    tracep->declBus(c+30,"dout2", false,-1, 3,0);
    tracep->declBus(c+68,"regA", false,-1, 3,0);
    tracep->declBus(c+69,"regB", false,-1, 3,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("main_memory ");
    tracep->declArray(c+112,"ROM_INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+103,"clk", false,-1);
    tracep->declBit(c+104,"reset", false,-1);
    tracep->declBus(c+5,"ram_addr", false,-1, 4,0);
    tracep->declBus(c+59,"ram_data_in", false,-1, 3,0);
    tracep->declBit(c+60,"WEN", false,-1);
    tracep->declBus(c+107,"ram_data_out", false,-1, 3,0);
    tracep->declBus(c+61,"rom_addr", false,-1, 5,0);
    tracep->declBus(c+1,"rom_data_out", false,-1, 7,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+70+i*1,"ram_mem", true,(i+0), 3,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+102,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_hd2c9f1e7__0;
    // Body
    bufp->fullCData(oldp+1,(vlSelf->testing__DOT__ui_in),8);
    bufp->fullCData(oldp+2,(vlSelf->testing__DOT__uo_out),8);
    bufp->fullCData(oldp+3,(vlSelf->testing__DOT__uio_in),8);
    bufp->fullCData(oldp+4,(vlSelf->testing__DOT__uio_out),8);
    bufp->fullCData(oldp+5,(vlSelf->testing__DOT__ram_addr),5);
    bufp->fullCData(oldp+6,(vlSelf->testing__DOT__main_cpu__DOT__memaddr),5);
    bufp->fullCData(oldp+7,((0xfU & (IData)(vlSelf->testing__DOT__uio_in))),4);
    bufp->fullCData(oldp+8,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu),4);
    bufp->fullBit(oldp+9,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memstr));
    bufp->fullBit(oldp+10,((1U & ((7U == (7U & (IData)(vlSelf->testing__DOT__ui_in)))
                                   ? ((0x40U & (IData)(vlSelf->testing__DOT__ui_in))
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
                                            : ((8U 
                                                & (IData)(vlSelf->testing__DOT__ui_in))
                                                ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                   >> 3U)))))
                                   : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout)))));
    bufp->fullBit(oldp+11,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__flagztocp));
    bufp->fullBit(oldp+12,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_taken));
    bufp->fullCData(oldp+13,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination),6);
    bufp->fullBit(oldp+14,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__saveaddress));
    bufp->fullBit(oldp+15,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jumpen));
    bufp->fullBit(oldp+16,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagcwen));
    bufp->fullBit(oldp+17,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagzwen));
    bufp->fullCData(oldp+18,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 4U))),2);
    bufp->fullBit(oldp+19,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                  >> 3U))));
    bufp->fullCData(oldp+20,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 1U))),2);
    bufp->fullCData(oldp+21,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 6U))),2);
    bufp->fullCData(oldp+22,((7U & (IData)(vlSelf->testing__DOT__ui_in))),3);
    bufp->fullCData(oldp+23,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 5U))),4);
    bufp->fullBit(oldp+24,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                  >> 4U))));
    bufp->fullCData(oldp+25,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset),6);
    bufp->fullCData(oldp+26,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_reg),6);
    bufp->fullCData(oldp+27,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset),6);
    bufp->fullBit(oldp+28,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile));
    bufp->fullBit(oldp+29,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile));
    bufp->fullCData(oldp+30,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu),4);
    bufp->fullCData(oldp+31,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__regfiledin),4);
    bufp->fullCData(oldp+32,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__general_data),4);
    bufp->fullCData(oldp+33,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aludout),4);
    bufp->fullCData(oldp+34,((0xfU & ((IData)(vlSelf->testing__DOT__ui_in) 
                                      >> 3U))),4);
    bufp->fullCData(oldp+35,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 5U))),2);
    bufp->fullCData(oldp+36,((3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 3U))),2);
    bufp->fullBit(oldp+37,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                  >> 5U))));
    bufp->fullBit(oldp+38,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aluen));
    bufp->fullBit(oldp+39,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__shiften));
    bufp->fullBit(oldp+40,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__extenden));
    bufp->fullBit(oldp+41,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel));
    bufp->fullBit(oldp+42,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__jumpen));
    bufp->fullBit(oldp+43,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memldr));
    bufp->fullBit(oldp+44,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__inverttoaddsub));
    bufp->fullBit(oldp+45,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__cintoaddsub));
    bufp->fullCData(oldp+46,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput),4);
    bufp->fullCData(oldp+47,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout),4);
    bufp->fullBit(oldp+48,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout));
    bufp->fullCData(oldp+49,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout),4);
    bufp->fullBit(oldp+50,((1U & ((0x40U & (IData)(vlSelf->testing__DOT__ui_in))
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
                                       >> 5U) & ((0x10U 
                                                  & (IData)(vlSelf->testing__DOT__ui_in))
                                                  ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                  : 
                                                 ((8U 
                                                   & (IData)(vlSelf->testing__DOT__ui_in))
                                                   ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                   : 
                                                  ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                   >> 3U))))))));
    bufp->fullCData(oldp+51,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data),4);
    bufp->fullBit(oldp+52,((1U & (((IData)(vlSelf->testing__DOT__ui_in) 
                                   >> 5U) & ((0x10U 
                                              & (IData)(vlSelf->testing__DOT__ui_in))
                                              ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                              : ((8U 
                                                  & (IData)(vlSelf->testing__DOT__ui_in))
                                                  ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                  : 
                                                 ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                  >> 3U)))))));
    bufp->fullBit(oldp+53,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                  >> 5U))));
    bufp->fullCData(oldp+54,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp),4);
    bufp->fullBit(oldp+55,((1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                  >> 6U))));
    bufp->fullCData(oldp+56,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp),4);
    bufp->fullCData(oldp+57,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__secondinput),4);
    bufp->fullCData(oldp+58,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__adderout),5);
    bufp->fullCData(oldp+59,((0xfU & (IData)(vlSelf->testing__DOT__uio_out))),4);
    bufp->fullBit(oldp+60,((1U & ((IData)(vlSelf->testing__DOT__uo_out) 
                                  >> 7U))));
    bufp->fullCData(oldp+61,((0x3fU & (IData)(vlSelf->testing__DOT__uo_out))),6);
    bufp->fullCData(oldp+62,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc),6);
    bufp->fullBit(oldp+63,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc));
    bufp->fullCData(oldp+64,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX),2);
    bufp->fullBit(oldp+65,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive));
    bufp->fullBit(oldp+66,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz));
    bufp->fullCData(oldp+67,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pcx),6);
    bufp->fullCData(oldp+68,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA),4);
    bufp->fullCData(oldp+69,(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB),4);
    bufp->fullCData(oldp+70,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[0]),4);
    bufp->fullCData(oldp+71,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[1]),4);
    bufp->fullCData(oldp+72,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[2]),4);
    bufp->fullCData(oldp+73,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[3]),4);
    bufp->fullCData(oldp+74,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[4]),4);
    bufp->fullCData(oldp+75,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[5]),4);
    bufp->fullCData(oldp+76,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[6]),4);
    bufp->fullCData(oldp+77,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[7]),4);
    bufp->fullCData(oldp+78,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[8]),4);
    bufp->fullCData(oldp+79,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[9]),4);
    bufp->fullCData(oldp+80,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[10]),4);
    bufp->fullCData(oldp+81,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[11]),4);
    bufp->fullCData(oldp+82,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[12]),4);
    bufp->fullCData(oldp+83,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[13]),4);
    bufp->fullCData(oldp+84,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[14]),4);
    bufp->fullCData(oldp+85,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[15]),4);
    bufp->fullCData(oldp+86,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[16]),4);
    bufp->fullCData(oldp+87,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[17]),4);
    bufp->fullCData(oldp+88,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[18]),4);
    bufp->fullCData(oldp+89,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[19]),4);
    bufp->fullCData(oldp+90,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[20]),4);
    bufp->fullCData(oldp+91,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[21]),4);
    bufp->fullCData(oldp+92,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[22]),4);
    bufp->fullCData(oldp+93,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[23]),4);
    bufp->fullCData(oldp+94,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[24]),4);
    bufp->fullCData(oldp+95,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[25]),4);
    bufp->fullCData(oldp+96,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[26]),4);
    bufp->fullCData(oldp+97,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[27]),4);
    bufp->fullCData(oldp+98,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[28]),4);
    bufp->fullCData(oldp+99,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[29]),4);
    bufp->fullCData(oldp+100,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[30]),4);
    bufp->fullCData(oldp+101,(vlSelf->testing__DOT__main_memory__DOT__ram_mem[31]),4);
    bufp->fullIData(oldp+102,(vlSelf->testing__DOT__main_memory__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+103,(vlSelf->clk));
    bufp->fullBit(oldp+104,(vlSelf->reset));
    bufp->fullCData(oldp+105,(vlSelf->uio_oe),8);
    bufp->fullBit(oldp+106,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->fullCData(oldp+107,(vlSelf->testing__DOT__main_memory__DOT__ram_mem
                              [vlSelf->testing__DOT__ram_addr]),4);
    bufp->fullBit(oldp+108,(1U));
    bufp->fullIData(oldp+109,(1U),32);
    bufp->fullBit(oldp+110,(0U));
    bufp->fullIData(oldp+111,(2U),32);
    __Vtemp_hd2c9f1e7__0[0U] = 0x2e6d656dU;
    __Vtemp_hd2c9f1e7__0[1U] = 0x64617461U;
    __Vtemp_hd2c9f1e7__0[2U] = 0x726f6dU;
    bufp->fullWData(oldp+112,(__Vtemp_hd2c9f1e7__0),88);
}
