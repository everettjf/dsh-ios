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

void ft_PySet_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_12a000:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3672));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xe7640ULL); return; };
L_12a010:
    SP = SP - 272ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 32), cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[1]);
    PB_STR((SP + 72), cpu->regs[2]); PB_STR((SP + 72) + 8, cpu->regs[5]);
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 240), cpu->regs[25]); PB_STR((SP + 240) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    PB_STR((SP + 168), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 112), 0ULL);
    cpu->regs[30] = PB_BASE + 0x12a058ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x12a000ULL);
    PB_STR((SP + 40), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12b3f8;
    cpu->regs[30] = PB_BASE + 0x12a064ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12b3f8;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a074ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x12a000ULL);
    PB_STR((SP + 64), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12b138;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a084ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x12a000ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12b1c8;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a094ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x12a000ULL);
    PB_STR((SP + 56), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12b1bc;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a0a4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a1a4;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_12a838;
L_12a0b8:
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    PB_STR((SP + 256), cpu->regs[27]); PB_STR((SP + 256) + 8, cpu->regs[28]);
L_12a0c0:
    cpu->regs[24] = SP + 120ULL;
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[23] = SP + 128ULL;
    cpu->regs[28] = SP + 112ULL;
    if ((cpu->regs[0])!=0) goto L_12af78;
    cpu->regs[0] = SP + 160ULL;
    cpu->regs[25] = 134ULL;
    PB_STR((SP + 24), cpu->regs[0]);
L_12a0e0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a0f8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12a298;
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[30] = PB_BASE + 0x12a108ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 160));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12a9cc;
    PB_LDR(cpu->regs[19], (SP + 128));
    cpu->regs[0] = cpu->regs[0] & 8ULL;
    if (((cpu->regs[27] >> 0) & 1)) goto L_12a9f0;
L_12a120:
    if ((cpu->regs[0])!=0) goto L_12a93c;
    FLAG_CMP((cpu->regs[27]) & (cpu->regs[25]), 0);
    if (FLAG_EQ) goto L_12a210;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x12a134ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12a14cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ada4;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12ae30;
L_12a160:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a16cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12a17cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x12b580ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[1] = cpu->regs[19];
    if (((cpu->regs[27] >> 10) & 1)) goto L_12a9b8;
L_12a18c:
    cpu->regs[30] = PB_BASE + 0x12a190ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x12b580ULL);
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12a0e0;
L_12a19c:
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
L_12a1a4:
    cpu->regs[19] = 0ULL;
L_12a1a8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12a1b0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x12a1b8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x12a1c0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x12a1c8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x12a1d0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x12a1d8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_12af10;
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    PB_LDR(cpu->regs[25], (SP + 240)); PB_LDR(cpu->regs[26], (SP + 240) + 8);
    SP = SP + 272ULL;
    return;
L_12a210:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12a22c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a220ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12a970;
L_12a22c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12a238ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12a24c;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 68));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12a92c;
L_12a24c:
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x12a254ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12a26cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b428;
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a0e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a0e0;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12a294ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a0e0;
L_12a298:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_12a898;
    cpu->regs[30] = PB_BASE + 0x12a2a8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x129660ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12a2d0;
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x12a2b8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x12bb0cULL);
    if ((cpu->regs[0])==0) goto L_12a19c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a2d0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12b420;
L_12a2d0:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12a2fc;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x12a2e4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x12bb0cULL);
    if ((cpu->regs[0])==0) goto L_12a19c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a2fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12b418;
L_12a2fc:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12a308ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x12bb0cULL);
    if ((cpu->regs[0])==0) goto L_12a19c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a320;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12b410;
L_12a320:
    cpu->regs[23] = 0ULL;
L_12a324:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[23], cpu->regs[19]);
    if (FLAG_LT) goto L_12a66c;
L_12a334:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    if (!((cpu->regs[19] >> 63) & 1)) goto L_12a640;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    cpu->regs[30] = PB_BASE + 0x12a344ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x129660ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12a400;
    cpu->regs[0] = 5ULL;
    PB_STR((SP + 160), 0ULL);
    cpu->regs[30] = PB_BASE + 0x12a358ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[28] = SP + 160ULL;
    cpu->regs[25] = SP + 152ULL;
    cpu->regs[24] = SP + 144ULL;
L_12a36c:
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a384ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12a3f4;
    PB_LDR(cpu->regs[0], (SP + 152));
    cpu->regs[30] = PB_BASE + 0x12a390ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x129680ULL);
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_12a36c;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[19], (SP + 144));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a3a8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a3f0;
    if (FLAG_NE) goto L_12a3cc;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x12a3c0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a3f0;
    if (FLAG_EQ) goto L_12a36c;
L_12a3cc:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12a3dcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a3f0;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a3ecULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x12b580ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12a36c;
L_12a3f0:
    cpu->regs[22] = 0ULL;
L_12a3f4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12af5c;
L_12a3fc:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_12a19c;
L_12a400:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_12a8d0;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 24));
L_12a410:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[21] + 80),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    PB_STRW((SP + 80), cpu->regs[0]);
L_12a41c:
    cpu->regs[0] = SP + 136ULL;
    PB_STR((SP + 16), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    cpu->regs[25] = SP + 152ULL;
    cpu->regs[24] = SP + 144ULL;
    cpu->regs[23] = SP + 160ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 32), cpu->regs[0]);
    PB_STR((SP + 136), 0ULL);
    PB_STR((SP + 144), 0ULL); PB_STR((SP + 144) + 8, 0ULL);
L_12a450:
    cpu->regs[3] = cpu->regs[24];
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12a468ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xecfd0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12a598;
    PB_LDR(cpu->regs[0], (SP + 144));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12a47cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 160));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12ad1c;
    PB_LDR(cpu->regs[27], (SP + 136));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12a498ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x12ba40ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
L_12a49c:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12b350;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_12b360;
L_12a4ac:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[1], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_12a79c;
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12a79c;
L_12a4c8:
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12a4d8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 160));
L_12a4dc:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12a4e4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 160));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12ad00;
L_12a4f0:
    cpu->regs[21] = cpu->regs[21] | (cpu->regs[28] << 12);
    cpu->regs[0] = cpu->regs[21] + 5ULL;
    FLAG_CMP(cpu->regs[0], 261ULL);
    if (FLAG_HI) goto L_12a570;
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] + 5ULL));
    PB_LDR(cpu->regs[1], (SP + 32));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[28] = cpu->regs[0] + cpu->regs[1];
L_12a514:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_12b378;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_12a7b8;
L_12a52c:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12a53c;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
L_12a53c:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12a54cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xddf8cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b38c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a450;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a450;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x12a56cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a450;
L_12a570:
    cpu->regs[0] = 1073741823ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[1] = 2147483646ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HI) goto L_12a7d4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12a58cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe3e84ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_12a514;
    goto L_12a19c;
L_12a598:
    cpu->regs[0] = 16384ULL;
    cpu->regs[30] = PB_BASE + 0x12a5a0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x12a5b0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12abb8;
L_12a5b8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12a5c0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe8060ULL);
    PB_STR((SP + 136), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_12ac44;
    cpu->regs[30] = PB_BASE + 0x12a5d0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_12af34;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a5f0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a5f0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12a5f0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12a5f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a60c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a60c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a60cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12a60c:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (SP + 72));
    cpu->regs[30] = PB_BASE + 0x12a618ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x12bb0cULL);
    if ((cpu->regs[0])==0) goto L_12a19c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a630;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12b3f0;
L_12a630:
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    cpu->regs[19] = 1ULL;
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12a640:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[19] << 3)));
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 80));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_12a334;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 48));
    cpu->regs[2] = cpu->regs[19] + 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a664ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1ac20cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12a334;
    goto L_12a19c;
L_12a66c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_STR((SP + 16), 0ULL);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + (cpu->regs[23] << 3)));
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[22] + 80),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ae48;
L_12a680:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 76));
    cpu->regs[27] = 0ULL;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12aa48;
L_12a68c:
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x12a694ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12b3b4;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x12a6a4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12b3b4;
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x12a6b4ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12b430;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x12a6c4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12b3c0;
    PB_LDR(cpu->regs[5], (SP + 16));
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12a6e8ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x12a010ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12b3c0;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a708;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a708;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x12a708ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12a708:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a724;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a724;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x12a724ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12a724:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a740;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a740;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x12a740ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12a740:
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_12aa58;
L_12a744:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a750ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x12bb0cULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a770;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a770;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a770ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12a770:
    if ((cpu->regs[24])==0) goto L_12a19c;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a788;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12b344;
L_12a788:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 72));
    FLAG_CMP((cpu->regs[0]) & (3ULL), 0);
    if (FLAG_NE) goto L_12a7c0;
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_12a324;
L_12a79c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12a7a4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12a4c8;
    cpu->regs[0] = 0ULL;
    goto L_12a4dc;
L_12a7b8:
    PB_STRW((cpu->regs[27] + 0), cpu->regs[0]);
    goto L_12a52c;
L_12a7c0:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 72));
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 2ULL));
    PB_STRB((cpu->regs[21] + 72), cpu->regs[0]);
    goto L_12a324;
L_12a7d4:
    FLAG_CMP(cpu->regs[21], 0ULL);
    cpu->regs[1] = (FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[21])) : cpu->regs[21];
    FLAG_CMP(0ULL, cpu->regs[1]);
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 2ULL));
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    PB_STR((SP + 88), cpu->regs[3]); PB_STR((SP + 88) + 8, cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x12a7f8ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    PB_LDR(cpu->regs[3], (SP + 88)); PB_LDR(cpu->regs[1], (SP + 88) + 8);
    FLAG_CMP(cpu->regs[21], 0ULL);
    cpu->regs[19] = ((uint32_t)((FLAG_GE) ? cpu->regs[19] : (~0ULL)));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[28] + 24ULL;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[3] = cpu->regs[0] | (cpu->regs[3] << 3);
    PB_STR((cpu->regs[28] + 16), cpu->regs[3]);
L_12a824:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 4;
    cpu->regs[1] = cpu->regs[1] >> 30;
    if ((cpu->regs[1])!=0) goto L_12a824;
    goto L_12a514;
L_12a838:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12a844ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x12bb0cULL);
    if ((cpu->regs[0])==0) goto L_12a1a4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a85c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12aebc;
L_12a85c:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12a0b8;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x12a870ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x12bb0cULL);
    if ((cpu->regs[0])==0) goto L_12a1a4;
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    PB_STR((SP + 256), cpu->regs[27]); PB_STR((SP + 256) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a0c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a0c0;
    cpu->regs[30] = PB_BASE + 0x12a894ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a0c0;
L_12a898:
    PB_LDR(cpu->regs[22], (SP + 56));
    cpu->regs[3] = 26712ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x12a8b4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    cpu->regs[2] = 26888ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12a8c8ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12a320;
    goto L_12a19c;
L_12a8d0:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = 26712ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[1] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x12a8e8ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x12b580ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12ac34;
L_12a8f4:
    cpu->regs[0] = 26888ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x12a904ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x12b580ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12ae94;
L_12a910:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    cpu->regs[1] = 1ULL;
    PB_STRW((SP + 80), cpu->regs[1]);
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_12a41c;
    goto L_12a410;
L_12a92c:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 1ULL));
    PB_STRB((cpu->regs[21] + 72), cpu->regs[0]);
    goto L_12a24c;
L_12a93c:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12aef4;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a94cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_EQ) goto L_12ae04;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12a964ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12aedc;
L_12a970:
    cpu->regs[0] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x12a978ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12a990ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b428;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12adcc;
L_12a9a4:
    PB_LDR(cpu->regs[0], (SP + 72));
    cpu->regs[1] = cpu->regs[19];
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | 1ULL));
    PB_STRB((cpu->regs[21] + 72), cpu->regs[2]);
L_12a9b8:
    cpu->regs[30] = PB_BASE + 0x12a9bcULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x12b468ULL);
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12a0e0;
    goto L_12a19c;
L_12a9cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12a9e4ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[19], (SP + 128));
    cpu->regs[0] = cpu->regs[27] & 8ULL;
    if (!((cpu->regs[27] >> 0) & 1)) goto L_12a120;
L_12a9f0:
    if ((cpu->regs[0])!=0) goto L_12ae7c;
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x12a9fcULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12aa14ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b428;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12ae60;
L_12aa28:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12aa34ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12a0e0;
    cpu->regs[1] = cpu->regs[19];
    goto L_12a18c;
L_12aa48:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 72));
    cpu->regs[0] = ((cpu->regs[0] >> 2) & 0x1ULL);
    cpu->regs[27] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    goto L_12a68c;
L_12aa58:
    cpu->regs[28] = SP + 160ULL;
    cpu->regs[25] = SP + 152ULL;
    cpu->regs[24] = SP + 144ULL;
    PB_STRW((SP + 88), 0ULL);
    PB_STR((SP + 160), 0ULL);
L_12aa6c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x12aa80ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12abe4;
    PB_LDR(cpu->regs[0], (SP + 152));
    cpu->regs[30] = PB_BASE + 0x12aa8cULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] & 4ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    if (((cpu->regs[27] >> 2) & 1)) goto L_12aa6c;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[27] >> 12) & 0xfULL)));
    PB_STRW((SP + 16), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_12b168;
    if (((cpu->regs[27] >> 11) & 1)) goto L_12b168;
L_12aab0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[1], (SP + 144));
    cpu->regs[30] = PB_BASE + 0x12aabcULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_12ab64;
    cpu->regs[30] = PB_BASE + 0x12aac8ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_12abb8;
    PB_LDRW(cpu->regs[0], (SP + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_12ac18;
L_12aad8:
    cpu->regs[0] = cpu->regs[27] & 4095ULL;
    cpu->regs[30] = PB_BASE + 0x12aae0ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12abb8;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_STR((SP + 24), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (SP + 144));
    cpu->regs[30] = PB_BASE + 0x12aaf8ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12ab14;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12b1b0;
L_12ab14:
    if (((cpu->regs[27] >> 31) & 1)) goto L_12abb8;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[0] = cpu->regs[0] & 15ULL;
    cpu->regs[30] = PB_BASE + 0x12ab24ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12abb8;
    PB_LDR(cpu->regs[1], (SP + 144));
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12ab3cULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b14c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_12aa6c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12aa6c;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12ab60ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12aa6c;
L_12ab64:
    PB_LDRW(cpu->regs[0], (SP + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_12ac18;
L_12ab70:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x12ab78ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[1] = 134ULL;
    FLAG_CMP((cpu->regs[0]) & (cpu->regs[1]), 0);
    if (FLAG_EQ) goto L_12aa6c;
    PB_LDR(cpu->regs[27], (SP + 144));
L_12ab88:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 48));
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LT) goto L_12b17c;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_12aa6c;
    PB_LDR(cpu->regs[1], (SP + 144));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12abb4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x12b580ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12aa6c;
L_12abb8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a19c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12abd8ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12abe4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12abecULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x1b6b10ULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[22] + 72));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_GT) ? 1 : 0;
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & ~0x1ULL) | ((cpu->regs[0] >> 0) & 0x1ULL))));
    PB_LDRW(cpu->regs[0], (SP + 88));
    PB_STRB((cpu->regs[22] + 72), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12aea4;
L_12ac08:
    PB_LDRB(cpu->regs[0], (cpu->regs[22] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 32ULL));
    PB_STRB((cpu->regs[22] + 80), cpu->regs[0]);
    goto L_12a744;
L_12ac18:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    cpu->regs[1] = 4ULL;
    PB_STRW((SP + 16), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_12ad4c;
L_12ac2c:
    if ((cpu->regs[3])==0) goto L_12aad8;
    goto L_12ab70;
L_12ac34:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 8ULL));
    PB_STRB((cpu->regs[21] + 80), cpu->regs[0]);
    goto L_12a8f4;
L_12ac44:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12ac50ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe27c8ULL);
    PB_STR((SP + 144), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12acb0;
    cpu->regs[30] = PB_BASE + 0x12ac5cULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_12af34;
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12ac7c;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12ac70ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12af34;
    if (FLAG_EQ) goto L_12ac90;
L_12ac7c:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12ac8cULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12af34;
L_12ac90:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a5b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a5b8;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12acacULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a5b8;
L_12acb0:
    PB_LDRW(cpu->regs[1], (SP + 80));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_12ac90;
    cpu->regs[30] = PB_BASE + 0x12acbcULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[0] = cpu->regs[0] | 64ULL;
    cpu->regs[30] = PB_BASE + 0x12acc4ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12af34;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12acdcULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12af1c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_12ac90;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12ac90;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x12acfcULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12ac90;
L_12ad00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12ad18ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_12a4f0;
L_12ad1c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12ad34ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[27], (SP + 136));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12ad44ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x12ba40ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12a49c;
    goto L_12a19c;
L_12ad4c:
    PB_LDR(cpu->regs[5], (SP + 144));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 264ULL;
    PB_STR((SP + 96), cpu->regs[5]); PB_STR((SP + 96) + 8, cpu->regs[3]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x12ad64ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x11d180ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (SP + 96)); PB_LDR(cpu->regs[3], (SP + 96) + 8);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12ac2c;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((SP + 16), cpu->regs[4]);
    PB_STR((SP + 96), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x12ad84ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x12b580ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12abb8;
    PB_LDR(cpu->regs[3], (SP + 96));
    cpu->regs[0] = 3ULL;
    PB_LDRW(cpu->regs[4], (SP + 16));
    PB_STRW((SP + 16), cpu->regs[0]);
    PB_STRW((SP + 88), cpu->regs[4]);
    if ((cpu->regs[3])==0) goto L_12aad8;
    goto L_12ab70;
L_12ada4:
    if (((cpu->regs[4] >> 31) & 1)) goto L_12a19c;
L_12ada8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a19c;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12adc0ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12adcc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a9a4;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12ade0ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a9a4;
L_12ade4:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12aef4;
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12adf8ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12aec4;
L_12ae04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1360ULL;
L_12ae18:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12ae20ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x11f220ULL);
L_12ae20:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12ae2cULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xcf350ULL);
    goto L_12a19c;
L_12ae30:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a160;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12ae44ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a160;
L_12ae48:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[21];
    PB_STR((SP + 16), cpu->regs[0]);
    goto L_12a680;
L_12ae60:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12aa28;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12ae74ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12aa28;
L_12ae78:
    if ((cpu->regs[0])==0) goto L_12b218;
L_12ae7c:
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = cpu->regs[1] + 1264ULL;
    goto L_12ae18;
L_12ae94:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 16ULL));
    PB_STRB((cpu->regs[21] + 80), cpu->regs[0]);
    goto L_12a910;
L_12aea4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 264ULL;
    cpu->regs[30] = PB_BASE + 0x12aeb4ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x1e9304ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12ac08;
    goto L_12abb8;
L_12aebc:
    cpu->regs[30] = PB_BASE + 0x12aec0ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a85c;
L_12aec4:
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12aed0ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_EQ) goto L_12b080;
L_12aedc:
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    goto L_12ae18;
L_12aef4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1304ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12af0cULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_12ae20;
L_12af10:
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    PB_STR((SP + 256), cpu->regs[27]); PB_STR((SP + 256) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x12af1cULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x7c170ULL);
L_12af1c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_12af34;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12af34;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x12af34ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12af34:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12af3cULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12af44ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12af50ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12af5c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12a3fc;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x12af70ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_12a400;
    goto L_12a19c;
L_12af78:
    cpu->regs[0] = SP + 160ULL;
    cpu->regs[27] = cpu->regs[0];
L_12af80:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12af98ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12a298;
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12afa8ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 160));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12b2ac;
L_12afb4:
    PB_LDR(cpu->regs[19], (SP + 128));
    cpu->regs[0] = cpu->regs[25] & 8ULL;
    if (((cpu->regs[25] >> 0) & 1)) goto L_12ae78;
    if ((cpu->regs[0])!=0) goto L_12ade4;
    cpu->regs[0] = 134ULL;
    FLAG_CMP((cpu->regs[25]) & (cpu->regs[0]), 0);
    if (FLAG_EQ) goto L_12b044;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x12afd8ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12aff0ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ada4;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12b0dc;
L_12b004:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12b010ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12b020ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x12b580ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[1] = cpu->regs[19];
    if (((cpu->regs[25] >> 10) & 1)) goto L_12b0c8;
    cpu->regs[30] = PB_BASE + 0x12b034ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x12b580ULL);
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12af80;
    goto L_12a19c;
L_12b044:
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x12b054ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x1b14c0ULL);
    if (((cpu->regs[0] >> 0) & 1)) goto L_12b0f4;
    cpu->regs[1] = 134ULL;
    FLAG_CMP((cpu->regs[0]) & (cpu->regs[1]), 0);
    if (FLAG_NE) goto L_12b200;
L_12b064:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12b2c8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12b074ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_EQ) goto L_12b2c8;
L_12b080:
    cpu->regs[0] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x12b088ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12b0a0ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b428;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12b27c;
L_12b0b4:
    PB_LDR(cpu->regs[0], (SP + 72));
    cpu->regs[1] = cpu->regs[19];
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + 72));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | 1ULL));
    PB_STRB((cpu->regs[21] + 72), cpu->regs[2]);
L_12b0c8:
    cpu->regs[30] = PB_BASE + 0x12b0ccULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x12b468ULL);
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12af80;
    goto L_12a19c;
L_12b0dc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12b004;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b0f0ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12b004;
L_12b0f4:
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x12b0fcULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
L_12b104:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12b114ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b1d8;
    if (((cpu->regs[1] >> 31) & 1)) goto L_12af80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12af80;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x12b134ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12af80;
L_12b138:
    cpu->regs[26] = 0ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 8), 0ULL);
    PB_STR((SP + 56), 0ULL);
    goto L_12a1a8;
L_12b14c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_12abb8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12abb8;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b164ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12abb8;
L_12b168:
    PB_LDR(cpu->regs[1], (SP + 144));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x12b174ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12aab0;
    goto L_12abb8;
L_12b17c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[27];
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[2] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x12b194ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x1b14c0ULL);
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] >> 12) & 0xfULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_12aa6c;
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[0] = cpu->regs[2] + 1ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    goto L_12ab88;
L_12b1b0:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b1b8ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12ab14;
L_12b1bc:
    cpu->regs[26] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_12a1a8;
L_12b1c8:
    cpu->regs[26] = 0ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 56), 0ULL);
    goto L_12a1a8;
L_12b1d8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a19c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a19c;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12b1f4ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12b200:
    if (((cpu->regs[0] >> 3) & 1)) goto L_12b064;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x12b20cULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_12b104;
    goto L_12a19c;
L_12b218:
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x12b220ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12b238ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b428;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12b294;
L_12b24c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12b258ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12a19c;
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_12af80;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12b26cULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x12b580ULL);
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12af80;
    goto L_12a19c;
L_12b27c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12b0b4;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b290ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12b0b4;
L_12b294:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12b24c;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b2a8ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12b24c;
L_12b2ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12b2c4ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_12afb4;
L_12b2c8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12b2d4ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x12ba40ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_12a19c;
    if (FLAG_NE) goto L_12b2e8;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 68));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12b334;
L_12b2e8:
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x12b2f0ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12a19c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12b308ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if (((cpu->regs[0] >> 31) & 1)) goto L_12b428;
    if (((cpu->regs[1] >> 31) & 1)) goto L_12af80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12af80;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12b330ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12af80;
L_12b334:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 1ULL));
    PB_STRB((cpu->regs[21] + 72), cpu->regs[0]);
    goto L_12b2e8;
L_12b344:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x12b34cULL; PB_CALL(159, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a788;
L_12b350:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[21] = cpu->regs[21] | 2048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_12a4ac;
L_12b360:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x12b370ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_12a4dc;
L_12b378:
    cpu->regs[1] = 1882ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x12b388ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x9bb50ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
L_12b38c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_12a19c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12a19c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12b3a8ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12b3b4:
    cpu->regs[28] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = 0ULL;
L_12b3c0:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x12b3c8ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12b3d0ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x12b3d8ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12b3e4ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_12a1a8;
L_12b3f0:
    cpu->regs[30] = PB_BASE + 0x12b3f4ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a630;
L_12b3f8:
    cpu->regs[19] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 8), 0ULL);
    PB_STR((SP + 56), 0ULL); PB_STR((SP + 56) + 8, 0ULL);
    goto L_12a1a8;
L_12b410:
    cpu->regs[30] = PB_BASE + 0x12b414ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a320;
L_12b418:
    cpu->regs[30] = PB_BASE + 0x12b41cULL; PB_CALL(169, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a2fc;
L_12b420:
    cpu->regs[30] = PB_BASE + 0x12b424ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12a2d0;
L_12b428:
    if (!((cpu->regs[3] >> 31) & 1)) goto L_12ada8;
    goto L_12a19c;
L_12b430:
    cpu->regs[28] = 0ULL;
    goto L_12b3c0;
    /* nop */
    /* nop */
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_12b450;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + cpu->regs[2]));
    return;
L_12b450:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_12b460;
    PB_LDRH(cpu->regs[0], (cpu->regs[1] + (cpu->regs[2] << 1)));
    return;
L_12b460:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + (cpu->regs[2] << 2)));
    return;
}
