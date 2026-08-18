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

void ft_PyObject_Calloc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_12c1d4;
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[0] = (cpu->regs[2] ? cpu->regs[0] / cpu->regs[2] : 0);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_12c1f0;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 176));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 192));
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_12c1d4:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 176));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 192));
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_12c1f0:
    cpu->regs[0] = 0ULL;
    return;
    /* nop */
    /* nop */
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_12c300;
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_12c32c;
L_12c250:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    PB_STR((SP + 0), 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_12c348;
L_12c270:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 120));
    if ((cpu->regs[1])==0) goto L_12c35c;
L_12c278:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12c280ULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12c370;
L_12c28c:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = SP;
    cpu->regs[30] = PB_BASE + 0x12c29cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdd360ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_12c370;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12c2b8;
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[21] = (FLAG_EQ) ? cpu->regs[21] : cpu->regs[0];
L_12c2b8:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12c2c8;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_12c2c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_12c358;
    PB_LDR(cpu->regs[23], (SP + 64));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_12c300:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 584ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12c31cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12c2c8;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_LE) goto L_12c250;
L_12c32c:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    PB_STR((SP + 0), 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_12c270;
L_12c348:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12c28c;
    goto L_12c270;
L_12c358:
    cpu->regs[30] = PB_BASE + 0x12c35cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_12c35c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12c364ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_12c378;
L_12c368:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12c370ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x23d444ULL);
L_12c370:
    cpu->regs[21] = 0ULL;
    goto L_12c2c8;
L_12c378:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12c380ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12c370;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 120));
    if ((cpu->regs[1])!=0) goto L_12c278;
    goto L_12c368;
    /* nop */
    /* nop */
    /* nop */
}
