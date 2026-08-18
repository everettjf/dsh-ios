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

void ft_PyObject_CallOneArg(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x120dfcULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[20], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    PB_STR((SP + 16), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (!((cpu->regs[0] >> 11) & 1)) goto L_120ea8;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 56));
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[3];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_120ec8;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_120e4c;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(SP, cpu->regs[0]);
    if (FLAG_LO) goto L_120ec8;
L_120e4c:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + cpu->regs[3]));
    if ((cpu->regs[4])==0) goto L_120ea8;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x120e68ULL; PB_CALL(2, cpu, tlb, cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x120e7cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe8888ULL);
L_120e7c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_120ec4;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_120ea8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x120ec0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xea120ULL);
    goto L_120e7c;
L_120ec4:
    cpu->regs[30] = PB_BASE + 0x120ec8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_120ec8:
    __builtin_trap();
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    SP = SP - 896ULL;
    cpu->regs[28] = cpu->regs[3];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 8), cpu->regs[0]); PB_STR((SP + 8) + 8, cpu->regs[1]);
    cpu->regs[1] = 58ULL;
    PB_STR((SP + 72), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    PB_STR((SP + 888), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = SP + 120ULL;
    PB_STR((SP + 104), cpu->regs[2]); PB_STR((SP + 104) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0x120f2cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((cpu->regs[0])==0) goto L_120fc4;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 24), cpu->regs[0]); PB_STR((SP + 24) + 8, 0ULL);
    if ((cpu->regs[1])==0) goto L_1215a0;
L_120f40:
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[25] = 0ULL;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1215c8;
L_120f4c:
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121a74;
    cpu->regs[19] = ((uint32_t)(cpu->regs[25] + 1ULL));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3)));
    if ((cpu->regs[0])==0) goto L_120f94;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121a74;
    cpu->regs[19] = ((uint32_t)(cpu->regs[25] + 2ULL));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3)));
    if ((cpu->regs[0])==0) goto L_120f94;
L_120f7c:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121a74;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3)));
    if ((cpu->regs[0])!=0) goto L_120f7c;
L_120f94:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(8ULL)));
    if (FLAG_GT) goto L_120ff0;
L_120f9c:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_1218a8;
    FLAG_CMP(cpu->regs[26], cpu->regs[24]);
    if (FLAG_LT) goto L_12175c;
    cpu->regs[20] = 0ULL;
L_120fb8:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_121024;
    goto L_121268;
L_120fc4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 59ULL;
    cpu->regs[30] = PB_BASE + 0x120fd0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_121a68;
L_120fd8:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1217bc;
    PB_STR((SP + 24), 0ULL);
    goto L_120f40;
L_120ff0:
    cpu->regs[0] = cpu->regs[26] << 4;
    cpu->regs[30] = PB_BASE + 0x120ff8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1218c0;
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 116), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_121530;
    FLAG_CMP(cpu->regs[26], cpu->regs[24]);
    if (FLAG_LT) goto L_12175c;
    cpu->regs[20] = 0ULL;
L_121024:
    PB_LDR(cpu->regs[1], (SP + 72));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(124ULL)));
    if (FLAG_NE) goto L_1210dc;
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[23] = 0ULL;
    cpu->regs[26] = 0ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(36ULL)));
    if (FLAG_NE) goto L_1210f0;
L_121050:
    cpu->regs[0] = cpu->regs[2] + 1ULL;
    PB_STR((SP + 72), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1219a0;
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_GT) goto L_121970;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 1));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12172c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 58ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_12172c;
    if ((cpu->regs[20])!=0) goto L_121480;
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_1213e4;
L_121088:
    PB_LDRW(cpu->regs[0], (SP + 116));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1210d0;
L_121090:
    cpu->regs[0] = 1ULL;
L_121094:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 888));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_12159c;
    SP = SP + 896ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1210d0:
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[30] = PB_BASE + 0x1210d8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_121090;
L_1210dc:
    cpu->regs[23] = 2147483647ULL;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[26] = cpu->regs[23];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(36ULL)));
    if (FLAG_EQ) goto L_121050;
L_1210f0:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12172c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 58ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_12172c;
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_GT) goto L_12121c;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[25], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_1213c4;
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_121460;
    cpu->regs[23] = 2147483647ULL;
L_121120:
    if ((cpu->regs[20])==0) goto L_121088;
L_121124:
    cpu->regs[26] = 0ULL;
    cpu->regs[27] = 0ULL;
L_12112c:
    cpu->regs[0] = SP + 72ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x121140ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c92e0ULL);
    if ((cpu->regs[0])!=0) goto L_121a24;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1214ac;
L_12114c:
    cpu->regs[10] = 1ULL;
    cpu->regs[18] = 2147483647ULL;
L_121154:
    PB_LDR(cpu->regs[1], (SP + 72));
    cpu->regs[15] = cpu->regs[10];
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(124ULL)));
    if (FLAG_NE) goto L_1213a8;
L_121168:
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(cpu->regs[18])));
    if (FLAG_NE) goto L_1219dc;
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    PB_STR((SP + 72), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_NE) goto L_121a00;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 1));
    cpu->regs[26] = cpu->regs[10];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(36ULL)));
    if (FLAG_NE) goto L_121310;
L_121190:
    cpu->regs[0] = cpu->regs[2] + 1ULL;
    PB_STR((SP + 72), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(cpu->regs[10])));
    if (FLAG_GT) goto L_1219a0;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_1214b4;
    FLAG_CMP(cpu->regs[10], cpu->regs[24]);
    if (FLAG_LT) goto L_12166c;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 1));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121730;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 58ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_121730;
    cpu->regs[23] = cpu->regs[15];
L_1211c8:
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[27] = cpu->regs[10];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[10], cpu->regs[25]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_1213ec;
    FLAG_CMP(((uint32_t)(cpu->regs[10])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_LT) goto L_121494;
L_1211e0:
    if ((cpu->regs[20])==0) goto L_121088;
L_1211e4:
    cpu->regs[27] = 0ULL;
L_1211e8:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    PB_STR((SP + 48), cpu->regs[10]);
    cpu->regs[30] = PB_BASE + 0x1211fcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1c92e0ULL);
    PB_LDR(cpu->regs[10], (SP + 48));
    cpu->regs[18] = 2147483647ULL;
    if ((cpu->regs[0])!=0) goto L_121a24;
    cpu->regs[0] = cpu->regs[10] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_121528;
    cpu->regs[10] = cpu->regs[0];
    goto L_121154;
L_12121c:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[23] = 2147483647ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_12145c;
L_12122c:
    cpu->regs[1] = SP + 72ULL;
    cpu->regs[27] = SP + 104ULL;
    cpu->regs[4] = SP + 248ULL;
    cpu->regs[7] = cpu->regs[27];
    cpu->regs[5] = SP + 376ULL;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[6] = 512ULL;
    PB_STR((SP + 40), cpu->regs[1]); PB_STR((SP + 40) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x121254ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xeaf48ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_121708;
    cpu->regs[27] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12114c;
L_121268:
    PB_LDR(cpu->regs[2], (SP + 72));
    cpu->regs[0] = 18446744073709551614ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 32)) | ((0xffefULL & 0xffff) << 32);
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0xf3ffULL & 0xffff) << 48);
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(60ULL)));
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[0] >> (cpu->regs[1] & 63));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 1ULL));
    cpu->regs[0] = (FLAG_LO) ? cpu->regs[0] : (0ULL + 1);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(124ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1218cc;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_121088;
    cpu->regs[21] = cpu->regs[25];
L_1212a4:
    cpu->regs[22] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[24], cpu->regs[21]);
    if (FLAG_GT) goto L_1216e4;
    cpu->regs[28] = cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3);
    cpu->regs[26] = SP + 96ULL;
    cpu->regs[20] = SP + 88ULL;
    PB_STR((SP + 88), 0ULL);
L_1212c0:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1212d4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121938;
    PB_LDR(cpu->regs[21], (SP + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_121914;
    cpu->regs[23] = cpu->regs[28];
    cpu->regs[22] = cpu->regs[25];
L_1212f0:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_GE) goto L_121618;
    PB_LDR(cpu->regs[1], cpu->regs[23]); cpu->regs[23] += 8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x121304ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1212c0;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    goto L_1212f0;
L_121310:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_121730;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 58ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_121730;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_1211e8;
    FLAG_CMP(cpu->regs[10], cpu->regs[24]);
    if (FLAG_GE) goto L_1211c8;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[10] << 3)));
    if ((cpu->regs[0])==0) goto L_12148c;
L_121340:
    cpu->regs[1] = SP + 248ULL;
    PB_STR((SP + 48), cpu->regs[1]); PB_STR((SP + 48) + 8, cpu->regs[10]);
    cpu->regs[4] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[27] = SP + 104ULL;
    cpu->regs[7] = cpu->regs[27];
    cpu->regs[5] = SP + 376ULL;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[6] = 512ULL;
    PB_STRW((SP + 68), cpu->regs[15]);
    cpu->regs[30] = PB_BASE + 0x121370ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xeaf48ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[15], (SP + 68));
    if ((cpu->regs[0])!=0) goto L_12170c;
    PB_LDR(cpu->regs[10], (SP + 56));
    cpu->regs[18] = 2147483647ULL;
    cpu->regs[10] = cpu->regs[10] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[10])));
    if (FLAG_LE) goto L_121268;
    PB_LDR(cpu->regs[1], (SP + 72));
    cpu->regs[15] = cpu->regs[10];
    cpu->regs[27] = 0ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(124ULL)));
    if (FLAG_EQ) goto L_121168;
L_1213a8:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(36ULL)));
    if (FLAG_NE) goto L_121310;
    cpu->regs[0] = 2147483647ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_121a98;
    cpu->regs[2] = cpu->regs[1];
    goto L_121190;
L_1213c4:
    cpu->regs[23] = 2147483647ULL;
L_1213c8:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x1213d4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xedfe0ULL);
    if ((cpu->regs[0])!=0) goto L_121478;
    cpu->regs[30] = PB_BASE + 0x1213dcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_121654;
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_121124;
L_1213e4:
    cpu->regs[15] = 0ULL;
    goto L_12141c;
L_1213ec:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + (cpu->regs[10] << 3)));
    PB_STR((SP + 48), cpu->regs[10]);
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_STRW((SP + 56), cpu->regs[15]);
    cpu->regs[30] = PB_BASE + 0x121400ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xedfe0ULL);
    PB_LDR(cpu->regs[10], (SP + 48));
    PB_LDRW(cpu->regs[15], (SP + 56));
    if ((cpu->regs[0])!=0) goto L_1214a4;
    cpu->regs[30] = PB_BASE + 0x121410ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_121654;
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_GE) goto L_1211e4;
L_12141c:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_12180c;
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
L_121438:
    PB_LDR(cpu->regs[4], (cpu->regs[28] + (((uint64_t)(uint32_t)(cpu->regs[15])) << 3)));
    cpu->regs[5] = ((uint32_t)(cpu->regs[15] + 1ULL));
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1136ULL;
    cpu->regs[30] = PB_BASE + 0x121450ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121458ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_12145c:
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_121120;
L_121460:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1213e4;
    cpu->regs[26] = 2147483647ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[23] = cpu->regs[26];
    goto L_12112c;
L_121478:
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_12122c;
L_121480:
    cpu->regs[26] = cpu->regs[23];
    cpu->regs[23] = 0ULL;
    goto L_1213c8;
L_12148c:
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(cpu->regs[10])));
    if (FLAG_LE) goto L_1211e0;
L_121494:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(cpu->regs[10])));
    if (FLAG_LE) goto L_12141c;
    cpu->regs[27] = 1ULL;
    goto L_1211e8;
L_1214a4:
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_121340;
L_1214ac:
    cpu->regs[15] = cpu->regs[19];
L_1214b0:
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_121268;
L_1214b4:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_1218fc;
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
L_1214d0:
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(cpu->regs[25])));
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[5] = (FLAG_LE) ? cpu->regs[26] : cpu->regs[25];
    cpu->regs[2] = cpu->regs[2] + 2280ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[15])));
    cpu->regs[4] = PB_BASE + 0x284000ULL;
    cpu->regs[4] = cpu->regs[4] + 2272ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[4] = (FLAG_GE) ? cpu->regs[4] : cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    PB_LDR(cpu->regs[2], (SP + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    cpu->regs[6] = PB_BASE + 0x292000ULL;
    cpu->regs[6] = cpu->regs[6] + 1000ULL;
    cpu->regs[6] = (FLAG_NE) ? cpu->regs[6] : cpu->regs[1];
    cpu->regs[7] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1016ULL;
    cpu->regs[30] = PB_BASE + 0x12151cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121524ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121528:
    cpu->regs[15] = ((uint32_t)(cpu->regs[10] + 1ULL));
    goto L_1214b0;
L_121530:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[7] = cpu->regs[20] + cpu->regs[24];
    FLAG_CMP(cpu->regs[26], cpu->regs[7]);
    if (FLAG_GE) goto L_121024;
L_121540:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_1217a4;
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
L_12155c:
    FLAG_CMP(cpu->regs[24], 0ULL);
    cpu->regs[5] = PB_BASE + 0x289000ULL;
    cpu->regs[6] = PB_BASE + 0x299000ULL;
    cpu->regs[5] = cpu->regs[5] + 688ULL;
    cpu->regs[6] = cpu->regs[6] + 240ULL;
    cpu->regs[5] = (FLAG_NE) ? cpu->regs[6] : cpu->regs[5];
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_121798;
L_12157c:
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 752ULL;
    cpu->regs[30] = PB_BASE + 0x121590ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121598ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_12159c:
    cpu->regs[30] = PB_BASE + 0x1215a0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1215a0:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_121824;
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_GT) goto L_121764;
L_1215b8:
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_121268;
L_1215c8:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 8));
    if ((cpu->regs[0])==0) goto L_121608;
    cpu->regs[19] = 1ULL;
L_1215d4:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1215f0;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3)));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    if ((cpu->regs[1])==0) goto L_121600;
    cpu->regs[25] = cpu->regs[19];
    goto L_120f4c;
L_1215f0:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    cpu->regs[26] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3)));
    if ((cpu->regs[0])!=0) goto L_1215d4;
L_121600:
    cpu->regs[25] = cpu->regs[19];
    goto L_120f94;
L_121608:
    cpu->regs[25] = 1ULL;
    cpu->regs[26] = 1ULL;
    cpu->regs[19] = cpu->regs[25];
    goto L_120f9c;
L_121618:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])!=0) goto L_121660;
    cpu->regs[4] = PB_BASE + 0x299000ULL;
    cpu->regs[4] = cpu->regs[4] + 240ULL;
    cpu->regs[20] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[20] + 704ULL;
    PB_STR((SP + 24), cpu->regs[1]);
L_121640:
    PB_LDR(cpu->regs[3], (SP + 24));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 1384ULL;
    cpu->regs[30] = PB_BASE + 0x121654ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11f220ULL);
L_121654:
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x12165cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121660:
    cpu->regs[4] = PB_BASE + 0x292000ULL;
    cpu->regs[4] = cpu->regs[4] + 3040ULL;
    goto L_121640;
L_12166c:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])!=0) goto L_1218f0;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    PB_STR((SP + 24), cpu->regs[1]);
L_121694:
    cpu->regs[2] = 2147483647ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(cpu->regs[2])));
    cpu->regs[1] = cpu->regs[1] + 2296ULL;
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[4] = PB_BASE + 0x284000ULL;
    cpu->regs[4] = cpu->regs[4] + 2272ULL;
    cpu->regs[6] = PB_BASE + 0x292000ULL;
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[4] : cpu->regs[1];
    FLAG_CMP(((uint32_t)(cpu->regs[15])), ((uint32_t)(1ULL)));
    cpu->regs[6] = cpu->regs[6] + 1000ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[7] = cpu->regs[24];
    cpu->regs[6] = (FLAG_NE) ? cpu->regs[6] : cpu->regs[1];
    cpu->regs[5] = cpu->regs[15];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1016ULL;
    cpu->regs[30] = PB_BASE + 0x1216e0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_121654;
L_1216e4:
    cpu->regs[22] = cpu->regs[22] << 3;
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[28] + cpu->regs[22]));
    cpu->regs[30] = PB_BASE + 0x1216f4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xedfe0ULL);
    if ((cpu->regs[0])!=0) goto L_121abc;
    cpu->regs[30] = PB_BASE + 0x1216fcULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_121654;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    goto L_1212a4;
L_121708:
    cpu->regs[15] = 0ULL;
L_12170c:
    PB_LDR(cpu->regs[3], (SP + 24)); PB_LDR(cpu->regs[4], (SP + 24) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[15] + 1ULL));
    PB_LDR(cpu->regs[2], (SP + 48));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x121720ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x22bb60ULL);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x121728ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_12172c:
    cpu->regs[15] = 0ULL;
L_121730:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[3] = cpu->regs[15];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x121750ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121758ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_12175c:
    cpu->regs[7] = cpu->regs[24];
    goto L_121540;
L_121764:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])!=0) goto L_121864;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[7] = cpu->regs[24];
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    PB_STR((SP + 24), cpu->regs[1]);
L_121798:
    cpu->regs[6] = PB_BASE + 0x292000ULL;
    cpu->regs[6] = cpu->regs[6] + 1000ULL;
    goto L_12157c;
L_1217a4:
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_12155c;
L_1217bc:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_121844;
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_LE) goto L_1215b8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[6] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[7] = cpu->regs[24];
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[6] = cpu->regs[6] + 1000ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_12157c;
L_12180c:
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_121438;
L_121824:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[7] = cpu->regs[20] + cpu->regs[24];
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_GT) goto L_121540;
    cpu->regs[25] = 0ULL;
    goto L_121268;
L_121844:
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[7] = cpu->regs[20] + cpu->regs[24];
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_GT) goto L_121880;
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = 0ULL;
    goto L_121268;
L_121864:
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[5] = PB_BASE + 0x299000ULL;
    cpu->regs[7] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
    cpu->regs[5] = cpu->regs[5] + 240ULL;
    cpu->regs[19] = 0ULL;
    goto L_121798;
L_121880:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_12155c;
L_1218a8:
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[7] = cpu->regs[20] + cpu->regs[24];
    FLAG_CMP(cpu->regs[26], cpu->regs[7]);
    if (FLAG_GE) goto L_120fb8;
    goto L_121540;
L_1218c0:
    cpu->regs[30] = PB_BASE + 0x1218c4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 0ULL;
    goto L_121094;
L_1218cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1208ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1218e4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x1218ecULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_1218f0:
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
    goto L_121694;
L_1218fc:
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_1214d0;
L_121914:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1352ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12192cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121934ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121938:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_121a50;
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
L_121954:
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1440ULL;
    cpu->regs[30] = PB_BASE + 0x121964ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x12196cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121970:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_1219c4;
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
L_12198c:
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    cpu->regs[30] = PB_BASE + 0x12199cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_121654;
L_1219a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 944ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1219b8ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x1219c0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_1219c4:
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_12198c;
L_1219dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1219f4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x1219fcULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121a00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x121a18ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121a20ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121a24:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2936));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (SP + 72));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[1] = cpu->regs[1] + 1192ULL;
    cpu->regs[30] = PB_BASE + 0x121a44ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121a4cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121a50:
    cpu->regs[20] = PB_BASE + 0x289000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[20] + 704ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    goto L_121954;
L_121a68:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 32), cpu->regs[0]);
    goto L_120fd8;
L_121a74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 720ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x121a8cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121a94ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121a98:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x121ab0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121ab8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121abc:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])!=0) goto L_121b08;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[20] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[20] + 4000ULL;
    PB_STR((SP + 24), cpu->regs[1]);
L_121ae4:
    PB_LDR(cpu->regs[4], (cpu->regs[28] + cpu->regs[22]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 1288ULL;
    cpu->regs[30] = PB_BASE + 0x121afcULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0x121b04ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x22bd0cULL);
    goto L_121094;
L_121b08:
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[3] + 3040ULL;
    goto L_121ae4;
    /* nop */
    /* nop */
    /* nop */
}
