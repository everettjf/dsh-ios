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

void ft__PyArgv_AsWstrList(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 96ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    PB_STR((SP + 8), 0ULL); PB_STR((SP + 8) + 8, 0ULL);
    cpu->regs[23] = cpu->regs[8];
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_17b934;
    cpu->regs[0] = cpu->regs[2] << 3;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x17b810ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd7700ULL);
    PB_STR((SP + 16), cpu->regs[0]);
    cpu->regs[22] = SP;
    cpu->regs[19] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_17b850;
    goto L_17b8fc;
L_17b824:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[21] = cpu->regs[19] << 3;
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x17b838ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x17b960ULL);
    if ((cpu->regs[0])==0) goto L_17b8b0;
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_STR((cpu->regs[1] + cpu->regs[21]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STR((SP + 8), cpu->regs[2]);
L_17b850:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_GT) goto L_17b824;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x17b864ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x17c2e0ULL);
    PB_LDR(cpu->regs[0], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]); PB_STR((cpu->regs[24] + 0) + 8, cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
L_17b870:
    PB_STR((cpu->regs[23] + 0), 0ULL); PB_STR((cpu->regs[23] + 0) + 8, 0ULL);
    PB_STR((cpu->regs[23] + 16), 0ULL); PB_STR((cpu->regs[23] + 16) + 8, 0ULL);
L_17b878:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_17b8a8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_17b8a8:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x17b8b0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_17b8b0:
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x17b8b8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17c2e0ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_17b950;
    cpu->regs[0] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[0] + 2192ULL;
L_17b8cc:
    cpu->regs[2] = cpu->regs[23] + 4ULL;
    cpu->regs[1] = PB_BASE + 0x2b6000ULL;
    cpu->regs[1] = cpu->regs[1] + 1584ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 208ULL;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[2] + 0), 0ULL); PB_STR((cpu->regs[2] + 0) + 8, 0ULL);
    PB_STR((cpu->regs[23] + 20), 0ULL);
    PB_STR((cpu->regs[23] + 8), cpu->regs[1]); PB_STR((cpu->regs[23] + 8) + 8, cpu->regs[0]);
    PB_STRW((cpu->regs[23] + 28), 0ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_17b878;
L_17b8fc:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
L_17b900:
    cpu->regs[1] = cpu->regs[23] + 4ULL;
    cpu->regs[0] = PB_BASE + 0x2b6000ULL;
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    cpu->regs[2] = PB_BASE + 0x281000ULL;
    PB_STR((cpu->regs[1] + 0), 0ULL); PB_STR((cpu->regs[1] + 0) + 8, 0ULL);
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    cpu->regs[3] = 1ULL;
    PB_STR((cpu->regs[23] + 20), 0ULL);
    PB_STRW((cpu->regs[23] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[23] + 8), cpu->regs[0]); PB_STR((cpu->regs[23] + 8) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[23] + 28), 0ULL);
    goto L_17b878;
L_17b934:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = SP + 8ULL;
    PB_STR((SP + 8), cpu->regs[2]); PB_STR((SP + 8) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x17b948ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17d860ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_17b870;
    goto L_17b900;
L_17b950:
    cpu->regs[0] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[0] + 2608ULL;
    goto L_17b8cc;
    /* nop */
}
