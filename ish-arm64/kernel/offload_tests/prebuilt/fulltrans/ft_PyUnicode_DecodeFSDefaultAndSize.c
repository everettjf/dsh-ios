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

void ft_PyUnicode_DecodeFSDefaultAndSize(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1931ecULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[3] + (65ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[4] = cpu->regs[0] + 88ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 8));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_193238;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 88));
    if ((cpu->regs[2])!=0) goto L_193254;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 1368));
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x19321cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x193268ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_193360;
L_193238:
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 24));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 16));
    cpu->regs[4] = 0ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xdea80ULL); return; };
L_193254:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 16));
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x153a00ULL); return; };
L_193268:
    if ((cpu->regs[0])==0) goto L_1932b4;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 944ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x193288ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_19332c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 880ULL;
    cpu->regs[30] = PB_BASE + 0x19329cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7b720ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 2ULL;
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1932bc;
L_1932a8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1932b4:
    cpu->regs[0] = 1ULL;
    return;
L_1932bc:
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1872ULL;
    cpu->regs[30] = PB_BASE + 0x1932ccULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_193334;
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1672ULL;
    cpu->regs[30] = PB_BASE + 0x1932e0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_19333c;
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1704ULL;
    cpu->regs[30] = PB_BASE + 0x1932f4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_193344;
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x193308ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_19334c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 1832ULL;
    cpu->regs[30] = PB_BASE + 0x19331cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b720ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 7ULL));
    goto L_1932a8;
L_19332c:
    cpu->regs[0] = 1ULL;
    goto L_1932a8;
L_193334:
    cpu->regs[0] = 3ULL;
    goto L_1932a8;
L_19333c:
    cpu->regs[0] = 4ULL;
    goto L_1932a8;
L_193344:
    cpu->regs[0] = 5ULL;
    goto L_1932a8;
L_19334c:
    cpu->regs[0] = 6ULL;
    goto L_1932a8;
    /* nop */
    /* nop */
    /* nop */
L_193360:
    SP = SP - 80ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDRB(cpu->regs[4], (cpu->regs[0] + cpu->regs[20]));
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_193434;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1933a4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_193434;
    cpu->regs[5] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[3] = SP;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1933c8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x17b9e8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_193418;
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    cpu->regs[30] = PB_BASE + 0x1933d4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x1933e0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd7784ULL);
L_1933e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_193414;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_193414:
    cpu->regs[30] = PB_BASE + 0x193418ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_193418:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_193454;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_1934b4;
    cpu->regs[30] = PB_BASE + 0x19342cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x22d780ULL);
L_19342c:
    cpu->regs[19] = 0ULL;
    goto L_1933e0;
L_193434:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3040ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x193450ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1933e0;
L_193454:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3656));
    cpu->regs[3] = cpu->regs[19];
    PB_LDR(cpu->regs[7], (SP + 0)); PB_LDR(cpu->regs[5], (SP + 0) + 8);
    cpu->regs[4] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = cpu->regs[2] + 96ULL;
    cpu->regs[1] = cpu->regs[1] + 104ULL;
    cpu->regs[6] = cpu->regs[5] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x193484ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19342c;
    cpu->regs[30] = PB_BASE + 0x193490ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x21e720ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_19342c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_19342c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1934b0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1933e0;
L_1934b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1934d0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1933e0;
    /* nop */
    /* nop */
    /* nop */
}
