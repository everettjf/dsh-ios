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

void ft__PyCode_Validate(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 88)); PB_LDRW(cpu->regs[1], (cpu->regs[0] + 88) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[5], cpu->regs[1]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_196484;
    PB_LDRW(cpu->regs[7], (cpu->regs[0] + 96));
    if (((cpu->regs[7] >> 31) & 1)) goto L_196484;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 100));
    if (((cpu->regs[1] >> 31) & 1)) goto L_196484;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 24));
    if (((cpu->regs[3] >> 31) & 1)) goto L_196484;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    if ((cpu->regs[2])==0) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 27) & 1)) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    if ((cpu->regs[1])==0) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 64));
    if ((cpu->regs[1])==0) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_196484;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 72));
    if ((cpu->regs[4])==0) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_196484;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 80));
    if ((cpu->regs[1])==0) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 168));
    if (!((cpu->regs[6] >> 27) & 1)) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 16));
    FLAG_CMP(cpu->regs[6], cpu->regs[4]);
    if (FLAG_NE) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 8));
    if ((cpu->regs[6])==0) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 168));
    if (!((cpu->regs[6] >> 28) & 1)) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 16));
    if ((cpu->regs[6])==0) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 168));
    if (!((cpu->regs[6] >> 28) & 1)) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 0));
    if ((cpu->regs[6])==0) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 168));
    if (!((cpu->regs[6] >> 28) & 1)) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 48));
    if ((cpu->regs[6])==0) goto L_196484;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 168));
    if (!((cpu->regs[6] >> 27) & 1)) goto L_196484;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 104));
    if ((cpu->regs[0])==0) goto L_196484;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 27) & 1)) goto L_196484;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    cpu->regs[6] = 2147483647ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_GT) goto L_196464;
    cpu->regs[2] = cpu->regs[2] | cpu->regs[0];
    if (((cpu->regs[2] >> 0) & 1)) goto L_196444;
    FLAG_CMP(cpu->regs[4], 0ULL);
    if (FLAG_LE) goto L_19643c;
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 32));
    cpu->regs[2] = ((cpu->regs[2] >> 5) & 0x1ULL);
    cpu->regs[0] = cpu->regs[2];
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_EQ) goto L_196414;
    PB_LDRB(cpu->regs[6], (cpu->regs[1] + 33));
    if (!((cpu->regs[6] >> 5) & 1)) goto L_1963d0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
L_1963d0:
    FLAG_CMP(cpu->regs[4], 2ULL);
    if (FLAG_EQ) goto L_196414;
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 34));
    cpu->regs[2] = ((cpu->regs[2] >> 5) & 0x1ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[2]));
    FLAG_CMP(cpu->regs[4], 3ULL);
    if (FLAG_EQ) goto L_196414;
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[8] = 3ULL;
L_1963f8:
    PB_LDRB(cpu->regs[6], (cpu->regs[1] + cpu->regs[8]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[8] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[6] = ((cpu->regs[6] >> 5) & 0x1ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[6]));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_GT) goto L_1963f8;
L_196414:
    cpu->regs[2] = ((cpu->regs[3] >> 2) & 0x1ULL);
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + cpu->regs[7]));
    cpu->regs[3] = ((cpu->regs[3] >> 3) & 0x1ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - cpu->regs[5]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[3]));
    cpu->regs[0] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LT) goto L_19649c;
L_196434:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_19643c:
    cpu->regs[0] = 0ULL;
    goto L_196414;
L_196444:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 2480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x19645cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_196434;
L_196464:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 2440ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x19647cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_196434;
L_196484:
    cpu->regs[0] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = 356ULL;
    cpu->regs[0] = cpu->regs[0] + 2416ULL;
    cpu->regs[30] = PB_BASE + 0x196494ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_196434;
L_19649c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 2512ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1964b4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_196434;
    /* nop */
}
