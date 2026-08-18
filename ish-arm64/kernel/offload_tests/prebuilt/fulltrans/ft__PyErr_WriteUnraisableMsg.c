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

void ft__PyErr_WriteUnraisableMsg(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 160ULL;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1fa250ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[19], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    if ((cpu->regs[19])==0) goto L_1fa520;
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[28] = SP + 48ULL;
    cpu->regs[3] = SP + 32ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[28];
    PB_STR((SP + 0), cpu->regs[3]); PB_STR((SP + 0) + 8, cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fa294ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1e6860ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[0], (SP + 32));
    if ((cpu->regs[23])==0) goto L_1fa5a0;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    if ((cpu->regs[0])==0) goto L_1fa4cc;
L_1fa2a8:
    PB_LDR(cpu->regs[3], (SP + 0)); PB_LDR(cpu->regs[2], (SP + 0) + 8);
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[30] = PB_BASE + 0x1fa2c0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1fa9c0ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[23]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1fa2f4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2432));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1fa2f4;
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fa2f0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x122464ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa6a4;
L_1fa2f4:
    if ((cpu->regs[20])!=0) goto L_1fa684;
L_1fa2f8:
    cpu->regs[0] = PB_BASE + 0x5ac000ULL;
    cpu->regs[0] = cpu->regs[0] + 3792ULL;
    PB_LDR(cpu->regs[25], (SP + 40)); PB_LDR(cpu->regs[24], (SP + 40) + 8);
    cpu->regs[0] = cpu->regs[0] + 1288ULL;
    cpu->regs[30] = PB_BASE + 0x1fa30cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe51acULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fa6e4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[24], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[24] : cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1fa510;
L_1fa330:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[25], 0ULL);
    PB_STR((cpu->regs[27] + 24), cpu->regs[0]);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[25] : cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1fa354;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1fa354:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[21], 0ULL);
    PB_STR((cpu->regs[27] + 32), cpu->regs[1]);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[21] : cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1fa378;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1fa378:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[20], 0ULL);
    PB_STR((cpu->regs[27] + 40), cpu->regs[0]);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1fa700;
L_1fa398:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[22], 0ULL);
    PB_STR((cpu->regs[27] + 48), cpu->regs[1]);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[22] : cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1fa3bc;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1fa3bc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[27] + 56), cpu->regs[0]);
    if ((cpu->regs[1])!=0) goto L_1fa6c0;
L_1fa3c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = 60168ULL;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1fa3e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fa648;
    PB_LDR(cpu->regs[26], (SP + 24));
    if ((cpu->regs[26])==0) goto L_1fa5f0;
    cpu->regs[2] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = cpu->regs[2] + 112ULL;
    cpu->regs[1] = cpu->regs[1] + 616ULL;
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fa410ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x181ea8ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa610;
    FLAG_CMP(cpu->regs[26], cpu->regs[23]);
    if (FLAG_EQ) goto L_1fa5d4;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1fa428ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1fa440;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1fa5c8;
L_1fa440:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1fa454;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1fa5bc;
L_1fa454:
    if ((cpu->regs[22])==0) goto L_1fa558;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1fa540;
L_1fa460:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    cpu->regs[23] = cpu->regs[20];
L_1fa468:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x1fa470ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x1fa478ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x1fa480ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1fa488ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1fa494ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1fa518;
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 160ULL;
    return;
L_1fa4cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fa4d4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x227188ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fa2a8;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fa4e8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x122448ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fa708;
L_1fa4f0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa2a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1fa2a8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fa50cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa2a8;
L_1fa510:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1fa330;
L_1fa518:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1fa520ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fa520:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 1248ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1fa540ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x91ebcULL);
L_1fa540:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1fa460;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1fa554ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa460;
L_1fa558:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[0] + 520ULL;
L_1fa560:
    cpu->regs[30] = PB_BASE + 0x1fa564ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fa570ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fa578ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1fa580ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fa588ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[3], (SP + 0)); PB_LDR(cpu->regs[2], (SP + 0) + 8);
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[22] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1fa59cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1e6860ULL);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
L_1fa5a0:
    cpu->regs[5] = cpu->regs[22];
    PB_LDR(cpu->regs[3], (SP + 32)); PB_LDR(cpu->regs[2], (SP + 32) + 8);
    cpu->regs[4] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fa5b8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1fb420ULL);
    goto L_1fa468;
L_1fa5bc:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1fa5c4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa454;
L_1fa5c8:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1fa5d0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa440;
L_1fa5d4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa5f0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1fa5f0;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1fa5f0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1fa5f0:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa604;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fa66c;
L_1fa604:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    cpu->regs[23] = cpu->regs[20];
    goto L_1fa5a0;
L_1fa610:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa624;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fa6f4;
L_1fa624:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa638;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fa6b4;
L_1fa638:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 560ULL;
    goto L_1fa560;
L_1fa648:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa65c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fa678;
L_1fa65c:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 520ULL;
    goto L_1fa560;
L_1fa66c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1fa674ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa604;
L_1fa678:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1fa680ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa65c;
L_1fa684:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[0] + 592ULL;
    cpu->regs[30] = PB_BASE + 0x1fa694ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1fa2f8;
    cpu->regs[30] = PB_BASE + 0x1fa6a0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1fa2f8;
L_1fa6a4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1fa6b0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1fa2f4;
L_1fa6b4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1fa6bcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa638;
L_1fa6c0:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    if ((cpu->regs[0])==0) goto L_1fa3c8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fa6e4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1fa6e4;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1fa6e4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1fa6e4:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[0] + 456ULL;
    goto L_1fa560;
L_1fa6f4:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1fa6fcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fa624;
L_1fa700:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1fa398;
L_1fa708:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1fa714ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1fa4f0;
    /* nop */
    /* nop */
}
