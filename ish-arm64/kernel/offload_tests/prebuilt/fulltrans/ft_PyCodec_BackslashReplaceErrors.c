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

void ft_PyCodec_BackslashReplaceErrors(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3656));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x247560ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_247674;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247570ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x2479e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247900;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247580ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x247ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247900;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24758cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x247b50ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_247900;
    PB_LDR(cpu->regs[0], (SP + 24)); PB_LDR(cpu->regs[2], (SP + 24) + 8);
    cpu->regs[1] = 127ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] << 2;
    cpu->regs[30] = PB_BASE + 0x2475a8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_247964;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_24795c;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[1] + 56ULL;
    cpu->regs[0] = cpu->regs[1] + 40ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[0];
L_2475c8:
    PB_LDR(cpu->regs[4], (SP + 32));
    cpu->regs[9] = cpu->regs[19] + 32ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2576));
    cpu->regs[8] = 92ULL;
    cpu->regs[7] = 120ULL;
L_2475e0:
    PB_LDR(cpu->regs[0], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LE) goto L_247624;
    PB_LDRB(cpu->regs[3], (cpu->regs[9] + cpu->regs[4]));
    cpu->regs[2] = cpu->regs[2] + 4ULL;
    PB_STRB((cpu->regs[2] + -4), cpu->regs[8]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_STRB((cpu->regs[2] + -3), cpu->regs[7]);
    cpu->regs[0] = cpu->regs[3] & 15ULL;
    cpu->regs[3] = ((cpu->regs[3] >> 4) & 0xfULL);
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[6] + cpu->regs[3]));
    PB_STRB((cpu->regs[2] + -2), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    PB_STRB((cpu->regs[2] + -1), cpu->regs[0]);
    goto L_2475e0;
L_247624:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_247638;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_247988;
L_247638:
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    cpu->regs[30] = PB_BASE + 0x247648ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe3f40ULL);
L_247648:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_247820;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 128ULL;
    return;
L_247674:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3720));
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x247690ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_247930;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2476a0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x248268ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247950;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2476b0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x248364ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247950;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2476bcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x2483e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_247950;
L_2476c4:
    PB_LDR(cpu->regs[21], (SP + 24)); PB_LDR(cpu->regs[19], (SP + 24) + 8);
    cpu->regs[1] = 14757395258967641292ULL;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 48)) | ((0xcccULL & 0xffff) << 48);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[0] = cpu->regs[21] - cpu->regs[19];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_247908;
L_2476e4:
    cpu->regs[23] = 65535ULL;
L_2476e8:
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_LT) goto L_2477f4;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[1] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x2476fcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2478e0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_2478d8;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[19] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[1];
L_24771c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[26] = 92ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2576));
    cpu->regs[25] = 65535ULL;
    cpu->regs[24] = 117ULL;
L_247734:
    PB_LDR(cpu->regs[2], (SP + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_GT) goto L_247778;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_247754;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2478cc;
L_247754:
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    cpu->regs[30] = PB_BASE + 0x247768ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe3f40ULL);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_247648;
L_247778:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x247784ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x2483f0ULL);
    PB_STRB((cpu->regs[19] + 0), cpu->regs[26]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_HI) goto L_247854;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_24783c;
    PB_STRB((cpu->regs[19] + 1), cpu->regs[24]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] >> 12));
    cpu->regs[3] = ((cpu->regs[2] >> 8) & 0xfULL);
    cpu->regs[5] = cpu->regs[19] + 4ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[23];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[4]));
    PB_STRB((cpu->regs[19] + 2), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[3]));
    PB_STRB((cpu->regs[19] + 3), cpu->regs[0]);
L_2477c8:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = ((cpu->regs[2] >> 4) & 0xfULL);
    cpu->regs[19] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[2] & 15ULL;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    PB_STRB(cpu->regs[19], cpu->regs[0]); cpu->regs[19] += 2;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[2]));
    PB_STRB((cpu->regs[5] + 1), cpu->regs[0]);
    goto L_247734;
L_2477f4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x247800ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x2483f0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_247830;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(256ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[20] + 6ULL));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 4ULL));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[20] = (FLAG_LO) ? cpu->regs[20] : cpu->regs[0];
    goto L_2476e8;
L_247820:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x247830ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_247830:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 10ULL));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_2476e8;
L_24783c:
    cpu->regs[0] = 120ULL;
    cpu->regs[5] = cpu->regs[19] + 2ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2576));
    PB_STRB((cpu->regs[19] + 1), cpu->regs[0]);
    goto L_2477c8;
L_247854:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2576));
    cpu->regs[0] = 85ULL;
    PB_STRB((cpu->regs[19] + 1), cpu->regs[0]);
    cpu->regs[8] = ((uint32_t)(cpu->regs[2] >> 28));
    cpu->regs[7] = ((cpu->regs[2] >> 24) & 0xfULL);
    cpu->regs[6] = ((cpu->regs[2] >> 20) & 0xfULL);
    PB_LDR(cpu->regs[9], (cpu->regs[1] + 0));
    cpu->regs[4] = ((cpu->regs[2] >> 16) & 0xfULL);
    cpu->regs[3] = ((cpu->regs[2] >> 12) & 0xfULL);
    cpu->regs[0] = ((cpu->regs[2] >> 8) & 0xfULL);
    cpu->regs[5] = cpu->regs[19] + 8ULL;
    PB_LDRB(cpu->regs[8], (cpu->regs[9] + cpu->regs[8]));
    PB_STRB((cpu->regs[19] + 2), cpu->regs[8]);
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 0));
    PB_LDRB(cpu->regs[7], (cpu->regs[8] + cpu->regs[7]));
    PB_STRB((cpu->regs[19] + 3), cpu->regs[7]);
    PB_LDR(cpu->regs[7], (cpu->regs[1] + 0));
    PB_LDRB(cpu->regs[6], (cpu->regs[7] + cpu->regs[6]));
    PB_STRB((cpu->regs[19] + 4), cpu->regs[6]);
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 0));
    PB_LDRB(cpu->regs[4], (cpu->regs[6] + cpu->regs[4]));
    PB_STRB((cpu->regs[19] + 5), cpu->regs[4]);
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[4] + cpu->regs[3]));
    PB_STRB((cpu->regs[19] + 6), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    PB_STRB((cpu->regs[19] + 7), cpu->regs[0]);
    goto L_2477c8;
L_2478cc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2478d4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_247754;
L_2478d8:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 56));
    goto L_24771c;
L_2478e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2478f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_247914;
L_2478f4:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
L_247900:
    cpu->regs[0] = 0ULL;
    goto L_247648;
L_247908:
    cpu->regs[21] = cpu->regs[19] + cpu->regs[1];
    PB_STR((SP + 24), cpu->regs[21]);
    goto L_2476e4;
L_247914:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24791cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_247648;
L_247930:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4072));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x247944ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24799c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x247950ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xb26a4ULL);
L_247950:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
L_247954:
    cpu->regs[0] = 0ULL;
    goto L_247648;
L_24795c:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 56));
    goto L_2475c8;
L_247964:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_247900;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_247900;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247980ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_247648;
L_247988:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x247994ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    goto L_247638;
L_24799c:
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2479a8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x248268ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247950;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2479b8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x248364ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247950;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2479c4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7af60ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_2476c4;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    goto L_247954;
    /* nop */
    /* nop */
    /* nop */
}
