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

void ft_PyContext_Enter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa2530ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xa2470ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[26], (cpu->regs[0] + 16) + 8);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 56));
L_a2568:
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[22] << 3);
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    cpu->regs[2] = 2ULL;
    if (FLAG_LT) goto L_a2600;
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[21];
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_a2594;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[3]);
L_a2594:
    cpu->regs[30] = PB_BASE + 0xa2598ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_a25b8;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a25b8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa25b8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a25b8:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_a2604;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_EQ) goto L_a25ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[20] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[1] + 1912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa25e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a2604;
L_a25ec:
    FLAG_CMP(cpu->regs[22], 64ULL);
    if (FLAG_NE) goto L_a2568;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 520));
    cpu->regs[22] = 0ULL;
    goto L_a2568;
L_a2600:
    cpu->regs[20] = 0ULL;
L_a2604:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 56));
    PB_STR((SP + 80), cpu->regs[27]);
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[27], (cpu->regs[0] + 16) + 8);
L_a2654:
    cpu->regs[0] = cpu->regs[27] + (cpu->regs[21] << 3);
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[24] = cpu->regs[24] - 1ULL; FLAG_CMP(cpu->regs[24], 0);
    cpu->regs[2] = 2ULL;
    if (FLAG_LT) goto L_a26ec;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_a2680;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[3]);
L_a2680:
    cpu->regs[30] = PB_BASE + 0xa2684ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_a26a4;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a26a4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa26a4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a26a4:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    if (((cpu->regs[22] >> 31) & 1)) goto L_a270c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[23] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_EQ) goto L_a26d8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa26d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a270c;
L_a26d8:
    FLAG_CMP(cpu->regs[21], 64ULL);
    if (FLAG_NE) goto L_a2654;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 520));
    cpu->regs[21] = 0ULL;
    goto L_a2654;
L_a26ec:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_a270c:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[7] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[5] = SP + 16ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3800));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[6];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = SP;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 40));
    cpu->regs[2] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[21] + 16)); PB_LDR(cpu->regs[22], (cpu->regs[21] + 16) + 8);
    cpu->regs[2] = cpu->regs[2] + 2816ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[21] + 56));
    PB_STR((SP + 8), cpu->regs[8]); PB_STR((SP + 8) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0xa279cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x93130ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a2864;
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if (!((cpu->regs[1] >> 63) & 1)) goto L_a27c4;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0]; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_LT) goto L_a27bc;
    PB_STR((SP + 16), cpu->regs[1]);
    goto L_a27c4;
L_a27bc:
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 16), 0ULL);
L_a27c4:
    PB_LDR(cpu->regs[2], (SP + 8));
    if (!((cpu->regs[2] >> 63) & 1)) goto L_a27e4;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[0]; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_LT) goto L_a27dc;
    PB_STR((SP + 8), cpu->regs[2]);
    goto L_a27e4;
L_a27dc:
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 8), 0ULL);
L_a27e4:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_a27f4;
    cpu->regs[2] = cpu->regs[0];
    PB_STR((SP + 8), cpu->regs[0]);
L_a27f4:
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_GE) goto L_a2804;
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 16), cpu->regs[2]);
L_a2804:
    cpu->regs[3] = cpu->regs[1] - 64ULL;
    cpu->regs[0] = 0ULL;
L_a280c:
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_a2820;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 520));
    cpu->regs[0] = cpu->regs[0] + 64ULL;
    goto L_a280c;
L_a2820:
    cpu->regs[3] = cpu->regs[0];
L_a2824:
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_GE) goto L_a2848;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[20], 64ULL);
    if (FLAG_NE) goto L_a2840;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 520));
    cpu->regs[20] = 0ULL;
L_a2840:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_a2824;
L_a2848:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[19] = cpu->regs[2] - cpu->regs[1];
    goto L_a2884;
L_a2860:
    if (FLAG_EQ) goto L_a28ec;
L_a2864:
    cpu->regs[0] = 0ULL;
    goto L_a2934;
L_a286c:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[20], 64ULL);
    if (FLAG_NE) goto L_a2880;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 520));
    cpu->regs[20] = 0ULL;
L_a2880:
    cpu->regs[19] = cpu->regs[25];
L_a2884:
    cpu->regs[25] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[25], 0);
    if (FLAG_LT) goto L_a2914;
    cpu->regs[0] = cpu->regs[22] + (cpu->regs[20] << 3);
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a28a4;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
L_a28a4:
    PB_LDR(cpu->regs[1], (SP + 0));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xa28b4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a28d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a28d4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xa28d4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a28d4:
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_a2860;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa28e8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    goto L_a2934;
L_a28ec:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 56));
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_a286c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa2910ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a2864;
L_a2914:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[1] = cpu->regs[1] + 1944ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa2930ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a2864;
L_a2934:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a2954;
    cpu->regs[30] = PB_BASE + 0xa2954ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a2954:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
}
