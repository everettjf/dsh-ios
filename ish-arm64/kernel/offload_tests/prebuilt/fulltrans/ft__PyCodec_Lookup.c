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

void ft__PyCodec_Lookup(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 96ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[20])==0) goto L_1c7600;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1c738cULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1248));
    if ((cpu->regs[0])==0) goto L_1c7510;
L_1c739c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c73a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[21] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c73b0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c7648;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c73c8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x17c400ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c75d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c73d4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1c73e4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_1c73e4:
    PB_STR((SP + 0), cpu->regs[19]);
    if ((cpu->regs[19])==0) goto L_1c7518;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1c73f8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdc100ULL);
    cpu->regs[21] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1256));
    PB_LDR(cpu->regs[25], (SP + 0));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c740cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c7464;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1c7424;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1c7424:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1c7630;
L_1c742c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1c7538;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1c7464:
    cpu->regs[30] = PB_BASE + 0x1c7468ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1c7560;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1248));
    cpu->regs[30] = PB_BASE + 0x1c7478ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1b0088ULL);
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1c75b0;
    cpu->regs[24] = 0ULL;
    if (FLAG_EQ) goto L_1c75b8;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2760));
L_1c7494:
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1248));
    cpu->regs[30] = PB_BASE + 0x1c74a0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1c4a00ULL);
    if ((cpu->regs[0])==0) goto L_1c75b0;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c74acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c75b0;
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_EQ) goto L_1c7520;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_1c7584;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_NE) goto L_1c7584;
L_1c74d4:
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_EQ) goto L_1c7540;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1c74e8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdb740ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1256));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[25], (SP + 0));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c74fcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c760c;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1c7654;
L_1c7508:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1c742c;
L_1c7510:
    cpu->regs[30] = PB_BASE + 0x1c7514ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1c7680ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c739c;
L_1c7518:
    cpu->regs[19] = 0ULL;
    goto L_1c742c;
L_1c7520:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1c761c;
L_1c7528:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_LE) goto L_1c74d4;
    goto L_1c7494;
L_1c7538:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1c7540ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c7540:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2784));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 296ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c755cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
L_1c7560:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c7518;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c7518;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c7580ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c742c;
L_1c7584:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c759cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c75b0;
L_1c75a4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c7670;
L_1c75b0:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1c7560;
L_1c75b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2784));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c75d0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1c7560;
L_1c75d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 152ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c75f0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c75fcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1c742c;
L_1c7600:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c7608ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x22aba0ULL);
    goto L_1c742c;
L_1c760c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1c75a4;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1c7560;
L_1c761c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c7528;
    cpu->regs[30] = PB_BASE + 0x1c762cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c7528;
L_1c7630:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c742c;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c7644ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c742c;
L_1c7648:
    cpu->regs[30] = PB_BASE + 0x1c764cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1c73e4;
L_1c7654:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c7508;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c7668ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1c742c;
L_1c7670:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c7678ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1c7560;
L_1c7680:
    cpu->regs[1] = cpu->tls_ptr;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1c769cULL; PB_CALL(29, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 1248));
    if ((cpu->regs[0])!=0) goto L_1c7774;
    cpu->regs[30] = PB_BASE + 0x1c76b4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((cpu->regs[23] + 1248), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c7794;
    cpu->regs[30] = PB_BASE + 0x1c76c0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[23] + 1256), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c7794;
    cpu->regs[30] = PB_BASE + 0x1c76ccULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[23] + 1264), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c7794;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x51e000ULL;
    cpu->regs[20] = cpu->regs[20] + 3856ULL;
    cpu->regs[20] = cpu->regs[20] + 2216ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = 0ULL;
L_1c76ec:
    cpu->regs[0] = cpu->regs[20] + 8ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c7700ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xddd20ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c778c;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x1c7714ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1c7960ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c772c;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c779c;
L_1c772c:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1c778c;
    cpu->regs[20] = cpu->regs[20] + 40ULL;
    FLAG_CMP(cpu->regs[22], 8ULL);
    if (FLAG_NE) goto L_1c76ec;
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x1c774cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1c7c60ULL);
    if ((cpu->regs[0])==0) goto L_1c778c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c7764;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1c7784;
L_1c7764:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[23] + 1272), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1c7774:
    cpu->regs[0] = 0ULL;
L_1c7778:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1c7784:
    cpu->regs[30] = PB_BASE + 0x1c7788ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c7764;
L_1c778c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1c7794:
    cpu->regs[0] = 4294967295ULL;
    goto L_1c7778;
L_1c779c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c77a4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c772c;
    SP = SP - 256ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    cpu->regs[5] = SP + 4ULL;
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[19] = PB_BASE + 0x51e000ULL;
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[19] + 3856ULL;
    cpu->regs[22] = 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 168), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x28e000ULL;
    cpu->regs[3] = cpu->regs[19] + 2544ULL;
    cpu->regs[2] = cpu->regs[2] + 336ULL;
    PB_STRW((SP + 4), cpu->regs[22]);
    PB_STR((SP + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c7808ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c7930;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c7814ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1c7a00ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c7930;
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1c7828ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1c8584ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[0])==0) goto L_1c7944;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2544));
    PB_STR((cpu->regs[20] + 2544), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c7848ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 2536));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 16));
    PB_STRW((cpu->regs[20] + 2552), cpu->regs[21]);
    PB_LDRW(cpu->regs[2], (SP + 4));
    PB_STRW((cpu->regs[20] + 2556), cpu->regs[2]);
    PB_STR((cpu->regs[20] + 2560), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c78d0;
    PB_STRW((cpu->regs[20] + 2536), cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1c786cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1c8830ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c7938;
    cpu->regs[21] = PB_BASE + 0x9e000ULL;
    cpu->regs[19] = cpu->regs[19] + 2568ULL;
    cpu->regs[21] = cpu->regs[21] + 1812ULL;
    cpu->regs[24] = SP + 24ULL;
    PB_STR((SP + 240), cpu->regs[25]);
    cpu->regs[25] = SP + 16ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[23] = 1207959552ULL;
L_1c7894:
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 16), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1c78a0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7b610ULL);
    PB_STRW((SP + 152), cpu->regs[23]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[19] + 16ULL;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c78b4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x7c030ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c7918;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_STRW((cpu->regs[19] + 4), cpu->regs[22]);
    cpu->regs[19] = cpu->regs[19] + 176ULL;
    FLAG_CMP(cpu->regs[20], 5ULL);
    if (FLAG_NE) goto L_1c7894;
    PB_LDR(cpu->regs[25], (SP + 240));
L_1c78d0:
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1c78dc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1c790c;
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    SP = SP + 256ULL;
    return;
L_1c790c:
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    PB_STR((SP + 240), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x1c7918ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c7918:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c7928ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1b2720ULL);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[25], (SP + 240));
L_1c7930:
    cpu->regs[0] = 0ULL;
    goto L_1c78dc;
L_1c7938:
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    cpu->regs[0] = 0ULL;
    goto L_1c78dc;
L_1c7944:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1c794cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    goto L_1c78dc;
    /* nop */
    /* nop */
}
