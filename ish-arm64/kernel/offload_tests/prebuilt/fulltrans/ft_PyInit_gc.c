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

void ft_PyInit_gc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[0] + 272ULL;
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x7f434ULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1864ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 16));
    cpu->regs[20] = cpu->regs[20] + 112ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 208));
    cpu->regs[30] = PB_BASE + 0x7f454ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1a3300ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7f460;
L_7f458:
    cpu->regs[0] = 4294967295ULL;
    goto L_7f4f0;
L_7f460:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 216));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1872ULL;
    cpu->regs[30] = PB_BASE + 0x7f474ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1a3300ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f458;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1888ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7f48cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f458;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1904ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x7f4a4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f458;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1928ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x7f4bcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f458;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    cpu->regs[2] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x7f4d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f458;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[2] = 38ULL;
    cpu->regs[1] = cpu->regs[1] + 1968ULL;
    cpu->regs[30] = PB_BASE + 0x7f4ecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1c1904ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_7f4f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 176ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_STR((SP + 160), cpu->regs[27]);
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 72), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])==0) goto L_7f548;
    PB_LDR(cpu->regs[23], (cpu->regs[3] + 16));
    goto L_7f54c;
L_7f548:
    cpu->regs[23] = 0ULL;
L_7f54c:
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[23] = cpu->regs[23] + cpu->regs[1];
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_7f568;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_7f594;
L_7f568:
    cpu->regs[2] = SP + 32ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[4] = cpu->regs[4] + 1688ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7f590ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_7f9c0;
L_7f594:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    if ((cpu->regs[23])==0) goto L_7f6e8;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    if ((cpu->regs[19])==0) goto L_7f5b4;
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_NE) goto L_7f5b8;
    goto L_7f608;
L_7f5b4:
    cpu->regs[19] = cpu->regs[22];
L_7f5b8:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    if ((cpu->regs[20])==0) goto L_7f5cc;
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_EQ) goto L_7f61c;
    goto L_7f5d4;
L_7f5cc:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_7f5d4:
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    if ((cpu->regs[24])==0) goto L_7f5e4;
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_EQ) goto L_7f630;
L_7f5e4:
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 24));
    if ((cpu->regs[26])==0) goto L_7f5f8;
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_NE) goto L_7f600;
    goto L_7f640;
L_7f5f8:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2760));
L_7f600:
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 32));
    goto L_7f648;
L_7f608:
    cpu->regs[23] = cpu->regs[22];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[20] = cpu->regs[22];
    cpu->regs[24] = 0ULL;
    goto L_7f648;
L_7f61c:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[24] = 0ULL;
    cpu->regs[26] = cpu->regs[23];
    goto L_7f648;
L_7f630:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[26] = cpu->regs[23];
    goto L_7f648;
L_7f640:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
L_7f648:
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_EQ) goto L_7f67c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_7f67c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 2032ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7f678ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_7f9c0;
L_7f67c:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_EQ) goto L_7f6b0;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_7f6b0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 2096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7f6acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_7f9c0;
L_7f6b0:
    if ((cpu->regs[24])==0) goto L_7f6fc;
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_EQ) goto L_7f6fc;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_7f6fc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 2160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7f6e4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_7f9c0;
L_7f6e8:
    cpu->regs[23] = cpu->regs[22];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[20] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[22];
    cpu->regs[24] = 0ULL;
L_7f6fc:
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 120));
    if ((cpu->regs[25])==0) goto L_7f730;
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_NE) goto L_7f718;
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_7f718;
    if ((cpu->regs[24])==0) goto L_7f75c;
L_7f718:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 192));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2224ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x7f72cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_7f9c0;
L_7f730:
    if ((cpu->regs[24])==0) goto L_7f760;
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_EQ) goto L_7f760;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7f744ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7f9c0;
    cpu->regs[30] = PB_BASE + 0x7f750ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d6ba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7f760;
    goto L_7f9c0;
L_7f75c:
    cpu->regs[25] = 0ULL;
L_7f760:
    PB_LDRB(cpu->regs[1], (cpu->regs[21] + 88));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7f76cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7fa04ULL);
    cpu->regs[26] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7f9c0;
    PB_LDRB(cpu->regs[1], (cpu->regs[21] + 89));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x7f784ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7fa04ULL);
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7f9c0;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2248));
    cpu->regs[4] = 44840ULL;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[27] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 24), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x7f7b4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_7f9c0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7f7d0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7f7d0;
    cpu->regs[30] = PB_BASE + 0x7f7d0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7f7d0:
    PB_STR((cpu->regs[21] + 160), 0ULL);
    if ((cpu->regs[24])!=0) goto L_7f7e4;
L_7f7d8:
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_EQ) goto L_7f7fc;
    goto L_7f840;
L_7f7e4:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7f7f0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d6c20ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7f7d8;
    goto L_7f9c0;
L_7f7fc:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_NE) goto L_7f81c;
    if ((cpu->regs[24])!=0) goto L_7f81c;
L_7f808:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STRB((cpu->regs[21] + 88), cpu->regs[26]);
    PB_STRB((cpu->regs[21] + 89), cpu->regs[23]);
    goto L_7f9c4;
L_7f81c:
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 40));
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_NE) goto L_7f82c;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 72));
L_7f82c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7f884;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_7f884;
L_7f840:
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 96ULL;
    cpu->regs[30] = PB_BASE + 0x7f850ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7f864;
    cpu->regs[30] = PB_BASE + 0x7f858ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x21720cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7f874;
    goto L_7f9c0;
L_7f864:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7f874;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_7f874:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_NE) goto L_7f884;
    cpu->regs[0] = 58200ULL;
    cpu->regs[20] = cpu->regs[27] + cpu->regs[0];
L_7f884:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7f894;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_7f894:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7f89cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7f91c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7f8acULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7f91c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 888ULL;
    cpu->regs[30] = PB_BASE + 0x7f8c4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d6a40ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7f91c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7f8dcULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d6cf0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7f8ec;
L_7f8e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7f908;
    goto L_7f91c;
L_7f8ec:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7f8fcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d6fa8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7f958;
    goto L_7f8e0;
L_7f908:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7f91c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7f91cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7f91c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f938;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7f938;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7f938ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7f938:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7f9c0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7f9c0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7f954ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7f9c0;
L_7f958:
    if (((cpu->regs[1] >> 31) & 1)) goto L_7f970;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7f970;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7f970ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7f970:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[21] + 40), cpu->regs[19]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_7f990;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7f990;
    cpu->regs[30] = PB_BASE + 0x7f990ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7f990:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[21] + 72), cpu->regs[20]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_7f9b0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7f9b0;
    cpu->regs[30] = PB_BASE + 0x7f9b0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7f9b0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7f9b8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d72e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7f808;
L_7f9c0:
    cpu->regs[0] = 0ULL;
L_7f9c4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_7f9e4;
    cpu->regs[30] = PB_BASE + 0x7f9e4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7f9e4:
    PB_LDR(cpu->regs[27], (SP + 160));
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    SP = SP + 176ULL;
    return;
L_7fa04:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_7fa4c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x7fa20ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7fa34;
    cpu->regs[30] = PB_BASE + 0x7fa30ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7fa40;
L_7fa34:
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    goto L_7fa44;
L_7fa40:
    cpu->regs[0] = cpu->regs[3];
L_7fa44:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_7fa4c:
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    return;
}
