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

void ft_PyException_SetTraceback(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = 0ULL;
    goto L_12246c;
L_12246c:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])==0) goto L_12253c;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2432));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_1224d4;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 40));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_122530;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[0] + 40), cpu->regs[1]);
    if ((cpu->regs[3])==0) goto L_1224bc;
L_1224a8:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1224bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1224c8;
L_1224bc:
    cpu->regs[0] = 0ULL;
L_1224c0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1224c8:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1224d0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1224bc;
L_1224d4:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_122510;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    if ((cpu->regs[2])==0) goto L_1224bc;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[0] + 40), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1224bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1224bc;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12250cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1224bc;
L_122510:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x122528ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1224c0;
L_122530:
    PB_STR((cpu->regs[0] + 40), cpu->regs[1]);
    if ((cpu->regs[3])!=0) goto L_1224a8;
    goto L_1224bc;
L_12253c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1760ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x122554ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1224c0;
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 26) & 1)) goto L_122580;
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1225b0;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 30) & 1)) goto L_1225b0;
L_122578:
    cpu->regs[0] = 0ULL;
    return;
L_122580:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    cpu->regs[1] = cpu->regs[1] + 24ULL;
    cpu->regs[2] = 0ULL;
L_12258c:
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_GE) goto L_122578;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 168));
    if (!((cpu->regs[4] >> 31) & 1)) goto L_1225b0;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (((cpu->regs[3] >> 30) & 1)) goto L_12258c;
L_1225b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    cpu->regs[29] = SP;
    cpu->regs[2] = cpu->regs[2] + 1848ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1225d0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -16));
    if ((cpu->regs[1])==0) goto L_1226e8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    cpu->regs[3] = PB_BASE + 0x122000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 48));
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[3] + 1504ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_122700;
L_122638:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x12264cULL; PB_CALL(6, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[20])==0) goto L_122714;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 152));
    cpu->regs[2] = cpu->regs[20] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_122728;
L_122664:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_122688;
L_122674:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_122688;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1226d8;
L_122688:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1226a4;
L_122690:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1226a4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1226e0;
L_1226a4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1226acULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    if ((cpu->regs[20])==0) goto L_1226cc;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1226cc;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 160));
    if ((cpu->regs[2])!=0) goto L_122744;
L_1226cc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1226d8:
    cpu->regs[30] = PB_BASE + 0x1226dcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_122688;
L_1226e0:
    cpu->regs[30] = PB_BASE + 0x1226e4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1226a4;
L_1226e8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x122000ULL;
    cpu->regs[0] = cpu->regs[0] + 1504ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_122638;
L_122700:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    if ((cpu->regs[20])==0) goto L_122780;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    goto L_122674;
L_122714:
    cpu->regs[30] = PB_BASE + 0x122718ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c39cULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_122664;
L_122728:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 8), cpu->regs[19]);
    goto L_1226cc;
L_122744:
    PB_STRW((cpu->regs[20] + 152), cpu->regs[1]);
L_122748:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])==0) goto L_122770;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[20] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x122768ULL; PB_CALL(11, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 160));
    goto L_122748;
L_122770:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 152), cpu->regs[0]);
    goto L_1226cc;
L_122780:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_122690;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(12, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
    /* nop */
    /* nop */
}
