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

void ft_Py_FinalizeEx(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 144ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDRW(cpu->regs[19], (cpu->regs[22] + 16));
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1c3814;
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1c35b4ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[21] = 1ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 16));
    PB_STRW((cpu->regs[1] + 44), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1c35d0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1e9380ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1c35d8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e94ccULL);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    cpu->regs[0] = cpu->regs[0] + 3928ULL;
    cpu->regs[30] = PB_BASE + 0x1c35e4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1e9804ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    cpu->regs[1] = cpu->regs[24];
    PB_LDRW(cpu->regs[25], (cpu->regs[0] + 1352));
    cpu->regs[30] = PB_BASE + 0x1c35f4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e98e0ULL);
    cpu->regs[0] = cpu->regs[22] + 24ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[22] + (18ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 136));
    cpu->regs[0] = cpu->regs[0] + 1920ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[24];
    PB_STR((cpu->regs[22] + 12), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c3618ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e9908ULL);
    cpu->regs[19] = cpu->regs[22] + 488ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[30] = PB_BASE + 0x1c3628ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1e99c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[26] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_1c364c;
L_1c3634:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1c3640ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(65ULL)));
    if (FLAG_EQ) goto L_1c3698;
L_1c364c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[19] - 8ULL;
    PB_STRW((cpu->regs[0] + 0), 0ULL);
    PB_STR((cpu->regs[19] + 0), 0ULL);
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[23]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1c3634;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1520));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c3674ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e9bc4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c3634;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 1528));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c3684ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1e9bc4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c3634;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c3694ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d3690ULL);
    goto L_1c3634;
L_1c3698:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1520));
    if ((cpu->regs[0])==0) goto L_1c36ac;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[22] + 1520), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1c389c;
L_1c36ac:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1528));
    if ((cpu->regs[0])==0) goto L_1c36c0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[22] + 1528), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1c3888;
L_1c36c0:
    cpu->regs[30] = PB_BASE + 0x1c36c4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1e9c0cULL);
    cpu->regs[20] = SP + 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    cpu->regs[30] = PB_BASE + 0x1c36d0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1e9f50ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1c36d8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1ea00cULL);
    cpu->regs[30] = PB_BASE + 0x1c36dcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1e99c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1c36e8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1ebbe8ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    cpu->regs[30] = PB_BASE + 0x1c36f0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1ebc64ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1928));
    cpu->regs[30] = PB_BASE + 0x1c36f8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x144810ULL);
    PB_STR((cpu->regs[22] + 1928), 0ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c3708ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x17a7a8ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1904));
    PB_STR((cpu->regs[22] + 1904), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c3714ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c3720ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x17ac80ULL);
    cpu->regs[30] = PB_BASE + 0x1c3724ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1ebda4ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1c372cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x159390ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 2704));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1c377c;
    cpu->regs[0] = 2ULL;
    PB_STRW((cpu->regs[22] + 2704), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1c3744ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1ebbe8ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 2896));
    cpu->regs[30] = PB_BASE + 0x1c374cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x144810ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 2888));
    cpu->regs[30] = PB_BASE + 0x1c3754ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x144810ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 2880));
    cpu->regs[30] = PB_BASE + 0x1c375cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x144810ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 2864));
    cpu->regs[30] = PB_BASE + 0x1c3764ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x144810ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 2840));
    if ((cpu->regs[0])==0) goto L_1c3774;
    cpu->regs[30] = PB_BASE + 0x1c3770ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1c208cULL);
    PB_STR((cpu->regs[22] + 2840), 0ULL);
L_1c3774:
    cpu->regs[0] = cpu->regs[22] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x1c377cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1f5fa0ULL);
L_1c377c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[25])))!=0) goto L_1c3880;
L_1c3790:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1c37a8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 96));
    PB_STR((cpu->regs[1] + 2504), 0ULL);
L_1c37a8:
    cpu->regs[30] = PB_BASE + 0x1c37acULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1f61c8ULL);
    cpu->regs[20] = PB_BASE + 0x5ac000ULL;
    cpu->regs[30] = PB_BASE + 0x1c37b4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1f6ae0ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1632));
    cpu->regs[2] = cpu->regs[20] + 3792ULL;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[22] + 392), 0ULL);
    PB_STR((cpu->regs[2] + 3792), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1c37d0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x17f520ULL);
L_1c37d0:
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 1896));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1632));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1c3854;
    cpu->regs[30] = PB_BASE + 0x1c37e4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3344));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c37f4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7b050ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x1c37fcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7b050ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[30] = PB_BASE + 0x1c3808ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1f6c24ULL);
    PB_STRW((cpu->regs[20] + 3792), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
L_1c3814:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1c3848;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 144ULL;
    return;
L_1c3848:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1c3854ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c3854:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[22] + 1896), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 1640));
    PB_STR((cpu->regs[1] + 1640), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c386cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[30] = PB_BASE + 0x1c3870ULL; PB_CALL(40, cpu, tlb, cpu->regs[21]);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 1632));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1c387cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x17f520ULL);
    goto L_1c37d0;
L_1c3880:
    cpu->regs[30] = PB_BASE + 0x1c3884ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x8fc6cULL);
    goto L_1c3790;
L_1c3888:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c36c0;
    cpu->regs[30] = PB_BASE + 0x1c3898ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c36c0;
L_1c389c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c36ac;
    cpu->regs[30] = PB_BASE + 0x1c38acULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c36ac;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[3] = PB_BASE + 0x1c3000ULL;
    cpu->regs[3] = cpu->regs[3] + 2468ULL;
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[2] = 16ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1c38e4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x7ab80ULL);
    cpu->regs[30] = PB_BASE + 0x1c38e8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xd94a0ULL);
    if ((cpu->regs[0])==0) goto L_1c3974;
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[20] + (((cpu->regs[24]) & 0xffffffffULL) << 4);
L_1c38f4:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 8),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1c38fcULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    if ((cpu->regs[19])==0) goto L_1c3950;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x1c3914ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c3950;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 0));
    if (!((cpu->regs[4] >> 31) & 1)) goto L_1c398c;
L_1c3924:
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[24]);
    if (FLAG_NE) goto L_1c38f4;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(49, cpu, tlb, PB_BASE + 0x1ab4d0ULL); return; };
L_1c3950:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c3958ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c3974;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c3974;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1c3974ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1c3974:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1c398c:
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[4]);
    if ((cpu->regs[4])!=0) goto L_1c3924;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c39a0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c3924;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    { PB_CALL(53, cpu, tlb, PB_BASE + 0x7ae60ULL); return; };
}
