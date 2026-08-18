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

void ft__PyWarnings_Init(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x51d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 8));
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[6] + 80),&_s,1); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1abb20;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[4];
    cpu->regs[23] = cpu->regs[5];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[2];
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 16));
    PB_LDRW(cpu->regs[2], (cpu->regs[6] + 84));
    PB_LDRW(cpu->regs[25], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(12ULL)));
    PB_STRW((cpu->regs[6] + 84), cpu->regs[2]);
    cpu->regs[26] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0x1ab874ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abac8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 84));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[1] + 84), cpu->regs[0]);
    if ((cpu->regs[27])==0) goto L_1abb7c;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 32) + 4);
    cpu->regs[1] = cpu->regs[27];
    PB_LDRW(cpu->regs[6], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[7], (cpu->regs[20] + 40) + 4);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ab8a8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abb7c;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_NE) goto L_1ab9dc;
    cpu->regs[0] = 1ULL;
L_1ab8c0:
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 24));
    PB_STRW((cpu->regs[1] + 76), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1abb94;
L_1ab8cc:
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x1ab8dcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1abbc0;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 4ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[4], (cpu->regs[3] + 88)); PB_LDRW(cpu->regs[5], (cpu->regs[3] + 88) + 4);
    PB_LDRW(cpu->regs[6], (cpu->regs[3] + 96)); PB_LDRW(cpu->regs[7], (cpu->regs[3] + 96) + 4);
    cpu->regs[30] = PB_BASE + 0x1ab900ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x128ea0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abbb0;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ab918;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1abba4;
L_1ab918:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 64ULL));
    PB_STRB((cpu->regs[2] + 80), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x1ab934ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1283a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abac8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967231ULL));
    PB_STRB((cpu->regs[1] + 80), cpu->regs[0]);
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 16));
    if ((cpu->regs[22])==0) goto L_1ab968;
    cpu->regs[27] = 0ULL;
    cpu->regs[1] = 0ULL;
L_1ab95c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_1aba00;
L_1ab968:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_GT) goto L_1aba28;
    if ((cpu->regs[23])!=0) goto L_1abab8;
L_1ab97c:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ab988ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1283a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abac8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 72));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & ~(0x1ULL << 2)) | ((cpu->regs[26] & 0x1ULL) << 2))));
    PB_STRB((cpu->regs[2] + 72), cpu->regs[1]);
    FLAG_CMP((cpu->regs[1]) & (8ULL), 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[25], 12ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[21] = (FLAG_NE) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0x1ab9b4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abb7c;
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1abbe0;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1ab9cc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1ab9dc:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8ULL)));
    if (FLAG_LS) goto L_1aba20;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_1abaec;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(11ULL)));
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = 4ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[2];
    goto L_1ab8c0;
L_1aba00:
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[27])) << 3);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[27] = ((uint32_t)(cpu->regs[27] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1aba14ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abac8;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[27]));
    goto L_1ab95c;
L_1aba20:
    cpu->regs[0] = 4ULL;
    goto L_1ab8c0;
L_1aba28:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[22], (cpu->regs[21] + (cpu->regs[1] << 3)));
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 64ULL));
    PB_STRB((cpu->regs[2] + 80), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x1aba4cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abb0c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + 80));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 84));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] & 4294967231ULL));
    PB_STRB((cpu->regs[1] + 80), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[1] + 84), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[30] = PB_BASE + 0x1aba78ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1abb0c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[28] = 0ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[22] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 84));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[1] + 84), cpu->regs[0]);
L_1aba94:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[28]));
    if ((cpu->regs[27])==0) goto L_1abb18;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
L_1abaa0:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_1abaf4;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 24));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1abb64;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_1ab968;
L_1abab8:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1abac4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ab97c;
L_1abac8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
L_1abacc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1ab9cc;
L_1abaec:
    cpu->regs[0] = 3ULL;
    goto L_1ab8c0;
L_1abaf4:
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    cpu->regs[28] = ((uint32_t)(cpu->regs[28] + 1ULL));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[27] + (cpu->regs[1] << 3)));
    cpu->regs[30] = PB_BASE + 0x1abb08ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aba94;
L_1abb0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1abacc;
L_1abb18:
    cpu->regs[1] = 0ULL;
    goto L_1abaa0;
L_1abb20:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1032ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1abb38ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 32)); PB_LDRW(cpu->regs[2], (cpu->regs[20] + 32) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 40) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[20] = 0ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1abb54ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x8502cULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[0]);
    goto L_1ab9cc;
L_1abb64:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 8ULL));
    PB_STRB((cpu->regs[1] + 72), cpu->regs[0]);
    goto L_1ab968;
L_1abb7c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1ab9cc;
L_1abb94:
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 8ULL));
    PB_STRB((cpu->regs[1] + 72), cpu->regs[0]);
    goto L_1ab8cc;
L_1abba4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1abbacULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ab918;
L_1abbb0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1abbc0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1abc04;
L_1abbc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1abbccULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1ab9cc;
L_1abbe0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 8ULL));
    PB_STRB((cpu->regs[1] + 72), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1ab9cc;
L_1abc04:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1abc0cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1abbc0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1abc34ULL; PB_CALL(19, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1abc9c;
    cpu->regs[20] = cpu->regs[0] + 3896ULL; FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_EQ) goto L_1abcb4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 3896));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1160ULL;
    cpu->regs[30] = PB_BASE + 0x1abc5cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1a3300ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1abcb4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1168ULL;
    cpu->regs[30] = PB_BASE + 0x1abc74ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1a3300ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1abcb4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1184ULL;
    cpu->regs[30] = PB_BASE + 0x1abc8cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1a3300ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_1abc90:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1abc9c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1abcb4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1abcb4:
    cpu->regs[0] = 4294967295ULL;
    goto L_1abc90;
    /* nop */
}
