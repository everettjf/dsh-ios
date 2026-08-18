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

void ft_PyInit__symtable(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[0] + 272ULL;
    cpu->regs[0] = cpu->regs[0] + 2080ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[2] = 16ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3776ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x804a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_804b0;
L_804a8:
    cpu->regs[0] = 4294967295ULL;
    goto L_806d8;
L_804b0:
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3784ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x804c4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3800ULL;
    cpu->regs[2] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x804dcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x804f4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x8050cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    cpu->regs[2] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x80524ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[2] = 64ULL;
    cpu->regs[30] = PB_BASE + 0x8053cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3880ULL;
    cpu->regs[2] = 128ULL;
    cpu->regs[30] = PB_BASE + 0x80554ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3896ULL;
    cpu->regs[2] = 134ULL;
    cpu->regs[30] = PB_BASE + 0x8056cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3912ULL;
    cpu->regs[2] = 256ULL;
    cpu->regs[30] = PB_BASE + 0x80584ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3928ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x8059cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3944ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x805b4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x805ccULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3976ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x805e4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3992ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x805fcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4016ULL;
    cpu->regs[2] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x80614ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4032ULL;
    cpu->regs[2] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x8062cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4048ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x80644ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4056ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x8065cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4072ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x80674ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4088ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x8068cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 0ULL;
    cpu->regs[2] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x806a4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    cpu->regs[2] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x806bcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_804a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = 15ULL;
    cpu->regs[1] = cpu->regs[1] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x806d4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1c1904ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_806d8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
