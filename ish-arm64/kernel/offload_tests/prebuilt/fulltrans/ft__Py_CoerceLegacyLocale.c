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

void ft__Py_CoerceLegacyLocale(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x90440ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7b8d0ULL);
    cpu->regs[30] = PB_BASE + 0x90444ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x17b700ULL);
    if ((cpu->regs[0])==0) goto L_9054c;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[0] + 2944ULL;
    cpu->regs[30] = PB_BASE + 0x90458ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c010ULL);
    if ((cpu->regs[0])==0) goto L_90474;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_90474;
L_90464:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x90470ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b8d0ULL);
    goto L_9053c;
L_90474:
    cpu->regs[19] = PB_BASE + 0x51d000ULL;
    cpu->regs[19] = cpu->regs[19] + 3600ULL;
    cpu->regs[19] = cpu->regs[19] + 456ULL;
L_90480:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[1])==0) goto L_90464;
    cpu->regs[30] = PB_BASE + 0x90490ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7b8d0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 14ULL;
    if ((cpu->regs[1])==0) goto L_90534;
    cpu->regs[30] = PB_BASE + 0x904a0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7af20ULL);
    if ((cpu->regs[0])==0) goto L_904ac;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_904b8;
L_904ac:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x904b4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x17b780ULL);
    goto L_90534;
L_904b8:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 0));
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x904c4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x17b780ULL);
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 152ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x904d8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b1f0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_90500;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = 51ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 680ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x904fcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b510ULL);
    goto L_9053c;
L_90500:
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_90524;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    cpu->regs[1] = PB_BASE + 0x2b9000ULL;
    cpu->regs[1] = cpu->regs[1] + 2352ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 752ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x90524ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b6e0ULL);
L_90524:
    cpu->regs[0] = 6ULL;
    cpu->regs[19] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x90530ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x17b780ULL);
    goto L_90540;
L_90534:
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    goto L_90480;
L_9053c:
    cpu->regs[19] = 0ULL;
L_90540:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x90548ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_90550;
L_9054c:
    cpu->regs[19] = 0ULL;
L_90550:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
