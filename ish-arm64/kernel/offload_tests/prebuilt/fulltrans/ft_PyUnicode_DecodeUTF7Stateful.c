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

void ft_PyUnicode_DecodeUTF7Stateful(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 288ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 192), cpu->regs[29]); PB_STR((SP + 192) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 192ULL;
    PB_STR((SP + 72), cpu->regs[0]);
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    PB_STR((SP + 256), cpu->regs[25]); PB_STR((SP + 256) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 184), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 48), cpu->regs[2]);
    PB_STR((SP + 80), 0ULL); PB_STR((SP + 80) + 8, 0ULL);
    PB_STR((SP + 120), cpu->regs[0]);
    if ((cpu->regs[1])==0) goto L_178620;
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    cpu->regs[23] = SP + 128ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[1];
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[23];
    PB_STR((SP + 136), 0ULL);
    PB_STRW((SP + 144), 0ULL); PB_STRW((SP + 144) + 4, 0ULL);
    cpu->regs[2] = cpu->regs[4];
    PB_STR((SP + 160), 0ULL);
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1780bcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11cb84ULL);
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_STR((SP + 40), 0ULL);
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_STR((SP + 96), cpu->regs[4]);
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    PB_STR((SP + 168), cpu->regs[24]);
L_1780d4:
    PB_LDR(cpu->regs[4], (SP + 72));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_HS) goto L_1785bc;
    PB_LDRB(cpu->regs[20], (cpu->regs[4] + 0));
    goto L_178120;
L_1780e8:
    PB_LDR(cpu->regs[0], (SP + 152));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[21];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_178140;
L_1780f8:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1781b4;
    PB_LDR(cpu->regs[2], (SP + 96));
    PB_STRB((cpu->regs[9] + cpu->regs[21]), cpu->regs[20]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_HS) goto L_1781dc;
    PB_LDRB(cpu->regs[20], (cpu->regs[19] + 0));
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[22] = 1ULL;
L_178120:
    cpu->regs[19] = cpu->regs[4] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_17827c;
L_17812c:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_178534;
    PB_STR((SP + 72), cpu->regs[19]);
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_HS) goto L_1780e8;
L_178140:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 1ULL;
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x17815cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11cba0ULL);
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1780f8;
L_178170:
    PB_LDR(cpu->regs[0], (SP + 88));
    PB_STRW((SP + 40), cpu->regs[8]);
    PB_STR((SP + 48), cpu->regs[9]);
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x178184ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[30] = PB_BASE + 0x17818cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 160), cpu->regs[21]);
    PB_LDR(cpu->regs[9], (SP + 48));
    cpu->regs[0] = cpu->regs[23];
    PB_LDRW(cpu->regs[8], (SP + 40));
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x1781a8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7bef0ULL);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
    goto L_178240;
L_1781b4:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_178274;
    PB_STRH((cpu->regs[9] + (cpu->regs[21] << 1)), cpu->regs[20]);
L_1781c0:
    PB_LDR(cpu->regs[2], (SP + 96));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_HS) goto L_1781e0;
    PB_LDRB(cpu->regs[20], (cpu->regs[19] + 0));
L_1781d4:
    cpu->regs[4] = cpu->regs[19];
    goto L_178120;
L_1781dc:
    cpu->regs[22] = 1ULL;
L_1781e0:
    PB_LDR(cpu->regs[24], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    if ((cpu->regs[25])==0) goto L_1781f8;
L_1781e8:
    PB_LDR(cpu->regs[0], (SP + 72));
    PB_LDR(cpu->regs[1], (SP + 120));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
L_1781f8:
    PB_STR((SP + 40), cpu->regs[21]);
L_1781fc:
    cpu->regs[0] = cpu->regs[26];
    PB_STRW((SP + 48), cpu->regs[8]);
    PB_STR((SP + 56), cpu->regs[9]);
    cpu->regs[30] = PB_BASE + 0x17820cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x178214ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[9], (SP + 56));
    PB_STR((SP + 136), cpu->regs[9]);
    PB_LDRW(cpu->regs[8], (SP + 48));
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x178234ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11ce48ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
L_178240:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 184));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_178664;
    PB_LDR(cpu->regs[29], (SP + 192)); PB_LDR(cpu->regs[30], (SP + 192) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 208)); PB_LDR(cpu->regs[20], (SP + 208) + 8);
    PB_LDR(cpu->regs[25], (SP + 256)); PB_LDR(cpu->regs[26], (SP + 256) + 8);
    SP = SP + 288ULL;
    return;
L_178274:
    PB_STRW((cpu->regs[9] + (cpu->regs[21] << 2)), cpu->regs[20]);
    goto L_1781c0;
L_17827c:
    PB_LDR(cpu->regs[2], (SP + 96));
    PB_STR((SP + 40), cpu->regs[21]);
    PB_STR((SP + 272), cpu->regs[27]); PB_STR((SP + 272) + 8, cpu->regs[28]);
    cpu->regs[27] = 1ULL;
    cpu->regs[28] = 4294912000ULL;
L_178290:
    PB_LDR(cpu->regs[1], (SP + 120));
    PB_STR((SP + 72), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[4] - cpu->regs[1];
    PB_STR((SP + 112), cpu->regs[0]);
    FLAG_CMP(cpu->regs[2], cpu->regs[19]);
    if (FLAG_LS) goto L_17849c;
    PB_LDRB(cpu->regs[3], (cpu->regs[4] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(45ULL)));
    if (FLAG_EQ) goto L_178674;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 4294967263ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 65ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_HI) goto L_1785c4;
L_1782c8:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[6] = 0ULL;
L_1782d8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 4294967263ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 65ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 65ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_HI) goto L_1783a4;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 71ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(25ULL)));
    cpu->regs[5] = cpu->regs[26] << 6;
    cpu->regs[3] = (FLAG_HI) ? cpu->regs[3] : cpu->regs[4];
L_178300:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[20] = ((uint32_t)(cpu->regs[6] + 6ULL));
    PB_STR((SP + 72), cpu->regs[19]);
    cpu->regs[26] = cpu->regs[3] | cpu->regs[5];
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(15ULL)));
    if (FLAG_HI) goto L_178334;
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_HS) goto L_178408;
    cpu->regs[6] = cpu->regs[1];
L_178324:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
L_178328:
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[6] = cpu->regs[20];
    goto L_1782d8;
L_178334:
    cpu->regs[20] = ((uint32_t)(cpu->regs[6] - 10ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[27] << (cpu->regs[20] & 63)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[2] = cpu->regs[26] >> (cpu->regs[20] & 63);
    cpu->regs[6] = cpu->regs[2];
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[26] = cpu->regs[26] & cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_178710;
L_178354:
    cpu->regs[0] = ((uint32_t)(cpu->regs[28] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1023ULL)));
    if (FLAG_LS) goto L_1783fc;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[23];
L_178368:
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x178378ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x129f60ULL);
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_178770;
    PB_LDR(cpu->regs[2], (SP + 96));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_HS) goto L_1784a4;
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[6] = 0ULL;
    goto L_178328;
L_1783a4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_178490;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 4294967291ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_17860c;
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_1783cc;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(5ULL)));
    if (FLAG_HI) goto L_1785f4;
    if ((cpu->regs[26])!=0) goto L_17864c;
L_1783cc:
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1786d0;
L_1783d0:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(45ULL)));
    if (FLAG_NE) goto L_1783e0;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_STR((SP + 72), cpu->regs[19]);
L_1783e0:
    PB_LDR(cpu->regs[19], (SP + 72));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_HS) goto L_1785ec;
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    cpu->regs[4] = cpu->regs[19];
    PB_LDRB(cpu->regs[20], (cpu->regs[19] + 0));
    goto L_178120;
L_1783fc:
    PB_LDR(cpu->regs[2], (SP + 96));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_LO) goto L_178324;
L_178408:
    if ((cpu->regs[25])==0) goto L_1784bc;
L_17840c:
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    cpu->regs[0] = 1ULL;
L_178414:
    PB_LDR(cpu->regs[24], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    if ((cpu->regs[25])==0) goto L_1781f8;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1781e8;
    PB_LDR(cpu->regs[0], (SP + 112));
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 40));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_1781fc;
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_1781fc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[9];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 40), cpu->regs[9]);
    PB_STRW((SP + 48), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x178454ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xefd20ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x178460ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x178468ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[9], (SP + 40));
    cpu->regs[0] = cpu->regs[23];
    PB_LDRW(cpu->regs[8], (SP + 48));
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x178484ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bef0ULL);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
    goto L_178240;
L_178490:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 4ULL));
    cpu->regs[5] = cpu->regs[26] << 6;
    goto L_178300;
L_17849c:
    cpu->regs[26] = 0ULL;
    cpu->regs[20] = 0ULL;
L_1784a4:
    if ((cpu->regs[25])!=0) goto L_17840c;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(5ULL)));
    if (FLAG_HI) goto L_1784bc;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[26], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_178528;
L_1784bc:
    cpu->regs[0] = SP + 72ULL;
    cpu->regs[1] = SP + 80ULL;
    PB_STR((SP + 0), cpu->regs[1]); PB_STR((SP + 0) + 8, cpu->regs[0]);
    cpu->regs[7] = SP + 104ULL;
    cpu->regs[6] = SP + 112ULL;
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_STR((SP + 16), cpu->regs[23]);
    cpu->regs[5] = SP + 96ULL;
    cpu->regs[4] = SP + 120ULL;
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[3] = PB_BASE + 0x29a000ULL;
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = cpu->regs[3] + 3560ULL;
    cpu->regs[2] = cpu->regs[2] + 3552ULL;
    PB_STR((SP + 104), cpu->regs[24]);
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x178508ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x21e128ULL);
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_178770;
    PB_LDR(cpu->regs[4], (SP + 72));
    PB_LDR(cpu->regs[2], (SP + 96));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_LO) goto L_178788;
L_178528:
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    PB_LDR(cpu->regs[24], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1781f8;
L_178534:
    PB_LDR(cpu->regs[1], (SP + 120));
    cpu->regs[3] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = cpu->regs[3] + 3520ULL;
    cpu->regs[4] = cpu->regs[4] - cpu->regs[1];
    PB_STR((SP + 112), cpu->regs[4]);
L_178548:
    cpu->regs[0] = SP + 72ULL;
    cpu->regs[2] = SP + 80ULL;
    PB_STR((SP + 0), cpu->regs[2]); PB_STR((SP + 0) + 8, cpu->regs[0]);
    cpu->regs[10] = cpu->regs[19] - cpu->regs[1];
    cpu->regs[7] = SP + 104ULL;
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_STR((SP + 16), cpu->regs[23]);
    cpu->regs[6] = SP + 112ULL;
    cpu->regs[5] = SP + 96ULL;
    cpu->regs[4] = SP + 120ULL;
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[2] = cpu->regs[2] + 3552ULL;
    PB_STR((SP + 72), cpu->regs[19]);
    PB_STR((SP + 104), cpu->regs[10]);
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x178594ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x21e128ULL);
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_178170;
    PB_LDR(cpu->regs[19], (SP + 72));
    PB_LDR(cpu->regs[2], (SP + 96));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_HS) goto L_1781e0;
    PB_LDRB(cpu->regs[20], (cpu->regs[19] + 0));
    goto L_1781d4;
L_1785bc:
    cpu->regs[0] = 0ULL;
    goto L_178414;
L_1785c4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 47ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(43ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 10ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_1782c8;
    cpu->regs[3] = PB_BASE + 0x29a000ULL;
    cpu->regs[19] = cpu->regs[4] + 2ULL;
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    cpu->regs[3] = cpu->regs[3] + 3496ULL;
    goto L_178548;
L_1785ec:
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    goto L_1781e0;
L_1785f4:
    PB_LDR(cpu->regs[1], (SP + 120));
    cpu->regs[3] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = cpu->regs[3] + 3416ULL;
    goto L_178548;
L_17860c:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(43ULL)));
    cpu->regs[5] = cpu->regs[26] << 6;
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
    cpu->regs[3] = cpu->regs[3] + 62ULL;
    goto L_178300;
L_178620:
    if ((cpu->regs[3])==0) goto L_178628;
    PB_STR((cpu->regs[3] + 0), 0ULL);
L_178628:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[1] = cpu->regs[19] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 8080));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_178778;
L_178640:
    cpu->regs[1] = 24464ULL;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[1];
    goto L_178240;
L_17864c:
    PB_LDR(cpu->regs[1], (SP + 120));
    cpu->regs[3] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = cpu->regs[3] + 3456ULL;
    goto L_178548;
L_178664:
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    PB_STR((SP + 272), cpu->regs[27]); PB_STR((SP + 272) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x178674ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_178674:
    cpu->regs[19] = cpu->regs[4] + 2ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 43ULL;
    PB_STR((SP + 40), cpu->regs[4]);
    PB_STR((SP + 56), cpu->regs[2]);
    PB_STR((SP + 72), cpu->regs[19]);
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x17869cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x129f60ULL);
    PB_LDR(cpu->regs[4], (SP + 40));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    if (FLAG_EQ) goto L_178770;
    FLAG_CMP(cpu->regs[2], cpu->regs[19]);
    if (FLAG_LS) goto L_1785ec;
    PB_LDRB(cpu->regs[20], (cpu->regs[4] + 2));
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    goto L_178120;
L_1786d0:
    PB_STRW((SP + 56), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_178780;
    cpu->regs[0] = cpu->regs[23];
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1786f0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x129f60ULL);
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_178770;
    PB_LDR(cpu->regs[2], (SP + 96));
    PB_LDRW(cpu->regs[3], (SP + 56));
    goto L_1783d0;
L_178710:
    cpu->regs[0] = 4294910976ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1023ULL)));
    if (FLAG_HI) goto L_178738;
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & 0x3ffULL) << 10)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 1023ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[2]));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (16ULL << 12)));
    goto L_178368;
L_178738:
    cpu->regs[0] = cpu->regs[23];
    PB_STRW((SP + 56), cpu->regs[2]);
    PB_STR((SP + 64), cpu->regs[2]);
    PB_STR((SP + 136), cpu->regs[9]);
    PB_STRW((SP + 144), cpu->regs[22]); PB_STRW((SP + 144) + 4, cpu->regs[8]);
    PB_STR((SP + 160), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x178754ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x129f60ULL);
    PB_LDR(cpu->regs[2], (SP + 64));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDR(cpu->regs[9], (SP + 136));
    PB_LDR(cpu->regs[21], (SP + 160));
    PB_LDRW(cpu->regs[6], (SP + 56));
    PB_LDRW(cpu->regs[22], (SP + 144)); PB_LDRW(cpu->regs[8], (SP + 144) + 4);
    if (FLAG_NE) goto L_178354;
L_178770:
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    goto L_178170;
L_178778:
    PB_STRW((cpu->regs[1] + 8080), cpu->regs[0]);
    goto L_178640;
L_178780:
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    goto L_1780d4;
L_178788:
    cpu->regs[19] = cpu->regs[4];
    PB_LDRB(cpu->regs[20], cpu->regs[19]); cpu->regs[19] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_1787a0;
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    goto L_17812c;
L_1787a0:
    PB_STR((SP + 40), cpu->regs[21]);
    goto L_178290;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 48));
    PB_STR((SP + 64), cpu->regs[25]);
    PB_LDR(cpu->regs[24], (cpu->regs[22] + 16)); PB_LDR(cpu->regs[21], (cpu->regs[22] + 16) + 8);
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 32)); PB_LDR(cpu->regs[20], (cpu->regs[22] + 32) + 8);
    PB_LDR(cpu->regs[25], (cpu->regs[24] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_178860;
    if ((cpu->regs[23])==0) goto L_178a28;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_GT) goto L_1789f4;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -16));
    if ((cpu->regs[0])==0) goto L_178a84;
L_1787f0:
    cpu->regs[19] = cpu->regs[20] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_178858;
    cpu->regs[2] = cpu->regs[19] << 3;
    cpu->regs[0] = cpu->regs[25] - 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + cpu->regs[2]));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_17886c;
    cpu->regs[19] = cpu->regs[20] - 2ULL;
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_178858;
    cpu->regs[2] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[25] - 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_178868;
    cpu->regs[19] = cpu->regs[20] - 3ULL;
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_178858;
    cpu->regs[25] = cpu->regs[25] - cpu->regs[20];
L_17883c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + (cpu->regs[19] << 3)));
    cpu->regs[0] = cpu->regs[25] + cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_178868;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_17883c;
L_178858:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[22] + 48), cpu->regs[0]);
L_178860:
    cpu->regs[23] = 0ULL;
    goto L_178960;
L_178868:
    cpu->regs[2] = cpu->regs[19] << 3;
L_17886c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + cpu->regs[2]));
    cpu->regs[22] = cpu->regs[19] + 1ULL;
    cpu->regs[25] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[21] + cpu->regs[2]), cpu->regs[0]);
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_GT) goto L_17897c;
L_178888:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_LE) goto L_178950;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + cpu->regs[2]));
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1789d8;
    cpu->regs[2] = cpu->regs[23] + cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 24));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1789b4;
L_1788bc:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_LE) goto L_178950;
L_1788c4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1788e0;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1788e0:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32));
    PB_STR((cpu->regs[2] + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1788fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_178a90;
L_1788fc:
    cpu->regs[19] = cpu->regs[19] + 2ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_LE) goto L_178950;
L_178908:
    cpu->regs[22] = cpu->regs[23] + 24ULL;
L_17890c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + (cpu->regs[19] << 3)));
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_178928;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_178928:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[19] << 3)));
    PB_STR((cpu->regs[22] + (cpu->regs[19] << 3)), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_178944;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_178aa4;
L_178944:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_GT) goto L_17890c;
L_178950:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_178960;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_178960:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_17897c:
    cpu->regs[3] = cpu->regs[1] + 2ULL;
    cpu->regs[0] = cpu->regs[19] + 2ULL;
    PB_STR((cpu->regs[25] + 8), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LE) goto L_178888;
    cpu->regs[4] = 1ULL;
    cpu->regs[4] = cpu->regs[4] - cpu->regs[19];
L_178998:
    cpu->regs[3] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[3] = cpu->regs[4] + cpu->regs[3];
    PB_STR((cpu->regs[21] + (cpu->regs[0] << 3)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_178888;
    goto L_178998;
L_1789b4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1788bc;
    PB_STR((SP + 88), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1789c8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 88));
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_GT) goto L_1788c4;
    goto L_178950;
L_1789d8:
    cpu->regs[2] = cpu->regs[23] + cpu->regs[2];
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 24));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1788bc;
    goto L_1789b4;
L_1789f4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x178a00ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_178858;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[22] + 32), cpu->regs[19]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_178a20;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_178a74;
L_178a20:
    cpu->regs[23] = cpu->regs[19];
    goto L_1787f0;
L_178a28:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x178a30ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_178858;
    cpu->regs[3] = cpu->regs[23] + 24ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[22] + 32), cpu->regs[23]);
L_178a44:
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_GE) goto L_178950;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + (cpu->regs[0] << 3)));
    cpu->regs[1] = cpu->regs[24] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_178a68;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_178a68:
    PB_STR((cpu->regs[3] + (cpu->regs[0] << 3)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_178a44;
L_178a74:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[23] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x178a80ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1787f0;
L_178a84:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x178a8cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_1787f0;
L_178a90:
    cpu->regs[19] = cpu->regs[19] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x178a98ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_GT) goto L_178908;
    goto L_178950;
L_178aa4:
    cpu->regs[30] = PB_BASE + 0x178aa8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_178944;
}
