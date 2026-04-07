// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->uio_oe = (0xf0U | (0xfU & (- (IData)((1U 
                                                  & ((IData)(vlSelf->testing__DOT__uo_out) 
                                                     >> 7U))))));
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive;
    CData/*5:0*/ __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc;
    // Body
    __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc 
        = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc;
    __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive 
        = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive;
    if (vlSelf->reset) {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz = 0U;
        __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc = 0U;
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pcx = 0U;
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB = 0U;
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA = 0U;
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX = 0U;
        __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive = 0U;
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc = 0U;
    } else {
        if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagzwen) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz 
                = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__flagztocp;
        }
        __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc 
            = (0x3fU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_taken)
                         ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination)
                         : ((IData)(1U) + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc))));
        if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__saveaddress) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pcx 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc)));
        }
        if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile) {
            if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile) {
                if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile) {
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB 
                        = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__regfiledin;
                }
            }
            if ((1U & (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile)))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA 
                    = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__regfiledin;
            }
        }
        if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive) {
            __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive = 0U;
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX = 0U;
        } else if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__extenden) {
            __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive = 1U;
            if ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX 
                    = (3U & ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                              ? ((IData)(vlSelf->testing__DOT__ui_in) 
                                 >> 4U) : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu)));
            } else if ((8U & (IData)(vlSelf->testing__DOT__ui_in))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX 
                    = (3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                             >> 4U));
            } else {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX 
                    = ((2U & (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX)) 
                       | (1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                >> 5U)));
            }
        }
        if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagcwen) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc 
                = (1U & ((7U == (7U & (IData)(vlSelf->testing__DOT__ui_in)))
                          ? ((0x40U & (IData)(vlSelf->testing__DOT__ui_in))
                              ? ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))
                                  ? ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                      ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                         >> 1U) : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                   >> 1U))
                                  : ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                      ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                         >> 1U) : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                                   >> 3U)))
                              : (((IData)(vlSelf->testing__DOT__ui_in) 
                                  >> 5U) & ((0x10U 
                                             & (IData)(vlSelf->testing__DOT__ui_in))
                                             ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                             : ((8U 
                                                 & (IData)(vlSelf->testing__DOT__ui_in))
                                                 ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)
                                                 : 
                                                ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                                 >> 3U)))))
                          : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout)));
        }
    }
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc 
        = __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc;
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive 
        = __Vdly__testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive;
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v0;
    CData/*4:0*/ __Vdlyvdim0__testing__DOT__main_memory__DOT__ram_mem__v32;
    CData/*3:0*/ __Vdlyvval__testing__DOT__main_memory__DOT__ram_mem__v32;
    CData/*0:0*/ __Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v32;
    // Body
    __Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v0 = 0U;
    __Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v32 = 0U;
    if (vlSelf->reset) {
        vlSelf->testing__DOT__main_memory__DOT__unnamedblk1__DOT__i = 0x20U;
        __Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v0 = 1U;
    } else if ((0x80U & (IData)(vlSelf->testing__DOT__uo_out))) {
        __Vdlyvval__testing__DOT__main_memory__DOT__ram_mem__v32 
            = (0xfU & (IData)(vlSelf->testing__DOT__uio_out));
        __Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v32 = 1U;
        __Vdlyvdim0__testing__DOT__main_memory__DOT__ram_mem__v32 
            = vlSelf->testing__DOT__ram_addr;
    }
    if (__Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v0) {
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[1U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[2U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[3U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[4U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[5U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[6U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[7U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[8U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[9U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0xaU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0xbU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0xcU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0xdU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0xeU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0xfU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x10U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x11U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x12U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x13U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x14U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x15U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x16U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x17U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x18U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x19U] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x1aU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x1bU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x1cU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x1dU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x1eU] = 0U;
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[0x1fU] = 0U;
    }
    if (__Vdlyvset__testing__DOT__main_memory__DOT__ram_mem__v32) {
        vlSelf->testing__DOT__main_memory__DOT__ram_mem[__Vdlyvdim0__testing__DOT__main_memory__DOT__ram_mem__v32] 
            = __Vdlyvval__testing__DOT__main_memory__DOT__ram_mem__v32;
    }
}

extern const VlUnpacked<CData/*0:0*/, 32> Vdut__ConstPool__TABLE_h35c5b8e8_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vdut__ConstPool__TABLE_h62a9b285_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vdut__ConstPool__TABLE_h484d16ef_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vdut__ConstPool__TABLE_he60f8426_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vdut__ConstPool__TABLE_hdb655e07_0;

VL_INLINE_OPT void Vdut___024root___combo__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__1\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    CData/*4:0*/ __Vtableidx2;
    // Body
    vlSelf->testing__DOT__ui_in = vlSelf->testing__DOT__main_memory__DOT__rom_mem
        [(0x3fU & (IData)(vlSelf->testing__DOT__uo_out))];
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__extenden 
        = (1U & (((~ ((IData)(vlSelf->testing__DOT__ui_in) 
                      >> 7U)) | (IData)((0x80U == (0xc0U 
                                                   & (IData)(vlSelf->testing__DOT__ui_in))))) 
                 & (~ ((7U != (7U & (IData)(vlSelf->testing__DOT__ui_in))) 
                       | (IData)((7U == (0x87U & (IData)(vlSelf->testing__DOT__ui_in))))))));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aluen 
        = (((~ ((IData)(vlSelf->testing__DOT__ui_in) 
                >> 7U)) | (IData)((0x80U == (0xc0U 
                                             & (IData)(vlSelf->testing__DOT__ui_in))))) 
           & ((7U != (7U & (IData)(vlSelf->testing__DOT__ui_in))) 
              | (IData)((7U == (0x87U & (IData)(vlSelf->testing__DOT__ui_in))))));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__jumpen = 0U;
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__shiften = 0U;
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memstr = 0U;
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memldr = 0U;
    if ((1U & (~ ((~ ((IData)(vlSelf->testing__DOT__ui_in) 
                      >> 7U)) | (IData)((0x80U == (0xc0U 
                                                   & (IData)(vlSelf->testing__DOT__ui_in)))))))) {
        if ((IData)((0xc1U == (0xc1U & (IData)(vlSelf->testing__DOT__ui_in))))) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__jumpen = 1U;
        }
        if ((IData)((0xc0U == (0xc1U & (IData)(vlSelf->testing__DOT__ui_in))))) {
            if ((2U & (IData)(vlSelf->testing__DOT__ui_in))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memstr = 1U;
            }
            if ((1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                          >> 1U)))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memldr = 1U;
            }
        }
    }
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel = 0U;
    __Vtableidx2 = ((0x1cU & ((IData)(vlSelf->testing__DOT__ui_in) 
                              << 2U)) | (3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                                               >> 6U)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jumpen 
        = Vdut__ConstPool__TABLE_h35c5b8e8_0[__Vtableidx2];
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagzwen 
        = Vdut__ConstPool__TABLE_h62a9b285_0[__Vtableidx2];
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagcwen 
        = Vdut__ConstPool__TABLE_h484d16ef_0[__Vtableidx2];
    __Vtableidx1 = (((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc) 
                     << 3U) | (7U & (IData)(vlSelf->testing__DOT__ui_in)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__cintoaddsub 
        = Vdut__ConstPool__TABLE_he60f8426_0[__Vtableidx1];
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__inverttoaddsub 
        = Vdut__ConstPool__TABLE_hdb655e07_0[__Vtableidx1];
    if ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))) {
        if ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu 
                = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB;
        }
    } else {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu 
            = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA;
    }
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile 
        = (1U & ((IData)(vlSelf->testing__DOT__ui_in) 
                 >> 5U));
    if ((1U & ((~ ((IData)(vlSelf->testing__DOT__ui_in) 
                   >> 7U)) | (IData)((0x80U == (0xc0U 
                                                & (IData)(vlSelf->testing__DOT__ui_in))))))) {
        if (((7U != (7U & (IData)(vlSelf->testing__DOT__ui_in))) 
             | (IData)((7U == (0x87U & (IData)(vlSelf->testing__DOT__ui_in)))))) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__shiften 
                = (7U == (7U & (IData)(vlSelf->testing__DOT__ui_in)));
            if ((1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                          >> 7U)))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel = 1U;
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile = 0U;
            } else {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel = 0U;
            }
            if ((7U == (7U & (IData)(vlSelf->testing__DOT__ui_in)))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile = 0U;
            }
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile 
                = (6U != (7U & (IData)(vlSelf->testing__DOT__ui_in)));
        } else {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile = 0U;
        }
    } else {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile = 0U;
        if ((IData)((0xc0U == (0xc1U & (IData)(vlSelf->testing__DOT__ui_in))))) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__wen1toregfile 
                = (1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                            >> 1U)));
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel 
                = (1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                            >> 2U)));
        }
    }
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__saveaddress = 0U;
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_taken 
        = ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jumpen) 
           & ((4U & (IData)(vlSelf->testing__DOT__ui_in))
               ? (((IData)(vlSelf->testing__DOT__ui_in) 
                   >> 1U) | ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                              ? (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc))
                              : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc)))
               : ((2U & (IData)(vlSelf->testing__DOT__ui_in))
                   ? ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                       ? (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz))
                       : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagz))
                   : (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                         >> 3U)))));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp = 0U;
    if ((0x20U & (IData)(vlSelf->testing__DOT__ui_in))) {
        if ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))) {
            if ((8U & (IData)(vlSelf->testing__DOT__ui_in))) {
                if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc) {
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp 
                        = (0xfU & (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)));
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp 
                        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp) 
                                   >> 1U));
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data 
                        = (0xfU & (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_1__DOT__temp)));
                } else {
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data 
                        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                   >> 1U));
                }
            } else {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data 
                    = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                               >> 1U));
            }
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset = 0x3dU;
        } else {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data 
                = (0xfU & ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                            ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                               >> 1U) : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu) 
                                         << 1U)));
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset = 0x3eU;
        }
    } else {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data 
            = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu;
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset 
            = ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))
                ? 3U : 2U);
    }
    if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile) {
        if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__ad1toregfile) {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu 
                = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regB;
        }
    } else {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu 
            = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_registers__DOT__regA;
    }
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp = 0U;
    if ((0x40U & (IData)(vlSelf->testing__DOT__ui_in))) {
        if ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))) {
            if ((8U & (IData)(vlSelf->testing__DOT__ui_in))) {
                if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__flagc) {
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp 
                        = (0xfU & (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data)));
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp 
                        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp) 
                                   >> 2U));
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout 
                        = (0xfU & (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift_2__DOT__temp)));
                } else {
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout 
                        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                   >> 2U));
                }
            } else {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout 
                    = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                               >> 2U));
            }
        } else {
            vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout 
                = (0xfU & ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                            ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                               >> 2U) : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data) 
                                         << 2U)));
        }
    } else {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout 
            = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__mainShifter__DOT__shift1toshift2data;
    }
    if ((4U & (IData)(vlSelf->testing__DOT__ui_in))) {
        if ((4U & (IData)(vlSelf->testing__DOT__ui_in))) {
            vlSelf->testing__DOT__main_cpu__DOT__memaddr 
                = ((0x10U & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX) 
                             << 4U)) | (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu));
        }
    } else {
        vlSelf->testing__DOT__main_cpu__DOT__memaddr 
            = (3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                     >> 3U));
    }
    vlSelf->testing__DOT__uo_out = (((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memstr) 
                                     << 7U) | ((0x40U 
                                                & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__memaddr) 
                                                   << 2U)) 
                                               | (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc)));
    vlSelf->testing__DOT__uio_out = ((0xfU & (IData)(vlSelf->testing__DOT__uio_out)) 
                                     | (0xf0U & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__memaddr) 
                                                 << 4U)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination = 0U;
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_reg 
        = (((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX) 
            << 4U) | (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset 
        = ((0x30U & ((- (IData)((1U & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX) 
                                       >> 1U)))) << 4U)) 
           | (((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__addr_ext__DOT__regX) 
               << 2U) | (3U & ((IData)(vlSelf->testing__DOT__ui_in) 
                               >> 4U))));
    if (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jumpen) {
        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__saveaddress = 0U;
        if ((4U & (IData)(vlSelf->testing__DOT__ui_in))) {
            if ((2U & (IData)(vlSelf->testing__DOT__ui_in))) {
                if ((1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                              >> 3U)))) {
                    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__saveaddress 
                        = (1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                                    >> 4U)));
                }
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination 
                    = (0x3fU & ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                 ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pcx)
                                 : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_reg)));
            } else {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination 
                    = (0x3fU & ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                 ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive)
                                     ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset))
                                     : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset)))
                                 : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive)
                                     ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset))
                                     : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset)))));
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                          >> 1U)))) {
                if ((8U & (IData)(vlSelf->testing__DOT__ui_in))) {
                    if ((0x10U & (IData)(vlSelf->testing__DOT__ui_in))) {
                        vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__saveaddress = 1U;
                    }
                }
            }
            if ((2U & (IData)(vlSelf->testing__DOT__ui_in))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination 
                    = (0x3fU & ((8U & (IData)(vlSelf->testing__DOT__ui_in))
                                 ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive)
                                     ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset))
                                     : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset)))
                                 : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive)
                                     ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset))
                                     : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                        + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset)))));
            } else if ((1U & (~ ((IData)(vlSelf->testing__DOT__ui_in) 
                                 >> 3U)))) {
                vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__destination 
                    = (0x3fU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__extactive)
                                 ? ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                    + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__extended_offset))
                                 : ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__pc) 
                                    + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_controlpath__DOT__jump_conditions__DOT__offset))));
            }
        }
    }
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__secondinput 
        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__inverttoaddsub)
                    ? (~ (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput))
                    : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__adderout 
        = (0x1fU & (((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu) 
                     + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__secondinput)) 
                    + (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__cintoaddsub)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout 
        = (0xfU & (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__adderout));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubcout 
        = (1U & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__main_adder__DOT__adderout) 
                 >> 4U));
    vlSelf->testing__DOT__uio_out = ((0xf0U & (IData)(vlSelf->testing__DOT__uio_out)) 
                                     | (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput 
        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__op2sel)
                    ? ((IData)(vlSelf->testing__DOT__ui_in) 
                       >> 3U) : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din2toalu)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aludout 
        = (0xfU & ((4U & (IData)(vlSelf->testing__DOT__ui_in))
                    ? ((2U & (IData)(vlSelf->testing__DOT__ui_in))
                        ? ((1U & (IData)(vlSelf->testing__DOT__ui_in))
                            ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__shiftdout)
                            : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout))
                        : ((1U & (IData)(vlSelf->testing__DOT__ui_in))
                            ? (~ ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__din1toalu) 
                                  & (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput)))
                            : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout)))
                    : ((2U & (IData)(vlSelf->testing__DOT__ui_in))
                        ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout)
                        : ((1U & (IData)(vlSelf->testing__DOT__ui_in))
                            ? (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__addsubdout)
                            : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput)))));
    vlSelf->testing__DOT__ram_addr = ((0x10U & ((IData)(vlSelf->testing__DOT__uo_out) 
                                                >> 2U)) 
                                      | (0xfU & ((IData)(vlSelf->testing__DOT__uio_out) 
                                                 >> 4U)));
    vlSelf->testing__DOT__uio_in = ((0xf0U & (IData)(vlSelf->testing__DOT__uio_in)) 
                                    | vlSelf->testing__DOT__main_memory__DOT__ram_mem
                                    [vlSelf->testing__DOT__ram_addr]);
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__general_data 
        = (0xfU & ((IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__memldr)
                    ? (IData)(vlSelf->testing__DOT__uio_in)
                    : (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__aludout)));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__flagztocp 
        = (0U == (IData)(vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__general_data));
    vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__regfiledin 
        = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__general_data;
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->reset) & (~ (IData)(vlSelf->__Vclklast__TOP__reset))))) {
        Vdut___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    Vdut___024root___combo__TOP__1(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

QData Vdut___024root___change_request_1(Vdut___024root* vlSelf);

VL_INLINE_OPT QData Vdut___024root___change_request(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___change_request\n"); );
    // Body
    return (Vdut___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vdut___024root___change_request_1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->testing__DOT__uo_out ^ vlSelf->__Vchglast__TOP__testing__DOT__uo_out)
         | (vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput ^ vlSelf->__Vchglast__TOP__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput));
    VL_DEBUG_IF( if(__req && ((vlSelf->testing__DOT__uo_out ^ vlSelf->__Vchglast__TOP__testing__DOT__uo_out))) VL_DBG_MSGF("        CHANGE: testing.sv:11: testing.uo_out\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput ^ vlSelf->__Vchglast__TOP__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput))) VL_DBG_MSGF("        CHANGE: alu4.sv:170: testing.main_cpu.main_cpu.main_datapath.main_alu.secondinput\n"); );
    // Final
    vlSelf->__Vchglast__TOP__testing__DOT__uo_out = vlSelf->testing__DOT__uo_out;
    vlSelf->__Vchglast__TOP__testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput 
        = vlSelf->testing__DOT__main_cpu__DOT__main_cpu__DOT__main_datapath__DOT__main_alu__DOT__secondinput;
    return __req;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
