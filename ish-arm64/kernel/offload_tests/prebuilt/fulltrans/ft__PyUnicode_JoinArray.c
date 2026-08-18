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

void ft__PyUnicode_JoinArray(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -128; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    if ((cpu->regs[2])==0) goto L_12f128;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_12f0b4;
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12f418;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_12f464;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 32));
    PB_LDR(cpu->regs[27], (cpu->regs[28] + 16));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_12f14c;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[1] = 127ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_12f168;
L_12edc0:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_12f044;
L_12edc8:
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[19] = 1ULL;
    cpu->regs[7] = 9223372036854775807ULL;
    cpu->regs[8] = 127ULL;
    goto L_12ee34;
L_12ede4:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[8];
    if ((cpu->regs[4])==0) goto L_12ee70;
L_12edf0:
    cpu->regs[5] = cpu->regs[5] + cpu->regs[27];
    cpu->regs[6] = cpu->regs[7] - cpu->regs[0];
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_LO) goto L_12ee7c;
L_12ee00:
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[5];
    cpu->regs[5] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[5]))) & (((uint32_t)(cpu->regs[19]))), 0);
    if (FLAG_EQ) goto L_12eebc;
    PB_LDRW(cpu->regs[5], (cpu->regs[2] + 32));
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 32));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] ^ cpu->regs[2]));
    FLAG_CMP((((uint32_t)(cpu->regs[5]))) & (((uint32_t)(28ULL))), 0);
    cpu->regs[19] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(cpu->regs[22], cpu->regs[4]);
    if (FLAG_LE) goto L_12eec8;
L_12ee34:
    cpu->regs[2] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[26] + (cpu->regs[4] << 3)));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 168));
    if (!((cpu->regs[6] >> 28) & 1)) goto L_12f3c0;
    PB_LDR(cpu->regs[6], (cpu->regs[3] + 32));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 16));
    if (((cpu->regs[6] >> 6) & 1)) goto L_12ede4;
    cpu->regs[6] = ((uint32_t)(((cpu->regs[6] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_12f170;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_12f100;
    cpu->regs[1] = 1114111ULL;
    if ((cpu->regs[4])!=0) goto L_12edf0;
L_12ee70:
    cpu->regs[6] = cpu->regs[7] - cpu->regs[0];
    FLAG_CMP(cpu->regs[5], cpu->regs[6]);
    if (FLAG_LS) goto L_12ee00;
L_12ee7c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 1440ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12ee94ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_12ee94:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x12ee9cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12eea8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_12efac;
L_12eebc:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[4]);
    if (FLAG_GT) goto L_12ee34;
L_12eec8:
    cpu->regs[30] = PB_BASE + 0x12eeccULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12ee94;
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_12f1b0;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 32));
    if (!((cpu->regs[24] >> 5) & 1)) goto L_12f448;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[24] >> 2) & 0x7ULL)));
    PB_STRW((SP + 108), cpu->regs[0]);
    if (!((cpu->regs[24] >> 6) & 1)) goto L_12f178;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    if ((cpu->regs[27])!=0) goto L_12f070;
L_12eef4:
    PB_STR((SP + 96), 0ULL);
L_12eef8:
    FLAG_CMP(cpu->regs[27], 0ULL);
    PB_LDRW(cpu->regs[24], (SP + 108));
    cpu->regs[25] = (FLAG_NE) ? 1 : 0;
    cpu->regs[21] = 0ULL;
    goto L_12ef24;
L_12ef0c:
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STRB((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
L_12ef18:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_LE) goto L_12ef84;
L_12ef24:
    FLAG_CMP(cpu->regs[21], 0ULL);
    PB_LDR(cpu->regs[19], (cpu->regs[26] + (cpu->regs[21] << 3)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[25], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12efe8;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[20] = cpu->regs[24];
    if ((cpu->regs[3])==0) goto L_12ef18;
L_12ef40:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_12f184;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_12efbc;
    cpu->regs[1] = cpu->regs[19] + 40ULL;
    cpu->regs[2] = cpu->regs[20] * cpu->regs[3];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_12efcc;
L_12ef5c:
    cpu->regs[19] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_HI) goto L_12f0fc;
L_12ef68:
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_12ef0c;
    cpu->regs[30] = PB_BASE + 0x12ef74ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_GT) goto L_12ef24;
L_12ef84:
    if ((cpu->regs[28])==0) goto L_12ef9c;
L_12ef88:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ef9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12f090;
L_12ef9c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_12efac:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    return;
L_12efbc:
    cpu->regs[1] = cpu->regs[19] + 56ULL;
L_12efc0:
    cpu->regs[2] = cpu->regs[20] * cpu->regs[3];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_12ef5c;
L_12efcc:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LS) goto L_12efe0;
    cpu->regs[3] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LO) goto L_12f0fc;
L_12efe0:
    cpu->regs[19] = cpu->regs[0] + cpu->regs[2];
    goto L_12ef68;
L_12efe8:
    PB_LDRW(cpu->regs[20], (SP + 108));
    cpu->regs[2] = cpu->regs[20] * cpu->regs[27];
L_12eff0:
    PB_LDR(cpu->regs[1], (SP + 96));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HI) goto L_12f0f0;
    if (FLAG_HS) goto L_12f00c;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_12f0fc;
L_12f00c:
    cpu->regs[6] = cpu->regs[0] + cpu->regs[2];
L_12f010:
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_12f114;
    PB_LDR(cpu->regs[1], (SP + 96));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STRB((cpu->regs[0] + 0), cpu->regs[1]);
L_12f024:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[6];
    if ((cpu->regs[3])!=0) goto L_12ef40;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_GE) goto L_12ef84;
    PB_LDR(cpu->regs[19], (cpu->regs[26] + (cpu->regs[21] << 3)));
    goto L_12eff0;
L_12f044:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12f04cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12ee94;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 32));
    if (!((cpu->regs[24] >> 5) & 1)) goto L_12f448;
    if (!((cpu->regs[24] >> 6) & 1)) goto L_12f18c;
    if ((cpu->regs[27])==0) goto L_12ef84;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[24] >> 2) & 0x7ULL)));
    PB_STRW((SP + 108), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[23] + 40ULL;
L_12f070:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_12f404;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_12f3ec;
    cpu->regs[1] = cpu->regs[28] + 40ULL;
    PB_STR((SP + 96), cpu->regs[1]);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_12eef8;
    goto L_12ef88;
L_12f090:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 8));
    cpu->regs[0] = cpu->regs[28];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x12f0a0ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_12efac;
L_12f0b4:
    PB_LDR(cpu->regs[23], (cpu->regs[1] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_12f1a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12ef9c;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_12efac;
L_12f0f0:
    cpu->regs[6] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[6]);
    if (FLAG_HS) goto L_12f010;
L_12f0fc:
    __builtin_trap();
L_12f100:
    cpu->regs[6] = 65535ULL;
L_12f104:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[6];
    if ((cpu->regs[4])!=0) goto L_12edf0;
    goto L_12ee70;
L_12f114:
    PB_LDR(cpu->regs[1], (SP + 96));
    PB_STR((SP + 112), cpu->regs[2]); PB_STR((SP + 112) + 8, cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x12f120ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[2], (SP + 112)); PB_LDR(cpu->regs[6], (SP + 112) + 8);
    goto L_12f024;
L_12f128:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = cpu->regs[23] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 8080));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_12f3e4;
L_12f140:
    cpu->regs[1] = 24464ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[1];
    goto L_12efac;
L_12f14c:
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    cpu->regs[1] = 255ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12f434;
L_12f15c:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12edc0;
L_12f168:
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
    goto L_12edc0;
L_12f170:
    cpu->regs[6] = 255ULL;
    goto L_12f104;
L_12f178:
    cpu->regs[0] = cpu->regs[23] + 56ULL;
    if ((cpu->regs[27])==0) goto L_12eef4;
    goto L_12f070;
L_12f184:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
    goto L_12efc0;
L_12f18c:
    if ((cpu->regs[27])==0) goto L_12ef84;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[24] >> 2) & 0x7ULL)));
    PB_STRW((SP + 108), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[23] + 56ULL;
    goto L_12f070;
L_12f1a0:
    cpu->regs[27] = 0ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_12edc8;
L_12f1b0:
    FLAG_CMP(cpu->regs[27], 0ULL);
    cpu->regs[21] = 0ULL;
    cpu->regs[24] = (FLAG_NE) ? 1 : 0;
    cpu->regs[19] = 0ULL;
L_12f1c0:
    cpu->regs[25] = (~cpu->regs[19]);
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[25] = cpu->regs[25] + cpu->regs[22];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_LDR(cpu->regs[6], (cpu->regs[26] + (cpu->regs[19] << 3)));
    cpu->regs[25] = cpu->regs[25] & 1ULL;
    if (FLAG_NE) goto L_12f358;
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])==0) goto L_12f318;
L_12f1e4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x12f204ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11ae68ULL);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[20];
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_LE) goto L_12ef84;
    if ((cpu->regs[25])==0) goto L_12f260;
    FLAG_CMP(cpu->regs[19], 0ULL);
    PB_LDR(cpu->regs[6], (cpu->regs[26] + (cpu->regs[19] << 3)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12f38c;
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])==0) goto L_12f318;
L_12f22c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x12f24cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11ae68ULL);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[20];
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_LE) goto L_12ef84;
    /* nop */
    /* nop */
L_12f260:
    FLAG_CMP(cpu->regs[19], 0ULL);
    PB_LDR(cpu->regs[6], (cpu->regs[26] + (cpu->regs[19] << 3)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12f32c;
L_12f270:
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])==0) goto L_12f318;
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12f294ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11ae68ULL);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[20];
    cpu->regs[19] = cpu->regs[19] + 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[25] = cpu->regs[19];
    PB_LDR(cpu->regs[6], (cpu->regs[26] + (cpu->regs[19] << 3)));
    if (FLAG_NE) goto L_12f2e8;
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])==0) goto L_12f318;
L_12f2b4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = cpu->regs[25] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x12f2d4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11ae68ULL);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[20];
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_GT) goto L_12f260;
    if ((cpu->regs[28])!=0) goto L_12ef88;
    goto L_12ef9c;
L_12f2e8:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 96), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x12f308ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[6], (SP + 96));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[27];
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])!=0) goto L_12f2b4;
L_12f318:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_GT) goto L_12f1c0;
    if ((cpu->regs[28])!=0) goto L_12ef88;
    goto L_12ef9c;
L_12f32c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 96), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x12f34cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[6], (SP + 96));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[27];
    goto L_12f270;
L_12f358:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 96), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x12f378ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[6], (SP + 96));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[27];
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])!=0) goto L_12f1e4;
    goto L_12f318;
L_12f38c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 96), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x12f3acULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[6], (SP + 96));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[27];
    PB_LDR(cpu->regs[20], (cpu->regs[6] + 16));
    if ((cpu->regs[20])!=0) goto L_12f22c;
    goto L_12f318;
L_12f3c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[4];
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 24));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 1384ULL;
    cpu->regs[30] = PB_BASE + 0x12f3e0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_12ee94;
L_12f3e4:
    PB_STRW((cpu->regs[1] + 8080), cpu->regs[0]);
    goto L_12f140;
L_12f3ec:
    cpu->regs[1] = cpu->regs[28] + 56ULL;
    PB_STR((SP + 96), cpu->regs[1]);
L_12f3f4:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_12eef8;
    if ((cpu->regs[28])!=0) goto L_12ef88;
    goto L_12ef9c;
L_12f404:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 56));
    PB_STR((SP + 96), cpu->regs[1]);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_12eef8;
    goto L_12ef88;
L_12f418:
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2248));
    cpu->regs[0] = 62720ULL;
    cpu->regs[1] = 32ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[28] = cpu->regs[28] + cpu->regs[0];
    goto L_12edc0;
L_12f434:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    cpu->regs[3] = 65535ULL;
    cpu->regs[0] = 1114111ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[0];
    goto L_12f15c;
L_12f448:
    PB_LDR(cpu->regs[24], (cpu->regs[23] + 32));
    PB_STR((SP + 96), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 56));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[24] >> 2) & 0x7ULL)));
    PB_STRW((SP + 108), cpu->regs[1]);
    if ((cpu->regs[27])==0) goto L_12f3f4;
    goto L_12f070;
L_12f464:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 1336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[28] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12f484ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_12ee94;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2] & 3ULL;
    cpu->regs[2] = cpu->regs[2] | cpu->regs[3];
    cpu->regs[3] = cpu->regs[3] & 3ULL;
    FLAG_CMP(cpu->regs[2], 15ULL);
    if (FLAG_HI) goto L_12f530;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 24));
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[19] = cpu->regs[0] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[2];
    cpu->regs[0] = cpu->regs[19] - cpu->regs[0] * cpu->regs[1];
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_12f504;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_12f4f8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_12f504:
    cpu->regs[1] = 1073741823ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_12f524;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0xe3e84ULL); return; };
L_12f524:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x169eacULL); return; };
L_12f530:
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_12f54c;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_12f578;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0x150300ULL); return; };
L_12f54c:
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_12f584;
    cpu->regs[30] = PB_BASE + 0x12f558ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x149310ULL);
    if ((cpu->regs[0])==0) goto L_12f4f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 3ULL));
    cpu->regs[2] = cpu->regs[1] & 18446744073709551608ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[19] - cpu->regs[3]));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_12f4f8;
L_12f578:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(23, cpu, tlb, PB_BASE + 0x149310ULL); return; };
L_12f584:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[4];
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x150300ULL); return; };
    /* nop */
    /* nop */
    SP = SP - 80ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 96));
    if ((cpu->regs[0])==0) goto L_12f670;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_12f670;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3880));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x12f5f0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12f6e4;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x12f610ULL; PB_CALL(26, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_12f760;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[0] - 1ULL;
L_12f624:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_12f770;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_12f644;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_12f644:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_12f798;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_12f670:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2224));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_12f7ac;
    cpu->regs[20] = SP + 16ULL;
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = SP;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12f6a0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x146840ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12f7a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12f6bcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x146b24ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_12f6f4;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_12f70c;
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12f6dcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1db900ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_12f644;
L_12f6e4:
    if (!((cpu->regs[0] >> 63) & 1)) goto L_12f704;
L_12f6e8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    goto L_12f624;
L_12f6f4:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12f6fcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_12f644;
L_12f704:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_12f624;
L_12f70c:
    cpu->regs[30] = PB_BASE + 0x12f710ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1519a0ULL);
    if ((cpu->regs[0])==0) goto L_12f7a0;
    PB_LDR(cpu->regs[5], (SP + 0));
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[3], (SP + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[5] = cpu->regs[5] << 3;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[2] + (cpu->regs[3] << 3);
L_12f730:
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_12f790;
L_12f740:
    PB_STR((cpu->regs[6] + (cpu->regs[1] << 3)), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[3] = cpu->regs[3] + cpu->regs[5];
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_12f730;
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]);
    goto L_12f644;
L_12f760:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_12f6e8;
    cpu->regs[0] = 0ULL;
    goto L_12f644;
L_12f770:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = 24680ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x12f788ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    cpu->regs[0] = 0ULL;
    goto L_12f644;
L_12f790:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
    goto L_12f740;
L_12f798:
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x12f7a0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7c170ULL);
L_12f7a0:
    PB_LDR(cpu->regs[21], (SP + 64));
    cpu->regs[0] = 0ULL;
    goto L_12f644;
L_12f7ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12f7c8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_12f644;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[0] + 8ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 12));
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[3] = 100ULL;
    cpu->regs[4] = 36ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12f814ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x12fc40ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12f864;
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 12));
    cpu->regs[0] = ((uint32_t)(cpu->regs[5] + 1ULL));
    PB_STRW((cpu->regs[19] + 12), cpu->regs[0]);
    FLAG_CMP(cpu->regs[5], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12f864;
    cpu->regs[1] = 36ULL;
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[5] = (uint64_t)((int64_t)(int32_t)cpu->regs[5] * (int64_t)(int32_t)cpu->regs[1]);
    cpu->regs[1] = cpu->regs[2] + cpu->regs[5];
    PB_STRW((cpu->regs[2] + cpu->regs[5]), cpu->regs[23]);
    PB_STRW((cpu->regs[1] + 4), cpu->regs[22]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[20]); PB_STR((cpu->regs[1] + 8) + 8, cpu->regs[21]);
L_12f850:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_12f864:
    cpu->regs[0] = 4294967295ULL;
    goto L_12f850;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LS) goto L_12f898;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_12f894;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_12f894:
    return;
L_12f898:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 24680ULL;
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12f8c0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
