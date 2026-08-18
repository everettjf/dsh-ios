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

void ft__PyErr_GetTopmostException(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 104));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
L_21edac:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_21edcc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    if ((cpu->regs[1])==0) goto L_21edcc;
    cpu->regs[0] = cpu->regs[1];
    goto L_21edac;
L_21edcc:
    return;
    SP = SP - 112ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[5] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_21eeec;
    if (((cpu->regs[2] >> 63) & 1)) goto L_21ef94;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[21] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_21eef4;
L_21ee20:
    if ((cpu->regs[21])==0) goto L_21eec0;
L_21ee24:
    PB_LDR(cpu->regs[19], (cpu->regs[5] + 0));
    if ((cpu->regs[19])==0) goto L_21ef88;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_21eeb8;
L_21ee34:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    cpu->regs[30] = PB_BASE + 0x21ee3cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21eeb0;
    cpu->regs[30] = PB_BASE + 0x21ee48ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_21efd4;
L_21ee54:
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_21eeb0;
L_21ee5c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_21eec4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_21ef68;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_21ef64;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
L_21ee9c:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96));
    SP = SP + 112ULL;
    goto L_21f000;
L_21eeb0:
    cpu->regs[30] = PB_BASE + 0x21eeb4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_21ef30;
L_21eeb8:
    cpu->regs[2] = 18446744073709551615ULL;
    goto L_21ee5c;
L_21eec0:
    cpu->regs[2] = 18446744073709551615ULL;
L_21eec4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_21ef64;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    goto L_21ee9c;
L_21eeec:
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[21] = cpu->regs[2] + cpu->regs[21];
L_21eef4:
    cpu->regs[1] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 1512ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21ef28ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21ee20;
L_21ef30:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_21ef64;
    PB_LDR(cpu->regs[21], (SP + 96));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_21ef64:
    cpu->regs[30] = PB_BASE + 0x21ef68ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_21ef68:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x21ef84ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_21ef30;
L_21ef88:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    goto L_21ee34;
L_21ef94:
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 1512ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21efc4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ef30;
    cpu->regs[21] = cpu->regs[19];
    goto L_21ee24;
L_21efd4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21ee54;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x21efecULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 24));
    goto L_21ee54;
    /* nop */
    /* nop */
    /* nop */
L_21f000:
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[19], (cpu->regs[23] + 16));
    cpu->regs[24] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if ((cpu->regs[1])==0) goto L_21f224;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[28], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[26] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (((cpu->regs[2] >> 63) & 1)) goto L_21f210;
L_21f048:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[19], cpu->regs[28]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_21f654;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_21fc28;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[23] + 40ULL;
    cpu->regs[21] = cpu->regs[23] + 56ULL;
    cpu->regs[21] = (FLAG_EQ) ? cpu->regs[21] : cpu->regs[2];
L_21f068:
    if (!((cpu->regs[1] >> 5) & 1)) goto L_21fc20;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[25] = cpu->regs[22] + 56ULL;
    cpu->regs[1] = cpu->regs[22] + 40ULL;
    cpu->regs[25] = (FLAG_EQ) ? cpu->regs[25] : cpu->regs[1];
L_21f07c:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_NE) goto L_21f4ac;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_21f1a0;
L_21f08c:
    if (!((cpu->regs[0] >> 6) & 1)) goto L_21fd08;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_21fd08;
    if ((cpu->regs[28])==0) goto L_21fd0c;
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_NE) goto L_21f3fc;
    PB_LDRB(cpu->regs[28], (cpu->regs[25] + 0));
    cpu->regs[30] = PB_BASE + 0x21f0bcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[27] = 0ULL;
    cpu->regs[1] = cpu->regs[19];
L_21f0d0:
    if (((cpu->regs[19] >> 63) & 1)) goto L_21f134;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_21f134;
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_21f0f0;
L_21f0e4:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_21f134;
L_21f0f0:
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_NE) goto L_21f0e4;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x21f10cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_21f744;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[1]);
L_21f124:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[1] = cpu->regs[19];
    goto L_21f0d0;
L_21f134:
    if ((cpu->regs[27])==0) goto L_21fc30;
L_21f138:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_LT) goto L_21f168;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f14cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
L_21f154:
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_21f858;
L_21f15c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[19]);
L_21f164:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
L_21f168:
    PB_STR((cpu->regs[22] + 16), cpu->regs[27]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21f174ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x220364ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_21f490;
L_21f178:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_NE) goto L_21f530;
L_21f180:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_21f188:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_21f1a0:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21f9dc;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_21f354;
L_21f1ac:
    if ((cpu->regs[28])==0) goto L_21fd0c;
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_NE) goto L_21f5bc;
    PB_LDRH(cpu->regs[27], (cpu->regs[25] + 0));
    cpu->regs[30] = PB_BASE + 0x21f1d0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[1] = cpu->regs[19];
L_21f1e4:
    if (((cpu->regs[19] >> 63) & 1)) goto L_21f574;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_21f574;
L_21f1f0:
    PB_LDRH(cpu->regs[0], (cpu->regs[21] + (cpu->regs[19] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_21f778;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21f1f0;
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_21f1e4;
L_21f210:
    if ((cpu->regs[28])==0) goto L_21ffc4;
    cpu->regs[20] = (cpu->regs[28] ? (uint64_t)((int64_t)cpu->regs[19] / (int64_t)cpu->regs[28]) : 0);
    cpu->regs[20] = cpu->regs[20] + 1ULL; FLAG_CMP(cpu->regs[20], 0);
    cpu->regs[20] = (FLAG_GE) ? cpu->regs[20] : cpu->regs[19];
    goto L_21f048;
L_21f224:
    if (!((cpu->regs[2] >> 63) & 1)) goto L_21f238;
    cpu->regs[20] = cpu->regs[19] - 1ULL;
    cpu->regs[1] = 2ULL;
    cpu->regs[20] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[20] / (int64_t)cpu->regs[1]) : 0);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
L_21f238:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_21f8f8;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[1] = ((uint32_t)(((cpu->regs[0] >> 5) & 0x1ULL)));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_220120;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_2200d8;
    cpu->regs[26] = cpu->regs[23] + 40ULL;
L_21f254:
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x21f268ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ffb8;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[21] = cpu->regs[19];
L_21f27c:
    cpu->regs[0] = cpu->regs[20] - cpu->regs[25];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_21f334;
L_21f288:
    if (((cpu->regs[21] >> 63) & 1)) goto L_21f31c;
    PB_LDRB(cpu->regs[0], (cpu->regs[26] + cpu->regs[21]));
    cpu->regs[24] = cpu->regs[21] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x21f298ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21f2a4;
    cpu->regs[21] = cpu->regs[24];
    goto L_21f288;
L_21f2a4:
    FLAG_CMP(cpu->regs[24], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_21f3c0;
    PB_LDRB(cpu->regs[0], (cpu->regs[26] + cpu->regs[24]));
    cpu->regs[30] = PB_BASE + 0x21f2b4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21f2c0;
    cpu->regs[24] = cpu->regs[24] - 1ULL;
    goto L_21f2a4;
L_21f2c0:
    cpu->regs[0] = cpu->regs[24] + 1ULL;
    cpu->regs[1] = cpu->regs[21] - cpu->regs[24];
    cpu->regs[0] = cpu->regs[26] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x21f2d0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ffa4;
    FLAG_CMP(cpu->regs[25], 11ULL);
    if (FLAG_GT) goto L_21f544;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[25] << 3)), cpu->regs[21]);
L_21f2e8:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    cpu->regs[21] = cpu->regs[24];
    goto L_21f27c;
L_21f2f4:
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x21f300ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ffa4;
    FLAG_CMP(cpu->regs[25], 11ULL);
    if (FLAG_GT) goto L_21ffe4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[25] << 3)), cpu->regs[19]);
L_21f318:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
L_21f31c:
    PB_STR((cpu->regs[22] + 16), cpu->regs[25]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21f328ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x220364ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_21ffa4;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_21f188;
L_21f334:
    if (((cpu->regs[21] >> 63) & 1)) goto L_21f31c;
L_21f338:
    PB_LDRB(cpu->regs[0], (cpu->regs[26] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x21f340ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21f2f4;
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21f338;
    goto L_21f31c;
L_21f354:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_21f9dc;
L_21f35c:
    if ((cpu->regs[28])==0) goto L_21fd0c;
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_NE) goto L_21f688;
    PB_LDRW(cpu->regs[27], (cpu->regs[25] + 0));
    cpu->regs[30] = PB_BASE + 0x21f380ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[1] = cpu->regs[19];
L_21f394:
    if (((cpu->regs[19] >> 63) & 1)) goto L_21f720;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_21f720;
L_21f3a0:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + (cpu->regs[19] << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_21f7b4;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21f3a0;
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_21f394;
L_21f3c0:
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_NE) goto L_21f2c0;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_21f2c0;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21f3ec;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_21f3ec:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    goto L_21f31c;
L_21f3fc:
    cpu->regs[30] = PB_BASE + 0x21f400ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
    cpu->regs[27] = 0ULL;
L_21f40c:
    cpu->regs[7] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_LE) goto L_21f478;
    cpu->regs[30] = PB_BASE + 0x21f434ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[2] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_21f478;
    cpu->regs[0] = cpu->regs[28] + cpu->regs[0];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[19] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x21f450ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    PB_LDR(cpu->regs[2], (SP + 104));
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_21f4d8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[19]);
L_21f46c:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[19] = cpu->regs[2];
    goto L_21f40c;
L_21f478:
    if ((cpu->regs[27])==0) goto L_21f8a0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f488ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f154;
L_21f490:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_21f4a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_21fbc4;
L_21f4a4:
    cpu->regs[22] = 0ULL;
    goto L_21f178;
L_21f4ac:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x21f4c0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x22e06cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9dc;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_21f518;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    goto L_21f08c;
L_21f4d8:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x21f4e8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[2], (SP + 104));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fb74;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f46c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f46c;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x21f510ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 104));
    goto L_21f46c;
L_21f518:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21f52c;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_21f1ac;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_21f35c;
L_21f52c:
    cpu->regs[22] = 0ULL;
L_21f530:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x21f538ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21f188;
L_21f544:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21f550ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21ff94;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f2e8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f2e8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f570ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f2e8;
L_21f574:
    if ((cpu->regs[28])==0) goto L_21f7f0;
L_21f578:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_LT) goto L_21f5a8;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f58cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
L_21f594:
    FLAG_CMP(cpu->regs[28], 11ULL);
    if (FLAG_GT) goto L_21fb60;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[28] << 3)), cpu->regs[19]);
L_21f5a4:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
L_21f5a8:
    PB_STR((cpu->regs[22] + 16), cpu->regs[28]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21f5b4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x220364ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_21f178;
    goto L_21f490;
L_21f5bc:
    cpu->regs[30] = PB_BASE + 0x21f5c0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
    cpu->regs[27] = 0ULL;
L_21f5cc:
    cpu->regs[7] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_LE) goto L_21f5fc;
    cpu->regs[30] = PB_BASE + 0x21f5f4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x22e280ULL);
    cpu->regs[2] = cpu->regs[0];
    if (!((cpu->regs[0] >> 63) & 1)) goto L_21f618;
L_21f5fc:
    if ((cpu->regs[27])==0) goto L_21f824;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f60cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f154;
    goto L_21f490;
L_21f618:
    cpu->regs[0] = cpu->regs[28] + cpu->regs[0];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[19] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[21] + (cpu->regs[0] << 1);
    cpu->regs[30] = PB_BASE + 0x21f62cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    PB_LDR(cpu->regs[2], (SP + 104));
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_2201c0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[19]);
L_21f648:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[19] = cpu->regs[2];
    goto L_21f5cc;
L_21f654:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x21f65cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9dc;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21f674;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_21f674:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21f188;
L_21f688:
    cpu->regs[30] = PB_BASE + 0x21f68cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[27] = 0ULL;
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
L_21f698:
    cpu->regs[7] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_LE) goto L_21f6c8;
    cpu->regs[30] = PB_BASE + 0x21f6c0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x27b888ULL);
    cpu->regs[2] = cpu->regs[0];
    if (!((cpu->regs[0] >> 63) & 1)) goto L_21f6e4;
L_21f6c8:
    if ((cpu->regs[27])==0) goto L_21f8cc;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f6d8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f154;
    goto L_21f490;
L_21f6e4:
    cpu->regs[0] = cpu->regs[28] + cpu->regs[0];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[19] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[21] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x21f6f8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    PB_LDR(cpu->regs[2], (SP + 104));
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_2200e0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[19]);
L_21f714:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[19] = cpu->regs[2];
    goto L_21f698;
L_21f720:
    if ((cpu->regs[28])==0) goto L_21f888;
L_21f724:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_LT) goto L_21f5a8;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f738ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f594;
    goto L_21f490;
L_21f744:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x21f750ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220030;
    if (((cpu->regs[2] >> 31) & 1)) goto L_21f124;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21f124;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x21f774ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f124;
L_21f778:
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[21] + (cpu->regs[0] << 1);
    cpu->regs[30] = PB_BASE + 0x21f788ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    FLAG_CMP(cpu->regs[28], 11ULL);
    if (FLAG_GT) goto L_220018;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[28] << 3)), cpu->regs[1]);
L_21f7a0:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_21f1e4;
L_21f7b4:
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[21] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x21f7c4ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    FLAG_CMP(cpu->regs[28], 11ULL);
    if (FLAG_GT) goto L_21fb90;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[28] << 3)), cpu->regs[1]);
L_21f7dc:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_21f394;
L_21f7f0:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_21f578;
L_21f804:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21f814;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_21f814:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[28] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    goto L_21f5a8;
L_21f824:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_21ffcc;
L_21f838:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21f848;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_21f848:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[27] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    goto L_21f168;
L_21f858:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21f864ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fb74;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f164;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f164;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21f884ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f164;
L_21f888:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_21f804;
    goto L_21f724;
L_21f8a0:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_21f838;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f8c0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f15c;
    goto L_21f490;
L_21f8cc:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_21f838;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21f8ecULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f15c;
    goto L_21f490;
L_21f8f8:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_21f9ec;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_21fab8;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[24] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[24] = (FLAG_EQ) ? cpu->regs[24] : cpu->regs[0];
L_21f914:
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x21f928ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9e4;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2520));
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[19];
    cpu->regs[26] = 0ULL;
L_21f94c:
    cpu->regs[0] = cpu->regs[20] - cpu->regs[26];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_21fbd4;
L_21f958:
    if (((cpu->regs[25] >> 63) & 1)) goto L_21f9b8;
    PB_LDRH(cpu->regs[0], (cpu->regs[24] + (cpu->regs[25] << 1)));
    cpu->regs[21] = cpu->regs[25] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x21f968ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21f980;
    goto L_21faf4;
L_21f970:
    PB_LDRH(cpu->regs[0], (cpu->regs[24] + (cpu->regs[21] << 1)));
    cpu->regs[30] = PB_BASE + 0x21f978ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fac0;
    cpu->regs[21] = cpu->regs[21] - 1ULL;
L_21f980:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21f970;
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_NE) goto L_21fac0;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_NE) goto L_21fac0;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21f9ac;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_21f9ac:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
L_21f9b8:
    PB_STR((cpu->regs[22] + 16), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21f9c4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x220364ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_21f180;
L_21f9c8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_21f9dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_21fb2c;
L_21f9dc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_21f9e4:
    cpu->regs[22] = 0ULL;
    goto L_21f188;
L_21f9ec:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    if (!((cpu->regs[0] >> 5) & 1)) goto L_21fc68;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[26] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[26] = (FLAG_EQ) ? cpu->regs[26] : cpu->regs[0];
L_21fa04:
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x21fa18ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ffb8;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[24] = cpu->regs[19];
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2520));
    cpu->regs[25] = 0ULL;
L_21fa38:
    cpu->regs[0] = cpu->regs[20] - cpu->regs[25];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_21fc48;
L_21fa44:
    if (((cpu->regs[24] >> 63) & 1)) goto L_21faa4;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + (cpu->regs[24] << 2)));
    cpu->regs[21] = cpu->regs[24] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x21fa54ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21fa6c;
    goto L_21fca4;
L_21fa5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + (cpu->regs[21] << 2)));
    cpu->regs[30] = PB_BASE + 0x21fa64ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fc70;
    cpu->regs[21] = cpu->regs[21] - 1ULL;
L_21fa6c:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21fa5c;
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_NE) goto L_21fc70;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_NE) goto L_21fc70;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21fa98;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_21fa98:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
L_21faa4:
    PB_STR((cpu->regs[22] + 16), cpu->regs[25]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fab0ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x220364ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_21f180;
    goto L_21f9c8;
L_21fab8:
    PB_LDR(cpu->regs[24], (cpu->regs[23] + 56));
    goto L_21f914;
L_21fac0:
    cpu->regs[0] = cpu->regs[21] + 1ULL;
    cpu->regs[1] = cpu->regs[25] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[0] << 1);
    cpu->regs[30] = PB_BASE + 0x21fad0ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9c8;
    FLAG_CMP(cpu->regs[26], 11ULL);
    if (FLAG_GT) goto L_21fafc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[26] << 3)), cpu->regs[25]);
L_21fae8:
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    cpu->regs[25] = cpu->regs[21];
    goto L_21f94c;
L_21faf4:
    cpu->regs[25] = cpu->regs[21];
    goto L_21f958;
L_21fafc:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fb08ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fb44;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21fae8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21fae8;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x21fb28ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21fae8;
L_21fb2c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21fb38ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21f188;
L_21fb44:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f9c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f9c8;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x21fb5cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f9c8;
L_21fb60:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fb6cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2200bc;
L_21fb74:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f490;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f490;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21fb8cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f490;
L_21fb90:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x21fb9cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220030;
    if (((cpu->regs[2] >> 31) & 1)) goto L_21f7dc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21f7dc;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x21fbc0ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f7dc;
L_21fbc4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21fbd0ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f178;
L_21fbd4:
    if (((cpu->regs[25] >> 63) & 1)) goto L_21f9b8;
L_21fbd8:
    PB_LDRH(cpu->regs[0], (cpu->regs[24] + (cpu->regs[25] << 1)));
    cpu->regs[30] = PB_BASE + 0x21fbe0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21fbf4;
    cpu->regs[25] = cpu->regs[25] - 1ULL;
    FLAG_CMP(cpu->regs[25], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21fbd8;
    goto L_21f9b8;
L_21fbf4:
    cpu->regs[1] = cpu->regs[25] + 1ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x21fc00ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9c8;
    FLAG_CMP(cpu->regs[26], 11ULL);
    if (FLAG_GT) goto L_21fd60;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[26] << 3)), cpu->regs[19]);
L_21fc18:
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    goto L_21f9b8;
L_21fc20:
    PB_LDR(cpu->regs[25], (cpu->regs[22] + 56));
    goto L_21f07c;
L_21fc28:
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 56));
    goto L_21f068;
L_21fc30:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_21f838;
    goto L_21f138;
L_21fc48:
    if (((cpu->regs[24] >> 63) & 1)) goto L_21faa4;
L_21fc4c:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + (cpu->regs[24] << 2)));
    cpu->regs[30] = PB_BASE + 0x21fc54ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21fcac;
    cpu->regs[24] = cpu->regs[24] - 1ULL;
    FLAG_CMP(cpu->regs[24], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21fc4c;
    goto L_21faa4;
L_21fc68:
    PB_LDR(cpu->regs[26], (cpu->regs[23] + 56));
    goto L_21fa04;
L_21fc70:
    cpu->regs[0] = cpu->regs[21] + 1ULL;
    cpu->regs[1] = cpu->regs[24] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x21fc80ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9c8;
    FLAG_CMP(cpu->regs[25], 11ULL);
    if (FLAG_GT) goto L_21fcd8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[25] << 3)), cpu->regs[24]);
L_21fc98:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    cpu->regs[24] = cpu->regs[21];
    goto L_21fa38;
L_21fca4:
    cpu->regs[24] = cpu->regs[21];
    goto L_21fa44;
L_21fcac:
    cpu->regs[1] = cpu->regs[24] + 1ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x21fcb8ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f9c8;
    FLAG_CMP(cpu->regs[25], 11ULL);
    if (FLAG_GT) goto L_21fd2c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[25] << 3)), cpu->regs[19]);
L_21fcd0:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_21faa4;
L_21fcd8:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fce4ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fd94;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21fc98;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21fc98;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x21fd04ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21fc98;
L_21fd08:
    if ((cpu->regs[28])!=0) goto L_21fdcc;
L_21fd0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x21fd28ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_21f178;
L_21fd2c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fd38ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fdb0;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21fcd0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21fcd0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x21fd5cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21faa4;
L_21fd60:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fd6cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fdb0;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21fc18;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21fc18;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x21fd90ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f9b8;
L_21fd94:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f9c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f9c8;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x21fdacULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f9c8;
L_21fdb0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f9c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f9c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21fdc8ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f9c8;
L_21fdcc:
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_EQ) goto L_21fe5c;
    cpu->regs[30] = PB_BASE + 0x21fde8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[27] = 0ULL;
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
L_21fdf4:
    cpu->regs[7] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_LE) goto L_21fea8;
    cpu->regs[30] = PB_BASE + 0x21fe1cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x1236a4ULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if (((cpu->regs[0] >> 63) & 1)) goto L_21fea8;
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[0] = cpu->regs[28] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[19] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x21fe38ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_21ff28;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[19]);
L_21fe50:
    PB_LDR(cpu->regs[19], (SP + 104));
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    goto L_21fdf4;
L_21fe5c:
    PB_LDRB(cpu->regs[28], (cpu->regs[25] + 0));
    cpu->regs[30] = PB_BASE + 0x21fe64ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f4a4;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[27] = 0ULL;
    cpu->regs[1] = cpu->regs[19];
    if (((cpu->regs[19] >> 63) & 1)) goto L_21fed8;
L_21fe7c:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_21fed8;
L_21fe84:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_EQ) goto L_21ff58;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21fe84;
    cpu->regs[20] = cpu->regs[20] - 1ULL;
L_21fea0:
    if (!((cpu->regs[19] >> 63) & 1)) goto L_21fe7c;
    goto L_21fed8;
L_21fea8:
    if ((cpu->regs[27])!=0) goto L_21ff10;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_21f838;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21feccULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f15c;
    goto L_21f490;
L_21fed8:
    if ((cpu->regs[27])!=0) goto L_21fef0;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_21f838;
L_21fef0:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_LT) goto L_21f168;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21ff04ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f154;
    goto L_21f490;
L_21ff10:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21ff1cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f154;
    goto L_21f490;
L_21ff28:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21ff34ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fb74;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21fe50;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_21fe50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21ff54ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21fe50;
L_21ff58:
    cpu->regs[1] = cpu->regs[1] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x21ff68ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21f490;
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_22018c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[1]);
L_21ff80:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_21fea0;
L_21ff94:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21ffa4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2200b0;
L_21ffa4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_21ffb8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22027c;
L_21ffb8:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[22] = 0ULL;
    goto L_21f188;
L_21ffc4:
    cpu->regs[20] = 0ULL;
    goto L_21f048;
L_21ffcc:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21ffd8ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21f15c;
    goto L_21f490;
L_21ffe4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21fff0ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220094;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f318;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f318;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x220014ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f31c;
L_220018:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x220024ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2202f0;
L_220030:
    if (((cpu->regs[2] >> 31) & 1)) goto L_21f490;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21f490;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x220048ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f490;
L_22004c:
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22020c;
L_220058:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x220060ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22004c;
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x220070ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ffa4;
    FLAG_CMP(cpu->regs[24], 11ULL);
    if (FLAG_LE) goto L_220290;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x22008cULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2202a0;
L_220094:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21ffa4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21ffa4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2200acULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21ffa4;
L_2200b0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2200b8ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21ffa4;
L_2200bc:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f5a4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f5a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2200d4ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f5a4;
L_2200d8:
    PB_LDR(cpu->regs[26], (cpu->regs[23] + 56));
    goto L_21f254;
L_2200e0:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x2200f0ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[2], (SP + 104));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fb74;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f714;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f714;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x220118ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 104));
    goto L_21f714;
L_220120:
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_220200;
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 56));
L_220128:
    FLAG_CMP(cpu->regs[20], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x22013cULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ffb8;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2520));
    cpu->regs[21] = cpu->regs[19];
L_220158:
    cpu->regs[0] = cpu->regs[20] - cpu->regs[24];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_220208;
    if (((cpu->regs[21] >> 63) & 1)) goto L_22020c;
L_220168:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[21] - 1ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x220178ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_220234;
    cpu->regs[21] = cpu->regs[27];
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    if (!((cpu->regs[21] >> 63) & 1)) goto L_220168;
    goto L_22020c;
L_22018c:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x220198ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220030;
    if (((cpu->regs[2] >> 31) & 1)) goto L_21ff80;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21ff80;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x2201bcULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21ff80;
L_2201c0:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x2201d0ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[2], (SP + 104));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21fb74;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21f648;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21f648;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x2201f8ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 104));
    goto L_21f648;
L_220200:
    cpu->regs[25] = cpu->regs[23] + 56ULL;
    goto L_220128;
L_220208:
    if (!((cpu->regs[21] >> 63) & 1)) goto L_220058;
L_22020c:
    PB_STR((cpu->regs[22] + 16), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x220218ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x220364ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_21ffa4;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_21f188;
L_220224:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[27]));
    cpu->regs[30] = PB_BASE + 0x22022cULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220244;
    cpu->regs[27] = cpu->regs[27] - 1ULL;
L_220234:
    FLAG_CMP(cpu->regs[27], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_220224;
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_EQ) goto L_2202c0;
L_220244:
    cpu->regs[0] = cpu->regs[27] + 1ULL;
    cpu->regs[1] = cpu->regs[21] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[25] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x220254ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_220330;
    FLAG_CMP(cpu->regs[24], 11ULL);
    if (FLAG_GT) goto L_22030c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[24] << 3)), cpu->regs[21]);
L_22026c:
    cpu->regs[21] = cpu->regs[27];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_220158;
L_22027c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x220288ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_21f188;
L_220290:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[24] << 3)), cpu->regs[19]);
L_220298:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_22020c;
L_2202a0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_220298;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_220298;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x2202bcULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22020c;
L_2202c0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_NE) goto L_220244;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2202dc;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_2202dc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_22020c;
L_2202f0:
    if (((cpu->regs[2] >> 31) & 1)) goto L_21f7a0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21f7a0;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x220308ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21f7a0;
L_22030c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x220318ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_220338;
    if (((cpu->regs[1] >> 31) & 1)) goto L_220330;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_220354;
L_220330:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21ffa4;
L_220338:
    if (((cpu->regs[1] >> 31) & 1)) goto L_22026c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22026c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x220350ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22026c;
L_220354:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22035cULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21ffa4;
}
