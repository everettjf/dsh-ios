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

void ft_PyInit_atexit(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[0] + 272ULL;
    cpu->regs[0] = cpu->regs[0] + 1408ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = PB_BASE + 0x51e000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[2] + 3856ULL;
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[2] - 144ULL;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x7f1a8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7f1e8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7f1b8;
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0x7f1b4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7f2ecULL);
    goto L_7f1bc;
L_7f1b8:
    cpu->regs[0] = 0ULL;
L_7f1bc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_7f1dc;
    cpu->regs[30] = PB_BASE + 0x7f1dcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7f1dc:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_7f1e8:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    PB_STR((SP + 64), cpu->regs[25]);
    if (!((cpu->regs[1] >> 24) & 1)) goto L_7f22c;
    cpu->regs[30] = PB_BASE + 0x7f214ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7f2cc;
    cpu->regs[30] = PB_BASE + 0x7f224ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7f248;
    goto L_7f2cc;
L_7f22c:
    if (((cpu->regs[1] >> 28) & 1)) goto L_7f250;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 944ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7f248ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_7f248:
    cpu->regs[0] = 0ULL;
    goto L_7f2d4;
L_7f250:
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[24] = cpu->regs[1] & 16777216ULL;
    cpu->regs[30] = PB_BASE + 0x7f260ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7f248;
L_7f268:
    cpu->regs[19] = cpu->regs[20] + cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    FLAG_CMP(cpu->regs[20], cpu->regs[24]);
    if (FLAG_LS) goto L_7f2b0;
    cpu->regs[19] = cpu->regs[19] >> 1;
    cpu->regs[1] = cpu->regs[19] << 4;
    cpu->regs[25] = cpu->regs[22] + (cpu->regs[19] << 4);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0x7f28cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7ae60ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_7f2a8;
    if (FLAG_EQ) goto L_7f2a0;
    cpu->regs[24] = cpu->regs[19] + 1ULL;
    goto L_7f268;
L_7f2a0:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 8));
    goto L_7f2cc;
L_7f2a8:
    cpu->regs[20] = cpu->regs[19];
    goto L_7f268;
L_7f2b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 992ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7f2c8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_7f248;
L_7f2cc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[3]);
L_7f2d4:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_7f2ec:
    SP = SP - 320ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 272), cpu->regs[29]); PB_STR((SP + 272) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 272ULL;
    PB_STR((SP + 288), cpu->regs[19]); PB_STR((SP + 288) + 8, cpu->regs[20]);
    PB_STR((SP + 304), cpu->regs[21]); PB_STR((SP + 304) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = SP + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 264), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7f320ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 255ULL;
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x7f338ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c0f0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7f35c;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7f3c0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7f358ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_7f3c8;
L_7f35c:
    FLAG_CMP(cpu->regs[0], 254ULL);
    if (FLAG_LS) goto L_7f3ac;
    cpu->regs[30] = PB_BASE + 0x7f368ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7f37c;
    cpu->regs[30] = PB_BASE + 0x7f374ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_7f3c8;
L_7f37c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7f38cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c0f0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x7f39cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1931c8ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7f3a8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_7f3c8;
L_7f3ac:
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7f3b8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1931c8ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_7f3c8;
L_7f3c0:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_7f3c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 264));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_7f3e8;
    cpu->regs[30] = PB_BASE + 0x7f3e8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7f3e8:
    PB_LDR(cpu->regs[29], (SP + 272)); PB_LDR(cpu->regs[30], (SP + 272) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 288)); PB_LDR(cpu->regs[20], (SP + 288) + 8);
    PB_LDR(cpu->regs[21], (SP + 304)); PB_LDR(cpu->regs[22], (SP + 304) + 8);
    SP = SP + 320ULL;
    return;
}
