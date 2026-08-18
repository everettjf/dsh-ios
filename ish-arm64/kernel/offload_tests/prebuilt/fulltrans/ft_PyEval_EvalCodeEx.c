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

void ft_PyEval_EvalCodeEx(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 208ULL;
    cpu->regs[9] = cpu->tls_ptr;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[6];
    PB_STR((SP + 160), cpu->regs[23]); PB_STR((SP + 160) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[10], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa302cULL; PB_CALL(1, cpu, tlb, cpu->regs[10]);
    PB_STR((SP + 176), cpu->regs[25]); PB_STR((SP + 176) + 8, cpu->regs[26]);
    cpu->regs[23] = cpu->regs[1];
    do { int32_t _s=0; tlb_read(tlb,(SP + 208),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_STR((SP + 192), cpu->regs[27]); PB_STR((SP + 192) + 8, cpu->regs[28]);
    cpu->regs[26] = cpu->regs[3];
    cpu->regs[27] = cpu->regs[5];
    PB_LDR(cpu->regs[0], (cpu->regs[9] + cpu->regs[0]));
    PB_STR((SP + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 216));
    PB_STR((SP + 8), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 224));
    PB_STR((SP + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[7];
    PB_LDR(cpu->regs[2], (cpu->regs[8] + 0));
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa3070ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdc780ULL);
    if ((cpu->regs[0])==0) goto L_a30b0;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0xa3084ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1965ccULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a30b8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a30b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a30b0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xa30b0ULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
L_a30b0:
    cpu->regs[23] = 0ULL;
    goto L_a3264;
L_a30b8:
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[20] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[23];
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_a3158;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    cpu->regs[30] = PB_BASE + 0xa30ccULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a3234;
    cpu->regs[0] = ((uint32_t)(cpu->regs[22] + cpu->regs[21]));
    cpu->regs[0] = (((uint64_t)(((int64_t)(cpu->regs[0] << 32)) >> 32) & 0xffffffffULL) << 3);
    cpu->regs[30] = PB_BASE + 0xa30e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a31f8;
    cpu->regs[0] = 0ULL;
L_a30ec:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_a3104;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + (cpu->regs[0] << 3)));
    PB_STR((cpu->regs[3] + (cpu->regs[0] << 3)), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_a30ec;
L_a3104:
    cpu->regs[7] = cpu->regs[28] + 24ULL;
    cpu->regs[0] = 0ULL;
L_a310c:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_a314c;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] << 1));
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[27] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_a3130;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
L_a3130:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[21] + cpu->regs[4]));
    PB_STR((cpu->regs[7] + (cpu->regs[0] << 3)), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_STR((cpu->regs[3] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3)), cpu->regs[1]);
    goto L_a310c;
L_a314c:
    cpu->regs[22] = cpu->regs[28];
    cpu->regs[28] = cpu->regs[3];
    goto L_a3164;
L_a3158:
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[28] = 0ULL;
    cpu->regs[22] = 0ULL;
L_a3164:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 120));
    PB_STR((SP + 48), cpu->regs[1]); PB_STR((SP + 48) + 8, cpu->regs[1]);
    cpu->regs[0] = SP + 32ULL;
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_STR((SP + 80), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_STR((SP + 24), cpu->regs[3]);
    PB_STR((SP + 32), cpu->regs[23]); PB_STR((SP + 32) + 8, cpu->regs[25]);
    PB_STR((SP + 64), cpu->regs[24]); PB_STR((SP + 64) + 8, cpu->regs[19]);
    PB_STR((SP + 88), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xa3190ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x19668cULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a31e8;
    PB_LDR(cpu->regs[3], (SP + 24));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[4] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    cpu->regs[5] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa31b4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_a31c8;
L_a31c0:
    cpu->regs[23] = cpu->regs[20];
    goto L_a31e8;
L_a31c8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a31c0;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xa31e4ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
    goto L_a31c0;
L_a31e8:
    if ((cpu->regs[22])==0) goto L_a3238;
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[28] = cpu->regs[22];
    goto L_a31fc;
L_a31f8:
    cpu->regs[23] = 0ULL;
L_a31fc:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a320c;
L_a3204:
    cpu->regs[28] = cpu->regs[3];
    goto L_a3238;
L_a320c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a3204;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 8));
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[28];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xa322cULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[3], (SP + 0));
    goto L_a3204;
L_a3234:
    cpu->regs[23] = 0ULL;
L_a3238:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xa3240ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a3264;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a3264;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xa3264ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
L_a3264:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a3284;
    cpu->regs[30] = PB_BASE + 0xa3284ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a3284:
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    PB_LDR(cpu->regs[23], (SP + 160)); PB_LDR(cpu->regs[24], (SP + 160) + 8);
    PB_LDR(cpu->regs[25], (SP + 176)); PB_LDR(cpu->regs[26], (SP + 176) + 8);
    PB_LDR(cpu->regs[27], (SP + 192)); PB_LDR(cpu->regs[28], (SP + 192) + 8);
    SP = SP + 208ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_a3334;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_a3334;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a32e8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a32e8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_a3318;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa32f8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_a3308;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa3308ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x197f6cULL);
L_a3308:
    cpu->regs[30] = PB_BASE + 0xa330cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a3318;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa3318ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_a3318:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a3334;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a3334;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa3334ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a3334:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
