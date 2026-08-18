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

void ft__PyErr_SetLocaleString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 2984ULL;
    cpu->regs[30] = PB_BASE + 0xaed10ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1b28d0ULL);
    if ((cpu->regs[0])==0) goto L_aed60;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaed2cULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0xaed3cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x120824ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_aed60;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_aed60;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_aed60:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xaed7cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aed90;
    cpu->regs[30] = PB_BASE + 0xaed8cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aedec;
L_aed90:
    cpu->regs[1] = PB_BASE + 0x3db000ULL;
    cpu->regs[1] = cpu->regs[1] + 2816ULL;
    cpu->regs[1] = cpu->regs[1] + 856ULL;
L_aed9c:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    if ((cpu->regs[0])==0) goto L_aedd4;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + -8));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_aed9c;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaedbcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7af20ULL);
    if ((cpu->regs[0])!=0) goto L_aedc8;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
L_aedc8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[1] = 0ULL;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x1b28d0ULL); return; };
L_aedd4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaedecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_aedec:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_aee58;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2216ULL;
    cpu->regs[30] = PB_BASE + 0xaee54ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_aeec4;
L_aee58:
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xaee60ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_aeec4;
    cpu->regs[30] = PB_BASE + 0xaee6cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_aee94;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaee90ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aeec4;
L_aee94:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaee9cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7abc0ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_aeed8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x1b28d0ULL); return; };
L_aeec4:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_aeedc;
L_aeed8:
    cpu->regs[30] = PB_BASE + 0xaeedcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_aeedc:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_aef44;
L_aef2c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_aef64;
    goto L_aefb8;
L_aef44:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2224ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaef5cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aef2c;
    goto L_af064;
L_aef64:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_aef94;
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xaef78ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af064;
    cpu->regs[30] = PB_BASE + 0xaef84ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_aefbc;
    goto L_af010;
L_aef94:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2224ULL;
    cpu->regs[30] = PB_BASE + 0xaefb4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af064;
L_aefb8:
    cpu->regs[19] = 0ULL;
L_aefbc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_aeff0;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2224ULL;
    cpu->regs[30] = PB_BASE + 0xaefecULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af064;
L_aeff0:
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xaeff8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af064;
    cpu->regs[30] = PB_BASE + 0xaf004ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af02c;
L_af010:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf028ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af064;
L_af02c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf038ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7b940ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_af078;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0x1b28d0ULL); return; };
L_af064:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_af07c;
L_af078:
    cpu->regs[30] = PB_BASE + 0xaf07cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af07c:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[2], 3ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3080));
    if (FLAG_NE) goto L_af0e8;
L_af0d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_af108;
    goto L_af15c;
L_af0e8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 2240ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaf100ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_af0d0;
    goto L_af228;
L_af108:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_af138;
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xaf11cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af228;
    cpu->regs[30] = PB_BASE + 0xaf128ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af160;
    goto L_af1b4;
L_af138:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2240ULL;
    cpu->regs[30] = PB_BASE + 0xaf158ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af228;
L_af15c:
    cpu->regs[19] = 0ULL;
L_af160:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_af194;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2240ULL;
    cpu->regs[30] = PB_BASE + 0xaf190ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af228;
L_af194:
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xaf19cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af228;
    cpu->regs[30] = PB_BASE + 0xaf1a8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af1d0;
L_af1b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf1ccULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af228;
L_af1d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0xaf1d8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_af1ec;
    cpu->regs[30] = PB_BASE + 0xaf1e8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_af228;
L_af1ec:
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf1fcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7bac0ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_af23c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    { PB_CALL(39, cpu, tlb, PB_BASE + 0x1b28d0ULL); return; };
L_af228:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_af240;
L_af23c:
    cpu->regs[30] = PB_BASE + 0xaf240ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af240:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3080));
    if (FLAG_EQ) goto L_af304;
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_af2e0;
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xaf2acULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af350;
    cpu->regs[30] = PB_BASE + 0xaf2b8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af308;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf2dcULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af350;
L_af2e0:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2256ULL;
    cpu->regs[30] = PB_BASE + 0xaf300ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af350;
L_af304:
    cpu->regs[19] = 0ULL;
L_af308:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaf310ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x7b930ULL);
    if ((cpu->regs[0])!=0) goto L_af328;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf324ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_af350;
L_af328:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_af364;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    { PB_CALL(47, cpu, tlb, PB_BASE + 0x1b28d0ULL); return; };
L_af350:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_af368;
L_af364:
    cpu->regs[30] = PB_BASE + 0xaf368ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af368:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 80ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_af3ec;
L_af3b8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_af40c;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2272ULL;
    cpu->regs[30] = PB_BASE + 0xaf3e8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af41c;
L_af3ec:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2272ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaf404ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_af3b8;
    goto L_af41c;
L_af40c:
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0xaf414ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_af424;
L_af41c:
    cpu->regs[0] = 0ULL;
    goto L_af4fc;
L_af424:
    cpu->regs[30] = PB_BASE + 0xaf428ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_af474;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af4b4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_af490;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xaf45cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_af41c;
    cpu->regs[30] = PB_BASE + 0xaf468ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_af4b8;
L_af474:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaf48cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_af41c;
L_af490:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 2272ULL;
    cpu->regs[30] = PB_BASE + 0xaf4b0ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_af41c;
L_af4b4:
    cpu->regs[19] = 0ULL;
L_af4b8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaf4c4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x7be80ULL);
    if ((cpu->regs[0])==0) goto L_af4f4;
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_af510;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64));
    SP = SP + 80ULL;
    { PB_CALL(58, cpu, tlb, PB_BASE + 0x1b28d0ULL); return; };
L_af4f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_af4fc:
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_af514;
L_af510:
    cpu->regs[30] = PB_BASE + 0xaf514ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x7c170ULL);
L_af514:
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
    cpu->regs[0] = 1ULL;
    { PB_CALL(60, cpu, tlb, PB_BASE + 0x1ef4c8ULL); return; };
}
