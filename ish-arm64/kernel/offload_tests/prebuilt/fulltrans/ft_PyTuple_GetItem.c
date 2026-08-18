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

void ft_PyTuple_GetItem(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 26) & 1)) goto L_10ef00;
    if (((cpu->regs[1] >> 63) & 1)) goto L_10eee0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_GE) goto L_10eee0;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
L_10eed8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_10eee0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x10eef8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_10eed8;
L_10ef00:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 100ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0x10ef10ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_10eed8;
    /* nop */
    /* nop */
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10f3f8;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10f408;
L_10ef54:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_10f0b4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[21], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x10ef7cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x10fa88ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f0e4;
L_10ef84:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 6000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10f430;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f444;
L_10efa8:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[1] = 8ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[26] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x10efc4ULL; PB_CALL(4, cpu, tlb, cpu->regs[2]);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f450;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f034;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10f410;
L_10efec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10f0ec;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_10f110;
L_10f00c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
L_10f01c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136));
    cpu->regs[1] = cpu->regs[25];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 168));
    cpu->regs[30] = PB_BASE + 0x10f02cULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
L_10f02c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
L_10f034:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_10f040:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f270;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f050ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x10fa88ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f078;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10f1ec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_10f210;
L_10f078:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10f270;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f08cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x10fa88ULL);
    if ((cpu->regs[0])!=0) goto L_10f094;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_10f094:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_10f0a8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_10f0b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f0bcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f3dc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_10f270;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f0dcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x10fa88ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10ef84;
L_10f0e4:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    goto L_10f040;
L_10f0ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f0f4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f3ac;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_NE) goto L_10f00c;
L_10f110:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f120ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x10fa88ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_10f378;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = 1ULL;
    cpu->regs[4] = cpu->regs[28];
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[3] = 6000ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
L_10f148:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[27] = cpu->regs[28];
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_10f3c8;
L_10f160:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10f188;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10f348;
L_10f174:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_10f1a4;
L_10f188:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10f18c:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_10f190:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    if ((cpu->regs[27])!=0) goto L_10f28c;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_10f01c;
L_10f1a4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 96), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10f1b8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x10fa88ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[5])==0) goto L_10f18c;
    PB_LDR(cpu->regs[4], (SP + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[3] = 6000ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[28]);
    if (FLAG_EQ) goto L_10f384;
L_10f1dc:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[25] + (cpu->regs[28] << 3)), cpu->regs[5]);
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    goto L_10f148;
L_10f1ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f1f4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f264;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(12ULL)));
    if (FLAG_NE) goto L_10f078;
L_10f210:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x10f21cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_10f270;
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 28) + 4);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x10f230ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x116c40ULL);
    if ((cpu->regs[0])==0) goto L_10f4a4;
L_10f234:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x10f250ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1a4ee0ULL);
    if ((cpu->regs[0])!=0) goto L_10f094;
    cpu->regs[30] = PB_BASE + 0x10f258ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_10f3dc;
    cpu->regs[0] = 0ULL;
    goto L_10f094;
L_10f264:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_10f270:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_10f280:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f0a8;
L_10f28c:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_10f490;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10f2a0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f460;
L_10f2a8:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[27], cpu->regs[23]);
    if (FLAG_LE) goto L_10f2cc;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 8));
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[25] + cpu->regs[1]));
    PB_STR((cpu->regs[0] + cpu->regs[1]), cpu->regs[2]);
    goto L_10f2a8;
L_10f2cc:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10f2d4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x10f2ecULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f500;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x10f300ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_10f4f8;
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f318ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x118accULL);
    if ((cpu->regs[0])==0) goto L_10f4c8;
L_10f31c:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x10f338ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1a4ee0ULL);
    if ((cpu->regs[0])==0) goto L_10f4b0;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_10f094;
L_10f348:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 96), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10f354ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f364;
    PB_LDR(cpu->regs[4], (SP + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_10f174;
L_10f364:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_10f190;
L_10f378:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_10f01c;
L_10f384:
    cpu->regs[4] = cpu->regs[4] << 1;
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 96), cpu->regs[4]); PB_STR((SP + 96) + 8, cpu->regs[5]);
    cpu->regs[1] = cpu->regs[4] << 3;
    cpu->regs[30] = PB_BASE + 0x10f398ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe5680ULL);
    PB_LDR(cpu->regs[4], (SP + 96)); PB_LDR(cpu->regs[5], (SP + 96) + 8);
    cpu->regs[3] = 6000ULL;
    if ((cpu->regs[0])==0) goto L_10f460;
    cpu->regs[25] = cpu->regs[0];
    goto L_10f1dc;
L_10f3ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_10f01c;
L_10f3c8:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 96), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10f3d4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDR(cpu->regs[4], (SP + 96));
    goto L_10f160;
L_10f3dc:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_10f280;
L_10f3f8:
    cpu->regs[30] = PB_BASE + 0x10f3fcULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10ef54;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10f408:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_10f280;
L_10f410:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f418ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10efec;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    goto L_10f18c;
L_10f430:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f438ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10efa8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10f444:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f040;
L_10f450:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x10f45cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_10f02c;
L_10f460:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10f468ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x10f474ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x22d780ULL);
L_10f474:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_10f040;
L_10f490:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136));
    cpu->regs[1] = cpu->regs[25];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 168));
    cpu->regs[30] = PB_BASE + 0x10f4a0ULL; PB_CALL(33, cpu, tlb, cpu->regs[2]);
    goto L_10f474;
L_10f4a4:
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_10f234;
L_10f4b0:
    cpu->regs[30] = PB_BASE + 0x10f4b4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_10f4d4;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_10f094;
L_10f4c8:
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_10f31c;
L_10f4d4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_10f4e0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_10f280;
L_10f4f8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    goto L_10f4e0;
L_10f500:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_10f040;
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10f96c;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f97c;
L_10f544:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10f79c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_10f58c;
L_10f568:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1111ULL)));
    if (FLAG_EQ) goto L_10f6b8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_10f568;
L_10f57c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_10f98c;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
L_10f58c:
    PB_LDRW(cpu->regs[21], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20) + 4);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10fa70;
L_10f594:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x10f5a0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x10fd10ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f6e8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 6000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10f9ec;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10fa00;
L_10f5cc:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[1] = 8ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[26] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x10f5e8ULL; PB_CALL(36, cpu, tlb, cpu->regs[2]);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fa14;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f658;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10fa24;
L_10f610:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10f6f8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(574ULL)));
    if (FLAG_EQ) goto L_10f71c;
L_10f630:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
L_10f640:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136));
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 168));
    cpu->regs[30] = PB_BASE + 0x10f650ULL; PB_CALL(37, cpu, tlb, cpu->regs[2]);
L_10f650:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
L_10f658:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_10f664:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10f7c4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f674ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x10fd10ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f6f0;
L_10f67c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1111ULL;
    cpu->regs[30] = PB_BASE + 0x10f690ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1082e0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_10f6b8:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
L_10f6d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_10f6e8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    goto L_10f664;
L_10f6f0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_10f67c;
L_10f6f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f700ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f8c0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(574ULL)));
    if (FLAG_NE) goto L_10f630;
L_10f71c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f72cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x10fd10ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])==0) goto L_10fa50;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[25] = 1ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    PB_STR((SP + 96), cpu->regs[25]);
L_10f74c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[27] = cpu->regs[25];
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10fa44;
L_10f768:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10fa38;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10f7e0;
L_10f77c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(574ULL)));
    if (FLAG_EQ) goto L_10f8dc;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10f794:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_10f804;
L_10f79c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f7a4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f998;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_10f568;
    goto L_10f57c;
L_10f7c4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f6d4;
L_10f7e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f7e8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10f7f4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_10f77c;
L_10f7f4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_10f804:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    if ((cpu->regs[27])==0) goto L_10f640;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_10f640;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10f824ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fa0c;
L_10f82c:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[27], cpu->regs[23]);
    if (FLAG_LE) goto L_10f850;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[24] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_10f82c;
L_10f850:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10f858ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x10f870ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f954;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    PB_LDRW(cpu->regs[23], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[24], (cpu->regs[0] + 28) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f88cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x118accULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f948;
L_10f894:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[5] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x10f8b0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x19c220ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f9b8;
L_10f8b8:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_10f67c;
L_10f8c0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_10f640;
L_10f8dc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f8ecULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x10fd10ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[5])==0) goto L_10f794;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 96));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_EQ) goto L_10f91c;
L_10f90c:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[24] + (cpu->regs[25] << 3)), cpu->regs[5]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_10f74c;
L_10f91c:
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[0] = cpu->regs[0] << 1;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 96), cpu->regs[1]); PB_STR((SP + 96) + 8, cpu->regs[5]);
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[30] = PB_BASE + 0x10f938ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe5680ULL);
    PB_LDR(cpu->regs[5], (SP + 104));
    if ((cpu->regs[0])==0) goto L_10fa0c;
    cpu->regs[24] = cpu->regs[0];
    goto L_10f90c;
L_10f948:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_10f894;
L_10f954:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 2ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f6d4;
L_10f96c:
    cpu->regs[30] = PB_BASE + 0x10f970ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10f544;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10f97c:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[23] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f6d4;
L_10f98c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f994ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_10fa5c;
L_10f998:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[23] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f6d4;
L_10f9b8:
    cpu->regs[30] = PB_BASE + 0x10f9bcULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10f8b8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[23] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f6d4;
L_10f9ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10f9f4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10f5cc;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10fa00:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f664;
L_10fa0c:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10fa14ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_10fa14:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x10fa20ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_10f650;
L_10fa24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fa2cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10f610;
    cpu->regs[27] = 0ULL;
L_10fa38:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_10f804;
L_10fa44:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fa4cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_10f768;
L_10fa50:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[27] = 0ULL;
    goto L_10f804;
L_10fa5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[21]));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_10f594;
L_10fa70:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10f6d4;
L_10fa88:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_10fc7c;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_10fc8c;
L_10fac0:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10fbf4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_10fb08;
L_10fae0:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1106ULL)));
    if (FLAG_EQ) goto L_10fb64;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_10fae0;
L_10faf4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_10fc1c;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_10fca8;
L_10fb08:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_10fb90;
L_10fb14:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_10fca8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fb24ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10fb30;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_10fb30:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1106ULL;
    cpu->regs[30] = PB_BASE + 0x10fb44ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1082e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_10fb64:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[2]);
L_10fb78:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_10fb90:
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[1] + 20) + 4);
L_10fb9c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fbacULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x111f50ULL);
    cpu->regs[7] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fc70;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x10fbc0ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fcc0;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x10fbe4ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1a7be4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fcd0;
L_10fbec:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_10fb30;
L_10fbf4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fbfcULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10fcf8;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_10fae0;
    goto L_10faf4;
L_10fc1c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fc24ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10fcf8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[21]));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_10fca4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_10fcb8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fc54ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10fc98;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
L_10fc64:
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_10fb9c;
L_10fc70:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    goto L_10fb14;
L_10fc7c:
    cpu->regs[30] = PB_BASE + 0x10fc80ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_10fac0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_10fc8c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_10fb78;
L_10fc98:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_10fca4:
    PB_LDR(cpu->regs[23], (SP + 48));
L_10fca8:
    cpu->regs[21] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10fb78;
L_10fcb8:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    goto L_10fc64;
L_10fcc0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10fb78;
L_10fcd0:
    cpu->regs[30] = PB_BASE + 0x10fcd4ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fbec;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_10fb78;
L_10fcf8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10fb78;
L_10fd10:
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_110170;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_110180;
L_10fd48:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10ffa0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_10fd90;
L_10fd6c:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1112ULL)));
    if (FLAG_EQ) goto L_10febc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_10fd6c;
L_10fd80:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_110190;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
L_10fd90:
    PB_LDRW(cpu->regs[21], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20) + 4);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_110274;
L_10fd98:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x10fda4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1103a0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10feec;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 6000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1101f0;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_110204;
L_10fdd0:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[1] = 8ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[26] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x10fdecULL; PB_CALL(70, cpu, tlb, cpu->regs[2]);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110218;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10fe5c;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_110228;
L_10fe14:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10fefc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(575ULL)));
    if (FLAG_EQ) goto L_10ff20;
L_10fe34:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
L_10fe44:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 136));
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 168));
    cpu->regs[30] = PB_BASE + 0x10fe54ULL; PB_CALL(71, cpu, tlb, cpu->regs[2]);
L_10fe54:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
L_10fe5c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_10fe68:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10ffc8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10fe78ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1103a0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10fef4;
L_10fe80:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1112ULL;
    cpu->regs[30] = PB_BASE + 0x10fe94ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x1082e0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_10febc:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
L_10fed8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_10feec:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    goto L_10fe68;
L_10fef4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_10fe80;
L_10fefc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10ff04ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1100c4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(575ULL)));
    if (FLAG_NE) goto L_10fe34;
L_10ff20:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10ff30ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x1103a0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])==0) goto L_110254;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[25] = 1ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    PB_STR((SP + 96), cpu->regs[25]);
L_10ff50:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[27] = cpu->regs[25];
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_110248;
L_10ff6c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11023c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10ffe4;
L_10ff80:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(575ULL)));
    if (FLAG_EQ) goto L_1100e0;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_10ff98:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110008;
L_10ffa0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10ffa8ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11019c;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_10fd6c;
    goto L_10fd80;
L_10ffc8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fed8;
L_10ffe4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10ffecULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10fff8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_10ff80;
L_10fff8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_110008:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    if ((cpu->regs[27])==0) goto L_10fe44;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_10fe44;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x110028ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110210;
L_110030:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[27], cpu->regs[23]);
    if (FLAG_LE) goto L_110054;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[24] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_110030;
L_110054:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x11005cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x110074ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_110158;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    PB_LDRW(cpu->regs[23], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[24], (cpu->regs[0] + 28) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x110090ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x118accULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11014c;
L_110098:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[5] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1100b4ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x19c220ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1101bc;
L_1100bc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_10fe80;
L_1100c4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_10fe44;
L_1100e0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1100f0ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1103a0ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[5])==0) goto L_10ff98;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 96));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_EQ) goto L_110120;
L_110110:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[24] + (cpu->regs[25] << 3)), cpu->regs[5]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_10ff50;
L_110120:
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[0] = cpu->regs[0] << 1;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 96), cpu->regs[1]); PB_STR((SP + 96) + 8, cpu->regs[5]);
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[30] = PB_BASE + 0x11013cULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe5680ULL);
    PB_LDR(cpu->regs[5], (SP + 104));
    if ((cpu->regs[0])==0) goto L_110210;
    cpu->regs[24] = cpu->regs[0];
    goto L_110110;
L_11014c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_110098;
L_110158:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 2ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fed8;
L_110170:
    cpu->regs[30] = PB_BASE + 0x110174ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10fd48;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_110180:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[23] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fed8;
L_110190:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x110198ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_110260;
L_11019c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[23] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fed8;
L_1101bc:
    cpu->regs[30] = PB_BASE + 0x1101c0ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1100bc;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[23] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fed8;
L_1101f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1101f8ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_10fdd0;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_110204:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fe68;
L_110210:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x110218ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_110218:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x110224ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_10fe54;
L_110228:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x110230ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10fe14;
    cpu->regs[27] = 0ULL;
L_11023c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_110008;
L_110248:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x110250ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_10ff6c;
L_110254:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[27] = 0ULL;
    goto L_110008;
L_110260:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[21]));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_10fd98;
L_110274:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_10fed8;
}
