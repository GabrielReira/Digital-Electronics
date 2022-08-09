// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pong.h for the primary calling header

#include "Vtop_pong.h"
#include "Vtop_pong__Syms.h"

//==========
CData/*3:0*/ Vtop_pong::__Vtable1_top_pong__DOT__paint_r[32];
CData/*3:0*/ Vtop_pong::__Vtable1_top_pong__DOT__paint_g[32];
CData/*3:0*/ Vtop_pong::__Vtable1_top_pong__DOT__paint_b[32];

VL_CTOR_IMP(Vtop_pong) {
    Vtop_pong__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_pong__Syms(this, name());
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_pong::__Vconfigure(Vtop_pong__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_pong::~Vtop_pong() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop_pong::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_pong::eval\n"); );
    Vtop_pong__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_pong.sv", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop_pong::_eval_initial_loop(Vtop_pong__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top_pong.sv", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop_pong::_sequent__TOP__1(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_sequent__TOP__1\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top_pong__DOT__scoreEsquerda;
    CData/*3:0*/ __Vdly__top_pong__DOT__scoreDireita;
    CData/*3:0*/ __Vdly__top_pong__DOT__contadorRebatidas;
    CData/*0:0*/ __Vdly__top_pong__DOT__movDireita;
    SData/*9:0*/ __Vdly__top_pong__DOT__compY;
    SData/*9:0*/ __Vdly__top_pong__DOT__playY;
    SData/*9:0*/ __Vdly__top_pong__DOT__bolaVelX;
    SData/*9:0*/ __Vdly__top_pong__DOT__bolaVelY;
    SData/*9:0*/ __Vdly__top_pong__DOT__bolaY;
    SData/*9:0*/ __Vdly__top_pong__DOT__bolaX;
    SData/*9:0*/ __Vdly__top_pong__DOT__sx;
    // Body
    __Vdly__top_pong__DOT__playY = vlTOPp->top_pong__DOT__playY;
    __Vdly__top_pong__DOT__compY = vlTOPp->top_pong__DOT__compY;
    __Vdly__top_pong__DOT__movDireita = vlTOPp->top_pong__DOT__movDireita;
    __Vdly__top_pong__DOT__contadorRebatidas = vlTOPp->top_pong__DOT__contadorRebatidas;
    __Vdly__top_pong__DOT__bolaVelY = vlTOPp->top_pong__DOT__bolaVelY;
    __Vdly__top_pong__DOT__bolaVelX = vlTOPp->top_pong__DOT__bolaVelX;
    __Vdly__top_pong__DOT__scoreDireita = vlTOPp->top_pong__DOT__scoreDireita;
    __Vdly__top_pong__DOT__scoreEsquerda = vlTOPp->top_pong__DOT__scoreEsquerda;
    __Vdly__top_pong__DOT__bolaX = vlTOPp->top_pong__DOT__bolaX;
    __Vdly__top_pong__DOT__bolaY = vlTOPp->top_pong__DOT__bolaY;
    __Vdly__top_pong__DOT__sx = vlTOPp->top_pong__DOT__sx;
    vlTOPp->sdl_b = (0xffU & (((IData)(vlTOPp->top_pong__DOT__paint_b) 
                               << 4U) | (IData)(vlTOPp->top_pong__DOT__paint_b)));
    vlTOPp->sdl_r = (0xffU & (((IData)(vlTOPp->top_pong__DOT__paint_r) 
                               << 4U) | (IData)(vlTOPp->top_pong__DOT__paint_r)));
    vlTOPp->sdl_g = (0xffU & (((IData)(vlTOPp->top_pong__DOT__paint_g) 
                               << 4U) | (IData)(vlTOPp->top_pong__DOT__paint_g)));
    vlTOPp->top_pong__DOT__pix_score = ((IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_l_region)
                                         ? ((0xeU >= 
                                             (0xfU 
                                              & ((IData)(0xeU) 
                                                 - (IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__pix_addr)))) 
                                            & (((9U 
                                                 >= (IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_l))
                                                 ? 
                                                vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars
                                                [vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_l]
                                                 : 0U) 
                                               >> (0xfU 
                                                   & ((IData)(0xeU) 
                                                      - (IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__pix_addr)))))
                                         : ((IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_r_region) 
                                            & ((0xeU 
                                                >= 
                                                (0xfU 
                                                 & ((IData)(0xeU) 
                                                    - (IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__pix_addr)))) 
                                               & (((9U 
                                                    >= (IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_r))
                                                    ? 
                                                   vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars
                                                   [vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_r]
                                                    : 0U) 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xeU) 
                                                      - (IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__pix_addr)))))));
    vlTOPp->sdl_sy = vlTOPp->top_pong__DOT__sy;
    vlTOPp->sdl_sx = vlTOPp->top_pong__DOT__sx;
    if ((1U == vlTOPp->top_pong__DOT__state)) {
        __Vdly__top_pong__DOT__playY = 0xd8U;
    } else {
        if (((IData)(vlTOPp->top_pong__DOT__frame) 
             & (2U == vlTOPp->top_pong__DOT__state))) {
            if (vlTOPp->btn_dn) {
                __Vdly__top_pong__DOT__playY = ((0x1dfU 
                                                 <= 
                                                 ((IData)(0x37U) 
                                                  + (IData)(vlTOPp->top_pong__DOT__playY)))
                                                 ? 0x1afU
                                                 : 
                                                (0x3ffU 
                                                 & ((IData)(7U) 
                                                    + (IData)(vlTOPp->top_pong__DOT__playY))));
            } else {
                if (vlTOPp->btn_up) {
                    __Vdly__top_pong__DOT__playY = 
                        ((7U > (IData)(vlTOPp->top_pong__DOT__playY))
                          ? 0U : (0x3ffU & ((IData)(vlTOPp->top_pong__DOT__playY) 
                                            - (IData)(7U))));
                }
            }
        }
    }
    if ((1U == vlTOPp->top_pong__DOT__state)) {
        __Vdly__top_pong__DOT__compY = 0xd8U;
    } else {
        if (((IData)(vlTOPp->top_pong__DOT__frame) 
             & (2U == vlTOPp->top_pong__DOT__state))) {
            if ((((IData)(0x18U) + (IData)(vlTOPp->top_pong__DOT__compY)) 
                 < (IData)(vlTOPp->top_pong__DOT__bolaY))) {
                __Vdly__top_pong__DOT__compY = ((0x1dfU 
                                                 <= 
                                                 ((IData)(0x37U) 
                                                  + (IData)(vlTOPp->top_pong__DOT__compY)))
                                                 ? 0x1afU
                                                 : 
                                                (0x3ffU 
                                                 & ((IData)(7U) 
                                                    + (IData)(vlTOPp->top_pong__DOT__compY))));
            } else {
                if ((((IData)(0x18U) + (IData)(vlTOPp->top_pong__DOT__compY)) 
                     > ((IData)(8U) + (IData)(vlTOPp->top_pong__DOT__bolaY)))) {
                    __Vdly__top_pong__DOT__compY = 
                        ((7U > (IData)(vlTOPp->top_pong__DOT__compY))
                          ? 0U : (0x3ffU & ((IData)(vlTOPp->top_pong__DOT__compY) 
                                            - (IData)(7U))));
                }
            }
        }
    }
    vlTOPp->sdl_de = ((0x27fU >= (IData)(vlTOPp->top_pong__DOT__sx)) 
                      & (0x1dfU >= (IData)(vlTOPp->top_pong__DOT__sy)));
    if ((0U == vlTOPp->top_pong__DOT__state)) {
        __Vdly__top_pong__DOT__scoreEsquerda = 0U;
        __Vdly__top_pong__DOT__scoreDireita = 0U;
    } else {
        if ((1U == vlTOPp->top_pong__DOT__state)) {
            vlTOPp->top_pong__DOT__colEsquerda = 0U;
            vlTOPp->top_pong__DOT__colDireita = 0U;
            __Vdly__top_pong__DOT__bolaVelX = 9U;
            __Vdly__top_pong__DOT__bolaVelY = 5U;
            __Vdly__top_pong__DOT__contadorRebatidas = 0U;
            __Vdly__top_pong__DOT__bolaY = 0xecU;
            __Vdly__top_pong__DOT__bolaX = 0x2dU;
            __Vdly__top_pong__DOT__movDireita = 1U;
        } else {
            if ((2U == vlTOPp->top_pong__DOT__state)) {
                if (vlTOPp->top_pong__DOT__frame) {
                    if (vlTOPp->top_pong__DOT__movDireita) {
                        if ((0x27fU <= ((IData)(8U) 
                                        + ((IData)(vlTOPp->top_pong__DOT__bolaX) 
                                           + (IData)(vlTOPp->top_pong__DOT__bolaVelX))))) {
                            __Vdly__top_pong__DOT__scoreEsquerda 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->top_pong__DOT__scoreEsquerda)));
                            __Vdly__top_pong__DOT__bolaX = 0x278U;
                            vlTOPp->top_pong__DOT__colDireita = 1U;
                        } else {
                            __Vdly__top_pong__DOT__bolaX 
                                = (0x3ffU & ((IData)(vlTOPp->top_pong__DOT__bolaX) 
                                             + (IData)(vlTOPp->top_pong__DOT__bolaVelX)));
                        }
                    } else {
                        if (((IData)(vlTOPp->top_pong__DOT__bolaX) 
                             < (IData)(vlTOPp->top_pong__DOT__bolaVelX))) {
                            __Vdly__top_pong__DOT__scoreDireita 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->top_pong__DOT__scoreDireita)));
                            __Vdly__top_pong__DOT__bolaX = 0U;
                            vlTOPp->top_pong__DOT__colEsquerda = 1U;
                        } else {
                            __Vdly__top_pong__DOT__bolaX 
                                = (0x3ffU & ((IData)(vlTOPp->top_pong__DOT__bolaX) 
                                             - (IData)(vlTOPp->top_pong__DOT__bolaVelX)));
                        }
                    }
                    if (vlTOPp->top_pong__DOT__movBaixo) {
                        if ((0x1dfU <= ((IData)(8U) 
                                        + ((IData)(vlTOPp->top_pong__DOT__bolaY) 
                                           + (IData)(vlTOPp->top_pong__DOT__bolaVelY))))) {
                            vlTOPp->top_pong__DOT__movBaixo = 0U;
                        } else {
                            __Vdly__top_pong__DOT__bolaY 
                                = (0x3ffU & ((IData)(vlTOPp->top_pong__DOT__bolaY) 
                                             + (IData)(vlTOPp->top_pong__DOT__bolaVelY)));
                        }
                    } else {
                        if (((IData)(vlTOPp->top_pong__DOT__bolaY) 
                             < (IData)(vlTOPp->top_pong__DOT__bolaVelY))) {
                            vlTOPp->top_pong__DOT__movBaixo = 1U;
                        } else {
                            __Vdly__top_pong__DOT__bolaY 
                                = (0x3ffU & ((IData)(vlTOPp->top_pong__DOT__bolaY) 
                                             - (IData)(vlTOPp->top_pong__DOT__bolaVelY)));
                        }
                    }
                    if (((IData)(vlTOPp->top_pong__DOT__movAnterior) 
                         != (IData)(vlTOPp->top_pong__DOT__movDireita))) {
                        __Vdly__top_pong__DOT__contadorRebatidas 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlTOPp->top_pong__DOT__contadorRebatidas)));
                    }
                    if ((5U == (IData)(vlTOPp->top_pong__DOT__contadorRebatidas))) {
                        __Vdly__top_pong__DOT__bolaVelX 
                            = (0x3ffU & ((0xaU > (IData)(vlTOPp->top_pong__DOT__bolaVelX))
                                          ? ((IData)(1U) 
                                             + (IData)(vlTOPp->top_pong__DOT__bolaVelX))
                                          : (IData)(vlTOPp->top_pong__DOT__bolaVelX)));
                        __Vdly__top_pong__DOT__bolaVelY 
                            = (0x3ffU & ((0xaU > (IData)(vlTOPp->top_pong__DOT__bolaVelY))
                                          ? ((IData)(1U) 
                                             + (IData)(vlTOPp->top_pong__DOT__bolaVelY))
                                          : (IData)(vlTOPp->top_pong__DOT__bolaVelY)));
                        __Vdly__top_pong__DOT__contadorRebatidas = 0U;
                    }
                }
            }
        }
    }
    if ((((IData)(vlTOPp->top_pong__DOT__bola) & (IData)(vlTOPp->top_pong__DOT__padEsquerda)) 
         & (~ (IData)(vlTOPp->top_pong__DOT__movDireita)))) {
        __Vdly__top_pong__DOT__movDireita = 1U;
    }
    if ((((IData)(vlTOPp->top_pong__DOT__bola) & (IData)(vlTOPp->top_pong__DOT__padDireita)) 
         & (IData)(vlTOPp->top_pong__DOT__movDireita))) {
        __Vdly__top_pong__DOT__movDireita = 0U;
    }
    if (vlTOPp->top_pong__DOT__frame) {
        vlTOPp->top_pong__DOT__movAnterior = vlTOPp->top_pong__DOT__movDireita;
    }
    if ((0x31fU == (IData)(vlTOPp->top_pong__DOT__sx))) {
        vlTOPp->top_pong__DOT__sy = ((0x20cU == (IData)(vlTOPp->top_pong__DOT__sy))
                                      ? 0U : (0x3ffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlTOPp->top_pong__DOT__sy))));
        __Vdly__top_pong__DOT__sx = 0U;
    } else {
        __Vdly__top_pong__DOT__sx = (0x3ffU & ((IData)(1U) 
                                               + (IData)(vlTOPp->top_pong__DOT__sx)));
    }
    if (vlTOPp->sim_rst) {
        vlTOPp->top_pong__DOT__sy = 0U;
        __Vdly__top_pong__DOT__sx = 0U;
    }
    vlTOPp->top_pong__DOT__playY = __Vdly__top_pong__DOT__playY;
    vlTOPp->top_pong__DOT__compY = __Vdly__top_pong__DOT__compY;
    vlTOPp->top_pong__DOT__bolaVelX = __Vdly__top_pong__DOT__bolaVelX;
    vlTOPp->top_pong__DOT__bolaVelY = __Vdly__top_pong__DOT__bolaVelY;
    vlTOPp->top_pong__DOT__contadorRebatidas = __Vdly__top_pong__DOT__contadorRebatidas;
    vlTOPp->top_pong__DOT__movDireita = __Vdly__top_pong__DOT__movDireita;
    vlTOPp->top_pong__DOT__scoreEsquerda = __Vdly__top_pong__DOT__scoreEsquerda;
    vlTOPp->top_pong__DOT__scoreDireita = __Vdly__top_pong__DOT__scoreDireita;
    vlTOPp->top_pong__DOT__bolaX = __Vdly__top_pong__DOT__bolaX;
    vlTOPp->top_pong__DOT__bolaY = __Vdly__top_pong__DOT__bolaY;
    vlTOPp->top_pong__DOT__sx = __Vdly__top_pong__DOT__sx;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_l 
        = ((0xaU > (IData)(vlTOPp->top_pong__DOT__scoreEsquerda))
            ? (0xfU & (IData)(vlTOPp->top_pong__DOT__scoreEsquerda))
            : 0U);
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_r 
        = ((0xaU > (IData)(vlTOPp->top_pong__DOT__scoreDireita))
            ? (0xfU & (IData)(vlTOPp->top_pong__DOT__scoreDireita))
            : 0U);
    vlTOPp->top_pong__DOT__state = vlTOPp->top_pong__DOT__next_state;
    vlTOPp->top_pong__DOT__frame = ((0x1e0U == (IData)(vlTOPp->top_pong__DOT__sy)) 
                                    & (0U == (IData)(vlTOPp->top_pong__DOT__sx)));
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_l_region 
        = ((((7U <= (IData)(vlTOPp->top_pong__DOT__sx)) 
             & (0x13U > (IData)(vlTOPp->top_pong__DOT__sx))) 
            & (8U <= (IData)(vlTOPp->top_pong__DOT__sy))) 
           & (0x1cU > (IData)(vlTOPp->top_pong__DOT__sy)));
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_r_region 
        = ((((0x26aU <= (IData)(vlTOPp->top_pong__DOT__sx)) 
             & (0x276U > (IData)(vlTOPp->top_pong__DOT__sx))) 
            & (8U <= (IData)(vlTOPp->top_pong__DOT__sy))) 
           & (0x1cU > (IData)(vlTOPp->top_pong__DOT__sy)));
    vlTOPp->top_pong__DOT__padEsquerda = ((((0x23U 
                                             <= (IData)(vlTOPp->top_pong__DOT__sx)) 
                                            & (0x2dU 
                                               > (IData)(vlTOPp->top_pong__DOT__sx))) 
                                           & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                              >= (IData)(vlTOPp->top_pong__DOT__playY))) 
                                          & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                             < ((IData)(0x30U) 
                                                + (IData)(vlTOPp->top_pong__DOT__playY))));
    vlTOPp->top_pong__DOT__padDireita = ((((0x252U 
                                            <= (IData)(vlTOPp->top_pong__DOT__sx)) 
                                           & (0x25cU 
                                              > (IData)(vlTOPp->top_pong__DOT__sx))) 
                                          & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                             >= (IData)(vlTOPp->top_pong__DOT__compY))) 
                                         & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                            < ((IData)(0x30U) 
                                               + (IData)(vlTOPp->top_pong__DOT__compY))));
    vlTOPp->top_pong__DOT__bola = (((((IData)(vlTOPp->top_pong__DOT__sx) 
                                      >= (IData)(vlTOPp->top_pong__DOT__bolaX)) 
                                     & ((IData)(vlTOPp->top_pong__DOT__sx) 
                                        < ((IData)(8U) 
                                           + (IData)(vlTOPp->top_pong__DOT__bolaX)))) 
                                    & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                       >= (IData)(vlTOPp->top_pong__DOT__bolaY))) 
                                   & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                      < ((IData)(8U) 
                                         + (IData)(vlTOPp->top_pong__DOT__bolaY))));
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__pix_addr 
        = (0xfU & ((IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_l_region)
                    ? ((((IData)(vlTOPp->top_pong__DOT__sx) 
                         - (IData)(7U)) >> 2U) + ((IData)(3U) 
                                                  * 
                                                  (((IData)(vlTOPp->top_pong__DOT__sy) 
                                                    - (IData)(8U)) 
                                                   >> 2U)))
                    : ((IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_r_region)
                        ? ((((IData)(vlTOPp->top_pong__DOT__sx) 
                             - (IData)(0x26aU)) >> 2U) 
                           + ((IData)(3U) * (((IData)(vlTOPp->top_pong__DOT__sy) 
                                              - (IData)(8U)) 
                                             >> 2U)))
                        : 0U)));
    vlTOPp->__Vtableidx1 = (((((0U == (IData)(vlTOPp->top_pong__DOT__sx)) 
                               | (0x27fU == (IData)(vlTOPp->top_pong__DOT__sx))) 
                              | ((0U == (IData)(vlTOPp->top_pong__DOT__sy)) 
                                 | (0x1dfU == (IData)(vlTOPp->top_pong__DOT__sy)))) 
                             << 4U) | (((IData)(vlTOPp->top_pong__DOT__padDireita) 
                                        << 3U) | (((IData)(vlTOPp->top_pong__DOT__padEsquerda) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->top_pong__DOT__bola) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->top_pong__DOT__pix_score)))));
    vlTOPp->top_pong__DOT__paint_r = vlTOPp->__Vtable1_top_pong__DOT__paint_r
        [vlTOPp->__Vtableidx1];
    vlTOPp->top_pong__DOT__paint_g = vlTOPp->__Vtable1_top_pong__DOT__paint_g
        [vlTOPp->__Vtableidx1];
    vlTOPp->top_pong__DOT__paint_b = vlTOPp->__Vtable1_top_pong__DOT__paint_b
        [vlTOPp->__Vtableidx1];
}

void Vtop_pong::_initial__TOP__2(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_initial__TOP__2\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[0U] = 0x7b6fU;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[1U] = 0x6497U;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[2U] = 0x73e7U;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[3U] = 0x72cfU;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[4U] = 0x5bc9U;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[5U] = 0x79cfU;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[6U] = 0x49efU;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[7U] = 0x7249U;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[8U] = 0x7befU;
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__chars[9U] = 0x7bc9U;
}

void Vtop_pong::_settle__TOP__3(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_settle__TOP__3\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_l 
        = ((0xaU > (IData)(vlTOPp->top_pong__DOT__scoreEsquerda))
            ? (0xfU & (IData)(vlTOPp->top_pong__DOT__scoreEsquerda))
            : 0U);
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__char_r 
        = ((0xaU > (IData)(vlTOPp->top_pong__DOT__scoreDireita))
            ? (0xfU & (IData)(vlTOPp->top_pong__DOT__scoreDireita))
            : 0U);
    vlTOPp->top_pong__DOT__frame = ((0x1e0U == (IData)(vlTOPp->top_pong__DOT__sy)) 
                                    & (0U == (IData)(vlTOPp->top_pong__DOT__sx)));
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_l_region 
        = ((((7U <= (IData)(vlTOPp->top_pong__DOT__sx)) 
             & (0x13U > (IData)(vlTOPp->top_pong__DOT__sx))) 
            & (8U <= (IData)(vlTOPp->top_pong__DOT__sy))) 
           & (0x1cU > (IData)(vlTOPp->top_pong__DOT__sy)));
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_r_region 
        = ((((0x26aU <= (IData)(vlTOPp->top_pong__DOT__sx)) 
             & (0x276U > (IData)(vlTOPp->top_pong__DOT__sx))) 
            & (8U <= (IData)(vlTOPp->top_pong__DOT__sy))) 
           & (0x1cU > (IData)(vlTOPp->top_pong__DOT__sy)));
    vlTOPp->top_pong__DOT__padEsquerda = ((((0x23U 
                                             <= (IData)(vlTOPp->top_pong__DOT__sx)) 
                                            & (0x2dU 
                                               > (IData)(vlTOPp->top_pong__DOT__sx))) 
                                           & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                              >= (IData)(vlTOPp->top_pong__DOT__playY))) 
                                          & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                             < ((IData)(0x30U) 
                                                + (IData)(vlTOPp->top_pong__DOT__playY))));
    vlTOPp->top_pong__DOT__padDireita = ((((0x252U 
                                            <= (IData)(vlTOPp->top_pong__DOT__sx)) 
                                           & (0x25cU 
                                              > (IData)(vlTOPp->top_pong__DOT__sx))) 
                                          & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                             >= (IData)(vlTOPp->top_pong__DOT__compY))) 
                                         & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                            < ((IData)(0x30U) 
                                               + (IData)(vlTOPp->top_pong__DOT__compY))));
    vlTOPp->top_pong__DOT__bola = (((((IData)(vlTOPp->top_pong__DOT__sx) 
                                      >= (IData)(vlTOPp->top_pong__DOT__bolaX)) 
                                     & ((IData)(vlTOPp->top_pong__DOT__sx) 
                                        < ((IData)(8U) 
                                           + (IData)(vlTOPp->top_pong__DOT__bolaX)))) 
                                    & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                       >= (IData)(vlTOPp->top_pong__DOT__bolaY))) 
                                   & ((IData)(vlTOPp->top_pong__DOT__sy) 
                                      < ((IData)(8U) 
                                         + (IData)(vlTOPp->top_pong__DOT__bolaY))));
    vlTOPp->top_pong__DOT__next_state = ((0U == vlTOPp->top_pong__DOT__state)
                                          ? 1U : ((1U 
                                                   == vlTOPp->top_pong__DOT__state)
                                                   ? 
                                                  ((IData)(vlTOPp->btn_fire)
                                                    ? 2U
                                                    : 1U)
                                                   : 
                                                  ((2U 
                                                    == vlTOPp->top_pong__DOT__state)
                                                    ? 
                                                   (((IData)(vlTOPp->top_pong__DOT__colEsquerda) 
                                                     | (IData)(vlTOPp->top_pong__DOT__colDireita))
                                                     ? 
                                                    (((5U 
                                                       == (IData)(vlTOPp->top_pong__DOT__scoreEsquerda)) 
                                                      | (5U 
                                                         == (IData)(vlTOPp->top_pong__DOT__scoreDireita)))
                                                      ? 3U
                                                      : 1U)
                                                     : 2U)
                                                    : 
                                                   ((3U 
                                                     == vlTOPp->top_pong__DOT__state)
                                                     ? 
                                                    ((IData)(vlTOPp->btn_fire)
                                                      ? 0U
                                                      : 3U)
                                                     : 0U))));
    if (vlTOPp->sim_rst) {
        vlTOPp->top_pong__DOT__next_state = 0U;
    }
    vlTOPp->top_pong__DOT__simple_score_inst__DOT__pix_addr 
        = (0xfU & ((IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_l_region)
                    ? ((((IData)(vlTOPp->top_pong__DOT__sx) 
                         - (IData)(7U)) >> 2U) + ((IData)(3U) 
                                                  * 
                                                  (((IData)(vlTOPp->top_pong__DOT__sy) 
                                                    - (IData)(8U)) 
                                                   >> 2U)))
                    : ((IData)(vlTOPp->top_pong__DOT__simple_score_inst__DOT__score_r_region)
                        ? ((((IData)(vlTOPp->top_pong__DOT__sx) 
                             - (IData)(0x26aU)) >> 2U) 
                           + ((IData)(3U) * (((IData)(vlTOPp->top_pong__DOT__sy) 
                                              - (IData)(8U)) 
                                             >> 2U)))
                        : 0U)));
    vlTOPp->__Vtableidx1 = (((((0U == (IData)(vlTOPp->top_pong__DOT__sx)) 
                               | (0x27fU == (IData)(vlTOPp->top_pong__DOT__sx))) 
                              | ((0U == (IData)(vlTOPp->top_pong__DOT__sy)) 
                                 | (0x1dfU == (IData)(vlTOPp->top_pong__DOT__sy)))) 
                             << 4U) | (((IData)(vlTOPp->top_pong__DOT__padDireita) 
                                        << 3U) | (((IData)(vlTOPp->top_pong__DOT__padEsquerda) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->top_pong__DOT__bola) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->top_pong__DOT__pix_score)))));
    vlTOPp->top_pong__DOT__paint_r = vlTOPp->__Vtable1_top_pong__DOT__paint_r
        [vlTOPp->__Vtableidx1];
    vlTOPp->top_pong__DOT__paint_g = vlTOPp->__Vtable1_top_pong__DOT__paint_g
        [vlTOPp->__Vtableidx1];
    vlTOPp->top_pong__DOT__paint_b = vlTOPp->__Vtable1_top_pong__DOT__paint_b
        [vlTOPp->__Vtableidx1];
}

VL_INLINE_OPT void Vtop_pong::_combo__TOP__4(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_combo__TOP__4\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_pong__DOT__next_state = ((0U == vlTOPp->top_pong__DOT__state)
                                          ? 1U : ((1U 
                                                   == vlTOPp->top_pong__DOT__state)
                                                   ? 
                                                  ((IData)(vlTOPp->btn_fire)
                                                    ? 2U
                                                    : 1U)
                                                   : 
                                                  ((2U 
                                                    == vlTOPp->top_pong__DOT__state)
                                                    ? 
                                                   (((IData)(vlTOPp->top_pong__DOT__colEsquerda) 
                                                     | (IData)(vlTOPp->top_pong__DOT__colDireita))
                                                     ? 
                                                    (((5U 
                                                       == (IData)(vlTOPp->top_pong__DOT__scoreEsquerda)) 
                                                      | (5U 
                                                         == (IData)(vlTOPp->top_pong__DOT__scoreDireita)))
                                                      ? 3U
                                                      : 1U)
                                                     : 2U)
                                                    : 
                                                   ((3U 
                                                     == vlTOPp->top_pong__DOT__state)
                                                     ? 
                                                    ((IData)(vlTOPp->btn_fire)
                                                      ? 0U
                                                      : 3U)
                                                     : 0U))));
    if (vlTOPp->sim_rst) {
        vlTOPp->top_pong__DOT__next_state = 0U;
    }
}

void Vtop_pong::_eval(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_eval\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_pix) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_pix)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk_pix = vlTOPp->clk_pix;
}

void Vtop_pong::_eval_initial(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_eval_initial\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk_pix = vlTOPp->clk_pix;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vtop_pong::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::final\n"); );
    // Variables
    Vtop_pong__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_pong::_eval_settle(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_eval_settle\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vtop_pong::_change_request(Vtop_pong__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_change_request\n"); );
    Vtop_pong* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop_pong::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_pix & 0xfeU))) {
        Verilated::overWidthError("clk_pix");}
    if (VL_UNLIKELY((sim_rst & 0xfeU))) {
        Verilated::overWidthError("sim_rst");}
    if (VL_UNLIKELY((btn_fire & 0xfeU))) {
        Verilated::overWidthError("btn_fire");}
    if (VL_UNLIKELY((btn_up & 0xfeU))) {
        Verilated::overWidthError("btn_up");}
    if (VL_UNLIKELY((btn_dn & 0xfeU))) {
        Verilated::overWidthError("btn_dn");}
}
#endif  // VL_DEBUG

void Vtop_pong::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pong::_ctor_var_reset\n"); );
    // Body
    clk_pix = VL_RAND_RESET_I(1);
    sim_rst = VL_RAND_RESET_I(1);
    btn_fire = VL_RAND_RESET_I(1);
    btn_up = VL_RAND_RESET_I(1);
    btn_dn = VL_RAND_RESET_I(1);
    sdl_sx = VL_RAND_RESET_I(10);
    sdl_sy = VL_RAND_RESET_I(10);
    sdl_de = VL_RAND_RESET_I(1);
    sdl_r = VL_RAND_RESET_I(8);
    sdl_g = VL_RAND_RESET_I(8);
    sdl_b = VL_RAND_RESET_I(8);
    top_pong__DOT__sx = VL_RAND_RESET_I(10);
    top_pong__DOT__sy = VL_RAND_RESET_I(10);
    top_pong__DOT__frame = VL_RAND_RESET_I(1);
    top_pong__DOT__scoreEsquerda = VL_RAND_RESET_I(4);
    top_pong__DOT__scoreDireita = VL_RAND_RESET_I(4);
    top_pong__DOT__bola = VL_RAND_RESET_I(1);
    top_pong__DOT__padEsquerda = VL_RAND_RESET_I(1);
    top_pong__DOT__padDireita = VL_RAND_RESET_I(1);
    top_pong__DOT__bolaX = VL_RAND_RESET_I(10);
    top_pong__DOT__bolaY = VL_RAND_RESET_I(10);
    top_pong__DOT__bolaVelX = VL_RAND_RESET_I(10);
    top_pong__DOT__bolaVelY = VL_RAND_RESET_I(10);
    top_pong__DOT__contadorRebatidas = VL_RAND_RESET_I(4);
    top_pong__DOT__movDireita = VL_RAND_RESET_I(1);
    top_pong__DOT__movBaixo = VL_RAND_RESET_I(1);
    top_pong__DOT__movAnterior = VL_RAND_RESET_I(1);
    top_pong__DOT__colDireita = VL_RAND_RESET_I(1);
    top_pong__DOT__colEsquerda = VL_RAND_RESET_I(1);
    top_pong__DOT__playY = VL_RAND_RESET_I(10);
    top_pong__DOT__compY = VL_RAND_RESET_I(10);
    top_pong__DOT__state = 0;
    top_pong__DOT__next_state = 0;
    top_pong__DOT__pix_score = VL_RAND_RESET_I(1);
    top_pong__DOT__paint_r = VL_RAND_RESET_I(4);
    top_pong__DOT__paint_g = VL_RAND_RESET_I(4);
    top_pong__DOT__paint_b = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            top_pong__DOT__simple_score_inst__DOT__chars[__Vi0] = VL_RAND_RESET_I(15);
    }}
    top_pong__DOT__simple_score_inst__DOT__char_l = VL_RAND_RESET_I(4);
    top_pong__DOT__simple_score_inst__DOT__char_r = VL_RAND_RESET_I(4);
    top_pong__DOT__simple_score_inst__DOT__score_l_region = VL_RAND_RESET_I(1);
    top_pong__DOT__simple_score_inst__DOT__score_r_region = VL_RAND_RESET_I(1);
    top_pong__DOT__simple_score_inst__DOT__pix_addr = VL_RAND_RESET_I(4);
    __Vtableidx1 = 0;
    __Vtable1_top_pong__DOT__paint_r[0] = 0U;
    __Vtable1_top_pong__DOT__paint_r[1] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[2] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[3] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[4] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[5] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[6] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[7] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[8] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[9] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[10] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[11] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[12] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[13] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[14] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[15] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[16] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[17] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[18] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[19] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[20] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[21] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[22] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[23] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[24] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[25] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[26] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[27] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[28] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[29] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[30] = 0xfU;
    __Vtable1_top_pong__DOT__paint_r[31] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[0] = 0U;
    __Vtable1_top_pong__DOT__paint_g[1] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[2] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[3] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[4] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[5] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[6] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[7] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[8] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[9] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[10] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[11] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[12] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[13] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[14] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[15] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[16] = 0U;
    __Vtable1_top_pong__DOT__paint_g[17] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[18] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[19] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[20] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[21] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[22] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[23] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[24] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[25] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[26] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[27] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[28] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[29] = 0xfU;
    __Vtable1_top_pong__DOT__paint_g[30] = 0xcU;
    __Vtable1_top_pong__DOT__paint_g[31] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[0] = 0U;
    __Vtable1_top_pong__DOT__paint_b[1] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[2] = 0U;
    __Vtable1_top_pong__DOT__paint_b[3] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[4] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[5] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[6] = 0U;
    __Vtable1_top_pong__DOT__paint_b[7] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[8] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[9] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[10] = 0U;
    __Vtable1_top_pong__DOT__paint_b[11] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[12] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[13] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[14] = 0U;
    __Vtable1_top_pong__DOT__paint_b[15] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[16] = 0U;
    __Vtable1_top_pong__DOT__paint_b[17] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[18] = 0U;
    __Vtable1_top_pong__DOT__paint_b[19] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[20] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[21] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[22] = 0U;
    __Vtable1_top_pong__DOT__paint_b[23] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[24] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[25] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[26] = 0U;
    __Vtable1_top_pong__DOT__paint_b[27] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[28] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[29] = 0xfU;
    __Vtable1_top_pong__DOT__paint_b[30] = 0U;
    __Vtable1_top_pong__DOT__paint_b[31] = 0xfU;
}
