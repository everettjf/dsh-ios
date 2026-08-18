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

void ft_PyEval_EvalCode(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    cpu->regs[4] = cpu->tls_ptr;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1964e8ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    FLAG_CMP(cpu->regs[2], 0ULL);
    PB_LDR(cpu->regs[22], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[20] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x196518ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1965ccULL);
    if ((cpu->regs[0])==0) goto L_1965c4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 120));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = SP;
    PB_STR((SP + 0), cpu->regs[21]); PB_STR((SP + 0) + 8, cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[1]); PB_STR((SP + 16) + 8, cpu->regs[1]);
    PB_STR((SP + 32), cpu->regs[19]);
    PB_STR((SP + 40), 0ULL); PB_STR((SP + 40) + 8, 0ULL);
    PB_STR((SP + 56), 0ULL);
    cpu->regs[30] = PB_BASE + 0x196540ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x19668cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1965c4;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x196564ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_19658c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_19658c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x19658cULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
L_19658c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1965c0;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_1965c0:
    cpu->regs[30] = PB_BASE + 0x1965c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1965c4:
    cpu->regs[20] = 0ULL;
    goto L_19658c;
L_1965cc:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 26488ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1965f4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_196630;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_196624;
L_196610:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 16));
L_196614:
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_196624:
    cpu->regs[30] = PB_BASE + 0x196628ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_196614;
    goto L_196610;
L_196630:
    cpu->regs[30] = PB_BASE + 0x196634ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_196614;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x196148ULL); return; };
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] << 3;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_196668;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
L_196668:
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((cpu->regs[3] + cpu->regs[1]), cpu->regs[0]);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_196678;
L_196674:
    return;
L_196678:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_196674;
    cpu->regs[0] = cpu->regs[4];
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_19668c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 30760ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1966b8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1967d4;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1966d0;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_1966d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3680));
    cpu->regs[30] = PB_BASE + 0x1966dcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_196838;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1966f8;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_1966f8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_196710;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_196710:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_196830;
L_196724:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[19] + 32), cpu->regs[3]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_196828;
L_196738:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[19] + 40), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_196750;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_196750:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    if ((cpu->regs[0])!=0) goto L_196814;
L_19675c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 48));
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    if ((cpu->regs[1])!=0) goto L_196800;
L_196768:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    PB_STR((cpu->regs[19] + 64), cpu->regs[1]);
    if ((cpu->regs[0])!=0) goto L_1967ec;
L_196774:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_STR((cpu->regs[19] + 72), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1967e4;
L_19678c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3648));
    PB_STR((cpu->regs[19] + 80), cpu->regs[2]); PB_STR((cpu->regs[19] + 80) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((cpu->regs[19] + 96), 0ULL); PB_STR((cpu->regs[19] + 96) + 8, cpu->regs[21]);
    PB_STR((cpu->regs[19] + 112), 0ULL); PB_STR((cpu->regs[19] + 112) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 128), cpu->regs[1]);
    PB_STRW((cpu->regs[19] + 136), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1967b0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xd9444ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1967c0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x196848ULL);
L_1967c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1967d4:
    cpu->regs[30] = PB_BASE + 0x1967d8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1966d0;
    cpu->regs[19] = 0ULL;
    goto L_1967c0;
L_1967e4:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_19678c;
L_1967ec:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_196774;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_196774;
L_196800:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_196768;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_196768;
L_196814:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_19675c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_19675c;
L_196828:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_196738;
L_196830:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_196724;
L_196838:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x196844ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1967c0;
L_196848:
    cpu->regs[4] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x196868ULL; PB_CALL(18, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 1816));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_196880;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_196880:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[5];
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x9b854ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[3] = cpu->regs[0] + (4ULL << 12);
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = 96ULL;
    cpu->regs[29] = SP;
    cpu->regs[7] = 96ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 880));
    cpu->regs[6] = 2864ULL;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[4] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[3] = cpu->regs[6] + (uint64_t)((int64_t)(int32_t)cpu->regs[3] * (int64_t)(int32_t)cpu->regs[7]);
    cpu->regs[4] = cpu->regs[4] * cpu->regs[5] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[0] + cpu->regs[3];
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 2864));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1968f8;
    cpu->regs[30] = PB_BASE + 0x1968e4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf41c0ULL);
L_1968e4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 2748));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_196900;
L_1968ec:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1968f8:
    cpu->regs[30] = PB_BASE + 0x1968fcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x119e90ULL);
    goto L_1968e4;
L_196900:
    cpu->regs[1] = 22ULL;
    cpu->regs[0] = 66ULL;
    PB_STRW((cpu->regs[19] + 64), cpu->regs[1]);
    goto L_1968ec;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 28));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[0] + 28), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_19692c;
    cpu->regs[0] = 0ULL;
    return;
L_19692c:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x196938ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x273360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[22] = cpu->regs[21] + 368ULL;
    cpu->regs[23] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20] + 1948ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_196a74;
L_196980:
    cpu->regs[0] = cpu->regs[21] + 416ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_196a60;
    cpu->regs[30] = PB_BASE + 0x196990ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xd7750ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 64));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1969b4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_1969b4;
    cpu->regs[0] = cpu->regs[20] + 1968ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_196a60;
L_1969b4:
    cpu->regs[0] = cpu->regs[23] + 396ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1969dc;
    PB_STRW((cpu->regs[0] + 0), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20] + 1944ULL;
    cpu->regs[30] = PB_BASE + 0x1969d4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x182ec0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1969dcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x196b70ULL);
L_1969dc:
    cpu->regs[0] = cpu->regs[23] + 372ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_196a18;
L_1969e8:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 128));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[21])!=0) goto L_196a84;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20] + 1944ULL;
    cpu->regs[30] = PB_BASE + 0x196a00ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x182ec0ULL);
    cpu->regs[0] = 0ULL;
L_196a04:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_196a18:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x196a20ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x182b00ULL);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_196acc;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x196a34ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x14770cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x196a3cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xd8448ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x196a44ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x182b00ULL);
    if ((cpu->regs[0])==0) goto L_1969e8;
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[0] + 3360ULL;
    cpu->regs[1] = cpu->regs[1] + 1824ULL;
    cpu->regs[30] = PB_BASE + 0x196a60ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x91ebcULL);
L_196a60:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x196a68ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1dd564ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1969b4;
L_196a6c:
    cpu->regs[0] = 4294967295ULL;
    goto L_196a04;
L_196a74:
    cpu->regs[30] = PB_BASE + 0x196a78ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1dd4e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_196a6c;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_196980;
L_196a84:
    cpu->regs[2] = cpu->regs[0] + 368ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 96));
    PB_STR((cpu->regs[19] + 128), 0ULL);
    PB_STRW((cpu->regs[2] + 52), 0ULL);
    cpu->regs[1] = cpu->regs[1] + 1944ULL;
    cpu->regs[30] = PB_BASE + 0x196a9cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x182ec0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x196aa8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x96e30ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_196a6c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_196a6c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x196ac4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_196a04;
L_196acc:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[0] + 3360ULL;
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x196ae4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x91ebcULL);
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_196b54;
L_196b00:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[2] << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_196b28;
L_196b18:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_196b28:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x196b34ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1063e8ULL);
    if ((cpu->regs[0])==0) goto L_196b64;
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x196b40ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_196b18;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0x10642cULL); return; };
L_196b54:
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x196b5cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf27b0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_196b00;
L_196b64:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_196b18;
L_196b70:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2] + 112ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 12));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_196bbc;
    cpu->regs[2] = cpu->regs[2] + 200ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[1] = 2ULL;
    PB_STRW((cpu->regs[19] + 200), cpu->regs[3]);
L_196b9c:
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 0)); PB_LDRW(cpu->regs[4], (cpu->regs[2] + 0) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_GT) goto L_196bc8;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[2] = cpu->regs[2] - 24ULL;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_196b9c;
L_196bb8:
    PB_STRW((cpu->regs[19] + 200), 0ULL);
L_196bbc:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_196bc8:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_196bd8;
L_196bd0:
    cpu->regs[30] = PB_BASE + 0x196bd4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x196c00ULL);
    goto L_196bb8;
L_196bd8:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 224)); PB_LDR(cpu->regs[4], (cpu->regs[19] + 224) + 8);
    cpu->regs[5] = 4ULL;
    cpu->regs[2] = cpu->regs[2] - 24ULL;
    cpu->regs[3] = (cpu->regs[5] ? (uint64_t)((int64_t)cpu->regs[3] / (int64_t)cpu->regs[5]) : 0);
    FLAG_CMP(cpu->regs[4], cpu->regs[3]);
    if (FLAG_GE) goto L_196bd0;
    cpu->regs[1] = 1ULL;
    goto L_196b9c;
    /* nop */
    /* nop */
L_196c00:
    SP = SP - 64ULL;
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 2280ULL;
    cpu->regs[30] = PB_BASE + 0x196c44ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x196d80ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x196c5cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x106540ULL);
    PB_LDR(cpu->regs[4], (SP + 8)); PB_LDR(cpu->regs[3], (SP + 8) + 8);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[1] + 2288ULL;
    cpu->regs[30] = PB_BASE + 0x196c78ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x196d80ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_196ca8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_196ca8:
    cpu->regs[30] = PB_BASE + 0x196cacULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7c170ULL);
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[3], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_196d4c;
L_196cc8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[3] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[3] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 40));
    if ((cpu->regs[3])==0) goto L_196d44;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_196d24;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    if ((cpu->regs[3])==0) goto L_196d44;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_196d24;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    if ((cpu->regs[3])==0) goto L_196d44;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_196d24;
L_196d10:
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    if ((cpu->regs[3])==0) goto L_196d44;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_196d10;
L_196d24:
    PB_LDRW(cpu->regs[4], (cpu->regs[3] + 16));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[4]);
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
L_196d38:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_196d44:
    cpu->regs[0] = 0ULL;
    goto L_196d38;
L_196d4c:
    PB_STRW((SP + 36), cpu->regs[1]);
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x196d58ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xf27b0ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDRW(cpu->regs[1], (SP + 36));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_196cc8;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = 4294967295ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_196d38;
    /* nop */
    /* nop */
    /* nop */
L_196d80:
    SP = SP - 96ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0] + 112ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 216));
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    if ((cpu->regs[5])==0) goto L_196e10;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[21] = 0ULL;
    if ((cpu->regs[0])!=0) goto L_196e40;
L_196dc4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x196dccULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_196ee8;
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 0), cpu->regs[0]); PB_STR((SP + 0) + 8, cpu->regs[21]);
L_196ddc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 216));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_LT) goto L_196e98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_196e08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_196e08;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x196e08ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_196e08:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x196e10ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x18d760ULL);
L_196e10:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_196e90;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_196e40:
    cpu->regs[6] = cpu->regs[4];
    cpu->regs[5] = PB_BASE + 0x286000ULL;
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[5] = cpu->regs[5] + 2296ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 2312ULL;
    cpu->regs[1] = cpu->regs[1] + 736ULL;
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[0] + 2328ULL;
    cpu->regs[30] = PB_BASE + 0x196e6cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_196dc4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_196f10;
L_196e90:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x196e98ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x7c170ULL);
L_196e98:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_STR((SP + 80), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + (cpu->regs[22] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_196eb4;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_196eb4:
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x196ec8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x11028cULL);
    if ((cpu->regs[0])==0) goto L_196f24;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_196f2c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_196f2c;
    cpu->regs[30] = PB_BASE + 0x196ee4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_196f2c;
L_196ee8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x196ef0ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    if (FLAG_NE) goto L_196e90;
L_196f10:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    { PB_CALL(56, cpu, tlb, PB_BASE + 0x1fa20cULL); return; };
L_196f24:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x196f2cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_196f2c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_196f40;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_196f4c;
L_196f40:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_196ddc;
L_196f4c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x196f54ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_196f40;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->tls_ptr;
L_196f7c:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_196fa4;
    goto L_196fdc;
L_196f88:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 1ULL;
    cpu->regs[0] = cpu->regs[2] | (cpu->regs[0] << 2);
    cpu->regs[0] = cpu->regs[0] | 2ULL;
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_EQ) goto L_196fdc;
L_196fa4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_196f88;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x196fc4ULL; PB_CALL(59, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 16));
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    cpu->regs[30] = PB_BASE + 0x196fd8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x196fecULL);
    goto L_196f7c;
L_196fdc:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_196fec:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[3], (cpu->regs[0] + 0) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 8));
    cpu->regs[3] = cpu->regs[3] & 18446744073709551612ULL;
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[4]);
    cpu->regs[2] = cpu->regs[2] | cpu->regs[3];
    PB_STR((cpu->regs[4] + 8), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[2] = cpu->regs[2] | cpu->regs[3];
    PB_STR((cpu->regs[0] + 8), cpu->regs[2]);
    PB_STR((cpu->regs[3] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19709c;
    cpu->regs[19] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1970c8;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x19706cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1970bc;
    cpu->regs[1] = 24ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[20]);
    PB_STRW((cpu->regs[0] + 16), cpu->regs[19]);
    PB_STRW((cpu->regs[0] + 32), cpu->regs[23]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[21]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_197090:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_19709c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 2704ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1970b4ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_197090;
L_1970bc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_197090;
L_1970c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 2736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1970e0ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_197090;
    cpu->regs[5] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(62ULL)));
    cpu->regs[0] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 3ULL); } else { FLAG_CMP(0, 0); }
    PB_LDRW(cpu->regs[6], (cpu->regs[5] + 528));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 512));
    PB_STRW((cpu->regs[1] + 0), cpu->regs[6]);
    cpu->regs[7] = cpu->regs[2];
    if (FLAG_EQ) goto L_19713c;
L_19710c:
    cpu->regs[6] = 4294967295ULL;
    PB_STRW((cpu->regs[1] + 4), cpu->regs[7]); PB_STRW((cpu->regs[1] + 4) + 4, cpu->regs[6]);
    PB_STRW((cpu->regs[1] + 12), cpu->regs[2]); PB_STRW((cpu->regs[1] + 12) + 4, cpu->regs[6]);
    FLAG_CMP(cpu->regs[3], 0ULL);
    PB_STR((cpu->regs[1] + 24), cpu->regs[3]); PB_STR((cpu->regs[1] + 24) + 8, cpu->regs[4]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_197138;
    PB_LDRW(cpu->regs[3], (cpu->regs[5] + 520));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 524));
    PB_STRW((cpu->regs[1] + 8), cpu->regs[3]);
    PB_STRW((cpu->regs[1] + 16), cpu->regs[2]);
L_197138:
    return;
L_19713c:
    PB_LDRW(cpu->regs[7], (cpu->regs[5] + 516));
    goto L_19710c;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    cpu->regs[6] = cpu->regs[4] << 4;
    cpu->regs[5] = cpu->regs[1] + (cpu->regs[4] << 4);
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_GT) goto L_197254;
    PB_LDR(cpu->regs[6], (cpu->regs[1] + cpu->regs[6]));
    cpu->regs[1] = PB_BASE + 0x51d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    FLAG_CMP(cpu->regs[6], 0ULL);
    cpu->regs[1] = cpu->regs[1] + 1784ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[6], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_197210;
    cpu->regs[6] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_LT) goto L_1971f8;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_197208;
    cpu->regs[6] = cpu->regs[4] + 2ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_LT) goto L_1971f8;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 32));
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_19723c;
    cpu->regs[6] = cpu->regs[4] + 3ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_LT) goto L_1971f8;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 48));
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_197248;
    cpu->regs[6] = cpu->regs[4] + 4ULL;
    cpu->regs[5] = cpu->regs[5] + 64ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_LT) goto L_1971f8;
L_1971d8:
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 0));
    FLAG_CMP(cpu->regs[4], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_197224;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[5] = cpu->regs[5] + 16ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_GE) goto L_1971d8;
L_1971f8:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[6]);
L_197204:
    return;
L_197208:
    cpu->regs[5] = cpu->regs[5] + 16ULL;
    cpu->regs[4] = cpu->regs[6];
L_197210:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
L_197218:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[5]);
    return;
L_197224:
    cpu->regs[1] = cpu->regs[6] + 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_GE) goto L_197218;
    cpu->regs[0] = 0ULL;
    goto L_197204;
L_19723c:
    cpu->regs[5] = cpu->regs[5] + 32ULL;
    cpu->regs[4] = cpu->regs[6];
    goto L_197210;
L_197248:
    cpu->regs[5] = cpu->regs[5] + 48ULL;
    cpu->regs[4] = cpu->regs[6];
    goto L_197210;
L_197254:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
    goto L_197204;
    { PB_CALL(64, cpu, tlb, PB_BASE + 0x280560ULL); return; };
}
