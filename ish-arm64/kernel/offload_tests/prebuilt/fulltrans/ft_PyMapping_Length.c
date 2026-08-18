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

void ft_PyMapping_Length(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x15bc60ULL); return; };
    SP = SP - 160ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb911cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x15bc60ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_b9138;
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LS) goto L_b9140;
L_b9134:
    cpu->regs[30] = PB_BASE + 0xb9138ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x22d780ULL);
L_b9138:
    cpu->regs[22] = 0ULL;
    goto L_b93d0;
L_b9140:
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[30] = PB_BASE + 0xb9148ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b9134;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9158ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d2d70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b93a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9168ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xb8678ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b93a8;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_b91b0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_b91b0;
    cpu->regs[26] = PB_BASE + 0x2a5000ULL;
    cpu->regs[0] = cpu->regs[26] + 1184ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = SP + 48ULL;
    cpu->regs[27] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 16), cpu->regs[0]);
    goto L_b9280;
L_b91b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1136ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb91ccULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_b93b0;
L_b91d0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb91dcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c4a00ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b93b0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb91f0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1c4a00ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b93b0;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xb9204ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1cb820ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b93b0;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xb9214ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1cb820ULL);
    PB_LDR(cpu->regs[26], (SP + 48));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b928c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 16));
    PB_LDR(cpu->regs[23], (SP + 40));
    if ((cpu->regs[0])==0) goto L_b92ac;
    cpu->regs[0] = cpu->regs[26] + 33ULL;
    cpu->regs[1] = 61ULL;
    cpu->regs[30] = PB_BASE + 0xb9234ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((cpu->regs[0])!=0) goto L_b92ac;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[1] = cpu->regs[26] + 32ULL;
    cpu->regs[2] = cpu->regs[23] + 32ULL;
    cpu->regs[30] = PB_BASE + 0xb9248ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x23ff24ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b9300;
L_b9254:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_b9318;
L_b925c:
    if ((cpu->regs[28])==0) goto L_b93b0;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xb926cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xaf91cULL);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b9330;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b934c;
L_b927c:
    cpu->regs[27] = cpu->regs[27] + 8ULL;
L_b9280:
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_NE) goto L_b91d0;
    goto L_b9364;
L_b928c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b93b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b93b0;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xb92a8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b93b0;
L_b92ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2656ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb92c4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b92e0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b92e0;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xb92e0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b92e0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b93b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b93b0;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xb92fcULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b93b0;
L_b9300:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9254;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xb9314ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b9254;
L_b9318:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b925c;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xb932cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b925c;
L_b9330:
    if (((cpu->regs[1] >> 31) & 1)) goto L_b93b0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b93b0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xb9348ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b93b0;
L_b934c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b927c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xb9360ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b927c;
L_b9364:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b9380;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b9380;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9380ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9380:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b939c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b939c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb939cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b939c:
    PB_STR((cpu->regs[22] + (cpu->regs[19] << 3)), 0ULL);
    PB_STR((cpu->regs[25] + 0), cpu->regs[19]);
    goto L_b93d0;
L_b93a8:
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
L_b93b0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb93b8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb93c0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb93ccULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x88290ULL);
    goto L_b9138;
L_b93d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b93f0;
    cpu->regs[30] = PB_BASE + 0xb93f0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b93f0:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
}
