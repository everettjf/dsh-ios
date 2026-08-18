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

void ft_PyUnicode_DecodeCharmap(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 288ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 192), cpu->regs[29]); PB_STR((SP + 192) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 192ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 184), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 40), cpu->regs[3]);
    if ((cpu->regs[2])==0) goto L_24a378;
    PB_STR((SP + 272), cpu->regs[27]); PB_STR((SP + 272) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_24a20c;
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    cpu->regs[22] = SP + 128ULL;
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 256), cpu->regs[25]); PB_STR((SP + 256) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 136), 0ULL);
    PB_STRW((SP + 148), 0ULL);
    PB_STR((SP + 152), 0ULL); PB_STR((SP + 152) + 8, 0ULL);
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x249f84ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11cb84ULL);
    PB_LDRW(cpu->regs[23], (SP + 148));
    PB_LDR(cpu->regs[0], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[0]);
    PB_STR((SP + 168), cpu->regs[28]);
    PB_LDR(cpu->regs[25], (SP + 136));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_24a6ac;
L_249fa0:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x249fb0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11cba0ULL);
    PB_LDR(cpu->regs[1], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 136));
    PB_LDRW(cpu->regs[23], (SP + 148));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24a568;
L_249fc8:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[28] = cpu->regs[26] + cpu->regs[28];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_24a3a0;
    PB_LDR(cpu->regs[27], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[9], (cpu->regs[21] + 16));
    PB_STR((SP + 72), cpu->regs[26]); PB_STR((SP + 72) + 8, cpu->regs[26]);
    PB_STR((SP + 112), 0ULL); PB_STR((SP + 112) + 8, 0ULL);
    if (!((cpu->regs[27] >> 5) & 1)) goto L_24a6a4;
    FLAG_CMP((((uint32_t)(cpu->regs[27]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[21] + 40ULL;
    cpu->regs[10] = cpu->regs[21] + 56ULL;
    cpu->regs[24] = (FLAG_EQ) ? cpu->regs[10] : cpu->regs[0];
L_24a004:
    FLAG_CMP(cpu->regs[9], 255ULL);
    cpu->regs[27] = ((uint32_t)(((cpu->regs[27] >> 2) & 0x7ULL)));
    cpu->regs[0] = (FLAG_GT) ? 1 : 0;
    PB_STR((SP + 88), cpu->regs[28]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[27], 1ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[21] = (FLAG_EQ) ? 1 : 0;
    if (FLAG_EQ) goto L_24a200;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[27], 2ULL); } else { FLAG_CMP(0, 1); }
    PB_LDR(cpu->regs[7], (SP + 72));
    cpu->regs[26] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[28] = cpu->regs[26];
L_24a038:
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[2] = cpu->regs[7];
    FLAG_CMP(cpu->regs[0], cpu->regs[7]);
    if (FLAG_LS) goto L_24a17c;
    if ((((uint32_t)(cpu->regs[28])))==0) goto L_24a2fc;
    PB_LDRW(cpu->regs[1], (SP + 144));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_24a230;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    cpu->regs[1] = (~cpu->regs[19]);
    cpu->regs[5] = cpu->regs[0] + cpu->regs[19];
    cpu->regs[6] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[3] = cpu->regs[0] & 3ULL; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_24a154;
    PB_LDRB(cpu->regs[0], (cpu->regs[7] + 0));
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[6] = cpu->regs[26];
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_24a154;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_24a0c8;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    cpu->regs[20] = cpu->regs[2] + 1ULL;
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_24a0c8:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[6] = cpu->regs[26];
    cpu->regs[20] = cpu->regs[2];
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_24a154;
L_24a0f0:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 1));
    cpu->regs[6] = cpu->regs[26];
    cpu->regs[20] = cpu->regs[4];
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    cpu->regs[2] = cpu->regs[4] + 1ULL;
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[4] + 2ULL;
    cpu->regs[19] = cpu->regs[3] + 2ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[4] + 2));
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    cpu->regs[2] = cpu->regs[4] + 3ULL;
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[3] + 3ULL;
L_24a154:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDRH(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a36c;
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[1]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[5]);
    if (FLAG_NE) goto L_24a0f0;
L_24a17c:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[30] = PB_BASE + 0x24a184ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[30] = PB_BASE + 0x24a18cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
L_24a18c:
    PB_LDR(cpu->regs[1], (SP + 32));
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[1]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a1a4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11ce48ULL);
    PB_LDR(cpu->regs[19], (SP + 208)); PB_LDR(cpu->regs[20], (SP + 208) + 8);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
    PB_LDR(cpu->regs[25], (SP + 256)); PB_LDR(cpu->regs[26], (SP + 256) + 8);
L_24a1b4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 184));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_24a5d0;
    PB_LDR(cpu->regs[27], (SP + 272)); PB_LDR(cpu->regs[28], (SP + 272) + 8);
    PB_LDR(cpu->regs[29], (SP + 192)); PB_LDR(cpu->regs[30], (SP + 192) + 8);
    SP = SP + 288ULL;
    return;
L_24a1e0:
    PB_LDRB(cpu->regs[0], (cpu->regs[26] + 0));
    PB_LDRB(cpu->regs[20], (cpu->regs[24] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_HI) goto L_24a5e4;
L_24a1f0:
    PB_STRB((cpu->regs[25] + cpu->regs[19]), cpu->regs[20]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    PB_STR((SP + 72), cpu->regs[26]);
L_24a200:
    FLAG_CMP(cpu->regs[26], cpu->regs[28]);
    if (FLAG_LO) goto L_24a1e0;
    goto L_24a18c;
L_24a20c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_24a69c;
L_24a224:
    cpu->regs[1] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    goto L_24a1b4;
L_24a230:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_24a2fc;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[21];
    cpu->regs[4] = 65534ULL;
    goto L_24a258;
L_24a248:
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[5] = cpu->regs[26];
    PB_STRH((cpu->regs[25] + (cpu->regs[1] << 1)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_24a258:
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_24a17c;
    PB_LDRB(cpu->regs[3], (cpu->regs[2] + 0));
    PB_LDRH(cpu->regs[3], (cpu->regs[24] + (cpu->regs[3] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_NE) goto L_24a248;
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_24a280;
    cpu->regs[7] = cpu->regs[2];
    PB_STR((SP + 72), cpu->regs[2]);
L_24a280:
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[1] = SP + 72ULL;
    cpu->regs[2] = SP + 120ULL;
    PB_STR((SP + 0), cpu->regs[2]); PB_STR((SP + 0) + 8, cpu->regs[1]);
    cpu->regs[0] = cpu->regs[7] - cpu->regs[0];
    cpu->regs[1] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 96), cpu->regs[0]); PB_STR((SP + 96) + 8, cpu->regs[1]);
    cpu->regs[6] = SP + 96ULL;
    PB_LDR(cpu->regs[8], (SP + 32)); PB_LDR(cpu->regs[0], (SP + 32) + 8);
    PB_STR((SP + 16), cpu->regs[22]);
    cpu->regs[1] = SP + 112ULL;
    cpu->regs[5] = SP + 88ULL;
    cpu->regs[4] = SP + 80ULL;
    cpu->regs[7] = SP + 104ULL;
    cpu->regs[3] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = cpu->regs[3] + 3464ULL;
    cpu->regs[2] = cpu->regs[2] + 832ULL;
    PB_STR((SP + 48), cpu->regs[9]);
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[8]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a2dcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x21e128ULL);
    PB_LDRW(cpu->regs[23], (SP + 148));
    PB_LDR(cpu->regs[1], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 136));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24a558;
    PB_LDR(cpu->regs[9], (SP + 48));
    PB_LDR(cpu->regs[7], (SP + 72));
    goto L_24a038;
L_24a2fc:
    PB_LDRB(cpu->regs[2], (cpu->regs[7] + 0));
    FLAG_CMP(cpu->regs[9], cpu->regs[2]);
    if (FLAG_LE) goto L_24a280;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x24a314ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[1] = cpu->regs[0];
L_24a318:
    cpu->regs[0] = 65534ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_24a638;
    PB_LDR(cpu->regs[2], (SP + 32));
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 48), cpu->regs[9]);
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[2]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a340ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x129f60ULL);
    PB_LDRW(cpu->regs[23], (SP + 148));
    PB_LDR(cpu->regs[1], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 136));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24a558;
    PB_LDR(cpu->regs[7], (SP + 72));
    PB_LDR(cpu->regs[9], (SP + 48));
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    PB_STR((SP + 72), cpu->regs[7]);
    goto L_24a038;
L_24a36c:
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_24a318;
    PB_STR((SP + 72), cpu->regs[20]);
    goto L_24a318;
L_24a378:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[4], (SP + 184));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_24a598;
    PB_LDR(cpu->regs[29], (SP + 192)); PB_LDR(cpu->regs[30], (SP + 192) + 8);
    SP = SP + 288ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xefdb0ULL); return; };
L_24a3a0:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    PB_STR((SP + 72), cpu->regs[26]); PB_STR((SP + 72) + 8, cpu->regs[26]);
    cpu->regs[24] = PB_BASE + 0x295000ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2784));
    cpu->regs[24] = cpu->regs[24] + 3464ULL;
    cpu->regs[0] = SP + 104ULL;
    PB_STR((SP + 48), cpu->regs[0]);
    PB_STR((SP + 88), cpu->regs[28]);
    PB_STR((SP + 112), 0ULL); PB_STR((SP + 112) + 8, 0ULL);
L_24a3cc:
    PB_LDR(cpu->regs[20], (SP + 72));
    PB_LDR(cpu->regs[0], (SP + 88));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HS) goto L_24a17c;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x24a3e4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24a484;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x24a3f8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_24a684;
L_24a408:
    if ((cpu->regs[28])!=0) goto L_24a48c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[30] = PB_BASE + 0x24a414ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_24a484;
    cpu->regs[30] = PB_BASE + 0x24a41cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_24a41c:
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[1] = SP + 72ULL;
    PB_LDR(cpu->regs[7], (SP + 48));
    cpu->regs[0] = cpu->regs[20] - cpu->regs[0];
    cpu->regs[9] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 96), cpu->regs[0]); PB_STR((SP + 96) + 8, cpu->regs[9]);
    cpu->regs[2] = SP + 120ULL;
    PB_LDR(cpu->regs[8], (SP + 32)); PB_LDR(cpu->regs[0], (SP + 32) + 8);
    PB_STR((SP + 0), cpu->regs[2]); PB_STR((SP + 0) + 8, cpu->regs[1]);
    cpu->regs[6] = SP + 96ULL;
    PB_STR((SP + 16), cpu->regs[22]);
    cpu->regs[1] = SP + 112ULL;
    cpu->regs[5] = SP + 88ULL;
    cpu->regs[4] = SP + 80ULL;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[2] = cpu->regs[2] + 832ULL;
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[8]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a470ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x21e128ULL);
    PB_LDRW(cpu->regs[23], (SP + 148));
    PB_LDR(cpu->regs[1], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 136));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_24a3cc;
L_24a484:
    cpu->regs[28] = 0ULL;
    goto L_24a550;
L_24a48c:
    FLAG_CMP(cpu->regs[28], cpu->regs[27]);
    if (FLAG_EQ) goto L_24a5b0;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 24) & 1)) goto L_24a510;
    if (!((cpu->regs[0] >> 28) & 1)) goto L_24a668;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_24a640;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x24a4bcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x12b9c0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 65534ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_24a5b0;
L_24a4cc:
    PB_LDR(cpu->regs[2], (SP + 32));
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[2]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a4e4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x129f60ULL);
L_24a4e4:
    PB_LDRW(cpu->regs[23], (SP + 148));
    PB_LDR(cpu->regs[1], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 136));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24a550;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24a620;
L_24a504:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_STR((SP + 72), cpu->regs[20]);
    goto L_24a3cc;
L_24a510:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x24a518ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[2] = 65534ULL;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_24a5b0;
    cpu->regs[0] = 1114111ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_24a4cc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = 1114112ULL;
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24a550ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11f220ULL);
L_24a550:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x24a558ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18d760ULL);
L_24a558:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[30] = PB_BASE + 0x24a560ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[30] = PB_BASE + 0x24a568ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18d760ULL);
L_24a568:
    PB_LDR(cpu->regs[1], (SP + 32));
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[1]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a580ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7bef0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 208)); PB_LDR(cpu->regs[20], (SP + 208) + 8);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
    PB_LDR(cpu->regs[25], (SP + 256)); PB_LDR(cpu->regs[26], (SP + 256) + 8);
    goto L_24a1b4;
L_24a598:
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    PB_STR((SP + 256), cpu->regs[25]); PB_STR((SP + 256) + 8, cpu->regs[26]);
    PB_STR((SP + 272), cpu->regs[27]); PB_STR((SP + 272) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x24a5b0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24a5b0:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24a41c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24a41c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x24a5ccULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24a41c;
L_24a5d0:
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    PB_STR((SP + 256), cpu->regs[25]); PB_STR((SP + 256) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x24a5e4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24a5e4:
    PB_LDR(cpu->regs[3], (SP + 32));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 255ULL;
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[3]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24a604ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11cba0ULL);
    PB_LDRW(cpu->regs[23], (SP + 148));
    PB_LDR(cpu->regs[1], (SP + 152)); PB_LDR(cpu->regs[19], (SP + 152) + 8);
    PB_STR((SP + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (SP + 136));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_24a1f0;
    goto L_24a558;
L_24a620:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24a504;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x24a634ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24a504;
L_24a638:
    PB_LDR(cpu->regs[7], (SP + 72));
    goto L_24a280;
L_24a640:
    PB_LDR(cpu->regs[3], (SP + 32));
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 136), cpu->regs[25]);
    PB_STRW((SP + 148), cpu->regs[23]);
    PB_STR((SP + 152), cpu->regs[3]); PB_STR((SP + 152) + 8, cpu->regs[19]);
    PB_STRB((SP + 180), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x24a664ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x120700ULL);
    goto L_24a4e4;
L_24a668:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3656ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24a680ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_24a550;
L_24a684:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_24a408;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x24a698ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24a408;
L_24a69c:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_24a224;
L_24a6a4:
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 56));
    goto L_24a004;
L_24a6ac:
    cpu->regs[0] = cpu->regs[0] - cpu->regs[19];
    FLAG_CMP(cpu->regs[0], cpu->regs[28]);
    if (FLAG_GE) goto L_249fc8;
    goto L_249fa0;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x24a6d8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe2620ULL);
    if ((cpu->regs[0])==0) goto L_24a78c;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24a6ecULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_24a738;
L_24a6f8:
    if ((cpu->regs[19])==0) goto L_24a7b8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_24a7d0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_24a750;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24a720ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x129680ULL);
    FLAG_CMP(cpu->regs[0], 255ULL);
    if (FLAG_HI) goto L_24a794;
L_24a728:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_24a738:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_24a6f8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24a74cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24a6f8;
L_24a750:
    if (((cpu->regs[1] >> 27) & 1)) goto L_24a728;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3200ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x24a770ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24a78c;
L_24a778:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24a78c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24a78cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_24a78c:
    cpu->regs[19] = 0ULL;
    goto L_24a728;
L_24a794:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24a7acULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24a778;
    goto L_24a78c;
L_24a7b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2784));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24a7c8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_24a78c;
    cpu->regs[30] = PB_BASE + 0x24a7d0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_24a7d0:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    goto L_24a728;
    /* nop */
}
