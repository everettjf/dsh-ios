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

void ft_PyInit__operator(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[0] = cpu->regs[0] + 1192ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = PB_BASE + 0x520000ULL;
    cpu->regs[22] = cpu->regs[21] + 16ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 32));
    cpu->regs[1] = cpu->regs[22] + 1296ULL;
    cpu->regs[30] = PB_BASE + 0x1df3ccULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df3e0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1328ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df3f4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 8), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df408ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1360ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df41cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df430ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1392ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df444ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 24), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df458ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1424ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df46cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df480ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[22] = cpu->regs[21] + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22] + 1456ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df498ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 40), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df4acULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1488ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df4c0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 48), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df4d4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1520ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df4e8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 56), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df4fcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1552ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df510ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 64), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df524ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1584ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df538ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 72), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df54cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1616ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df560ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 80), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df574ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1648ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df588ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 88), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df59cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1680ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df5b0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 96), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df5c4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1712ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df5d8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 104), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df5ecULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1744ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df600ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 112), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df614ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1776ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df628ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 120), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df63cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1808ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df650ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 128), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df664ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1840ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df678ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 136), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df68cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1872ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df6a0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 144), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df6b4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1904ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df6c8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 152), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df6dcULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1936ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df6f0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 160), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df704ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    cpu->regs[1] = cpu->regs[22] + 1968ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df718ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 168), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df754;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df72cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df754;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 160));
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3216));
    PB_STR((cpu->regs[1] + 8), cpu->regs[2]);
L_1df744:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1df754:
    cpu->regs[0] = 4294967295ULL;
    goto L_1df744;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x520000ULL;
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    cpu->regs[1] = cpu->regs[20] + 2000ULL;
    cpu->regs[30] = PB_BASE + 0x1df78cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1df804;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df7a0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df804;
    cpu->regs[1] = cpu->regs[20] + 2032ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df7b4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df804;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df7c8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1ab080ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1df804;
    cpu->regs[1] = cpu->regs[20] + 2064ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1df7dcULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 16), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1df804;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1df7f0ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1ab080ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_1df7f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1df804:
    cpu->regs[0] = 4294967295ULL;
    goto L_1df7f4;
L_1df80c:
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1df824;
    cpu->regs[3] = 1ULL;
    if (((cpu->regs[2] >> 7) & 1)) goto L_1df82c;
L_1df81c:
    cpu->regs[0] = cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    goto L_1df80c;
L_1df824:
    cpu->regs[0] = 1ULL;
    return;
L_1df82c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(223ULL)));
    if (FLAG_HI) goto L_1df864;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(193ULL)));
    if (FLAG_LS) goto L_1df894;
    cpu->regs[4] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + 1ULL));
L_1df844:
    PB_LDRB(cpu->regs[5], (cpu->regs[0] + cpu->regs[4]));
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 128ULL));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(63ULL)));
    if (FLAG_HI) goto L_1df894;
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1df844;
    goto L_1df81c;
L_1df864:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(239ULL)));
    if (FLAG_HI) goto L_1df8c8;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(224ULL)));
    if (FLAG_EQ) goto L_1df888;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(237ULL)));
    if (FLAG_EQ) goto L_1df900;
L_1df87c:
    cpu->regs[4] = 2ULL;
L_1df880:
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + 1ULL));
    goto L_1df844;
L_1df888:
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(159ULL)));
    if (FLAG_HI) goto L_1df87c;
L_1df894:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = PB_BASE + 0x293000ULL;
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 512));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 2336));
    cpu->regs[1] = cpu->regs[5] + 1112ULL;
    cpu->regs[30] = PB_BASE + 0x1df8bcULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1df8c8:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(244ULL)));
    if (FLAG_HI) goto L_1df894;
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(143ULL)));
    if (FLAG_HI) goto L_1df8f0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(240ULL)));
    if (FLAG_EQ) goto L_1df894;
    cpu->regs[4] = 3ULL;
L_1df8e8:
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + 1ULL));
    goto L_1df844;
L_1df8f0:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(244ULL)));
    if (FLAG_EQ) goto L_1df894;
    cpu->regs[4] = 3ULL;
    goto L_1df8e8;
L_1df900:
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(159ULL)));
    if (FLAG_HI) goto L_1df894;
    cpu->regs[4] = 2ULL;
    goto L_1df880;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    if ((cpu->regs[0])==0) goto L_1df950;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1df94cULL; PB_CALL(53, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1df984;
L_1df950:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[0])==0) goto L_1df964;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1df960ULL; PB_CALL(54, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1df984;
L_1df964:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_1df984;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1df984:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
}
