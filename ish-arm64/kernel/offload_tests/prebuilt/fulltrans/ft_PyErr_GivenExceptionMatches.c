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

void ft_PyErr_GivenExceptionMatches(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_121d90:
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_121ec0;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_121e5c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    if (!((cpu->regs[3] >> 30) & 1)) goto L_121ea8;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_121efc;
    if (!((cpu->regs[0] >> 31) & 1)) goto L_121efc;
L_121dd4:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 30) & 1)) goto L_121efc;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 344));
    if ((cpu->regs[0])==0) goto L_121ed8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_121e4c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_EQ) goto L_121e98;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_121e4c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_EQ) goto L_121e98;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_121e4c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 40));
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_EQ) goto L_121e98;
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_EQ) goto L_121e4c;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[3] = 3ULL;
L_121e34:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + (cpu->regs[3] << 3)));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_EQ) goto L_121e98;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_121e34;
L_121e4c:
    cpu->regs[0] = 0ULL;
L_121e50:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_121e5c:
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = 0ULL;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x121e70ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x10e664ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1] + 24ULL;
L_121e7c:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_GE) goto L_121ed0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + (cpu->regs[21] << 3)));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x121e90ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x121d90ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121ec8;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_121e98:
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_121ea8:
    if (!((cpu->regs[3] >> 31) & 1)) goto L_121f00;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 168));
    if (!((cpu->regs[2] >> 30) & 1)) goto L_121f00;
    if (!((cpu->regs[0] >> 31) & 1)) goto L_121f00;
    cpu->regs[2] = cpu->regs[20];
    goto L_121dd4;
L_121ec0:
    cpu->regs[0] = 0ULL;
    return;
L_121ec8:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_121e7c;
L_121ed0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_121e4c;
L_121ed8:
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_EQ) goto L_121e98;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 256));
    if ((cpu->regs[2])!=0) goto L_121ed8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_121e50;
L_121efc:
    cpu->regs[20] = cpu->regs[2];
L_121f00:
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_121e50;
}
