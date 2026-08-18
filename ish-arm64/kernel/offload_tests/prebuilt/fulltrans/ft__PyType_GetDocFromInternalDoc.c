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

void ft__PyType_GetDocFromInternalDoc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1daef0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18d1a0ULL);
    if ((cpu->regs[0])==0) goto L_1daf04;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1daf04;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_1daf04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 9) & 1)) goto L_1daf68;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[1] + 3096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1daf54ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1daf54:
    cpu->regs[20] = 0ULL;
L_1daf58:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1daf68:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1daf70ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[1] = 26024ULL;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1daf88ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1dafcc;
    cpu->regs[30] = PB_BASE + 0x1daf94ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1db004;
    cpu->regs[30] = PB_BASE + 0x1daf9cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1db004;
    cpu->regs[0] = 26024ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1dafb8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1daff0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1dafc4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18e42cULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1daf58;
L_1dafcc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 272));
    if ((cpu->regs[3])!=0) goto L_1db014;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1db00c;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1daf58;
L_1daff0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1db004;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1db030;
L_1db004:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1daf54;
L_1db00c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1daf58;
L_1db014:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[1] = 0ULL;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1db030:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1db038ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1daf54;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 344));
    if ((cpu->regs[0])==0) goto L_1db05c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1db058;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1db058:
    return;
L_1db05c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2680));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_1db084;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xdd250ULL); return; };
L_1db084:
    { PB_CALL(12, cpu, tlb, PB_BASE + 0x11e710ULL); return; };
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    { PB_CALL(13, cpu, tlb, PB_BASE + 0xe3ac0ULL); return; };
L_1db090:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 168));
    if (!((cpu->regs[3] >> 8) & 1)) goto L_1db09c;
L_1db098:
    return;
L_1db09c:
    cpu->regs[4] = cpu->regs[3] & 96ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_EQ) goto L_1db098;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[3] & 18446744073709551519ULL;
    cpu->regs[3] = cpu->regs[3] | cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((cpu->regs[0] + 168), cpu->regs[3]);
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1db0c8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5444ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1db108;
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[20] = 0ULL;
L_1db0d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LT) goto L_1db114;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1db108;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1db108;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1db108:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1db114:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((SP + 40), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1db128ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1db090ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    goto L_1db0d8;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 512ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = SP;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1db170ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1db1a8;
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x1db17cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1db1b0ULL);
L_1db17c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1db1a4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_1db1a4:
    cpu->regs[30] = PB_BASE + 0x1db1a8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1db1a8:
    cpu->regs[0] = 0ULL;
    goto L_1db17c;
}
