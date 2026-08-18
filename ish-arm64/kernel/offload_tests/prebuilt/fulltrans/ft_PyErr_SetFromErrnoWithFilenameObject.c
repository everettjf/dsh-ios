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

void ft_PyErr_SetFromErrnoWithFilenameObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1c8cf0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1b2740ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c8d1cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_1c8d3c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c8d3c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1c8d74;
L_1c8d3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_1c8d68;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c8d68;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c8d68;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1c8d68:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1c8d74:
    cpu->regs[30] = PB_BASE + 0x1c8d78ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c8d3c;
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = SP;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 1296ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[3] = SP + 8ULL;
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c8dc8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x148028ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c8e1c;
    PB_LDR(cpu->regs[3], (SP + 0)); PB_LDR(cpu->regs[2], (SP + 0) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1c8de0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1481a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_1c8e1c;
    cpu->regs[30] = PB_BASE + 0x1c8decULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1fc0ULL);
L_1c8dec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1c8e18;
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1c8e18:
    cpu->regs[30] = PB_BASE + 0x1c8e1cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c8e1c:
    cpu->regs[0] = 0ULL;
    goto L_1c8dec;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    cpu->regs[30] = PB_BASE + 0x1c8e48ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe51acULL);
    if ((cpu->regs[0])==0) goto L_1c8fc8;
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1c8e58ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_STR((cpu->regs[20] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8e6cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1485e0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[20] + 32), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8e80ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1485e0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    PB_STR((cpu->regs[20] + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8e94ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[20] + 48), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8ea8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1c8fd0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 28));
    PB_STR((cpu->regs[20] + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8ebcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7aff0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[20] + 64), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8ed0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7b0f0ULL);
    if ((cpu->regs[0])==0) goto L_1c8fac;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 72)); PB_LDR(cpu->regs[6], (cpu->regs[19] + 72) + 8);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 112));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[20] + 72), cpu->regs[0]);
    cpu->regs[4] = 13ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = 10ULL;
    cpu->regs[2] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1c8f00ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c8fecULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c8fa8;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 88));
    cpu->regs[6] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 14ULL;
    cpu->regs[3] = 11ULL;
    cpu->regs[2] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1c8f28ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1c8fecULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c8fa8;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 104));
    cpu->regs[6] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = 15ULL;
    cpu->regs[3] = 12ULL;
    cpu->regs[2] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x1c8f50ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1c8fecULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c8fa8;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 56),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1c8f60ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fa8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    PB_STR((cpu->regs[20] + 152), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8f74ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c8fa8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[20] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c8f88ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe2620ULL);
    if ((cpu->regs[0])==0) goto L_1c8fa8;
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STR((cpu->regs[20] + 168), cpu->regs[0]);
L_1c8f94:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1c8fa8:
    PB_LDR(cpu->regs[23], (SP + 48));
L_1c8fac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c8fc8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c8fc8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c8fc8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1c8fc8:
    cpu->regs[20] = 0ULL;
    goto L_1c8f94;
}
