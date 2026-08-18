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

void ft__Py_DecodeUTF8_surrogateescape(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[5] = 2ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[30] = PB_BASE + 0x1b56a4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1b5ae8ULL);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1b56e0;
L_1b56b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1b56dc;
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_1b56dc:
    cpu->regs[30] = PB_BASE + 0x1b56e0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1b56e0:
    if ((cpu->regs[19])==0) goto L_1b56e8;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
L_1b56e8:
    cpu->regs[0] = 0ULL;
    goto L_1b56b0;
    SP = SP - 112ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[5];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1b572cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1346a4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5814;
    PB_STR((SP + 96), cpu->regs[27]);
    if ((cpu->regs[20])==0) goto L_1b5868;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 0));
    if ((cpu->regs[22])!=0) goto L_1b5890;
    cpu->regs[27] = 0ULL;
    FLAG_CMP(cpu->regs[19], 30ULL);
    if (FLAG_GT) goto L_1b5a98;
L_1b5750:
    cpu->regs[1] = cpu->regs[20] + 16ULL;
    cpu->regs[6] = 0ULL;
L_1b5758:
    FLAG_CMP(cpu->regs[6], cpu->regs[19]);
    if (FLAG_GE) goto L_1b57dc;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + (cpu->regs[6] << 3)));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(23ULL)));
    if (FLAG_NE) goto L_1b5758;
L_1b5774:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[19], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_1b59fc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(23ULL)));
    if (FLAG_NE) goto L_1b59fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1b579cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x132ce0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    if ((cpu->regs[27])!=0) goto L_1b590c;
L_1b57a8:
    cpu->regs[27] = 0ULL;
L_1b57ac:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 64));
    FLAG_CMP(cpu->regs[27], 0ULL);
    cpu->regs[2] = (FLAG_GT) ? 1 : 0;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 142ULL;
    cpu->regs[30] = PB_BASE + 0x1b57ccULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDR(cpu->regs[27], (SP + 96));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_1b584c;
L_1b57dc:
    cpu->regs[0] = 0ULL;
L_1b57e0:
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_LT) goto L_1b5878;
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    cpu->regs[21] = 0ULL;
L_1b57f0:
    cpu->regs[0] = cpu->regs[26];
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_GE) goto L_1b581c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[21] << 3)));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1b5808ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x132ce0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1b57f0;
L_1b5810:
    PB_LDR(cpu->regs[27], (SP + 96));
L_1b5814:
    cpu->regs[0] = 4294967295ULL;
    goto L_1b584c;
L_1b581c:
    if ((cpu->regs[27])!=0) goto L_1b58a4;
L_1b5820:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 64));
    cpu->regs[2] = cpu->regs[19] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[25]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[27]));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 171ULL;
    cpu->regs[30] = PB_BASE + 0x1b5840ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    PB_LDR(cpu->regs[27], (SP + 96));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
L_1b584c:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_1b5868:
    cpu->regs[19] = 0ULL;
    if ((cpu->regs[22])!=0) goto L_1b5890;
    cpu->regs[27] = 0ULL;
    goto L_1b5750;
L_1b5878:
    cpu->regs[1] = cpu->regs[22] + 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    if ((cpu->regs[1])!=0) goto L_1b57e0;
    goto L_1b5774;
L_1b5890:
    PB_LDR(cpu->regs[27], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[27] << 1);
    FLAG_CMP(cpu->regs[0], 30ULL);
    if (FLAG_LE) goto L_1b5750;
    goto L_1b5774;
L_1b58a4:
    if ((cpu->regs[22])==0) goto L_1b58e4;
    cpu->regs[20] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1b58b0:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[3] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[26];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1b58e4;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0x1b58d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x132ce0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_1b58b0;
L_1b58e4:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1b58fcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1c0fc4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1b5820;
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_1b5814;
L_1b590c:
    cpu->regs[25] = cpu->regs[22] + 16ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[19] = 0ULL;
L_1b591c:
    FLAG_CMP(cpu->regs[19], cpu->regs[27]);
    if (FLAG_GE) goto L_1b59a4;
    PB_LDR(cpu->regs[21], (cpu->regs[25] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[0])!=0) goto L_1b5a38;
    if ((cpu->regs[4])!=0) goto L_1b5a44;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_1b595c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 64));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 105ULL;
    cpu->regs[30] = PB_BASE + 0x1b5954ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
L_1b595c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1b5968ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x132ce0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 64));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 164ULL;
    cpu->regs[30] = PB_BASE + 0x1b598cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[20] = 1ULL;
    cpu->regs[4] = 0ULL;
    goto L_1b591c;
L_1b59a4:
    if ((cpu->regs[4])==0) goto L_1b57ac;
    cpu->regs[4] = cpu->regs[27] - cpu->regs[4];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[5] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1b59c4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x215640ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1b57ac;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 64));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 164ULL;
    cpu->regs[30] = PB_BASE + 0x1b59ecULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1b57ac;
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_1b5814;
L_1b59fc:
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 0), cpu->regs[0]);
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[7] = 162ULL;
    cpu->regs[6] = 145ULL;
    cpu->regs[5] = 103ULL;
    cpu->regs[30] = PB_BASE + 0x1b5a28ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b39e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    if ((cpu->regs[27])==0) goto L_1b57a8;
    goto L_1b590c;
L_1b5a38:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_1b591c;
L_1b5a44:
    cpu->regs[4] = cpu->regs[19] - cpu->regs[4];
    cpu->regs[5] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1b5a60ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x215640ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b5810;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1b595c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 64));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 164ULL;
    cpu->regs[30] = PB_BASE + 0x1b5a88ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1b595c;
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_1b5814;
L_1b5a98:
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 0), cpu->regs[0]);
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[7] = 162ULL;
    cpu->regs[6] = 145ULL;
    cpu->regs[5] = 103ULL;
    cpu->regs[30] = PB_BASE + 0x1b5ac4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1b39e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1b57a8;
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_1b5814;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[1] + 16) + 8);
    { PB_CALL(19, cpu, tlb, PB_BASE + 0xdc780ULL); return; };
}
