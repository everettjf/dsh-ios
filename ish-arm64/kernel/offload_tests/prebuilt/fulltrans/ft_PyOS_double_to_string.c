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

void ft_PyOS_double_to_string(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 144ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = ((uint32_t)(cpu->regs[0] & 255ULL));
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[3];
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(114ULL)));
    if (FLAG_NE) goto L_22536c;
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_225598;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[1] = cpu->regs[21] + 2576ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 0), cpu->regs[1]);
L_225080:
    cpu->regs[4] = SP + 32ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[27] = ((uint32_t)(cpu->regs[2] & 1ULL));
    cpu->regs[23] = ((uint32_t)(cpu->regs[2] & 2ULL));
    cpu->regs[24] = ((uint32_t)(cpu->regs[2] & 4ULL));
    cpu->regs[19] = ((uint32_t)(cpu->regs[2] & 8ULL));
    cpu->regs[3] = SP + 28ULL;
    cpu->regs[2] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x2250a4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1719f0ULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 24));
    cpu->regs[4] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[28] = cpu->regs[4];
    if ((cpu->regs[0])==0) goto L_22558c;
    PB_LDR(cpu->regs[3], (SP + 32));
    cpu->regs[21] = cpu->regs[3] - cpu->regs[0];
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_2255d8;
L_2250c4:
    if ((cpu->regs[21])==0) goto L_2250dc;
L_2250c8:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + 0));
L_2250cc:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2272));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 2)));
    if (!((cpu->regs[2] >> 2) & 1)) goto L_2253a8;
L_2250dc:
    if ((cpu->regs[26])!=0) goto L_225424;
L_2250e0:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(114ULL)));
    if (FLAG_NE) goto L_225278;
    cpu->regs[0] = cpu->regs[4] + 3ULL;
    cpu->regs[26] = cpu->regs[21];
    FLAG_CMP(cpu->regs[0], 19ULL);
    if (FLAG_LS) goto L_225284;
L_2250f8:
    FLAG_CMP(cpu->regs[26], 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[26] = (FLAG_GT) ? cpu->regs[26] : (0ULL + 1);
    cpu->regs[28] = 1ULL;
    cpu->regs[4] = cpu->regs[26] + 3ULL;
    cpu->regs[23] = cpu->regs[28];
    cpu->regs[19] = 0ULL;
    PB_STRW((SP + 12), cpu->regs[0]);
    cpu->regs[0] = 5ULL;
L_22511c:
    cpu->regs[0] = cpu->regs[0] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x225128ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2255b0;
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_2252b0;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_2254cc;
L_225144:
    FLAG_CMP(cpu->regs[28], 0ULL);
    if (FLAG_LE) goto L_2252bc;
    FLAG_CMP(cpu->regs[21], cpu->regs[28]);
    if (FLAG_LT) goto L_22542c;
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[22] + cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x225168ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[27] = cpu->regs[21] - cpu->regs[28];
    cpu->regs[0] = 46ULL;
    PB_STRB((cpu->regs[22] + cpu->regs[28]), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[19] + cpu->regs[27];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x22518cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b5d0ULL);
L_22518c:
    cpu->regs[26] = cpu->regs[26] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[19] + cpu->regs[26];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x2251a4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7aee0ULL);
L_2251a4:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + -1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(46ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[19] = cpu->regs[19] - cpu->regs[0];
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_2251e4;
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDRW(cpu->regs[2], (SP + 12));
    cpu->regs[1] = cpu->regs[1] + 3568ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STRB(cpu->regs[19], cpu->regs[0]); cpu->regs[19] += 1;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2251e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7bff0ULL);
    cpu->regs[19] = cpu->regs[19] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
L_2251e4:
    PB_STRB((cpu->regs[19] + 0), 0ULL);
    cpu->regs[2] = cpu->regs[25] - 4ULL;
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + -4));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << (cpu->regs[1] & 63)));
    PB_STRW((cpu->regs[2] + 8), cpu->regs[1]); PB_STRW((cpu->regs[2] + 8) + 4, cpu->regs[0]);
    if ((cpu->regs[2])==0) goto L_225238;
L_225200:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_225580;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22521cULL; PB_CALL(7, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3);
    cpu->regs[1] = cpu->regs[1] + (64ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 5296));
    PB_STR((cpu->regs[25] + -4), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 5296), cpu->regs[2]);
L_225238:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_225534;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
L_225278:
    cpu->regs[26] = cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(102ULL)));
    if (FLAG_NE) goto L_225414;
L_225284:
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[4] : (0ULL + 1);
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_225354;
    FLAG_CMP(cpu->regs[4], cpu->regs[26]);
    if (FLAG_GE) goto L_225390;
    cpu->regs[4] = cpu->regs[26] + 3ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[0] = 0ULL;
    PB_STRW((SP + 12), 0ULL);
    goto L_22511c;
L_2252b0:
    cpu->regs[0] = 45ULL;
    PB_STRB(cpu->regs[22], cpu->regs[0]); cpu->regs[22] += 1;
    goto L_225144;
L_2252bc:
    cpu->regs[27] = cpu->regs[28] - cpu->regs[19];
    cpu->regs[1] = 48ULL;
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2252d0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[19] = cpu->regs[22] + cpu->regs[27];
    cpu->regs[0] = 46ULL;
    PB_STRB((cpu->regs[22] + cpu->regs[27]), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[27] = (uint64_t)(-(int64_t)cpu->regs[28]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[19] = cpu->regs[19] + cpu->regs[27];
    cpu->regs[1] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x2252f8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x225308ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[19] = cpu->regs[19] + cpu->regs[21];
    FLAG_CMP(cpu->regs[21], cpu->regs[28]);
    if (FLAG_GE) goto L_22518c;
L_225314:
    cpu->regs[21] = cpu->regs[28] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x225328ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[0] = cpu->regs[19] + cpu->regs[21];
    cpu->regs[1] = 46ULL;
    cpu->regs[3] = cpu->regs[0] + 1ULL;
    PB_STRB((cpu->regs[19] + cpu->regs[21]), cpu->regs[1]);
    cpu->regs[19] = cpu->regs[26] - cpu->regs[28];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x22534cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[19] = cpu->regs[0] + cpu->regs[19];
    goto L_2251a4;
L_225354:
    FLAG_CMP(cpu->regs[26], cpu->regs[4]);
    cpu->regs[0] = 0ULL;
    cpu->regs[26] = (FLAG_GE) ? cpu->regs[26] : cpu->regs[4];
    PB_STRW((SP + 12), 0ULL);
    cpu->regs[4] = cpu->regs[26] + 3ULL;
    goto L_22511c;
L_22536c:
    if (FLAG_HI) goto L_2255f0;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(102ULL)));
    if (FLAG_NE) goto L_225460;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[0] = cpu->regs[21] + 2576ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[0] = 3ULL;
    goto L_225080;
L_225390:
    cpu->regs[26] = cpu->regs[4] + 1ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 4ULL;
    cpu->regs[0] = 0ULL;
    PB_STRW((SP + 12), 0ULL);
    goto L_22511c;
L_2253a8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967263ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(78ULL)));
    if (FLAG_NE) goto L_2253b8;
    PB_STRW((SP + 28), 0ULL);
L_2253b8:
    cpu->regs[0] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x2253c0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2255b0;
    PB_LDRW(cpu->regs[0], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    cpu->regs[0] = cpu->regs[20];
    if (FLAG_EQ) goto L_22548c;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_225504;
L_2253dc:
    PB_LDRB(cpu->regs[1], (cpu->regs[25] + 0));
    cpu->regs[19] = cpu->regs[0] + 3ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 4294967263ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(73ULL)));
    PB_LDR(cpu->regs[1], (SP + 0));
    if (FLAG_NE) goto L_225444;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x225404ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    if ((cpu->regs[26])==0) goto L_2251e4;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_2251e4;
L_225414:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(103ULL)));
    if (FLAG_EQ) goto L_2254d8;
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_2250f8;
L_225424:
    PB_STRW((cpu->regs[26] + 0), 0ULL);
    goto L_2250e0;
L_22542c:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[22] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x225440ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    goto L_225314;
L_225444:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x225450ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    if ((cpu->regs[26])==0) goto L_2251e4;
    cpu->regs[0] = 2ULL;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_2251e4;
L_225460:
    if (FLAG_HI) goto L_225498;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(101ULL)));
    if (FLAG_NE) goto L_225510;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[0] = cpu->regs[21] + 2576ULL;
    PB_STR((SP + 0), cpu->regs[0]);
L_22547c:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[0] = 2ULL;
    cpu->regs[22] = 101ULL;
    goto L_225080;
L_22548c:
    cpu->regs[1] = 45ULL;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    goto L_2253dc;
L_225498:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(103ULL)));
    if (FLAG_NE) goto L_2255f0;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[0] = cpu->regs[21] + 2576ULL;
    PB_STR((SP + 0), cpu->regs[0]);
L_2254b0:
    cpu->regs[0] = 2ULL;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_2254c0;
    cpu->regs[22] = 103ULL;
    goto L_225080;
L_2254c0:
    cpu->regs[20] = 1ULL;
    cpu->regs[22] = 103ULL;
    goto L_225080;
L_2254cc:
    cpu->regs[0] = 43ULL;
    PB_STRB(cpu->regs[22], cpu->regs[0]); cpu->regs[22] += 1;
    goto L_225144;
L_2254d8:
    FLAG_CMP(cpu->regs[4], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_LT) goto L_225538;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[20] - cpu->regs[0]));
    cpu->regs[26] = (FLAG_NE) ? cpu->regs[26] : cpu->regs[21];
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_LE) goto L_225284;
    goto L_2250f8;
L_225504:
    cpu->regs[1] = 43ULL;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    goto L_2253dc;
L_225510:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(70ULL)));
    if (FLAG_NE) goto L_225548;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[0] = cpu->regs[21] + 2608ULL;
    cpu->regs[22] = 102ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[0] = 3ULL;
    goto L_225080;
L_225534:
    cpu->regs[30] = PB_BASE + 0x225538ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_225538:
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    cpu->regs[26] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[21];
    goto L_2250f8;
L_225548:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(71ULL)));
    if (FLAG_EQ) goto L_22556c;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(69ULL)));
    if (FLAG_NE) goto L_2255f0;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[0] = cpu->regs[21] + 2608ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_22547c;
L_22556c:
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[0] = cpu->regs[21] + 2608ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_2254b0;
L_225580:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x225588ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_225238;
L_22558c:
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x225594ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_225238;
L_225598:
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = 1268ULL;
    cpu->regs[0] = cpu->regs[0] + 3544ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2255acULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_225238;
L_2255b0:
    cpu->regs[30] = PB_BASE + 0x2255b4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[20] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + -4));
    cpu->regs[2] = cpu->regs[25] - 4ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << (cpu->regs[1] & 63)));
    PB_STRW((cpu->regs[2] + 8), cpu->regs[1]); PB_STRW((cpu->regs[2] + 8) + 4, cpu->regs[0]);
    if ((cpu->regs[2])!=0) goto L_225200;
    cpu->regs[20] = 0ULL;
    goto L_225238;
L_2255d8:
    PB_LDRW(cpu->regs[0], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_2250c4;
    if ((cpu->regs[21])!=0) goto L_225608;
    PB_STRW((SP + 28), 0ULL);
    goto L_2250dc;
L_2255f0:
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = 1274ULL;
    cpu->regs[0] = cpu->regs[0] + 3544ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x225604ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_225238;
L_225608:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + 0));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_2250cc;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_NE) goto L_2250cc;
    PB_STRW((SP + 28), 0ULL);
    goto L_2250c8;
}
