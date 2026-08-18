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

void ft__PyObject_FastCallDictTstate(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[20] & 9223372036854775807ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 168));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[2];
    if (!((cpu->regs[0] >> 11) & 1)) goto L_edc0c;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 56));
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[4] = SP;
    cpu->regs[5] = cpu->regs[19] + cpu->regs[7];
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[4], cpu->regs[5]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_edca8;
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_HS) goto L_edae0;
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    FLAG_CMP(SP, cpu->regs[5]);
    if (FLAG_LO) goto L_edca8;
L_edae0:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + cpu->regs[7]));
    if ((cpu->regs[22])==0) goto L_edc0c;
    if ((cpu->regs[3])!=0) goto L_edb7c;
L_edaec:
    cpu->regs[0] = PB_BASE + 0x11d000ULL;
    cpu->regs[0] = cpu->regs[0] + 1996ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_edbf4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xedb14ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 48));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    if (!((cpu->regs[2] >> 0) & 1)) goto L_edc54;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xedb38ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_edbec;
L_edb58:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 96ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe8888ULL); return; };
L_edb7c:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 16));
    if ((cpu->regs[0])==0) goto L_edaec;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xedb90ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x122d00ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_edc74;
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[2] = cpu->regs[20] | 9223372036854775808ULL;
    PB_LDR(cpu->regs[25], (SP + 0));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xedbb4ULL; PB_CALL(5, cpu, tlb, cpu->regs[22]);
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xedbc8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1a76e4ULL);
    PB_LDR(cpu->regs[25], (SP + 80));
L_edbcc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[20];
    if (FLAG_EQ) goto L_edb58;
L_edbec:
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0xedbf4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_edbf4:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xedc04ULL; PB_CALL(8, cpu, tlb, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[0];
    goto L_edbcc;
L_edc0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[4], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[2]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_edbec;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xea120ULL); return; };
L_edc54:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xedc6cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_edbcc;
L_edc74:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_edbec;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_edca8:
    PB_STR((SP + 80), cpu->regs[25]);
    __builtin_trap();
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xedcd8ULL; PB_CALL(11, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[3])!=0) goto L_edd34;
L_edce0:
    cpu->regs[4] = cpu->regs[4] & 9223372036854775807ULL; FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_NE) goto L_edd74;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_edd58;
L_edcfc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    if ((cpu->regs[2])==0) goto L_edd50;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 5) & 1)) goto L_eddd0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xedd1cULL; PB_CALL(12, cpu, tlb, cpu->regs[2]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
L_edd28:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_edd34:
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0xedd48ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x192fe0ULL);
    PB_LDR(cpu->regs[4], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_edce0;
L_edd50:
    cpu->regs[0] = 0ULL;
    goto L_edd28;
L_edd58:
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    cpu->regs[30] = PB_BASE + 0xedd68ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x26c444ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_edcfc;
    cpu->regs[0] = 0ULL;
    goto L_edd28;
L_edd74:
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0xedd80ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_edd50;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[4], (SP + 40));
    cpu->regs[3] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[2] = cpu->regs[2] + 4032ULL;
    cpu->regs[30] = PB_BASE + 0xeddacULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x225d40ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_edd50;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_edd50;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xeddc8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_edd28;
L_eddd0:
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xedddcULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    goto L_edd28;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -16));
    if ((cpu->regs[1])==0) goto L_edf44;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    cpu->regs[3] = PB_BASE + 0xed000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 48));
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[3] + 3564ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_edf5c;
L_ede44:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xede58ULL; PB_CALL(19, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[20])==0) goto L_edf74;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 152));
    cpu->regs[1] = cpu->regs[20] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_edf88;
L_ede70:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[2])!=0) goto L_edf68;
L_ede80:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 9) & 1)) goto L_edef8;
L_ede8c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_edea8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_edea8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_edf24;
L_edea8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_edec4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_edec4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_edf34;
L_edec4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xedeccULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    if ((cpu->regs[20])==0) goto L_edeec;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_edeec;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 160));
    if ((cpu->regs[2])!=0) goto L_edfa4;
L_edeec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_edef8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_ede8c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_ede8c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_ede8c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xedf20ULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
    goto L_ede8c;
L_edf24:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xedf30ULL; PB_CALL(22, cpu, tlb, cpu->regs[1]);
    goto L_edea8;
L_edf34:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xedf40ULL; PB_CALL(23, cpu, tlb, cpu->regs[1]);
    goto L_edec4;
L_edf44:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0xed000ULL;
    cpu->regs[0] = cpu->regs[0] + 3564ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_ede44;
L_edf5c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 40));
    if ((cpu->regs[20])==0) goto L_ede80;
    cpu->regs[20] = 0ULL;
L_edf68:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xedf70ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_ede80;
L_edf74:
    cpu->regs[30] = PB_BASE + 0xedf78ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_ede70;
L_edf88:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[19]);
    goto L_edeec;
L_edfa4:
    PB_STRW((cpu->regs[20] + 152), cpu->regs[1]);
    goto L_edfc8;
L_edfac:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[20] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xedfc4ULL; PB_CALL(26, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 160));
L_edfc8:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])!=0) goto L_edfac;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 152), cpu->regs[0]);
    goto L_edeec;
}
