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

void ft_PyUnicode_AsUTF8String(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x147310ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = 4611686018427387903ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_GT) goto L_1dd89c;
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[2] << 1;
    cpu->regs[30] = PB_BASE + 0x1dd6b4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1474c0ULL);
    cpu->regs[30] = PB_BASE + 0x1dd6b8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1474d0ULL);
    cpu->regs[4] = cpu->regs[19] - 1ULL;
    cpu->regs[3] = 0ULL;
    if ((cpu->regs[0])==0) goto L_1dd8a0;
L_1dd6c4:
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_LE) goto L_1dd854;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] & 7ULL; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1dd788;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_1dd76c;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_1dd758;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_1dd744;
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_EQ) goto L_1dd730;
    FLAG_CMP(cpu->regs[1], 5ULL);
    if (FLAG_EQ) goto L_1dd71c;
    FLAG_CMP(cpu->regs[1], 6ULL);
    if (FLAG_NE) goto L_1dd884;
L_1dd708:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
L_1dd71c:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
L_1dd730:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
L_1dd744:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
L_1dd758:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
L_1dd76c:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_EQ) goto L_1dd854;
L_1dd788:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[5] = cpu->regs[3];
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STRB((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[6] = cpu->regs[0];
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[5] + 2ULL;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[5] + 3ULL;
    PB_STRB((cpu->regs[6] + 1), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[6] + 2ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[5] + 4ULL;
    PB_STRB((cpu->regs[6] + 2), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[6] + 3ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[5] + 5ULL;
    PB_STRB((cpu->regs[6] + 3), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[6] + 4ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[5] + 6ULL;
    PB_STRB((cpu->regs[6] + 4), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[6] + 5ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    cpu->regs[3] = cpu->regs[5] + 7ULL;
    PB_STRB((cpu->regs[6] + 5), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[6] + 6ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB((cpu->regs[6] + 6), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[6] + 7ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_NE) goto L_1dd788;
L_1dd854:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1dd860:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] >> 6));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] | 4294967232ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 63ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4294967168ULL));
    PB_STRB(cpu->regs[2], cpu->regs[5]); cpu->regs[2] += 2;
    PB_STRB((cpu->regs[0] + 1), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2];
    goto L_1dd6c4;
L_1dd884:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1dd860;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    goto L_1dd708;
L_1dd89c:
    cpu->regs[30] = PB_BASE + 0x1dd8a0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1dd8a0:
    cpu->regs[0] = 0ULL;
    goto L_1dd854;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = 32ULL;
L_1dd8bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1dd8c8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 536));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 540));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_1dd8f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x1dd8e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = 0ULL;
L_1dd8e4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1dd8f0:
    cpu->regs[1] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 4);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 24)); PB_LDR(cpu->regs[21], (cpu->regs[1] + 24) + 8);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1dd91c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STR((cpu->regs[1] + 24), 0ULL); PB_STR((cpu->regs[1] + 24) + 8, 0ULL);
    cpu->regs[1] = (uint64_t)(-(int64_t)cpu->regs[0]); FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 31ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 31ULL));
    cpu->regs[0] = ((uint32_t)((FLAG_LT) ? cpu->regs[0] : ((uint64_t)(-(int64_t)cpu->regs[1]))));
    PB_STRW((cpu->regs[19] + 536), cpu->regs[0]);
L_1dd91c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x1dd924ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x17faa0ULL);
    if ((cpu->regs[22])!=0) goto L_1dd934;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    goto L_1dd8e4;
L_1dd934:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1dd93cULL; PB_CALL(8, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dd954;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] - 1ULL)); FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_NE) goto L_1dd8bc;
    cpu->regs[0] = 0ULL;
    goto L_1dd8e4;
L_1dd954:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_1dd8e4;
}
