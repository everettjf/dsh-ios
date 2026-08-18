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

void ft__PyBytesWriter_Prepare(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = cpu->regs[1];
    if ((cpu->regs[2])==0) goto L_11dbd4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = 9223372036854775807ULL;
    cpu->regs[5] = cpu->regs[5] - cpu->regs[2];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_GT) goto L_11dbdc;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_LT) goto L_11dbc0;
L_11dbac:
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
L_11dbb0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_11dbc0:
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x11dbc8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c6c40ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    cpu->regs[4] = cpu->regs[0];
    goto L_11dbac;
L_11dbd4:
    cpu->regs[0] = cpu->regs[1];
    return;
L_11dbdc:
    cpu->regs[30] = PB_BASE + 0x11dbe0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11dbe8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
    cpu->regs[4] = 0ULL;
    goto L_11dbb0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    if ((cpu->regs[20])==0) goto L_11dd98;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_11de68;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[3])!=0) goto L_11de2c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[2] = 1ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + 10));
    PB_LDRB(cpu->regs[5], (cpu->regs[1] + 9));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 24));
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[5] & 63);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_11dd38;
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[0] << 4);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_GE) goto L_11dd7c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    if ((cpu->regs[2])==0) goto L_11ddf4;
L_11dc60:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0)); PB_LDR(cpu->regs[22], (cpu->regs[1] + 0) + 8);
    if ((cpu->regs[2])==0) goto L_11dd64;
L_11dc6c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 40));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 48), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_11dda0;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24)); PB_LDR(cpu->regs[19], (cpu->regs[20] + 24) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_11dcec;
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[20] + 24), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_11dd00;
L_11dcac:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[20] + 32), cpu->regs[22]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_11dd14;
L_11dcbc:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11dd20;
L_11dcc8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_11dddc;
L_11dcd0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -16));
    if ((cpu->regs[0])==0) goto L_11de90;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_11dcdc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_11dcec:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[20] + 24), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_11dcac;
L_11dd00:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[20] + 32), cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_11dcbc;
L_11dd14:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_11dcc8;
    /* nop */
L_11dd20:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11dcc8;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x11dd34ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11dcc8;
L_11dd38:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[0] << 1);
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[4] << 3);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_GE) goto L_11dd7c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    if ((cpu->regs[2])==0) goto L_11dea0;
L_11dd58:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 8)); PB_LDR(cpu->regs[22], (cpu->regs[1] + 8) + 8);
    if ((cpu->regs[2])!=0) goto L_11dc6c;
L_11dd64:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11dd7cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_11dd7c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11dd94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_11de18;
L_11dd94:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_11dd98:
    cpu->regs[20] = 0ULL;
    goto L_11dcdc;
L_11dda0:
    cpu->regs[30] = PB_BASE + 0x11dda4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x187fc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11dd94;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_11ddbc;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_11ddbc:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[20] + 24), cpu->regs[21]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_11ddd0;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_11ddd0:
    PB_STR((cpu->regs[20] + 32), cpu->regs[22]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_11dcdc;
L_11dddc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_11dcd0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11ddf0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11dcd0;
L_11ddf4:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_11dd7c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    if ((cpu->regs[2])==0) goto L_11ddf4;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_GT) goto L_11dc60;
    goto L_11dd7c;
L_11de18:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x11de24ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_11dcdc;
L_11de2c:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_11dd7c;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 32));
    cpu->regs[5] = cpu->regs[3] - cpu->regs[0];
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    PB_LDRB(cpu->regs[6], (cpu->regs[4] + 9));
    PB_LDRB(cpu->regs[5], (cpu->regs[5] + -3));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[6] & 63);
    cpu->regs[1] = cpu->regs[1] + (((cpu->regs[5]) & 0xffffffffULL) << 4);
    cpu->regs[4] = cpu->regs[4] + cpu->regs[1];
    PB_LDR(cpu->regs[22], (cpu->regs[3] + (cpu->regs[5] << 3)));
    PB_LDR(cpu->regs[21], (cpu->regs[4] + 32));
    if ((cpu->regs[2])!=0) goto L_11dc6c;
    goto L_11dd64;
L_11de68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3264ULL;
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11de84ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    goto L_11dcdc;
L_11de90:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x11de98ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd9444ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_11dcdc;
L_11dea0:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = cpu->regs[1] + 24ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_11dd7c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    if ((cpu->regs[2])==0) goto L_11dea0;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_GT) goto L_11dd58;
    goto L_11dd7c;
}
