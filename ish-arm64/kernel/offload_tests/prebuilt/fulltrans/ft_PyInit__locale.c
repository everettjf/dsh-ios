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

void ft_PyInit__locale(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[0] + 272ULL;
    cpu->regs[0] = cpu->regs[0] - 88ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP = SP - 112ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])!=0) goto L_2018c8;
    if (((cpu->regs[1] >> 63) & 1)) goto L_20190c;
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[22] = cpu->regs[1];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_2018d0;
L_201760:
    if ((cpu->regs[22])==0) goto L_2018b8;
L_201764:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 0));
    if ((cpu->regs[19])==0) goto L_20183c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_201818;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[30] = PB_BASE + 0x201784ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2017f8;
    cpu->regs[30] = PB_BASE + 0x201790ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_2017e0;
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_NE) goto L_20183c;
    cpu->regs[2] = 0ULL;
L_2017a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_201814;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 112ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x153800ULL); return; };
L_2017e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2017f8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2017f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_2018a0;
L_201814:
    cpu->regs[30] = PB_BASE + 0x201818ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_201818:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0x201838ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_2017f8;
L_20183c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_20187c;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[30] = PB_BASE + 0x201854ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2017f8;
    cpu->regs[30] = PB_BASE + 0x201860ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[2], (SP + 24)); PB_LDR(cpu->regs[1], (SP + 24) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_2017e0;
    if ((cpu->regs[19])!=0) goto L_2017a8;
    cpu->regs[19] = PB_BASE + 0x283000ULL;
    cpu->regs[19] = cpu->regs[19] + 1576ULL;
    goto L_2017a8;
L_20187c:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0x20189cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_2017f8;
L_2018a0:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_2018b8:
    cpu->regs[19] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 1576ULL;
    goto L_2017a8;
L_2018c8:
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 16));
    cpu->regs[22] = cpu->regs[1] + cpu->regs[22];
L_2018d0:
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x201900ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_201760;
    goto L_2017f8;
L_20190c:
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x20193cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2017f8;
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[22] = cpu->regs[1];
    goto L_201764;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x141d48ULL); return; };
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 152ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x201980ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 168ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x201998ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 176ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x2019b0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 192ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x2019c8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 208ULL;
    cpu->regs[2] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x2019e0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 224ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2019f8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2944ULL;
    cpu->regs[2] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x201a10ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[2] = 255ULL;
    cpu->regs[30] = PB_BASE + 0x201a28ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x201a34ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[1] + 256ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x201a4cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x191650ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_201afc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x201a5cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_201a70;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_201a70:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x201a78ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3768ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x201a90ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1abf4cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201ad8;
    cpu->regs[19] = PB_BASE + 0x3db000ULL;
    cpu->regs[19] = cpu->regs[19] + 2816ULL;
    cpu->regs[19] = cpu->regs[19] + 856ULL;
    goto L_201ab4;
L_201aa4:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 8),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x201ab0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_201afc;
L_201ab4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    if ((cpu->regs[1])!=0) goto L_201aa4;
    cpu->regs[30] = PB_BASE + 0x201ac4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
L_201acc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_201ad8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x201ae0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_201afc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_201afc;
    cpu->regs[30] = PB_BASE + 0x201afcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_201afc:
    cpu->regs[0] = 4294967295ULL;
    goto L_201acc;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_201b20;
    /* nop */
    /* nop */
    /* nop */
L_201b20:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x201b40ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22608));
    cpu->regs[30] = PB_BASE + 0x201b4cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_201b88;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_201bc4;
L_201b60:
    PB_STR((cpu->regs[5] + 16), cpu->regs[21]); PB_STR((cpu->regs[5] + 16) + 8, 0ULL);
    if ((cpu->regs[19])!=0) goto L_201b9c;
L_201b68:
    PB_STR((cpu->regs[5] + 32), cpu->regs[19]); PB_STR((cpu->regs[5] + 32) + 8, 0ULL);
    if ((cpu->regs[20])!=0) goto L_201bb0;
L_201b70:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[5] + 48), cpu->regs[20]);
    PB_STRH((cpu->regs[5] + 56), 0ULL);
    cpu->regs[0] = cpu->regs[5];
    PB_STRB((cpu->regs[5] + 58), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x201b88ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xd9444ULL);
L_201b88:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_201b9c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_201b68;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_201b68;
L_201bb0:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_201b70;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_201b70;
L_201bc4:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_201b60;
}
