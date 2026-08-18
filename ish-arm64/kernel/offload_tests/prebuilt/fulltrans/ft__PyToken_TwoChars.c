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

void ft__PyToken_TwoChars(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 33ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(91ULL)));
    if (FLAG_HI) goto L_1087a4;
    cpu->regs[2] = PB_BASE + 0x2b4000ULL;
    cpu->regs[2] = cpu->regs[2] + 2952ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    cpu->regs[0] = PB_BASE + 0x1087a4ULL;
    cpu->regs[2] = cpu->regs[0] + (((uint64_t)(int64_t)(int8_t)(cpu->regs[2])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[2]); return;
L_1087a4:
    cpu->regs[0] = 55ULL;
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 53ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 27ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_108914;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(62ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 51ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 36ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(42ULL)));
    if (FLAG_EQ) goto L_1088f4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 38ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 28ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 50ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 40ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_1088fc;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(62ULL)));
    if (FLAG_EQ) goto L_10891c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(60ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 33ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_108904;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(62ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 34ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    if (FLAG_EQ) goto L_10890c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 39ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 42ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 41ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 43ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1088f4:
    cpu->regs[0] = 35ULL;
    return;
L_1088fc:
    cpu->regs[0] = 29ULL;
    return;
L_108904:
    cpu->regs[0] = 30ULL;
    return;
L_10890c:
    cpu->regs[0] = cpu->regs[1];
    return;
L_108914:
    cpu->regs[0] = 37ULL;
    return;
L_10891c:
    cpu->regs[0] = 28ULL;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 24));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1];
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 10));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_108af4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_108a54;
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 9));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[1] & 63);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_1089b0;
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[19] = 0ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[1]);
    if (FLAG_NE) goto L_1089c8;
L_10898c:
    cpu->regs[0] = cpu->regs[19] << 4;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + cpu->regs[0]));
    if ((cpu->regs[21])==0) goto L_1089a4;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_108a0c;
L_1089a4:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_NE) goto L_10898c;
L_1089b0:
    cpu->regs[0] = 0ULL;
L_1089b4:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1089c8:
    cpu->regs[0] = cpu->regs[19] << 4;
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_108a04;
    /* nop */
    /* nop */
L_1089e0:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1089e8ULL; PB_CALL(1, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_1089ec:
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_EQ) goto L_1089b0;
    cpu->regs[0] = cpu->regs[19] << 4;
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    if ((cpu->regs[0])!=0) goto L_1089e0;
L_108a04:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_1089ec;
L_108a0c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_108a34;
L_108a14:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_1089a4;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_STR((cpu->regs[21] + -8), cpu->regs[0]);
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_NE) goto L_10898c;
    goto L_1089b0;
L_108a34:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_108c38;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_108a14;
    goto L_1089a4;
L_108a54:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_1089b0;
    cpu->regs[1] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[23], cpu->regs[1]);
    if (FLAG_NE) goto L_108b8c;
    if ((cpu->regs[0])==0) goto L_108a78;
    cpu->regs[30] = PB_BASE + 0x108a78ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x108700ULL);
L_108a78:
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_108a90;
    cpu->regs[30] = PB_BASE + 0x108a90ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x108700ULL);
L_108a90:
    FLAG_CMP(cpu->regs[22], 2ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_108aa8;
    cpu->regs[30] = PB_BASE + 0x108aa8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x108700ULL);
L_108aa8:
    FLAG_CMP(cpu->regs[22], 3ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_108ac0;
    cpu->regs[30] = PB_BASE + 0x108ac0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x108700ULL);
L_108ac0:
    FLAG_CMP(cpu->regs[22], 4ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[20] = 4ULL;
    goto L_108ad8;
L_108ad4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
L_108ad8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    if ((cpu->regs[0])==0) goto L_108ae4;
    cpu->regs[30] = PB_BASE + 0x108ae4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x108700ULL);
L_108ae4:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[20]);
    if (FLAG_NE) goto L_108ad4;
    goto L_1089b0;
L_108af4:
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 9));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[1] & 63);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_1089b0;
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[19] = 0ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[1]);
    if (FLAG_NE) goto L_108b50;
L_108b24:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    if ((cpu->regs[0])==0) goto L_108b3c;
    cpu->regs[30] = PB_BASE + 0x108b30ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x108700ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_108b3c;
    cpu->regs[30] = PB_BASE + 0x108b3cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x108700ULL);
L_108b3c:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_NE) goto L_108b24;
    goto L_1089b0;
L_108b50:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[21];
    if ((cpu->regs[0])==0) goto L_108b78;
    cpu->regs[30] = PB_BASE + 0x108b60ULL; PB_CALL(9, cpu, tlb, cpu->regs[23]);
    cpu->regs[1] = cpu->regs[21];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_108b78;
    cpu->regs[30] = PB_BASE + 0x108b74ULL; PB_CALL(10, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_108b78:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_NE) goto L_108b50;
    goto L_1089b0;
L_108b8c:
    if ((cpu->regs[0])==0) goto L_108b9c;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x108b98ULL; PB_CALL(11, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_108b9c:
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_108bbc;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x108bb8ULL; PB_CALL(12, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_108bbc:
    FLAG_CMP(cpu->regs[22], 2ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_108bdc;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x108bd8ULL; PB_CALL(13, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_108bdc:
    FLAG_CMP(cpu->regs[22], 3ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_108bfc;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x108bf8ULL; PB_CALL(14, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_108bfc:
    FLAG_CMP(cpu->regs[22], 4ULL);
    if (FLAG_EQ) goto L_1089b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[20] = 4ULL;
    goto L_108c14;
L_108c10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
L_108c14:
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    if ((cpu->regs[0])==0) goto L_108c28;
    cpu->regs[30] = PB_BASE + 0x108c24ULL; PB_CALL(15, cpu, tlb, cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1089b4;
L_108c28:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[20]);
    if (FLAG_NE) goto L_108c10;
    goto L_1089b0;
L_108c38:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x108c40ULL; PB_CALL(16, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_108a14;
    goto L_1089a4;
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_109f74;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_109f84;
L_108c7c:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_109f8c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x108ca4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])!=0) goto L_108db4;
L_108ca8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_108f48;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(601ULL)));
    if (FLAG_EQ) goto L_1091b0;
L_108cd4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_108f74;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(603ULL)));
    if (FLAG_EQ) goto L_109148;
L_108cfc:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_108fa0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(602ULL)));
    if (FLAG_EQ) goto L_109050;
L_108d24:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109b48;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_108fcc;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_108fe8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = cpu->regs[20];
L_108d58:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_108e8c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1099a0;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_108ed0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_108e8c;
L_108d94:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_108eb8;
L_108da8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108db0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x116c80ULL);
    if ((cpu->regs[0])==0) goto L_108dd4;
L_108db4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_108db8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_108dc8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_108dd4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1090cc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_109000;
L_108e00:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1090f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_109088;
L_108e28:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109180;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_EQ) goto L_1092b8;
L_108e50:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109130;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    cpu->regs[1] = cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1091e8;
L_108e68:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(52ULL)));
    if (FLAG_EQ) goto L_108efc;
L_108e7c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_108e80:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    goto L_108db8;
L_108e8c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x108ea4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x10a34cULL);
    if ((cpu->regs[0])!=0) goto L_108db4;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
L_108eac:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_108da8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_108eb8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_108ec4:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108dc8;
L_108ed0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108ed8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1099c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_108e8c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108d94;
L_108efc:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x108f08ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109130;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2504));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x108f2cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x10c468ULL);
    if ((cpu->regs[0])!=0) goto L_108db4;
L_108f30:
    cpu->regs[30] = PB_BASE + 0x108f34ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_108e80;
L_108f38:
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108eb8;
L_108f48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108f50ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1099b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(601ULL)));
    if (FLAG_EQ) goto L_1091ac;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108cd4;
L_108f74:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108f7cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1099e0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(603ULL)));
    if (FLAG_EQ) goto L_109144;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108cfc;
L_108fa0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108fa8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1099d0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(602ULL)));
    if (FLAG_EQ) goto L_10904c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108d24;
L_108fcc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108fd4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1099a0;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_NE) goto L_109b6c;
L_108fe8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x108ff0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_109994;
    cpu->regs[0] = cpu->regs[21];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_108d58;
L_109000:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109e30;
L_10901c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e20;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109030ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x19ce48ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1091fc;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_10903c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = cpu->regs[21];
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108db8;
L_10904c:
    cpu->regs[20] = cpu->regs[1];
L_109050:
    cpu->regs[1] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x10905cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109130;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x109080ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x10c468ULL);
    if ((cpu->regs[0])!=0) goto L_108db4;
    goto L_108f30;
L_109088:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109ba8;
L_1090a4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109b98;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1090b8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x19e628ULL);
    if ((cpu->regs[0])==0) goto L_109420;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_1090c0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108db8;
L_1090cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1090d4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_109910;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_109000;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108e00;
L_1090f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109100ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_109124;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_109088;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108e28;
L_109124:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_109130:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_108ec4;
L_109144:
    cpu->regs[20] = cpu->regs[1];
L_109148:
    cpu->regs[1] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x109154ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109130;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x109178ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x10c468ULL);
    if ((cpu->regs[0])!=0) goto L_108db4;
    goto L_108f30;
L_109180:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109188ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_109124;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_EQ) goto L_1092b8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_108e50;
L_1091ac:
    cpu->regs[20] = cpu->regs[1];
L_1091b0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1091bcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109130;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1091e0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x10c468ULL);
    if ((cpu->regs[0])!=0) goto L_108db4;
    goto L_108f30;
L_1091e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1091f0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_109920;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    goto L_108e68;
L_1091fc:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109904;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109f58;
L_109220:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[1] = 7ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x109234ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((cpu->regs[0])==0) goto L_109e18;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109e0c;
L_109250:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109b14;
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109264ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x19a680ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_109288;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109b14;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109280ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x119360ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109b24;
L_109288:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1092a0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1098b8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_10903c;
L_1092b8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 6000ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109e80;
L_1092d8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e74;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    cpu->regs[25] = cpu->regs[21];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109e3c;
L_109304:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109b74;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
L_10931c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x109328ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1094ec;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109eec;
L_109344:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109b38;
    PB_LDRW(cpu->regs[28], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109358ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1a34a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_109408;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
L_109364:
    cpu->regs[24] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[28]);
L_10936c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1094f0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 26ULL;
    cpu->regs[30] = PB_BASE + 0x109388ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1094ec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x109398ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109f40;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[28], (cpu->regs[0] + 28) + 4);
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STRW((SP + 108), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1093b0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1a3a68ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109a90;
L_1093b8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1093c4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x19fc20ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109a84;
L_1093cc:
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[5] = cpu->regs[28];
    PB_LDRW(cpu->regs[4], (SP + 108));
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1093e8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1a3accULL);
    if ((cpu->regs[0])==0) goto L_109b58;
L_1093ec:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_108db8;
L_109408:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x109414ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_10936c;
    goto L_109364;
L_109420:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109bd0;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109c28;
L_109444:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109bdc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[27])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
L_109464:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x109470ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109c08;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10947cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x119360ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109c08;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10948cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x117288ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109c08;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x1094a0ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109c08;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1094b0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109bbc;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[25];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1094d0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1a6dacULL);
    if ((cpu->regs[0])==0) goto L_109bb4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1090c0;
L_1094ec:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
L_1094f0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e68;
    cpu->regs[1] = 25ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109504ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((cpu->regs[0])==0) goto L_109f50;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109e00;
L_109520:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e90;
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109534ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1a34a0ULL);
    if ((cpu->regs[0])!=0) goto L_1097cc;
L_109538:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
L_10953c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10954cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_109560;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x10955cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_109870;
L_109560:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109574ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_10958c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x109584ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10980c;
L_10958c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_109590:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
L_10959c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1095a0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109f14;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109ef8;
L_1095bc:
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109eb0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
L_1095d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x1095e0ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109638;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1095ecULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x19e7e0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109638;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 26ULL;
    cpu->regs[30] = PB_BASE + 0x109600ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109638;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x109610ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_109638;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 32));
    cpu->regs[2] = cpu->regs[25];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28) + 4);
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x10962cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1ab420ULL);
    if ((cpu->regs[0])!=0) goto L_1093ec;
    cpu->regs[30] = PB_BASE + 0x109634ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_109ebc;
L_109638:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_109644:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1097b8;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109c6c;
L_109660:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109c84;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
L_109678:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x109684ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10992c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109690ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1a38ecULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10992c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1096a0ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x117288ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10992c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 26ULL;
    cpu->regs[30] = PB_BASE + 0x1096b4ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10992c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1096c4ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109ea0;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[24] + 0) + 8);
    cpu->regs[4] = cpu->regs[27];
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[5] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[5] + 28) + 4);
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1096e8ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1eaf00ULL);
    if ((cpu->regs[0])!=0) goto L_1093ec;
    cpu->regs[30] = PB_BASE + 0x1096f0ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_109ed4;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
L_1096f8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
L_1096fc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_109700:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1097b8;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109a9c;
L_10971c:
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_109a60;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[27])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
L_109734:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x109740ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10974cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x119360ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10975cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x117288ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 26ULL;
    cpu->regs[30] = PB_BASE + 0x109770ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109ad8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x109780ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1097ac;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[25];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1097a0ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1a61ecULL);
    if ((cpu->regs[0])!=0) goto L_1093ec;
    cpu->regs[30] = PB_BASE + 0x1097a8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_109a6c;
L_1097ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1097b8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_108e50;
L_1097cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1097d8ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109538;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109cac;
L_1097f4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109cb8;
L_1097fc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_10953c;
L_10980c:
    cpu->regs[1] = PB_BASE + 0x1ea000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3824ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x109820ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10958c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 20),&_a,4); tlb_read(tlb,(cpu->regs[24] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 2960ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 28),&_a,4); tlb_read(tlb,(cpu->regs[24] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
L_109844:
    cpu->regs[30] = PB_BASE + 0x109848ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x10984cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_109590;
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_10959c;
L_109870:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x10987cULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109560;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10988cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x111f50ULL);
    if ((cpu->regs[0])==0) goto L_109560;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    cpu->regs[5] = 18446744073709551611ULL;
    cpu->regs[6] = cpu->regs[6] + 2904ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 20),&_a,4); tlb_read(tlb,(cpu->regs[24] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[4] = cpu->regs[5];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[19];
    goto L_109844;
L_1098b8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_1098c0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_109fbc;
L_1098cc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1098d4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1098f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1098e8ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x10dc40ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10903c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
L_1098f8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108e00;
L_109904:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_108e00;
L_109910:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108e00;
L_109920:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108e7c;
L_10992c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1096f8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1096fc;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_109ab8;
L_109958:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x109964ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10997c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x109974ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1099f0;
L_10997c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_109980:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
L_10998c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    goto L_1096fc;
L_109994:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_1099a0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108eac;
L_1099b0:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108cd4;
L_1099c0:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108d94;
L_1099d0:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108d24;
L_1099e0:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_108cfc;
L_1099f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1099f8ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x111f50ULL);
    if ((cpu->regs[0])==0) goto L_10997c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109a04ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_10997c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 26ULL;
    cpu->regs[30] = PB_BASE + 0x109a14ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10997c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 20),&_a,4); tlb_read(tlb,(cpu->regs[24] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[6] = cpu->regs[6] + 3016ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 28),&_a,4); tlb_read(tlb,(cpu->regs[24] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[30] = PB_BASE + 0x109a3cULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x109a40ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_109980;
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_10998c;
L_109a60:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109a68ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_109afc;
L_109a6c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = cpu->regs[1];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1097b8;
L_109a84:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1093cc;
L_109a90:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1093b8;
L_109a9c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109aa4ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_10971c;
L_109aac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1097b8;
L_109ab8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109ac0ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109958;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_10998c;
L_109ad8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[27]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1097ac;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109aac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109af4ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x1e4a60ULL);
    if ((cpu->regs[0])==0) goto L_1097ac;
    goto L_1093ec;
L_109afc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[27])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109734;
    goto L_109aac;
L_109b14:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1098c0;
L_109b24:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1098c0;
L_109b38:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1094f0;
L_109b48:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_108ec4;
L_109b58:
    cpu->regs[30] = PB_BASE + 0x109b5cULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_109b80;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    goto L_10959c;
L_109b6c:
    cpu->regs[0] = cpu->regs[21];
    goto L_108d58;
L_109b74:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109b7cULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_109e54;
L_109b80:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1095a0;
L_109b98:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108e28;
L_109ba8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109bb0ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1090a4;
L_109bb4:
    cpu->regs[30] = PB_BASE + 0x109bb8ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_109be8;
L_109bbc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_109bd0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_108e28;
L_109bdc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109be4ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_109c44;
L_109be8:
    cpu->regs[1] = 1ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_109bd0;
L_109c08:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[27]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_109bbc;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109c58;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109c24ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x1e4a60ULL);
    goto L_109bbc;
L_109c28:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109c30ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109444;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_109bd0;
L_109c44:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[27])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109464;
L_109c58:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_109bd0;
L_109c6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109c74ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109660;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    goto L_1096fc;
L_109c84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109c8cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_109ed4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109678;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    goto L_1096fc;
L_109cac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109cb4ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1097f4;
L_109cb8:
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109cc4ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109ce0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 11ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x109cdcULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_109d74;
L_109ce0:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1097fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109cf4ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_109da8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x109d04ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_109da8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x109d14ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109da8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109d24ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x111f50ULL);
    if ((cpu->regs[0])==0) goto L_109da8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 20),&_a,4); tlb_read(tlb,(cpu->regs[24] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[5] = 18446744073709551611ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[6] = cpu->regs[6] + 2904ULL;
    cpu->regs[4] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
L_109d4c:
    cpu->regs[30] = PB_BASE + 0x109d50ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x109d54ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_109df0;
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_10953c;
L_109d74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[24] + 44));
    cpu->regs[6] = cpu->regs[6] + 2864ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 32),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[5] = 18446744073709551615ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 40),&_s,4); cpu->regs[4] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[0] = cpu->regs[19];
    goto L_109d4c;
L_109da8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1097fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109dbcULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_109dec;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x109dccULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_109dec;
    cpu->regs[1] = PB_BASE + 0x280000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2436ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x109de8ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10a054;
L_109dec:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_109df0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_10953c;
L_109e00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109e08ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_109520;
L_109e0c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109e14ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_109250;
L_109e18:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_1098c0;
L_109e20:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108e00;
L_109e30:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109e38ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_10901c;
L_109e3c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109e44ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_109e68;
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    goto L_109304;
L_109e54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_10931c;
L_109e68:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1095a0;
L_109e74:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_108e50;
L_109e80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109e88ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    goto L_1092d8;
L_109e90:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_10959c;
L_109ea0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_109700;
L_109eb0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109eb8ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_109f28;
L_109ebc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = cpu->regs[1];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_109644;
L_109ed4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = cpu->regs[1];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_109700;
L_109eec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109ef4ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_109344;
L_109ef8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109f00ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1095bc;
L_109f08:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_109644;
L_109f14:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_108e50;
L_109f28:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1095d4;
    goto L_109f08;
L_109f40:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1095a0;
L_109f50:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_10959c;
L_109f58:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109f60ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109220;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1098d4;
L_109f74:
    cpu->regs[30] = PB_BASE + 0x109f78ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_108c7c;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_109f84:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_108ec4;
L_109f8c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109f94ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_108f38;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_109130;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109fb4ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])==0) goto L_108ca8;
    goto L_108db4;
L_109fbc:
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1098cc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10a078;
L_109fd4:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x109fe4ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10a094;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x109ff0ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x118420ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10a094;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x10a004ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10a094;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 32),&_a,4); tlb_read(tlb,(cpu->regs[21] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 2776ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 40),&_a,4); tlb_read(tlb,(cpu->regs[21] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
L_10a028:
    cpu->regs[30] = PB_BASE + 0x10a02cULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x10a030ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_10a108;
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_10a048:
    cpu->regs[1] = cpu->regs[3];
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1098cc;
L_10a054:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 20),&_a,4); tlb_read(tlb,(cpu->regs[24] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 2960ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[24] + 28),&_a,4); tlb_read(tlb,(cpu->regs[24] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_109d4c;
L_10a078:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10a080ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_109fd4;
L_10a088:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_10a048;
L_10a094:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10a088;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x10a0acULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10a104;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x10a0bcULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10a104;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10a0ccULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_10a104;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x10a0dcULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_10a104;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 20),&_a,4); tlb_read(tlb,(cpu->regs[21] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 2816ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 28),&_a,4); tlb_read(tlb,(cpu->regs[21] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_10a028;
L_10a104:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_10a108:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10a048;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    if ((cpu->regs[19])==0) goto L_10a154;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    cpu->regs[3] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10a18c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10a164;
L_10a154:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_10a164:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10a1a4;
L_10a16c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10a154;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_10a18c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_10a1a4:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10a1c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10a16c;
    goto L_10a154;
L_10a1c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10a1c8ULL; PB_CALL(146, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10a16c;
    goto L_10a154;
}
