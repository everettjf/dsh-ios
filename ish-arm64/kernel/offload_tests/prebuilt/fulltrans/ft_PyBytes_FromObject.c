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

void ft_PyBytes_FromObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_207bdc;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2392));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_207bbc;
    cpu->regs[30] = PB_BASE + 0x20790cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x141ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_207930;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3312));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_207940;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x22eaa0ULL); return; };
L_207930:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x21b4a0ULL); return; };
L_207940:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_2079a8;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_207b48;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x207964ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_207b10;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x207974ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x207ed0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_207b08;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_207b08;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x207994ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_207998:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_2079a8:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2079b8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_207b54;
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_207b08;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[20] = cpu->regs[0] + 32ULL;
    cpu->regs[19] = cpu->regs[19] + 24ULL;
    cpu->regs[0] = cpu->regs[21] & 3ULL; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[23] = 0ULL;
    if (FLAG_EQ) goto L_207a64;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_207a38;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_207a14;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2079fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x123dd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    cpu->regs[23] = 1ULL;
    PB_STRB((cpu->regs[20] + 0), cpu->regs[0]);
L_207a14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[23] << 3)));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x207a20ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x123dd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    PB_STRB((cpu->regs[20] + cpu->regs[23]), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
L_207a38:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[23] << 3)));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x207a44ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x123dd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    PB_STRB((cpu->regs[20] + cpu->regs[23]), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_EQ) goto L_207afc;
L_207a64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[23] << 3)));
    cpu->regs[1] = 0ULL;
    cpu->regs[24] = cpu->regs[23] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x207a74ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    PB_STRB((cpu->regs[20] + cpu->regs[23]), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[24] << 3)));
    cpu->regs[30] = PB_BASE + 0x207a98ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    PB_STRB((cpu->regs[20] + cpu->regs[24]), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[23] << 3)));
    cpu->regs[30] = PB_BASE + 0x207ab8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    PB_STRB((cpu->regs[20] + cpu->regs[23]), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[24] + 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[23] << 3)));
    cpu->regs[30] = PB_BASE + 0x207adcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x123dd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207b60;
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_207b68;
    PB_STRB((cpu->regs[20] + cpu->regs[23]), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[24] + 3ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_NE) goto L_207a64;
L_207afc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_207998;
L_207b08:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_207998;
L_207b10:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x207b20ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_207b54;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
L_207b28:
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] + 3688ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x207b40ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_207998;
L_207b48:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2736));
    goto L_207b28;
L_207b54:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[22] = 0ULL;
    goto L_207998;
L_207b60:
    cpu->regs[30] = PB_BASE + 0x207b64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_207b80;
L_207b68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 3656ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x207b80ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_207b80:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_207b94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_207ba4;
L_207b94:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_207998;
L_207ba4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x207bb0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_207998;
L_207bbc:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_207bd0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_207bd0:
    cpu->regs[22] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_207998;
L_207bdc:
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = 2858ULL;
    cpu->regs[0] = cpu->regs[0] + 1848ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x207bf4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_207998;
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x207c38ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdb480ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_207ce0;
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[21];
    cpu->regs[19] = 0ULL;
    cpu->regs[22] = 0ULL;
L_207c54:
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_LT) goto L_207cb0;
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_LE) goto L_207c78;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x207c70ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe2100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207cd4;
L_207c78:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[0], (SP + 0));
L_207c80:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_207cc8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 112ULL;
    return;
L_207cb0:
    PB_LDR(cpu->regs[23], (cpu->regs[20] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_207ce8;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_207c54;
L_207cc8:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x207cd4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_207cd4:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x207cdcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_207ce0:
    cpu->regs[0] = 0ULL;
    goto L_207c80;
L_207ce8:
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[1] = 33936ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2248));
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x207d08ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207db4;
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_207ddc;
    cpu->regs[0] = 31400ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[25] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x207d2cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207db4;
    PB_LDR(cpu->regs[23], (SP + 16));
    if ((cpu->regs[23])==0) goto L_207d6c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_207d6c;
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[22] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[25] - 1ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_207d80;
L_207d60:
    cpu->regs[0] = 0ULL;
L_207d64:
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_LT) goto L_207e04;
L_207d6c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x207d78ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[25], (SP + 96));
    goto L_207c54;
L_207d80:
    cpu->regs[24] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[0] = SP;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x207d90ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe2100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_207d60;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_207db4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_207db4;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x207db4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_207db4:
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_207dcc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_207e34;
L_207dcc:
    PB_LDR(cpu->regs[25], (SP + 96));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_207c80;
L_207ddc:
    PB_LDR(cpu->regs[1], (SP + 0));
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
L_207de8:
    FLAG_CMP(cpu->regs[22], cpu->regs[2]);
    if (FLAG_LE) goto L_207e48;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + (cpu->regs[2] << 3)));
    FLAG_CMP(cpu->regs[23], cpu->regs[4]);
    if (FLAG_EQ) goto L_207eb8;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_207de8;
L_207e04:
    cpu->regs[2] = cpu->regs[23] + 24ULL;
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[1], (SP + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[0] << 3)));
    cpu->regs[4] = cpu->regs[1] + 24ULL;
L_207e18:
    FLAG_CMP(cpu->regs[22], cpu->regs[3]);
    if (FLAG_LE) goto L_207e88;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + (cpu->regs[3] << 3)));
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_EQ) goto L_207eb0;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_207e18;
L_207e34:
    cpu->regs[30] = PB_BASE + 0x207e38ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 96));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_207c80;
L_207e48:
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_207e58;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[2]);
L_207e58:
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 3);
    cpu->regs[2] = 1ULL;
    PB_STR((cpu->regs[1] + 24), cpu->regs[23]);
L_207e64:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[22] = cpu->regs[22] + cpu->regs[2];
    if (((cpu->regs[1] >> 31) & 1)) goto L_207e7c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_207ec0;
L_207e7c:
    PB_LDR(cpu->regs[25], (SP + 96));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_207c54;
L_207e88:
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_207e98;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[3]);
L_207e98:
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 3);
    cpu->regs[3] = 1ULL;
    PB_STR((cpu->regs[1] + 24), cpu->regs[2]);
L_207ea4:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[22] = cpu->regs[22] + cpu->regs[3];
    goto L_207d64;
L_207eb0:
    cpu->regs[3] = 0ULL;
    goto L_207ea4;
L_207eb8:
    cpu->regs[2] = 0ULL;
    goto L_207e64;
L_207ec0:
    cpu->regs[30] = PB_BASE + 0x207ec4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[25], (SP + 96));
    goto L_207c54;
L_207ed0:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]);
    SP = SP - 576ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 568), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 64ULL;
    cpu->regs[30] = PB_BASE + 0x207f10ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x141b04ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_208060;
L_207f1c:
    cpu->regs[25] = SP + 16ULL;
    cpu->regs[3] = 512ULL;
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[25];
    PB_STRW((SP + 48), cpu->regs[19]);
    cpu->regs[1] = SP + 52ULL;
    PB_STR((cpu->regs[25] + 16), 0ULL); PB_STR((cpu->regs[25] + 16) + 8, 0ULL);
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x207f44ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x11db70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_208020;
    PB_LDR(cpu->regs[24], (SP + 24));
    cpu->regs[22] = 0ULL;
    PB_STRW((SP + 44), cpu->regs[19]);
    goto L_207f98;
L_207f5c:
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x207f64ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x123dd0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_208048;
L_207f70:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_207ff8;
    FLAG_CMP(cpu->regs[19], 255ULL);
    if (FLAG_HI) goto L_208000;
    FLAG_CMP(cpu->regs[22], cpu->regs[24]);
    if (FLAG_GE) goto L_208028;
L_207f88:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    PB_STRB(cpu->regs[1], cpu->regs[19]); cpu->regs[1] += 1;
    cpu->regs[21] = cpu->regs[1];
L_207f98:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x207fa0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_207f5c;
    cpu->regs[30] = PB_BASE + 0x207facULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_208018;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x207fbcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11dec4ULL);
L_207fbc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 568));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_207ff4;
    SP = SP + 576ULL;
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_207ff4:
    cpu->regs[30] = PB_BASE + 0x207ff8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c170ULL);
L_207ff8:
    cpu->regs[30] = PB_BASE + 0x207ffcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_208018;
L_208000:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 3656ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x208018ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_208018:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x208020ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
L_208020:
    cpu->regs[0] = 0ULL;
    goto L_207fbc;
L_208028:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[24] + 1ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x208038ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1c6c40ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_208020;
    PB_LDR(cpu->regs[24], (SP + 24));
    goto L_207f88;
L_208048:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_207f70;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20805cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_207f70;
L_208060:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x208068ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    if ((cpu->regs[0])==0) goto L_207f1c;
    cpu->regs[0] = 0ULL;
    goto L_207fbc;
    /* nop */
    /* nop */
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[1] + 24) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 40));
    goto L_2080a0;
    /* nop */
    /* nop */
L_2080a0:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = PB_BASE + 0x495000ULL;
    cpu->regs[5] = cpu->regs[5] + 576ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[5] + 3856ULL;
    cpu->regs[30] = PB_BASE + 0x2080d8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20813c;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_208154;
L_2080ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[5] + 16), cpu->regs[23]);
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_208184;
L_208104:
    cpu->regs[19] = 0ULL;
L_208108:
    PB_STR((cpu->regs[5] + 24), cpu->regs[19]);
    if ((cpu->regs[20])==0) goto L_208120;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_208120;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_208120:
    PB_STR((cpu->regs[5] + 32), cpu->regs[20]);
    if ((cpu->regs[22])!=0) goto L_208170;
L_208128:
    PB_STR((cpu->regs[5] + 40), cpu->regs[22]);
    if ((cpu->regs[21])!=0) goto L_20815c;
L_208130:
    PB_STR((cpu->regs[5] + 48), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x20813cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xd9444ULL);
L_20813c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_208154:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_2080ec;
L_20815c:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_208130;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_208130;
L_208170:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_208128;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_208128;
L_208184:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_208198;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_208104;
L_208198:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_208108;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_208108;
L_2081ac:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_2081dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2081dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20848c;
L_2081dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_2081fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2081fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208534;
L_2081fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_20821c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20821c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20852c;
L_20821c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_20823c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20823c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208524;
L_20823c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_20825c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20825c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20851c;
L_20825c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_20827c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20827c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208514;
L_20827c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_20829c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20829c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20850c;
L_20829c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_2082bc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2082bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208504;
L_2082bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])==0) goto L_2082dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 64), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2082dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084fc;
L_2082dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_2082fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2082fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084f4;
L_2082fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_20831c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20831c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084ec;
L_20831c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_20833c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20833c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084e4;
L_20833c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_20835c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20835c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084dc;
L_20835c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_20837c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20837c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084d4;
L_20837c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_20839c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 112), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20839c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084cc;
L_20839c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])==0) goto L_2083bc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2083bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084c4;
L_2083bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 128));
    if ((cpu->regs[0])==0) goto L_2083dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 128), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2083dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084bc;
L_2083dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 136));
    if ((cpu->regs[0])==0) goto L_2083fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 136), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2083fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084b4;
L_2083fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 144));
    if ((cpu->regs[0])==0) goto L_20841c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 144), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20841c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084ac;
L_20841c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    if ((cpu->regs[0])==0) goto L_20843c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 152), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20843c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2084a4;
L_20843c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 160));
    if ((cpu->regs[0])==0) goto L_20845c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 160), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20845c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20849c;
L_20845c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if ((cpu->regs[0])==0) goto L_20847c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 168), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20847c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208494;
L_20847c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20848c:
    cpu->regs[30] = PB_BASE + 0x208490ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2081dc;
L_208494:
    cpu->regs[30] = PB_BASE + 0x208498ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20847c;
L_20849c:
    cpu->regs[30] = PB_BASE + 0x2084a0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20845c;
L_2084a4:
    cpu->regs[30] = PB_BASE + 0x2084a8ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20843c;
L_2084ac:
    cpu->regs[30] = PB_BASE + 0x2084b0ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20841c;
L_2084b4:
    cpu->regs[30] = PB_BASE + 0x2084b8ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2083fc;
L_2084bc:
    cpu->regs[30] = PB_BASE + 0x2084c0ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2083dc;
L_2084c4:
    cpu->regs[30] = PB_BASE + 0x2084c8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2083bc;
L_2084cc:
    cpu->regs[30] = PB_BASE + 0x2084d0ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20839c;
L_2084d4:
    cpu->regs[30] = PB_BASE + 0x2084d8ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20837c;
L_2084dc:
    cpu->regs[30] = PB_BASE + 0x2084e0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20835c;
L_2084e4:
    cpu->regs[30] = PB_BASE + 0x2084e8ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20833c;
L_2084ec:
    cpu->regs[30] = PB_BASE + 0x2084f0ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20831c;
L_2084f4:
    cpu->regs[30] = PB_BASE + 0x2084f8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2082fc;
L_2084fc:
    cpu->regs[30] = PB_BASE + 0x208500ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2082dc;
L_208504:
    cpu->regs[30] = PB_BASE + 0x208508ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2082bc;
L_20850c:
    cpu->regs[30] = PB_BASE + 0x208510ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20829c;
L_208514:
    cpu->regs[30] = PB_BASE + 0x208518ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20827c;
L_20851c:
    cpu->regs[30] = PB_BASE + 0x208520ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20825c;
L_208524:
    cpu->regs[30] = PB_BASE + 0x208528ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20823c;
L_20852c:
    cpu->regs[30] = PB_BASE + 0x208530ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20821c;
L_208534:
    cpu->regs[30] = PB_BASE + 0x208538ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2081fc;
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 16));
    cpu->regs[8] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_2085fc;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[5] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_208568:
    FLAG_CMP(cpu->regs[7], 1ULL);
    if (FLAG_NE) goto L_2085a0;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_2085e4;
    PB_LDRB(cpu->regs[0], (cpu->regs[5] + 0));
L_20857c:
    cpu->regs[30] = PB_BASE + 0x208580ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x14d168ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[1] : cpu->regs[0];
L_208598:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_2085a0:
    if ((cpu->regs[7])==0) goto L_2085cc;
    cpu->regs[6] = 0ULL;
L_2085a8:
    FLAG_CMP(cpu->regs[7], cpu->regs[6]);
    if (FLAG_LE) goto L_2085d8;
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x2085c4ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[30] = PB_BASE + 0x2085c8ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x14d168ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2085a8;
L_2085cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_208598;
L_2085d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_208598;
L_2085e4:
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_2085f4;
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    goto L_20857c;
L_2085f4:
    PB_LDRH(cpu->regs[0], (cpu->regs[5] + 0));
    goto L_20857c;
L_2085fc:
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 56));
    goto L_208568;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = 0ULL;
    { PB_CALL(72, cpu, tlb, PB_BASE + 0x201b20ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    goto L_2081ac;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_208780;
L_208650:
    PB_LDR(cpu->regs[24], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_208714;
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x208664ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2086f8;
    cpu->regs[22] = 2ULL;
L_208670:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x208678ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2086dc;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    cpu->regs[30] = PB_BASE + 0x20868cULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x20894cULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_2086a4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2087bc;
L_2086a4:
    if ((cpu->regs[19])==0) goto L_2086dc;
    cpu->regs[23] = cpu->regs[21];
    cpu->regs[20] = 1ULL;
    cpu->regs[23] += 24; PB_STR(cpu->regs[23], cpu->regs[19]);
L_2086b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[20]);
    if (FLAG_LE) goto L_2086fc;
    cpu->regs[30] = PB_BASE + 0x2086c8ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x208da0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2086dc;
    PB_STR((cpu->regs[23] + (cpu->regs[20] << 3)), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_2086b4;
L_2086dc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2086f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2086f8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2086f8ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2086f8:
    cpu->regs[21] = 0ULL;
L_2086fc:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_208714:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x20871cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_208758;
    cpu->regs[30] = PB_BASE + 0x208728ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2087a4;
L_208734:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_208758;
    if (((cpu->regs[22] >> 63) & 1)) goto L_208760;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x208748ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2086f8;
    if ((cpu->regs[22])!=0) goto L_208670;
    goto L_2086fc;
L_208758:
    cpu->regs[30] = PB_BASE + 0x20875cULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_2086f8;
L_208760:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3776ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20877cULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2086fc;
L_208780:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3768ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x208798ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_208650;
    cpu->regs[21] = 0ULL;
    goto L_2086fc;
L_2087a4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_208734;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2087b8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_208734;
L_2087bc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2087c4ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2086a4;
L_2087c8:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_2087f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2087f8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208848;
L_2087f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_208818;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_208818;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208858;
L_208818:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_208838;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_208838;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208850;
L_208838:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_208848:
    cpu->regs[30] = PB_BASE + 0x20884cULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2087f8;
L_208850:
    cpu->regs[30] = PB_BASE + 0x208854ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_208838;
L_208858:
    cpu->regs[30] = PB_BASE + 0x20885cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_208818;
    goto L_2087c8;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_208894;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_208894;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208924;
L_208894:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_2088b4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2088b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208944;
L_2088b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_2088d4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2088d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20893c;
L_2088d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_2088f4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2088f4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_208934;
L_2088f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_208914;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_208914;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20892c;
L_208914:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_208924:
    cpu->regs[30] = PB_BASE + 0x208928ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_208894;
L_20892c:
    cpu->regs[30] = PB_BASE + 0x208930ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_208914;
L_208934:
    cpu->regs[30] = PB_BASE + 0x208938ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2088f4;
L_20893c:
    cpu->regs[30] = PB_BASE + 0x208940ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2088d4;
L_208944:
    cpu->regs[30] = PB_BASE + 0x208948ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2088b4;
L_20894c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x208964ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2089cc;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 152));
    cpu->regs[30] = PB_BASE + 0x208978ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2089dc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 160));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x208988ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x208b84ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_208a10;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 152));
    cpu->regs[30] = PB_BASE + 0x208998ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2089fc;
    PB_STR((cpu->regs[0] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[0] + 24), 0ULL);
    PB_STR((cpu->regs[0] + 32), 0ULL); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x2089b0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xe1984ULL);
L_2089b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2089c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2089f0;
L_2089c4:
    cpu->regs[19] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_2089cc:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2089dc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2089e8ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x208da0ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_2089b0;
L_2089f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2089f8ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2089c4;
L_2089fc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_208a10;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_208a18;
L_208a10:
    cpu->regs[21] = 0ULL;
    goto L_2089b0;
L_208a18:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x208a24ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2089b0;
}
