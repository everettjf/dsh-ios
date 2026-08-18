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

void ft_PyImport_ImportModuleLevelObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_13b400:
    SP = SP - 160ULL;
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x13b430ULL; PB_CALL(1, cpu, tlb, cpu->regs[6]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[23], (cpu->regs[5] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[23] + 16));
    if ((cpu->regs[20])==0) goto L_13b9cc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_13baac;
    cpu->regs[22] = cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_13ba14;
    cpu->regs[21] = cpu->regs[3];
    if (FLAG_NE) goto L_13b7f0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_13b9cc;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13b48c;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_13b48c:
    cpu->regs[24] = cpu->regs[20];
L_13b490:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x13b49cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11c380ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13b5fc;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_EQ) goto L_13b604;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[30] = PB_BASE + 0x13b4c4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x142660ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13ba94;
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[25]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_13b708;
L_13b4d8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13b4e0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1227a0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_13ba94;
    if (FLAG_NE) goto L_13b7ac;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) { FLAG_CMP(cpu->regs[22], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_13b718;
L_13b4fc:
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 1ULL;
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x13b514ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1348ccULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_13ba94;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_13b74c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13b728;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b54c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13b59c;
L_13b54c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b560;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13b5e4;
L_13b560:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_13b9c4;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    SP = SP + 160ULL;
    return;
L_13b59c:
    cpu->regs[20] = cpu->regs[19];
L_13b5a0:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13b5b0ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
L_13b5b8:
    if ((cpu->regs[0])==0) goto L_13b5d0;
L_13b5bc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13b5d0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13b5e8;
L_13b5d0:
    if ((cpu->regs[19])!=0) goto L_13b560;
L_13b5d4:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13b5e0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1dbf20ULL);
    goto L_13b560;
L_13b5e4:
    cpu->regs[0] = cpu->regs[19];
L_13b5e8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13b5f4ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[19])!=0) goto L_13b560;
    goto L_13b5d4;
L_13b5fc:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])!=0) goto L_13b9fc;
L_13b604:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x13b610ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 16));
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[0] + 2744ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[25] + 1024));
    PB_LDRW(cpu->regs[19], (cpu->regs[25] + 1324));
    cpu->regs[30] = PB_BASE + 0x13b62cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1bce60ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b98c;
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x13b640ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1bce60ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b984;
    cpu->regs[1] = SP + 48ULL;
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0x13b654ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1bce60ULL);
    PB_LDR(cpu->regs[6], (SP + 40));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b97c;
    PB_LDR(cpu->regs[5], (SP + 32));
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    FLAG_CMP(cpu->regs[5], 0ULL);
    PB_LDR(cpu->regs[7], (SP + 48));
    cpu->regs[5] = (FLAG_NE) ? cpu->regs[5] : cpu->regs[4];
    FLAG_CMP(cpu->regs[6], 0ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[6] = (FLAG_NE) ? cpu->regs[6] : cpu->regs[4];
    FLAG_CMP(cpu->regs[7], 0ULL);
    cpu->regs[7] = (FLAG_NE) ? cpu->regs[7] : cpu->regs[4];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 1176ULL;
    cpu->regs[1] = cpu->regs[1] + 1184ULL;
    cpu->regs[30] = PB_BASE + 0x13b6a0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x181ea8ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 48));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13be74;
    cpu->regs[30] = PB_BASE + 0x13b6b0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x13b6b8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x13b6c0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdce4cULL);
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_13baf4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 35160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 960));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 984));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13b6e8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x13bfa0ULL);
    cpu->regs[19] = cpu->regs[0];
L_13b6ec:
    if ((cpu->regs[19])==0) goto L_13b98c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[21], 0ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_13b4d8;
L_13b708:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_13b4fc;
L_13b718:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13b728;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_13b728:
    cpu->regs[20] = cpu->regs[19];
L_13b72c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b7a0;
L_13b734:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13b5a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    goto L_13b5b8;
L_13b74c:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_13ba3c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13b75cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13ba94;
    cpu->regs[1] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13b778ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x13b400ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13b72c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_13b72c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13b798ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_13b798:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13b9ec;
L_13b7a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    goto L_13b5bc;
L_13b7ac:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2248));
    cpu->regs[5] = 31456ULL;
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x13b7c8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13ba94;
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])!=0) goto L_13b940;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13b7e8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_13b7e8:
    cpu->regs[20] = cpu->regs[19];
    goto L_13b798;
L_13b7f0:
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_13be50;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_13be2c;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2248));
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[11] = 31344ULL;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[11];
    cpu->regs[30] = PB_BASE + 0x13b828ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[24] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_EQ) goto L_13bc68;
    if ((cpu->regs[0])==0) goto L_13bc58;
    cpu->regs[1] = 33336ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x13b848ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_13bd48;
L_13b84c:
    PB_LDRW(cpu->regs[1], (cpu->regs[24] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_13b85c;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[1]);
L_13b85c:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_13bd94;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[27]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_13b8c4;
    cpu->regs[10] = 53256ULL;
    cpu->regs[1] = cpu->regs[25] + cpu->regs[10];
    cpu->regs[30] = PB_BASE + 0x13b880ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13bd58;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x13b898ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[25] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_13b8b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_13b8b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13b8b8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_13b8b8:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_13bd58;
    if (FLAG_EQ) goto L_13bd60;
L_13b8c4:
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 16));
    if ((cpu->regs[2])==0) goto L_13bd24;
    cpu->regs[19] = 1ULL;
L_13b8d0:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_GT) goto L_13bbcc;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x13b8e4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13b8fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13bd88;
L_13b8fc:
    if ((cpu->regs[19])==0) goto L_13b9a0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_13b9b8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[0] + 1112ULL;
    cpu->regs[30] = PB_BASE + 0x13b91cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13b934;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13bc00;
L_13b934:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    if ((cpu->regs[24])!=0) goto L_13b490;
    goto L_13b5d4;
L_13b940:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13b954;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13ba34;
L_13b954:
    cpu->regs[4] = 35376ULL;
    cpu->regs[1] = cpu->regs[25] + cpu->regs[4];
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 960));
    cpu->regs[3] = cpu->regs[21];
    PB_LDR(cpu->regs[4], (cpu->regs[26] + 984));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13b974ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x13bfa0ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_13b798;
L_13b97c:
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x13b984ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdce4cULL);
L_13b984:
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x13b98cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdce4cULL);
L_13b98c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b9a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13b9a8;
L_13b9a0:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13b5d4;
L_13b9a8:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_13b5a0;
L_13b9b8:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    cpu->regs[24] = cpu->regs[19];
    goto L_13b490;
L_13b9c4:
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x13b9ccULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_13b9cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 688ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13b9e8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_13b5d4;
L_13b9ec:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_13b7a0;
    goto L_13b5a0;
L_13b9fc:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_13b604;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13b5d4;
    cpu->regs[20] = 0ULL;
    goto L_13b734;
L_13ba14:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 744ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13ba30ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_13b5d4;
L_13ba34:
    cpu->regs[30] = PB_BASE + 0x13ba38ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13b954;
L_13ba3c:
    PB_LDR(cpu->regs[3], (cpu->regs[24] + 16));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 0ULL;
    cpu->regs[3] = cpu->regs[3] - cpu->regs[21];
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x13ba54ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13ba94;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x13ba68ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11c380ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13ba80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13ba9c;
L_13ba80:
    if ((cpu->regs[20])!=0) goto L_13b72c;
L_13ba84:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_13bacc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_13bacc;
L_13ba94:
    cpu->regs[20] = 0ULL;
    goto L_13b72c;
L_13ba9c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13baa4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if ((cpu->regs[20])!=0) goto L_13b72c;
    goto L_13ba84;
L_13baac:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 712ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13bac8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_13b5d4;
L_13bacc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3544));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 1288ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13baf0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_13b72c;
L_13baf4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2192));
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 1032));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STR((SP + 0), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_13bc0c;
L_13bb0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 1016));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[25] + 1016), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x13bb1cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7bf70ULL);
    cpu->regs[28] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[6] = 35160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 960));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[6];
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 984));
    cpu->regs[2] = cpu->regs[24];
    PB_STR((cpu->regs[25] + 1024), 0ULL);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13bb48ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x13bfa0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x13bb50ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7bf70ULL);
    cpu->regs[28] = cpu->regs[0] - cpu->regs[28];
    PB_LDRW(cpu->regs[4], (cpu->regs[25] + 1016));
    cpu->regs[27] = cpu->regs[27] + cpu->regs[28];
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 1024));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[25] + 1016), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[28] - cpu->regs[1];
    cpu->regs[1] = 1ULL;
    PB_STRW((SP + 28), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x13bb78ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1bea60ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[28];
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x13bb8cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1bea60ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x13bb9cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 0)); PB_LDR(cpu->regs[3], (SP + 0) + 8);
    cpu->regs[5] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[5] = cpu->regs[5] + 240ULL;
    PB_LDRW(cpu->regs[4], (SP + 28));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1248ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] << 1));
    cpu->regs[30] = PB_BASE + 0x13bbc4ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    PB_STR((cpu->regs[25] + 1024), cpu->regs[27]);
    goto L_13b6ec;
L_13bbcc:
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x13bbe4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1348ccULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_13bd58;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13bc2c;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    goto L_13b8d0;
L_13bc00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13bc08ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13b934;
L_13bc0c:
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = 55ULL;
    cpu->regs[0] = cpu->regs[0] + 1192ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x13bc24ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7b510ULL);
    PB_STRW((cpu->regs[25] + 1032), 0ULL);
    goto L_13bb0c;
L_13bc2c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2840));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 1056ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13bc48ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1d5980ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
L_13bc4c:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x13bc54ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_13b5d4;
L_13bc58:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_13bc68;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_13bdd0;
L_13bc68:
    cpu->regs[0] = 33336ULL;
    cpu->regs[1] = cpu->regs[25] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13bc78ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13bddc;
    FLAG_CMP(cpu->regs[24], cpu->regs[27]);
    if (FLAG_NE) goto L_13bde8;
L_13bc88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2888));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 928ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x13bca4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_13bdd0;
    cpu->regs[8] = 30760ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x13bcb8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13bdc0;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13bcd0;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
L_13bcd0:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_13beb4;
    cpu->regs[7] = 31456ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x13bcecULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdd250ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13bd58;
    PB_LDR(cpu->regs[3], (cpu->regs[24] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_13b8c4;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x13bd10ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1348ccULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_13bd58;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_13bed8;
L_13bd24:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2840));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 1120ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13bd40ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1d5980ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13bd48:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_13b84c;
L_13bd50:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_13bdb8;
L_13bd58:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13bd60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x13bd7cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13b8c4;
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13bd88:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x13bd90ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13b8fc;
L_13bd94:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 824ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13bdb0ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1d5980ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13bdb8:
    if ((cpu->regs[24])!=0) goto L_13b84c;
    goto L_13bc88;
L_13bdc0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_13be8c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_13be8c;
L_13bdd0:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    cpu->regs[24] = 0ULL;
    goto L_13bc4c;
L_13bddc:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])!=0) goto L_13bd50;
    goto L_13bc88;
L_13bde8:
    cpu->regs[9] = 53256ULL;
    cpu->regs[1] = cpu->regs[25] + cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x13bdf4ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13bdd0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_13b8c4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 888ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13be24ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1d5980ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13be2c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 800ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13be4cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_13bc4c;
L_13be50:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3544));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 768ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13be70ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_13bc4c;
L_13be74:
    cpu->regs[30] = PB_BASE + 0x13be78ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x13be80ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x13be88ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_13b98c;
L_13be8c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3544));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 768ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13beacULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1d5980ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13beb4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 1024ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x13bed0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1d5980ULL);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_13bc4c;
L_13bed8:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x13bee4ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13bd58;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13bf00;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13bf08;
L_13bf00:
    cpu->regs[24] = cpu->regs[19];
    goto L_13b8c4;
L_13bf08:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[24] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13bf14ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13b8c4;
    /* nop */
    /* nop */
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_13bf84;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[4] = 40ULL;
    cpu->regs[0] = (uint64_t)(uint32_t)cpu->regs[0] * (uint64_t)(uint32_t)cpu->regs[4];
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_13bf84;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 83ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    if (FLAG_HI) goto L_13bf6c;
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 32)) | ((0x8050ULL & 0xffff) << 32);
    cpu->regs[1] = cpu->regs[0] >> (cpu->regs[1] & 63);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] & 1ULL));
    if (((cpu->regs[1] >> 0) & 1)) goto L_13bf70;
L_13bf6c:
    return;
L_13bf70:
    cpu->regs[2] = cpu->regs[2] + 8ULL;
    cpu->regs[1] = 0ULL;
L_13bf78:
    cpu->regs[5] = (uint64_t)(uint32_t)cpu->regs[1] * (uint64_t)(uint32_t)cpu->regs[4];
    PB_LDRW(cpu->regs[5], (cpu->regs[2] + cpu->regs[5]));
    if (((cpu->regs[5] >> 31) & 1)) goto L_13bf8c;
L_13bf84:
    cpu->regs[0] = 0ULL;
    return;
L_13bf8c:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_13bf78;
    return;
    /* nop */
}
