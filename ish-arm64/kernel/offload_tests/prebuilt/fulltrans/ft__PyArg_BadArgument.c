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

void ft__PyArg_BadArgument(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2736));
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 2760));
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[2];
    FLAG_CMP(cpu->regs[5], cpu->regs[7]);
    if (FLAG_EQ) goto L_23b354;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 24));
L_23b344:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 160ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x11f220ULL); return; };
L_23b354:
    cpu->regs[5] = PB_BASE + 0x2a3000ULL;
    cpu->regs[5] = cpu->regs[5] + 2064ULL;
    goto L_23b344;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if ((cpu->regs[2])==0) goto L_23b3fc;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x23b3a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1fbcc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23b46c;
L_23b3a8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if (((cpu->regs[19] >> 63) & 1)) goto L_23b44c;
L_23b3b0:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GE) goto L_23b454;
    if ((cpu->regs[20])==0) goto L_23b40c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 40));
    cpu->regs[0] = 0ULL;
    PB_LDRW(cpu->regs[2], (SP + 4));
    PB_STRB((cpu->regs[1] + cpu->regs[19]), cpu->regs[2]);
L_23b3cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_23b408;
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_23b3fc:
    cpu->regs[0] = 4294967295ULL;
    PB_STRW((SP + 4), cpu->regs[0]);
    goto L_23b3a8;
L_23b408:
    cpu->regs[30] = PB_BASE + 0x23b40cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23b40c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_23b408;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[19] + 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x1e790cULL); return; };
L_23b44c:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0]; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_GE) goto L_23b3b0;
L_23b454:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 1648ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23b46cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_23b46c:
    cpu->regs[0] = 4294967295ULL;
    goto L_23b3cc;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_23b4a0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
L_23b490:
    cpu->regs[2] = PB_BASE + 0x28e000ULL;
    cpu->regs[4] = 1ULL;
    cpu->regs[2] = cpu->regs[2] + 1760ULL;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x201dccULL); return; };
L_23b4a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
    goto L_23b490;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_23b4c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[0] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] & ~(((uint64_t)((int64_t)cpu->regs[0] >> 63)));
    { PB_CALL(7, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_23b4c8:
    cpu->regs[0] = 0ULL;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_23b5c8;
L_23b4f4:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_23b590;
L_23b4fc:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_23b648;
    cpu->regs[19] = 18446744073709551615ULL;
L_23b508:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[22]; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_23b628;
L_23b510:
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_GE) goto L_23b628;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    cpu->regs[30] = PB_BASE + 0x23b520ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e70a4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23b5e4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_23b61c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
L_23b530:
    cpu->regs[2] = cpu->regs[22] - cpu->regs[19];
    cpu->regs[1] = cpu->regs[19] + 1ULL;
    PB_LDRB(cpu->regs[21], (cpu->regs[0] + cpu->regs[19]));
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23b548ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b030ULL);
    cpu->regs[1] = cpu->regs[22] - 1ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23b554ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1e6c20ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23b5e4;
    cpu->regs[1] = ((uint32_t)(cpu->regs[21] + 5ULL));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = ((cpu->regs[1] & 0x1ffULL) << 5);
    cpu->regs[1] = cpu->regs[1] + 3048ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[3];
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_23b614;
L_23b580:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_23b590:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x23b598ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23b604;
    cpu->regs[30] = PB_BASE + 0x23b5a4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_23b5ec;
L_23b5b0:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23b604;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_23b648;
    if (!((cpu->regs[19] >> 63) & 1)) goto L_23b510;
    goto L_23b508;
L_23b5c8:
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3608ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23b5e0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23b4f4;
L_23b5e4:
    cpu->regs[0] = 0ULL;
    goto L_23b580;
L_23b5ec:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_23b5b0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23b600ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23b5b0;
L_23b604:
    cpu->regs[30] = PB_BASE + 0x23b608ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_23b4fc;
    cpu->regs[0] = 0ULL;
    goto L_23b580;
L_23b614:
    PB_STRW((cpu->regs[3] + cpu->regs[1]), cpu->regs[2]);
    goto L_23b580;
L_23b61c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
    goto L_23b530;
L_23b628:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 72ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23b640ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_23b580;
L_23b648:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 208ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23b660ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_23b580;
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_23b688;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
L_23b678:
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[2] = cpu->regs[2] + 2664ULL;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x201dccULL); return; };
L_23b688:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
    goto L_23b678;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[1];
    if ((cpu->regs[0])!=0) goto L_23b6b4;
    cpu->regs[0] = 0ULL;
    return;
L_23b6b4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    if ((cpu->regs[19])==0) goto L_23b6f4;
L_23b6d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_23b6e4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_23b6e4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_23b6f4:
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_23b784;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_23b784;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = 31664ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x23b728ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23b7d4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_23b7a8;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x23b750ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23b770;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23b770;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23b770ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23b770:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STR((cpu->regs[20] + 32), cpu->regs[19]);
    if ((cpu->regs[19])!=0) goto L_23b6d4;
    cpu->regs[19] = 0ULL;
    goto L_23b6e4;
L_23b784:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23b79cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_STR((cpu->regs[20] + 32), 0ULL);
L_23b7a0:
    cpu->regs[19] = 0ULL;
    goto L_23b6e4;
L_23b7a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23b7c0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23b7c8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STR((cpu->regs[20] + 32), 0ULL);
    goto L_23b7a0;
L_23b7d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STR((cpu->regs[20] + 32), 0ULL);
    goto L_23b7a0;
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[5] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_23b8ac;
    if (((cpu->regs[2] >> 63) & 1)) goto L_23b910;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_23b8b4;
L_23b830:
    if ((cpu->regs[19])==0) goto L_23b8a0;
L_23b834:
    PB_LDR(cpu->regs[20], (cpu->regs[5] + 0));
    if ((cpu->regs[20])==0) goto L_23b844;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_23b898;
L_23b844:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    cpu->regs[30] = PB_BASE + 0x23b84cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23b950;
L_23b858:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    if ((cpu->regs[1])==0) goto L_23b95c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
L_23b864:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[5], (SP + 40));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    cpu->regs[5] = cpu->regs[5] - cpu->regs[4]; FLAG_CMP(cpu->regs[5], 0);
    cpu->regs[4] = 0ULL;
    if (FLAG_NE) goto L_23b90c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80));
    SP = SP + 96ULL;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0x233050ULL); return; };
L_23b898:
    cpu->regs[3] = cpu->regs[19];
    goto L_23b858;
L_23b8a0:
    cpu->regs[3] = 1ULL;
    cpu->regs[20] = 0ULL;
    goto L_23b858;
L_23b8ac:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[2] + cpu->regs[19];
L_23b8b4:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 3928ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23b8e8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_23b830;
L_23b8f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_23b968;
L_23b90c:
    cpu->regs[30] = PB_BASE + 0x23b910ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23b910:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 3928ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23b940ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23b8f0;
    cpu->regs[19] = cpu->regs[20];
    goto L_23b834;
L_23b950:
    cpu->regs[30] = PB_BASE + 0x23b954ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_23b858;
    goto L_23b8f0;
L_23b95c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
    goto L_23b864;
L_23b968:
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
}
