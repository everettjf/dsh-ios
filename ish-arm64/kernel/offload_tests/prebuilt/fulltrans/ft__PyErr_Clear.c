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

void ft__PyErr_Clear(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    PB_STR((cpu->regs[1] + 96), 0ULL);
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18d760ULL); return; };
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 40));
    if ((cpu->regs[25])==0) goto L_1d2fac;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_LDR(cpu->regs[23], cpu->regs[21]); cpu->regs[21] += 72;
    cpu->regs[30] = PB_BASE + 0x1d2f48ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + 72));
L_1d2f50:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_GT) goto L_1d2f74;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x121f40ULL); return; };
L_1d2f74:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 104));
    cpu->regs[0] = cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,1); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRB(cpu->regs[26], (cpu->regs[0] + 32));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d2fa0;
L_1d2f90:
    if (!((cpu->regs[26] >> 4) & 1)) goto L_1d2fb8;
L_1d2f94:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    goto L_1d2f50;
L_1d2fa0:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 48));
    if (((cpu->regs[0] >> 0) & 1)) goto L_1d2f90;
    goto L_1d2f94;
L_1d2fac:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_1d2fb8:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 96));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[27] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_STR((SP + 96), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d2fd0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d3030;
L_1d2fd8:
    cpu->regs[27] = cpu->regs[27] << 3;
    PB_LDR(cpu->regs[4], (cpu->regs[21] + cpu->regs[27]));
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(128ULL)));
    if (FLAG_EQ) goto L_1d303c;
    FLAG_CMP((cpu->regs[26]) & (64ULL), 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1d3074;
L_1d2ff4:
    FLAG_CMP(cpu->regs[28], cpu->regs[4]);
    if (FLAG_EQ) goto L_1d30a8;
    if ((cpu->regs[28])==0) goto L_1d30b4;
    PB_LDR(cpu->regs[4], (cpu->regs[21] + cpu->regs[27]));
L_1d3004:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d3014;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
L_1d3014:
    PB_STR((cpu->regs[21] + cpu->regs[27]), cpu->regs[28]);
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1d3020ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[28];
L_1d3024:
    cpu->regs[30] = PB_BASE + 0x1d3028ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18d760ULL);
L_1d3028:
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + 72));
    goto L_1d2f94;
L_1d3030:
    cpu->regs[30] = PB_BASE + 0x1d3034ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121fa0ULL);
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1d2fd8;
    goto L_1d3028;
L_1d303c:
    if ((cpu->regs[4])==0) goto L_1d2ff4;
L_1d3040:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 16));
    FLAG_CMP(cpu->regs[28], cpu->regs[0]);
    if (FLAG_EQ) goto L_1d3024;
    if ((cpu->regs[28])==0) goto L_1d3060;
    PB_LDRW(cpu->regs[1], (cpu->regs[28] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1d3060;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[1]);
L_1d3060:
    PB_STR((cpu->regs[4] + 16), cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1d3068ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1d3070ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1d3028;
L_1d3074:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2872));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1d2ff4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
    PB_STR((SP + 104), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1d309cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x2518acULL);
    PB_LDR(cpu->regs[4], (SP + 104));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d3040;
    goto L_1d2ff4;
L_1d30a8:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1d30b0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1d3028;
L_1d30b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3744));
    cpu->regs[2] = PB_BASE + 0x291000ULL;
    PB_LDR(cpu->regs[3], (SP + 96));
    cpu->regs[2] = cpu->regs[2] + 3144ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d30d4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x24d184ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d30fc;
L_1d30d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[4], (cpu->regs[21] + cpu->regs[27]));
    cpu->regs[28] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1d3014;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1d3004;
L_1d30fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x1d3104ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1d30d8;
    SP = SP - 48ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1d318c;
    cpu->regs[1] = SP;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1d3144ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d31f0;
    cpu->regs[30] = PB_BASE + 0x1d3150ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1d31d0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d31cc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32));
    SP = SP + 48ULL;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x1d3208ULL); return; };
L_1d318c:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[0] = PB_BASE + 0x291000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = cpu->regs[0] + 3184ULL;
    cpu->regs[30] = PB_BASE + 0x1d31acULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x23b310ULL);
L_1d31ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_1d31f8;
    PB_STR((SP + 32), cpu->regs[19]);
L_1d31cc:
    cpu->regs[30] = PB_BASE + 0x1d31d0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d31d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d31e8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[19], (SP + 32));
    goto L_1d31ac;
L_1d31f0:
    PB_LDR(cpu->regs[19], (SP + 32));
    goto L_1d31ac;
L_1d31f8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    SP = SP + 48ULL;
    return;
}
