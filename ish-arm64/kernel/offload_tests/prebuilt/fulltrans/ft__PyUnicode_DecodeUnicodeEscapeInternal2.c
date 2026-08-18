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

void ft__PyUnicode_DecodeUnicodeEscapeInternal2(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 288ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 192), cpu->regs[29]); PB_STR((SP + 192) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 192ULL;
    PB_STR((SP + 56), cpu->regs[0]);
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[4];
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[5];
    cpu->regs[24] = cpu->regs[3];
    PB_STR((SP + 256), cpu->regs[25]); PB_STR((SP + 256) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    PB_STR((SP + 184), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 80), 0ULL); PB_STR((SP + 80) + 8, 0ULL);
    PB_STR((SP + 104), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x11c584ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[1] = 4294967295ULL;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[23] + 0), 0ULL);
    if ((cpu->regs[19])==0) goto L_11cab0;
    cpu->regs[21] = SP + 128ULL;
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11c5a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11cb84ULL);
    PB_LDRW(cpu->regs[0], (SP + 148));
    PB_STR((SP + 168), cpu->regs[19]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_11cb44;
L_11c5b4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x11c5c4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11cba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11c7e4;
L_11c5cc:
    cpu->regs[19] = cpu->regs[20] + cpu->regs[19];
    PB_STR((SP + 96), cpu->regs[19]);
    PB_STR((SP + 272), cpu->regs[27]); PB_STR((SP + 272) + 8, cpu->regs[28]);
L_11c5d8:
    PB_LDR(cpu->regs[19], (SP + 56));
    PB_LDR(cpu->regs[27], (SP + 96));
    FLAG_CMP(cpu->regs[27], cpu->regs[19]);
    if (FLAG_HI) goto L_11c628;
    goto L_11c6f8;
L_11c5ec:
    PB_LDRW(cpu->regs[0], (SP + 148));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_11ca38;
    PB_LDR(cpu->regs[6], (SP + 160));
    PB_LDRW(cpu->regs[0], (SP + 144));
    cpu->regs[2] = cpu->regs[6] + 1ULL;
    PB_STR((SP + 160), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (SP + 136));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_11c804;
    PB_STRB((cpu->regs[2] + cpu->regs[6]), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 56));
    PB_LDR(cpu->regs[27], (SP + 96));
    FLAG_CMP(cpu->regs[19], cpu->regs[27]);
    if (FLAG_HS) goto L_11c6f8;
L_11c628:
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    PB_STR((SP + 56), cpu->regs[0]);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(92ULL)));
    if (FLAG_NE) goto L_11c5ec;
    PB_LDR(cpu->regs[8], (SP + 104));
    cpu->regs[4] = cpu->regs[0] - cpu->regs[8];
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    PB_STR((SP + 120), cpu->regs[4]);
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_HS) goto L_11ca20;
    cpu->regs[28] = cpu->regs[19] + 2ULL;
    PB_STR((SP + 56), cpu->regs[28]);
    PB_LDRB(cpu->regs[6], (cpu->regs[19] + 1));
    cpu->regs[1] = ((uint32_t)(cpu->regs[6] - 10ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(110ULL)));
    if (FLAG_LS) goto L_11c74c;
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_11c688;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[6]);
    FLAG_CMP(cpu->regs[20], cpu->regs[8]);
    if (FLAG_NE) goto L_11c688;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
L_11c688:
    PB_LDR(cpu->regs[19], (SP + 160));
    cpu->regs[3] = 92ULL;
    PB_LDR(cpu->regs[28], (SP + 136));
    cpu->regs[4] = cpu->regs[19] + 1ULL;
    PB_LDRW(cpu->regs[27], (SP + 144));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[28];
    PB_STR((SP + 32), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[27];
    PB_STRW((SP + 40), cpu->regs[6]);
    PB_STR((SP + 160), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x11c6b8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11ce20ULL);
    PB_LDRW(cpu->regs[6], (SP + 40));
    PB_LDRW(cpu->regs[0], (SP + 148));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_11ca34;
    PB_LDR(cpu->regs[4], (SP + 32));
    cpu->regs[19] = cpu->regs[19] + 2ULL;
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[4];
    PB_STR((SP + 160), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x11c6e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11ce20ULL);
L_11c6e8:
    PB_LDR(cpu->regs[27], (SP + 96));
L_11c6ec:
    PB_LDR(cpu->regs[19], (SP + 56));
    FLAG_CMP(cpu->regs[19], cpu->regs[27]);
    if (FLAG_LO) goto L_11c628;
L_11c6f8:
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x11c700ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[30] = PB_BASE + 0x11c708ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11c710ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11ce48ULL);
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
L_11c714:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 184));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_11cafc;
    PB_LDR(cpu->regs[29], (SP + 192)); PB_LDR(cpu->regs[30], (SP + 192) + 8);
    PB_LDR(cpu->regs[19], (SP + 208)); PB_LDR(cpu->regs[20], (SP + 208) + 8);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
    PB_LDR(cpu->regs[25], (SP + 256)); PB_LDR(cpu->regs[26], (SP + 256) + 8);
    SP = SP + 288ULL;
    return;
L_11c74c:
    cpu->regs[2] = PB_BASE + 0x2b4000ULL;
    cpu->regs[2] = cpu->regs[2] + 3108ULL;
    PB_LDRH(cpu->regs[2], (cpu->regs[2] + (((uint64_t)(uint32_t)(cpu->regs[1])) << 1)));
    cpu->regs[1] = PB_BASE + 0x11c764ULL;
    cpu->regs[2] = cpu->regs[1] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[2])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[2]); return;
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[6] = cpu->regs[0] + 1088ULL;
    cpu->regs[2] = 4ULL;
L_11c770:
    PB_STRW((SP + 76), 0ULL);
L_11c774:
    FLAG_CMP(cpu->regs[27], cpu->regs[28]);
    if (FLAG_EQ) goto L_11ca28;
    PB_LDRB(cpu->regs[3], (cpu->regs[28] + 0));
    PB_LDRW(cpu->regs[0], (SP + 76));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 48ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << 4));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_11c814;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 48ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + cpu->regs[3]));
L_11c7a0:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    PB_STR((SP + 56), cpu->regs[28]);
    PB_STRW((SP + 76), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_11c774;
    cpu->regs[0] = 1114111ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_11cad8;
L_11c7c0:
    PB_LDRW(cpu->regs[0], (SP + 148));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_HS) goto L_11c854;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11c7d8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x129f60ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_11c6e8;
L_11c7e0:
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
L_11c7e4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11c7ecULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7bef0ULL);
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x11c7f4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[30] = PB_BASE + 0x11c7fcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    goto L_11c714;
L_11c804:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_11c874;
    PB_STRH((cpu->regs[2] + (cpu->regs[6] << 1)), cpu->regs[1]);
    goto L_11c6ec;
L_11c814:
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 97ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(5ULL)));
    if (FLAG_HI) goto L_11ca04;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 87ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + cpu->regs[3]));
    goto L_11c7a0;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 10ULL;
L_11c838:
    PB_LDR(cpu->regs[2], (SP + 160));
    PB_LDRW(cpu->regs[0], (SP + 144));
    cpu->regs[4] = cpu->regs[2] + 1ULL;
    PB_STR((SP + 160), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x11c84cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11ce20ULL);
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_11c6ec;
L_11c854:
    PB_LDR(cpu->regs[1], (SP + 136));
    goto L_11c838;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 13ULL;
    goto L_11c838;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 9ULL;
    goto L_11c838;
L_11c874:
    PB_STRW((cpu->regs[2] + (cpu->regs[6] << 2)), cpu->regs[1]);
    goto L_11c6ec;
    cpu->regs[3] = ((uint32_t)(cpu->regs[6] - 48ULL));
    PB_STRW((SP + 76), cpu->regs[3]);
    FLAG_CMP(cpu->regs[28], cpu->regs[27]);
    if (FLAG_HS) goto L_11c7c0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 2));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 48ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_11c7c0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + (cpu->regs[3] << 3)));
    cpu->regs[1] = cpu->regs[19] + 3ULL;
    PB_STR((SP + 56), cpu->regs[1]);
    PB_STRW((SP + 76), cpu->regs[3]);
    FLAG_CMP(cpu->regs[1], cpu->regs[27]);
    if (FLAG_HS) goto L_11c7c0;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 3));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 48ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_11c7c0;
    cpu->regs[19] = cpu->regs[19] + 4ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + (cpu->regs[3] << 3)));
    PB_STR((SP + 56), cpu->regs[19]);
    PB_STRW((SP + 76), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_11c7c0;
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_11c7c0;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], cpu->regs[8]);
    if (FLAG_NE) goto L_11c7c0;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_11c7c0;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 92ULL;
    goto L_11c838;
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[6] = cpu->regs[0] + 1064ULL;
    goto L_11c770;
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = 8ULL;
    cpu->regs[6] = cpu->regs[0] + 1032ULL;
    goto L_11c770;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 34ULL;
    goto L_11c838;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 39ULL;
    goto L_11c838;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 11ULL;
    goto L_11c838;
    cpu->regs[3] = cpu->regs[25] + (64ULL << 12);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 5240));
    if ((cpu->regs[2])==0) goto L_11cb14;
L_11c960:
    FLAG_CMP(cpu->regs[28], cpu->regs[27]);
    if (FLAG_HS) goto L_11caf0;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(123ULL)));
    if (FLAG_NE) goto L_11cae4;
    cpu->regs[0] = cpu->regs[19] + 3ULL;
    cpu->regs[1] = cpu->regs[0];
L_11c97c:
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[3] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], cpu->regs[27]);
    if (FLAG_EQ) goto L_11caf0;
    PB_LDRB(cpu->regs[6], cpu->regs[1]); cpu->regs[1] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(125ULL)));
    if (FLAG_NE) goto L_11c97c;
    cpu->regs[1] = cpu->regs[3] - cpu->regs[0]; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_11cae4;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[4] = 4294967295ULL;
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[3] = 2147483647ULL;
    PB_STRW((SP + 76), cpu->regs[4]);
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_HI) goto L_11cb78;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 76ULL;
    PB_STR((SP + 32), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x11c9d0ULL; PB_CALL(14, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[8], (SP + 32));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11cb78;
    PB_LDRW(cpu->regs[3], (SP + 76));
    goto L_11c7c0;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 12ULL;
    goto L_11c838;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 8ULL;
    goto L_11c838;
    PB_LDR(cpu->regs[1], (SP + 136));
    cpu->regs[3] = 7ULL;
    goto L_11c838;
L_11ca04:
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 65ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(5ULL)));
    if (FLAG_HI) goto L_11ca50;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 55ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + cpu->regs[3]));
    goto L_11c7a0;
L_11ca20:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[6] = cpu->regs[0] + 1112ULL;
L_11ca28:
    if ((cpu->regs[24])==0) goto L_11ca54;
    PB_STR((cpu->regs[24] + 0), cpu->regs[4]);
    goto L_11c6f8;
L_11ca34:
    cpu->regs[1] = cpu->regs[6];
L_11ca38:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11ca40ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x129f60ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11c7e0;
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_11c6ec;
L_11ca50:
    PB_STRW((SP + 76), cpu->regs[0]);
L_11ca54:
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[1] = SP + 56ULL;
    PB_LDR(cpu->regs[2], (SP + 160));
    cpu->regs[9] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[8] = cpu->regs[0] - cpu->regs[8];
    cpu->regs[3] = SP + 80ULL;
    cpu->regs[9] = cpu->regs[9] + cpu->regs[2];
    PB_STR((SP + 0), cpu->regs[3]); PB_STR((SP + 0) + 8, cpu->regs[1]);
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    PB_STR((SP + 16), cpu->regs[21]);
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[7] = SP + 112ULL;
    cpu->regs[6] = SP + 120ULL;
    cpu->regs[5] = SP + 96ULL;
    cpu->regs[4] = SP + 104ULL;
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[2] = cpu->regs[2] + 1328ULL;
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 112), cpu->regs[8]);
    PB_STR((SP + 168), cpu->regs[9]);
    cpu->regs[30] = PB_BASE + 0x11caa8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x21e128ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11c5d8;
    goto L_11c7e0;
L_11cab0:
    if ((cpu->regs[24])!=0) goto L_11cb04;
L_11cab4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_11cb0c;
L_11cacc:
    cpu->regs[1] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    goto L_11c714;
L_11cad8:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[6] = cpu->regs[0] + 1168ULL;
    goto L_11ca54;
L_11cae4:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[6] = cpu->regs[0] + 1136ULL;
    goto L_11ca54;
L_11caf0:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[6] = cpu->regs[0] + 1136ULL;
    goto L_11ca28;
L_11cafc:
    PB_STR((SP + 272), cpu->regs[27]); PB_STR((SP + 272) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x11cb04ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_11cb04:
    PB_STR((cpu->regs[24] + 0), 0ULL);
    goto L_11cab4;
L_11cb0c:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_11cacc;
L_11cb14:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    PB_STR((SP + 32), cpu->regs[8]); PB_STR((SP + 32) + 8, cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x11cb2cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x2236a0ULL);
    PB_LDR(cpu->regs[3], (SP + 48));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[8], (SP + 32)); PB_LDR(cpu->regs[4], (SP + 32) + 8);
    if ((cpu->regs[0])==0) goto L_11cb58;
    PB_STR((cpu->regs[3] + 5240), cpu->regs[0]);
    goto L_11c960;
L_11cb44:
    PB_LDR(cpu->regs[0], (SP + 152)); PB_LDR(cpu->regs[1], (SP + 152) + 8);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LT) goto L_11c5b4;
    goto L_11c5cc;
L_11cb58:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3992));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 1264ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x11cb70ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    goto L_11c7e4;
L_11cb78:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[6] = cpu->regs[0] + 1200ULL;
    goto L_11ca54;
}
