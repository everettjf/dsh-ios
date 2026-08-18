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

void ft__PyBytes_FormatEx(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[29] = SP;
    SP = SP - 656ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 648), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[2])==0) goto L_23c548;
    PB_STR((SP + 680), cpu->regs[20]);
    cpu->regs[20] = SP + 96ULL;
    PB_STR((SP + 96), 0ULL); PB_STR((SP + 96) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 672), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 688), cpu->regs[21]);
    cpu->regs[2] = cpu->regs[1];
    PB_STR((SP + 696), cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[3] = 512ULL;
    PB_STR((SP + 704), cpu->regs[23]);
    PB_STR((SP + 712), cpu->regs[24]);
    cpu->regs[23] = 1ULL;
    PB_STR((SP + 720), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[1];
    PB_STR((SP + 728), cpu->regs[26]);
    cpu->regs[1] = SP + 132ULL;
    PB_STR((cpu->regs[20] + 16), 0ULL); PB_STR((cpu->regs[20] + 16) + 8, 0ULL);
    PB_STR((SP + 104), cpu->regs[3]);
    PB_STRW((SP + 120), cpu->regs[22]);
    PB_STRW((SP + 128), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x23ba84ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11db70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23c520;
    PB_STR((SP + 736), cpu->regs[27]);
    PB_STR((SP + 744), cpu->regs[28]);
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_23ba9c;
    PB_STRW((SP + 124), cpu->regs[23]);
L_23ba9c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 112));
    if (((cpu->regs[1] >> 26) & 1)) goto L_23c188;
    cpu->regs[2] = 18446744073709551614ULL;
    PB_STR((SP + 80), cpu->regs[2]);
    cpu->regs[22] = 18446744073709551615ULL;
    if ((cpu->regs[0])!=0) goto L_23c01c;
L_23babc:
    PB_STR((SP + 8), 0ULL);
L_23bac0:
    PB_LDR(cpu->regs[26], (SP + 32));
    cpu->regs[0] = SP + 80ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    PB_STRW((SP + 56), 0ULL);
L_23bad0:
    cpu->regs[27] = cpu->regs[25] - 1ULL; FLAG_CMP(cpu->regs[27], 0);
    if (FLAG_LT) goto L_23bc74;
    cpu->regs[23] = cpu->regs[26];
    PB_LDRB(cpu->regs[0], cpu->regs[23]); cpu->regs[23] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(37ULL)));
    if (FLAG_EQ) goto L_23bb40;
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 37ULL;
    cpu->regs[30] = PB_BASE + 0x23baf8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7bdd0ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[26];
    cpu->regs[27] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[25];
    FLAG_CMP(cpu->regs[26], cpu->regs[21]);
    if (FLAG_HI) goto L_23c630;
    cpu->regs[28] = cpu->regs[26] + cpu->regs[27];
    if (FLAG_HS) goto L_23bb1c;
    FLAG_CMP(cpu->regs[28], cpu->regs[21]);
    if (FLAG_HI) goto L_23c63c;
L_23bb1c:
    cpu->regs[23] = cpu->regs[21] + cpu->regs[27];
L_23bb20:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[21] = cpu->regs[23];
    cpu->regs[26] = cpu->regs[28];
    cpu->regs[25] = cpu->regs[25] - cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x23bb3cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_23bad0;
L_23bb40:
    PB_STR((SP + 88), 0ULL);
    PB_LDRB(cpu->regs[0], (cpu->regs[26] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(37ULL)));
    if (FLAG_EQ) goto L_23c31c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(40ULL)));
    if (FLAG_EQ) goto L_23c204;
L_23bb58:
    cpu->regs[26] = cpu->regs[23];
    cpu->regs[28] = 0ULL;
    cpu->regs[24] = 0ULL;
L_23bb64:
    cpu->regs[25] = cpu->regs[27] - 1ULL;
    if ((cpu->regs[27])==0) goto L_23bb88;
    cpu->regs[23] = cpu->regs[26];
    PB_LDRB(cpu->regs[8], cpu->regs[23]); cpu->regs[23] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_23c3f0;
    if (FLAG_LS) goto L_23bcec;
    cpu->regs[28] = cpu->regs[8];
    cpu->regs[26] = cpu->regs[23];
L_23bb88:
    cpu->regs[11] = ((uint32_t)(cpu->regs[28] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[11])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_23c6dc;
L_23bb94:
    cpu->regs[11] = 18446744073709551615ULL;
    cpu->regs[23] = cpu->regs[11];
L_23bb9c:
    if (((cpu->regs[25] >> 63) & 1)) goto L_23c614;
L_23bba0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[28] - 76ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32ULL)));
    if (FLAG_HI) goto L_23bbbc;
    cpu->regs[1] = 4294967297ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x1000ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[1] >> (cpu->regs[0] & 63);
    if (((cpu->regs[0] >> 0) & 1)) goto L_23c560;
L_23bbbc:
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23bbd0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x23cad0ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[11], (SP + 16));
    if ((cpu->regs[25])!=0) goto L_23bbe4;
    PB_STRW((SP + 124), 0ULL);
L_23bbe4:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(120ULL)));
    if (FLAG_GT) goto L_23bdc4;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(104ULL)));
    if (FLAG_LE) goto L_23be30;
    cpu->regs[2] = ((uint32_t)(cpu->regs[28] - 105ULL));
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = 36929ULL;
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[2] & 63);
    FLAG_CMP((cpu->regs[0]) & (cpu->regs[1]), 0);
    if (FLAG_EQ) goto L_23bdb4;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_23c194;
L_23bc20:
    FLAG_CMP(cpu->regs[11], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)1LL)); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_23c194;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(88ULL)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[24] & 6ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_23c194;
    cpu->regs[4] = ((uint32_t)(cpu->regs[24] & 8ULL));
    cpu->regs[3] = 8ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(111ULL)));
    if (FLAG_NE) goto L_23c1a4;
L_23bc4c:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[5] = cpu->regs[0] - 2ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 112), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x23bc68ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x23cb24ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_23bad0;
    goto L_23bdf0;
L_23bc74:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (SP + 80));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[0], cpu->regs[22]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_23cab4;
    PB_LDRW(cpu->regs[0], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23c2b4;
L_23bc90:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23bc9cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11dec4ULL);
    PB_LDR(cpu->regs[19], (SP + 672));
    PB_LDR(cpu->regs[20], (SP + 680));
    PB_LDR(cpu->regs[21], (SP + 688));
    PB_LDR(cpu->regs[22], (SP + 696));
    PB_LDR(cpu->regs[23], (SP + 704));
    PB_LDR(cpu->regs[24], (SP + 712));
    PB_LDR(cpu->regs[25], (SP + 720));
    PB_LDR(cpu->regs[26], (SP + 728));
    PB_LDR(cpu->regs[27], (SP + 736));
    PB_LDR(cpu->regs[28], (SP + 744));
L_23bcc4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 648));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_23c388;
    SP = SP + 656ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_23bcec:
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(45ULL)));
    if (FLAG_EQ) goto L_23c514;
    if (FLAG_HI) goto L_23bd2c;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_23c3e4;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(44ULL)));
    if (FLAG_EQ) goto L_23c008;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(32ULL)));
    if (FLAG_EQ) goto L_23c3b4;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(35ULL)));
    if (FLAG_EQ) goto L_23c508;
    cpu->regs[28] = cpu->regs[8];
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(42ULL)));
    if (FLAG_EQ) goto L_23c1b0;
    cpu->regs[26] = cpu->regs[23];
    goto L_23bb94;
L_23bd2c:
    cpu->regs[28] = cpu->regs[8];
    cpu->regs[26] = cpu->regs[23];
    cpu->regs[11] = 18446744073709551615ULL;
L_23bd38:
    cpu->regs[23] = 4294967295ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(46ULL)));
    if (FLAG_NE) goto L_23bb9c;
L_23bd44:
    cpu->regs[0] = cpu->regs[25] - 1ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_LT) goto L_23c5a4;
    PB_LDRB(cpu->regs[28], (cpu->regs[26] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(42ULL)));
    if (FLAG_NE) goto L_23c588;
    cpu->regs[2] = SP + 80ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23bd6cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x23cad0ULL);
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[11], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_23c5f8;
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23bd88ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x13ae00ULL);
    PB_LDR(cpu->regs[11], (SP + 16));
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23c57c;
L_23bd98:
    cpu->regs[25] = cpu->regs[25] - 2ULL;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] & ~(((uint64_t)((int64_t)cpu->regs[23] >> 31)))));
    FLAG_CMP(cpu->regs[25], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23c614;
    PB_LDRB(cpu->regs[28], (cpu->regs[26] + 1));
    cpu->regs[26] = cpu->regs[26] + 2ULL;
    goto L_23bba0;
L_23bdb4:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(115ULL)));
    if (FLAG_EQ) goto L_23c048;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(114ULL)));
    if (FLAG_EQ) goto L_23c648;
L_23bdc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[4] = cpu->regs[26] - 1ULL;
    PB_LDR(cpu->regs[1], (SP + 32));
    cpu->regs[3] = cpu->regs[28];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[1];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x23bdf0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
L_23bdf0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23bdf8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
    PB_LDRW(cpu->regs[0], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23c6bc;
L_23be00:
    PB_LDR(cpu->regs[19], (SP + 672));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[20], (SP + 680));
    PB_LDR(cpu->regs[21], (SP + 688));
    PB_LDR(cpu->regs[22], (SP + 696));
    PB_LDR(cpu->regs[23], (SP + 704));
    PB_LDR(cpu->regs[24], (SP + 712));
    PB_LDR(cpu->regs[25], (SP + 720));
    PB_LDR(cpu->regs[26], (SP + 728));
    PB_LDR(cpu->regs[27], (SP + 736));
    PB_LDR(cpu->regs[28], (SP + 744));
    goto L_23bcc4;
L_23be30:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(98ULL)));
    if (FLAG_EQ) goto L_23c048;
    if (FLAG_LE) goto L_23bf0c;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(100ULL)));
    if (FLAG_NE) goto L_23c348;
L_23be44:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    cpu->regs[27] = cpu->regs[28];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_23bc20;
L_23be5c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 24) & 1)) goto L_23ca34;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23be6cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1cb0b0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23c8bc;
    cpu->regs[1] = ((uint32_t)(cpu->regs[27] - 88ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[27] - 88ULL));
    cpu->regs[0] = 4294967297ULL;
    PB_STRW((SP + 16), cpu->regs[2]);
    PB_STR((SP + 48), cpu->regs[11]);
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x80ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[1] & 63);
    if (!((cpu->regs[0] >> 0) & 1)) goto L_23c304;
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x23be9cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (SP + 40)); PB_LDR(cpu->regs[11], (SP + 40) + 8);
L_23bea4:
    if ((cpu->regs[4])!=0) goto L_23c454;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2736));
    PB_STR((SP + 8), cpu->regs[5]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x23bebcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x121d30ULL);
    PB_LDR(cpu->regs[5], (SP + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23bdf0;
L_23bec4:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    cpu->regs[1] = 4294967297ULL;
    PB_LDRB(cpu->regs[3], (SP + 16));
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x80ULL & 0xffff) << 16);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] >> (cpu->regs[3] & 63);
    FLAG_CMP((cpu->regs[1]) & (1ULL), 0);
    cpu->regs[3] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = cpu->regs[3] + 376ULL;
    cpu->regs[1] = cpu->regs[1] + 360ULL;
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 496ULL;
    cpu->regs[30] = PB_BASE + 0x23bf08ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_23bdf0;
L_23bf0c:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(88ULL)));
    if (FLAG_EQ) goto L_23be44;
    if (FLAG_GT) goto L_23c640;
    cpu->regs[0] = ((uint32_t)(cpu->regs[28] - 69ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_HI) goto L_23bdc4;
L_23bf24:
    FLAG_CMP(cpu->regs[11], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)1LL)); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_23bf38;
    FLAG_CMP((((uint32_t)(cpu->regs[24]))) & (((uint32_t)(6ULL))), 0);
    if (FLAG_EQ) goto L_23c684;
L_23bf38:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[6] = cpu->regs[21];
    cpu->regs[4] = SP + 88ULL;
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23bf5cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xab874ULL);
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[0], (SP + 88));
    FLAG_CMP((cpu->regs[24]) & (16ULL), 0);
    PB_LDR(cpu->regs[11], (SP + 16));
    cpu->regs[23] = 32ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 16));
    cpu->regs[1] = 48ULL;
    cpu->regs[3] = cpu->regs[0] + 32ULL;
    cpu->regs[23] = (FLAG_EQ) ? cpu->regs[23] : cpu->regs[1];
L_23bf80:
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + 0));
    cpu->regs[0] = 253ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[4] - 43ULL));
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_NE) goto L_23ca94;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[27] = cpu->regs[27] - 1ULL;
L_23bf9c:
    FLAG_CMP(cpu->regs[27], cpu->regs[11]);
    cpu->regs[7] = (FLAG_GE) ? cpu->regs[27] : cpu->regs[11];
L_23bfa4:
    FLAG_CMP(cpu->regs[11], cpu->regs[27]);
    cpu->regs[2] = (FLAG_LE) ? (cpu->regs[7] + 1) : cpu->regs[7];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_LE) goto L_23bfe4;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[2] - 2ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[11]);
    PB_STR((SP + 40), cpu->regs[7]); PB_STR((SP + 40) + 8, cpu->regs[3]);
    PB_STRW((SP + 60), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23bfd0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11db70ULL);
    PB_LDR(cpu->regs[11], (SP + 16));
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[7], (SP + 40)); PB_LDR(cpu->regs[3], (SP + 40) + 8);
    PB_LDRW(cpu->regs[4], (SP + 60));
    if ((cpu->regs[0])==0) goto L_23bdf0;
L_23bfe4:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(32ULL)));
    if (FLAG_EQ) goto L_23bff8;
    cpu->regs[6] = cpu->regs[21];
    PB_STRB(cpu->regs[6], cpu->regs[4]); cpu->regs[6] += 1;
    cpu->regs[21] = cpu->regs[6];
L_23bff8:
    FLAG_CMP(cpu->regs[11], cpu->regs[27]);
    if (FLAG_LE) goto L_23c0b8;
    cpu->regs[7] = cpu->regs[7] - 1ULL;
    goto L_23c0b8;
L_23c008:
    cpu->regs[26] = cpu->regs[23];
    cpu->regs[11] = 18446744073709551615ULL;
    cpu->regs[28] = cpu->regs[8];
    cpu->regs[23] = cpu->regs[11];
    goto L_23bb9c;
L_23c01c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_23babc;
    FLAG_CMP((cpu->regs[1]) & (469762048ULL), 0);
    if (FLAG_NE) goto L_23babc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23c03cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe270cULL);
    PB_STR((SP + 8), cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23bac0;
    goto L_23babc;
L_23c048:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 27) & 1)) goto L_23c7b0;
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[3] = cpu->regs[5] + 32ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[5] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_23c06c;
L_23c068:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
L_23c06c:
    PB_STR((SP + 88), cpu->regs[5]);
    if (!((cpu->regs[23] >> 31) & 1)) goto L_23c168;
L_23c074:
    FLAG_CMP(cpu->regs[27], cpu->regs[11]);
    cpu->regs[23] = 32ULL;
    cpu->regs[7] = (FLAG_GE) ? cpu->regs[27] : cpu->regs[11];
L_23c080:
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[7], 2ULL);
    if (FLAG_LE) goto L_23c0b8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[7] - 2ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[7]);
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x23c0a4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11db70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[7], (SP + 16));
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[3], (SP + 40));
L_23c0b8:
    cpu->regs[5] = ((uint32_t)(cpu->regs[24] & 8ULL));
    if (((cpu->regs[24] >> 3) & 1)) goto L_23c75c;
L_23c0c0:
    FLAG_CMP(cpu->regs[7], cpu->regs[27]);
    if (FLAG_GT) goto L_23c12c;
L_23c0c8:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(32ULL)));
    if (FLAG_NE) goto L_23c0d8;
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_23c74c;
L_23c0d4:
    if ((((uint32_t)(cpu->regs[5])))!=0) goto L_23c8e0;
L_23c0d8:
    FLAG_CMP(cpu->regs[21], cpu->regs[3]);
    if (FLAG_LO) goto L_23c8d0;
    if (FLAG_LS) goto L_23c0f0;
    cpu->regs[0] = cpu->regs[3] + cpu->regs[27];
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LO) goto L_23c63c;
L_23c0f0:
    cpu->regs[23] = cpu->regs[21] + cpu->regs[27];
L_23c0f4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[27];
    PB_STR((SP + 16), cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x23c108ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[21] = cpu->regs[23];
    PB_LDR(cpu->regs[7], (SP + 16));
    FLAG_CMP(cpu->regs[7], cpu->regs[27]);
    if (FLAG_GT) goto L_23c4d8;
L_23c118:
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_23c2d4;
L_23c120:
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x23c128ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_23bad0;
L_23c12c:
    if (((cpu->regs[24] >> 0) & 1)) goto L_23c0c8;
    cpu->regs[24] = cpu->regs[7] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    PB_STRW((SP + 16), cpu->regs[5]);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[24];
    PB_STR((SP + 40), cpu->regs[3]);
    PB_STRW((SP + 48), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23c154ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7aee0ULL);
    PB_LDR(cpu->regs[3], (SP + 40));
    cpu->regs[7] = cpu->regs[27];
    PB_LDRW(cpu->regs[5], (SP + 16));
    PB_LDRW(cpu->regs[4], (SP + 48));
    goto L_23c0c8;
L_23c168:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[27], cpu->regs[23]);
    if (FLAG_LE) goto L_23c074;
L_23c174:
    FLAG_CMP(cpu->regs[0], cpu->regs[11]);
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[7] = (FLAG_GE) ? cpu->regs[0] : cpu->regs[11];
    cpu->regs[23] = 32ULL;
    goto L_23c080;
L_23c188:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16));
    PB_STR((SP + 80), 0ULL);
    goto L_23babc;
L_23c194:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(105ULL)));
    cpu->regs[27] = 100ULL;
    cpu->regs[27] = (FLAG_NE) ? cpu->regs[28] : cpu->regs[27];
    goto L_23be5c;
L_23c1a4:
    if (FLAG_GT) goto L_23c334;
    cpu->regs[3] = 10ULL;
    goto L_23bc4c;
L_23c1b0:
    cpu->regs[2] = SP + 80ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23c1c0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x23cad0ULL);
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_23c5f8;
    cpu->regs[30] = PB_BASE + 0x23c1d4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[11] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23c440;
    if (((cpu->regs[0] >> 63) & 1)) goto L_23c448;
L_23c1e4:
    cpu->regs[25] = cpu->regs[27] - 2ULL; FLAG_CMP(cpu->regs[25], 0);
    if (FLAG_LT) goto L_23c614;
    PB_LDRB(cpu->regs[28], (cpu->regs[23] + 0));
    cpu->regs[26] = cpu->regs[26] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(46ULL)));
    if (FLAG_EQ) goto L_23bd44;
    cpu->regs[23] = 4294967295ULL;
    goto L_23bba0;
L_23c204:
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])==0) goto L_23c3fc;
    cpu->regs[0] = cpu->regs[26] + 2ULL;
    cpu->regs[27] = cpu->regs[25] - 2ULL;
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[2] = 1ULL;
L_23c21c:
    cpu->regs[27] = cpu->regs[27] - 1ULL; FLAG_CMP(cpu->regs[27], 0);
    if (FLAG_LT) goto L_23c3c8;
    PB_LDRB(cpu->regs[1], (cpu->regs[23] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(41ULL)));
    if (FLAG_EQ) goto L_23c240;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(40ULL)));
    if (FLAG_EQ) goto L_23c438;
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_23c21c;
L_23c240:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_23c244:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_23c21c;
    cpu->regs[1] = cpu->regs[23] - cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x23c25cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDRW(cpu->regs[0], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23c418;
L_23c26c:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x23c278ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23c298;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_23c298;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x23c298ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23c298:
    if ((cpu->regs[19])==0) goto L_23c4bc;
    cpu->regs[0] = 18446744073709551614ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[22] = 18446744073709551615ULL;
    PB_STRW((SP + 56), cpu->regs[1]);
    PB_STR((SP + 80), cpu->regs[0]);
    goto L_23bb58;
L_23c2b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23bc90;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23bc90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23c2d0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23bc90;
L_23c2d4:
    PB_LDR(cpu->regs[0], (SP + 80));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_GE) goto L_23c120;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 624ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c2f8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x23c300ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_23bdf0;
L_23c304:
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x23c310ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x14b0a0ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (SP + 40)); PB_LDR(cpu->regs[11], (SP + 40) + 8);
    goto L_23bea4;
L_23c31c:
    cpu->regs[6] = cpu->regs[21];
    cpu->regs[26] = cpu->regs[26] + 2ULL;
    cpu->regs[25] = cpu->regs[25] - 2ULL;
    PB_STRB(cpu->regs[6], cpu->regs[0]); cpu->regs[6] += 1;
    cpu->regs[21] = cpu->regs[6];
    goto L_23bad0;
L_23c334:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(117ULL)));
    cpu->regs[3] = 16ULL;
    cpu->regs[0] = 10ULL;
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[0];
    goto L_23bc4c;
L_23c348:
    if (FLAG_GT) goto L_23c974;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 27) & 1)) goto L_23c944;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_23c860;
    PB_LDRB(cpu->regs[0], (cpu->regs[5] + 32));
    PB_STRB((SP + 75), cpu->regs[0]);
L_23c36c:
    FLAG_CMP(cpu->regs[11], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_23c854;
    cpu->regs[6] = cpu->regs[21];
    PB_LDRB(cpu->regs[0], (SP + 75));
    PB_STRB(cpu->regs[6], cpu->regs[0]); cpu->regs[6] += 1;
    cpu->regs[21] = cpu->regs[6];
    goto L_23bad0;
L_23c388:
    PB_STR((SP + 672), cpu->regs[19]);
    PB_STR((SP + 680), cpu->regs[20]);
    PB_STR((SP + 688), cpu->regs[21]);
    PB_STR((SP + 696), cpu->regs[22]);
    PB_STR((SP + 704), cpu->regs[23]);
    PB_STR((SP + 712), cpu->regs[24]);
    PB_STR((SP + 720), cpu->regs[25]);
    PB_STR((SP + 728), cpu->regs[26]);
    PB_STR((SP + 736), cpu->regs[27]);
    PB_STR((SP + 744), cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x23c3b4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23c3b4:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] | 4ULL));
    cpu->regs[28] = cpu->regs[8];
L_23c3bc:
    cpu->regs[27] = cpu->regs[25];
    cpu->regs[26] = cpu->regs[23];
    goto L_23bb64;
L_23c3c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3904ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c3e0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c3e4:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] | 2ULL));
    cpu->regs[28] = cpu->regs[8];
    goto L_23c3bc;
L_23c3f0:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] | 16ULL));
    cpu->regs[28] = cpu->regs[8];
    goto L_23c3bc;
L_23c3fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3872ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c414ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c418:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23c26c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23c26c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23c434ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23c26c;
L_23c438:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    goto L_23c244;
L_23c440:
    cpu->regs[30] = PB_BASE + 0x23c444ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_23bdf0;
L_23c448:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] | 1ULL));
    cpu->regs[11] = (uint64_t)(-(int64_t)cpu->regs[11]);
    goto L_23c1e4;
L_23c454:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = ((uint32_t)(cpu->regs[24] & 8ULL));
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[3] = cpu->regs[27];
    PB_STR((SP + 16), cpu->regs[4]);
    PB_STR((SP + 40), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23c470ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x225760ULL);
    PB_LDR(cpu->regs[4], (SP + 16));
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[11], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23c490;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23c4c4;
L_23c490:
    PB_STR((SP + 88), cpu->regs[23]);
    if ((cpu->regs[23])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    if (((cpu->regs[0] >> 5) & 1)) goto L_23c4f4;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 56));
L_23c4a4:
    FLAG_CMP((cpu->regs[24]) & (16ULL), 0);
    PB_LDR(cpu->regs[27], (cpu->regs[23] + 16));
    cpu->regs[0] = 48ULL;
    cpu->regs[23] = 32ULL;
    cpu->regs[23] = (FLAG_EQ) ? cpu->regs[23] : cpu->regs[0];
    goto L_23bf80;
L_23c4bc:
    PB_STRW((SP + 56), 0ULL);
    goto L_23bdf0;
L_23c4c4:
    cpu->regs[0] = cpu->regs[4];
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23c4d0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[11], (SP + 16));
    goto L_23c490;
L_23c4d8:
    cpu->regs[27] = cpu->regs[7] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = 32ULL;
    cpu->regs[21] = cpu->regs[23] + cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x23c4f0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7aee0ULL);
    goto L_23c118;
L_23c4f4:
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[3] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[0];
    goto L_23c4a4;
L_23c508:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] | 8ULL));
    cpu->regs[28] = cpu->regs[8];
    goto L_23c3bc;
L_23c514:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] | 1ULL));
    cpu->regs[28] = cpu->regs[8];
    goto L_23c3bc;
L_23c520:
    PB_LDR(cpu->regs[19], (SP + 672));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[20], (SP + 680));
    PB_LDR(cpu->regs[21], (SP + 688));
    PB_LDR(cpu->regs[22], (SP + 696));
    PB_LDR(cpu->regs[23], (SP + 704));
    PB_LDR(cpu->regs[24], (SP + 712));
    PB_LDR(cpu->regs[25], (SP + 720));
    PB_LDR(cpu->regs[26], (SP + 728));
    goto L_23bcc4;
L_23c548:
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = 583ULL;
    cpu->regs[0] = cpu->regs[0] + 1848ULL;
    cpu->regs[30] = PB_BASE + 0x23c558ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_23bcc4;
L_23c560:
    cpu->regs[25] = cpu->regs[25] - 1ULL;
    FLAG_CMP(cpu->regs[25], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23c614;
    cpu->regs[9] = cpu->regs[26];
    PB_LDRB(cpu->regs[28], cpu->regs[9]); cpu->regs[9] += 1;
    cpu->regs[26] = cpu->regs[9];
    goto L_23bbbc;
L_23c57c:
    cpu->regs[30] = PB_BASE + 0x23c580ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_23bd98;
    goto L_23bdf0;
L_23c588:
    cpu->regs[23] = ((uint32_t)(cpu->regs[28] - 48ULL));
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    cpu->regs[25] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_23c5b4;
    cpu->regs[23] = 0ULL;
    goto L_23bba0;
L_23c5a4:
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[23] = 0ULL;
    cpu->regs[28] = 46ULL;
    goto L_23bb9c;
L_23c5b4:
    cpu->regs[3] = 47ULL;
    cpu->regs[1] = 10ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x8000ULL & 0xffff) << 16);
L_23c5c0:
    cpu->regs[25] = cpu->regs[25] - 1ULL;
    FLAG_CMP(cpu->regs[25], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23c614;
    PB_LDRB(cpu->regs[0], cpu->regs[26]); cpu->regs[26] += 1;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 48ULL));
    cpu->regs[28] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_23bba0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - cpu->regs[0]));
    cpu->regs[0] = ((uint32_t)((cpu->regs[1] ? cpu->regs[0] / cpu->regs[1] : 0)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_LT) goto L_23c730;
    cpu->regs[23] = cpu->regs[23] * cpu->regs[1] + cpu->regs[2];
    goto L_23c5c0;
L_23c5f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c610ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c614:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c62cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c630:
    cpu->regs[23] = cpu->regs[21] + cpu->regs[27];
    FLAG_CMP(cpu->regs[26], cpu->regs[23]);
    if (FLAG_HS) goto L_23ca84;
L_23c63c:
    __builtin_trap();
L_23c640:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(97ULL)));
    if (FLAG_NE) goto L_23bdc4;
L_23c648:
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23c654ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x25bc90ULL);
    PB_STR((SP + 88), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[11], (SP + 16));
    if (((cpu->regs[1] >> 5) & 1)) goto L_23c71c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 56));
L_23c66c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[23] >> 31) & 1)) goto L_23c174;
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    cpu->regs[23] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[0] : cpu->regs[23];
    goto L_23c174;
L_23c684:
    PB_LDR(cpu->regs[2], (SP + 112));
    cpu->regs[6] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[8] = cpu->regs[2] - 2ULL;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[5] = cpu->regs[20];
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 4294967295ULL;
    PB_STR((SP + 112), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x23c6b0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xab874ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_23bad0;
    goto L_23bdf0;
L_23c6bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23be00;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23be00;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23c6d8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23be00;
L_23c6dc:
    cpu->regs[11] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[11]));
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[2] = 10ULL;
L_23c6e8:
    cpu->regs[25] = cpu->regs[25] - 1ULL; FLAG_CMP(cpu->regs[25], 0);
    if (FLAG_LT) goto L_23c920;
    PB_LDRB(cpu->regs[28], cpu->regs[26]); cpu->regs[26] += 1;
    cpu->regs[0] = ((uint32_t)(cpu->regs[28] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_23bd38;
    cpu->regs[1] = cpu->regs[3] - ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = (cpu->regs[2] ? cpu->regs[1] / cpu->regs[2] : 0);
    FLAG_CMP(cpu->regs[1], cpu->regs[11]);
    if (FLAG_LT) goto L_23c928;
    cpu->regs[11] = cpu->regs[11] * cpu->regs[2] + cpu->regs[0];
    goto L_23c6e8;
L_23c71c:
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[3] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[1];
    goto L_23c66c;
L_23c730:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 392ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c748ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c74c:
    cpu->regs[6] = cpu->regs[21];
    PB_STRB(cpu->regs[6], cpu->regs[4]); cpu->regs[6] += 1;
    cpu->regs[21] = cpu->regs[6];
    goto L_23c0d4;
L_23c75c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[28] - 88ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(32ULL)));
    if (FLAG_HI) goto L_23c0c0;
    cpu->regs[0] = 4294967297ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x80ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[1] & 63);
    if (!((cpu->regs[0] >> 0) & 1)) goto L_23c0c0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(32ULL)));
    if (FLAG_EQ) goto L_23c7a0;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[21];
    PB_LDRB(cpu->regs[2], cpu->regs[1]); cpu->regs[1] += 2;
    PB_STRB(cpu->regs[0], cpu->regs[2]); cpu->regs[0] += 2;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 1));
    cpu->regs[3] = cpu->regs[1];
    PB_STRB((cpu->regs[21] + 1), cpu->regs[2]);
    cpu->regs[21] = cpu->regs[0];
L_23c7a0:
    cpu->regs[7] = cpu->regs[7] - 2ULL;
    cpu->regs[27] = cpu->regs[27] - 2ULL;
    cpu->regs[7] = cpu->regs[7] & ~(((uint64_t)((int64_t)cpu->regs[7] >> 63)));
    goto L_23c0c0;
L_23c7b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23c7c0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23c7e4;
    PB_LDR(cpu->regs[27], (cpu->regs[5] + 16));
    if ((cpu->regs[27])!=0) goto L_23ca58;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3336));
L_23c7d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_23c068;
    goto L_23c06c;
L_23c7e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 26544ULL;
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 16), cpu->regs[5]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    PB_STR((SP + 40), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23c804ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[11], (SP + 40));
    PB_LDR(cpu->regs[5], (SP + 16));
    PB_STR((SP + 16), cpu->regs[11]);
    if ((cpu->regs[0])==0) goto L_23c980;
    cpu->regs[30] = PB_BASE + 0x23c81cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    PB_LDR(cpu->regs[11], (SP + 16));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23c838;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23c9ac;
L_23c838:
    if ((cpu->regs[5])==0) goto L_23bdf0;
L_23c83c:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 27) & 1)) goto L_23c9f0;
    PB_LDR(cpu->regs[27], (cpu->regs[5] + 16));
    cpu->regs[3] = cpu->regs[5] + 32ULL;
    goto L_23c06c;
L_23c854:
    cpu->regs[3] = SP + 75ULL;
    cpu->regs[0] = 1ULL;
    goto L_23c174;
L_23c860:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23c870ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe270cULL);
L_23c870:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = SP + 76ULL;
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23c880ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x129708ULL);
    PB_LDR(cpu->regs[11], (SP + 16));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_23ca60;
    cpu->regs[30] = PB_BASE + 0x23c890ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_23ca68;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x23c8a4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23bdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 536ULL;
    cpu->regs[30] = PB_BASE + 0x23c8b8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c8bc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[27] - 88ULL));
    PB_STRW((SP + 16), cpu->regs[0]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2736));
    goto L_23bec4;
L_23c8d0:
    cpu->regs[23] = cpu->regs[21] + cpu->regs[27];
    FLAG_CMP(cpu->regs[3], cpu->regs[23]);
    if (FLAG_HS) goto L_23c0f4;
    __builtin_trap();
L_23c8e0:
    cpu->regs[8] = ((uint32_t)(cpu->regs[28] - 88ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(32ULL)));
    if (FLAG_HI) goto L_23c0d8;
    cpu->regs[0] = 4294967297ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x80ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[8] & 63);
    if (!((cpu->regs[0] >> 0) & 1)) goto L_23c0d8;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[21];
    PB_LDRB(cpu->regs[2], cpu->regs[1]); cpu->regs[1] += 2;
    PB_STRB(cpu->regs[0], cpu->regs[2]); cpu->regs[0] += 2;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 1));
    cpu->regs[3] = cpu->regs[1];
    PB_STRB((cpu->regs[21] + 1), cpu->regs[2]);
    cpu->regs[21] = cpu->regs[0];
    goto L_23c0d8;
L_23c920:
    cpu->regs[23] = 4294967295ULL;
    goto L_23bb9c;
L_23c928:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c940ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23c944:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23c954ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23c870;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_23c870;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 40));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STRB((SP + 75), cpu->regs[0]);
    goto L_23c36c;
L_23c974:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(104ULL)));
    if (FLAG_NE) goto L_23bf24;
    goto L_23bdc4;
L_23c980:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23c988ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x141ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23c9cc;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23c994ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x21b4a0ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23bdf0;
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[0] + 32ULL;
    PB_LDR(cpu->regs[11], (SP + 16));
    goto L_23c06c;
L_23c9ac:
    cpu->regs[0] = cpu->regs[27];
    PB_STR((SP + 16), cpu->regs[5]);
    PB_STR((SP + 40), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23c9bcULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[5], (SP + 16));
    PB_LDR(cpu->regs[11], (SP + 40));
    if ((cpu->regs[5])!=0) goto L_23c83c;
    goto L_23bdf0;
L_23c9cc:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 408ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23c9ecULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_23bdf0;
L_23c9f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x23ca10ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[5], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23bdf0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[5] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23bdf0;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x23ca30ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23bdf0;
L_23ca34:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = ((uint32_t)(cpu->regs[24] & 8ULL));
    PB_STR((SP + 16), cpu->regs[11]);
    cpu->regs[30] = PB_BASE + 0x23ca4cULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x225760ULL);
    PB_LDR(cpu->regs[11], (SP + 16));
    cpu->regs[23] = cpu->regs[0];
    goto L_23c490;
L_23ca58:
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 40));
    goto L_23c7d4;
L_23ca60:
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_LS) goto L_23ca8c;
L_23ca68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 592ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23ca80ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23ca84:
    cpu->regs[28] = cpu->regs[26] + cpu->regs[27];
    goto L_23bb20;
L_23ca8c:
    PB_STRB((SP + 75), cpu->regs[0]);
    goto L_23c36c;
L_23ca94:
    FLAG_CMP(cpu->regs[27], cpu->regs[11]);
    cpu->regs[7] = (FLAG_GE) ? cpu->regs[27] : cpu->regs[11];
    if (!((cpu->regs[24] >> 1) & 1)) goto L_23caa8;
    cpu->regs[4] = 43ULL;
    goto L_23bf9c;
L_23caa8:
    if (!((cpu->regs[24] >> 2) & 1)) goto L_23c080;
    cpu->regs[4] = 32ULL;
    goto L_23bfa4;
L_23cab4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 624ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23caccULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23bdf0;
L_23cad0:
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_GE) goto L_23caf4;
    cpu->regs[5] = cpu->regs[4] + 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[5]);
    if (!((cpu->regs[1] >> 63) & 1)) goto L_23caec;
    return;
L_23caec:
    cpu->regs[1] = cpu->regs[4];
    { PB_CALL(66, cpu, tlb, PB_BASE + 0x10eeacULL); return; };
L_23caf4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3928ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23cb14ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
