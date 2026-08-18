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

void ft_PyFunction_NewWithQualName(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_10e1b4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[26] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x10deacULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[27], (cpu->regs[26] + cpu->regs[0]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_10e1d8;
L_10debc:
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 120));
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_10e1e8;
L_10ded0:
    if ((cpu->regs[22])!=0) goto L_10e160;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 128));
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_10e16c;
L_10dee4:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_10e17c;
L_10def8:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_10e144;
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_10e14c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    cpu->regs[24] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_10e158;
L_10df2c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_10e0cc;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2520));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 30768));
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_10e198;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 30784));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_10e198;
L_10df60:
    cpu->regs[4] = 30760ULL;
    cpu->regs[3] = SP;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[4];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10df74ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[28], (SP + 0));
    if ((cpu->regs[28])==0) goto L_10e0dc;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_10e0e4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_10e2e8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 26496));
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_10e10c;
L_10dfa4:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 26512));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_10e10c;
L_10dfb0:
    cpu->regs[0] = 26488ULL;
    cpu->regs[3] = SP;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10dfc4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[23], (SP + 0));
    if ((cpu->regs[23])==0) goto L_10e124;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_10e0bc;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 16));
L_10dfe4:
    if ((cpu->regs[23])==0) goto L_10e200;
L_10dfe8:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3680));
    if (FLAG_EQ) goto L_10e1f4;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x10e004ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e200;
L_10e00c:
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[23]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x10e020ULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
    cpu->regs[2] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((cpu->regs[19] + 40), cpu->regs[22]); PB_STR((cpu->regs[19] + 40) + 8, cpu->regs[21]);
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3648));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 208));
    PB_STR((cpu->regs[19] + 72), 0ULL); PB_STR((cpu->regs[19] + 72) + 8, cpu->regs[24]);
    PB_STR((cpu->regs[19] + 56), 0ULL); PB_STR((cpu->regs[19] + 56) + 8, 0ULL);
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 8));
    PB_STR((cpu->regs[19] + 32), cpu->regs[25]);
    PB_STR((cpu->regs[19] + 88), 0ULL); PB_STR((cpu->regs[19] + 88) + 8, 0ULL);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[5];
    PB_STR((cpu->regs[19] + 104), cpu->regs[28]); PB_STR((cpu->regs[19] + 104) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 120), 0ULL); PB_STR((cpu->regs[19] + 120) + 8, cpu->regs[4]);
    PB_STRW((cpu->regs[19] + 136), 0ULL);
    PB_STR((cpu->regs[5] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[3]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 1816));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_10e298;
L_10e07c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_10e1f0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_10e0bc:
    cpu->regs[30] = PB_BASE + 0x10e0c0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10dfe8;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 16));
    goto L_10dfe4;
L_10e0cc:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x10e0dcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_10e0dc:
    PB_LDR(cpu->regs[28], (cpu->regs[27] + 96));
    if ((cpu->regs[28])!=0) goto L_10e27c;
L_10e0e4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_10e2e8;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2520));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 26496));
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_10dfa4;
L_10e10c:
    cpu->regs[1] = 26488ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x10e118ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_10dfb0;
L_10e124:
    cpu->regs[30] = PB_BASE + 0x10e128ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_10e290;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 56));
    cpu->regs[30] = PB_BASE + 0x10e138ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x196148ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[23])!=0) goto L_10dfe8;
    goto L_10e200;
L_10e144:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2760));
L_10e14c:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_10df2c;
L_10e158:
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
    goto L_10df2c;
L_10e160:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_10dee4;
L_10e16c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_10def8;
L_10e17c:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 89ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0x10e18cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2760));
    goto L_10e14c;
L_10e198:
    cpu->regs[5] = 30760ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x10e1a4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_10df60;
    goto L_10e0dc;
L_10e1b4:
    cpu->regs[26] = cpu->tls_ptr;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x10e1ccULL; PB_CALL(13, cpu, tlb, cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    PB_LDR(cpu->regs[27], (cpu->regs[26] + cpu->regs[0]));
    if (FLAG_NE) goto L_10debc;
L_10e1d8:
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 120));
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_10ded0;
L_10e1e8:
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
    goto L_10ded0;
L_10e1f0:
    cpu->regs[30] = PB_BASE + 0x10e1f4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_10e1f4:
    cpu->regs[30] = PB_BASE + 0x10e1f8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10e00c;
L_10e200:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e214;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_10e2ac;
L_10e214:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e228;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_10e2b8;
L_10e228:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e23c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_10e2c4;
L_10e23c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e250;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_10e2d0;
L_10e250:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e264;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_10e2dc;
L_10e264:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x10e26cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10e278ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_10e07c;
L_10e27c:
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 8));
    if ((cpu->regs[28])==0) goto L_10e0e4;
    cpu->regs[28] = 0ULL;
    cpu->regs[23] = 0ULL;
    goto L_10e200;
L_10e290:
    cpu->regs[23] = 0ULL;
    goto L_10e200;
L_10e298:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10e2a8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x9b854ULL);
    goto L_10e07c;
L_10e2ac:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10e2b4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_10e214;
L_10e2b8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x10e2c0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_10e228;
L_10e2c4:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10e2ccULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_10e23c;
L_10e2d0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10e2d8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_10e250;
L_10e2dc:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10e2e4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_10e264;
L_10e2e8:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x10e2f8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_10e124;
    /* nop */
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
    if (FLAG_EQ) goto L_10e4d0;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e4e0;
L_10e338:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_10e3b0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[23], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[24], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x10e35cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e384;
L_10e364:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_10e3e4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(53ULL)));
    if (FLAG_EQ) goto L_10e408;
L_10e384:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[22] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_10e398:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_10e3b0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e3b8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e4a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_10e4bc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e3d8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10e364;
    goto L_10e384;
L_10e3e4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e3ecULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10e494;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(53ULL)));
    if (FLAG_NE) goto L_10e384;
L_10e408:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e418ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e518;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x10e42cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_10e4bc;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[21], (cpu->regs[0] + 28) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e444ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x10d8f0ULL);
    if ((cpu->regs[0])==0) goto L_10e50c;
L_10e448:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[5] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10e464ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1a66c0ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 3560ULL;
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x10e47cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1a6840ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e4ec;
L_10e484:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10e398;
L_10e494:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_10e384;
L_10e4a0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_10e398;
L_10e4bc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10e398;
L_10e4d0:
    cpu->regs[30] = PB_BASE + 0x10e4d4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10e338;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_10e4e0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[22] = 0ULL;
    goto L_10e398;
L_10e4ec:
    cpu->regs[30] = PB_BASE + 0x10e4f0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10e484;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_10e398;
L_10e50c:
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_10e448;
L_10e518:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_10e398;
L_10e52c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_10e63c;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e64c;
L_10e560:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x10e570ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x107310ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10e5b0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e654;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e58cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])!=0) goto L_10e5d0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10e654;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x10e5a8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_10e5ec;
L_10e5ac:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_10e5b0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_10e5c0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10e5d0:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e5e0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x10d8f0ULL);
    if ((cpu->regs[0])==0) goto L_10e614;
    cpu->regs[20] = cpu->regs[0];
    goto L_10e5b0;
L_10e5ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10e5f4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x10e52cULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10e5ac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x10e608ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10e5ac;
    cpu->regs[20] = cpu->regs[22];
    goto L_10e5b0;
L_10e614:
    cpu->regs[30] = PB_BASE + 0x10e618ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10e5b0;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_10e630:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_10e5c0;
L_10e63c:
    cpu->regs[30] = PB_BASE + 0x10e640ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10e560;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_10e64c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10e630;
L_10e654:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10e630;
}
