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

void ft_PyUnicode_AsRawUnicodeEscapeString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_24aa60;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_24aa58;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[19] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[1];
L_24a830:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_24a874;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24aa08;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xe9c70ULL); return; };
L_24a874:
    cpu->regs[1] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[1] = ((cpu->regs[1] & 0xfULL) << 1);
    cpu->regs[0] = (cpu->regs[1] ? cpu->regs[0] / cpu->regs[1] : 0);
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LT) goto L_24aa28;
    cpu->regs[1] = cpu->regs[20] * cpu->regs[1];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24a898ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24aa18;
    if ((cpu->regs[20])==0) goto L_24aa0c;
    cpu->regs[8] = cpu->regs[0] + 32ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2576));
    cpu->regs[3] = cpu->regs[8];
    cpu->regs[9] = 65535ULL;
    cpu->regs[10] = 30044ULL;
L_24a8c0:
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_24a948;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24a8d4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_24a8f0;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[3] = cpu->regs[1];
    goto L_24a8c0;
L_24a8f0:
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] >> 12));
    cpu->regs[7] = ((cpu->regs[0] >> 8) & 0xfULL);
    cpu->regs[6] = ((cpu->regs[0] >> 4) & 0xfULL);
    cpu->regs[5] = cpu->regs[0] & 15ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[9])));
    if (FLAG_HI) goto L_24a990;
    PB_STRH((cpu->regs[3] + 0), cpu->regs[10]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[3] = cpu->regs[3] + 6ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
    PB_STRB((cpu->regs[3] + -4), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[7]));
    PB_STRB((cpu->regs[3] + -3), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[6]));
    PB_STRB((cpu->regs[3] + -2), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[5]));
    PB_STRB((cpu->regs[3] + -1), cpu->regs[0]);
    goto L_24a8c0;
L_24a948:
    cpu->regs[1] = cpu->regs[3] - cpu->regs[8];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x24a954ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x13e868ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24aa18;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[21], (SP + 48));
L_24a968:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_24aa00;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 64ULL;
    return;
L_24a990:
    cpu->regs[11] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[11], (cpu->regs[11] + 2576));
    cpu->regs[12] = 21852ULL;
    cpu->regs[12] = (cpu->regs[12] & ~(0xffffULL << 16)) | ((0x3030ULL & 0xffff) << 16);
    PB_STRW((cpu->regs[3] + 0), cpu->regs[12]);
    cpu->regs[12] = ((cpu->regs[0] >> 20) & 0xfULL);
    cpu->regs[0] = ((cpu->regs[0] >> 16) & 0xfULL);
    PB_LDR(cpu->regs[13], (cpu->regs[11] + 0));
    cpu->regs[1] = cpu->regs[1] & 15ULL;
    cpu->regs[3] = cpu->regs[3] + 10ULL;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_LDRB(cpu->regs[12], (cpu->regs[13] + cpu->regs[12]));
    PB_STRB((cpu->regs[3] + -6), cpu->regs[12]);
    PB_LDR(cpu->regs[12], (cpu->regs[11] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[12] + cpu->regs[0]));
    PB_STRB((cpu->regs[3] + -5), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[11] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
    PB_STRB((cpu->regs[3] + -4), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[11] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[7]));
    PB_STRB((cpu->regs[3] + -3), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[11] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + cpu->regs[6]));
    PB_STRB((cpu->regs[3] + -2), cpu->regs[1]);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[5]));
    PB_STRB((cpu->regs[3] + -1), cpu->regs[0]);
    goto L_24a8c0;
L_24aa00:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]);
L_24aa08:
    cpu->regs[30] = PB_BASE + 0x24aa0cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24aa0c:
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_24a968;
L_24aa18:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_24a968;
L_24aa28:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24aa08;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_24aa58:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 56));
    goto L_24a830;
L_24aa60:
    cpu->regs[30] = PB_BASE + 0x24aa64ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 0ULL;
    goto L_24a968;
}
