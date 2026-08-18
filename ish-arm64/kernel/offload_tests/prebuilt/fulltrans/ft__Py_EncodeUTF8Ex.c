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

void ft__Py_EncodeUTF8Ex(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[4];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[5];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1c7008ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7b8b0ULL);
    cpu->regs[25] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1c70ac;
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = 0ULL;
L_1c701c:
    cpu->regs[1] = 2305843009213693950ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[1]);
    if (FLAG_GT) goto L_1c70e8;
    cpu->regs[0] = cpu->regs[25] + 1ULL;
    cpu->regs[0] = cpu->regs[0] << 2;
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1c7148;
    cpu->regs[30] = PB_BASE + 0x1c7038ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd7700ULL);
    cpu->regs[26] = cpu->regs[0];
L_1c703c:
    if ((cpu->regs[26])==0) goto L_1c70e8;
    cpu->regs[6] = cpu->regs[26];
    cpu->regs[5] = 0ULL;
L_1c7048:
    FLAG_CMP(cpu->regs[5], cpu->regs[25]);
    if (FLAG_GE) goto L_1c706c;
    PB_LDRW(cpu->regs[7], (cpu->regs[27] + (cpu->regs[5] << 2)));
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_1c711c;
L_1c7064:
    PB_STRB(cpu->regs[6], cpu->regs[7]); cpu->regs[6] += 1;
    goto L_1c7048;
L_1c706c:
    PB_STRB(cpu->regs[6], 0ULL); cpu->regs[6] += 1;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[6] - cpu->regs[26];
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1c7110;
    cpu->regs[30] = PB_BASE + 0x1c7080ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd77c8ULL);
    cpu->regs[1] = cpu->regs[0];
L_1c7084:
    if ((cpu->regs[1])==0) goto L_1c70d0;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
L_1c7090:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1c70ac:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1c7108;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1c70fc;
    cpu->regs[0] = 4294967293ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(6ULL)));
    if (FLAG_NE) goto L_1c7090;
    cpu->regs[24] = 1ULL;
    cpu->regs[23] = 0ULL;
    goto L_1c701c;
L_1c70d0:
    if ((cpu->regs[21])==0) goto L_1c70dc;
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
L_1c70dc:
    cpu->regs[0] = cpu->regs[26];
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1c70f0;
    cpu->regs[30] = PB_BASE + 0x1c70e8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd7784ULL);
L_1c70e8:
    cpu->regs[0] = 4294967295ULL;
    goto L_1c7090;
L_1c70f0:
    cpu->regs[30] = PB_BASE + 0x1c70f4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1c7090;
L_1c70fc:
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = 1ULL;
    goto L_1c701c;
L_1c7108:
    cpu->regs[0] = 4294967293ULL;
    goto L_1c7090;
L_1c7110:
    cpu->regs[30] = PB_BASE + 0x1c7114ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_1c7084;
L_1c711c:
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(2047ULL)));
    if (FLAG_HI) goto L_1c7154;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[2] = ((uint32_t)(cpu->regs[7] >> 6));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | 4294967232ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & 63ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4294967168ULL));
    PB_STRB(cpu->regs[0], cpu->regs[2]); cpu->regs[0] += 2;
    PB_STRB((cpu->regs[6] + 1), cpu->regs[1]);
    cpu->regs[6] = cpu->regs[0];
    goto L_1c7048;
L_1c7148:
    cpu->regs[30] = PB_BASE + 0x1c714cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[26] = cpu->regs[0];
    goto L_1c703c;
L_1c7154:
    cpu->regs[2] = 4294912000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[7] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2047ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[24] ^ 1ULL));
    cpu->regs[2] = (FLAG_LS) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_NE) goto L_1c71a8;
    cpu->regs[2] = ((cpu->regs[7] >> 6) & 0x3fULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & 63ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | 128ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 128ULL));
    cpu->regs[0] = ((cpu->regs[7] >> 12) & 0xffULL);
    cpu->regs[3] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_HI) goto L_1c71e8;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4294967264ULL));
    cpu->regs[6] = cpu->regs[6] + 3ULL;
    PB_STRB((cpu->regs[6] + -3), cpu->regs[0]);
    PB_STRB((cpu->regs[6] + -2), cpu->regs[2]);
    PB_STRB((cpu->regs[6] + -1), cpu->regs[1]);
    goto L_1c7048;
L_1c71a8:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1c71bc;
    cpu->regs[0] = 4294910848ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[7] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_1c7064;
L_1c71bc:
    if ((cpu->regs[21])==0) goto L_1c71c4;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
L_1c71c4:
    if ((cpu->regs[22])==0) goto L_1c71d4;
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[0] + 2928ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_1c71d4:
    cpu->regs[0] = cpu->regs[26];
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1c7210;
    cpu->regs[30] = PB_BASE + 0x1c71e0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[0] = 4294967294ULL;
    goto L_1c7090;
L_1c71e8:
    cpu->regs[7] = ((uint32_t)(cpu->regs[7] >> 18));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 63ULL));
    cpu->regs[7] = ((uint32_t)(cpu->regs[7] | 4294967280ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4294967168ULL));
    cpu->regs[6] = cpu->regs[6] + 4ULL;
    PB_STRB((cpu->regs[6] + -4), cpu->regs[7]);
    PB_STRB((cpu->regs[6] + -3), cpu->regs[0]);
    PB_STRB((cpu->regs[6] + -2), cpu->regs[2]);
    PB_STRB((cpu->regs[6] + -1), cpu->regs[1]);
    goto L_1c7048;
L_1c7210:
    cpu->regs[30] = PB_BASE + 0x1c7214ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 4294967294ULL;
    goto L_1c7090;
    /* nop */
    cpu->regs[0] = 0ULL;
    return;
}
