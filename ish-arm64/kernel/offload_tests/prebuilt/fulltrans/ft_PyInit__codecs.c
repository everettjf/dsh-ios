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

void ft_PyInit__codecs(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[0] = cpu->regs[0] - 16ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x14cec8ULL); return; };
    SP = SP - 144ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 56));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1d26ecULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d2a8cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d293c;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 40));
    if ((cpu->regs[21])==0) goto L_1d2a50;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[4] = 25872ULL;
    cpu->regs[2] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19] + cpu->regs[4];
    PB_STR((SP + 8), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1d271cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d292c;
    PB_LDR(cpu->regs[22], (SP + 24));
    if ((cpu->regs[22])!=0) goto L_1d28ec;
    cpu->regs[3] = 27464ULL;
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1d2740ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d292c;
    PB_LDR(cpu->regs[19], (SP + 32));
    if ((cpu->regs[19])==0) goto L_1d2910;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d2758ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d2d70ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d2774;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d2904;
L_1d2774:
    if ((cpu->regs[22])==0) goto L_1d292c;
    cpu->regs[23] = 1ULL;
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
L_1d2780:
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2680));
    cpu->regs[20] = 0ULL;
L_1d2790:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d279cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x14d028ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d285c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1d2954;
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1d27c4;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d27bcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x122a60ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_1d2838;
L_1d27c4:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1d27d0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d2814;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[28];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    cpu->regs[0] = cpu->regs[21];
    if (FLAG_NE) goto L_1d2a44;
    cpu->regs[30] = PB_BASE + 0x1d27f4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[19] = cpu->regs[0];
L_1d27f8:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d2820;
L_1d2800:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1d2808ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
    if (((cpu->regs[19] >> 31) & 1)) goto L_1d29c4;
L_1d280c:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_1d2790;
L_1d2814:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d29bc;
    cpu->regs[19] = 4294967295ULL;
L_1d2820:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d2800;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1d2834ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2800;
L_1d2838:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d280c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d280c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1d2858ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2790;
L_1d285c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3880));
    cpu->regs[0] = cpu->regs[26];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1d2870ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2a34;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1d287cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d2898;
L_1d2884:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d2898;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d2898ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d2898:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d28a4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d2f10ULL);
    if (((cpu->regs[19] >> 31) & 1)) goto L_1d2944;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1d28b8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d28f8;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_1d28ec:
    cpu->regs[23] = 0ULL;
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    goto L_1d2780;
L_1d28f8:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1d2904ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d2904:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d290cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2774;
L_1d2910:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2840));
    cpu->regs[2] = PB_BASE + 0x291000ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[2] + 2952ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1d292cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5980ULL);
L_1d292c:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d2938ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d2f10ULL);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
L_1d293c:
    cpu->regs[0] = 0ULL;
    goto L_1d28b8;
L_1d2944:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_1d28b8;
L_1d2954:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = 30760ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1d2968ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d2a18;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[3] >> 28) & 1)) goto L_1d29e8;
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1d2a78;
    cpu->regs[3] = PB_BASE + 0x291000ULL;
    cpu->regs[5] = PB_BASE + 0x28f000ULL;
    cpu->regs[3] = cpu->regs[3] + 2888ULL;
    cpu->regs[5] = cpu->regs[5] + 960ULL;
L_1d299c:
    PB_LDR(cpu->regs[4], (cpu->regs[28] + 8));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = PB_BASE + 0x291000ULL;
    cpu->regs[2] = cpu->regs[2] + 3056ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 24));
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d29b8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_1d29fc;
L_1d29bc:
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1d29c4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdce4cULL);
L_1d29c4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d2884;
L_1d29cc:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d29d8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1d2f10ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_1d28b8;
L_1d29e8:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = PB_BASE + 0x291000ULL;
    cpu->regs[2] = cpu->regs[2] + 3008ULL;
    cpu->regs[30] = PB_BASE + 0x1d29fcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x225d40ULL);
L_1d29fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d2a18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d2a18;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d2a18ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d2a18:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d2a34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d2a34;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1d2a34ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d2a34:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d29cc;
    cpu->regs[19] = 4294967295ULL;
    goto L_1d2884;
L_1d2a44:
    cpu->regs[30] = PB_BASE + 0x1d2a48ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe97e4ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1d27f8;
L_1d2a50:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2936));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = PB_BASE + 0x291000ULL;
    cpu->regs[2] = cpu->regs[2] + 2912ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1d2a6cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    goto L_1d28b8;
L_1d2a78:
    cpu->regs[3] = PB_BASE + 0x291000ULL;
    cpu->regs[5] = PB_BASE + 0x291000ULL;
    cpu->regs[3] = cpu->regs[3] + 2896ULL;
    cpu->regs[5] = cpu->regs[5] + 2904ULL;
    goto L_1d299c;
L_1d2a8c:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1d2a9cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d2ad0ULL);
    if ((cpu->regs[0])==0) goto L_1d2ac0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d2ab4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d2ac8;
L_1d2ab4:
    cpu->regs[0] = 0ULL;
L_1d2ab8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1d2ac0:
    cpu->regs[0] = 4294967295ULL;
    goto L_1d2ab8;
L_1d2ac8:
    cpu->regs[30] = PB_BASE + 0x1d2accULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2ab4;
L_1d2ad0:
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[23])==0) goto L_1d2c3c;
L_1d2b10:
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_1d2c54;
    cpu->regs[30] = PB_BASE + 0x1d2b18ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d2c4c;
L_1d2b20:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d2b28ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d2ce0ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 0));
    cpu->regs[24] = SP;
    cpu->regs[19] = 0ULL;
L_1d2b34:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 72));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LE) goto L_1d2b94;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 48));
    cpu->regs[4] = cpu->regs[24];
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 104));
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d2b5cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1fda44ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2b8c;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 96));
    cpu->regs[20] = cpu->regs[20] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[2] = cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 24));
    if (((cpu->regs[0] >> 4) & 1)) goto L_1d2c5c;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[0] = cpu->regs[23];
    if ((cpu->regs[2])==0) goto L_1d2c14;
    cpu->regs[30] = PB_BASE + 0x1d2b88ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d2c74;
L_1d2b8c:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    goto L_1d2b34;
L_1d2b94:
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_1d2ba4;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1d2ba0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1df090ULL);
    if ((cpu->regs[0])!=0) goto L_1d2c84;
L_1d2ba4:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d2bb4;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_1d2bb4:
    cpu->regs[19] = cpu->regs[23];
L_1d2bb8:
    if ((cpu->regs[26])==0) goto L_1d2bd8;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d2bd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d2bd8;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1d2bd8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d2bd8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d2cd4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1d2c14:
    cpu->regs[30] = PB_BASE + 0x1d2c18ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x144960ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2b8c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d2c2cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2c74;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1d2c38ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1d2b34;
L_1d2c3c:
    cpu->regs[30] = PB_BASE + 0x1d2c40ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[22] + 40), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1d2b10;
L_1d2c4c:
    cpu->regs[19] = 0ULL;
    goto L_1d2bd8;
L_1d2c54:
    cpu->regs[26] = 0ULL;
    goto L_1d2b20;
L_1d2c5c:
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_1d2b8c;
    PB_LDR(cpu->regs[2], (SP + 0));
    if ((cpu->regs[2])==0) goto L_1d2b8c;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1d2c70ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2b8c;
L_1d2c74:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d2c80ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1d2bd8;
L_1d2c84:
    cpu->regs[30] = PB_BASE + 0x1d2c88ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d2c74;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1d2c9cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x26bf44ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d2cb4;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1d2cb0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x26bf44ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d2bb8;
L_1d2cb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d2c74;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d2c74;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d2cd0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d2c74;
L_1d2cd4:
    cpu->regs[30] = PB_BASE + 0x1d2cd8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
L_1d2ce0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    cpu->regs[3] = cpu->regs[2] + 192ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 1);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d2cfc;
L_1d2cf8:
    return;
L_1d2cfc:
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 192));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(149ULL)));
    if (FLAG_NE) goto L_1d2cf8;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3680));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_NE) goto L_1d2cf8;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 72));
    cpu->regs[1] = 0ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[2] + 72));
    PB_LDRW(cpu->regs[8], (cpu->regs[2] + 88));
    cpu->regs[6] = cpu->regs[6] + 24ULL;
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - cpu->regs[8]));
L_1d2d38:
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_1d2d68;
    PB_LDR(cpu->regs[7], (cpu->regs[6] + (cpu->regs[1] << 3)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] + cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3);
    PB_LDRW(cpu->regs[4], (cpu->regs[7] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_EQ) goto L_1d2d60;
    PB_STRW((cpu->regs[7] + 0), cpu->regs[4]);
L_1d2d60:
    PB_STR((cpu->regs[2] + 72), cpu->regs[7]);
    goto L_1d2d38;
L_1d2d68:
    PB_STR((cpu->regs[0] + 56), cpu->regs[3]);
    return;
}
