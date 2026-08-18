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

void ft__PyInterpreterState_SetNotRunningMain(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_STR((cpu->regs[0] + 22800), 0ULL);
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = 59144ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1e93c0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5800ULL);
    if ((cpu->regs[0])!=0) goto L_1e93fc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 96));
    if ((cpu->regs[1])!=0) goto L_1e9470;
L_1e93cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e9494;
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1e93fc:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = SP;
    cpu->regs[0] = 36104ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e941cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1e94ac;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1e9498;
L_1e9428:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e93cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e93cc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e9494;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1e9470:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_1e93cc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_1e94b8;
L_1e9494:
    cpu->regs[30] = PB_BASE + 0x1e9498ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e9498:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e9428;
    cpu->regs[30] = PB_BASE + 0x1e94a8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e9428;
L_1e94ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e94b4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1e9428;
L_1e94b8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x1fa20cULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1e94e4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1dd564ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e94f8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e94f8:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[1] = 952ULL;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 664ULL;
    cpu->regs[30] = PB_BASE + 0x1e9510ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e9518ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xcd394ULL); return; };
    SP = SP - 144ULL;
    cpu->regs[3] = 6000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_1e9770;
L_1e956c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e97f4;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[0] = 8ULL;
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e9584ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e97d4;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1e97c0;
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[28] = SP + 24ULL;
    cpu->regs[0] = SP + 32ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[26] = 1ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[24] = 6000ULL;
L_1e95b4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_1e97b4;
L_1e95c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9604;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 62ULL;
    cpu->regs[30] = PB_BASE + 0x1e95e0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e964c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9604;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e95fcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x19eda0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e96ac;
L_1e9604:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1e960c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e9620ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e9758;
L_1e9628:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_1e96d0;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1e9628;
L_1e964c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[2] = cpu->regs[28];
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x1e965cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1e34c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e978c;
    PB_LDR(cpu->regs[2], (SP + 24)); PB_LDR(cpu->regs[1], (SP + 24) + 8);
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9674ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1a1860ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e978c;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1e9688ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e9778;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[23];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 20)); PB_LDRW(cpu->regs[3], (cpu->regs[27] + 20) + 4);
    cpu->regs[1] = 0ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[27] + 28) + 4);
    cpu->regs[30] = PB_BASE + 0x1e96a4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e978c;
L_1e96ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(cpu->regs[26], cpu->regs[20]);
    if (FLAG_EQ) goto L_1e9728;
L_1e96c0:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[22] + (cpu->regs[20] << 3)), cpu->regs[23]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_1e95b4;
L_1e96d0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e96d8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_1e96d8:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1e96ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e9748;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_1e9728:
    cpu->regs[26] = cpu->regs[26] << 1;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[26] << 3;
    cpu->regs[30] = PB_BASE + 0x1e9738ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e9758;
    cpu->regs[22] = cpu->regs[0];
    goto L_1e96c0;
L_1e9748:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1e9758ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e9758:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e9760ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e976cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_1e96d8;
L_1e9770:
    cpu->regs[30] = PB_BASE + 0x1e9774ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e956c;
L_1e9778:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e978c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e97a8;
L_1e978c:
    cpu->regs[30] = PB_BASE + 0x1e9790ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e9604;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1e960c;
L_1e97a8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e97b0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e978c;
L_1e97b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e97bcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e95c8;
L_1e97c0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[25] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1e96ec;
L_1e97d4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[25] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e97e4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1e96ec;
L_1e97f4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[25] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1e96ec;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 24));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9828;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e9828:
    cpu->regs[20] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
L_1e9834:
    if (((cpu->regs[20] >> 31) & 1)) goto L_1e9890;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[22]));
    if ((cpu->regs[1])==0) goto L_1e9884;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1e9858;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_1e9858:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[1] + 8) + 8);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9864ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c1e0ULL);
    if ((cpu->regs[0])==0) goto L_1e98c4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1e98b0;
L_1e9870:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e9884;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e98a4;
L_1e9884:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] - 1ULL));
    cpu->regs[22] = cpu->regs[22] - 8ULL;
    goto L_1e9834;
L_1e9890:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(31, cpu, tlb, PB_BASE + 0x1ef5e0ULL); return; };
L_1e98a4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e98acULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e9884;
L_1e98b0:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e9870;
    cpu->regs[30] = PB_BASE + 0x1e98c0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e9870;
L_1e98c4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x1e98d4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1fa220ULL);
    goto L_1e9870;
    /* nop */
    /* nop */
    cpu->regs[2] = cpu->regs[0] + 104ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 2328ULL;
    if ((cpu->regs[1])==0) goto L_1e9900;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 136));
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_1e9900:
    PB_STR((cpu->regs[0] + 0), 0ULL);
    return;
}
