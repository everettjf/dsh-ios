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

void ft__Py_wfopen(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[3] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2920ULL;
    cpu->regs[0] = cpu->regs[0] + 3064ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b20ccULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b2128;
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x1b20ecULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7b740ULL);
    FLAG_CMP(cpu->regs[0], 9ULL);
    if (FLAG_HI) goto L_1b219c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b2104ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1b22e8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1b2124;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1b2114ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7beb0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1b2120ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd7784ULL);
    if ((cpu->regs[19])!=0) goto L_1b215c;
L_1b2124:
    PB_LDR(cpu->regs[21], (SP + 64));
L_1b2128:
    cpu->regs[19] = 0ULL;
L_1b212c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1b2184;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1b215c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1b2164ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7bf20ULL);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b2174ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1b54e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b218c;
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_1b212c;
L_1b2184:
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1b218cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1b218c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1b2194ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_1b2128;
L_1b219c:
    cpu->regs[30] = PB_BASE + 0x1b21a0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    cpu->regs[1] = 22ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1b2128;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[4];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 120));
    cpu->regs[30] = PB_BASE + 0x1b21ecULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1ab1c0ULL);
    if ((cpu->regs[0])==0) goto L_1b22d0;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1b2200ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x135248ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1b2288;
L_1b220c:
    if (((cpu->regs[2] >> 63) & 1)) goto L_1b22d0;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(106ULL)));
    if (FLAG_EQ) goto L_1b2250;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(262ULL)));
    if (FLAG_NE) goto L_1b2258;
    cpu->regs[5] = cpu->regs[2] << 1;
    cpu->regs[19] = 106ULL;
    cpu->regs[2] = cpu->regs[5] | 1ULL;
L_1b222c:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x12f7d0ULL); return; };
L_1b2250:
    cpu->regs[2] = cpu->regs[2] << 1;
    goto L_1b222c;
L_1b2258:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(141ULL)));
    if (FLAG_EQ) goto L_1b22c4;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(263ULL)));
    if (FLAG_EQ) goto L_1b22a8;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(265ULL)));
    if (FLAG_EQ) goto L_1b22b8;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(264ULL)));
    if (FLAG_NE) goto L_1b222c;
    cpu->regs[5] = cpu->regs[2] << 2;
    cpu->regs[19] = 141ULL;
    cpu->regs[2] = cpu->regs[5] | 1ULL;
    goto L_1b222c;
L_1b2288:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1b220c;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1b22a0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_1b220c;
L_1b22a8:
    cpu->regs[5] = cpu->regs[2] << 2;
    cpu->regs[19] = 141ULL;
    cpu->regs[2] = cpu->regs[5] | 3ULL;
    goto L_1b222c;
L_1b22b8:
    cpu->regs[2] = cpu->regs[2] << 2;
    cpu->regs[19] = 141ULL;
    goto L_1b222c;
L_1b22c4:
    cpu->regs[5] = cpu->regs[2] << 2;
    cpu->regs[2] = cpu->regs[5] | 2ULL;
    goto L_1b222c;
L_1b22d0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1b22e8:
    SP = SP - 48ULL;
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1b232cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b2384ULL);
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)2LL)); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1b2378;
L_1b2338:
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1b2374;
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_1b2374:
    cpu->regs[30] = PB_BASE + 0x1b2378ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1b2378:
    cpu->regs[1] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    goto L_1b2338;
L_1b2384:
    if ((((uint32_t)(cpu->regs[5])))!=0) goto L_1b2400;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 2964));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1b2408;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[24] = cpu->regs[0];
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 2528));
    cpu->regs[23] = cpu->regs[1];
    FLAG_CMP(cpu->regs[5], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1b2444;
L_1b23d0:
    if ((((uint32_t)(cpu->regs[5])))!=0) goto L_1b2418;
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[5] = cpu->regs[6];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(17, cpu, tlb, PB_BASE + 0x135550ULL); return; };
L_1b2400:
    cpu->regs[5] = cpu->regs[6];
    { PB_CALL(18, cpu, tlb, PB_BASE + 0x135550ULL); return; };
L_1b2408:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[5] = cpu->regs[6];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x1c6fd0ULL); return; };
L_1b2418:
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1b245c;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1b24b0;
    cpu->regs[1] = 4294967293ULL;
L_1b242c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1b2444:
    PB_STRW((SP + 92), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x1b244cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x17ba00ULL);
    PB_LDRW(cpu->regs[6], (SP + 92));
    cpu->regs[5] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 2528), cpu->regs[0]);
    goto L_1b23d0;
L_1b245c:
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
L_1b2464:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1b246cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7b8b0ULL);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1b24bc;
    cpu->regs[30] = PB_BASE + 0x1b247cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd7700ULL);
    if ((cpu->regs[0])==0) goto L_1b24c4;
L_1b2480:
    cpu->regs[25] = 0ULL;
    cpu->regs[2] = 4294910848ULL;
L_1b2488:
    FLAG_CMP(cpu->regs[26], cpu->regs[25]);
    if (FLAG_EQ) goto L_1b24d0;
    PB_LDRW(cpu->regs[1], (cpu->regs[24] + (cpu->regs[25] << 2)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1b24e4;
L_1b24a0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    PB_STRB((cpu->regs[0] + cpu->regs[25]), cpu->regs[1]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_1b2488;
L_1b24b0:
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    goto L_1b2464;
L_1b24bc:
    cpu->regs[30] = PB_BASE + 0x1b24c0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])!=0) goto L_1b2480;
L_1b24c4:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = 4294967295ULL;
    goto L_1b242c;
L_1b24d0:
    PB_STRB((cpu->regs[0] + cpu->regs[26]), 0ULL);
    cpu->regs[1] = 0ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1b242c;
L_1b24e4:
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1b24f0;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_1b24a0;
L_1b24f0:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1b251c;
    cpu->regs[30] = PB_BASE + 0x1b24f8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xd7784ULL);
    if ((cpu->regs[22])==0) goto L_1b2500;
L_1b24fc:
    PB_STR((cpu->regs[22] + 0), cpu->regs[25]);
L_1b2500:
    if ((cpu->regs[21])==0) goto L_1b2510;
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[0] + 2928ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
L_1b2510:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = 4294967294ULL;
    goto L_1b242c;
L_1b251c:
    cpu->regs[30] = PB_BASE + 0x1b2520ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((cpu->regs[22])!=0) goto L_1b24fc;
    goto L_1b2500;
}
