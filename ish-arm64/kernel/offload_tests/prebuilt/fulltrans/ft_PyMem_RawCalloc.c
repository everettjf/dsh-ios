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

void ft_PyMem_RawCalloc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[1])==0) goto L_d8400;
    cpu->regs[2] = 3689348814741910323ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x333ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[1], 40ULL);
    if (FLAG_EQ) goto L_d83bc;
    cpu->regs[2] = 9223372036854775807ULL;
    cpu->regs[2] = (cpu->regs[1] ? cpu->regs[2] / cpu->regs[1] : 0);
L_d83bc:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_HI) goto L_d8428;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    cpu->regs[2] = PB_BASE + 0xd8000ULL;
    cpu->regs[2] = cpu->regs[2] + 1072ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 112));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_d83e8;
    if ((cpu->regs[0])==0) goto L_d841c;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x7b8e0ULL); return; };
L_d83e8:
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 96));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[16] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[4];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_d8400:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    cpu->regs[2] = PB_BASE + 0xd8000ULL;
    cpu->regs[2] = cpu->regs[2] + 1072ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 112));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_d83e8;
L_d841c:
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x7b8e0ULL); return; };
L_d8428:
    cpu->regs[0] = 0ULL;
    return;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = cpu->regs[1];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[2] : (0ULL + 1);
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x7b8e0ULL); return; };
    SP = SP - 160ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[30] = PB_BASE + 0xd848cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[27], (cpu->regs[0] + 0));
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19] + (18ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1920ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_d877c;
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[20] + 104ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[20] + (93ULL << 12);
    cpu->regs[1] = cpu->regs[1] + 2328ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_d881c;
L_d84d0:
    PB_LDR(cpu->regs[28], (cpu->regs[20] + 384));
    cpu->regs[24] = cpu->regs[20] + 368ULL;
    cpu->regs[25] = cpu->regs[28] + 80ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xd84e4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7bc40ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d887c;
    cpu->regs[26] = cpu->regs[28] + 16ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d869c;
L_d84f8:
    cpu->regs[21] = cpu->regs[28] + 168ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd8504ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7bc40ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d8864;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[28] + 8ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_NE) goto L_d8668;
    cpu->regs[0] = cpu->regs[28] + 120ULL;
    cpu->regs[30] = PB_BASE + 0xd8528ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7bc10ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d8684;
L_d852c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd8534ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7bb30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d87f0;
    cpu->regs[0] = cpu->regs[19] + (18ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1920ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_d878c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[0] + 104ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 2328ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_d8794;
L_d8574:
    cpu->regs[0] = cpu->regs[20] + 372ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_d876c;
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[19] + 1948ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d87c4;
    cpu->regs[0] = cpu->regs[20] + 416ULL;
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 440));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d87e8;
L_d85a0:
    cpu->regs[30] = PB_BASE + 0xd85a4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7ac90ULL);
    PB_STR((SP + 40), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    PB_LDR(cpu->regs[1], (SP + 40));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_d8648;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_d8648;
    cpu->regs[19] = cpu->regs[19] + 1968ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 52));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[20] = cpu->regs[20] + 396ULL;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[0]));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[0]));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[26]));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[0]));
    PB_STRW((cpu->regs[24] + 0), cpu->regs[21]);
L_d85f4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 128));
    if ((cpu->regs[0])!=0) goto L_d884c;
L_d85fc:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xd8604ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7bb30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d87ac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[27]);
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_d8778;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
L_d8648:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 52));
    cpu->regs[20] = cpu->regs[20] + 396ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] | cpu->regs[0]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | cpu->regs[26]));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | cpu->regs[1]));
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
    goto L_d85f4;
L_d8668:
    PB_STR((cpu->regs[0] + 0), cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 24));
    cpu->regs[0] = cpu->regs[28] + 120ULL;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[28] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xd8680ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7bc10ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d852c;
L_d8684:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xd869cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x91ebcULL);
L_d869c:
    cpu->regs[0] = cpu->regs[28] + 32ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[0]);
L_d86ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d84f8;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 24));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : (0ULL + 1);
    PB_STR((SP + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xd86ccULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1bde28ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 448));
    if ((cpu->regs[2])==0) goto L_d883c;
    cpu->regs[30] = PB_BASE + 0xd86dcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x227088ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 8));
L_d86e4:
    PB_STR((SP + 40), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0xd86f0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x21c6ecULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0xd86fcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x227200ULL);
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[1] = cpu->regs[25];
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0xd870cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b9b0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(110ULL)));
    if (FLAG_EQ) goto L_d8730;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d86ac;
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 2048ULL;
    cpu->regs[30] = PB_BASE + 0xd8730ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x91ebcULL);
L_d8730:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d86ac;
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_d86ac;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xd8750ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x182e40ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d8808;
    cpu->regs[0] = cpu->regs[20] + 372ULL;
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STRW((cpu->regs[24] + 0), cpu->regs[1]);
    cpu->regs[21] = cpu->regs[1];
    goto L_d86ac;
L_d876c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd8774ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x26bea0ULL);
    goto L_d85f4;
L_d8778:
    cpu->regs[30] = PB_BASE + 0xd877cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_d877c:
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_d881c;
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 16));
    goto L_d84d0;
L_d878c:
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_d8574;
L_d8794:
    cpu->regs[30] = PB_BASE + 0xd8798ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd7750ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_d8574;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xd87a8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7bb30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d8894;
L_d87ac:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0xd87c4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x91ebcULL);
L_d87c4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd87ccULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1b03a0ULL);
    cpu->regs[1] = cpu->regs[20] + 416ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 440));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[26] = (FLAG_NE) ? 1 : 0;
    cpu->regs[26] = ((uint32_t)(cpu->regs[26] | cpu->regs[2]));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_d85a0;
L_d87e8:
    cpu->regs[30] = PB_BASE + 0xd87ecULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x17ac10ULL);
    goto L_d85a0;
L_d87f0:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 2200ULL;
    cpu->regs[30] = PB_BASE + 0xd8808ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x91ebcULL);
L_d8808:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xd8810ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7bb30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d87ac;
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_d8830;
L_d8818:
    cpu->regs[30] = PB_BASE + 0xd881cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x90830ULL);
L_d881c:
    cpu->regs[30] = PB_BASE + 0xd8820ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xd7750ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_d8818;
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 16));
    goto L_d84d0;
L_d8830:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd8838ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x26bea0ULL);
    cpu->regs[30] = PB_BASE + 0xd883cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x90830ULL);
L_d883c:
    cpu->regs[30] = PB_BASE + 0xd8840ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x227108ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 8));
    goto L_d86e4;
L_d884c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 368ULL;
    PB_STRW((cpu->regs[0] + 52), cpu->regs[1]);
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_d85fc;
L_d8864:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 2120ULL;
    cpu->regs[30] = PB_BASE + 0xd887cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x91ebcULL);
L_d887c:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[1] = cpu->regs[1] + 2016ULL;
    cpu->regs[30] = PB_BASE + 0xd8894ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x91ebcULL);
L_d8894:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xd88a0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x14770cULL);
    cpu->regs[30] = PB_BASE + 0xd88a4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x90830ULL);
}
