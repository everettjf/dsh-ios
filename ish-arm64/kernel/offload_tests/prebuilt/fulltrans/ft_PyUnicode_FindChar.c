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

void ft_PyUnicode_FindChar(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_GT) goto L_134ad0;
    if (((cpu->regs[3] >> 63) & 1)) goto L_134ab8;
L_1348ec:
    if (((cpu->regs[20] >> 63) & 1)) goto L_134ac4;
L_1348f0:
    cpu->regs[3] = cpu->regs[3] - cpu->regs[20];
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_LE) goto L_1349c0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    cpu->regs[5] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_134ab0;
    if (!((cpu->regs[2] >> 6) & 1)) goto L_134a30;
    cpu->regs[19] = cpu->regs[5];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[20] + cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] + 40ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_134a44;
L_134920:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_1349c0;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_134a1c;
    FLAG_CMP(cpu->regs[3], 15ULL);
    if (FLAG_GT) goto L_1349d0;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[3];
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_LS) goto L_1349c0;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_134a10;
    cpu->regs[3] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_HS) goto L_1349c0;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1349fc;
    cpu->regs[3] = cpu->regs[19] + 2ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_1349c0;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1349fc;
    cpu->regs[3] = cpu->regs[19] + 3ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_HS) goto L_1349c0;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 3));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1349fc;
    cpu->regs[3] = cpu->regs[19] + 4ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_HS) goto L_1349c0;
L_1349a8:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1349fc;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_NE) goto L_1349a8;
L_1349c0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1349d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1349dcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7bdd0ULL);
    cpu->regs[19] = cpu->regs[0] - cpu->regs[19];
    if ((cpu->regs[0])==0) goto L_1349c0;
L_1349e4:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1349c0;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
L_1349f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1349fc:
    cpu->regs[19] = cpu->regs[3] - cpu->regs[19];
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1349c0;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
    goto L_1349f0;
L_134a10:
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
    goto L_1349f0;
L_134a1c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x134a28ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1a8180ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1349e4;
L_134a30:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
L_134a34:
    cpu->regs[19] = cpu->regs[5];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[20] + cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_134920;
L_134a44:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_134a78;
    cpu->regs[0] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_1349c0;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 65535ULL));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_134a98;
    cpu->regs[30] = PB_BASE + 0x134a70ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x22e7e0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1349e4;
L_134a78:
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_134aa4;
    cpu->regs[30] = PB_BASE + 0x134a90ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x25a4e0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1349e4;
L_134a98:
    cpu->regs[30] = PB_BASE + 0x134a9cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x272c00ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1349e4;
L_134aa4:
    cpu->regs[30] = PB_BASE + 0x134aa8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x27fe40ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1349e4;
L_134ab0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_134a34;
L_134ab8:
    cpu->regs[3] = cpu->regs[3] + cpu->regs[5];
    cpu->regs[3] = cpu->regs[3] & ~(((uint64_t)((int64_t)cpu->regs[3] >> 63)));
    goto L_1348ec;
L_134ac4:
    cpu->regs[20] = cpu->regs[20] + cpu->regs[5];
    cpu->regs[20] = cpu->regs[20] & ~(((uint64_t)((int64_t)cpu->regs[20] >> 63)));
    goto L_1348f0;
L_134ad0:
    cpu->regs[3] = cpu->regs[5];
    goto L_1348ec;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[2], 15ULL);
    if (FLAG_HI) goto L_134b48;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2];
    cpu->regs[2] = 5ULL;
    cpu->regs[1] = cpu->regs[1] * cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[0] = (uint64_t)(-(int64_t)cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], 261ULL);
    if (FLAG_HI) goto L_134b30;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    return;
L_134b30:
    cpu->regs[2] = 1073741823ULL;
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_134b7c;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0xe3e84ULL); return; };
L_134b48:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x134b54ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x170a04ULL);
    if ((cpu->regs[0])==0) goto L_134b74;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[1] = 2ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 3ULL));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551608ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
L_134b74:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_134b7c:
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x169eacULL); return; };
}
