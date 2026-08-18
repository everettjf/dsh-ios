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

void ft__Py_GetEnv(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17c3d0;
    cpu->regs[0] = 0ULL;
    return;
L_17c3d0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x17c3e0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c010ULL);
    if ((cpu->regs[0])!=0) goto L_17c3f0;
L_17c3e4:
    cpu->regs[0] = 0ULL;
L_17c3e8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_17c3f0:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_17c3e8;
    goto L_17c3e4;
    /* nop */
    PB_LDRB(cpu->regs[4], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[2] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[3] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_17c490;
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 2272));
    cpu->regs[6] = 0ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3472));
    cpu->regs[9] = 95ULL;
L_17c42c:
    PB_LDRW(cpu->regs[5], (cpu->regs[7] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[4])) << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(46ULL)));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_17c480;
L_17c440:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    cpu->regs[5] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[5]))) & (((uint32_t)(cpu->regs[6]))), 0);
    if (FLAG_NE) goto L_17c49c;
L_17c450:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_17c4ac;
    PB_LDRB(cpu->regs[4], (cpu->regs[8] + cpu->regs[4]));
    PB_STRB(cpu->regs[3], cpu->regs[4]); cpu->regs[3] += 1;
    cpu->regs[0] += 1; PB_LDRB(cpu->regs[4], cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_17c490;
    PB_LDRW(cpu->regs[5], (cpu->regs[7] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[4])) << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(46ULL)));
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_17c440;
L_17c480:
    cpu->regs[0] += 1; PB_LDRB(cpu->regs[4], cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_17c490;
    cpu->regs[6] = 1ULL;
    goto L_17c42c;
L_17c490:
    cpu->regs[0] = 1ULL;
    PB_STRB((cpu->regs[3] + 0), 0ULL);
    return;
L_17c49c:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_17c4ac;
    PB_STRB(cpu->regs[3], cpu->regs[9]); cpu->regs[3] += 1;
    goto L_17c450;
L_17c4ac:
    cpu->regs[0] = 0ULL;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = PB_BASE + 0x51d000ULL;
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 3600));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17c570;
    cpu->regs[19] = PB_BASE + 0x450000ULL;
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 192));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GE) goto L_17c604;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + (cpu->regs[0] << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(45ULL)));
    if (FLAG_NE) goto L_17c604;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 4));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_17c604;
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 472ULL;
    cpu->regs[30] = PB_BASE + 0x17c528ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7b720ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 192));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c5fc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 488ULL;
    cpu->regs[30] = PB_BASE + 0x17c540ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b720ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 192));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c780;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 520ULL;
    cpu->regs[30] = PB_BASE + 0x17c558ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b720ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 192));
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c6fc;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + (cpu->regs[1] << 3)));
    PB_STR((cpu->regs[19] + 192), cpu->regs[2]);
    cpu->regs[3] = cpu->regs[3] + 4ULL;
L_17c570:
    PB_LDRW(cpu->regs[19], (cpu->regs[3] + 0));
    cpu->regs[0] = cpu->regs[3] + 4ULL;
    PB_STR((cpu->regs[22] + 3600), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_17c604;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(45ULL)));
    if (FLAG_EQ) goto L_17c6bc;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(74ULL)));
    if (FLAG_EQ) goto L_17c688;
    cpu->regs[0] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 560ULL;
    cpu->regs[30] = PB_BASE + 0x17c5a0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7ae90ULL);
    if ((cpu->regs[0])==0) goto L_17c658;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(58ULL)));
    if (FLAG_NE) goto L_17c5e4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 3600));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_17c61c;
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 192));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LE) goto L_17c60c;
    cpu->regs[3] = PB_BASE + 0x5ac000ULL;
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[1] << 3)));
    PB_STR((cpu->regs[3] + 3800), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 192), cpu->regs[2]);
L_17c5e4:
    cpu->regs[0] = cpu->regs[19];
L_17c5e8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_17c5fc:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 192), cpu->regs[1]);
L_17c604:
    cpu->regs[0] = 4294967295ULL;
    goto L_17c5e8;
L_17c60c:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 200));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17c634;
L_17c614:
    cpu->regs[0] = 95ULL;
    goto L_17c5e8;
L_17c61c:
    cpu->regs[1] = PB_BASE + 0x5ac000ULL;
    cpu->regs[2] = PB_BASE + 0x2b4000ULL;
    cpu->regs[2] = cpu->regs[2] + 480ULL;
    PB_STR((cpu->regs[22] + 3600), cpu->regs[2]);
    PB_STR((cpu->regs[1] + 3800), cpu->regs[0]);
    goto L_17c5e4;
L_17c634:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] & 255ULL));
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x17c650ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = 95ULL;
    goto L_17c5e8;
L_17c658:
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 208));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c614;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] & 255ULL));
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[1] + 2832ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x17c680ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = 95ULL;
    goto L_17c5e8;
L_17c688:
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 208));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c614;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x281000ULL;
    cpu->regs[2] = 26ULL;
    cpu->regs[0] = cpu->regs[0] + 2800ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x17c6b4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7b510ULL);
    cpu->regs[0] = 95ULL;
    goto L_17c5e8;
L_17c6bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 4));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c708;
    cpu->regs[19] = PB_BASE + 0x3d9000ULL;
    cpu->regs[19] = cpu->regs[19] + 2304ULL;
    cpu->regs[24] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
L_17c6d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_17c744;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 3600));
    cpu->regs[30] = PB_BASE + 0x17c6e8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c73c;
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    cpu->regs[19] = cpu->regs[24] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 4);
    goto L_17c6d4;
L_17c6fc:
    cpu->regs[0] = 86ULL;
    PB_STR((cpu->regs[19] + 192), cpu->regs[2]);
    goto L_17c5e8;
L_17c708:
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 208));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c604;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x281000ULL;
    cpu->regs[2] = 21ULL;
    cpu->regs[0] = cpu->regs[0] + 2712ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x17c734ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b510ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_17c5e8;
L_17c73c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])!=0) goto L_17c790;
L_17c744:
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 200));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_17c614;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 192));
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    cpu->regs[1] = cpu->regs[1] + 2736ULL;
    cpu->regs[2] = cpu->regs[20] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + -8));
    cpu->regs[30] = PB_BASE + 0x17c778ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = 95ULL;
    goto L_17c5e8;
L_17c780:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = 104ULL;
    PB_STR((cpu->regs[19] + 192), cpu->regs[1]);
    goto L_17c5e8;
L_17c790:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x2b4000ULL;
    cpu->regs[0] = cpu->regs[0] + 480ULL;
    PB_STR((cpu->regs[22] + 3600), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_17c7d4;
    cpu->regs[2] = PB_BASE + 0x450000ULL;
    cpu->regs[2] = cpu->regs[2] + 8ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 192));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LE) goto L_17c7dc;
    cpu->regs[3] = PB_BASE + 0x5ac000ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 12));
    PB_LDR(cpu->regs[4], (cpu->regs[20] + (cpu->regs[1] << 3)));
    PB_STR((cpu->regs[3] + 3800), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[2] + 192), cpu->regs[1]);
    goto L_17c5e8;
L_17c7d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 12));
    goto L_17c5e8;
L_17c7dc:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 200));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_17c614;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = cpu->regs[20] + (cpu->regs[1] << 3);
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[1] + 2760ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x17c804ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = 95ULL;
    goto L_17c5e8;
}
