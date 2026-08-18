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

void ft_PyUnicode_DecodeUTF8Stateful(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xdea80ULL); return; };
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_197294;
L_19728c:
    PB_STR((cpu->regs[0] + 0), cpu->regs[0]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[0]);
    return;
L_197294:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    cpu->regs[5] = cpu->regs[5] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    cpu->regs[3] = cpu->regs[3] & 3ULL;
    PB_STR((cpu->regs[5] + 0), cpu->regs[2]);
    cpu->regs[3] = cpu->regs[3] | cpu->regs[5];
    PB_STR((cpu->regs[2] + 8), cpu->regs[3]);
    cpu->regs[3] = cpu->regs[4] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_STR((cpu->regs[3] + 0), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[2] = cpu->regs[2] | cpu->regs[3];
    PB_STR((cpu->regs[1] + 8), cpu->regs[2]);
    goto L_19728c;
    SP = SP - 224ULL;
    PB_STR((SP + 128), cpu->regs[29]); PB_STR((SP + 128) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 128ULL;
    PB_STR((SP + 144), cpu->regs[19]); PB_STR((SP + 144) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 160), cpu->regs[21]); PB_STR((SP + 160) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 176), cpu->regs[23]); PB_STR((SP + 176) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[4];
    PB_STR((SP + 192), cpu->regs[25]); PB_STR((SP + 192) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[5];
    PB_STR((SP + 208), cpu->regs[27]); PB_STR((SP + 208) + 8, cpu->regs[28]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[26], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[7], (cpu->regs[1] + 0));
    PB_STR((SP + 120), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    PB_STRW((SP + 8), cpu->regs[2]); PB_STRW((SP + 8) + 4, cpu->regs[3]);
    FLAG_CMP(cpu->regs[26], 0ULL);
    if (FLAG_LE) goto L_1973e4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2392));
    cpu->regs[28] = cpu->regs[20] + 16ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[27] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[5] = 0ULL;
L_197344:
    PB_LDR(cpu->regs[2], (cpu->regs[28] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(19ULL)));
    if (FLAG_EQ) goto L_197500;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_19775c;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_197434;
    cpu->regs[4] = 1ULL;
L_197370:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_197374:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[26], cpu->regs[1]);
    if (FLAG_NE) goto L_197344;
    cpu->regs[4] = ((uint32_t)(cpu->regs[5] | cpu->regs[4]));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_19743c;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_1977bc;
    cpu->regs[27] = cpu->regs[5];
L_197390:
    FLAG_CMP(cpu->regs[26], 1ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[27] ^ 1ULL));
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[1]))), 0);
    if (FLAG_EQ) goto L_1973e8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
L_1973a8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 120));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_197758;
    PB_LDR(cpu->regs[29], (SP + 128)); PB_LDR(cpu->regs[30], (SP + 128) + 8);
    PB_LDR(cpu->regs[19], (SP + 144)); PB_LDR(cpu->regs[20], (SP + 144) + 8);
    PB_LDR(cpu->regs[21], (SP + 160)); PB_LDR(cpu->regs[22], (SP + 160) + 8);
    PB_LDR(cpu->regs[23], (SP + 176)); PB_LDR(cpu->regs[24], (SP + 176) + 8);
    PB_LDR(cpu->regs[25], (SP + 192)); PB_LDR(cpu->regs[26], (SP + 192) + 8);
    PB_LDR(cpu->regs[27], (SP + 208)); PB_LDR(cpu->regs[28], (SP + 208) + 8);
    SP = SP + 224ULL;
    return;
L_1973e4:
    cpu->regs[27] = 0ULL;
L_1973e8:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1973f4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197770;
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
L_197408:
    FLAG_CMP(cpu->regs[4], cpu->regs[26]);
    if (FLAG_GE) goto L_197524;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + (cpu->regs[4] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(19ULL)));
    if (FLAG_EQ) goto L_1974c8;
    cpu->regs[0] = cpu->regs[5] + 2ULL;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    PB_STR((cpu->regs[22] + (cpu->regs[0] << 3)), cpu->regs[1]);
    goto L_197408;
L_197434:
    cpu->regs[27] = 1ULL;
    goto L_197370;
L_19743c:
    PB_STR((SP + 16), cpu->regs[6]);
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_197390;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x197450ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1a4b90ULL);
    PB_STR((SP + 64), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = SP + 64ULL;
    PB_LDR(cpu->regs[6], (SP + 16));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    PB_STR((SP + 40), cpu->regs[0]);
L_19746c:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + (cpu->regs[20] << 3)));
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_STR((SP + 16), cpu->regs[6]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0x197484ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1a4cc0ULL);
    PB_LDR(cpu->regs[6], (SP + 16));
    FLAG_CMP(cpu->regs[26], cpu->regs[20]);
    if (FLAG_NE) goto L_19746c;
    PB_LDR(cpu->regs[1], (SP + 64));
    if ((cpu->regs[1])==0) goto L_197788;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1974a0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xf7220ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 64));
    if (((cpu->regs[1] >> 31) & 1)) goto L_197788;
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 32));
    cpu->regs[5] = cpu->regs[25];
    PB_LDRW(cpu->regs[2], (SP + 8)); PB_LDRW(cpu->regs[3], (SP + 8) + 4);
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1974c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x10c468ULL);
    goto L_1973a8;
L_1974c8:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[22] + (cpu->regs[5] << 3);
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[3] = cpu->regs[0] + 16ULL;
L_1974dc:
    if ((cpu->regs[0])==0) goto L_197778;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
L_1974e4:
    FLAG_CMP(cpu->regs[6], cpu->regs[1]);
    if (FLAG_GE) goto L_197518;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + (cpu->regs[6] << 3)));
    if ((cpu->regs[1])==0) goto L_197770;
    PB_STR((cpu->regs[2] + (cpu->regs[6] << 3)), cpu->regs[1]);
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    goto L_1974dc;
L_197500:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    if ((cpu->regs[2])==0) goto L_197780;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
L_19750c:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[5] = 1ULL;
    goto L_197374;
L_197518:
    cpu->regs[5] = cpu->regs[5] + cpu->regs[6];
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_197408;
L_197524:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_1976e4;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_197720;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2520));
    cpu->regs[23] = cpu->regs[22] + 16ULL;
    cpu->regs[6] = 0ULL;
L_197548:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + (cpu->regs[6] << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_197574;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_NE) goto L_197570;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    if ((cpu->regs[2])==0) goto L_197580;
L_197570:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_197578;
L_197574:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_197578:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    cpu->regs[3] = (FLAG_EQ) ? 1 : 0;
L_197580:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[6]);
    if (FLAG_NE) goto L_197548;
L_19758c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[30] = PB_BASE + 0x197594ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197770;
    cpu->regs[12] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[12], (cpu->regs[12] + 2520));
    cpu->regs[9] = 0ULL;
    cpu->regs[20] = 0ULL;
L_1975ac:
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_LE) goto L_1976f8;
    cpu->regs[1] = cpu->regs[22] + (cpu->regs[20] << 3);
    cpu->regs[2] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[1] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_197600;
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_LE) goto L_1975e4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_197614;
L_1975e4:
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_197600;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[12]);
    if (FLAG_NE) goto L_197600;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_19760c;
L_197600:
    cpu->regs[1] = cpu->regs[9] + 2ULL;
    cpu->regs[9] = cpu->regs[9] + 1ULL;
    PB_STR((cpu->regs[28] + (cpu->regs[1] << 3)), cpu->regs[26]);
L_19760c:
    cpu->regs[20] = cpu->regs[2];
    goto L_1975ac;
L_197614:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 16));
    cpu->regs[0] = SP + 64ULL;
    PB_STR((SP + 16), cpu->regs[9]); PB_STR((SP + 16) + 8, cpu->regs[12]);
    PB_STR((SP + 40), cpu->regs[0]); PB_STR((SP + 40) + 8, cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x197628ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11cb84ULL);
    cpu->regs[4] = cpu->regs[26];
    PB_LDR(cpu->regs[9], (SP + 16)); PB_LDR(cpu->regs[12], (SP + 16) + 8);
    goto L_197660;
L_197634:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 8));
    PB_STR((SP + 16), cpu->regs[4]); PB_STR((SP + 16) + 8, cpu->regs[9]);
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_STR((SP + 32), cpu->regs[12]);
    cpu->regs[30] = PB_BASE + 0x197648ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x120700ULL);
    PB_LDR(cpu->regs[12], (SP + 32));
    PB_LDR(cpu->regs[4], (SP + 16)); PB_LDR(cpu->regs[9], (SP + 16) + 8);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_197768;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_EQ) goto L_197678;
L_197660:
    cpu->regs[1] = cpu->regs[4];
    PB_LDR(cpu->regs[4], (cpu->regs[23] + (cpu->regs[20] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_197634;
    cpu->regs[4] = cpu->regs[1];
L_197678:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    PB_STR((SP + 24), cpu->regs[4]); PB_STR((SP + 24) + 8, cpu->regs[9]);
    PB_STR((SP + 56), cpu->regs[12]);
    cpu->regs[30] = PB_BASE + 0x19768cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11ce48ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197768;
    cpu->regs[1] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[30] = PB_BASE + 0x1976a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf7220ULL);
    PB_LDR(cpu->regs[9], (SP + 32));
    PB_LDR(cpu->regs[12], (SP + 56));
    PB_LDR(cpu->regs[2], (SP + 16)); PB_LDR(cpu->regs[4], (SP + 16) + 8);
    if (((cpu->regs[0] >> 31) & 1)) goto L_197798;
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 32));
    PB_STR((SP + 16), cpu->regs[9]); PB_STR((SP + 16) + 8, cpu->regs[12]);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (SP + 48));
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + 32)); PB_LDRW(cpu->regs[3], (cpu->regs[26] + 32) + 4);
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 40)); PB_LDRW(cpu->regs[5], (cpu->regs[4] + 40) + 4);
    cpu->regs[30] = PB_BASE + 0x1976d0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197770;
    PB_LDR(cpu->regs[9], (SP + 16)); PB_LDR(cpu->regs[12], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[20] + 1ULL;
    goto L_1975e4;
L_1976e4:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1976f0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197770;
L_1976f8:
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_197718;
    PB_LDR(cpu->regs[5], (cpu->regs[21] + 32));
    cpu->regs[4] = cpu->regs[25];
    PB_LDRW(cpu->regs[1], (SP + 8)); PB_LDRW(cpu->regs[2], (SP + 8) + 4);
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x197714ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1a1320ULL);
    goto L_1973a8;
L_197718:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 16));
    goto L_1973a8;
L_197720:
    cpu->regs[23] = cpu->regs[22] + 16ULL;
    cpu->regs[1] = 0ULL;
L_197728:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_19773c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_197740;
L_19773c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_197740:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(20ULL)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[3] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_NE) goto L_197728;
    goto L_19758c;
L_197758:
    cpu->regs[30] = PB_BASE + 0x19775cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_19775c:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[5] = 1ULL;
    goto L_197374;
L_197768:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x197770ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bef0ULL);
L_197770:
    cpu->regs[0] = 0ULL;
    goto L_1973a8;
L_197778:
    cpu->regs[1] = 0ULL;
    goto L_1974e4;
L_197780:
    cpu->regs[2] = 0ULL;
    goto L_19750c;
L_197788:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x197790ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = 0ULL;
    goto L_1973a8;
L_197798:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197770;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_197770;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1977b4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1973a8;
L_1977bc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[3] + 3400ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1977dcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[0] = 0ULL;
    goto L_1973a8;
}
