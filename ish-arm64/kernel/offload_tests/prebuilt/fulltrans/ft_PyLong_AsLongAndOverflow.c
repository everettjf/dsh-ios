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

void ft_PyLong_AsLongAndOverflow(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_STRW((cpu->regs[1] + 0), 0ULL);
    if ((cpu->regs[0])==0) goto L_129830;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 24) & 1)) goto L_12975c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[0], 15ULL);
    if (FLAG_HI) goto L_129778;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 24));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[19] = 1ULL;
    cpu->regs[19] = cpu->regs[19] - cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[1];
L_12974c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_12975c:
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x129764ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x123ed0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_129804;
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_12974c;
L_129778:
    cpu->regs[6] = 0ULL;
L_12977c:
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] & 3ULL));
    cpu->regs[5] = 1ULL;
    cpu->regs[0] = cpu->regs[0] >> 3;
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - cpu->regs[4]));
    cpu->regs[7] = cpu->regs[2] + 24ULL;
    cpu->regs[3] = 0ULL;
L_129794:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1297b8;
    PB_LDRW(cpu->regs[4], (cpu->regs[7] + (cpu->regs[0] << 2)));
    cpu->regs[4] = cpu->regs[4] | (cpu->regs[3] << 30);
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_NE) goto L_1297f8;
    cpu->regs[3] = cpu->regs[4];
    goto L_129794;
L_1297b8:
    if (((cpu->regs[3] >> 63) & 1)) goto L_1297e8;
    cpu->regs[5] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]));
    cpu->regs[19] = cpu->regs[5] * cpu->regs[3];
L_1297c4:
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_12974c;
L_1297c8:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12974c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12974c;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1297e4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12974c;
L_1297e8:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(0ULL)));
    cpu->regs[19] = 9223372036854775808ULL;
    if (FLAG_LT) { FLAG_CMP(cpu->regs[3], cpu->regs[19]); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_1297c4;
L_1297f8:
    cpu->regs[19] = 18446744073709551615ULL;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[5]);
    goto L_1297c4;
L_129804:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[0], 15ULL);
    if (FLAG_HI) goto L_129828;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 24));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[19] = 1ULL;
    cpu->regs[19] = cpu->regs[19] - cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[1];
    goto L_1297c8;
L_129828:
    cpu->regs[6] = 1ULL;
    goto L_12977c;
L_129830:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = 473ULL;
    cpu->regs[0] = cpu->regs[0] + 408ULL;
    cpu->regs[19] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x129844ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_12974c;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[8] = cpu->regs[5] & 3ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[7] = cpu->regs[0] & 3ULL;
    cpu->regs[4] = cpu->regs[5] | cpu->regs[0];
    cpu->regs[6] = cpu->regs[2] - cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] - cpu->regs[8];
    FLAG_CMP(cpu->regs[4], 15ULL);
    if (FLAG_HI) goto L_129888;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[6];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1] * cpu->regs[2];
L_129884:
    return;
L_129888:
    cpu->regs[4] = cpu->regs[0] >> 3;
    cpu->regs[5] = cpu->regs[5] >> 3;
    cpu->regs[6] = cpu->regs[4] * cpu->regs[6];
    cpu->regs[0] = cpu->regs[6] - cpu->regs[5] * cpu->regs[2];
    if ((cpu->regs[0])!=0) goto L_129884;
    if ((cpu->regs[4])==0) goto L_129958;
    cpu->regs[5] = cpu->regs[3] + (cpu->regs[4] << 2);
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[4] << 2);
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 20));
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 20));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[6])); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_129940;
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_EQ) goto L_129958;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 16));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[6])); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_129940;
    FLAG_CMP(cpu->regs[4], 2ULL);
    if (FLAG_EQ) goto L_129958;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 12));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 12));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[6])); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_129940;
    FLAG_CMP(cpu->regs[4], 3ULL);
    if (FLAG_EQ) goto L_129958;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[6])); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_129940;
    FLAG_CMP(cpu->regs[4], 4ULL);
    if (FLAG_EQ) goto L_129958;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 4));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 4));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[0])); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_129940;
L_129918:
    FLAG_CMP(cpu->regs[4], 5ULL);
    if (FLAG_EQ) goto L_129958;
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + (cpu->regs[4] << 2)));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + (cpu->regs[4] << 2)));
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[0])); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_129918;
    /* nop */
    /* nop */
    /* nop */
L_129940:
    cpu->regs[0] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[2])));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[7], 2ULL);
    if (FLAG_EQ) goto L_129884;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    return;
L_129958:
    cpu->regs[2] = 0ULL;
    goto L_129940;
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129994;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[0], 15ULL);
    if (FLAG_HI) goto L_129994;
    cpu->regs[2] = cpu->regs[0] & 3ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 24));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[3];
    cpu->regs[2] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[2], 261ULL);
    if (FLAG_LS) goto L_1299c4;
L_129994:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0xdf000ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 320));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_1299f0;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1299c4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_129994;
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    return;
L_1299f0:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
L_129a00:
    SP = SP - 208ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    PB_STR((SP + 160), cpu->regs[23]); PB_STR((SP + 160) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 176), cpu->regs[25]); PB_STR((SP + 176) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    PB_STR((SP + 192), cpu->regs[27]); PB_STR((SP + 192) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 104), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])!=0) goto L_129c6c;
L_129a50:
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 16));
    if (((cpu->regs[19] >> 63) & 1)) goto L_129d58;
    FLAG_CMP(cpu->regs[19], cpu->regs[4]);
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[4];
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_GT) goto L_129d60;
L_129a68:
    FLAG_CMP(cpu->regs[20], cpu->regs[4]);
    cpu->regs[20] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[4];
    cpu->regs[21] = cpu->regs[27] - cpu->regs[20];
    cpu->regs[26] = cpu->regs[20] - cpu->regs[19];
    cpu->regs[21] = cpu->regs[21] + cpu->regs[19];
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(cpu->regs[4])));
    if (FLAG_EQ) goto L_129d68;
    PB_LDR(cpu->regs[6], (cpu->regs[23] + 24));
    cpu->regs[3] = cpu->regs[26] << 3;
    if ((cpu->regs[3])==0) goto L_129d3c;
    FLAG_CMP(cpu->regs[3], 64ULL);
    if (FLAG_HI) goto L_129ddc;
    cpu->regs[1] = cpu->regs[6] + (cpu->regs[19] << 3);
    cpu->regs[22] = SP + 40ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[22]);
    if (FLAG_HI) goto L_129dcc;
    if (FLAG_HS) goto L_129ab8;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[3];
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_LO) goto L_129dd8;
L_129ab8:
    FLAG_CMP(cpu->regs[3], 8ULL);
    if (FLAG_NE) goto L_129c40;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[5] = cpu->regs[22];
    if (!((cpu->regs[21] >> 63) & 1)) goto L_129ca0;
L_129ad0:
    cpu->regs[4] = cpu->regs[4] - cpu->regs[20];
    cpu->regs[28] = cpu->regs[20] + cpu->regs[21];
    cpu->regs[20] = cpu->regs[6] + (cpu->regs[20] << 3);
    PB_STR((SP + 8), cpu->regs[6]); PB_STR((SP + 8) + 8, cpu->regs[5]);
    cpu->regs[28] = cpu->regs[6] + (cpu->regs[28] << 3);
    cpu->regs[22] = cpu->regs[4] << 3;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[28];
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x129afcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 16));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x129b0cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe5550ULL);
    PB_LDR(cpu->regs[6], (SP + 8)); PB_LDR(cpu->regs[5], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_129e24;
    cpu->regs[22] = SP + 40ULL;
    FLAG_CMP(cpu->regs[27], 0ULL);
    if (FLAG_LE) goto L_129b84;
    PB_LDR(cpu->regs[6], (cpu->regs[23] + 24));
    cpu->regs[22] = SP + 40ULL;
L_129b2c:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[2] = cpu->regs[19] << 3;
    cpu->regs[19] = cpu->regs[6] + (cpu->regs[19] << 3);
    if ((cpu->regs[0])==0) goto L_129d94;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_129d94;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[6] + cpu->regs[2]), cpu->regs[0]);
    FLAG_CMP(cpu->regs[27], 1ULL);
    if (FLAG_EQ) goto L_129b84;
L_129b58:
    cpu->regs[0] = 1ULL;
L_129b5c:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 3)));
    if ((cpu->regs[1])==0) goto L_129d80;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_129d80;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[19] + (cpu->regs[0] << 3)), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_NE) goto L_129b5c;
L_129b84:
    cpu->regs[0] = cpu->regs[26] - 1ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_LT) goto L_129bdc;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + (cpu->regs[0] << 3)));
    if ((cpu->regs[0])==0) goto L_129ba8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_129ba8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_129d18;
L_129ba8:
    cpu->regs[19] = cpu->regs[26] - 2ULL;
    FLAG_CMP(cpu->regs[26], 1ULL);
    if (FLAG_EQ) goto L_129bdc;
L_129bb4:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + (cpu->regs[19] << 3)));
    if ((cpu->regs[0])==0) goto L_129bd0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_129bd0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_129cf4;
L_129bd0:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_129bb4;
L_129bdc:
    cpu->regs[19] = 0ULL;
L_129be0:
    FLAG_CMP(cpu->regs[5], cpu->regs[22]);
    if (FLAG_NE) goto L_129db4;
L_129be8:
    if ((cpu->regs[24])==0) goto L_129c00;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_129c00;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_129d44;
L_129c00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_129dc8;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    PB_LDR(cpu->regs[23], (SP + 160)); PB_LDR(cpu->regs[24], (SP + 160) + 8);
    PB_LDR(cpu->regs[25], (SP + 176)); PB_LDR(cpu->regs[26], (SP + 176) + 8);
    PB_LDR(cpu->regs[27], (SP + 192)); PB_LDR(cpu->regs[28], (SP + 192) + 8);
    SP = SP + 208ULL;
    return;
L_129c40:
    cpu->regs[5] = cpu->regs[22];
L_129c44:
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 8), cpu->regs[3]); PB_STR((SP + 8) + 8, cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x129c54ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (SP + 8)); PB_LDR(cpu->regs[6], (SP + 8) + 8);
L_129c5c:
    cpu->regs[22] = SP + 40ULL;
    if (!((cpu->regs[21] >> 63) & 1)) goto L_129ca0;
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 16));
    goto L_129ad0;
L_129c6c:
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_129e84;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0x129c84ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129ed0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[27], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_129dc0;
    PB_LDR(cpu->regs[25], (cpu->regs[24] + 24));
    goto L_129a50;
L_129ca0:
    if ((cpu->regs[21])==0) goto L_129ce8;
    PB_LDR(cpu->regs[28], (cpu->regs[23] + 16));
    cpu->regs[0] = cpu->regs[23];
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[1] = cpu->regs[28] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x129cb8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe5550ULL);
    PB_LDR(cpu->regs[5], (SP + 8));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_129e7c;
    PB_LDR(cpu->regs[6], (cpu->regs[23] + 24));
    cpu->regs[2] = cpu->regs[28] - cpu->regs[20];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[6]); PB_STR((SP + 8) + 8, cpu->regs[5]);
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[1] = cpu->regs[6] + (cpu->regs[20] << 3);
    cpu->regs[0] = cpu->regs[6] + (cpu->regs[0] << 3);
    cpu->regs[30] = PB_BASE + 0x129ce4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_LDR(cpu->regs[6], (SP + 8)); PB_LDR(cpu->regs[5], (SP + 8) + 8);
L_129ce8:
    FLAG_CMP(cpu->regs[27], 0ULL);
    if (FLAG_GT) goto L_129b2c;
    goto L_129b84;
L_129cf4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x129d08ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[5], (SP + 8));
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_129bb4;
    goto L_129bdc;
L_129d18:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[19] = cpu->regs[26] - 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x129d2cULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[5], (SP + 8));
    FLAG_CMP(cpu->regs[26], 1ULL);
    if (FLAG_NE) goto L_129bb4;
    goto L_129bdc;
L_129d3c:
    cpu->regs[5] = SP + 40ULL;
    goto L_129c5c;
L_129d44:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x129d54ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    goto L_129c00;
L_129d58:
    cpu->regs[19] = 0ULL;
    if (!((cpu->regs[20] >> 63) & 1)) goto L_129a68;
L_129d60:
    FLAG_CMP(cpu->regs[27], (uint64_t)(-(int64_t)(cpu->regs[4])));
    if (FLAG_NE) goto L_129ed8;
L_129d68:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x129d70ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x129d7cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x129f00ULL);
    goto L_129c00;
L_129d80:
    PB_STR((cpu->regs[19] + (cpu->regs[0] << 3)), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_NE) goto L_129b5c;
    goto L_129b84;
L_129d94:
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[27], 1ULL);
    if (FLAG_NE) goto L_129b58;
    goto L_129b84;
L_129da4:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x129dacULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[5], (SP + 8));
    cpu->regs[19] = 4294967295ULL;
L_129db4:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x129dbcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_129be8;
L_129dc0:
    cpu->regs[25] = cpu->regs[24] + 24ULL;
    goto L_129a50;
L_129dc8:
    cpu->regs[30] = PB_BASE + 0x129dccULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_129dcc:
    cpu->regs[0] = cpu->regs[22] + cpu->regs[3];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_129ab8;
L_129dd8:
    __builtin_trap();
L_129ddc:
    cpu->regs[0] = cpu->regs[3];
    PB_STR((SP + 8), cpu->regs[3]); PB_STR((SP + 8) + 8, cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x129de8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_LDR(cpu->regs[3], (SP + 8)); PB_LDR(cpu->regs[6], (SP + 8) + 8);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129da4;
    cpu->regs[1] = cpu->regs[6] + (cpu->regs[19] << 3);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_129e14;
    if (FLAG_LS) goto L_129c44;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[3];
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_HS) goto L_129c44;
    __builtin_trap();
L_129e14:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_129c44;
    __builtin_trap();
L_129e24:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 8), cpu->regs[5]); PB_STR((SP + 8) + 8, cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x129e38ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_LDR(cpu->regs[5], (SP + 8)); PB_LDR(cpu->regs[6], (SP + 8) + 8);
    cpu->regs[0] = cpu->regs[6] + (cpu->regs[19] << 3);
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_LO) { FLAG_CMP(cpu->regs[20], cpu->regs[5]); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_129dd8;
    PB_LDR(cpu->regs[3], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_LS) goto L_129e64;
    cpu->regs[1] = cpu->regs[5] + cpu->regs[3];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_129dd8;
L_129e64:
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[3];
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x129e74ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[5], (SP + 8));
    cpu->regs[22] = SP + 40ULL;
L_129e7c:
    cpu->regs[19] = 4294967295ULL;
    goto L_129be0;
L_129e84:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 16));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x129e90ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1db900ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129ed0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x129eacULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x129a00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_129c00;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_129c00;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x129eccULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_129c00;
L_129ed0:
    cpu->regs[19] = 4294967295ULL;
    goto L_129c00;
L_129ed8:
    PB_LDR(cpu->regs[6], (cpu->regs[23] + 24));
    cpu->regs[21] = cpu->regs[27];
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[5] = SP + 40ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[26] = 0ULL;
    goto L_129c5c;
    /* nop */
    /* nop */
    /* nop */
L_129f00:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    if ((cpu->regs[20])==0) goto L_129f44;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    PB_STR((cpu->regs[0] + 16), 0ULL); PB_STR((cpu->regs[0] + 16) + 8, 0ULL);
    PB_STR((cpu->regs[0] + 32), 0ULL);
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_129f3c;
L_129f28:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[19] << 3)));
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x129f34ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdce4cULL);
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_129f28;
L_129f3c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x129f44ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_129f44:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LO) goto L_129fc0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 24) + 8);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_129fc0;
L_129f90:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_129fe0;
    PB_STRB((cpu->regs[2] + cpu->regs[1]), cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
L_129fb0:
    cpu->regs[0] = 0ULL;
L_129fb4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_129fc0:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x129fd0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11cba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_129fb4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    goto L_129f90;
L_129fe0:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_129ff8;
    PB_STRH((cpu->regs[2] + (cpu->regs[1] << 1)), cpu->regs[20]);
L_129fec:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    goto L_129fb0;
L_129ff8:
    PB_STRW((cpu->regs[2] + (cpu->regs[1] << 2)), cpu->regs[20]);
    goto L_129fec;
}
