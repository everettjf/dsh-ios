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

void ft__PyModule_Add(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1ab4e4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1a3300ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ab4f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 64));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[21] = ((uint32_t)(cpu->regs[2] & 16777216ULL));
    if (((cpu->regs[2] >> 24) & 1)) goto L_1ab5fc;
L_1ab52c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((cpu->regs[1])==0) goto L_1ab540;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab53cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1ab628ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab5b0;
L_1ab540:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[1])==0) goto L_1ab554;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab550ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ab628ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab5b0;
L_1ab554:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    if ((cpu->regs[1])!=0) goto L_1ab5b8;
L_1ab55c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    if ((cpu->regs[1])!=0) goto L_1ab5d0;
L_1ab564:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_1ab578;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab574ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1ab628ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab5b0;
L_1ab578:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1ab5e8;
    if ((cpu->regs[20])!=0) goto L_1ab594;
L_1ab580:
    cpu->regs[0] = 1ULL;
L_1ab584:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1ab594:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab5a0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1f6b90ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ab580;
L_1ab5a4:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[22] + 72), cpu->regs[0]);
L_1ab5b0:
    cpu->regs[0] = 0ULL;
    goto L_1ab584;
L_1ab5b8:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_1ab55c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab5c8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ab55c;
    goto L_1ab5a4;
L_1ab5d0:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_1ab564;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab5e0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ab564;
    goto L_1ab5a4;
L_1ab5e8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab5f0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab5a4;
    if ((cpu->regs[20])==0) goto L_1ab580;
    goto L_1ab594;
L_1ab5fc:
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[1] + 64) + 4);
    cpu->regs[3] = cpu->regs[1];
    PB_LDRW(cpu->regs[6], (cpu->regs[1] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[1] + 72) + 4);
    cpu->regs[8] = 34464ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 3ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x1ab620ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ab52c;
    goto L_1ab5a4;
L_1ab628:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
L_1ab648:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_GT) goto L_1ab668;
    cpu->regs[0] = 1ULL;
L_1ab658:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1ab668:
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])!=0) goto L_1ab680;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    goto L_1ab648;
L_1ab680:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ab688ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab698;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    goto L_1ab648;
L_1ab698:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 72));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[21] + 72), cpu->regs[1]);
    goto L_1ab658;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    if ((cpu->regs[1])==0) goto L_1ab6cc;
    cpu->regs[30] = PB_BASE + 0x1ab6c8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1ab784ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab77c;
L_1ab6cc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[1])==0) goto L_1ab6e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ab6dcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1ab784ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab77c;
L_1ab6e0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_1ab6f4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ab6f0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1ab784ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab77c;
L_1ab6f4:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 16));
    if ((cpu->regs[6])!=0) goto L_1ab748;
L_1ab6fc:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 40));
    if ((cpu->regs[6])!=0) goto L_1ab714;
L_1ab704:
    cpu->regs[0] = 1ULL;
L_1ab708:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1ab714:
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 0));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[2] = 4ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 24)); PB_LDRW(cpu->regs[5], (cpu->regs[6] + 24) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[6] + 32)); PB_LDRW(cpu->regs[7], (cpu->regs[6] + 32) + 4);
    cpu->regs[30] = PB_BASE + 0x1ab730ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab77c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 2ULL));
    PB_STRB((cpu->regs[1] + 80), cpu->regs[0]);
    goto L_1ab704;
L_1ab748:
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 0));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[2] = 4ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 24)); PB_LDRW(cpu->regs[5], (cpu->regs[6] + 24) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[6] + 32)); PB_LDRW(cpu->regs[7], (cpu->regs[6] + 32) + 4);
    cpu->regs[30] = PB_BASE + 0x1ab764ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ab77c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 1ULL));
    PB_STRB((cpu->regs[1] + 80), cpu->regs[0]);
    goto L_1ab6fc;
L_1ab77c:
    cpu->regs[0] = 0ULL;
    goto L_1ab708;
L_1ab784:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
L_1ab7a0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_GT) goto L_1ab7c4;
    cpu->regs[0] = 1ULL;
L_1ab7b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1ab7c4:
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[6], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[2] = 4ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 0));
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 24)); PB_LDRW(cpu->regs[5], (cpu->regs[6] + 24) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[6] + 32)); PB_LDRW(cpu->regs[7], (cpu->regs[6] + 32) + 4);
    cpu->regs[30] = PB_BASE + 0x1ab7ecULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ab7a0;
    goto L_1ab7b4;
    /* nop */
    /* nop */
    /* nop */
}
