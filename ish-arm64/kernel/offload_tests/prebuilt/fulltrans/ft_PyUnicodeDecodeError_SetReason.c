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

void ft_PyUnicodeDecodeError_SetReason(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = cpu->regs[0] + 104ULL;
    goto L_247bb0;
L_247bb0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x247bc8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdea4cULL);
    if ((cpu->regs[0])==0) goto L_247bec;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x247bdcULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_247be0:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_247bec:
    cpu->regs[0] = 4294967295ULL;
    goto L_247be0;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32));
    cpu->regs[23] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_247d68;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[2] + 40ULL;
    cpu->regs[2] = cpu->regs[2] + 56ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[0];
L_247c40:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = 9223372036854775807ULL;
L_247c4c:
    FLAG_CMP(cpu->regs[2], cpu->regs[22]);
    if (FLAG_GE) goto L_247c94;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x247c60ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_247d60;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(99ULL)));
    if (FLAG_LS) goto L_247d58;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(999ULL)));
    if (FLAG_HI) goto L_247d20;
    cpu->regs[1] = 6ULL;
L_247c7c:
    cpu->regs[0] = cpu->regs[4] - cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LT) goto L_247cec;
    cpu->regs[3] = cpu->regs[3] + cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_247c4c;
L_247c94:
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x247ca4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11db70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_247d04;
    cpu->regs[24] = PB_BASE + 0x29a000ULL;
    cpu->regs[24] = cpu->regs[24] + 840ULL;
L_247cb4:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_GE) goto L_247d08;
    cpu->regs[30] = PB_BASE + 0x247cccULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x247ce0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7bff0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_247d04;
    cpu->regs[21] = cpu->regs[21] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    goto L_247cb4;
L_247cec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 440ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x247d04ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_247d04:
    cpu->regs[21] = 0ULL;
L_247d08:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_247d20:
    cpu->regs[1] = 9999ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LS) goto L_247d70;
    cpu->regs[7] = 34463ULL;
    cpu->regs[1] = 8ULL;
    cpu->regs[7] = (cpu->regs[7] & ~(0xffffULL << 16)) | ((0x1ULL & 0xffff) << 16);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[7])));
    if (FLAG_LS) goto L_247c7c;
    cpu->regs[1] = 16959ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    cpu->regs[1] = (FLAG_HI) ? 1 : 0;
    cpu->regs[1] = cpu->regs[1] + 9ULL;
    goto L_247c7c;
L_247d58:
    cpu->regs[1] = 5ULL;
    goto L_247c7c;
L_247d60:
    cpu->regs[1] = 4ULL;
    goto L_247c7c;
L_247d68:
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 56));
    goto L_247c40;
L_247d70:
    cpu->regs[1] = 7ULL;
    goto L_247c7c;
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    cpu->regs[26] = cpu->regs[6];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STR((SP + 96), cpu->regs[27]);
    PB_LDR(cpu->regs[20], (SP + 112));
    PB_LDR(cpu->regs[9], (cpu->regs[8] + 0));
    PB_STR((SP + 8), cpu->regs[9]);
    cpu->regs[9] = 0ULL;
    cpu->regs[27] = cpu->regs[7];
    if ((cpu->regs[1])!=0) goto L_247de8;
    cpu->regs[30] = PB_BASE + 0x247de0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d3208ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_247f0c;
L_247de8:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[5] = cpu->regs[25];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x247e08ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x230880ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if ((cpu->regs[1])==0) goto L_247f0c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x247e18ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_247f0c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_247f24;
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2776ULL;
    cpu->regs[2] = SP;
    cpu->regs[30] = PB_BASE + 0x247e40ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_247ef0;
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    FLAG_CMP((cpu->regs[1]) & (402653184ULL), 0);
    if (FLAG_EQ) goto L_247f24;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    if (((cpu->regs[2] >> 63) & 1)) goto L_247f18;
L_247e60:
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_GE) { FLAG_CMP(cpu->regs[2], cpu->regs[23]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_247ed8;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_247e7c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_247e7c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_247e9c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_247e9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247e98ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
L_247e9c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_247f14;
    PB_LDR(cpu->regs[27], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_247ed8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3560ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x247ef0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
L_247ef0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_247f0c;
L_247ef8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_247f0c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247f0cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_247f0c:
    cpu->regs[0] = 0ULL;
    goto L_247e9c;
L_247f14:
    cpu->regs[30] = PB_BASE + 0x247f18ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_247f18:
    cpu->regs[2] = cpu->regs[2] + cpu->regs[23];
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    goto L_247e60;
L_247f24:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2779ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x247f3cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_247ef8;
    goto L_247f0c;
    SP = SP - 112ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3720));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247f84ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2480a0;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247f94ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x248268ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24805c;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247fa4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x248364ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24805c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247fb0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x2483e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24805c;
    PB_LDR(cpu->regs[1], (SP + 0)); PB_LDR(cpu->regs[2], (SP + 0) + 8);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x247fccULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_248230;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = 4294910848ULL;
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x247fe4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1063e8ULL);
    PB_LDR(cpu->regs[24], (SP + 0));
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[24];
L_247ff0:
    PB_LDR(cpu->regs[2], (SP + 8));
    FLAG_CMP(cpu->regs[22], cpu->regs[2]);
    if (FLAG_GE) goto L_2481ac;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x248008ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x2483f0ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[23]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_248210;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x248020ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24803c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24803c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24803cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_24803c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_248050;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_248194;
L_248050:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96));
L_24805c:
    cpu->regs[19] = 0ULL;
L_248060:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_248090;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 112ULL;
    return;
L_248090:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x2480a0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2480a0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3656));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x2480b4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_248180;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2480c4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x2479e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24805c;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2480d4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x247ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24805c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2480e0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x247b50ULL);
    if ((cpu->regs[0])==0) goto L_24805c;
    PB_LDR(cpu->regs[2], (SP + 0)); PB_LDR(cpu->regs[3], (SP + 0) + 8);
    cpu->regs[7] = SP + 16ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[6] = 4294958080ULL;
    cpu->regs[4] = cpu->regs[2] + 32ULL;
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2];
    cpu->regs[4] = cpu->regs[0] + cpu->regs[4];
L_248100:
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_LE) goto L_248130;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[4] + cpu->regs[1]),&_s,1); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRB(cpu->regs[5], (cpu->regs[4] + cpu->regs[1]));
    if (!((cpu->regs[8] >> 31) & 1)) goto L_248130;
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] + cpu->regs[6]));
    PB_STRH((cpu->regs[7] + (cpu->regs[1] << 1)), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_NE) goto L_248100;
    cpu->regs[20] = cpu->regs[1];
L_248130:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_248144;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_24818c;
L_248144:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_248220;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x24815cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xefd20ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24805c;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    cpu->regs[2] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x248178ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_248060;
L_248180:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x248188ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xb26a4ULL);
    goto L_24805c;
L_24818c:
    cpu->regs[30] = PB_BASE + 0x248190ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_248144;
L_248194:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24819cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 96));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_24805c;
L_2481ac:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2840ULL;
    cpu->regs[30] = PB_BASE + 0x2481bcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe3f40ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_2481d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_24824c;
L_2481d4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2481e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2481f8;
L_2481e8:
    PB_LDR(cpu->regs[25], (SP + 96));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_248060;
L_2481f8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x248200ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 96));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_248060;
L_248210:
    cpu->regs[1] = cpu->regs[25] - cpu->regs[24];
    PB_STRB((cpu->regs[1] + cpu->regs[22]), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_247ff0;
L_248220:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24822cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    goto L_24805c;
L_248230:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_248244;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_248258;
L_248244:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_24805c;
L_24824c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x248254ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2481d4;
L_248258:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x248260ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_24805c;
}
