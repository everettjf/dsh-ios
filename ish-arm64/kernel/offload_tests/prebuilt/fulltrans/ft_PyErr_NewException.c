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

void ft_PyErr_NewException(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = 46ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x191678ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7b140ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1917a4;
    PB_STR((SP + 64), cpu->regs[25]);
    if ((cpu->regs[19])==0) goto L_191768;
    if ((cpu->regs[24])!=0) goto L_191778;
L_19168c:
    cpu->regs[30] = PB_BASE + 0x191690ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1917ec;
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[25] = cpu->regs[0];
L_1916a0:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = 30600ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1916b8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdd250ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_191794;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1917fc;
    cpu->regs[1] = cpu->regs[21] - cpu->regs[22];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1916d0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1ec0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_191794;
    cpu->regs[0] = 30600ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1916ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1917e0;
L_1916f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_191780;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x191708ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe13e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1917d8;
L_191710:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3216));
    cpu->regs[2] = cpu->regs[21] + 1ULL;
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1392ULL;
    cpu->regs[30] = PB_BASE + 0x191730ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe6d90ULL);
    cpu->regs[21] = cpu->regs[0];
L_191734:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x19173cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x191744ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x19174cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
L_191750:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_191768:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3640));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    if ((cpu->regs[24])==0) goto L_19168c;
L_191778:
    cpu->regs[25] = 0ULL;
    goto L_1916a0;
L_191780:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_191710;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_191710;
L_191794:
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_191734;
L_1917a4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2936));
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1917c0ULL; PB_CALL(11, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[2] = cpu->regs[2] + 1344ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1917d4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_191750;
L_1917d8:
    cpu->regs[21] = 0ULL;
    goto L_191734;
L_1917e0:
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_191734;
L_1917ec:
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = 0ULL;
    goto L_191734;
L_1917fc:
    cpu->regs[20] = 0ULL;
    goto L_1916f0;
    SP = SP - 240ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2680));
    cpu->regs[6] = SP + 64ULL;
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    cpu->regs[4] = SP + 72ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2640));
    PB_STR((SP + 160), cpu->regs[19]); PB_STR((SP + 160) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 136), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[2] = SP + 80ULL;
    cpu->regs[1] = cpu->regs[1] + 1576ULL;
    cpu->regs[30] = PB_BASE + 0x191860ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1923c0;
    PB_STR((SP + 176), cpu->regs[21]); PB_STR((SP + 176) + 8, cpu->regs[22]);
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[24], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_STR((SP + 208), cpu->regs[25]); PB_STR((SP + 208) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[25], (SP + 80));
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 16));
    if ((cpu->regs[21])!=0) goto L_191d84;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3488));
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x191890ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe13e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19262c;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3488));
L_1918a0:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1918a8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1920a4;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[4] = 33280ULL;
    PB_STR((SP + 224), cpu->regs[27]); PB_STR((SP + 224) + 8, cpu->regs[28]);
    cpu->regs[1] = cpu->regs[20] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1918c8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_191f0c;
    cpu->regs[30] = PB_BASE + 0x1918d4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1920a0;
    PB_LDR(cpu->regs[26], (cpu->regs[21] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[21] + 288));
    if ((cpu->regs[26])!=0) goto L_191e70;
L_1918e8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[23])!=0) goto L_191fa8;
L_1918fc:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    FLAG_CMP(cpu->regs[5], 0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[28] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x191914ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1920a0;
    cpu->regs[4] = 0ULL;
L_191920:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[7] = cpu->regs[19] + 416ULL;
    cpu->regs[2] = cpu->regs[19] + 448ULL;
    cpu->regs[3] = cpu->regs[19] + 760ULL;
    cpu->regs[6] = cpu->regs[19] + 736ULL;
    cpu->regs[1] = cpu->regs[19] + 840ULL;
    cpu->regs[5] = 17920ULL;
    PB_STR((cpu->regs[19] + 80), cpu->regs[7]);
    PB_STR((cpu->regs[19] + 96), cpu->regs[2]); PB_STR((cpu->regs[19] + 96) + 8, cpu->regs[3]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_STR((cpu->regs[19] + 112), cpu->regs[6]);
    PB_STR((cpu->regs[19] + 160), cpu->regs[1]); PB_STR((cpu->regs[19] + 160) + 8, cpu->regs[5]);
    if (FLAG_EQ) goto L_191958;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_191958:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[19] + 336), cpu->regs[22]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_191e08;
L_191968:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3280));
    cpu->regs[6] = PB_BASE + 0x13e000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2376));
    cpu->regs[6] = cpu->regs[6] + 4032ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[3] = PB_BASE + 0x142000ULL;
    cpu->regs[5] = PB_BASE + 0x1eb000ULL;
    cpu->regs[3] = cpu->regs[3] + 2240ULL;
    cpu->regs[5] = cpu->regs[5] + 300ULL;
    PB_STR((cpu->regs[19] + 48), cpu->regs[6]);
    PB_STR((cpu->regs[19] + 184), cpu->regs[3]); PB_STR((cpu->regs[19] + 184) + 8, cpu->regs[5]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_STR((cpu->regs[19] + 256), cpu->regs[21]);
    PB_STR((cpu->regs[19] + 304), cpu->regs[2]);
    PB_STR((cpu->regs[19] + 320), cpu->regs[1]);
    if (FLAG_NE) goto L_191f04;
L_1919b0:
    cpu->regs[2] = cpu->regs[19] + 1024ULL;
    PB_STR((cpu->regs[19] + 856), cpu->regs[25]);
    cpu->regs[23] = SP + 104ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[23];
    PB_STR((cpu->regs[2] + -136), 0ULL); PB_STR((cpu->regs[2] + -136) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 264), cpu->regs[24]);
    PB_STR((cpu->regs[19] + 864), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1919d4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_192508;
    cpu->regs[30] = PB_BASE + 0x1919e0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 104));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_192748;
    cpu->regs[15] = 30600ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1919f8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[15];
    cpu->regs[30] = PB_BASE + 0x191a04ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdd250ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_192508;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1922b0;
L_191a10:
    cpu->regs[14] = 31664ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191a1cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[14];
    cpu->regs[30] = PB_BASE + 0x191a28ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_191ee0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_192728;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_191a48;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_191a48:
    cpu->regs[11] = 31664ULL;
    PB_STR((cpu->regs[19] + 872), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[20] + cpu->regs[11];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x191a5cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_192508;
L_191a60:
    cpu->regs[10] = 27680ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191a6cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[1] = cpu->regs[20] + cpu->regs[10];
    cpu->regs[30] = PB_BASE + 0x191a74ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_191e10;
    cpu->regs[30] = PB_BASE + 0x191a7cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_192508;
L_191a80:
    cpu->regs[9] = 30912ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191a8cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x191a98ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_192258;
    cpu->regs[30] = PB_BASE + 0x191aa0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_192508;
L_191aa4:
    cpu->regs[0] = 29336ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191ab4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x192860ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_192508;
    cpu->regs[7] = 26768ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x191accULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x192860ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_192508;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 864));
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 32));
    if ((cpu->regs[0])!=0) goto L_191e8c;
L_191ae0:
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_191af8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[1] = 18446744073709551584ULL;
    PB_STR((cpu->regs[19] + 208), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | 8ULL;
    PB_STR((cpu->regs[19] + 168), cpu->regs[0]);
L_191af8:
    if ((((uint32_t)(cpu->regs[28])))==0) goto L_191b10;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[1] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 288), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | 16ULL;
    PB_STR((cpu->regs[19] + 168), cpu->regs[0]);
L_191b10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    PB_STR((cpu->regs[19] + 32), cpu->regs[24]); PB_STR((cpu->regs[19] + 32) + 8, cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191b20ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f68ULL);
    PB_STR((cpu->regs[19] + 240), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 208));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 288));
    if ((cpu->regs[1])==0) goto L_191df0;
    if ((cpu->regs[0])==0) goto L_1920b4;
    cpu->regs[0] = PB_BASE + 0x51d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    cpu->regs[0] = cpu->regs[0] + 1912ULL;
    PB_STR((cpu->regs[19] + 248), cpu->regs[0]);
L_191b44:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 64));
    if ((cpu->regs[0])!=0) goto L_191b54;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 144));
    if ((cpu->regs[0])==0) goto L_192684;
L_191b54:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 72));
    if ((cpu->regs[0])!=0) goto L_191b64;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 152));
    if ((cpu->regs[0])==0) goto L_192694;
L_191b64:
    cpu->regs[6] = 26832ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191b70ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x191b7cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_1921e4;
    cpu->regs[30] = PB_BASE + 0x191b84ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_192508;
L_191b88:
    cpu->regs[5] = 26944ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191b94ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x191ba0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_1923c8;
    cpu->regs[30] = PB_BASE + 0x191ba8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_192508;
L_191bac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191bb4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_192508;
    cpu->regs[0] = PB_BASE + 0x512000ULL;
    cpu->regs[1] = cpu->regs[0] + 2704ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2704));
    if ((cpu->regs[0])==0) goto L_191be0;
L_191bcc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191bd4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xecac4ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_191bcc;
L_191be0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191be8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[30] = PB_BASE + 0x191becULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192508;
    cpu->regs[2] = 32944ULL;
    cpu->regs[25] = SP + 96ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[2];
    cpu->regs[24] = SP + 88ULL;
    cpu->regs[27] = cpu->tls_ptr;
    PB_STR((SP + 8), cpu->regs[0]);
    PB_STR((SP + 88), 0ULL);
    goto L_191c68;
L_191c14:
    PB_LDR(cpu->regs[26], (SP + 104));
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 8));
    cpu->regs[30] = PB_BASE + 0x191c24ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_191c4c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 272));
    if ((cpu->regs[4])==0) goto L_191f3c;
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 8));
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x191c44ULL; PB_CALL(46, cpu, tlb, cpu->regs[4]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_191f48;
L_191c4c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x191c5cULL; PB_CALL(47, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[27] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_191eb8;
L_191c68:
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x191c80ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_191c14;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_191ca0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_191ca0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x191ca0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_191ca0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2544));
    cpu->regs[1] = SP + 112ULL;
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x191cb8ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x192928ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192508;
    cpu->regs[1] = 29336ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x191cccULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_191cec;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_191cec;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x191cecULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_191cec:
    if ((cpu->regs[20])==0) goto L_192508;
    PB_LDR(cpu->regs[3], (SP + 16));
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x191d04ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x192f90ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_191d24;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_191d24;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x191d24ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_191d24:
    if ((cpu->regs[21])==0) goto L_192508;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1926bc;
L_191d30:
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
L_191d34:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_191d48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1926a4;
L_191d48:
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
L_191d54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 136));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_192404;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 160)); PB_LDR(cpu->regs[20], (SP + 160) + 8);
    SP = SP + 240ULL;
    return;
L_191d84:
    cpu->regs[26] = cpu->regs[22] + 24ULL;
    cpu->regs[23] = 0ULL;
L_191d8c:
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_LE) goto L_191dac;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + (cpu->regs[23] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1925d8;
L_191da4:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_191d8c;
L_191dac:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191db8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x18e1e4ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19262c;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_19238c;
L_191dc8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x191dd0ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x18e280ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19262c;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_191de8;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_191de8:
    cpu->regs[19] = cpu->regs[23];
    goto L_1918a0;
L_191df0:
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_192378;
L_191df8:
    PB_STR((cpu->regs[19] + 248), cpu->regs[1]);
    FLAG_CMP(cpu->regs[26], 0ULL);
    if (FLAG_LE) goto L_191b64;
    goto L_191b44;
L_191e08:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_191968;
L_191e10:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_191a80;
    cpu->regs[30] = PB_BASE + 0x191e20ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192508;
    cpu->regs[30] = PB_BASE + 0x191e2cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[25] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x191e38ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xd8e60ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192640;
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_HI) goto L_191e7c;
    if (FLAG_HS) goto L_191e58;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[25];
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LO) goto L_191e88;
L_191e58:
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x191e68ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_STR((cpu->regs[19] + 176), cpu->regs[0]);
    goto L_191a80;
L_191e70:
    cpu->regs[26] = 0ULL;
    cpu->regs[27] = 0ULL;
    goto L_1918fc;
L_191e7c:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[25];
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_HS) goto L_191e58;
L_191e88:
    __builtin_trap();
L_191e8c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x191e94ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe1f68ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 864));
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
L_191ea4:
    cpu->regs[2] = cpu->regs[24] + (cpu->regs[1] << 3);
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_GT) goto L_192218;
    cpu->regs[24] = cpu->regs[2];
    goto L_191ae0;
L_191eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_191c68;
L_191ec0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_192508;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_192508;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x191edcULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_192508;
L_191ee0:
    cpu->regs[30] = PB_BASE + 0x191ee4ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_192508;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 856));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_191efc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_191efc:
    PB_STR((cpu->regs[19] + 872), cpu->regs[1]);
    goto L_191a60;
L_191f04:
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
    goto L_1919b0;
L_191f0c:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 28) & 1)) goto L_192418;
    cpu->regs[30] = PB_BASE + 0x191f1cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[23] = cpu->regs[0];
L_191f20:
    if ((cpu->regs[23])==0) goto L_1920a0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 208));
    PB_LDR(cpu->regs[26], (cpu->regs[23] + 16));
    PB_LDR(cpu->regs[5], (cpu->regs[21] + 288));
    if ((cpu->regs[0])==0) goto L_1918e8;
    PB_STRW((SP + 8), 0ULL);
    goto L_191fac;
L_191f3c:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1925d0;
L_191f48:
    PB_LDR(cpu->regs[2], (SP + 96));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x191f5cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1987c8ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_191f84;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_191f84;
    cpu->regs[0] = cpu->regs[28];
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x191f80ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
L_191f84:
    if ((cpu->regs[1])==0) goto L_1926d8;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_191c68;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_191c68;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x191fa4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_191c68;
L_191fa8:
    PB_STRW((SP + 8), cpu->regs[0]);
L_191fac:
    FLAG_CMP(cpu->regs[26], 0ULL);
    if (FLAG_GT) goto L_1922e4;
    cpu->regs[27] = 0ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[3] = 0ULL;
L_191fc0:
    FLAG_CMP(cpu->regs[3], cpu->regs[26]);
    if (FLAG_LT) goto L_192160;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[28]));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[27]));
    cpu->regs[0] = cpu->regs[26] - cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x191fdcULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_192474;
    PB_LDR(cpu->regs[5], (SP + 40));
    PB_STR((SP + 24), 0ULL);
    PB_STR((SP + 48), 0ULL);
L_191ff0:
    PB_LDR(cpu->regs[0], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_LT) goto L_1920c4;
    PB_LDR(cpu->regs[26], (SP + 32));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x19200cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x190310ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1925a8;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x19201cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdc740ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (SP + 24));
    if (((cpu->regs[1] >> 31) & 1)) goto L_192048;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[26];
    if ((cpu->regs[1])!=0) goto L_192048;
    PB_STR((SP + 24), cpu->regs[4]); PB_STR((SP + 24) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x192044ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[4], (SP + 24)); PB_LDR(cpu->regs[5], (SP + 24) + 8);
L_192048:
    PB_STR((SP + 24), cpu->regs[4]); PB_STR((SP + 24) + 8, cpu->regs[5]);
    if ((cpu->regs[4])==0) goto L_192474;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x192058ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[4], (SP + 24)); PB_LDR(cpu->regs[5], (SP + 24) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    FLAG_CMP(cpu->regs[2], 1ULL);
    PB_LDR(cpu->regs[26], (cpu->regs[4] + 16));
    if (FLAG_GT) goto L_1922f8;
L_19206c:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[26];
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x192080ULL; PB_CALL(73, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_191920;
L_19208c:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1920a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1924b8;
L_1920a0:
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
L_1920a4:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1920b0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_191d34;
L_1920b4:
    cpu->regs[1] = PB_BASE + 0x51d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    cpu->regs[1] = cpu->regs[1] + 1832ULL;
    goto L_191df8;
L_1920c4:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_STR((SP + 40), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_192144;
L_1920d8:
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_192358;
L_1920dc:
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x1920ecULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x129360ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1925a8;
    cpu->regs[1] = cpu->regs[0];
    PB_STR((SP + 40), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[3], (SP + 48));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    cpu->regs[0] = cpu->regs[24];
    PB_STR((cpu->regs[4] + (cpu->regs[3] << 3)), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x192114ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdd250ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1925a8;
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[5], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_19253c;
L_192128:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 48), cpu->regs[0]);
L_192134:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    goto L_191ff0;
L_192144:
    cpu->regs[1] = 27464ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x192154ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[5], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1920d8;
    goto L_192134;
L_192160:
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + (cpu->regs[3] << 3)));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_192704;
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 24), cpu->regs[2]); PB_STR((SP + 24) + 8, cpu->regs[3]);
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x192184ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1ac3a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1924c8;
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[3] = 27464ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x19219cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[5], (SP + 40));
    PB_LDR(cpu->regs[2], (SP + 24)); PB_LDR(cpu->regs[3], (SP + 24) + 8);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_192430;
L_1921a8:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = 34200ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[2];
    PB_STR((SP + 24), cpu->regs[3]); PB_STR((SP + 24) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x1921bcULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[3], (SP + 24)); PB_LDR(cpu->regs[5], (SP + 24) + 8);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1921cc;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_191fc0;
L_1921cc:
    PB_LDRW(cpu->regs[0], (SP + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_19247c;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_19247c;
    PB_LDRW(cpu->regs[27], (SP + 8));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_191fc0;
L_1921e4:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2872));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_192764;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x192200ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x1ac5e0ULL);
    cpu->regs[4] = 26832ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x192210ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_191b88;
    goto L_192508;
L_192218:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 864));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_STR((SP + 24), cpu->regs[3]); PB_STR((SP + 24) + 8, cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x192230ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1947a0ULL);
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_192508;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = 16ULL;
    PB_LDR(cpu->regs[3], (SP + 24)); PB_LDR(cpu->regs[2], (SP + 24) + 8);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[25] = cpu->regs[25] + 40ULL;
    PB_STRW((cpu->regs[25] + -32), cpu->regs[0]);
    PB_STR((cpu->regs[25] + -24), cpu->regs[2]);
    goto L_191ea4;
L_192258:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3680));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_191aa4;
    cpu->regs[30] = PB_BASE + 0x192270ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x18d670ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192508;
    cpu->regs[8] = 30912ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[8];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x19228cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_19249c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_191aa4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_191aa4;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1922acULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_191aa4;
L_1922b0:
    cpu->regs[30] = PB_BASE + 0x1922b4ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x144470ULL);
    if ((cpu->regs[0])==0) goto L_191a10;
    cpu->regs[13] = 30760ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[13];
    cpu->regs[30] = PB_BASE + 0x1922c4ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1926f8;
    cpu->regs[12] = 30600ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[12];
    cpu->regs[30] = PB_BASE + 0x1922dcULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_191a10;
    goto L_192508;
L_1922e4:
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 40));
    if ((cpu->regs[3])!=0) goto L_192648;
    cpu->regs[27] = 0ULL;
    cpu->regs[28] = 0ULL;
    goto L_191fc0;
L_1922f8:
    if ((cpu->regs[5])!=0) goto L_19244c;
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_19244c;
L_192300:
    cpu->regs[3] = cpu->regs[22] + 24ULL;
    cpu->regs[0] = 0ULL;
L_192308:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + (cpu->regs[0] << 3)));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_EQ) goto L_192348;
    if ((cpu->regs[5])!=0) goto L_192440;
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_192328;
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 288));
    FLAG_CMP(cpu->regs[6], 0ULL);
    cpu->regs[28] = (FLAG_NE) ? 1 : 0;
L_192328:
    PB_LDRW(cpu->regs[6], (SP + 8));
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_1923fc;
L_192330:
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_192428;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 208));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[27] = (FLAG_NE) ? 1 : 0;
    if ((cpu->regs[5])!=0) goto L_1924e8;
L_192344:
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_1924e8;
L_192348:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_192308;
    goto L_19206c;
L_192358:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = 34200ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[30];
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x19236cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[5], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1920dc;
    goto L_192134;
L_192378:
    cpu->regs[0] = PB_BASE + 0x51d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    cpu->regs[0] = cpu->regs[0] + 2032ULL;
    PB_STR((cpu->regs[19] + 248), cpu->regs[0]);
    goto L_191b44;
L_19238c:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 312));
    cpu->regs[1] = PB_BASE + 0x191000ULL;
    cpu->regs[1] = cpu->regs[1] + 2052ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_EQ) goto L_191dc8;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1923acULL; PB_CALL(91, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
    if ((cpu->regs[0])!=0) goto L_191d54;
L_1923c0:
    cpu->regs[19] = 0ULL;
    goto L_191d54;
L_1923c8:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2872));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_1924f0;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1923e4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x1ac5e0ULL);
    cpu->regs[3] = 26944ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1923f4ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_191bac;
    goto L_192508;
L_1923fc:
    if ((((uint32_t)(cpu->regs[28])))==0) goto L_192348;
    goto L_19206c;
L_192404:
    PB_STR((SP + 176), cpu->regs[21]); PB_STR((SP + 176) + 8, cpu->regs[22]);
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    PB_STR((SP + 208), cpu->regs[25]); PB_STR((SP + 208) + 8, cpu->regs[26]);
    PB_STR((SP + 224), cpu->regs[27]); PB_STR((SP + 224) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x192418ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x7c170ULL);
L_192418:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x192420ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe13e0ULL);
    cpu->regs[23] = cpu->regs[0];
    goto L_191f20;
L_192428:
    if ((cpu->regs[5])==0) goto L_192344;
    goto L_19206c;
L_192430:
    if ((cpu->regs[5])!=0) goto L_19245c;
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_19245c;
    cpu->regs[28] = 1ULL;
    goto L_1921a8;
L_192440:
    PB_LDRW(cpu->regs[6], (SP + 8));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_192330;
    goto L_19206c;
L_19244c:
    PB_LDRW(cpu->regs[0], (SP + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_19206c;
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_19206c;
    goto L_192300;
L_19245c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192474ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_192474:
    cpu->regs[4] = cpu->regs[23];
    goto L_19208c;
L_19247c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192494ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[4] = cpu->regs[23];
    goto L_19208c;
L_19249c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_192508;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_192508;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1924b4ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_192508;
L_1924b8:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1924c0ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_1920a4;
L_1924c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1776ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1924e0ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[4] = cpu->regs[23];
    goto L_19208c;
L_1924e8:
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_19206c;
    goto L_192348;
L_1924f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192508ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x11f220ULL);
L_192508:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_19251c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_192528;
L_19251c:
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    cpu->regs[19] = 0ULL;
    goto L_191d34;
L_192528:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x192534ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_191d34;
L_19253c:
    cpu->regs[18] = 31664ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[18];
    cpu->regs[30] = PB_BASE + 0x19254cULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[5], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_192128;
    cpu->regs[17] = 26832ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[17];
    cpu->regs[30] = PB_BASE + 0x192568ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[5], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_192128;
    cpu->regs[16] = 26944ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[16];
    cpu->regs[30] = PB_BASE + 0x192584ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[5], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_192128;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1904ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1925a8ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1925a8:
    PB_LDR(cpu->regs[1], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_192474;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_192474;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1925c8ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[4] = cpu->regs[23];
    goto L_19208c;
L_1925d0:
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
    goto L_191f48;
L_1925d8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[5] = 30656ULL;
    cpu->regs[2] = SP + 104ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1925f0ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x112290ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_19262c;
    PB_LDR(cpu->regs[0], (SP + 104));
    if ((cpu->regs[0])==0) goto L_191da4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1600ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192614ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_19262c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_19266c;
L_19262c:
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
    goto L_191d54;
L_192640:
    cpu->regs[30] = PB_BASE + 0x192644ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_192508;
L_192648:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[1] = cpu->regs[1] + 1672ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192664ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[4] = cpu->regs[23];
    goto L_19208c;
L_19266c:
    cpu->regs[30] = PB_BASE + 0x192670ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
    goto L_191d54;
L_192684:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 4048));
    PB_STR((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_191b54;
L_192694:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3040));
    PB_STR((cpu->regs[19] + 152), cpu->regs[0]);
    goto L_191b64;
L_1926a4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1926acULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
    goto L_191d54;
L_1926bc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_191d30;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1926d0ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_191d34;
L_1926d8:
    PB_LDR(cpu->regs[2], (SP + 96)); PB_LDR(cpu->regs[1], (SP + 96) + 8);
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[0] + 2152ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[30] = PB_BASE + 0x1926f4ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x24c4e0ULL);
    goto L_191ec0;
L_1926f8:
    cpu->regs[30] = PB_BASE + 0x1926fcULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_191a10;
    goto L_192508;
L_192704:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[1] = cpu->regs[1] + 1728ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192720ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[4] = cpu->regs[23];
    goto L_19208c;
L_192728:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 2000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192744ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_192508;
L_192748:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192760ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_192508;
L_192764:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2040ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x19277cULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_192508;
}
