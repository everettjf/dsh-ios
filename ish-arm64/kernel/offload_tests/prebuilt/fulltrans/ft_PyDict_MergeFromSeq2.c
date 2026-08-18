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

void ft_PyDict_MergeFromSeq2(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x15b7c0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_15b9b0;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[24] = 0ULL;
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_15b9b8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[25] = PB_BASE + 0x299000ULL;
    cpu->regs[25] = cpu->regs[25] + 240ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x15b7f0ULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15b8f4;
    /* nop */
    /* nop */
L_15b800:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x15b808ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15ba28;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 25) & 1)) goto L_15b93c;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_NE) goto L_15b9fc;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[26], (cpu->regs[19] + 24) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_15b958;
L_15b834:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15b964;
L_15b844:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_15ba54;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15b934;
L_15b85c:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_15b86c;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
L_15b86c:
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15b87cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xddf8cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15ba64;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15b898;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15ba1c;
L_15b898:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15b96c;
L_15b8a0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15b8b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15baa4;
L_15b8b4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15b8d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15b8d8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15b8d8ULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
L_15b8d8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x15b8ecULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_15b800;
L_15b8f4:
    cpu->regs[30] = PB_BASE + 0x15b8f8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe8090ULL);
    cpu->regs[30] = PB_BASE + 0x15b8fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_15b990;
    cpu->regs[19] = 0ULL;
L_15b904:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15b918;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15b984;
L_15b918:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_15b924:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_15b934:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_15b85c;
L_15b93c:
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_NE) goto L_15b9fc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[26], (cpu->regs[0] + 0) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15b834;
L_15b958:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_15b844;
L_15b964:
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_15b844;
L_15b96c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15b8a0;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15b980ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15b8a0;
L_15b984:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15b98cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15b918;
L_15b990:
    cpu->regs[20] = 0ULL;
L_15b994:
    cpu->regs[19] = 0ULL;
L_15b998:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x15b9a0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x15b9acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_15b904;
L_15b9b0:
    cpu->regs[0] = 4294967295ULL;
    goto L_15b924;
L_15b9b8:
    cpu->regs[26] = PB_BASE + 0x299000ULL;
    cpu->regs[26] = cpu->regs[26] + 240ULL;
L_15b9c0:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x15b9d0ULL; PB_CALL(13, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15b8f4;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15b9e0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15ba28;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_15bab0;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_15bb48;
L_15b9fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2712ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15ba18ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_15b998;
L_15ba1c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15ba24ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15b898;
L_15ba28:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x15ba38ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_15b994;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2640ULL;
    cpu->regs[30] = PB_BASE + 0x15ba50ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_15b994;
L_15ba54:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1882ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x15ba64ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_15ba64:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15ba78;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15ba98;
L_15ba78:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15b998;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15b998;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15ba94ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15b998;
L_15ba98:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15baa0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15ba78;
L_15baa4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15baacULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15b8b4;
L_15bab0:
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_NE) goto L_15b9fc;
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[21], (cpu->regs[19] + 24) + 8);
L_15babc:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_15bacc;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
L_15bacc:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15bb54;
L_15bad8:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15bae8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe09a4ULL);
    if ((cpu->regs[0])==0) goto L_15bb5c;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15bb00;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15bb90;
L_15bb00:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15bb9c;
L_15bb08:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15bb1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15bbb4;
L_15bb1c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15bb40;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15bb40;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15bb40ULL; PB_CALL(24, cpu, tlb, cpu->regs[1]);
L_15bb40:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_15b9c0;
L_15bb48:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[21], (cpu->regs[0] + 0) + 8);
    goto L_15babc;
L_15bb54:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_15bad8;
L_15bb5c:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15bb70;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15bbc0;
L_15bb70:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15b998;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15b998;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15bb8cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15b998;
L_15bb90:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x15bb98ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15bb00;
L_15bb9c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15bb08;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15bbb0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15bb08;
L_15bbb4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15bbbcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15bb1c;
L_15bbc0:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x15bbc8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15bb70;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2640));
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_15bc3c;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_NE) goto L_15bc00;
    cpu->regs[0] = 1ULL;
L_15bbf8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_15bc00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    cpu->regs[5] = PB_BASE + 0x292000ULL;
    cpu->regs[5] = cpu->regs[5] + 1000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[5] : cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x15bc34ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_15bbf8;
L_15bc3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 784ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15bc54ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_15bbf8;
    /* nop */
}
