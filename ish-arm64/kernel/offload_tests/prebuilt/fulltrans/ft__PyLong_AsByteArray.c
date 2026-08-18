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

void ft__PyLong_AsByteArray(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16));
    cpu->regs[6] = cpu->regs[5] & 3ULL;
    cpu->regs[5] = cpu->regs[5] >> 3;
    cpu->regs[14] = cpu->regs[5];
    FLAG_CMP(cpu->regs[6], 2ULL);
    if (FLAG_EQ) goto L_145190;
    cpu->regs[11] = 0ULL;
L_144da4:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1451cc;
    cpu->regs[17] = cpu->regs[11];
    if ((cpu->regs[5])==0) goto L_14514c;
    cpu->regs[13] = cpu->regs[0] + 24ULL;
    cpu->regs[15] = cpu->regs[14] - 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[9] = 0ULL;
    cpu->regs[8] = 0ULL;
    cpu->regs[10] = 0ULL;
    cpu->regs[16] = 1ULL;
L_144dcc:
    PB_LDRW(cpu->regs[3], (cpu->regs[13] + (cpu->regs[10] << 2)));
    if ((((uint32_t)(cpu->regs[11])))!=0) goto L_145040;
L_144dd4:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[9] & 63);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[8];
    FLAG_CMP(cpu->regs[15], cpu->regs[10]);
    if (FLAG_EQ) goto L_145084;
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_HS) goto L_145170;
    cpu->regs[12] = ((uint32_t)(cpu->regs[9] + 30ULL));
L_144df4:
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] & 255ULL));
    PB_STRB((cpu->regs[1] + 0), cpu->regs[3]);
    cpu->regs[7] = cpu->regs[1] + 1ULL;
    cpu->regs[6] = cpu->regs[0] >> 8;
    FLAG_CMP(cpu->regs[2], cpu->regs[16]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[3] = cpu->regs[5] + 2ULL;
    cpu->regs[18] = cpu->regs[1] + 2ULL;
    cpu->regs[8] = cpu->regs[0] >> 16;
    PB_STRB((cpu->regs[7] + 0), cpu->regs[6]);
L_144e1c:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[3] = cpu->regs[2] - cpu->regs[5];
    cpu->regs[9] = ((uint32_t)(cpu->regs[12] - 24ULL));
    PB_STRB((cpu->regs[18] + 0), cpu->regs[8]);
    cpu->regs[6] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[8] = cpu->regs[0] >> 24;
    cpu->regs[3] = cpu->regs[1] + 3ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_145074;
    cpu->regs[7] = cpu->regs[6] - cpu->regs[3];
    cpu->regs[7] = cpu->regs[7] & 7ULL; FLAG_CMP(cpu->regs[7], 0);
    if (FLAG_EQ) goto L_144f30;
    cpu->regs[9] = ((uint32_t)(cpu->regs[12] - 32ULL));
    PB_STRB((cpu->regs[3] + 0), cpu->regs[8]);
    cpu->regs[5] = cpu->regs[1] + 4ULL;
    cpu->regs[8] = cpu->regs[0] >> 32;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[3] = cpu->regs[5];
    FLAG_CMP(cpu->regs[7], 1ULL);
    if (FLAG_EQ) goto L_144f30;
    FLAG_CMP(cpu->regs[7], 2ULL);
    if (FLAG_EQ) goto L_144f18;
    FLAG_CMP(cpu->regs[7], 3ULL);
    if (FLAG_EQ) goto L_144f00;
    FLAG_CMP(cpu->regs[7], 4ULL);
    if (FLAG_EQ) goto L_144ee8;
    FLAG_CMP(cpu->regs[7], 5ULL);
    if (FLAG_EQ) goto L_144ed0;
    FLAG_CMP(cpu->regs[7], 6ULL);
    if (FLAG_EQ) goto L_144eb8;
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB((cpu->regs[1] + 4), cpu->regs[8]);
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[3] = cpu->regs[5];
L_144eb8:
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB(cpu->regs[5], cpu->regs[8]); cpu->regs[5] += 1;
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[3] = cpu->regs[5];
L_144ed0:
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB(cpu->regs[5], cpu->regs[8]); cpu->regs[5] += 1;
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[3] = cpu->regs[5];
L_144ee8:
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB(cpu->regs[5], cpu->regs[8]); cpu->regs[5] += 1;
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[3] = cpu->regs[5];
L_144f00:
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB(cpu->regs[5], cpu->regs[8]); cpu->regs[5] += 1;
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[3] = cpu->regs[5];
L_144f18:
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB(cpu->regs[5], cpu->regs[8]); cpu->regs[5] += 1;
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
L_144f2c:
    cpu->regs[3] = cpu->regs[5];
L_144f30:
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    FLAG_CMP(cpu->regs[3], cpu->regs[6]);
    if (FLAG_EQ) goto L_145170;
    PB_STRB(cpu->regs[5], cpu->regs[8]); cpu->regs[5] += 1;
    cpu->regs[7] = cpu->regs[9];
    cpu->regs[8] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB((cpu->regs[5] + 0), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] - 16ULL));
    PB_STRB((cpu->regs[5] + 0), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] - 24ULL));
    PB_STRB((cpu->regs[0] + 2), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[0] + 2ULL;
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[0] + 3ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] - 32ULL));
    PB_STRB((cpu->regs[0] + 3), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[0] + 4ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] - 40ULL));
    PB_STRB((cpu->regs[0] + 4), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[0] + 5ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] - 48ULL));
    PB_STRB((cpu->regs[0] + 5), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[0] + 6ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14501c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] - 56ULL));
    PB_STRB((cpu->regs[0] + 6), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[8] = cpu->regs[8] >> 8;
    cpu->regs[5] = cpu->regs[0] + 7ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_144f2c;
L_14501c:
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[5] = cpu->regs[3] + cpu->regs[16];
L_145028:
    cpu->regs[10] = cpu->regs[10] + 1ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[14]);
    if (FLAG_EQ) goto L_145100;
    PB_LDRW(cpu->regs[3], (cpu->regs[13] + (cpu->regs[10] << 2)));
    cpu->regs[16] = cpu->regs[5] + 1ULL;
    if ((((uint32_t)(cpu->regs[11])))==0) goto L_144dd4;
L_145040:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[17] + cpu->regs[3]));
    cpu->regs[0] = cpu->regs[3] & 1073741823ULL;
    cpu->regs[6] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    cpu->regs[17] = ((uint32_t)(cpu->regs[3] >> 30));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[9] & 63);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[8];
    FLAG_CMP(cpu->regs[15], cpu->regs[10]);
    if (FLAG_EQ) goto L_145080;
    cpu->regs[12] = ((uint32_t)(cpu->regs[9] + 30ULL));
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_LO) goto L_144df4;
    goto L_145170;
L_145074:
    cpu->regs[5] = cpu->regs[5] + 3ULL;
    cpu->regs[1] = cpu->regs[3];
    goto L_145028;
L_145080:
    cpu->regs[3] = ((uint32_t)(cpu->regs[6] ^ 1073741823ULL));
L_145084:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1450f0;
    cpu->regs[3] = (((uint32_t)(((uint32_t)(cpu->regs[3])))) == 0) ? 32 : (uint64_t)__builtin_clz(((uint32_t)(((uint32_t)(cpu->regs[3])))));
    cpu->regs[12] = ((uint32_t)(cpu->regs[9] + 32ULL));
    cpu->regs[12] = ((uint32_t)(cpu->regs[12] - cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[12])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_1450ec;
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_HS) goto L_145170;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[9] = ((uint32_t)(cpu->regs[12] - 8ULL));
    cpu->regs[8] = cpu->regs[0] >> 8;
    PB_STRB(cpu->regs[3], cpu->regs[0]); cpu->regs[3] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_145318;
    FLAG_CMP(cpu->regs[2], cpu->regs[16]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[9] = ((uint32_t)(cpu->regs[12] - 16ULL));
    PB_STRB((cpu->regs[1] + 1), cpu->regs[8]);
    cpu->regs[3] = cpu->regs[5] + 2ULL;
    cpu->regs[18] = cpu->regs[1] + 2ULL;
    cpu->regs[8] = cpu->regs[0] >> 16;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_144e1c;
    cpu->regs[1] = cpu->regs[18];
    cpu->regs[5] = cpu->regs[3];
    goto L_145028;
L_1450ec:
    cpu->regs[9] = cpu->regs[12];
L_1450f0:
    cpu->regs[10] = cpu->regs[10] + 1ULL;
    cpu->regs[8] = cpu->regs[0];
    FLAG_CMP(cpu->regs[14], cpu->regs[10]);
    if (FLAG_NE) goto L_144dcc;
L_145100:
    cpu->regs[0] = 1ULL;
L_145104:
    if ((((uint32_t)(cpu->regs[9])))==0) goto L_145150;
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_HS) goto L_145170;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    if ((((uint32_t)(cpu->regs[11])))!=0) goto L_1451bc;
L_145118:
    PB_STRB((cpu->regs[1] + 0), cpu->regs[8]);
    cpu->regs[1] = cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
L_145120:
    cpu->regs[3] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[11])));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] & 255ULL));
L_145128:
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_HS) goto L_145140;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    PB_STRB((cpu->regs[1] + 0), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    goto L_145128;
L_145140:
    cpu->regs[0] = 0ULL;
L_145144:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_14514c:
    cpu->regs[0] = 1ULL;
L_145150:
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[5]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_145120;
    cpu->regs[0] = cpu->regs[1] - ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    do { int8_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(((uint32_t)(cpu->regs[11])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_145140;
L_145170:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3168ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x145188ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_145144;
L_145190:
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_14519c;
    cpu->regs[11] = 1ULL;
    goto L_144da4;
L_14519c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3128ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1451b4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_145144;
L_1451bc:
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[9] & 63);
    cpu->regs[8] = cpu->regs[8] | cpu->regs[3];
    goto L_145118;
L_1451cc:
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    cpu->regs[10] = cpu->regs[11];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    if ((cpu->regs[5])==0) goto L_145324;
    cpu->regs[13] = cpu->regs[0] + 24ULL;
    cpu->regs[15] = cpu->regs[14] - 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[9] = 0ULL;
    cpu->regs[8] = 0ULL;
    cpu->regs[7] = 0ULL;
L_1451f4:
    PB_LDRW(cpu->regs[0], (cpu->regs[13] + (cpu->regs[7] << 2)));
    if ((((uint32_t)(cpu->regs[11])))!=0) goto L_1452ac;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[9] & 63);
    cpu->regs[8] = cpu->regs[8] | cpu->regs[3];
    FLAG_CMP(cpu->regs[7], cpu->regs[15]);
    if (FLAG_EQ) goto L_1452d4;
L_145210:
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] + 30ULL));
    cpu->regs[3] = cpu->regs[5] + 1ULL;
    cpu->regs[0] = cpu->regs[8] >> 8;
    PB_STRB(cpu->regs[1], cpu->regs[8]); cpu->regs[1] += -1;
L_145228:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[6] = ((uint32_t)(cpu->regs[9] - 16ULL));
    PB_STRB((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[5] + 2ULL;
    cpu->regs[0] = cpu->regs[8] >> 16;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_145310;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[6] = ((uint32_t)(cpu->regs[9] - 24ULL));
    PB_STRB((cpu->regs[1] + -1), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[5] + 3ULL;
    cpu->regs[1] = cpu->regs[1] - 2ULL;
    cpu->regs[0] = cpu->regs[8] >> 24;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14528c;
L_14526c:
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - 8ULL));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_145170;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += -1;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = cpu->regs[0] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_14526c;
L_14528c:
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[9] = cpu->regs[6];
    cpu->regs[8] = cpu->regs[0];
L_145298:
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[14]);
    if (FLAG_NE) goto L_1451f4;
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_145104;
L_1452ac:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + cpu->regs[10]));
    cpu->regs[6] = cpu->regs[3] & 1073741823ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    cpu->regs[10] = ((uint32_t)(cpu->regs[3] >> 30));
    cpu->regs[3] = cpu->regs[6] << (cpu->regs[9] & 63);
    cpu->regs[8] = cpu->regs[8] | cpu->regs[3];
    FLAG_CMP(cpu->regs[7], cpu->regs[15]);
    if (FLAG_NE) goto L_145210;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1073741823ULL));
L_1452d4:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_145298;
    cpu->regs[0] = (((uint32_t)(((uint32_t)(cpu->regs[0])))) == 0) ? 32 : (uint64_t)__builtin_clz(((uint32_t)(((uint32_t)(cpu->regs[0])))));
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] + 32ULL));
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] - cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_145298;
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_LS) goto L_145170;
    cpu->regs[6] = ((uint32_t)(cpu->regs[9] - 8ULL));
    PB_STRB(cpu->regs[1], cpu->regs[8]); cpu->regs[1] += -1;
    cpu->regs[3] = cpu->regs[5] + 1ULL;
    cpu->regs[0] = cpu->regs[8] >> 8;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_14528c;
    goto L_145228;
L_145310:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    goto L_14528c;
L_145318:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[5] = cpu->regs[16];
    goto L_145028;
L_145324:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_145150;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[5] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_145560;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_145434;
    cpu->regs[0] = cpu->regs[2] + 40ULL;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_14543c;
L_145360:
    if (!((cpu->regs[1] >> 6) & 1)) goto L_1453d4;
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 16));
    cpu->regs[1] = cpu->regs[3] + 40ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    cpu->regs[2] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1453f0;
L_145380:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_145450;
    cpu->regs[30] = PB_BASE + 0x14538cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7ab70ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GE) goto L_1453b0;
L_145394:
    cpu->regs[0] = 4294967295ULL;
L_145398:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1453a4:
    cpu->regs[30] = PB_BASE + 0x1453a8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7ac10ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_145394;
L_1453b0:
    if (FLAG_EQ) goto L_1453c4;
    cpu->regs[0] = 1ULL;
L_1453b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1453c4:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_145444;
    cpu->regs[0] = 0ULL;
    goto L_145398;
L_1453d4:
    cpu->regs[1] = cpu->regs[3] + 56ULL;
L_1453d8:
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 16));
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    cpu->regs[2] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[19];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_145380;
L_1453f0:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_145480;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 1);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1454b0;
L_145408:
    cpu->regs[4] = cpu->regs[0] + cpu->regs[3];
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRH(cpu->regs[5], (cpu->regs[0] + cpu->regs[3]));
    PB_LDRH(cpu->regs[4], (cpu->regs[1] + cpu->regs[3]));
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_EQ) goto L_145408;
L_145428:
    if (FLAG_LO) goto L_145394;
L_14542c:
    cpu->regs[0] = 1ULL;
    goto L_1453b8;
L_145434:
    cpu->regs[0] = cpu->regs[2] + 56ULL;
    if (((cpu->regs[1] >> 5) & 1)) goto L_145360;
L_14543c:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 56));
    goto L_1453d8;
L_145444:
    if (FLAG_LT) goto L_145394;
    cpu->regs[0] = 1ULL;
    goto L_1453b8;
L_145450:
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1454dc;
L_14545c:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRB(cpu->regs[5], (cpu->regs[0] + cpu->regs[3]));
    PB_LDRH(cpu->regs[4], (cpu->regs[1] + (cpu->regs[3] << 1)));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_EQ) goto L_14545c;
    if (FLAG_LO) goto L_145394;
    goto L_14542c;
L_145480:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_145508;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 2);
L_14548c:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_145428;
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_14548c;
L_1454b0:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_145540;
L_1454b8:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRH(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_145428;
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_1454b8;
L_1454dc:
    cpu->regs[1] = cpu->regs[1] - 4ULL;
    cpu->regs[3] = 0ULL;
L_1454e4:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRB(cpu->regs[5], (cpu->regs[0] + cpu->regs[3]));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + (cpu->regs[3] << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_EQ) goto L_1454e4;
    if (FLAG_LO) goto L_145394;
    goto L_14542c;
L_145508:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1453a4;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 2);
L_145514:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRH(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_145428;
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    goto L_145514;
L_145538:
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    cpu->regs[1] = cpu->regs[1] + 4ULL;
L_145540:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1453c4;
    PB_LDRH(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_145538;
    if (FLAG_LO) goto L_145394;
    goto L_14542c;
L_145560:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 56));
    if (((cpu->regs[1] >> 5) & 1)) goto L_145360;
    goto L_14543c;
}
