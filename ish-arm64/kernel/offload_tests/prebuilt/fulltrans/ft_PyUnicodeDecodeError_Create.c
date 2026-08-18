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

void ft_PyUnicodeDecodeError_Create(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 3656));
    cpu->regs[9] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[8] = cpu->regs[3];
    cpu->regs[6] = cpu->regs[4];
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[7] + 0));
    cpu->regs[4] = cpu->regs[9];
    cpu->regs[7] = cpu->regs[5];
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[5] = cpu->regs[8];
    cpu->regs[1] = cpu->regs[1] + 104ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x1c1960ULL); return; };
    SP = SP - 144ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 88), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21e4f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x137bd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_21e660;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])!=0) goto L_21e6b8;
L_21e500:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])!=0) goto L_21e698;
L_21e508:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])!=0) goto L_21e678;
L_21e510:
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[6] = cpu->regs[19] + 104ULL;
    cpu->regs[1] = cpu->regs[1] + 864ULL;
    cpu->regs[5] = cpu->regs[19] + 96ULL;
    cpu->regs[4] = cpu->regs[19] + 88ULL;
    cpu->regs[3] = cpu->regs[19] + 80ULL;
    cpu->regs[2] = cpu->regs[19] + 72ULL;
    cpu->regs[30] = PB_BASE + 0x21e534ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21e668;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21e54c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_21e54c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_21e560;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_21e560:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 104));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_21e574;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_21e574:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 27) & 1)) goto L_21e5b8;
L_21e580:
    cpu->regs[0] = 0ULL;
L_21e584:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 88));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_21e5b0;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_21e5b0:
    PB_STR((SP + 128), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x21e5b8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_21e5b8:
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x21e5c8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21e600;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_STR((SP + 128), cpu->regs[21]);
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 80));
    cpu->regs[30] = PB_BASE + 0x21e5e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((cpu->regs[19] + 80), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21e5ecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x21e5f4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11ec60ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    PB_LDR(cpu->regs[21], (SP + 128));
    if ((cpu->regs[0])!=0) goto L_21e580;
L_21e600:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_21e620;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e620;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_21e6d8;
L_21e620:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_21e640;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e640;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_21e6e0;
L_21e640:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_21e660;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e660;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_21e6e8;
L_21e660:
    cpu->regs[0] = 4294967295ULL;
    goto L_21e584;
L_21e668:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[19] + 72), 0ULL); PB_STR((cpu->regs[19] + 72) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 104), 0ULL);
    goto L_21e584;
L_21e678:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e510;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21e510;
    cpu->regs[30] = PB_BASE + 0x21e694ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e510;
L_21e698:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e508;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21e508;
    cpu->regs[30] = PB_BASE + 0x21e6b4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e508;
L_21e6b8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e500;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21e500;
    cpu->regs[30] = PB_BASE + 0x21e6d4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e500;
L_21e6d8:
    cpu->regs[30] = PB_BASE + 0x21e6dcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e620;
L_21e6e0:
    cpu->regs[30] = PB_BASE + 0x21e6e4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e640;
L_21e6e8:
    cpu->regs[30] = PB_BASE + 0x21e6ecULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_21e584;
    /* nop */
    /* nop */
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x21e710ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x21e720ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
}
