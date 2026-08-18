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

void ft__PyThreadState_Swap(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x26deb8ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->tls_ptr;
    cpu->regs[22] = cpu->regs[21] + cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[20], (cpu->regs[21] + cpu->regs[0]));
    if ((cpu->regs[20])==0) goto L_26def4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 368ULL;
    cpu->regs[30] = PB_BASE + 0x26dee4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x14770cULL);
    PB_STR((cpu->regs[22] + 0), 0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967279ULL));
    PB_STRW((cpu->regs[20] + 24), cpu->regs[0]);
L_26def4:
    if ((cpu->regs[19])==0) goto L_26df28;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x26df0cULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    PB_STR((cpu->regs[21] + cpu->regs[0]), cpu->regs[19]);
    if (!((cpu->regs[1] >> 3) & 1)) goto L_26df3c;
L_26df14:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 16ULL));
    PB_STRW((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x26df28ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8448ULL);
L_26df28:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26df3c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26df44ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x182a68ULL);
    goto L_26df14;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_HI) goto L_26e00c;
L_26df68:
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_26dfa4;
    cpu->regs[1] = 0ULL;
L_26df7c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26df84ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x141b04ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26e02c;
L_26df90:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_26dfa4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x26dfacULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26dfcc;
    cpu->regs[30] = PB_BASE + 0x26dfb8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_26dfec;
L_26dfc4:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_26df7c;
L_26dfcc:
    cpu->regs[30] = PB_BASE + 0x26dfd0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[1] = 18446744073709551615ULL;
    if ((cpu->regs[0])==0) goto L_26df7c;
L_26dfd8:
    PB_LDR(cpu->regs[21], (SP + 32));
L_26dfdc:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_26dfec:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_26dfc4;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x26e004ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_26dfc4;
L_26e00c:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3232ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x26e024ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26df68;
    goto L_26dfdc;
L_26e02c:
    cpu->regs[30] = PB_BASE + 0x26e030ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_26dfd8;
    goto L_26df90;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26e050;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x7aeb0ULL); return; };
L_26e050:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26e070ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[5] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    if ((cpu->regs[2])!=0) goto L_26e1e4;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_HI) goto L_26e17c;
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_26e1f0;
L_26e0d8:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_26e1b0;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_26e0ec:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e0fcULL; PB_CALL(16, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e1dc;
    PB_STR((cpu->regs[0] + 32), 0ULL); PB_STR((cpu->regs[0] + 32) + 8, 0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26e1b8;
L_26e118:
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26e124ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26e1c0;
    cpu->regs[1] = PB_BASE + 0x520000ULL;
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x26e140ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((cpu->regs[19] + 64), cpu->regs[0]);
L_26e148:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_26e22c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_26e17c:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[0] = cpu->regs[3] + 24ULL;
    cpu->regs[4] = cpu->regs[4] + 968ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e1a8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_26e1dc;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
L_26e1b0:
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    goto L_26e0ec;
L_26e1b8:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_26e118;
L_26e1c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26e1dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26e1dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26e1dcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_26e1dc:
    cpu->regs[19] = 0ULL;
    goto L_26e148;
L_26e1e4:
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[19] = cpu->regs[1] + cpu->regs[19];
L_26e1f0:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[4] + 968ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e220ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_26e0d8;
    cpu->regs[19] = 0ULL;
    goto L_26e148;
L_26e22c:
    cpu->regs[30] = PB_BASE + 0x26e230ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_STR((cpu->regs[0] + 56), 0ULL);
    if ((cpu->regs[1])==0) goto L_26e2d0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    if ((cpu->regs[0])==0) goto L_26e26c;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x26e25cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26e3a4;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26e2d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
L_26e26c:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26e34c;
L_26e278:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x26e284ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26e290ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x26e3e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e3a4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x26e2a8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_26e2c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_26e3ac;
L_26e2c0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26e2d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x26e2d8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e3a4;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_26e370;
L_26e2f8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e300ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e398;
L_26e308:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 40) + 8);
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]); PB_STR((cpu->regs[19] + 40) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x26e314ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26e31cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    if ((cpu->regs[1])==0) goto L_26e354;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_26e390;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x26e334ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26e3a0;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26e354;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_26e26c;
L_26e34c:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_26e278;
L_26e354:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x26e35cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e3a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_26e2f8;
L_26e370:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26e384;
    cpu->regs[1] = cpu->regs[20];
    goto L_26e308;
L_26e384:
    cpu->regs[1] = cpu->regs[20];
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_26e308;
L_26e390:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_26e26c;
L_26e398:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26e3b8;
L_26e3a0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_26e3a4:
    cpu->regs[19] = 0ULL;
    goto L_26e2c0;
L_26e3ac:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e3b4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26e2c0;
L_26e3b8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26e3a0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e3d0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_26e2c0;
    /* nop */
    /* nop */
L_26e3e0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 88));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26e404ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e43c;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26e41c;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_26e41c:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26e450;
L_26e42c:
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((cpu->regs[20] + 56), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x26e43cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe1984ULL);
L_26e43c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26e450:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_26e42c;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x26e48cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_26e518;
L_26e49c:
    if ((cpu->regs[21])!=0) goto L_26e4fc;
L_26e4a0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_26e52c;
L_26e4ac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x26e4b4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e510;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e4c4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e54c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e4dcULL; PB_CALL(40, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26e570;
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[21]);
    PB_STR((cpu->regs[0] + 32), 0ULL);
    PB_STRW((cpu->regs[0] + 40), 0ULL);
L_26e4ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26e4fc:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 3272ULL;
    cpu->regs[30] = PB_BASE + 0x26e50cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26e4a0;
L_26e510:
    cpu->regs[0] = 0ULL;
    goto L_26e4ec;
L_26e518:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_26e49c;
    goto L_26e4a0;
L_26e52c:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3272ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x26e540ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26e4ac;
    cpu->regs[0] = 0ULL;
    goto L_26e4ec;
L_26e54c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26e510;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26e510;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e568ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_26e4ec;
L_26e570:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26e584;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26e5a8;
L_26e584:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26e510;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26e510;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26e5a0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_26e4ec;
L_26e5a8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e5b0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26e584;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_26e620;
L_26e5d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_26e658;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[2] + 1ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[3] + (cpu->regs[2] << 3)));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    cpu->regs[0] = (FLAG_LT) ? cpu->regs[0] : 0ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26e610;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_26e610:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26e620:
    cpu->regs[30] = PB_BASE + 0x26e624ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e660;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26e610;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e640ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe548cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26e610;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26e658;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26e690;
L_26e658:
    cpu->regs[20] = 0ULL;
    goto L_26e610;
L_26e660:
    cpu->regs[30] = PB_BASE + 0x26e664ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_26e658;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_26e5d8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_26e5d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26e5d8;
    cpu->regs[30] = PB_BASE + 0x26e68cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26e5d8;
L_26e690:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e69cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26e610;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x26e6b8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x26e6c0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x26e6c8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26e6d4ULL; PB_CALL(54, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26e6e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26e6f4;
L_26e6e8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26e6f4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[1] << 3);
    { PB_CALL(56, cpu, tlb, PB_BASE + 0x7aeb0ULL); return; };
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[5], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_26e840;
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_26e840;
L_26e764:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x26e770ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e8d4;
    cpu->regs[30] = PB_BASE + 0x26e77cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26e8f0;
L_26e788:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26e8d4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26e798ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e8b0;
    PB_STR((SP + 96), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    if (((cpu->regs[19] >> 63) & 1)) goto L_26e894;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HI) goto L_26e888;
    cpu->regs[0] = cpu->regs[19] << 3;
    cpu->regs[30] = PB_BASE + 0x26e7c0ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[1] = 0ULL;
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26e888;
L_26e7cc:
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_26e7e0;
    PB_STR((cpu->regs[20] + (cpu->regs[1] << 3)), 0ULL);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_26e7cc;
L_26e7e0:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 304));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e7f0ULL; PB_CALL(61, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26e8c4;
    FLAG_CMP(cpu->regs[23], 0ULL);
    PB_STR((cpu->regs[0] + 16), cpu->regs[21]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[19], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((cpu->regs[0] + 32), 0ULL); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[19]);
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[23], (SP + 96));
    PB_STRW((cpu->regs[0] + 48), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_26e814:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_26e87c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_26e840:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[6] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 1040ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e870ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_26e764;
    cpu->regs[0] = 0ULL;
    goto L_26e814;
L_26e87c:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x26e888ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26e888:
    cpu->regs[30] = PB_BASE + 0x26e88cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[23], (SP + 96));
    goto L_26e8b0;
L_26e894:
    PB_LDR(cpu->regs[23], (SP + 96));
L_26e898:
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = cpu->regs[1] + 2912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26e8b0ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_26e8b0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26e8b8ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x18d760ULL);
L_26e8b8:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    goto L_26e814;
L_26e8c4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e8ccULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 96));
    goto L_26e8b0;
L_26e8d4:
    cpu->regs[30] = PB_BASE + 0x26e8d8ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_26e8b8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26e8e4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_26e898;
    goto L_26e8b0;
L_26e8f0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26e788;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26e904ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26e788;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 32));
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[0] << 3);
    { PB_CALL(71, cpu, tlb, PB_BASE + 0x7aeb0ULL); return; };
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3432));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[4]);
    if (FLAG_EQ) goto L_26e974;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_26e978;
L_26e974:
    if ((cpu->regs[2])!=0) goto L_26ea04;
L_26e978:
    cpu->regs[21] = PB_BASE + 0x282000ULL;
L_26e97c:
    cpu->regs[3] = 2ULL;
    cpu->regs[1] = cpu->regs[21] + 3864ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[5] = SP + 8ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[4] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x26e998ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26ea18;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x26e9a4ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26ea18;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26e9bcULL; PB_CALL(74, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26ea2c;
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_26ea20;
L_26e9d0:
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
L_26e9d4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_26ea28;
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_26ea04:
    cpu->regs[21] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[21] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x26ea14ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26e97c;
L_26ea18:
    cpu->regs[0] = 0ULL;
    goto L_26e9d4;
L_26ea20:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    goto L_26e9d0;
L_26ea28:
    cpu->regs[30] = PB_BASE + 0x26ea2cULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26ea2c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26ea18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26ea18;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26ea48ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_26e9d4;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2408));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_26ea84;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_26ea88;
L_26ea84:
    if ((cpu->regs[2])!=0) goto L_26eb24;
L_26ea88:
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x26ea94ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x10e664ULL);
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_26eb58;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x26eaacULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26eb48;
    cpu->regs[24] = cpu->regs[0] + 16ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[20] + 24ULL;
    cpu->regs[22] = 1ULL;
L_26eac4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + (cpu->regs[22] << 3)));
    cpu->regs[30] = PB_BASE + 0x26eaccULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_26eb7c;
    PB_STR((cpu->regs[24] + (cpu->regs[22] << 3)), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[22]);
    if (FLAG_NE) goto L_26eac4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26eaf0ULL; PB_CALL(81, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26eb7c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[0] + 16), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_26eb40;
L_26eb08:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STR((cpu->regs[0] + 24), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_26eb18:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_26eb24:
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 3904ULL;
    cpu->regs[30] = PB_BASE + 0x26eb34ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26ea88;
    cpu->regs[0] = 0ULL;
    goto L_26eb18;
L_26eb40:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    goto L_26eb08;
L_26eb48:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26eb18;
L_26eb58:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26eb70ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26eb18;
L_26eb7c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26eb90;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26eba4;
L_26eb90:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26eb18;
L_26eba4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26ebacULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26eb18;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x26ebecULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 144));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_26ec68;
L_26ebfc:
    if ((cpu->regs[21])!=0) goto L_26ec24;
L_26ec00:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_26ec4c;
L_26ec0c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_26ec80;
L_26ec24:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 3280ULL;
    cpu->regs[30] = PB_BASE + 0x26ec34ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26ec00;
L_26ec38:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26ec4c:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3280ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x26ec60ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26ec38;
    goto L_26ec0c;
L_26ec68:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_26ebfc;
    goto L_26ec00;
    /* nop */
L_26ec80:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x26eca0ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_26ed00;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 304));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26ecb8ULL; PB_CALL(89, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26ece4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_26eccc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_26eccc:
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
    PB_STR((cpu->regs[0] + 32), 0ULL);
L_26ecd4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26ece4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26ed00;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26ed00;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26ed00ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_26ed00:
    cpu->regs[0] = 0ULL;
    goto L_26ecd4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 24) + 8);
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_26ed94;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x26ed30ULL; PB_CALL(91, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26ed94;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x26ed48ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26edb4;
    cpu->regs[30] = PB_BASE + 0x26ed54ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[22] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26edd4;
L_26ed60:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_26ed7c;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_26ed6c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26ed7c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26ed9c;
L_26ed84:
    if ((cpu->regs[22])!=0) goto L_26edc8;
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_26ed94:
    cpu->regs[19] = 0ULL;
    goto L_26ed6c;
L_26ed9c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26ed84;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26edb0ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26ed84;
L_26edb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26edc8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26edec;
L_26edc8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[19] = 0ULL;
    goto L_26ed6c;
L_26edd4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26ed60;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26ede8ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26ed60;
L_26edec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26edf8ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_26ed6c;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x26ee2cULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_26eea8;
L_26ee3c:
    if ((cpu->regs[21])!=0) goto L_26ee64;
L_26ee40:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_26ee8c;
L_26ee4c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_26ec80;
L_26ee64:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    cpu->regs[30] = PB_BASE + 0x26ee74ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26ee40;
L_26ee78:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26ee8c:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x26eea0ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26ee78;
    goto L_26ee4c;
L_26eea8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_26ee3c;
    goto L_26ee40;
    /* nop */
L_26eec0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x26eed8ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x26eee0ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x26eee8ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26eef4ULL; PB_CALL(103, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26ef08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26ef14;
L_26ef08:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26ef14:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(104, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 224));
L_26ef44:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26ef4cULL; PB_CALL(105, cpu, tlb, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26efdc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_26ef74;
L_26ef60:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_26ef74:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x26ef84ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26efc4;
    cpu->regs[30] = PB_BASE + 0x26ef90ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[24] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26efe4;
L_26ef9c:
    if ((cpu->regs[24])==0) goto L_26efb4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26effc;
L_26efa8:
    if (((cpu->regs[24] >> 63) & 1)) goto L_26efd8;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26ef44;
L_26efb4:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26ef60;
L_26efc4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26efd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26f014;
L_26efd8:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_26efdc:
    cpu->regs[19] = 0ULL;
    goto L_26ef60;
L_26efe4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26ef9c;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x26eff8ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26ef9c;
L_26effc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26efa8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f010ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26efa8;
L_26f014:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f020ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_26ef60;
    goto L_26eec0;
    SP = SP - 96ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[5], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_26f0dc;
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f0dc;
L_26f070:
    PB_STR((SP + 80), cpu->regs[21]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0)); PB_LDR(cpu->regs[21], (cpu->regs[3] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x26f07cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f118;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f08cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f118;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f0a4ULL; PB_CALL(113, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26f11c;
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 80));
L_26f0b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_26f138;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_26f0dc:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[6] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 1112ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f108ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_26f070;
    cpu->regs[0] = 0ULL;
    goto L_26f0b0;
L_26f118:
    cpu->regs[21] = 0ULL;
L_26f11c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f124ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f12cULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = 0ULL;
    goto L_26f0b0;
L_26f138:
    PB_STR((SP + 80), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x26f140ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x7c170ULL);
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[23], (cpu->regs[0] + 16) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[24], (cpu->regs[2] + 224));
    PB_LDR(cpu->regs[25], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x26f174ULL; PB_CALL(118, cpu, tlb, cpu->regs[24]);
    if ((cpu->regs[0])==0) goto L_26f238;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x26f184ULL; PB_CALL(119, cpu, tlb, cpu->regs[25]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f230;
    cpu->regs[30] = PB_BASE + 0x26f190ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26f288;
L_26f19c:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_26f1c0;
L_26f1a4:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_26f1c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26f240;
L_26f1c8:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_26f238;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26f1d4ULL; PB_CALL(121, cpu, tlb, cpu->regs[24]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f238;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x26f1e4ULL; PB_CALL(122, cpu, tlb, cpu->regs[25]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f230;
L_26f1ec:
    cpu->regs[30] = PB_BASE + 0x26f1f0ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26f258;
L_26f1fc:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_26f1a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26f270;
L_26f20c:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_26f238;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26f218ULL; PB_CALL(124, cpu, tlb, cpu->regs[24]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    if ((cpu->regs[19])==0) goto L_26f238;
    cpu->regs[30] = PB_BASE + 0x26f228ULL; PB_CALL(125, cpu, tlb, cpu->regs[25]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_26f1ec;
L_26f230:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26f2a0;
L_26f238:
    cpu->regs[19] = 0ULL;
    goto L_26f1a4;
L_26f240:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26f1c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f254ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f1c8;
L_26f258:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26f1fc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26f26cULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f1fc;
L_26f270:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26f20c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f284ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f20c;
L_26f288:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26f19c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26f29cULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f19c;
L_26f2a0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26f238;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f2b8ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f1a4;
    /* nop */
    { PB_CALL(131, cpu, tlb, PB_BASE + 0x222924ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x26f2dcULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x26f2e4ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x26f2ecULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x26f2f4ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x26f2fcULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x26f304ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f310ULL; PB_CALL(138, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26f324;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26f330;
L_26f324:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26f330:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(139, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP = SP - 112ULL;
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    PB_STR((SP + 96), cpu->regs[23]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if ((cpu->regs[2])!=0) goto L_26f484;
    cpu->regs[0] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_HI) goto L_26f4e8;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_26f490;
L_26f398:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_26f45c;
L_26f3a4:
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 8));
    if ((cpu->regs[23])==0) goto L_26f4d4;
    FLAG_CMP(cpu->regs[21], 2ULL);
    if (FLAG_NE) goto L_26f4dc;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_26f3bc:
    cpu->regs[30] = PB_BASE + 0x26f3c0ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f4cc;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f3d8ULL; PB_CALL(141, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f52c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_NE) goto L_26f46c;
L_26f3f0:
    PB_STR((cpu->regs[19] + 16), 0ULL); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[21]);
    if ((cpu->regs[22])==0) goto L_26f404;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26f550;
L_26f404:
    PB_STR((cpu->regs[19] + 40), cpu->regs[22]);
    cpu->regs[1] = PB_BASE + 0x520000ULL;
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x26f41cULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
L_26f424:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_26f4e4;
    PB_LDR(cpu->regs[23], (SP + 96));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_26f45c:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[22] = cpu->regs[23];
    goto L_26f3bc;
L_26f46c:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26f47c;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_26f47c:
    PB_STR((cpu->regs[19] + 32), cpu->regs[23]);
    goto L_26f3f0;
L_26f484:
    PB_LDR(cpu->regs[21], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = cpu->regs[19] + cpu->regs[21];
L_26f490:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[4] + 1184ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f4c4ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_26f398;
L_26f4cc:
    cpu->regs[19] = 0ULL;
    goto L_26f424;
L_26f4d4:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
L_26f4dc:
    PB_LDR(cpu->regs[22], (cpu->regs[2] + 16));
    goto L_26f3bc;
L_26f4e4:
    cpu->regs[30] = PB_BASE + 0x26f4e8ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26f4e8:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[4] = cpu->regs[4] + 1184ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f518ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f4cc;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[21] = cpu->regs[19];
    goto L_26f3a4;
L_26f52c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26f4cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26f4cc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26f54cULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f424;
L_26f550:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_26f404;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 40));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_26f674;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x26f598ULL; PB_CALL(147, cpu, tlb, cpu->regs[1]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f660;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_26f628;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    if ((cpu->regs[2])!=0) goto L_26f644;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f5b8ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x11a700ULL);
    cpu->regs[20] = cpu->regs[0];
L_26f5bc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_26f610;
L_26f5c4:
    if ((cpu->regs[20])==0) goto L_26f660;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26f66c;
L_26f5d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26f5f8;
L_26f5e4:
    PB_LDR(cpu->regs[21], (SP + 32));
L_26f5e8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26f5f8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26f5e4;
    cpu->regs[30] = PB_BASE + 0x26f608ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_26f5e8;
L_26f610:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26f5c4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f624ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26f5c4;
L_26f628:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26f69c;
L_26f634:
    cpu->regs[20] = cpu->regs[21];
    PB_STR((cpu->regs[19] + 16), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_26f5e8;
L_26f644:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f658ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x1987c8ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_26f5bc;
L_26f660:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[20] = 0ULL;
    goto L_26f5e8;
L_26f66c:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_26f5d4;
L_26f674:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_26f6a4;
L_26f684:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_26f5e8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    goto L_26f5e8;
L_26f69c:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_26f634;
L_26f6a4:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_26f684;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x26f6c4ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[30] = PB_BASE + 0x26f6ccULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x26f6d4ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x26f6dcULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x26f6e4ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f6f0ULL; PB_CALL(157, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26f704;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_26f710;
L_26f704:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26f710:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(158, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x26f74cULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_26f860;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 40)); PB_LDR(cpu->regs[21], (cpu->regs[19] + 40) + 8);
    FLAG_CMP(cpu->regs[4], cpu->regs[20]);
    if (FLAG_NE) goto L_26f810;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[4]);
    if (FLAG_EQ) goto L_26f7a8;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[4];
    FLAG_CMP(cpu->regs[20], 0ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3432ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(160, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_26f7a8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3400ULL;
    cpu->regs[30] = PB_BASE + 0x26f7c0ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f85c;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[1] = cpu->regs[1] + 3416ULL;
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26f7e4ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f85c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 96));
    cpu->regs[4] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3424ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[3] = 1ULL;
    { PB_CALL(163, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_26f810:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3400ULL;
    cpu->regs[30] = PB_BASE + 0x26f828ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f85c;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[3], 0ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[0] = cpu->regs[0] + 3408ULL;
    { PB_CALL(165, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_26f85c:
    PB_LDR(cpu->regs[21], (SP + 32));
L_26f860:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x26f88cULL; PB_CALL(166, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f918;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 16) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[2] * cpu->regs[0] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26f8a4ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f918;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x26f8b4ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f920;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2632));
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f8d4ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x14e610ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26f920;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 47952ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26f8f0ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x225b60ULL);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 3440ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    { PB_CALL(171, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_26f918:
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
L_26f920:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x26f928ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26f930ULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26f938ULL; PB_CALL(174, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[1] + 3448ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[3] + 8) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24)); PB_LDR(cpu->regs[4], (cpu->regs[3] + 24) + 8);
    { PB_CALL(175, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x26f994ULL; PB_CALL(176, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_26f9c4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_26f9cc;
L_26f9a4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_STR((cpu->regs[20] + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x26f9b0ULL; PB_CALL(177, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_26f9b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26f9c4:
    cpu->regs[0] = 0ULL;
    goto L_26f9b8;
L_26f9cc:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_26f9a4;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x26fa0cULL; PB_CALL(178, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_26fa5c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    if ((cpu->regs[2])==0) goto L_26fa48;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    if ((cpu->regs[3])!=0) goto L_26fa34;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3472ULL;
    { PB_CALL(179, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_26fa34:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3464ULL;
    { PB_CALL(180, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_26fa48:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3480ULL;
    { PB_CALL(181, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_26fa5c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 47952ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x26fa90ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0x225b60ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    if ((cpu->regs[2])==0) goto L_26fab4;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 680ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(183, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_26fab4:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 688ULL;
    { PB_CALL(184, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26fae0ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26fb18;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_26fb04;
    if (((cpu->regs[0] >> 63) & 1)) goto L_26fb30;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_26fb00:
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
L_26fb04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_26fb0c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_26fb18:
    cpu->regs[30] = PB_BASE + 0x26fb1cULL; PB_CALL(186, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_26fb38;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_26fb00;
    goto L_26fb04;
L_26fb30:
    cpu->regs[1] = 0ULL;
    goto L_26fb00;
L_26fb38:
    cpu->regs[0] = 0ULL;
    goto L_26fb0c;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x26fb88ULL; PB_CALL(187, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_26fc54;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_STR((SP + 8), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_26fc70;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[1] + 3512ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x26fbb4ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26fc54;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x26fbc4ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0x152da0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26fc3c;
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_26fc34;
L_26fbd0:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26fbe0;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_26fbe0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x26fbecULL; PB_CALL(190, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[1])!=0) goto L_26fc5c;
L_26fbf4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x26fc00ULL; PB_CALL(191, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_26fc08:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_26fc90;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_26fc34:
    cpu->regs[30] = PB_BASE + 0x26fc38ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0x152da0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26fbd0;
L_26fc3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3520ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26fc54ULL; PB_CALL(193, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_26fc54:
    cpu->regs[0] = 0ULL;
    goto L_26fc08;
L_26fc5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26fbf4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_26fbf4;
L_26fc70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26fc88ULL; PB_CALL(194, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_26fc08;
L_26fc90:
    cpu->regs[30] = PB_BASE + 0x26fc94ULL; PB_CALL(195, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 96ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[5], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_26fda8;
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_26fda8;
L_26fce4:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x26fcf0ULL; PB_CALL(196, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26fd70;
    cpu->regs[30] = PB_BASE + 0x26fcfcULL; PB_CALL(197, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26fdec;
L_26fd08:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26fd70;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_26fd84;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26fd20ULL; PB_CALL(198, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26fd78;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 304));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26fd38ULL; PB_CALL(199, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_26fe04;
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_26fd44:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_26fde4;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_26fd70:
    cpu->regs[30] = PB_BASE + 0x26fd74ULL; PB_CALL(200, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_26fd84;
L_26fd78:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    goto L_26fd44;
L_26fd84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3552ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26fd9cULL; PB_CALL(201, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_26fd44;
L_26fda8:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[6] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 1256ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26fdd8ULL; PB_CALL(202, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_26fce4;
    cpu->regs[0] = 0ULL;
    goto L_26fd44;
L_26fde4:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x26fdecULL; PB_CALL(203, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26fdec:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26fd08;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26fe00ULL; PB_CALL(204, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26fd08;
L_26fe04:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26fd78;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26fd78;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26fe20ULL; PB_CALL(205, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_26fd44;
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 16)); PB_LDR(cpu->regs[23], (cpu->regs[21] + 16) + 8);
    if ((cpu->regs[22])==0) goto L_26ff48;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x26fe6cULL; PB_CALL(206, cpu, tlb, PB_BASE + 0xdb480ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26ff48;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 224));
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[20] + 24ULL;
L_26fe8c:
    FLAG_CMP(cpu->regs[19], cpu->regs[23]);
    if (FLAG_GE) goto L_26fec8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26fe9cULL; PB_CALL(207, cpu, tlb, cpu->regs[24]);
    if ((cpu->regs[0])==0) goto L_26feac;
    PB_STR((cpu->regs[25] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_26fe8c;
L_26feac:
    cpu->regs[30] = PB_BASE + 0x26feb0ULL; PB_CALL(208, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_26ff50;
    if ((cpu->regs[19])==0) goto L_26ff04;
L_26feb8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x26fec4ULL; PB_CALL(209, cpu, tlb, PB_BASE + 0xe2100ULL);
    PB_LDR(cpu->regs[20], (SP + 0));
L_26fec8:
    PB_LDR(cpu->regs[25], (SP + 80));
L_26fecc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_26ff70;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_26ff04:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_26ff28;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[21] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_26ff28;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26ff28;
    cpu->regs[30] = PB_BASE + 0x26ff28ULL; PB_CALL(210, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_26ff28:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_26ff78;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26ff78;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26ff44ULL; PB_CALL(211, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 80));
L_26ff48:
    cpu->regs[20] = 0ULL;
    goto L_26fecc;
L_26ff50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26ff60ULL; PB_CALL(212, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26ff04;
    cpu->regs[30] = PB_BASE + 0x26ff68ULL; PB_CALL(213, cpu, tlb, PB_BASE + 0x121fa0ULL);
    if ((cpu->regs[19])==0) goto L_26ff04;
    goto L_26feb8;
L_26ff70:
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x26ff78ULL; PB_CALL(214, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26ff78:
    PB_LDR(cpu->regs[25], (SP + 80));
    cpu->regs[20] = 0ULL;
    goto L_26fecc;
    { PB_CALL(215, cpu, tlb, PB_BASE + 0x238ec0ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    if ((cpu->regs[2])!=0) goto L_270084;
L_26ffa4:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
L_26ffb0:
    PB_LDR(cpu->regs[20], (cpu->regs[24] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26ffbcULL; PB_CALL(216, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270168;
    cpu->regs[24] = cpu->regs[24] + 24ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[0] + 24ULL;
    cpu->regs[19] = 0ULL;
L_26ffd4:
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_GE) goto L_26fff4;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + (cpu->regs[19] << 3)));
    cpu->regs[30] = PB_BASE + 0x26ffe4ULL; PB_CALL(217, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_2700d4;
    PB_STR((cpu->regs[25] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_26ffd4;
L_26fff4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26fffcULL; PB_CALL(218, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2700d4;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[4] = cpu->regs[19] + 24ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + 0));
L_27001c:
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_27003c;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    PB_STR((cpu->regs[4] + (cpu->regs[2] << 3)), cpu->regs[3]);
    cpu->regs[1] = ((uint32_t)((FLAG_NE) ? cpu->regs[1] : (~0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : (0ULL + 1);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_27001c;
L_27003c:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27017c;
L_270040:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 304));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x270050ULL; PB_CALL(219, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_270100;
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    PB_STR((cpu->regs[0] + 32), cpu->regs[21]); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[19]);
    if (FLAG_NE) goto L_270174;
L_270068:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STR((cpu->regs[0] + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_270074:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_270084:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_26ffa4;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_26ffa4;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_270140;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = 44528ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x2700c4ULL; PB_CALL(220, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270140;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    goto L_26ffb0;
L_2700d4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_270130;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_270130;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2700f0ULL; PB_CALL(221, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[25], (SP + 64));
L_2700f8:
    cpu->regs[0] = 0ULL;
    goto L_270074;
L_270100:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_27011c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_27011c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27011cULL; PB_CALL(222, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_27011c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_270130;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_270184;
L_270130:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_270074;
L_270140:
    cpu->regs[30] = PB_BASE + 0x270144ULL; PB_CALL(223, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_2700f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3576ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x270160ULL; PB_CALL(224, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_270074;
L_270168:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    goto L_270074;
L_270174:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    goto L_270068;
L_27017c:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[1]);
    goto L_270040;
L_270184:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27018cULL; PB_CALL(225, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_270074;
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 40));
    if ((cpu->regs[26])==0) goto L_270358;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_2703b8;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_270260;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x2701e0ULL; PB_CALL(226, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2703b8;
    cpu->regs[25] = cpu->regs[0] + 24ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = 0ULL;
L_2701f4:
    FLAG_CMP(cpu->regs[19], cpu->regs[26]);
    if (FLAG_GE) goto L_270244;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[24] = cpu->regs[19] + 2ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[24] << 3);
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 8));
    if ((cpu->regs[22])==0) goto L_27022c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x270218ULL; PB_CALL(227, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2702dc;
L_270220:
    PB_STR((cpu->regs[25] + (cpu->regs[19] << 3)), cpu->regs[20]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_2701f4;
L_27022c:
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_270220;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_270220;
L_270244:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_27024c:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_270260:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_270274;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_270274:
    cpu->regs[25] = cpu->regs[23] + 24ULL;
    cpu->regs[19] = 0ULL;
L_27027c:
    FLAG_CMP(cpu->regs[19], cpu->regs[26]);
    if (FLAG_GE) goto L_2702c0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[24] = cpu->regs[19] + 2ULL;
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[24] << 3);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    if ((cpu->regs[22])==0) goto L_2703c4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2702a0ULL; PB_CALL(228, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270360;
L_2702a8:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + (cpu->regs[19] << 3)));
    PB_STR((cpu->regs[25] + (cpu->regs[19] << 3)), cpu->regs[20]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2703dc;
L_2702b8:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_27027c;
L_2702c0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -16));
    if ((cpu->regs[0])!=0) goto L_270244;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x2702d0ULL; PB_CALL(229, cpu, tlb, PB_BASE + 0xd9444ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_27024c;
L_2702dc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_270330;
    cpu->regs[30] = PB_BASE + 0x2702f0ULL; PB_CALL(230, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_270330;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2703f4;
L_270304:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[24] = cpu->regs[1] + (cpu->regs[24] << 3);
    PB_STR((cpu->regs[24] + 8), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_270220;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_270220;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x27032cULL; PB_CALL(231, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_270220;
L_270330:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[21] + 24), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2703b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2703b4;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x270350ULL; PB_CALL(232, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_270358:
    cpu->regs[23] = 0ULL;
    goto L_27024c;
L_270360:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_270330;
    cpu->regs[30] = PB_BASE + 0x270374ULL; PB_CALL(233, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_270330;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2703fc;
L_270388:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[24] = cpu->regs[1] + (cpu->regs[24] << 3);
    PB_STR((cpu->regs[24] + 8), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2702a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2702a8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2703b0ULL; PB_CALL(234, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2702a8;
L_2703b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_2703b8:
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_27024c;
L_2703c4:
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2702a8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_2702a8;
L_2703dc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2702b8;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x2703f0ULL; PB_CALL(235, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27027c;
L_2703f4:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_270304;
L_2703fc:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_270388;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x27041cULL; PB_CALL(236, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[30] = PB_BASE + 0x270424ULL; PB_CALL(237, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x27042cULL; PB_CALL(238, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x270434ULL; PB_CALL(239, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x270440ULL; PB_CALL(240, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_270454;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_270460;
L_270454:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_270460:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(241, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 47952ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[0] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x270494ULL; PB_CALL(242, cpu, tlb, PB_BASE + 0x225b60ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_2704b8;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 680ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(243, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2704b8:
    cpu->regs[2] = cpu->regs[20] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 8080));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2704e4;
L_2704c8:
    cpu->regs[0] = 24464ULL;
    cpu->regs[2] = cpu->regs[20] + cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3632ULL;
    { PB_CALL(244, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2704e4:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[0]);
    goto L_2704c8;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x270504ULL; PB_CALL(245, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_27053c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_270528;
    if (((cpu->regs[0] >> 63) & 1)) goto L_270554;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_270524:
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
L_270528:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_270530:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_27053c:
    cpu->regs[30] = PB_BASE + 0x270540ULL; PB_CALL(246, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_27055c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_270524;
    goto L_270528;
L_270554:
    cpu->regs[1] = 0ULL;
    goto L_270524;
L_27055c:
    cpu->regs[0] = 0ULL;
    goto L_270530;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_270594;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x270590ULL; PB_CALL(247, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270604;
L_270594:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_2705a8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2705a4ULL; PB_CALL(248, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270604;
L_2705a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_2705bc;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2705b8ULL; PB_CALL(249, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270604;
L_2705bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_2705d0;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2705ccULL; PB_CALL(250, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270604;
L_2705d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_2705e4;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2705e0ULL; PB_CALL(251, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270604;
L_2705e4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_270604;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_270604:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    { PB_CALL(252, cpu, tlb, PB_BASE + 0x234d00ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x27063cULL; PB_CALL(253, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_270654;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_27069c;
L_270654:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_270688;
L_270660:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x270668ULL; PB_CALL(254, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_27067c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2706a4;
L_27067c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_270688:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_270660;
    cpu->regs[30] = PB_BASE + 0x270698ULL; PB_CALL(255, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_270660;
L_27069c:
    cpu->regs[30] = PB_BASE + 0x2706a0ULL; PB_CALL(256, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_270654;
L_2706a4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(257, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    goto L_2706c4;
L_2706c4:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x2706f0ULL; PB_CALL(258, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_270798;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[3], (cpu->regs[19] + 32) + 8);
    if ((cpu->regs[0])!=0) goto L_270714;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3640ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(259, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_270714:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 48));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2707a8;
    cpu->regs[0] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x270728ULL; PB_CALL(260, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270794;
    cpu->regs[22] = cpu->regs[0] + 24ULL;
    cpu->regs[20] = 0ULL;
L_270738:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 40));
    FLAG_CMP(cpu->regs[3], cpu->regs[20]);
    if (FLAG_LE) goto L_270760;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x270750ULL; PB_CALL(261, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])==0) goto L_270780;
    PB_STR((cpu->regs[22] + (cpu->regs[20] << 3)), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_270738;
L_270760:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[4] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 3656ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(262, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_270780:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_270794;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2707c4;
L_270794:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_270798:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2707a8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[2] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[0] = cpu->regs[0] + 3648ULL;
    { PB_CALL(263, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2707c4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2707ccULL; PB_CALL(264, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_270798;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x270814ULL; PB_CALL(265, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_270914;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_2708fc;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[21] = cpu->regs[21] + 24ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_2708fc;
L_270844:
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LE) goto L_27088c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x270854ULL; PB_CALL(266, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_27091c;
L_270860:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[22] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[20];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] & ~(((uint64_t)((int64_t)cpu->regs[1] >> 63)));
    PB_STR((cpu->regs[0] + (cpu->regs[20] << 3)), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    goto L_270844;
L_27088c:
    cpu->regs[30] = PB_BASE + 0x270890ULL; PB_CALL(267, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270914;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 40));
    cpu->regs[6] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
L_2708a4:
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_LE) goto L_2708d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 16) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[1] << 3)));
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_2708cc;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_2708cc:
    PB_STR((cpu->regs[6] + (cpu->regs[1] << 3)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_2708a4;
L_2708d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 32), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x2708e4ULL; PB_CALL(268, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_2708ec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2708fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x270914ULL; PB_CALL(269, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_270914:
    cpu->regs[0] = 0ULL;
    goto L_2708ec;
L_27091c:
    cpu->regs[30] = PB_BASE + 0x270920ULL; PB_CALL(270, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_270860;
    cpu->regs[0] = 0ULL;
    goto L_2708ec;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 48));
    PB_STR((SP + 64), cpu->regs[25]);
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16)); PB_LDR(cpu->regs[24], (cpu->regs[20] + 16) + 8);
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32)); PB_LDR(cpu->regs[25], (cpu->regs[20] + 32) + 8);
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270a98;
    if ((cpu->regs[19])==0) goto L_270a44;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_270aa0;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x270978ULL; PB_CALL(271, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270a90;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[20] + 32), cpu->regs[21]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_270998;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_270ac0;
L_270998:
    cpu->regs[2] = cpu->regs[23] - 1ULL;
    cpu->regs[19] = cpu->regs[25] - 1ULL;
L_2709a0:
    if (((cpu->regs[19] >> 63) & 1)) goto L_270a90;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + (cpu->regs[19] << 3)));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_270a1c;
    cpu->regs[22] = cpu->regs[22] + (cpu->regs[0] << 3);
    cpu->regs[20] = cpu->regs[0] + 1ULL;
    cpu->regs[23] = cpu->regs[21] + 24ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 32));
L_2709c0:
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_GE) goto L_2709f0;
    PB_STR((cpu->regs[24] + (cpu->regs[19] << 3)), cpu->regs[20]);
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_270a3c;
L_2709d8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + (cpu->regs[19] << 3)));
    PB_STR((cpu->regs[23] + (cpu->regs[19] << 3)), cpu->regs[22]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_270a24;
L_2709e8:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_2709c0;
L_2709f0:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_270a00;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_270a00:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_270a1c:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    goto L_2709a0;
L_270a24:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_2709e8;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x270a38ULL; PB_CALL(272, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2709c0;
L_270a3c:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_2709d8;
L_270a44:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x270a4cULL; PB_CALL(273, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270a90;
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_2709f0;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[3] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
L_270a6c:
    FLAG_CMP(cpu->regs[1], cpu->regs[25]);
    if (FLAG_GE) goto L_2709f0;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_270a84;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_270a84:
    PB_STR((cpu->regs[3] + (cpu->regs[1] << 3)), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_270a6c;
L_270a90:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[20] + 48), cpu->regs[0]);
L_270a98:
    cpu->regs[21] = 0ULL;
    goto L_270a00;
L_270aa0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -16));
    if ((cpu->regs[0])==0) goto L_270ab0;
    cpu->regs[21] = cpu->regs[19];
    goto L_270998;
L_270ab0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x270abcULL; PB_CALL(274, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_270998;
L_270ac0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x270ac8ULL; PB_CALL(275, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_270998;
L_270acc:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_270afc;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x270af8ULL; PB_CALL(276, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270b30;
L_270afc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_270b10;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x270b0cULL; PB_CALL(277, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270b30;
L_270b10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_270b30;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_270b30:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_270b70;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x270b6cULL; PB_CALL(278, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270b90;
L_270b70:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_270b90;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_270b90:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x270bb8ULL; PB_CALL(279, cpu, tlb, PB_BASE + 0x18cd00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_270bf0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_270bd8:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_270bfc;
L_270be4:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_270bf0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_270bd8;
L_270bfc:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_270be4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x270c38ULL; PB_CALL(280, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_270d24;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_270d0c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_270d0c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[22] = cpu->regs[22] + 24ULL;
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    cpu->regs[21] = cpu->regs[21] - 1ULL;
L_270c6c:
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LE) goto L_270c9c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x270c7cULL; PB_CALL(281, cpu, tlb, PB_BASE + 0xe5240ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_270d2c;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[21] : cpu->regs[0];
L_270c88:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[1] + (cpu->regs[20] << 3)), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    goto L_270c6c;
L_270c9c:
    cpu->regs[30] = PB_BASE + 0x270ca0ULL; PB_CALL(282, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_270d24;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 40));
    cpu->regs[6] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
L_270cb4:
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_LE) goto L_270ce8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 16) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[1] << 3)));
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_270cdc;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_270cdc:
    PB_STR((cpu->regs[6] + (cpu->regs[1] << 3)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_270cb4;
L_270ce8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 32), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x270cf4ULL; PB_CALL(283, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_270cfc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_270d0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x270d24ULL; PB_CALL(284, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_270d24:
    cpu->regs[0] = 0ULL;
    goto L_270cfc;
L_270d2c:
    cpu->regs[30] = PB_BASE + 0x270d30ULL; PB_CALL(285, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_270c88;
    cpu->regs[0] = 0ULL;
    goto L_270cfc;
    /* nop */
    goto L_270acc;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_270d74;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x270d70ULL; PB_CALL(286, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270da8;
L_270d74:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_270d88;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x270d84ULL; PB_CALL(287, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_270da8;
L_270d88:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_270da8;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_270da8:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    goto L_270dc4;
L_270dc4:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x270df0ULL; PB_CALL(288, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_270e10;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = cpu->regs[0] + 3688ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(289, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_270e10:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 47952ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x270e44ULL; PB_CALL(290, cpu, tlb, PB_BASE + 0x225b60ULL);
    if ((cpu->regs[0])==0) goto L_270e80;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_270e6c;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 680ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(291, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_270e6c:
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x270e78ULL; PB_CALL(292, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_270e90;
L_270e80:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_270e90:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = cpu->regs[0] + 3632ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(293, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x270ec0ULL; PB_CALL(294, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_270ef8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_270ee4;
    if (((cpu->regs[0] >> 63) & 1)) goto L_270f10;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_270ee0:
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
L_270ee4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_270eec:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_270ef8:
    cpu->regs[30] = PB_BASE + 0x270efcULL; PB_CALL(295, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_270f18;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_270ee0;
    goto L_270ee4;
L_270f10:
    cpu->regs[1] = 0ULL;
    goto L_270ee0;
L_270f18:
    cpu->regs[0] = 0ULL;
    goto L_270eec;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_270f90;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_270f5c;
    cpu->regs[30] = PB_BASE + 0x270f4cULL; PB_CALL(296, cpu, tlb, PB_BASE + 0x129680ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_270f80;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_270fb4;
L_270f5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x270f64ULL; PB_CALL(297, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[3], (cpu->regs[19] + 24) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 3712ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(298, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_270f80:
    cpu->regs[30] = PB_BASE + 0x270f84ULL; PB_CALL(299, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_270f5c;
    cpu->regs[30] = PB_BASE + 0x270f8cULL; PB_CALL(300, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_270f5c;
L_270f90:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x270f98ULL; PB_CALL(301, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 3696ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(302, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_270fb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x270fbcULL; PB_CALL(303, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 3704ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(304, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    /* nop */
    /* nop */
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x27100cULL; PB_CALL(305, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_27104c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_271038;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[3], (cpu->regs[19] + 24) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 3688ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(306, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271038:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3728ULL;
    { PB_CALL(307, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_27104c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x27108cULL; PB_CALL(308, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_271148;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[3], (cpu->regs[19] + 16) + 8);
    if ((cpu->regs[2])==0) goto L_2710cc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3664));
    cpu->regs[0] = cpu->regs[0] + 3752ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3184));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[4] : cpu->regs[5];
    { PB_CALL(309, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2710cc:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2710d4ULL; PB_CALL(310, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_271148;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    if ((cpu->regs[3])==0) goto L_27110c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[4] = 33112ULL;
    cpu->regs[2] = PB_BASE + 0x2a8000ULL;
    cpu->regs[2] = cpu->regs[2] + 4080ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x271100ULL; PB_CALL(311, cpu, tlb, PB_BASE + 0x1d604cULL);
    if ((cpu->regs[0])==0) goto L_271134;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_271158;
L_27110c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3736ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3664));
    { PB_CALL(312, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271134:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_271148;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_27116c;
L_271148:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_271158:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_27110c;
    cpu->regs[30] = PB_BASE + 0x271168ULL; PB_CALL(313, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27110c;
L_27116c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x271174ULL; PB_CALL(314, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_271148;
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x2711c8ULL; PB_CALL(315, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_271280;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_STR((SP + 16), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_271268;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3312));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = SP + 12ULL;
    cpu->regs[1] = cpu->regs[1] + 3768ULL;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x2711fcULL; PB_CALL(316, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_271280;
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_271214;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_271214:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x271220ULL; PB_CALL(317, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((cpu->regs[19] + 32), 0ULL);
    PB_LDRW(cpu->regs[1], (SP + 12));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    PB_STRW((cpu->regs[19] + 40), cpu->regs[1]);
L_27123c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_271288;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_271268:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x271280ULL; PB_CALL(318, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_271280:
    cpu->regs[0] = 0ULL;
    goto L_27123c;
L_271288:
    cpu->regs[30] = PB_BASE + 0x27128cULL; PB_CALL(319, cpu, tlb, PB_BASE + 0x7c170ULL);
    goto L_271290;
L_271290:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2712bcULL; PB_CALL(320, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2712dc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[4], (cpu->regs[19] + 24) + 8);
    cpu->regs[0] = cpu->regs[0] + 3776ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(321, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2712dc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    goto L_2712f0;
L_2712f0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x271320ULL; PB_CALL(322, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_27134c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x27132cULL; PB_CALL(323, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    if (((cpu->regs[1] >> 31) & 1)) goto L_27134c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
L_271340:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_27134c:
    cpu->regs[0] = 0ULL;
    goto L_271340;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[1] + 3688ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[3] + 8) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    { PB_CALL(324, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    /* nop */
    /* nop */
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2713acULL; PB_CALL(325, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2713f4;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[6], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    if ((cpu->regs[6])!=0) goto L_2713d0;
L_2713bc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3688ULL;
    { PB_CALL(326, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2713d0:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 40));
    if ((cpu->regs[4])==0) goto L_2713bc;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 48));
    if ((cpu->regs[5])==0) goto L_2713bc;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3784ULL;
    { PB_CALL(327, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2713f4:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x271430ULL; PB_CALL(328, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_27148c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 56));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_271460;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 3688ULL;
    { PB_CALL(329, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271460:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 47952ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x271474ULL; PB_CALL(330, cpu, tlb, PB_BASE + 0x225b60ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[2] + 688ULL;
    { PB_CALL(331, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_27148c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x2714e8ULL; PB_CALL(332, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2715d0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_2715b8;
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = SP;
    cpu->regs[1] = cpu->regs[1] + 1656ULL;
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x271514ULL; PB_CALL(333, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2715d0;
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2715b0;
L_271528:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x271534ULL; PB_CALL(334, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_271548;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_271548:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x271554ULL; PB_CALL(335, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2715a8;
L_271564:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x271570ULL; PB_CALL(336, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_271578:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2715a4;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_2715a4:
    cpu->regs[30] = PB_BASE + 0x2715a8ULL; PB_CALL(337, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2715a8:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_271564;
L_2715b0:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_271528;
L_2715b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2715d0ULL; PB_CALL(338, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2715d0:
    cpu->regs[0] = 0ULL;
    goto L_271578;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x27160cULL; PB_CALL(339, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 88));
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_NE) goto L_271660;
L_27161c:
    if ((cpu->regs[20])!=0) goto L_2716c0;
L_271620:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_2716a4;
L_27162c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 888));
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 80));
    cpu->regs[30] = PB_BASE + 0x271644ULL; PB_CALL(340, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_271674;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_26e3e0;
L_271660:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 296));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_271620;
    goto L_27161c;
L_271674:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[0] + 3800ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[30] = PB_BASE + 0x271690ULL; PB_CALL(341, cpu, tlb, PB_BASE + 0x23b310ULL);
L_271690:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2716a4:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3800ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2716b8ULL; PB_CALL(342, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27162c;
    goto L_271690;
L_2716c0:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 3800ULL;
    cpu->regs[30] = PB_BASE + 0x2716d0ULL; PB_CALL(343, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_271620;
    goto L_271690;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x27170cULL; PB_CALL(344, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2717b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_271750;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2717c0;
    cpu->regs[30] = PB_BASE + 0x271728ULL; PB_CALL(345, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2717b0;
L_271730:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = cpu->regs[0] + 3824ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 40)); PB_LDR(cpu->regs[6], (cpu->regs[19] + 40) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(346, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271750:
    cpu->regs[30] = PB_BASE + 0x271754ULL; PB_CALL(347, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2717b0;
    cpu->regs[30] = PB_BASE + 0x271760ULL; PB_CALL(348, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_271778;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_27179c;
L_271778:
    if ((cpu->regs[2])==0) goto L_2717b0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3816ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    { PB_CALL(349, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_27179c:
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x2717a8ULL; PB_CALL(350, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    goto L_271778;
L_2717b0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2717c0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2717d8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_2717d8:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    goto L_271730;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x271814ULL; PB_CALL(351, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_27184c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x271820ULL; PB_CALL(352, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_271844;
L_27182c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[19] + 48), cpu->regs[3]);
L_271838:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_271844:
    cpu->regs[30] = PB_BASE + 0x271848ULL; PB_CALL(353, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_27182c;
L_27184c:
    cpu->regs[0] = 0ULL;
    goto L_271838;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x271880ULL; PB_CALL(354, cpu, tlb, PB_BASE + 0xdb480ULL);
    if ((cpu->regs[0])==0) goto L_2718f0;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_27189c;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
L_27189c:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] += 24; PB_STR(cpu->regs[0], cpu->regs[3]);
L_2718a8:
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_GE) goto L_2718d8;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[1] << 3);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 24));
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_2718d0;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[3]);
L_2718d0:
    PB_STR((cpu->regs[0] + (cpu->regs[1] << 3)), cpu->regs[4]);
    goto L_2718a8;
L_2718d8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x2ac000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3592ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(355, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_2718f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x27192cULL; PB_CALL(356, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 104));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_2719c0;
L_27193c:
    if ((cpu->regs[21])!=0) goto L_271984;
L_271940:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_2719a0;
L_27194c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x271954ULL; PB_CALL(357, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_271998;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x27196cULL; PB_CALL(358, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_2719d4;
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, 0ULL);
L_271974:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_271984:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 3840ULL;
    cpu->regs[30] = PB_BASE + 0x271994ULL; PB_CALL(359, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_271940;
L_271998:
    cpu->regs[0] = 0ULL;
    goto L_271974;
L_2719a0:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3840ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2719b4ULL; PB_CALL(360, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27194c;
    cpu->regs[0] = 0ULL;
    goto L_271974;
L_2719c0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_271940;
    goto L_27193c;
L_2719d4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_271998;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_271998;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2719f0ULL; PB_CALL(361, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_271974;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[20], (cpu->regs[0] + 16) + 8);
    if ((cpu->regs[0])==0) goto L_271acc;
    if ((cpu->regs[20])==0) goto L_271a90;
L_271a1c:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_271a30;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_271a30:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x271a3cULL; PB_CALL(362, cpu, tlb, cpu->regs[1]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_271ad4;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x271a54ULL; PB_CALL(363, cpu, tlb, PB_BASE + 0xe1204ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x271a68ULL; PB_CALL(364, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_271a7c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_271b74;
L_271a7c:
    PB_LDR(cpu->regs[21], (SP + 32));
L_271a80:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_271a90:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x271a9cULL; PB_CALL(365, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x271aacULL; PB_CALL(366, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[20])==0) goto L_271b38;
    if ((cpu->regs[0])!=0) goto L_271a1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_271acc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_271b48;
L_271acc:
    cpu->regs[19] = 0ULL;
    goto L_271a80;
L_271ad4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_271af8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_271af8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_271af8;
    cpu->regs[30] = PB_BASE + 0x271af8ULL; PB_CALL(367, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_271af8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_271b18;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_271b18;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_271b84;
L_271b18:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_271b2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_271b60;
L_271b2c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[19] = 0ULL;
    goto L_271a80;
L_271b38:
    if ((cpu->regs[0])==0) goto L_271acc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_271acc;
L_271b48:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_271acc;
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x271b5cULL; PB_CALL(368, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_271a80;
L_271b60:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x271b6cULL; PB_CALL(369, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_271a80;
L_271b74:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x271b7cULL; PB_CALL(370, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_271a80;
L_271b84:
    cpu->regs[30] = PB_BASE + 0x271b88ULL; PB_CALL(371, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_271b18;
    { PB_CALL(372, cpu, tlb, PB_BASE + 0x222924ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x271bbcULL; PB_CALL(373, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_271cd8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_271be4;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 48));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = cpu->regs[0] + 3640ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(374, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271be4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_271ca0;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x271c00ULL; PB_CALL(375, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_271cc0;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0] + 24ULL;
    cpu->regs[20] = 0ULL;
L_271c14:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_GE) goto L_271c38;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x271c28ULL; PB_CALL(376, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])==0) goto L_271cbc;
    PB_STR((cpu->regs[23] + (cpu->regs[20] << 3)), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_271c14;
L_271c38:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x271c40ULL; PB_CALL(377, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_271cbc;
    cpu->regs[23] = cpu->regs[0] + 24ULL;
    cpu->regs[20] = 0ULL;
L_271c50:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 48));
    FLAG_CMP(cpu->regs[3], cpu->regs[20]);
    if (FLAG_LE) goto L_271c78;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x271c68ULL; PB_CALL(378, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])==0) goto L_271ce8;
    PB_STR((cpu->regs[23] + (cpu->regs[20] << 3)), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_271c50;
L_271c78:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[5] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[4] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 3856ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(379, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271ca0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    cpu->regs[0] = cpu->regs[0] + 3648ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(380, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_271cbc:
    PB_LDR(cpu->regs[23], (SP + 48));
L_271cc0:
    cpu->regs[22] = 0ULL;
L_271cc4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x271cccULL; PB_CALL(381, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x271cd4ULL; PB_CALL(382, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_271cd8:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_271ce8:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_271cc4;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x271d38ULL; PB_CALL(383, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_271ec8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_271f0c;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2640));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = SP + 8ULL;
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[1] + 3872ULL;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x271d6cULL; PB_CALL(384, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_271ec8;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_271ee8;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[22] = cpu->regs[21] - 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 48));
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_271ee8;
L_271da8:
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_GE) goto L_271ddc;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x271dc0ULL; PB_CALL(385, cpu, tlb, PB_BASE + 0xe5240ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_271ed8;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[22] : cpu->regs[0];
L_271dcc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    PB_STR((cpu->regs[1] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_271da8;
L_271ddc:
    cpu->regs[19] = 0ULL;
L_271de0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LE) goto L_271e24;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x271dfcULL; PB_CALL(386, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_271ebc;
    if (FLAG_EQ) goto L_271ed0;
    cpu->regs[1] = cpu->regs[21] - cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_271e14:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_STR((cpu->regs[0] + (cpu->regs[19] << 3)), cpu->regs[1]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_271de0;
L_271e24:
    cpu->regs[30] = PB_BASE + 0x271e28ULL; PB_CALL(387, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_271ec4;
    cpu->regs[5] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
L_271e3c:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_271e70;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[20] + 16) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[1] << 3)));
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_271e64;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_271e64:
    PB_STR((cpu->regs[5] + (cpu->regs[1] << 3)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_271e3c;
L_271e70:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    PB_STR((cpu->regs[20] + 40), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x271e7cULL; PB_CALL(388, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_271e88:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_271eb4;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_271eb4:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x271ebcULL; PB_CALL(389, cpu, tlb, PB_BASE + 0x7c170ULL);
L_271ebc:
    cpu->regs[30] = PB_BASE + 0x271ec0ULL; PB_CALL(390, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_271ed0;
L_271ec4:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
L_271ec8:
    cpu->regs[0] = 0ULL;
    goto L_271e88;
L_271ed0:
    cpu->regs[1] = 1ULL;
    goto L_271e14;
L_271ed8:
    cpu->regs[30] = PB_BASE + 0x271edcULL; PB_CALL(391, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_271dcc;
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_271ec8;
L_271ee8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x271f00ULL; PB_CALL(392, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_271e88;
L_271f0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x271f24ULL; PB_CALL(393, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_271e88;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_271f44;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[1] - cpu->regs[0];
    { PB_CALL(394, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_271f44:
    cpu->regs[0] = 0ULL;
    { PB_CALL(395, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_271f6c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_271f6c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    { PB_CALL(396, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_271f6c:
    cpu->regs[0] = 0ULL;
    { PB_CALL(397, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x271fb4ULL; PB_CALL(398, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2720b0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_272098;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[20] = 0ULL;
    cpu->regs[22] = cpu->regs[22] + 24ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_272098;
L_271fe0:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_GE) goto L_272024;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x271ff0ULL; PB_CALL(399, cpu, tlb, PB_BASE + 0xe5240ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_2720c0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[20] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if ((cpu->regs[2])==0) goto L_2720dc;
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
L_272014:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[20] << 3)), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_271fe0;
L_272024:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27202cULL; PB_CALL(400, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2720b0;
    cpu->regs[4] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
L_27203c:
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_LT) goto L_272068;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x272050ULL; PB_CALL(401, cpu, tlb, PB_BASE + 0x18d760ULL);
L_272050:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_272058:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_272068:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 16) + 8);
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2720b8;
L_27208c:
    PB_STR((cpu->regs[4] + (cpu->regs[1] << 3)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_27203c;
L_272098:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2720b0ULL; PB_CALL(402, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2720b0:
    cpu->regs[0] = 0ULL;
    goto L_272058;
L_2720b8:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_27208c;
L_2720c0:
    cpu->regs[30] = PB_BASE + 0x2720c4ULL; PB_CALL(403, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_2720b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[20] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_2720e8;
L_2720dc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 40), cpu->regs[0]);
    goto L_272050;
L_2720e8:
    cpu->regs[1] = 0ULL;
    goto L_272014;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x27211cULL; PB_CALL(404, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2721d4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27214c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_272164;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 112ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(405, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_27214c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 2184ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(406, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_272164:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[2] + 16));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x272174ULL; PB_CALL(407, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2721d0;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0] + 24ULL;
    cpu->regs[20] = 0ULL;
L_272188:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_LT) goto L_2721b4;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[3] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 3880ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(408, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2721b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x2721c0ULL; PB_CALL(409, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])==0) goto L_2721e4;
    PB_STR((cpu->regs[23] + (cpu->regs[20] << 3)), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_272188;
L_2721d0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_2721d4:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_2721e4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2721f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_272204;
L_2721f8:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2721d4;
L_272204:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27220cULL; PB_CALL(410, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2721d4;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[20], (cpu->regs[0] + 8) + 8);
    cpu->regs[30] = PB_BASE + 0x272238ULL; PB_CALL(411, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_272260;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3888ULL;
    { PB_CALL(412, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_272260:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 3704ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(413, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    /* nop */
    /* nop */
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2722acULL; PB_CALL(414, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2722d0;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    if (((cpu->regs[3] >> 63) & 1)) goto L_2722e0;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3640ULL;
    { PB_CALL(415, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2722d0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2722e0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3904ULL;
    { PB_CALL(416, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    goto L_270dc4;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_27231c;
    cpu->regs[0] = 2ULL;
    { PB_CALL(417, cpu, tlb, PB_BASE + 0xe1204ULL); return; };
L_27231c:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3664));
    cpu->regs[0] = 3ULL;
    { PB_CALL(418, cpu, tlb, PB_BASE + 0xe0f0cULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x272358ULL; PB_CALL(419, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 152));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_2723ac;
L_272368:
    if ((cpu->regs[21])!=0) goto L_272394;
L_27236c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_2723c0;
L_272378:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 888));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    { PB_CALL(420, cpu, tlb, PB_BASE + 0x20894cULL); return; };
L_272394:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 3912ULL;
    cpu->regs[30] = PB_BASE + 0x2723a4ULL; PB_CALL(421, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27236c;
    goto L_2723d8;
L_2723ac:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_27236c;
    goto L_272368;
L_2723c0:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3912ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2723d4ULL; PB_CALL(422, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272378;
L_2723d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x272418ULL; PB_CALL(423, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_272438;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[0] + 3920ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(424, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_272438:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x272474ULL; PB_CALL(425, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2724e8;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x272480ULL; PB_CALL(426, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2724e8;
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 24));
    cpu->regs[6] = cpu->regs[19] + 40ULL;
    cpu->regs[1] = 0ULL;
L_272494:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_2724bc;
    PB_LDR(cpu->regs[4], (cpu->regs[6] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_2724f8;
L_2724ac:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 24));
    PB_STR((cpu->regs[0] + (((uint64_t)(uint32_t)(cpu->regs[1])) << 3)), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_272494;
L_2724bc:
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 32));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    FLAG_CMP(cpu->regs[5], 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 3936ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[5] : cpu->regs[4];
    { PB_CALL(427, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_2724e8:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2724f8:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
    goto L_2724ac;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x27252cULL; PB_CALL(428, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 160));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_2725e0;
L_27253c:
    if ((cpu->regs[20])!=0) goto L_272668;
L_272540:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_NE) goto L_272648;
L_27254c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[20], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_272684;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 888));
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 160));
    cpu->regs[30] = PB_BASE + 0x272570ULL; PB_CALL(429, cpu, tlb, PB_BASE + 0x208b84ULL);
    if ((cpu->regs[0])==0) goto L_272640;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 16));
    cpu->regs[3] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[4], 57ULL);
    if (FLAG_GT) goto L_272624;
L_272588:
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_LE) goto L_2725b4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[5], (cpu->regs[2] + (((uint64_t)(uint32_t)(cpu->regs[1])) << 3)));
    PB_STR((cpu->regs[3] + (cpu->regs[1] << 3)), cpu->regs[5]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_272588;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_272588;
L_2725b4:
    PB_STRW((cpu->regs[0] + 24), cpu->regs[4]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[4], 57ULL);
    if (FLAG_EQ) goto L_2725f4;
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_NE) goto L_272624;
L_2725d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2725e0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_272540;
    goto L_27253c;
L_2725f4:
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_2725d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 160));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_272624;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_27261c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_27261c:
    PB_STR((cpu->regs[0] + 32), cpu->regs[19]);
    goto L_2725d0;
L_272624:
    cpu->regs[30] = PB_BASE + 0x272628ULL; PB_CALL(430, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x272640ULL; PB_CALL(431, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_272640:
    cpu->regs[0] = 0ULL;
    goto L_2725d0;
L_272648:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 3944ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x27265cULL; PB_CALL(432, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27254c;
    cpu->regs[0] = 0ULL;
    goto L_2725d0;
L_272668:
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 3944ULL;
    cpu->regs[30] = PB_BASE + 0x272678ULL; PB_CALL(433, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272540;
    cpu->regs[0] = 0ULL;
    goto L_2725d0;
L_272684:
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 312ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 3944ULL;
    cpu->regs[30] = PB_BASE + 0x2726a4ULL; PB_CALL(434, cpu, tlb, PB_BASE + 0x23b310ULL);
    cpu->regs[0] = 0ULL;
    goto L_2725d0;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x2726f4ULL; PB_CALL(435, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2727ac;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_2727b4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = SP + 12ULL;
    cpu->regs[1] = cpu->regs[1] + 3768ULL;
    cpu->regs[3] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 160));
    cpu->regs[30] = PB_BASE + 0x272724ULL; PB_CALL(436, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2727ac;
    PB_LDRW(cpu->regs[0], (SP + 12));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(57ULL)));
    if (FLAG_HI) goto L_272794;
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_272748;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_272748:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x272754ULL; PB_CALL(437, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (SP + 12));
    PB_STRW((cpu->regs[19] + 24), cpu->regs[1]);
L_272764:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_272790;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_272790:
    cpu->regs[30] = PB_BASE + 0x272794ULL; PB_CALL(438, cpu, tlb, PB_BASE + 0x7c170ULL);
L_272794:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3984ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2727acULL; PB_CALL(439, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2727ac:
    cpu->regs[0] = 0ULL;
    goto L_272764;
L_2727b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2727ccULL; PB_CALL(440, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_272764;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3360));
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x27280cULL; PB_CALL(441, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2728a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x27281cULL; PB_CALL(442, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2728a0;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[4] = 0ULL;
L_27282c:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 16));
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]));
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    cpu->regs[1] = cpu->regs[6] + (cpu->regs[3] << 3);
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LE) goto L_27286c;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_272888;
    PB_LDRW(cpu->regs[5], (cpu->regs[1] + 0));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + 1ULL)); FLAG_CMP(cpu->regs[5], 0);
    if (FLAG_EQ) goto L_27285c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[5]);
L_27285c:
    cpu->regs[3] = cpu->regs[2] + (cpu->regs[3] << 3);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
    goto L_27282c;
L_27286c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 48));
    cpu->regs[0] = cpu->regs[0] + 4008ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(443, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_272888:
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x272890ULL; PB_CALL(444, cpu, tlb, PB_BASE + 0xdb548ULL);
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 40));
    goto L_27285c;
L_2728a0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3360));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x2728e0ULL; PB_CALL(445, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_272910;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_272918;
L_2728f0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    PB_STR((cpu->regs[20] + 48), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x2728fcULL; PB_CALL(446, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_272904:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_272910:
    cpu->regs[0] = 0ULL;
    goto L_272904;
L_272918:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_2728f0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_272950;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x27294cULL; PB_CALL(447, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272998;
L_272950:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_272964;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x272960ULL; PB_CALL(448, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272998;
L_272964:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    if ((cpu->regs[0])==0) goto L_272978;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x272974ULL; PB_CALL(449, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272998;
L_272978:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    if ((cpu->regs[0])==0) goto L_272998;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_272998:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_2729f4;
L_2729c0:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_272a1c;
L_2729e8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2729f4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x272a0cULL; PB_CALL(450, cpu, tlb, PB_BASE + 0x116fa0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_2729e8;
    goto L_2729c0;
L_272a1c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_2729e8;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_272a54;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x272a50ULL; PB_CALL(451, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272a88;
L_272a54:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_272a68;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x272a64ULL; PB_CALL(452, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272a88;
L_272a68:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_272a88;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_272a88:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_272ad0;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x272accULL; PB_CALL(453, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272b04;
L_272ad0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_272ae4;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x272ae0ULL; PB_CALL(454, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_272b04;
L_272ae4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_272b04;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_272b04:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
}
