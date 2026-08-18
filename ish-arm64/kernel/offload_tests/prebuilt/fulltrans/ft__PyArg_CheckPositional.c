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

void ft__PyArg_CheckPositional(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[7] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[29] = SP;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LT) goto L_116fd0;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    if (FLAG_GT) goto L_11702c;
    cpu->regs[0] = 1ULL;
L_116fc8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_116fd0:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2736));
    FLAG_CMP(cpu->regs[7], cpu->regs[3]);
    PB_LDR(cpu->regs[9], (cpu->regs[2] + 0));
    if ((cpu->regs[0])==0) goto L_117084;
    cpu->regs[5] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = PB_BASE + 0x287000ULL;
    cpu->regs[5] = cpu->regs[5] + 240ULL;
    cpu->regs[3] = cpu->regs[3] + 1008ULL;
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[5];
    cpu->regs[8] = PB_BASE + 0x292000ULL;
    FLAG_CMP(cpu->regs[7], 1ULL);
    cpu->regs[8] = cpu->regs[8] + 1000ULL;
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = (FLAG_NE) ? cpu->regs[8] : cpu->regs[5];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 1040ULL;
    cpu->regs[30] = PB_BASE + 0x117024ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_116fc8;
L_11702c:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2736));
    FLAG_CMP(cpu->regs[7], cpu->regs[3]);
    PB_LDR(cpu->regs[8], (cpu->regs[2] + 0));
    if ((cpu->regs[0])==0) goto L_1170c8;
    cpu->regs[5] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = PB_BASE + 0x287000ULL;
    cpu->regs[5] = cpu->regs[5] + 240ULL;
    cpu->regs[3] = cpu->regs[3] + 1024ULL;
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[5];
    cpu->regs[7] = PB_BASE + 0x292000ULL;
    FLAG_CMP(cpu->regs[4], 1ULL);
    cpu->regs[7] = cpu->regs[7] + 1000ULL;
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[5] = (FLAG_NE) ? cpu->regs[7] : cpu->regs[5];
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 1040ULL;
    cpu->regs[30] = PB_BASE + 0x11707cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_116fc8;
L_117084:
    cpu->regs[4] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[4] = cpu->regs[4] + 240ULL;
    cpu->regs[2] = cpu->regs[2] + 1008ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[4];
    cpu->regs[6] = PB_BASE + 0x292000ULL;
    FLAG_CMP(cpu->regs[7], 1ULL);
    cpu->regs[6] = cpu->regs[6] + 1000ULL;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[3] = cpu->regs[7];
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[6] : cpu->regs[4];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x1170c0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_116fc8;
L_1170c8:
    cpu->regs[6] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[6] = cpu->regs[6] + 240ULL;
    cpu->regs[2] = cpu->regs[2] + 1024ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[6];
    cpu->regs[7] = PB_BASE + 0x292000ULL;
    FLAG_CMP(cpu->regs[3], 1ULL);
    cpu->regs[7] = cpu->regs[7] + 1000ULL;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[7] : cpu->regs[6];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x117100ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_116fc8;
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_117200;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_117170;
L_11712c:
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 40));
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 8));
    if ((cpu->regs[4])==0) goto L_117230;
    cpu->regs[3] = PB_BASE + 0x14c000ULL;
    cpu->regs[3] = cpu->regs[3] + 3496ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[3]);
    if (FLAG_NE) goto L_11715c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1171f8;
L_117154:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_11715c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 32));
    cpu->regs[16] = cpu->regs[4];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_117170:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 344));
    if ((cpu->regs[4])==0) goto L_117218;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 16));
    FLAG_CMP(cpu->regs[5], 0ULL);
    if (FLAG_LE) goto L_1171e0;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[6]);
    if (FLAG_EQ) goto L_11712c;
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_1171e0;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 32));
    FLAG_CMP(cpu->regs[6], cpu->regs[1]);
    if (FLAG_EQ) goto L_11712c;
    FLAG_CMP(cpu->regs[5], 2ULL);
    if (FLAG_EQ) goto L_1171e0;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 40));
    FLAG_CMP(cpu->regs[6], cpu->regs[1]);
    if (FLAG_EQ) goto L_11712c;
    FLAG_CMP(cpu->regs[5], 3ULL);
    if (FLAG_EQ) goto L_1171e0;
    cpu->regs[4] = cpu->regs[4] + 24ULL;
    cpu->regs[6] = 3ULL;
L_1171c8:
    PB_LDR(cpu->regs[7], (cpu->regs[4] + (cpu->regs[6] << 3)));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[7]);
    if (FLAG_EQ) goto L_11712c;
    FLAG_CMP(cpu->regs[5], cpu->regs[6]);
    if (FLAG_NE) goto L_1171c8;
L_1171e0:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1171ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1985a8ULL);
    cpu->regs[0] = 0ULL;
L_1171f0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1171f8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_117154;
L_117200:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_117210;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
L_117210:
    cpu->regs[0] = cpu->regs[3];
    return;
L_117218:
    cpu->regs[4] = cpu->regs[0];
L_11721c:
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 256));
    if ((cpu->regs[4])==0) goto L_117274;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_EQ) goto L_11712c;
    goto L_11721c;
L_117230:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_117254;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    FLAG_CMP((cpu->regs[3]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_117254:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 24));
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[1] = cpu->regs[1] + 1240ULL;
    cpu->regs[30] = PB_BASE + 0x11726cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1171f0;
L_117274:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3488));
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_EQ) goto L_11712c;
    goto L_1171e0;
L_117288:
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_117824;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117834;
L_1172bc:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_117900;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[1] = 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[24] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x1172ecULL; PB_CALL(7, cpu, tlb, cpu->regs[2]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117930;
    cpu->regs[23] = cpu->regs[20];
L_1172f8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117940;
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[2] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1178e8;
L_117318:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1175ec;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(57ULL)));
    if (FLAG_EQ) goto L_1173bc;
L_117338:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1178c8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1175c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(650ULL)));
    if (FLAG_EQ) goto L_11745c;
L_117360:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1178c0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
L_11737c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 136));
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 168));
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x117390ULL; PB_CALL(8, cpu, tlb, cpu->regs[2]);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_11739c:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1173a4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_1173bc:
    cpu->regs[0] = cpu->regs[21];
L_1173c0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[1] = 650ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1173d4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_117610;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1173e4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x10c56cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1178dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 651ULL;
    cpu->regs[30] = PB_BASE + 0x1173f8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1178dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117404ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1178cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117414ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1a3b40ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1178cc;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x117430ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1a4140ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1296ULL;
    cpu->regs[1] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x117448ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1a6840ULL);
    if ((cpu->regs[0])==0) goto L_11795c;
L_11744c:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_1174d0;
L_11745c:
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
L_117464:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117474ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x10c56cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117840;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 651ULL;
    cpu->regs[30] = PB_BASE + 0x117488ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_117840;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117494ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1178cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1174a4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1a3b40ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1178cc;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1174c0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1a4140ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1179a4;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
L_1174d0:
    cpu->regs[26] = 1ULL;
    cpu->regs[27] = cpu->regs[26];
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[28] = 6000ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_1174e8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[25] = cpu->regs[26];
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_EQ) goto L_117998;
L_117500:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117990;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    cpu->regs[0] = cpu->regs[21];
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_117650;
L_117518:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(57ULL)));
    if (FLAG_EQ) goto L_117768;
L_11752c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117990;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[0] = cpu->regs[21];
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_11763c;
L_117548:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(650ULL)));
    if (FLAG_EQ) goto L_117664;
L_11755c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117878;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((cpu->regs[26])==0) goto L_117630;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_117580:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_11781c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x117594ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11773c;
L_11759c:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_GT) goto L_117618;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1175b0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_11739c;
L_1175c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1175c8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1176fc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(650ULL)));
    if (FLAG_NE) goto L_117360;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    goto L_117464;
L_1175ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1175f4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1176ec;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(57ULL)));
    if (FLAG_EQ) goto L_1173c0;
L_117610:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    goto L_117338;
L_117618:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_11759c;
L_117630:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_11737c;
L_11763c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117644ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_117724;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_117548;
L_117650:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117658ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_117730;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_117518;
L_117664:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117674ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x10c56cULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_11755c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 651ULL;
    cpu->regs[30] = PB_BASE + 0x117688ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_11755c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117694ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117990;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1176a4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1a3b40ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117990;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1176c0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1a4140ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])==0) goto L_117864;
L_1176d0:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    FLAG_CMP(cpu->regs[27], cpu->regs[26]);
    if (FLAG_EQ) goto L_117708;
L_1176dc:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[22] + (cpu->regs[26] << 3)), cpu->regs[21]);
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    goto L_1174e8;
L_1176ec:
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_117338;
L_1176fc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_117360;
L_117708:
    cpu->regs[27] = cpu->regs[27] << 1;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[27] << 3;
    cpu->regs[30] = PB_BASE + 0x117718ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_1179b4;
    cpu->regs[22] = cpu->regs[0];
    goto L_1176dc;
L_117724:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_11755c;
L_117730:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_11752c;
L_11773c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x117744ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x117750ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_11775c:
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_11739c;
L_117768:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[1] = 650ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11777cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_11752c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117788ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x10c56cULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_11752c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 651ULL;
    cpu->regs[30] = PB_BASE + 0x11779cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_11752c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1177a8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x10f50cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117990;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1177b8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1a3b40ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117990;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[3] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1177d4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1a4140ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1296ULL;
    cpu->regs[1] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x1177ecULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1a6840ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_117890;
    cpu->regs[30] = PB_BASE + 0x1177f8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1179dc;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_117800:
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_117810:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((cpu->regs[25])!=0) goto L_117580;
L_11781c:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_11737c;
L_117824:
    cpu->regs[30] = PB_BASE + 0x117828ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1172bc;
L_117834:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_1173a4;
L_117840:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1178bc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_11737c;
L_117864:
    cpu->regs[30] = PB_BASE + 0x117868ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_11789c;
L_11786c:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_117810;
L_117878:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117990;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117888ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xcfcfcULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1178ac;
L_117890:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_1176d0;
L_11789c:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1178a0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_117810;
L_1178ac:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_117810;
L_1178bc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_1178c0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_117948;
L_1178c8:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
L_1178cc:
    cpu->regs[25] = 0ULL;
L_1178d0:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_117810;
L_1178dc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    goto L_117338;
L_1178e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1178f0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_117318;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    goto L_1178cc;
L_117900:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117908ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11793c;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[1] = 8ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[24] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x117928ULL; PB_CALL(48, cpu, tlb, cpu->regs[2]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1172f8;
L_117930:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x11793cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x22d780ULL);
L_11793c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_117940:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_11775c;
L_117948:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117950ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xcfcfcULL);
    if ((cpu->regs[0])==0) goto L_11797c;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    goto L_11744c;
L_11795c:
    cpu->regs[30] = PB_BASE + 0x117960ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_117988;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
L_117968:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
L_117970:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    goto L_11737c;
L_11797c:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_117970;
L_117988:
    cpu->regs[25] = 0ULL;
    goto L_117800;
L_117990:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1178d0;
L_117998:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1179a0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_117500;
L_1179a4:
    cpu->regs[30] = PB_BASE + 0x1179a8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_117968;
    cpu->regs[25] = 0ULL;
    goto L_1178a0;
L_1179b4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1179bcULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1179c8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_11775c;
L_1179dc:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    goto L_11786c;
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 144));
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[4]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_117c88;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117c98;
L_117a18:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_117ae4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])==0) goto L_117a54;
L_117a38:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1172ULL)));
    if (FLAG_EQ) goto L_117aa4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_117a38;
L_117a4c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117ca4;
L_117a54:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117a5cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x19a100ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117ad0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x117a70ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117ad0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 8ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x117a88ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_117ad0;
L_117a8c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1172ULL;
    cpu->regs[30] = PB_BASE + 0x117aa0ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1082e0ULL);
    goto L_117ab0;
L_117aa4:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_117ab0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_117abc:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_117ad0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117b08;
    cpu->regs[20] = 0ULL;
    goto L_117a8c;
L_117ae4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117aecULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_117cb8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])!=0) goto L_117a38;
    goto L_117a4c;
L_117b08:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117cc8;
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_117cd8;
L_117b28:
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    cpu->regs[20] = cpu->regs[22];
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_117d00;
L_117b48:
    cpu->regs[0] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_117d1c;
L_117b5c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117b64ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x179b20ULL);
    if ((cpu->regs[0])==0) goto L_117b84;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x117b74ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_117b84;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117b80ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1a4f80ULL);
    if ((cpu->regs[0])!=0) goto L_117f5c;
L_117b84:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_117b90:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117f50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117ba4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1a4f80ULL);
    if ((cpu->regs[0])==0) goto L_117f48;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_117bb4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117bc4ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117fb4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_117fc0;
L_117be4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117fcc;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x117bf8ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xd0268ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117fe0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_117ff8;
L_117c18:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_118004;
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x117c2cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_118014;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[27] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_118034;
    cpu->regs[23] = 0ULL;
    cpu->regs[28] = 1ULL;
L_117c4c:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117c58ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])==0) goto L_1180c0;
    cpu->regs[30] = PB_BASE + 0x117c68ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xd0268ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1180c0;
    FLAG_CMP(cpu->regs[28], cpu->regs[23]);
    if (FLAG_EQ) goto L_1180fc;
L_117c78:
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[23] << 3)), cpu->regs[2]);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_117c4c;
L_117c88:
    cpu->regs[30] = PB_BASE + 0x117c8cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_117a18;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
L_117c98:
    cpu->regs[0] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[20] = 0ULL;
    goto L_117abc;
L_117ca4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_117abc;
L_117cb8:
    cpu->regs[0] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_117ab0;
L_117cc8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[20] = 0ULL;
    goto L_117abc;
L_117cd8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117ce0ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_117b28;
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
L_117cf0:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_117a8c;
L_117d00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117d08ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117d38;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    goto L_117b48;
L_117d1c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117d24ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_117b5c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_117b90;
L_117d38:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
L_117d40:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117e4c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117d50ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117e58;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x117d64ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x117288ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117e60;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x117d78ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_117e60;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_117fa8;
L_117d94:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_118218;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117da8ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x19a100ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_118210;
L_117db0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_118250;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_117dc4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117e4c;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x117dd8ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117e6c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x117decULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117e6c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117dfcULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_117e6c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117e08ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_117e6c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 28),&_a,4); tlb_read(tlb,(cpu->regs[20] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1576ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[23] + 32),&_a,4); tlb_read(tlb,(cpu->regs[23] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
L_117e2c:
    cpu->regs[30] = PB_BASE + 0x117e30ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x280d00ULL);
L_117e30:
    cpu->regs[30] = PB_BASE + 0x117e34ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_1180b0;
L_117e40:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_117cf0;
L_117e4c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_117cf0;
L_117e58:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_117dc4;
L_117e60:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_117dc4;
L_117e6c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117f9c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1181f0;
L_117e90:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117e9cULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x19a100ULL);
    if ((cpu->regs[0])==0) goto L_117eb0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x117eacULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_117eb4;
L_117eb0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_117eb4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1182c0;
L_117ec8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_117f98;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117ed8ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x19a100ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117f74;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117ee8ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_117f74;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16));
    if ((cpu->regs[3])==0) goto L_117e30;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_LE) goto L_117e30;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[4], (cpu->regs[0] + 0) + 8);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2416));
    PB_LDR(cpu->regs[20], (cpu->regs[3] + (cpu->regs[1] << 3)));
    cpu->regs[0] = cpu->regs[4] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[22], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + -8));
    cpu->regs[30] = PB_BASE + 0x117f24ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x85f80ULL);
    cpu->regs[4] = cpu->regs[0];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 32),&_a,4); tlb_read(tlb,(cpu->regs[20] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[1] = cpu->regs[22];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[4] + 40),&_a,4); tlb_read(tlb,(cpu->regs[4] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    cpu->regs[6] = cpu->regs[6] + 1528ULL;
    cpu->regs[30] = PB_BASE + 0x117f44ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x280d00ULL);
    goto L_117e30;
L_117f48:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
L_117f50:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_117d40;
L_117f5c:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_117bb4;
L_117f74:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_117f98;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117f88ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x19a100ULL);
    if ((cpu->regs[0])!=0) goto L_118288;
L_117f8c:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_11830c;
L_117f98:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_117f9c:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_117cf0;
L_117fa8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117fb0ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_117d94;
L_117fb4:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_117d40;
L_117fc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x117fc8ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_117be4;
L_117fcc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_117d40;
L_117fe0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
L_117fe4:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_117d40;
L_117ff8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x118000ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_117c18;
L_118004:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    goto L_117fe4;
L_118014:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x118020ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    goto L_117fe4;
L_118034:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_117fe4;
L_118048:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + (cpu->regs[1] << 3)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[3] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] | cpu->regs[3]));
L_118060:
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LT) goto L_118048;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[0] + 1360ULL;
    cpu->regs[3] = cpu->regs[3] + 1416ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x118098ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_118384;
    cpu->regs[30] = PB_BASE + 0x1180acULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_117e40;
L_1180b0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_117cf0;
L_1180c0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1180d0ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_118118;
L_1180d8:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[27]));
    FLAG_CMP(cpu->regs[23], cpu->regs[27]);
    if (FLAG_LE) goto L_118144;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[27] = ((uint32_t)(cpu->regs[27] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1180d8;
L_1180fc:
    cpu->regs[28] = cpu->regs[28] << 1;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[28] << 3;
    cpu->regs[30] = PB_BASE + 0x118110ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xe5680ULL);
    PB_LDR(cpu->regs[2], (SP + 104));
    if ((cpu->regs[0])!=0) goto L_1181e8;
L_118118:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x118120ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x11812cULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_117fe4;
L_118144:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x11814cULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x118168ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_1181bc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[5] = 18446744073709551611ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 20),&_a,4); tlb_read(tlb,(cpu->regs[24] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[4] = cpu->regs[5];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[6] = cpu->regs[6] + 1464ULL;
    cpu->regs[30] = PB_BASE + 0x1181a0ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1181a4ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_1181d0;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_117e40;
L_1181bc:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_117d40;
L_1181d0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_117cf0;
L_1181e8:
    cpu->regs[20] = cpu->regs[0];
    goto L_117c78;
L_1181f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1181f8ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_117e90;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_117ec8;
L_118210:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_11822c;
L_118218:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_117dc4;
L_11822c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x118234ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_118244;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x118240ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])!=0) goto L_118304;
L_118244:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_117db0;
L_118250:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[23];
L_11825c:
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x118264ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x85f70ULL);
    cpu->regs[30] = PB_BASE + 0x118268ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x85f80ULL);
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[22];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 32),&_a,4); tlb_read(tlb,(cpu->regs[20] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[4] + 40),&_a,4); tlb_read(tlb,(cpu->regs[4] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1528ULL;
    goto L_117e2c;
L_118288:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x118294ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_117f8c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1182a0ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_117f8c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1182b0ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_117f8c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    goto L_11825c;
L_1182c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1182c8ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1182fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x1182dcULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1182fc;
    cpu->regs[1] = PB_BASE + 0x94000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2572ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1182f8ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_118358;
L_1182fc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_117ec8;
L_118304:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_117db0;
L_11830c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x118314ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x19a100ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_118350;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x118328ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_118350;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x118334ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x19a100ULL);
    if ((cpu->regs[0])==0) goto L_118350;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    if ((cpu->regs[0])==0) goto L_11837c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
L_118344:
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[1] = 0ULL;
    goto L_118060;
L_118350:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    goto L_117e40;
L_118358:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 32),&_a,4); tlb_read(tlb,(cpu->regs[20] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1640ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[23] + 28),&_a,4); tlb_read(tlb,(cpu->regs[23] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_117e2c;
L_11837c:
    cpu->regs[2] = 0ULL;
    goto L_118344;
L_118384:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_117a8c;
}
