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

void ft__PyToken_ThreeChars(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(47ULL)));
    if (FLAG_EQ) goto L_19d19c;
    if (FLAG_GT) goto L_19d144;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(42ULL)));
    if (FLAG_EQ) goto L_19d16c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(46ULL)));
    if (FLAG_EQ) goto L_19d1b4;
L_19d13c:
    cpu->regs[0] = 55ULL;
    return;
L_19d144:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(60ULL)));
    if (FLAG_EQ) goto L_19d184;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(62ULL)));
    if (FLAG_NE) goto L_19d13c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(61ULL)));
    cpu->regs[2] = 55ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = 45ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[0];
    return;
L_19d16c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(61ULL)));
    cpu->regs[2] = 55ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = 46ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[0];
    return;
L_19d184:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(61ULL)));
    cpu->regs[2] = 55ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = 44ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[0];
    return;
L_19d19c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(61ULL)));
    cpu->regs[2] = 55ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = 48ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[0];
    return;
L_19d1b4:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(46ULL)));
    cpu->regs[2] = 55ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = 52ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[0];
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])==0) goto L_19d210;
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_19d210;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 40));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_19d1fc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
L_19d1fc:
    PB_STR((cpu->regs[2] + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x19d204ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_19d208:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_19d210:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 2976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x19d228ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_19d208;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
L_19d240:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_LT) goto L_19d24c;
    return;
L_19d24c:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] + 3ULL));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[5] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(23ULL)));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[4] : (cpu->regs[0] + 1);
    goto L_19d240;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_19d3e0;
L_19d294:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_19d3d0;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = 8ULL;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x19d2acULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19d3b0;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_19d398;
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 1ULL;
L_19d2cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x19d2d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x19cbd0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_19d330;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x19d2ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19d380;
L_19d2f4:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_GT) goto L_19d348;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x19d308ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_19d308:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_19d31c:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_19d330:
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_EQ) goto L_19d360;
L_19d338:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[23] + (cpu->regs[24] << 3)), cpu->regs[21]);
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_19d2cc;
L_19d348:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[23] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_19d2f4;
L_19d360:
    cpu->regs[25] = cpu->regs[25] << 1;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[25] << 3;
    cpu->regs[30] = PB_BASE + 0x19d370ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19d380;
    cpu->regs[23] = cpu->regs[0];
    goto L_19d338;
L_19d380:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x19d388ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x19d394ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_19d308;
L_19d398:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_19d31c;
L_19d3b0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x19d3c0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_19d31c;
L_19d3d0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_19d31c;
L_19d3e0:
    cpu->regs[30] = PB_BASE + 0x19d3e4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_19d294;
}
