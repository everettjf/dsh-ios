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

void ft_PyLong_AsUnsignedLongLongMask(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_1e59e0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_1e5a08;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_1e5a40;
L_1e59e0:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = 1346ULL;
    cpu->regs[0] = cpu->regs[0] + 408ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1e59f4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_1e59f4:
    cpu->regs[20] = 18446744073709551615ULL;
L_1e59f8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e5a08:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1e5a10ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e59f4;
    cpu->regs[30] = PB_BASE + 0x1e5a1cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e5a40ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e59f8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e59f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e5a3cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e59f8;
L_1e5a40:
    if ((cpu->regs[0])==0) goto L_1e5a74;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_1e5a74;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 15ULL);
    if (FLAG_HI) goto L_1e5a98;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[2];
    return;
L_1e5a74:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 1319ULL;
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[29] = SP;
    cpu->regs[0] = cpu->regs[0] + 408ULL;
    cpu->regs[30] = PB_BASE + 0x1e5a8cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1e5a98:
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 3ULL));
    cpu->regs[2] = cpu->regs[1] >> 3;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4]));
    cpu->regs[3] = 0ULL;
L_1e5ab0:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e5ac8;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + (cpu->regs[2] << 2)));
    cpu->regs[3] = cpu->regs[4] | (cpu->regs[3] << 30);
    goto L_1e5ab0;
L_1e5ac8:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[3];
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e5b4c;
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_1e5b78;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1e5b20ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1e5b6c;
    cpu->regs[1] = 5ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[20]);
    PB_STRW((cpu->regs[0] + 32), cpu->regs[23]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[21]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1e5b40:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1e5b4c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 3232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e5b64ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e5b40;
L_1e5b6c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1e5b40;
L_1e5b78:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 3272ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e5b90ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e5b40;
    /* nop */
    /* nop */
}
