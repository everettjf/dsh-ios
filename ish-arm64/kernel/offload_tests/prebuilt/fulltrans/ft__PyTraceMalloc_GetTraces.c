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

void ft__PyTraceMalloc_GetTraces(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_9f774:
    SP = SP - 112ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, 0ULL);
    PB_STR((SP + 32), 0ULL);
    PB_STRW((SP + 48), 0ULL);
    cpu->regs[30] = PB_BASE + 0x9f7b0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((SP + 40), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_9f8e8;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 2708));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_9f934;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2512));
    cpu->regs[4] = SP;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3824));
    cpu->regs[3] = PB_BASE + 0x89000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3456));
    cpu->regs[3] = cpu->regs[3] + 292ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2312));
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 0), cpu->regs[6]); PB_STR((SP + 0) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x9f800ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1825a0ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_9f8e4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2840));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x9f814ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2888));
    cpu->regs[30] = PB_BASE + 0x9f81cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x8f710ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2840));
    PB_STR((SP + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x9f82cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])==0) goto L_9f8e4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2840));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x9f840ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 2896));
    cpu->regs[30] = PB_BASE + 0x9f848ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x182710ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9f870;
    cpu->regs[1] = PB_BASE + 0x8f000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1888ULL;
    cpu->regs[30] = PB_BASE + 0x9f864ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x8f67cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9f874;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9f870ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x144810ULL);
L_9f870:
    cpu->regs[20] = 0ULL;
L_9f874:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2840));
    PB_STR((SP + 24), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x9f880ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    if ((cpu->regs[0])==0) goto L_9f8e4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[19] + 2928ULL;
    cpu->regs[21] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x9f89cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x182ae0ULL);
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x9f000ULL;
    cpu->regs[1] = cpu->regs[1] + 1244ULL;
    cpu->regs[30] = PB_BASE + 0x9f8b0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x8f67cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9f8d0;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x8f000ULL;
    cpu->regs[1] = cpu->regs[1] + 1780ULL;
    cpu->regs[30] = PB_BASE + 0x9f8ccULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x8f67cULL);
    cpu->regs[20] = cpu->regs[0];
L_9f8d0:
    cpu->regs[0] = cpu->regs[19] + 2928ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9f8dcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x182ae0ULL);
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_9f8e8;
    goto L_9f90c;
L_9f8e4:
    cpu->regs[30] = PB_BASE + 0x9f8e8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x22d780ULL);
L_9f8e8:
    PB_LDR(cpu->regs[0], (SP + 40));
    if ((cpu->regs[0])==0) goto L_9f90c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 40), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_9f90c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9f90c;
    cpu->regs[30] = PB_BASE + 0x9f90cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9f90c:
    PB_LDR(cpu->regs[0], (SP + 32));
    if ((cpu->regs[0])==0) goto L_9f918;
    cpu->regs[30] = PB_BASE + 0x9f918ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x144810ULL);
L_9f918:
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])==0) goto L_9f924;
    cpu->regs[30] = PB_BASE + 0x9f924ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x144810ULL);
L_9f924:
    PB_LDR(cpu->regs[0], (SP + 24));
    if ((cpu->regs[0])==0) goto L_9f930;
    cpu->regs[30] = PB_BASE + 0x9f930ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x144810ULL);
L_9f930:
    PB_LDR(cpu->regs[0], (SP + 40));
L_9f934:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9f954;
    cpu->regs[30] = PB_BASE + 0x9f954ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9f954:
    PB_LDR(cpu->regs[21], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
    goto L_9f774;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[2])==0) goto L_9fb3c;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_9f9bc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9f9b8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9f9d0;
L_9f9bc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1320));
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x9f9c8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9f9d8;
L_9f9d0:
    cpu->regs[21] = 0ULL;
    goto L_9fb44;
L_9f9d8:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9f9e8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fb18;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1832));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9fa00ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9fb1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fa24;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fa24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fa24ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fa24:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9fa34ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fb18;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1512));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9fa4cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9fb1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fa70;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fa70;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fa70ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fa70:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[3] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[3] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x9fa88ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fb18;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1488));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9faa0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9fb1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fac4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fac4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fac4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fac4:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[23] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x9faccULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fb18;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1496));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9fae4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9fb1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fb08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fb08;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fb08ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fb08:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_9fb44;
L_9fb18:
    cpu->regs[19] = 0ULL;
L_9fb1c:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x9fb30ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9fb38ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_9f9d0;
L_9fb3c:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_9fb44:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[2])==0) goto L_9fe14;
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_9fbac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9fba8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9fe0c;
L_9fbac:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[22] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_9fc54;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_9fc68;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_9fcd4;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1032));
    cpu->regs[30] = PB_BASE + 0x9fbd4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fde8;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9fc00;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9fc00:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1664));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fc10ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9fdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fc34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fc34;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fc34ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fc34:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9fc44ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1264));
    goto L_9fca0;
L_9fc54:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 848));
    cpu->regs[30] = PB_BASE + 0x9fc5cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9fc78;
    goto L_9fde8;
L_9fc68:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1024));
    cpu->regs[30] = PB_BASE + 0x9fc70ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fde8;
L_9fc78:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9fc9c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9fc9c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1664));
L_9fca0:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fcacULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9fdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fcd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fcd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fcd0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9fcd8;
L_9fcd4:
    cpu->regs[20] = 0ULL;
L_9fcd8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x9fce0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1616));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fcf8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fd18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fd18;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fd18ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fd18:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 28),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x9fd20ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1304));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fd38ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fd58;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fd58;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fd58ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fd58:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x9fd60ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1392));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fd78ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fd98;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fd98;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fd98ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fd98:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 36),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x9fda0ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9fdf0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1384));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fdb8ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fdf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9fdd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9fdd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9fdd8ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9fdd8:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_9fe1c;
L_9fde8:
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
L_9fdf0:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x9fe04ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9fe0cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdce4cULL);
L_9fe0c:
    cpu->regs[20] = 0ULL;
    goto L_9fe1c;
L_9fe14:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_9fe1c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_9fe34:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    if ((cpu->regs[2])==0) goto L_a03a4;
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_9fe84;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9fe80ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a039c;
L_9fe84:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[22] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_a003c;
    if (FLAG_HI) goto L_9febc;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_9ff44;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_9ff58;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_9fedc;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_9ff08;
    goto L_9fed4;
L_9febc:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_a017c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8ULL)));
    if (FLAG_EQ) goto L_a0204;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_a0164;
L_9fed4:
    cpu->regs[20] = 0ULL;
    goto L_a0268;
L_9fedc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 704));
    cpu->regs[30] = PB_BASE + 0x9fee4ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9fefcULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9ff3c;
    goto L_a0380;
L_9ff08:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 688));
    cpu->regs[30] = PB_BASE + 0x9ff10ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9ff3c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9ff3c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1920));
    goto L_a0238;
L_9ff44:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 680));
    cpu->regs[30] = PB_BASE + 0x9ff4cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a0214;
    goto L_a0378;
L_9ff58:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 664));
    cpu->regs[30] = PB_BASE + 0x9ff60ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[3] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x9ff80ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1528));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9ff98ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9ffbc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9ffbc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9ffbcULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9ffbc:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = PB_BASE + 0x9f000ULL;
    cpu->regs[3] = cpu->regs[3] + 3636ULL;
    cpu->regs[30] = PB_BASE + 0x9ffd4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1744));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9ffecULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0010;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0010;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0010ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0010:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a0034;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a0034:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1760));
    goto L_a0238;
L_a003c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 656));
    cpu->regs[30] = PB_BASE + 0xa0044ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa005cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1288));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0074ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0098;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0098;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0098ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0098:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[24] = PB_BASE + 0x9f000ULL;
    cpu->regs[3] = cpu->regs[24] + 3636ULL;
    cpu->regs[30] = PB_BASE + 0xa00b0ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1744));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa00c8ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a00ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a00ec;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa00ecULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a00ec:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = PB_BASE + 0x87000ULL;
    cpu->regs[3] = cpu->regs[3] + 484ULL;
    cpu->regs[30] = PB_BASE + 0xa0104ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1576));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa011cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0140;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0140;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0140ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0140:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 32));
    cpu->regs[3] = cpu->regs[24] + 3636ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0154ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1584));
    goto L_a0238;
L_a0164:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 696));
    cpu->regs[30] = PB_BASE + 0xa016cULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    goto L_a01dc;
L_a017c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 648));
    cpu->regs[30] = PB_BASE + 0xa0184ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa019cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x9fe34ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1728));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa01b4ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a01d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a01d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa01d8ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a01d8:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 16));
L_a01dc:
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a01fc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a01fc:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1664));
    goto L_a0238;
L_a0204:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 672));
    cpu->regs[30] = PB_BASE + 0xa020cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0378;
L_a0214:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = PB_BASE + 0x9f000ULL;
    cpu->regs[3] = cpu->regs[3] + 3636ULL;
    cpu->regs[30] = PB_BASE + 0xa022cULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1744));
L_a0238:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0244ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0268;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0268;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0268ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0268:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 40),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa0270ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1616));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0288ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a02a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a02a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa02a8ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a02a8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 44),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa02b0ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1304));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa02c8ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a02e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a02e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa02e8ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a02e8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 48),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa02f0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1392));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0308ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0328;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0328;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0328ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0328:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 52),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa0330ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0380;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1384));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0348ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0368;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0368;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0368ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0368:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_a03ac;
L_a0378:
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
L_a0380:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xa0394ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa039cULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xdce4cULL);
L_a039c:
    cpu->regs[20] = 0ULL;
    goto L_a03ac;
L_a03a4:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_a03ac:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[2])==0) goto L_a0550;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_a0414;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa0410ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a0428;
L_a0414:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1632));
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xa0420ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a0430;
L_a0428:
    cpu->regs[21] = 0ULL;
    goto L_a0558;
L_a0430:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa0440ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x9fe34ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a052c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1728));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0458ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0530;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a047c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a047c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa047cULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a047c:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa048cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a052c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1464));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa04a4ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0530;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a04c8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a04c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa04c8ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a04c8:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[3] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[3] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0xa04e0ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a052c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa04f8ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0530;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a051c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a051c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa051cULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a051c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_a0558;
L_a052c:
    cpu->regs[19] = 0ULL;
L_a0530:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xa0544ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa054cULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_a0428;
L_a0550:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_a0558:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[2])==0) goto L_a06a8;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_a05c0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa05bcULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a05d4;
L_a05c0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1944));
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xa05ccULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a05dc;
L_a05d4:
    cpu->regs[21] = 0ULL;
    goto L_a06b0;
L_a05dc:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa05ecULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0684;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1328));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0604ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0688;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0628;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0628;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0628ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0628:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa0638ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0684;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1712));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0650ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a0688;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0674;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0674;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0674ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0674:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_a06b0;
L_a0684:
    cpu->regs[19] = 0ULL;
L_a0688:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xa069cULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa06a4ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_a05d4;
L_a06a8:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_a06b0:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[2])==0) goto L_a0970;
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_a0718;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa0714ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a0968;
L_a0718:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[23] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_a0834;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 312));
    cpu->regs[30] = PB_BASE + 0xa0730ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0948;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0748ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a094c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1856));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0760ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0784;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0784;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0784ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0784:
    PB_LDR(cpu->regs[19], (cpu->regs[23] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a07a8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a07a8:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1664));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa07b8ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a07dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a07dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa07dcULL; PB_CALL(135, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a07dc:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 24));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[3] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0xa07f4ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a094c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa080cULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0838;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0838;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0830ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a0838;
L_a0834:
    cpu->regs[20] = 0ULL;
L_a0838:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[23] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa0840ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a094c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1616));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0858ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0878;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0878;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0878ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0878:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[23] + 36),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa0880ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a094c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1304));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0898ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a08b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a08b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa08b8ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a08b8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[23] + 40),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa08c0ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a094c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1392));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa08d8ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a08f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a08f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa08f8ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a08f8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[23] + 44),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xa0900ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a094c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1384));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0918ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a094c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a0938;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a0938;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0938ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0938:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_a0978;
L_a0948:
    cpu->regs[19] = 0ULL;
L_a094c:
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[22] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xa0960ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0968ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdce4cULL);
L_a0968:
    cpu->regs[20] = 0ULL;
    goto L_a0978;
L_a0970:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_a0978:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
