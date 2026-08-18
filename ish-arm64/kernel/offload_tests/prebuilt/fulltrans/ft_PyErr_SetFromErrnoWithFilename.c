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

void ft_PyErr_SetFromErrnoWithFilename(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_af56c;
    cpu->regs[30] = PB_BASE + 0xaf550ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[22], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xaf560ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1931a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af584;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[22]);
L_af56c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xaf57cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1b2740ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf584ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
L_af584:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xaf5b0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_af5cc;
    cpu->regs[30] = PB_BASE + 0xaf5c0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_af5cc;
L_af5c4:
    cpu->regs[19] = 0ULL;
    goto L_af660;
L_af5cc:
    cpu->regs[0] = 72ULL;
    cpu->regs[30] = PB_BASE + 0xaf5d4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b880ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_af5f4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf5f0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_af5c4;
L_af5f4:
    cpu->regs[30] = PB_BASE + 0xaf5f8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xd7700ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_af610;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_af610:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf620ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b6b0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_af64c;
    cpu->regs[30] = PB_BASE + 0xaf630ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[30] = PB_BASE + 0xaf634ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_STRW((cpu->regs[0] + 0), cpu->regs[20]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xaf648ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_af5c4;
L_af64c:
    cpu->regs[30] = PB_BASE + 0xaf650ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1931a0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xaf660ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd7784ULL);
L_af660:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[0] = SP;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xaf6a0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b3d0ULL);
    if ((cpu->regs[0])!=0) goto L_af6bc;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf6b8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_af6c8;
L_af6bc:
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0xaf6c4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1931a0ULL);
    cpu->regs[19] = cpu->regs[0];
L_af6c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_af6e8;
    cpu->regs[30] = PB_BASE + 0xaf6e8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af6e8:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xaf710ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 0));
    cpu->regs[20] = cpu->regs[0];
    PB_STRW((cpu->regs[0] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xaf720ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7bd40ULL);
    if ((cpu->regs[0])!=0) goto L_af754;
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_af744;
    cpu->regs[30] = PB_BASE + 0xaf740ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_af75c;
L_af744:
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2296ULL;
    cpu->regs[30] = PB_BASE + 0xaf750ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af75c;
L_af754:
    cpu->regs[30] = PB_BASE + 0xaf758ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1931a0ULL);
    cpu->regs[19] = cpu->regs[0];
L_af75c:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_af7e0;
L_af7ac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_af800;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2328ULL;
    cpu->regs[30] = PB_BASE + 0xaf7dcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af884;
L_af7e0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2328ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaf7f8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_af7ac;
    goto L_af884;
L_af800:
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0xaf808ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af884;
    cpu->regs[30] = PB_BASE + 0xaf814ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af83c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf838ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af884;
L_af83c:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((SP + 16), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_af868;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xaf854ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2344ULL;
    cpu->regs[30] = PB_BASE + 0xaf864ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af884;
L_af868:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af8a0;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xaf880ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1cb820ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_af88c;
L_af884:
    cpu->regs[19] = 0ULL;
    goto L_af8e4;
L_af88c:
    PB_LDR(cpu->regs[20], (SP + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaf898ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_af8a8;
L_af8a0:
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = 0ULL;
L_af8a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf8b0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7adb0ULL);
    if ((cpu->regs[0])!=0) goto L_af8d0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf8c4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaf8ccULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_af884;
L_af8d0:
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xaf8d8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1b28d0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaf8e4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdce4cULL);
L_af8e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_af904;
    cpu->regs[30] = PB_BASE + 0xaf904ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af904:
    PB_LDR(cpu->regs[21], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_af91c:
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = SP;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xaf950ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1cb820ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_af9d8;
    PB_LDR(cpu->regs[20], (SP + 0));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf96cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_af9b4;
    cpu->regs[1] = cpu->regs[20] + 32ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_af990;
    cpu->regs[2] = cpu->regs[0] + cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HS) goto L_af9a4;
    goto L_af9a0;
L_af990:
    if (FLAG_LS) goto L_af9a4;
    cpu->regs[2] = cpu->regs[1] + cpu->regs[19];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_HS) goto L_af9a4;
L_af9a0:
    __builtin_trap();
L_af9a4:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[19] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xaf9b0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_af9bc;
L_af9b4:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xaf9bcULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x22d780ULL);
L_af9bc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_af9d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_af9d8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaf9d8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_af9d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_af9f8;
    cpu->regs[30] = PB_BASE + 0xaf9f8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af9f8:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 1152921504606846975ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LS) goto L_afa48;
L_afa40:
    cpu->regs[30] = PB_BASE + 0xafa44ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_afaf0;
L_afa48:
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[30] = PB_BASE + 0xafa50ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_afa40;
    cpu->regs[23] = 0ULL;
L_afa5c:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[22] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    FLAG_CMP(cpu->regs[2], cpu->regs[23]);
    if (FLAG_LE) goto L_afad8;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0xafa84ULL; PB_CALL(49, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_afae0;
    cpu->regs[1] = cpu->regs[19] + (cpu->regs[22] << 3);
    cpu->regs[30] = PB_BASE + 0xafa94ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xaf91cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_afab8;
    if (((cpu->regs[2] >> 31) & 1)) goto L_afae0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_afae0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xafab4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_afae0;
L_afab8:
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    if (((cpu->regs[2] >> 31) & 1)) goto L_afad0;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_afad0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xafad0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_afad0:
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    goto L_afa5c;
L_afad8:
    PB_STR((cpu->regs[19] + (cpu->regs[2] << 3)), 0ULL);
    goto L_afaf4;
L_afae0:
    PB_STR((cpu->regs[21] + 0), cpu->regs[22]);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xafaf0ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x88290ULL);
L_afaf0:
    cpu->regs[19] = 0ULL;
L_afaf4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP = SP - 64ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_afb54;
L_afb40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xafb4cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1cb820ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_afb78;
    goto L_afb70;
L_afb54:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2384ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xafb6cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_afb40;
L_afb70:
    cpu->regs[19] = 0ULL;
    goto L_afbbc;
L_afb78:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = SP + 12ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xafb88ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_afb70;
    PB_LDRW(cpu->regs[1], (SP + 12));
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0xafb98ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x7b9d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_afbb4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xafbb0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_afb70;
L_afbb4:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_afbbc:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xafbc4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_afbe4;
    cpu->regs[30] = PB_BASE + 0xafbe4ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7c170ULL);
L_afbe4:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48));
    SP = SP + 64ULL;
    return;
}
