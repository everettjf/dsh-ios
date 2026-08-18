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

void ft__PyUnicode_FormatAdvancedWriter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 112ULL;
    cpu->regs[5] = cpu->regs[3];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_NE) goto L_1fc464;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_1fc4e4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[4], (SP + 56));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_1fc4dc;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 112ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x120700ULL); return; };
L_1fc464:
    cpu->regs[6] = cpu->regs[2];
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = SP;
    cpu->regs[6] = 60ULL;
    cpu->regs[5] = 115ULL;
    PB_STR((SP + 96), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1fc48cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x167360ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fc528;
    PB_LDRW(cpu->regs[0], (SP + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(115ULL)));
    if (FLAG_NE) goto L_1fc51c;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fc4acULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x25d540ULL);
L_1fc4ac:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1fc518;
    PB_LDR(cpu->regs[21], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_1fc4dc:
    PB_STR((SP + 96), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1fc4e4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fc4e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1fc4dc;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 112ULL;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x244104ULL); return; };
L_1fc518:
    cpu->regs[30] = PB_BASE + 0x1fc51cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fc51c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[30] = PB_BASE + 0x1fc528ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x2551c0ULL);
L_1fc528:
    cpu->regs[0] = 4294967295ULL;
    goto L_1fc4ac;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    SP = SP - 1200ULL;
    PB_STR((SP + 1024), 0ULL);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 1192), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[22] = cpu->regs[2];
    FLAG_CMP(cpu->regs[21], cpu->regs[3]);
    if (FLAG_EQ) goto L_1fc878;
    cpu->regs[20] = SP + 88ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fc590ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1fc7fc;
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDR(cpu->regs[19], (SP + 88));
    FLAG_CMP(cpu->regs[0], 256ULL);
    if (FLAG_NE) goto L_1fc884;
L_1fc5a4:
    if ((cpu->regs[22])!=0) goto L_1fc7e4;
    PB_STR((SP + 8), 0ULL);
    PB_STR((SP + 24), 0ULL);
L_1fc5b0:
    PB_LDR(cpu->regs[20], (cpu->regs[24] + 16));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fc5c0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1fc8e0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fc860;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1fc8ac;
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 40));
L_1fc5d4:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    if ((cpu->regs[0])==0) goto L_1fc8b8;
    PB_LDR(cpu->regs[5], (cpu->regs[24] + 40));
L_1fc5e0:
    cpu->regs[0] = cpu->regs[20] - 1ULL;
    PB_LDR(cpu->regs[3], (SP + 24));
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[19], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1fc78c;
    if (((cpu->regs[0] >> 63) & 1)) goto L_1fc724;
    cpu->regs[1] = cpu->regs[20] & 7ULL; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[0] = 0ULL;
    if (FLAG_EQ) goto L_1fc69c;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_1fc684;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_1fc674;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_1fc664;
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_EQ) goto L_1fc654;
    FLAG_CMP(cpu->regs[1], 5ULL);
    if (FLAG_EQ) goto L_1fc644;
    FLAG_CMP(cpu->regs[1], 6ULL);
    if (FLAG_NE) goto L_1fc76c;
L_1fc634:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1fc644:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1fc654:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1fc664:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1fc674:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1fc684:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_EQ) goto L_1fc724;
L_1fc69c:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    cpu->regs[3] = cpu->regs[0] + 1ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[3]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[3]), cpu->regs[2]);
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3] + 2ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3] + 3ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3] + 4ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3] + 5ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3] + 6ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + cpu->regs[0]));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3] + 7ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_NE) goto L_1fc69c;
L_1fc724:
    if ((cpu->regs[21])==0) goto L_1fc730;
    cpu->regs[0] = SP + 88ULL;
    cpu->regs[30] = PB_BASE + 0x1fc730ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11ec60ULL);
L_1fc730:
    if ((cpu->regs[22])!=0) goto L_1fc780;
L_1fc734:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 1192));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1fc804;
    SP = SP + 1200ULL;
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1fc76c:
    PB_LDRB(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[0] = 1ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[4] + 0), cpu->regs[2]);
    goto L_1fc634;
L_1fc780:
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x1fc788ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_1fc734;
L_1fc78c:
    cpu->regs[2] = SP + 168ULL;
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[19])==0) goto L_1fc7d0;
L_1fc798:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[0]));
    PB_STRW((cpu->regs[2] + (cpu->regs[0] << 2)), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], 256ULL);
    if (FLAG_NE) goto L_1fc798;
L_1fc7ac:
    PB_LDR(cpu->regs[6], (SP + 8));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = 4294967295ULL;
L_1fc7b8:
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_1fc808;
    PB_LDRB(cpu->regs[7], (cpu->regs[6] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STRW((cpu->regs[2] + (cpu->regs[7] << 2)), cpu->regs[1]);
    goto L_1fc7b8;
L_1fc7d0:
    PB_STRW((cpu->regs[2] + (cpu->regs[0] << 2)), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], 256ULL);
    if (FLAG_NE) goto L_1fc7d0;
    goto L_1fc7ac;
L_1fc7e4:
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fc7f4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fc5b0;
    if ((cpu->regs[21])!=0) goto L_1fc868;
L_1fc7fc:
    cpu->regs[23] = 0ULL;
    goto L_1fc734;
L_1fc804:
    cpu->regs[30] = PB_BASE + 0x1fc808ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1fc808:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[4];
L_1fc810:
    cpu->regs[0] = cpu->regs[0] - 1ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_LT) goto L_1fc830;
    PB_LDRB(cpu->regs[3], cpu->regs[5]); cpu->regs[5] += 1;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + (cpu->regs[3] << 2)));
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fc810;
    PB_STRB(cpu->regs[1], cpu->regs[3]); cpu->regs[1] += 1;
    goto L_1fc810;
L_1fc830:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_1fc724;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[4];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1fc844ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1e6c20ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1fc724;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fc860;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fc8c4;
L_1fc860:
    cpu->regs[23] = 0ULL;
    goto L_1fc724;
L_1fc868:
    cpu->regs[0] = SP + 88ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fc874ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_1fc734;
L_1fc878:
    cpu->regs[19] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_1fc5a4;
L_1fc884:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 2400ULL;
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fc8a0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1fc8a8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_1fc734;
L_1fc8ac:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3336));
    goto L_1fc5d4;
L_1fc8b8:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3336));
    goto L_1fc5e0;
L_1fc8c4:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fc8d0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fc724;
    /* nop */
    /* nop */
    /* nop */
}
