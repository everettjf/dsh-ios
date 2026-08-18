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

void ft__PyDict_Next(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 168));
    if (!((cpu->regs[5] >> 29) & 1)) goto L_ed070;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 0));
    if ((cpu->regs[6])!=0) goto L_ed0e0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[5], 0ULL);
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 24));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[5], cpu->regs[7]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_ed070;
    PB_LDRB(cpu->regs[8], (cpu->regs[0] + 10));
    cpu->regs[6] = 1ULL;
    PB_LDRB(cpu->regs[9], (cpu->regs[0] + 9));
    cpu->regs[6] = cpu->regs[6] << (cpu->regs[9] & 63);
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_ed078;
    cpu->regs[6] = cpu->regs[6] + (cpu->regs[5] << 4);
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[6];
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 8));
    if ((cpu->regs[6])==0) goto L_ed0b8;
L_ed024:
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 0) + 8);
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 24));
    PB_STR((cpu->regs[1] + 0), cpu->regs[5]);
    if ((cpu->regs[2])==0) goto L_ed0a4;
L_ed038:
    PB_STR((cpu->regs[2] + 0), cpu->regs[6]);
    if ((cpu->regs[3])==0) goto L_ed0a8;
L_ed040:
    PB_STR((cpu->regs[3] + 0), cpu->regs[0]);
    if ((cpu->regs[4])!=0) goto L_ed0ac;
L_ed048:
    cpu->regs[0] = 1ULL;
L_ed04c:
    return;
L_ed050:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_LE) goto L_ed070;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 16));
    if ((cpu->regs[6])==0) goto L_ed050;
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_GT) goto L_ed090;
L_ed070:
    cpu->regs[0] = 0ULL;
L_ed074:
    return;
L_ed078:
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[5] << 1);
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[6] = cpu->regs[6] + (cpu->regs[8] << 3);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[6];
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 16));
    if ((cpu->regs[6])==0) goto L_ed050;
L_ed090:
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[6], (cpu->regs[0] + 0) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
L_ed098:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[5]);
    if ((cpu->regs[2])!=0) goto L_ed038;
L_ed0a4:
    if ((cpu->regs[3])!=0) goto L_ed040;
L_ed0a8:
    if ((cpu->regs[4])==0) goto L_ed048;
L_ed0ac:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[7]);
    goto L_ed04c;
L_ed0b8:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_LE) goto L_ed070;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 8));
    if ((cpu->regs[6])==0) goto L_ed0b8;
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_GT) goto L_ed024;
    cpu->regs[0] = 0ULL;
    goto L_ed074;
L_ed0e0:
    if (((cpu->regs[5] >> 63) & 1)) goto L_ed070;
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_LE) goto L_ed070;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[9] = cpu->regs[6] - cpu->regs[5];
    cpu->regs[8] = 1ULL;
    PB_LDRB(cpu->regs[10], (cpu->regs[0] + 9));
    PB_LDRB(cpu->regs[7], (cpu->regs[9] + -3));
    PB_LDRB(cpu->regs[9], (cpu->regs[9] + -3));
    cpu->regs[8] = cpu->regs[8] << (cpu->regs[10] & 63);
    cpu->regs[7] = cpu->regs[8] + (((cpu->regs[7]) & 0xffffffffULL) << 4);
    cpu->regs[7] = cpu->regs[0] + cpu->regs[7];
    PB_LDR(cpu->regs[0], (cpu->regs[6] + (cpu->regs[9] << 3)));
    PB_LDR(cpu->regs[6], (cpu->regs[7] + 32));
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 24));
    goto L_ed098;
}
