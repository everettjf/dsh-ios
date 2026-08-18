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

void ft__PyLong_GCD(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 160ULL;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    FLAG_CMP(cpu->regs[1], 23ULL);
    if (FLAG_HI) goto L_177258;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[0], 23ULL);
    if (FLAG_HI) goto L_177258;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_177184;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_177184:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1774a4;
L_177190:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x177198ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1771a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[22], 0ULL);
    cpu->regs[22] = (FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[22])) : cpu->regs[22];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_177240;
L_1771b8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_17748c;
L_1771c0:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if ((cpu->regs[19])==0) goto L_17720c;
    cpu->regs[1] = (FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[19])) : cpu->regs[19];
    cpu->regs[2] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[22] / (int64_t)cpu->regs[1]) : 0);
    cpu->regs[2] = cpu->regs[22] - cpu->regs[2] * cpu->regs[1];
    if ((cpu->regs[2])==0) goto L_177208;
    cpu->regs[0] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0);
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0] * cpu->regs[2];
    if ((cpu->regs[1])==0) goto L_1774cc;
    cpu->regs[0] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[1]) : 0);
    cpu->regs[0] = cpu->regs[2] - cpu->regs[0] * cpu->regs[1];
    if ((cpu->regs[0])==0) goto L_177208;
    cpu->regs[2] = cpu->regs[1];
L_1771f4:
    cpu->regs[3] = (cpu->regs[0] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[0]) : 0);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2] - cpu->regs[3] * cpu->regs[0];
    cpu->regs[2] = cpu->regs[1];
    if ((cpu->regs[0])!=0) goto L_1771f4;
L_177208:
    cpu->regs[22] = cpu->regs[1];
L_17720c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_177734;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 160ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_177240:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1771b8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x177254ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1771b8;
L_177258:
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x177264ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1709ecULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1777c0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x177274ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1709ecULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1777e0;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x177290ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x129848ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_177410;
L_177294:
    PB_LDR(cpu->regs[28], (cpu->regs[20] + 16));
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 16));
    cpu->regs[19] = 0ULL;
    cpu->regs[28] = cpu->regs[28] >> 3;
    cpu->regs[27] = 64ULL;
    cpu->regs[23] = 60ULL;
    cpu->regs[25] = cpu->regs[25] >> 3;
L_1772b4:
    PB_LDR(cpu->regs[26], (cpu->regs[20] + 16));
    cpu->regs[24] = cpu->regs[26] >> 3;
    FLAG_CMP(cpu->regs[26], 23ULL);
    if (FLAG_LS) goto L_1774ac;
    cpu->regs[5] = cpu->regs[20] + (cpu->regs[24] << 2);
    cpu->regs[3] = cpu->regs[24] << 2;
    PB_LDR(cpu->regs[4], (cpu->regs[21] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[5] + 20));
    cpu->regs[0] = (((uint64_t)(cpu->regs[1])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[1])));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[27] - cpu->regs[0]));
    cpu->regs[4] = cpu->regs[4] >> 3;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : 0ULL;
    if ((cpu->regs[4])==0) goto L_177424;
    PB_LDRW(cpu->regs[7], (cpu->regs[5] + 12)); PB_LDRW(cpu->regs[2], (cpu->regs[5] + 12) + 4);
    cpu->regs[6] = 30ULL;
    cpu->regs[8] = ((uint32_t)(cpu->regs[23] - cpu->regs[0]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[6] - cpu->regs[0]));
    cpu->regs[6] = cpu->regs[24] - 2ULL;
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[8] & 63);
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[5] & 63);
    cpu->regs[2] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] >> (cpu->regs[0] & 63)));
    cpu->regs[2] = cpu->regs[2] | cpu->regs[1];
    FLAG_CMP(cpu->regs[6], cpu->regs[4]);
    if (FLAG_GT) goto L_1774dc;
    cpu->regs[1] = cpu->regs[21] + (cpu->regs[24] << 2);
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 12));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] >> (cpu->regs[0] & 63)));
L_177328:
    cpu->regs[1] = cpu->regs[24] - 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_GT) goto L_1774d4;
    cpu->regs[6] = cpu->regs[21] + (cpu->regs[6] << 2);
    PB_LDRW(cpu->regs[6], (cpu->regs[6] + 24));
    cpu->regs[5] = cpu->regs[6] << (cpu->regs[5] & 63);
L_177340:
    cpu->regs[0] = cpu->regs[0] | cpu->regs[5];
    FLAG_CMP(cpu->regs[4], cpu->regs[24]);
    if (FLAG_LT) goto L_177408;
    cpu->regs[1] = cpu->regs[21] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[8] & 63);
L_177358:
    cpu->regs[7] = 1ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    cpu->regs[8] = cpu->regs[7];
    cpu->regs[10] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[9] = 0ULL;
L_177370:
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_EQ) goto L_177398;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[8];
    cpu->regs[6] = cpu->regs[0] - cpu->regs[5];
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[1] = (cpu->regs[6] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[6]) : 0);
    cpu->regs[6] = cpu->regs[2] - cpu->regs[0] * cpu->regs[1];
    cpu->regs[11] = cpu->regs[7] * cpu->regs[1] + cpu->regs[9];
    FLAG_CMP(cpu->regs[11], cpu->regs[6]);
    if (FLAG_LE) goto L_1773e4;
L_177398:
    if ((((uint32_t)(cpu->regs[10])))!=0) goto L_1774e4;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1773acULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1736a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_177784;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1773c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1776e0;
L_1773c8:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[28] = cpu->regs[25];
    cpu->regs[20] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 16));
    cpu->regs[25] = cpu->regs[25] >> 3;
    goto L_1772b4;
L_1773e4:
    cpu->regs[1] = cpu->regs[5] * cpu->regs[1] + cpu->regs[8];
    cpu->regs[9] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[7];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[7] = cpu->regs[1];
    cpu->regs[10] = ((uint32_t)(cpu->regs[10] + 1ULL));
    cpu->regs[5] = cpu->regs[11];
    cpu->regs[0] = cpu->regs[6];
    goto L_177370;
L_177408:
    cpu->regs[1] = 0ULL;
    goto L_177358;
L_177410:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[20];
    PB_STR((SP + 48), cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    goto L_177294;
L_177424:
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    if (FLAG_GT) goto L_177704;
    cpu->regs[23] = cpu->regs[20];
    PB_STR((SP + 48), cpu->regs[20]);
L_177434:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_17775c;
L_17743c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x177444ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x17744cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
L_177454:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_177744;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 160ULL;
    return;
L_17748c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1771c0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1774a0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1771c0;
L_1774a4:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_177190;
L_1774ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1774b4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1774bcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_177190;
L_1774cc:
    cpu->regs[1] = cpu->regs[2];
    goto L_177208;
L_1774d4:
    cpu->regs[5] = 0ULL;
    goto L_177340;
L_1774dc:
    cpu->regs[0] = 0ULL;
    goto L_177328;
L_1774e4:
    if (!((cpu->regs[10] >> 0) & 1)) goto L_177500;
    cpu->regs[1] = (uint64_t)(-(int64_t)cpu->regs[8]);
    cpu->regs[0] = (uint64_t)(-(int64_t)cpu->regs[5]);
    cpu->regs[8] = (uint64_t)(-(int64_t)cpu->regs[9]);
    cpu->regs[5] = (uint64_t)(-(int64_t)cpu->regs[7]);
    cpu->regs[9] = cpu->regs[1];
    cpu->regs[7] = cpu->regs[0];
L_177500:
    if ((cpu->regs[19])!=0) goto L_17767c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_1776ec;
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 0), cpu->regs[8]); PB_STR((SP + 0) + 8, cpu->regs[9]);
    PB_STR((SP + 16), cpu->regs[5]); PB_STR((SP + 16) + 8, cpu->regs[7]);
    PB_STR((SP + 32), cpu->regs[4]); PB_STR((SP + 32) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x177524ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[8], (SP + 0)); PB_LDR(cpu->regs[9], (SP + 0) + 8);
    PB_LDR(cpu->regs[5], (SP + 16)); PB_LDR(cpu->regs[7], (SP + 16) + 8);
    PB_LDR(cpu->regs[4], (SP + 32)); PB_LDR(cpu->regs[3], (SP + 32) + 8);
    if ((cpu->regs[0])==0) goto L_177780;
    cpu->regs[28] = cpu->regs[24];
L_17753c:
    if ((cpu->regs[22])!=0) goto L_17766c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[25], cpu->regs[24]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_1776bc;
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 0), cpu->regs[8]); PB_STR((SP + 0) + 8, cpu->regs[9]);
    PB_STR((SP + 16), cpu->regs[5]); PB_STR((SP + 16) + 8, cpu->regs[7]);
    PB_STR((SP + 32), cpu->regs[4]); PB_STR((SP + 32) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x177564ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[8], (SP + 0)); PB_LDR(cpu->regs[9], (SP + 0) + 8);
    PB_LDR(cpu->regs[5], (SP + 16)); PB_LDR(cpu->regs[7], (SP + 16) + 8);
    PB_LDR(cpu->regs[4], (SP + 32)); PB_LDR(cpu->regs[3], (SP + 32) + 8);
    if ((cpu->regs[0])==0) goto L_177780;
L_177578:
    cpu->regs[10] = cpu->regs[20] + 24ULL;
    cpu->regs[14] = cpu->regs[21] + 24ULL;
    cpu->regs[3] = cpu->regs[10] + cpu->regs[3];
    cpu->regs[11] = cpu->regs[19] + 24ULL;
    cpu->regs[12] = cpu->regs[22] + 24ULL;
    cpu->regs[14] = cpu->regs[14] + (cpu->regs[4] << 2);
    cpu->regs[0] = 24ULL;
    cpu->regs[13] = 0ULL;
    cpu->regs[4] = 0ULL;
L_17759c:
    cpu->regs[1] = cpu->regs[0] + cpu->regs[21];
    FLAG_CMP(cpu->regs[14], cpu->regs[1]);
    if (FLAG_LS) goto L_1775e0;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + cpu->regs[0]));
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + cpu->regs[0]));
    cpu->regs[4] = cpu->regs[1] * cpu->regs[8] + cpu->regs[4];
    cpu->regs[13] = cpu->regs[2] * cpu->regs[7] + cpu->regs[13];
    cpu->regs[1] = cpu->regs[13] - cpu->regs[1] * cpu->regs[5];
    cpu->regs[2] = cpu->regs[4] - cpu->regs[2] * cpu->regs[9];
    cpu->regs[6] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[19] + cpu->regs[0]), cpu->regs[4]);
    cpu->regs[13] = (uint64_t)((int64_t)cpu->regs[1] >> 30);
    cpu->regs[4] = (uint64_t)((int64_t)cpu->regs[2] >> 30);
    PB_STRW((cpu->regs[22] + cpu->regs[0]), cpu->regs[6]);
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    goto L_17759c;
L_1775e0:
    cpu->regs[0] = cpu->regs[14] - cpu->regs[21];
    cpu->regs[1] = cpu->regs[21] + 21ULL;
    cpu->regs[0] = cpu->regs[0] - 21ULL;
    FLAG_CMP(cpu->regs[14], cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] & 18446744073709551612ULL;
    cpu->regs[0] = (FLAG_HS) ? cpu->regs[0] : 0ULL;
    cpu->regs[0] = cpu->regs[10] + cpu->regs[0];
L_1775fc:
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LO) goto L_177688;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_177614;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_177614:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_177624;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_177624:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_177638;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_177774;
L_177638:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_17764c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_177750;
L_17764c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x177654ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x145d20ULL);
    cpu->regs[25] = cpu->regs[24];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x177664ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x145d20ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_1772b4;
L_17766c:
    cpu->regs[26] = cpu->regs[26] & 18446744073709551608ULL;
    cpu->regs[24] = cpu->regs[25];
    PB_STR((cpu->regs[22] + 16), cpu->regs[26]);
    goto L_177578;
L_17767c:
    cpu->regs[0] = cpu->regs[26] & 18446744073709551608ULL;
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    goto L_17753c;
L_177688:
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], cpu->regs[0]); cpu->regs[0] += 4;
    cpu->regs[7] = cpu->regs[11] - cpu->regs[10];
    cpu->regs[6] = cpu->regs[12] - cpu->regs[10];
    cpu->regs[4] = cpu->regs[1] * cpu->regs[8] + cpu->regs[4];
    cpu->regs[1] = cpu->regs[13] - cpu->regs[1] * cpu->regs[5];
    cpu->regs[9] = ((uint32_t)(cpu->regs[4] & 1073741823ULL));
    PB_STRW((cpu->regs[7] + cpu->regs[2]), cpu->regs[9]);
    cpu->regs[4] = (uint64_t)((int64_t)cpu->regs[4] >> 30);
    cpu->regs[7] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[13] = (uint64_t)((int64_t)cpu->regs[1] >> 30);
    PB_STRW((cpu->regs[6] + cpu->regs[2]), cpu->regs[7]);
    goto L_1775fc;
L_1776bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1776cc;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_1776cc:
    cpu->regs[26] = cpu->regs[26] & 18446744073709551608ULL;
    cpu->regs[24] = cpu->regs[25];
    cpu->regs[22] = cpu->regs[21];
    PB_STR((cpu->regs[21] + 16), cpu->regs[26]);
    goto L_177578;
L_1776e0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1776e8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1773c8;
L_1776ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1776fc;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1776fc:
    cpu->regs[19] = cpu->regs[20];
    goto L_17753c;
L_177704:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x17770cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x170a04ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_177434;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_177434;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x177730ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_177434;
L_177734:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x177744ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_177744:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x177750ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_177750:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x177758ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_17764c;
L_17775c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_17743c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x177770ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_17743c;
L_177774:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x17777cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_177638;
L_177780:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
L_177784:
    if (((cpu->regs[1] >> 31) & 1)) goto L_177794;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1777c8;
L_177794:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1777a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1777d4;
L_1777a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1777b0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1777b8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
L_1777c0:
    cpu->regs[23] = 0ULL;
    goto L_177454;
L_1777c8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1777d0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_177794;
L_1777d4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1777dcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1777a8;
L_1777e0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1777c0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1777c0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x177800ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_177454;
}
