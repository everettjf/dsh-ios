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

void ft_PyType_FromSpec(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    goto L_18d7a4;
L_18d7a4:
    SP += -144; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[3];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[2] + 24));
    PB_STR((SP + 96), 0ULL);
    PB_STR((SP + 120), 0ULL); PB_STR((SP + 120) + 8, cpu->regs[0]);
    PB_STRW((SP + 140), cpu->regs[4]);
L_18d7e8:
    PB_LDRW(cpu->regs[25], (cpu->regs[28] + 0));
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_18d884;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(81ULL)));
    if (FLAG_HI) goto L_18de7c;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(56ULL)));
    if (FLAG_EQ) goto L_18d920;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(72ULL)));
    if (FLAG_EQ) goto L_18d810;
L_18d808:
    cpu->regs[28] = cpu->regs[28] + 16ULL;
    goto L_18d7e8;
L_18d810:
    if ((cpu->regs[22])!=0) goto L_18de50;
    PB_LDR(cpu->regs[21], (cpu->regs[28] + 8));
    cpu->regs[26] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[26] = cpu->regs[26] + 1976ULL;
    cpu->regs[0] = cpu->regs[0] + 2000ULL;
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 2016ULL;
    PB_STR((SP + 112), cpu->regs[0]);
L_18d838:
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 0));
    if ((cpu->regs[25])==0) goto L_18d808;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18d850ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18ddb4;
L_18d854:
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18d860ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18de10;
L_18d864:
    PB_LDR(cpu->regs[1], (SP + 112));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18d870ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18de34;
L_18d874:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 24));
    if (((cpu->regs[0] >> 3) & 1)) goto L_18de98;
L_18d87c:
    cpu->regs[21] = cpu->regs[21] + 40ULL;
    goto L_18d838;
L_18d884:
    PB_LDR(cpu->regs[28], (cpu->regs[19] + 0));
    if ((cpu->regs[28])==0) goto L_18e130;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x18d898ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b140ULL);
    if ((cpu->regs[0])==0) goto L_18d8a0;
    cpu->regs[28] = cpu->regs[0] + 1ULL;
L_18d8a0:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x18d8a8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18e1c8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x18d8b8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[28] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x18d8c4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18df5c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_18dd78;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[28];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_18dd60;
L_18d8e4:
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18d8f0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c090ULL);
    if ((cpu->regs[24])!=0) goto L_18dd8c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3488));
L_18d900:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18d978;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_18df18;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_EQ) goto L_18df0c;
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    goto L_18d900;
L_18d920:
    if ((cpu->regs[20])!=0) goto L_18ded4;
    PB_LDR(cpu->regs[20], (cpu->regs[28] + 8));
    if ((cpu->regs[20])==0) goto L_18de40;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18d934ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[21] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18d940ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd8e60ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18df54;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HI) goto L_18dd54;
    if (FLAG_HS) goto L_18d964;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[21];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LO) goto L_18dd60;
L_18d964:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[28] = cpu->regs[28] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x18d974ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_18d7e8;
L_18d978:
    if ((cpu->regs[24])!=0) goto L_18dfc0;
L_18d97c:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x18d984ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe13e0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18de74;
L_18d98c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (!((cpu->regs[0] >> 8) & 1)) goto L_18d9c0;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 16));
L_18d998:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[25]));
    FLAG_CMP(cpu->regs[1], cpu->regs[25]);
    if (FLAG_LE) goto L_18d9c0;
    cpu->regs[0] = cpu->regs[28] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    if ((cpu->regs[4])==0) goto L_18de74;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (!((cpu->regs[0] >> 8) & 1)) goto L_18e0c0;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 1ULL));
    goto L_18d998;
L_18d9c0:
    PB_LDR(cpu->regs[0], (SP + 128));
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3216));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x18d9dcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18e1e4ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18de74;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18e048;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 312));
    if ((cpu->regs[0])==0) goto L_18da04;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 312));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_18df8c;
L_18da04:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x18da0cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18e280ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18de74;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[24] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[24], 0ULL);
    if ((cpu->regs[24])==0) goto L_18de2c;
    cpu->regs[3] = cpu->regs[24];
    if (FLAG_LT) goto L_18dff4;
L_18da2c:
    PB_LDR(cpu->regs[5], (cpu->regs[25] + 304));
    cpu->regs[0] = cpu->regs[25];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 12),&_s,4); cpu->regs[4] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[1] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[4]); PB_STR((SP + 104) + 8, cpu->regs[3]);
    PB_STR((SP + 128), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x18da48ULL; PB_CALL(15, cpu, tlb, cpu->regs[5]);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18de74;
    PB_LDRW(cpu->regs[7], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[4], (SP + 104)); PB_LDR(cpu->regs[3], (SP + 104) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[7] | 512ULL));
    PB_STR((cpu->regs[25] + 168), cpu->regs[0]);
    PB_LDR(cpu->regs[2], (SP + 128));
    if ((cpu->regs[23])==0) goto L_18da78;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18da78;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_18da78:
    cpu->regs[8] = cpu->regs[25] + 416ULL;
    cpu->regs[1] = cpu->regs[25] + 448ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[5] = cpu->regs[25] + 760ULL;
    PB_STR((cpu->regs[25] + 80), cpu->regs[8]);
    cpu->regs[8] = cpu->regs[25] + 736ULL;
    PB_STR((cpu->regs[25] + 96), cpu->regs[1]); PB_STR((cpu->regs[25] + 96) + 8, cpu->regs[5]);
    cpu->regs[1] = cpu->regs[25] + 840ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_STR((cpu->regs[25] + 112), cpu->regs[8]);
    PB_STR((cpu->regs[25] + 160), cpu->regs[1]);
    PB_STR((cpu->regs[25] + 888), cpu->regs[23]);
    if (FLAG_NE) goto L_18ddd4;
L_18daac:
    PB_STR((cpu->regs[25] + 256), cpu->regs[2]);
    if (((cpu->regs[7] >> 1) & 1)) goto L_18df24;
L_18dab4:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    PB_STR((cpu->regs[25] + 176), cpu->regs[20]);
    PB_STR((cpu->regs[25] + 336), cpu->regs[28]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18dacc;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
L_18dacc:
    cpu->regs[23] = PB_BASE + 0x2b7000ULL;
    cpu->regs[23] = cpu->regs[23] + 1840ULL;
    cpu->regs[23] = cpu->regs[23] + 2672ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[25] + 24), cpu->regs[21]); PB_STR((cpu->regs[25] + 24) + 8, cpu->regs[3]);
    PB_STR((cpu->regs[25] + 40), cpu->regs[4]);
    PB_STR((cpu->regs[25] + 856), cpu->regs[26]);
    PB_STR((cpu->regs[25] + 872), cpu->regs[26]);
    PB_STR((cpu->regs[25] + 896), cpu->regs[21]);
L_18daf0:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_18dba8;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(56ULL)));
    if (FLAG_EQ) goto L_18db30;
    if (FLAG_GT) goto L_18db38;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_18db30;
L_18db10:
    cpu->regs[0] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 2);
    cpu->regs[1] = cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[23] + cpu->regs[0]),&_s,2); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[1] + 2),&_s,2); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_18dddc;
    PB_STR((cpu->regs[25] + cpu->regs[1]), cpu->regs[2]);
L_18db30:
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    goto L_18daf0;
L_18db38:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(72ULL)));
    if (FLAG_NE) goto L_18db10;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 40));
    cpu->regs[30] = PB_BASE + 0x18db50ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f68ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[21] = cpu->regs[22] * cpu->regs[21];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_18dd64;
    cpu->regs[2] = cpu->regs[0] + cpu->regs[21];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LO) goto L_18dd60;
L_18db6c:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18db74ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18db7cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe1f68ULL);
    PB_STR((cpu->regs[25] + 240), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18db88ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f68ULL);
    cpu->regs[1] = cpu->regs[22];
L_18db8c:
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_18db30;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 24));
    if (((cpu->regs[2] >> 3) & 1)) goto L_18e118;
L_18db9c:
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    goto L_18db8c;
L_18dba8:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 48));
    if ((cpu->regs[0])==0) goto L_18de1c;
L_18dbb0:
    PB_LDR(cpu->regs[1], (SP + 96));
    PB_STR((cpu->regs[25] + 208), cpu->regs[27]);
    PB_LDR(cpu->regs[0], (SP + 120));
    PB_STR((cpu->regs[25] + 56), cpu->regs[0]);
    PB_STR((cpu->regs[25] + 288), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18dbccULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18e404ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18dcfc;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 304));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3280));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_18dc2c;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 256));
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 32));
    if ((cpu->regs[0])==0) goto L_18dbfc;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_LT) goto L_18df68;
L_18dbfc:
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 208));
    cpu->regs[0] = cpu->regs[2] + 8ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LT) goto L_18e0f4;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 288));
    cpu->regs[0] = cpu->regs[2] + 8ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LT) goto L_18e078;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 56));
    cpu->regs[0] = cpu->regs[2] + 8ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LT) goto L_18df30;
L_18dc2c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18dc34ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdb420ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 176));
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_18ddec;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 24));
    cpu->regs[30] = PB_BASE + 0x18dc48ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18d1a0ULL);
    cpu->regs[30] = PB_BASE + 0x18dc4cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18dcfc;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[4] = 27680ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x18dc70ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[23] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_18dc88;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_18dfe4;
L_18dc88:
    if (((cpu->regs[23] >> 31) & 1)) goto L_18dcfc;
L_18dc8c:
    if ((cpu->regs[27])!=0) goto L_18ddbc;
L_18dc90:
    PB_LDR(cpu->regs[0], (SP + 96));
    if ((cpu->regs[0])!=0) goto L_18ddf8;
L_18dc98:
    cpu->regs[2] = 30600ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x18dca8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdd250ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18dcfc;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 0));
    cpu->regs[1] = 46ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18dcbcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7b140ULL);
    if ((cpu->regs[0])==0) goto L_18e09c;
    cpu->regs[1] = cpu->regs[0] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18dcccULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1ec0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18dcfc;
    cpu->regs[0] = 30600ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18dce8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18dcfc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18e06c;
L_18dcfc:
    cpu->regs[30] = PB_BASE + 0x18dd00ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_18e17c;
    cpu->regs[21] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[20] = 0ULL;
L_18dd14:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x18dd1cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18dd24ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdfce0ULL);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x18dd2cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18dd34ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 144;
    return;
L_18dd54:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[21];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_18d964;
L_18dd60:
    __builtin_trap();
L_18dd64:
    if (FLAG_HS) goto L_18db6c;
    cpu->regs[2] = cpu->regs[1] + cpu->regs[21];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_HS) goto L_18db6c;
    __builtin_trap();
L_18dd78:
    if (FLAG_HS) goto L_18d8e4;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[28];
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_HS) goto L_18d8e4;
    goto L_18dd60;
L_18dd8c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_18d97c;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18dfdc;
    cpu->regs[28] = cpu->regs[24];
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
    goto L_18d98c;
L_18ddb4:
    PB_LDR(cpu->regs[27], (cpu->regs[21] + 16));
    goto L_18d854;
L_18ddbc:
    cpu->regs[3] = 34136ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x18ddccULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18dc90;
    goto L_18dcfc;
L_18ddd4:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_18daac;
L_18dddc:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + cpu->regs[1]));
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    PB_STR((cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]))), cpu->regs[2]);
    goto L_18daf0;
L_18ddec:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    goto L_18dc8c;
L_18ddf8:
    cpu->regs[1] = 27520ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x18de08ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18dc98;
    goto L_18dcfc;
L_18de10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    PB_STR((SP + 96), cpu->regs[0]);
    goto L_18d864;
L_18de1c:
    cpu->regs[0] = PB_BASE + 0x13e000ULL;
    cpu->regs[0] = cpu->regs[0] + 4032ULL;
    PB_STR((cpu->regs[25] + 48), cpu->regs[0]);
    goto L_18dbb0;
L_18de2c:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 32));
    goto L_18da2c;
L_18de34:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    PB_STR((SP + 120), cpu->regs[0]);
    goto L_18d874;
L_18de40:
    cpu->regs[0] = 0ULL;
    cpu->regs[28] = cpu->regs[28] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x18de4cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdfce0ULL);
    goto L_18d7e8;
L_18de50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1928ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18de68ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_18de68:
    cpu->regs[21] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[28] = 0ULL;
L_18de74:
    cpu->regs[25] = 0ULL;
    goto L_18dd14;
L_18de7c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1904ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18de94ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18de68;
L_18de98:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_18def0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    if (((cpu->regs[1] >> 63) & 1)) goto L_18deb8;
    cpu->regs[0] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[0])));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LT) goto L_18d87c;
L_18deb8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 2096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18ded0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18de68;
L_18ded4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 2144ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18deecULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18de68;
L_18def0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 2040ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18df08ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18de68;
L_18df0c:
    PB_LDR(cpu->regs[24], (cpu->regs[2] + 8));
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    goto L_18d900;
L_18df18:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    goto L_18d900;
L_18df24:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    goto L_18dab4;
L_18df30:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[4] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 24));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 2904ULL;
    cpu->regs[30] = PB_BASE + 0x18df50ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18dcfc;
L_18df54:
    cpu->regs[30] = PB_BASE + 0x18df58ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_18de68;
L_18df5c:
    cpu->regs[28] = 0ULL;
    cpu->regs[25] = 0ULL;
    goto L_18dd14;
L_18df68:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 24));
    cpu->regs[1] = cpu->regs[1] + 2696ULL;
    cpu->regs[30] = PB_BASE + 0x18df88ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18dcfc;
L_18df8c:
    PB_LDRW(cpu->regs[0], (SP + 140));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18e1a8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    cpu->regs[2] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[2] + 2432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x18dfb4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x24d184ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18da04;
    cpu->regs[25] = 0ULL;
    goto L_18dd14;
L_18dfc0:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_18e158;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18dfdc;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
L_18dfdc:
    cpu->regs[28] = cpu->regs[24];
    goto L_18d98c;
L_18dfe4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18dfecULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if (!((cpu->regs[23] >> 31) & 1)) goto L_18dc8c;
    goto L_18dcfc;
L_18dff4:
    PB_LDR(cpu->regs[24], (cpu->regs[2] + 32)); PB_LDR(cpu->regs[1], (cpu->regs[2] + 32) + 8);
    cpu->regs[0] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[0])));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] + 15ULL;
    cpu->regs[0] = cpu->regs[0] & 18446744073709551600ULL;
    cpu->regs[24] = cpu->regs[24] + 15ULL;
    cpu->regs[24] = cpu->regs[24] & 18446744073709551600ULL;
    cpu->regs[3] = cpu->regs[0] + cpu->regs[24];
    if ((cpu->regs[1])==0) goto L_18da2c;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    if (((cpu->regs[0] >> 23) & 1)) goto L_18da2c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2624ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e044ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18dd14;
L_18e048:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2384ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e068ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18dd14;
L_18e06c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18e074ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18dcfc;
L_18e078:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[4] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 24));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 2832ULL;
    cpu->regs[30] = PB_BASE + 0x18e098ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18dcfc;
L_18e09c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = cpu->regs[2] + 2976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e0bcULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x24d184ULL);
    goto L_18dcfc;
L_18e0c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    cpu->regs[2] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[2] + 2272ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 24));
    cpu->regs[30] = PB_BASE + 0x18e0e4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x24d184ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18de74;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 16));
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 1ULL));
    goto L_18d998;
L_18e0f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[4] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 24));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 2760ULL;
    cpu->regs[30] = PB_BASE + 0x18e114ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18dcfc;
L_18e118:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 4294967287ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[24];
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    goto L_18db9c;
L_18e130:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2192ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[25] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e154ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18dd14;
L_18e158:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2240ULL;
    cpu->regs[25] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e178ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18dd14;
L_18e17c:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18e190;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18e1d8;
L_18e190:
    cpu->regs[21] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[25] = 0ULL;
    goto L_18dd14;
L_18e1a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2568ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e1c4ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18dd14;
L_18e1c8:
    cpu->regs[21] = 0ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[25] = 0ULL;
    goto L_18dd14;
L_18e1d8:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18e1e0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18e190;
}
