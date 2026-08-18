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

void ft_PyWeakref_NewRef(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 208));
    if ((cpu->regs[2])==0) goto L_e1950;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e1824;
L_e173c:
    cpu->regs[20] = cpu->regs[3] + cpu->regs[2];
L_e1740:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((SP + 8), 0ULL); PB_STR((SP + 8) + 8, 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[19])==0) goto L_e17d4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    if ((cpu->regs[2])!=0) goto L_e17d4;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3288));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_NE) goto L_e1864;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    PB_STR((SP + 16), cpu->regs[19]);
    if ((cpu->regs[2])==0) goto L_e1790;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
    if ((cpu->regs[4])==0) goto L_e1868;
L_e1790:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e1890;
L_e1794:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e17a4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_e17a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_e1904;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_e17d4:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e1890;
L_e17d8:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0xe17e8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18d5f0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e190c;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe1804ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18d588ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    if ((cpu->regs[19])!=0) goto L_e1924;
    PB_STR((cpu->regs[21] + 40), 0ULL); PB_STR((cpu->regs[21] + 40) + 8, cpu->regs[22]);
    if ((cpu->regs[22])!=0) goto L_e18e4;
L_e1814:
    PB_STR((cpu->regs[20] + 0), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_e17a4;
L_e1824:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_e173c;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe1840ULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 360));
    cpu->regs[5] = 40ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[0] = 46016ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x5ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[2] * cpu->regs[5] + cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 16));
    cpu->regs[20] = cpu->regs[2] + cpu->regs[0];
    goto L_e1740;
L_e1864:
    cpu->regs[2] = cpu->regs[19];
L_e1868:
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 8));
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 4056));
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3632));
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[6], cpu->regs[4]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_e188c;
    PB_STR((SP + 8), cpu->regs[2]);
L_e188c:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e1918;
L_e1890:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xe1898ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d5f0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e1910;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[2] = SP + 8ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe18b8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18d588ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[1])!=0) goto L_e18c8;
    PB_LDR(cpu->regs[1], (SP + 16));
    if ((cpu->regs[1])==0) goto L_e18ec;
L_e18c8:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 48));
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]); PB_STR((cpu->regs[19] + 40) + 8, cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e18d8;
    PB_STR((cpu->regs[0] + 40), cpu->regs[19]);
L_e18d8:
    PB_STR((cpu->regs[1] + 48), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_e17a4;
L_e18e4:
    PB_STR((cpu->regs[22] + 40), cpu->regs[21]);
    goto L_e1814;
L_e18ec:
    PB_STR((cpu->regs[19] + 40), 0ULL); PB_STR((cpu->regs[19] + 40) + 8, cpu->regs[21]);
    if ((cpu->regs[21])==0) goto L_e18f8;
    PB_STR((cpu->regs[21] + 40), cpu->regs[19]);
L_e18f8:
    PB_STR((cpu->regs[20] + 0), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_e17a4;
L_e1904:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0xe190cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e190c:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
L_e1910:
    cpu->regs[19] = 0ULL;
    goto L_e17a4;
L_e1918:
    PB_LDR(cpu->regs[19], (SP + 16));
    if ((cpu->regs[19])!=0) goto L_e1794;
    goto L_e17d8;
L_e1924:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e1934;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_e1934:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e1948;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e1974;
L_e1948:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_e17a4;
L_e1950:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xe1970ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_e17a4;
L_e1974:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe197cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_e17a4;
}
