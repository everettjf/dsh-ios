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

void ft__Py_read(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = (FLAG_LS) ? cpu->regs[2] : cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[25]);
L_1cd018:
    cpu->regs[30] = PB_BASE + 0x1cd01cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1cd024ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1cd03cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b9a0ULL);
    PB_LDRW(cpu->regs[25], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1cd04cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LT) { FLAG_CMP(cpu->regs[25], 4ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_1cd078;
    if (((cpu->regs[19] >> 63) & 1)) goto L_1cd088;
L_1cd05c:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1cd078:
    cpu->regs[30] = PB_BASE + 0x1cd07cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1cd018;
    cpu->regs[25] = 4ULL;
    goto L_1cd098;
L_1cd088:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cd098ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_1cd098:
    cpu->regs[19] = 18446744073709551615ULL;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[25]);
    goto L_1cd05c;
    SP = SP - 32ULL;
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 39328ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1cd0ecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1cd114;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_1cd114:
    cpu->regs[30] = PB_BASE + 0x1cd118ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1cd2bc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cd160ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x17f520ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1cd304;
L_1cd164:
    cpu->regs[30] = PB_BASE + 0x1cd168ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7750ULL);
    PB_STR((cpu->regs[19] + 112), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd174ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1cd3c0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1cd2e4;
    if (FLAG_NE) goto L_1cd26c;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cd28c;
L_1cd18c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    PB_STR((cpu->regs[19] + 112), 0ULL);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[22] = SP;
    cpu->regs[30] = PB_BASE + 0x1cd1a4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[4] = 44840ULL;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[30] = PB_BASE + 0x1cd1c0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    cpu->regs[30] = PB_BASE + 0x1cd1d0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x17f520ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1cd2ec;
L_1cd1d4:
    cpu->regs[30] = PB_BASE + 0x1cd1d8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd7750ULL);
    PB_STR((cpu->regs[19] + 112), cpu->regs[0]);
    if ((cpu->regs[20])==0) goto L_1cd384;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1cd318;
L_1cd1e8:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = 39328ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1cd208ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_1cd224;
L_1cd218:
    cpu->regs[30] = PB_BASE + 0x1cd21cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[19] + 56), 0ULL);
L_1cd220:
    if ((cpu->regs[22])!=0) goto L_1cd34c;
L_1cd224:
    PB_STR((cpu->regs[19] + 64), 0ULL);
    PB_STR((cpu->regs[19] + 80), 0ULL);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
L_1cd230:
    PB_STR((cpu->regs[19] + 112), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    cpu->regs[30] = PB_BASE + 0x1cd23cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_1cd23c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1cd2b4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1cd26c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1cd330;
L_1cd280:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
    goto L_1cd230;
L_1cd28c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd298ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1eb560ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1cd18c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1cd18c;
    cpu->regs[30] = PB_BASE + 0x1cd2b0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cd18c;
L_1cd2b4:
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1cd2bcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1cd2bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 28));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1cd338;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1cd2e0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cd23c;
L_1cd2e4:
    cpu->regs[20] = 0ULL;
    goto L_1cd230;
L_1cd2ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd2f4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xabc58ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cd1d4;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    goto L_1cd23c;
L_1cd304:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd30cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xabc58ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cd164;
    cpu->regs[20] = 0ULL;
    goto L_1cd23c;
L_1cd318:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1cd1e8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1cd32cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cd1e8;
L_1cd330:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1cd280;
L_1cd338:
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x1cd348ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cd23c;
L_1cd34c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1cd354ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    if ((cpu->regs[20])==0) goto L_1cd360;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1cd368;
L_1cd360:
    cpu->regs[20] = 0ULL;
    goto L_1cd224;
L_1cd368:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1cd360;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cd380ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cd224;
L_1cd384:
    cpu->regs[30] = PB_BASE + 0x1cd388ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 16));
    cpu->regs[2] = 39328ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1cd3acULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])!=0) goto L_1cd218;
    goto L_1cd220;
    /* nop */
L_1cd3c0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1cd418;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = 39376ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1cd3f0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cd438;
    cpu->regs[30] = PB_BASE + 0x1cd3fcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1cd440;
L_1cd408:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1cd418:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 28));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1cd458;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1cd438ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1cd438:
    cpu->regs[20] = 4294967295ULL;
    goto L_1cd408;
L_1cd440:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1cd408;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd454ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cd408;
L_1cd458:
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[20] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x1cd468ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cd408;
    SP = SP - 32ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1cd4ec;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = 44840ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1cd4c0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x147564ULL);
L_1cd4c0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1cd4e8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_1cd4e8:
    cpu->regs[30] = PB_BASE + 0x1cd4ecULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1cd4ec:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 28));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1cd514;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1cd50cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1cd4c0;
L_1cd514:
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x1cd520ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1cd4c0;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1cd534ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1cd580ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cd548;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1cd540:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1cd548:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1cd558;
    cpu->regs[0] = 0ULL;
    goto L_1cd540;
L_1cd558:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cd570ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1cd540;
    /* nop */
    /* nop */
L_1cd580:
    SP = SP - 48ULL;
    cpu->regs[4] = 25432ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cd5bcULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x112290ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x1cd5c8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1cd5f8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32));
    SP = SP + 48ULL;
    return;
L_1cd5f8:
    cpu->regs[30] = PB_BASE + 0x1cd5fcULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    SP = SP - 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[5], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])!=0) goto L_1cd6f4;
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[4])!=0) goto L_1cd6ec;
L_1cd630:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 888));
    cpu->regs[3] = 39328ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = 2ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[1] = SP;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 32));
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1cd664ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 20));
    if (!((cpu->regs[1] >> 6) & 1)) goto L_1cd6bc;
    if ((cpu->regs[0])==0) goto L_1cd754;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 21));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cd714;
L_1cd67c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd684ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1cd960ULL);
L_1cd684:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1cd6d0;
L_1cd68c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1cd6c8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1cd6bc:
    cpu->regs[0] = 4294967295ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    goto L_1cd68c;
L_1cd6c8:
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1cd6d0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1cd6d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1cd6e4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1cd784;
L_1cd6e4:
    cpu->regs[20] = 0ULL;
    goto L_1cd68c;
L_1cd6ec:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 16));
    if ((cpu->regs[0])==0) goto L_1cd630;
L_1cd6f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cd710ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cd68c;
L_1cd714:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd720ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1eb620ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1cd67c;
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = 0ULL;
L_1cd730:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1cd740;
    cpu->regs[30] = PB_BASE + 0x1cd740ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1cd740:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd748ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1cd960ULL);
    if ((cpu->regs[20])==0) goto L_1cd770;
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_1cd684;
L_1cd754:
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1cd75cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x121f0cULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 21));
    cpu->regs[21] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1cd794;
L_1cd768:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd770ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1cd960ULL);
L_1cd770:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cd77cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_1cd68c;
L_1cd784:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cd790ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cd68c;
L_1cd794:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd7a0ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x1eb620ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1cd730;
    goto L_1cd768;
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cd7d8ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1cd580ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1cd8a0;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cd850;
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[1] = SP;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = 44840ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    PB_STR((SP + 0), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1cd80cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1cd814ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    cpu->regs[1] = 25432ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1cd830ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe28a0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1cd83cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    if (((cpu->regs[20] >> 31) & 1)) goto L_1cd884;
    if ((cpu->regs[19])==0) goto L_1cd89c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1cd8a8;
L_1cd84c:
    PB_LDR(cpu->regs[21], (SP + 48));
L_1cd850:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1cd858:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1cd8c4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1cd884:
    if ((cpu->regs[19])==0) goto L_1cd89c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1cd89c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1cd8cc;
L_1cd89c:
    PB_LDR(cpu->regs[21], (SP + 48));
L_1cd8a0:
    cpu->regs[0] = 0ULL;
    goto L_1cd858;
L_1cd8a8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1cd84c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd8bcULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 48));
    goto L_1cd850;
L_1cd8c4:
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1cd8ccULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1cd8cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cd8d4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 0ULL;
    goto L_1cd858;
}
