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

void ft_PyModule_GetState(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[5] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_11d2c0;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 32));
    return;
L_11d2c0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x11d2ccULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11d2dc;
    cpu->regs[30] = PB_BASE + 0x11d2d4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 0ULL;
    goto L_11d2e0;
L_11d2dc:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 32));
L_11d2e0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x11d308ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1157e0ULL);
    if ((cpu->regs[0])==0) goto L_11d318;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_11d318:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_11d330;
L_11d330:
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_11d66c;
    cpu->regs[19] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x11d384ULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_11d744;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_11d698;
L_11d3a0:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 28272));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_11d574;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 28288));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11d574;
    cpu->regs[8] = 28264ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19] + cpu->regs[8];
    cpu->regs[3] = SP;
    cpu->regs[30] = PB_BASE + 0x11d3dcULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])!=0) goto L_11d5ac;
L_11d3e4:
    cpu->regs[19] = cpu->tls_ptr;
L_11d3e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x11d3f8ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_11d738;
L_11d404:
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_11d798;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2520));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 30768));
    PB_STR((SP + 80), cpu->regs[25]);
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_NE) goto L_11d618;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 30784));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11d618;
L_11d440:
    cpu->regs[4] = 30760ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = SP;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x11d454ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdd360ULL);
    cpu->regs[25] = SP;
    PB_LDR(cpu->regs[20], (SP + 0));
    if ((cpu->regs[20])==0) goto L_11d630;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_11d630;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_11d518;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_11d524;
L_11d48c:
    cpu->regs[1] = cpu->regs[19] + (8ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 576));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_NE) goto L_11d5e0;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 592));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11d5e0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[1] + 568ULL;
    cpu->regs[30] = PB_BASE + 0x11d4b8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[21], (SP + 0));
    if ((cpu->regs[21])==0) goto L_11d534;
L_11d4c0:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_11d6ac;
L_11d4c8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_11d4dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_11d788;
L_11d4dc:
    PB_LDR(cpu->regs[25], (SP + 80));
L_11d4e0:
    cpu->regs[0] = 0ULL;
L_11d4e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_11d750;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_11d518:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_11d48c;
L_11d524:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x11d534ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_11d534:
    cpu->regs[30] = PB_BASE + 0x11d538ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11d4c8;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_11d4c8;
    cpu->regs[30] = PB_BASE + 0x11d54cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x121ff0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11d70c;
L_11d550:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 2624ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11d570ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_11d72c;
L_11d574:
    cpu->regs[7] = 28264ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x11d580ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11d3e4;
    cpu->regs[6] = 28264ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19] + cpu->regs[6];
    cpu->regs[3] = SP;
    cpu->regs[30] = PB_BASE + 0x11d5a0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdd360ULL);
    cpu->regs[19] = cpu->tls_ptr;
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_11d3e8;
L_11d5ac:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x11d5b4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x120dccULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[22]))) & (((uint32_t)(cpu->regs[1]))), 0);
    if (FLAG_EQ) goto L_11d4e4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11d5d4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11d4e0;
    cpu->regs[30] = PB_BASE + 0x11d5dcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_11d4e0;
L_11d5e0:
    cpu->regs[2] = 33336ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x11d5ecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11d534;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[1] = 33336ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x11d60cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[21], (SP + 0));
    if ((cpu->regs[21])!=0) goto L_11d4c0;
    goto L_11d534;
L_11d618:
    cpu->regs[5] = 30760ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x11d624ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_11d440;
L_11d630:
    PB_LDR(cpu->regs[25], (SP + 80));
L_11d634:
    cpu->regs[30] = PB_BASE + 0x11d638ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] ^ 1ULL));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[22]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_EQ) goto L_11d4e0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 2848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11d668ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_11d4e0;
L_11d66c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11d67cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11d4e0;
    cpu->regs[30] = PB_BASE + 0x11d684ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_11d684:
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_11d3a0;
    cpu->regs[19] = cpu->tls_ptr;
L_11d698:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x11d6a8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_11d3e8;
L_11d6ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_11d6bc;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_11d6bc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11d6c4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x121ff0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11d550;
    cpu->regs[0] = 36384ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11d6d8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11d70c;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x11d6e8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x11e710ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_11d700;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_11d77c;
L_11d700:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11d70c;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_11d758;
L_11d70c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11d72cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
L_11d72c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11d734ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_11d4c8;
L_11d738:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_11d404;
    goto L_11d4e0;
L_11d744:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_11d684;
    goto L_11d4e0;
L_11d750:
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x11d758ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7c170ULL);
L_11d758:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 2720ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11d778ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_11d72c;
L_11d77c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11d784ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11d700;
L_11d788:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x11d790ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 80));
    goto L_11d4e0;
L_11d798:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x11d7a8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_11d634;
}
