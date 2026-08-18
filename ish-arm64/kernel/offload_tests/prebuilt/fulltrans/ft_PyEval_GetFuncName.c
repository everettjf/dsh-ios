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

void ft_PyEval_GetFuncName(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3984));
    cpu->regs[5] = cpu->regs[0];
L_abfa0:
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 8));
    FLAG_CMP(cpu->regs[6], cpu->regs[1]);
    if (FLAG_NE) goto L_abfb4;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 16));
    goto L_abfa0;
L_abfb4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3680));
    FLAG_CMP(cpu->regs[6], cpu->regs[0]);
    if (FLAG_NE) goto L_abfcc;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 32));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x1947a0ULL); return; };
L_abfcc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2864));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xabfe4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_abff4;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_abff8;
L_abff4:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 24));
L_abff8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    SP = SP - 1040ULL;
    PB_STR((SP + 1024), 0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 1032), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xac044ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd94a0ULL);
    if ((cpu->regs[0])==0) goto L_ac1b8;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = 0ULL;
L_ac058:
    PB_STR((SP + 24), cpu->regs[3]);
    FLAG_CMP(cpu->regs[21], cpu->regs[3]);
    if (FLAG_LE) goto L_ac0a0;
    cpu->regs[3] = cpu->regs[3] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[3]));
    PB_LDR(cpu->regs[3], (cpu->regs[22] + cpu->regs[3]));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_GE) goto L_ac094;
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[3] << 3);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 24));
    cpu->regs[30] = PB_BASE + 0xac090ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_ac19c;
L_ac094:
    PB_LDR(cpu->regs[3], (SP + 24));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_ac058;
L_ac0a0:
    cpu->regs[22] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[2] + 1408ULL;
    cpu->regs[1] = 1000ULL;
    cpu->regs[26] = PB_BASE + 0x28b000ULL;
    cpu->regs[30] = PB_BASE + 0xac0c0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[23] = PB_BASE + 0x29f000ULL;
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[26] = cpu->regs[26] + 2216ULL;
    cpu->regs[23] = cpu->regs[23] + 1440ULL;
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_STR((SP + 24), 0ULL);
L_ac0d8:
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac0ecULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ac188;
    FLAG_CMP(cpu->regs[20], 999ULL);
    if (FLAG_HI) goto L_ac188;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xac100ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xa6020ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ac11c;
L_ac108:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xac110ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ac1a4;
    goto L_ac1b8;
L_ac11c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_ac138;
    cpu->regs[30] = PB_BASE + 0xac12cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ac13c;
    goto L_ac108;
L_ac138:
    cpu->regs[3] = cpu->regs[26];
L_ac13c:
    cpu->regs[1] = 1000ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[20];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22] + cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac150ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[20] = cpu->regs[20] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0xac160ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[24] = cpu->regs[24] - 1ULL; FLAG_CMP(cpu->regs[24], 0);
    if (FLAG_EQ) goto L_ac0d8;
    cpu->regs[0] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[0], 999ULL);
    if (FLAG_HI) goto L_ac0d8;
    cpu->regs[1] = 44ULL;
    PB_STRB((cpu->regs[22] + cpu->regs[20]), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    PB_STRB((cpu->regs[22] + cpu->regs[0]), 0ULL);
    goto L_ac0d8;
L_ac188:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xac19cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_ac19c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_ac1b8;
L_ac1a4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_ac1b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac1b8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_ac1b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 1032));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ac1d8;
    cpu->regs[30] = PB_BASE + 0xac1d8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ac1d8:
    SP = SP + 1040ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
}
