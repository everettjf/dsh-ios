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

void ft_PyObject_Vectorcall(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[5] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1102ccULL; PB_CALL(1, cpu, tlb, cpu->regs[7]);
    PB_LDR(cpu->regs[20], (cpu->regs[5] + cpu->regs[0]));
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 168));
    if (!((cpu->regs[6] >> 11) & 1)) goto L_110354;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 56));
    cpu->regs[5] = SP + 8ULL;
    cpu->regs[4] = SP;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[6];
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[4], cpu->regs[0]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_110398;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_HS) goto L_110308;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(SP, cpu->regs[0]);
    if (FLAG_LO) goto L_110398;
L_110308:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + cpu->regs[6]));
    if ((cpu->regs[4])==0) goto L_110354;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x110318ULL; PB_CALL(2, cpu, tlb, cpu->regs[4]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_110394;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe8888ULL); return; };
L_110354:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[5], (SP + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    cpu->regs[5] = cpu->regs[5] - cpu->regs[4]; FLAG_CMP(cpu->regs[5], 0);
    cpu->regs[4] = 0ULL;
    if (FLAG_NE) goto L_110394;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0xea120ULL); return; };
L_110394:
    cpu->regs[30] = PB_BASE + 0x110398ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_110398:
    __builtin_trap();
    /* nop */
L_1103a0:
    SP += -128; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1119dc;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1119ec;
L_1103d8:
    PB_LDRW(cpu->regs[28], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110fe0;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[19] = (((uint64_t)(((int64_t)(cpu->regs[28] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_110420;
L_1103f8:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1113ULL)));
    if (FLAG_EQ) goto L_110868;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_1103f8;
L_11040c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_EQ) goto L_111a10;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111a74;
L_110420:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(581ULL)));
    if (FLAG_EQ) goto L_110908;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
L_110434:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111cd8;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110894;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    cpu->regs[20] = cpu->regs[28];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_EQ) goto L_1108b0;
L_110464:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x110478ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1108e0;
L_110480:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = 6000ULL;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_111988;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_11199c;
L_1104a4:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[1] = 8ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    PB_LDRW(cpu->regs[21], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[26] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x1104c0ULL; PB_CALL(7, cpu, tlb, cpu->regs[2]);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111d48;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111d04;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111d18;
L_1104e8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 16));
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110ec4;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110ee0;
    cpu->regs[0] = cpu->regs[24];
L_110510:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(27ULL)));
    if (FLAG_EQ) goto L_1110b0;
L_110524:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110dfc;
L_110538:
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11193c;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 2ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_111968;
L_11055c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_110f24;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(28ULL)));
    if (FLAG_EQ) goto L_111194;
L_11057c:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 2ULL));
L_110584:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110dfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110f80;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110f9c;
    cpu->regs[0] = cpu->regs[24];
L_1105b0:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(29ULL)));
    if (FLAG_EQ) goto L_111394;
L_1105c4:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_1105d8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110f50;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110f6c;
    cpu->regs[0] = cpu->regs[24];
L_1105fc:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_111204;
L_110610:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_110624:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110fb0;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110fcc;
    cpu->regs[0] = cpu->regs[24];
L_110648:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(30ULL)));
    if (FLAG_EQ) goto L_1112cc;
L_11065c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_110670:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e04;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e20;
    cpu->regs[0] = cpu->regs[24];
L_110694:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(21ULL)));
    if (FLAG_EQ) goto L_111330;
L_1106a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_1106bc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110ef4;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110f10;
    cpu->regs[0] = cpu->regs[24];
L_1106e0:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(581ULL)));
    if (FLAG_EQ) goto L_110980;
L_1106f4:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_110708:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e64;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e80;
    cpu->regs[0] = cpu->regs[24];
L_11072c:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(651ULL)));
    if (FLAG_EQ) goto L_111144;
L_110740:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_110754:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e94;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110eb0;
    cpu->regs[0] = cpu->regs[24];
L_110778:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(582ULL)));
    if (FLAG_EQ) goto L_110da4;
L_11078c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110dfc;
L_1107a0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e34;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110e50;
L_1107c0:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(582ULL)));
    if (FLAG_EQ) goto L_111100;
L_1107d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 2ULL));
L_1107dc:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
L_1107e4:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136));
    cpu->regs[1] = cpu->regs[25];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 168));
    cpu->regs[30] = PB_BASE + 0x1107f4ULL; PB_CALL(8, cpu, tlb, cpu->regs[2]);
    PB_STRW((cpu->regs[27] + 16), cpu->regs[20]);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1108f0;
L_110810:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110818ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x111f50ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1108f4;
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_110830:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = 1113ULL;
    cpu->regs[30] = PB_BASE + 0x110844ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1082e0ULL);
L_110844:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_110850:
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    return;
L_110868:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    return;
L_110894:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x11089cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1108ec;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[20], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_NE) goto L_111ac0;
L_1108b0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1108b8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111aac;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1108ec;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1108d8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_110480;
L_1108e0:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
L_1108e4:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110810;
L_1108ec:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
L_1108f0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1108f4:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_110900:
    cpu->regs[19] = 0ULL;
    goto L_110830;
L_110908:
    PB_LDRW(cpu->regs[20], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[21], (cpu->regs[1] + 20) + 4);
    cpu->regs[0] = cpu->regs[28];
L_110910:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110920ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1103a0ULL);
    cpu->regs[7] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111a64;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16));
    cpu->regs[30] = PB_BASE + 0x110934ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110844;
    PB_LDR(cpu->regs[6], (cpu->regs[27] + 32));
    cpu->regs[3] = cpu->regs[21];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x110958ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1a6780ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_110830;
    cpu->regs[30] = PB_BASE + 0x110964ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_110900;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_110850;
L_110980:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[1] = 651ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110994ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1106f4;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1109a0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1106f4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x1109b4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])==0) goto L_111c48;
L_1109c0:
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[1] = 1ULL;
    PB_LDRW(cpu->regs[21], (cpu->regs[27] + 16));
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    PB_STR((SP + 104), cpu->regs[1]); PB_STR((SP + 104) + 8, cpu->regs[1]);
L_1109d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STR((SP + 96), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111c38;
L_1109f4:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1119b4;
L_110a18:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_111268;
L_110a24:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(27ULL)));
    if (FLAG_EQ) goto L_1114d4;
L_110a38:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110a44:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111bd4;
L_110a60:
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111bb8;
L_110a74:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111254;
L_110a80:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(28ULL)));
    if (FLAG_EQ) goto L_11140c;
L_110a94:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110aa0:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110aa4:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111cec;
L_110ac4:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1113e4;
L_110ad0:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(29ULL)));
    if (FLAG_EQ) goto L_1117e8;
L_110ae4:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110af0:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111db4;
L_110b10:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1113f8;
L_110b1c:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_111834;
L_110b30:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110b3c:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111d90;
L_110b5c:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11131c;
L_110b68:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(30ULL)));
    if (FLAG_EQ) goto L_111750;
L_110b7c:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110b88:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1118d8;
L_110ba8:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_111380;
L_110bb4:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(21ULL)));
    if (FLAG_EQ) goto L_11179c;
L_110bc8:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110bd4:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_11188c;
L_110bf4:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1112b8;
L_110c00:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(581ULL)));
    if (FLAG_EQ) goto L_1116e8;
L_110c14:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110c20:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1118c0;
L_110c40:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1112a4;
L_110c4c:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(651ULL)));
    if (FLAG_EQ) goto L_111614;
L_110c60:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110c6c:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_111924;
L_110c8c:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_111290;
L_110c98:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(582ULL)));
    if (FLAG_EQ) goto L_111550;
L_110cac:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110cb8:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_110cfc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_111c78;
L_110cd4:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_11127c;
L_110ce0:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(582ULL)));
    if (FLAG_EQ) goto L_1115ac;
L_110cf4:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110cfc:
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1107e4;
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1107e4;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 32));
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[30] = PB_BASE + 0x110d24ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111d40;
L_110d2c:
    PB_LDR(cpu->regs[1], (SP + 96));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[24]));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_GT) goto L_111008;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x110d44ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 144));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x110d5cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_111d34;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 32));
    PB_LDR(cpu->regs[26], (cpu->regs[21] + 0));
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[24], (cpu->regs[0] + 28) + 4);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x110d74ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x19e020ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111020;
    cpu->regs[1] = cpu->regs[25] + 16ULL;
    cpu->regs[0] = 0ULL;
L_110d84:
    FLAG_CMP(cpu->regs[26], cpu->regs[0]);
    if (FLAG_LE) goto L_111028;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[0] << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    PB_STRW((cpu->regs[1] + (cpu->regs[0] << 2)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_110d84;
L_110da4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[1] = 581ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110db8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_11078c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110dc4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11078c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x110dd8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x110de8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111cb0;
L_110dec:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_110df4:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1107a0;
L_110dfc:
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_110e04:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e0cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e48;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_110694;
L_110e20:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e28ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111538;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110694;
L_110e34:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e3cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_111e2c;
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_1107c0;
L_110e50:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e58ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11152c;
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 16));
    goto L_1107c0;
L_110e64:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e6cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e3c;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_11072c;
L_110e80:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e88ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111544;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_11072c;
L_110e94:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110e9cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e20;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_110778;
L_110eb0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110eb8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1116ac;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110778;
L_110ec4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110eccULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e80;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_110510;
L_110ee0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110ee8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11166c;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110510;
L_110ef4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110efcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1119f8;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_1106e0;
L_110f10:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110f18ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111678;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_1106e0;
L_110f24:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110f2cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111690;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(28ULL)));
    if (FLAG_EQ) goto L_111194;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_11057c;
L_110f50:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110f58ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e68;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_1105fc;
L_110f6c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110f74ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111684;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_1105fc;
L_110f80:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110f88ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e5c;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_1105b0;
L_110f9c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110fa4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1116a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_1105b0;
L_110fb0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110fb8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111ce0;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_110648;
L_110fcc:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110fd4ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1116b8;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110648;
L_110fe0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110fe8ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111d6c;
    PB_LDRW(cpu->regs[28], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[19] = (((uint64_t)(((int64_t)(cpu->regs[28] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_1103f8;
    goto L_11040c;
L_111008:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[25] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_110d2c;
L_111020:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
L_111028:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 32));
    PB_LDR(cpu->regs[26], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x111038ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111068;
    cpu->regs[1] = cpu->regs[2] + 16ULL;
    cpu->regs[0] = 0ULL;
L_111048:
    FLAG_CMP(cpu->regs[26], cpu->regs[0]);
    if (FLAG_LE) goto L_111070;
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 8));
    PB_STR((cpu->regs[1] + (cpu->regs[0] << 3)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_111048;
L_111068:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
L_111070:
    PB_LDR(cpu->regs[7], (cpu->regs[27] + 32));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[6] = cpu->regs[24];
    cpu->regs[5] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x111090ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x19e340ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_111ad8;
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_110830;
L_1110b0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1110c0ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110524;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1110d4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x1110e4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111b58;
L_1110e8:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1110f0:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110538;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_111100:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111110ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1107d4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x111124ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x111134ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111cbc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_11113c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1107dc;
L_111144:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111154ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110740;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x111168ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x111178ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1119a8;
L_11117c:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_111184:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110754;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_111194:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 100));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[1] + 32ULL;
    if (((cpu->regs[2] >> 5) & 1)) goto L_111b00;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    cpu->regs[30] = PB_BASE + 0x1111b8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_111b30;
L_1111bc:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1111d0ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111ac8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1111e4ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x1111f4ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111b64;
L_1111f8:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_110584;
L_111204:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111214ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110610;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x111228ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x111238ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111ccc;
L_11123c:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_111244:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110624;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_111254:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x11125cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111520;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110a80;
L_111268:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111270ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111608;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110a24;
L_11127c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111284ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1115fc;
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 16));
    goto L_110ce0;
L_111290:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111298ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111660;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110c98;
L_1112a4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1112acULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111744;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110c4c;
L_1112b8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1112c0ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1116c4;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110c00;
L_1112cc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1112dcULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11065c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x1112f0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x111300ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111e04;
L_111304:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_11130c:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110670;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_11131c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111324ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1116d0;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110b68;
L_111330:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111340ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1106a8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x111354ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x111364ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1118fc;
L_111368:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_111370:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1106bc;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_111380:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111388ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1116dc;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110bb4;
L_111394:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1113a4ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1105c4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1113b8ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x19d52cULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 2ULL));
    if ((cpu->regs[0])!=0) goto L_1109c0;
    cpu->regs[30] = PB_BASE + 0x1113c8ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111de8;
L_1113cc:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1113d4:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1105d8;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_1113e4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1113ecULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111880;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110ad0;
L_1113f8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111400ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111498;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110b1c;
L_11140c:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 100));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[1] + 32ULL;
    if (((cpu->regs[2] >> 5) & 1)) goto L_111bf0;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    cpu->regs[30] = PB_BASE + 0x111430ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_111c20;
L_111434:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x111448ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_111b9c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x11145cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])==0) goto L_111b84;
L_11146c:
    PB_LDR(cpu->regs[1], (SP + 104)); PB_LDR(cpu->regs[0], (SP + 104) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1114a4;
L_111480:
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDRW(cpu->regs[21], (cpu->regs[27] + 16));
    PB_STR((cpu->regs[25] + (cpu->regs[0] << 3)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 104), cpu->regs[0]);
    goto L_1109d4;
L_111498:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110b30;
L_1114a4:
    PB_LDR(cpu->regs[0], (SP + 112));
    PB_STR((SP + 96), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] << 1;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 112), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[30] = PB_BASE + 0x1114c4ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xe5680ULL);
    PB_LDR(cpu->regs[3], (SP + 96));
    if ((cpu->regs[0])==0) goto L_111d40;
    cpu->regs[25] = cpu->regs[0];
    goto L_111480;
L_1114d4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1114e4ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110a38;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1114f8ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111510ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111ca0;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110a44;
L_111520:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110a94;
L_11152c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1107d4;
L_111538:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1106a8;
L_111544:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110740;
L_111550:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[1] = 581ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111564ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_110cac;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111570ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110cac;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x111584ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x11159cULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111c90;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110cb8;
L_1115ac:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1115bcULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110cf4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1115d0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1115e8ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 104));
    if ((cpu->regs[0])==0) goto L_110cfc;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110cfc;
L_1115fc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110cf4;
L_111608:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110a38;
L_111614:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111624ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110c60;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x111638ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111650ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_1119cc;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110c6c;
L_111660:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110cac;
L_11166c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110524;
L_111678:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1106f4;
L_111684:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110610;
L_111690:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_11057c;
L_1116a0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1105c4;
L_1116ac:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_11078c;
L_1116b8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_11065c;
L_1116c4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110c14;
L_1116d0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110b7c;
L_1116dc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110bc8;
L_1116e8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[1] = 651ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1116fcULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_110c14;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111708ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110c14;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x11171cULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111734ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_1118b0;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110c20;
L_111744:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110c60;
L_111750:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111760ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110b7c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x111774ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x11178cULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111914;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110b88;
L_11179c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1117acULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110bc8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x1117c0ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1117d8ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111df4;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110bd4;
L_1117e8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1117f8ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110ae4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x11180cULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111824ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111dd8;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110af0;
L_111834:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111844ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110b30;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x111858ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x19d52cULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_11146c;
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111870ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111e10;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110b3c;
L_111880:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110ae4;
L_11188c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111894ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1118a4;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110bf4;
L_1118a4:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110c20;
L_1118b0:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110c20;
L_1118c0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1118c8ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1118f0;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110c40;
L_1118d8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1118e0ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111908;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110ba8;
L_1118f0:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110c6c;
L_1118fc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_111368;
L_111908:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110bd4;
L_111914:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110b88;
L_111924:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x11192cULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111b4c;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110c8c;
L_11193c:
    cpu->regs[0] = cpu->regs[27];
    PB_STRW((SP + 96), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111948ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[2], (SP + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e54;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_11055c;
L_111968:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111970ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_11055c;
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110584;
L_111988:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111990ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1104a4;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
L_11199c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    goto L_1108e4;
L_1119a8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_11117c;
L_1119b4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1119bcULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111d84;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110a18;
L_1119cc:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110c6c;
L_1119dc:
    cpu->regs[30] = PB_BASE + 0x1119e0ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1103d8;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
L_1119ec:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[19] = 0ULL;
    goto L_110850;
L_1119f8:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_111a00:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110708;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_111a10:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111a18ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111d6c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[19]));
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111a70;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[2], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_111a84;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111a48ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_111a8c;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
L_111a58:
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(581ULL)));
    if (FLAG_EQ) goto L_110910;
L_111a64:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110434;
L_111a70:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_111a74:
    cpu->regs[19] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_110850;
L_111a84:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    goto L_111a58;
L_111a8c:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
L_111a9c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[19] = 0ULL;
    goto L_110850;
L_111aac:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1108f4;
L_111ac0:
    cpu->regs[20] = cpu->regs[0];
    goto L_110464;
L_111ac8:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110584;
L_111ad8:
    PB_STRW((SP + 96), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x111ae0ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (SP + 96));
    if ((cpu->regs[0])!=0) goto L_111af0;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1108f4;
L_111af0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1108f4;
L_111b00:
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3856ULL;
    cpu->regs[30] = PB_BASE + 0x111b0cULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1111bc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[3] + 3864ULL;
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x111b30ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x26acc4ULL);
L_111b30:
    cpu->regs[30] = PB_BASE + 0x111b34ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_111b70;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110584;
L_111b4c:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110cb8;
L_111b58:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1110e8;
L_111b64:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1111f8;
L_111b70:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110584;
L_111b84:
    PB_STRW((SP + 124), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x111b8cULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (SP + 124));
    if ((cpu->regs[0])!=0) goto L_111ba8;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110aa4;
L_111b9c:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    goto L_110aa0;
L_111ba8:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110aa4;
L_111bb8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111bc0ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110a74;
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110aa0;
L_111bd4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111bdcULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 1ULL));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_110a60;
    goto L_110aa4;
L_111bf0:
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3856ULL;
    cpu->regs[30] = PB_BASE + 0x111bfcULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_111434;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[3] + 3864ULL;
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x111c20ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x26acc4ULL);
L_111c20:
    cpu->regs[30] = PB_BASE + 0x111c24ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_111c5c;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    goto L_110aa0;
L_111c38:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111c40ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    goto L_1109f4;
L_111c48:
    cpu->regs[30] = PB_BASE + 0x111c4cULL; PB_CALL(141, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_111c6c;
L_111c50:
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_111a00;
L_111c5c:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110aa0;
L_111c6c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_111c50;
L_111c78:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111c80ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_110cf4;
    PB_LDRW(cpu->regs[24], (cpu->regs[27] + 16));
    goto L_110cd4;
L_111c90:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110cb8;
L_111ca0:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110a44;
L_111cb0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110dec;
L_111cbc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_11113c;
L_111ccc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_11123c;
L_111cd8:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_111a9c;
L_111ce0:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_11130c;
L_111cec:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111cf4ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111e74;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110ac4;
L_111d04:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1108e4;
L_111d18:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111d20ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1104e8;
    PB_STR((SP + 96), 0ULL);
    goto L_110cfc;
L_111d34:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[4] - 2ULL));
    goto L_1108f4;
L_111d40:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x111d48ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_111d48:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x111d54ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1108e4;
L_111d6c:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[0] = 1ULL;
    cpu->regs[19] = 0ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_110850;
L_111d84:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110a44;
L_111d90:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111d98ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111da8;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110b5c;
L_111da8:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110b88;
L_111db4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x111dbcULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_111dcc;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    goto L_110b10;
L_111dcc:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110b3c;
L_111dd8:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110af0;
L_111de8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_1113cc;
L_111df4:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110bd4;
L_111e04:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_111304;
L_111e10:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    goto L_110b3c;
L_111e20:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110df4;
L_111e2c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1107dc;
L_111e3c:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_111184;
L_111e48:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_111370;
L_111e54:
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_110584;
L_111e5c:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1113d4;
L_111e68:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_111244;
L_111e74:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110af0;
L_111e80:
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1110f0;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x111eb4ULL; PB_CALL(149, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[19], (cpu->regs[4] + cpu->regs[0]));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 36));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_111f10;
L_111ed4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    if ((cpu->regs[4])==0) goto L_111f2c;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 5) & 1)) goto L_111f34;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x111ef4ULL; PB_CALL(150, cpu, tlb, cpu->regs[4]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
L_111f00:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_111f10:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    PB_STR((SP + 48), cpu->regs[2]); PB_STR((SP + 48) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x111f24ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x26c444ULL);
    PB_LDR(cpu->regs[2], (SP + 48)); PB_LDR(cpu->regs[3], (SP + 48) + 8);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_111ed4;
L_111f2c:
    cpu->regs[0] = 0ULL;
    goto L_111f00;
L_111f34:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x111f40ULL; PB_CALL(152, cpu, tlb, cpu->regs[4]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    goto L_111f00;
L_111f50:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_112288;
L_111f7c:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1121cc;
L_111f88:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_111fac;
L_111f98:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1126ULL)));
    if (FLAG_EQ) goto L_112090;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_111f98;
L_111fac:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1126ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[22] = cpu->regs[21];
    cpu->regs[23] = 6000ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x111fd4ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11207c;
L_111fdc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_EQ) goto L_11227c;
L_111ff0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112214;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1120bc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x112018ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1120ec;
L_112020:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112214;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112034ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x1124d0ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1121a8;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1121b4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_112178;
L_112058:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1126ULL;
    cpu->regs[30] = PB_BASE + 0x112074ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_111fdc;
L_11207c:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1120a4;
L_112090:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_1120a4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1120bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1120c4ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112268;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112214;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1120e4ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112020;
L_1120ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1121e0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(18ULL)));
    if (FLAG_NE) goto L_112020;
L_11210c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11211cULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x1124d0ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112020;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x112130ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_112250;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x112154ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_112238;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1121b4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_GT) goto L_112058;
L_112178:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1121a8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_112178;
L_1121b4:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1120a4;
L_1121cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1121d4ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112220;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_111f88;
L_1121e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1121e8ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112208;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(18ULL)));
    if (FLAG_NE) goto L_112020;
    goto L_11210c;
L_112208:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_112214:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1121b4;
L_112220:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1120a4;
L_112238:
    cpu->regs[30] = PB_BASE + 0x11223cULL; PB_CALL(164, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_11225c;
L_112240:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_112178;
    goto L_1121b4;
L_112250:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112240;
L_11225c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1121b4;
L_112268:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1121b4;
L_11227c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112284ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_111ff0;
L_112288:
    cpu->regs[30] = PB_BASE + 0x11228cULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_111f7c;
}
