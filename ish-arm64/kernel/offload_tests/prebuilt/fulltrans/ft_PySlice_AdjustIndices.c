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

void ft_PySlice_AdjustIndices(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    if (((cpu->regs[4] >> 63) & 1)) goto L_146bb0;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_GE) goto L_146b90;
L_146b34:
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    if (((cpu->regs[4] >> 63) & 1)) goto L_146b6c;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_GT) goto L_146b78;
    if (((cpu->regs[3] >> 63) & 1)) goto L_146c70;
L_146b48:
    cpu->regs[4] = cpu->regs[0];
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
L_146b50:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_GE) goto L_146b88;
L_146b5c:
    cpu->regs[0] = cpu->regs[4] - cpu->regs[0];
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_NE) goto L_146c0c;
    return;
L_146b6c:
    cpu->regs[4] = cpu->regs[4] + cpu->regs[0];
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
    if (((cpu->regs[4] >> 63) & 1)) goto L_146bd8;
L_146b78:
    if (((cpu->regs[3] >> 63) & 1)) goto L_146be8;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LT) goto L_146b5c;
L_146b88:
    cpu->regs[0] = 0ULL;
L_146b8c:
    return;
L_146b90:
    if (((cpu->regs[3] >> 63) & 1)) goto L_146c34;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    if (((cpu->regs[4] >> 63) & 1)) goto L_146c1c;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LE) goto L_146b48;
    cpu->regs[0] = 0ULL;
    goto L_146b8c;
L_146bb0:
    cpu->regs[4] = cpu->regs[4] + cpu->regs[0];
    PB_STR((cpu->regs[1] + 0), cpu->regs[4]);
    if (!((cpu->regs[4] >> 63) & 1)) goto L_146b34;
    if (((cpu->regs[3] >> 63) & 1)) goto L_146c58;
    PB_STR((cpu->regs[1] + 0), 0ULL);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    if (((cpu->regs[4] >> 63) & 1)) goto L_146c1c;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LE) goto L_146b48;
    goto L_146b50;
L_146bd8:
    if (!((cpu->regs[3] >> 63) & 1)) goto L_146c28;
L_146bdc:
    cpu->regs[0] = 18446744073709551615ULL;
    cpu->regs[4] = cpu->regs[0];
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
L_146be8:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LE) goto L_146b88;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    cpu->regs[3] = (uint64_t)(-(int64_t)cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[4];
    cpu->regs[0] = (cpu->regs[3] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[3]) : 0);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    return;
L_146c0c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    cpu->regs[0] = (cpu->regs[3] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[3]) : 0);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    return;
L_146c1c:
    cpu->regs[4] = cpu->regs[4] + cpu->regs[0];
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
    if (!((cpu->regs[4] >> 63) & 1)) goto L_146b50;
L_146c28:
    cpu->regs[4] = 0ULL;
    PB_STR((cpu->regs[2] + 0), 0ULL);
    goto L_146b50;
L_146c34:
    cpu->regs[5] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[5]);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    if (((cpu->regs[4] >> 63) & 1)) goto L_146c78;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_GT) goto L_146be8;
L_146c4c:
    cpu->regs[4] = cpu->regs[5];
    PB_STR((cpu->regs[2] + 0), cpu->regs[5]);
    goto L_146be8;
L_146c58:
    cpu->regs[4] = 18446744073709551615ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[4]);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    if (((cpu->regs[4] >> 63) & 1)) goto L_146c78;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_GT) goto L_146b88;
L_146c70:
    cpu->regs[5] = cpu->regs[0] - 1ULL;
    goto L_146c4c;
L_146c78:
    cpu->regs[4] = cpu->regs[0] + cpu->regs[4];
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
    if (!((cpu->regs[4] >> 63) & 1)) goto L_146be8;
    goto L_146bdc;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x146cacULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + -16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + -16) + 8);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_146d44;
L_146ce8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_146d1c;
L_146cf4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_146d30;
L_146d00:
    cpu->regs[0] = cpu->regs[20] + (64ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 7680));
    if ((cpu->regs[1])!=0) goto L_146d58;
    PB_STR((cpu->regs[0] + 7680), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_146d1c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_146cf4;
    cpu->regs[30] = PB_BASE + 0x146d2cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146cf4;
L_146d30:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_146d00;
    cpu->regs[30] = PB_BASE + 0x146d40ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146d00;
L_146d44:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_146ce8;
    cpu->regs[30] = PB_BASE + 0x146d54ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146ce8;
L_146d58:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
}
