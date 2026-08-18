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

void ft_PyTuple_Size(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_10e678;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    return;
L_10e678:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 89ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[29] = SP;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0x10e690ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
L_10e6a0:
    SP = SP - 128ULL;
    cpu->regs[2] = 6000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_10ed1c;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ed2c;
L_10e6dc:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[28], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10e950;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[19] = (((uint64_t)(((int64_t)(cpu->regs[28] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_10e724;
L_10e700:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1103ULL)));
    if (FLAG_EQ) goto L_10e7bc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_10e700;
L_10e714:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_EQ) goto L_10e8b8;
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
L_10e724:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 148));
    PB_LDRW(cpu->regs[20], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[19], (cpu->regs[1] + 20) + 4);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e8dc;
L_10e730:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10e93c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e73cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e764;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10e814;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(642ULL)));
    if (FLAG_EQ) goto L_10e838;
L_10e764:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e93c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e778ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e7f0;
L_10e780:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = 1103ULL;
    cpu->regs[30] = PB_BASE + 0x10e794ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1082e0ULL);
L_10e794:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_10e7a0:
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_10e7bc:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[2]);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_10e7f0:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 96));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e794;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e804ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x198d00ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10e780;
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    goto L_10e780;
L_10e814:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e81cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e930;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(642ULL)));
    if (FLAG_NE) goto L_10e764;
L_10e838:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e84cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10edc8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 645ULL;
    cpu->regs[30] = PB_BASE + 0x10e860ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10edc8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e86cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[10] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10edc8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16));
    cpu->regs[30] = PB_BASE + 0x10e880ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10ed08;
    PB_LDR(cpu->regs[7], (cpu->regs[27] + 32));
    cpu->regs[4] = cpu->regs[19];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[10];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10e8a8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1a73c4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10ece4;
L_10e8b0:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10e780;
L_10e8b8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e8c0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10ebac;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 148));
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[19]));
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[19], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_10e730;
L_10e8dc:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ecd4;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10ecb8;
L_10e8f8:
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[1] = PB_BASE + 0x1e4000ULL;
    cpu->regs[2] = cpu->regs[27];
    PB_LDRW(cpu->regs[26], (cpu->regs[27] + 16));
    cpu->regs[1] = cpu->regs[1] + 1824ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10e914ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10e928;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e920ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10e978;
L_10e928:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    goto L_10ea14;
L_10e930:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
L_10e93c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10e7a0;
L_10e950:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e958ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10ebac;
    PB_LDRW(cpu->regs[28], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[19] = (((uint64_t)(((int64_t)(cpu->regs[28] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_10e700;
    goto L_10e714;
L_10e978:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144)); PB_LDRW(cpu->regs[21], (cpu->regs[27] + 144) + 4);
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]); PB_STRW((cpu->regs[27] + 144) + 4, 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10ed70;
L_10e990:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10edd0;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[23], (cpu->regs[27] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10ed38;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20) + 4);
    PB_STRW((SP + 120), cpu->regs[1]); PB_STRW((SP + 120) + 4, cpu->regs[0]);
L_10e9b8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e9c0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10ee00;
L_10e9c8:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ed5c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e9dcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10ebd8;
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ed5c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10e9f8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x198d00ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10ebc8;
L_10ea00:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]); PB_STRW((cpu->regs[27] + 144) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
L_10ea14:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ea70;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ea24ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10ea3c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 642ULL;
    cpu->regs[30] = PB_BASE + 0x10ea38ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_10ed7c;
L_10ea3c:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ea70;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 600ULL;
    cpu->regs[30] = PB_BASE + 0x10ea54ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10eacc;
L_10ea5c:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
L_10ea60:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
L_10ea64:
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10ea7c;
L_10ea70:
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_10ea7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 148));
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    PB_STRW((cpu->regs[27] + 144), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10e730;
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10eb4c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10ec58;
L_10eaa4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10eaacULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10eb5c;
L_10eab4:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_10eac0:
    PB_STRW((cpu->regs[27] + 16), cpu->regs[28]);
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]);
    goto L_10e730;
L_10eacc:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ead4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1e0684ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ea60;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x10eae8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10ea5c;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[2] = 62ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x10eb00ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10ea5c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 20),&_a,4); tlb_read(tlb,(cpu->regs[21] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3680ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[27];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 28),&_a,4); tlb_read(tlb,(cpu->regs[22] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
L_10eb24:
    cpu->regs[30] = PB_BASE + 0x10eb28ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x10eb2cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_10ec74;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_10ea7c;
L_10eb4c:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_10e7a0;
L_10eb5c:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[2] = 7ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10eb6cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10eab4;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10eb78ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x10ef20ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10eab4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x10eb88ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1e56c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10ec88;
L_10eb8c:
    cpu->regs[30] = PB_BASE + 0x10eb90ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10eab4;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[3] = cpu->regs[1];
    PB_STRW((cpu->regs[27] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10eac0;
L_10ebac:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[1]);
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_10e7a0;
L_10ebc8:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    PB_STRW((cpu->regs[27] + 148), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10ebe4;
L_10ebd8:
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
L_10ebdc:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[27] + 148), cpu->regs[21]);
L_10ebe4:
    PB_STRW((cpu->regs[27] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10ebf0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1e56c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10ec30;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10ec30;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 32),&_a,4); tlb_read(tlb,(cpu->regs[22] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3592ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[27];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 40),&_a,4); tlb_read(tlb,(cpu->regs[24] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[30] = PB_BASE + 0x10ec30ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x280d00ULL);
L_10ec30:
    cpu->regs[30] = PB_BASE + 0x10ec34ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_10ec7c;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_10ea7c;
L_10ec58:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ec60ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10eaa4;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10eac0;
L_10ec74:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    goto L_10ea64;
L_10ec7c:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    goto L_10ea64;
L_10ec88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[21] + 8));
    cpu->regs[6] = cpu->regs[6] + 3752ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[27];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 32),&_a,4); tlb_read(tlb,(cpu->regs[21] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 40),&_a,4); tlb_read(tlb,(cpu->regs[22] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    PB_STR((SP + 0), cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x10ecb4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x280d00ULL);
    goto L_10eb8c;
L_10ecb8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ecc0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10e8f8;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10ea7c;
L_10ecd4:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_10e7a0;
L_10ece4:
    cpu->regs[30] = PB_BASE + 0x10ece8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10e8b0;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10e7a0;
L_10ed08:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10e7a0;
L_10ed1c:
    cpu->regs[30] = PB_BASE + 0x10ed20ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10e6dc;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
L_10ed2c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_10e7a0;
L_10ed38:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ed40ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10ede0;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20) + 4);
    PB_STRW((SP + 120), cpu->regs[1]); PB_STRW((SP + 120) + 4, cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10e9b8;
L_10ed5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]); PB_STRW((cpu->regs[27] + 144) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10ea14;
L_10ed70:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ed78ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_10e990;
L_10ed7c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ed84ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10ea3c;
    cpu->regs[1] = PB_BASE + 0x94000ULL;
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[1] + 2716ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10eda0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10ea3c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 32),&_a,4); tlb_read(tlb,(cpu->regs[21] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3640ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[27];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 40),&_a,4); tlb_read(tlb,(cpu->regs[22] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_10eb24;
L_10edc8:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10e764;
L_10edd0:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]); PB_STRW((cpu->regs[27] + 144) + 4, cpu->regs[21]);
    goto L_10ea14;
L_10ede0:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[1]);
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[27] + 144), cpu->regs[0]); PB_STRW((cpu->regs[27] + 144) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10ea14;
L_10ee00:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 642ULL;
    cpu->regs[30] = PB_BASE + 0x10ee0cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10e9c8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ee18ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e9c8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 645ULL;
    cpu->regs[30] = PB_BASE + 0x10ee2cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10e9c8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10ee38ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[10] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e9c8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 16));
    cpu->regs[30] = PB_BASE + 0x10ee4cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_10ea00;
    PB_LDR(cpu->regs[7], (cpu->regs[27] + 32));
    cpu->regs[1] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[10];
    PB_LDRW(cpu->regs[4], (SP + 120)); PB_LDRW(cpu->regs[3], (SP + 120) + 4);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10ee6cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1a73c4ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_10ebdc;
    cpu->regs[30] = PB_BASE + 0x10ee80ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_10ee94;
    PB_STRW((cpu->regs[27] + 144), cpu->regs[4]); PB_STRW((cpu->regs[27] + 144) + 4, cpu->regs[21]);
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10ea14;
L_10ee94:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[27] + 96), cpu->regs[0]);
    PB_STRW((cpu->regs[27] + 144), cpu->regs[4]); PB_STRW((cpu->regs[27] + 144) + 4, cpu->regs[21]);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_10ea14;
}
