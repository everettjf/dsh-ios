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

void ft_Py_GETENV(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3128));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_187bdc;
    cpu->regs[0] = 0ULL;
    return;
L_187bdc:
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x7c010ULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[29] = SP;
    cpu->regs[3] = 34ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x187c00ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c190ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_187c10;
L_187c08:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_187c10:
    cpu->regs[0] = 0ULL;
    goto L_187c08;
    /* nop */
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1] >> 49;
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0] + (cpu->regs[20] << 3);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1096));
    if ((cpu->regs[1])==0) goto L_187ce8;
    cpu->regs[21] = ((cpu->regs[19] >> 34) & 0x7fffULL);
    PB_LDR(cpu->regs[25], (cpu->regs[1] + (cpu->regs[21] << 3)));
    if ((cpu->regs[25])==0) goto L_187d64;
L_187c60:
    cpu->regs[1] = ((cpu->regs[19] >> 20) & 0x3fffULL);
    cpu->regs[22] = ((uint32_t)(cpu->regs[19] & 1048575ULL)); FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_EQ) goto L_187d74;
    cpu->regs[19] = cpu->regs[19] + (256ULL << 12);
    cpu->regs[21] = cpu->regs[19] >> 49;
    cpu->regs[21] = cpu->regs[23] + (cpu->regs[21] << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 1096));
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_187cc4;
    cpu->regs[0] = ((cpu->regs[1] & 0x3fffULL) << 3);
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_STRW((cpu->regs[25] + cpu->regs[0]), cpu->regs[22]);
    if ((cpu->regs[3])==0) goto L_187dc4;
    cpu->regs[24] = ((cpu->regs[19] >> 34) & 0x7fffULL);
    PB_LDR(cpu->regs[1], (cpu->regs[3] + (cpu->regs[24] << 3)));
    if ((cpu->regs[1])==0) goto L_187d84;
L_187c9c:
    cpu->regs[19] = ((cpu->regs[19] >> 20) & 0x3fffULL);
    cpu->regs[19] = cpu->regs[1] + (cpu->regs[19] << 3);
    PB_STRW((cpu->regs[19] + 4), cpu->regs[22]);
L_187ca8:
    cpu->regs[0] = 1ULL;
L_187cac:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_187cc4:
    cpu->regs[0] = ((cpu->regs[1] & 0x3fffULL) << 3);
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_STRW((cpu->regs[25] + cpu->regs[0]), 0ULL);
    if ((cpu->regs[3])==0) goto L_187de4;
    cpu->regs[0] = ((cpu->regs[19] >> 34) & 0x7fffULL);
    PB_LDR(cpu->regs[1], (cpu->regs[3] + (cpu->regs[0] << 3)));
    if ((cpu->regs[1])==0) goto L_187de4;
    cpu->regs[22] = 0ULL;
    goto L_187c9c;
L_187ce8:
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_187dec;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    cpu->regs[2] = 262144ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 96));
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 112));
    cpu->regs[30] = PB_BASE + 0x187d08ULL; PB_CALL(3, cpu, tlb, cpu->regs[3]);
    if ((cpu->regs[0])==0) goto L_187dec;
    cpu->regs[1] = cpu->regs[23] + (64ULL << 12);
    cpu->regs[21] = ((cpu->regs[19] >> 34) & 0x7fffULL);
    PB_STR((cpu->regs[20] + 1096), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (cpu->regs[0] + (cpu->regs[21] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 1096));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[1] + 1096), cpu->regs[0]);
    if ((cpu->regs[25])!=0) goto L_187c60;
L_187d2c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 96));
    cpu->regs[2] = 131072ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 112));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x187d40ULL; PB_CALL(4, cpu, tlb, cpu->regs[3]);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_187dec;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 1096));
    cpu->regs[1] = cpu->regs[23] + (64ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 1100));
    PB_STR((cpu->regs[2] + (cpu->regs[21] << 3)), cpu->regs[25]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[1] + 1100), cpu->regs[0]);
    goto L_187c60;
L_187d64:
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_187dec;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    goto L_187d2c;
L_187d74:
    cpu->regs[1] = ((cpu->regs[1] & 0x3fffULL) << 3);
    cpu->regs[2] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[24])));
    PB_STRW((cpu->regs[25] + cpu->regs[1]), cpu->regs[2]);
    goto L_187ca8;
L_187d84:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
L_187d8c:
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 96));
    cpu->regs[2] = 131072ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 112));
    cpu->regs[30] = PB_BASE + 0x187da0ULL; PB_CALL(5, cpu, tlb, cpu->regs[3]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_187de4;
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 1096));
    cpu->regs[0] = cpu->regs[23] + (64ULL << 12);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 1100));
    PB_STR((cpu->regs[3] + (cpu->regs[24] << 3)), cpu->regs[1]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 1100), cpu->regs[2]);
    goto L_187c9c;
L_187dc4:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    cpu->regs[2] = 262144ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 96));
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 112));
    cpu->regs[30] = PB_BASE + 0x187de0ULL; PB_CALL(6, cpu, tlb, cpu->regs[3]);
    if ((cpu->regs[0])!=0) goto L_187df4;
L_187de4:
    cpu->regs[1] = cpu->regs[20] << 3;
    PB_STRW((cpu->regs[25] + cpu->regs[1]), 0ULL);
L_187dec:
    cpu->regs[0] = 0ULL;
    goto L_187cac;
L_187df4:
    cpu->regs[2] = cpu->regs[23] + (64ULL << 12);
    cpu->regs[24] = ((cpu->regs[19] >> 34) & 0x7fffULL);
    PB_STR((cpu->regs[21] + 1096), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (cpu->regs[24] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 1096));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[2] + 1096), cpu->regs[0]);
    if ((cpu->regs[1])!=0) goto L_187c9c;
    goto L_187d8c;
    /* nop */
    /* nop */
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 2708));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_187e54;
L_187e40:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_187e54:
    cpu->regs[30] = PB_BASE + 0x187e58ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x98264ULL);
    goto L_187e40;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    PB_LDR(cpu->regs[4], (cpu->regs[21] + 48));
    PB_STR((SP + 48), cpu->regs[23]);
    if (((cpu->regs[0] >> 12) & 1)) goto L_187eb0;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 3040));
    cpu->regs[2] = 258ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x8ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[21] + 3040), cpu->regs[2]);
    PB_STR((cpu->regs[19] + 168), cpu->regs[0]);
    PB_STRW((cpu->regs[19] + 384), cpu->regs[1]);
L_187eb0:
    cpu->regs[22] = cpu->regs[20] + (88ULL << 12);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 360));
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 13248));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    if ((cpu->regs[2])!=0) goto L_187ecc;
    cpu->regs[2] = cpu->regs[3];
    PB_STR((cpu->regs[19] + 360), cpu->regs[3]);
L_187ecc:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[23] = 40ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[4]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    cpu->regs[2] = cpu->regs[2] * cpu->regs[23] + cpu->regs[20];
    cpu->regs[2] = cpu->regs[2] + (88ULL << 12);
    PB_STR((cpu->regs[2] + 13256), cpu->regs[19]);
    PB_STR((cpu->regs[22] + 13248), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x187ef4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xd9660ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_187f10;
L_187efc:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_187f10:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 360));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 48));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[1] = cpu->regs[1] * cpu->regs[23] + cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + (88ULL << 12);
    PB_STR((cpu->regs[1] + 13256), 0ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_EQ) goto L_187f40;
L_187f30:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 13248));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 13248), cpu->regs[1]);
    goto L_187efc;
L_187f40:
    PB_STR((cpu->regs[19] + 360), 0ULL);
    goto L_187f30;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x2b7000ULL;
    cpu->regs[2] = cpu->regs[2] + 1840ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x187f6cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x187f84ULL);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x17fe80ULL); return; };
L_187f84:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x187f98ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x188028ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_187fa8;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_187fa8:
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 920ULL;
    cpu->regs[30] = PB_BASE + 0x187fb8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x91ebcULL);
    /* nop */
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = 2ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x187fd0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdc8acULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18801c;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x187fecULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + -8));
    PB_STR((cpu->regs[1] + 24), 0ULL); PB_STR((cpu->regs[1] + 24) + 8, 0ULL);
    cpu->regs[3] = cpu->regs[1] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[2] = cpu->regs[2] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[1] + -16), cpu->regs[4]); PB_STR((cpu->regs[1] + -16) + 8, cpu->regs[2]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
L_18801c:
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
