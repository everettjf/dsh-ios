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

void ft__Py_strhex_bytes_with_sep(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = 1ULL;
    goto L_22f26c;
L_22f26c:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    if ((cpu->regs[2])!=0) goto L_22f4ac;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[24] = 0ULL;
    cpu->regs[26] = (FLAG_GT) ? 1 : 0;
    cpu->regs[25] = 0ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = 0ULL;
L_22f2ac:
    cpu->regs[1] = 4611686018427387903ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_LE) goto L_22f784;
    cpu->regs[21] = cpu->regs[0] + (cpu->regs[20] << 1);
    FLAG_CMP(cpu->regs[20], cpu->regs[24]);
    if (FLAG_LS) goto L_22f638;
L_22f2c8:
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_22f5d4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x22f2d8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    if ((cpu->regs[0])==0) goto L_22f668;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_22f79c;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[7] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[7] = (FLAG_EQ) ? cpu->regs[7] : cpu->regs[1];
L_22f2f4:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_22f534;
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_22f494;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2576));
    cpu->regs[9] = cpu->regs[20] - 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[8] = cpu->regs[7] + 2ULL;
    cpu->regs[9] = cpu->regs[9] & 3ULL;
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[7] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[7] + 1), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_LE) goto L_22f494;
    if ((cpu->regs[9])==0) goto L_22f3e4;
    FLAG_CMP(cpu->regs[9], 1ULL);
    if (FLAG_EQ) goto L_22f3b0;
    FLAG_CMP(cpu->regs[9], 2ULL);
    if (FLAG_EQ) goto L_22f384;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 1));
    cpu->regs[3] = 2ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[8] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[8] + 1), cpu->regs[1]);
    cpu->regs[8] = cpu->regs[8] + cpu->regs[3];
L_22f384:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[3]));
    cpu->regs[8] = cpu->regs[8] + 2ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[8] + -2), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[8] + -1), cpu->regs[1]);
L_22f3b0:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[3]));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    cpu->regs[8] = cpu->regs[8] + 2ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[8] + -2), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[8] + -1), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_LE) goto L_22f494;
L_22f3e4:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[3]));
    cpu->regs[9] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    cpu->regs[7] = cpu->regs[8] + 2ULL;
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    cpu->regs[8] = cpu->regs[8] + 8ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[8] + -8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[8] + -7), cpu->regs[1]);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[9]));
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[8] + -6), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[7] + 1), cpu->regs[1]);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[3]));
    cpu->regs[3] = cpu->regs[9] + 2ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[7] + 2), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[7] + 3), cpu->regs[1]);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[3]));
    cpu->regs[3] = cpu->regs[9] + 3ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1] & 15ULL;
    cpu->regs[5] = ((cpu->regs[1] >> 4) & 0xfULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + cpu->regs[5]));
    PB_STRB((cpu->regs[7] + 4), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[7] + 5), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_GT) goto L_22f3e4;
L_22f494:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_22f4ac:
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x22f4bcULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x141d48ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_22f668;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_22f650;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_22f644;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_22f678;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22f4f0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x122a60ULL);
    cpu->regs[25] = ((uint32_t)(cpu->regs[0] & 255ULL));
L_22f4f4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[23] ^ 1ULL));
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[25]))), 0);
    if (FLAG_NE) goto L_22f678;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    cpu->regs[24] = ((uint32_t)((FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[22])) : cpu->regs[22]));
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[26] = (FLAG_GT) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[26], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[2] = (FLAG_NE) ? 1 : 0;
    if (FLAG_EQ) goto L_22f670;
    cpu->regs[0] = cpu->regs[20] - 1ULL;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[26] = cpu->regs[2];
    cpu->regs[0] = (cpu->regs[1] ? cpu->regs[0] / cpu->regs[1] : 0);
    goto L_22f2ac;
L_22f534:
    cpu->regs[9] = cpu->regs[20] - 1ULL;
    cpu->regs[6] = cpu->regs[24];
    cpu->regs[1] = (cpu->regs[6] ? (uint64_t)((int64_t)cpu->regs[9] / (int64_t)cpu->regs[6]) : 0);
    if (FLAG_LT) goto L_22f698;
    cpu->regs[4] = 18446744073709551614ULL;
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    cpu->regs[10] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[10], (cpu->regs[10] + 2576));
    cpu->regs[4] = cpu->regs[6] * cpu->regs[4];
    cpu->regs[11] = cpu->regs[21];
    cpu->regs[13] = cpu->regs[9];
    cpu->regs[8] = cpu->regs[9];
    cpu->regs[16] = cpu->regs[7] + 1ULL;
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[12] = 0ULL;
L_22f570:
    FLAG_CMP(cpu->regs[12], cpu->regs[1]);
    if (FLAG_GE) goto L_22f5ec;
    cpu->regs[5] = cpu->regs[7] + cpu->regs[11];
    cpu->regs[2] = cpu->regs[13];
L_22f580:
    cpu->regs[3] = ((uint32_t)(cpu->regs[8] - cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_LS) goto L_22f5bc;
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + cpu->regs[2]));
    cpu->regs[5] = cpu->regs[5] - 2ULL;
    PB_LDR(cpu->regs[15], (cpu->regs[10] + 0));
    cpu->regs[14] = cpu->regs[3] & 15ULL;
    cpu->regs[3] = ((cpu->regs[3] >> 4) & 0xfULL);
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_LDRB(cpu->regs[14], (cpu->regs[15] + cpu->regs[14]));
    PB_STRB((cpu->regs[5] + 2), cpu->regs[14]);
    PB_LDR(cpu->regs[14], (cpu->regs[10] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[14] + cpu->regs[3]));
    PB_STRB((cpu->regs[5] + 1), cpu->regs[3]);
    goto L_22f580;
L_22f5bc:
    cpu->regs[11] = cpu->regs[4] + cpu->regs[11];
    cpu->regs[8] = cpu->regs[8] - cpu->regs[6];
    cpu->regs[12] = cpu->regs[12] + 1ULL;
    cpu->regs[13] = cpu->regs[13] - cpu->regs[6];
    PB_STRB((cpu->regs[16] + cpu->regs[11]), cpu->regs[25]);
    goto L_22f570;
L_22f5d4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22f5e0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe9c70ULL);
    if ((cpu->regs[0])==0) goto L_22f668;
    cpu->regs[7] = cpu->regs[0] + 32ULL;
    goto L_22f2f4;
L_22f5ec:
    cpu->regs[1] = cpu->regs[1] & ~(((uint64_t)((int64_t)cpu->regs[1] >> 63)));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2576));
    cpu->regs[4] = cpu->regs[4] * cpu->regs[1] + cpu->regs[21];
    cpu->regs[1] = cpu->regs[9] - cpu->regs[6] * cpu->regs[1];
    cpu->regs[7] = cpu->regs[7] + cpu->regs[4];
L_22f604:
    if (((cpu->regs[1] >> 63) & 1)) goto L_22f494;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[1]));
    cpu->regs[7] = cpu->regs[7] - 2ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    cpu->regs[4] = cpu->regs[2] & 15ULL;
    cpu->regs[2] = ((cpu->regs[2] >> 4) & 0xfULL);
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[5] + cpu->regs[4]));
    PB_STRB((cpu->regs[7] + 2), cpu->regs[4]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_LDRB(cpu->regs[2], (cpu->regs[4] + cpu->regs[2]));
    PB_STRB((cpu->regs[7] + 1), cpu->regs[2]);
    goto L_22f604;
L_22f638:
    cpu->regs[24] = 0ULL;
    cpu->regs[22] = 0ULL;
    goto L_22f2c8;
L_22f644:
    if (!((cpu->regs[0] >> 27) & 1)) goto L_22f764;
    PB_LDRB(cpu->regs[25], (cpu->regs[21] + 32));
    goto L_22f4f4;
L_22f650:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 2456ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22f668ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_22f668:
    cpu->regs[0] = 0ULL;
    goto L_22f494;
L_22f670:
    cpu->regs[0] = 0ULL;
    goto L_22f2ac;
L_22f678:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 2480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22f690ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_22f494;
L_22f698:
    cpu->regs[2] = cpu->regs[6] << 1;
    cpu->regs[10] = cpu->regs[19];
    cpu->regs[11] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[11], (cpu->regs[11] + 2576));
    cpu->regs[13] = cpu->regs[2] + 1ULL;
    cpu->regs[12] = cpu->regs[7] - 1ULL;
    cpu->regs[9] = 0ULL;
    cpu->regs[3] = 0ULL;
L_22f6b8:
    FLAG_CMP(cpu->regs[9], cpu->regs[1]);
    if (FLAG_GE) goto L_22f714;
    cpu->regs[5] = cpu->regs[7] + cpu->regs[3];
    cpu->regs[4] = 0ULL;
L_22f6c8:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LS) goto L_22f700;
    PB_LDRB(cpu->regs[8], (cpu->regs[10] + cpu->regs[4]));
    cpu->regs[5] = cpu->regs[5] + 2ULL;
    PB_LDR(cpu->regs[15], (cpu->regs[11] + 0));
    cpu->regs[14] = cpu->regs[8] & 15ULL;
    cpu->regs[8] = ((cpu->regs[8] >> 4) & 0xfULL);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_LDRB(cpu->regs[8], (cpu->regs[15] + cpu->regs[8]));
    PB_STRB((cpu->regs[5] + -2), cpu->regs[8]);
    PB_LDR(cpu->regs[8], (cpu->regs[11] + 0));
    PB_LDRB(cpu->regs[8], (cpu->regs[8] + cpu->regs[14]));
    PB_STRB((cpu->regs[5] + -1), cpu->regs[8]);
    goto L_22f6c8;
L_22f700:
    cpu->regs[3] = cpu->regs[13] + cpu->regs[3];
    cpu->regs[9] = cpu->regs[9] + 1ULL;
    cpu->regs[10] = cpu->regs[10] + cpu->regs[6];
    PB_STRB((cpu->regs[12] + cpu->regs[3]), cpu->regs[25]);
    goto L_22f6b8;
L_22f714:
    cpu->regs[3] = cpu->regs[1] & ~(((uint64_t)((int64_t)cpu->regs[1] >> 63)));
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2576));
    cpu->regs[2] = cpu->regs[2] * cpu->regs[3] + cpu->regs[3];
    cpu->regs[3] = cpu->regs[6] * cpu->regs[3];
    cpu->regs[1] = cpu->regs[7] + cpu->regs[2];
L_22f72c:
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_LE) goto L_22f494;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[3]));
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 0));
    cpu->regs[5] = cpu->regs[2] & 15ULL;
    cpu->regs[2] = ((cpu->regs[2] >> 4) & 0xfULL);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[6] + cpu->regs[2]));
    PB_STRB((cpu->regs[1] + -2), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + cpu->regs[5]));
    PB_STRB((cpu->regs[1] + -1), cpu->regs[2]);
    goto L_22f72c;
L_22f764:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 2504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22f77cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_22f494;
L_22f784:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_22f79c:
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 56));
    goto L_22f2f4;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x22f7c0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[6] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22f7d8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x22f7d8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1fdda0ULL);
L_22f7d8:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[6];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x165fe0ULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x22f7f8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x129f00ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[2] = PB_BASE + 0x28e000ULL;
    cpu->regs[4] = 1ULL;
    cpu->regs[2] = cpu->regs[2] + 1760ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 16));
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x201dccULL); return; };
}
