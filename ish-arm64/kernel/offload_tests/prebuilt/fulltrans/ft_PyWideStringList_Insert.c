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

void ft_PyWideStringList_Insert(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 9223372036854775807ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[8];
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_EQ) goto L_17c910;
    if (((cpu->regs[21] >> 63) & 1)) goto L_17c95c;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = (FLAG_LE) ? cpu->regs[22] : cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x17c8acULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x17c9c0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_17c90c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[22] + 1ULL;
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[30] = PB_BASE + 0x17c8c4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd77c8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_17c978;
    cpu->regs[26] = cpu->regs[25] << 3;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[25] << 3);
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_GT) goto L_17c944;
L_17c8dc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[23] + 0), 0ULL); PB_STR((cpu->regs[23] + 0) + 8, 0ULL);
    PB_STR((cpu->regs[19] + cpu->regs[26]), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]); PB_STR((cpu->regs[20] + 0) + 8, cpu->regs[19]);
    PB_STR((cpu->regs[23] + 16), 0ULL); PB_STR((cpu->regs[23] + 16) + 8, 0ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_17c8f8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_17c90c:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_17c910:
    cpu->regs[0] = PB_BASE + 0x2b6000ULL;
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    cpu->regs[2] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[23] + 4ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
L_17c928:
    PB_STR((cpu->regs[1] + 0), 0ULL); PB_STR((cpu->regs[1] + 0) + 8, 0ULL);
    cpu->regs[3] = 1ULL;
    PB_STR((cpu->regs[23] + 20), 0ULL);
    PB_STRW((cpu->regs[23] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[23] + 8), cpu->regs[0]); PB_STR((cpu->regs[23] + 8) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[23] + 28), 0ULL);
    goto L_17c8f8;
L_17c944:
    cpu->regs[2] = cpu->regs[22] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[26] + 8ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[30] = PB_BASE + 0x17c958ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b030ULL);
    goto L_17c8dc;
L_17c95c:
    cpu->regs[0] = PB_BASE + 0x2b6000ULL;
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    cpu->regs[2] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[8] + 4ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[2] = cpu->regs[2] + 2896ULL;
    goto L_17c928;
L_17c978:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x17c980ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[1] = cpu->regs[23] + 4ULL;
    cpu->regs[0] = PB_BASE + 0x2b6000ULL;
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[2] = PB_BASE + 0x281000ULL;
    PB_STR((cpu->regs[1] + 0), 0ULL); PB_STR((cpu->regs[1] + 0) + 8, 0ULL);
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    PB_STR((cpu->regs[23] + 20), 0ULL);
    PB_STRW((cpu->regs[23] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[23] + 8), cpu->regs[0]); PB_STR((cpu->regs[23] + 8) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[23] + 28), 0ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_17c8f8;
    /* nop */
    /* nop */
}
