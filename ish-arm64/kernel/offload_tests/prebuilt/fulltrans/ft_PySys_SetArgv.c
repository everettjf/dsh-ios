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

void ft_PySys_SetArgv(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3304));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xb13e4ULL); return; };
    SP = SP - 80ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_STR((SP + 64), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_b16f0;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3408ULL;
    cpu->regs[30] = PB_BASE + 0xb16ecULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_b1808;
L_b16f0:
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xb16f8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1728;
    cpu->regs[30] = PB_BASE + 0xb1704ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b8b0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_b1734;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1728ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_b1728:
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_b17f8;
L_b1734:
    cpu->regs[19] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[0] = 2305843009213693951ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_LS) goto L_b1750;
L_b1748:
    cpu->regs[30] = PB_BASE + 0xb174cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_b1728;
L_b1750:
    cpu->regs[0] = cpu->regs[19] << 2;
    cpu->regs[30] = PB_BASE + 0xb1758ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1748;
    cpu->regs[30] = PB_BASE + 0xb1764ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    PB_STRW((cpu->regs[22] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xb177cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b5e0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(34ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_b17d4;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HI) goto L_b17ec;
    cpu->regs[19] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19] << 2;
    cpu->regs[30] = PB_BASE + 0xb17a8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])!=0) goto L_b17b4;
    cpu->regs[30] = PB_BASE + 0xb17b0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_b17e4;
L_b17b4:
    PB_STRW((cpu->regs[22] + 0), 0ULL);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xb17c8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b5e0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 0));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_b17ec;
L_b17d4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb17e4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_b17e4:
    cpu->regs[19] = 0ULL;
    goto L_b17f8;
L_b17ec:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb17f4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[19] = cpu->regs[0];
L_b17f8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1800ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1808ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_b1808:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b1828;
    cpu->regs[30] = PB_BASE + 0xb1828ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b1828:
    PB_LDR(cpu->regs[23], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3632));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_b1884;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_b18b0;
L_b1884:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[30] = PB_BASE + 0xb188cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b1898;
L_b1890:
    cpu->regs[22] = 0ULL;
    goto L_b19bc;
L_b1898:
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[21] = (FLAG_GT) ? cpu->regs[21] : cpu->regs[0];
L_b18b0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_b18cc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_b18f0;
L_b18cc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0xb18d4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b1890;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[20] = (FLAG_GT) ? cpu->regs[20] : cpu->regs[0];
L_b18f0:
    if ((cpu->regs[19])==0) goto L_b1934;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_b1910;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_b1934;
L_b1910:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xb1918ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b1890;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
L_b1934:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b1944;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_b1944:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b1954;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_b1954:
    if ((cpu->regs[19])==0) goto L_b1968;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b1968;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_b1968:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1978ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x83724ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b1998;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b1998;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1998ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1998:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b19b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b19b4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb19b4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b19b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb19bcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdce4cULL);
L_b19bc:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3632));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_b1a10;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_b1a3c;
L_b1a10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[30] = PB_BASE + 0xb1a18ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b1a24;
L_b1a1c:
    cpu->regs[22] = 0ULL;
    goto L_b1b48;
L_b1a24:
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[21] = (FLAG_GT) ? cpu->regs[21] : cpu->regs[0];
L_b1a3c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_b1a58;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_b1a7c;
L_b1a58:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0xb1a60ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b1a1c;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[20] = (FLAG_GT) ? cpu->regs[20] : cpu->regs[0];
L_b1a7c:
    if ((cpu->regs[19])==0) goto L_b1ac0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_b1a9c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_b1ac0;
L_b1a9c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xb1aa4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b1a1c;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
L_b1ac0:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b1ad0;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_b1ad0:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b1ae0;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_b1ae0:
    if ((cpu->regs[19])==0) goto L_b1af4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b1af4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_b1af4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1b04ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1f5d40ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b1b24;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b1b24;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1b24ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1b24:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b1b40;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b1b40;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1b40ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1b40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb1b48ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdce4cULL);
L_b1b48:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 224ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 208), cpu->regs[21]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 168), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_b1ba4;
L_b1b90:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[19], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_b1bc8;
    goto L_b1c34;
L_b1ba4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3416ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xb1bbcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b1b90;
L_b1bc0:
    cpu->regs[0] = 0ULL;
    goto L_b1d60;
L_b1bc8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_b1c34;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_b1be4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    if (((cpu->regs[1] >> 6) & 1)) goto L_b1c00;
L_b1be4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1bfcULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b1bc0;
L_b1c00:
    if (!((cpu->regs[0] >> 5) & 1)) goto L_b1c0c;
    cpu->regs[0] = cpu->regs[2] + 40ULL;
    goto L_b1c10;
L_b1c0c:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 56));
L_b1c10:
    if (!((cpu->regs[1] >> 5) & 1)) goto L_b1c1c;
    cpu->regs[1] = cpu->regs[19] + 40ULL;
    goto L_b1c20;
L_b1c1c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
L_b1c20:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    cpu->regs[30] = PB_BASE + 0xb1c2cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x880d8ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_b1d48;
L_b1c34:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xb1c3cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x141ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b1c74;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb1c48ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x141ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b1c74;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 3496ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[30] = PB_BASE + 0xb1c70ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b1bc0;
L_b1c74:
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb1c88ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x11e5ccULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b1bc0;
    PB_LDRW(cpu->regs[0], (SP + 44));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_b1cc0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2792));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3576ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1cb4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1cbcULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_b1bc0;
L_b1cc0:
    cpu->regs[21] = SP + 88ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb1cd4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11e5ccULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b1ce8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1ce4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_b1bc0;
L_b1ce8:
    PB_LDRW(cpu->regs[0], (SP + 124));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_b1d20;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2792));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3576ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1d0cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1d14ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1d1cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_b1bc0;
L_b1d20:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (SP + 88));
    PB_LDR(cpu->regs[3], (SP + 104));
    cpu->regs[30] = PB_BASE + 0xb1d34ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x880d8ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1d40ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1d48ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x11ec60ULL);
L_b1d48:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_b1d60:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_b1d80;
    cpu->regs[30] = PB_BASE + 0xb1d80ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b1d80:
    PB_LDR(cpu->regs[21], (SP + 208));
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    SP = SP + 224ULL;
    return;
    SP = SP - 144ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[4] = SP + 32ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = SP + 28ULL;
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0xb1de4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x22ee90ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b1df0;
L_b1de8:
    cpu->regs[0] = 0ULL;
    goto L_b203c;
L_b1df0:
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDRW(cpu->regs[1], (SP + 28));
    PB_STRW((SP + 12), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xb1e00ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1de8;
    cpu->regs[1] = 8ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xb1e14ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x7b8e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b1e24;
    cpu->regs[30] = PB_BASE + 0xb1e20ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_b2030;
L_b1e24:
    cpu->regs[24] = 8ULL;
    cpu->regs[23] = 64ULL;
    cpu->regs[28] = 2147483646ULL;
    cpu->regs[27] = 1073741823ULL;
    cpu->regs[26] = 1ULL;
L_b1e38:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1e40ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1fc0;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (((cpu->regs[1] >> 24) & 1)) goto L_b1e8c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3632ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1e6cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2024;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2024;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1e88ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b2024;
L_b1e8c:
    cpu->regs[30] = PB_BASE + 0xb1e90ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b1eb0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b1eb0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1eb0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1eb0:
    if (!((cpu->regs[20] >> 63) & 1)) goto L_b1ed8;
    cpu->regs[30] = PB_BASE + 0xb1eb8ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b2024;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3688ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1ed4ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b2024;
L_b1ed8:
    FLAG_CMP(cpu->regs[20], cpu->regs[28]);
    if (FLAG_LE) goto L_b1efc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3712ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb1ef8ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b2024;
L_b1efc:
    FLAG_CMP(cpu->regs[20], cpu->regs[23]);
    if (FLAG_LT) goto L_b1f9c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[20] + 1ULL));
L_b1f08:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[20], cpu->regs[23]);
    if (FLAG_LT) goto L_b1f24;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[27])));
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] << 1));
    cpu->regs[23] = (FLAG_LE) ? cpu->regs[23] : cpu->regs[0];
    goto L_b1f08;
L_b1f24:
    cpu->regs[21] = cpu->regs[23] & 63ULL;
    cpu->regs[1] = cpu->regs[1] >> 6;
    cpu->regs[21] = cpu->regs[21] + 63ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[21] = cpu->regs[1] + (cpu->regs[21] >> 6);
    cpu->regs[21] = ((cpu->regs[21] & 0xffffffffULL) << 3);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1f44ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x7b8e0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b1f54;
    cpu->regs[30] = PB_BASE + 0xb1f50ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_b2024;
L_b1f54:
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_HS) goto L_b1f6c;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[24];
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HS) goto L_b1f7c;
L_b1f68:
    __builtin_trap();
L_b1f6c:
    if (FLAG_LS) goto L_b1f7c;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[24];
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_LO) goto L_b1f68;
L_b1f7c:
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xb1f8cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[24] = cpu->regs[21];
    cpu->regs[19] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xb1f9cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x7bcf0ULL);
L_b1f9c:
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[20] >> 3);
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_HS) goto L_b1e38;
    cpu->regs[0] = cpu->regs[0] & 18446744073709551608ULL;
    cpu->regs[20] = cpu->regs[26] << (cpu->regs[20] & 63);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[20];
    PB_STR((cpu->regs[19] + cpu->regs[0]), cpu->regs[1]);
    goto L_b1e38;
L_b1fc0:
    cpu->regs[30] = PB_BASE + 0xb1fc4ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b2024;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b1fe4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b1fe4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1fe4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1fe4:
    PB_LDRW(cpu->regs[0], (SP + 12));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb1ff4ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x7b960ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b2010;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb200cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_b2024;
L_b2010:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb2018ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x7bcf0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_b203c;
L_b2024:
    if ((cpu->regs[19])==0) goto L_b2030;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb2030ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x7bcf0ULL);
L_b2030:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb2038ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_b1de8;
L_b203c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_b205c;
    cpu->regs[30] = PB_BASE + 0xb205cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b205c:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_NE) goto L_b20b0;
L_b2098:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xb20a0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b20d8;
    goto L_b20d0;
L_b20b0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 3736ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xb20c8ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b2098;
    goto L_b22a8;
L_b20d0:
    cpu->regs[30] = PB_BASE + 0xb20d4ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b22a8;
L_b20d8:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 8) + 8);
    cpu->regs[30] = PB_BASE + 0xb20e0ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b20f4;
    cpu->regs[30] = PB_BASE + 0xb20f0ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b22a8;
L_b20f4:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3776));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_b2124;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2120ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b22a8;
L_b2124:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb212cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b22a8;
    FLAG_CMP((((uint32_t)(cpu->regs[19]))) & (((uint32_t)(98304ULL))), 0);
    if (FLAG_EQ) goto L_b2164;
    cpu->regs[0] = 32784ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x1ULL & 0xffff) << 16);
    FLAG_CMP(((uint32_t)(((uint32_t)(cpu->regs[0] & ~(cpu->regs[19]))))), 0);
    if (FLAG_EQ) goto L_b2164;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3792ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2160ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b22a8;
L_b2164:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] & 4294868991ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(1023ULL)));
    if (FLAG_LS) goto L_b2190;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb218cULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b22a8;
L_b2190:
    cpu->regs[30] = PB_BASE + 0xb2194ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[21] + 176),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_b21c8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 120));
    cpu->regs[1] = cpu->regs[1] + 3880ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb21c4ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b22a8;
L_b21c8:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(5ULL)));
    if (FLAG_GT) goto L_b2204;
    cpu->regs[0] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_b2204;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2200ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b22a8;
L_b2204:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb220cULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x27964cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b22a8;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 168));
    cpu->regs[4] = 1ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] << (cpu->regs[20] & 63)));
L_b2224:
    PB_LDRB(cpu->regs[6], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[4] << (cpu->regs[0] & 63)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP((((uint32_t)(cpu->regs[6]))) & (((uint32_t)(cpu->regs[2]))), 0);
    if (FLAG_EQ) goto L_b223c;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[5]));
L_b223c:
    FLAG_CMP(cpu->regs[0], 10ULL);
    if (FLAG_NE) goto L_b2224;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_b22b0;
    cpu->regs[2] = ((uint32_t)((~cpu->regs[2])));
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 255ULL));
L_b2258:
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + cpu->regs[4]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] >> (cpu->regs[4] & 63)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 1ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & cpu->regs[0]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] << (cpu->regs[20] & 63)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | cpu->regs[0]));
    PB_STRB((cpu->regs[1] + cpu->regs[4]), cpu->regs[2]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[4], 10ULL);
    if (FLAG_NE) goto L_b2258;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 48));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 160));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_b2298;
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[21] + 160), cpu->regs[0]);
L_b2298:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb22a4ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1b8630ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b22b0;
L_b22a8:
    cpu->regs[0] = 0ULL;
    goto L_b22b8;
L_b22b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_b22b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_b22c8:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[29] = SP;
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[2];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xb22e8ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb2300ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x27a0e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b2314;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb2310ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x121f40ULL);
    goto L_b2338;
L_b2314:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b2338;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b2338;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xb2338ULL; PB_CALL(91, cpu, tlb, cpu->regs[1]);
L_b2338:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if ((cpu->regs[3])==0) goto L_b2360;
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + 24));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_b2370;
    goto L_b2378;
L_b2360:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[3] + (93ULL << 12);
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + 825));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_b2378;
L_b2370:
    cpu->regs[3] = 9ULL;
    goto L_b22c8;
L_b2378:
    cpu->regs[0] = 0ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[8] = cpu->regs[4];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    cpu->regs[7] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[4] = 4ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[5] = SP;
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, cpu->regs[8]);
    PB_STR((SP + 32), cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0xb23c0ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x279ad0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_b23e0;
    cpu->regs[30] = PB_BASE + 0xb23e0ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b23e0:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_b23ec:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[29] = SP;
    cpu->regs[2] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 96));
    PB_STR((cpu->regs[0] + 96), 0ULL);
    cpu->regs[4] = 4ULL;
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0xb2420ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x279ad0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b2434;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(95, cpu, tlb, PB_BASE + 0xdce4cULL); return; };
L_b2434:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), cpu->regs[20]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(96, cpu, tlb, PB_BASE + 0x18d760ULL); return; };
    SP = SP - 64ULL;
    cpu->regs[6] = cpu->regs[3];
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    cpu->regs[3] = SP;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 0));
    PB_STR((SP + 40), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, cpu->regs[6]);
    PB_STR((SP + 32), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0xb2480ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xb23ecULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b24a0;
    cpu->regs[30] = PB_BASE + 0xb24a0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b24a0:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_b24dc;
L_b24c4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xb24ccULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b2508;
    goto L_b2500;
L_b24dc:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3920ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xb24f4ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b24c4;
L_b24f8:
    cpu->regs[0] = 0ULL;
    goto L_b2590;
L_b2500:
    cpu->regs[30] = PB_BASE + 0xb2504ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b24f8;
L_b2508:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb2514ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b24f8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_b2540;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb253cULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b24f8;
L_b2540:
    cpu->regs[30] = PB_BASE + 0xb2544ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[1] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    cpu->regs[1] = cpu->regs[1] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 22424));
    if ((cpu->regs[0])==0) goto L_b2574;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2570ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b24f8;
L_b2574:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b2584;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_b2584:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[1] + 22424), cpu->regs[20]);
L_b2590:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_b25cc;
L_b25b4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xb25bcULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b25f4;
    goto L_b25ec;
L_b25cc:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3992ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xb25e4ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b25b4;
    goto L_b2694;
L_b25ec:
    cpu->regs[30] = PB_BASE + 0xb25f0ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b2694;
L_b25f4:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3776));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_b2628;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2624ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b2684;
L_b2628:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb2630ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b2684;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 168));
    if ((cpu->regs[3])==0) goto L_b2670;
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[19] = ((uint32_t)(cpu->regs[2] << (cpu->regs[19] & 63)));
L_b264c:
    PB_LDRB(cpu->regs[5], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] << (cpu->regs[0] & 63)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP((((uint32_t)(cpu->regs[5]))) & (((uint32_t)(cpu->regs[19]))), 0);
    if (FLAG_EQ) goto L_b2664;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[4]));
L_b2664:
    FLAG_CMP(cpu->regs[0], 10ULL);
    if (FLAG_NE) goto L_b264c;
    goto L_b2674;
L_b2670:
    cpu->regs[1] = 0ULL;
L_b2674:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(111, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_b2684:
    cpu->regs[30] = PB_BASE + 0xb2688ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_b2694;
    cpu->regs[1] = 4294967295ULL;
    goto L_b2674;
L_b2694:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2736));
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 4016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    { PB_CALL(113, cpu, tlb, PB_BASE + 0x11f220ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_HI) goto L_b26fc;
L_b26e8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_LE) goto L_b2720;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    goto L_b2724;
L_b26fc:
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 4072ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xb2714ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b26e8;
L_b2718:
    cpu->regs[19] = 0ULL;
    goto L_b27d8;
L_b2720:
    cpu->regs[21] = 0ULL;
L_b2724:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 80));
    if ((cpu->regs[1])==0) goto L_b2738;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    if ((cpu->regs[1])!=0) goto L_b2758;
L_b2738:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 4080ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2754ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b2718;
L_b2758:
    cpu->regs[30] = PB_BASE + 0xb275cULL; PB_CALL(116, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b2718;
    if ((cpu->regs[21])==0) goto L_b27d8;
    cpu->regs[0] = PB_BASE + 0x497000ULL;
    cpu->regs[0] = cpu->regs[0] + 1088ULL;
    cpu->regs[0] = cpu->regs[0] + 1288ULL;
    cpu->regs[30] = PB_BASE + 0xb2778ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b27b0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b2790;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_b2790:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[20] + 16), cpu->regs[19]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b27a4;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_b27a4:
    PB_STR((cpu->regs[20] + 24), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb27b0ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xd9444ULL);
L_b27b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b27c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_b27cc;
L_b27c4:
    cpu->regs[19] = cpu->regs[20];
    goto L_b27d8;
L_b27cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb27d4ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b27c4;
L_b27d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 144ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[24] = SP + 32ULL;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[2];
    cpu->regs[25] = cpu->regs[3];
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 1664));
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 32), 0ULL);
    cpu->regs[30] = PB_BASE + 0xb2848ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2870;
    PB_LDR(cpu->regs[20], (SP + 32));
    if ((cpu->regs[20])!=0) goto L_b2878;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2870ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_b2870:
    cpu->regs[27] = 1ULL;
    goto L_b2c94;
L_b2878:
    cpu->regs[19] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb288cULL; PB_CALL(122, cpu, tlb, cpu->regs[1]);
    cpu->regs[27] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[23] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[23] + 80ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0xb28a0ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b28b0;
L_b28a4:
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0xb28acULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_b2870;
L_b28b0:
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb28c0ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x268f8cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b28f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b28f4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb28f4ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b28f4:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1216));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb2904ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2870;
    PB_LDR(cpu->regs[20], (SP + 32));
    if ((cpu->regs[20])==0) goto L_b2944;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_b294c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2944;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2944;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2944ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2944:
    PB_STR((SP + 16), 0ULL);
    goto L_b29b4;
L_b294c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb295cULL; PB_CALL(129, cpu, tlb, cpu->regs[1]);
    cpu->regs[27] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[23] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xb296cULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2980ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x268f8cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b29b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b29b4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb29b4ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b29b4:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1616));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb29c4ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2870;
    PB_LDR(cpu->regs[20], (SP + 32));
    if ((cpu->regs[20])!=0) goto L_b29f0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb29ecULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b2870;
L_b29f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb2a00ULL; PB_CALL(135, cpu, tlb, cpu->regs[1]);
    cpu->regs[27] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[23] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xb2a10ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    cpu->regs[1] = SP + 12ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2a20ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x264d20ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2a54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2a54;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2a54ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2a54:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1304));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb2a64ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2870;
    PB_LDR(cpu->regs[20], (SP + 32));
    if ((cpu->regs[20])!=0) goto L_b2a90;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb2a8cULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b2870;
L_b2a90:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb2aa0ULL; PB_CALL(141, cpu, tlb, cpu->regs[1]);
    cpu->regs[27] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[23] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xb2ab0ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2ac0ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x264d20ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    cpu->regs[27] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[1] + 36), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_b28a4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2af8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2af8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2af8ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2af8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1392));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb2b08ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2870;
    PB_LDR(cpu->regs[20], (SP + 32));
    if ((cpu->regs[20])==0) goto L_b2b48;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_b2b54;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2b48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2b48;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2b48ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2b48:
    PB_LDRW(cpu->regs[0], (SP + 12));
    PB_STRW((SP + 4), cpu->regs[0]);
    goto L_b2bb8;
L_b2b54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb2b64ULL; PB_CALL(147, cpu, tlb, cpu->regs[1]);
    cpu->regs[28] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[23] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xb2b74ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2b84ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x264d20ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2bb8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2bb8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2bb8ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2bb8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1384));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb2bc8ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2870;
    PB_LDR(cpu->regs[20], (SP + 32));
    if ((cpu->regs[20])==0) goto L_b2c08;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_b2c14;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2c08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2c08;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2c08ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2c08:
    PB_LDRW(cpu->regs[0], (SP + 8));
    PB_STRW((SP + 0), cpu->regs[0]);
    goto L_b2c78;
L_b2c14:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb2c24ULL; PB_CALL(153, cpu, tlb, cpu->regs[1]);
    cpu->regs[21] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[23] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xb2c34ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2c44ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x264d20ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b28a4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 32), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b2c78;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b2c78;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb2c78ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b2c78:
    PB_LDR(cpu->regs[1], (SP + 16)); PB_LDR(cpu->regs[0], (SP + 16) + 8);
    cpu->regs[6] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (SP + 0)); PB_LDRW(cpu->regs[4], (SP + 0) + 4);
    PB_LDRW(cpu->regs[3], (SP + 8)); PB_LDRW(cpu->regs[2], (SP + 8) + 4);
    cpu->regs[30] = PB_BASE + 0xb2c8cULL; PB_CALL(157, cpu, tlb, PB_BASE + 0x19aa90ULL);
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_b28a4;
L_b2c94:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b2cb4;
    cpu->regs[30] = PB_BASE + 0xb2cb4ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b2cb4:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
}
