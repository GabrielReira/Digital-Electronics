// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_PONG_H_
#define _VTOP_PONG_H_  // guard

#include "verilated.h"

//==========

class Vtop_pong__Syms;

//----------

VL_MODULE(Vtop_pong) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_pix,0,0);
    VL_IN8(sim_rst,0,0);
    VL_IN8(btn_fire,0,0);
    VL_IN8(btn_up,0,0);
    VL_IN8(btn_dn,0,0);
    VL_OUT8(sdl_de,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    VL_OUT16(sdl_sx,9,0);
    VL_OUT16(sdl_sy,9,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top_pong__DOT__frame;
    CData/*3:0*/ top_pong__DOT__scoreEsquerda;
    CData/*3:0*/ top_pong__DOT__scoreDireita;
    CData/*0:0*/ top_pong__DOT__bola;
    CData/*0:0*/ top_pong__DOT__padEsquerda;
    CData/*0:0*/ top_pong__DOT__padDireita;
    CData/*3:0*/ top_pong__DOT__contadorRebatidas;
    CData/*0:0*/ top_pong__DOT__movDireita;
    CData/*0:0*/ top_pong__DOT__movBaixo;
    CData/*0:0*/ top_pong__DOT__movAnterior;
    CData/*0:0*/ top_pong__DOT__colDireita;
    CData/*0:0*/ top_pong__DOT__colEsquerda;
    CData/*0:0*/ top_pong__DOT__pix_score;
    CData/*3:0*/ top_pong__DOT__paint_r;
    CData/*3:0*/ top_pong__DOT__paint_g;
    CData/*3:0*/ top_pong__DOT__paint_b;
    CData/*3:0*/ top_pong__DOT__simple_score_inst__DOT__char_l;
    CData/*3:0*/ top_pong__DOT__simple_score_inst__DOT__char_r;
    CData/*0:0*/ top_pong__DOT__simple_score_inst__DOT__score_l_region;
    CData/*0:0*/ top_pong__DOT__simple_score_inst__DOT__score_r_region;
    CData/*3:0*/ top_pong__DOT__simple_score_inst__DOT__pix_addr;
    SData/*9:0*/ top_pong__DOT__sx;
    SData/*9:0*/ top_pong__DOT__sy;
    SData/*9:0*/ top_pong__DOT__bolaX;
    SData/*9:0*/ top_pong__DOT__bolaY;
    SData/*9:0*/ top_pong__DOT__bolaVelX;
    SData/*9:0*/ top_pong__DOT__bolaVelY;
    SData/*9:0*/ top_pong__DOT__playY;
    SData/*9:0*/ top_pong__DOT__compY;
    IData/*31:0*/ top_pong__DOT__state;
    IData/*31:0*/ top_pong__DOT__next_state;
    SData/*14:0*/ top_pong__DOT__simple_score_inst__DOT__chars[10];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*4:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk_pix;
    static CData/*3:0*/ __Vtable1_top_pong__DOT__paint_r[32];
    static CData/*3:0*/ __Vtable1_top_pong__DOT__paint_g[32];
    static CData/*3:0*/ __Vtable1_top_pong__DOT__paint_b[32];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_pong__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_pong);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop_pong(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_pong();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop_pong__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_pong__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop_pong__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vtop_pong__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop_pong__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop_pong__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop_pong__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vtop_pong__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtop_pong__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop_pong__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
