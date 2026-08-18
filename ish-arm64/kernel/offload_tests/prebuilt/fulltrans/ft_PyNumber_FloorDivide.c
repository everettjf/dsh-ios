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

void ft_PyNumber_FloorDivide(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 232ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1508bcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1508d8;
L_1508cc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1508d8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = 232ULL;
    cpu->regs[3] = cpu->regs[3] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x1508f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1b02c0ULL);
    cpu->regs[0] = 0ULL;
    goto L_1508cc;
    /* nop */
    /* nop */
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_150aa8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_150aa8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[2] >> 3;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_NE) goto L_150a28;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    cpu->regs[4] = cpu->regs[3] >> 3;
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_NE) goto L_150a28;
    cpu->regs[2] = cpu->regs[2] ^ cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[19], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 24));
    FLAG_CMP((cpu->regs[2]) & (3ULL), 0);
    if (FLAG_NE) goto L_1509c8;
    cpu->regs[19] = ((uint32_t)((cpu->regs[0] ? (uint64_t)((int64_t)cpu->regs[19] / (int64_t)cpu->regs[0]) : 0)));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    cpu->regs[0] = cpu->regs[1] + 5ULL;
    FLAG_CMP(cpu->regs[0], 261ULL);
    if (FLAG_HI) goto L_1509e4;
L_150984:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 5ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[19] = ((cpu->regs[19] & 0xffffffffULL) << 5);
    cpu->regs[19] = cpu->regs[19] + 3048ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
L_1509a0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_150a94;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_1509c8:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] - 1ULL));
    cpu->regs[19] = ((uint32_t)((cpu->regs[0] ? (uint64_t)((int64_t)cpu->regs[19] / (int64_t)cpu->regs[0]) : 0)));
    cpu->regs[19] = ((uint32_t)((~cpu->regs[19])));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    cpu->regs[0] = cpu->regs[1] + 5ULL;
    FLAG_CMP(cpu->regs[0], 261ULL);
    if (FLAG_LS) goto L_150984;
L_1509e4:
    cpu->regs[0] = 1073741823ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_HI) goto L_150a44;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_150a98;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe3e84ULL); return; };
L_150a28:
    cpu->regs[2] = SP;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x150a34ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x150ac0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_150aa0;
    PB_LDR(cpu->regs[0], (SP + 0));
    goto L_1509a0;
L_150a44:
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = 2ULL;
    cpu->regs[20] = (FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[1])) : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x150a54ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_150a9c;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[1] = 4294967295ULL;
    cpu->regs[2] = ((uint32_t)((FLAG_GT) ? ((uint64_t)(-(int64_t)cpu->regs[1])) : cpu->regs[1]));
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[2] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 16ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
L_150a7c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[20] & 1073741823ULL));
    PB_STRW(cpu->regs[2], cpu->regs[1]); cpu->regs[2] += 4;
    cpu->regs[20] = cpu->regs[20] >> 30;
    if ((cpu->regs[20])!=0) goto L_150a7c;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_1509a0;
L_150a94:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
L_150a98:
    cpu->regs[30] = PB_BASE + 0x150a9cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_150a9c:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
L_150aa0:
    cpu->regs[0] = 0ULL;
    goto L_1509a0;
L_150aa8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_1509a0;
    /* nop */
    /* nop */
    /* nop */
L_150ac0:
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[3];
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[7], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 16));
    cpu->regs[7] = cpu->regs[5] >> 3;
    cpu->regs[4] = cpu->regs[6] >> 3;
    FLAG_CMP(cpu->regs[7], 1ULL);
    if (FLAG_EQ) goto L_150b90;
    FLAG_CMP(cpu->regs[4], 300ULL);
    if (FLAG_HI) goto L_150da4;
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x150b24ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x150fa8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_150d18;
L_150b2c:
    PB_LDR(cpu->regs[21], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_150cec;
    if ((cpu->regs[0])==0) goto L_150c68;
L_150b44:
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[20])==0) goto L_150c24;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[22])==0) goto L_150c44;
L_150b58:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
L_150b60:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_150d9c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_150b90:
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_NE) goto L_150d78;
    PB_STR((SP + 16), 0ULL);
    if ((cpu->regs[2])==0) goto L_150d20;
    cpu->regs[5] = cpu->regs[5] ^ cpu->regs[6];
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 24));
    FLAG_CMP((cpu->regs[5]) & (3ULL), 0);
    if (FLAG_NE) goto L_150cfc;
    cpu->regs[0] = ((uint32_t)((cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[1]) : 0)));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x150bc0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 16), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_150d18;
L_150bc8:
    if ((cpu->regs[22])==0) goto L_150c14;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[4] = 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] & 3ULL));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - cpu->regs[3]));
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[1];
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 24));
    FLAG_CMP((cpu->regs[0]) & (3ULL), 0);
    if (FLAG_NE) goto L_150d40;
    cpu->regs[0] = ((uint32_t)((cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - cpu->regs[0] * cpu->regs[2]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] * cpu->regs[4]));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x150c08ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_150f24;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_150c14:
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
L_150c1c:
    cpu->regs[0] = 0ULL;
    goto L_150b60;
L_150c24:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_150c3c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_150c3c;
    cpu->regs[30] = PB_BASE + 0x150c3cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_150c3c:
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[22])!=0) goto L_150b58;
L_150c44:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_150c1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_150c1c;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x150c60ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_150b60;
L_150c68:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_NE) goto L_150b44;
L_150c78:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x150c84ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1484c0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_150ca8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_150ca8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x150ca8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_150ca8:
    PB_LDR(cpu->regs[21], (SP + 16));
    if ((cpu->regs[19])==0) goto L_150f48;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x150cc4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1b07c0ULL);
    if ((cpu->regs[0])==0) goto L_150f34;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_STR((SP + 16), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_150b44;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_150b44;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x150ce8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_150b44;
L_150cec:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP((cpu->regs[0]) & (3ULL), 0);
    if (FLAG_EQ) goto L_150c78;
    goto L_150b44;
L_150cfc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[0] = ((uint32_t)((cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[1]) : 0)));
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x150d10ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 16), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_150bc8;
L_150d18:
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150d20:
    if ((cpu->regs[3])==0) goto L_150c1c;
    cpu->regs[5] = cpu->regs[5] ^ cpu->regs[6];
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] & 3ULL));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - cpu->regs[6]));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 24));
    FLAG_CMP((cpu->regs[5]) & (3ULL), 0);
    if (FLAG_EQ) goto L_150f08;
L_150d40:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[3] = ((uint32_t)((cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3] * cpu->regs[2]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - cpu->regs[1]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] * cpu->regs[4]));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x150d60ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_150f24;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[20])!=0) goto L_150c14;
    cpu->regs[0] = 0ULL;
    goto L_150b60;
L_150d78:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x150d8cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x150fa8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_150b2c;
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150d9c:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x150da4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_150da4:
    cpu->regs[7] = cpu->regs[7] - cpu->regs[4];
    FLAG_CMP(cpu->regs[7], 150ULL);
    if (FLAG_LE) goto L_150d78;
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[0] + 1240ULL;
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x150dc0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1c7c60ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_150f78;
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[2] + 112ULL;
    cpu->regs[1] = cpu->regs[1] + 2944ULL;
    cpu->regs[30] = PB_BASE + 0x150de4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1a36c0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_150dfc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_150f84;
L_150dfc:
    if ((cpu->regs[19])==0) goto L_150f78;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_150eb8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_150e80;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_150e80;
    if ((cpu->regs[20])==0) goto L_150e40;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_150e3c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
L_150e3c:
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
L_150e40:
    if ((cpu->regs[22])==0) goto L_150e58;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_150e54;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_150e54:
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_150e58:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_150f90;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_150f90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x150e74ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 0ULL;
    goto L_150b60;
L_150e80:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_150e94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_150ef0;
L_150e94:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x150eacULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_150ecc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_150efc;
L_150ecc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2960ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x150ee4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150ef0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x150ef8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_150e94;
L_150efc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x150f04ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_150ecc;
L_150f08:
    cpu->regs[0] = ((uint32_t)((cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - cpu->regs[0] * cpu->regs[2]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] * cpu->regs[4]));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x150f1cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_150f9c;
L_150f24:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x150f2cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150f34:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_150f48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_150f6c;
L_150f48:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_150d18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_150d18;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x150f64ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150f6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x150f74ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_150f48;
L_150f78:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    goto L_150b60;
L_150f84:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x150f8cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_150dfc;
L_150f90:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 0ULL;
    goto L_150b60;
L_150f9c:
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    goto L_150b60;
L_150fa8:
    SP = SP - 96ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] >> 3;
    if ((cpu->regs[0])==0) goto L_151214;
    cpu->regs[1] = cpu->regs[1] >> 3;
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_151070;
L_150ffc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2280));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_151134;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    if (FLAG_NE) goto L_1510f8;
L_151024:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 3208));
    PB_STR((cpu->regs[22] + 0), cpu->regs[19]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_151158;
L_151034:
    cpu->regs[1] = cpu->regs[0] + 3208ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
L_151040:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_15120c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_151070:
    if (FLAG_EQ) goto L_151160;
L_151074:
    PB_STR((SP + 80), cpu->regs[23]);
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_151100;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[2] = SP + 12ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((SP + 12), 0ULL);
    cpu->regs[30] = PB_BASE + 0x151094ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x151260ULL);
    PB_STR((SP + 16), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_151128;
    PB_LDRW(cpu->regs[0], (SP + 12));
    cpu->regs[30] = PB_BASE + 0x1510a8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_151234;
L_1510b0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(cpu->regs[0], 2ULL);
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_1511f0;
L_1510d8:
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_151180;
L_1510e0:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x1510e8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x145da0ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    goto L_151040;
L_1510f8:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
    goto L_151024;
L_151100:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x151110ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x170cccULL);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[23]);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x151120ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x145da0ULL);
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[23])!=0) goto L_1510b0;
L_151128:
    PB_LDR(cpu->regs[23], (SP + 80));
L_15112c:
    cpu->regs[0] = 4294967295ULL;
    goto L_151040;
L_151134:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15113cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x170a04ULL);
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15112c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 3208));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_151034;
L_151158:
    PB_STRW((cpu->regs[0] + 3208), cpu->regs[1]);
    goto L_151034;
L_151160:
    cpu->regs[1] = cpu->regs[0] + 3ULL;
    cpu->regs[2] = cpu->regs[19] + (cpu->regs[1] << 2);
    cpu->regs[1] = cpu->regs[20] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HS) goto L_151074;
    goto L_150ffc;
L_151180:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_1510e0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15119cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x22d820ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if ((cpu->regs[0])!=0) goto L_1510e0;
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_151128;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_151128;
    cpu->regs[30] = PB_BASE + 0x1511c0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1511c0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if ((cpu->regs[0])==0) goto L_151128;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[22] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_151128;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_151128;
    cpu->regs[30] = PB_BASE + 0x1511e4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    goto L_151040;
L_1511f0:
    cpu->regs[0] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1511f8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x22d820ULL);
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])==0) goto L_1511c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    goto L_1510d8;
L_15120c:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x151214ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c170ULL);
L_151214:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2960));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15122cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_151040;
L_151234:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_151128;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_151128;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x151250ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    goto L_151040;
    /* nop */
L_151260:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    cpu->regs[19] = cpu->regs[19] >> 3;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15128cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_1513ec;
    if ((cpu->regs[19])==0) goto L_151548;
    cpu->regs[5] = cpu->regs[22];
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_151448;
    cpu->regs[4] = cpu->regs[19] + 5ULL;
    cpu->regs[7] = 14757395258967641292ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[7] = (cpu->regs[7] & ~(0xffffULL << 0)) | ((0xcccdULL & 0xffff) << 0);
    cpu->regs[4] = cpu->regs[4] << 2;
    cpu->regs[3] = cpu->regs[4] - 24ULL;
    cpu->regs[3] = cpu->regs[3] >> 2;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[3] = cpu->regs[3] & 3ULL; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_151344;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_151318;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_1512f4;
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[5] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[4] - 4ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    cpu->regs[1] = ((uint32_t)(cpu->regs[5] - (cpu->regs[1] << 1)));
L_1512f4:
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[3] = cpu->regs[5] | cpu->regs[1];
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[3] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[4] - 4ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - (cpu->regs[1] << 1)));
L_151318:
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[3] = cpu->regs[5] | cpu->regs[1];
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[3] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[4] - 4ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - (cpu->regs[1] << 1)));
    FLAG_CMP(cpu->regs[4], 20ULL);
    if (FLAG_EQ) goto L_1513d0;
L_151344:
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[6] = cpu->regs[4] - 4ULL;
    cpu->regs[3] = cpu->regs[5] | cpu->regs[1];
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[3] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[4] - 8ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[6]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - (cpu->regs[1] << 1)));
    cpu->regs[3] = cpu->regs[5] | (cpu->regs[3] << 30);
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[3] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[6]), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - (cpu->regs[1] << 1)));
    cpu->regs[3] = cpu->regs[5] | (cpu->regs[3] << 30);
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[3] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[6] - 8ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - (cpu->regs[1] << 1)));
    cpu->regs[3] = cpu->regs[5] | (cpu->regs[3] << 30);
    cpu->regs[1] = (uint64_t)(((unsigned __int128)cpu->regs[3] * (unsigned __int128)cpu->regs[7]) >> 64);
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[6] - 12ULL;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 2);
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - (cpu->regs[1] << 1)));
    FLAG_CMP(cpu->regs[6], 32ULL);
    if (FLAG_NE) goto L_151344;
L_1513d0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[2] >> 3;
    if ((cpu->regs[1])==0) goto L_1513ec;
L_1513e0:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 20));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1513fc;
L_1513ec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1513fc:
    cpu->regs[3] = cpu->regs[1] - 1ULL; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_15155c;
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 16));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_15141c;
L_15140c:
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[3] = cpu->regs[2] | (cpu->regs[3] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[3]);
    goto L_1513ec;
L_15141c:
    cpu->regs[3] = cpu->regs[1] - 2ULL;
    cpu->regs[6] = cpu->regs[0] + 24ULL;
L_151424:
    cpu->regs[4] = cpu->regs[3] - 1ULL;
    if ((cpu->regs[3])==0) goto L_15155c;
    PB_LDRW(cpu->regs[5], (cpu->regs[6] + (cpu->regs[4] << 2)));
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_151440;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_15140c;
    goto L_1513ec;
L_151440:
    cpu->regs[3] = cpu->regs[4];
    goto L_151424;
L_151448:
    cpu->regs[3] = cpu->regs[19] + 5ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[3] = cpu->regs[3] << 2;
    cpu->regs[2] = cpu->regs[3] - 24ULL;
    cpu->regs[2] = cpu->regs[2] >> 2;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[2] = cpu->regs[2] & 3ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1514c0;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_151494;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_151530;
L_151478:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[3]));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[1] / cpu->regs[5] : 0);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4] * cpu->regs[5]));
    PB_STRW((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[3] - 4ULL;
L_151494:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[3]));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[1] / cpu->regs[5] : 0);
    PB_STRW((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[3] - 4ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4] * cpu->regs[5]));
    FLAG_CMP(cpu->regs[3], 20ULL);
    if (FLAG_EQ) goto L_1513d0;
    /* nop */
    /* nop */
L_1514c0:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[3]));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[6] = cpu->regs[3] - 4ULL;
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[1] / cpu->regs[5] : 0);
    PB_STRW((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4] * cpu->regs[5]));
    cpu->regs[3] = cpu->regs[3] - 8ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[6]));
    cpu->regs[1] = cpu->regs[2] | (cpu->regs[1] << 30);
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[1] / cpu->regs[5] : 0);
    PB_STRW((cpu->regs[0] + cpu->regs[6]), cpu->regs[4]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4] * cpu->regs[5]));
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[3]));
    cpu->regs[1] = cpu->regs[2] | (cpu->regs[1] << 30);
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[1] / cpu->regs[5] : 0);
    PB_STRW((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[6] - 8ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4] * cpu->regs[5]));
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[3]));
    cpu->regs[1] = cpu->regs[2] | (cpu->regs[1] << 30);
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[1] / cpu->regs[5] : 0);
    PB_STRW((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[4] * cpu->regs[5]));
    cpu->regs[3] = cpu->regs[6] - 12ULL;
    FLAG_CMP(cpu->regs[6], 32ULL);
    if (FLAG_NE) goto L_1514c0;
    goto L_1513d0;
L_151530:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + cpu->regs[3]));
    cpu->regs[4] = (cpu->regs[5] ? cpu->regs[2] / cpu->regs[5] : 0);
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - cpu->regs[4] * cpu->regs[5]));
    PB_STRW((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[3] - 4ULL;
    goto L_151478;
L_151548:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[21] + 0), 0ULL);
    cpu->regs[1] = cpu->regs[2] >> 3;
    if ((cpu->regs[1])!=0) goto L_1513e0;
    goto L_1513ec;
L_15155c:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_1513ec;
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STRW((SP + 20), 0ULL);
    if ((cpu->regs[2])!=0) goto L_151714;
L_1515a4:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1515b0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_151708;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_1516dc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x1515c8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_1516ec;
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_151618;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x1515e0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_1516ec;
    PB_STR((cpu->regs[21] + 32), cpu->regs[0]);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_151618;
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    cpu->regs[24] = cpu->regs[21] + 24ULL;
    cpu->regs[22] = 2ULL;
L_1515fc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[22] << 3)));
    cpu->regs[30] = PB_BASE + 0x151604ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_1516ec;
    PB_STR((cpu->regs[24] + (cpu->regs[22] << 3)), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_NE) goto L_1515fc;
L_151618:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x151620ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1516ec;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_STR((cpu->regs[20] + 24), cpu->regs[2]);
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1517bc;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_151684;
    cpu->regs[3] = 0ULL;
L_15164c:
    PB_STR((cpu->regs[20] + 32), cpu->regs[2]);
    cpu->regs[1] = 4294967295ULL;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_LE) goto L_151680;
L_15165c:
    cpu->regs[4] = cpu->regs[20] + 24ULL;
    cpu->regs[0] = 2ULL;
L_151664:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    PB_STR((cpu->regs[4] + (cpu->regs[0] << 3)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = ((uint32_t)((FLAG_NE) ? cpu->regs[1] : (~0ULL)));
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : (0ULL + 1);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_151664;
L_151680:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1517e0;
L_151684:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 304));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x151694ULL; PB_CALL(51, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_151778;
    PB_LDRW(cpu->regs[1], (SP + 20));
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[21]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[20]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[1]);
L_1516a8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_151710;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1516dc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1516e4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_151684;
L_1516ec:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_151708;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_151708;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x151708ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_151708:
    cpu->regs[0] = 0ULL;
    goto L_1516a8;
L_151710:
    cpu->regs[30] = PB_BASE + 0x151714ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x7c170ULL);
L_151714:
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x15171cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdb548ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = cpu->regs[3] + 784ULL;
    cpu->regs[4] = SP + 20ULL;
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[2] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x151744ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x13eb20ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15175c;
L_151750:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1515a4;
L_151754:
    cpu->regs[0] = 0ULL;
    goto L_1516a8;
L_15175c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_151750;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x151770ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1515a4;
    goto L_151754;
L_151778:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15178c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1517b0;
L_15178c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_151708;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_151708;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1517a8ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1516a8;
L_1517b0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1517b8ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15178c;
L_1517bc:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_1517e0;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 2ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1517d4;
    cpu->regs[3] = 1ULL;
    goto L_15164c;
L_1517d4:
    PB_STR((cpu->regs[20] + 32), cpu->regs[2]);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_NE) goto L_1517e8;
L_1517e0:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    goto L_151684;
L_1517e8:
    cpu->regs[3] = 1ULL;
    goto L_15165c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    if (!((cpu->regs[2] >> 9) & 1)) goto L_15180c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 856));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_151820;
    return;
L_15180c:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x151818ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1ab164ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(61, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_151820:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 28) & 1)) goto L_151900;
    if (((cpu->regs[1] >> 63) & 1)) goto L_1518d8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_GE) goto L_1518d8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    cpu->regs[3] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_1518f8;
    if (!((cpu->regs[2] >> 6) & 1)) goto L_151890;
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_15189c;
L_151868:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
    if (((cpu->regs[0] >> 7) & 1)) goto L_1518b4;
L_151870:
    cpu->regs[3] = 48ULL;
    cpu->regs[2] = 61184ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = cpu->regs[2] + (uint64_t)(uint32_t)cpu->regs[0] * (uint64_t)(uint32_t)cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_151888:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_151890:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
L_151894:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_151868;
L_15189c:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1518d0;
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 1)));
L_1518a8:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_1518c8;
    if (!((cpu->regs[0] >> 7) & 1)) goto L_151870;
L_1518b4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 924ULL));
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 6);
    goto L_151888;
L_1518c8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    goto L_15190c;
L_1518d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 2)));
    goto L_1518a8;
L_1518d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 2480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1518f0ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_151888;
L_1518f8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_151894;
L_151900:
    cpu->regs[30] = PB_BASE + 0x151904ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 0ULL;
    goto L_151888;
L_15190c:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x151928ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    if ((cpu->regs[0])==0) goto L_151954;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 28ULL));
    cpu->regs[3] = ((uint32_t)(((cpu->regs[2] >> 5) & 0x1ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(8ULL)));
    if (FLAG_EQ) goto L_151960;
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_151988;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    if (((cpu->regs[2] >> 6) & 1)) goto L_15198c;
    PB_STRW((cpu->regs[0] + 56), cpu->regs[19]);
L_151954:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_151960:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_15197c;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    if (((cpu->regs[2] >> 6) & 1)) goto L_151980;
    PB_STRH((cpu->regs[0] + 56), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_15197c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
L_151980:
    PB_STRH((cpu->regs[1] + 0), cpu->regs[19]);
    goto L_151954;
L_151988:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
L_15198c:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[19]);
    goto L_151954;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1519b8ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1519ec;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HI) goto L_1519fc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = cpu->regs[20] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[0] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x1519e0ULL; PB_CALL(66, cpu, tlb, cpu->regs[2]);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_151a00;
    PB_STR((cpu->regs[19] + 32), cpu->regs[20]);
L_1519ec:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1519fc:
    PB_STR((cpu->regs[19] + 24), 0ULL);
L_151a00:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_151a14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_151a20;
L_151a14:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(67, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_151a20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x151a28ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_151a14;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2408));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[4]); } else { FLAG_CMP(0, 1); }
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    if (FLAG_EQ) goto L_151c94;
L_151a58:
    cpu->regs[22] = cpu->regs[2] & 9223372036854775807ULL;
    FLAG_CMP((cpu->regs[2]) & (9223372036854775806ULL), 0);
    if (FLAG_EQ) goto L_151c74;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[22] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_EQ) goto L_151c08;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x151a78ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdc8acULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_151cc8;
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_151bc4;
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[23] << 3;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x151a98ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x151aacULL; PB_CALL(71, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[2] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[3]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x151ae0ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_151c4c;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    FLAG_CMP(cpu->regs[22], 2ULL);
    if (FLAG_EQ) goto L_151b20;
    cpu->regs[23] = 2ULL;
    cpu->regs[2] = 2ULL;
L_151af8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + (cpu->regs[2] << 3)));
    cpu->regs[30] = PB_BASE + 0x151b00ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[23] - 1ULL));
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    if ((cpu->regs[0])==0) goto L_151c4c;
    cpu->regs[1] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3);
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    PB_STR((cpu->regs[1] + 24), cpu->regs[0]);
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_GT) goto L_151af8;
L_151b20:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = PB_BASE + 0xde000ULL;
    cpu->regs[0] = cpu->regs[0] + 2088ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_151c38;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x151b40ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xde8a0ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_151c4c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    if (!((cpu->regs[0] >> 14) & 1)) goto L_151b90;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x151b64ULL; PB_CALL(75, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + -8));
    cpu->regs[1] = cpu->regs[2] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[3] = cpu->regs[3] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[3] = cpu->regs[3] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[2] + -16), cpu->regs[4]); PB_STR((cpu->regs[2] + -16) + 8, cpu->regs[3]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[1]);
L_151b90:
    PB_STR((cpu->regs[2] + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_151c2c;
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
L_151bb0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_151bc4:
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x151bd8ULL; PB_CALL(76, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[2] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[3]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    goto L_151b20;
L_151c08:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[1] = cpu->regs[19] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_151cb8;
    cpu->regs[19] = cpu->regs[19] + (18ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 1808ULL;
    goto L_151b20;
L_151c2c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    goto L_151bb0;
L_151c38:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x151c44ULL; PB_CALL(77, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_151b90;
L_151c4c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_151cc8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_151cc8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x151c68ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[2] = 0ULL;
    goto L_151bb0;
L_151c74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x151c8cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[2] = 0ULL;
    goto L_151bb0;
L_151c94:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3904ULL;
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x151ca8ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_151a58;
    cpu->regs[2] = 0ULL;
    goto L_151bb0;
L_151cb8:
    cpu->regs[19] = cpu->regs[19] + (18ULL << 12);
    PB_STRW((cpu->regs[1] + 10000), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1808ULL;
    goto L_151b20;
L_151cc8:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[2] = 0ULL;
    goto L_151bb0;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 144ULL;
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x151d08ULL; PB_CALL(81, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[1] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[19], 5ULL);
    if (FLAG_GT) goto L_1521b0;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_151ee0;
    cpu->regs[22] = SP + 16ULL;
    cpu->regs[21] = cpu->regs[22];
L_151d48:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 24));
    cpu->regs[24] = PB_BASE + 0x136000ULL;
    cpu->regs[2] = cpu->regs[24] + 1760ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_151e94;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_152160;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_GE) goto L_152140;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[3] = cpu->regs[2] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[2] << 3)));
    PB_STR((cpu->regs[0] + 16), cpu->regs[3]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_151d9c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_151d9c:
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_151ea8;
L_151da8:
    cpu->regs[24] = cpu->regs[24] + 1760ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[25] = 1ULL;
L_151db4:
    cpu->regs[0] = cpu->regs[19] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[0] & 3ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_152054;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_151e28;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_151dfc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_151e44;
    cpu->regs[30] = PB_BASE + 0x151df0ULL; PB_CALL(82, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
L_151dfc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_151e44;
    cpu->regs[30] = PB_BASE + 0x151e1cULL; PB_CALL(83, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
L_151e28:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_NE) goto L_15203c;
L_151e44:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_152130;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_GE) goto L_152118;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[3] = cpu->regs[2] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[2] << 3)));
    PB_STR((cpu->regs[0] + 16), cpu->regs[3]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_151e7c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_151e7c:
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[1]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[19]);
    if (FLAG_NE) goto L_151db4;
L_151e8c:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_151eac;
L_151e94:
    cpu->regs[30] = PB_BASE + 0x151e98ULL; PB_CALL(84, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152160;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_151da8;
L_151ea8:
    cpu->regs[19] = 1ULL;
L_151eac:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 11) & 1)) goto L_151f00;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x151ed8ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xea120ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_151f60;
L_151ee0:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 11) & 1)) goto L_152168;
    cpu->regs[22] = SP + 16ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
L_151f00:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 56));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[3];
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_15219c;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_151fe8;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_15219c;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + cpu->regs[3]));
    if ((cpu->regs[4])==0) goto L_151ff0;
L_151f34:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x151f44ULL; PB_CALL(86, cpu, tlb, cpu->regs[4]);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x151f58ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xe8888ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[19])==0) goto L_151fa8;
L_151f60:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_151f78;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_152024;
L_151f78:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_151fa8;
L_151f80:
    cpu->regs[23] = 1ULL;
L_151f84:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + (cpu->regs[23] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_151f9c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_152014;
L_151f9c:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[19]);
    if (FLAG_NE) goto L_151f84;
L_151fa8:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_NE) goto L_1521a4;
L_151fb0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_152188;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_151fe8:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    if ((cpu->regs[4])!=0) goto L_151f34;
L_151ff0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152008ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xea120ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_151f60;
    goto L_151fa8;
L_152014:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x152020ULL; PB_CALL(89, cpu, tlb, cpu->regs[1]);
    goto L_151f9c;
L_152024:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x152030ULL; PB_CALL(90, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_151f80;
    goto L_151fa8;
L_15203c:
    cpu->regs[30] = PB_BASE + 0x152040ULL; PB_CALL(91, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_EQ) goto L_151e8c;
L_152054:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_151e44;
    cpu->regs[30] = PB_BASE + 0x152074ULL; PB_CALL(92, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    cpu->regs[26] = cpu->regs[25];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_151e44;
    cpu->regs[30] = PB_BASE + 0x1520a4ULL; PB_CALL(93, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_151e44;
    cpu->regs[30] = PB_BASE + 0x1520d0ULL; PB_CALL(94, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[26] + 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[26] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_151e44;
    cpu->regs[30] = PB_BASE + 0x1520fcULL; PB_CALL(95, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152130;
    PB_STR((cpu->regs[21] + (cpu->regs[25] << 3)), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[26] + 3ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_NE) goto L_152054;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_151eac;
L_152118:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[0] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_152130;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_152190;
L_152130:
    cpu->regs[19] = cpu->regs[25];
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_151f60;
L_152140:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[0] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_152160;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_152160;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x152160ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_152160:
    cpu->regs[20] = 0ULL;
    goto L_151fa8;
L_152168:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152180ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xea120ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_151fb0;
L_152188:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x152190ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x7c170ULL);
L_152190:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x152198ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_152130;
L_15219c:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    __builtin_trap();
L_1521a4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1521acULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_151fb0;
L_1521b0:
    cpu->regs[0] = cpu->regs[19] << 3;
    cpu->regs[30] = PB_BASE + 0x1521b8ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1521cc;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16));
    cpu->regs[22] = SP + 16ULL;
    goto L_151d48;
L_1521cc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1521d8ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x22d7a8ULL);
    goto L_151fb0;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + -16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_15229c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[3] = cpu->regs[3] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    PB_STR((cpu->regs[2] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_152230;
L_152228:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_152280;
L_152230:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_152240;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15225c;
L_152240:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
L_152248:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_15225c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_152240;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x152274ULL; PB_CALL(103, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    goto L_152248;
L_152280:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_152230;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x152298ULL; PB_CALL(104, cpu, tlb, cpu->regs[1]);
    goto L_152230;
L_15229c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_152228;
    goto L_152230;
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 96));
    if ((cpu->regs[0])==0) goto L_152360;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_152360;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3880));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x152300ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_152450;
    if (((cpu->regs[0] >> 63) & 1)) goto L_152458;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
L_152314:
    FLAG_CMP(cpu->regs[4], cpu->regs[3]);
    if (FLAG_HS) goto L_152780;
    if ((cpu->regs[20])!=0) goto L_152464;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_152778;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[2] = cpu->regs[4] + 1ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[4];
    SP = SP + 96ULL;
    cpu->regs[3] = 0ULL;
    { PB_CALL(106, cpu, tlb, PB_BASE + 0x129a00ULL); return; };
L_152360:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2224));
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_NE) goto L_152798;
    cpu->regs[21] = SP + 8ULL;
    cpu->regs[22] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[3] = SP;
    cpu->regs[30] = PB_BASE + 0x15238cULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x146840ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_152790;
    if ((cpu->regs[20])==0) goto L_1524a4;
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_EQ) goto L_1527fc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3376ULL;
    cpu->regs[30] = PB_BASE + 0x1523b0ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[20] = cpu->regs[0];
L_1523b4:
    if ((cpu->regs[20])==0) goto L_152790;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[6], (SP + 0));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1523d0ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x146b24ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_LT) goto L_1525c0;
    if (FLAG_EQ) goto L_1525d0;
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_1526ac;
L_1523ec:
    FLAG_CMP(cpu->regs[6], 1ULL);
    if (FLAG_NE) goto L_1525d0;
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x152404ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x129a00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15241c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15276c;
L_15241c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_152778;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_152450:
    cpu->regs[30] = PB_BASE + 0x152454ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_152790;
L_152458:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[4] = cpu->regs[4] + cpu->regs[3];
    goto L_152314;
L_152464:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[4] = cpu->regs[4] << 3;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[4]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_152480;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_152480:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[2] + cpu->regs[4]), cpu->regs[20]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_15249c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15249c;
    cpu->regs[30] = PB_BASE + 0x15249cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_15249c:
    cpu->regs[19] = 0ULL;
    goto L_15241c;
L_1524a4:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[6], (SP + 0));
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1524c0ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x146b24ULL);
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_LT) goto L_1526dc;
    if (FLAG_EQ) goto L_15275c;
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_152728;
L_1524dc:
    FLAG_CMP(cpu->regs[6], 1ULL);
    if (FLAG_EQ) goto L_1526c0;
L_1524e4:
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_GT) goto L_1524f8;
L_1524ec:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_1524f0:
    cpu->regs[19] = 0ULL;
    goto L_15241c;
L_1524f8:
    if (((cpu->regs[6] >> 63) & 1)) goto L_1526f0;
L_1524fc:
    cpu->regs[0] = cpu->regs[23] << 3;
    cpu->regs[30] = PB_BASE + 0x152504ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15281c;
    PB_LDR(cpu->regs[22], (SP + 16));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[20] = cpu->regs[22];
    goto L_152564;
L_152520:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[20] << 3;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + cpu->regs[1]));
    PB_STR((cpu->regs[24] + (cpu->regs[21] << 3)), cpu->regs[5]);
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_HS) goto L_1526b4;
L_152540:
    cpu->regs[0] = cpu->regs[20] - cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[1] = cpu->regs[4] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[4] + (cpu->regs[0] << 3);
    cpu->regs[30] = PB_BASE + 0x152558ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[2];
L_152564:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_HI) goto L_152520;
    cpu->regs[22] = cpu->regs[23] * cpu->regs[2] + cpu->regs[22];
    FLAG_CMP(cpu->regs[22], cpu->regs[3]);
    if (FLAG_LO) goto L_152730;
L_152580:
    cpu->regs[1] = cpu->regs[3] - cpu->regs[23];
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152594ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xe5550ULL);
    cpu->regs[19] = cpu->regs[0];
L_152598:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + (cpu->regs[20] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_152714;
L_1525a4:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[23]);
    if (FLAG_LT) goto L_152598;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1525b8ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_15241c;
L_1525c0:
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_1525d0;
    PB_STR((SP + 8), cpu->regs[0]);
L_1525d0:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_NE) goto L_1527bc;
    if ((cpu->regs[21])!=0) goto L_152600;
L_1525e0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15249c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15249c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1525fcULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15249c;
L_152600:
    cpu->regs[0] = cpu->regs[21] << 3;
    cpu->regs[30] = PB_BASE + 0x152608ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15282c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 25) & 1)) goto L_152814;
    PB_LDR(cpu->regs[6], (cpu->regs[20] + 24));
L_152624:
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[5], (SP + 0));
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[5] = cpu->regs[5] << 3;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 3);
    goto L_152660;
L_15263c:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[22] + (cpu->regs[1] << 3)), cpu->regs[0]);
    PB_LDR(cpu->regs[4], (cpu->regs[6] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_15270c;
L_152654:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
    cpu->regs[2] = cpu->regs[2] + cpu->regs[5];
L_152660:
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_LT) goto L_15263c;
    cpu->regs[19] = 0ULL;
L_15266c:
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_GE) goto L_1526a0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_152688;
L_152680:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_15266c;
L_152688:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_152680;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x15269cULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15266c;
L_1526a0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1526a8ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1525e0;
L_1526ac:
    PB_STR((SP + 8), cpu->regs[0]);
    goto L_1523ec;
L_1526b4:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[2] = cpu->regs[3] - cpu->regs[20];
    goto L_152540;
L_1526c0:
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1526d0ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x129a00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_15241c;
L_1526dc:
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_152754;
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_1524ec;
L_1526f0:
    cpu->regs[1] = cpu->regs[23] - 1ULL;
    cpu->regs[2] = cpu->regs[0] + 1ULL;
    cpu->regs[3] = (uint64_t)(-(int64_t)cpu->regs[6]);
    PB_STR((SP + 0), cpu->regs[3]); PB_STR((SP + 0) + 8, cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] * cpu->regs[6] + cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[1]);
    goto L_1524fc;
L_15270c:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[3]);
    goto L_152654;
L_152714:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1525a4;
    cpu->regs[30] = PB_BASE + 0x152724ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1525a4;
L_152728:
    PB_STR((SP + 8), cpu->regs[0]);
    goto L_1524dc;
L_152730:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[2] = cpu->regs[3] - cpu->regs[22];
    cpu->regs[3] = cpu->regs[22] - cpu->regs[23];
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[22] << 3);
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[3] << 3);
    cpu->regs[30] = PB_BASE + 0x15274cULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    goto L_152580;
L_152754:
    PB_STR((SP + 8), cpu->regs[0]);
    goto L_1524e4;
L_15275c:
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_1524fc;
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1524f0;
L_15276c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x152774ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15241c;
L_152778:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x152780ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x7c170ULL);
L_152780:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 936ULL;
    cpu->regs[30] = PB_BASE + 0x152790ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_152790:
    cpu->regs[19] = 4294967295ULL;
    goto L_15241c;
L_152798:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[1] = cpu->regs[1] + 1488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1527b8ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_15241c;
L_1527bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3416ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1527d8ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_152790;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_152790;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1527f8ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15241c;
L_1527fc:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15280cULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x1db900ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_1523b4;
L_152814:
    cpu->regs[6] = cpu->regs[20] + 24ULL;
    goto L_152624;
L_15281c:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_152820:
    cpu->regs[30] = PB_BASE + 0x152824ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x22d780ULL);
L_152824:
    cpu->regs[19] = 4294967295ULL;
    goto L_15241c;
L_15282c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_152820;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_152820;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x152848ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[30] = PB_BASE + 0x15284cULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_152824;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 96));
    if ((cpu->regs[0])==0) goto L_152934;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_152934;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2584));
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x15288cULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1528d4;
    cpu->regs[2] = PB_BASE + 0x152000ULL;
    cpu->regs[2] = cpu->regs[2] + 2400ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_NE) goto L_152920;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1528f4;
    cpu->regs[0] = cpu->regs[20];
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_1528c8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_1529a4;
L_1528c8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(136, cpu, tlb, PB_BASE + 0x1c5c40ULL); return; };
L_1528d4:
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1528dcULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    if ((cpu->regs[0])!=0) goto L_152950;
    cpu->regs[0] = PB_BASE + 0x152000ULL;
    cpu->regs[0] = cpu->regs[0] + 2400ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_152920;
L_1528f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_152958;
L_15290c:
    cpu->regs[1] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_152914:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_152920:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_152934:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x152950ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x11f220ULL);
L_152950:
    cpu->regs[0] = 0ULL;
    goto L_152914;
L_152958:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_15290c;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_152978;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_152974;
    goto L_1529a4;
L_152974:
    { PB_CALL(139, cpu, tlb, PB_BASE + 0x1c5c40ULL); return; };
L_152978:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_15299c;
L_152990:
    cpu->regs[1] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    return;
L_15299c:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_152990;
L_1529a4:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[3] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[3] / (int64_t)cpu->regs[1]) : 0);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_GT) goto L_152b70;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[20] = cpu->regs[0] * cpu->regs[1];
    cpu->regs[22] = cpu->regs[1];
    if (!((cpu->regs[3] >> 6) & 1)) goto L_152a9c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x1529e8ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_152ac8;
L_1529f0:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[5] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    cpu->regs[7] = ((uint32_t)(((cpu->regs[4] >> 5) & 0x1ULL)));
    cpu->regs[8] = ((uint32_t)(((cpu->regs[6] >> 5) & 0x1ULL)));
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_152a5c;
    cpu->regs[5] = cpu->regs[5];
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_152b60;
    FLAG_CMP((((uint32_t)(cpu->regs[6]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[21] + 40ULL;
    cpu->regs[1] = cpu->regs[21] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
L_152a28:
    cpu->regs[1] = cpu->regs[20] * cpu->regs[5];
    if ((((uint32_t)(cpu->regs[7])))==0) goto L_152b40;
    FLAG_CMP((((uint32_t)(cpu->regs[4]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[19] + 56ULL;
    cpu->regs[4] = cpu->regs[19] + 40ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[4];
L_152a40:
    cpu->regs[3] = cpu->regs[3] * cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x152a48ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x16bdc8ULL);
L_152a48:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_152a5c:
    if ((((uint32_t)(cpu->regs[7])))==0) goto L_152b90;
    cpu->regs[0] = cpu->regs[19] + 40ULL;
    FLAG_CMP((((uint32_t)(cpu->regs[4]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[19] = cpu->regs[19] + 56ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[0];
L_152a70:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_152ad0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_152b58;
    FLAG_CMP((((uint32_t)(cpu->regs[6]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[21] + 40ULL;
    cpu->regs[0] = cpu->regs[21] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_152a90:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x152a98ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x7aee0ULL);
    goto L_152a48;
L_152a9c:
    cpu->regs[3] = ((uint32_t)(((cpu->regs[3] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_152b48;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 65535ULL;
    cpu->regs[0] = 1114111ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_152ab8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x152ac0ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1529f0;
L_152ac8:
    cpu->regs[21] = 0ULL;
    goto L_152a48;
L_152ad0:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_152b0c;
    PB_LDRH(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_152b68;
    FLAG_CMP((((uint32_t)(cpu->regs[6]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[21] + 40ULL;
    cpu->regs[1] = cpu->regs[21] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_152af0:
    cpu->regs[0] = 0ULL;
    goto L_152b00;
L_152af8:
    PB_STRH((cpu->regs[1] + (cpu->regs[0] << 1)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_152b00:
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_GT) goto L_152af8;
    goto L_152a48;
L_152b0c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_152b50;
    FLAG_CMP((((uint32_t)(cpu->regs[6]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[21] + 40ULL;
    cpu->regs[1] = cpu->regs[21] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_152b24:
    cpu->regs[0] = 0ULL;
    goto L_152b34;
L_152b2c:
    PB_STRW((cpu->regs[1] + (cpu->regs[0] << 2)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_152b34:
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_GT) goto L_152b2c;
    goto L_152a48;
L_152b40:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 56));
    goto L_152a40;
L_152b48:
    cpu->regs[1] = 255ULL;
    goto L_152ab8;
L_152b50:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 56));
    goto L_152b24;
L_152b58:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 56));
    goto L_152a90;
L_152b60:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 56));
    goto L_152a28;
L_152b68:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 56));
    goto L_152af0;
L_152b70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3544ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x152b8cULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_152a48;
L_152b90:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 56));
    goto L_152a70;
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_152d24;
L_152bdc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2208));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 224));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_152d64;
    cpu->regs[1] = PB_BASE + 0x137000ULL;
    cpu->regs[1] = cpu->regs[1] + 928ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_152ce4;
    cpu->regs[2] = SP;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152c20ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x137460ULL);
    PB_LDR(cpu->regs[21], (SP + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_152c60;
L_152c28:
    if ((cpu->regs[21])==0) goto L_152ca0;
L_152c2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_152d20;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_152c60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_152c7c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x152c78ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x252128ULL);
    if ((cpu->regs[21])==0) goto L_152ca0;
L_152c7c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((SP + 0), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_152ca0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_152d88;
    /* nop */
    /* nop */
    /* nop */
L_152ca0:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_152d00;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x152cbcULL; PB_CALL(147, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 96));
    if ((cpu->regs[1])!=0) goto L_152cf0;
L_152cc8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2368));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x152cdcULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x120824ULL);
L_152cdc:
    cpu->regs[21] = 0ULL;
    goto L_152c2c;
L_152ce4:
    cpu->regs[30] = PB_BASE + 0x152ce8ULL; PB_CALL(149, cpu, tlb, cpu->regs[2]);
    cpu->regs[21] = cpu->regs[0];
    goto L_152c28;
L_152cf0:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_152cc8;
    cpu->regs[21] = 0ULL;
    goto L_152c2c;
L_152d00:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x152d08ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_152d48;
L_152d0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_152c2c;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_152c2c;
L_152d20:
    cpu->regs[30] = PB_BASE + 0x152d24ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x7c170ULL);
L_152d24:
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3576ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x152d3cULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_152bdc;
    cpu->regs[21] = 0ULL;
    goto L_152c2c;
L_152d48:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x152d58ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_152cdc;
    cpu->regs[30] = PB_BASE + 0x152d60ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_152d0c;
L_152d64:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x152d84ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_152c2c;
L_152d88:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x152d90ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_152ca0;
    /* nop */
    /* nop */
    /* nop */
}
