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

void ft_PyIndex_Check(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])==0) goto L_147704;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    return;
L_147704:
    cpu->regs[0] = 0ULL;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    cpu->regs[21] = cpu->regs[23] + 16ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_147878;
    cpu->regs[22] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_147794;
    cpu->regs[0] = cpu->regs[23] + 8ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[23] + 80ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x147750ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7bc40ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1477a4;
L_147754:
    PB_STRW((cpu->regs[21] + 0), 0ULL);
    cpu->regs[0] = cpu->regs[23] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x147760ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7bc10ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_147860;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14776cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7bb30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_147848;
    if ((cpu->regs[22])==0) goto L_147780;
    cpu->regs[19] = cpu->regs[19] + 4ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1477bc;
L_147780:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_147794:
    cpu->regs[20] = cpu->regs[23] + 80ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1477a0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7bc40ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_147754;
L_1477a4:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 2016ULL;
    cpu->regs[30] = PB_BASE + 0x1477bcULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x91ebcULL);
L_1477bc:
    cpu->regs[19] = cpu->regs[23] + 168ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1477c8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7bc40ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_147818;
    cpu->regs[0] = cpu->regs[23] + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_1477f4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[30] = PB_BASE + 0x1477e4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x26bea0ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23] + 120ULL;
    cpu->regs[30] = PB_BASE + 0x1477f0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7b330ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_147830;
L_1477f4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1477fcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7bb30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_147780;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 2200ULL;
    cpu->regs[30] = PB_BASE + 0x147818ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x91ebcULL);
L_147818:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 2120ULL;
    cpu->regs[30] = PB_BASE + 0x147830ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x91ebcULL);
L_147830:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 1064ULL;
    cpu->regs[30] = PB_BASE + 0x147848ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x91ebcULL);
L_147848:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x147860ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x91ebcULL);
L_147860:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 1032ULL;
    cpu->regs[30] = PB_BASE + 0x147878ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x91ebcULL);
L_147878:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 792ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    cpu->regs[30] = PB_BASE + 0x147890ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x91ebcULL);
    cpu->regs[10] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1478a4;
    return;
L_1478a4:
    PB_LDR(cpu->regs[0], (cpu->regs[10] + 32)); PB_LDR(cpu->regs[9], (cpu->regs[10] + 32) + 8);
    cpu->regs[1] = cpu->regs[9] + (cpu->regs[0] << 4);
    FLAG_CMP(cpu->regs[9], cpu->regs[1]);
    if (FLAG_HI) goto L_147af8;
    cpu->regs[11] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[9];
    cpu->regs[7] = 19891ULL;
    cpu->regs[6] = 13527ULL;
    cpu->regs[1] = cpu->regs[1] >> 4;
    cpu->regs[11] = cpu->regs[11] + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] & 7ULL; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[7] = (cpu->regs[7] & ~(0xffffULL << 16)) | ((0x55bULL & 0xffff) << 16);
    cpu->regs[6] = (cpu->regs[6] & ~(0xffffULL << 16)) | ((0xd93fULL & 0xffff) << 16);
    if (FLAG_EQ) goto L_1479c0;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_1479a0;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_147988;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_147970;
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_EQ) goto L_147958;
    FLAG_CMP(cpu->regs[1], 5ULL);
    if (FLAG_EQ) goto L_147940;
    FLAG_CMP(cpu->regs[1], 6ULL);
    if (FLAG_EQ) goto L_147928;
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[3] * cpu->regs[6];
L_147928:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
L_147940:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
L_147958:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
L_147970:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
L_147988:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
L_1479a0:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[9] = cpu->regs[9] + 16ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    FLAG_CMP(cpu->regs[9], cpu->regs[11]);
    if (FLAG_EQ) goto L_147a70;
L_1479c0:
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 8));
    cpu->regs[8] = cpu->regs[9];
    cpu->regs[9] = cpu->regs[9] + 128ULL;
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 24));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 40));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 56));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 72));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 88));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 104));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 120));
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[4] = cpu->regs[1] ^ (cpu->regs[1] << 16);
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[3] = cpu->regs[4] ^ cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    cpu->regs[5] = cpu->regs[3] * cpu->regs[6];
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[5];
    FLAG_CMP(cpu->regs[9], cpu->regs[11]);
    if (FLAG_NE) goto L_1479c0;
L_147a70:
    PB_LDR(cpu->regs[1], (cpu->regs[10] + 16)); PB_LDR(cpu->regs[4], (cpu->regs[10] + 16) + 8);
    cpu->regs[3] = 61261ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x72e8ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[5] = 40277ULL;
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 16)) | ((0xe583ULL & 0xffff) << 16);
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 32)) | ((0xb76fULL & 0xffff) << 32);
    cpu->regs[3] = cpu->regs[4] * cpu->regs[3] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[4];
    cpu->regs[4] = 11732ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0x6ceeULL & 0xffff) << 16);
    cpu->regs[0] = ((uint64_t)(((int64_t)(cpu->regs[0] << (63-0)) ) >> 63));
    cpu->regs[1] = ((uint64_t)(((int64_t)(cpu->regs[1] << (63-0)) ) >> 63));
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 32)) | ((0xcceULL & 0xffff) << 32);
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 48)) | ((0x48bULL & 0xffff) << 48);
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 48)) | ((0x48cULL & 0xffff) << 48);
    cpu->regs[0] = cpu->regs[0] & cpu->regs[5];
    cpu->regs[1] = cpu->regs[1] & cpu->regs[4];
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[0];
    cpu->regs[3] = 3533ULL;
    cpu->regs[2] = 50147ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x1ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[1] >> 25;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x3611ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] ^ (cpu->regs[1] >> 11);
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] * cpu->regs[3] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_147b00;
    PB_STR((cpu->regs[10] + 48), cpu->regs[0]);
    return;
L_147af8:
    cpu->regs[2] = 0ULL;
    goto L_147a70;
L_147b00:
    cpu->regs[1] = 51137ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x2338ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[1];
    PB_STR((cpu->regs[10] + 48), cpu->regs[1]);
    return;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = 4ULL;
    goto L_147b30;
L_147b30:
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_147e1c;
    cpu->regs[24] = PB_BASE + 0x28e000ULL;
    cpu->regs[24] = cpu->regs[24] + 1112ULL;
    if (!((cpu->regs[0] >> 26) & 1)) goto L_147e28;
L_147b88:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_LE) goto L_147e3c;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[20] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_147e70;
L_147bb0:
    cpu->regs[3] = PB_BASE + 0x51e000ULL;
    cpu->regs[3] = cpu->regs[3] + 3856ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[3] + 3520ULL;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_147e7c;
    cpu->regs[2] = PB_BASE + 0x28e000ULL;
    cpu->regs[5] = SP;
    cpu->regs[2] = cpu->regs[2] + 1160ULL;
L_147bd0:
    cpu->regs[0] = cpu->regs[20] + (18ULL << 12);
    cpu->regs[4] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[0] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x147be0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x13eb20ULL);
    cpu->regs[1] = cpu->regs[20] + (16ULL << 12);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 10000));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_147fc4;
L_147bf0:
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_147eb8;
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_LE) goto L_147c04;
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])!=0) goto L_147fa0;
L_147c04:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x147c0cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_147eb8;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_147ef8;
L_147c28:
    cpu->regs[21] = 0ULL;
    cpu->regs[23] = 0ULL;
L_147c30:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x147c40ULL; PB_CALL(18, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_147d80;
L_147c48:
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_147ec0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_147c60;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_147c60:
    cpu->regs[26] = cpu->regs[19];
L_147c64:
    if ((cpu->regs[21])==0) goto L_147d60;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x147c78ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_147fe4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2296));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_147ce0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_148004;
L_147c9c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_EQ) goto L_147d20;
L_147cac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147cc0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_147f48;
L_147cc0:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147c30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147c30;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x147cdcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147c30;
L_147ce0:
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x147ce8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    cpu->regs[27] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_147d10;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_147d10;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
L_147d04:
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x147d10ULL; PB_CALL(22, cpu, tlb, cpu->regs[1]);
L_147d10:
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[27], (SP + 112));
    if (FLAG_LT) goto L_147fe4;
    if (FLAG_EQ) goto L_147cac;
L_147d20:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147d3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147d3c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x147d3cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_147d3c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147d60;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147d60;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x147d58ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    /* nop */
    /* nop */
L_147d60:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[23] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = cpu->regs[26];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x147d78ULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_147c48;
L_147d80:
    cpu->regs[30] = PB_BASE + 0x147d84ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe8090ULL);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x147d98ULL; PB_CALL(27, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_147e8c;
L_147da4:
    if ((cpu->regs[21])==0) goto L_147f54;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147dbc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_147f74;
L_147dbc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147de0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147de0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x147de0ULL; PB_CALL(28, cpu, tlb, cpu->regs[1]);
L_147de0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147ef0;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_147e1c:
    cpu->regs[24] = PB_BASE + 0x28e000ULL;
    cpu->regs[24] = cpu->regs[24] + 1104ULL;
    if (((cpu->regs[0] >> 26) & 1)) goto L_147b88;
L_147e28:
    cpu->regs[23] = 18446744073709551615ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 89ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0x147e3cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_147e3c:
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = SP + 16ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x147e54ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_147f00;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[0] = cpu->regs[20] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_147bb0;
L_147e70:
    cpu->regs[1] = cpu->regs[20] + (16ULL << 12);
    PB_STRW((cpu->regs[1] + 10000), cpu->regs[0]);
    goto L_147bb0;
L_147e7c:
    cpu->regs[2] = PB_BASE + 0x28e000ULL;
    cpu->regs[5] = SP;
    cpu->regs[2] = cpu->regs[2] + 1176ULL;
    goto L_147bd0;
L_147e8c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_147da4;
L_147e94:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x147e9cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x147ea4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147eb8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_147f38;
L_147eb8:
    cpu->regs[23] = 0ULL;
    goto L_147de0;
L_147ec0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x147ec8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_147c64;
L_147ed0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147e94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147e94;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x147eecULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147e94;
L_147ef0:
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x147ef8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7c170ULL);
L_147ef8:
    PB_STR((SP + 8), 0ULL);
    goto L_147c28;
L_147f00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_147eb8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 30) & 1)) goto L_147eb8;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1120ULL;
    cpu->regs[30] = PB_BASE + 0x147f34ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_147de0;
L_147f38:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x147f44ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147de0;
L_147f48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x147f50ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147cc0;
L_147f54:
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_147f80;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_147f6c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_147f6c:
    cpu->regs[23] = cpu->regs[0];
    goto L_147dbc;
L_147f74:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x147f7cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147dbc;
L_147f80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 1264ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x147f9cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_147dbc;
L_147fa0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1192ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x147fc0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_147de0;
L_147fc4:
    cpu->regs[1] = cpu->regs[20] + (16ULL << 12);
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 10000), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147bf0;
    cpu->regs[0] = cpu->regs[20] + (18ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x147fe0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147bf0;
L_147fe4:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147ed0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147ed0;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x148000ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_147ed0;
L_148004:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147c9c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_STR((SP + 112), cpu->regs[27]);
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    cpu->regs[27] = (FLAG_EQ) ? 1 : 0;
    goto L_147d04;
    SP = SP - 176ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = SP + 48ULL;
    PB_STR((SP + 160), cpu->regs[23]); PB_STR((SP + 160) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[4];
    cpu->regs[4] = 31823ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0x4f4fULL & 0xffff) << 16);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 32)) | ((0x3aULL & 0xffff) << 32);
    cpu->regs[5] = 0ULL;
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    cpu->regs[2] = 44ULL;
    cpu->regs[0] = SP + 53ULL;
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, cpu->regs[3]);
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[19]);
    PB_STR((SP + 48), cpu->regs[4]); PB_STR((SP + 48) + 8, cpu->regs[5]);
    PB_STR((SP + 64), 0ULL); PB_STR((SP + 64) + 8, 0ULL);
    PB_STR((SP + 80), 0ULL); PB_STR((SP + 80) + 8, 0ULL);
    PB_STRH((SP + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1480acULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = SP + 40ULL;
    cpu->regs[3] = SP + 32ULL;
    cpu->regs[2] = SP + 8ULL;
    PB_STRB((SP + 97), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1480c8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_148190;
    PB_LDR(cpu->regs[0], (SP + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_1480e4;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1480e0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x146a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_148190;
L_1480e4:
    PB_LDR(cpu->regs[0], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_148148;
    PB_LDR(cpu->regs[0], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    PB_STR((cpu->regs[24] + 0), cpu->regs[2]);
    cpu->regs[1] = 9223372036854775807ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_148174;
L_148110:
    cpu->regs[0] = 1ULL;
L_148114:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_148198;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    PB_LDR(cpu->regs[23], (SP + 160)); PB_LDR(cpu->regs[24], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
L_148148:
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x148150ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x146a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_148190;
    PB_LDR(cpu->regs[0], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_148110;
L_148174:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x148190ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x11f220ULL);
L_148190:
    cpu->regs[0] = 0ULL;
    goto L_148114;
L_148198:
    cpu->regs[30] = PB_BASE + 0x14819cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[23] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    cpu->regs[25] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_LT) goto L_1482d4;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[20] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 16));
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_LE) goto L_148338;
    if (((cpu->regs[2] >> 63) & 1)) goto L_14835c;
L_1481f4:
    cpu->regs[28] = cpu->regs[19] - cpu->regs[20];
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    if (FLAG_LT) goto L_1482d0;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_14848c;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_148370;
    cpu->regs[26] = cpu->regs[22] + 40ULL;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_148378;
L_148210:
    if (!((cpu->regs[1] >> 6) & 1)) goto L_14829c;
    cpu->regs[27] = cpu->regs[21] + 40ULL;
    FLAG_CMP(cpu->regs[24], 1ULL);
    if (FLAG_EQ) goto L_1482a8;
L_148220:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_NE) goto L_1483b8;
L_148228:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1482f4;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_148438;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 32));
    cpu->regs[0] = cpu->regs[26] + cpu->regs[20];
    if (!((cpu->regs[1] >> 6) & 1)) goto L_148498;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    if (!((cpu->regs[1] >> 6) & 1)) goto L_148498;
    if ((cpu->regs[24])==0) goto L_148354;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x148268ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[20] = cpu->regs[0] + cpu->regs[20];
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = (FLAG_GE) ? cpu->regs[20] : cpu->regs[0];
L_148274:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_NE) goto L_148420;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_148280:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_14829c:
    cpu->regs[27] = cpu->regs[21] + 56ULL;
L_1482a0:
    FLAG_CMP(cpu->regs[24], 1ULL);
    if (FLAG_NE) goto L_148220;
L_1482a8:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_148410;
    PB_LDRB(cpu->regs[3], (cpu->regs[27] + 0));
L_1482b4:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[20] + cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1482c8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x12fd40ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_14832c;
L_1482d0:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1482d4:
    cpu->regs[19] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_1482f4:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_148380;
    cpu->regs[0] = cpu->regs[26] + cpu->regs[20];
    if ((cpu->regs[24])==0) goto L_148274;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x14831cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_148274;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[20];
    goto L_148274;
L_14832c:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[19] = cpu->regs[20] + cpu->regs[0];
    goto L_148280;
L_148338:
    if (((cpu->regs[3] >> 63) & 1)) goto L_148348;
L_14833c:
    if (((cpu->regs[20] >> 63) & 1)) goto L_148360;
    cpu->regs[19] = cpu->regs[3];
    goto L_1481f4;
L_148348:
    cpu->regs[3] = cpu->regs[3] + cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] & ~(((uint64_t)((int64_t)cpu->regs[3] >> 63)));
    goto L_14833c;
L_148354:
    cpu->regs[19] = cpu->regs[20];
    goto L_148274;
L_14835c:
    cpu->regs[3] = cpu->regs[19];
L_148360:
    cpu->regs[20] = cpu->regs[20] + cpu->regs[19];
    cpu->regs[19] = cpu->regs[3];
    cpu->regs[20] = cpu->regs[20] & ~(((uint64_t)((int64_t)cpu->regs[20] >> 63)));
    goto L_1481f4;
L_148370:
    cpu->regs[26] = cpu->regs[22] + 56ULL;
    if (((cpu->regs[1] >> 5) & 1)) goto L_148210;
L_148378:
    PB_LDR(cpu->regs[27], (cpu->regs[21] + 56));
    goto L_1482a0;
L_148380:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1483e0;
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[20] << 1);
    if ((cpu->regs[24])==0) goto L_148274;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1483a8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x22e280ULL);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_148274;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[20];
    goto L_148274;
L_1483b8:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[25];
    PB_STRW((SP + 108), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1483d0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x22e06cULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_148480;
    PB_LDRW(cpu->regs[4], (SP + 108));
    goto L_148228;
L_1483e0:
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[20] << 2);
    if ((cpu->regs[24])==0) goto L_148274;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x148400ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x27b888ULL);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_148274;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[20];
    goto L_148274;
L_148410:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_148430;
    PB_LDRH(cpu->regs[3], (cpu->regs[27] + 0));
    goto L_1482b4;
L_148420:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x148428ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_148280;
L_148430:
    PB_LDRW(cpu->regs[3], (cpu->regs[27] + 0));
    goto L_1482b4;
L_148438:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_148460;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[20] << 1);
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x148458ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x25c6a0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_148274;
L_148460:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[20] << 2);
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x148478ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x27be00ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_148274;
L_148480:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[19] = 18446744073709551614ULL;
    goto L_148280;
L_14848c:
    PB_LDR(cpu->regs[26], (cpu->regs[22] + 56));
    if (((cpu->regs[1] >> 5) & 1)) goto L_148210;
    goto L_148378;
L_148498:
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1484acULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1de660ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_148274;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 24) & 1)) goto L_1484dc;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_1484dc;
    goto L_1484e8;
L_1484dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    return;
L_1484e8:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[4] & 3ULL;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] | cpu->regs[3];
    cpu->regs[3] = cpu->regs[3] & 3ULL;
    FLAG_CMP(cpu->regs[4], 15ULL);
    if (FLAG_HI) goto L_148568;
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 24));
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[2] = cpu->regs[0] - cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[4];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_148550;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    return;
L_148550:
    cpu->regs[1] = 1073741823ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_1485d0;
    { PB_CALL(60, cpu, tlb, PB_BASE + 0xe3e84ULL); return; };
L_148568:
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_14857c;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_1485a0;
    { PB_CALL(61, cpu, tlb, PB_BASE + 0x149310ULL); return; };
L_14857c:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[3], 2ULL);
    cpu->regs[29] = SP;
    PB_STR((SP + 24), cpu->regs[3]);
    if (FLAG_EQ) goto L_1485a4;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[5];
    { PB_CALL(62, cpu, tlb, PB_BASE + 0x150300ULL); return; };
L_1485a0:
    { PB_CALL(63, cpu, tlb, PB_BASE + 0x150300ULL); return; };
L_1485a4:
    cpu->regs[30] = PB_BASE + 0x1485a8ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x149310ULL);
    if ((cpu->regs[0])==0) goto L_1485c8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (SP + 24));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 3ULL));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551608ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - cpu->regs[2]));
    cpu->regs[1] = cpu->regs[3] | cpu->regs[1];
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
L_1485c8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1485d0:
    { PB_CALL(65, cpu, tlb, PB_BASE + 0x169eacULL); return; };
    /* nop */
    /* nop */
    /* nop */
}
