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

void ft__PyErr_SetNone(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x120824ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x96e58ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1936ULL;
    cpu->regs[30] = PB_BASE + 0x96e6cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x96ea8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x87da4ULL);
    PB_STR((SP + 0), 0ULL);
    cpu->regs[0] = 104857599ULL;
    FLAG_CMP(SP, cpu->regs[0]);
    if (FLAG_LS) goto L_96ed4;
    cpu->regs[0] = 18446744073709486080ULL;
    cpu->regs[1] = 18446744073604694015ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0xf9c0ULL & 0xffff) << 16);
    cpu->regs[0] = SP + cpu->regs[0];
    FLAG_CMP(SP, cpu->regs[1]);
    if (FLAG_HI) goto L_96ee4;
    goto L_96ed8;
L_96ed4:
    cpu->regs[0] = 0ULL;
L_96ed8:
    cpu->regs[1] = 104857600ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[1];
    goto L_96ee8;
L_96ee4:
    cpu->regs[1] = 18446744073709551615ULL;
L_96ee8:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x96ef0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x87d14ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3296));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    PB_LDR(cpu->regs[3], (SP + 0));
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[2] = cpu->regs[4] - cpu->regs[19];
    cpu->regs[19] = cpu->regs[19] - cpu->regs[4];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = (FLAG_HS) ? cpu->regs[19] : cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + 1976ULL;
    cpu->regs[30] = PB_BASE + 0x96f20ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_96f40;
    cpu->regs[30] = PB_BASE + 0x96f40ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_96f40:
    PB_LDR(cpu->regs[19], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 2072ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0x96f88ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_96f94;
L_96f8c:
    cpu->regs[0] = 0ULL;
    goto L_96fd8;
L_96f94:
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0x96f9cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7fc8cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_96f8c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2648));
    if ((cpu->regs[0])==0) goto L_96fc4;
    PB_LDRW(cpu->regs[1], (SP + 4));
    cpu->regs[2] = 192ULL;
    cpu->regs[0] = cpu->regs[0] + (uint64_t)((int64_t)(int32_t)cpu->regs[1] * (int64_t)(int32_t)cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x96fc0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x280450ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_96fd0;
L_96fc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_96fd8;
L_96fd0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_96fd8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_96ff8;
    cpu->regs[30] = PB_BASE + 0x96ff8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_96ff8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
}
