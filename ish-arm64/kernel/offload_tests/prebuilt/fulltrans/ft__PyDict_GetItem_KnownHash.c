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

void ft__PyDict_GetItem_KnownHash(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 32ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 168));
    if (!((cpu->regs[3] >> 29) & 1)) goto L_e3654;
    cpu->regs[3] = SP;
    cpu->regs[30] = PB_BASE + 0xe3624ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
L_e3628:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e3650;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_e3650:
    cpu->regs[30] = PB_BASE + 0xe3654ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e3654:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1738ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0xe3664ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_e3628;
L_e366c:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 19) & 1)) goto L_e3694;
L_e3684:
    cpu->regs[0] = 1ULL;
L_e3688:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_e3694:
    if (!((cpu->regs[0] >> 12) & 1)) goto L_e370c;
    cpu->regs[19] = cpu->regs[1];
    if (((cpu->regs[0] >> 8) & 1)) goto L_e3714;
    cpu->regs[1] = cpu->regs[20] + (64ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 13240));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e370c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_STRW((cpu->regs[1] + 13240), cpu->regs[2]);
L_e36bc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 336));
    cpu->regs[21] = 0ULL;
    cpu->regs[23] = cpu->regs[1] + 24ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    PB_STRW((cpu->regs[19] + 384), cpu->regs[0]);
L_e36d0:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_LT) goto L_e36f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[0] | 524288ULL;
    PB_STR((cpu->regs[19] + 168), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_e3684;
L_e36f0:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[21] << 3)));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0xe3700ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe366cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e36d0;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_e370c:
    cpu->regs[0] = 0ULL;
    goto L_e3688;
L_e3714:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 131071ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 3040));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_HI) goto L_e370c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_STRW((cpu->regs[1] + 3040), cpu->regs[2]);
    goto L_e36bc;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 10));
    PB_LDRB(cpu->regs[19], (cpu->regs[0] + 8));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_e39f4;
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = 12297829382473034410ULL;
    cpu->regs[19] = cpu->regs[1] << (cpu->regs[19] & 63);
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 0)) | ((0xaaabULL & 0xffff) << 0);
    cpu->regs[19] = cpu->regs[19] << 1;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 9));
    cpu->regs[19] = (uint64_t)(((unsigned __int128)cpu->regs[19] * (unsigned __int128)cpu->regs[2]) >> 64);
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[0] & 63);
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[19] = cpu->regs[19] >> 1;
    cpu->regs[19] = cpu->regs[1] + (cpu->regs[19] << 4); FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_e3a20;
L_e3790:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[0] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0xe37a4ULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e3a20;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HI) goto L_e399c;
    if (FLAG_HS) goto L_e37c8;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[19];
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LO) goto L_e39a8;
L_e37c8:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xe37d4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 9));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[2] & 63);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 10));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e39d4;
    cpu->regs[0] = cpu->regs[3] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = 2ULL;
    cpu->regs[4] = cpu->regs[0] + 8ULL;
    FLAG_CMP(cpu->regs[5], 0ULL);
    if (FLAG_LE) goto L_e3968;
L_e380c:
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 0));
    cpu->regs[1] = cpu->regs[1] << 3;
    if ((cpu->regs[6])==0) goto L_e3838;
    PB_LDRW(cpu->regs[2], (cpu->regs[6] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e3828;
    PB_STRW((cpu->regs[6] + 0), cpu->regs[2]);
L_e3828:
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[6] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_e39ac;
L_e3838:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[6] = cpu->regs[4] + cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_e3968;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + cpu->regs[1]));
    if ((cpu->regs[4])==0) goto L_e3870;
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e3860;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
L_e3860:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_e39b4;
L_e3870:
    cpu->regs[7] = cpu->regs[6] + cpu->regs[1];
    cpu->regs[8] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 2ULL);
    if (FLAG_EQ) goto L_e3968;
    PB_LDR(cpu->regs[4], (cpu->regs[6] + cpu->regs[1]));
    if ((cpu->regs[4])==0) goto L_e38a8;
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e3898;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
L_e3898:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + cpu->regs[1]));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e39bc;
L_e38a8:
    cpu->regs[4] = cpu->regs[7] + cpu->regs[1];
    cpu->regs[6] = cpu->regs[8] + cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 3ULL);
    if (FLAG_EQ) goto L_e3968;
    PB_LDR(cpu->regs[2], (cpu->regs[7] + cpu->regs[1]));
    if ((cpu->regs[2])==0) goto L_e38e0;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e38d0;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_e38d0:
    PB_LDR(cpu->regs[2], (cpu->regs[8] + cpu->regs[1]));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e39c4;
L_e38e0:
    cpu->regs[8] = cpu->regs[4] + cpu->regs[1];
    cpu->regs[9] = cpu->regs[6] + cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 4ULL);
    if (FLAG_EQ) goto L_e3968;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + cpu->regs[1]));
    if ((cpu->regs[2])==0) goto L_e3918;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e3908;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_e3908:
    PB_LDR(cpu->regs[2], (cpu->regs[6] + cpu->regs[1]));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e39cc;
L_e3918:
    cpu->regs[8] = cpu->regs[8] + cpu->regs[1];
    cpu->regs[9] = cpu->regs[9] + cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 5ULL);
    if (FLAG_EQ) goto L_e3968;
    cpu->regs[2] = 0ULL;
    cpu->regs[6] = 5ULL;
L_e3930:
    PB_LDR(cpu->regs[4], (cpu->regs[8] + cpu->regs[2]));
    if ((cpu->regs[4])==0) goto L_e3958;
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDR(cpu->regs[7], (cpu->regs[9] + cpu->regs[2]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e3978;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[7] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e3984;
L_e3958:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[1];
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_NE) goto L_e3930;
L_e3968:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_e3978:
    PB_LDRW(cpu->regs[0], (cpu->regs[7] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e3958;
L_e3984:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_STRW((cpu->regs[7] + 0), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] + cpu->regs[1];
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_NE) goto L_e3930;
    goto L_e3968;
L_e399c:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_e37c8;
L_e39a8:
    __builtin_trap();
L_e39ac:
    PB_STRW((cpu->regs[6] + 0), cpu->regs[2]);
    goto L_e3838;
L_e39b4:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
    goto L_e3870;
L_e39bc:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_e38a8;
L_e39c4:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_e38e0;
L_e39cc:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_e3918;
L_e39d4:
    cpu->regs[4] = cpu->regs[3] + 32ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[4] + 8ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    FLAG_CMP(cpu->regs[5], 0ULL);
    if (FLAG_LE) goto L_e3968;
    cpu->regs[1] = 3ULL;
    goto L_e380c;
L_e39f4:
    cpu->regs[1] = 1ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 9));
    cpu->regs[19] = cpu->regs[1] << (cpu->regs[19] & 63);
    cpu->regs[3] = 3ULL;
    cpu->regs[19] = cpu->regs[19] << 1;
    cpu->regs[2] = 24ULL;
    cpu->regs[0] = cpu->regs[1] << (cpu->regs[0] & 63);
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[19] = (cpu->regs[3] ? cpu->regs[19] / cpu->regs[3] : 0);
    cpu->regs[19] = cpu->regs[19] * cpu->regs[2] + cpu->regs[0];
    if (!((cpu->regs[19] >> 63) & 1)) goto L_e3790;
L_e3a20:
    cpu->regs[30] = PB_BASE + 0xe3a24ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[3] = 0ULL;
    goto L_e3968;
}
