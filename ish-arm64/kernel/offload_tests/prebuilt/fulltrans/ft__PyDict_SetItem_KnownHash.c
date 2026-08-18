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

void ft__PyDict_SetItem_KnownHash(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_202e74;
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x202df4ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 32));
    cpu->regs[5] = PB_BASE + 0x450000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[5] = cpu->regs[5] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[8] = ((uint32_t)(cpu->regs[1] + 1ULL));
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_EQ) goto L_202e4c;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_202e44;
L_202e24:
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_202e3c;
L_202e30:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[1] = cpu->regs[6];
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xdfd00ULL); return; };
L_202e3c:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[1]);
    goto L_202e30;
L_202e44:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[8]);
    goto L_202e24;
L_202e4c:
    if ((((uint32_t)(cpu->regs[8])))!=0) goto L_202e6c;
L_202e50:
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_202e60;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[1]);
L_202e60:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[1] = cpu->regs[6];
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xde0c0ULL); return; };
L_202e6c:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[8]);
    goto L_202e50;
L_202e74:
    cpu->regs[1] = 1898ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x202e84ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_202ef4;
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x202ec8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_202f14;
    PB_STRW((cpu->regs[0] + 32), cpu->regs[22]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[23]);
    cpu->regs[1] = 13ULL;
    PB_STRW((cpu->regs[0] + 40), cpu->regs[20]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_202ee8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_202ef4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 1192ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x202f0cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_202ee8;
L_202f14:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_202ee8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_GT) goto L_202f38;
L_202f2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
L_202f38:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[1] << 3);
    cpu->regs[0] = cpu->regs[0] - 8ULL;
    goto L_202f58;
L_202f48:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR(cpu->regs[2], cpu->regs[3]); cpu->regs[2] += 8;
    PB_STR(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += -8;
L_202f58:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LO) goto L_202f48;
    goto L_202f2c;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 9223372036854775807ULL;
    PB_STR((SP + 8), cpu->regs[3]); PB_STR((SP + 8) + 8, 0ULL);
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_HI) goto L_203038;
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_203098;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[21] = 0ULL;
L_202fc4:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_202fcc:
    cpu->regs[20] = cpu->regs[20] + 24ULL;
L_202fd0:
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_GE) goto L_203078;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[21] << 3)));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x202fe8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_203028;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x202ff8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe1fc0ULL);
L_202ff8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_203034;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_203028:
    if (FLAG_NE) goto L_203090;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_202fd0;
L_203034:
    cpu->regs[30] = PB_BASE + 0x203038ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c170ULL);
L_203038:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x203050ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_203090;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_2030c4;
L_203060:
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[21], (SP + 8) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if (((cpu->regs[21] >> 63) & 1)) goto L_2030d8;
L_20306c:
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
    if (!((cpu->regs[1] >> 63) & 1)) goto L_202fc4;
    goto L_202fcc;
L_203078:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 1240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x203090ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_203090:
    cpu->regs[0] = 0ULL;
    goto L_202ff8;
L_203098:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x2030a4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x22bab0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_203090;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_203060;
L_2030b0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x2030bcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x22bab0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_203060;
    goto L_203090;
L_2030c4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x2030d0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x22bab0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2030b0;
    goto L_203090;
L_2030d8:
    cpu->regs[21] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[21] = cpu->regs[21] & ~(((uint64_t)((int64_t)cpu->regs[21] >> 63)));
    goto L_20306c;
    SP = SP - 128ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    if ((cpu->regs[2])==0) goto L_20332c;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
L_203120:
    cpu->regs[4] = SP + 32ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[7] = 1ULL;
    cpu->regs[21] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[6] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[3] + 24ULL;
    cpu->regs[5] = cpu->regs[7];
    cpu->regs[4] = cpu->regs[4] + 88ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x203150ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2032d4;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x203164ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_2032d0;
    FLAG_CMP(cpu->regs[21], 2ULL);
    if (FLAG_EQ) goto L_2032a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_203300;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x20318cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2032d0;
    cpu->regs[30] = PB_BASE + 0x203198ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_2032dc;
L_2031a4:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2031b4ULL; PB_CALL(19, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2032d0;
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 2664ULL;
    cpu->regs[30] = PB_BASE + 0x2031c8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2032d0;
    cpu->regs[30] = PB_BASE + 0x2031d4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1946e4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2032b8;
    cpu->regs[0] = 1024ULL;
    cpu->regs[30] = PB_BASE + 0x2031e4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2032b0;
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    PB_STR((cpu->regs[19] + 8), cpu->regs[1]); PB_STR((cpu->regs[19] + 8) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if ((cpu->regs[21])==0) goto L_203224;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20320cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20321cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1de500ULL);
    PB_STR((cpu->regs[19] + 2752), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2032b0;
L_203224:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[1] = 2ULL;
    PB_STRW((cpu->regs[19] + 2744), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_20323c;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_20323c:
    PB_STR((cpu->regs[19] + 2800), cpu->regs[23]);
    PB_STR((cpu->regs[20] + 16), cpu->regs[19]);
    PB_STR((cpu->regs[19] + 2336), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_203258;
    cpu->regs[19] = cpu->regs[19] + (4ULL << 12);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 884), cpu->regs[0]);
L_203258:
    PB_STRW((cpu->regs[20] + 24), 0ULL);
    PB_STR((cpu->regs[20] + 32), 0ULL);
    PB_STR((cpu->regs[20] + 40), 0ULL); PB_STR((cpu->regs[20] + 40) + 8, 0ULL);
    PB_STR((cpu->regs[20] + 56), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
L_20326c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2032a8;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_2032a0:
    cpu->regs[21] = 0ULL;
    goto L_2031a4;
L_2032a8:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x2032b0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2032b0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2032b8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1a8480ULL);
L_2032b8:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    PB_STR((cpu->regs[20] + 16), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2032d0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_203334;
L_2032d0:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
L_2032d4:
    cpu->regs[20] = 0ULL;
    goto L_20326c;
L_2032dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2032f8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_20326c;
L_203300:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 1272ULL;
    cpu->regs[30] = PB_BASE + 0x203324ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_20326c;
L_20332c:
    cpu->regs[0] = 0ULL;
    goto L_203120;
L_203334:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x203340ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_20326c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x203364ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_20336c;
    PB_STR((cpu->regs[0] + 0), cpu->regs[19]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[20]);
L_20336c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
}
