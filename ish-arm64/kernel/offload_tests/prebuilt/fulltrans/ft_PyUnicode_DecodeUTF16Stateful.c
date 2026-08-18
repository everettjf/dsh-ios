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

void ft_PyUnicode_DecodeUTF16Stateful(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 256ULL;
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 160), cpu->regs[29]); PB_STR((SP + 160) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 160ULL;
    PB_STR((SP + 192), cpu->regs[21]); PB_STR((SP + 192) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 208), cpu->regs[23]); PB_STR((SP + 208) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[4];
    PB_STR((SP + 224), cpu->regs[25]); PB_STR((SP + 224) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 152), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[5] = cpu->regs[6] + cpu->regs[1];
    PB_STR((SP + 40), 0ULL); PB_STR((SP + 40) + 8, 0ULL);
    PB_STR((SP + 56), cpu->regs[5]); PB_STR((SP + 56) + 8, cpu->regs[6]);
    PB_STR((SP + 88), cpu->regs[6]);
    if ((cpu->regs[3])==0) goto L_2299e4;
    PB_LDRW(cpu->regs[25], (cpu->regs[3] + 0));
L_229670:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 1ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_GT) goto L_2299bc;
L_22967c:
    FLAG_CMP(cpu->regs[5], cpu->regs[6]);
    if (FLAG_EQ) goto L_229a34;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1088ULL;
    PB_STR((SP + 176), cpu->regs[19]); PB_STR((SP + 176) + 8, cpu->regs[20]);
    cpu->regs[20] = SP + 96ULL;
    cpu->regs[19] = PB_BASE + 0x299000ULL;
    cpu->regs[19] = cpu->regs[19] + 1104ULL;
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[22] = (FLAG_LE) ? 1 : 0;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 104), 0ULL);
    PB_STR((SP + 128), 0ULL);
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 240), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x2296c0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11cb84ULL);
    cpu->regs[1] = cpu->regs[5] - cpu->regs[6];
    PB_LDRW(cpu->regs[0], (SP + 116));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDR(cpu->regs[24], (SP + 104));
    cpu->regs[1] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0);
    PB_LDR(cpu->regs[27], (SP + 128));
    PB_STR((SP + 136), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_229d40;
L_2296e4:
    if ((cpu->regs[1])==0) goto L_229704;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x2296f4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11cba0ULL);
    PB_LDR(cpu->regs[24], (SP + 104));
    PB_LDR(cpu->regs[27], (SP + 128));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_229ac0;
L_229704:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    cpu->regs[26] = (FLAG_GT) ? 1 : 0;
L_22970c:
    PB_LDR(cpu->regs[9], (SP + 56)); PB_LDR(cpu->regs[3], (SP + 56) + 8);
    cpu->regs[1] = cpu->regs[9] - cpu->regs[3];
    cpu->regs[0] = cpu->regs[3];
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_LE) goto L_2297a8;
    PB_LDRW(cpu->regs[0], (SP + 112));
    cpu->regs[7] = cpu->regs[9] - 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_2298c8;
    PB_LDR(cpu->regs[1], (SP + 96));
    cpu->regs[0] = cpu->regs[24] + cpu->regs[27];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    if (!((cpu->regs[1] >> 6) & 1)) goto L_229cd0;
    cpu->regs[10] = cpu->regs[22];
    cpu->regs[8] = cpu->regs[26];
    cpu->regs[11] = 4294912000ULL;
L_22974c:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_HS) goto L_22978c;
    FLAG_CMP((cpu->regs[3]) & (7ULL), 0);
    if (FLAG_EQ) goto L_229820;
L_22975c:
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[8]));
    cpu->regs[4] = cpu->regs[3] + 2ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[3] + cpu->regs[10]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] | (cpu->regs[1] << 8)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[11]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_2299ec;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_GT) goto L_229794;
    cpu->regs[3] = cpu->regs[4];
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    goto L_22974c;
L_22978c:
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[1] = 0ULL;
L_229794:
    cpu->regs[27] = cpu->regs[0] - cpu->regs[24];
    cpu->regs[3] = cpu->regs[4];
L_22979c:
    PB_STR((SP + 64), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_229980;
    cpu->regs[0] = cpu->regs[3];
L_2297a8:
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[9], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_229be0;
    if ((cpu->regs[23])==0) goto L_2297c4;
L_2297b8:
    PB_LDR(cpu->regs[1], (SP + 88));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
L_2297c4:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x2297ccULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x2297d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 104), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 128), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x2297e4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11ce48ULL);
    PB_LDR(cpu->regs[19], (SP + 176)); PB_LDR(cpu->regs[20], (SP + 176) + 8);
    PB_LDR(cpu->regs[27], (SP + 240));
L_2297ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 152));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_229bb4;
    PB_LDR(cpu->regs[29], (SP + 160)); PB_LDR(cpu->regs[30], (SP + 160) + 8);
    PB_LDR(cpu->regs[21], (SP + 192)); PB_LDR(cpu->regs[22], (SP + 192) + 8);
    PB_LDR(cpu->regs[23], (SP + 208)); PB_LDR(cpu->regs[24], (SP + 208) + 8);
    PB_LDR(cpu->regs[25], (SP + 224)); PB_LDR(cpu->regs[26], (SP + 224) + 8);
    SP = SP + 256ULL;
    return;
L_229820:
    cpu->regs[4] = cpu->regs[3] + 8ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[7]);
    if (FLAG_HI) goto L_22975c;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_22983c;
    goto L_229888;
L_229838:
    cpu->regs[4] = cpu->regs[2];
L_22983c:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + -8));
    FLAG_CMP((cpu->regs[1]) & (18410996206198128512ULL), 0);
    if (FLAG_NE) goto L_229978;
    cpu->regs[6] = cpu->regs[1] >> 16;
    cpu->regs[5] = cpu->regs[1] >> 32;
    cpu->regs[3] = cpu->regs[1] >> 48;
    cpu->regs[2] = cpu->regs[4] + 8ULL;
    PB_STRB((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    PB_STRB((cpu->regs[0] + -3), cpu->regs[6]);
    PB_STRB((cpu->regs[0] + -2), cpu->regs[5]);
    PB_STRB((cpu->regs[0] + -1), cpu->regs[3]);
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_LS) goto L_229838;
L_229874:
    FLAG_CMP(cpu->regs[4], cpu->regs[7]);
    if (FLAG_HS) goto L_229cc8;
    cpu->regs[3] = cpu->regs[4];
    goto L_22975c;
L_229884:
    cpu->regs[4] = cpu->regs[2];
L_229888:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + -8));
    FLAG_CMP((cpu->regs[1]) & (9295289990785237247ULL), 0);
    if (FLAG_NE) goto L_229978;
    cpu->regs[6] = cpu->regs[1] >> 8;
    cpu->regs[5] = cpu->regs[1] >> 24;
    cpu->regs[3] = cpu->regs[1] >> 40;
    cpu->regs[2] = cpu->regs[4] + 8ULL;
    cpu->regs[1] = cpu->regs[1] >> 56;
    PB_STRB((cpu->regs[0] + 0), cpu->regs[6]);
    PB_STRB((cpu->regs[0] + 1), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    PB_STRB((cpu->regs[0] + -2), cpu->regs[3]);
    PB_STRB((cpu->regs[0] + -1), cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_LS) goto L_229884;
    goto L_229874;
L_2298c8:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_229b24;
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[27] << 1);
    cpu->regs[5] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[26];
    cpu->regs[6] = 4294912000ULL;
    goto L_229910;
L_2298e4:
    FLAG_CMP((cpu->regs[3]) & (7ULL), 0);
    if (FLAG_EQ) goto L_229938;
L_2298ec:
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[8] = cpu->regs[3];
    PB_LDRB(cpu->regs[1], (cpu->regs[3] + cpu->regs[5]));
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] | (cpu->regs[1] << 8)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[6]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_229c80;
    PB_STRH(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 2;
L_229910:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_LO) goto L_2298e4;
L_229918:
    cpu->regs[1] = 0ULL;
L_22991c:
    cpu->regs[0] = cpu->regs[0] - cpu->regs[24];
    cpu->regs[27] = (uint64_t)((int64_t)cpu->regs[0] >> 1);
    goto L_22979c;
L_229928:
    FLAG_CMP((cpu->regs[1]) & (9223512776490647552ULL), 0);
    if (FLAG_NE) goto L_22996c;
L_229930:
    cpu->regs[3] = cpu->regs[2];
    PB_STR(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 8;
L_229938:
    cpu->regs[2] = cpu->regs[3] + 8ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_HI) goto L_22996c;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_229928;
    FLAG_CMP((cpu->regs[1]) & (36029346783166592ULL), 0);
    if (FLAG_NE) goto L_22996c;
    cpu->regs[3] = cpu->regs[1] << 8;
    cpu->regs[1] = cpu->regs[1] & 18374966859414961920ULL;
    cpu->regs[3] = cpu->regs[3] & 18374966859414961920ULL;
    cpu->regs[1] = cpu->regs[3] | (cpu->regs[1] >> 8);
    goto L_229930;
L_22996c:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_LO) goto L_2298ec;
    goto L_229918;
L_229978:
    cpu->regs[4] = cpu->regs[4] - 8ULL;
    goto L_229874;
L_229980:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_229a60;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_229c64;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_229af0;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 104), cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x2299a8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x129f60ULL);
    PB_LDR(cpu->regs[24], (SP + 104));
    PB_LDR(cpu->regs[27], (SP + 128));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_22970c;
    goto L_229ac0;
L_2299bc:
    PB_LDRH(cpu->regs[0], (cpu->regs[6] + 0));
    cpu->regs[2] = 65279ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_229bc0;
    cpu->regs[6] = cpu->regs[6] + 2ULL;
    PB_STR((SP + 64), cpu->regs[6]);
    cpu->regs[25] = 4294967295ULL;
    if ((cpu->regs[3])==0) goto L_22967c;
L_2299dc:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[25]);
    goto L_22967c;
L_2299e4:
    cpu->regs[25] = 0ULL;
    goto L_229670;
L_2299ec:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1023ULL)));
    if (FLAG_HI) goto L_229b1c;
    FLAG_CMP(cpu->regs[4], cpu->regs[7]);
    if (FLAG_HS) goto L_229b14;
    PB_LDRB(cpu->regs[2], (cpu->regs[4] + cpu->regs[10]));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & 0x3ffULL) << 10)));
    PB_LDRB(cpu->regs[6], (cpu->regs[4] + cpu->regs[8]));
    cpu->regs[4] = cpu->regs[3] + 4ULL;
    cpu->regs[10] = 4294910976ULL;
    cpu->regs[5] = 3ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[6] | (cpu->regs[2] << 8)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1023ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[10]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1024ULL)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (16ULL << 12)));
    cpu->regs[1] = (FLAG_LO) ? cpu->regs[1] : cpu->regs[5];
    goto L_229794;
L_229a34:
    if ((cpu->regs[23])==0) goto L_229a3c;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
L_229a3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_229d28;
L_229a54:
    cpu->regs[11] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[11];
    goto L_2297ec;
L_229a60:
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[8] = cpu->regs[3] - 2ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 1144ULL;
    cpu->regs[8] = cpu->regs[8] - cpu->regs[0];
    cpu->regs[9] = cpu->regs[8] + 2ULL;
L_229a78:
    cpu->regs[0] = SP + 64ULL;
    cpu->regs[1] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[1]); PB_STR((SP + 0) + 8, cpu->regs[0]);
    cpu->regs[7] = SP + 72ULL;
    cpu->regs[6] = SP + 80ULL;
    PB_STR((SP + 16), cpu->regs[20]);
    cpu->regs[5] = SP + 56ULL;
    cpu->regs[4] = SP + 88ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = SP + 48ULL;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 72), cpu->regs[9]); PB_STR((SP + 72) + 8, cpu->regs[8]);
    PB_STR((SP + 104), cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x229ab4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x21e128ULL);
    PB_LDR(cpu->regs[24], (SP + 104));
    PB_LDR(cpu->regs[27], (SP + 128));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22970c;
L_229ac0:
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 104), cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x229ad0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7bef0ULL);
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x229ad8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x229ae0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 240));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 176)); PB_LDR(cpu->regs[20], (SP + 176) + 8);
    goto L_2297ec;
L_229af0:
    cpu->regs[0] = cpu->regs[3] - 2ULL;
    PB_STR((SP + 64), cpu->regs[0]);
    if ((cpu->regs[23])!=0) goto L_2297b8;
    PB_LDR(cpu->regs[1], (SP + 88));
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[3] = cpu->regs[3] + 1496ULL;
    cpu->regs[8] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[9] = cpu->regs[9] - cpu->regs[1];
    goto L_229a78;
L_229b14:
    cpu->regs[1] = 1ULL;
    goto L_229794;
L_229b1c:
    cpu->regs[1] = 2ULL;
    goto L_229794;
L_229b24:
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[27] << 2);
    cpu->regs[5] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[26];
    cpu->regs[8] = 4294912000ULL;
L_229b34:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_HS) goto L_229c5c;
    FLAG_CMP((cpu->regs[3]) & (7ULL), 0);
    if (FLAG_EQ) goto L_229c48;
L_229b44:
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[6] = cpu->regs[3];
    PB_LDRB(cpu->regs[1], (cpu->regs[3] + cpu->regs[5]));
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] | (cpu->regs[1] << 8)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[8]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2047ULL)));
    if (FLAG_HI) goto L_229c08;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1023ULL)));
    if (FLAG_HI) goto L_229bf8;
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_HS) goto L_229d38;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[5]));
    PB_LDRB(cpu->regs[10], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[3] = cpu->regs[6] + 4ULL;
    cpu->regs[6] = 4294910976ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[10] | (cpu->regs[2] << 8)));
    cpu->regs[6] = ((uint32_t)(cpu->regs[2] + cpu->regs[6]));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(1023ULL)));
    if (FLAG_HI) goto L_229d30;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 1023ULL));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & 0x3ffULL) << 10)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[2]));
    cpu->regs[2] = cpu->regs[0] + 4ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (16ULL << 12)));
L_229ba8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2];
    goto L_229b34;
L_229bb4:
    PB_STR((SP + 176), cpu->regs[19]); PB_STR((SP + 176) + 8, cpu->regs[20]);
    PB_STR((SP + 240), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x229bc0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_229bc0:
    cpu->regs[2] = 65534ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_229d1c;
    cpu->regs[6] = cpu->regs[6] + 2ULL;
    PB_STR((SP + 64), cpu->regs[6]);
    cpu->regs[25] = 1ULL;
    if ((cpu->regs[3])==0) goto L_22967c;
    goto L_2299dc;
L_229be0:
    PB_LDR(cpu->regs[1], (SP + 88));
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 1128ULL;
    cpu->regs[8] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[9] = cpu->regs[9] - cpu->regs[1];
    goto L_229a78;
L_229bf8:
    cpu->regs[1] = 2ULL;
L_229bfc:
    cpu->regs[0] = cpu->regs[0] - cpu->regs[24];
    cpu->regs[27] = (uint64_t)((int64_t)cpu->regs[0] >> 2);
    goto L_22979c;
L_229c08:
    cpu->regs[2] = cpu->regs[0] + 4ULL;
    goto L_229ba8;
L_229c10:
    FLAG_CMP((cpu->regs[1]) & (36029346783166592ULL), 0);
    if (FLAG_NE) goto L_229c54;
    cpu->regs[3] = cpu->regs[1] << 8;
    cpu->regs[1] = cpu->regs[1] & 18374966859414961920ULL;
    cpu->regs[3] = cpu->regs[3] & 18374966859414961920ULL;
    cpu->regs[1] = cpu->regs[3] | (cpu->regs[1] >> 8);
L_229c28:
    cpu->regs[6] = ((uint32_t)(cpu->regs[1] & 65535ULL));
    cpu->regs[10] = ((uint32_t)(cpu->regs[1] >> 16));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[2] = ((cpu->regs[1] >> 32) & 0xffffULL);
    cpu->regs[1] = cpu->regs[1] >> 48;
    PB_STRW((cpu->regs[0] + -16), cpu->regs[6]); PB_STRW((cpu->regs[0] + -16) + 4, cpu->regs[10]);
    PB_STRW((cpu->regs[0] + -8), cpu->regs[2]); PB_STRW((cpu->regs[0] + -8) + 4, cpu->regs[1]);
L_229c48:
    cpu->regs[2] = cpu->regs[3] + 8ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_LS) goto L_229d54;
L_229c54:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_LO) goto L_229b44;
L_229c5c:
    cpu->regs[1] = 0ULL;
    goto L_229bfc;
L_229c64:
    PB_LDR(cpu->regs[0], (SP + 88));
    cpu->regs[8] = cpu->regs[3] - 4ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 1168ULL;
    cpu->regs[8] = cpu->regs[8] - cpu->regs[0];
    cpu->regs[9] = cpu->regs[8] + 2ULL;
    goto L_229a78;
L_229c80:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1023ULL)));
    if (FLAG_HI) goto L_229d74;
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_HS) goto L_229d6c;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[5]));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & 0x3ffULL) << 10)));
    PB_LDRB(cpu->regs[5], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[7] = 4294910976ULL;
    cpu->regs[4] = 3ULL;
    cpu->regs[3] = cpu->regs[8] + 4ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] | (cpu->regs[2] << 8)));
    cpu->regs[5] = ((uint32_t)(cpu->regs[2] & 1023ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[7]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1024ULL)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (16ULL << 12)));
    cpu->regs[1] = (FLAG_LO) ? cpu->regs[1] : cpu->regs[4];
    goto L_22991c;
L_229cc8:
    cpu->regs[1] = 0ULL;
    goto L_229794;
L_229cd0:
    cpu->regs[6] = cpu->regs[22];
    cpu->regs[5] = cpu->regs[26];
    cpu->regs[8] = 4294912000ULL;
L_229cdc:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_HS) goto L_229e20;
    FLAG_CMP((cpu->regs[3]) & (7ULL), 0);
    if (FLAG_EQ) goto L_229df8;
L_229cec:
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[5]));
    cpu->regs[4] = cpu->regs[3];
    PB_LDRB(cpu->regs[1], (cpu->regs[3] + cpu->regs[6]));
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] | (cpu->regs[1] << 8)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[8]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2047ULL)));
    if (FLAG_LS) goto L_229d7c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(255ULL)));
    if (FLAG_GT) goto L_229dc0;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    goto L_229cdc;
L_229d1c:
    cpu->regs[25] = 0ULL;
    if ((cpu->regs[3])==0) goto L_22967c;
    goto L_2299dc;
L_229d28:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_229a54;
L_229d30:
    cpu->regs[1] = 3ULL;
    goto L_229bfc;
L_229d38:
    cpu->regs[1] = 1ULL;
    goto L_229bfc;
L_229d40:
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[27];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_229704;
    goto L_2296e4;
L_229d54:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_229c10;
    FLAG_CMP((cpu->regs[1]) & (9223512776490647552ULL), 0);
    if (FLAG_NE) goto L_229c54;
    goto L_229c28;
L_229d6c:
    cpu->regs[1] = 1ULL;
    goto L_22991c;
L_229d74:
    cpu->regs[1] = 2ULL;
    goto L_22991c;
L_229d7c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1023ULL)));
    if (FLAG_HI) goto L_229e38;
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_HS) goto L_229e2c;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[6]));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & 0x3ffULL) << 10)));
    PB_LDRB(cpu->regs[6], (cpu->regs[3] + cpu->regs[5]));
    cpu->regs[3] = cpu->regs[4] + 4ULL;
    cpu->regs[8] = 4294910976ULL;
    cpu->regs[5] = 3ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[6] | (cpu->regs[2] << 8)));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] & 1023ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[8]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1024ULL)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (16ULL << 12)));
    cpu->regs[1] = (FLAG_LO) ? cpu->regs[1] : cpu->regs[5];
L_229dc0:
    cpu->regs[27] = cpu->regs[0] - cpu->regs[24];
    goto L_22979c;
L_229dc8:
    FLAG_CMP((cpu->regs[1]) & (71777214294589695ULL), 0);
    if (FLAG_NE) goto L_229e18;
    cpu->regs[1] = cpu->regs[1] >> 8;
L_229dd4:
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[10] = cpu->regs[1] >> 16;
    cpu->regs[4] = cpu->regs[1] >> 32;
    cpu->regs[2] = cpu->regs[1] >> 48;
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    PB_STRB((cpu->regs[0] + -4), cpu->regs[1]);
    PB_STRB((cpu->regs[0] + -3), cpu->regs[10]);
    PB_STRB((cpu->regs[0] + -2), cpu->regs[4]);
    PB_STRB((cpu->regs[0] + -1), cpu->regs[2]);
L_229df8:
    cpu->regs[2] = cpu->regs[3] + 8ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_HI) goto L_229e18;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_229dc8;
    FLAG_CMP((cpu->regs[1]) & (18374966859414961920ULL), 0);
    if (FLAG_EQ) goto L_229dd4;
L_229e18:
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_LO) goto L_229cec;
L_229e20:
    cpu->regs[27] = cpu->regs[0] - cpu->regs[24];
    cpu->regs[1] = 0ULL;
    goto L_22979c;
L_229e2c:
    cpu->regs[27] = cpu->regs[0] - cpu->regs[24];
    cpu->regs[1] = 1ULL;
    goto L_22979c;
L_229e38:
    cpu->regs[27] = cpu->regs[0] - cpu->regs[24];
    cpu->regs[1] = 2ULL;
    goto L_22979c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_229ea4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_229ea4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_229e80;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_229e80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x229e88ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12b580ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_229eb8;
    if (((cpu->regs[1] >> 31) & 1)) goto L_229ea4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_229ed0;
L_229ea4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_229eac:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_229eb8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_229ec8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_229edc;
L_229ec8:
    cpu->regs[0] = 0ULL;
    goto L_229eac;
L_229ed0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x229ed8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_229ea4;
L_229edc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x229ee4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_229eac;
    SP = SP - 80ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_22a058;
L_229f24:
    PB_STR((SP + 64), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_22a030;
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_229f94;
L_229f44:
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x229f50ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x228fc0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_229ffc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[4], (SP + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_229ff8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[0] + 3336ULL;
    PB_LDR(cpu->regs[21], (SP + 64));
    SP = SP + 80ULL;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_229f94:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_229f44;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_22a078;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x229fbcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_229ffc;
    cpu->regs[30] = PB_BASE + 0x229fc8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_229f44;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x229fecULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_22a000;
L_229ff4:
    PB_STR((SP + 64), cpu->regs[21]);
L_229ff8:
    cpu->regs[30] = PB_BASE + 0x229ffcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_229ffc:
    PB_LDR(cpu->regs[21], (SP + 64));
L_22a000:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_229ff4;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_22a030:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1200ULL;
    cpu->regs[30] = PB_BASE + 0x22a050ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_22a000;
L_22a058:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1200ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x22a070ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22a000;
    goto L_229f24;
L_22a078:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1200ULL;
    cpu->regs[30] = PB_BASE + 0x22a098ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_22a000;
    SP = SP - 80ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_22a1d8;
L_22a0d8:
    PB_STR((SP + 64), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_22a22c;
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_22a148;
L_22a0f8:
    cpu->regs[2] = 4294967295ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22a104ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x22a260ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_22a1f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[4], (SP + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_22a1ac;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[0] + 3336ULL;
    PB_LDR(cpu->regs[21], (SP + 64));
    SP = SP + 80ULL;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0x1e5ca0ULL); return; };
L_22a148:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_22a0f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_22a1b0;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x22a170ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22a1f8;
    cpu->regs[30] = PB_BASE + 0x22a17cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_22a0f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22a1a0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_22a1fc;
L_22a1a8:
    PB_STR((SP + 64), cpu->regs[21]);
L_22a1ac:
    cpu->regs[30] = PB_BASE + 0x22a1b0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22a1b0:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1224ULL;
    cpu->regs[30] = PB_BASE + 0x22a1d0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_22a1fc;
L_22a1d8:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1224ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x22a1f0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22a0d8;
    goto L_22a1fc;
L_22a1f8:
    PB_LDR(cpu->regs[21], (SP + 64));
L_22a1fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_22a1a8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_22a22c:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1224ULL;
    cpu->regs[30] = PB_BASE + 0x22a24cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    goto L_22a1fc;
    /* nop */
    /* nop */
    /* nop */
}
