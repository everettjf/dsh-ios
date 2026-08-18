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

void ft_PyUnicode_Find(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_b2f5c:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xb2f8cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2fcc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0xb2f9cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b2fcc;
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x1481a0ULL); return; };
L_b2fcc:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 18446744073709551614ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_b2fe4:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0xb3008ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x2560f0ULL);
    if ((cpu->regs[0])==0) goto L_b3198;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 0ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[4] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + (16ULL << 12);
    cpu->regs[3] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0xb3030ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xb2f5cULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[0] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 2064ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb3054ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b3074;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b3198;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b3198;
    goto L_b309c;
L_b3074:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb3080ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x120700ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b30a8;
    if (((cpu->regs[2] >> 31) & 1)) goto L_b3198;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_b3198;
L_b309c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb30a4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b3198;
L_b30a8:
    if (((cpu->regs[2] >> 31) & 1)) goto L_b30c0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_b30c0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb30c0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b30c0:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_b30d8;
L_b30cc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])!=0) goto L_b3144;
    goto L_b3178;
L_b30d8:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(114ULL)));
    if (FLAG_EQ) goto L_b310c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(115ULL)));
    if (FLAG_EQ) goto L_b3118;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(97ULL)));
    if (FLAG_EQ) goto L_b3124;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb3108ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b3198;
L_b310c:
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[2] + 224ULL;
    goto L_b312c;
L_b3118:
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[2] + 232ULL;
    goto L_b312c;
L_b3124:
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[2] + 216ULL;
L_b312c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0xb3138ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b30cc;
    goto L_b3198;
L_b3144:
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2216ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xb3158ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3198;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xb3170ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xb31acULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3198;
L_b3178:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[1] = cpu->regs[1] + 2072ULL;
    cpu->regs[2] = 18446744073709551615ULL;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x1200e8ULL); return; };
L_b3198:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_b31ac:
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[1];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(19ULL)));
    if (FLAG_EQ) goto L_b3288;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_b31ec;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(18ULL)));
    if (FLAG_NE) goto L_b3294;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_b2fe4;
L_b31ec:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[19] + (16ULL << 12);
    cpu->regs[1] = cpu->regs[1] + 1552ULL;
    cpu->regs[2] = 24256ULL;
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[2] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xb3214ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7fa5cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b32ac;
    cpu->regs[1] = 24208ULL;
    cpu->regs[2] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[19] + (16ULL << 12);
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[1] = cpu->regs[1] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0xb3234ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7fa5cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b3254;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b3254;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb3254ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b3254:
    if ((cpu->regs[19])==0) goto L_b32ac;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb3264ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x120700ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b32b0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b32b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb3284ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b32b0;
L_b3288:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    goto L_b32c4;
L_b3294:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 272ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb32acULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_b32ac:
    cpu->regs[20] = 4294967295ULL;
L_b32b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_b32c4:
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = SP;
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[23] = ((uint32_t)(cpu->regs[2] & 255ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0xb3308ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11cb84ULL);
    cpu->regs[1] = 256ULL;
    cpu->regs[0] = 1ULL;
    PB_STR((SP + 40), cpu->regs[1]);
    PB_STRB((SP + 52), cpu->regs[0]);
    if ((cpu->regs[19])==0) goto L_b3358;
    PB_LDR(cpu->regs[24], cpu->regs[19]); cpu->regs[19] += 16;
    cpu->regs[22] = 0ULL;
L_b3324:
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_LE) goto L_b3358;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + (cpu->regs[22] << 3)));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb333cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xb31acULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b3350;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb334cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7bef0ULL);
    goto L_b3368;
L_b3350:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_b3324;
L_b3358:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb3360ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11ce48ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b3370;
L_b3368:
    cpu->regs[19] = 4294967295ULL;
    goto L_b33d8;
L_b3370:
    if (((cpu->regs[23] >> 0) & 1)) goto L_b33ac;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x2b1000ULL;
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[1] = cpu->regs[1] + 2376ULL;
    cpu->regs[30] = PB_BASE + 0xb3388ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1200e8ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b33bc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb33a0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xb2d48ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[19] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_b33bc;
L_b33ac:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb33b8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x120700ULL);
    cpu->regs[19] = cpu->regs[0];
L_b33bc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b33d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b33d8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb33d8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b33d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b33f8;
    cpu->regs[30] = PB_BASE + 0xb33f8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b33f8:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_b3414:
    if ((cpu->regs[1])==0) goto L_b3564;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = PB_BASE + 0x29b000ULL;
    cpu->regs[24] = cpu->regs[24] + 2048ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = PB_BASE + 0x2a5000ULL;
    cpu->regs[25] = cpu->regs[25] + 312ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[1] + 0));
    PB_STR((SP + 80), cpu->regs[27]);
L_b3454:
    FLAG_CMP(cpu->regs[22], cpu->regs[26]);
    if (FLAG_GE) goto L_b353c;
    cpu->regs[3] = cpu->regs[20] + 16ULL;
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 328ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[3] + (cpu->regs[22] << 3)));
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xb3484ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3544;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb349cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x2561e4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3544;
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0xb34b8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3544;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xb34d0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x2561e4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3544;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_b3534;
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 0));
    cpu->regs[23] = 0ULL;
L_b34e8:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[23]);
    if (FLAG_LE) goto L_b3534;
    cpu->regs[30] = PB_BASE + 0xb3500ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1200e8ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[23] + 2ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 2ULL;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3544;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[3] << 3)));
    cpu->regs[30] = PB_BASE + 0xb3528ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x2561e4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b34e8;
    goto L_b3544;
L_b3534:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_b3454;
L_b353c:
    cpu->regs[0] = 0ULL;
    goto L_b3548;
L_b3544:
    cpu->regs[0] = 4294967295ULL;
L_b3548:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_b3564:
    cpu->regs[0] = 0ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 1208ULL;
    cpu->regs[30] = PB_BASE + 0xb3590ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b35e0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xb35a8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x2561e4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b35e0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb35bcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xb3414ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b35e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[1] + 192ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[2] = 18446744073709551615ULL;
    { PB_CALL(39, cpu, tlb, PB_BASE + 0x1200e8ULL); return; };
L_b35e0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xb360cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x120700ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b361c;
L_b3614:
    cpu->regs[0] = 4294967295ULL;
    goto L_b3660;
L_b361c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_b365c;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1656ULL;
    cpu->regs[2] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0xb3638ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b3614;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xb3650ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x2561e4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_b3660;
L_b365c:
    cpu->regs[0] = 0ULL;
L_b3660:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
