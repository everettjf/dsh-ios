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

void ft_PyEval_MergeCompilerFlags(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1e0640ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    if ((cpu->regs[2])==0) goto L_1e066c;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 48));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 33423360ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_1e0674;
L_1e066c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1e0674:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[2]));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
    goto L_1e066c;
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 144));
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e0f2c;
L_1e06b0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e0f98;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[20] = cpu->regs[21];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e0810;
L_1e06cc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1e0ef4;
L_1e06e0:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e06f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1e0fc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e0d9c;
L_1e06f8:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e06fc:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0fa4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e070cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e1470ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e0eb0;
L_1e0714:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e0718:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0fa4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0728ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1e10c4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0794;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0738ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e26acULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0794;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0748ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e2924ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[5] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0798;
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[20];
L_1e075c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e076cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x19e0acULL);
    if ((cpu->regs[0])==0) goto L_1e0e24;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_1e0774:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1e077c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
L_1e0784:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_1e0794:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e0798:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0fa4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e07a8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1e1840ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e07f0;
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e07b4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0fa4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e07c4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e2924ULL);
    if ((cpu->regs[0])!=0) goto L_1e07e0;
L_1e07c8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_1e07cc:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1e07d4:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    goto L_1e077c;
L_1e07e0:
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    goto L_1e075c;
L_1e07f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e07f8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1e2924ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[5] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e07b4;
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    goto L_1e075c;
L_1e0810:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1e0d80;
L_1e0824:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e0830ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e0e74;
L_1e0838:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0d90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e084cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x26b4d0ULL);
    if ((cpu->regs[0])!=0) goto L_1e0d48;
L_1e0850:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0d90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0864ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1e0fc0ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e08d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0874ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1e1680ULL);
    if ((cpu->regs[0])==0) goto L_1e0e6c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e0f10;
L_1e0890:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0f1c;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e08a4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1e1470ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e0e44;
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0f1c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e08c0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1e1840ULL);
    if ((cpu->regs[0])!=0) goto L_1e0ee8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
L_1e08d4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0d90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e08e4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1e1680ULL);
    if ((cpu->regs[0])==0) goto L_1e08fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1e08f4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e09e4;
L_1e08fc:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e0900:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0d90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0910ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x26b4d0ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0938;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0920ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x217260ULL);
    if ((cpu->regs[0])==0) goto L_1e0934;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e0930ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e0aa4;
L_1e0934:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e0938:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0d90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0948ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x252fc0ULL);
    if ((cpu->regs[0])==0) goto L_1e095c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e0958ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e0988;
L_1e095c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_1e0960:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1e0968:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[3] = cpu->regs[4];
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_1e06cc;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[0] = 0ULL;
    goto L_1e0784;
L_1e0988:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1e0994ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e095c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[6] = cpu->regs[6] + 2048ULL;
L_1e09b0:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 24),&_a,4); tlb_read(tlb,(cpu->regs[2] + 28),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 20),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
L_1e09c0:
    cpu->regs[30] = PB_BASE + 0x1e09c4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1e09c8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e0960;
    cpu->regs[0] = 1ULL;
    cpu->regs[6] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1e0968;
L_1e09e4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e0b64;
L_1e09fc:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0b70;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1e0a10ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1e1324ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0b80;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1e0b94;
L_1e0a30:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0ba0;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = 8ULL;
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e0a48ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0bb0;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[27] = cpu->regs[6];
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0bd4;
    cpu->regs[24] = 0ULL;
    cpu->regs[28] = 1ULL;
L_1e0a68:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0a74ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])==0) goto L_1e0bec;
    cpu->regs[30] = PB_BASE + 0x1e0a84ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0bec;
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    if (FLAG_EQ) goto L_1e0c28;
L_1e0a94:
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[23] + (cpu->regs[24] << 3)), cpu->regs[2]);
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_1e0a68;
L_1e0aa4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1e0b44;
L_1e0abc:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0b34;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e0ad4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e0af0;
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0b34;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0aecULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1e1240ULL);
    if ((cpu->regs[0])==0) goto L_1e0b50;
L_1e0af0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0b04ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x217260ULL);
    if ((cpu->regs[0])==0) goto L_1e0934;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e0b14ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0934;
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = cpu->regs[6] + 2024ULL;
    goto L_1e09b0;
L_1e0b34:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1e0938;
L_1e0b44:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0b4cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e0abc;
L_1e0b50:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1e0938;
L_1e0b64:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0b6cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e09fc;
L_1e0b70:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1e0900;
L_1e0b80:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
L_1e0b84:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1e0900;
L_1e0b94:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0b9cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e0a30;
L_1e0ba0:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1e0b84;
L_1e0bb0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e0bbcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1e0b84;
L_1e0bd4:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1e0b84;
L_1e0bec:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1e0bfcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0c44;
L_1e0c04:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[27]));
    FLAG_CMP(cpu->regs[24], cpu->regs[27]);
    if (FLAG_LE) goto L_1e0c74;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[27] = ((uint32_t)(cpu->regs[27] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[23] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1e0c04;
L_1e0c28:
    cpu->regs[28] = cpu->regs[28] << 1;
    cpu->regs[0] = cpu->regs[23];
    PB_STR((SP + 104), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[28] << 3;
    cpu->regs[30] = PB_BASE + 0x1e0c3cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe5680ULL);
    PB_LDR(cpu->regs[2], (SP + 104));
    if ((cpu->regs[0])!=0) goto L_1e0cf0;
L_1e0c44:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e0c4cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e0c58ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1e0b84;
L_1e0c74:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e0c7cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1e0c98ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_1e0cdc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e0cb4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_1e0ccc;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1e0900;
L_1e0ccc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1e0cd8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e0cf8;
L_1e0cdc:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    goto L_1e0900;
L_1e0cf0:
    cpu->regs[23] = cpu->regs[0];
    goto L_1e0a94;
L_1e0cf8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x293000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[0] + 28),&_a,4); tlb_read(tlb,(cpu->regs[0] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1664ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 20),&_a,4); tlb_read(tlb,(cpu->regs[22] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[30] = PB_BASE + 0x1e0d1cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1e0d20ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e0f38;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1e0968;
L_1e0d48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0d50ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x217260ULL);
    if ((cpu->regs[0])==0) goto L_1e0850;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e0d60ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0850;
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = cpu->regs[6] + 1888ULL;
    goto L_1e09b0;
L_1e0d80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0d88ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_1e0ea8;
L_1e0d90:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_1e0968;
L_1e0d9c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0da4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1e1680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e06f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0db4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1e26acULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e06f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0dc4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1e2924ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[5] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e06fc;
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = 0ULL;
L_1e0de0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0de8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x19e0acULL);
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] + 2080ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1e0e00ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x1a6840ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_1e0774;
    cpu->regs[30] = PB_BASE + 0x1e0e10ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e07cc;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1e07d4;
L_1e0e24:
    cpu->regs[30] = PB_BASE + 0x1e0e28ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e07c8;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1e07d4;
L_1e0e44:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1e0e4cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x116c40ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e0f48;
L_1e0e58:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0e64ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1e1240ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e0f5c;
L_1e0e6c:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    goto L_1e08d4;
L_1e0e74:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e0e80ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e0838;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 20),&_a,4); tlb_read(tlb,(cpu->regs[22] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1848ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 28),&_a,4); tlb_read(tlb,(cpu->regs[22] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_1e09c0;
L_1e0ea8:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    goto L_1e0824;
L_1e0eb0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0eb8ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1e26acULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e0714;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0ec8ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1e2924ULL);
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    cpu->regs[5] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1e0718;
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_1e0de0;
L_1e0ee8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_1e0e58;
L_1e0ef4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0efcULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e06e0;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_1e07d4;
L_1e0f10:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e0f18ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e0890;
L_1e0f1c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1e08d4;
L_1e0f2c:
    cpu->regs[30] = PB_BASE + 0x1e0f30ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    goto L_1e06b0;
L_1e0f38:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1e0960;
L_1e0f48:
    cpu->regs[30] = PB_BASE + 0x1e0f4cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1e0f84;
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1e08d4;
L_1e0f5c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 28),&_a,4); tlb_read(tlb,(cpu->regs[2] + 32),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1912ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 36),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 24),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    goto L_1e09c0;
L_1e0f84:
    cpu->regs[0] = 1ULL;
    cpu->regs[6] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1e08d4;
L_1e0f98:
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[0] = 0ULL;
    goto L_1e0784;
L_1e0fa4:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_1e07d4;
    /* nop */
    /* nop */
    /* nop */
L_1e0fc0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e106c;
L_1e0fe8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e10b4;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e1000ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1e10c4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e1018;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e1014ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e10a0;
L_1e1018:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e108c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e102cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1e10c4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e1044;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e1040ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e1074;
L_1e1044:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_1e104c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e1058:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e106c:
    cpu->regs[30] = PB_BASE + 0x1e1070ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e0fe8;
L_1e1074:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 11ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e1084ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e1044;
    goto L_1e104c;
L_1e108c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e1058;
L_1e10a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e10acULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e104c;
    goto L_1e1018;
L_1e10b4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e1058;
L_1e10c4:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e1214;
L_1e10f0:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1204;
    PB_LDRW(cpu->regs[23], (cpu->regs[21] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1e1104ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e11f8;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1204;
    cpu->regs[24] = 1ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = 0ULL;
    goto L_1e1138;
L_1e1124:
    FLAG_CMP(cpu->regs[24], cpu->regs[20]);
    if (FLAG_EQ) goto L_1e11bc;
L_1e112c:
    PB_LDRW(cpu->regs[23], (cpu->regs[21] + 16));
    PB_STR((cpu->regs[22] + (cpu->regs[20] << 3)), cpu->regs[19]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
L_1e1138:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e1140ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1e1240ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e1124;
    PB_STRW((cpu->regs[21] + 16), cpu->regs[23]);
    if ((cpu->regs[20])==0) goto L_1e11dc;
    PB_LDRW(cpu->regs[19], (cpu->regs[21] + 96));
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_1e11dc;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e1164ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e1184;
    goto L_1e121c;
L_1e1170:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + cpu->regs[1]));
    PB_STR((cpu->regs[0] + cpu->regs[1]), cpu->regs[2]);
L_1e1184:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_GT) goto L_1e1170;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e1198ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e11a4:
    PB_STRW((cpu->regs[21] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1e11bc:
    cpu->regs[24] = cpu->regs[24] << 1;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24] << 3;
    cpu->regs[30] = PB_BASE + 0x1e11ccULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e121c;
    cpu->regs[22] = cpu->regs[0];
    goto L_1e112c;
L_1e11dc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e11e4ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 144));
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e11a4;
L_1e11f8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[21] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e1204ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1e1204:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 144));
    cpu->regs[23] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e11a4;
L_1e1214:
    cpu->regs[30] = PB_BASE + 0x1e1218ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e10f0;
L_1e121c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e1224ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[21] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e1230ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 144));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e11a4;
L_1e1240:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e131c;
L_1e1268:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e130c;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e1280ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e12b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e1294ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e12b8;
L_1e1298:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e12a4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e12b8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e12f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e12ccULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e12e0;
L_1e12d4:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    goto L_1e1298;
L_1e12e0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 11ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e12f0ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1298;
    goto L_1e12d4;
L_1e12f8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e12a4;
L_1e130c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e12a4;
L_1e131c:
    cpu->regs[30] = PB_BASE + 0x1e1320ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e1268;
L_1e1324:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e1448;
L_1e134c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1438;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_1e13e8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20) + 4);
L_1e1370:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e1378ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e13dc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e138cULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e13bc;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[21];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 8));
    cpu->regs[1] = 0ULL;
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e13b4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x19c180ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e1450;
L_1e13bc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1e13c8:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e13dc:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1e13e0:
    cpu->regs[5] = 0ULL;
    goto L_1e13bc;
L_1e13e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e13f0ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e141c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1e1370;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1e13c8;
L_1e141c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[5] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e13c8;
L_1e1438:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[5] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1e13c8;
L_1e1448:
    cpu->regs[30] = PB_BASE + 0x1e144cULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e134c;
L_1e1450:
    cpu->regs[30] = PB_BASE + 0x1e1454ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e13e0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e13c8;
L_1e1470:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e15c0;
L_1e1498:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e159c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e14b0ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x1e1680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e14c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e14c0ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1e1840ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e151c;
L_1e14c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e15ac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e14dcULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x1e1680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e14f4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e14ecULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1e1840ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e1574;
L_1e14f4:
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
L_1e14fc:
    cpu->regs[3] = 0ULL;
L_1e1500:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[5] - 1ULL));
L_1e1508:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e151c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e1528ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e14c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e1538ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e14c8;
L_1e153c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e154cULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x203348ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[5] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_1e1500;
    cpu->regs[30] = PB_BASE + 0x1e1560ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e14fc;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e1508;
L_1e1574:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x1e1580ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e14f4;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 11ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e1594ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e14f4;
    goto L_1e153c;
L_1e159c:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_1e1508;
L_1e15ac:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_1e1508;
L_1e15c0:
    cpu->regs[30] = PB_BASE + 0x1e15c4ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e1498;
}
