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

void ft__PyObject_VisitManagedDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    if (!((cpu->regs[2] >> 4) & 1)) goto L_142e84;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + -24));
    if (!((cpu->regs[20] >> 0) & 1)) goto L_142f78;
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[1] + 880));
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_LE) goto L_142e80;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_142e98;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = 0ULL;
    /* nop */
    /* nop */
L_142e60:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + (cpu->regs[19] << 3)));
    if ((cpu->regs[21])==0) goto L_142e74;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_142f4c;
L_142e74:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_LT) goto L_142e60;
L_142e80:
    PB_LDR(cpu->regs[23], (SP + 48));
L_142e84:
    cpu->regs[0] = 0ULL;
L_142e88:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_142e98:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1));
    if ((cpu->regs[0])==0) goto L_142fc8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x142ea8ULL; PB_CALL(1, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14301c;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_LE) goto L_142e80;
L_142eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 9));
    if ((cpu->regs[0])==0) goto L_142fd8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x142ec8ULL; PB_CALL(2, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14301c;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_LE) goto L_142e80;
L_142ed8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 17));
    if ((cpu->regs[0])==0) goto L_142ef0;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x142ee8ULL; PB_CALL(3, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14301c;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
L_142ef0:
    FLAG_CMP(cpu->regs[3], 3ULL);
    if (FLAG_LE) goto L_142e80;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 25));
    if ((cpu->regs[0])==0) goto L_142f10;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x142f08ULL; PB_CALL(4, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14301c;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
L_142f10:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[22] = 4ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[22]);
    if (FLAG_LE) goto L_142e80;
L_142f20:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[22] << 3)));
    cpu->regs[1] = cpu->regs[21];
    if ((cpu->regs[0])==0) goto L_142fb4;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x142f34ULL; PB_CALL(5, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14301c;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
    FLAG_CMP(cpu->regs[22], cpu->regs[3]);
    if (FLAG_LT) goto L_142f20;
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_142e84;
L_142f4c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_142fe8;
L_142f54:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + -8));
    cpu->regs[1] = cpu->regs[0] - 4ULL;
    if (!((cpu->regs[0] >> 1) & 1)) goto L_142e74;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_STR((cpu->regs[21] + -8), cpu->regs[1]);
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_GT) goto L_142e60;
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_142e84;
L_142f78:
    if ((cpu->regs[20])==0) goto L_142e84;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_142f98;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x142f94ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x108700ULL);
    goto L_142e84;
L_142f98:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_142fb4:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[3]);
    if (FLAG_LT) goto L_142f20;
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_142e84;
L_142fc8:
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_NE) goto L_142eb8;
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_142e84;
L_142fd8:
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_GT) goto L_142ed8;
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_142e84;
L_142fe8:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_143008;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142f54;
    goto L_142e74;
L_143008:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x143010ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_142f54;
    goto L_142e74;
L_14301c:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_142e88;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_143298;
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[6], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[6];
    if (!((cpu->regs[2] >> 31) & 1)) goto L_14313c;
    PB_LDR(cpu->regs[2], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_14313c;
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 344));
    cpu->regs[4] = cpu->regs[20];
    if ((cpu->regs[5])==0) goto L_14323c;
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_1430ec;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_143148;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_1430ec;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_143148;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_1430ec;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_143148;
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_EQ) goto L_1430ec;
    cpu->regs[5] = cpu->regs[5] + 24ULL;
    cpu->regs[3] = 3ULL;
L_1430d4:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + (cpu->regs[3] << 3)));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_143148;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_1430d4;
L_1430ec:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_143110;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    FLAG_CMP((cpu->regs[1]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_143110:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 24));
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 24));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 3768ULL;
    cpu->regs[30] = PB_BASE + 0x143134ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_1431cc;
L_14313c:
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x143144ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c5acULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_143290;
L_143148:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_143268;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 16));
L_143158:
    FLAG_CMP(cpu->regs[4], cpu->regs[20]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[4] : cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[1] = (FLAG_GT) ? cpu->regs[1] : (0ULL + 1);
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x143174ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_143284;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 40));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 40));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
    if (((cpu->regs[1] >> 0) & 1)) goto L_1431e8;
    if ((cpu->regs[21])!=0) goto L_143204;
L_143190:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 48));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1431a0ULL; PB_CALL(11, cpu, tlb, cpu->regs[4]);
    cpu->regs[20] = cpu->regs[0];
L_1431a4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1431e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1431e0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1431c8ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48));
L_1431cc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1431e0:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_1431cc;
L_1431e8:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 48));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1431fcULL; PB_CALL(13, cpu, tlb, cpu->regs[4]);
    cpu->regs[20] = cpu->regs[0];
    goto L_1431a4;
L_143204:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_143218;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_143190;
L_143218:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x143238ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1431a4;
L_14323c:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_143148;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 256));
    if ((cpu->regs[0])!=0) goto L_14323c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1430ec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_143158;
L_143268:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 433ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14327cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x9bb50ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_1431cc;
L_143284:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[20] = 0ULL;
    goto L_1431cc;
L_143290:
    PB_LDR(cpu->regs[6], (cpu->regs[23] + 8));
    goto L_1430ec;
L_143298:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_1432bc;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    FLAG_CMP((cpu->regs[3]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_1432bc:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 24));
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[1] = cpu->regs[1] + 3712ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1432d8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1431cc;
    /* nop */
}
