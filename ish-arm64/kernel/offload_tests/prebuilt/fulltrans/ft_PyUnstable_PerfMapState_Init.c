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

void ft_PyUnstable_PerfMapState_Init(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 144ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9087cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7ae40ULL);
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = 99ULL;
    cpu->regs[0] = SP;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = cpu->regs[2] + 736ULL;
    cpu->regs[30] = PB_BASE + 0x90894ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[1] = 33857ULL;
    cpu->regs[0] = SP;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x8ULL & 0xffff) << 16);
    cpu->regs[2] = 384ULL;
    cpu->regs[30] = PB_BASE + 0x908a8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_908d8;
    cpu->regs[19] = PB_BASE + 0x5ad000ULL;
    cpu->regs[19] = cpu->regs[19] + 4048ULL;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29e000ULL;
    cpu->regs[1] = cpu->regs[1] + 488ULL;
    cpu->regs[30] = PB_BASE + 0x908c8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7ab40ULL);
    PB_STR((cpu->regs[19] + 240), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_908e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x908d8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7b860ULL);
L_908d8:
    cpu->regs[0] = 4294967295ULL;
    goto L_90900;
L_908e0:
    cpu->regs[30] = PB_BASE + 0x908e4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17aba0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_STR((cpu->regs[19] + 248), cpu->regs[1]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[1])!=0) goto L_90900;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 240));
    cpu->regs[30] = PB_BASE + 0x908fcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    cpu->regs[0] = 4294967294ULL;
L_90900:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_90920;
    cpu->regs[30] = PB_BASE + 0x90920ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_90920:
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
}
