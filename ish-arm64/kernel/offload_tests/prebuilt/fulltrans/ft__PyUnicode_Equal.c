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

void ft__PyUnicode_Equal(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_12b6e4;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_NE) goto L_12b718;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 32));
    PB_LDR(cpu->regs[6], (cpu->regs[3] + 32));
    cpu->regs[7] = ((uint32_t)(((cpu->regs[5] >> 2) & 0x7ULL)));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[6] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_NE) goto L_12b718;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if (!((cpu->regs[6] >> 5) & 1)) goto L_12b71c;
    if (!((cpu->regs[6] >> 6) & 1)) goto L_12b708;
    cpu->regs[0] = cpu->regs[3] + 40ULL;
    if (!((cpu->regs[5] >> 5) & 1)) goto L_12b710;
L_12b6c0:
    if (!((cpu->regs[5] >> 6) & 1)) goto L_12b6ec;
    cpu->regs[4] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[1] + 40ULL;
    cpu->regs[2] = cpu->regs[4] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b6d4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7ab70ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
L_12b6dc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_12b6e4:
    cpu->regs[0] = 1ULL;
    return;
L_12b6ec:
    cpu->regs[1] = cpu->regs[1] + 56ULL;
L_12b6f0:
    cpu->regs[4] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[4] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b6fcULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7ab70ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_12b6dc;
L_12b708:
    cpu->regs[0] = cpu->regs[3] + 56ULL;
    if (((cpu->regs[5] >> 5) & 1)) goto L_12b6c0;
L_12b710:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 56));
    goto L_12b6f0;
L_12b718:
    return;
L_12b71c:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 56));
    if (((cpu->regs[5] >> 5) & 1)) goto L_12b6c0;
    goto L_12b710;
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 40));
L_12b750:
    cpu->regs[27] = cpu->regs[19];
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 32));
    cpu->regs[24] = cpu->regs[3] & cpu->regs[19];
L_12b75c:
    cpu->regs[20] = cpu->regs[21] + (cpu->regs[24] << 4);
    cpu->regs[2] = cpu->regs[24] + 9ULL;
    cpu->regs[25] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[24] << 4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_LS) goto L_12b900;
    if ((cpu->regs[0])!=0) goto L_12b7a4;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + cpu->regs[4]));
    if ((cpu->regs[22])!=0) goto L_12b958;
L_12b784:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_12b7a4:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_12b8e8;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    cpu->regs[26] = 0ULL;
L_12b7b4:
    FLAG_CMP(cpu->regs[1], cpu->regs[22]);
    if (FLAG_EQ) goto L_12b784;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_12b964;
L_12b7d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12b7e0;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_12b7e0:
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12b7f0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 104));
    if (((cpu->regs[2] >> 31) & 1)) goto L_12b80c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_12b92c;
L_12b80c:
    if (((cpu->regs[28] >> 31) & 1)) goto L_12b9ac;
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 40));
    FLAG_CMP(cpu->regs[25], cpu->regs[21]);
    if (FLAG_NE) goto L_12b750;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_12b750;
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_12b784;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 32));
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_12b8e8;
L_12b838:
    cpu->regs[25] = 8ULL;
L_12b83c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    if ((cpu->regs[0])!=0) goto L_12b84c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    if ((cpu->regs[2])==0) goto L_12b784;
L_12b84c:
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_12b8d8;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_EQ) goto L_12b784;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_12b988;
L_12b874:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[26] = cpu->regs[21];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12b888;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_12b888:
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12b898ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 104));
    if (((cpu->regs[2] >> 31) & 1)) goto L_12b8b4;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_12b940;
L_12b8b4:
    if (((cpu->regs[28] >> 31) & 1)) goto L_12b9ac;
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 40));
    FLAG_CMP(cpu->regs[21], cpu->regs[26]);
    if (FLAG_NE) goto L_12b750;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_12b750;
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_12b784;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 32));
L_12b8d8:
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] - 1ULL));
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    FLAG_CMP(cpu->regs[25], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12b83c;
L_12b8e8:
    cpu->regs[27] = cpu->regs[27] >> 5;
    cpu->regs[24] = cpu->regs[24] + (cpu->regs[24] << 2);
    cpu->regs[24] = cpu->regs[24] + cpu->regs[27];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    cpu->regs[24] = cpu->regs[24] & cpu->regs[3];
    goto L_12b75c;
L_12b900:
    if ((cpu->regs[0])!=0) goto L_12b918;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    if ((cpu->regs[22])==0) goto L_12b784;
    if ((cpu->regs[19])!=0) goto L_12b950;
    cpu->regs[26] = 9ULL;
    goto L_12b7b4;
L_12b918:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_12b950;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    cpu->regs[26] = 9ULL;
    goto L_12b7b4;
L_12b92c:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12b938ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    goto L_12b80c;
L_12b940:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12b948ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    goto L_12b8b4;
L_12b950:
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    goto L_12b838;
L_12b958:
    if ((cpu->regs[19])!=0) goto L_12b8e8;
    cpu->regs[26] = 0ULL;
    goto L_12b7b4;
L_12b964:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_12b7d0;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12b97cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d6c0ULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12b784;
    goto L_12b7d0;
L_12b988:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_12b874;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12b9a0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18d6c0ULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12b784;
    goto L_12b874;
L_12b9ac:
    cpu->regs[20] = 0ULL;
    goto L_12b784;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 32));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[5] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12b9e8;
    if (!((cpu->regs[4] >> 5) & 1)) goto L_12ba28;
    if (!((cpu->regs[4] >> 6) & 1)) goto L_12ba10;
    cpu->regs[2] = cpu->regs[0] + cpu->regs[1];
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 40));
    return;
L_12b9e8:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_12ba0c;
    if (!((cpu->regs[4] >> 5) & 1)) goto L_12ba1c;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    FLAG_CMP((((uint32_t)(cpu->regs[4]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[3] << 1)));
L_12ba08:
    return;
L_12ba0c:
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x1ac5acULL); return; };
L_12ba10:
    cpu->regs[2] = cpu->regs[0] + 56ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + cpu->regs[3]));
L_12ba18:
    return;
L_12ba1c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[3] << 1)));
    goto L_12ba08;
L_12ba28:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 56));
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + cpu->regs[3]));
    goto L_12ba18;
    /* nop */
    /* nop */
    /* nop */
}
