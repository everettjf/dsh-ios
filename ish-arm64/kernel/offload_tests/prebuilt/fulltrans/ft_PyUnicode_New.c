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

void ft_PyUnicode_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[0])==0) goto L_df700;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_df64c;
    if (((cpu->regs[0] >> 63) & 1)) goto L_df7b4;
    cpu->regs[0] = 18446744073709551574ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GT) goto L_df6a4;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = cpu->regs[19] + 41ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[21] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0xdf5ecULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_df6a4;
    cpu->regs[20] = 1ULL;
    cpu->regs[22] = cpu->regs[20];
L_df5f8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]);
    if (((cpu->regs[2] >> 9) & 1)) goto L_df6ec;
L_df60c:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 2708));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_df7a4;
L_df614:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_df6b4;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[19];
    cpu->regs[20] = ((uint32_t)(((cpu->regs[20] & 0x3fULL) << 2)));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] | 96ULL));
    cpu->regs[2] = 18446744073709551615ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[2]);
    PB_STRB((cpu->regs[0] + 32), cpu->regs[20]);
    PB_STRB((cpu->regs[1] + 40), 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_df640:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_df64c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_df748;
    cpu->regs[0] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LS) goto L_df730;
    cpu->regs[0] = 1114111ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_df778;
    if (((cpu->regs[19] >> 63) & 1)) goto L_df7b4;
    cpu->regs[1] = 4ULL;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = 2305843009213693936ULL;
L_df67c:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GT) goto L_df6a4;
    cpu->regs[1] = cpu->regs[19] * cpu->regs[1] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 56ULL;
L_df68c:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[21] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0xdf6a0ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])!=0) goto L_df5f8;
L_df6a4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_df6b4:
    cpu->regs[1] = ((uint32_t)(((cpu->regs[20] & 0x3fULL) << 2)));
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 32ULL));
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0] + 56ULL;
    PB_STRB((cpu->regs[0] + 32), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_df768;
    PB_STR((cpu->regs[0] + 40), 0ULL); PB_STR((cpu->regs[0] + 40) + 8, 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_df724;
    PB_STRW((cpu->regs[2] + (cpu->regs[19] << 2)), 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_df640;
L_df6ec:
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_df60c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    goto L_df60c;
L_df700:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = cpu->regs[21] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 8080));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_df79c;
L_df718:
    cpu->regs[0] = 24464ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    goto L_df640;
L_df724:
    PB_STRH((cpu->regs[2] + (cpu->regs[19] << 1)), 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_df640;
L_df730:
    if (((cpu->regs[19] >> 63) & 1)) goto L_df7b4;
    cpu->regs[0] = 18446744073709551586ULL;
    cpu->regs[1] = 2ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x3fffULL & 0xffff) << 48);
    cpu->regs[20] = cpu->regs[1];
    goto L_df67c;
L_df748:
    if (((cpu->regs[0] >> 63) & 1)) goto L_df7b4;
    cpu->regs[0] = 18446744073709551558ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GT) goto L_df6a4;
    cpu->regs[1] = cpu->regs[19] + 57ULL;
    cpu->regs[20] = 1ULL;
    goto L_df68c;
L_df768:
    PB_STRB((cpu->regs[2] + cpu->regs[19]), 0ULL);
    PB_STR((cpu->regs[0] + 40), 0ULL); PB_STR((cpu->regs[0] + 40) + 8, 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_df640;
L_df778:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1584ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xdf790ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_df790:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    goto L_df640;
L_df79c:
    PB_STRW((cpu->regs[1] + 8080), cpu->regs[0]);
    goto L_df718;
L_df7a4:
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xdf7acULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    goto L_df614;
L_df7b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1640ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xdf7ccULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_df790;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[2];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    FLAG_CMP((cpu->regs[0]) & (7ULL), 0);
    if (FLAG_NE) goto L_df934;
    cpu->regs[3] = cpu->regs[0] + 8ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LO) goto L_df90c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP((cpu->regs[2]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_df90c;
    cpu->regs[4] = cpu->regs[6];
    cpu->regs[5] = cpu->regs[0] + 16ULL;
    PB_STR(cpu->regs[4], cpu->regs[2]); cpu->regs[4] += 8;
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_LO) goto L_df868;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    FLAG_CMP((cpu->regs[2]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_df868;
    cpu->regs[3] = cpu->regs[0] + 24ULL;
    PB_STR((cpu->regs[6] + 8), cpu->regs[2]);
    cpu->regs[6] = cpu->regs[6] + 16ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LO) goto L_df92c;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + -8));
    FLAG_CMP((cpu->regs[4]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_df860;
L_df840:
    cpu->regs[5] = cpu->regs[3] + 8ULL;
    PB_STR(cpu->regs[6], cpu->regs[4]); cpu->regs[6] += 8;
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_HI) goto L_df86c;
    cpu->regs[3] = cpu->regs[5];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + -8));
    FLAG_CMP((cpu->regs[4]) & (9259542123273814144ULL), 0);
    if (FLAG_EQ) goto L_df840;
L_df860:
    cpu->regs[3] = cpu->regs[3] - 8ULL;
    goto L_df86c;
L_df868:
    cpu->regs[6] = cpu->regs[4];
L_df86c:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_df918;
L_df874:
    PB_LDRB(cpu->regs[5], (cpu->regs[3] + 0));
    if (((cpu->regs[5] >> 7) & 1)) goto L_dfa74;
    cpu->regs[4] = cpu->regs[3] + 1ULL;
    PB_STRB((cpu->regs[6] + 0), cpu->regs[5]);
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LS) goto L_df904;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 1));
    if (((cpu->regs[2] >> 7) & 1)) goto L_dfa78;
    cpu->regs[4] = cpu->regs[3] + 2ULL;
    PB_STRB((cpu->regs[6] + 1), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LS) goto L_df904;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 2));
    if (((cpu->regs[2] >> 7) & 1)) goto L_dfa78;
    cpu->regs[4] = cpu->regs[3] + 3ULL;
    PB_STRB((cpu->regs[6] + 2), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LS) goto L_df904;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 3));
    if (((cpu->regs[2] >> 7) & 1)) goto L_dfa78;
    cpu->regs[4] = cpu->regs[3] + 4ULL;
    PB_STRB((cpu->regs[6] + 3), cpu->regs[2]);
    cpu->regs[3] = cpu->regs[6] + 4ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LS) goto L_df904;
L_df8d8:
    PB_LDRB(cpu->regs[2], (cpu->regs[4] + 0));
    if (((cpu->regs[2] >> 7) & 1)) goto L_dfa78;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_STRB(cpu->regs[3], cpu->regs[2]); cpu->regs[3] += 1;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_NE) goto L_df8d8;
L_df8f0:
    cpu->regs[19] = cpu->regs[1] - cpu->regs[0];
L_df8f4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_df904:
    cpu->regs[1] = cpu->regs[4];
    goto L_df8f0;
L_df90c:
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_HI) goto L_df874;
L_df918:
    cpu->regs[19] = cpu->regs[3] - cpu->regs[0];
L_df91c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_df92c:
    cpu->regs[3] = cpu->regs[5];
    goto L_df86c;
L_df934:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[19] = 0ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_df980;
L_df948:
    FLAG_CMP((cpu->regs[3]) & (7ULL), 0);
    if (FLAG_EQ) goto L_df990;
    do { int8_t _s=0; tlb_read(tlb,cpu->regs[3],&_s,1); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[2] >> 31) & 1)) goto L_df964;
L_df958:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_HI) goto L_df948;
L_df964:
    cpu->regs[19] = cpu->regs[3] - cpu->regs[0];
    cpu->regs[2] = cpu->regs[19];
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_LS) goto L_dfa58;
    cpu->regs[1] = cpu->regs[6] + cpu->regs[19];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_dfa60;
L_df980:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0xdf98cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_df8f4;
L_df990:
    cpu->regs[2] = cpu->regs[3] + 8ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LO) goto L_dfa6c;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    FLAG_CMP((cpu->regs[4]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_dfa6c;
    cpu->regs[4] = cpu->regs[3] + 16ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LO) goto L_dfa40;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 8));
    FLAG_CMP((cpu->regs[5]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_dfa40;
    cpu->regs[2] = cpu->regs[3] + 24ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LO) goto L_dfa64;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 16));
    FLAG_CMP((cpu->regs[5]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_dfa64;
    cpu->regs[4] = cpu->regs[3] + 32ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LO) goto L_dfa40;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 24));
    FLAG_CMP((cpu->regs[5]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_dfa40;
    cpu->regs[2] = cpu->regs[3] + 40ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LO) goto L_dfa64;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 32));
    FLAG_CMP((cpu->regs[5]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_dfa64;
    cpu->regs[4] = cpu->regs[3] + 48ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LO) goto L_dfa40;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 40));
    FLAG_CMP((cpu->regs[3]) & (9259542123273814144ULL), 0);
    if (FLAG_EQ) goto L_dfa30;
    goto L_dfa40;
L_dfa24:
    PB_LDR(cpu->regs[3], (cpu->regs[4] + -8));
    FLAG_CMP((cpu->regs[3]) & (9259542123273814144ULL), 0);
    if (FLAG_NE) goto L_dfa40;
L_dfa30:
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[4] = cpu->regs[4] + 8ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_LS) goto L_dfa24;
L_dfa40:
    cpu->regs[3] = cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_EQ) goto L_df964;
    do { int8_t _s=0; tlb_read(tlb,cpu->regs[2],&_s,1); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_df958;
    goto L_df964;
L_dfa58:
    if (FLAG_LO) { FLAG_CMP(cpu->regs[3], cpu->regs[6]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_df980;
L_dfa60:
    __builtin_trap();
L_dfa64:
    cpu->regs[2] = cpu->regs[4];
    goto L_dfa40;
L_dfa6c:
    cpu->regs[2] = cpu->regs[3];
    goto L_dfa40;
L_dfa74:
    cpu->regs[4] = cpu->regs[3];
L_dfa78:
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[19] = cpu->regs[3] - cpu->regs[0];
    goto L_df91c;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_dfa94;
    goto L_dfaa0;
L_dfa94:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    return;
L_dfaa0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_dfb04;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 32));
    cpu->regs[3] = ((uint32_t)(((cpu->regs[5] >> 2) & 0x7ULL)));
    cpu->regs[6] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_dfb04;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if (!((cpu->regs[5] >> 5) & 1)) goto L_dfb38;
    if (!((cpu->regs[5] >> 6) & 1)) goto L_dfb28;
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    if (!((cpu->regs[4] >> 5) & 1)) goto L_dfb30;
L_dfae0:
    if (!((cpu->regs[4] >> 6) & 1)) goto L_dfb0c;
    cpu->regs[3] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] + 40ULL;
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xdfaf4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7ab70ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
L_dfafc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_dfb04:
    cpu->regs[0] = 0ULL;
    return;
L_dfb0c:
    cpu->regs[1] = cpu->regs[1] + 56ULL;
L_dfb10:
    cpu->regs[3] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xdfb1cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7ab70ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_dfafc;
L_dfb28:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    if (((cpu->regs[4] >> 5) & 1)) goto L_dfae0;
L_dfb30:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 56));
    goto L_dfb10;
L_dfb38:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    if (((cpu->regs[4] >> 5) & 1)) goto L_dfae0;
    goto L_dfb30;
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 32));
    if (((cpu->regs[0] >> 7) & 1)) goto L_dfcd0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 32));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 3ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_dfbf0;
L_dfb64:
    cpu->regs[3] = ((uint32_t)(((cpu->regs[2] >> 5) & 0x1ULL)));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_dfba4;
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_dfc58;
L_dfb70:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0xdf000ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 320));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_dfc7c;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_dfba4:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 48));
    if ((cpu->regs[0])!=0) goto L_dfbbc;
L_dfbac:
    if (((cpu->regs[2] >> 5) & 1)) goto L_dfb70;
L_dfbb0:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 56));
    if ((cpu->regs[0])!=0) goto L_dfc6c;
    goto L_dfb70;
L_dfbbc:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_dfc60;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[3] = cpu->regs[1] + 40ULL;
    cpu->regs[2] = cpu->regs[1] + 56ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[3];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_dfb70;
L_dfbd8:
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xdfbe0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdfce0ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 32));
    if (((cpu->regs[2] >> 5) & 1)) goto L_dfb70;
    goto L_dfbb0;
L_dfbf0:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_dfcc4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_dfc08;
    cpu->regs[0] = 3ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
L_dfc08:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xdfc1cULL; PB_CALL(11, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22488));
    cpu->regs[30] = PB_BASE + 0xdfc34ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x197f6cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDR(cpu->regs[1], (SP + 24));
    if (FLAG_EQ) goto L_dfc98;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_dfc8c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 32));
    PB_STR((cpu->regs[1] + 0), 0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 32));
    goto L_dfb64;
L_dfc58:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 48));
    if ((cpu->regs[0])==0) goto L_dfbac;
L_dfc60:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 56));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_dfbd8;
L_dfc6c:
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xdfc74ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdfce0ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    goto L_dfb70;
L_dfc7c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_dfc8c:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 32));
    goto L_dfb64;
L_dfc98:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xdfca0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1fa20cULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[2] = 2ULL;
    cpu->regs[3] = 4294967295ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 32));
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~0x3ULL) | ((cpu->regs[2] >> 0) & 0x3ULL))));
    PB_STRW((cpu->regs[1] + 32), cpu->regs[0]);
L_dfcbc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_dfcc4:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_dfcbc;
L_dfcd0:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    return;
    /* nop */
}
