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

void ft_PyCodec_NameReplaceErrors(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 384ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3720));
    PB_STR((SP + 288), cpu->regs[29]); PB_STR((SP + 288) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 288ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 304), cpu->regs[19]); PB_STR((SP + 304) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 280), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24eae0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_24ed14;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24eaf0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x248268ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24ed1c;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24eb00ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x248364ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24ed1c;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 320), cpu->regs[21]); PB_STR((SP + 320) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x24eb10ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x2483e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24ee7c;
    PB_STR((SP + 336), cpu->regs[23]); PB_STR((SP + 336) + 8, cpu->regs[24]);
    cpu->regs[24] = PB_BASE + 0x5ad000ULL;
    cpu->regs[19] = cpu->regs[24] + 4048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 232));
    if ((cpu->regs[0])==0) goto L_24ee54;
L_24eb2c:
    PB_LDR(cpu->regs[23], (SP + 16));
    cpu->regs[20] = SP + 24ULL;
    PB_STR((SP + 352), cpu->regs[25]); PB_STR((SP + 352) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[24] + 4048ULL;
    cpu->regs[21] = cpu->regs[23];
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = 65535ULL;
    PB_STR((SP + 368), cpu->regs[27]); PB_STR((SP + 368) + 8, cpu->regs[28]);
L_24eb4c:
    PB_LDR(cpu->regs[0], (SP + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_LE) goto L_24ebbc;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24eb64ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x2483f0ULL);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[4], (cpu->regs[26] + 232));
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 256ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 0));
    cpu->regs[30] = PB_BASE + 0x24eb80ULL; PB_CALL(6, cpu, tlb, cpu->regs[4]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24ee44;
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_HI) goto L_24ee3c;
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(255ULL)));
    cpu->regs[0] = 6ULL;
    cpu->regs[1] = 4ULL;
    cpu->regs[0] = (FLAG_HI) ? cpu->regs[0] : cpu->regs[1];
L_24eb9c:
    cpu->regs[1] = 9223372036854775807ULL;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = cpu->regs[1] - ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LT) goto L_24ebbc;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_24eb4c;
L_24ebbc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 127ULL;
    PB_STR((SP + 8), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x24ebccULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24ee24;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_24ee1c;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[19] = cpu->regs[0] + 56ULL;
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[2];
L_24ebec:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2576));
    cpu->regs[24] = cpu->regs[24] + 4048ULL;
    cpu->regs[26] = SP + 24ULL;
    cpu->regs[27] = 92ULL;
L_24ec00:
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_GT) goto L_24ec74;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    cpu->regs[30] = PB_BASE + 0x24ec1cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_24ec34;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_24ee00;
L_24ec34:
    PB_LDR(cpu->regs[21], (SP + 320)); PB_LDR(cpu->regs[22], (SP + 320) + 8);
    PB_LDR(cpu->regs[23], (SP + 336)); PB_LDR(cpu->regs[24], (SP + 336) + 8);
    PB_LDR(cpu->regs[25], (SP + 352)); PB_LDR(cpu->regs[26], (SP + 352) + 8);
    PB_LDR(cpu->regs[27], (SP + 368)); PB_LDR(cpu->regs[28], (SP + 368) + 8);
L_24ec44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 280));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24edec;
    PB_LDR(cpu->regs[29], (SP + 288)); PB_LDR(cpu->regs[30], (SP + 288) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 304)); PB_LDR(cpu->regs[20], (SP + 304) + 8);
    SP = SP + 384ULL;
    return;
L_24ec74:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24ec80ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x2483f0ULL);
    PB_STRB((cpu->regs[19] + 0), cpu->regs[27]);
    PB_LDR(cpu->regs[4], (cpu->regs[24] + 232));
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 256ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 0));
    cpu->regs[30] = PB_BASE + 0x24eca0ULL; PB_CALL(10, cpu, tlb, cpu->regs[4]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24edb4;
    cpu->regs[0] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_24ed3c;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_24ed24;
    cpu->regs[0] = 117ULL;
    PB_STRB((cpu->regs[19] + 1), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[20] >> 12));
    cpu->regs[2] = ((cpu->regs[20] >> 8) & 0xfULL);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[5] = cpu->regs[19] + 4ULL;
    cpu->regs[4] = cpu->regs[25];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[3]));
    PB_STRB((cpu->regs[19] + 2), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[2]));
    PB_STRB((cpu->regs[19] + 3), cpu->regs[0]);
L_24ece8:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    cpu->regs[0] = ((cpu->regs[20] >> 4) & 0xfULL);
    cpu->regs[19] = cpu->regs[5];
    cpu->regs[20] = cpu->regs[20] & 15ULL;
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_STRB(cpu->regs[19], cpu->regs[0]); cpu->regs[19] += 2;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[20]));
    PB_STRB((cpu->regs[5] + 1), cpu->regs[0]);
    goto L_24ec00;
L_24ed14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x24ed1cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xb26a4ULL);
L_24ed1c:
    cpu->regs[19] = 0ULL;
    goto L_24ec44;
L_24ed24:
    cpu->regs[0] = 120ULL;
    cpu->regs[5] = cpu->regs[19] + 2ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2576));
    PB_STRB((cpu->regs[19] + 1), cpu->regs[0]);
    goto L_24ece8;
L_24ed3c:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2576));
    cpu->regs[0] = 85ULL;
    PB_STRB((cpu->regs[19] + 1), cpu->regs[0]);
    cpu->regs[7] = ((uint32_t)(cpu->regs[20] >> 28));
    cpu->regs[6] = ((cpu->regs[20] >> 24) & 0xfULL);
    cpu->regs[3] = ((cpu->regs[20] >> 20) & 0xfULL);
    PB_LDR(cpu->regs[8], (cpu->regs[4] + 0));
    cpu->regs[2] = ((cpu->regs[20] >> 16) & 0xfULL);
    cpu->regs[1] = ((cpu->regs[20] >> 12) & 0xfULL);
    cpu->regs[0] = ((cpu->regs[20] >> 8) & 0xfULL);
    cpu->regs[5] = cpu->regs[19] + 8ULL;
    PB_LDRB(cpu->regs[7], (cpu->regs[8] + cpu->regs[7]));
    PB_STRB((cpu->regs[19] + 2), cpu->regs[7]);
    PB_LDR(cpu->regs[7], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[6], (cpu->regs[7] + cpu->regs[6]));
    PB_STRB((cpu->regs[19] + 3), cpu->regs[6]);
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[6] + cpu->regs[3]));
    PB_STRB((cpu->regs[19] + 4), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[2]));
    PB_STRB((cpu->regs[19] + 5), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + cpu->regs[1]));
    PB_STRB((cpu->regs[19] + 6), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_STRB((cpu->regs[19] + 7), cpu->regs[0]);
    goto L_24ece8;
L_24edb4:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = 31566ULL;
    PB_STRH((cpu->regs[19] + 1), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[19] + 3ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x24edd0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b130ULL);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x24edd8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[19] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[1] = 125ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_STRB((cpu->regs[20] + cpu->regs[0]), cpu->regs[1]);
    goto L_24ec00;
L_24edec:
    PB_STR((SP + 320), cpu->regs[21]); PB_STR((SP + 320) + 8, cpu->regs[22]);
    PB_STR((SP + 336), cpu->regs[23]); PB_STR((SP + 336) + 8, cpu->regs[24]);
    PB_STR((SP + 352), cpu->regs[25]); PB_STR((SP + 352) + 8, cpu->regs[26]);
    PB_STR((SP + 368), cpu->regs[27]); PB_STR((SP + 368) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x24ee00ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24ee00:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24ee08ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 320)); PB_LDR(cpu->regs[22], (SP + 320) + 8);
    PB_LDR(cpu->regs[23], (SP + 336)); PB_LDR(cpu->regs[24], (SP + 336) + 8);
    PB_LDR(cpu->regs[25], (SP + 352)); PB_LDR(cpu->regs[26], (SP + 352) + 8);
    PB_LDR(cpu->regs[27], (SP + 368)); PB_LDR(cpu->regs[28], (SP + 368) + 8);
    goto L_24ec44;
L_24ee1c:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 56));
    goto L_24ebec;
L_24ee24:
    PB_LDR(cpu->regs[21], (SP + 320)); PB_LDR(cpu->regs[22], (SP + 320) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 336)); PB_LDR(cpu->regs[24], (SP + 336) + 8);
    PB_LDR(cpu->regs[25], (SP + 352)); PB_LDR(cpu->regs[26], (SP + 352) + 8);
    PB_LDR(cpu->regs[27], (SP + 368)); PB_LDR(cpu->regs[28], (SP + 368) + 8);
    goto L_24ec44;
L_24ee3c:
    cpu->regs[0] = 10ULL;
    goto L_24eb9c;
L_24ee44:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24ee4cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 4ULL));
    goto L_24eb9c;
L_24ee54:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0x24ee64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x2236a0ULL);
    PB_STR((cpu->regs[19] + 232), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24eb2c;
    PB_LDR(cpu->regs[21], (SP + 320)); PB_LDR(cpu->regs[22], (SP + 320) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 336)); PB_LDR(cpu->regs[24], (SP + 336) + 8);
    goto L_24ec44;
L_24ee7c:
    PB_LDR(cpu->regs[21], (SP + 320)); PB_LDR(cpu->regs[22], (SP + 320) + 8);
    cpu->regs[19] = 0ULL;
    goto L_24ec44;
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(18, cpu, tlb, PB_BASE + 0x24ee90ULL); return; };
}
