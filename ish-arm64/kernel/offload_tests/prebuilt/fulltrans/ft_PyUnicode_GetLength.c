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

void ft_PyUnicode_GetLength(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1e2694;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    return;
L_1e2694:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1e26a0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e27e8;
L_1e26d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e27d8;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = 8ULL;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e26ecULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e27b8;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1e27a0;
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 1ULL;
L_1e270c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2714ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e2540ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e2770;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1e272cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e27f0;
L_1e2734:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_GT) goto L_1e2788;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e2748ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_1e2748:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e275c:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1e2770:
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_EQ) goto L_1e2808;
L_1e2778:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[23] + (cpu->regs[24] << 3)), cpu->regs[21]);
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_1e270c;
L_1e2788:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[23] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1e2734;
L_1e27a0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1e275c;
L_1e27b8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e27c8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e275c;
L_1e27d8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e275c;
L_1e27e8:
    cpu->regs[30] = PB_BASE + 0x1e27ecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e26d4;
L_1e27f0:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e27f8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e2804ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_1e2748;
L_1e2808:
    cpu->regs[25] = cpu->regs[25] << 1;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[25] << 3;
    cpu->regs[30] = PB_BASE + 0x1e2818ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e27f0;
    cpu->regs[23] = cpu->regs[0];
    goto L_1e2778;
    SP = SP - 48ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1e28e0;
L_1e2858:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 944));
    if ((cpu->regs[0])==0) goto L_1e291c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 60520ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1e2874ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5800ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e291c;
L_1e287c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e288cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x112290ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e28a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e28d4;
L_1e28a0:
    PB_LDR(cpu->regs[0], (SP + 0));
L_1e28a4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1e28d0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1e28d0:
    cpu->regs[30] = PB_BASE + 0x1e28d4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e28d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e28dcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e28a0;
L_1e28e0:
    cpu->regs[30] = PB_BASE + 0x1e28e4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x2076a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2858;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = 60520ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1e28fcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x145e2cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e287c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2840));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e2914ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e291c;
    cpu->regs[30] = PB_BASE + 0x1e291cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_1e291c:
    cpu->regs[0] = 0ULL;
    goto L_1e28a4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e2c20;
L_1e294c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2c10;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[21] = cpu->regs[20];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2a94;
L_1e2968:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e2974ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e29d8;
L_1e2978:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
L_1e297c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2bfc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e2990ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2a44;
L_1e2994:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
L_1e2998:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2bfc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e29a8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1e2dacULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e2c28;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1e29b4:
    cpu->regs[4] = 0ULL;
L_1e29b8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e29c4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e29d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e29e0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1e1240ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2978;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e29f0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x217260ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2978;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2a00ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1e2dacULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    cpu->regs[3] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e297c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e2a1cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1a60ecULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e29b8;
L_1e2a24:
    cpu->regs[30] = PB_BASE + 0x1e2a28ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e29b4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e29c4;
L_1e2a44:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e2a50ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e2994;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2a5cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x252fc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2994;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2a6cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1e2dacULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    cpu->regs[3] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2998;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e2a88ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1a60ecULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e29b8;
    goto L_1e2a24;
L_1e2a94:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e2be0;
L_1e2aac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e2ab8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2c4c;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
L_1e2ac0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2bf0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e2ad4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2b98;
L_1e2ad8:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2bf0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e2af0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2b1c;
L_1e2af4:
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
L_1e2af8:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[5] - 1ULL));
L_1e2b00:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1e2968;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[4] = 0ULL;
    goto L_1e29c4;
L_1e2b1c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2b24ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xc8d70ULL);
    if ((cpu->regs[0])==0) goto L_1e2af4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2b30ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x217260ULL);
    if ((cpu->regs[0])==0) goto L_1e2af4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e2b40ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2af4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2b50ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xc8d70ULL);
    if ((cpu->regs[0])==0) goto L_1e2af4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 20),&_a,4); tlb_read(tlb,(cpu->regs[21] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3152ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 28),&_a,4); tlb_read(tlb,(cpu->regs[21] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
L_1e2b74:
    cpu->regs[30] = PB_BASE + 0x1e2b78ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1e2b7cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[5] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e2af8;
L_1e2b88:
    cpu->regs[0] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1e2b00;
L_1e2b98:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2ba0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1e1324ULL);
    if ((cpu->regs[0])==0) goto L_1e2ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x1e2bb0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2ad8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 24),&_a,4); tlb_read(tlb,(cpu->regs[2] + 28),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3096ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 20),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    goto L_1e2b74;
L_1e2be0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2be8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1e2c44;
L_1e2bf0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e2b00;
L_1e2bfc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e29c4;
L_1e2c10:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e29c4;
L_1e2c20:
    cpu->regs[30] = PB_BASE + 0x1e2c24ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e294c;
L_1e2c28:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e2c38ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1a60ecULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e29b8;
    goto L_1e2a24;
L_1e2c44:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_1e2aac;
L_1e2c4c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e2d48;
L_1e2c64:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2d38;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1e2c7cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2d30;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2d38;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e2c98ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2cb0;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
L_1e2ca4:
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[5]);
    goto L_1e2ac0;
L_1e2cb0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e2d54;
L_1e2cc8:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1e2d6c;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1e2ce0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e2d60;
L_1e2ce4:
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[5]);
L_1e2cf0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[5]);
    cpu->regs[3] = PB_BASE + 0x287000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[3] + 3184ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2d18ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[5] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e2da0;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1e29b8;
L_1e2d30:
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    goto L_1e2cf0;
L_1e2d38:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1e2ac0;
L_1e2d48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2d50ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e2c64;
L_1e2d54:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2d5cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e2cc8;
L_1e2d60:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1e2d7c;
L_1e2d6c:
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[5]);
    goto L_1e2ca4;
L_1e2d7c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x1e2d88ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2ce4;
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[5]);
    goto L_1e2ca4;
L_1e2da0:
    cpu->regs[30] = PB_BASE + 0x1e2da4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e2af8;
    goto L_1e2b88;
L_1e2dac:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e2ff0;
L_1e2dd4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2fd8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[20];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2e34;
L_1e2df0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x1e2dfcULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2e24;
L_1e2e00:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1e2e08:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e2e14:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e2e24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2e2cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1e1240ULL);
    if ((cpu->regs[0])!=0) goto L_1e2e08;
    goto L_1e2e00;
L_1e2e34:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e2f84;
L_1e2e4c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x1e2e58ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2fa0;
L_1e2e5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2f94;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x1e2e74ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2f30;
L_1e2e78:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2f94;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x1e2e90ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e2ebc;
L_1e2e94:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_1e2e98:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_1e2ea0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e2df0;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = 0ULL;
    goto L_1e2e14;
L_1e2ebc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2ec4ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1e1324ULL);
    if ((cpu->regs[0])==0) goto L_1e2e94;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e2ed4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e2e94;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2ee0ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x94bc0ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2e94;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3272ULL;
L_1e2efc:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 24),&_a,4); tlb_read(tlb,(cpu->regs[2] + 28),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 20),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
L_1e2f0c:
    cpu->regs[30] = PB_BASE + 0x1e2f10ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1e2f14ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e2e98;
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[2];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[2]);
    goto L_1e2ea0;
L_1e2f30:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2f38ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1e1324ULL);
    if ((cpu->regs[0])==0) goto L_1e2e78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e2f48ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e2e78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2f54ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2e78;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 28),&_a,4); tlb_read(tlb,(cpu->regs[2] + 32),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 3272ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 36),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 24),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    goto L_1e2f0c;
L_1e2f84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2f8cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e2fe8;
L_1e2f94:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e2ea0;
L_1e2fa0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2fa8ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1e1324ULL);
    if ((cpu->regs[0])==0) goto L_1e2e5c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x1e2fb8ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2e5c;
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = cpu->regs[6] + 3224ULL;
    goto L_1e2efc;
L_1e2fd8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e2e14;
L_1e2fe8:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_1e2e4c;
L_1e2ff0:
    cpu->regs[30] = PB_BASE + 0x1e2ff4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e2dd4;
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_1e3094;
    cpu->regs[30] = PB_BASE + 0x1e303cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1c4a70ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e3080;
L_1e3048:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    cpu->regs[19] = (FLAG_EQ) ? 1 : 0;
L_1e3050:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e3090;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_1e3080:
    cpu->regs[30] = PB_BASE + 0x1e3084ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e3048;
L_1e3088:
    cpu->regs[19] = 4294967295ULL;
    goto L_1e3050;
L_1e3090:
    cpu->regs[30] = PB_BASE + 0x1e3094ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e3094:
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 49824ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x1e30c4ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e3088;
    cpu->regs[30] = PB_BASE + 0x1e30d0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e3050;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e3050;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e30f0ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e3050;
    /* nop */
    /* nop */
    /* nop */
}
