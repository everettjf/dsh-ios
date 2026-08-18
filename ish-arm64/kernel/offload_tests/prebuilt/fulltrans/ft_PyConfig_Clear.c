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

void ft_PyConfig_Clear(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    cpu->regs[30] = PB_BASE + 0x17d738ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 96), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 280));
    cpu->regs[30] = PB_BASE + 0x17d744ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 280), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 288));
    cpu->regs[30] = PB_BASE + 0x17d750ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 288), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 272));
    cpu->regs[30] = PB_BASE + 0x17d75cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 272), 0ULL);
    cpu->regs[0] = cpu->regs[19] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x17d768ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17c2e0ULL);
    cpu->regs[0] = cpu->regs[19] + 160ULL;
    cpu->regs[30] = PB_BASE + 0x17d770ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17c2e0ULL);
    cpu->regs[0] = cpu->regs[19] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x17d778ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x17c2e0ULL);
    cpu->regs[0] = cpu->regs[19] + 312ULL;
    cpu->regs[30] = PB_BASE + 0x17d780ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x17c2e0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 328));
    PB_STRW((cpu->regs[19] + 304), 0ULL);
    cpu->regs[30] = PB_BASE + 0x17d78cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 328), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 336));
    cpu->regs[30] = PB_BASE + 0x17d798ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 336), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 344));
    cpu->regs[30] = PB_BASE + 0x17d7a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 344), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 352));
    cpu->regs[30] = PB_BASE + 0x17d7b0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 352), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 360));
    cpu->regs[30] = PB_BASE + 0x17d7bcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 360), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 368));
    cpu->regs[30] = PB_BASE + 0x17d7c8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 368), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 376));
    cpu->regs[30] = PB_BASE + 0x17d7d4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 376), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 296));
    cpu->regs[30] = PB_BASE + 0x17d7e0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 296), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    cpu->regs[30] = PB_BASE + 0x17d7ecULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 80), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    cpu->regs[30] = PB_BASE + 0x17d7f8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 88), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 232));
    cpu->regs[30] = PB_BASE + 0x17d804ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 232), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 240));
    cpu->regs[30] = PB_BASE + 0x17d810ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 240), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 392));
    cpu->regs[30] = PB_BASE + 0x17d81cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 392), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 400));
    cpu->regs[30] = PB_BASE + 0x17d828ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 400), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 408));
    cpu->regs[30] = PB_BASE + 0x17d834ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 408), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 248));
    cpu->regs[30] = PB_BASE + 0x17d840ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 248), 0ULL);
    cpu->regs[0] = cpu->regs[19] + 112ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0x17c2e0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
}
