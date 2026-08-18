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

void ft__PyBytes_DecodeEscape2(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = 1ULL;
    cpu->regs[22] = cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    SP = SP - 576ULL;
    cpu->regs[27] = SP + 16ULL;
    cpu->regs[28] = cpu->regs[3];
    cpu->regs[3] = 512ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 0));
    PB_STR((SP + 568), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[27];
    PB_STRW((SP + 48), cpu->regs[24]);
    cpu->regs[1] = SP + 52ULL;
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[21];
    PB_STR((cpu->regs[27] + 16), 0ULL); PB_STR((cpu->regs[27] + 16) + 8, 0ULL);
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1a4310ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11db70ULL);
    if ((cpu->regs[0])==0) goto L_1a464c;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 3352));
    PB_STR((SP + 592), cpu->regs[19]);
    PB_STR((SP + 600), cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x2b4000ULL;
    cpu->regs[0] = 4294967295ULL;
    cpu->regs[21] = cpu->regs[25] + cpu->regs[21];
    cpu->regs[3] = cpu->regs[3] + 3332ULL;
    cpu->regs[20] = cpu->regs[25];
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[22] + 0), 0ULL);
    PB_STRW((SP + 44), cpu->regs[24]);
L_1a4348:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_HS) goto L_1a4418;
    cpu->regs[5] = cpu->regs[20];
    PB_LDRB(cpu->regs[6], cpu->regs[5]); cpu->regs[5] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_1a4378;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[24] = cpu->regs[5];
    PB_STRB(cpu->regs[1], cpu->regs[6]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
L_1a4370:
    cpu->regs[20] = cpu->regs[24];
    goto L_1a4348;
L_1a4378:
    FLAG_CMP(cpu->regs[5], cpu->regs[21]);
    if (FLAG_EQ) goto L_1a46c4;
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + 1));
    cpu->regs[24] = cpu->regs[20] + 2ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - 10ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(110ULL)));
    if (FLAG_LS) goto L_1a43c4;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a43a8;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[22] + 0), cpu->regs[5]);
L_1a43a8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 92ULL;
    cpu->regs[24] = cpu->regs[5];
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
L_1a43c4:
    PB_LDRH(cpu->regs[1], (cpu->regs[3] + (((uint64_t)(uint32_t)(cpu->regs[1])) << 1)));
    cpu->regs[0] = PB_BASE + 0x1a43d4ULL;
    cpu->regs[1] = cpu->regs[0] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[1])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[1]); return;
    cpu->regs[26] = cpu->regs[20] + 3ULL;
    FLAG_CMP(cpu->regs[26], cpu->regs[21]);
    if (FLAG_HS) goto L_1a45a8;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 3));
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 2));
    PB_LDRB(cpu->regs[2], (cpu->regs[23] + cpu->regs[0]));
    PB_LDRB(cpu->regs[5], (cpu->regs[23] + cpu->regs[1]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[5] | cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_HI) goto L_1a45a8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[5] = ((uint32_t)(cpu->regs[2] + (cpu->regs[5] << 4)));
    cpu->regs[24] = cpu->regs[20] + 4ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[5]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
L_1a4418:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1a4424ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11dec4ULL);
    PB_LDR(cpu->regs[19], (SP + 592));
    PB_LDR(cpu->regs[20], (SP + 600));
L_1a442c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 568));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1a4668;
    SP = SP + 576ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 48ULL));
    FLAG_CMP(cpu->regs[21], cpu->regs[24]);
    if (FLAG_LS) goto L_1a44bc;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(47ULL)));
    if (FLAG_LS) goto L_1a44bc;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(55ULL)));
    if (FLAG_HI) goto L_1a44bc;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 48ULL));
    cpu->regs[24] = cpu->regs[20] + 3ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + (cpu->regs[2] << 3)));
    FLAG_CMP(cpu->regs[21], cpu->regs[24]);
    if (FLAG_LS) goto L_1a44bc;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 3));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 48ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_1a44bc;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + (cpu->regs[2] << 3)));
    cpu->regs[24] = cpu->regs[20] + 4ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(255ULL)));
    if (FLAG_GT) goto L_1a4590;
L_1a44bc:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 13ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 9ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 92ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 34ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 39ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 11ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 12ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
L_1a4590:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a44bc;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[22] + 0), cpu->regs[5]);
    goto L_1a44bc;
L_1a45a8:
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])==0) goto L_1a4620;
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[1] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x1a45bcULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a4620;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x1a45d0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7ae60ULL);
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[3] = cpu->regs[1] + 3332ULL;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a4654;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 3288ULL;
    cpu->regs[30] = PB_BASE + 0x1a45ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7ae60ULL);
    cpu->regs[1] = PB_BASE + 0x2b4000ULL;
    cpu->regs[3] = cpu->regs[1] + 3332ULL;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a4674;
L_1a45f8:
    FLAG_CMP(cpu->regs[21], cpu->regs[24]);
    if (FLAG_LS) goto L_1a4370;
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 2));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 2)));
    FLAG_CMP((cpu->regs[0]) & (16ULL), 0);
    cpu->regs[24] = (FLAG_EQ) ? cpu->regs[24] : cpu->regs[26];
    cpu->regs[20] = cpu->regs[24];
    goto L_1a4348;
L_1a4620:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[20] - cpu->regs[25];
    cpu->regs[1] = cpu->regs[1] + 3088ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a463cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1a463c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1a4644ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
    PB_LDR(cpu->regs[19], (SP + 592));
    PB_LDR(cpu->regs[20], (SP + 600));
L_1a464c:
    cpu->regs[0] = 0ULL;
    goto L_1a442c;
L_1a4654:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 63ULL;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a45f8;
L_1a4668:
    PB_STR((SP + 592), cpu->regs[19]);
    PB_STR((SP + 600), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1a4674ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1a4674:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[1] + 3128ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a4690ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1a463c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 7ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 8ULL;
    cpu->regs[20] = cpu->regs[24];
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    cpu->regs[19] = cpu->regs[1];
    goto L_1a4348;
L_1a46c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3064ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a46dcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1a463c;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_1a4768;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_1a479c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 80ULL;
    PB_LDR(cpu->regs[0], (SP + 88));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[5];
    cpu->regs[21] = cpu->regs[7];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[4];
    cpu->regs[23] = cpu->regs[6];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[2];
    cpu->regs[26] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1a472cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a4788;
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[20]);
    cpu->regs[1] = 10ULL;
    PB_STR((cpu->regs[0] + 24), cpu->regs[25]); PB_STR((cpu->regs[0] + 24) + 8, cpu->regs[26]);
    PB_STRW((cpu->regs[0] + 64), cpu->regs[22]); PB_STRW((cpu->regs[0] + 64) + 4, cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (SP + 80));
    PB_STR((cpu->regs[0] + 40), cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 72), cpu->regs[21]); PB_STRW((cpu->regs[0] + 72) + 4, cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_1a4760:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1a4768:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a4780ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a4760;
L_1a4788:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1a4760;
L_1a479c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3224ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a47b4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1a4760;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a4828;
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[0] = cpu->regs[6];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[1] = 80ULL;
    cpu->regs[30] = PB_BASE + 0x1a47fcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a4848;
    cpu->regs[1] = 20ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 64), cpu->regs[22]); PB_STRW((cpu->regs[0] + 64) + 4, cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 72), cpu->regs[20]); PB_STRW((cpu->regs[0] + 72) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a481c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a4828:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3360ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a4840ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a481c;
L_1a4848:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1a481c;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1a4890ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_1a4a08;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[21] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1a48c0;
L_1a48a4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a48acULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe8060ULL);
    if ((cpu->regs[0])==0) goto L_1a4960;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[20] += -8; PB_STR(cpu->regs[20], cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_NE) goto L_1a48a4;
L_1a48c0:
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1a4938;
    cpu->regs[30] = PB_BASE + 0x1a48d0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x14d3acULL);
    if ((cpu->regs[0])==0) goto L_1a4994;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    PB_STR((cpu->regs[20] + -8), cpu->regs[0]);
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[4], cpu->regs[22]);
    if (FLAG_LT) goto L_1a4ac0;
    cpu->regs[1] = cpu->regs[20];
L_1a48ec:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1a49e4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[2];
    PB_STR((cpu->regs[0] + 16), cpu->regs[4]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1a4920;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1a4920;
L_1a4910:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1a4920ULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
L_1a4920:
    cpu->regs[0] = 1ULL;
L_1a4924:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a4938:
    cpu->regs[30] = PB_BASE + 0x1a493cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe8060ULL);
    if ((cpu->regs[0])!=0) goto L_1a4a58;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 96));
    if ((cpu->regs[0])!=0) goto L_1a4af0;
L_1a4948:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a4920;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1a4910;
    goto L_1a4920;
L_1a4960:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 96));
    if ((cpu->regs[0])!=0) goto L_1a4b18;
L_1a4968:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a4afc;
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[2] + 3448ULL;
    cpu->regs[30] = PB_BASE + 0x1a4994ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x225d40ULL);
L_1a4994:
    cpu->regs[22] = 0ULL;
L_1a4998:
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] - cpu->regs[22]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1a49d0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a49c8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1a49c8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1a49c8ULL; PB_CALL(22, cpu, tlb, cpu->regs[1]);
L_1a49c8:
    cpu->regs[0] = 0ULL;
    goto L_1a4924;
L_1a49d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[22] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1a4a84;
L_1a49dc:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_1a4998;
L_1a49e4:
    cpu->regs[3] = cpu->regs[4] - cpu->regs[2];
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] - 1ULL));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[20] + (cpu->regs[3] << 3);
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] - 8ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + cpu->regs[3]));
    PB_STR((cpu->regs[1] + -8), cpu->regs[3]);
    goto L_1a48ec;
L_1a4a08:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2736));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x1a4a1cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a49c8;
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 216));
    if ((cpu->regs[0])!=0) goto L_1a49c8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a4a34ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a49c8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[2] + 3400ULL;
    cpu->regs[30] = PB_BASE + 0x1a4a50ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x225d40ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a4924;
L_1a4a58:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1a4aa4;
L_1a4a60:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[2] + 3568ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1a4a80ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_1a4994;
L_1a4a84:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1a49dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1a4aa0ULL; PB_CALL(27, cpu, tlb, cpu->regs[1]);
    goto L_1a4998;
L_1a4aa4:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1a4a60;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1a4abcULL; PB_CALL(28, cpu, tlb, cpu->regs[1]);
    goto L_1a4a60;
L_1a4ac0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[20] = cpu->regs[20] - 8ULL;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[4] = cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[23] + cpu->regs[22]));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[2] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0x1a4aecULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_1a4994;
L_1a4af0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_1a4994;
    goto L_1a4948;
L_1a4afc:
    cpu->regs[3] = ((uint32_t)(cpu->regs[23] + cpu->regs[22]));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[2] + 3504ULL;
    cpu->regs[30] = PB_BASE + 0x1a4b14ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_1a4994;
L_1a4b18:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_1a4994;
    goto L_1a4968;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1a4b6c;
L_1a4b3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x1a4b44ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11e0a4ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1a4b88;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_1a4b60:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a4b6c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3672ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1a4b84ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a4b3c;
L_1a4b88:
    cpu->regs[0] = 0ULL;
    goto L_1a4b60;
}
