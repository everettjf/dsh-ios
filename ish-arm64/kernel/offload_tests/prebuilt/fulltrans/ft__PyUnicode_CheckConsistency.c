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

void ft__PyUnicode_CheckConsistency(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 28) & 1)) goto L_92694;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1752ULL;
    cpu->regs[4] = 645ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92694ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92694:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 32));
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[4] & 96ULL;
    cpu->regs[5] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    FLAG_CMP(cpu->regs[2], 96ULL);
    if (FLAG_NE) goto L_926dc;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_928bc;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1824ULL;
    cpu->regs[4] = 651ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x926dcULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x924f8ULL);
L_926dc:
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] - 1ULL));
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_HI) { FLAG_CMP(cpu->regs[5], 4ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[7] = ((uint32_t)(cpu->regs[6] & 64ULL));
    cpu->regs[2] = (FLAG_NE) ? 1 : 0;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 1ULL));
    if (!((cpu->regs[6] >> 5) & 1)) goto L_9278c;
    cpu->regs[6] = cpu->regs[0] + 56ULL;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_9272c;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1856ULL;
    cpu->regs[4] = 659ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9272cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x924f8ULL);
L_9272c:
    if ((((uint32_t)(cpu->regs[7])))==0) goto L_92758;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1952ULL;
    cpu->regs[4] = 662ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92758ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92758:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[2], cpu->regs[6]);
    if (FLAG_NE) goto L_92884;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1976ULL;
    cpu->regs[4] = 663ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9278cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x924f8ULL);
L_9278c:
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 56));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_927bc;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1856ULL;
    cpu->regs[4] = 669ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x927bcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x924f8ULL);
L_927bc:
    if ((cpu->regs[6])!=0) goto L_927e8;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2000ULL;
    cpu->regs[4] = 673ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x927e8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x924f8ULL);
L_927e8:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[6], cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[7])))==0) goto L_92858;
    if (FLAG_EQ) goto L_92820;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2024ULL;
    cpu->regs[4] = 675ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92820ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92820:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 40));
    FLAG_CMP(cpu->regs[6], cpu->regs[2]);
    if (FLAG_EQ) goto L_928bc;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2048ULL;
    cpu->regs[4] = 676ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92858ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92858:
    if (FLAG_NE) goto L_92884;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 1976ULL;
    cpu->regs[4] = 679ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92884ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92884:
    if ((cpu->regs[2])!=0) goto L_928bc;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 40));
    if ((cpu->regs[0])==0) goto L_928bc;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2088ULL;
    cpu->regs[4] = 684ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x928bcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x924f8ULL);
L_928bc:
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_92ad0;
    if (!((cpu->regs[4] >> 5) & 1)) goto L_928d8;
    FLAG_CMP((((uint32_t)(cpu->regs[4]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[3] + 40ULL;
    cpu->regs[1] = cpu->regs[3] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_928dc;
L_928d8:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 56));
L_928dc:
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[3] + 16));
    cpu->regs[2] = 0ULL;
L_928e8:
    FLAG_CMP(cpu->regs[6], cpu->regs[2]);
    if (FLAG_LE) goto L_92908;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x928f8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[4] = (FLAG_HS) ? cpu->regs[4] : cpu->regs[0];
    goto L_928e8;
L_92908:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_929b4;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 32));
    if (((cpu->regs[0] >> 6) & 1)) goto L_92980;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_9294c;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2120ULL;
    cpu->regs[4] = 703ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9294cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x924f8ULL);
L_9294c:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_92a94;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2136ULL;
    cpu->regs[4] = 704ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92980ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92980:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_92a94;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2152ULL;
    cpu->regs[4] = 707ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x929b4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x924f8ULL);
L_929b4:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    cpu->regs[0] = 65535ULL;
    if (FLAG_NE) goto L_92a28;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_929f4;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2168ULL;
    cpu->regs[4] = 710ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x929f4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x924f8ULL);
L_929f4:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LS) goto L_92a94;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    cpu->regs[4] = 711ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92a28ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92a28:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_92a5c;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2216ULL;
    cpu->regs[4] = 714ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92a5cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92a5c:
    cpu->regs[0] = 1114111ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LS) goto L_92a94;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2240ULL;
    cpu->regs[4] = 715ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92a94ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92a94:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x92aa0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x12b440ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_92ad0;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[5] + 1040ULL;
    cpu->regs[3] = cpu->regs[3] + 144ULL;
    cpu->regs[2] = cpu->regs[2] + 2264ULL;
    cpu->regs[4] = 717ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92ad0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92ad0:
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
