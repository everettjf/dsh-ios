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

void ft_PyNumber_InPlaceAnd(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = PB_BASE + 0x294000ULL;
    cpu->regs[3] = 104ULL;
    cpu->regs[4] = cpu->regs[4] + 3776ULL;
    cpu->regs[2] = 208ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x12bc80ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    PB_STR((SP + 48), cpu->regs[19]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[5], 1ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    if (FLAG_NE) goto L_1f7398;
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f7398;
L_1f7320:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f732cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d4500ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f73cc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3752));
    cpu->regs[30] = PB_BASE + 0x1f7340ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f73cc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1f7358;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1f7358:
    PB_STR((cpu->regs[5] + 16), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1f7364ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd9444ULL);
L_1f7364:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f7394;
    PB_LDR(cpu->regs[19], (SP + 48));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1f7394:
    cpu->regs[30] = PB_BASE + 0x1f7398ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f7398:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[6] = 1ULL;
    cpu->regs[4] = cpu->regs[4] + 3328ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f73c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f7320;
L_1f73cc:
    cpu->regs[5] = 0ULL;
    goto L_1f7364;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 30064ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[1] = SP;
    cpu->regs[2] = 1ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1f7428ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x152e40ULL);
    if ((cpu->regs[0])==0) goto L_1f7504;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1f7434ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1f74a4;
L_1f7440:
    if ((cpu->regs[19])==0) goto L_1f7504;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_1f74d8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2584));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1f7468ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1f74bc;
L_1f7474:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f74d4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1f74a4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1f7440;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f74b8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f7440;
L_1f74bc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1f7474;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f74d0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f7474;
L_1f74d4:
    cpu->regs[30] = PB_BASE + 0x1f74d8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f74d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f74ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f750c;
L_1f74ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3824ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f7504ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1f7504:
    cpu->regs[20] = 18446744073709551615ULL;
    goto L_1f7474;
L_1f750c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f7514ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f74ec;
    /* nop */
    /* nop */
}
