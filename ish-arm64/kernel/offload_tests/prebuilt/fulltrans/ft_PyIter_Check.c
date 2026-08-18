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

void ft_PyIter_Check(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2208));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 224));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 28440ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x152e08ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_152e30;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_152e30:
    cpu->regs[30] = PB_BASE + 0x152e34ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
L_152e40:
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->tls_ptr;
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x152e74ULL; PB_CALL(3, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[2];
    PB_LDR(cpu->regs[22], (cpu->regs[24] + cpu->regs[0]));
    PB_STR((SP + 80), cpu->regs[25]);
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152ea4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe31ccULL);
    if ((cpu->regs[0])==0) goto L_153058;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 17) & 1)) goto L_152fb4;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_152fdc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    if (!((cpu->regs[1] >> 11) & 1)) goto L_152fe4;
L_152ecc:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 56));
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[3];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_153084;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_153008;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(SP, cpu->regs[0]);
    if (FLAG_LO) goto L_153084;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + cpu->regs[3]));
    if ((cpu->regs[4])==0) goto L_152fe4;
L_152f04:
    cpu->regs[0] = PB_BASE + 0x11d000ULL;
    cpu->regs[0] = cpu->regs[0] + 1996ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_NE) goto L_153014;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x152f28ULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + cpu->regs[0]));
    cpu->regs[4] = cpu->regs[20] & 9223372036854775807ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 48));
    if (!((cpu->regs[1] >> 0) & 1)) goto L_153088;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152f4cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152f60ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe8888ULL);
    cpu->regs[20] = cpu->regs[0];
L_152f64:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_152f78;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_153078;
L_152f78:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_153004;
    PB_LDR(cpu->regs[25], (SP + 80));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_152fb4:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 272));
    if ((cpu->regs[3])!=0) goto L_153044;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_152fcc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_152fcc:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[21] = cpu->regs[21] + 8ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
L_152fdc:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 11) & 1)) goto L_152ecc;
L_152fe4:
    cpu->regs[3] = cpu->regs[20] & 9223372036854775807ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152ffcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xea120ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_152f64;
L_153004:
    cpu->regs[30] = PB_BASE + 0x153008ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c170ULL);
L_153008:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    if ((cpu->regs[4])!=0) goto L_152f04;
    goto L_152fe4;
L_153014:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x153028ULL; PB_CALL(10, cpu, tlb, cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0];
L_15302c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15303cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe8888ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_152f64;
L_153044:
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x153050ULL; PB_CALL(12, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_152fcc;
L_153058:
    cpu->regs[30] = PB_BASE + 0x15305cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_153068;
    cpu->regs[20] = 0ULL;
    goto L_152f78;
L_153068:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x153074ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c598ULL);
    goto L_152f78;
L_153078:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x153080ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_152f78;
L_153084:
    __builtin_trap();
L_153088:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15309cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[2] = cpu->regs[0];
    goto L_15302c;
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])!=0) goto L_1531dc;
    if (((cpu->regs[20] >> 63) & 1)) goto L_15322c;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_1532fc;
    if ((cpu->regs[20])==0) goto L_1531cc;
L_1530f4:
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 0));
    if ((cpu->regs[19])==0) goto L_153170;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_153298;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x153114ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_153264;
    cpu->regs[30] = PB_BASE + 0x153120ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1532e0;
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_NE) goto L_153170;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1531d8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 0ULL;
L_15315c:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x146d68ULL); return; };
L_153170:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1532bc;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x153188ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_153264;
    cpu->regs[30] = PB_BASE + 0x153194ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1532e0;
L_1531a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1531d8;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    goto L_15315c;
L_1531cc:
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_1531a0;
L_1531d8:
    cpu->regs[30] = PB_BASE + 0x1531dcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1531dc:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[20] + cpu->regs[19];
L_1531e4:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 872ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x153218ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_153264;
    if ((cpu->regs[19])==0) goto L_1531cc;
    cpu->regs[20] = cpu->regs[19];
    goto L_1530f4;
L_15322c:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[4] + 872ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15325cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1530f4;
L_153264:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1531d8;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_153298:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x1532b8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_153264;
L_1532bc:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x1532dcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_153264;
L_1532e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1532f8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_153264;
L_1532fc:
    cpu->regs[19] = cpu->regs[20];
    goto L_1531e4;
    SP = SP - 176ULL;
    cpu->regs[4] = 31823ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0x4f4fULL & 0xffff) << 16);
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 32)) | ((0x3aULL & 0xffff) << 32);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[20] = 9223372036854775807ULL;
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 160), cpu->regs[23]);
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    cpu->regs[2] = 44ULL;
    cpu->regs[23] = SP + 48ULL;
    cpu->regs[0] = SP + 53ULL;
    PB_STR((SP + 24), cpu->regs[20]); PB_STR((SP + 24) + 8, cpu->regs[19]);
    PB_STR((SP + 40), cpu->regs[19]);
    PB_STR((SP + 48), cpu->regs[4]); PB_STR((SP + 48) + 8, cpu->regs[5]);
    PB_STR((SP + 64), 0ULL); PB_STR((SP + 64) + 8, 0ULL);
    PB_STR((SP + 80), 0ULL); PB_STR((SP + 80) + 8, 0ULL);
    PB_STRH((SP + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x153384ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[4] = SP + 40ULL;
    cpu->regs[3] = SP + 32ULL;
    cpu->regs[2] = SP + 16ULL;
    PB_STRB((SP + 97), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1533a0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_153548;
    PB_LDR(cpu->regs[1], (SP + 32));
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_EQ) goto L_153484;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1533c8ULL; PB_CALL(30, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 96));
    PB_LDR(cpu->regs[22], (cpu->regs[2] + cpu->regs[0]));
    if ((cpu->regs[3])==0) goto L_153554;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 264));
    if ((cpu->regs[0])==0) goto L_153554;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1533e8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_153538;
    PB_LDR(cpu->regs[0], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_153498;
    cpu->regs[3] = cpu->regs[20];
L_153404:
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 168));
    if (!((cpu->regs[4] >> 28) & 1)) goto L_153578;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x153420ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1481a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_153548;
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_1534b4;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_153450:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_153550;
    PB_LDR(cpu->regs[23], (SP + 160));
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    SP = SP + 176ULL;
    return;
L_153484:
    cpu->regs[2] = 0ULL;
L_153488:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[3] = 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_153404;
L_153498:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1534a4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x146a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_153548;
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[3], (SP + 24));
    goto L_153404;
L_1534b4:
    if (((cpu->regs[0] >> 63) & 1)) goto L_15352c;
    cpu->regs[22] = 0ULL;
L_1534bc:
    cpu->regs[21] = cpu->regs[19] >> 30;
    if ((cpu->regs[21])!=0) goto L_15351c;
    cpu->regs[20] = 1ULL;
L_1534c8:
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1534d4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_153548;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    cpu->regs[2] = 4294967295ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : (0ULL + 1);
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[2]);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[20] = cpu->regs[1] | (cpu->regs[20] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]);
    if ((cpu->regs[21])==0) goto L_153450;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 28), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[19] >> 60;
    if ((cpu->regs[19])==0) goto L_153450;
    PB_STRW((cpu->regs[0] + 32), cpu->regs[19]);
    goto L_153450;
L_15351c:
    FLAG_CMP(0ULL, cpu->regs[19]);
    cpu->regs[20] = (FLAG_NE) ? 1 : 0;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 2ULL));
    goto L_1534c8;
L_15352c:
    cpu->regs[19] = (uint64_t)(-(int64_t)cpu->regs[0]);
    cpu->regs[22] = 1ULL;
    goto L_1534bc;
L_153538:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 96));
    if ((cpu->regs[0])==0) goto L_153488;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_153488;
L_153548:
    cpu->regs[0] = 0ULL;
    goto L_153450;
L_153550:
    cpu->regs[30] = PB_BASE + 0x153554ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7c170ULL);
L_153554:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2680ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x153570ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 0ULL;
    goto L_153450;
L_153578:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x153594ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_153450;
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])!=0) goto L_153708;
    if (((cpu->regs[20] >> 63) & 1)) goto L_153764;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_1537dc;
    if ((cpu->regs[20])==0) goto L_153758;
L_1535f0:
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 0));
    if ((cpu->regs[19])==0) goto L_15366c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1537a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x153610ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1536e8;
    cpu->regs[30] = PB_BASE + 0x15361cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1537e4;
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_NE) goto L_15366c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_153704;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 0ULL;
L_153658:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0x153800ULL); return; };
L_15366c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1536c8;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x153684ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1536e8;
    cpu->regs[30] = PB_BASE + 0x153690ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1537e4;
L_15369c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_153704;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    goto L_153658;
L_1536c8:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = cpu->regs[0] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0x1536e8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x23b310ULL);
L_1536e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_1537c4;
L_153704:
    cpu->regs[30] = PB_BASE + 0x153708ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x7c170ULL);
L_153708:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[20] + cpu->regs[19];
L_153710:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 944ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x153744ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1536e8;
    if ((cpu->regs[19])==0) goto L_153758;
    cpu->regs[20] = cpu->regs[19];
    goto L_1535f0;
L_153758:
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_15369c;
L_153764:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[4] + 944ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x153794ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1535f0;
    goto L_1536e8;
L_1537a0:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0x1537c0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_1536e8;
L_1537c4:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1537dc:
    cpu->regs[19] = cpu->regs[20];
    goto L_153710;
L_1537e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1537fcULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1536e8;
}
