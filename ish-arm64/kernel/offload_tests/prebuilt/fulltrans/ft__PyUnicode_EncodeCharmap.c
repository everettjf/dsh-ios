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

void ft__PyUnicode_EncodeCharmap(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 272ULL;
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 240), cpu->regs[25]); PB_STR((SP + 240) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[20], (cpu->regs[26] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 168), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[26] + 16));
    PB_STR((SP + 24), cpu->regs[2]);
    PB_STR((SP + 88), 0ULL); PB_STR((SP + 88) + 8, 0ULL);
    PB_STR((SP + 104), 0ULL); PB_STR((SP + 104) + 8, 0ULL);
    if (!((cpu->regs[20] >> 5) & 1)) goto L_23f7d4;
    FLAG_CMP((((uint32_t)(cpu->regs[20]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[26] + 40ULL;
    cpu->regs[23] = cpu->regs[26] + 56ULL;
    cpu->regs[23] = (FLAG_EQ) ? cpu->regs[23] : cpu->regs[0];
L_23f6e0:
    cpu->regs[20] = ((uint32_t)(((cpu->regs[20] >> 2) & 0x7ULL)));
    if ((cpu->regs[21])==0) goto L_23f7b8;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23f6f4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((SP + 112), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23f7f0;
    if ((cpu->regs[22])==0) goto L_23f780;
    cpu->regs[25] = SP + 104ULL;
    cpu->regs[24] = SP + 112ULL;
    PB_STR((SP + 256), cpu->regs[27]); PB_STR((SP + 256) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
    cpu->regs[28] = 0ULL;
    goto L_23f750;
L_23f718:
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23f728ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23f738ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x23fc30ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_23f7ec;
    cpu->regs[19] = cpu->regs[27] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_23f810;
    cpu->regs[27] = cpu->regs[19];
L_23f750:
    FLAG_CMP(cpu->regs[22], cpu->regs[27]);
    if (FLAG_GT) goto L_23f718;
    PB_LDR(cpu->regs[1], (SP + 104)); PB_LDR(cpu->regs[0], (SP + 104) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LT) goto L_23f7dc;
L_23f768:
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x23f770ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[30] = PB_BASE + 0x23f778ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    PB_LDR(cpu->regs[0], (SP + 112));
L_23f780:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_23f7cc;
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[25], (SP + 240)); PB_LDR(cpu->regs[26], (SP + 240) + 8);
    SP = SP + 272ULL;
    return;
L_23f7b8:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = 256ULL;
    cpu->regs[30] = PB_BASE + 0x23f7c8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e836cULL);
    goto L_23f780;
L_23f7cc:
    PB_STR((SP + 256), cpu->regs[27]); PB_STR((SP + 256) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x23f7d4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_23f7d4:
    PB_LDR(cpu->regs[23], (cpu->regs[26] + 56));
    goto L_23f6e0;
L_23f7dc:
    cpu->regs[0] = SP + 112ULL;
    cpu->regs[30] = PB_BASE + 0x23f7e4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x13e868ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_23f768;
L_23f7ec:
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
L_23f7f0:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[30] = PB_BASE + 0x23f7f8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x23f800ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[30] = PB_BASE + 0x23f808ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    goto L_23f780;
L_23f810:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 16));
    cpu->regs[0] = PB_BASE + 0x51d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    cpu->regs[0] = cpu->regs[0] + 736ULL;
    PB_STR((SP + 40), cpu->regs[1]); PB_STR((SP + 40) + 8, cpu->regs[0]);
L_23f824:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_STR((SP + 32), cpu->regs[19]);
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LE) goto L_23f864;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x23f848ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    PB_LDR(cpu->regs[1], (SP + 48)); PB_LDR(cpu->regs[2], (SP + 48) + 8);
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    cpu->regs[1] = cpu->regs[21];
    if (FLAG_NE) goto L_23f9b0;
    cpu->regs[30] = PB_BASE + 0x23f85cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x23fe20ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23f9e0;
L_23f864:
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_23f874;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x23f870ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1b2a10ULL);
    cpu->regs[28] = cpu->regs[0];
L_23f874:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_23f9e8;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(8ULL)));
    if (FLAG_EQ) goto L_23f8a0;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_23f9a8;
    if (FLAG_HI) goto L_23f8a0;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_23fae4;
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_23fa3c;
L_23f8a0:
    cpu->regs[0] = SP + 120ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[0] = SP + 88ULL;
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[3] = cpu->regs[0] + 3464ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[2] = cpu->regs[0] + 832ULL;
    cpu->regs[4] = cpu->regs[26];
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[7] = cpu->regs[19];
    cpu->regs[6] = cpu->regs[27];
    cpu->regs[1] = SP + 96ULL;
    cpu->regs[30] = PB_BASE + 0x23f8dcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x247d80ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23f7ec;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 27) & 1)) goto L_23fb24;
    PB_LDR(cpu->regs[0], (SP + 112));
    PB_STR((SP + 32), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23f8fcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x24ae4cULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 32));
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x23f90cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x24ae4cULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[4], (SP + 32));
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[27], cpu->regs[1]);
    if (FLAG_LT) goto L_23fa7c;
L_23f924:
    PB_LDR(cpu->regs[0], (SP + 112));
    PB_STR((SP + 32), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23f930ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 32));
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[27] = cpu->regs[27] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x23f948ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 32));
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_HS) goto L_23fb10;
    cpu->regs[0] = cpu->regs[27] + cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_23fa38;
L_23f964:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[19];
    PB_STR((SP + 32), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23f974ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[4], (SP + 32));
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[19];
    PB_STR((SP + 104), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (SP + 120));
    PB_STR((SP + 32), cpu->regs[1]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_23f9a8;
L_23f994:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23f9a8;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x23f9a8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23f9a8:
    PB_LDR(cpu->regs[27], (SP + 32));
    goto L_23f750;
L_23f9b0:
    cpu->regs[30] = PB_BASE + 0x23f9b4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x24a6c0ULL);
    if ((cpu->regs[0])==0) goto L_23f7ec;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (FLAG_NE) goto L_23fbcc;
    if (((cpu->regs[2] >> 31) & 1)) goto L_23f9e0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_23f9e0;
    cpu->regs[30] = PB_BASE + 0x23f9e0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23f9e0:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_23f824;
L_23f9e8:
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[0] + 840ULL;
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[0] = SP + 128ULL;
    PB_STR((SP + 40), cpu->regs[0]);
L_23fa00:
    FLAG_CMP(cpu->regs[19], cpu->regs[4]);
    if (FLAG_LE) goto L_23f9a8;
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23fa18ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = 33ULL;
    PB_LDR(cpu->regs[0], (SP + 40)); PB_LDR(cpu->regs[2], (SP + 40) + 8);
    cpu->regs[30] = PB_BASE + 0x23fa28ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_LDR(cpu->regs[4], (SP + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(33ULL)));
    if (FLAG_LS) goto L_23fab0;
L_23fa38:
    __builtin_trap();
L_23fa3c:
    cpu->regs[4] = cpu->regs[27];
L_23fa40:
    FLAG_CMP(cpu->regs[19], cpu->regs[4]);
    if (FLAG_LE) goto L_23f9a8;
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 63ULL;
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x23fa60ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x23fc30ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_23f7ec;
    PB_LDR(cpu->regs[4], (SP + 40));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_23fae4;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_23fa40;
L_23fa7c:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x23fa84ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xa2440ULL);
    PB_LDR(cpu->regs[4], (SP + 32));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23f924;
L_23fa8c:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23f7ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23f7ec;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x23faa8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_23f7f0;
L_23fab0:
    PB_LDR(cpu->regs[5], (SP + 40));
L_23fab4:
    PB_LDRB(cpu->regs[0], (cpu->regs[5] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23fba4;
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    PB_STR((SP + 56), cpu->regs[4]); PB_STR((SP + 56) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x23fad0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x23fc30ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_23f7ec;
    PB_LDR(cpu->regs[4], (SP + 56)); PB_LDR(cpu->regs[5], (SP + 56) + 8);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_23fbc4;
L_23fae4:
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = SP + 88ULL;
    cpu->regs[5] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[5] = cpu->regs[5] + 3464ULL;
    cpu->regs[1] = cpu->regs[1] + 832ULL;
    cpu->regs[30] = PB_BASE + 0x23fb08ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x230848ULL);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_23f7f0;
L_23fb10:
    if (FLAG_LS) goto L_23f964;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[19];
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_HS) goto L_23f964;
    __builtin_trap();
L_23fb24:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 32));
    PB_LDR(cpu->regs[8], (cpu->regs[4] + 16));
    if (((cpu->regs[0] >> 5) & 1)) goto L_23fb90;
    PB_LDR(cpu->regs[7], (cpu->regs[4] + 56));
L_23fb34:
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    cpu->regs[5] = 0ULL;
    PB_STRW((SP + 32), cpu->regs[0]);
L_23fb40:
    FLAG_CMP(cpu->regs[8], cpu->regs[5]);
    if (FLAG_LE) goto L_23fbac;
    PB_LDRW(cpu->regs[0], (SP + 32));
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[3] = cpu->regs[25];
    PB_STR((SP + 48), cpu->regs[7]); PB_STR((SP + 48) + 8, cpu->regs[5]);
    PB_STR((SP + 64), cpu->regs[4]); PB_STR((SP + 64) + 8, cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x23fb64ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23fb70ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x23fc30ULL);
    PB_LDR(cpu->regs[7], (SP + 48)); PB_LDR(cpu->regs[5], (SP + 48) + 8);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    PB_LDR(cpu->regs[4], (SP + 64)); PB_LDR(cpu->regs[8], (SP + 64) + 8);
    if (FLAG_EQ) goto L_23fa8c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_23fbe4;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    goto L_23fb40;
L_23fb90:
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[4] + 40ULL;
    cpu->regs[7] = cpu->regs[4] + 56ULL;
    cpu->regs[7] = (FLAG_EQ) ? cpu->regs[7] : cpu->regs[1];
    goto L_23fb34;
L_23fba4:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_23fa00;
L_23fbac:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDR(cpu->regs[1], (SP + 120));
    PB_STR((SP + 32), cpu->regs[1]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_23f994;
    PB_LDR(cpu->regs[27], (SP + 32));
    goto L_23f750;
L_23fbc4:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    goto L_23fab4;
L_23fbcc:
    if (((cpu->regs[2] >> 31) & 1)) goto L_23f864;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_23f864;
    cpu->regs[30] = PB_BASE + 0x23fbe0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23f864;
L_23fbe4:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23fbf8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_23fc24;
L_23fbf8:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[5] = cpu->regs[0] + 3464ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[0] + 832ULL;
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x23fc1cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x230848ULL);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    goto L_23f7f0;
L_23fc24:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x23fc2cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23fbf8;
L_23fc30:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = PB_BASE + 0x51d000ULL;
    cpu->regs[4] = cpu->regs[4] + 3600ULL;
    cpu->regs[29] = SP;
    cpu->regs[4] = cpu->regs[4] + 736ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[23], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_NE) goto L_23fcb4;
    cpu->regs[30] = PB_BASE + 0x23fc70ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x23fe20ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_23fd70;
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_GT) goto L_23fe00;
L_23fc8c:
    cpu->regs[21] = cpu->regs[21] + 32ULL;
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    PB_STRB((cpu->regs[21] + cpu->regs[1]), cpu->regs[22]);
L_23fc9c:
    cpu->regs[0] = 0ULL;
L_23fca0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_23fcb4:
    cpu->regs[30] = PB_BASE + 0x23fcb8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x24a6c0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_23fd54;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_23fd5c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_23fd78;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[23]);
    if (FLAG_GT) goto L_23fd2c;
L_23fcec:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23fcf8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x129680ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[20] + 32ULL;
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    PB_STRB((cpu->regs[20] + cpu->regs[1]), cpu->regs[0]);
L_23fd0c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23fc9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23fc9c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23fd28ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23fc9c;
L_23fd2c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23fd34ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xa2440ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23fcec;
L_23fd38:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23fd54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_23fd54;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x23fd54ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_23fd54:
    cpu->regs[0] = 2ULL;
    goto L_23fca0;
L_23fd5c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23fd70;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_23fde0;
L_23fd70:
    cpu->regs[0] = 1ULL;
    goto L_23fca0;
L_23fd78:
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 16));
    cpu->regs[24] = cpu->regs[21] + 32ULL;
    cpu->regs[0] = cpu->regs[22] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_GT) goto L_23fdc8;
L_23fd8c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_HS) goto L_23fdec;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[22];
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_LO) goto L_23fdfc;
L_23fdac:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x23fdb8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_23fd0c;
L_23fdc8:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23fdd4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xa2440ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23fd38;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    goto L_23fd8c;
L_23fde0:
    cpu->regs[30] = PB_BASE + 0x23fde4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 1ULL;
    goto L_23fca0;
L_23fdec:
    if (FLAG_LS) goto L_23fdac;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[22];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_23fdac;
L_23fdfc:
    __builtin_trap();
L_23fe00:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x23fe0cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xa2440ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_23fd54;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 0));
    goto L_23fc8c;
    /* nop */
L_23fe20:
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] & 127ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] >> 11));
    cpu->regs[5] = ((cpu->regs[0] >> 7) & 0xfULL);
    cpu->regs[3] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_HI) goto L_23fe8c;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_23fe84;
    cpu->regs[2] = cpu->regs[1] + cpu->regs[2];
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_EQ) goto L_23fe8c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[5] + (cpu->regs[0] << 4)));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_EQ) goto L_23fe8c;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 48));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + (cpu->regs[0] << 3)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[4] + (cpu->regs[0] << 4)));
    cpu->regs[1] = cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = ((uint32_t)((FLAG_NE) ? cpu->regs[0] : (~0ULL)));
    return;
L_23fe84:
    cpu->regs[0] = 0ULL;
    return;
L_23fe8c:
    cpu->regs[0] = 4294967295ULL;
    return;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[1];
    if ((cpu->regs[0])!=0) goto L_23feb4;
    cpu->regs[0] = 0ULL;
    return;
L_23feb4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
}
