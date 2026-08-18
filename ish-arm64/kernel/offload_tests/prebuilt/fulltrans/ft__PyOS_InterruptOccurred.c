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

void ft__PyOS_InterruptOccurred(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_91680:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])!=0) goto L_916a4;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 896ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x916a4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x91ebcULL);
L_916a4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x916acULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1b03a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_916b8;
L_916b0:
    cpu->regs[0] = 0ULL;
    goto L_916d0;
L_916b8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + 496ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_916b0;
    PB_STRW((cpu->regs[1] + 0), 0ULL);
L_916d0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3256));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x91710ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b050ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 0));
    if ((cpu->regs[19])==0) goto L_9172c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9172cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7bba0ULL);
L_9172c:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 3768));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2248));
    cpu->regs[24] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[21] = 100ULL;
    cpu->regs[27] = 2147483647ULL;
    cpu->regs[30] = PB_BASE + 0x91754ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7b050ULL);
L_91754:
    cpu->regs[1] = cpu->regs[21] + cpu->regs[20];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x91760ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xd77c8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_91788;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x91770ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x91778ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    cpu->regs[30] = PB_BASE + 0x9177cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[30] = PB_BASE + 0x91780ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
L_91780:
    cpu->regs[20] = 0ULL;
    goto L_918c8;
L_91788:
    cpu->regs[28] = cpu->regs[0] + cpu->regs[20];
L_9178c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if ((cpu->regs[0])==0) goto L_917a8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 48));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_917a8;
    cpu->regs[30] = PB_BASE + 0x917a8ULL; PB_CALL(11, cpu, tlb, cpu->regs[0]);
L_917a8:
    cpu->regs[30] = PB_BASE + 0x917acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    PB_STRW((cpu->regs[24] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x917bcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bb90ULL);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x917ccULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7b780ULL);
    if ((cpu->regs[0])!=0) goto L_91824;
    PB_LDRW(cpu->regs[24], (cpu->regs[24] + 0));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x917dcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7bc90ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_917f4;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x917f0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bb90ULL);
    goto L_91898;
L_917f4:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_91814;
    cpu->regs[30] = PB_BASE + 0x91800ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    cpu->regs[30] = PB_BASE + 0x91804ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x12cde0ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9180cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    if (!((cpu->regs[24] >> 31) & 1)) goto L_9178c;
    goto L_9188c;
L_91814:
    cpu->regs[30] = PB_BASE + 0x91818ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x91680ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_9188c;
    goto L_91898;
L_91824:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x9182cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19] + cpu->regs[20];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + -1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_9189c;
    if ((cpu->regs[20])==0) goto L_91880;
    cpu->regs[21] = cpu->regs[20] + 2ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[27]);
    if (FLAG_LS) goto L_91884;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91858ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x91860ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1120ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x91878ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[30] = PB_BASE + 0x9187cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    goto L_91780;
L_91880:
    cpu->regs[21] = 100ULL;
L_91884:
    cpu->regs[24] = cpu->regs[19];
    goto L_91754;
L_9188c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91894ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_91780;
L_91898:
    PB_STRB((cpu->regs[28] + 0), 0ULL);
L_9189c:
    cpu->regs[1] = cpu->regs[20] + 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x918a8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xd77c8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_918c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x918b8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x918c0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    cpu->regs[30] = PB_BASE + 0x918c4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[30] = PB_BASE + 0x918c8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
L_918c8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
}
