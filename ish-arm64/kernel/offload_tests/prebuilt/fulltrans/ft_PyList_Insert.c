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

void ft_PyList_Insert(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 25) & 1)) goto L_1c65b8;
    goto L_1c65e0;
L_1c65b8:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 311ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[29] = SP;
    cpu->regs[0] = cpu->regs[0] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x1c65d0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
L_1c65e0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    if ((cpu->regs[2])==0) goto L_1c6778;
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1c660cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe5550ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c679c;
    if (((cpu->regs[19] >> 63) & 1)) goto L_1c6790;
L_1c6618:
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    cpu->regs[3] = cpu->regs[21] - 1ULL;
    cpu->regs[6] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[21];
    PB_LDR(cpu->regs[4], (cpu->regs[22] + 24));
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_GT) goto L_1c673c;
    cpu->regs[5] = cpu->regs[4] + 8ULL;
    cpu->regs[1] = cpu->regs[3] - cpu->regs[6];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    cpu->regs[1] = cpu->regs[1] & 7ULL;
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[21] - 2ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_GT) goto L_1c673c;
    if ((cpu->regs[1])==0) goto L_1c66d4;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_1c66c0;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_1c66b4;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_1c66a8;
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_EQ) goto L_1c669c;
    FLAG_CMP(cpu->regs[1], 5ULL);
    if (FLAG_EQ) goto L_1c6690;
    FLAG_CMP(cpu->regs[1], 6ULL);
    if (FLAG_NE) goto L_1c6768;
L_1c6684:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
L_1c6690:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
L_1c669c:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
L_1c66a8:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
L_1c66b4:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
L_1c66c0:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_GT) goto L_1c673c;
L_1c66d4:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    cpu->regs[1] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[1] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[1] << 3)), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] - 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] - 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] - 4ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] - 5ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] - 6ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] - 7ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_LE) goto L_1c66d4;
L_1c673c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[6] = cpu->regs[6] << 3;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1c6750;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1c6750:
    PB_STR((cpu->regs[4] + cpu->regs[6]), cpu->regs[20]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_1c675c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1c6768:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + (cpu->regs[3] << 3)));
    PB_STR((cpu->regs[5] + (cpu->regs[3] << 3)), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    goto L_1c6684;
L_1c6778:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 285ULL;
    cpu->regs[0] = cpu->regs[0] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x1c6788ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1c675c;
L_1c6790:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[21];
    cpu->regs[19] = cpu->regs[19] & ~(((uint64_t)((int64_t)cpu->regs[19] >> 63)));
    goto L_1c6618;
L_1c679c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_1c675c;
    SP = SP - 160ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 12297829382473034410ULL;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 48)) | ((0x2aaaULL & 0xffff) << 48);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 16), cpu->regs[5]);
    PB_STR((SP + 32), 0ULL); PB_STR((SP + 32) + 8, 0ULL);
    FLAG_CMP(cpu->regs[27], cpu->regs[1]);
    if (FLAG_GT) goto L_1c6b28;
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1c6808ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1474c0ULL);
    cpu->regs[1] = cpu->regs[27] + (cpu->regs[27] << 1);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6814ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1474d0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c6b34;
    cpu->regs[24] = 0ULL;
    cpu->regs[28] = 4294912000ULL;
    FLAG_CMP(cpu->regs[27], 0ULL);
    if (FLAG_LE) goto L_1c68a8;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    goto L_1c684c;
L_1c6834:
    cpu->regs[0] = cpu->regs[23];
    PB_STRB(cpu->regs[0], cpu->regs[8]); cpu->regs[0] += 1;
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[27], cpu->regs[25]);
    if (FLAG_LE) goto L_1c68a4;
    cpu->regs[24] = cpu->regs[25];
L_1c684c:
    PB_LDRH(cpu->regs[8], (cpu->regs[22] + (cpu->regs[24] << 1)));
    cpu->regs[25] = cpu->regs[24] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_1c6834;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_1c68f4;
    cpu->regs[0] = ((uint32_t)(cpu->regs[8] + cpu->regs[28]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_1c691c;
    cpu->regs[1] = ((uint32_t)(cpu->regs[8] >> 12));
    cpu->regs[0] = ((cpu->regs[8] >> 6) & 0x3fULL);
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] & 63ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4294967264ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4294967168ULL));
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] | 4294967168ULL));
    cpu->regs[24] = cpu->regs[25];
    cpu->regs[23] = cpu->regs[23] + 3ULL;
    PB_STRB((cpu->regs[23] + -3), cpu->regs[1]);
    PB_STRB((cpu->regs[23] + -2), cpu->regs[0]);
    PB_STRB((cpu->regs[23] + -1), cpu->regs[8]);
L_1c689c:
    FLAG_CMP(cpu->regs[27], cpu->regs[25]);
    if (FLAG_GT) goto L_1c684c;
L_1c68a4:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
L_1c68a8:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x1c68b0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x1c68b8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
L_1c68bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1c6ae0;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
L_1c68f4:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = ((uint32_t)(cpu->regs[8] >> 6));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4294967232ULL));
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] & 63ULL));
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] | 4294967168ULL));
    cpu->regs[24] = cpu->regs[25];
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 2;
    PB_STRB((cpu->regs[23] + 1), cpu->regs[8]);
    cpu->regs[23] = cpu->regs[0];
    goto L_1c689c;
L_1c691c:
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_1c692c;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x1c6928ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1b2a10ULL);
    cpu->regs[20] = cpu->regs[0];
L_1c692c:
    FLAG_CMP(cpu->regs[25], cpu->regs[27]);
    if (FLAG_GE) goto L_1c6948;
    PB_LDRH(cpu->regs[0], (cpu->regs[22] + (cpu->regs[25] << 1)));
    cpu->regs[1] = 4294912000ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_1c69ec;
L_1c6948:
    FLAG_CMP(cpu->regs[25], cpu->regs[27]);
    cpu->regs[0] = (FLAG_LT) ? 1 : 0;
    PB_STRW((cpu->regs[19] + 28), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(6ULL)));
    if (FLAG_NE) goto L_1c69a0;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23];
L_1c6964:
    FLAG_CMP(cpu->regs[25], cpu->regs[2]);
    if (FLAG_LE) goto L_1c69d4;
    PB_LDRH(cpu->regs[0], (cpu->regs[22] + (cpu->regs[2] << 1)));
    cpu->regs[1] = cpu->regs[1] + 3ULL;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] & 63ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] >> 12));
    cpu->regs[0] = ((cpu->regs[0] >> 6) & 0x3fULL);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] | 4294967264ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4294967168ULL));
    PB_STRB((cpu->regs[1] + -3), cpu->regs[4]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | 4294967168ULL));
    PB_STRB((cpu->regs[1] + -2), cpu->regs[0]);
    PB_STRB((cpu->regs[1] + -1), cpu->regs[3]);
    goto L_1c6964;
L_1c69a0:
    if (FLAG_HI) goto L_1c6a9c;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1c6a64;
    cpu->regs[1] = 4294910848ULL;
L_1c69b0:
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_LE) goto L_1c69e4;
    PB_LDRH(cpu->regs[0], (cpu->regs[22] + (cpu->regs[24] << 1)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1c69f4;
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_STRB(cpu->regs[23], cpu->regs[0]); cpu->regs[23] += 1;
    goto L_1c69b0;
L_1c69d4:
    cpu->regs[0] = cpu->regs[25] - cpu->regs[24]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[0] << 1);
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[0] : 0ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
L_1c69e4:
    cpu->regs[24] = cpu->regs[25];
    goto L_1c689c;
L_1c69ec:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_1c692c;
L_1c69f4:
    cpu->regs[0] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[0] = SP + 32ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[3] = cpu->regs[0] + 104ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = cpu->regs[0] + 1576ULL;
    cpu->regs[7] = cpu->regs[25];
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[6] = cpu->regs[24];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x1c6a30ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x247d80ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1c6b40;
L_1c6a38:
    cpu->regs[26] = 0ULL;
L_1c6a3c:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1c6a44ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6a50ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x1c6a58ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_1c68bc;
L_1c6a64:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1c69f4;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_1c69e4;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_1c6aec;
    cpu->regs[24] = cpu->regs[25] - cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[23] = cpu->regs[23] + cpu->regs[24];
    cpu->regs[1] = 63ULL;
    cpu->regs[24] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c6a98ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7aee0ULL);
    goto L_1c689c;
L_1c6a9c:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(7ULL)));
    if (FLAG_NE) goto L_1c69f4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[24] - cpu->regs[25];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[0] << 1);
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[0];
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c6ad0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x247c00ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c6a38;
    cpu->regs[24] = cpu->regs[25];
    goto L_1c689c;
L_1c6ae0:
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1c6aecULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c6aec:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[24] - cpu->regs[25];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[0] << 1);
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[0];
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c6b18ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1e8848ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c6a38;
    cpu->regs[24] = cpu->regs[25];
    goto L_1c689c;
L_1c6b28:
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6b30ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_1c68bc;
L_1c6b34:
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    cpu->regs[23] = 0ULL;
    goto L_1c68bc;
L_1c6b40:
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[2] = cpu->regs[24] - cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[2] << 1);
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_LT) goto L_1c6bc8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[27]);
    cpu->regs[1] = (FLAG_LT) ? 1 : 0;
    PB_STRW((cpu->regs[19] + 28), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
L_1c6b6c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 27) & 1)) goto L_1c6c18;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_1c6bf0;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_1c6be8;
    cpu->regs[2] = cpu->regs[26] + 40ULL;
L_1c6b88:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6b98ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x240780ULL);
    cpu->regs[23] = cpu->regs[0];
L_1c6b9c:
    if ((cpu->regs[23])==0) goto L_1c6a3c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6bbc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c6bbc;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1c6bbcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1c6bbc:
    PB_LDR(cpu->regs[25], (SP + 48));
    cpu->regs[24] = cpu->regs[25];
    goto L_1c689c;
L_1c6bc8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 28), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6bdcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11db70ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1c6b6c;
    goto L_1c6a3c;
L_1c6be8:
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 56));
    goto L_1c6b88;
L_1c6bf0:
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[5] = cpu->regs[0] + 104ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[0] + 1576ULL;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c6c14ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x230848ULL);
    goto L_1c6a3c;
L_1c6c18:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[26] + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6c2cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x240780ULL);
    cpu->regs[23] = cpu->regs[0];
    goto L_1c6b9c;
    /* nop */
    /* nop */
    /* nop */
}
