/* AUTO-GENERATED prebuilt-gadget spec_fn for guest `_PyToken_OneChar` — DO NOT EDIT.
 * Source: /tmp/pyroot/fs/usr/lib/debug/usr/lib/libpython3.12.so.1.0.debug  addr 0xef9ab4e0
 * Produced by tools/prebuilt_gadget_gen/gen.sh (guest asm -> equivalent C).
 * Compiled only with -Doffload_test_prebuilt=true. */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"
#include "kernel/native_offload.h"  /* prebuilt_call for bl/blr sites */

static uint64_t ror64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }
static uint64_t g_fa, g_fb;
static double fr[32];   /* float/double register file (s/d regs) */
/* FCMP: encode float ordering into g_fa/g_fb so the integer FLAG_* macros
 * that follow a fcmp read the right branch. sign(lhs-rhs) → (1,0)/(0,1)/(0,0);
 * NaN (unordered) → (0,1): gt/ge false, matching AArch64 fcmp semantics. */
#define FCMP(x,y) do { double _dx=(x), _dy=(y); \
    if (_dx < _dy) { g_fa=0; g_fb=1; } \
    else if (_dx > _dy) { g_fa=1; g_fb=0; } \
    else if (_dx == _dy) { g_fa=0; g_fb=0; } \
    else { g_fa=0; g_fb=1; } } while(0)   /* NaN */
#define FLAG_CMP(x,y) do { g_fa=(x); g_fb=(y); } while(0)
#define FLAG_EQ (g_fa == g_fb)
#define FLAG_NE (g_fa != g_fb)
#define FLAG_GT ((int64_t)g_fa >  (int64_t)g_fb)   /* signed */
#define FLAG_LT ((int64_t)g_fa <  (int64_t)g_fb)
#define FLAG_GE ((int64_t)g_fa >= (int64_t)g_fb)
#define FLAG_LE ((int64_t)g_fa <= (int64_t)g_fb)
#define FLAG_HI (g_fa >  g_fb)                     /* unsigned */
#define FLAG_LO (g_fa <  g_fb)
#define FLAG_HS (g_fa >= g_fb)
#define FLAG_LS (g_fa <= g_fb)
#define SP (cpu->sp)                               /* stack pointer */
/* PB_BASE: library load base = runtime addr (0xef9ab4e0) - file offset (0x00000000000874e0).
 * adrp/adr targets (file-absolute in the disassembly) resolve to
 * PB_BASE + target at runtime. No-ASLR makes this constant. */
extern uint64_t g_ft_base;
#define PB_BASE g_ft_base
/* Memory ops go through the guest TLB (fork/CoW safe). 64/32-bit + byte. */
#define PB_LDR(dst, addr)  do { uint64_t _v=0; tlb_read (tlb,(addr),&_v,8); (dst)=_v; } while(0)
#define PB_STR(addr, val)  do { uint64_t _v=(val); tlb_write(tlb,(addr),&_v,8); } while(0)
#define PB_LDRW(dst, addr) do { uint32_t _v=0; tlb_read (tlb,(addr),&_v,4); (dst)=_v; } while(0)
#define PB_STRW(addr, val) do { uint32_t _v=(uint32_t)(val); tlb_write(tlb,(addr),&_v,4); } while(0)
#define PB_LDRB(dst, addr) do { uint8_t  _b=0; tlb_read (tlb,(addr),&_b,1); (dst)=_b; } while(0)
#define PB_STRB(addr, val) do { uint8_t  _b=(uint8_t)(val); tlb_write(tlb,(addr),&_b,1); } while(0)
#define PB_LDRH(dst, addr) do { uint16_t _h=0; tlb_read (tlb,(addr),&_h,2); (dst)=_h; } while(0)
#define PB_STRH(addr, val) do { uint16_t _h=(uint16_t)(val); tlb_write(tlb,(addr),&_h,2); } while(0)
/* Inline-cache call: if the callee (guest addr `tgt`) has a translated
 * spec_fn, call it directly (stays in host code, no interpreter round-
 * trip); otherwise fall back to prebuilt_call (nested dispatch). Each
 * call site has its own static IC slot keyed by the last target. */
#define PB_CALL(id, cpu, tlb, tgt) do {                       \
    static addr_t _ic_tgt##id = 0; static prebuilt_fn _ic_fn##id = 0; \
    addr_t _t = (tgt);                                        \
    if (_t == _ic_tgt##id && _ic_fn##id) { _ic_fn##id(cpu, tlb); } \
    else { prebuilt_fn _f = native_offload_prebuilt_lookup(_t);\
           if (_f) { _ic_tgt##id = _t; _ic_fn##id = _f; _f(cpu, tlb); } \
           else { prebuilt_call(cpu, tlb, _t); } }            \
  } while(0)

void ft_PyEval_ReleaseThread(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92020ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x182b00ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_92040;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[0] + 976ULL;
    cpu->regs[1] = cpu->regs[1] + 1384ULL;
    cpu->regs[30] = PB_BASE + 0x92040ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x91ebcULL);
L_92040:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] + 368ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x14770cULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x92078ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x91ebcULL);
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x92090ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x92000ULL;
    cpu->regs[0] = cpu->regs[0] + 120ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_920d4;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x920bcULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x920ccULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_920d8;
    goto L_9211c;
L_920d4:
    cpu->regs[20] = 0ULL;
L_920d8:
    cpu->regs[22] = cpu->regs[19] + 16ULL;
    cpu->regs[21] = 0ULL;
L_920e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[21] << 3)));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x920ecULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdce4cULL);
    FLAG_CMP(cpu->regs[21], 32ULL);
    if (FLAG_NE) goto L_920e0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x92104ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[20])==0) goto L_9211c;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0xdce80ULL); return; };
L_9211c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x92148ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x92000ULL;
    cpu->regs[0] = cpu->regs[0] + 300ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_9218c;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x92174ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x92184ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_92190;
    goto L_921e0;
L_9218c:
    cpu->regs[21] = 0ULL;
L_92190:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_921a0;
    cpu->regs[22] = cpu->regs[19] + 32ULL;
    goto L_921c8;
L_921a0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x921b0ULL; PB_CALL(14, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[21])==0) goto L_921e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0xdce80ULL); return; };
L_921c8:
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_921a0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x921dcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_921c8;
L_921e0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
L_9220c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x92214ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xf6800ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_92250;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967263ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 65ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_LS) goto L_92260;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_92260;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    cpu->regs[0] = 127ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[21] = (FLAG_LE) ? 1 : 0;
    goto L_92264;
L_92250:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_92260;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_9220c;
L_92260:
    cpu->regs[21] = 0ULL;
L_92264:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9226cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xf71a0ULL);
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_EQ) goto L_9227c;
    cpu->regs[19] += -1; PB_LDRB(cpu->regs[1], cpu->regs[19]);
    goto L_92264;
L_9227c:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
