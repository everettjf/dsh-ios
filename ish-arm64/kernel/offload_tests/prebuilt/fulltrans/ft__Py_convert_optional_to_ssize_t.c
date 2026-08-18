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

void ft__Py_convert_optional_to_ssize_t(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_155718;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 96));
    if ((cpu->regs[1])==0) goto L_1556f4;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 264));
    if ((cpu->regs[1])==0) goto L_1556f4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2584));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1556c4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1556e4;
L_1556d0:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
L_1556d8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1556e4:
    cpu->regs[30] = PB_BASE + 0x1556e8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1556d0;
    cpu->regs[0] = 0ULL;
    goto L_1556d8;
L_1556f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 456ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x155710ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1556d8;
L_155718:
    cpu->regs[0] = 1ULL;
    return;
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[5] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[3];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = 1ULL;
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[2] + 536ULL;
    cpu->regs[30] = PB_BASE + 0x155778ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x15594cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_155908;
    PB_LDR(cpu->regs[19], (SP + 8));
    if ((cpu->regs[19])==0) goto L_155910;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15578cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_155908;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15579cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x136924ULL);
    if ((cpu->regs[0])==0) goto L_1558ec;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_155938;
L_1557a8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 57224ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1557c0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1558ec;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1557dcULL; PB_CALL(8, cpu, tlb, cpu->regs[4]);
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[1] = cpu->regs[20] + 8ULL;
    cpu->regs[2] = cpu->regs[21] - 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 168));
    PB_LDR(cpu->regs[24], (cpu->regs[5] + cpu->regs[0]));
    if (!((cpu->regs[4] >> 11) & 1)) goto L_1558c0;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 56));
    cpu->regs[3] = SP + 24ULL;
    cpu->regs[0] = SP + 16ULL;
    cpu->regs[5] = cpu->regs[19] + cpu->regs[4];
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[0], cpu->regs[5]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_15591c;
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_HS) goto L_1558b8;
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_LO) goto L_15591c;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + cpu->regs[4]));
    if ((cpu->regs[4])==0) goto L_1558c0;
L_15582c:
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x155838ULL; PB_CALL(9, cpu, tlb, cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15584cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe8888ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_155874;
L_155858:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_155874;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x155874ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
L_155874:
    if ((cpu->regs[20])==0) goto L_1558ec;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_155920;
L_155880:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1558e8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1558b8:
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 0));
    if ((cpu->regs[4])!=0) goto L_15582c;
L_1558c0:
    cpu->regs[3] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1558d8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xea120ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_155858;
    goto L_155874;
L_1558e8:
    cpu->regs[30] = PB_BASE + 0x1558ecULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1558ec:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_155908;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_155908;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x155908ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_155908:
    cpu->regs[22] = 0ULL;
    goto L_155880;
L_155910:
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x155918ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_155880;
L_15591c:
    __builtin_trap();
L_155920:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_155880;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x155934ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_155880;
L_155938:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1557a8;
    cpu->regs[30] = PB_BASE + 0x155948ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1557a8;
}
