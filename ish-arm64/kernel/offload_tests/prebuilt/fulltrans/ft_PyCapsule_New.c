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

void ft_PyCapsule_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_1b5308;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3016));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1b52ecULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe3a2cULL);
    if ((cpu->regs[0])==0) goto L_1b5328;
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[21]);
    PB_STR((cpu->regs[0] + 32), 0ULL); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32));
L_1b5300:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1b5308:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3296ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1b5320ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1b5300;
L_1b5328:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1b5300;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 176ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    PB_STR((SP + 160), cpu->regs[19]); PB_STR((SP + 160) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 136), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[30] = PB_BASE + 0x1b5378ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1b5418;
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b5388ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1b5418;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x1b5398ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1b5420ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1b540c;
    PB_LDRW(cpu->regs[1], (SP + 24));
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(32768ULL)));
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[0];
L_1b53bc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1b53c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1b5404;
L_1b53d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 136));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1b5400;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 160)); PB_LDR(cpu->regs[20], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
L_1b5400:
    cpu->regs[30] = PB_BASE + 0x1b5404ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1b5404:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1b53d0;
L_1b540c:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3184));
    goto L_1b53bc;
L_1b5418:
    cpu->regs[19] = 0ULL;
    goto L_1b53d0;
L_1b5420:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b543cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1b22e8ULL);
    if ((cpu->regs[0])==0) goto L_1b546c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1b544cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7bda0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1b545cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7784ULL);
L_1b545c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1b546c:
    cpu->regs[30] = PB_BASE + 0x1b5470ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[1] = 22ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1b545c;
    PB_LDR(cpu->regs[11], (cpu->regs[0] + 64));
    PB_LDRW(cpu->regs[8], (cpu->regs[11] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(20ULL)));
    if (FLAG_GT) goto L_1b54c0;
    cpu->regs[7] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[8]));
    cpu->regs[9] = cpu->regs[1];
    cpu->regs[1] = 40ULL;
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] + 1ULL));
    PB_STRW((cpu->regs[11] + 56), cpu->regs[8]);
    cpu->regs[0] = 0ULL;
    cpu->regs[7] = cpu->regs[7] * cpu->regs[1] + cpu->regs[11];
    PB_STRW((cpu->regs[7] + 64), cpu->regs[3]); PB_STRW((cpu->regs[7] + 64) + 4, cpu->regs[4]);
    PB_STR((cpu->regs[7] + 72), cpu->regs[9]); PB_STR((cpu->regs[7] + 72) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[7] + 88), cpu->regs[5]);
    PB_STR((cpu->regs[7] + 96), cpu->regs[6]);
    return;
L_1b54c0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    cpu->regs[3] = cpu->regs[3] + 3368ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1b54d4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x26ba00ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    if (FLAG_NE) goto L_1b5558;
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + 0));
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5528;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1b55d8;
L_1b5514:
    cpu->regs[0] = 0ULL;
L_1b5518:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1b5528:
    cpu->regs[1] = cpu->regs[2];
    PB_STRW((SP + 52), cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1b5538ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1cb92cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b55a8;
    PB_LDR(cpu->regs[3], (SP + 56));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    PB_LDRW(cpu->regs[2], (SP + 52));
    PB_STRW((cpu->regs[3] + 0), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1b5514;
    goto L_1b55d8;
L_1b5558:
    cpu->regs[22] = PB_BASE + 0x450000ULL;
    cpu->regs[1] = cpu->regs[22] + 8ULL;
    cpu->regs[20] = ((uint32_t)(cpu->regs[2] & 1ULL));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 260));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1b55b0;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1b557cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7bb50ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1b55a4;
L_1b5580:
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] & 4294967294ULL));
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_1b558c;
L_1b5588:
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] | 1ULL));
L_1b558c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1b5514;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1b55a0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7bb50ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1b5514;
L_1b55a4:
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_1b5630;
L_1b55a8:
    cpu->regs[0] = 4294967295ULL;
    goto L_1b5518;
L_1b55b0:
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_1b560c;
L_1b55b4:
    cpu->regs[1] = 21585ULL;
L_1b55b8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b55c4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7abb0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1b5614;
    cpu->regs[22] = cpu->regs[22] + 8ULL;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[22] + 260), cpu->regs[0]);
    goto L_1b5514;
L_1b55d8:
    cpu->regs[22] = PB_BASE + 0x450000ULL;
    cpu->regs[0] = cpu->regs[22] + 8ULL;
    cpu->regs[20] = ((uint32_t)(cpu->regs[2] & 1ULL));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 260));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1b55b4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1b5600ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7bb50ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1b5588;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1b55a8;
    goto L_1b5630;
L_1b560c:
    cpu->regs[1] = 21584ULL;
    goto L_1b55b8;
L_1b5614:
    cpu->regs[30] = PB_BASE + 0x1b5618ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_1b5650;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 13ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1b5648;
L_1b5630:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1b5640ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1b5518;
L_1b5648:
    cpu->regs[22] = cpu->regs[22] + 8ULL;
    PB_STRW((cpu->regs[22] + 260), 0ULL);
L_1b5650:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1b565cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7bb50ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1b5630;
    cpu->regs[20] = 1ULL;
    goto L_1b5580;
}
