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

void ft__PyDictView_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_1a3d60;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_1a3d84;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1a3d2cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a3d78;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1a3d44;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1a3d44:
    PB_STR((cpu->regs[5] + 16), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1a3d50ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd9444ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
L_1a3d54:
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a3d60:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 4571ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1a3d70ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[5] = 0ULL;
    goto L_1a3d54;
L_1a3d78:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[5] = 0ULL;
    goto L_1a3d54;
L_1a3d84:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2736));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 2880ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0x1a3da4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[5] = 0ULL;
    goto L_1a3d54;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1a40e0;
L_1a3dd8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a40d0;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 36ULL;
    cpu->regs[30] = PB_BASE + 0x1a3df0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f98;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 37ULL;
    cpu->regs[30] = PB_BASE + 0x1a3e10ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3fc8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 38ULL;
    cpu->regs[30] = PB_BASE + 0x1a3e30ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a4010;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 50ULL;
    cpu->regs[30] = PB_BASE + 0x1a3e50ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a40e8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 39ULL;
    cpu->regs[30] = PB_BASE + 0x1a3e70ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a4070;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 40ULL;
    cpu->regs[30] = PB_BASE + 0x1a3e90ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a4088;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 41ULL;
    cpu->regs[30] = PB_BASE + 0x1a3eb0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3ff8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 42ULL;
    cpu->regs[30] = PB_BASE + 0x1a3ed0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3fe0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 43ULL;
    cpu->regs[30] = PB_BASE + 0x1a3ef0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a4028;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 44ULL;
    cpu->regs[30] = PB_BASE + 0x1a3f10ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a4058;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 45ULL;
    cpu->regs[30] = PB_BASE + 0x1a3f30ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a40a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x1a3f50ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a40b8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a3f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x1a3f70ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1a4040;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1a3f78:
    cpu->regs[3] = 0ULL;
L_1a3f7c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1a3f84:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a3f98:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1a3fa4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
L_1a3fac:
    cpu->regs[30] = PB_BASE + 0x1a3fb0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1a3f78;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1a3f84;
L_1a3fc8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1a3fd4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a3fe0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x1a3fecULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a3ff8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1a4004ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a4010:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1a401cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a4028:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1a4034ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a4040:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 13ULL;
    cpu->regs[30] = PB_BASE + 0x1a404cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a4058:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1a4064ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a4070:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x1a407cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a4088:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x1a4094ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a40a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x1a40acULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a40b8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1a40c4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
L_1a40d0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1a3f84;
L_1a40e0:
    cpu->regs[30] = PB_BASE + 0x1a40e4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a3dd8;
L_1a40e8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1a40f4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1a7180ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 272ULL;
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x1a410cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1a6840ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a3f7c;
    goto L_1a3fac;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1a4134;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2304));
    { PB_CALL(34, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
L_1a4134:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a4194;
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_1a41bc;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[1] = 32ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1a4174ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a41b4;
    PB_STR((cpu->regs[0] + 0), cpu->regs[19]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[20]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[0] + 24), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1a4188:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1a4194:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 2920ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a41acULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a4188;
L_1a41b4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1a4188;
L_1a41bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 2968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a41d4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a4188;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1a41f0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1a41fcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a4274;
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[0] = cpu->regs[6];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[1] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x1a4248ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a4294;
    cpu->regs[1] = 12ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 32), cpu->regs[22]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[20]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a4268:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a4274:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a428cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a4268;
L_1a4294:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1a4268;
}
