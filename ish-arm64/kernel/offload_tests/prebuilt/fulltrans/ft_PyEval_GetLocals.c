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

void ft_PyEval_GetLocals(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = cpu->tls_ptr;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xc6c50ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[4], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0xc6c64ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x280648ULL);
    if ((cpu->regs[0])!=0) goto L_c6c88;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2936));
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[2] = cpu->regs[2] + 400ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xc6c84ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_c6c98;
L_c6c88:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xc6c90ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d2a8cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c6ca0;
L_c6c98:
    cpu->regs[0] = 0ULL;
    goto L_c6ca4;
L_c6ca0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
L_c6ca4:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xc6cc8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1db1b0ULL);
    if ((cpu->regs[0])==0) goto L_c6d68;
    cpu->regs[21] = PB_BASE + 0x3db000ULL;
    cpu->regs[21] = cpu->regs[21] + 2816ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[21] + 1760ULL;
L_c6cdc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[0])==0) goto L_c6d6c;
    cpu->regs[30] = PB_BASE + 0xc6ce8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[20])==0) goto L_c6d44;
    cpu->regs[30] = PB_BASE + 0xc6cfcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11e710ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_c6d44;
    if (FLAG_EQ) goto L_c6d18;
L_c6d08:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_c6d2c;
    goto L_c6d3c;
L_c6d18:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6d24ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c6d08;
    goto L_c6d44;
L_c6d2c:
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c6d3c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6d3cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6d3c:
    cpu->regs[21] = cpu->regs[21] + 8ULL;
    goto L_c6cdc;
L_c6d44:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c6d60;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c6d60;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6d60ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6d60:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6d68ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
L_c6d68:
    cpu->regs[19] = 0ULL;
L_c6d6c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 113));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c6db8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc6db4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c6df8;
L_c6db8:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c6dd4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[0], 3ULL);
    if (FLAG_GT) goto L_c6e00;
L_c6dd4:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 3344ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0xc6df8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
L_c6df8:
    cpu->regs[0] = 0ULL;
    goto L_c6fdc;
L_c6e00:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc6e10ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x13e388ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c6df8;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6e28ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x230fe0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c6e50;
    if (((cpu->regs[2] >> 31) & 1)) goto L_c6df8;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c6df8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6e4cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c6df8;
L_c6e50:
    if (((cpu->regs[2] >> 31) & 1)) goto L_c6e68;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c6e68;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6e68ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6e68:
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_c6ef4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc6e80ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x989b0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c6df8;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc6e98ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x231410ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c6eac;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6ea8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_c6df8;
L_c6eac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[22] << 2;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_HS) goto L_c6ecc;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_HS) goto L_c6ee0;
    goto L_c6edc;
L_c6ecc:
    if (FLAG_LS) goto L_c6ee0;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_c6ee0;
L_c6edc:
    __builtin_trap();
L_c6ee0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6ee8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6ef0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_c6ef8;
L_c6ef4:
    cpu->regs[22] = 0ULL;
L_c6ef8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    PB_STR((cpu->regs[19] + 32), cpu->regs[22]);
    if (((cpu->regs[1] >> 24) & 1)) goto L_c6f2c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3408ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc6f28ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c6df8;
L_c6f2c:
    cpu->regs[30] = PB_BASE + 0xc6f30ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c6f44;
    cpu->regs[30] = PB_BASE + 0xc6f3cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_c6f48;
    goto L_c6df8;
L_c6f44:
    if (!((cpu->regs[0] >> 63) & 1)) goto L_c6f64;
L_c6f48:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc6f60ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c6df8;
L_c6f64:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 48));
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_c6fb8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_c6fa8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc6fa4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c6df8;
L_c6fa8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 144));
    if ((cpu->regs[0])==0) goto L_c6fc4;
    cpu->regs[30] = PB_BASE + 0xc6fb4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1904c0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_c6df8;
L_c6fb8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_c6fdc;
L_c6fc4:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c6fd4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_c6fd4:
    PB_STR((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_c6fb8;
L_c6fdc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c7018;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_GT) goto L_c7040;
L_c7018:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 3560ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0xc703cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c70a4;
L_c7040:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[30] = PB_BASE + 0xc7048ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x230d20ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c70a4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    PB_STR((cpu->regs[19] + 24), 0ULL); PB_STR((cpu->regs[19] + 24) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc705cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x175a60ULL);
    if ((cpu->regs[0])==0) goto L_c70a4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c7078;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c7078;
    cpu->regs[30] = PB_BASE + 0xc7078ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c7078:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (((cpu->regs[1] >> 24) & 1)) goto L_c70ac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc70a4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x11f220ULL);
L_c70a4:
    cpu->regs[0] = 0ULL;
    goto L_c7160;
L_c70ac:
    cpu->regs[30] = PB_BASE + 0xc70b0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe5240ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c70c4;
    cpu->regs[30] = PB_BASE + 0xc70bcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_c70c8;
    goto L_c70a4;
L_c70c4:
    if (!((cpu->regs[0] >> 63) & 1)) goto L_c70e4;
L_c70c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc70e0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c70a4;
L_c70e4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 40));
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_c7108;
L_c70fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_c7160;
L_c7108:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_c7134;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3680ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7130ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c70a4;
L_c7134:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_c7148;
    cpu->regs[30] = PB_BASE + 0xc7140ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1904c0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c70fc;
    goto L_c70a4;
L_c7148:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c7158;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_c7158:
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    goto L_c70fc;
L_c7160:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x520000ULL;
    cpu->regs[21] = cpu->regs[21] + 16ULL;
    cpu->regs[21] = cpu->regs[21] + 2096ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc719cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    if ((cpu->regs[0])!=0) goto L_c71b0;
    cpu->regs[30] = PB_BASE + 0xc71a4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc71b0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x14b8f0ULL);
L_c71b0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0xc71c0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c71d0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    goto L_c71d8;
L_c71d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
L_c71d8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_c7240;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 48));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[4] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xc7208ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1987c8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c7238;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc7218ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1904c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c7248;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c7238;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c7238;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc7238ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c7238:
    cpu->regs[19] = 0ULL;
    goto L_c7248;
L_c7240:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2400));
L_c7248:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
