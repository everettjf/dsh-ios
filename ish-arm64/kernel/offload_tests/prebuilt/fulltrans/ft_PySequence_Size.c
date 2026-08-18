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

void ft_PySequence_Size(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_1fd24c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 104));
    if ((cpu->regs[2])==0) goto L_1fd214;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    if ((cpu->regs[2])==0) goto L_1fd214;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1fd214:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 112));
    if ((cpu->regs[0])!=0) goto L_1fd234;
L_1fd21c:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 3016ULL;
    cpu->regs[30] = PB_BASE + 0x1fd228ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x234660ULL);
L_1fd228:
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1fd234:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_1fd21c;
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[0] + 2208ULL;
    cpu->regs[30] = PB_BASE + 0x1fd248ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x234660ULL);
    goto L_1fd228;
L_1fd24c:
    cpu->regs[30] = PB_BASE + 0x1fd250ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_1fd228;
    /* nop */
    /* nop */
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1fd270ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fd29c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 61440ULL));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(40960ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
L_1fd294:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1fd29c:
    cpu->regs[30] = PB_BASE + 0x1fd2a0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_1fd294;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1fd2d4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x136924ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fd2f8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1fd308;
L_1fd2e4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1fd2f4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1fd2f4:
    cpu->regs[1] = cpu->regs[19];
L_1fd2f8:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1fd308:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1fd2e4;
    cpu->regs[30] = PB_BASE + 0x1fd318ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fd2e4;
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1fd330ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fd35c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 61440ULL));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32768ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
L_1fd354:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1fd35c:
    cpu->regs[30] = PB_BASE + 0x1fd360ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_1fd354;
    /* nop */
    /* nop */
    /* nop */
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((cpu->regs[1] >> 3) & 0xfULL);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(11ULL)));
    if (FLAG_EQ) goto L_1fd3d0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    if (FLAG_LS) goto L_1fd3c8;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_1fd3f0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(15ULL)));
    if (FLAG_EQ) goto L_1fd3c8;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 1));
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 63ULL));
L_1fd3b8:
    if (((cpu->regs[1] >> 6) & 1)) goto L_1fd3d8;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] >> 1));
    if (((cpu->regs[2] >> 0) & 1)) goto L_1fd3f8;
    return;
L_1fd3c8:
    cpu->regs[0] = 0ULL;
    return;
L_1fd3d0:
    cpu->regs[0] = 1ULL;
    return;
L_1fd3d8:
    PB_LDRB(cpu->regs[1], cpu->regs[0]); cpu->regs[0] += 1;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 6ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 63ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] << (cpu->regs[3] & 63)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | cpu->regs[4]));
    goto L_1fd3b8;
L_1fd3f0:
    cpu->regs[0] = 2ULL;
    return;
L_1fd3f8:
    cpu->regs[0] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[0])));
    return;
    goto L_1fd404;
L_1fd404:
    SP = SP - 448ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 400), cpu->regs[29]); PB_STR((SP + 400) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 400ULL;
    PB_STR((SP + 416), cpu->regs[19]); PB_STR((SP + 416) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 432), cpu->regs[21]); PB_STR((SP + 432) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 392), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fd434ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x1fd440ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c0c0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fd44cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if (((cpu->regs[20] >> 31) & 1)) goto L_1fd4ec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    cpu->regs[30] = PB_BASE + 0x1fd45cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe51acULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fd4fc;
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x1fd46cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1931a0ULL);
    if ((cpu->regs[0])==0) goto L_1fd504;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = SP + 65ULL;
    cpu->regs[30] = PB_BASE + 0x1fd47cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1931a0ULL);
    if ((cpu->regs[0])==0) goto L_1fd504;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    cpu->regs[0] = SP + 130ULL;
    cpu->regs[30] = PB_BASE + 0x1fd48cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1931a0ULL);
    if ((cpu->regs[0])==0) goto L_1fd504;
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    cpu->regs[0] = SP + 195ULL;
    cpu->regs[30] = PB_BASE + 0x1fd49cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1931a0ULL);
    if ((cpu->regs[0])==0) goto L_1fd504;
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    cpu->regs[0] = SP + 260ULL;
    cpu->regs[30] = PB_BASE + 0x1fd4acULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1931a0ULL);
    if ((cpu->regs[0])==0) goto L_1fd504;
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
L_1fd4b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 392));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1fd4e8;
    PB_LDR(cpu->regs[29], (SP + 400)); PB_LDR(cpu->regs[30], (SP + 400) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 416)); PB_LDR(cpu->regs[20], (SP + 416) + 8);
    PB_LDR(cpu->regs[21], (SP + 432)); PB_LDR(cpu->regs[22], (SP + 432) + 8);
    SP = SP + 448ULL;
    return;
L_1fd4e8:
    cpu->regs[30] = PB_BASE + 0x1fd4ecULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fd4ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fd4fcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_1fd4fc:
    cpu->regs[19] = 0ULL;
    goto L_1fd4b4;
L_1fd504:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fd4fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1fd4fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fd524ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fd4b4;
L_1fd528:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_1fd56c;
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], cpu->regs[3]); cpu->regs[3] += 4;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_1fd5a0;
    if (FLAG_HI) goto L_1fd574;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(8ULL)));
    if (FLAG_NE) goto L_1fd5c0;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_1fd564;
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(17ULL)));
    if (FLAG_LS) goto L_1fd528;
L_1fd564:
    cpu->regs[0] = 4294967295ULL;
    return;
L_1fd56c:
    cpu->regs[0] = 0ULL;
    return;
L_1fd574:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(22ULL)));
    if (FLAG_EQ) goto L_1fd584;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(42ULL)));
    if (FLAG_NE) goto L_1fd5b0;
L_1fd584:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_1fd564;
    cpu->regs[2] = cpu->regs[0] + 8ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LS) goto L_1fd564;
    cpu->regs[0] = cpu->regs[0] + 12ULL;
    goto L_1fd528;
L_1fd5a0:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_1fd564;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    goto L_1fd528;
L_1fd5b0:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(21ULL)));
    if (FLAG_NE) goto L_1fd564;
    cpu->regs[0] = cpu->regs[3];
    goto L_1fd528;
L_1fd5c0:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_1fd564;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(9ULL)));
    if (FLAG_NE) goto L_1fd5e4;
    cpu->regs[3] = cpu->regs[1] - cpu->regs[3];
    FLAG_CMP(cpu->regs[3], 28ULL);
    if (FLAG_LS) goto L_1fd564;
    cpu->regs[0] = cpu->regs[0] + 36ULL;
    goto L_1fd528;
L_1fd5e4:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_1fd564;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_1fd564;
    cpu->regs[2] = cpu->regs[0] + 8ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[3] + 0));
    cpu->regs[3] = cpu->regs[1] - cpu->regs[2];
    FLAG_CMP(cpu->regs[3], 252ULL);
    if (FLAG_LS) goto L_1fd564;
    cpu->regs[0] = cpu->regs[0] + 264ULL;
L_1fd60c:
    PB_LDRB(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_HS) goto L_1fd564;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_1fd60c;
    cpu->regs[3] = cpu->regs[1] - cpu->regs[2];
    cpu->regs[0] = ((uint32_t)(cpu->regs[4] << 3));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_HI) goto L_1fd564;
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[0] << 2);
    goto L_1fd528;
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_1fd65c;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_1fd668;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x12cb88ULL); return; };
L_1fd65c:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    { PB_CALL(23, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_1fd668:
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x12cb88ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_1fd69c;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1fd698ULL; PB_CALL(25, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd77c;
L_1fd69c:
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 24));
    PB_STR((SP + 48), cpu->regs[23]);
L_1fd6a4:
    cpu->regs[23] = cpu->regs[22];
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_NE) goto L_1fd738;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 72));
    if ((cpu->regs[0])==0) goto L_1fd6c4;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fd6c0ULL; PB_CALL(26, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd6c4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 88));
    if ((cpu->regs[0])==0) goto L_1fd6d8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fd6d4ULL; PB_CALL(27, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd6d8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 112));
    if ((cpu->regs[0])==0) goto L_1fd6ec;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fd6e8ULL; PB_CALL(28, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd6ec:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 120));
    if ((cpu->regs[0])==0) goto L_1fd700;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fd6fcULL; PB_CALL(29, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd700:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 128));
    if ((cpu->regs[0])==0) goto L_1fd714;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fd710ULL; PB_CALL(30, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd714:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 136));
    if ((cpu->regs[0])==0) goto L_1fd778;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1fd738:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 40));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 24));
    if ((cpu->regs[0])==0) goto L_1fd750;
    cpu->regs[30] = PB_BASE + 0x1fd74cULL; PB_CALL(31, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd750:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 48));
    cpu->regs[1] = cpu->regs[20];
    if ((cpu->regs[0])==0) goto L_1fd764;
    cpu->regs[30] = PB_BASE + 0x1fd760ULL; PB_CALL(32, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fd778;
L_1fd764:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[1] = cpu->regs[20];
    if ((cpu->regs[0])==0) goto L_1fd6a4;
    cpu->regs[30] = PB_BASE + 0x1fd774ULL; PB_CALL(33, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fd6a4;
L_1fd778:
    PB_LDR(cpu->regs[23], (SP + 48));
L_1fd77c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP = SP - 112ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    if ((cpu->regs[2])!=0) goto L_1fd924;
    cpu->regs[4] = cpu->regs[1] - 1ULL;
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_HI) goto L_1fd9d0;
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_1fd930;
L_1fd7e8:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_1fd90c;
L_1fd7f4:
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 8));
    cpu->regs[30] = PB_BASE + 0x1fd7fcULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fda0c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_1fd970;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_1fda14;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fd82cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fd97c;
L_1fd838:
    if (((cpu->regs[19] >> 63) & 1)) goto L_1fd984;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HI) goto L_1fda3c;
    cpu->regs[0] = cpu->regs[20] << 3;
    cpu->regs[30] = PB_BASE + 0x1fd850ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[21] = cpu->regs[0];
L_1fd854:
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HI) goto L_1fd9ac;
    cpu->regs[0] = cpu->regs[19] << 3;
    cpu->regs[30] = PB_BASE + 0x1fd868ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdbd90ULL);
    FLAG_CMP(cpu->regs[21], 0ULL);
    cpu->regs[24] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_1fda30;
L_1fd87c:
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_LE) goto L_1fd890;
    PB_STR((cpu->regs[21] + (cpu->regs[1] << 3)), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_1fd87c;
L_1fd890:
    cpu->regs[1] = 0ULL;
L_1fd894:
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_1fd8ac;
    cpu->regs[0] = cpu->regs[20] - cpu->regs[1];
    PB_STR((cpu->regs[24] + (cpu->regs[1] << 3)), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_1fd894;
L_1fd8ac:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 304));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fd8bcULL; PB_CALL(38, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1fd9b8;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[22]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[21]);
    cpu->regs[1] = (FLAG_GT) ? 1 : 0;
    PB_STR((cpu->regs[0] + 32), cpu->regs[24]); PB_STR((cpu->regs[0] + 32) + 8, 0ULL);
    PB_STR((cpu->regs[0] + 48), cpu->regs[19]);
    PB_STRW((cpu->regs[0] + 56), cpu->regs[1]);
L_1fd8d8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1fd978;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_1fd90c:
    cpu->regs[30] = PB_BASE + 0x1fd910ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fda0c;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 16));
    cpu->regs[20] = cpu->regs[19];
    goto L_1fd838;
L_1fd924:
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[19] = cpu->regs[1] + cpu->regs[19];
L_1fd930:
    cpu->regs[2] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[4] + 4016ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fd960ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1fd7e8;
L_1fd968:
    cpu->regs[0] = 0ULL;
    goto L_1fd8d8;
L_1fd970:
    cpu->regs[19] = cpu->regs[20];
    goto L_1fd838;
L_1fd978:
    cpu->regs[30] = PB_BASE + 0x1fd97cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fd97c:
    cpu->regs[30] = PB_BASE + 0x1fd980ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1fd99c;
L_1fd984:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 2912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fd99cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1fd99c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1fd9a4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    goto L_1fd8d8;
L_1fd9ac:
    cpu->regs[30] = PB_BASE + 0x1fd9b0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x22d780ULL);
    if ((cpu->regs[21])==0) goto L_1fd99c;
    cpu->regs[24] = 0ULL;
L_1fd9b8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fd9c0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_1fd9c0:
    if ((cpu->regs[24])==0) goto L_1fd99c;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fd9ccULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1fd99c;
L_1fd9d0:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[0] = cpu->regs[3] + 24ULL;
    cpu->regs[4] = cpu->regs[4] + 4016ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fd9fcULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fd968;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    goto L_1fd7f4;
L_1fda0c:
    cpu->regs[22] = 0ULL;
    goto L_1fd99c;
L_1fda14:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fda2cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1fd99c;
L_1fda30:
    cpu->regs[30] = PB_BASE + 0x1fda34ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x22d780ULL);
    if ((cpu->regs[21])!=0) goto L_1fd9b8;
    goto L_1fd9c0;
L_1fda3c:
    cpu->regs[21] = 0ULL;
    goto L_1fd854;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[2] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[6] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    PB_STR((SP + 16), cpu->regs[19]);
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + 32));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fda90;
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 64));
    cpu->regs[6] = cpu->regs[5] + (cpu->regs[6] << 3);
    PB_LDR(cpu->regs[19], (cpu->regs[6] + 72));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fda7c;
    if (((cpu->regs[2] >> 6) & 1)) goto L_1fdab0;
L_1fda7c:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[19]);
L_1fda84:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1fda90:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] & 1ULL));
    if (!((cpu->regs[1] >> 0) & 1)) goto L_1fda84;
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 64));
    cpu->regs[6] = cpu->regs[5] + (cpu->regs[6] << 3);
    PB_LDR(cpu->regs[19], (cpu->regs[6] + 72));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fda7c;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    goto L_1fda7c;
L_1fdab0:
    if ((cpu->regs[19])==0) goto L_1fda7c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2872));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1fda7c;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[2] = cpu->regs[3];
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 56));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1fdadcULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x2518acULL);
    PB_LDR(cpu->regs[4], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fda7c;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    goto L_1fda7c;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fdb50;
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1fdb24ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1fdb70;
    PB_STRW((cpu->regs[0] + 32), cpu->regs[22]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[23]);
    cpu->regs[1] = 15ULL;
    PB_STRW((cpu->regs[0] + 40), cpu->regs[20]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1fdb44:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1fdb50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 2936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fdb68ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1fdb44;
L_1fdb70:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1fdb44;
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[20], (cpu->regs[0] + 16) + 8);
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[23], (cpu->regs[0] + 32) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 48));
    PB_LDR(cpu->regs[22], (cpu->regs[26] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fdd44;
    if ((cpu->regs[23])==0) goto L_1fdc44;
    if ((cpu->regs[22])==0) goto L_1fdd3c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_1fdd4c;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1fdbd4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fdd3c;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[21] + 40), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1fdbf4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1fdd60;
L_1fdbf4:
    cpu->regs[23] = cpu->regs[19];
L_1fdbf8:
    cpu->regs[1] = cpu->regs[20] + (cpu->regs[22] << 3);
    cpu->regs[19] = cpu->regs[24] - 1ULL;
    cpu->regs[1] = cpu->regs[1] - 8ULL;
    cpu->regs[4] = cpu->regs[22] - 1ULL;
L_1fdc08:
    if (((cpu->regs[19] >> 63) & 1)) goto L_1fdd3c;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + (cpu->regs[19] << 3)));
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[25] + (cpu->regs[19] << 3)), cpu->regs[2]);
    PB_LDR(cpu->regs[3], (cpu->regs[20] + (cpu->regs[19] << 3)));
    if ((cpu->regs[2])!=0) goto L_1fdcbc;
    cpu->regs[0] = cpu->regs[19];
L_1fdc24:
    cpu->regs[2] = cpu->regs[20] + 8ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_GT) goto L_1fdd24;
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[22] - cpu->regs[19];
    PB_STR((cpu->regs[25] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    goto L_1fdc08;
L_1fdc44:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fdc4cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fdd3c;
    cpu->regs[3] = cpu->regs[23] + 24ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[21] + 40), cpu->regs[23]);
L_1fdc60:
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_GE) goto L_1fdc90;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[0] << 3)));
    cpu->regs[1] = cpu->regs[26] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1fdc84;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_1fdc84:
    PB_STR((cpu->regs[3] + (cpu->regs[0] << 3)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_1fdc60;
L_1fdc90:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1fdca0;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_1fdca0:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1fdcbc:
    cpu->regs[22] = cpu->regs[22] - cpu->regs[2];
    cpu->regs[21] = cpu->regs[23] + 24ULL;
    cpu->regs[22] = cpu->regs[22] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[22]));
    PB_STR((cpu->regs[20] + (cpu->regs[19] << 3)), cpu->regs[0]);
    PB_STR((cpu->regs[20] + cpu->regs[22]), cpu->regs[3]);
L_1fdcd4:
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_GE) goto L_1fdc90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[19] << 3)));
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1fdd34;
L_1fdcf4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + (cpu->regs[19] << 3)));
    PB_STR((cpu->regs[21] + (cpu->regs[19] << 3)), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1fdd0c;
L_1fdd04:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_1fdcd4;
L_1fdd0c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1fdd04;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1fdd20ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fdcd4;
L_1fdd24:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[0] << 3)));
    PB_STR((cpu->regs[20] + (cpu->regs[0] << 3)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_1fdc24;
L_1fdd34:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_1fdcf4;
L_1fdd3c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[21] + 56), cpu->regs[0]);
L_1fdd44:
    cpu->regs[23] = 0ULL;
    goto L_1fdca0;
L_1fdd4c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -16));
    if ((cpu->regs[0])!=0) goto L_1fdbf8;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1fdd5cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_1fdbf8;
L_1fdd60:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1fdd68ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fdbf4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if (((cpu->regs[1] >> 6) & 1)) goto L_1fdd80;
    cpu->regs[1] = PB_BASE + 0x27c000ULL;
    cpu->regs[1] = cpu->regs[1] + 3140ULL;
    { PB_CALL(59, cpu, tlb, PB_BASE + 0x24d5acULL); return; };
L_1fdd80:
    cpu->regs[1] = 0ULL;
    { PB_CALL(60, cpu, tlb, PB_BASE + 0x1f6060ULL); return; };
}
