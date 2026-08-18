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

void ft__PyDict_DelItem_KnownHash(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 168));
    if (!((cpu->regs[3] >> 29) & 1)) goto L_198130;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x198028ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdd360ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_1980d4;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1980cc;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (SP + 16));
    if ((cpu->regs[23])==0) goto L_1980c8;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x19805cULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    PB_LDRB(cpu->regs[24], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16));
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1980e4;
    cpu->regs[5] = cpu->regs[5] + (64ULL << 12);
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 8576));
    cpu->regs[4] = cpu->regs[4] + 256ULL;
    PB_STR((cpu->regs[5] + 8576), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x198090ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x114640ULL);
L_198090:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    cpu->regs[0] = 0ULL;
L_198098:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1980dc;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1980c8:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_1980cc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1980d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1bdee0ULL);
L_1980d4:
    cpu->regs[0] = 4294967295ULL;
    goto L_198098;
L_1980dc:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1980e4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1980e4:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = 2ULL;
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x198100ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x9b684ULL);
    PB_LDR(cpu->regs[5], (SP + 8));
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[5] = cpu->regs[5] + (64ULL << 12);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 8576));
    cpu->regs[4] = cpu->regs[4] + 256ULL;
    PB_STR((cpu->regs[5] + 8576), cpu->regs[4]);
    cpu->regs[4] = cpu->regs[24] | cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x19812cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x114640ULL);
    goto L_198090;
L_198130:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1995ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x198140ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_198098;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[4] = 1ULL;
    cpu->regs[29] = SP;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[7] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[0] & 63);
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[3] = cpu->regs[4] & cpu->regs[1];
L_198170:
    cpu->regs[8] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x198180ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18cc20ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[7]);
    if (FLAG_NE) goto L_198194;
L_198188:
    cpu->regs[0] = cpu->regs[8];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_198194:
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[3] << 2);
    cpu->regs[6] = cpu->regs[6] >> 5;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1981b4;
    cpu->regs[3] = cpu->regs[3] + cpu->regs[6];
    cpu->regs[3] = cpu->regs[3] & cpu->regs[4];
    goto L_198170;
L_1981b4:
    cpu->regs[8] = cpu->regs[0];
    goto L_198188;
    /* nop */
    cpu->regs[3] = 21845ULL;
    cpu->regs[4] = 64ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x1ULL & 0xffff) << 16);
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[1] << 1);
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[1] + 1ULL;
    cpu->regs[5] = 17ULL;
    cpu->regs[29] = SP;
    cpu->regs[3] = (uint64_t)((int64_t)cpu->regs[3] >> 1);
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[3] = cpu->regs[3] | 8ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[3] = cpu->regs[3] | 7ULL;
    cpu->regs[3] = (((uint64_t)(cpu->regs[3])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[3])));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - cpu->regs[3]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & 255ULL));
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[4] : cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x198210ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xde420ULL);
    if ((cpu->regs[0])==0) goto L_198234;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xd9580ULL); return; };
L_198234:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_1984bc;
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = cpu->regs[3];
    FLAG_CMP(cpu->regs[3], 4ULL);
    if (FLAG_HI) goto L_1984c8;
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1984c8;
L_198290:
    if ((cpu->regs[21])==0) goto L_198504;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 0));
    if ((cpu->regs[20])==0) goto L_198440;
    cpu->regs[21] = cpu->regs[21] - 1ULL; FLAG_CMP(cpu->regs[21], 0);
    if (FLAG_NE) goto L_198440;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_EQ) goto L_198558;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[23] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[24] = 0ULL;
L_1982c4:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1982d4;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_1982d4:
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1982dcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[23])!=0) goto L_198490;
L_1982e4:
    PB_STR((cpu->regs[19] + 24), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x1982ecULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[24])!=0) goto L_19856c;
L_1982f4:
    PB_STR((cpu->regs[19] + 32), cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1982fcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    cpu->regs[30] = PB_BASE + 0x198308ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    cpu->regs[30] = PB_BASE + 0x198314ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 16), 0ULL);
    PB_STRW((cpu->regs[19] + 56), 0ULL);
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_198580;
    if ((cpu->regs[20])==0) goto L_198368;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[4] = 27680ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x198348ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1984fc;
    PB_LDR(cpu->regs[21], (SP + 16));
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_NE) goto L_1983c4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    PB_STR((SP + 16), 0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_198540;
L_198368:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3192));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_198520;
L_19837c:
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x19838cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL);
L_19838c:
    cpu->regs[0] = 0ULL;
L_198390:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1984b0;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_1983c4:
    if ((cpu->regs[21])==0) goto L_198368;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 56), cpu->regs[0]);
L_1983d0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3192));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_19837c;
L_1983e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 27680ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x198400ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe28a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_198418;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_198598;
L_198418:
    if (!((cpu->regs[20] >> 31) & 1)) goto L_19838c;
L_19841c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1984fc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x198434ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1984fc;
    cpu->regs[30] = PB_BASE + 0x19843cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_19838c;
L_198440:
    PB_LDR(cpu->regs[23], (cpu->regs[1] + 8));
    if ((cpu->regs[23])==0) goto L_198450;
    cpu->regs[21] = cpu->regs[21] - 1ULL; FLAG_CMP(cpu->regs[21], 0);
    if (FLAG_EQ) goto L_1984a4;
L_198450:
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 16));
    if ((cpu->regs[24])==0) goto L_198460;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_1984b4;
L_198460:
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 24));
L_198464:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    cpu->regs[20] = (FLAG_NE) ? cpu->regs[20] : 0ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[22]);
    cpu->regs[23] = (FLAG_NE) ? cpu->regs[23] : 0ULL;
L_19847c:
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    cpu->regs[24] = (FLAG_NE) ? cpu->regs[24] : 0ULL;
L_198484:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[20])!=0) goto L_1982c4;
    goto L_1982d4;
L_198490:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1982e4;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    goto L_1982e4;
L_1984a4:
    cpu->regs[21] = 0ULL;
    cpu->regs[24] = 0ULL;
    goto L_198464;
L_1984b0:
    cpu->regs[30] = PB_BASE + 0x1984b4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1984b4:
    cpu->regs[21] = 0ULL;
    goto L_198464;
L_1984bc:
    PB_LDR(cpu->regs[21], (cpu->regs[2] + 16));
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = cpu->regs[3] + cpu->regs[21];
L_1984c8:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x51d000ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[4] + 3600ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 2232ULL;
    cpu->regs[6] = 4ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1984f4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_198290;
L_1984fc:
    cpu->regs[0] = 4294967295ULL;
    goto L_198390;
L_198504:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    cpu->regs[21] = 0ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_19847c;
L_198520:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_198530;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_198530:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    PB_STR((SP + 16), cpu->regs[22]);
    goto L_1983e4;
L_198540:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_198368;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x198554ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_198368;
L_198558:
    cpu->regs[20] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[24] = 0ULL;
    goto L_198484;
L_19856c:
    PB_LDRW(cpu->regs[1], (cpu->regs[24] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1982f4;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[1]);
    goto L_1982f4;
L_198580:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_198590;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_198590:
    PB_STR((SP + 16), cpu->regs[21]);
    goto L_1983d0;
L_198598:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1985a0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if (!((cpu->regs[20] >> 31) & 1)) goto L_19838c;
    goto L_19841c;
    cpu->regs[3] = cpu->regs[0];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_1985d8;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 168));
    FLAG_CMP((cpu->regs[4]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_1985d8:
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 24));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 24));
    cpu->regs[1] = cpu->regs[1] + 352ULL;
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[30] = PB_BASE + 0x1985f8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_198620;
    /* nop */
    /* nop */
    /* nop */
L_198620:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x198644ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x19878cULL);
    if ((cpu->regs[0])==0) goto L_198768;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_198670;
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
L_198670:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[22], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_19874c;
L_19867c:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_19869c;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 32));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[20] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[1];
L_19869c:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_198728;
    PB_LDR(cpu->regs[4], (cpu->regs[21] + 40));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[4] : cpu->regs[0];
L_1986c0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1986d8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1987c8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_198734;
L_1986e4:
    if ((cpu->regs[19])==0) goto L_198764;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3192));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1986f8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_198784;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 48));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[1])!=0) goto L_198770;
L_198708:
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x198710ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
L_198714:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_198728:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    goto L_1986c0;
L_198734:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1986e4;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x198748ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1986e4;
L_19874c:
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 24));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[22], 0ULL);
    cpu->regs[22] = (FLAG_NE) ? cpu->regs[22] : cpu->regs[1];
    goto L_19867c;
L_198764:
    PB_LDR(cpu->regs[23], (SP + 48));
L_198768:
    cpu->regs[19] = 0ULL;
    goto L_198714;
L_198770:
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_198708;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    goto L_198708;
L_198784:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_198714;
}
