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

void ft_PyNumber_Lshift(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 88ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x12c65cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_12c678;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_12c678:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[3] = cpu->regs[3] + 816ULL;
    cpu->regs[2] = 88ULL;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x1b02c0ULL); return; };
    /* nop */
    /* nop */
    SP = SP - 144ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 16), cpu->regs[3]);
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[24] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12c6e4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_12ca6c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12c6f4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1b01a4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12ca6c;
    cpu->regs[30] = PB_BASE + 0x12c700ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x190310ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12cabc;
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[25], 0ULL);
    if (FLAG_LE) goto L_12c814;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2520));
    cpu->regs[22] = SP + 32ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
L_12c724:
    cpu->regs[0] = cpu->regs[25] - cpu->regs[19];
    if (((cpu->regs[0] >> 0) & 1)) goto L_12c86c;
L_12c72c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[27], (cpu->regs[1] + (cpu->regs[19] << 3)));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_12cae0;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_NE) goto L_12c8e8;
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12c8e8;
L_12c758:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12c768ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
L_12c76c:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12c774ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 32));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12c9b4;
L_12c780:
    cpu->regs[0] = ((cpu->regs[2] >> 12) & 0xfULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_12c94c;
    FLAG_CMP((cpu->regs[24]) & (cpu->regs[2]), 0);
    if (FLAG_NE) goto L_12c94c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    cpu->regs[28] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[27], (cpu->regs[1] + (cpu->regs[19] << 3)));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_12ca8c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_NE) goto L_12c904;
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12c904;
L_12c7c8:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12c7d8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
L_12c7dc:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12c7e4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 32));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12c920;
    cpu->regs[0] = ((cpu->regs[0] >> 12) & 0xfULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_12c94c;
L_12c7fc:
    FLAG_CMP((cpu->regs[24]) & (cpu->regs[2]), 0);
    if (FLAG_NE) goto L_12c94c;
    cpu->regs[19] = cpu->regs[28] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[19]);
    if (FLAG_NE) goto L_12c72c;
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
L_12c814:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12c830;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12c830;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12c830ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12c830:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_12c9d8;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_12c86c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[27], (cpu->regs[1] + (cpu->regs[19] << 3)));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_12caa4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_NE) goto L_12c998;
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12c998;
L_12c898:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12c8a8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
L_12c8ac:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12c8b4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 32));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_12c9e0;
    cpu->regs[0] = ((cpu->regs[0] >> 12) & 0xfULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_12c94c;
L_12c8cc:
    FLAG_CMP((cpu->regs[24]) & (cpu->regs[2]), 0);
    if (FLAG_NE) goto L_12c94c;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[19]);
    if (FLAG_NE) goto L_12c72c;
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_12c814;
L_12c8e8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12c8f0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12c758;
    cpu->regs[0] = 0ULL;
    goto L_12c76c;
L_12c904:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12c90cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12c7c8;
    cpu->regs[0] = 0ULL;
    goto L_12c7dc;
L_12c920:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_STR((SP + 24), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12c93cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[0] = ((cpu->regs[2] >> 12) & 0xfULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_12c7fc;
L_12c94c:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x12c954ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_12caf8;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[27];
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 16), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x12c978ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ca10;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_12ca74;
L_12c984:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_NE) goto L_12c724;
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_12c814;
L_12c998:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x12c9a0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_12c898;
    cpu->regs[0] = 0ULL;
    goto L_12c8ac;
L_12c9b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_STR((SP + 24), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12c9d0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[2], (SP + 24));
    goto L_12c780;
L_12c9d8:
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x12c9e0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_12c9e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_STR((SP + 24), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12c9fcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[0] = ((cpu->regs[2] >> 12) & 0xfULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_12c8cc;
    goto L_12c94c;
L_12ca10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ca2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12ca2c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12ca2cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12ca2c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ca48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12ca48;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x12ca48ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_12ca48:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12cb18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12cb18;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x12ca68ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
L_12ca6c:
    PB_STR((SP + 8), 0ULL);
    goto L_12c830;
L_12ca74:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12c984;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x12ca88ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12c984;
L_12ca8c:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x12ca9cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_12c7dc;
L_12caa4:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x12cab4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_12c8ac;
L_12cabc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ca6c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12ca6c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12cad8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_STR((SP + 8), 0ULL);
    goto L_12c830;
L_12cae0:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x12caf0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_12c76c;
L_12caf8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12ca48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12ca48;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x12cb14ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12ca48;
L_12cb18:
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    PB_STR((SP + 8), 0ULL);
    goto L_12c830;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x12cb48ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_12cb68;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_12cb68:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(32, cpu, tlb, PB_BASE + 0x1b02c0ULL); return; };
}
