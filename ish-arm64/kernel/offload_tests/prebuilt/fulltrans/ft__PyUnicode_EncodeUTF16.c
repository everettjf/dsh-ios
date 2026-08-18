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

void ft__PyUnicode_EncodeUTF16(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 192ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = (FLAG_LE) ? 1 : 0;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 88), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    PB_STR((SP + 48), 0ULL); PB_STR((SP + 48) + 8, 0ULL);
    if (!((cpu->regs[0] >> 28) & 1)) goto L_229604;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[25] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_2295ac;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[19] = cpu->regs[22] + 56ULL;
    cpu->regs[0] = cpu->regs[22] + 40ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[0];
L_229030:
    PB_LDR(cpu->regs[24], (cpu->regs[22] + 16));
    cpu->regs[2] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_2293f8;
L_229040:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    cpu->regs[0] = 4611686018427387903ULL;
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_LT) goto L_229610;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[24];
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] << 1;
    cpu->regs[30] = PB_BASE + 0x229070ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((SP + 72), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2295fc;
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_229228;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    PB_STR((SP + 64), cpu->regs[0]);
L_229084:
    if ((cpu->regs[24])==0) goto L_2291d4;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_229210;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 1104ULL;
    cpu->regs[0] = cpu->regs[0] + 1120ULL;
    cpu->regs[26] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    cpu->regs[26] = cpu->regs[26] + 1088ULL;
    cpu->regs[26] = (FLAG_LT) ? cpu->regs[26] : cpu->regs[0];
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
L_2290bc:
    PB_LDR(cpu->regs[5], (SP + 64));
    cpu->regs[1] = cpu->regs[5];
    FLAG_CMP(cpu->regs[27], cpu->regs[24]);
    if (FLAG_GE) goto L_2291a8;
    cpu->regs[7] = cpu->regs[24] - cpu->regs[27];
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_22938c;
    cpu->regs[6] = cpu->regs[7] & 18446744073709551612ULL;
    cpu->regs[3] = cpu->regs[19] + (cpu->regs[27] << 1);
    cpu->regs[8] = cpu->regs[3] + (cpu->regs[7] << 1);
    cpu->regs[6] = cpu->regs[3] + (cpu->regs[6] << 1);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_22923c;
    cpu->regs[0] = 4294957056ULL;
    goto L_229154;
L_2290f8:
    PB_LDRH(cpu->regs[1], (cpu->regs[3] + 2));
    PB_LDRH(cpu->regs[4], (cpu->regs[3] + 4));
    PB_LDRH(cpu->regs[2], (cpu->regs[3] + 6));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] ^ cpu->regs[0]));
    PB_LDRH(cpu->regs[9], (cpu->regs[3] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] ^ cpu->regs[0]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] ^ cpu->regs[0]));
    cpu->regs[10] = ((uint32_t)(cpu->regs[9] ^ cpu->regs[0]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & cpu->regs[10]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & cpu->regs[1]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & 65535ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_22915c;
    PB_STRH((cpu->regs[5] + 0), cpu->regs[9]);
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    PB_LDRH(cpu->regs[1], (cpu->regs[3] + -6));
    PB_STRH((cpu->regs[5] + -6), cpu->regs[1]);
    PB_LDRH(cpu->regs[1], (cpu->regs[3] + -4));
    PB_STRH((cpu->regs[5] + -4), cpu->regs[1]);
    PB_LDRH(cpu->regs[1], (cpu->regs[3] + -2));
    PB_STRH((cpu->regs[5] + -2), cpu->regs[1]);
L_229154:
    FLAG_CMP(cpu->regs[3], cpu->regs[6]);
    if (FLAG_LO) goto L_2290f8;
L_22915c:
    cpu->regs[1] = 55295ULL;
L_229160:
    FLAG_CMP(cpu->regs[8], cpu->regs[3]);
    if (FLAG_LS) goto L_229194;
    PB_LDRH(cpu->regs[0], cpu->regs[3]); cpu->regs[3] += 2;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_22917c;
L_229174:
    PB_STRH(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 2;
    goto L_229160;
L_22917c:
    cpu->regs[2] = 57343ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_HI) goto L_229174;
L_229188:
    cpu->regs[8] = cpu->regs[8] - cpu->regs[3];
    cpu->regs[7] = cpu->regs[7] - 1ULL;
    cpu->regs[7] = cpu->regs[7] - ((uint64_t)((int64_t)cpu->regs[8] >> 1));
L_229194:
    cpu->regs[6] = cpu->regs[27] + cpu->regs[7];
    PB_STR((SP + 64), cpu->regs[5]);
    FLAG_CMP(cpu->regs[6], cpu->regs[24]);
    if (FLAG_NE) goto L_2292dc;
    cpu->regs[1] = cpu->regs[5];
L_2291a8:
    PB_LDR(cpu->regs[0], (SP + 72));
    cpu->regs[2] = cpu->regs[0] + 32ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_229598;
L_2291c0:
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x2291c8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x2291d0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
L_2291d4:
    PB_LDR(cpu->regs[0], (SP + 72));
L_2291d8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 88));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2295a4;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    SP = SP + 192ULL;
    return;
L_229210:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = SP + 64ULL;
    cpu->regs[30] = PB_BASE + 0x229224ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x242e30ULL);
    goto L_2291d4;
L_229228:
    cpu->regs[2] = cpu->regs[0] + 34ULL;
    cpu->regs[1] = 4294967039ULL;
    PB_STRH((cpu->regs[0] + 32), cpu->regs[1]);
    PB_STR((SP + 64), cpu->regs[2]);
    goto L_229084;
L_22923c:
    cpu->regs[4] = 4294957056ULL;
    goto L_2292b0;
L_229244:
    PB_LDRH(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRH(cpu->regs[1], (cpu->regs[3] + 4));
    PB_LDRH(cpu->regs[9], (cpu->regs[3] + 6));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ cpu->regs[4]));
    PB_LDRH(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] ^ cpu->regs[4]));
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] ^ cpu->regs[4]));
    cpu->regs[10] = ((uint32_t)(cpu->regs[2] ^ cpu->regs[4]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & cpu->regs[9]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & cpu->regs[10]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & cpu->regs[0]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 65535ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_2292b8;
    cpu->regs[2] = (cpu->regs[2] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[2] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH((cpu->regs[5] + 0), cpu->regs[2]);
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    PB_LDRH(cpu->regs[0], (cpu->regs[3] + -6));
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH((cpu->regs[5] + -6), cpu->regs[0]);
    PB_LDRH(cpu->regs[0], (cpu->regs[3] + -4));
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH((cpu->regs[5] + -4), cpu->regs[0]);
    PB_LDRH(cpu->regs[0], (cpu->regs[3] + -2));
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH((cpu->regs[5] + -2), cpu->regs[0]);
L_2292b0:
    FLAG_CMP(cpu->regs[3], cpu->regs[6]);
    if (FLAG_LO) goto L_229244;
L_2292b8:
    cpu->regs[1] = 55295ULL;
L_2292bc:
    FLAG_CMP(cpu->regs[8], cpu->regs[3]);
    if (FLAG_LS) goto L_229194;
    PB_LDRH(cpu->regs[0], cpu->regs[3]); cpu->regs[3] += 2;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_2294f4;
L_2292d0:
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 2;
    goto L_2292bc;
L_2292dc:
    cpu->regs[8] = SP + 48ULL;
    cpu->regs[0] = SP + 80ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[27] = PB_BASE + 0x28e000ULL;
    cpu->regs[27] = cpu->regs[27] + 104ULL;
    cpu->regs[7] = cpu->regs[6] + 1ULL;
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[5] = cpu->regs[8];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = SP + 56ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 24), cpu->regs[6]); PB_STR((SP + 24) + 8, cpu->regs[8]);
    PB_STR((SP + 40), cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x229318ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x247d80ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2295d8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[7], (SP + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[6], (SP + 24)); PB_LDR(cpu->regs[8], (SP + 24) + 8);
    if (((cpu->regs[0] >> 27) & 1)) goto L_229420;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 16));
    if (!((cpu->regs[1] >> 6) & 1)) goto L_2295bc;
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = cpu->regs[6] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_229514;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_2295b4;
L_229358:
    cpu->regs[0] = cpu->regs[28] + 40ULL;
L_22935c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = SP + 64ULL;
    cpu->regs[30] = PB_BASE + 0x22936cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x242e30ULL);
L_22936c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2290bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2290bc;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x229388ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2290bc;
L_22938c:
    cpu->regs[1] = cpu->regs[19] + (cpu->regs[27] << 2);
    cpu->regs[2] = cpu->regs[1] + (cpu->regs[7] << 2);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_22948c;
    cpu->regs[4] = 55295ULL;
    cpu->regs[10] = 57343ULL;
    cpu->regs[9] = 65535ULL;
    cpu->regs[8] = 55232ULL;
    cpu->regs[6] = 56320ULL;
L_2293b0:
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LS) goto L_229194;
    PB_LDRW(cpu->regs[0], cpu->regs[1]); cpu->regs[1] += 4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LS) goto L_2293f0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[10])));
    if (FLAG_LS) goto L_229504;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[9])));
    if (FLAG_LS) goto L_2293f0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] & 1023ULL));
    cpu->regs[5] = cpu->regs[5] + 4ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[8] + (cpu->regs[0] >> 10)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + cpu->regs[6]));
    PB_STRH((cpu->regs[5] + -4), cpu->regs[0]);
    PB_STRH((cpu->regs[5] + -2), cpu->regs[3]);
    goto L_2293b0;
L_2293f0:
    PB_STRH(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 2;
    goto L_2293b0;
L_2293f8:
    cpu->regs[3] = cpu->regs[19] + (cpu->regs[24] << 2);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = 65535ULL;
L_229404:
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_HS) goto L_229040;
    PB_LDRW(cpu->regs[1], cpu->regs[0]); cpu->regs[0] += 4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LS) goto L_229404;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_229404;
L_229420:
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 16));
    if (((cpu->regs[2] >> 0) & 1)) goto L_2295bc;
    cpu->regs[1] = 2ULL;
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[1]) : 0);
    cpu->regs[0] = cpu->regs[6] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_229514;
L_229444:
    PB_LDR(cpu->regs[3], (SP + 64));
    cpu->regs[1] = cpu->regs[28] + 32ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_LO) goto L_229588;
    if (FLAG_LS) goto L_229464;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LO) goto L_229594;
L_229464:
    cpu->regs[0] = cpu->regs[3];
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x229470ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[0] = 2ULL;
    cpu->regs[0] = (cpu->regs[0] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[0]) : 0);
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 1);
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_22936c;
L_22948c:
    cpu->regs[10] = 55295ULL;
    cpu->regs[9] = 57343ULL;
    cpu->regs[8] = 65535ULL;
    cpu->regs[6] = 55232ULL;
    cpu->regs[4] = 56320ULL;
L_2294a0:
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LS) goto L_229194;
    PB_LDRW(cpu->regs[0], cpu->regs[1]); cpu->regs[1] += 4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[10])));
    if (FLAG_HI) goto L_2294c0;
L_2294b4:
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 2;
    goto L_2294a0;
L_2294c0:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[9])));
    if (FLAG_LS) goto L_229504;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[8])));
    if (FLAG_LS) goto L_2294b4;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] & 1023ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[6] + (cpu->regs[0] >> 10)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + cpu->regs[4]));
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    cpu->regs[3] = (cpu->regs[3] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[3] & 0x00ff00ff00ff00ffULL) << 8;
    cpu->regs[5] = cpu->regs[5] + 4ULL;
    PB_STRH((cpu->regs[5] + -4), cpu->regs[0]);
    PB_STRH((cpu->regs[5] + -2), cpu->regs[3]);
    goto L_2294a0;
L_2294f4:
    cpu->regs[2] = 57343ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LS) goto L_229188;
    goto L_2292d0;
L_229504:
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[7] = cpu->regs[7] - 1ULL;
    cpu->regs[7] = cpu->regs[7] - ((uint64_t)((int64_t)cpu->regs[2] >> 2));
    goto L_229194;
L_229514:
    PB_LDR(cpu->regs[4], (SP + 64)); PB_LDR(cpu->regs[1], (SP + 64) + 8);
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[6] = cpu->regs[1] + 32ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[6];
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1];
    cpu->regs[3] = (cpu->regs[5] ? (uint64_t)((int64_t)cpu->regs[3] / (int64_t)cpu->regs[5]) : 0);
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_229618;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[0] << 1);
    cpu->regs[0] = SP + 72ULL;
    PB_STR((SP + 24), cpu->regs[4]); PB_STR((SP + 24) + 8, cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x22954cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x13e868ULL);
    PB_LDR(cpu->regs[1], (SP + 72));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2295d8;
    PB_LDR(cpu->regs[4], (SP + 24)); PB_LDR(cpu->regs[2], (SP + 24) + 8);
    cpu->regs[0] = cpu->regs[1] + 32ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[28] + 8));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (((cpu->regs[0] >> 27) & 1)) goto L_229444;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 32));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_2295b4;
    if (((cpu->regs[0] >> 6) & 1)) goto L_229358;
    cpu->regs[0] = cpu->regs[28] + 56ULL;
    goto L_22935c;
L_229588:
    cpu->regs[0] = cpu->regs[3] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_229464;
L_229594:
    __builtin_trap();
L_229598:
    cpu->regs[0] = SP + 72ULL;
    cpu->regs[30] = PB_BASE + 0x2295a0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x13e868ULL);
    goto L_2291c0;
L_2295a4:
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x2295acULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2295ac:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 56));
    goto L_229030;
L_2295b4:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 56));
    goto L_22935c;
L_2295bc:
    cpu->regs[5] = cpu->regs[27];
    cpu->regs[4] = cpu->regs[7];
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x2295d8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x230848ULL);
L_2295d8:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x2295e0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x2295e8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x2295f0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 72));
    cpu->regs[30] = PB_BASE + 0x2295f8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
L_2295fc:
    cpu->regs[0] = 0ULL;
    goto L_2291d8;
L_229604:
    cpu->regs[30] = PB_BASE + 0x229608ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 0ULL;
    goto L_2291d8;
L_229610:
    cpu->regs[30] = PB_BASE + 0x229614ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_2291d8;
L_229618:
    cpu->regs[30] = PB_BASE + 0x22961cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_2295d8;
}
