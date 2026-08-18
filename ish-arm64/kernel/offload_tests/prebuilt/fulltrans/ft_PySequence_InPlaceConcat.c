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

void ft_PySequence_InPlaceConcat(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    if (FLAG_NE) goto L_83154;
    cpu->regs[30] = PB_BASE + 0x83150ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_83210;
L_83154:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 104));
    if ((cpu->regs[3])==0) goto L_83198;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 64));
    if ((cpu->regs[4])==0) goto L_83180;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[16] = cpu->regs[4];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_83180:
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 8));
    if ((cpu->regs[3])==0) goto L_83198;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_83198:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x831a0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_831f0;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x831acULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_831f0;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 152ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x831c4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ac780ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_83214;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_831f0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_831f0;
    cpu->regs[30] = PB_BASE + 0x831f0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_831f0:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 3424ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x83210ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
L_83210:
    cpu->regs[1] = 0ULL;
L_83214:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_8324c;
L_8323c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x1b50a0ULL); return; };
L_8324c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1192ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x83264ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_8323c;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_832a0;
L_83290:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x1f72c0ULL); return; };
L_832a0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1200ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x832b8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_83290;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_832f4;
L_832e4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x245604ULL); return; };
L_832f4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1208ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x8330cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_832e4;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 28888ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x83368ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_83388;
    cpu->regs[30] = PB_BASE + 0x83388ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_83388:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_833bc;
L_833ac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x16aea0ULL); return; };
L_833bc:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1224ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x833d4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_833ac;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 28944ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x83430ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_83450;
    cpu->regs[30] = PB_BASE + 0x83450ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_83450:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_83484;
L_83474:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x23b980ULL); return; };
L_83484:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x8349cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_83474;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 29056ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x834f8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_83518;
    cpu->regs[30] = PB_BASE + 0x83518ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_83518:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 29168ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x8356cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_8358c;
    cpu->regs[30] = PB_BASE + 0x8358cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c170ULL);
L_8358c:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_835c0;
L_835b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0x835ecULL); return; };
L_835c0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1240ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x835d8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_835b0;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
