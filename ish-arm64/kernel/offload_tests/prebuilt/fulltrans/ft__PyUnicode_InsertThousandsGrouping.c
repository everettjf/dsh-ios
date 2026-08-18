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

void ft__PyUnicode_InsertThousandsGrouping(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_1697e8:
    SP = SP - 192ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[3] = cpu->regs[20] + cpu->regs[3];
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[5] & ~(((uint64_t)((int64_t)cpu->regs[5] >> 63)));
    cpu->regs[22] = cpu->regs[6];
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[7];
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[4], (cpu->regs[8] + 0));
    PB_STR((SP + 88), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 72), cpu->regs[3]);
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 16));
    PB_LDR(cpu->regs[25], (SP + 192));
    if ((cpu->regs[0])!=0) goto L_1698cc;
    cpu->regs[3] = 127ULL;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[3]);
    PB_STR((SP + 80), cpu->regs[1]);
    PB_LDRB(cpu->regs[23], (cpu->regs[6] + 0));
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_169858;
L_169850:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(255ULL)));
    if (FLAG_NE) goto L_1698ec;
L_169858:
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    PB_STR((SP + 0), cpu->regs[25]);
    cpu->regs[1] = (FLAG_GE) ? cpu->regs[19] : cpu->regs[20];
    cpu->regs[3] = SP + 72ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[6] = 0ULL;
    cpu->regs[1] = (FLAG_GT) ? cpu->regs[1] : (0ULL + 1);
    cpu->regs[5] = cpu->regs[1] - cpu->regs[20]; FLAG_CMP(cpu->regs[5], 0);
    cpu->regs[4] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[20];
    cpu->regs[1] = SP + 80ULL;
    cpu->regs[5] = cpu->regs[5] & ~(((uint64_t)((int64_t)cpu->regs[5] >> 63)));
    cpu->regs[4] = cpu->regs[4] & ~(((uint64_t)((int64_t)cpu->regs[4] >> 63)));
    cpu->regs[21] = cpu->regs[5] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x169890ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x169a64ULL);
L_169890:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1698e4;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    SP = SP + 192ULL;
    return;
L_1698cc:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    PB_LDRB(cpu->regs[23], (cpu->regs[6] + 0));
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_169850;
    goto L_169858;
L_1698e4:
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1698ecULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1698ec:
    FLAG_CMP(cpu->regs[20], 0ULL);
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    cpu->regs[28] = (FLAG_GT) ? cpu->regs[20] : (0ULL + 1);
    FLAG_CMP(cpu->regs[28], cpu->regs[19]);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[28] = (FLAG_GE) ? cpu->regs[28] : cpu->regs[19];
    PB_STR((SP + 0), cpu->regs[25]);
    FLAG_CMP(cpu->regs[28], cpu->regs[23]);
    cpu->regs[27] = SP + 72ULL;
    cpu->regs[28] = (FLAG_LE) ? cpu->regs[28] : cpu->regs[1];
    cpu->regs[26] = SP + 80ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[28]);
    cpu->regs[5] = cpu->regs[28] - cpu->regs[20];
    cpu->regs[4] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[28];
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[5] = cpu->regs[5] & ~(((uint64_t)((int64_t)cpu->regs[5] >> 63)));
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[4] = cpu->regs[4] & ~(((uint64_t)((int64_t)cpu->regs[4] >> 63)));
    cpu->regs[6] = 0ULL;
    cpu->regs[21] = cpu->regs[5] + cpu->regs[4];
    PB_STR((SP + 24), cpu->regs[0]); PB_STR((SP + 24) + 8, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[19] - cpu->regs[28];
    PB_STR((SP + 40), cpu->regs[4]); PB_STR((SP + 40) + 8, cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x16994cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x169a64ULL);
    PB_LDR(cpu->regs[4], (SP + 40));
    cpu->regs[20] = cpu->regs[20] - cpu->regs[4];
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) { FLAG_CMP(cpu->regs[19], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_1699cc;
    PB_LDR(cpu->regs[7], (SP + 48));
    cpu->regs[9] = 1ULL;
    PB_LDR(cpu->regs[0], (SP + 24)); PB_LDR(cpu->regs[2], (SP + 24) + 8);
    cpu->regs[19] = cpu->regs[19] - cpu->regs[7];
L_169970:
    PB_LDRB(cpu->regs[1], (cpu->regs[22] + cpu->regs[9]));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[7];
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_169a5c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(255ULL)));
    if (FLAG_NE) goto L_1699d4;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    PB_STR((SP + 0), cpu->regs[25]);
    cpu->regs[19] = (FLAG_GE) ? cpu->regs[19] : cpu->regs[20];
    cpu->regs[3] = cpu->regs[27];
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[6] = cpu->regs[24];
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : (0ULL + 1);
    cpu->regs[1] = cpu->regs[26];
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    cpu->regs[5] = cpu->regs[19] - cpu->regs[20];
    cpu->regs[4] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] & ~(((uint64_t)((int64_t)cpu->regs[5] >> 63)));
    cpu->regs[4] = cpu->regs[4] & ~(((uint64_t)((int64_t)cpu->regs[4] >> 63)));
    cpu->regs[8] = cpu->regs[4] + cpu->regs[5];
    cpu->regs[21] = cpu->regs[8] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1699c4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x169a64ULL);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
    goto L_169890;
L_1699cc:
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
    goto L_169890;
L_1699d4:
    cpu->regs[9] = cpu->regs[9] + 1ULL;
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[1];
L_1699e0:
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    PB_STR((SP + 0), cpu->regs[25]);
    cpu->regs[1] = (FLAG_GE) ? cpu->regs[19] : cpu->regs[20];
    cpu->regs[6] = cpu->regs[24];
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[1] = (FLAG_GT) ? cpu->regs[1] : (0ULL + 1);
    PB_STR((SP + 40), cpu->regs[2]); PB_STR((SP + 40) + 8, cpu->regs[7]);
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    cpu->regs[28] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[4];
    cpu->regs[1] = cpu->regs[26];
    FLAG_CMP(cpu->regs[20], cpu->regs[28]);
    cpu->regs[5] = cpu->regs[28] - cpu->regs[20];
    cpu->regs[4] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[28];
    PB_STR((SP + 56), cpu->regs[9]);
    cpu->regs[5] = cpu->regs[5] & ~(((uint64_t)((int64_t)cpu->regs[5] >> 63)));
    cpu->regs[4] = cpu->regs[4] & ~(((uint64_t)((int64_t)cpu->regs[4] >> 63)));
    PB_STR((SP + 24), cpu->regs[4]); PB_STR((SP + 24) + 8, cpu->regs[0]);
    cpu->regs[8] = cpu->regs[5] + cpu->regs[4];
    cpu->regs[21] = cpu->regs[8] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x169a34ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x169a64ULL);
    PB_LDR(cpu->regs[4], (SP + 24));
    cpu->regs[1] = cpu->regs[19] - cpu->regs[28];
    cpu->regs[20] = cpu->regs[20] - cpu->regs[4];
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_1699cc;
    PB_LDR(cpu->regs[7], (SP + 48)); PB_LDR(cpu->regs[9], (SP + 48) + 8);
    PB_LDR(cpu->regs[0], (SP + 32)); PB_LDR(cpu->regs[2], (SP + 32) + 8);
    cpu->regs[19] = cpu->regs[1] - cpu->regs[7];
    goto L_169970;
L_169a5c:
    cpu->regs[4] = cpu->regs[23];
    goto L_1699e0;
L_169a64:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[8], (SP + 64));
    if ((cpu->regs[0])!=0) goto L_169a8c;
    PB_LDRW(cpu->regs[0], (cpu->regs[8] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[6], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_169b80;
L_169a84:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_169a8c:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[5];
    if ((cpu->regs[6])!=0) goto L_169b38;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[4];
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
L_169ac4:
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[21];
    PB_STR((cpu->regs[22] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x169ad8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11ae68ULL);
    if ((cpu->regs[24])!=0) goto L_169af0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_169af0:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[24];
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 32));
    cpu->regs[0] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_169b94;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[4] = cpu->regs[2] + 40ULL;
    cpu->regs[1] = cpu->regs[2] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[4];
L_169b1c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[4] = cpu->regs[24];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = 48ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x20700cULL); return; };
L_169b38:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[7];
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[7];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x169b60ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[21];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[5] = 0ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    goto L_169ac4;
L_169b80:
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 32));
    cpu->regs[0] = 127ULL;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_169b9c;
    PB_STRW((cpu->regs[8] + 0), cpu->regs[0]);
    goto L_169a84;
L_169b94:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 56));
    goto L_169b1c;
L_169b9c:
    cpu->regs[0] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_169bc0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 1114111ULL;
    cpu->regs[0] = 65535ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    PB_STRW((cpu->regs[8] + 0), cpu->regs[0]);
    goto L_169a84;
L_169bc0:
    cpu->regs[0] = 255ULL;
    PB_STRW((cpu->regs[8] + 0), cpu->regs[0]);
    goto L_169a84;
    SP = SP - 128ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[22] = cpu->regs[7];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[24] = cpu->regs[6];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[25], (cpu->regs[0] + 16));
    PB_STR((SP + 96), cpu->regs[27]);
    cpu->regs[27] = cpu->regs[4];
    if ((cpu->regs[1])!=0) goto L_169cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_169cfc;
L_169c24:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    if ((cpu->regs[4])!=0) goto L_169dec;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    if ((cpu->regs[2])!=0) goto L_169e20;
L_169c34:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 48));
    if ((cpu->regs[4])==0) goto L_169d70;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[21];
    PB_LDR(cpu->regs[7], (cpu->regs[22] + 8)); PB_LDR(cpu->regs[6], (cpu->regs[22] + 8) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 80));
    cpu->regs[30] = PB_BASE + 0x169c60ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1697e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_169e5c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 48));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 128));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_169d78;
L_169c7c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 56));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_STR((cpu->regs[20] + 32), cpu->regs[1]);
    if ((cpu->regs[4])!=0) goto L_169d20;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 64));
    if ((cpu->regs[4])!=0) goto L_169d48;
L_169c98:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    if ((cpu->regs[2])!=0) goto L_169dc8;
L_169ca0:
    cpu->regs[0] = 0ULL;
L_169ca4:
    PB_LDR(cpu->regs[27], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 128ULL;
    return;
L_169cc4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[3] = cpu->regs[6];
    PB_STR((SP + 120), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x169cdcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x225f00ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[5], (SP + 120));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_169c24;
L_169cfc:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[25];
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x169d10ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11ce20ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    goto L_169c24;
L_169d20:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x169d30ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x2551b0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56)); PB_LDR(cpu->regs[4], (cpu->regs[19] + 56) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    if ((cpu->regs[4])==0) goto L_169c98;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_169d48:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x169d5cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x2551b0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    goto L_169c98;
L_169d70:
    PB_LDRW(cpu->regs[0], (SP + 128));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_169c7c;
L_169d78:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3240));
    cpu->regs[4] = 0ULL;
L_169d84:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[25];
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_LE) goto L_169c7c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[2] = cpu->regs[4] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x169da0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[3] & 255ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[5] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_169e44;
    cpu->regs[30] = PB_BASE + 0x169dbcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 48));
    goto L_169d84;
L_169dc8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x169dd8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x225f00ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    goto L_169ca0;
L_169dec:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[5];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x169e00ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x2551b0ULL);
    PB_LDRW(cpu->regs[0], (SP + 128));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_169e64;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
L_169e10:
    cpu->regs[0] = cpu->regs[2] + cpu->regs[3];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    if ((cpu->regs[2])==0) goto L_169c34;
L_169e20:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x169e30ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x225f00ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    goto L_169c34;
L_169e44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 2976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x169e5cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_169e5c:
    cpu->regs[0] = 4294967295ULL;
    goto L_169ca4;
L_169e64:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3240));
    cpu->regs[4] = 0ULL;
L_169e70:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[26];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[25];
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_LE) goto L_169e10;
    cpu->regs[2] = cpu->regs[4] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x169e90ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[3] = cpu->regs[3] & 255ULL;
    cpu->regs[0] = cpu->regs[25];
    PB_LDRB(cpu->regs[3], (cpu->regs[5] + cpu->regs[3]));
    cpu->regs[30] = PB_BASE + 0x169ea8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_169e70;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_169f0c;
    cpu->regs[20] = cpu->regs[0] >> 60;
    if ((cpu->regs[20])!=0) goto L_169f6c;
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x169ed0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_169f64;
    cpu->regs[1] = 16ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    if ((cpu->regs[19])==0) goto L_169f00;
L_169ee0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[19] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[1]);
    cpu->regs[19] = cpu->regs[19] >> 30;
    if ((cpu->regs[19])==0) goto L_169f00;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 28), cpu->regs[19]);
    if ((cpu->regs[20])==0) goto L_169f00;
    PB_STRW((cpu->regs[0] + 32), cpu->regs[20]);
L_169f00:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_169f0c:
    cpu->regs[19] = (uint64_t)(-(int64_t)cpu->regs[0]);
    cpu->regs[20] = cpu->regs[19] >> 60;
    if ((cpu->regs[20])!=0) goto L_169f30;
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x169f20ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_169f64;
    cpu->regs[1] = 18ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_169ee0;
L_169f30:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = 4294967295ULL;
L_169f38:
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x169f40ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_169f60;
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[21]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 24ULL));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_169ee0;
L_169f60:
    PB_LDR(cpu->regs[21], (SP + 32));
L_169f64:
    cpu->regs[0] = 0ULL;
    goto L_169f00;
L_169f6c:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = 1ULL;
    goto L_169f38;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 28720ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x169fa8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe31ccULL);
    if ((cpu->regs[0])==0) goto L_16a0dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    if (!((cpu->regs[2] >> 17) & 1)) goto L_16a080;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_16a124;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_16a12c;
L_169fdc:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x169fe4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[20] = cpu->regs[0];
L_169fe8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_169ffc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_16a118;
L_169ffc:
    if ((cpu->regs[20])==0) goto L_16a078;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_16a060;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16a014ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_16a050;
L_16a020:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_16a038;
L_16a028:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16a038:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_16a028;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16a04cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16a028;
L_16a050:
    cpu->regs[30] = PB_BASE + 0x16a054ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_16a0ec;
    cpu->regs[19] = 18446744073709551614ULL;
    goto L_16a020;
L_16a060:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 3344ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16a078ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_16a078:
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_16a028;
L_16a080:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 272));
    if ((cpu->regs[3])!=0) goto L_16a0b8;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_16a0a0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_16a0a0:
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_16a12c;
L_16a0a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16a0b0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x22c880ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_169fe8;
L_16a0b8:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16a0c4ULL; PB_CALL(32, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_16a12c;
    if ((cpu->regs[0])!=0) goto L_16a0a8;
L_16a0dc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(33, cpu, tlb, PB_BASE + 0x23d444ULL); return; };
L_16a0ec:
    cpu->regs[30] = PB_BASE + 0x16a0f0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 120));
    cpu->regs[30] = PB_BASE + 0x16a104ULL; PB_CALL(35, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_16a020;
    cpu->regs[19] = 18446744073709551614ULL;
    goto L_16a020;
L_16a118:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16a120ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_169ffc;
L_16a124:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_169fdc;
L_16a12c:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_16a0dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_16a0dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[30] = PB_BASE + 0x16a14cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16a0dc;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 120));
    if ((cpu->regs[2])==0) goto L_16a2a4;
L_16a168:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16a170ULL; PB_CALL(38, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_16a29c;
    cpu->regs[0] = cpu->regs[0] + 5ULL;
    cpu->regs[20] = cpu->regs[19];
    FLAG_CMP(cpu->regs[0], 261ULL);
    if (FLAG_HI) goto L_16a1b0;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 5ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[19] = ((cpu->regs[19] & 0xffffffffULL) << 5);
    cpu->regs[19] = cpu->regs[19] + 3048ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
L_16a1a4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_16a1b0:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if (((cpu->regs[19] >> 63) & 1)) goto L_16a238;
    cpu->regs[21] = cpu->regs[19] >> 30;
    if ((cpu->regs[21])!=0) goto L_16a1e0;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x16a1c8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_16a2e4;
    cpu->regs[1] = 8ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    PB_STRW((cpu->regs[0] + 24), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_16a1a4;
L_16a1e0:
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = 0ULL;
L_16a1e8:
    cpu->regs[22] = cpu->regs[20] >> 60;
    FLAG_CMP(cpu->regs[22], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? 1 : 0;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 2ULL));
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16a204ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_16a294;
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_16a274;
    cpu->regs[19] = cpu->regs[19] << 3;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] & 1073741823ULL));
    cpu->regs[1] = cpu->regs[0] + 28ULL;
L_16a218:
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]);
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[20]);
    PB_STRW((cpu->regs[1] + 0), cpu->regs[21]);
    if ((cpu->regs[22])!=0) goto L_16a264;
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_16a1a4;
L_16a238:
    cpu->regs[20] = (uint64_t)(-(int64_t)cpu->regs[19]);
    cpu->regs[21] = cpu->regs[20] >> 30;
    if ((cpu->regs[21])!=0) goto L_16a288;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x16a24cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_16a2e4;
    cpu->regs[1] = 10ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    PB_STRW((cpu->regs[0] + 24), cpu->regs[20]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_16a1a4;
L_16a264:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[0] + 32), cpu->regs[22]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_16a1a4;
L_16a274:
    cpu->regs[19] = cpu->regs[19] << 3;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] & 1073741823ULL));
    cpu->regs[19] = cpu->regs[19] | 2ULL;
    cpu->regs[1] = cpu->regs[0] + 28ULL;
    goto L_16a218;
L_16a288:
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = 1ULL;
    goto L_16a1e8;
L_16a294:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_16a29c:
    cpu->regs[0] = 0ULL;
    goto L_16a1a4;
L_16a2a4:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 72), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x16a2b0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdb420ULL);
    PB_LDR(cpu->regs[1], (SP + 72));
    if ((cpu->regs[0])!=0) goto L_16a2d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16a2c0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_16a29c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 120));
    PB_LDR(cpu->regs[1], (SP + 72));
    if ((cpu->regs[2])!=0) goto L_16a168;
L_16a2d4:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16a2dcULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x23d444ULL);
    cpu->regs[0] = 0ULL;
    goto L_16a1a4;
L_16a2e4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    goto L_16a1a4;
}
