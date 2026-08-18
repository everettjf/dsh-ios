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

void ft__PyCompile_OptimizeCfg(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc5488ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c5638;
    cpu->regs[22] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc54a0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xa9aa0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c54b0;
L_c54a8:
    cpu->regs[20] = 0ULL;
    goto L_c5610;
L_c54b0:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc54ccULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x138290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c54a8;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc54dcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c54a8;
    PB_LDR(cpu->regs[26], (SP + 8));
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[26];
L_c54f0:
    if ((cpu->regs[0])==0) goto L_c5508;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 40));
    PB_STRW((cpu->regs[0] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    goto L_c54f0;
L_c5508:
    cpu->regs[22] = PB_BASE + 0x2b8000ULL;
    cpu->regs[22] = cpu->regs[22] + 2096ULL;
    cpu->regs[22] = cpu->regs[22] - 144ULL;
    cpu->regs[24] = PB_BASE + 0x2a6000ULL;
L_c5518:
    if ((cpu->regs[26])==0) goto L_c5610;
    cpu->regs[25] = cpu->regs[24] + 3016ULL;
    cpu->regs[23] = 0ULL;
L_c5524:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 40));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_GE) goto L_c5608;
    cpu->regs[1] = 40ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 24));
    cpu->regs[1] = (uint64_t)((int64_t)(int32_t)cpu->regs[23] * (int64_t)(int32_t)cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2] + cpu->regs[1];
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + cpu->regs[1]));
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 8)); PB_LDRW(cpu->regs[4], (cpu->regs[0] + 8) + 4);
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(511ULL)));
    if (FLAG_HI) goto L_c5584;
    cpu->regs[2] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[1] >> 5)));
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + (cpu->regs[2] << 2)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> (cpu->regs[1] & 63)));
    if (((cpu->regs[2] >> 0) & 1)) goto L_c5578;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 4294967293ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(256ULL)));
    if (FLAG_EQ) goto L_c5578;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(257ULL)));
    if (FLAG_NE) goto L_c5584;
L_c5578:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 8));
    goto L_c5588;
L_c5584:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 4));
L_c5588:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc5590ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c55e8;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc55a4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c55c8;
    if (((cpu->regs[3] >> 31) & 1)) goto L_c55e8;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_c55e8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc55c4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c55e8;
L_c55c8:
    if (((cpu->regs[3] >> 31) & 1)) goto L_c55e0;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_c55e0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc55e0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c55e0:
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    goto L_c5524;
L_c55e8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c54a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c54a8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5604ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c54a8;
L_c5608:
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 32));
    goto L_c5518;
L_c5610:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c562c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c562c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc562cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c562c:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5638ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x13f968ULL);
L_c5638:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c5658;
    cpu->regs[30] = PB_BASE + 0xc5658ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c5658:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xc568cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xc4fd8ULL);
    if ((cpu->regs[0])==0) goto L_c56c0;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc569cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1ffce0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c56c4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c56c0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c56c0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc56c0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c56c0:
    cpu->regs[19] = 0ULL;
L_c56c4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_c56d4:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc56f0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x12a000ULL);
    if ((cpu->regs[0])==0) goto L_c576c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[21] = 1ULL;
L_c56fc:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc5708ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b4a0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_c578c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc5718ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[20])==0) goto L_c5750;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc572cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x12b468ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c5774;
    if (((cpu->regs[1] >> 31) & 1)) goto L_c5750;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c5750;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5750ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5750:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c576c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c576c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc576cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c576c:
    cpu->regs[19] = 0ULL;
    goto L_c5798;
L_c5774:
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_c578c;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c578c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc578cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c578c:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[21], 65ULL);
    if (FLAG_NE) goto L_c56fc;
L_c5798:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 304ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 272), cpu->regs[29]); PB_STR((SP + 272) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 272ULL;
    PB_STR((SP + 288), cpu->regs[19]);
    cpu->regs[19] = SP + 136ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 264), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc57dcULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7b100ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c57f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc57f0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_c580c;
L_c57f8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 128ULL;
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0xc5808ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[30] = PB_BASE + 0xc580cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xc56d4ULL);
L_c580c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 264));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c582c;
    cpu->regs[30] = PB_BASE + 0xc582cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c582c:
    PB_LDR(cpu->regs[19], (SP + 288));
    PB_LDR(cpu->regs[29], (SP + 272)); PB_LDR(cpu->regs[30], (SP + 272) + 8);
    SP = SP + 304ULL;
    return;
    SP = SP - 304ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 272), cpu->regs[29]); PB_STR((SP + 272) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 272ULL;
    PB_STR((SP + 288), cpu->regs[19]);
    cpu->regs[19] = SP + 136ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 264), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc586cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7b610ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c5888;
L_c5870:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc5880ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_c58a8;
L_c5888:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5890ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c0a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c5870;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 128ULL;
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0xc58a4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[30] = PB_BASE + 0xc58a8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xc56d4ULL);
L_c58a8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 264));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c58c8;
    cpu->regs[30] = PB_BASE + 0xc58c8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c58c8:
    PB_LDR(cpu->regs[19], (SP + 288));
    PB_LDR(cpu->regs[29], (SP + 272)); PB_LDR(cpu->regs[30], (SP + 272) + 8);
    SP = SP + 304ULL;
    return;
}
