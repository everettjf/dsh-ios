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

void ft_PyDescr_IsData(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 280));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    return;
    /* nop */
    /* nop */
    /* nop */
L_112ac0:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_112dfc;
L_112aec:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_112d40;
L_112af8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_112b1c;
L_112b08:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1128ULL)));
    if (FLAG_EQ) goto L_112c00;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_112b08;
L_112b1c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1128ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[22] = cpu->regs[21];
    cpu->regs[23] = 6000ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x112b44ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112bec;
L_112b4c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_EQ) goto L_112df0;
L_112b60:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112d88;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_112c2c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x112b88ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x112ac0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_112c60;
L_112b90:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112d88;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112ba4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x112e04ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_112d1c;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112d28;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_112cec;
L_112bc8:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1128ULL;
    cpu->regs[30] = PB_BASE + 0x112be4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_112b4c;
L_112bec:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_112c14;
L_112c00:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_112c14:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_112c2c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112c34ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112ddc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112d88;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112c54ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x112ac0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112b90;
    /* nop */
L_112c60:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_112d54;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(19ULL)));
    if (FLAG_NE) goto L_112b90;
L_112c80:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112c90ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x112e04ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112b90;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x112ca4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_112dc4;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x112cc8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_112dac;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112d28;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_GT) goto L_112bc8;
L_112cec:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_112d1c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_112cec;
L_112d28:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_112c14;
L_112d40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112d48ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112d94;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_112af8;
L_112d54:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112d5cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112d7c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(19ULL)));
    if (FLAG_NE) goto L_112b90;
    goto L_112c80;
L_112d7c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_112d88:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112d28;
L_112d94:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112c14;
L_112dac:
    cpu->regs[30] = PB_BASE + 0x112db0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_112dd0;
L_112db4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_112cec;
    goto L_112d28;
L_112dc4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112db4;
L_112dd0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_112d28;
L_112ddc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112d28;
L_112df0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112df8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_112b60;
L_112dfc:
    cpu->regs[30] = PB_BASE + 0x112e00ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_112aec;
L_112e04:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_113100;
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_113110;
L_112e3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_112e60;
L_112e4c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1129ULL)));
    if (FLAG_EQ) goto L_112f34;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_112e4c;
L_112e60:
    cpu->regs[22] = cpu->regs[21];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = 6000ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
L_112e74:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1129ULL;
    cpu->regs[30] = PB_BASE + 0x112e88ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1131dc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_1131d0;
L_112ea4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113158;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_112f60;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[27], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x112eccULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x112e04ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_112f90;
L_112ed4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113158;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112ee8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x112e04ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11304c;
L_112ef0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113158;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112f04ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1132d0ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1130dc;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1130e8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_11301c;
L_112f28:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    goto L_112e74;
L_112f34:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_112f48:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_112f60:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112f68ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1131a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_113158;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112f88ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x112e04ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112ed4;
L_112f90:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113124;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(33ULL)));
    if (FLAG_NE) goto L_112ed4;
L_112fb0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112fc0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1132d0ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112ed4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x112fd4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1131b8;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x112ff8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1130c0;
L_113004:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1130e8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_GT) goto L_112f28;
L_11301c:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_11304c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113164;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(34ULL)));
    if (FLAG_NE) goto L_112ef0;
L_11306c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11307cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1132d0ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112ef0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113090ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1131b8;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x1130b4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_113004;
L_1130c0:
    cpu->regs[30] = PB_BASE + 0x1130c4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1131c4;
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
L_1130cc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11301c;
    goto L_1130e8;
L_1130dc:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_11301c;
L_1130e8:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_112f48;
L_113100:
    cpu->regs[30] = PB_BASE + 0x113104ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_112e3c;
L_113110:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113118ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11318c;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_112e3c;
L_113124:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11312cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11314c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(33ULL)));
    if (FLAG_NE) goto L_112ed4;
    goto L_112fb0;
L_11314c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_113158:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1130e8;
L_113164:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11316cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11314c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(34ULL)));
    if (FLAG_NE) goto L_112ef0;
    goto L_11306c;
L_11318c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112f48;
L_1131a4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1130e8;
L_1131b8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1130cc;
L_1131c4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1130e8;
L_1131d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1131d8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_112ea4;
L_1131dc:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_112f48;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 70));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_113264;
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x113220ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1136c0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_113238;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1132c0;
L_113238:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 232));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 36));
    cpu->regs[2] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_EQ) goto L_113298;
    PB_STR((cpu->regs[19] + 240), cpu->regs[20]);
L_113258:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_113264:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + -24));
    cpu->regs[4] = 4ULL;
    PB_STRB((cpu->regs[20] + -5), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[20];
    PB_STR((cpu->regs[19] + 104), cpu->regs[3]);
    PB_STR((cpu->regs[20] + -24), 0ULL);
    PB_STRW((cpu->regs[19] + 36), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x113284ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1136c0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 36), cpu->regs[0]);
    PB_STR((cpu->regs[20] + 8), 0ULL);
    goto L_113258;
L_113298:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 0) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[2] = cpu->regs[2] + 3ULL;
    cpu->regs[2] = cpu->regs[20] + (cpu->regs[2] << 3);
    PB_STR((cpu->regs[19] + 232), cpu->regs[20]); PB_STR((cpu->regs[19] + 232) + 8, cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1132b0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1f6820ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    PB_STR((cpu->regs[19] + 248), cpu->regs[20]);
    goto L_113258;
L_1132c0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1132ccULL; PB_CALL(36, cpu, tlb, cpu->regs[1]);
    goto L_113238;
L_1132d0:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1135d0;
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_1135e0;
L_113308:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_11332c;
L_113318:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1130ULL)));
    if (FLAG_EQ) goto L_113400;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_113318;
L_11332c:
    cpu->regs[22] = cpu->regs[21];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = 6000ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
L_113340:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1130ULL;
    cpu->regs[30] = PB_BASE + 0x113354ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113688;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_11369c;
L_113370:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113628;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11342c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[27], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x113398ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1132d0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_113460;
L_1133a0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113628;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1133b4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1132d0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11351c;
L_1133bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113628;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1133d0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x113a70ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1135ac;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1135b8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_1134ec;
L_1133f4:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    goto L_113340;
L_113400:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_113414:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_11342c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113434ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_113674;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_113628;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113454ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1132d0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1133a0;
    /* nop */
L_113460:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1135f4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(14ULL)));
    if (FLAG_NE) goto L_1133a0;
L_113480:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113490ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1133a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1134a4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1136a8;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1134c8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])==0) goto L_113590;
L_1134d4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1135b8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_GT) goto L_1133f4;
L_1134ec:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_11351c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113634;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(15ULL)));
    if (FLAG_NE) goto L_1133bc;
L_11353c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11354cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1133bc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113560ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1136a8;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x113584ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_1134d4;
L_113590:
    cpu->regs[30] = PB_BASE + 0x113594ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1136b4;
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
L_11359c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1134ec;
    goto L_1135b8;
L_1135ac:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1134ec;
L_1135b8:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_113414;
L_1135d0:
    cpu->regs[30] = PB_BASE + 0x1135d4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_113308;
L_1135e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1135e8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11365c;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_113308;
L_1135f4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1135fcULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11361c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(14ULL)));
    if (FLAG_NE) goto L_1133a0;
    goto L_113480;
L_11361c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_113628:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1135b8;
L_113634:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11363cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11361c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(15ULL)));
    if (FLAG_NE) goto L_1133bc;
    goto L_11353c;
L_11365c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_113414;
L_113674:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1135b8;
L_113688:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_113414;
L_11369c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1136a4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_113370;
L_1136a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_11359c;
L_1136b4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1135b8;
L_1136c0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 48));
    if ((cpu->regs[20])!=0) goto L_1138ac;
L_1136d8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1137c8;
L_1136e4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_113700;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_113700;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_11383c;
L_113700:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_1137ac;
L_113708:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_113724;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_113724;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_113858;
L_113724:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_LE) goto L_1137ac;
L_11372c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_113748;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_113748;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_113874;
L_113748:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    if (FLAG_LE) goto L_1137ac;
L_113750:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_11376c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_11376c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_113890;
L_11376c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    if (FLAG_LE) goto L_1137ac;
L_113774:
    cpu->regs[20] = 4ULL;
    /* nop */
    /* nop */
L_113780:
    cpu->regs[0] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])==0) goto L_1137a0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1137a0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_113828;
L_1137a0:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_GT) goto L_113780;
L_1137ac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_1137c8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1137c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_113808;
L_1137c8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_1137e4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1137e4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_113818;
L_1137e4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1137fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1138ec;
L_1137fc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_113808:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x113814ULL; PB_CALL(55, cpu, tlb, cpu->regs[1]);
    goto L_1137c8;
L_113818:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x113824ULL; PB_CALL(56, cpu, tlb, cpu->regs[1]);
    goto L_1137e4;
L_113828:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x113834ULL; PB_CALL(57, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    goto L_1137a0;
L_11383c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x113848ULL; PB_CALL(58, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_GT) goto L_113708;
    goto L_1137ac;
L_113858:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x113864ULL; PB_CALL(59, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_GT) goto L_11372c;
    goto L_1137ac;
L_113874:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x113880ULL; PB_CALL(60, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    if (FLAG_GT) goto L_113750;
    goto L_1137ac;
L_113890:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x11389cULL; PB_CALL(61, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    if (FLAG_GT) goto L_113774;
    goto L_1137ac;
L_1138ac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_GT) goto L_113904;
    if (((cpu->regs[0] >> 31) & 1)) goto L_1136d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1136d8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1138dcULL; PB_CALL(62, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1136e4;
    goto L_1137ac;
L_1138ec:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_113904:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 64),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[2] = cpu->regs[2] + 9ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = cpu->regs[2] << 3;
    if (FLAG_EQ) goto L_113924;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_113924:
    cpu->regs[3] = cpu->regs[20] + 48ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_LS) goto L_113a3c;
    cpu->regs[0] = cpu->regs[3] + cpu->regs[2];
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_LO) goto L_113a4c;
L_11393c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x113948ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 56));
    PB_STR((cpu->regs[20] + 24), cpu->regs[3]);
    PB_STRB((cpu->regs[3] + 70), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    cpu->regs[2] = cpu->regs[0] + 192ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 176),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[0] << 1);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_113a60;
L_113974:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    if ((cpu->regs[0])==0) goto L_1139d0;
L_11397c:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 70));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1139a4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 56));
    cpu->regs[4] = cpu->regs[1] + 192ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[1] + 176),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[1] = cpu->regs[4] + (cpu->regs[1] << 1);
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LO) goto L_113a50;
L_1139a4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 48));
    PB_STR((cpu->regs[3] + 8), 0ULL);
    if ((cpu->regs[1])!=0) goto L_1139bc;
    cpu->regs[30] = PB_BASE + 0x1139b4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1220b0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113a68;
L_1139bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1139cc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1139cc:
    PB_STR((cpu->regs[20] + 16), cpu->regs[1]);
L_1139d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -16));
    if ((cpu->regs[0])!=0) goto L_113a18;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1139ecULL; PB_CALL(65, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + -8));
    cpu->regs[2] = cpu->regs[20] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[1] & 3ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[0] = cpu->regs[0] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[20] + -16), cpu->regs[3]); PB_STR((cpu->regs[20] + -16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
L_113a18:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1137fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1137fc;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_113a3c:
    cpu->regs[0] = cpu->regs[19] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[19], cpu->regs[3]); } else { FLAG_CMP(1, 0); }
    if (FLAG_HS) goto L_11393c;
L_113a4c:
    __builtin_trap();
L_113a50:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_11397c;
    PB_STR((cpu->regs[3] + 8), 0ULL);
    goto L_1139d0;
L_113a60:
    PB_STR((cpu->regs[3] + 56), cpu->regs[0]);
    goto L_113974;
L_113a68:
    cpu->regs[30] = PB_BASE + 0x113a6cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1139d0;
L_113a70:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_113f20;
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_EQ) goto L_113f30;
L_113aa8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_113acc;
L_113ab8:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1131ULL)));
    if (FLAG_EQ) goto L_113bf0;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_113ab8;
L_113acc:
    cpu->regs[21] = cpu->regs[22];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
L_113ad8:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1131ULL;
    cpu->regs[30] = PB_BASE + 0x113aecULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11401c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_113ffc;
L_113b0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113f78;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_113cd4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x113b34ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_113d04;
L_113b3c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113f78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113b50ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_113e84;
L_113b58:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113f78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113b6cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_113e10;
L_113b74:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113f78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113b88ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_113d9c;
L_113b90:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113f78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113ba4ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_113d78;
L_113bac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_113f78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113bc0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x114060ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_113ef8;
L_113bc8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_113f0c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_LE) goto L_113cc0;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[2];
    goto L_113ad8;
L_113bf0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_113c04:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_113c1c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113c24ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_113f6c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(49ULL)));
    if (FLAG_NE) goto L_113bac;
L_113c40:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113c50ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113bac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113c64ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_114044;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[1] = 4ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x113c88ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 272ULL;
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x113ca0ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1a6840ULL);
    if ((cpu->regs[0])!=0) goto L_113d70;
L_113ca4:
    cpu->regs[30] = PB_BASE + 0x113ca8ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_114008;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_113f0c;
L_113cc0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_113c04;
L_113cd4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113cdcULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114008;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_113f78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113cfcULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x113a70ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113b3c;
L_113d04:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113f84;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_113b3c;
L_113d24:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113d34ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113b3c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113d48ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_114044;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x113d6cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    if ((cpu->regs[0])==0) goto L_113ca4;
L_113d70:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_113bc8;
L_113d78:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113c1c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(49ULL)));
    if (FLAG_NE) goto L_113bac;
    goto L_113c40;
L_113d9c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113fac;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(24ULL)));
    if (FLAG_NE) goto L_113b90;
L_113dbc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113dccULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113b90;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113de0ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_114044;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x113e04ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    if ((cpu->regs[0])==0) goto L_113ca4;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_113bc8;
L_113e10:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113f44;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    if (FLAG_NE) goto L_113b74;
L_113e30:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113e40ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113b74;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113e54ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_114044;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 13ULL;
    cpu->regs[30] = PB_BASE + 0x113e78ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    if ((cpu->regs[0])==0) goto L_113ca4;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_113bc8;
L_113e84:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_113fd4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(17ULL)));
    if (FLAG_NE) goto L_113b58;
L_113ea4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113eb4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_113b58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x113ec8ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_114044;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x113eecULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    if ((cpu->regs[0])==0) goto L_113ca4;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_113bc8;
L_113ef8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_113cc0;
L_113f0c:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[20] = 0ULL;
    goto L_113c04;
L_113f20:
    cpu->regs[30] = PB_BASE + 0x113f24ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_113aa8;
L_113f30:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113f38ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_11402c;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    goto L_113aa8;
L_113f44:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113f4cULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_113f6c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    if (FLAG_NE) goto L_113b74;
    goto L_113e30;
L_113f6c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_113f78:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_113f0c;
L_113f84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113f8cULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_113f6c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_113b3c;
    goto L_113d24;
L_113fac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113fb4ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_113f6c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(24ULL)));
    if (FLAG_NE) goto L_113b90;
    goto L_113dbc;
L_113fd4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x113fdcULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_113f6c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(17ULL)));
    if (FLAG_NE) goto L_113b58;
    goto L_113ea4;
L_113ffc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114004ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_113b0c;
L_114008:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_113f0c;
L_11401c:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_113c04;
L_11402c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_113c04;
L_114044:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_113cc0;
    goto L_113f0c;
    /* nop */
L_114060:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1145b4;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1145c4;
L_114098:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11451c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_1140e0;
L_1140bc:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1132ULL)));
    if (FLAG_EQ) goto L_114220;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_1140bc;
L_1140d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_114250;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
L_1140e0:
    PB_LDRW(cpu->regs[23], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[24], (cpu->regs[1] + 20) + 4);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_114430;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[22] = cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(14ULL)));
    if (FLAG_EQ) goto L_114294;
L_1140f8:
    cpu->regs[22] = cpu->regs[20];
L_1140fc:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_114430;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1143f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[21]));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_EQ) goto L_11432c;
L_114124:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_114430;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_114444;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[21]));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(31ULL)));
    if (FLAG_EQ) goto L_1143a0;
    PB_STR((SP + 64), cpu->regs[25]);
L_114150:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1145d0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_114550;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    cpu->regs[23] = cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11456c;
L_114180:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x114194ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x114900ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1141bc;
L_11419c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_114494;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(35ULL)));
    if (FLAG_EQ) goto L_1144b8;
L_1141bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_114310;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1141d0ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x114900ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_114318;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1132ULL;
    cpu->regs[30] = PB_BASE + 0x1141f8ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x1082e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_114220:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[2]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_114238:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_114250:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114258ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1145ec;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[21]));
    PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_114430;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_114608;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
L_114280:
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(14ULL)));
    if (FLAG_NE) goto L_114638;
    cpu->regs[22] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[0];
L_114294:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1142a4ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[7] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114544;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1142b8ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1142f8;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[24];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1142dcULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x1a6780ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114380;
L_1142e4:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1132ULL;
    cpu->regs[30] = PB_BASE + 0x1142f8ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x1082e0ULL);
L_1142f8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_114238;
L_114308:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_114310:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_114318:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
L_114324:
    cpu->regs[21] = 0ULL;
    goto L_1142e4;
L_11432c:
    cpu->regs[0] = cpu->regs[20];
L_114330:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114340ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[7] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11441c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x114354ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1142f8;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[24];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x114378ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x1a6780ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1142e4;
L_114380:
    cpu->regs[30] = PB_BASE + 0x114384ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_114324;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_114238;
L_1143a0:
    cpu->regs[0] = cpu->regs[20];
L_1143a4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1143b4ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[7] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114468;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1143c8ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1142f8;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[24];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1143ecULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x1a6780ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1142e4;
    goto L_114380;
L_1143f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114400ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114424;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(15ULL)));
    if (FLAG_EQ) goto L_114330;
L_11441c:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    goto L_114124;
L_114424:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_114430:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_114238;
L_114444:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11444cULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114474;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(31ULL)));
    if (FLAG_EQ) goto L_1143a4;
L_114468:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    PB_STR((SP + 64), cpu->regs[25]);
    goto L_114150;
L_114474:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_114484:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_114238;
L_114494:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11449cULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114308;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(35ULL)));
    if (FLAG_NE) goto L_1141bc;
L_1144b8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1144c8ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x114060ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1141bc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1144dcULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_114310;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[24];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x114500ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1145a0;
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1142e4;
L_11451c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114524ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1145ec;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_1140bc;
    goto L_1140d0;
L_114544:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    cpu->regs[20] = cpu->regs[22];
    goto L_1140f8;
L_114550:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114558ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_114310;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_NE) goto L_114180;
L_11456c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114574ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1145d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_114310;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114594ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x114900ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11419c;
    goto L_1141bc;
L_1145a0:
    cpu->regs[30] = PB_BASE + 0x1145a4ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_114318;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_114318;
L_1145b4:
    cpu->regs[30] = PB_BASE + 0x1145b8ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_114098;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_1145c4:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    goto L_114238;
L_1145d0:
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_114484;
L_1145d8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_114318;
L_1145ec:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_114238;
L_114608:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114610ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114624;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    goto L_114280;
L_114624:
    cpu->regs[0] = 1ULL;
    cpu->regs[22] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1140fc;
L_114638:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 96));
    goto L_1140f8;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[7] = 1ULL;
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 32));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[3];
    PB_LDRB(cpu->regs[3], (cpu->regs[5] + 8));
    cpu->regs[7] = cpu->regs[7] << (cpu->regs[3] & 63);
    cpu->regs[7] = cpu->regs[7] - 1ULL;
    cpu->regs[6] = cpu->regs[1] & cpu->regs[7];
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_1147d8;
    cpu->regs[8] = cpu->regs[5] + cpu->regs[6];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[8] + 32),&_s,1); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_NE) goto L_11470c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 40));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[4]);
    if ((cpu->regs[7])!=0) goto L_114878;
    PB_STRW((cpu->regs[5] + 12), 0ULL);
L_114698:
    cpu->regs[6] = cpu->regs[5] + cpu->regs[6];
    cpu->regs[3] = 4294967294ULL;
    cpu->regs[1] = 1ULL;
    PB_STRB((cpu->regs[6] + 32), cpu->regs[3]);
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 32));
    PB_LDRB(cpu->regs[0], (cpu->regs[5] + 10));
    PB_LDRB(cpu->regs[3], (cpu->regs[5] + 9));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[3] & 63);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_114788;
L_1146bc:
    cpu->regs[5] = cpu->regs[5] + 32ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[2] << 4);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + cpu->regs[1]));
    cpu->regs[1] = cpu->regs[5] + cpu->regs[1];
    PB_STR((cpu->regs[1] + 0), 0ULL); PB_STR((cpu->regs[1] + 0) + 8, 0ULL);
L_1146d0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1146e4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_114704;
L_1146e4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1146f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1147a8;
L_1146f8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_114704:
    cpu->regs[30] = PB_BASE + 0x114708ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1146e4;
L_11470c:
    FLAG_CMP(cpu->regs[8], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_114860;
    cpu->regs[1] = cpu->regs[1] >> 5;
    cpu->regs[6] = cpu->regs[6] + (cpu->regs[6] << 2);
    cpu->regs[8] = cpu->regs[1] + 1ULL;
    cpu->regs[6] = cpu->regs[6] + cpu->regs[8];
    cpu->regs[6] = cpu->regs[6] & cpu->regs[7];
L_114728:
    cpu->regs[8] = cpu->regs[5] + cpu->regs[6];
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_11480c;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[8] + 32),&_s,1); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
L_114738:
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_NE) goto L_1147b8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 40));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[4]);
    if ((cpu->regs[7])!=0) goto L_114878;
L_114754:
    PB_STRW((cpu->regs[5] + 12), 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(7ULL)));
    if (FLAG_LE) goto L_114698;
L_114760:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_114820;
    cpu->regs[6] = cpu->regs[5] + (cpu->regs[6] << 1);
    cpu->regs[0] = 4294967294ULL;
    PB_STRH((cpu->regs[6] + 32), cpu->regs[0]);
L_114774:
    PB_LDRB(cpu->regs[0], (cpu->regs[5] + 10));
    cpu->regs[1] = 1ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[5] + 9));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[3] & 63);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1146bc;
L_114788:
    cpu->regs[0] = 24ULL;
    cpu->regs[5] = cpu->regs[5] + 32ULL;
    cpu->regs[1] = cpu->regs[2] * cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = cpu->regs[5] + cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    PB_STR((cpu->regs[2] + 8), 0ULL); PB_STR((cpu->regs[2] + 8) + 8, 0ULL);
    PB_STR((cpu->regs[5] + cpu->regs[1]), 0ULL);
    goto L_1146d0;
L_1147a8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(131, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1147b8:
    cpu->regs[6] = cpu->regs[6] + (cpu->regs[6] << 2);
    cpu->regs[1] = cpu->regs[1] >> 5;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[8], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_114860;
    cpu->regs[6] = cpu->regs[6] + cpu->regs[1];
    cpu->regs[6] = cpu->regs[7] & cpu->regs[6];
    goto L_114728;
L_1147d8:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_114838;
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[6] << 1);
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[8] + 32),&_s,2); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
L_1147e8:
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_NE) goto L_11470c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 40));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[4]);
    if ((cpu->regs[7])!=0) goto L_114878;
    PB_STRW((cpu->regs[5] + 12), 0ULL);
    goto L_114760;
L_11480c:
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[6] << 1);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_11484c;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[8] + 32),&_s,2); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
    goto L_114738;
L_114820:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_1148d4;
    cpu->regs[6] = cpu->regs[5] + (cpu->regs[6] << 2);
    cpu->regs[0] = 4294967294ULL;
    PB_STRW((cpu->regs[6] + 32), cpu->regs[0]);
    goto L_114774;
L_114838:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_1148e4;
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[6] << 2);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[8] + 32),&_s,4); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
    goto L_1147e8;
L_11484c:
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[6] << 2);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_1148f0;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[8] + 32),&_s,4); cpu->regs[8] = (uint64_t)(int64_t)_s; } while(0);
    goto L_114738;
L_114860:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[6] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 40));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[4]);
    if ((cpu->regs[7])==0) goto L_114754;
L_114878:
    PB_STR((cpu->regs[7] + (cpu->regs[2] << 3)), 0ULL);
    cpu->regs[4] = cpu->regs[7] - 2ULL;
    cpu->regs[0] = 1ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[7] + -2));
L_114888:
    cpu->regs[1] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[0])));
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]))));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_1148a0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    goto L_114888;
L_1148a0:
    cpu->regs[1] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[1] = cpu->regs[7] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
L_1148a8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[2] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[0])));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_1148c8;
    PB_LDRB(cpu->regs[5], (cpu->regs[1] + -1));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRB((cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))), cpu->regs[5]);
    goto L_1148a8;
L_1148c8:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRB((cpu->regs[7] + -2), cpu->regs[3]);
    goto L_1146e4;
L_1148d4:
    cpu->regs[6] = cpu->regs[5] + (cpu->regs[6] << 3);
    cpu->regs[0] = 18446744073709551614ULL;
    PB_STR((cpu->regs[6] + 32), cpu->regs[0]);
    goto L_114774;
L_1148e4:
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[6] << 3);
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 32));
    goto L_1147e8;
L_1148f0:
    cpu->regs[8] = cpu->regs[5] + (cpu->regs[6] << 3);
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 32));
    goto L_114738;
    /* nop */
L_114900:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_114b54;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_114b64;
L_114938:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_114a84;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])==0) goto L_114980;
L_114958:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1134ULL)));
    if (FLAG_EQ) goto L_1149d8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_114958;
L_11496c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_114aec;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_114b90;
L_114980:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(56ULL)));
    if (FLAG_EQ) goto L_114a0c;
L_11498c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_114b90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11499cULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114a04;
L_1149a4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1134ULL;
    cpu->regs[30] = PB_BASE + 0x1149b8ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x1082e0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1149d8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[2]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
L_1149f0:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_114a04:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_1149a4;
L_114a0c:
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDRW(cpu->regs[22], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[1] + 20) + 4);
L_114a18:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114a28ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[6] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114b2c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x114a3cULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114ad8;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 32));
    cpu->regs[2] = cpu->regs[23];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28) + 4);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x114a5cULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x202e90ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 296ULL;
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x114a74ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x1a6840ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114aac;
L_114a7c:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_1149a4;
L_114a84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114a8cULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114b38;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[21] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[21]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    if ((cpu->regs[0])!=0) goto L_114958;
    goto L_11496c;
L_114aac:
    cpu->regs[30] = PB_BASE + 0x114ab0ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114a7c;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1149f0;
L_114ad8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1149f0;
L_114aec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114af4ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114b38;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[21]));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_114b8c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_114b74;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
L_114b20:
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(56ULL)));
    if (FLAG_EQ) goto L_114a18;
L_114b2c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    goto L_11498c;
L_114b38:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1149f0;
L_114b54:
    cpu->regs[30] = PB_BASE + 0x114b58ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_114938;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_114b64:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1149f0;
L_114b74:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114b7cULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_114ba4;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_114b8c:
    PB_LDR(cpu->regs[23], (SP + 48));
L_114b90:
    cpu->regs[21] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1149f0;
L_114ba4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    goto L_114b20;
    /* nop */
    /* nop */
    /* nop */
L_114bc0:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1150b4;
L_114bec:
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_114fe8;
L_114bf8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_114c1c;
L_114c08:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1135ULL)));
    if (FLAG_EQ) goto L_114d44;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_114c08;
L_114c1c:
    cpu->regs[21] = cpu->regs[22];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
L_114c28:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1135ULL;
    cpu->regs[30] = PB_BASE + 0x114c3cULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11511c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_115074;
L_114c5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_115008;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_115080;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x114c84ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114cac;
L_114c8c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_114f54;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(23ULL)));
    if (FLAG_EQ) goto L_114f78;
L_114cac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_115008;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114cc0ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_114e24;
L_114cc8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_115008;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114cdcULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_114d70;
L_114ce4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
L_114ce8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_115008;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114cf8ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_114ed0;
L_114d00:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_115008;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114d14ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x108c48ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_114fd0;
L_114d1c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_114e10;
L_114d2c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_LE) goto L_114ea8;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[2];
    goto L_114c28;
L_114d44:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_114d58:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_114d70:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_115014;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_NE) goto L_114ce4;
L_114d90:
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114da4ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x1179e4ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1150e4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x114dbcULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_11513c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x114dccULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_11512c;
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    if ((cpu->regs[27])==0) goto L_115064;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 16)); PB_LDR(cpu->regs[27], (cpu->regs[27] + 16) + 8);
L_114ddc:
    cpu->regs[4] = cpu->regs[25];
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x114df4ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x118c84ULL);
    if ((cpu->regs[0])==0) goto L_114e88;
L_114df8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_114d2c;
L_114e10:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[20] = 0ULL;
    goto L_114d58;
L_114e24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114e2cULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x10dc40ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114cc8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x114e40ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_115104;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[1] = cpu->regs[4];
    PB_LDRW(cpu->regs[23], (cpu->regs[2] + 28)); PB_LDRW(cpu->regs[27], (cpu->regs[2] + 28) + 4);
    cpu->regs[30] = PB_BASE + 0x114e5cULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x116c40ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1150bc;
L_114e64:
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[6] = cpu->regs[27];
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x114e84ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x118c84ULL);
    if ((cpu->regs[0])!=0) goto L_114df8;
L_114e88:
    cpu->regs[30] = PB_BASE + 0x114e8cULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1150ec;
    PB_LDR(cpu->regs[27], (SP + 80));
L_114e94:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_114e10;
L_114ea8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_114ed0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_11503c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_NE) goto L_114d00;
L_114ef0:
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114f04ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x1a0d64ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11506c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x114f18ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_11506c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x114f28ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_11512c;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x114f4cULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x1a1c50ULL);
    if ((cpu->regs[0])!=0) goto L_114df8;
    goto L_114e88;
L_114f54:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114f5cULL; PB_CALL(162, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114ffc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(23ULL)));
    if (FLAG_NE) goto L_114cac;
L_114f78:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114f88ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_114cac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x114f9cULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_115104;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 8));
    cpu->regs[3] = cpu->regs[26];
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[24];
    PB_LDRW(cpu->regs[5], (cpu->regs[2] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[2] + 28) + 4);
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x114fc4ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x10dae0ULL);
    if ((cpu->regs[0])==0) goto L_1150c8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_114d1c;
L_114fd0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_114ea8;
    goto L_114e10;
L_114fe8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x114ff0ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_115148;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    goto L_114bf8;
L_114ffc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_115008:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_114e10;
L_115014:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11501cULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114ffc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_NE) goto L_114ce4;
    goto L_114d90;
L_11503c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x115044ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_114ffc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_NE) goto L_114d00;
    goto L_114ef0;
L_115064:
    cpu->regs[1] = 0ULL;
    goto L_114ddc;
L_11506c:
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_114d00;
L_115074:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11507cULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_114c5c;
L_115080:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x115088ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1150d0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_115008;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1150a8ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0x114bc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_114c8c;
    goto L_114cac;
L_1150b4:
    cpu->regs[30] = PB_BASE + 0x1150b8ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_114bec;
L_1150bc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_114e64;
L_1150c8:
    cpu->regs[30] = PB_BASE + 0x1150ccULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_114e94;
L_1150d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_114e10;
L_1150e4:
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_114ce8;
L_1150ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_114e10;
L_115104:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_11510c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_114ea8;
    goto L_114e10;
L_11511c:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_114d58;
L_11512c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_11510c;
L_11513c:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_114ce8;
L_115148:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_114d58;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x115184ULL; PB_CALL(174, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 1816));
    if (((cpu->regs[1] >> 31) & 1)) goto L_115234;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_115260;
L_1151a4:
    PB_STR((cpu->regs[19] + 0), 0ULL);
L_1151a8:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -16)); PB_LDR(cpu->regs[1], (cpu->regs[19] + -16) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    PB_STR((cpu->regs[2] + 8), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[0] = cpu->regs[0] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[0]);
    if ((cpu->regs[3])!=0) goto L_115228;
L_1151d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1151e0ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0x1152acULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1151f8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_115220;
L_1151f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_115298;
L_115204:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11524c;
L_115210:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(176, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
L_115220:
    cpu->regs[30] = PB_BASE + 0x115224ULL; PB_CALL(177, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1151f8;
L_115228:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x115230ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_1151d8;
L_115234:
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_115260;
    cpu->regs[2] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_GT) goto L_11528c;
L_115244:
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1151a4;
    goto L_1151a8;
L_11524c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115210;
    cpu->regs[30] = PB_BASE + 0x11525cULL; PB_CALL(179, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115210;
L_115260:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x115270ULL; PB_CALL(180, cpu, tlb, PB_BASE + 0x9b854ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_115244;
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    if (((cpu->regs[0] >> 31) & 1)) goto L_11528c;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
L_11528c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_115298:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115204;
    cpu->regs[30] = PB_BASE + 0x1152a8ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115204;
L_1152ac:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[19] + 136), 0ULL);
    if ((cpu->regs[0])==0) goto L_1152e0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1152e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_11549c;
L_1152e0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_115300;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_115300;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1154cc;
L_115300:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_115320;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_115320;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1154c4;
L_115320:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])!=0) goto L_115434;
L_115328:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])!=0) goto L_11547c;
L_115330:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_115344;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_115400;
L_115344:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])!=0) goto L_115454;
L_11534c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])!=0) goto L_1153d8;
L_115354:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])!=0) goto L_115414;
L_11535c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])!=0) goto L_1154a4;
L_115364:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[20] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1154f0;
L_115380:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = 24464ULL;
    cpu->regs[2] = cpu->regs[20] + cpu->regs[2];
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1154d4;
L_115394:
    cpu->regs[2] = cpu->regs[20] + (4ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1154e8;
L_1153a8:
    cpu->regs[1] = 24464ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 40), cpu->regs[20]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1153c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_115474;
L_1153c8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1153d8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_115354;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115354;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1153fcULL; PB_CALL(182, cpu, tlb, cpu->regs[1]);
    goto L_115354;
L_115400:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115344;
    cpu->regs[30] = PB_BASE + 0x115410ULL; PB_CALL(183, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115344;
L_115414:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 112), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_11535c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11535c;
    cpu->regs[30] = PB_BASE + 0x115430ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11535c;
L_115434:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_115328;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115328;
    cpu->regs[30] = PB_BASE + 0x115450ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115328;
L_115454:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_11534c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11534c;
    cpu->regs[30] = PB_BASE + 0x115470ULL; PB_CALL(186, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11534c;
L_115474:
    cpu->regs[30] = PB_BASE + 0x115478ULL; PB_CALL(187, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1153c8;
L_11547c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 64), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_115330;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115330;
    cpu->regs[30] = PB_BASE + 0x115498ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115330;
L_11549c:
    cpu->regs[30] = PB_BASE + 0x1154a0ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1152e0;
L_1154a4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_115364;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115364;
    cpu->regs[30] = PB_BASE + 0x1154c0ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115364;
L_1154c4:
    cpu->regs[30] = PB_BASE + 0x1154c8ULL; PB_CALL(191, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115320;
L_1154cc:
    cpu->regs[30] = PB_BASE + 0x1154d0ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115300;
L_1154d4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_115394;
    cpu->regs[30] = PB_BASE + 0x1154e4ULL; PB_CALL(193, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_115394;
L_1154e8:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_1153a8;
L_1154f0:
    cpu->regs[2] = cpu->regs[20] + (4ULL << 12);
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_115380;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x115534ULL; PB_CALL(194, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_GT) goto L_1155c4;
L_115544:
    cpu->regs[2] = cpu->regs[20] + (66ULL << 12);
    cpu->regs[2] = cpu->regs[2] + 384ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 1296));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_115638;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[2] + 1296), cpu->regs[3]);
    cpu->regs[3] = cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[3])) << 3);
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 2708));
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_115694;
L_115574:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
L_11557c:
    cpu->regs[20] = cpu->regs[20] + (64ULL << 12);
    cpu->regs[3] = PB_BASE + 0x450000ULL;
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    cpu->regs[3] = cpu->regs[3] + 216ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8576));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[3]); PB_STR((cpu->regs[19] + 32) + 8, 0ULL);
    cpu->regs[2] = cpu->regs[2] + 256ULL;
    PB_STR((cpu->regs[20] + 8576), cpu->regs[2]);
    PB_STR((cpu->regs[19] + 24), cpu->regs[2]);
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_GT) goto L_11560c;
L_1155ac:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1155c4:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    cpu->regs[0] = 0ULL;
L_1155d0:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_115668;
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_1155d0;
    cpu->regs[2] = 1ULL;
L_1155f0:
    FLAG_CMP(cpu->regs[21], 5ULL);
    if (FLAG_LE) goto L_115544;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x115604ULL; PB_CALL(195, cpu, tlb, PB_BASE + 0x1981c0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_115660;
L_11560c:
    cpu->regs[20] = 0ULL;
L_115610:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + (cpu->regs[20] << 3)));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[20] << 3)));
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x115624ULL; PB_CALL(196, cpu, tlb, PB_BASE + 0xddf30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_115670;
    FLAG_CMP(cpu->regs[21], cpu->regs[20]);
    if (FLAG_LE) goto L_1155ac;
    goto L_115610;
L_115638:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    cpu->regs[30] = PB_BASE + 0x115644ULL; PB_CALL(197, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11557c;
    cpu->regs[1] = PB_BASE + 0x450000ULL;
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    cpu->regs[30] = PB_BASE + 0x115660ULL; PB_CALL(198, cpu, tlb, PB_BASE + 0xe9320ULL);
L_115660:
    cpu->regs[19] = 0ULL;
    goto L_1155ac;
L_115668:
    cpu->regs[2] = 0ULL;
    goto L_1155f0;
L_115670:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_115660;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_115660;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x115690ULL; PB_CALL(199, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1155ac;
L_115694:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11569cULL; PB_CALL(200, cpu, tlb, PB_BASE + 0x98264ULL);
    goto L_115574;
}
