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

void ft__PyLong_FormatBytesWriter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 32ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_23cba4;
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[6] = SP;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23cb70ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x168640ULL);
L_23cb70:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23cbc0;
    PB_LDR(cpu->regs[0], (SP + 0));
L_23cb7c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_23cbbc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_23cba4:
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[4] = SP;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23cbb8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x12df40ULL);
    goto L_23cb70;
L_23cbbc:
    cpu->regs[30] = PB_BASE + 0x23cbc0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23cbc0:
    cpu->regs[0] = 0ULL;
    goto L_23cb7c;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_23cccc;
L_23cc00:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x23cc08ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23cd40;
    cpu->regs[30] = PB_BASE + 0x23cc14ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_23cd28;
L_23cc20:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23cd40;
L_23cc28:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0x23cc34ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1fbcc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23cce8;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    cpu->regs[0] = 9223372036854775807ULL;
    PB_LDRW(cpu->regs[22], (SP + 4));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_23cd08;
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23cc58ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1e6c20ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23cce8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_23ccfc;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 40));
L_23cc6c:
    if (((cpu->regs[19] >> 63) & 1)) goto L_23ccf0;
L_23cc70:
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[21] : cpu->regs[19];
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    cpu->regs[2] = cpu->regs[21] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23cc8cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_STRB((cpu->regs[20] + cpu->regs[19]), cpu->regs[22]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_23cc98:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_23ccc8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_23ccc8:
    cpu->regs[30] = PB_BASE + 0x23ccccULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23cccc:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2936ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x23cce4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23cc00;
L_23cce8:
    cpu->regs[0] = 0ULL;
    goto L_23cc98;
L_23ccf0:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[21];
    cpu->regs[19] = cpu->regs[19] & ~(((uint64_t)((int64_t)cpu->regs[19] >> 63)));
    goto L_23cc70;
L_23ccfc:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3336));
    goto L_23cc6c;
L_23cd08:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 3056ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23cd20ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_23cc98;
L_23cd28:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_23cc20;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23cd3cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23cc20;
L_23cd40:
    cpu->regs[30] = PB_BASE + 0x23cd44ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_23cce8;
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_23cc28;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 47952ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x23cd74ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x225b60ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    if ((cpu->regs[2])==0) goto L_23cd98;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 680ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_23cd98:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 688ULL;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x23cdc4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23cdfc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_23cde8;
    if (((cpu->regs[0] >> 63) & 1)) goto L_23ce14;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_23cde4:
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
L_23cde8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_23cdf0:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_23cdfc:
    cpu->regs[30] = PB_BASE + 0x23ce00ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_23ce1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_23cde4;
    goto L_23cde8;
L_23ce14:
    cpu->regs[1] = 0ULL;
    goto L_23cde4;
L_23ce1c:
    cpu->regs[0] = 0ULL;
    goto L_23cdf0;
    SP = SP - 128ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_23cf44;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_23cfcc;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[21] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_23cf4c;
L_23ce74:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_23cfbc;
L_23ce80:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 8));
    if ((cpu->regs[19])==0) goto L_23cefc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_23d010;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x23cea0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23cf88;
    cpu->regs[30] = PB_BASE + 0x23ceacULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_23d058;
    FLAG_CMP(cpu->regs[21], 2ULL);
    if (FLAG_NE) goto L_23cefc;
    cpu->regs[2] = 0ULL;
L_23cec4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_23cf40;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0x23d080ULL); return; };
L_23cefc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_23d034;
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x23cf14ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23cf88;
    cpu->regs[30] = PB_BASE + 0x23cf20ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_23d058;
    if ((cpu->regs[19])!=0) goto L_23cec4;
    cpu->regs[19] = PB_BASE + 0x283000ULL;
    cpu->regs[19] = cpu->regs[19] + 1576ULL;
    goto L_23cec4;
L_23cf40:
    cpu->regs[30] = PB_BASE + 0x23cf44ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23cf44:
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[21] = cpu->regs[2] + cpu->regs[21];
L_23cf4c:
    cpu->regs[2] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 4072ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23cf80ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_23ce74;
L_23cf88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_23cf40;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_23cfbc:
    cpu->regs[19] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 1576ULL;
    goto L_23cec4;
L_23cfcc:
    cpu->regs[0] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 4072ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23cffcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23cf88;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[19];
    goto L_23ce80;
L_23d010:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x23d030ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_23cf88;
L_23d034:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x23d054ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_23cf88;
L_23d058:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23d070ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_23cf88;
    /* nop */
    /* nop */
    /* nop */
}
