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

void ft__PyUnicode_ToUpperFull(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x27cd54ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x10a220ULL);
    PB_LDRH(cpu->regs[1], (cpu->regs[0] + 14));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 14) & 1)) goto L_27cd74;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[6]));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[1]);
L_27cd6c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_27cd74:
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] & 65535ULL));
    cpu->regs[2] = PB_BASE + 0x347000ULL;
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 24)));
    cpu->regs[2] = cpu->regs[2] + 2464ULL;
    cpu->regs[1] = 0ULL;
L_27cd88:
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_27cd6c;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[3])) << 2)));
    PB_STRW((cpu->regs[5] + (cpu->regs[1] << 2)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_27cd88;
    SP = SP - 144ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
    PB_STR((SP + 56), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    if ((cpu->regs[4])!=0) goto L_27ced0;
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_LE) goto L_27cf14;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[23] = cpu->regs[3];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_27ced8;
L_27cdfc:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_NE) goto L_27cf5c;
    cpu->regs[23] = 9223372036854775807ULL;
    cpu->regs[22] = 0ULL;
L_27ce10:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27ce18ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x15e540ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x27ce24ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27cec0;
    PB_STR((cpu->regs[19] + 16), 0ULL);
    cpu->regs[4] = cpu->regs[23];
    PB_STRW((cpu->regs[19] + 248), 0ULL);
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x27ce4cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1f8aa4ULL);
    if ((cpu->regs[0])==0) goto L_27cea4;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_27ce60;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_27ce60:
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27ce6cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1984ULL);
L_27ce6c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_27cec8;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_27cea4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_27cec0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_27cec0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27cec0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_27cec0:
    cpu->regs[19] = 0ULL;
    goto L_27ce6c;
L_27cec8:
    PB_STR((SP + 128), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x27ced0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_27ced0:
    PB_LDR(cpu->regs[23], (cpu->regs[4] + 16));
    cpu->regs[23] = cpu->regs[3] + cpu->regs[23];
L_27ced8:
    cpu->regs[0] = SP + 32ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[2] = PB_BASE + 0x522000ULL;
    cpu->regs[2] = cpu->regs[2] + 528ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[2] + 1976ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x27cf08ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_27cdfc;
    goto L_27cec0;
L_27cf14:
    cpu->regs[0] = SP + 32ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[4] + 1976ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x27cf48ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 24));
    if ((cpu->regs[0])==0) goto L_27cec0;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 0));
    cpu->regs[23] = cpu->regs[1];
L_27cf5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_27d01c;
    PB_STR((SP + 128), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x27cf6cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d00c;
    cpu->regs[30] = PB_BASE + 0x27cf78ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_27cff4;
L_27cf84:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_27d00c;
L_27cf8c:
    FLAG_CMP(cpu->regs[23], 2ULL);
    if (FLAG_EQ) goto L_27cfe8;
    PB_LDR(cpu->regs[25], (SP + 128));
L_27cf98:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x27cfa0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27cfc0;
    cpu->regs[30] = PB_BASE + 0x27cfacULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_27cfd0;
L_27cfb8:
    FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_27ce10;
L_27cfc0:
    cpu->regs[30] = PB_BASE + 0x27cfc4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_27cec0;
    cpu->regs[23] = 18446744073709551615ULL;
    goto L_27ce10;
L_27cfd0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27cfb8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27cfe4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27cfb8;
L_27cfe8:
    PB_LDR(cpu->regs[25], (SP + 128));
    cpu->regs[23] = 9223372036854775807ULL;
    goto L_27ce10;
L_27cff4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27cf84;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x27d008ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27cf84;
L_27d00c:
    cpu->regs[30] = PB_BASE + 0x27d010ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_27d024;
    cpu->regs[22] = 18446744073709551615ULL;
    goto L_27cf8c;
L_27d01c:
    cpu->regs[22] = 0ULL;
    goto L_27cf98;
L_27d024:
    PB_LDR(cpu->regs[25], (SP + 128));
    cpu->regs[19] = 0ULL;
    goto L_27ce6c;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 72));
    PB_LDRW(cpu->regs[22], (cpu->regs[24] + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27d064;
    cpu->regs[0] = 292ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[22] & cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32ULL)));
    if (FLAG_NE) goto L_27d064;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] & 4294967263ULL));
L_27d064:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x27d06cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d134;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = PB_BASE + 0x3db000ULL;
    cpu->regs[19] = cpu->regs[19] + 2816ULL;
    cpu->regs[19] = cpu->regs[19] + 2672ULL;
    cpu->regs[20] = 0ULL;
L_27d088:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 8));
    FLAG_CMP((((uint32_t)(cpu->regs[21]))) & (((uint32_t)(cpu->regs[22]))), 0);
    if (FLAG_NE) goto L_27d148;
L_27d094:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    FLAG_CMP(cpu->regs[20], 9ULL);
    if (FLAG_NE) goto L_27d088;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_27d1a4;
L_27d0a8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x27d0b0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1b0088ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_27d18c;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x27d0c4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d20c;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x27d0d4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x144c60ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_27d254;
L_27d0e0:
    if ((cpu->regs[19])==0) goto L_27d20c;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 48));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[0] + 2144ULL;
    cpu->regs[30] = PB_BASE + 0x27d0f8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d110;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_27d248;
L_27d110:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d12c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27d12c;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x27d12cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_27d12c:
    cpu->regs[23] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_27d134:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_27d148:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x27d154ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[23];
    if ((cpu->regs[25])==0) goto L_27d208;
    cpu->regs[30] = PB_BASE + 0x27d168ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_27d1f8;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d180;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_27d1ec;
L_27d180:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] & ~(cpu->regs[21])));
    goto L_27d094;
L_27d18c:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 48));
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[0] + 2168ULL;
    cpu->regs[30] = PB_BASE + 0x27d19cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_27d110;
L_27d1a4:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x27d1b4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d20c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x27d1c8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_27d214;
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d0a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27d0a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27d1e8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27d0a8;
L_27d1ec:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x27d1f4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27d180;
L_27d1f8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d208;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_27d234;
L_27d208:
    PB_LDR(cpu->regs[25], (SP + 64));
L_27d20c:
    cpu->regs[20] = 0ULL;
    goto L_27d110;
L_27d214:
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d20c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27d20c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x27d230ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27d110;
L_27d234:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x27d240ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_27d110;
L_27d248:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27d250ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27d110;
L_27d254:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27d0e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x27d268ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27d0e0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    if (((cpu->regs[0] >> 63) & 1)) goto L_27d278;
    { PB_CALL(35, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_27d278:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_27d294;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_27d294:
    return;
    /* nop */
    /* nop */
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_27d2b0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_27d2b0:
    return;
    /* nop */
    /* nop */
    /* nop */
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_27d2d0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_27d2d0:
    return;
    /* nop */
    /* nop */
    /* nop */
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_27d2f0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_27d2f0:
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
    PB_STR((SP + 40), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    if ((cpu->regs[4])!=0) goto L_27d404;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_LE) goto L_27d460;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[19] = cpu->regs[3];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_27d40c;
L_27d354:
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 0)); PB_LDR(cpu->regs[24], (cpu->regs[2] + 0) + 8);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_27d4a0;
L_27d360:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    cpu->regs[30] = PB_BASE + 0x27d368ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d3dc;
    cpu->regs[30] = PB_BASE + 0x27d374ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_27d448;
L_27d380:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_27d3dc;
L_27d388:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27d390ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x15e540ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_27d400;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    cpu->regs[5] = 1ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    SP = SP + 112ULL;
    { PB_CALL(39, cpu, tlb, PB_BASE + 0x20c94cULL); return; };
L_27d3dc:
    cpu->regs[30] = PB_BASE + 0x27d3e0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_27d4a8;
L_27d3e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_27d4b0;
L_27d400:
    cpu->regs[30] = PB_BASE + 0x27d404ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7c170ULL);
L_27d404:
    PB_LDR(cpu->regs[19], (cpu->regs[4] + 16));
    cpu->regs[19] = cpu->regs[3] + cpu->regs[19];
L_27d40c:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[6] = PB_BASE + 0x522000ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[6] = cpu->regs[6] + 528ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[7] = 0ULL;
    cpu->regs[4] = cpu->regs[6] + 2120ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x27d43cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_27d354;
    goto L_27d3e4;
L_27d448:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27d380;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x27d45cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27d380;
L_27d460:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 2120ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x27d490ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d3e4;
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 0)); PB_LDR(cpu->regs[24], (cpu->regs[2] + 0) + 8);
    goto L_27d360;
L_27d4a0:
    cpu->regs[19] = 0ULL;
    goto L_27d388;
L_27d4a8:
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_27d388;
L_27d4b0:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x27d4ecULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x16b4b0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27d534;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 80)); PB_LDR(cpu->regs[3], (cpu->regs[20] + 80) + 8);
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[0] = cpu->regs[0] + 2192ULL;
    cpu->regs[30] = PB_BASE + 0x27d510ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_27d530;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27d530;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27d530ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_27d530:
    cpu->regs[19] = cpu->regs[20];
L_27d534:
    cpu->regs[0] = cpu->regs[19];
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
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x27d568ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x15e540ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[21] - 2ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_27d620;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_27d620;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_NE) goto L_27d5b0;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_27d614;
L_27d598:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_27d5a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_27d5b0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 56));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_27d62c;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 72));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_27d62c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 80));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 80));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_27d62c;
    cpu->regs[2] = cpu->regs[2] << 2;
    cpu->regs[1] = cpu->regs[20] + 88ULL;
    cpu->regs[0] = cpu->regs[19] + 88ULL;
    cpu->regs[30] = PB_BASE + 0x27d5f0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27d62c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[2] = 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 48));
    cpu->regs[30] = PB_BASE + 0x27d604ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_27d640;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_27d638;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27d598;
L_27d614:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_27d5a0;
L_27d620:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_27d5a0;
L_27d62c:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_27d598;
    goto L_27d614;
L_27d638:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27d614;
    goto L_27d598;
L_27d640:
    cpu->regs[0] = 0ULL;
    goto L_27d5a0;
}
