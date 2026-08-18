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

void ft__PyType_CheckConsistency(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xc75a0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x88eccULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c75d0;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3736ULL;
    cpu->regs[4] = 536ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc75d0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c75d0:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 168));
    if (!((cpu->regs[4] >> 12) & 1)) goto L_c7768;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_c7610;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3776ULL;
    cpu->regs[4] = 543ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc7610ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c7610:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c7648;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3816ULL;
    cpu->regs[4] = 544ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc7648ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c7648:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc7650ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x865c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c7680;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3856ULL;
    cpu->regs[4] = 546ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc7680ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c7680:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc7688ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_c76b8;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3880ULL;
    cpu->regs[4] = 547ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc76b8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c76b8:
    if (!((cpu->regs[4] >> 14) & 1)) goto L_c76ec;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 184));
    if ((cpu->regs[1])!=0) goto L_c76ec;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3920ULL;
    cpu->regs[4] = 552ULL;
    cpu->regs[30] = PB_BASE + 0xc76ecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c76ec:
    if (!((cpu->regs[4] >> 7) & 1)) goto L_c7768;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 312));
    if ((cpu->regs[1])==0) goto L_c7724;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3952ULL;
    cpu->regs[4] = 556ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc7724ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c7724:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 30912ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xc7738ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdd250ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c7768;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1560ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[2] = cpu->regs[2] + 3984ULL;
    cpu->regs[4] = 557ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc7768ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c7768:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
