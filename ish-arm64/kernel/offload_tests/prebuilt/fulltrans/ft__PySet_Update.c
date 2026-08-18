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

void ft__PySet_Update(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[6] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1ffd08;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xe7768ULL); return; };
L_1ffd08:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1ffd14ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ffd28;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe7768ULL); return; };
L_1ffd28:
    cpu->regs[1] = 2365ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[0] + 1456ULL;
    cpu->regs[30] = PB_BASE + 0x1ffd38ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28));
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = ((uint32_t)(cpu->regs[5] + 1ULL));
    FLAG_CMP(cpu->regs[5], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_1fff24;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = ((uint32_t)(cpu->regs[5] + 2ULL));
    FLAG_CMP(cpu->regs[5], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_1fff40;
    cpu->regs[20] = ((uint32_t)(cpu->regs[5] + 3ULL));
    PB_STRW((cpu->regs[0] + 28), cpu->regs[20]);
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff34;
    cpu->regs[23] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1ffda8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1b2920ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 123ULL;
    cpu->regs[30] = PB_BASE + 0x1ffdccULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 256ULL;
    cpu->regs[30] = PB_BASE + 0x1ffdf0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 150ULL;
    cpu->regs[30] = PB_BASE + 0x1ffe14ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    cpu->regs[1] = PB_BASE + 0x2b8000ULL;
    cpu->regs[1] = cpu->regs[1] + 2096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + -240)); PB_LDR(cpu->regs[5], (cpu->regs[1] + -240) + 8);
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 259ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[4] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1ffe44ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[2] = ((uint32_t)(cpu->regs[23] + 2ULL));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 151ULL;
    cpu->regs[30] = PB_BASE + 0x1ffe68ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 261ULL;
    cpu->regs[30] = PB_BASE + 0x1ffe8cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1ffea4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1b2920ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 55ULL;
    cpu->regs[30] = PB_BASE + 0x1ffec8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1ffee0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1b2920ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fff30;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x1fff04ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1fff14:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1fff24:
    PB_STRW((cpu->regs[0] + 28), cpu->regs[25]);
    cpu->regs[0] = 4294967295ULL;
    goto L_1fff14;
L_1fff30:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1fff34:
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1fff14;
L_1fff40:
    PB_STRW((cpu->regs[0] + 28), cpu->regs[24]);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1fff14;
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[0] + 3736ULL;
    goto L_1fff6c;
L_1fff6c:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[0] + 3760ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1fff9cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c7c60ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2000b8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fffacULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2000b8;
    PB_STR((SP + 64), cpu->regs[25]);
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 16));
    cpu->regs[0] = cpu->regs[25] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1fffc4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_200094;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1fffdc;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_1fffdc:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[19] + 24), cpu->regs[22]);
L_1fffe4:
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_LT) goto L_200060;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ffffcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c1e0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_200014;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_200088;
L_200014:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_200028;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2000c8;
L_200028:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_2000c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2000c0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x200044ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
L_200048:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_200060:
    cpu->regs[1] = cpu->regs[23] + 24ULL;
    cpu->regs[3] = cpu->regs[19] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_200080;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_200080:
    PB_STR((cpu->regs[3] + (cpu->regs[0] << 3)), cpu->regs[2]);
    goto L_1fffe4;
L_200088:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x200090ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_200014;
L_200094:
    PB_LDR(cpu->regs[25], (SP + 64));
L_200098:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2000a0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2000acULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2000b4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_200048;
L_2000b8:
    cpu->regs[20] = 0ULL;
    goto L_200098;
L_2000c0:
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_200048;
L_2000c8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2000d0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_200028;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 48));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    if ((cpu->regs[1])==0) goto L_2001f0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_2001f0;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_2001b4;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 24));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x200130ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11d7acULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    FLAG_CMP(cpu->regs[21], cpu->regs[3]);
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[3]))), 0);
    if (FLAG_NE) goto L_200200;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x200150ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x200220ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_200218;
    if ((cpu->regs[21])==0) goto L_200168;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2001d0;
L_200168:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2680));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[23];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 296));
    PB_STR((cpu->regs[20] + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x200188ULL; PB_CALL(28, cpu, tlb, cpu->regs[3]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2001d8;
L_200194:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x20019cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18d760ULL);
L_20019c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_2001b4:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2001c0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x200220ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_200218;
    cpu->regs[21] = 0ULL;
    goto L_200168;
L_2001d0:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_200168;
L_2001d8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_200194;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2001ecULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_200194;
L_2001f0:
    cpu->regs[30] = PB_BASE + 0x2001f4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdb548ULL);
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = cpu->regs[0];
    goto L_200168;
L_200200:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3768ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x200218ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_200218:
    cpu->regs[20] = 4294967295ULL;
    goto L_20019c;
}
