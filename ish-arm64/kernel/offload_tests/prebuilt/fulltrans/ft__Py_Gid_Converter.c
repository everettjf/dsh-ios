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

void ft__Py_Gid_Converter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xaa840ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x123ed0ULL);
    if ((cpu->regs[0])!=0) goto L_aa870;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xaa858ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    cpu->regs[30] = PB_BASE + 0xaa86cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_aa95c;
L_aa870:
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xaa87cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_aa8b0;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa8a0;
    cpu->regs[30] = PB_BASE + 0xaa898ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa954;
    goto L_aa8f8;
L_aa8a0:
    cpu->regs[0] = 4294967295ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LS) goto L_aa8f8;
    goto L_aa920;
L_aa8b0:
    if (FLAG_LT) goto L_aa920;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa8bcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x13ae90ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xaa8c4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_aa8e0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaa8d8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aa93c;
    goto L_aa954;
L_aa8e0:
    cpu->regs[20] = cpu->regs[3];
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_aa93c;
    cpu->regs[0] = 4294967295ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_HI) goto L_aa93c;
L_aa8f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_aa914;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_aa914;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa914ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_aa914:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[20]);
    goto L_aa97c;
L_aa920:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 256ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaa938ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aa954;
L_aa93c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaa954ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_aa954:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_aa964;
L_aa95c:
    cpu->regs[0] = 0ULL;
    goto L_aa97c;
L_aa964:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_aa95c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa978ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_aa95c;
L_aa97c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_aa99c;
    cpu->regs[30] = PB_BASE + 0xaa99cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_aa99c:
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 192ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 88), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[1])!=0) goto L_aaa08;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 3896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaaa04ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aaa38;
L_aaa08:
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2280));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_aaa40;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 728ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaaa38ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_aaa38:
    cpu->regs[27] = 4294967295ULL;
    goto L_ab4b4;
L_aaa40:
    cpu->regs[30] = PB_BASE + 0xaaa44ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x82788ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GE) goto L_aaa6c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 760ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaaa68ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_aaa38;
L_aaa6c:
    if (FLAG_EQ) goto L_aaac4;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_HI) goto L_aaafc;
    cpu->regs[2] = 1ULL;
    cpu->regs[22] = 40482ULL;
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[0] & 63);
    cpu->regs[22] = cpu->regs[2] & cpu->regs[22]; FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_NE) goto L_aaae0;
    cpu->regs[0] = 213ULL;
    FLAG_CMP((cpu->regs[2]) & (cpu->regs[0]), 0);
    if (FLAG_NE) goto L_aab18;
    cpu->regs[0] = 16392ULL;
    FLAG_CMP((cpu->regs[2]) & (cpu->regs[0]), 0);
    if (FLAG_EQ) goto L_aaafc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaaac0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aaa38;
L_aaac4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaaadcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_aaa38;
L_aaae0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaaaf8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_aaa38;
L_aaafc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaab14ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aaa38;
L_aab18:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0xaab20ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x8836cULL);
    PB_STRW((SP + 24), cpu->regs[0]);
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaab30ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 32));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_aab50;
    cpu->regs[1] = 2147483648ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[0] = 4294967295ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_aab6c;
L_aab50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 960ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaab68ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aaa38;
L_aab6c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[21] = cpu->regs[27];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 68));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_LE) goto L_aaba4;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2976));
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 984ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0xaaba0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_aaa38;
L_aaba4:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 136));
    PB_STRW((SP + 52), 0ULL);
    PB_LDR(cpu->regs[26], (cpu->regs[1] + 16));
    cpu->regs[23] = cpu->regs[4] + 32ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[4] + 16));
    PB_STRW((SP + 64), cpu->regs[3]);
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[25] = cpu->regs[23] + cpu->regs[25];
    PB_STR((SP + 80), cpu->regs[25]);
    if (((cpu->regs[26] >> 31) & 1)) goto L_aaa38;
    cpu->regs[0] = ((cpu->regs[26] & 0xffffffffULL) << 2);
    cpu->regs[30] = PB_BASE + 0xaabd4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_aaa38;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 4294967295ULL;
L_aabe4:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_aabf8;
    PB_STRW((cpu->regs[19] + (cpu->regs[1] << 2)), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_aabe4;
L_aabf8:
    cpu->regs[1] = 4294967295ULL;
    cpu->regs[0] = SP + 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[7] = cpu->regs[1];
L_aac08:
    FLAG_CMP(cpu->regs[23], cpu->regs[25]);
    if (FLAG_HS) goto L_aac50;
    PB_STRW((SP + 48), cpu->regs[3]);
    PB_STRW((SP + 56), cpu->regs[1]);
    PB_STR((SP + 72), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0xaac20ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x164670ULL);
    PB_LDRW(cpu->regs[1], (SP + 56));
    PB_LDR(cpu->regs[23], (SP + 72));
    PB_LDRW(cpu->regs[3], (SP + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[7])));
    if (FLAG_EQ) goto L_aac48;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_aac08;
    cpu->regs[4] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[4] = cpu->regs[4] >> 1;
    PB_STRW((cpu->regs[19] + (cpu->regs[4] << 2)), cpu->regs[1]);
L_aac48:
    cpu->regs[7] = cpu->regs[1];
    goto L_aac08;
L_aac50:
    cpu->regs[0] = 2147483647ULL;
    cpu->regs[1] = 0ULL;
    PB_STRW((SP + 4), cpu->regs[0]);
L_aac5c:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_aac88;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[1] << 2)));
    PB_LDRW(cpu->regs[0], (SP + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_GE) goto L_aac80;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[0] = (FLAG_GT) ? cpu->regs[0] : cpu->regs[3];
    PB_STRW((SP + 4), cpu->regs[0]);
L_aac80:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_aac5c;
L_aac88:
    PB_LDRW(cpu->regs[1], (SP + 4));
    cpu->regs[0] = 2147483646ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LS) goto L_aacc0;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2976));
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 1032ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0xaacb4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaacbcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_aaa38;
L_aacc0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xaacd0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1c1a60ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ab198;
    cpu->regs[0] = ((uint32_t)(cpu->regs[26] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[28] = cpu->regs[21] + 32ULL;
    if (FLAG_GE) goto L_aacf4;
L_aace4:
    cpu->regs[30] = PB_BASE + 0xaace8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_aad10;
    goto L_ab198;
L_aacf4:
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 3);
    cpu->regs[30] = PB_BASE + 0xaacfcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_aace4;
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = 18446744073709551614ULL;
    goto L_aad28;
L_aad10:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_ab198;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xaad24ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_ab198;
L_aad28:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LT) goto L_aad3c;
    PB_STR((cpu->regs[23] + (cpu->regs[0] << 3)), cpu->regs[1]);
    goto L_aad28;
L_aad3c:
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 48));
    cpu->regs[0] = 672ULL;
    cpu->regs[1] = PB_BASE + 0x2b7000ULL;
    cpu->regs[1] = cpu->regs[1] + 1840ULL;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(cpu->regs[0]))), 0);
    cpu->regs[1] = cpu->regs[1] + 2320ULL;
    cpu->regs[0] = 3ULL;
    cpu->regs[0] = (FLAG_EQ) ? 0ULL : cpu->regs[0];
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    PB_STR((SP + 8), cpu->regs[1]);
L_aad64:
    cpu->regs[27] = PB_BASE + 0x2b6000ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[0] = cpu->regs[27] + 1488ULL;
    cpu->regs[6] = 0ULL;
    PB_STR((SP + 16), cpu->regs[0]);
L_aad78:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_LE) goto L_ab098;
    PB_LDR(cpu->regs[27], (cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[6])) << 3)));
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xaad94ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18cb8cULL);
L_aad94:
    cpu->regs[7] = ((uint32_t)(cpu->regs[6] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(144ULL)));
    if (FLAG_NE) goto L_aadc4;
    cpu->regs[6] = cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[6])) << 1);
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xaadb0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x18cb8cULL);
    PB_LDRB(cpu->regs[5], (cpu->regs[6] + 1));
    cpu->regs[6] = cpu->regs[7];
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[7])) << 3)), cpu->regs[27]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[5] | (cpu->regs[4] << 8)));
    goto L_aad94;
L_aadc4:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDRB(cpu->regs[5], (cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]))));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + cpu->regs[7]));
    FLAG_CMP(cpu->regs[27], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_ab090;
    cpu->regs[1] = cpu->regs[28] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[6])) << 1);
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 1));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | (cpu->regs[4] << 8)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(140ULL)));
    if (FLAG_GT) goto L_aae74;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(92ULL)));
    if (FLAG_GT) goto L_aae34;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(54ULL)));
    if (FLAG_EQ) goto L_aaf24;
    if (FLAG_GT) goto L_aae54;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(35ULL)));
    if (FLAG_EQ) goto L_aaf30;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(50ULL)));
    if (FLAG_EQ) goto L_aaee4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_ab040;
    cpu->regs[0] = cpu->regs[27] << 3;
    cpu->regs[1] = 1152921504606846975ULL;
    cpu->regs[0] = cpu->regs[0] | 4ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[1]);
    cpu->regs[0] = (FLAG_LS) ? cpu->regs[0] : (~0ULL);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[0]);
    goto L_ab090;
L_aae34:
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] - 93ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(47ULL)));
    if (FLAG_HI) goto L_ab040;
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDRH(cpu->regs[4], (cpu->regs[2] + (((uint64_t)(uint32_t)(cpu->regs[4])) << 1)));
    cpu->regs[8] = PB_BASE + 0xaae54ULL;
    cpu->regs[4] = cpu->regs[8] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[4])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[4]); return;
L_aae54:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(89ULL)));
    if (FLAG_EQ) goto L_aaf4c;
    if (FLAG_GT) goto L_ab040;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(68ULL)));
    if (FLAG_EQ) goto L_aaee4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(83ULL)));
    if (FLAG_EQ) goto L_ab090;
    goto L_ab040;
L_aae74:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(171ULL)));
    if (FLAG_NE) goto L_ab040;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 2ULL));
    cpu->regs[0] = 0ULL;
    goto L_aafac;
    cpu->regs[1] = ((uint32_t)(cpu->regs[5] + cpu->regs[1]));
    cpu->regs[2] = (uint64_t)((int64_t)cpu->regs[27] >> 3);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)), cpu->regs[2]);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[2]);
    goto L_ab090;
    cpu->regs[1] = ((uint32_t)(cpu->regs[6] + cpu->regs[1]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 2ULL));
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)), cpu->regs[27]);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[27]);
    goto L_ab090;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[7]));
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)), cpu->regs[27]);
    goto L_ab090;
    cpu->regs[7] = ((uint32_t)(cpu->regs[7] - cpu->regs[1]));
    cpu->regs[0] = (((uint64_t)(((int64_t)(cpu->regs[7] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_NE) goto L_aaedc;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[7])));
    cpu->regs[1] = (FLAG_GT) ? 1 : 0;
    cpu->regs[26] = ((uint32_t)(cpu->regs[26] | cpu->regs[1]));
L_aaedc:
    PB_STR((cpu->regs[23] + cpu->regs[0]), cpu->regs[27]);
    goto L_ab090;
L_aaee4:
    cpu->regs[0] = cpu->regs[27] & 18446744073709551608ULL;
    FLAG_CMP(cpu->regs[27], 0ULL);
    cpu->regs[0] = cpu->regs[0] | 1ULL;
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[0] : (~0ULL);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[0]);
    goto L_ab090;
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] + 2ULL));
    cpu->regs[0] = cpu->regs[27] << 3;
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | 3ULL;
    cpu->regs[1] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[1]);
    cpu->regs[0] = (FLAG_LS) ? cpu->regs[0] : (~0ULL);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[0]);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[6])) << 3)), cpu->regs[0]);
    goto L_ab090;
L_aaf24:
    cpu->regs[2] = (uint64_t)((int64_t)cpu->regs[27] >> 6);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[2]);
    goto L_ab090;
L_aaf30:
    cpu->regs[0] = cpu->regs[27] << 3;
    cpu->regs[1] = 1152921504606846975ULL;
    cpu->regs[0] = cpu->regs[0] | 2ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[1]);
    cpu->regs[0] = (FLAG_LS) ? cpu->regs[0] : (~0ULL);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[0]);
    goto L_ab090;
L_aaf4c:
    cpu->regs[2] = (uint64_t)((int64_t)cpu->regs[27] >> 3);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[2]);
    goto L_ab090;
    if (!((cpu->regs[1] >> 0) & 1)) goto L_aafc0;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_HI) goto L_aaf74;
    cpu->regs[2] = cpu->regs[27] << 3;
    cpu->regs[27] = cpu->regs[2] | 4ULL;
    goto L_aafc0;
L_aaf74:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_aafd4;
    if (!((cpu->regs[1] >> 0) & 1)) goto L_ab08c;
    cpu->regs[0] = 1152921504606846975ULL;
    if (((cpu->regs[27] >> 63) & 1)) goto L_aafa4;
    cpu->regs[2] = cpu->regs[27] & 18446744073709551608ULL;
    cpu->regs[2] = cpu->regs[2] | 4ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[2] = cpu->regs[2] | 3ULL;
    cpu->regs[27] = (FLAG_LE) ? cpu->regs[2] : (~0ULL);
    goto L_ab08c;
L_aafa4:
    cpu->regs[27] = 18446744073709551615ULL;
    goto L_ab08c;
L_aafac:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_aafc0;
    cpu->regs[27] = (uint64_t)((int64_t)cpu->regs[27] >> 3);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    goto L_aafac;
L_aafc0:
    cpu->regs[0] = cpu->regs[27] << 3;
    cpu->regs[1] = 1152921504606846975ULL;
    cpu->regs[0] = cpu->regs[0] | 3ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[1]);
    cpu->regs[0] = (FLAG_LS) ? cpu->regs[0] : (~0ULL);
L_aafd4:
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[0]);
    goto L_ab090;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = 7ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[27] & cpu->regs[0]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (cpu->regs[1] << 1)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << (cpu->regs[1] & 63)));
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] << (cpu->regs[1] & 63)));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[27] >> (cpu->regs[1] & 63));
    cpu->regs[0] = cpu->regs[0] & cpu->regs[27];
    cpu->regs[0] = cpu->regs[0] | cpu->regs[4];
    cpu->regs[0] = ((cpu->regs[0] & ~0x7ULL) | ((cpu->regs[1] >> 0) & 0x7ULL));
    cpu->regs[0] = cpu->regs[0] & 4294967295ULL;
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[0]);
    goto L_ab090;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (cpu->regs[1] << 1)));
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[27] >> (cpu->regs[1] & 63));
    cpu->regs[1] = cpu->regs[1] & 7ULL;
    cpu->regs[1] = cpu->regs[1] | (cpu->regs[27] << 3);
    cpu->regs[1] = (FLAG_LS) ? cpu->regs[1] : (~0ULL);
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[1]);
    goto L_ab090;
L_ab040:
    PB_STRW((SP + 28), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0xab048ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x8f048ULL);
    PB_LDRW(cpu->regs[5], (SP + 28));
    cpu->regs[1] = cpu->regs[0];
L_ab050:
    if (!((cpu->regs[1] >> 31) & 1)) goto L_ab060;
    cpu->regs[27] = (uint64_t)((int64_t)cpu->regs[27] >> 3);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    goto L_ab050;
L_ab060:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[4] = 1152921504606846975ULL;
    cpu->regs[1] = ((uint32_t)((FLAG_GT) ? 0ULL : ((uint64_t)(-(int64_t)cpu->regs[0]))));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + cpu->regs[0]));
L_ab070:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ab08c;
    cpu->regs[1] = cpu->regs[27] << 3;
    FLAG_CMP(cpu->regs[27], cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] | 3ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[27] = (FLAG_LS) ? cpu->regs[1] : (~0ULL);
    goto L_ab070;
L_ab08c:
    PB_STR((cpu->regs[23] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 3)), cpu->regs[27]);
L_ab090:
    cpu->regs[6] = cpu->regs[5];
    goto L_aad78;
L_ab098:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 40));
    cpu->regs[7] = SP + 36ULL;
    cpu->regs[6] = SP + 40ULL;
    cpu->regs[5] = SP + 44ULL;
    cpu->regs[0] = cpu->regs[1] + 32ULL;
    cpu->regs[4] = SP + 48ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 16));
    cpu->regs[9] = 1152921504606846975ULL;
    cpu->regs[8] = cpu->regs[0] + cpu->regs[8];
L_ab0bc:
    FLAG_CMP(cpu->regs[8], cpu->regs[0]);
    if (FLAG_LS) goto L_ab174;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0xab0ccULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x2806c0ULL);
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0xab0d4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x2806c0ULL);
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0xab0dcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x2806c0ULL);
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xab0e4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x2806c0ULL);
    do { int32_t _s=0; tlb_read(tlb,(SP + 36),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[10], (cpu->regs[23] + (cpu->regs[1] << 3)));
    FLAG_CMP(cpu->regs[10], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_ab0bc;
    do { int32_t _s=0; tlb_read(tlb,(SP + 44),&_s,4); cpu->regs[11] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[11] = cpu->regs[11] << 3;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + cpu->regs[11]));
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_NE) goto L_ab0bc;
    PB_LDRW(cpu->regs[12], (SP + 48));
    cpu->regs[1] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[12] >> 1)));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_ab134;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[2] = 7ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + (cpu->regs[1] << 1)));
    cpu->regs[1] = cpu->regs[2] << (cpu->regs[1] & 63);
L_ab124:
    FLAG_CMP(cpu->regs[1], cpu->regs[10]);
    if (FLAG_GE) goto L_ab138;
    cpu->regs[10] = (uint64_t)((int64_t)cpu->regs[10] >> 3);
    goto L_ab124;
L_ab134:
    cpu->regs[10] = 0ULL;
L_ab138:
    if (!((cpu->regs[12] >> 0) & 1)) goto L_ab150;
    cpu->regs[1] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[10], cpu->regs[1]);
    if (FLAG_HI) goto L_ab164;
    cpu->regs[1] = 5ULL;
    cpu->regs[10] = cpu->regs[1] | (cpu->regs[10] << 3);
L_ab150:
    cpu->regs[1] = cpu->regs[10] << 3;
    FLAG_CMP(cpu->regs[10], cpu->regs[9]);
    cpu->regs[1] = cpu->regs[1] | 2ULL;
    cpu->regs[1] = (FLAG_LS) ? cpu->regs[1] : (~0ULL);
    goto L_ab168;
L_ab164:
    cpu->regs[1] = 18446744073709551615ULL;
L_ab168:
    cpu->regs[26] = 1ULL;
    PB_STR((cpu->regs[23] + cpu->regs[11]), cpu->regs[1]);
    goto L_ab0bc;
L_ab174:
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_aad64;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_ab1a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_ab1a4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xab194ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_ab1a4;
L_ab198:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab1a0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_aaa38;
L_ab1a4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = 4294967295ULL;
    cpu->regs[21] = cpu->regs[21] + 688ULL;
    cpu->regs[26] = cpu->regs[27];
    cpu->regs[6] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[25] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    cpu->regs[1] = cpu->regs[1] + 192ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[0] = ((uint64_t)(((int64_t)(cpu->regs[0] << (32-1)) ) >> 32));
    PB_LDR(cpu->regs[28], (cpu->regs[23] + (cpu->regs[0] << 3)));
L_ab1d8:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_LE) goto L_ab33c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + (cpu->regs[6] << 2)));
    PB_LDRW(cpu->regs[1], (SP + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_ab334;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + (cpu->regs[6] << 3)));
    cpu->regs[1] = cpu->regs[28] | cpu->regs[0];
    if (((cpu->regs[1] >> 63) & 1)) goto L_ab274;
    cpu->regs[1] = cpu->regs[28];
L_ab200:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_ab210;
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 3);
    goto L_ab200;
L_ab210:
    cpu->regs[2] = cpu->regs[0];
L_ab214:
    if ((cpu->regs[1])==0) goto L_ab258;
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] & 7ULL)); FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_EQ) goto L_ab274;
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 7ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_ab238;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(4ULL)));
    cpu->regs[4] = (FLAG_NE) ? 1 : 0;
    goto L_ab248;
L_ab238:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_ab24c;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    cpu->regs[4] = (FLAG_EQ) ? 1 : 0;
L_ab248:
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_ab274;
L_ab24c:
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 3);
    cpu->regs[2] = (uint64_t)((int64_t)cpu->regs[2] >> 3);
    goto L_ab214;
L_ab258:
    if ((cpu->regs[2])!=0) goto L_ab274;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_GE) goto L_ab2c8;
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[26] = cpu->regs[6];
    cpu->regs[27] = 0ULL;
    goto L_ab334;
L_ab274:
    FLAG_CMP(cpu->regs[27], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ab334;
    FLAG_CMP(cpu->regs[28], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ab2d0;
    FLAG_CMP(cpu->regs[28], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_ab2dc;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ab2e8;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_ab2f8;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 7ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_HI) goto L_ab308;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_HI) goto L_ab318;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_ab328;
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[21] = cpu->regs[21] + 624ULL;
    goto L_ab334;
L_ab2c8:
    cpu->regs[27] = 0ULL;
    goto L_ab334;
L_ab2d0:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[21] = cpu->regs[21] + 320ULL;
    goto L_ab334;
L_ab2dc:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[21] = cpu->regs[21] + 352ULL;
    goto L_ab334;
L_ab2e8:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[21] = cpu->regs[21] + 464ULL;
    goto L_ab334;
L_ab2f8:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[21] = cpu->regs[21] + 392ULL;
    goto L_ab334;
L_ab308:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[21] = cpu->regs[21] + 560ULL;
    goto L_ab334;
L_ab318:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[21] = cpu->regs[21] + 536ULL;
    goto L_ab334;
L_ab328:
    cpu->regs[21] = PB_BASE + 0x2a4000ULL;
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[21] + 496ULL;
L_ab334:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    goto L_ab1d8;
L_ab33c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xab344ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab34cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_ab368;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[2], cpu->regs[1]); cpu->regs[1] += 72;
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 72));
    goto L_ab380;
L_ab368:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xab37cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aaa38;
L_ab380:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_ab39c;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[3] = ((uint32_t)((FLAG_EQ) ? (cpu->regs[3] + 1) : cpu->regs[3]));
    goto L_ab380;
L_ab39c:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_ab424;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3744));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[4] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[4] = cpu->regs[4] + 1000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[4] : cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 1080ULL;
    cpu->regs[30] = PB_BASE + 0xab3d4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x24d184ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aaa38;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_LDR(cpu->regs[4], cpu->regs[1]); cpu->regs[1] += 72;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 72));
L_ab3f4:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_LE) goto L_ab41c;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + (cpu->regs[22] << 3)));
    if ((cpu->regs[5])!=0) goto L_ab414;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_STR((cpu->regs[1] + (cpu->regs[22] << 3)), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)((FLAG_NE) ? cpu->regs[0] : (~0ULL)));
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : (0ULL + 1);
L_ab414:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_ab3f4;
L_ab41c:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_ab424;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_ab424:
    PB_LDRW(cpu->regs[0], (SP + 24));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ab434;
    cpu->regs[28] = (uint64_t)((int64_t)cpu->regs[28] >> 3);
L_ab434:
    cpu->regs[19] = cpu->tls_ptr;
L_ab438:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    FLAG_CMP(cpu->regs[25], cpu->regs[28]);
    if (FLAG_GE) goto L_ab4a0;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 64));
    cpu->regs[0] = ((uint32_t)(cpu->regs[28] & 7ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[3] = cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 72));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_ab48c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xab470ULL; PB_CALL(47, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + cpu->regs[0]));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 104));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STRW((cpu->regs[1] + 64), cpu->regs[2]);
    PB_STR((cpu->regs[4] + 0), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xab488ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_ab498;
L_ab48c:
    PB_STRW((cpu->regs[1] + 64), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xab498ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x18d760ULL);
L_ab498:
    cpu->regs[28] = (uint64_t)((int64_t)cpu->regs[28] >> 3);
    goto L_ab438;
L_ab4a0:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STRW((cpu->regs[20] + 40), 0ULL);
    cpu->regs[0] = cpu->regs[0] + 192ULL;
    cpu->regs[0] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[26])) << 1);
    PB_STR((cpu->regs[1] + 56), cpu->regs[0]);
L_ab4b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ab4d4;
    cpu->regs[30] = PB_BASE + 0xab4d4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ab4d4:
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
    SP = SP + 192ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2920));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xab51cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ab528;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_ab5a4;
L_ab528:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 96));
    if ((cpu->regs[0])==0) goto L_ab554;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_ab554;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab548ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x2284c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ab580;
    goto L_ab574;
L_ab554:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1120ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xab570ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_ab5ac;
L_ab574:
    cpu->regs[30] = PB_BASE + 0xab578ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ab5ac;
    goto L_ab584;
L_ab580:
    if (!((cpu->regs[0] >> 63) & 1)) goto L_ab5a4;
L_ab584:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 1168ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xab5a0ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_ab5ac;
L_ab5a4:
    cpu->regs[20] = 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
L_ab5ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
