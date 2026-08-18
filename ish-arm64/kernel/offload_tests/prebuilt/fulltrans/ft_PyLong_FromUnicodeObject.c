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

void ft_PyLong_FromUnicodeObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 96ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1fe0a8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1647a4ULL);
    if ((cpu->regs[0])==0) goto L_1fe170;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1fe0b8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1fe0c8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x16388cULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 16));
    if ((cpu->regs[1])==0) goto L_1fe0e8;
    if ((cpu->regs[0])==0) goto L_1fe134;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_NE) goto L_1fe134;
L_1fe0e8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1fe0fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1fe188;
L_1fe0fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1fe178;
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1fe134:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fe148;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fe17c;
L_1fe148:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fe150ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 2560ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fe170ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1fe170:
    cpu->regs[21] = 0ULL;
    goto L_1fe0fc;
L_1fe178:
    cpu->regs[30] = PB_BASE + 0x1fe17cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fe17c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fe184ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fe148;
L_1fe188:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fe190ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fe0fc;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[4] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    if ((cpu->regs[2])!=0) goto L_1fe2dc;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 16));
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HI) goto L_1fe384;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = cpu->regs[20];
L_1fe1fc:
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[30] = PB_BASE + 0x1fe204ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fe350;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fe214ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fe368;
    cpu->regs[25] = cpu->regs[25] + 24ULL;
    cpu->regs[26] = cpu->regs[0] + 24ULL;
    cpu->regs[19] = 0ULL;
L_1fe228:
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_EQ) goto L_1fe27c;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + (cpu->regs[19] << 3)));
    cpu->regs[30] = PB_BASE + 0x1fe238ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    if ((cpu->regs[0])==0) goto L_1fe368;
    PB_STR((cpu->regs[26] + (cpu->regs[19] << 3)), cpu->regs[0]);
    PB_STR((cpu->regs[22] + (cpu->regs[19] << 3)), 0ULL);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_1fe228;
L_1fe24c:
    cpu->regs[0] = 18446744073709551608ULL;
    cpu->regs[0] = cpu->regs[20] * cpu->regs[0] + cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (cpu->regs[19] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1fe26c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1fe26c:
    cpu->regs[0] = cpu->regs[21] + 24ULL;
    PB_STR((cpu->regs[0] + (cpu->regs[19] << 3)), cpu->regs[1]);
    PB_STR((cpu->regs[22] + (cpu->regs[19] << 3)), 0ULL);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_1fe27c:
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_LT) goto L_1fe24c;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 304));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fe294ULL; PB_CALL(12, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1fe368;
    PB_STR((cpu->regs[0] + 16), cpu->regs[21]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[22]);
    PB_STR((cpu->regs[0] + 32), 0ULL);
    PB_STRW((cpu->regs[0] + 40), 0ULL);
L_1fe2a4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1fe380;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_1fe2dc:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[0] + 3032ULL;
    cpu->regs[3] = cpu->regs[2];
    PB_STR((SP + 8), cpu->regs[0]); PB_STR((SP + 8) + 8, 0ULL);
    cpu->regs[4] = SP;
    cpu->regs[30] = PB_BASE + 0x1fe2f4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdb548ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x295000ULL;
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[2] = cpu->regs[2] + 3040ULL;
    cpu->regs[30] = PB_BASE + 0x1fe30cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1a63ccULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fe3a4;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1fe3c4;
L_1fe318:
    PB_LDR(cpu->regs[20], (SP + 0));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LT) goto L_1fe3dc;
    if (FLAG_EQ) goto L_1fe35c;
    cpu->regs[1] = 1152921504606846975ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 16));
    cpu->regs[2] = (cpu->regs[20] ? cpu->regs[1] / cpu->regs[20] : 0);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LO) goto L_1fe384;
    cpu->regs[24] = cpu->regs[20] * cpu->regs[0];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_LS) goto L_1fe1fc;
L_1fe350:
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fe358ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_1fe370;
L_1fe35c:
    cpu->regs[24] = 0ULL;
    cpu->regs[0] = 0ULL;
    goto L_1fe1fc;
L_1fe368:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1fe370ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_1fe370:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1fe378ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
L_1fe378:
    cpu->regs[0] = 0ULL;
    goto L_1fe2a4;
L_1fe380:
    cpu->regs[30] = PB_BASE + 0x1fe384ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fe384:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fe39cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1fe2a4;
L_1fe3a4:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1fe378;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1fe378;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fe3bcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1fe2a4;
L_1fe3c4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1fe318;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fe3d8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fe318;
L_1fe3dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3056ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fe3f4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1fe2a4;
    /* nop */
}
