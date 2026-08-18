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

void ft__PyUnicode_FormatLong(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[1] = 2147483644ULL;
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_STR((SP + 112), cpu->regs[27]);
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_225aa4;
    cpu->regs[25] = ((uint32_t)(cpu->regs[3] - 88ULL));
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = 4096ULL;
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x2002ULL & 0xffff) << 16);
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[25] & 63);
    FLAG_CMP((cpu->regs[2]) & (cpu->regs[1]), 0);
    if (FLAG_EQ) goto L_2258f4;
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x2257d4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x225bf0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[22] = 0ULL;
L_2257dc:
    PB_STR((SP + 16), cpu->regs[19]);
    if ((cpu->regs[19])==0) goto L_2259b8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_225acc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_225ac4;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[20] = cpu->regs[19] + 56ULL;
    cpu->regs[0] = cpu->regs[19] + 40ULL;
    cpu->regs[20] = (FLAG_EQ) ? cpu->regs[20] : cpu->regs[0];
L_225808:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = 2147483647ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_225994;
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[27] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(45ULL)));
    cpu->regs[22] = ((uint32_t)((FLAG_EQ) ? (cpu->regs[22] + 1) : cpu->regs[22]));
    cpu->regs[26] = ((uint32_t)(cpu->regs[0] - cpu->regs[22]));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_225840;
    cpu->regs[1] = 4294967297ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x80ULL & 0xffff) << 16);
    cpu->regs[1] = cpu->regs[1] >> (cpu->regs[25] & 63);
    if (((cpu->regs[1] >> 0) & 1)) goto L_2258d8;
L_225840:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[23] = cpu->regs[22];
L_225848:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_GT) goto L_2259c8;
L_225854:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(88ULL)));
    if (FLAG_EQ) goto L_225940;
L_22585c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_225910;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_225af0;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[19] + 40ULL;
    cpu->regs[0] = cpu->regs[19] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_225884:
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_225910;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_225a0c;
L_225898:
    cpu->regs[0] = cpu->regs[19];
L_22589c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_225984;
    PB_LDR(cpu->regs[27], (SP + 112));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_2258d8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 2ULL));
    cpu->regs[23] = ((uint32_t)(cpu->regs[22] - 2ULL));
    cpu->regs[0] = cpu->regs[20] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(45ULL)));
    if (FLAG_EQ) goto L_225988;
    cpu->regs[20] = cpu->regs[0];
    goto L_225848;
L_2258f4:
    FLAG_CMP((cpu->regs[2]) & (4294967297ULL), 0);
    if (FLAG_EQ) goto L_225970;
    cpu->regs[1] = 16ULL;
    cpu->regs[22] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x225908ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x225bf0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_2257dc;
L_225910:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x225918ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe9b80ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((SP + 16), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2259c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_225938;
L_225930:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x225938ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_225938:
    PB_LDR(cpu->regs[19], (SP + 16));
    goto L_225898;
L_225940:
    cpu->regs[0] = 0ULL;
L_225944:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_22585c;
    PB_LDRB(cpu->regs[3], (cpu->regs[20] + cpu->regs[0]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - 97ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(23ULL)));
    if (FLAG_HI) goto L_225968;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 32ULL));
    PB_STRB((cpu->regs[20] + cpu->regs[0]), cpu->regs[3]);
L_225968:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_225944;
L_225970:
    cpu->regs[1] = 8ULL;
    cpu->regs[22] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x22597cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x225bf0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_2257dc;
L_225984:
    cpu->regs[30] = PB_BASE + 0x225988ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_225988:
    PB_STRB((cpu->regs[20] + 2), cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    goto L_225848;
L_225994:
    PB_STR((cpu->regs[19] + 0), 0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2259a0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 3664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2259b8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2259b8:
    cpu->regs[0] = 0ULL;
    goto L_22589c;
L_2259c0:
    cpu->regs[19] = cpu->regs[0];
    goto L_225898;
L_2259c8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[23] + cpu->regs[21]));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x2259dcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[0])==0) goto L_225a44;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    cpu->regs[25] = cpu->regs[0] + 32ULL;
    cpu->regs[0] = 0ULL;
L_2259f4:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LE) goto L_225a70;
    PB_LDRB(cpu->regs[4], (cpu->regs[20] + cpu->regs[0]));
    PB_STRB((cpu->regs[25] + cpu->regs[0]), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_2259f4;
L_225a0c:
    cpu->regs[0] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x225a14ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x9c964ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_225898;
    if ((cpu->regs[19])==0) goto L_225898;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 16), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_225a68;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_225930;
    PB_LDR(cpu->regs[19], (SP + 16));
    goto L_225898;
L_225a44:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2259b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2259b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x225a60ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_22589c;
L_225a68:
    cpu->regs[19] = 0ULL;
    goto L_225898;
L_225a70:
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] - cpu->regs[27]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[23] & ~(((uint64_t)((int64_t)cpu->regs[23] >> 31)))));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[22]));
    cpu->regs[4] = 0ULL;
    cpu->regs[20] = cpu->regs[20] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[2] = cpu->regs[25] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[6] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[5] = 48ULL;
L_225a90:
    FLAG_CMP(cpu->regs[6], cpu->regs[4]);
    if (FLAG_LE) goto L_225af8;
    PB_STRB((cpu->regs[4] + cpu->regs[2]), cpu->regs[5]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_225a90;
L_225aa4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 3640ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x225abcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_22589c;
L_225ac4:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 56));
    goto L_225808;
L_225acc:
    if (((cpu->regs[0] >> 31) & 1)) goto L_225ad8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
L_225ad8:
    cpu->regs[0] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = 13910ULL;
    cpu->regs[0] = cpu->regs[0] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x225ae8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_22589c;
L_225af0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    goto L_225884;
L_225af8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & ~(((uint64_t)((int64_t)cpu->regs[0] >> 31)))));
    cpu->regs[5] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[2] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
L_225b08:
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_LE) goto L_225b20;
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[4]));
    PB_STRB((cpu->regs[0] + cpu->regs[4]), cpu->regs[2]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_225b08;
L_225b20:
    cpu->regs[26] = ((uint32_t)(cpu->regs[26] & ~(((uint64_t)((int64_t)cpu->regs[26] >> 31)))));
    PB_STRB((cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]))), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 16), cpu->regs[3]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_225b40;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_225b48;
L_225b40:
    cpu->regs[20] = cpu->regs[25];
    goto L_225854;
L_225b48:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x225b54ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[20] = cpu->regs[25];
    PB_LDR(cpu->regs[1], (SP + 8));
    goto L_225854;
}
