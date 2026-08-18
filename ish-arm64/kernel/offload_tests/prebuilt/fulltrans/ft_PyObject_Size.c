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

void ft_PyObject_Size(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[0])==0) goto L_141d74;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 104));
    if ((cpu->regs[2])==0) goto L_141d6c;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    if ((cpu->regs[2])==0) goto L_141d6c;
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_141d6c:
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x15bc60ULL); return; };
L_141d74:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x141d80ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x96bd4ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -128; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_141f74;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_141f74;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    cpu->regs[25] = (FLAG_LE) ? cpu->regs[24] : cpu->regs[23];
    FLAG_CMP(cpu->regs[25], 0ULL);
    if (FLAG_LE) goto L_141f44;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_141e30;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x141df8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_141fbc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2296));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_141ff4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    cpu->regs[26] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_142078;
L_141e2c:
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_142114;
L_141e30:
    FLAG_CMP(cpu->regs[25], 1ULL);
    if (FLAG_EQ) goto L_141f44;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_141e88;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x141e50ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_141fbc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2296));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_14205c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    cpu->regs[26] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_142088;
L_141e84:
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_1420bc;
L_141e88:
    FLAG_CMP(cpu->regs[25], 2ULL);
    if (FLAG_EQ) goto L_141f44;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2296));
    cpu->regs[26] = cpu->regs[19] + 24ULL;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[20] + 24ULL;
    cpu->regs[28] = 2ULL;
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_STR((SP + 112), cpu->regs[0]);
L_141eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + (cpu->regs[28] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[26] + (cpu->regs[28] << 3)));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_141f00;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x141ed0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_141fb8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (SP + 104));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_141f80;
    PB_LDR(cpu->regs[2], (SP + 112));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[21], cpu->regs[2]);
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14204c;
L_141efc:
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_142108;
L_141f00:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    FLAG_CMP(cpu->regs[28], cpu->regs[25]);
    if (FLAG_NE) goto L_141eb8;
L_141f0c:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_141f4c;
L_141f18:
    if (FLAG_LE) goto L_141fe4;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_141fd0;
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_NE) goto L_141f54;
L_141f2c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_141f68;
L_141f44:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_141f18;
L_141f4c:
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_NE) goto L_141f2c;
L_141f54:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_141f68:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    return;
L_141f74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_141f68;
L_141f80:
    cpu->regs[30] = PB_BASE + 0x141f84ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_141fb4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_141fb4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
L_141fa0:
    PB_STRW((SP + 124), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x141fb0ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[2], (SP + 124));
L_141fb4:
    if (!((cpu->regs[2] >> 31) & 1)) goto L_141efc;
L_141fb8:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_141fbc:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_141f68;
L_141fd0:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_142010;
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_GE) goto L_141f2c;
    goto L_141f54;
L_141fe4:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_14201c;
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_LE) goto L_141f2c;
    goto L_141f54;
L_141ff4:
    cpu->regs[30] = PB_BASE + 0x141ff8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_142028;
L_142004:
    if (((cpu->regs[26] >> 31) & 1)) goto L_141fbc;
L_142008:
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_141e30;
    goto L_142114;
L_142010:
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_LE) goto L_141f54;
    goto L_141f2c;
L_14201c:
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_GE) goto L_141f54;
    goto L_141f2c;
L_142028:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_142004;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
L_142038:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 48));
    cpu->regs[30] = PB_BASE + 0x142044ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
    if (!((cpu->regs[26] >> 31) & 1)) goto L_142008;
    goto L_141fbc;
L_14204c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_141fa0;
    goto L_141efc;
L_14205c:
    cpu->regs[30] = PB_BASE + 0x142060ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1420a8;
L_14206c:
    if (((cpu->regs[26] >> 31) & 1)) goto L_141fbc;
L_142070:
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_141e88;
    goto L_1420bc;
L_142078:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_142038;
    goto L_141e2c;
L_142088:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_141e84;
L_142094:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 48));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1420a0ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    if (!((cpu->regs[26] >> 31) & 1)) goto L_142070;
    goto L_141fbc;
L_1420a8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14206c;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    goto L_142094;
L_1420bc:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = 1ULL;
L_1420c4:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_142120;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_142128;
    cpu->regs[28] = cpu->regs[28] + 2ULL;
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[19] = cpu->regs[19] + (cpu->regs[28] << 3);
    cpu->regs[28] = cpu->regs[20] + (cpu->regs[28] << 3);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 8));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    { PB_CALL(12, cpu, tlb, PB_BASE + 0x11ed08ULL); return; };
L_142108:
    FLAG_CMP(cpu->regs[25], cpu->regs[28]);
    if (FLAG_GT) goto L_1420c4;
    goto L_141f0c;
L_142114:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = 0ULL;
    goto L_1420c4;
L_142120:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_141f2c;
L_142128:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_141f54;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 168));
    if (!((cpu->regs[22] >> 27) & 1)) goto L_1422a4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 27) & 1)) goto L_1422a4;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_EQ) goto L_14220c;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 2ULL));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[1] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_14224c;
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_NE) goto L_1421c0;
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1421f0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_1421d4;
L_1421a4:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_1421b0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1421c0:
    cpu->regs[1] = 0ULL;
L_1421c4:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(3ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1421a4;
L_1421d4:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1421f0:
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x142200ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7ab70ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    goto L_1421c4;
L_14220c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(4ULL)));
    if (FLAG_GT) goto L_142238;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_GT) goto L_1422bc;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1422bc;
    cpu->regs[21] = ((uint32_t)(cpu->regs[2] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_142240;
L_14222c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_1421b0;
L_142238:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_14222c;
L_142240:
    cpu->regs[30] = PB_BASE + 0x142244ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x22aba0ULL);
L_142244:
    cpu->regs[0] = 0ULL;
    goto L_1421b0;
L_14224c:
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    cpu->regs[2] = (FLAG_LE) ? cpu->regs[22] : cpu->regs[23];
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_1422c8;
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[0])); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_142280;
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[0] = cpu->regs[20] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x142278ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7ab70ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1422c8;
L_142280:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1422f8;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_LT) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_1422a4:
    cpu->regs[30] = PB_BASE + 0x1422a8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1915a0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 180));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1423a4;
L_1422b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_1421b0;
L_1422bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_1421b0;
L_1422c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_14234c;
    if (FLAG_GT) goto L_142334;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_142328;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_LT) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_1422f8:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_142384;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_142364;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_142328:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_142334:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_14234c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_GT) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_142364:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_142384:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_GT) ? cpu->regs[0] : cpu->regs[1];
    goto L_1421b0;
L_1423a4:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_1422b0;
    if (((cpu->regs[22] >> 28) & 1)) goto L_1423c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1423e0;
L_1423c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2768));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1423dcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x226a20ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142244;
L_1423e0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 24) & 1)) goto L_1423f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_1422b0;
L_1423f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2768));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x142414ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x226a20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1422b0;
    cpu->regs[0] = 0ULL;
    goto L_1421b0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    if ((cpu->regs[21])==0) goto L_142460;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1424dc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_1424c0;
L_142460:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_1424f4;
L_142468:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_142534;
L_142470:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_142504;
L_142478:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_142498;
    cpu->regs[2] = PB_BASE + 0x108000ULL;
    cpu->regs[2] = cpu->regs[2] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[2]);
    if (FLAG_NE) goto L_1424a8;
    cpu->regs[30] = PB_BASE + 0x142494ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x108700ULL);
    cpu->regs[0] = 0ULL;
L_142498:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1424a8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1424c0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_142514;
L_1424c8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_142460;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[21] + -8), cpu->regs[0]);
    goto L_142460;
L_1424dc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1424e8ULL; PB_CALL(20, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142498;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_142468;
L_1424f4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1424fcULL; PB_CALL(21, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_142468;
    goto L_142498;
L_142504:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14250cULL; PB_CALL(22, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_142478;
    goto L_142498;
L_142514:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_142544;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1424c8;
    goto L_142460;
L_142534:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14253cULL; PB_CALL(23, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_142470;
    goto L_142498;
L_142544:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14254cULL; PB_CALL(24, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1424c8;
    goto L_142460;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    if ((cpu->regs[22])==0) goto L_14263c;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1425dc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_1425c0;
L_1425a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1425ac;
    cpu->regs[30] = PB_BASE + 0x1425acULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x108700ULL);
L_1425ac:
    cpu->regs[0] = 0ULL;
L_1425b0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1425c0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_14260c;
L_1425c8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_1425a0;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[22] + -8), cpu->regs[0]);
    goto L_1425a0;
L_1425dc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1425e8ULL; PB_CALL(26, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1425b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1425ac;
L_1425f4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_14260c:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_14262c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1425c8;
    goto L_1425a0;
L_14262c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x142634ULL; PB_CALL(27, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1425c8;
    goto L_1425a0;
L_14263c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_1425ac;
    cpu->regs[1] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_1425f4;
    cpu->regs[30] = PB_BASE + 0x142658ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x108700ULL);
    goto L_1425ac;
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[2] = 33336ULL;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1426acULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xed3ccULL);
    if ((cpu->regs[0])==0) goto L_1427c0;
    cpu->regs[1] = 35440ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1426c4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x112290ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_142750;
    PB_LDR(cpu->regs[21], (SP + 8));
    if ((cpu->regs[21])==0) goto L_1427e0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1426d8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1427c8;
L_1426e4:
    if (((cpu->regs[20] >> 31) & 1)) goto L_1427e0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14272c;
L_1426f0:
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_142778;
L_1426f4:
    cpu->regs[0] = 0ULL;
L_1426f8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1427bc;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_14272c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1426f0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x142748ULL; PB_CALL(32, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1426f4;
    goto L_142778;
L_142750:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1426f4;
L_142758:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1426f4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x142774ULL; PB_CALL(33, cpu, tlb, cpu->regs[1]);
    goto L_1426f4;
L_142778:
    PB_LDR(cpu->regs[4], (cpu->regs[24] + 960));
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = 35712ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 16), cpu->regs[4]); PB_STR((SP + 16) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x14279cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1427f0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1426f4;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1426f4;
    cpu->regs[30] = PB_BASE + 0x1427b8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1426f4;
L_1427bc:
    cpu->regs[30] = PB_BASE + 0x1427c0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1427c0:
    cpu->regs[30] = PB_BASE + 0x1427c4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1426f4;
L_1427c8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1426e4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1427dcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1426e4;
L_1427e0:
    cpu->regs[30] = PB_BASE + 0x1427e4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1426f4;
    goto L_142758;
L_1427f0:
    cpu->regs[0] = 4294967295ULL;
    goto L_1426f8;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    if ((cpu->regs[19])==0) goto L_142834;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    cpu->regs[3] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_14286c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_142844;
L_142834:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_142844:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_142884;
L_14284c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_142834;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_14286c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_142884:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1428a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14284c;
    goto L_142834;
L_1428a4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1428acULL; PB_CALL(40, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14284c;
    goto L_142834;
    /* nop */
    /* nop */
    /* nop */
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = PB_BASE + 0x142000ULL;
    cpu->regs[0] = cpu->regs[25] + 2240ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 184));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_142a08;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    cpu->regs[19] = cpu->regs[21];
    cpu->regs[26] = cpu->regs[20];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1429c0;
L_142914:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    if ((cpu->regs[20])!=0) goto L_142a74;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 256));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 184));
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_EQ) goto L_142914;
L_14292c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 288));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 288));
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 168));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_142a10;
L_142940:
    if (!((cpu->regs[6] >> 4) & 1)) goto L_142d38;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x142954ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x142e00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142980;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_142a14;
L_142960:
    if ((cpu->regs[20])!=0) goto L_142a40;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_1429f0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14297cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x108700ULL);
L_14297c:
    cpu->regs[0] = 0ULL;
L_142980:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_142998:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[27] = cpu->regs[27] + 40ULL;
    FLAG_CMP(cpu->regs[28], cpu->regs[20]);
    if (FLAG_NE) goto L_142ca0;
L_1429a8:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 256));
    cpu->regs[0] = cpu->regs[25] + 2240ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 184));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_14292c;
L_1429c0:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    if ((cpu->regs[20])!=0) goto L_142b98;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 256));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 184));
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_EQ) goto L_1429c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 288));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 288));
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 168));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_142940;
    goto L_142a10;
L_1429f0:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1429fcULL; PB_CALL(43, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142980;
    cpu->regs[0] = 0ULL;
    goto L_142980;
L_142a08:
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 168));
    cpu->regs[19] = cpu->regs[21];
L_142a10:
    if (((cpu->regs[6] >> 9) & 1)) goto L_142960;
L_142a14:
    if ((cpu->regs[20])==0) goto L_14297c;
L_142a18:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_142a40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_142a18;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21];
    if (FLAG_NE) goto L_142a64;
    cpu->regs[30] = PB_BASE + 0x142a60ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x108700ULL);
    goto L_142a18;
L_142a64:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142a6cULL; PB_CALL(45, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_142a18;
    goto L_142980;
L_142a74:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 23) & 1)) goto L_142d0c;
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 32));
    cpu->regs[27] = cpu->regs[19] + cpu->regs[27];
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_142b7c;
L_142a94:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142ab0;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142ab0;
    cpu->regs[30] = PB_BASE + 0x142ab0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x108700ULL);
L_142ab0:
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_142b7c;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142ad4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142ad4;
    cpu->regs[30] = PB_BASE + 0x142ad4ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x108700ULL);
L_142ad4:
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_142b7c;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 88));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142af8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142af8;
    cpu->regs[30] = PB_BASE + 0x142af8ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x108700ULL);
L_142af8:
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_142b7c;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 128));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142b1c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 136));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142b1c;
    cpu->regs[30] = PB_BASE + 0x142b1cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x108700ULL);
L_142b1c:
    FLAG_CMP(cpu->regs[20], 4ULL);
    if (FLAG_EQ) goto L_142b7c;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 168));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142b40;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 176));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142b40;
    cpu->regs[30] = PB_BASE + 0x142b40ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x108700ULL);
L_142b40:
    cpu->regs[27] = cpu->regs[27] + 200ULL;
    FLAG_CMP(cpu->regs[20], 5ULL);
    if (FLAG_EQ) goto L_142b7c;
    cpu->regs[28] = 5ULL;
L_142b50:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142b6c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142b6c;
    cpu->regs[30] = PB_BASE + 0x142b6cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x108700ULL);
L_142b6c:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[27] = cpu->regs[27] + 40ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[28]);
    if (FLAG_NE) goto L_142b50;
L_142b7c:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 256));
    cpu->regs[0] = cpu->regs[25] + 2240ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 184));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_142914;
    goto L_14292c;
L_142b98:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 23) & 1)) goto L_142ce0;
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 32));
    cpu->regs[27] = cpu->regs[19] + cpu->regs[27];
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_1429a8;
L_142bb8:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142bdc;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142bdc;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142bd8ULL; PB_CALL(52, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142cd8;
L_142bdc:
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_1429a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142c08;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142c08;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142c04ULL; PB_CALL(53, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142cd8;
L_142c08:
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_1429a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 88));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142c34;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142c34;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142c30ULL; PB_CALL(54, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142cd8;
L_142c34:
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_1429a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 128));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142c60;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 136));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142c60;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142c5cULL; PB_CALL(55, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142cd8;
L_142c60:
    FLAG_CMP(cpu->regs[20], 4ULL);
    if (FLAG_EQ) goto L_1429a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + 168));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142c8c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 176));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142c8c;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142c88ULL; PB_CALL(56, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142cd8;
L_142c8c:
    cpu->regs[27] = cpu->regs[27] + 200ULL;
    FLAG_CMP(cpu->regs[20], 5ULL);
    if (FLAG_EQ) goto L_1429a8;
    cpu->regs[28] = 5ULL;
    /* nop */
L_142ca0:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[1] = cpu->regs[24];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_142998;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_142998;
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x142cc4ULL; PB_CALL(57, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142cd8;
    cpu->regs[27] = cpu->regs[27] + 40ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[28]);
    if (FLAG_NE) goto L_142ca0;
    goto L_1429a8;
L_142cd8:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_142980;
L_142ce0:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3408ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x142cfcULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x11f220ULL);
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_1429a8;
    cpu->regs[27] = 0ULL;
    goto L_142bb8;
L_142d0c:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3408ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x142d28ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x11f220ULL);
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_142b7c;
    cpu->regs[27] = 0ULL;
    goto L_142a94;
L_142d38:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x142d40ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x18fb28ULL);
    if ((cpu->regs[0])==0) goto L_142a10;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_142a10;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x142d54ULL; PB_CALL(61, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142980;
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 168));
    if (((cpu->regs[6] >> 9) & 1)) goto L_142960;
    goto L_142a14;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x142d8cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xed18cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_142dec;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x142db0ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xed4ccULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_142de8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_142de0;
L_142dc8:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_142de0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x142de8ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_142de8:
    cpu->regs[19] = cpu->regs[20];
L_142dec:
    cpu->regs[20] = cpu->regs[19];
    goto L_142dc8;
    /* nop */
    /* nop */
    /* nop */
}
