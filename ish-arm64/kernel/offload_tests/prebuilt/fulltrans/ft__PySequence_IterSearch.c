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

void ft__PySequence_IterSearch(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_276a88:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if (FLAG_EQ) goto L_276c3c;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x276ab8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_276b64;
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = 0ULL;
    cpu->regs[26] = 9223372036854775807ULL;
L_276ad0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x276ad8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_276bb0;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x276aecULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_276b98;
L_276af8:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_276bd8;
    if (FLAG_NE) goto L_276b20;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_276ad0;
    FLAG_CMP(cpu->regs[22], cpu->regs[26]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] | cpu->regs[0]));
    goto L_276ad0;
L_276b20:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_276be0;
    if ((((uint32_t)(cpu->regs[25])))!=0) goto L_276c0c;
L_276b2c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_276c2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_276c2c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x276b48ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_276b54:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_276b64:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x276b74ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_276bfc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[22] = 18446744073709551615ULL;
    cpu->regs[0] = cpu->regs[0] + 1008ULL;
    cpu->regs[30] = PB_BASE + 0x276b8cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x234660ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_276b54;
L_276b98:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_276af8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x276bacULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_276af8;
L_276bb0:
    cpu->regs[30] = PB_BASE + 0x276bb4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_276bd8;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_276b2c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 1120ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x276bd8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_276bd8:
    cpu->regs[22] = 18446744073709551615ULL;
    goto L_276b2c;
L_276be0:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_276c68;
    cpu->regs[0] = 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_276c48;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_276ad0;
L_276bfc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[22] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_276b54;
L_276c0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[22] = 18446744073709551615ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x276c28ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_276b2c;
L_276c2c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_276b54;
L_276c3c:
    cpu->regs[22] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x276c44ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_276b54;
L_276c48:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[22] = 18446744073709551615ULL;
    cpu->regs[1] = cpu->regs[1] + 1056ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x276c64ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_276b2c;
L_276c68:
    cpu->regs[22] = 1ULL;
    goto L_276b2c;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2280));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2296));
    FLAG_CMP(cpu->regs[4], cpu->regs[3]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_276c94;
    goto L_276cac;
L_276c94:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 3ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x276ca4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x276a88ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_276cac:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 4ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[1] = cpu->regs[22] + 3208ULL;
    cpu->regs[30] = PB_BASE + 0x276cdcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_276d80;
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_276da8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x276cfcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x276d10ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11ebb0ULL);
L_276d10:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)1LL)); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_276d80;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_276d90;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x276d34ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1b06e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_276d80;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x276d44ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x154008ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_276da0;
    cpu->regs[1] = cpu->regs[22] + 3208ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x276d58ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[21] = cpu->regs[0];
L_276d5c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x276d64ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x276d6cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_276d80:
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_276d5c;
L_276d90:
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_276d5c;
L_276da0:
    cpu->regs[21] = 4294967295ULL;
    goto L_276d5c;
L_276da8:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x276db8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x276dccULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    goto L_276d10;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_276e0c;
L_276de8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x276df0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x276e44ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_276e38;
L_276dfc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_276e0c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1160ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x276e24ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_276de8;
L_276e28:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_276e38:
    cpu->regs[30] = PB_BASE + 0x276e3cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_276e28;
    goto L_276dfc;
}
