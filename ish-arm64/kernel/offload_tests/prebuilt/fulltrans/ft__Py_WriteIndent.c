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

void ft__Py_WriteIndent(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[2] + 3640ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = SP + 24ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 7));
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 24), cpu->regs[4]);
    PB_STRW((cpu->regs[20] + 7), cpu->regs[2]);
L_1e7d74:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1e7db0;
    cpu->regs[0] = 0ULL;
L_1e7d80:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1e7dac;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_1e7dac:
    cpu->regs[30] = PB_BASE + 0x1e7db0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e7db0:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(9ULL)));
    if (FLAG_GT) goto L_1e7dbc;
    PB_STRB((cpu->regs[20] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]))), 0ULL);
L_1e7dbc:
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e7dc8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e7d80;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] - 10ULL));
    goto L_1e7d74;
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1e7e1cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e8120ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    if ((cpu->regs[20])==0) goto L_1e7f80;
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1e7f90;
L_1e7e38:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e7e40ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x121b20ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e7e64;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1e7f98;
L_1e7e5c:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1e7e64:
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_1e810c;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[5] = 48696ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1e7e80ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d7540ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e80f8;
L_1e7e84:
    cpu->regs[4] = 48864ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1e7e94ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d7540ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e8060;
L_1e7e98:
    cpu->regs[3] = 48920ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1e7ea8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d7540ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e8054;
L_1e7eac:
    cpu->regs[2] = 48808ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1e7ebcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d7540ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e8074;
L_1e7ec0:
    cpu->regs[0] = 43496ULL;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1e7ed0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e806c;
L_1e7ed8:
    PB_LDR(cpu->regs[21], (SP + 8));
    if ((cpu->regs[21])==0) goto L_1e8080;
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[2] + 3752ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    cpu->regs[6] = cpu->regs[22];
    cpu->regs[5] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e7f08ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x181ea8ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e802c;
L_1e7f0c:
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 3ULL;
    PB_STR((SP + 16), cpu->regs[23]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1e7f24ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x192928ULL);
    if ((cpu->regs[0])==0) goto L_1e7fb8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1e7fa4;
L_1e7f30:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e7f38ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e7f40ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e7f48ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e7fa0;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0xdce4cULL); return; };
L_1e7f80:
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[23] = 0ULL;
    goto L_1e7f30;
L_1e7f90:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_1e7e38;
L_1e7f98:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1e7e5c;
L_1e7fa0:
    cpu->regs[30] = PB_BASE + 0x1e7fa4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e7fa4:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e7f30;
    cpu->regs[30] = PB_BASE + 0x1e7fb4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e7f30;
L_1e7fb8:
    cpu->regs[30] = PB_BASE + 0x1e7fbcULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1e8120ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3344));
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e7fd4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7b050ULL);
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 3656ULL;
    cpu->regs[30] = PB_BASE + 0x1e7fe0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xa8500ULL);
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e7ff0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7cdf4ULL);
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 3688ULL;
    cpu->regs[30] = PB_BASE + 0x1e7ffcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xa8500ULL);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e800cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7cdf4ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e7f30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e7f30;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1e8028ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e7f30;
L_1e802c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e803cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e8104;
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3776ULL;
    cpu->regs[30] = PB_BASE + 0x1e8050ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1fa220ULL);
    goto L_1e7f0c;
L_1e8054:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e805cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    goto L_1e7eac;
L_1e8060:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e8068ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    goto L_1e7e98;
L_1e806c:
    cpu->regs[30] = PB_BASE + 0x1e8070ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e7ed8;
L_1e8074:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e807cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    goto L_1e7ec0;
L_1e8080:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 3752ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    cpu->regs[6] = cpu->regs[22];
    cpu->regs[5] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e80acULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x181ea8ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e80d0;
L_1e80b0:
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 3720ULL;
    cpu->regs[30] = PB_BASE + 0x1e80bcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xa8500ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e80ccULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7cdf4ULL);
    goto L_1e7f30;
L_1e80d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e80e0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e8104;
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3776ULL;
    cpu->regs[30] = PB_BASE + 0x1e80f4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1fa220ULL);
    goto L_1e80b0;
L_1e80f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e8100ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    goto L_1e7e84;
L_1e8104:
    cpu->regs[30] = PB_BASE + 0x1e8108ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e7f30;
L_1e810c:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    goto L_1e7ec0;
    /* nop */
    /* nop */
L_1e8120:
    SP = SP - 32ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[0] = SP + 4ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e8148ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1e8180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e8154;
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0x1e8154ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1eaec4ULL);
L_1e8154:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e817c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_1e817c:
    cpu->regs[30] = PB_BASE + 0x1e8180ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7c170ULL);
}
