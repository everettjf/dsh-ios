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

void ft__PyObject_Call(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 168));
    if (!((cpu->regs[0] >> 11) & 1)) goto L_1266c4;
    PB_LDR(cpu->regs[2], (cpu->regs[6] + 56));
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = SP + 16ULL;
    cpu->regs[5] = cpu->regs[19] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[0], cpu->regs[5]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_1267a0;
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_HS) goto L_126680;
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_LO) goto L_1267a0;
L_126680:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + cpu->regs[2]));
    if ((cpu->regs[1])==0) goto L_1266c4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_12673c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    goto L_1267a4;
L_1266c4:
    PB_LDR(cpu->regs[22], (cpu->regs[6] + 128));
    if ((cpu->regs[22])==0) goto L_126740;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_126780;
L_1266e0:
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1266f0ULL; PB_CALL(1, cpu, tlb, cpu->regs[22]);
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 36));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_12673c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[3] = 0ULL;
    SP = SP + 80ULL;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xe8888ULL); return; };
L_12673c:
    cpu->regs[30] = PB_BASE + 0x126740ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_126740:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12674cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x2337c0ULL);
L_12674c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_12673c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_126780:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x126794ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x26c444ULL);
    PB_LDR(cpu->regs[4], (SP + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1266e0;
    goto L_12674c;
L_1267a0:
    __builtin_trap();
L_1267a4:
    SP = SP - 80ULL;
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[5] + 16));
    if ((cpu->regs[4])==0) goto L_1267e8;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    if ((cpu->regs[1])!=0) goto L_12682c;
L_1267e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1268c0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[5] + 24ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[3] = 0ULL;
    SP = SP + 80ULL;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_12682c:
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[5] + 24ULL;
    cpu->regs[4] = SP;
    cpu->regs[2] = cpu->regs[22];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x126848ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x122d00ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1268cc;
    PB_LDR(cpu->regs[24], (SP + 0));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[22] | 9223372036854775808ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x126868ULL; PB_CALL(7, cpu, tlb, cpu->regs[20]);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12687cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1a76e4ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1268c8;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xe8888ULL); return; };
L_1268c0:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1268c8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1268c8:
    cpu->regs[30] = PB_BASE + 0x1268ccULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1268cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1268c8;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_126900:
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 72)); PB_LDRW(cpu->regs[0], (cpu->regs[0] + 72) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_GT) goto L_127f58;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(24ULL)));
    if (FLAG_LS) goto L_126958;
L_12693c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[0] = 1ULL;
L_126944:
    PB_STRW((cpu->regs[19] + 72), cpu->regs[1]);
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 96ULL;
    return;
L_126958:
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3692ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDRH(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(uint32_t)(cpu->regs[0])) << 1)));
    cpu->regs[0] = PB_BASE + 0x126974ULL;
    cpu->regs[1] = cpu->regs[0] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[1])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[1]); return;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])==0) goto L_126990;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126984:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_1269e4;
L_126990:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12699cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1280a8;
L_1269a0:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
L_1269a4:
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[1]);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 96ULL;
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1269d0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1269e4:
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1269f4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127a14;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126984;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[30] = PB_BASE + 0x126a20ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128128;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 48));
    if ((cpu->regs[22])==0) goto L_126a48;
L_126a34:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GT) goto L_1273ac;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
L_126a48:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 32));
    if ((cpu->regs[22])==0) goto L_126a64;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[21] = 0ULL;
L_126a58:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GT) goto L_127588;
L_126a64:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 32));
    if ((cpu->regs[21])!=0) goto L_127468;
L_126a6c:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 56));
    if ((cpu->regs[2])!=0) goto L_127898;
L_126a74:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 40));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126a88ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1ab500ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1281e0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[3] = cpu->regs[20];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x126aa8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1281d0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126ab8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1ab6a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1281c0;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 24));
    if ((cpu->regs[22])==0) goto L_126b74;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126acc:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_126b74;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126ae8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1281b0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126acc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126b04ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1281a0;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_126bb0;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
L_126b18:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_126bb0;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126b34ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12825c;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126b18;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])==0) goto L_1269a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126b54ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12824c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4ULL));
    PB_STRB((cpu->regs[1] + 80), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    goto L_12693c;
L_126b74:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126b7cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12826c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    if ((cpu->regs[0])==0) goto L_1269a0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126b9cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_126bb0:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])==0) goto L_1269a0;
    cpu->regs[21] = 0ULL;
L_126bbc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x126bdcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128314;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_126bbc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126bf4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128368;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126c04ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128358;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 24));
    if ((cpu->regs[22])==0) goto L_1272d8;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
L_126c18:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_1272d8;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126c34ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128378;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126c18;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[30] = PB_BASE + 0x126c60ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127f20;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 40));
    if ((cpu->regs[21])!=0) goto L_1275e0;
L_126c6c:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 48));
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 56));
    if ((cpu->regs[2])!=0) goto L_127800;
L_126c7c:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_127310;
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126c8c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_127310;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126ca8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128324;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_126c8c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])==0) goto L_1269a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126cc8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ef0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    if ((cpu->regs[1])==0) goto L_1269a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126cdcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])==0) goto L_1273c8;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126d00:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1273c8;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126d1cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127f00;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126d00;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_1269a4;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126d3c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126d58ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1b25a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128338;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_126d3c;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])==0) goto L_126d84;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126d78:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_127448;
L_126d84:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_1269a0;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = 0ULL;
L_126d94:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126db0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12827c;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_126d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126dccULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127e90;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126ddcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_1269a4;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126e00:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126e1cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1b25a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ea0;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_126e00;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    if ((cpu->regs[20])==0) goto L_1269a4;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
L_126e3c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126e58ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127eb0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126e3c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126e74ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12829c;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_1274b8;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_126e88:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1274b8;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x126ea4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12828c;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126e88;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(24ULL)));
    if (FLAG_NE) goto L_1276f4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[30] = PB_BASE + 0x126ed4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1b1940ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_127e40;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[2] = 9ULL;
    FLAG_CMP((cpu->regs[0]) & (cpu->regs[2]), 0);
    if (FLAG_NE) goto L_127dbc;
L_126ee8:
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_126f0c;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[2] = 258ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[21] + 32) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[21] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[21] + 40) + 4);
    cpu->regs[30] = PB_BASE + 0x126f08ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127e30;
L_126f0c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])!=0) goto L_127684;
L_126f14:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126f20ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1f6b90ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127e64;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    if ((cpu->regs[1])==0) goto L_1269a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126f34ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126f54ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ec0;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 16));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[23])==0) goto L_126f74;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
L_126f74:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_12757c;
    cpu->regs[1] = cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x126f90ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127720;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])!=0) goto L_127714;
L_126f9c:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_126fb8;
    cpu->regs[0] = 0ULL;
    cpu->regs[20] = 0ULL;
L_126fac:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_127498;
L_126fb8:
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_126f74;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126fd4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127d8c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    if ((cpu->regs[1])==0) goto L_1269a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x126fe8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[30] = PB_BASE + 0x127018ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12822c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 48));
    if ((cpu->regs[22])==0) goto L_127040;
L_12702c:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_GT) goto L_1276d8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
L_127040:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 32));
    if ((cpu->regs[22])==0) goto L_12705c;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[21] = 0ULL;
L_127050:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_GT) goto L_1276b4;
L_12705c:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 32));
    if ((cpu->regs[22])!=0) goto L_12773c;
L_127064:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 56));
    if ((cpu->regs[2])!=0) goto L_127acc;
L_12706c:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 40));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127080ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1ab500ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127abc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[3] = cpu->regs[20];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1270a0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127aac;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | 8ULL));
    PB_STRB((cpu->regs[3] + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1270c0ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1ab6a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127cb0;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 24));
    if ((cpu->regs[22])==0) goto L_127610;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
L_1270d4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_127610;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1270f0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127d9c;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1270d4;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[22])==0) goto L_12711c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
L_12711c:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_12757c;
    cpu->regs[2] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 16));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12713cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1b1940ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_127bd0;
    cpu->regs[1] = 278ULL;
    FLAG_CMP((cpu->regs[0]) & (cpu->regs[1]), 0);
    if (FLAG_NE) goto L_127b28;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x127168ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127bac;
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[3], (cpu->regs[20] + 64) + 4);
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 72) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127180ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1b1a60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127a98;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_12711c;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 8));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[23])==0) goto L_1271b0;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
L_1271b0:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_12757c;
    cpu->regs[2] = cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[22], (cpu->regs[2] + 16));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1271d0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1b1940ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_127d48;
    cpu->regs[1] = 278ULL;
    FLAG_CMP((cpu->regs[0]) & (cpu->regs[1]), 0);
    if (FLAG_NE) goto L_127cf8;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[22];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1271fcULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ce4;
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[3], (cpu->regs[20] + 64) + 4);
    cpu->regs[1] = cpu->regs[22];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 72) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127214ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1b1a60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127cd0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1271b0;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])==0) goto L_12776c;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_127238:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_12776c;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127254ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1b3460ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128138;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_127238;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])==0) goto L_127280;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_127274:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_1277a8;
L_127280:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 24));
    cpu->regs[21] = 0ULL;
L_127288:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    if ((cpu->regs[22])==0) goto L_1282dc;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
L_127294:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_1282c0;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_1277c8;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1272ac:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1277c8;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1272c8ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1ac2e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1282f4;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1272ac;
L_1272d8:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 32));
    if ((cpu->regs[20])==0) goto L_1269a0;
    cpu->regs[21] = 0ULL;
L_1272e4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x127304ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127b18;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_1272e4;
L_127310:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 24));
    if ((cpu->regs[21])!=0) goto L_12764c;
L_127318:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[3] = cpu->regs[20];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x127334ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128164;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
    if ((cpu->regs[0])!=0) goto L_12795c;
L_127348:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 32));
    if ((cpu->regs[22])==0) goto L_127384;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
    goto L_127378;
L_12735c:
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x12736cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1282ac;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
L_127378:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_12735c;
L_127384:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12738cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1279cc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    if ((cpu->regs[0])!=0) goto L_127930;
L_127398:
    PB_STR((cpu->regs[19] + 56), cpu->regs[23]);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_12693c;
L_1273ac:
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x1273bcULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127f10;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_126a34;
L_1273c8:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 24));
    if ((cpu->regs[21])!=0) goto L_1275ac;
L_1273d0:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_1273ec;
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1273e0:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_127428;
L_1273ec:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 32));
    if ((cpu->regs[20])==0) goto L_1269a0;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1273fc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127418ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128178;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1273fc;
L_127428:
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127438ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1ac2e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128348;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_1273e0;
L_127448:
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127458ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1b3460ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1279f4;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_126d78;
L_127468:
    cpu->regs[22] = 0ULL;
L_12746c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[1], cpu->regs[22]);
    if (FLAG_LE) goto L_126a6c;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x12748cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ed0;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    goto L_12746c;
L_127498:
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1274a8ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127720;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_126fac;
L_1274b8:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])==0) goto L_1269a0;
    cpu->regs[21] = 0ULL;
L_1274c4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x1274e4ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ee0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_1274c4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1274fcULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128098;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[20] + 8) + 8);
    PB_LDRW(cpu->regs[22], (cpu->regs[1] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    cpu->regs[23] = (FLAG_EQ) ? 1 : 0;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 8));
    if ((cpu->regs[2])!=0) goto L_128024;
L_127524:
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[1] = cpu->regs[24];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x127540ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128004;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 80));
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~(0x1ULL << 7)) | ((cpu->regs[23] & 0x1ULL) << 7))));
    PB_STRB((cpu->regs[3] + 80), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_127fc4;
L_12755c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127568ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127fb0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127574ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127f9c;
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_127f80;
L_12757c:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    goto L_1269a4;
L_127588:
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    if ((cpu->regs[1])==0) goto L_1275a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12759cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127a04;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
L_1275a4:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_126a58;
L_1275ac:
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1275b4:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1273d0;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1275d0ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127f30;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_1275b4;
L_1275e0:
    cpu->regs[22] = 0ULL;
L_1275e4:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[1], cpu->regs[22]);
    if (FLAG_LE) goto L_126c6c;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x127604ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127cc0;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    goto L_1275e4;
L_127610:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127618ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128118;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    if ((cpu->regs[0])==0) goto L_1269a0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127638ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1269a4;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    goto L_126944;
L_12764c:
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = 0ULL;
L_127654:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_127318;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0x127674ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127e74;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_127654;
L_127684:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[21] + 32) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[21] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[21] + 40) + 4);
    cpu->regs[30] = PB_BASE + 0x1276a0ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_126f14;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1276b4:
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[0] << 3)));
    if ((cpu->regs[1])==0) goto L_1276d0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1276c8ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12823c;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
L_1276d0:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_127050;
L_1276d8:
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x1276e8ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127e54;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_12702c;
L_1276f4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127700ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_126f14;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127714:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12771cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_126f9c;
L_127720:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12773c:
    cpu->regs[21] = 0ULL;
L_127740:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_LE) goto L_127064;
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x127760ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128148;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_127740;
L_12776c:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_1269a0;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
L_12777c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127798ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127dac;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_12777c;
L_1277a8:
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1277b8ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128304;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_127274;
L_1277c8:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 32));
    cpu->regs[20] = 0ULL;
L_1277d0:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[21])!=0) goto L_127f40;
L_1277dc:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x1277f4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127f48;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_1277d0;
L_127800:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_126c7c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 64) + 4);
    cpu->regs[4] = 0ULL;
    PB_LDRW(cpu->regs[9], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[8], (cpu->regs[20] + 72) + 4);
    cpu->regs[3] = 0ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 0));
    PB_STRW((SP + 0), cpu->regs[9]);
    PB_STRW((SP + 8), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x127834ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x219c24ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128218;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12784cULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x12a000ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_STR((cpu->regs[21] + 120), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 120));
    if ((cpu->regs[0])==0) goto L_128204;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 48));
    if ((cpu->regs[22])==0) goto L_126c7c;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_12786c:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_126c7c;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127888ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x219e48ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1281f0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_12786c;
L_127898:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_126a74;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[0], (cpu->regs[20] + 8) + 8);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 48));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24)); PB_LDR(cpu->regs[7], (cpu->regs[0] + 24) + 8);
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
L_1278bc:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]));
    if ((cpu->regs[5])==0) goto L_128100;
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
L_1278c8:
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_LT) goto L_1280ec;
    cpu->regs[4] = 0ULL;
L_1278d4:
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[9], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[8], (cpu->regs[20] + 72) + 4);
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 0));
    PB_STRW((SP + 0), cpu->regs[9]);
    PB_STRW((SP + 8), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x1278f0ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x219c24ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1280dc;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 56));
    if ((cpu->regs[22])==0) goto L_126a74;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_127904:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_126a74;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x127920ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x219e48ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1280cc;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_127904;
L_127930:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_127398;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127944ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_127398;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_12795c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_127348;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[8] = 33728ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = 2ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = cpu->regs[21] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x127990ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1279e0;
    cpu->regs[5] = 24792ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[5];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 64) + 4);
    cpu->regs[2] = 16ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 72) + 4);
    cpu->regs[30] = PB_BASE + 0x1279b4ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_127348;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_1279cc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_1279e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_1279f4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127a04:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127a14:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127a30ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127bf8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127a40ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127be8;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 24));
    cpu->regs[21] = 0ULL;
L_127a4c:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    if ((cpu->regs[22])==0) goto L_127b94;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
L_127a58:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_127b78;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 32));
    if ((cpu->regs[21])==0) goto L_1269a0;
    cpu->regs[20] = 0ULL;
L_127a6c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LE) goto L_1269a0;
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x127a8cULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127bc0;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_127a6c;
L_127a98:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127aac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127abc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127acc:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_12706c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[0], (cpu->regs[20] + 8) + 8);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 48));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24)); PB_LDR(cpu->regs[7], (cpu->regs[0] + 24) + 8);
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
L_127af0:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]));
    if ((cpu->regs[5])==0) goto L_127c34;
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
L_127afc:
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_GE) goto L_127c3c;
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[7] + (cpu->regs[0] << 3)));
    if ((cpu->regs[0])!=0) goto L_127c98;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    goto L_127af0;
L_127b18:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127b28:
    if (!((cpu->regs[0] >> 2) & 1)) goto L_127c08;
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3968ULL;
L_127b34:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[2] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x127b48ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[2], (cpu->regs[20] + 64) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x127b60ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x8502cULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127b78:
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x127b88ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127b9c;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_127a4c;
L_127b94:
    cpu->regs[1] = 0ULL;
    goto L_127a58;
L_127b9c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127bac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127bc0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127bd0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127be8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127bf8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127c08:
    if (!((cpu->regs[0] >> 4) & 1)) goto L_127c18;
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 4008ULL;
    goto L_127b34;
L_127c18:
    FLAG_CMP((cpu->regs[0]) & (256ULL), 0);
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 4056ULL;
    cpu->regs[0] = cpu->regs[0] + 3888ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_127b34;
L_127c34:
    cpu->regs[6] = 0ULL;
    goto L_127afc;
L_127c3c:
    cpu->regs[4] = 0ULL;
L_127c40:
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 64) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[9], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[8], (cpu->regs[20] + 72) + 4);
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 0));
    PB_STRW((SP + 0), cpu->regs[9]);
    PB_STRW((SP + 8), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x127c5cULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x219c24ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_127ca0;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 56));
    cpu->regs[21] = 0ULL;
L_127c68:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    if ((cpu->regs[22])==0) goto L_127e88;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
L_127c74:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_12706c;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x127c8cULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x219e48ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128388;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_127c68;
L_127c98:
    cpu->regs[4] = 1ULL;
    goto L_127c40;
L_127ca0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127cb0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127cc0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127cd0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127ce4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127cf8:
    if (!((cpu->regs[0] >> 2) & 1)) goto L_127d60;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 16ULL;
L_127d04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x127d18ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[2], (cpu->regs[20] + 64) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x127d30ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x8502cULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127d48:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127d60:
    if (!((cpu->regs[0] >> 4) & 1)) goto L_127d70;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 56ULL;
    goto L_127d04;
L_127d70:
    FLAG_CMP((cpu->regs[0]) & (256ULL), 0);
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 104ULL;
    cpu->regs[0] = cpu->regs[0] + 3928ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_127d04;
L_127d8c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127d9c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127dac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127dbc:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_126ee8;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_126f0c;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2416));
    FLAG_CMP((cpu->regs[0]) & (1ULL), 0);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[3] = PB_BASE + 0x289000ULL;
    cpu->regs[3] = cpu->regs[3] + 3928ULL;
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x127e04ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[2], (cpu->regs[20] + 64) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 72) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x127e1cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x8502cULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127e30:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127e40:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127e54:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127e64:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127e74:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 2ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127e88:
    cpu->regs[1] = 0ULL;
    goto L_127c74;
L_127e90:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127ea0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127eb0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127ec0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127ed0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127ee0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127ef0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f00:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f10:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f20:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f30:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f40:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    goto L_1277dc;
L_127f48:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f58:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3496ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x127f70ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_127f80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x127f88ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128018;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1269a4;
L_127f9c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127fb0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_127fc4:
    PB_LDR(cpu->regs[6], (cpu->regs[20] + 24));
    cpu->regs[4] = 26888ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[6] + 32) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[6] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[6] + 40) + 4);
    cpu->regs[30] = PB_BASE + 0x127fecULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12755c;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128004:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128018:
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128024:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_127524;
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 64)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 64) + 4);
    cpu->regs[1] = cpu->regs[24];
    PB_LDRW(cpu->regs[9], (cpu->regs[20] + 72)); PB_LDRW(cpu->regs[8], (cpu->regs[20] + 72) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 0));
    cpu->regs[4] = 0ULL;
    PB_STRW((SP + 0), cpu->regs[9]);
    cpu->regs[3] = 0ULL;
    PB_STRW((SP + 8), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x128058ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x219c24ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1280b8;
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[20] + 16));
L_128068:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    if ((cpu->regs[25])==0) goto L_128110;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
L_128074:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_128158;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[25] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x12808cULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x219e48ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128188;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_128068;
L_128098:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1280a8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1280b8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_1280cc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1280dc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1280ec:
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[7] + (cpu->regs[0] << 3)));
    if ((cpu->regs[0])!=0) goto L_128108;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    goto L_1278bc;
L_128100:
    cpu->regs[6] = 0ULL;
    goto L_1278c8;
L_128108:
    cpu->regs[4] = 1ULL;
    goto L_1278d4;
L_128110:
    cpu->regs[1] = 0ULL;
    goto L_128074;
L_128118:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128128:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128138:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128148:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128158:
    PB_LDR(cpu->regs[25], (SP + 80));
    cpu->regs[21] = 1ULL;
    goto L_127524;
L_128164:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128178:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128188:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[25], (SP + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_1281a0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1281b0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1281c0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1281d0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1281e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1281f0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128204:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128218:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_12822c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12823c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12824c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12825c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12826c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12827c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12828c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_12829c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1282ac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_1282c0:
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x1282d0ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1282e4;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_127288;
L_1282dc:
    cpu->regs[1] = 0ULL;
    goto L_127294;
L_1282e4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_1282f4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128304:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128314:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128324:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_126944;
L_128338:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128348:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128358:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128368:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128378:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
L_128388:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_126944;
    /* nop */
    /* nop */
L_1283a0:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 72)); PB_LDRW(cpu->regs[1], (cpu->regs[0] + 72) + 4);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_128be4;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(26ULL)));
    if (FLAG_HI) goto L_128468;
    cpu->regs[3] = PB_BASE + 0x2b4000ULL;
    cpu->regs[3] = cpu->regs[3] + 3744ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRH(cpu->regs[3], (cpu->regs[3] + (((uint64_t)(uint32_t)(cpu->regs[1])) << 1)));
    cpu->regs[1] = PB_BASE + 0x1283f8ULL;
    cpu->regs[3] = cpu->regs[1] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[3])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[3]); return;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_128584;
    cpu->regs[2] = 16ULL;
L_128410:
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 32) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 40) + 4);
    cpu->regs[30] = PB_BASE + 0x128420ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12845c;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 4ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_12845c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    cpu->regs[30] = PB_BASE + 0x128458ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128b00;
L_12845c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_128468:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 72), cpu->regs[2]);
L_128470:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
L_128480:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128488ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x1283a0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
L_128494:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1284a8ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_128520;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_128520;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1284ccULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_128520;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1284e8ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[22] = 2ULL;
    cpu->regs[1] = 2ULL;
L_1284f4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_128520;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x128510ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_1284f4;
L_128520:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[20])!=0) goto L_128560;
    cpu->regs[0] = 0ULL;
L_128534:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_12845c;
    cpu->regs[0] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_128558;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128554ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128bcc;
L_128558:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
L_128560:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    goto L_128534;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128574ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
L_128578:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    if ((cpu->regs[1])==0) goto L_12845c;
    goto L_128480;
L_128584:
    cpu->regs[2] = 2ULL;
    goto L_128410;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128598ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 24));
    if ((cpu->regs[21])==0) goto L_12845c;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1285ac:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_12845c;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1285c8ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_1285ac;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1285e4ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    goto L_128480;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1285fcULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    goto L_128480;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_128684;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = 0ULL;
L_128618:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GE) goto L_128680;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x128634ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_128618;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_128684;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
    goto L_128674;
L_128658:
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x128668ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
L_128674:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_128658;
L_128680:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
L_128684:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_128468;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_128684;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1286a0:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_128680;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1286bcULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_1286a0;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_128684;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
    goto L_1286fc;
L_1286e0:
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1286f0ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
L_1286fc:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_1286e0;
    goto L_128680;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])==0) goto L_128720;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12871cULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
L_128720:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    if ((cpu->regs[1])==0) goto L_128578;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128730ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128578;
L_128734:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
L_128738:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128470;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[22])==0) goto L_128764;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
L_128764:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_128abc;
    cpu->regs[0] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_128784;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128780ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
L_128784:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_128764;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[0] + 80),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[0] >> 31) & 1)) goto L_128b84;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 48));
    if ((cpu->regs[22])==0) goto L_1287c4;
L_1287b0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GT) goto L_128b3c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
L_1287c4:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 32));
    if ((cpu->regs[22])==0) goto L_1287e0;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[21] = 0ULL;
L_1287d4:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_GT) goto L_128b58;
L_1287e0:
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 32) + 4);
    cpu->regs[13] = 48600ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 40) + 4);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[13];
    cpu->regs[30] = PB_BASE + 0x128808ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128818ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x1ab6a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128828ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128834ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128494;
L_128840:
    PB_STRW((cpu->regs[19] + 72), cpu->regs[2]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128470;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 744ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128864ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x1b1c64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])==0) goto L_12887c;
L_128870:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128878ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
L_12887c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 72));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 76));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4ULL));
    PB_STRB((cpu->regs[0] + 72), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_12845c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1288a0ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xcf41cULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128470;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[20] + 8) + 8);
    cpu->regs[11] = 49424ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[11];
    cpu->regs[30] = PB_BASE + 0x1288d0ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x1ab810ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[20] + 8) + 8);
    cpu->regs[12] = 45464ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[12];
    cpu->regs[30] = PB_BASE + 0x128908ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x1ab810ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128928ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128938ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    goto L_128480;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_128684;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = 0ULL;
L_128954:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_128680;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x128970ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_128954;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 768ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128994ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x1b1c64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1289a4ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x1283a0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 8ULL));
    PB_STRB((cpu->regs[1] + 72), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[5], (cpu->regs[20] + 8) + 8);
    cpu->regs[9] = 41848ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 24));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x1289ecULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x1ab810ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 744ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128a14ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x1b1c64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    goto L_128870;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 160ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128a34ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x1b1c64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 84));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_128c68;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 76));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128c10;
L_128a50:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128a5cULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128df0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128a6cULL; PB_CALL(157, cpu, tlb, PB_BASE + 0x1283a0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128494;
    cpu->regs[0] = cpu->regs[2];
    PB_STRW((cpu->regs[19] + 72), cpu->regs[2]);
    goto L_128738;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[20] + 8) + 8);
    cpu->regs[10] = 56488ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[10];
    cpu->regs[30] = PB_BASE + 0x128aa8ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x1ab810ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
L_128abc:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_12845c;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_128ad8;
L_128ad0:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
L_128ad8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_12845c;
    cpu->regs[1] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x128af4ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128ad0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    goto L_128738;
L_128b00:
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 32) + 4);
    cpu->regs[8] = 26712ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 40) + 4);
    cpu->regs[2] = 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x128b28ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x128ea0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128840;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128468;
L_128b3c:
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x128b4cULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_1287b0;
L_128b58:
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[0] << 3)));
    if ((cpu->regs[1])!=0) goto L_128b6c;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_1287d4;
L_128b6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128b74ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128734;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_1287d4;
L_128b84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 680ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128b9cULL; PB_CALL(163, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[2], (cpu->regs[20] + 32) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 40) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x128bb4ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x8502cULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128470;
L_128bcc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 2ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_128470;
L_128be4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3496ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128bfcULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    goto L_128470;
L_128c10:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 8));
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 514ULL;
L_128c30:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[24], (cpu->regs[0] + (cpu->regs[21] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 76));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128cec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x128c50ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x1b1940ULL);
    cpu->regs[0] = cpu->regs[0] & cpu->regs[25];
    FLAG_CMP(cpu->regs[0], 514ULL);
    if (FLAG_EQ) goto L_128ca0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
L_128c60:
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    goto L_128c30;
L_128c68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128c80ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[2], (cpu->regs[20] + 32) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 40) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x128c98ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x8502cULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    goto L_128738;
L_128ca0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[1] + 264ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128cbcULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x11f220ULL);
L_128cbc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[2], (cpu->regs[22] + 32) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[22] + 40) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x128cd4ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x8502cULL);
L_128cd4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_128738;
L_128cec:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 64));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128d6c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x128d04ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0x1b1940ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[22] + 32) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[22] + 40) + 4);
    if (((cpu->regs[0] >> 0) & 1)) goto L_128e00;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x128d24ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128cd4;
L_128d28:
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[3], (cpu->regs[22] + 32) + 4);
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[5], (cpu->regs[22] + 40) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128d3cULL; PB_CALL(173, cpu, tlb, PB_BASE + 0x1b1a60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128cd4;
    PB_LDRW(cpu->regs[4], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[22] + 32) + 4);
    cpu->regs[3] = cpu->regs[24];
    PB_LDRW(cpu->regs[6], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[22] + 40) + 4);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x128d5cULL; PB_CALL(174, cpu, tlb, PB_BASE + 0x128ea0ULL);
L_128d5c:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128e18;
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_128a50;
L_128d6c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_128e60;
    if (FLAG_HI) goto L_128c60;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_128e44;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_128e7c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_128e28;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_128c60;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[22] + 32) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[6], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[22] + 40) + 4);
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x128db4ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128cd4;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[3], (cpu->regs[22] + 32) + 4);
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[5], (cpu->regs[22] + 40) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128dccULL; PB_CALL(176, cpu, tlb, PB_BASE + 0x1b1a60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_128cd4;
    PB_LDRW(cpu->regs[4], (cpu->regs[22] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[22] + 32) + 4);
    cpu->regs[3] = cpu->regs[24];
    PB_LDRW(cpu->regs[6], (cpu->regs[22] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[22] + 40) + 4);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x128decULL; PB_CALL(177, cpu, tlb, PB_BASE + 0x128ea0ULL);
    goto L_128d5c;
L_128df0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    goto L_128738;
L_128e00:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x128e10ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0x128ea0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_128d28;
    goto L_128cd4;
L_128e18:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    goto L_128738;
L_128e28:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 344ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128e40ULL; PB_CALL(179, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_128cbc;
L_128e44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 520ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128e5cULL; PB_CALL(180, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_128cbc;
L_128e60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 424ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128e78ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_128cbc;
L_128e7c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 600ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x128e94ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_128cbc;
    /* nop */
    /* nop */
L_128ea0:
    SP = SP - 128ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[4];
    cpu->regs[26] = cpu->regs[5];
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[7];
    PB_LDR(cpu->regs[8], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[19], (cpu->regs[23] + 56));
    PB_LDR(cpu->regs[9], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[9]);
    cpu->regs[9] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[8] + 120));
    PB_STRW((SP + 12), cpu->regs[6]);
    if ((cpu->regs[0])!=0) goto L_1292a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x128f0cULL; PB_CALL(183, cpu, tlb, PB_BASE + 0x129360ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129234;
L_128f14:
    PB_LDR(cpu->regs[27], (cpu->regs[22] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_1290a4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1290e8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1290e8;
L_128f44:
    cpu->regs[20] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x128f58ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])==0) goto L_1290c0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x128f68ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0x129708ULL);
    PB_LDRW(cpu->regs[1], (SP + 16));
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12915c;
    if (((cpu->regs[21] >> 2) & 1)) goto L_1292ec;
L_128f78:
    if (((cpu->regs[21] >> 10) & 1)) goto L_129318;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    cpu->regs[20] = cpu->regs[0] | cpu->regs[20];
L_128f84:
    PB_LDRB(cpu->regs[0], (cpu->regs[22] + 80));
    if (((cpu->regs[0] >> 6) & 1)) goto L_1291dc;
L_128f8c:
    cpu->regs[0] = cpu->regs[20] + 5ULL;
    FLAG_CMP(cpu->regs[0], 261ULL);
    if (FLAG_HI) goto L_129044;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 5ULL));
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[20] = ((cpu->regs[20] & 0xffffffffULL) << 5);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    cpu->regs[20] = cpu->regs[20] + 3048ULL;
    cpu->regs[24] = cpu->regs[20] + cpu->regs[24];
    if (!((cpu->regs[0] >> 29) & 1)) goto L_129074;
L_128fbc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_129100;
L_128fc8:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_128fd8;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
L_128fd8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x128fe8ULL; PB_CALL(186, cpu, tlb, PB_BASE + 0xddf8cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_129084;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12911c;
L_128ff4:
    if (((cpu->regs[21] >> 2) & 1)) goto L_129108;
    if (((cpu->regs[21] >> 0) & 1)) goto L_12923c;
L_128ffc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_129144;
L_129004:
    cpu->regs[0] = 1ULL;
L_129008:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_129298;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_129044:
    cpu->regs[0] = 1073741823ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[1] = 2147483646ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HI) goto L_12917c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x129060ULL; PB_CALL(187, cpu, tlb, PB_BASE + 0xe3e84ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129220;
L_129068:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_128fbc;
L_129074:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1882ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x129084ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_129084:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_129220;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_129220;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1290a0ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_129220;
L_1290a4:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1290b4ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0x9bb50ULL);
    /* nop */
    /* nop */
    /* nop */
L_1290c0:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1290d4ULL; PB_CALL(191, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_129134;
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_128f84;
L_1290e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1290f0ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_128f44;
    goto L_1290c0;
L_129100:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_128fc8;
L_129108:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 40));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x129114ULL; PB_CALL(193, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_128ffc;
    goto L_129220;
L_12911c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_128ff4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x129130ULL; PB_CALL(194, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_128ff4;
L_129134:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_129220;
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_128f84;
L_129144:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_129004;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x129158ULL; PB_CALL(195, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_129004;
L_12915c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x129174ULL; PB_CALL(196, cpu, tlb, PB_BASE + 0x1d5940ULL);
    if (!((cpu->regs[21] >> 2) & 1)) goto L_128f78;
    goto L_1292ec;
L_12917c:
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[25] = (FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[20])) : cpu->regs[20];
    FLAG_CMP(0ULL, cpu->regs[25]);
    cpu->regs[26] = (FLAG_NE) ? 1 : 0;
    cpu->regs[26] = ((uint32_t)(cpu->regs[26] + 2ULL));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x12919cULL; PB_CALL(197, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129220;
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = 4294967295ULL;
    cpu->regs[1] = ((uint32_t)((FLAG_GT) ? ((uint64_t)(-(int64_t)cpu->regs[0])) : cpu->regs[0]));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - cpu->regs[1]));
    cpu->regs[1] = cpu->regs[24] + 24ULL;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[26] = cpu->regs[0] | (cpu->regs[26] << 3);
    PB_STR((cpu->regs[24] + 16), cpu->regs[26]);
L_1291c8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[25] & 1073741823ULL));
    PB_STRW(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 4;
    cpu->regs[25] = cpu->regs[25] >> 30;
    if ((cpu->regs[25])!=0) goto L_1291c8;
    goto L_129068;
L_1291dc:
    cpu->regs[0] = 9ULL;
    cpu->regs[0] = cpu->regs[20] & cpu->regs[0];
    cpu->regs[20] = cpu->regs[20] | 512ULL;
    if ((cpu->regs[0])==0) goto L_128f8c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[1] + 904ULL;
L_129200:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x129208ULL; PB_CALL(198, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[28] + 1ULL));
    PB_LDRW(cpu->regs[3], (SP + 12));
    cpu->regs[2] = ((uint32_t)(cpu->regs[26] + 1ULL));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x129220ULL; PB_CALL(199, cpu, tlb, PB_BASE + 0x8502cULL);
L_129220:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_129234;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_129308;
L_129234:
    cpu->regs[0] = 0ULL;
    goto L_129008;
L_12923c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 40));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x129248ULL; PB_CALL(200, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_12929c;
    cpu->regs[30] = PB_BASE + 0x129250ULL; PB_CALL(201, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[21] = cpu->regs[21] | cpu->regs[0];
L_129254:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12925cULL; PB_CALL(202, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129220;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 40));
    cpu->regs[30] = PB_BASE + 0x129274ULL; PB_CALL(203, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_129328;
    if (((cpu->regs[1] >> 31) & 1)) goto L_128ffc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_128ffc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x129294ULL; PB_CALL(204, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_128ffc;
L_129298:
    cpu->regs[30] = PB_BASE + 0x12929cULL; PB_CALL(205, cpu, tlb, PB_BASE + 0x7c170ULL);
L_12929c:
    cpu->regs[30] = PB_BASE + 0x1292a0ULL; PB_CALL(206, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_129254;
    goto L_129220;
L_1292a8:
    cpu->regs[30] = PB_BASE + 0x1292acULL; PB_CALL(207, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_129234;
    if (FLAG_NE) goto L_1292d0;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1292c8;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
L_1292c8:
    cpu->regs[19] = cpu->regs[24];
    goto L_128f14;
L_1292d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1292dcULL; PB_CALL(208, cpu, tlb, PB_BASE + 0x129360ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_128f14;
    cpu->regs[0] = 0ULL;
    goto L_129008;
L_1292ec:
    if (!((cpu->regs[20] >> 2) & 1)) goto L_128f78;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = cpu->regs[1] + 824ULL;
    goto L_129200;
L_129308:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x129310ULL; PB_CALL(209, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_129008;
L_129318:
    if (((cpu->regs[20] >> 10) & 1)) goto L_129344;
    cpu->regs[0] = 1026ULL;
    cpu->regs[20] = cpu->regs[20] | cpu->regs[0];
    goto L_128f84;
L_129328:
    if (((cpu->regs[1] >> 31) & 1)) goto L_129220;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_129220;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x129340ULL; PB_CALL(210, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_129220;
L_129344:
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = cpu->regs[1] + 872ULL;
    goto L_129200;
    /* nop */
L_129360:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[0])==0) goto L_1293ac;
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1293ac;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 32));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12951c;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_129570;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_129550;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 40));
L_1293a4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_1293d0;
L_1293ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_12950c;
L_1293b8:
    cpu->regs[21] = cpu->regs[19];
L_1293bc:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1293d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1293dcULL; PB_CALL(211, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_NE) goto L_1293ac;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x1293f4ULL; PB_CALL(212, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_NE) goto L_129410;
    cpu->regs[1] = cpu->regs[22] - 2ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x129408ULL; PB_CALL(213, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_1293ac;
L_129410:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 16));
    cpu->regs[4] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 46ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x129434ULL; PB_CALL(214, cpu, tlb, PB_BASE + 0x1348ccULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_129568;
L_12943c:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x129448ULL; PB_CALL(215, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_129514;
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_EQ) goto L_1294fc;
    cpu->regs[23] = cpu->regs[23] - cpu->regs[24];
    cpu->regs[1] = 9223372036854775806ULL;
    cpu->regs[0] = cpu->regs[22] + cpu->regs[23];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_129620;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    cpu->regs[1] = 127ULL;
    if (!((cpu->regs[2] >> 6) & 1)) goto L_1295f0;
L_129478:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    if (!((cpu->regs[2] >> 6) & 1)) goto L_1295b0;
L_129480:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x129488ULL; PB_CALL(216, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_129638;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[2] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_129618;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[21] + 40ULL;
    cpu->regs[0] = cpu->regs[21] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_1294ac:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12959c;
    cpu->regs[1] = 95ULL;
    PB_STRB((cpu->regs[0] + 0), cpu->regs[1]);
L_1294bc:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1294d4ULL; PB_CALL(217, cpu, tlb, PB_BASE + 0x20736cULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_12957c;
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1294f0ULL; PB_CALL(218, cpu, tlb, PB_BASE + 0x20736cULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_12957c;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1293bc;
L_1294fc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1293b8;
L_12950c:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1293b8;
L_129514:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_12943c;
L_12951c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_129540;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_12955c;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[19] + 40ULL;
    cpu->regs[0] = cpu->regs[19] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_1293a4;
L_129540:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12954cULL; PB_CALL(219, cpu, tlb, PB_BASE + 0x1ac5acULL);
    goto L_1293a4;
L_129550:
    cpu->regs[0] = cpu->regs[19] + 56ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_1293a4;
L_12955c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_1293a4;
L_129568:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1293ac;
L_129570:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_1293a4;
L_12957c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_129638;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_129638;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x129598ULL; PB_CALL(220, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_129638;
L_12959c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_129644;
    cpu->regs[1] = 95ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1294bc;
L_1295b0:
    cpu->regs[2] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_129610;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    cpu->regs[3] = 65535ULL;
    cpu->regs[4] = 1114111ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[4];
L_1295cc:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LS) goto L_129480;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_129658;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 65535ULL;
    cpu->regs[2] = 1114111ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_129480;
L_1295f0:
    cpu->regs[2] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_129650;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 65535ULL;
    cpu->regs[2] = 1114111ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_129478;
L_129610:
    cpu->regs[3] = 255ULL;
    goto L_1295cc;
L_129618:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 56));
    goto L_1294ac;
L_129620:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 984ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x129638ULL; PB_CALL(221, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_129638:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[21] = 0ULL;
    goto L_1293bc;
L_129644:
    cpu->regs[1] = 95ULL;
    PB_STRH((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1294bc;
L_129650:
    cpu->regs[1] = 255ULL;
    goto L_129478;
L_129658:
    cpu->regs[1] = 255ULL;
    goto L_129480;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 4ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 2ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = (FLAG_LS) ? 1 : 0;
    return;
    /* nop */
    /* nop */
    /* nop */
}
