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

void ft__Py_HashPointer(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = ror64(cpu->regs[0], 4);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13ec00;
    return;
L_13ec00:
    cpu->regs[0] = 18446744073709551614ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13ec30;
L_13ec24:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_13ec30:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x13ec3cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd7f88ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    goto L_13ec24;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_13efa8;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_13eeb4;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_13eec4;
    cpu->regs[19] = 0ULL;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_13ee90;
L_13ec9c:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2296));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3664));
L_13ecb0:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GE) goto L_13ed64;
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 24));
    cpu->regs[3] = cpu->regs[19] << 3;
    PB_LDR(cpu->regs[4], (cpu->regs[27] + 24));
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[3]));
    PB_LDR(cpu->regs[20], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_EQ) goto L_13eda4;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13edd8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13ecf4;
L_13ecf0:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_13ecf4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x13ed04ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13ede8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_NE) goto L_13ef18;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[22], cpu->regs[24]);
    cpu->regs[28] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_13ef2c;
L_13ed28:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13ed3c;
L_13ed30:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13ef78;
L_13ed3c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13ed50;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13ef6c;
L_13ed50:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_13ef58;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 16));
    if (FLAG_NE) goto L_13eda4;
L_13ed64:
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_LE) goto L_13edb0;
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LE) goto L_13edb0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_13edf8;
L_13ed7c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_13ed80:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3184));
L_13ed90:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_13eda4:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_LT) goto L_13ecb0;
L_13edb0:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_13eedc;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_13ed7c;
L_13edc0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_13edc4:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
    goto L_13ed90;
L_13edd8:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_13ecf0;
    goto L_13ecf4;
L_13ede8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[28] = 4294967295ULL;
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13ed30;
    goto L_13ed3c;
L_13edf8:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_13edc0;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 24));
    cpu->regs[19] = cpu->regs[19] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 24));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + cpu->regs[19]));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + cpu->regs[19]));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13ee24;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_13ee24:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_13ee34;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_13ee34:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13ee44ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ed08ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_13ee5c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13ef9c;
L_13ee5c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13ee70;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13ef84;
L_13ee70:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_13ee90:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_13edc4;
L_13ee98:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_LE) goto L_13eef8;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_13eee4;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_13ed80;
    goto L_13edc4;
L_13eeb4:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2400));
    goto L_13ed90;
L_13eec4:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_13ef08;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_13ed80;
    goto L_13edc4;
L_13eedc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_13ee98;
L_13eee4:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_13ef4c;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_13edc4;
    goto L_13ed80;
L_13eef8:
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_13efb4;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_13ed80;
    goto L_13edc4;
L_13ef08:
    cpu->regs[19] = 0ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_GT) goto L_13ec9c;
    goto L_13ee98;
L_13ef18:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13ef20ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[28] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_13ed28;
L_13ef2c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_13ed28;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13ef48ULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
    goto L_13ed28;
L_13ef4c:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_13edc4;
    goto L_13ed80;
L_13ef58:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_13ed90;
L_13ef6c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13ef74ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13ed50;
L_13ef78:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13ef80ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13ed3c;
L_13ef84:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13ef8cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_13ed90;
L_13ef9c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13efa4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13ee5c;
L_13efa8:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2400));
    goto L_13ed90;
L_13efb4:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_13edc4;
    goto L_13ed80;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_13f618;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -16));
    if ((cpu->regs[1])==0) goto L_13f2f0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    cpu->regs[24] = PB_BASE + 0x13e000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 48));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[24] + 4032ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[0] = cpu->regs[0] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[0]);
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_13f304;
L_13f028:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x13f03cULL; PB_CALL(10, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[23], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[23])==0) goto L_13f594;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 152));
    cpu->regs[2] = cpu->regs[23] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_13f5a8;
L_13f054:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[1] = cpu->regs[24] + 4032ULL;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_13f308;
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 256));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_NE) goto L_13f09c;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_NE) goto L_13f09c;
    cpu->regs[1] = cpu->regs[20];
L_13f08c:
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_13f08c;
L_13f09c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 392));
    if ((cpu->regs[0])!=0) goto L_13f314;
L_13f0a4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[22] + 376));
    if ((cpu->regs[0])==0) goto L_13f37c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 208));
    if ((cpu->regs[0])!=0) goto L_13f37c;
    FLAG_CMP(cpu->regs[5], 0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = (FLAG_NE) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0x13f0c8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_LDR(cpu->regs[5], (cpu->regs[22] + 376));
    if ((cpu->regs[5])!=0) goto L_13f384;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_13f350;
L_13f0d4:
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 48));
L_13f0d8:
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_13f28c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])!=0) goto L_13f4ec;
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 256));
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_13f140;
L_13f100:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])!=0) goto L_13f53c;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_13f140;
L_13f11c:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[24] + 4032ULL;
L_13f124:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])!=0) goto L_13f4a4;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[25]);
    if (FLAG_EQ) goto L_13f124;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_13f140:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    if (!((cpu->regs[0] >> 4) & 1)) goto L_13f298;
L_13f148:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + -24));
    if (!((cpu->regs[22] >> 0) & 1)) goto L_13f510;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 880));
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 24));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_13f1c8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1));
    if ((cpu->regs[0])==0) goto L_13f178;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_13f3c4;
L_13f178:
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_13f1c8;
L_13f180:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 9));
    if ((cpu->regs[0])==0) goto L_13f190;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_13f400;
L_13f190:
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_LE) goto L_13f1c8;
L_13f198:
    cpu->regs[26] = cpu->regs[22] + 1ULL;
    cpu->regs[24] = 2ULL;
L_13f1a0:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + (cpu->regs[24] << 3)));
    if ((cpu->regs[0])==0) goto L_13f1bc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if (((cpu->regs[2] >> 31) & 1)) goto L_13f1bc;
    PB_STR((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_13f4cc;
L_13f1bc:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_LT) goto L_13f1a0;
L_13f1c8:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_LDRB(cpu->regs[1], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 136));
    cpu->regs[1] = cpu->regs[22] - cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x13f1e8ULL; PB_CALL(12, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_13f1ec:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 168));
    PB_STR((cpu->regs[19] + -24), 0ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8));
    if (((cpu->regs[1] >> 14) & 1)) goto L_13f2ac;
L_13f1fc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_13f464;
    if (((cpu->regs[1] >> 9) & 1)) goto L_13f464;
    cpu->regs[0] = PB_BASE + 0xea000ULL;
    cpu->regs[0] = cpu->regs[0] + 64ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_13f3b0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 320));
    cpu->regs[0] = PB_BASE + 0xdf000ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_13f3ec;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[30] = PB_BASE + 0x13f244ULL; PB_CALL(13, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13f258;
L_13f24c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13f560;
L_13f258:
    if ((cpu->regs[23])==0) goto L_13f278;
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[23] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_13f278;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 160));
    if ((cpu->regs[2])!=0) goto L_13f5d8;
L_13f278:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_13f27c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_13f28c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    cpu->regs[21] = cpu->regs[22];
    if (((cpu->regs[0] >> 4) & 1)) goto L_13f148;
L_13f298:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 288));
    if ((cpu->regs[0])!=0) goto L_13f428;
L_13f2a0:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 168));
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_13f1fc;
L_13f2ac:
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x13f2c0ULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    cpu->regs[3] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[2] = cpu->regs[2] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[4]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[2]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
    goto L_13f1fc;
L_13f2f0:
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 48));
    cpu->regs[24] = PB_BASE + 0x13e000ULL;
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_13f028;
L_13f304:
    cpu->regs[23] = 0ULL;
L_13f308:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 392));
    cpu->regs[21] = cpu->regs[22];
    if ((cpu->regs[0])==0) goto L_13f0a4;
L_13f314:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f31cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd9444ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f324ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1379e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13f258;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f334ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 208));
    if ((cpu->regs[1])==0) goto L_13f584;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 208));
    if ((cpu->regs[1])!=0) goto L_13f5c8;
    cpu->regs[30] = PB_BASE + 0x13f348ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_LDR(cpu->regs[5], (cpu->regs[22] + 376));
    if ((cpu->regs[5])!=0) goto L_13f380;
L_13f350:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 208));
    if ((cpu->regs[0])==0) goto L_13f0d4;
L_13f358:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 208));
    if ((cpu->regs[0])!=0) goto L_13f0d4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 208));
    cpu->regs[20] = cpu->regs[19] + cpu->regs[20];
L_13f36c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_13f0d4;
    cpu->regs[30] = PB_BASE + 0x13f378ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1ded20ULL);
    goto L_13f36c;
L_13f37c:
    if ((cpu->regs[5])==0) goto L_13f0d8;
L_13f380:
    cpu->regs[20] = 1ULL;
L_13f384:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f38cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xd9444ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f394ULL; PB_CALL(21, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_13f258;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f3a8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_13f0d4;
    goto L_13f350;
L_13f3b0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f3b8ULL; PB_CALL(23, cpu, tlb, cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13f24c;
    goto L_13f258;
L_13f3c4:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_13f178;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13f3dcULL; PB_CALL(24, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 24));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_GT) goto L_13f180;
    goto L_13f1c8;
L_13f3ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f3f4ULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13f24c;
    goto L_13f258;
L_13f400:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_13f190;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13f418ULL; PB_CALL(26, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 24));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_GT) goto L_13f198;
    goto L_13f1c8;
L_13f428:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 288));
    if ((cpu->regs[0])!=0) goto L_13f2a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f438ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18fb28ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13f2a0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_13f2a0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13f45c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_13f6e0;
L_13f45c:
    PB_STR((cpu->regs[22] + 0), 0ULL);
    goto L_13f2a0;
L_13f464:
    cpu->regs[0] = PB_BASE + 0xea000ULL;
    cpu->regs[0] = cpu->regs[0] + 64ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_13f56c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 320));
    cpu->regs[0] = PB_BASE + 0xdf000ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_13f578;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[30] = PB_BASE + 0x13f4a0ULL; PB_CALL(28, cpu, tlb, cpu->regs[2]);
    goto L_13f258;
L_13f4a4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f4b0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x13fa80ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_13f124;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_13f140;
L_13f4cc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13f4dcULL; PB_CALL(30, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 24));
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_LT) goto L_13f1a0;
    goto L_13f1c8;
L_13f4ec:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f4f8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x13fa80ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 256));
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_13f100;
    goto L_13f140;
L_13f510:
    if ((cpu->regs[22])==0) goto L_13f1ec;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13f1ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_13f1ec;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13f538ULL; PB_CALL(32, cpu, tlb, cpu->regs[1]);
    goto L_13f1ec;
L_13f53c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f548ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x13fa80ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    cpu->regs[0] = cpu->regs[24] + 4032ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 48));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_13f11c;
    goto L_13f140;
L_13f560:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13f568ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13f258;
L_13f56c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f574ULL; PB_CALL(35, cpu, tlb, cpu->regs[20]);
    goto L_13f258;
L_13f578:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f580ULL; PB_CALL(36, cpu, tlb, cpu->regs[1]);
    goto L_13f258;
L_13f584:
    PB_LDR(cpu->regs[5], (cpu->regs[22] + 376));
    if ((cpu->regs[5])==0) goto L_13f0d4;
    cpu->regs[20] = 1ULL;
    goto L_13f384;
L_13f594:
    cpu->regs[30] = PB_BASE + 0x13f598ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_13f6c8;
L_13f5a8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_13f27c;
L_13f5c8:
    PB_LDR(cpu->regs[5], (cpu->regs[22] + 376));
    if ((cpu->regs[5])==0) goto L_13f358;
    cpu->regs[20] = 1ULL;
    goto L_13f384;
L_13f5d8:
    PB_STRW((cpu->regs[23] + 152), cpu->regs[1]);
    goto L_13f5fc;
L_13f5e0:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[23] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x13f5f8ULL; PB_CALL(38, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 160));
L_13f5fc:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])!=0) goto L_13f5e0;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[23] + 152), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_13f27c;
L_13f618:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 392));
    if ((cpu->regs[1])!=0) goto L_13f6d0;
L_13f620:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 376));
    if ((cpu->regs[1])!=0) goto L_13f6b0;
L_13f628:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = PB_BASE + 0x13e000ULL;
    cpu->regs[24] = cpu->regs[24] + 4032ULL;
L_13f634:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_EQ) goto L_13f68c;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_13f694;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 168));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[2] & 512ULL;
    cpu->regs[30] = PB_BASE + 0x13f65cULL; PB_CALL(39, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[19])!=0) goto L_13f278;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13f278;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_13f278;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_13f68c:
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 256));
    goto L_13f634;
L_13f694:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_13f6b0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f6b8ULL; PB_CALL(41, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_13f27c;
    goto L_13f628;
L_13f6c8:
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 48));
    goto L_13f054;
L_13f6d0:
    cpu->regs[30] = PB_BASE + 0x13f6d4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1379e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_13f620;
    goto L_13f27c;
L_13f6e0:
    cpu->regs[30] = PB_BASE + 0x13f6e4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_STR((cpu->regs[22] + 0), 0ULL);
    goto L_13f2a0;
}
