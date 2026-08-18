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

void ft__PyStructSequence_NewType(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 240ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[1] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 224), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 168), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ab280ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18e780ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ab298ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18e7c4ULL);
    if ((cpu->regs[0])==0) goto L_1ab3f0;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 24),&_s,4); cpu->regs[3] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[12], (cpu->regs[19] + 0) + 8);
    cpu->regs[3] = cpu->regs[21] - cpu->regs[3];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 3ULL));
    cpu->regs[2] = PB_BASE + 0x51d000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] << 3));
    cpu->regs[2] = cpu->regs[2] + 3600ULL;
    cpu->regs[7] = PB_BASE + 0x149000ULL;
    cpu->regs[2] = cpu->regs[2] + 1720ULL;
    cpu->regs[7] = cpu->regs[7] + 1952ULL;
    cpu->regs[6] = PB_BASE + 0x27a000ULL;
    cpu->regs[5] = PB_BASE + 0x20b000ULL;
    cpu->regs[6] = cpu->regs[6] + 3360ULL;
    cpu->regs[5] = cpu->regs[5] + 560ULL;
    cpu->regs[4] = PB_BASE + 0x258000ULL;
    cpu->regs[4] = cpu->regs[4] + 1184ULL;
    PB_STRW((SP + 16), cpu->regs[3]);
    cpu->regs[3] = SP + 40ULL;
    cpu->regs[15] = 52ULL;
    cpu->regs[14] = 66ULL;
    cpu->regs[13] = 56ULL;
    cpu->regs[11] = 64ULL;
    cpu->regs[10] = 65ULL;
    cpu->regs[9] = 72ULL;
    cpu->regs[8] = 71ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 8ULL;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] | 16384ULL));
    PB_STRW((SP + 20), cpu->regs[0]);
    cpu->regs[0] = SP + 8ULL;
    PB_STRW((SP + 24), cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[3]);
    PB_STRW((SP + 40), cpu->regs[15]);
    PB_STR((SP + 48), cpu->regs[7]);
    PB_STRW((SP + 56), cpu->regs[14]);
    PB_STR((SP + 64), cpu->regs[6]);
    PB_STRW((SP + 72), cpu->regs[13]);
    PB_STR((SP + 80), cpu->regs[12]);
    PB_STRW((SP + 88), cpu->regs[11]);
    PB_STR((SP + 96), cpu->regs[2]);
    PB_STRW((SP + 104), cpu->regs[10]);
    PB_STR((SP + 112), cpu->regs[5]);
    PB_STRW((SP + 120), cpu->regs[9]);
    PB_STR((SP + 128), cpu->regs[22]);
    PB_STRW((SP + 136), cpu->regs[8]);
    PB_STR((SP + 144), cpu->regs[4]);
    PB_STRW((SP + 152), 0ULL);
    PB_STR((SP + 160), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1ab36cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1ab408ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ab378ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((cpu->regs[20])==0) goto L_1ab3f0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ab384ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ab398ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18e8a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1ab3dc;
L_1ab3a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1ab3d8;
    PB_LDR(cpu->regs[23], (SP + 224));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    SP = SP + 240ULL;
    return;
L_1ab3d8:
    cpu->regs[30] = PB_BASE + 0x1ab3dcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1ab3dc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ab3f0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ab3f8;
L_1ab3f0:
    cpu->regs[20] = 0ULL;
    goto L_1ab3a0;
L_1ab3f8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ab404ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ab3a0;
}
