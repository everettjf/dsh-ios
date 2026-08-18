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

void ft__Py_SourceAsString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 160ULL;
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 168));
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 0));
    PB_STR((SP + 88), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    PB_STR((cpu->regs[20] + 0), 0ULL);
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1d2384;
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[1] = SP;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | 2048ULL));
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1d2334ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d2408;
L_1d233c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d2344ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1d23d0;
L_1d2350:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d239c;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    SP = SP + 160ULL;
    return;
L_1d2384:
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[1] >> 27) & 1)) goto L_1d23a4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[19] = cpu->regs[19] + 32ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_1d233c;
L_1d239c:
    PB_STR((SP + 144), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x1d23a4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d23a4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d23b4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2410;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_1d248c;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3336));
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_1d233c;
L_1d23d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    cpu->regs[1] = cpu->regs[1] + 2816ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d23e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_1d2408;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d2408;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d2498;
L_1d2408:
    cpu->regs[19] = 0ULL;
    goto L_1d2350;
L_1d2410:
    PB_STR((SP + 144), cpu->regs[23]);
    cpu->regs[23] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d2428ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d2460;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x1d2438ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d2444ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11ec60ULL);
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 0));
    if ((cpu->regs[19])==0) goto L_1d24a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[19] = cpu->regs[19] + 32ULL;
    PB_LDR(cpu->regs[23], (SP + 144));
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_1d233c;
L_1d2460:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2784ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d2484ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[23], (SP + 144));
    goto L_1d2350;
L_1d248c:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 40));
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_1d233c;
L_1d2498:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d24a0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2350;
L_1d24a4:
    PB_LDR(cpu->regs[23], (SP + 144));
    cpu->regs[19] = 0ULL;
    goto L_1d2350;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 48));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 48), cpu->regs[1]);
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1d2524;
L_1d24d8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3776));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d24ecULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2570;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1d2548;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 112));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d250cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c4a70ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d2594;
L_1d2510:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1d2518:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d2524:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x291000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2864ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1d253cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d24d8;
    cpu->regs[0] = 0ULL;
    goto L_1d2518;
L_1d2548:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x291000ULL;
    cpu->regs[0] = cpu->regs[0] + 2864ULL;
    cpu->regs[30] = PB_BASE + 0x1d2568ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x23b310ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d2518;
L_1d2570:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x291000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[0] + 2864ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[30] = PB_BASE + 0x1d258cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x23b310ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d2518;
L_1d2594:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 112));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d25a8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1d25a8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d25b8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x97564ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d2510;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d2510;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d25d8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2510;
    /* nop */
L_1d25e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    if (!((cpu->regs[1] >> 0) & 1)) goto L_1d25ec;
    return;
L_1d25ec:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 1ULL));
    cpu->regs[29] = SP;
    PB_STRW((cpu->regs[0] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d2600ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x11ec60ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1d2620ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d25e0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (((cpu->regs[0] >> 1) & 1)) goto L_1d2638;
L_1d2628:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
L_1d2638:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[30] = PB_BASE + 0x1d2640ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1d2628;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_1d2660;
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1d2660:
    cpu->regs[0] = 0ULL;
    return;
    cpu->regs[0] = PB_BASE + 0x471000ULL;
    cpu->regs[2] = cpu->regs[0] + 64ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 752));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1d2688;
L_1d267c:
    cpu->regs[0] = cpu->regs[0] + 64ULL;
    cpu->regs[0] = cpu->regs[0] + 752ULL;
    return;
L_1d2688:
    PB_STRW((cpu->regs[2] + 752), cpu->regs[1]);
    goto L_1d267c;
}
