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

void ft_PyCodec_Register(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1d3304ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1248));
    if ((cpu->regs[0])==0) goto L_1d3338;
L_1d3314:
    if ((cpu->regs[19])==0) goto L_1d336c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d3320ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d3344;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe548cULL); return; };
L_1d3338:
    cpu->regs[30] = PB_BASE + 0x1d333cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c7680ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d3314;
    goto L_1d335c;
L_1d3344:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    cpu->regs[1] = cpu->regs[1] + 3240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d335cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1d335c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d336c:
    cpu->regs[30] = PB_BASE + 0x1d3370ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x22aba0ULL);
    goto L_1d335c;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[21] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_1d3444;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[19] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[1];
L_1d33ac:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_NE) goto L_1d3400;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1d33f0;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 0));
L_1d33c4:
    cpu->regs[30] = PB_BASE + 0x1d33c8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d3460ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[1] : cpu->regs[0];
L_1d33e0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d33f0:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1d344c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    goto L_1d33c4;
L_1d3400:
    if ((cpu->regs[20])==0) goto L_1d342c;
    cpu->regs[22] = 0ULL;
L_1d3408:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_LE) goto L_1d3438;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1d3424ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[30] = PB_BASE + 0x1d3428ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d3460ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d3408;
L_1d342c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_1d33e0;
L_1d3438:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_1d33e0;
L_1d3444:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 56));
    goto L_1d33ac;
L_1d344c:
    PB_LDRH(cpu->regs[0], (cpu->regs[19] + 0));
    goto L_1d33c4;
    /* nop */
    /* nop */
    /* nop */
L_1d3460:
    cpu->regs[1] = 1114111ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_1d34b0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] >> 7));
    cpu->regs[1] = PB_BASE + 0x35c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1904ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 127ULL));
    cpu->regs[2] = PB_BASE + 0x34a000ULL;
    cpu->regs[2] = cpu->regs[2] + 3184ULL;
    PB_LDRH(cpu->regs[1], (cpu->regs[1] + (cpu->regs[3] << 1)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + (cpu->regs[1] << 7)));
    PB_LDRH(cpu->regs[0], (cpu->regs[2] + (cpu->regs[0] << 1)));
L_1d3490:
    cpu->regs[1] = PB_BASE + 0x348000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[0] = cpu->regs[1] + (((cpu->regs[0]) & 0xffffULL) << 4);
    cpu->regs[1] = 2055ULL;
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + 14));
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(cpu->regs[0]))), 0);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    return;
L_1d34b0:
    cpu->regs[0] = 0ULL;
    goto L_1d3490;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2640));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_1d3514;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1d3518;
L_1d3514:
    if ((cpu->regs[2])!=0) goto L_1d3540;
L_1d3518:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_HI) goto L_1d356c;
L_1d3524:
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_1d3564;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
L_1d3530:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x1c40a0ULL); return; };
L_1d3540:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 3888ULL;
    cpu->regs[30] = PB_BASE + 0x1d3550ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d3518;
L_1d3554:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d3564:
    cpu->regs[1] = 0ULL;
    goto L_1d3530;
L_1d356c:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3888ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d3580ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d3554;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    goto L_1d3524;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16)); PB_LDR(cpu->regs[21], (cpu->regs[1] + 16) + 8);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d35b4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1a6f20ULL);
    if ((cpu->regs[0])==0) goto L_1d35f4;
    PB_STRB((cpu->regs[0] + -2), 0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[21])==0) goto L_1d35d0;
    cpu->regs[2] = cpu->regs[21] << 3;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d35d0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7aee0ULL);
L_1d35d0:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[4] = 1ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0xd9580ULL); return; };
L_1d35f4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d3600ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe9320ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(17, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2232));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 16), cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d3644;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2456));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_1d3644;
    cpu->regs[30] = PB_BASE + 0x1d3640ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 0), 0ULL);
L_1d3644:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3872));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d366c;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3176));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_1d366c;
    cpu->regs[30] = PB_BASE + 0x1d3668ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[19] + 0), 0ULL);
L_1d366c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
}
