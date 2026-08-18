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

void ft__PyEval_SignalReceived(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 96));
    cpu->regs[4] = 1ULL;
    cpu->regs[3] = cpu->regs[1] + 1948ULL;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0] + 368ULL;
    cpu->regs[1] = cpu->regs[1] + 1944ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x182ec0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_820b4;
L_820a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x820a8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x13ae00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_820dc;
    goto L_820d4;
L_820b4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x291000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3752ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x820ccULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_820a0;
    goto L_820ec;
L_820d4:
    cpu->regs[30] = PB_BASE + 0x820d8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_820ec;
L_820dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3440));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x820ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x137ba0ULL);
L_820ec:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 2240ULL;
    goto L_82108;
L_82108:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 320ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[0] + 328ULL;
    cpu->regs[30] = PB_BASE + 0x82134ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_82154;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_82158;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_82158;
L_82154:
    cpu->regs[0] = 0ULL;
L_82158:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_82190;
    cpu->regs[30] = PB_BASE + 0x82190ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x94950ULL);
L_82190:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_821a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_821e4;
L_821a8:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x821b8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_821dc;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_821dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 53ULL;
    cpu->regs[30] = PB_BASE + 0x821d4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_821dc;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_821dc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_821e4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[1] = 0ULL;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x1db900ULL); return; };
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[1] + 2568ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 32));
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x8222cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_82284;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_82258;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_82258:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82260ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_82288;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_82288;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82280ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_82288;
L_82284:
    cpu->regs[20] = 0ULL;
L_82288:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x198620ULL); return; };
    SP = SP - 96ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_STR((SP + 80), cpu->regs[23]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_82300;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x822fcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_82314;
L_82300:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2752ULL;
    cpu->regs[30] = PB_BASE + 0x8230cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdea4cULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_8231c;
L_82314:
    cpu->regs[20] = 0ULL;
    goto L_824b8;
L_8231c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82324ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x213250ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_82358;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_824a0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = cpu->regs[1] + 2776ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x82354ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_824a0;
L_82358:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = 51144ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x82374ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_82394;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x8238cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_824a0;
    cpu->regs[30] = PB_BASE + 0x82394ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_82394:
    PB_LDR(cpu->regs[21], (SP + 16));
    if ((cpu->regs[21])!=0) goto L_823bc;
L_8239c:
    cpu->regs[0] = 50568ULL;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x823b0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_82408;
    goto L_824a0;
L_823bc:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2816ULL;
    cpu->regs[30] = PB_BASE + 0x823ccULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[2] >> 31) & 1)) goto L_823ec;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_823ec;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x823ecULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_823ec:
    if ((cpu->regs[22])==0) goto L_824a0;
    cpu->regs[0] = SP;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x823fcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x20c928ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])!=0) goto L_8239c;
    goto L_824a0;
L_82408:
    PB_LDR(cpu->regs[21], (SP + 8));
    if ((cpu->regs[21])!=0) goto L_82438;
L_82410:
    PB_LDR(cpu->regs[1], (SP + 0));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    cpu->regs[0] = cpu->regs[0] + 2832ULL;
    cpu->regs[30] = PB_BASE + 0x82424ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_82484;
    goto L_82494;
L_82438:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x82448ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[2] >> 31) & 1)) goto L_82468;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_82468;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x82468ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_82468:
    if ((cpu->regs[22])==0) goto L_824a0;
    cpu->regs[0] = SP;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x82478ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x20c928ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])!=0) goto L_82410;
    goto L_824a0;
L_82484:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_82494;
    cpu->regs[30] = PB_BASE + 0x82494ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_82494:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x8249cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x2153e0ULL);
    goto L_824b8;
L_824a0:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x824a8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x18d760ULL);
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_82314;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x824b4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x2153e0ULL);
    goto L_82314;
L_824b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_824d8;
    cpu->regs[30] = PB_BASE + 0x824d8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7c170ULL);
L_824d8:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_82524;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x82520ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_82564;
L_82524:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_82548;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x82544ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_82564;
L_82548:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = 51144ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    { PB_CALL(38, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
L_82564:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[3] = 51144ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3080));
    cpu->regs[30] = PB_BASE + 0x825bcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_825dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x825d4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_8269c;
    cpu->regs[30] = PB_BASE + 0x825dcULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_825dc:
    PB_LDR(cpu->regs[21], (SP + 0));
    if ((cpu->regs[21])!=0) goto L_8261c;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_826b4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 2864ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    SP = SP + 64ULL;
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_8261c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82624ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x213250ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_82650;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2872ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[30] = PB_BASE + 0x82640ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x8264cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x2153e0ULL);
    goto L_8267c;
L_82650:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_82678;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = cpu->regs[1] + 2776ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x82678ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x11f220ULL);
L_82678:
    cpu->regs[20] = 0ULL;
L_8267c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_826a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_826a0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x82698ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_826a0;
L_8269c:
    cpu->regs[20] = 0ULL;
L_826a0:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_826b8;
L_826b4:
    cpu->regs[30] = PB_BASE + 0x826b8ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x7c170ULL);
L_826b8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
}
