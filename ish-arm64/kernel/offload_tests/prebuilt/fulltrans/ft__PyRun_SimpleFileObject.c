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

void ft__PyRun_SimpleFileObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 112ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 2912ULL;
    cpu->regs[30] = PB_BASE + 0x1ddc6cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1a1c00ULL);
    if ((cpu->regs[0])==0) goto L_1de0c0;
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1ddc88;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_1ddc88:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[26] = PB_BASE + 0x293000ULL;
    cpu->regs[30] = PB_BASE + 0x1ddc94ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18fc40ULL);
    cpu->regs[21] = cpu->regs[26] + 824ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ddca4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xedfe0ULL);
    if ((cpu->regs[0])!=0) goto L_1de0b8;
    cpu->regs[30] = PB_BASE + 0x1ddcacULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1de0d8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ddcc0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1de0d8;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 840ULL;
    cpu->regs[30] = PB_BASE + 0x1ddcdcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1de0d8;
    cpu->regs[27] = 1ULL;
L_1ddce4:
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 856ULL;
    cpu->regs[30] = PB_BASE + 0x1ddcf0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1de008;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[4] = 1ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ddd10ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1de1e0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[28] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ddd30;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ddd30;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ddd30ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ddd30:
    if ((cpu->regs[28])!=0) goto L_1dded8;
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_1ddd7c;
    cpu->regs[30] = PB_BASE + 0x1ddd3cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1de260ULL);
    cpu->regs[21] = ((uint32_t)(cpu->regs[0] & 65535ULL));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddd48ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b4b0ULL);
    if ((cpu->regs[0])!=0) goto L_1ddd7c;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[0] = SP;
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ddd60ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b840ULL);
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_NE) goto L_1de0ac;
    PB_LDRH(cpu->regs[28], (SP + 0));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddd74ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7b480ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_EQ) goto L_1ddedc;
L_1ddd7c:
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2952ULL;
    cpu->regs[30] = PB_BASE + 0x1ddd8cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1dddb0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[2] + 1032ULL;
    cpu->regs[30] = PB_BASE + 0x1ddda4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1de3c0ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dde74;
L_1dddb0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[6] = cpu->regs[25];
    cpu->regs[5] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = 257ULL;
    cpu->regs[30] = PB_BASE + 0x1dddd0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1de58cULL);
    cpu->regs[20] = cpu->regs[0];
L_1dddd4:
    cpu->regs[30] = PB_BASE + 0x1dddd8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1e6da0ULL);
    if ((cpu->regs[20])==0) goto L_1dde98;
L_1ddddc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1dde58;
L_1ddde4:
    cpu->regs[21] = 0ULL;
L_1ddde8:
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_1dde10;
    cpu->regs[1] = cpu->regs[26] + 824ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1dddf8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1e9304ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1de0d0;
L_1dddfc:
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 840ULL;
    cpu->regs[30] = PB_BASE + 0x1dde0cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1e9304ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1de0c8;
L_1dde10:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1dde18ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
L_1dde1c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1de064;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_1dde58:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ddde4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1dde70ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ddde8;
L_1dde74:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = 42ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 920ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1dde94ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7b510ULL);
    goto L_1ddde8;
L_1dde98:
    cpu->regs[20] = cpu->tls_ptr;
L_1dde9c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ddeb0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1de058;
L_1ddeb0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1ddec0ULL; PB_CALL(23, cpu, tlb, cpu->regs[1]);
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    cpu->regs[1] = 1ULL;
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1dded4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1e7de0ULL);
    goto L_1ddde8;
L_1dded8:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_1ddee4;
L_1ddedc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddee4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7b1c0ULL);
L_1ddee4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2704ULL;
    cpu->regs[30] = PB_BASE + 0x1ddef4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1dd228ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ddfe8;
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 896ULL;
    cpu->regs[30] = PB_BASE + 0x1ddf10ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1de3c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1de010;
    cpu->regs[20] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1ddf2cULL; PB_CALL(28, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[24], (cpu->regs[20] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddf38ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xc412cULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1ddf40ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1de260ULL);
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_1de040;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddf50ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xc412cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddf58ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xc412cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddf60ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xc412cULL);
    cpu->regs[30] = PB_BASE + 0x1ddf64ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1de048;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddf70ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xd1018ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1de088;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3776));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1de088;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ddf94ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1ddfa8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1eaa48ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[20] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[25], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (FLAG_EQ) goto L_1de0e0;
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 48));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 33423360ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[2]));
    PB_STRW((cpu->regs[25] + 0), cpu->regs[1]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ddfe0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1de0f0;
L_1ddfe0:
    cpu->regs[30] = PB_BASE + 0x1ddfe4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1e6da0ULL);
    goto L_1ddddc;
L_1ddfe8:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = 31ULL;
    cpu->regs[0] = cpu->regs[0] + 864ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1de008ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7b510ULL);
L_1de008:
    cpu->regs[21] = 4294967295ULL;
    goto L_1ddde8;
L_1de010:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[2] = 42ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 920ULL;
    cpu->regs[21] = 4294967295ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1de034ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7b510ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1de03cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    goto L_1ddde8;
L_1de040:
    cpu->regs[30] = PB_BASE + 0x1de044ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1de06c;
L_1de048:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1de050ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    cpu->regs[30] = PB_BASE + 0x1de054ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1e6da0ULL);
    goto L_1dde9c;
L_1de058:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1de060ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ddeb0;
L_1de064:
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1de06cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1de06c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1de084ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1de048;
L_1de088:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de090ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1de0a8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1de048;
L_1de0ac:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1de0b4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7b480ULL);
    goto L_1ddd7c;
L_1de0b8:
    cpu->regs[27] = 0ULL;
    goto L_1ddce4;
L_1de0c0:
    cpu->regs[21] = 4294967295ULL;
    goto L_1dde1c;
L_1de0c8:
    cpu->regs[30] = PB_BASE + 0x1de0ccULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1dde10;
L_1de0d0:
    cpu->regs[30] = PB_BASE + 0x1de0d4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1dddfc;
L_1de0d8:
    cpu->regs[21] = 4294967295ULL;
    goto L_1dde10;
L_1de0e0:
    if (((cpu->regs[0] >> 31) & 1)) goto L_1dddd4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1dddd4;
L_1de0f0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de0f8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1dddd4;
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_1de118;
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1de118:
    cpu->regs[0] = 0ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])!=0) goto L_1de1b0;
L_1de144:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1de158;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de154ULL; PB_CALL(54, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1de178;
L_1de158:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_1de1d0;
L_1de160:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_1de188;
L_1de168:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])!=0) goto L_1de1c0;
L_1de170:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])!=0) goto L_1de198;
L_1de178:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1de188:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de190ULL; PB_CALL(55, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de168;
    goto L_1de178;
L_1de198:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1de1b0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1de1b8ULL; PB_CALL(56, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de144;
    goto L_1de178;
L_1de1c0:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de1c8ULL; PB_CALL(57, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de170;
    goto L_1de178;
L_1de1d0:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de1d8ULL; PB_CALL(58, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de160;
    goto L_1de178;
}
