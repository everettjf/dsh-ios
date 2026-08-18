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

void ft__PySlice_FromIndices(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x200304ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])==0) goto L_200370;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x200314ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_200354;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20032cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1f6d44ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_200390;
L_200338:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_200378;
L_200340:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_200354:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_200370;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_200370;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x200370ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_200370:
    cpu->regs[21] = 0ULL;
    goto L_200340;
L_200378:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_200340;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20038cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_200340;
L_200390:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_200338;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2003a4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_200338;
    SP = SP - 176ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[1] : (0ULL + 1);
    if ((cpu->regs[2])!=0) goto L_200558;
    cpu->regs[4] = 0ULL;
L_2003e8:
    cpu->regs[6] = 1ULL;
    cpu->regs[3] = SP + 24ULL;
    PB_STRW((SP + 0), cpu->regs[6]);
    cpu->regs[19] = cpu->regs[19] + cpu->regs[4];
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[4] = cpu->regs[4] - 160ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[22] = cpu->regs[19] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x200420ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1ec340ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20077c;
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_200788;
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[22])!=0) goto L_200560;
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[22] = 0ULL;
L_20045c:
    if ((cpu->regs[21])==0) goto L_20073c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_200744;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_2007b8;
    cpu->regs[25] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_2005c4;
L_200488:
    cpu->regs[30] = PB_BASE + 0x20048cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x200b2cULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(0ULL)));
    cpu->regs[26] = (FLAG_NE) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0x20049cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22608));
    cpu->regs[30] = PB_BASE + 0x2004a8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_200774;
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_200724;
L_2004bc:
    PB_STR((cpu->regs[19] + 16), cpu->regs[27]);
    if ((cpu->regs[22])!=0) goto L_200660;
L_2004c4:
    PB_STR((cpu->regs[19] + 24), cpu->regs[22]); PB_STR((cpu->regs[19] + 24) + 8, 0ULL);
    if ((cpu->regs[25])!=0) goto L_20064c;
L_2004cc:
    PB_STR((cpu->regs[19] + 40), cpu->regs[25]); PB_STR((cpu->regs[19] + 40) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_STRB((cpu->regs[19] + 56), cpu->regs[23]);
    PB_STRB((cpu->regs[19] + 57), cpu->regs[24]);
    PB_STRB((cpu->regs[19] + 58), cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x2004e4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xd9444ULL);
    if ((cpu->regs[20])==0) goto L_200500;
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2004fcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18fab0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_200760;
L_200500:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x200508ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x200510ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
L_20051c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x200524ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_200674;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 176ULL;
    return;
L_200558:
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 16));
    goto L_2003e8;
L_200560:
    PB_LDR(cpu->regs[28], (cpu->regs[20] + 16));
    if ((cpu->regs[28])!=0) goto L_2005b4;
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2760));
L_200570:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])==0) goto L_200604;
    cpu->regs[30] = PB_BASE + 0x20057cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[25] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_2006c8;
    cpu->regs[22] = cpu->regs[22] - 1ULL; FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_NE) goto L_200608;
L_20058c:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = (FLAG_NE) ? 1 : 0;
    cpu->regs[26] = 0ULL;
L_20059c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[28], cpu->regs[0]);
    if (FLAG_NE) goto L_2005f0;
    cpu->regs[22] = 0ULL;
    goto L_20045c;
L_2005b4:
    cpu->regs[22] = cpu->regs[19] - 2ULL; FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_NE) goto L_200570;
    cpu->regs[25] = 0ULL;
    goto L_20058c;
L_2005c4:
    cpu->regs[25] = cpu->regs[21];
    if ((cpu->regs[22])==0) goto L_200488;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 4016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2005e4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2005ecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_2006c8;
L_2005f0:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x2005f8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x200f68ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_20045c;
    goto L_2006c8;
L_200604:
    cpu->regs[25] = 0ULL;
L_200608:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    if ((cpu->regs[19])==0) goto L_2006dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x200618ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_2006c8;
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_NE) goto L_200684;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    cpu->regs[23] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[24] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_2006b0;
    cpu->regs[26] = 0ULL;
    goto L_20059c;
L_20064c:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2004cc;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
    goto L_2004cc;
L_200660:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2004c4;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_2004c4;
L_200674:
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x200684ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_200684:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    cpu->regs[30] = PB_BASE + 0x20068cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[26] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_2006c8;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    cpu->regs[23] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    cpu->regs[24] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_2006fc;
L_2006b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2006c8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2006c8:
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_20051c;
L_2006dc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    cpu->regs[30] = PB_BASE + 0x2006e4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[26] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_20072c;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = (FLAG_NE) ? 1 : 0;
    cpu->regs[19] = 0ULL;
L_2006fc:
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_20059c;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] | cpu->regs[19]));
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_20059c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x200720ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2006c8;
L_200724:
    PB_STRW((cpu->regs[27] + 0), cpu->regs[0]);
    goto L_2004bc;
L_20072c:
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_20051c;
L_20073c:
    cpu->regs[25] = 0ULL;
    goto L_200488;
L_200744:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3944ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20075cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2006c8;
L_200760:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_200774;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2007dc;
L_200774:
    cpu->regs[19] = 0ULL;
    goto L_200500;
L_20077c:
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_20051c;
L_200788:
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2920ULL;
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3840ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2007b0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_20051c;
L_2007b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2007d0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2007d8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_2006c8;
L_2007dc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2007e8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_200500;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x200804ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_200820;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_200820:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_200860;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x20085cULL; PB_CALL(32, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20089c;
L_200860:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_200890;
L_200868:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_2008ac;
L_200870:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_20089c;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_200890:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x200898ULL; PB_CALL(33, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_200868;
L_20089c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2008ac:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2008b4ULL; PB_CALL(34, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_200870;
    goto L_20089c;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[19], (cpu->regs[0] + 8) + 8);
    cpu->regs[30] = PB_BASE + 0x2008dcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x2008e4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[1] = 18446744073709551609ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[1] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0);
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_LT) goto L_200ae0;
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 2);
    cpu->regs[0] = cpu->regs[0] + 6ULL;
    cpu->regs[30] = PB_BASE + 0x20090cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xd8e60ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_200b20;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])==0) goto L_200a48;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 40));
L_200920:
    cpu->regs[4] = cpu->regs[1] + cpu->regs[19];
    cpu->regs[3] = 39ULL;
    cpu->regs[5] = 34ULL;
    goto L_200948;
L_200930:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_200b18;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(39ULL)));
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[5];
L_200948:
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_LO) goto L_200930;
L_200950:
    cpu->regs[1] = 0ULL;
    goto L_200960;
L_200958:
    PB_STRB((cpu->regs[20] + cpu->regs[1]), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_200960:
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + cpu->regs[1]));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_200958;
    cpu->regs[4] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] + 4064ULL;
L_200974:
    PB_LDRB(cpu->regs[5], (cpu->regs[4] + 0));
    cpu->regs[1] = cpu->regs[2] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_200990;
    cpu->regs[2] = cpu->regs[1];
    PB_STRB((cpu->regs[1] + -1), cpu->regs[5]);
    goto L_200974;
L_200990:
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] & 255ULL));
    PB_STRB((cpu->regs[2] + 0), cpu->regs[5]);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])==0) goto L_200a54;
    PB_LDR(cpu->regs[7], (cpu->regs[22] + 40));
L_2009a4:
    cpu->regs[3] = 0ULL;
    cpu->regs[6] = 92ULL;
L_2009ac:
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_GE) goto L_2009fc;
    PB_LDRB(cpu->regs[2], (cpu->regs[7] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(39ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[6]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_200b00;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_200ad0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_200ac0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_200ab0;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_200a9c;
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] - 32ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(94ULL)));
    if (FLAG_HI) goto L_200a60;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STRB(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += 1;
    goto L_2009ac;
L_2009fc:
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 192ULL;
    PB_STRB(cpu->regs[1], cpu->regs[5]); cpu->regs[1] += 1;
L_200a08:
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_200a40;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[20];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x200a20ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1ec0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x200a2cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdfce0ULL);
L_200a2c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_200a40:
    PB_STRB(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += 1;
    goto L_200a08;
L_200a48:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3336));
    goto L_200920;
L_200a54:
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 3336));
    goto L_2009a4;
L_200a60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2576));
    cpu->regs[4] = 30812ULL;
    PB_STRH((cpu->regs[1] + 0), cpu->regs[4]);
    cpu->regs[4] = ((cpu->regs[2] >> 4) & 0xfULL);
    cpu->regs[2] = cpu->regs[2] & 15ULL;
    cpu->regs[1] = cpu->regs[1] + 4ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[8] + cpu->regs[4]));
    PB_STRB((cpu->regs[1] + -2), cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[2]));
    PB_STRB((cpu->regs[1] + -1), cpu->regs[0]);
    goto L_2009ac;
L_200a9c:
    cpu->regs[0] = 30812ULL;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x3030ULL & 0xffff) << 16);
    PB_STRW(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 4;
    goto L_2009ac;
L_200ab0:
    cpu->regs[0] = 29276ULL;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STRH(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 2;
    goto L_2009ac;
L_200ac0:
    cpu->regs[0] = 28252ULL;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STRH(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 2;
    goto L_2009ac;
L_200ad0:
    cpu->regs[0] = 29788ULL;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STRH(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 2;
    goto L_2009ac;
L_200ae0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 4072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x200afcULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_200a2c;
L_200b00:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STRB(cpu->regs[0], cpu->regs[6]); cpu->regs[0] += 2;
    PB_STRB((cpu->regs[1] + 1), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[0];
    goto L_2009ac;
L_200b18:
    cpu->regs[3] = 39ULL;
    goto L_200950;
L_200b20:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x200b28ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_200a2c;
L_200b2c:
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x200b48ULL; PB_CALL(42, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_200b88;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_200b88;
    cpu->regs[30] = PB_BASE + 0x200b64ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1f058cULL);
    if ((cpu->regs[0])==0) goto L_200b84;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_200b7c;
L_200b74:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_200b7c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_200b74;
L_200b84:
    cpu->regs[30] = PB_BASE + 0x200b88ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_200b88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_200b74;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 16));
    if (((cpu->regs[1] >> 5) & 1)) goto L_200bd8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_200bc0:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_200bd0;
    return;
L_200bd0:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_200bd8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_200bc0;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 8ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x200bf8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xef6a0ULL);
    if ((cpu->regs[0])==0) goto L_200c08;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[1] = 1ULL;
    { PB_CALL(46, cpu, tlb, PB_BASE + 0x200c20ULL); return; };
L_200c08:
    fr[0] = -1.0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
}
