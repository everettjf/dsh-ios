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

void ft__PyLong_Sign(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 3ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - cpu->regs[0]));
    return;
    /* nop */
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[25], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[24], cpu->regs[25]);
    cpu->regs[23] = (FLAG_LE) ? cpu->regs[24] : cpu->regs[25];
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_14a02c;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_149f08;
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x149e74ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14a08c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2296));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_14a0f4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    cpu->regs[26] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_14a09c;
L_149ea8:
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_149f08;
L_149eac:
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 4168));
    cpu->regs[2] = PB_BASE + 0x15d000ULL;
    cpu->regs[2] = cpu->regs[2] + 1924ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_14a13c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[3] - cpu->regs[2];
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[4] = cpu->regs[4] & 3ULL;
    cpu->regs[0] = cpu->regs[3] - cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[2] * cpu->regs[5];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    cpu->regs[0] = (FLAG_LT) ? 1 : 0;
    goto L_14a034;
L_149f08:
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_EQ) goto L_14a044;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_149f94;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x149f28ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14a08c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2296));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_14a118;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_14a0c0;
L_149f5c:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_149f94;
L_149f60:
    cpu->regs[22] = 1ULL;
L_149f64:
    cpu->regs[22] = cpu->regs[22] + 2ULL;
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[19] = cpu->regs[19] + (cpu->regs[22] << 3);
    cpu->regs[22] = cpu->regs[21] + (cpu->regs[22] << 3);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x11ebb0ULL); return; };
L_149f94:
    FLAG_CMP(cpu->regs[23], 2ULL);
    if (FLAG_EQ) goto L_14a044;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[26] = cpu->regs[21] + 24ULL;
    cpu->regs[28] = cpu->regs[19] + 24ULL;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2296));
    cpu->regs[22] = 2ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_STR((SP + 96), cpu->regs[0]);
L_149fc0:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + (cpu->regs[22] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[28] + (cpu->regs[22] << 3)));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_14a014;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x149fd8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14a088;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[27]);
    if (FLAG_NE) goto L_14a050;
    PB_LDR(cpu->regs[2], (SP + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14a0e4;
L_14a000:
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_14a014;
    FLAG_CMP(cpu->regs[23], cpu->regs[22]);
    if (FLAG_LE) goto L_14a020;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_149f64;
L_14a014:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_NE) goto L_149fc0;
L_14a020:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_14a02c:
    FLAG_CMP(cpu->regs[24], cpu->regs[25]);
    cpu->regs[0] = (FLAG_LT) ? 1 : 0;
L_14a034:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_14a044:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_14a02c;
L_14a050:
    cpu->regs[30] = PB_BASE + 0x14a054ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_14a084;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14a084;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
L_14a070:
    PB_STRW((SP + 108), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14a080ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[2], (SP + 108));
L_14a084:
    if (!((cpu->regs[2] >> 31) & 1)) goto L_14a000;
L_14a088:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_14a08c:
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_14a034;
L_14a09c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_149ea8;
L_14a0a8:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 48));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14a0b4ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
L_14a0b4:
    if (((cpu->regs[26] >> 31) & 1)) goto L_14a08c;
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_149eac;
    goto L_149f08;
L_14a0c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_149f5c;
L_14a0cc:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 48));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14a0d8ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
L_14a0d8:
    if (((cpu->regs[22] >> 31) & 1)) goto L_14a08c;
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_149f60;
    goto L_149f94;
L_14a0e4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14a070;
    goto L_14a000;
L_14a0f4:
    cpu->regs[30] = PB_BASE + 0x14a0f8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_14a0b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14a0b4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    goto L_14a0a8;
L_14a118:
    cpu->regs[30] = PB_BASE + 0x14a11cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_14a0d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14a0d8;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    goto L_14a0cc;
L_14a13c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_14a1b8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14a1b8;
L_14a194:
    cpu->regs[30] = PB_BASE + 0x14a198ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x12b728ULL);
    if ((cpu->regs[0])==0) goto L_14a1d8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? 1 : 0;
L_14a1a8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_14a1b8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14a1c0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14a1d8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    goto L_14a194;
L_14a1d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_14a1fc;
    cpu->regs[30] = PB_BASE + 0x14a1f0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14a1fc;
L_14a1f4:
    cpu->regs[19] = 4294967295ULL;
    goto L_14a1a8;
L_14a1fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x14a20cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14a1f4;
    cpu->regs[30] = PB_BASE + 0x14a214ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2592));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14a224ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe7640ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14a1f4;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14a238ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1ac644ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_14a1a8;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_14a1a8;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14a25cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14a1a8;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 4160));
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 200));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_14a3d0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x126000ULL;
    cpu->regs[2] = cpu->regs[2] + 864ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_14a354;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_14a388;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_14a388;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_14a37c;
    cpu->regs[30] = PB_BASE + 0x14a2bcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x129848ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_14a30c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2296));
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_14a328;
L_14a2e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    cpu->regs[20] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_14a33c;
L_14a2f8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_14a30c:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
L_14a314:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_14a2e0;
L_14a328:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14a330ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_14a2f8;
L_14a33c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14a2f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14a350ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14a2f8;
L_14a354:
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14a35cULL; PB_CALL(22, cpu, tlb, cpu->regs[3]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_14a390;
    if ((cpu->regs[0])!=0) goto L_14a314;
    cpu->regs[20] = 4294967295ULL;
    goto L_14a2f8;
L_14a37c:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3184));
    goto L_14a314;
L_14a388:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
L_14a390:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14a3a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14a3c0;
L_14a3a4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(23, cpu, tlb, PB_BASE + 0x11ebb0ULL); return; };
L_14a3c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    cpu->regs[30] = PB_BASE + 0x14a3ccULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14a3a4;
L_14a3d0:
    cpu->regs[2] = 0ULL;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0x11ebb0ULL); return; };
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_NE) goto L_14a484;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[0] >> 5) & 0x1ULL)));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_14a53c;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_14a518;
    cpu->regs[2] = cpu->regs[19] + 40ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_14a524;
L_14a42c:
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_14a508;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2568));
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14a4c4;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_14a534;
    cpu->regs[0] = cpu->regs[21] - 1ULL;
    cpu->regs[23] = 0ULL;
L_14a454:
    PB_LDRB(cpu->regs[3], (cpu->regs[2] + cpu->regs[0]));
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]))));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_14a49c;
L_14a460:
    cpu->regs[21] = cpu->regs[0] + 1ULL;
L_14a464:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0x134b80ULL); return; };
L_14a484:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 28) & 1)) goto L_14a5b4;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0x14a5ecULL); return; };
L_14a49c:
    cpu->regs[0] = cpu->regs[21] - 2ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_LT) goto L_14a460;
L_14a4a8:
    PB_LDRB(cpu->regs[3], (cpu->regs[2] + cpu->regs[0]));
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + cpu->regs[3]));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_14a460;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_GE) goto L_14a4a8;
    goto L_14a460;
L_14a4c4:
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_14a510;
    cpu->regs[23] = 1ULL;
L_14a4d0:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + cpu->regs[23]));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14a4f8;
L_14a4dc:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_14a464;
    cpu->regs[0] = cpu->regs[21] - 1ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_GT) goto L_14a460;
L_14a4ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2568));
    goto L_14a454;
L_14a4f8:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_NE) goto L_14a4d0;
    goto L_14a4dc;
L_14a508:
    cpu->regs[23] = 0ULL;
    goto L_14a4dc;
L_14a510:
    cpu->regs[23] = cpu->regs[21];
    goto L_14a4dc;
L_14a518:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14a42c;
L_14a524:
    cpu->regs[0] = cpu->regs[21] - 1ULL; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[23] = 0ULL;
    if (FLAG_GE) goto L_14a4ec;
    goto L_14a460;
L_14a534:
    cpu->regs[23] = 0ULL;
    goto L_14a464;
L_14a53c:
    cpu->regs[22] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_14a5ac;
    cpu->regs[24] = cpu->regs[19] + 56ULL;
L_14a548:
    cpu->regs[23] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_14a578;
L_14a554:
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_LE) goto L_14a574;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14a56cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[30] = PB_BASE + 0x14a570ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14a5a4;
L_14a574:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_14a464;
L_14a578:
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_LT) goto L_14a59c;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14a594ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[30] = PB_BASE + 0x14a598ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14a578;
L_14a59c:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_14a464;
L_14a5a4:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_14a554;
L_14a5ac:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 56));
    goto L_14a548;
L_14a5b4:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[0] = PB_BASE + 0x3da000ULL;
    cpu->regs[0] = cpu->regs[0] + 2560ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 2512ULL;
    cpu->regs[1] = cpu->regs[1] + 1672ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x14a5dcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
