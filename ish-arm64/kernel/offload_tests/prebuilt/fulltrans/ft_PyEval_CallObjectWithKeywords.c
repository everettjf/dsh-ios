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

void ft_PyEval_CallObjectWithKeywords(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = cpu->regs[1];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa6a08ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + cpu->regs[0]));
    if ((cpu->regs[2])==0) goto L_a6a38;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 168));
    if (((cpu->regs[4] >> 26) & 1)) goto L_a6a7c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = cpu->regs[2] + 3864ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa6a34ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_a6a88;
L_a6a38:
    if ((cpu->regs[3])==0) goto L_a6a68;
L_a6a3c:
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 168));
    if (((cpu->regs[4] >> 29) & 1)) goto L_a6a64;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x2a3000ULL;
    cpu->regs[2] = cpu->regs[2] + 3448ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa6a60ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_a6a88;
L_a6a64:
    if ((cpu->regs[2])!=0) goto L_a6a80;
L_a6a68:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = 0ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0xeda60ULL); return; };
L_a6a7c:
    if ((cpu->regs[3])!=0) goto L_a6a3c;
L_a6a80:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x12660cULL); return; };
L_a6a88:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_a6afc;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_a6adc;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    FLAG_CMP((cpu->regs[3]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_a6adc:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[1] = cpu->regs[1] + 3712ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 24));
    cpu->regs[30] = PB_BASE + 0xa6af8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a6b14;
L_a6afc:
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0xa6b0cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x192e10ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a6b1c;
L_a6b14:
    cpu->regs[20] = 0ULL;
    goto L_a6b4c;
L_a6b1c:
    cpu->regs[1] = cpu->regs[20] + 32ULL;
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22] - 1ULL;
    cpu->regs[30] = PB_BASE + 0xa6b2cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x192f90ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6b4c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6b4c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6b4cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6b4c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 32));
    if ((cpu->regs[0])==0) goto L_a6b94;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_GT) goto L_a6b94;
    cpu->regs[30] = PB_BASE + 0xa6b88ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x22d18cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a6ba4;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
L_a6b94:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x7aeb0ULL); return; };
L_a6ba4:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa6be0ULL; PB_CALL(12, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[4] + cpu->regs[0]));
    PB_STR((SP + 48), cpu->regs[23]);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_a6c10;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x2a3000ULL;
    cpu->regs[2] = cpu->regs[2] + 3488ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa6c0cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_a6c28;
L_a6c10:
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6c24ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xa2470ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a6c30;
L_a6c28:
    cpu->regs[19] = 0ULL;
    goto L_a6c68;
L_a6c30:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[19] + 8ULL;
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[22] - 1ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6c48ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x280becULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6c58ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x973ccULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a6c68;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6c64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_a6c28;
L_a6c68:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
