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

void ft__PyObject_Call_Prepend(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[4];
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[2];
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[26] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    FLAG_CMP(cpu->regs[26], 5ULL);
    if (FLAG_GT) goto L_122c74;
    cpu->regs[1] = cpu->regs[19] + 24ULL;
    cpu->regs[0] = SP + 8ULL;
    PB_STR((SP + 0), cpu->regs[25]);
    cpu->regs[2] = cpu->regs[20] << 3;
    cpu->regs[21] = SP;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HI) goto L_122cac;
    if (FLAG_HS) goto L_122cb8;
L_122c00:
    cpu->regs[3] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LO) goto L_122ce8;
L_122c0c:
    cpu->regs[30] = PB_BASE + 0x122c10ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x122c28ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xeda60ULL);
    cpu->regs[1] = SP;
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_NE) goto L_122ca0;
L_122c38:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_122cec;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_122c74:
    cpu->regs[0] = cpu->regs[26] << 3;
    cpu->regs[30] = PB_BASE + 0x122c7cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_122cf0;
    PB_STR(cpu->regs[0], cpu->regs[25]); cpu->regs[0] += 8;
    cpu->regs[1] = cpu->regs[19] + 24ULL;
    cpu->regs[2] = cpu->regs[20] << 3;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_122cdc;
    if (FLAG_HI) goto L_122c00;
    goto L_122c0c;
L_122ca0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x122ca8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_122c38;
L_122cac:
    cpu->regs[3] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LO) goto L_122ce8;
L_122cb8:
    cpu->regs[30] = PB_BASE + 0x122cbcULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x122cd4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xeda60ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_122c38;
L_122cdc:
    cpu->regs[3] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_HS) goto L_122c0c;
L_122ce8:
    __builtin_trap();
L_122cec:
    cpu->regs[30] = PB_BASE + 0x122cf0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_122cf0:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x122cf8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_122c38;
    /* nop */
    SP = SP - 112ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[2] = 1152921504606846974ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[26], (cpu->regs[21] + 16));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[26];
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_LT) goto L_1230dc;
    cpu->regs[0] = cpu->regs[20] + 1ULL;
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[26];
    cpu->regs[1] = cpu->regs[0] << 3;
    if (((cpu->regs[0] >> 60) & 1)) goto L_1230dc;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[24] = cpu->regs[4];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x122d78ULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1230dc;
    if ((cpu->regs[26])==0) goto L_123034;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x122d8cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdc8acULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1230c4;
    FLAG_CMP(cpu->regs[26], 0ULL);
    if (FLAG_LE) goto L_122dac;
    cpu->regs[2] = cpu->regs[26] << 3;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x122dacULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7aee0ULL);
L_122dac:
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x122dc0ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[2] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[26] = cpu->regs[23] + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[3]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_122e80;
L_122df8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_122e0c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_122e0c:
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_122e80;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_122e2c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_122e2c:
    PB_STR((cpu->regs[23] + 16), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_122e80;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_122e4c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_122e4c:
    PB_STR((cpu->regs[23] + 24), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_122e80;
    cpu->regs[2] = 3ULL;
L_122e5c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[2] << 3)));
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_123018;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[26] + (cpu->regs[2] << 3)), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_NE) goto L_122e5c;
L_122e80:
    cpu->regs[3] = SP;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0x122e9cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_122fd0;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[11], (cpu->regs[5] + 168));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    PB_LDR(cpu->regs[5], (SP + 0));
    cpu->regs[11] = cpu->regs[11] & 268435456ULL;
    if (FLAG_NE) goto L_12306c;
L_122ec0:
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[12] = cpu->regs[20] << 3;
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[4] = cpu->regs[26] + (cpu->regs[20] << 3);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_123010;
L_122ed8:
    PB_STR((cpu->regs[4] + 0), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x122ee8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_122fcc;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 168));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[11] = cpu->regs[11] & cpu->regs[5];
    if (FLAG_NE) goto L_123074;
L_122f08:
    PB_LDR(cpu->regs[5], (SP + 0));
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    cpu->regs[4] = cpu->regs[12] + 8ULL;
    cpu->regs[4] = cpu->regs[26] + cpu->regs[4];
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_123064;
L_122f24:
    PB_STR((cpu->regs[4] + 0), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x122f34ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_122fcc;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 168));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[11] = cpu->regs[11] & cpu->regs[5];
    if (FLAG_NE) goto L_123084;
L_122f54:
    PB_LDR(cpu->regs[5], (SP + 0));
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    cpu->regs[4] = cpu->regs[12] + 16ULL;
    cpu->regs[4] = cpu->regs[26] + cpu->regs[4];
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_12302c;
L_122f70:
    cpu->regs[12] = cpu->regs[23] + cpu->regs[12];
    cpu->regs[14] = cpu->regs[19] + 16ULL;
    cpu->regs[13] = 4ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[5]);
L_122f80:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x122f8cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_122fcc;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 168));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[11] = cpu->regs[11] & cpu->regs[5];
    if (FLAG_NE) goto L_12307c;
L_122fac:
    PB_LDR(cpu->regs[4], (SP + 0));
    PB_STR((cpu->regs[14] + (cpu->regs[13] << 3)), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_12305c;
L_122fc0:
    PB_STR((cpu->regs[12] + (cpu->regs[13] << 3)), cpu->regs[4]);
    cpu->regs[13] = cpu->regs[13] + 1ULL;
    goto L_122f80;
L_122fcc:
    if ((cpu->regs[11])==0) goto L_123090;
L_122fd0:
    PB_STR((cpu->regs[24] + 0), cpu->regs[19]);
L_122fd4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_12308c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[26];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_123010:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
    goto L_122ed8;
L_123018:
    PB_STR((cpu->regs[26] + (cpu->regs[2] << 3)), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_NE) goto L_122e5c;
    goto L_122e80;
L_12302c:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
    goto L_122f70;
L_123034:
    cpu->regs[1] = cpu->regs[19] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1230d4;
L_123044:
    cpu->regs[19] = cpu->regs[19] + (18ULL << 12);
    cpu->regs[26] = cpu->regs[23] + 8ULL;
    cpu->regs[19] = cpu->regs[19] + 1808ULL;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_GT) goto L_122df8;
    goto L_122e80;
L_12305c:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[0]);
    goto L_122fc0;
L_123064:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
    goto L_122f24;
L_12306c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[4]);
    goto L_122ec0;
L_123074:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[4]);
    goto L_122f08;
L_12307c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[4]);
    goto L_122fac;
L_123084:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[4]);
    goto L_122f54;
L_12308c:
    cpu->regs[30] = PB_BASE + 0x123090ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_123090:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    cpu->regs[2] = cpu->regs[2] + 1352ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1230acULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1230c0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1a76e4ULL);
    goto L_122fd4;
L_1230c4:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1230d0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_122fd4;
L_1230d4:
    PB_STRW((cpu->regs[1] + 10000), cpu->regs[0]);
    goto L_123044;
L_1230dc:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1230e8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x22d7a8ULL);
    goto L_122fd4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0] - 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 136));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    cpu->regs[30] = PB_BASE + 0x123114ULL; PB_CALL(22, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_123144;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_123144;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_123144:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + -16));
    if ((cpu->regs[0])!=0) goto L_1232fc;
L_12316c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x123000ULL;
    cpu->regs[0] = cpu->regs[0] + 336ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_12322c;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x123198ULL; PB_CALL(23, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[20])==0) goto L_123384;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 152));
    cpu->regs[1] = cpu->regs[20] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_123398;
L_1231b0:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[21] = cpu->regs[19] + 48ULL;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_EQ) goto L_123240;
L_1231c8:
    cpu->regs[22] = 0ULL;
L_1231cc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_123328;
L_1231d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_1233d4;
L_1231dc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1231e4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    if ((cpu->regs[22])==0) goto L_1231fc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1231fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_123348;
L_1231fc:
    if ((cpu->regs[20])==0) goto L_12321c;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_12321c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 160));
    if ((cpu->regs[2])!=0) goto L_1233f4;
L_12321c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_12322c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[21] = cpu->regs[19] + 48ULL;
    cpu->regs[20] = 0ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_1231c8;
L_123240:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 70));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1231c8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if ((cpu->regs[0])==0) goto L_123274;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 64), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_123274;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_123354;
L_123274:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])!=0) goto L_1233b4;
L_12327c:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1231cc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])==0) goto L_1232a8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1232a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12337c;
L_1232a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_1231cc;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[19] + 128ULL;
    cpu->regs[24] = 1ULL;
L_1232c0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if ((cpu->regs[0])==0) goto L_1232e0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[23] + 0), 0ULL);
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1232e0;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_12335c;
L_1232e0:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    cpu->regs[23] = cpu->regs[23] + 8ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LT) goto L_1232c0;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1231cc;
L_1232fc:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[0] = cpu->regs[0] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[0]);
    goto L_12316c;
L_123328:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1231d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1231d4;
    cpu->regs[30] = PB_BASE + 0x123344ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1231d4;
L_123348:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x123350ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1231fc;
L_123354:
    cpu->regs[30] = PB_BASE + 0x123358ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_123274;
L_12335c:
    cpu->regs[30] = PB_BASE + 0x123360ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 64));
    cpu->regs[23] = cpu->regs[23] + 8ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_GT) goto L_1232c0;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1231cc;
L_12337c:
    cpu->regs[30] = PB_BASE + 0x123380ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1232a8;
L_123384:
    cpu->regs[30] = PB_BASE + 0x123388ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_1231b0;
L_123398:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[19]);
    goto L_12321c;
L_1233b4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_12327c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12327c;
    cpu->regs[30] = PB_BASE + 0x1233d0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12327c;
L_1233d4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1231dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1231dc;
    cpu->regs[30] = PB_BASE + 0x1233f0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1231dc;
L_1233f4:
    PB_STRW((cpu->regs[20] + 152), cpu->regs[1]);
L_1233f8:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])==0) goto L_123420;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[20] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x123418ULL; PB_CALL(33, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 160));
    goto L_1233f8;
L_123420:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 152), cpu->regs[0]);
    goto L_12321c;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x123454ULL; PB_CALL(34, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[20], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_12356c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_NE) goto L_1234cc;
L_12347c:
    if ((cpu->regs[3])!=0) goto L_12363c;
L_123480:
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1235bc;
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 36));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_123614;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    if ((cpu->regs[2])==0) goto L_123608;
L_1234a8:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0x1234b0ULL; PB_CALL(35, cpu, tlb, cpu->regs[2]);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 36));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[1]);
L_1234c0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1234cc:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 344));
    if ((cpu->regs[5])==0) goto L_123554;
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_LE) goto L_123540;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 24));
    FLAG_CMP(cpu->regs[4], cpu->regs[7]);
    if (FLAG_EQ) goto L_12347c;
    FLAG_CMP(cpu->regs[6], 1ULL);
    if (FLAG_EQ) goto L_123540;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 32));
    FLAG_CMP(cpu->regs[4], cpu->regs[7]);
    if (FLAG_EQ) goto L_12347c;
    FLAG_CMP(cpu->regs[6], 2ULL);
    if (FLAG_EQ) goto L_123540;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 40));
    FLAG_CMP(cpu->regs[7], cpu->regs[4]);
    if (FLAG_EQ) goto L_12347c;
    FLAG_CMP(cpu->regs[6], 3ULL);
    if (FLAG_EQ) goto L_123540;
    cpu->regs[5] = cpu->regs[5] + 24ULL;
    cpu->regs[7] = 3ULL;
L_123524:
    PB_LDR(cpu->regs[8], (cpu->regs[5] + (cpu->regs[7] << 3)));
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[8]);
    if (FLAG_EQ) goto L_12347c;
    FLAG_CMP(cpu->regs[6], cpu->regs[7]);
    if (FLAG_NE) goto L_123524;
    /* nop */
L_123540:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x123548ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1985a8ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
L_12354c:
    cpu->regs[0] = 0ULL;
    goto L_1234c0;
L_123554:
    cpu->regs[5] = cpu->regs[1];
L_123558:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 256));
    if ((cpu->regs[5])==0) goto L_12367c;
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_EQ) goto L_12347c;
    goto L_123558;
L_12356c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x123574ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12354c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x123598ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12354c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12354c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1235b4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1234c0;
L_1235bc:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1235c8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_123608;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    PB_LDR(cpu->regs[2], (SP + 56));
    cpu->regs[1] = cpu->regs[1] + 592ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1235f4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_123608;
L_1235fc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_123690;
L_123608:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    goto L_1234c0;
L_123614:
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    cpu->regs[30] = PB_BASE + 0x123624ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x26c444ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_123608;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    if ((cpu->regs[2])==0) goto L_123608;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    goto L_1234a8;
L_12363c:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    if ((cpu->regs[1])==0) goto L_123480;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12364cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_123608;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 4072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x123670ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1235fc;
    goto L_123608;
L_12367c:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3488));
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_EQ) goto L_12347c;
    goto L_123540;
L_123690:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x123698ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    goto L_1234c0;
    SP = SP - 176ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[6] + 0));
    PB_STR((SP + 136), cpu->regs[8]);
    cpu->regs[8] = 0ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LT) goto L_123aec;
    PB_STR((SP + 160), cpu->regs[19]);
    cpu->regs[7] = cpu->regs[1];
    cpu->regs[9] = cpu->regs[3];
    cpu->regs[11] = cpu->regs[2];
    cpu->regs[10] = cpu->regs[4];
    cpu->regs[12] = cpu->regs[5];
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_LE) goto L_1238d0;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_123ab8;
    FLAG_CMP(cpu->regs[1], 2499ULL);
    if (FLAG_GT) goto L_123cb8;
    cpu->regs[5] = cpu->regs[3] - 1ULL;
    PB_LDRB(cpu->regs[13], (cpu->regs[2] + 0));
    cpu->regs[6] = cpu->regs[3] - 2ULL;
    cpu->regs[7] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[19] + cpu->regs[5];
    PB_LDRB(cpu->regs[3], (cpu->regs[11] + cpu->regs[5]));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[13] & 63);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[13])));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[6] : cpu->regs[5];
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_1237c0;
L_123730:
    PB_LDRB(cpu->regs[8], (cpu->regs[11] + 1));
    cpu->regs[1] = cpu->regs[9] - 3ULL;
    cpu->regs[6] = 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[4];
    cpu->regs[8] = cpu->regs[6] << (cpu->regs[8] & 63);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[8];
    FLAG_CMP(cpu->regs[5], 2ULL);
    if (FLAG_EQ) goto L_1237c0;
    PB_LDRB(cpu->regs[1], (cpu->regs[11] + 2));
    cpu->regs[8] = cpu->regs[9] - 4ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[8] : cpu->regs[4];
    cpu->regs[1] = cpu->regs[6] << (cpu->regs[1] & 63);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 3ULL);
    if (FLAG_EQ) goto L_1237c0;
    PB_LDRB(cpu->regs[1], (cpu->regs[11] + 3));
    cpu->regs[8] = cpu->regs[9] - 5ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[8] : cpu->regs[4];
    cpu->regs[1] = cpu->regs[6] << (cpu->regs[1] & 63);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    FLAG_CMP(cpu->regs[5], 4ULL);
    if (FLAG_EQ) goto L_1237c0;
    cpu->regs[15] = cpu->regs[9] - 2ULL;
    cpu->regs[1] = 4ULL;
L_12379c:
    PB_LDRB(cpu->regs[8], (cpu->regs[11] + cpu->regs[1]));
    cpu->regs[14] = cpu->regs[15] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[14] : cpu->regs[4];
    cpu->regs[8] = cpu->regs[6] << (cpu->regs[8] & 63);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[8];
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_LT) goto L_12379c;
L_1237c0:
    cpu->regs[8] = 1ULL;
    cpu->regs[8] = cpu->regs[8] << (cpu->regs[3] & 63);
    cpu->regs[8] = cpu->regs[8] | cpu->regs[0];
    if (((cpu->regs[7] >> 63) & 1)) goto L_123ae4;
L_1237d0:
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = 0ULL;
    /* nop */
    /* nop */
L_1237e0:
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_123840;
    cpu->regs[6] = cpu->regs[2] + cpu->regs[1];
    PB_LDRB(cpu->regs[6], (cpu->regs[6] + 1));
    cpu->regs[6] = cpu->regs[8] >> (cpu->regs[6] & 63);
    if (((cpu->regs[6] >> 0) & 1)) goto L_12386c;
    cpu->regs[1] = cpu->regs[9] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[7]);
    if (FLAG_LE) goto L_1237e0;
L_12380c:
    PB_LDR(cpu->regs[19], (SP + 160));
    FLAG_CMP(((uint32_t)(cpu->regs[12])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : (~0ULL);
L_123818:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 136));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_123cb0;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    SP = SP + 176ULL;
    return;
L_123840:
    PB_LDRB(cpu->regs[6], (cpu->regs[19] + cpu->regs[1]));
    cpu->regs[14] = cpu->regs[19] + cpu->regs[1];
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[13])));
    if (FLAG_EQ) goto L_12387c;
L_123850:
    cpu->regs[6] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[14] = cpu->regs[1] + cpu->regs[9];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    PB_LDRB(cpu->regs[6], (cpu->regs[6] + 1));
    cpu->regs[6] = cpu->regs[8] >> (cpu->regs[6] & 63);
    FLAG_CMP((cpu->regs[6]) & (1ULL), 0);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[1] : cpu->regs[14];
L_12386c:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[7]);
    if (FLAG_LE) goto L_1237e0;
    goto L_12380c;
L_12387c:
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_1238c0;
    PB_LDRB(cpu->regs[15], (cpu->regs[14] + 1));
    PB_LDRB(cpu->regs[6], (cpu->regs[11] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[15])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_NE) goto L_123850;
    FLAG_CMP(cpu->regs[5], 2ULL);
    if (FLAG_EQ) goto L_1238c0;
    cpu->regs[6] = 2ULL;
L_1238a0:
    PB_LDRB(cpu->regs[16], (cpu->regs[14] + cpu->regs[6]));
    PB_LDRB(cpu->regs[15], (cpu->regs[11] + cpu->regs[6]));
    FLAG_CMP(((uint32_t)(cpu->regs[16])), ((uint32_t)(cpu->regs[15])));
    if (FLAG_NE) goto L_123bd0;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_LT) goto L_1238a0;
    if (FLAG_NE) goto L_123850;
L_1238c0:
    if ((((uint32_t)(cpu->regs[12])))==0) goto L_123c1c;
    PB_LDR(cpu->regs[19], (SP + 160));
    cpu->regs[0] = cpu->regs[1];
    goto L_123818;
L_1238d0:
    if (FLAG_NE) goto L_123b80;
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_123af4;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_123bec;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_123c30;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123c3c;
L_123900:
    FLAG_CMP(cpu->regs[7], 1ULL);
    if (FLAG_EQ) goto L_123ab0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123c4c;
L_123914:
    FLAG_CMP(cpu->regs[7], 2ULL);
    if (FLAG_EQ) goto L_123ab0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123c9c;
L_123928:
    FLAG_CMP(cpu->regs[7], 3ULL);
    if (FLAG_EQ) goto L_123ab0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 3));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123c88;
L_12393c:
    FLAG_CMP(cpu->regs[7], 4ULL);
    if (FLAG_EQ) goto L_123ab0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123c74;
L_123950:
    FLAG_CMP(cpu->regs[7], 5ULL);
    if (FLAG_EQ) goto L_123ab0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 5));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123c60;
L_123964:
    FLAG_CMP(cpu->regs[7], 6ULL);
    if (FLAG_EQ) goto L_123ab0;
    cpu->regs[7] = cpu->regs[19] + cpu->regs[7];
    cpu->regs[1] = cpu->regs[19] + 6ULL;
L_123974:
    cpu->regs[2] = cpu->regs[7] - cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] & 7ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_123a28;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_123a10;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_123a00;
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_EQ) goto L_1239f0;
    FLAG_CMP(cpu->regs[2], 4ULL);
    if (FLAG_EQ) goto L_1239e0;
    FLAG_CMP(cpu->regs[2], 5ULL);
    if (FLAG_EQ) goto L_1239d0;
    FLAG_CMP(cpu->regs[2], 6ULL);
    if (FLAG_EQ) goto L_1239c0;
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_1239c0:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_1239d0:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_1239e0:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_1239f0:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_123a00:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_123a10:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[7]);
    if (FLAG_EQ) goto L_123ab0;
L_123a28:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 1));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[3] = cpu->regs[1];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] += 1; PB_LDRB(cpu->regs[2], cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 2));
    cpu->regs[1] = cpu->regs[3] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 3));
    cpu->regs[1] = cpu->regs[3] + 3ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 4));
    cpu->regs[1] = cpu->regs[3] + 4ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 5));
    cpu->regs[1] = cpu->regs[3] + 5ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 6));
    cpu->regs[1] = cpu->regs[3] + 6ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bb0;
    cpu->regs[1] = cpu->regs[3] + 7ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[7]);
    if (FLAG_NE) goto L_123a28;
L_123ab0:
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123ab8:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_LDR(cpu->regs[6], (SP + 136));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    cpu->regs[6] = cpu->regs[6] - cpu->regs[5]; FLAG_CMP(cpu->regs[6], 0);
    cpu->regs[5] = 0ULL;
    if (FLAG_NE) goto L_123cb4;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    PB_LDR(cpu->regs[19], (SP + 160));
    SP = SP + 176ULL;
    { PB_CALL(46, cpu, tlb, PB_BASE + 0x156380ULL); return; };
L_123ae4:
    cpu->regs[0] = 0ULL;
    goto L_12380c;
L_123aec:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_123818;
L_123af4:
    FLAG_CMP(cpu->regs[1], 15ULL);
    if (FLAG_GT) goto L_123b8c;
    cpu->regs[7] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[7]);
    if (FLAG_HS) goto L_123b80;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123bdc;
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_LS) goto L_123b80;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123be0;
    cpu->regs[0] = cpu->regs[19] + 2ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_LS) goto L_123b80;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123be0;
    cpu->regs[0] = cpu->regs[19] + 3ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_LS) goto L_123b80;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 3));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123be0;
    cpu->regs[0] = cpu->regs[19] + 4ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_LS) goto L_123b80;
L_123b68:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_EQ) goto L_123be0;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_NE) goto L_123b68;
L_123b80:
    PB_LDR(cpu->regs[19], (SP + 160));
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_123818;
L_123b8c:
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x123b98ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x7bdd0ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 160));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : (~0ULL);
    goto L_123818;
L_123bb0:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_EQ) goto L_123ab0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[1]);
    if (FLAG_NE) goto L_123974;
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123bd0:
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_EQ) goto L_1238c0;
    goto L_123850;
L_123bdc:
    cpu->regs[0] = cpu->regs[19];
L_123be0:
    cpu->regs[0] = cpu->regs[0] - cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123bec:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[4], (SP + 136));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_123cb4;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    cpu->regs[2] = cpu->regs[6];
    PB_LDR(cpu->regs[19], (SP + 160));
    SP = SP + 176ULL;
    { PB_CALL(48, cpu, tlb, PB_BASE + 0x1a8180ULL); return; };
L_123c1c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_EQ) goto L_123ab0;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    goto L_12386c;
L_123c30:
    PB_LDR(cpu->regs[19], (SP + 160));
    cpu->regs[0] = 0ULL;
    goto L_123818;
L_123c3c:
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_EQ) goto L_123d88;
    cpu->regs[0] = cpu->regs[3];
    goto L_123900;
L_123c4c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_NE) goto L_123914;
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123c60:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_NE) goto L_123964;
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123c74:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_NE) goto L_123950;
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123c88:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_NE) goto L_12393c;
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123c9c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[0]);
    if (FLAG_NE) goto L_123928;
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123cb0:
    PB_STR((SP + 160), cpu->regs[19]);
L_123cb4:
    cpu->regs[30] = PB_BASE + 0x123cb8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7c170ULL);
L_123cb8:
    FLAG_CMP(cpu->regs[3], 99ULL);
    cpu->regs[6] = 29999ULL;
    if (FLAG_LE) { FLAG_CMP(cpu->regs[1], cpu->regs[6]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) { FLAG_CMP(cpu->regs[3], 5ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_GT) goto L_123d00;
    cpu->regs[5] = cpu->regs[3] - 1ULL;
    PB_LDRB(cpu->regs[13], (cpu->regs[2] + 0));
    cpu->regs[7] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[19] + cpu->regs[5];
    PB_LDRB(cpu->regs[3], (cpu->regs[11] + cpu->regs[5]));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[13] & 63);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[13])));
    if (FLAG_EQ) goto L_123d48;
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_123d94;
    cpu->regs[4] = cpu->regs[5];
    goto L_123730;
L_123d00:
    cpu->regs[6] = (uint64_t)((int64_t)cpu->regs[3] >> 2);
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[6] = cpu->regs[6] + (cpu->regs[6] << 1);
    FLAG_CMP(cpu->regs[6], cpu->regs[1]);
    if (FLAG_GE) goto L_123d5c;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_123da4;
    cpu->regs[2] = SP + 24ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[11];
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x123d30ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x237000ULL);
    PB_LDR(cpu->regs[2], (SP + 0)); PB_LDR(cpu->regs[7], (SP + 0) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x123d40ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x2372e0ULL);
    PB_LDR(cpu->regs[19], (SP + 160));
    goto L_123818;
L_123d48:
    cpu->regs[4] = cpu->regs[9] - 2ULL;
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_NE) goto L_123730;
    cpu->regs[8] = cpu->regs[0];
    goto L_1237d0;
L_123d5c:
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_LDR(cpu->regs[8], (SP + 136));
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 0));
    cpu->regs[8] = cpu->regs[8] - cpu->regs[7]; FLAG_CMP(cpu->regs[8], 0);
    cpu->regs[7] = 0ULL;
    if (FLAG_NE) goto L_123cb4;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    PB_LDR(cpu->regs[19], (SP + 160));
    SP = SP + 176ULL;
    { PB_CALL(52, cpu, tlb, PB_BASE + 0x236b40ULL); return; };
L_123d88:
    PB_LDR(cpu->regs[19], (SP + 160));
    cpu->regs[0] = cpu->regs[4];
    goto L_123818;
L_123d94:
    cpu->regs[8] = cpu->regs[5] << (cpu->regs[3] & 63);
    cpu->regs[4] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] | cpu->regs[0];
    goto L_1237d0;
L_123da4:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_LDR(cpu->regs[7], (SP + 136));
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
    cpu->regs[7] = cpu->regs[7] - cpu->regs[6]; FLAG_CMP(cpu->regs[7], 0);
    cpu->regs[6] = 0ULL;
    if (FLAG_NE) goto L_123cb4;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    PB_LDR(cpu->regs[19], (SP + 160));
    SP = SP + 176ULL;
    { PB_CALL(53, cpu, tlb, PB_BASE + 0x237848ULL); return; };
}
