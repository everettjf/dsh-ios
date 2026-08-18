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

void ft__PyObject_GetState(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = 0ULL;
    goto L_23a1c8;
L_23a1c8:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 28616ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x23a1f4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23a26c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2864));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_23a280;
L_23a210:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    if (((cpu->regs[1] >> 5) & 1)) goto L_23a298;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
L_23a220:
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_23a288;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x23f000ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_23a288;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23a248ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x23a2a0ULL);
    cpu->regs[20] = cpu->regs[0];
L_23a24c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23a268;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_23a268;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a268ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23a268:
    cpu->regs[19] = cpu->regs[20];
L_23a26c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_23a280:
    cpu->regs[30] = PB_BASE + 0x23a284ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23a210;
L_23a288:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a290ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x22c880ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_23a24c;
L_23a298:
    cpu->regs[1] = 0ULL;
    goto L_23a220;
L_23a2a0:
    SP = SP - 144ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_23a3f0;
L_23a2d8:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 288));
    if ((cpu->regs[0])==0) goto L_23a3cc;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 4) & 1)) goto L_23a670;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + -24));
    if (((cpu->regs[3] >> 0) & 1)) goto L_23a538;
L_23a2f0:
    if ((cpu->regs[3])==0) goto L_23a3cc;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 16));
    if ((cpu->regs[0])==0) goto L_23a3cc;
L_23a2fc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23a308ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x19d3e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23a414;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
L_23a314:
    PB_LDR(cpu->regs[24], (cpu->regs[23] + 8));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x23a328ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[1] = 33224ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x23a334ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23a41c;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_23a358;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 25) & 1)) goto L_23a8cc;
L_23a358:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_23a368;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
L_23a368:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_23a494;
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_EQ) goto L_23a380;
L_23a374:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_23a570;
L_23a380:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23a394;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23a560;
L_23a394:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_23a398:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_23a6bc;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 144ULL;
    return;
L_23a3cc:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_23a8c4;
L_23a3e4:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_23a314;
L_23a3f0:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 40));
    if ((cpu->regs[0])==0) goto L_23a2d8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23a414ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
L_23a414:
    cpu->regs[21] = 0ULL;
    goto L_23a398;
L_23a41c:
    cpu->regs[30] = PB_BASE + 0x23a420ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_23a6e8;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x23a42cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x23a904ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23a7e4;
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = 36160ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 16), cpu->regs[25]); PB_STR((SP + 16) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x23a454ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23a46c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23a7ac;
L_23a46c:
    if ((cpu->regs[19])==0) goto L_23a7e4;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_EQ) goto L_23a7a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_23a7b8;
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_23a374;
L_23a494:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3488));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 288));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    if ((cpu->regs[2])==0) goto L_23a4b4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    if (!((cpu->regs[2] >> 4) & 1)) goto L_23a6a0;
L_23a4b4:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 208));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_GT) goto L_23a8f0;
L_23a4c0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_EQ) goto L_23a8f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 3);
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_23a374;
L_23a4dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a4f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23a4f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a4f8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23a4f8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a50c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a8b8;
L_23a50c:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 1736ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23a530ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_23a398;
L_23a538:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 880));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
L_23a544:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_23a3cc;
    cpu->regs[2] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[0] << 3)));
    if ((cpu->regs[2])!=0) goto L_23a2fc;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_23a544;
L_23a560:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a568ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_23a398;
L_23a570:
    cpu->regs[30] = PB_BASE + 0x23a574ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23a6cc;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = SP + 8ULL;
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[27], (cpu->regs[19] + 16));
L_23a590:
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_GE) goto L_23a614;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + (cpu->regs[20] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_23a888;
L_23a5ac:
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x23a5bcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23a7f8;
    PB_LDR(cpu->regs[25], (SP + 8));
    if ((cpu->regs[25])==0) goto L_23a680;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x23a5dcULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[28] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_23a708;
L_23a5e8:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23a5fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23a7ec;
L_23a5fc:
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_23a830;
L_23a600:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_NE) goto L_23a818;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_23a590;
L_23a614:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_23a650;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x23a630ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1204ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_23a648;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23a720;
L_23a648:
    cpu->regs[21] = cpu->regs[20];
    if ((cpu->regs[20])==0) goto L_23a72c;
L_23a650:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a664;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a6a8;
L_23a664:
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_23a380;
L_23a670:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x23a678ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18fb28ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    goto L_23a2f0;
L_23a680:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a600;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23a600;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x23a69cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a600;
L_23a6a0:
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    goto L_23a4b4;
L_23a6a8:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x23a6b0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_23a380;
L_23a6bc:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x23a6ccULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23a6cc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a6e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23a6e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a6e8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23a6e8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a6fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a790;
L_23a6fc:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    cpu->regs[21] = 0ULL;
    goto L_23a398;
L_23a708:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_23a5e8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x23a71cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a5e8;
L_23a720:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23a728ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a648;
L_23a72c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a740;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a784;
L_23a740:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a754;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a768;
L_23a754:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_23a398;
L_23a768:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23a774ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_23a398;
L_23a784:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a78cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a740;
L_23a790:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23a79cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_23a398;
L_23a7a4:
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_23a368;
L_23a7ac:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x23a7b4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a46c;
L_23a7b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 4064ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23a7d0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a7e4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a89c;
L_23a7e4:
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_23a6e8;
L_23a7ec:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x23a7f4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a5fc;
L_23a7f8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a830;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23a830;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x23a814ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a830;
L_23a818:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x23a830ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x11f220ULL);
L_23a830:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a844;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a8ac;
L_23a844:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a858;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23a890;
L_23a858:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23a754;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23a754;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23a878ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_23a398;
L_23a888:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_23a5ac;
L_23a890:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x23a898ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a858;
L_23a89c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a8a4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_23a6e8;
L_23a8ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x23a8b4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a844;
L_23a8b8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23a8c0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23a50c;
L_23a8c4:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_23a3e4;
L_23a8cc:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 4000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 24));
    cpu->regs[30] = PB_BASE + 0x23a8ecULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_23a6e8;
L_23a8f0:
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    goto L_23a4c0;
L_23a8f8:
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_GE) goto L_23a380;
    goto L_23a4dc;
L_23a904:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 40992ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[0] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x23a924ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d5800ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23a93c;
L_23a92c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_23a93c:
    cpu->regs[30] = PB_BASE + 0x23a940ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_23a92c;
    cpu->regs[0] = 40992ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(43, cpu, tlb, PB_BASE + 0x145e2cULL); return; };
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_23aa00;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3496));
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0x23a998ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x23aa28ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_NE) goto L_23a9b8;
    PB_LDR(cpu->regs[21], (SP + 32));
L_23a9a8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_23a9b8:
    if ((cpu->regs[0])==0) goto L_23a9f4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23a9c8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23a9e8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_23a9e8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23a9e8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23a9e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[20] = cpu->regs[19];
    goto L_23a9a8;
L_23a9f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[20] = 0ULL;
    goto L_23a9a8;
L_23aa00:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 64ULL;
    cpu->regs[30] = PB_BASE + 0x23aa24ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_23a9a8;
}
