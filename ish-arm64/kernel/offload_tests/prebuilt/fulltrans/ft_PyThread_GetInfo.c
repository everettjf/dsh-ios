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

void ft_PyThread_GetInfo(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 304ULL;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 272), cpu->regs[29]); PB_STR((SP + 272) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 272ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1907f4ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = PB_BASE + 0x51d000ULL;
    cpu->regs[2] = cpu->regs[2] + 3600ULL;
    PB_STR((SP + 288), cpu->regs[19]); PB_STR((SP + 288) + 8, cpu->regs[20]);
    cpu->regs[19] = PB_BASE + 0x5ac000ULL;
    cpu->regs[19] = cpu->regs[19] + 3792ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 264), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 3376ULL;
    cpu->regs[2] = cpu->regs[2] + 1800ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x190830ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18e5ecULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_19091c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x190840ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe51acULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19091c;
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 840ULL;
    cpu->regs[30] = PB_BASE + 0x190854ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdea4cULL);
    if ((cpu->regs[0])==0) goto L_190908;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 848ULL;
    cpu->regs[30] = PB_BASE + 0x190868ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdea4cULL);
    if ((cpu->regs[0])==0) goto L_190908;
    cpu->regs[20] = SP + 8ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 255ULL;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x190884ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c0f0ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(252ULL)));
    if (FLAG_LS) goto L_1908ec;
L_190890:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1908e4;
L_1908a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1908ac:
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
L_1908b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 264));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1908e0;
    PB_LDR(cpu->regs[29], (SP + 272)); PB_LDR(cpu->regs[30], (SP + 272) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 288)); PB_LDR(cpu->regs[20], (SP + 288) + 8);
    SP = SP + 304ULL;
    return;
L_1908e0:
    cpu->regs[30] = PB_BASE + 0x1908e4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1908e4:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1908a4;
L_1908ec:
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0x1908fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1931c8ULL);
    if ((cpu->regs[0])!=0) goto L_1908ac;
    cpu->regs[30] = PB_BASE + 0x190904ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_190890;
L_190908:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_19091c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_190924;
L_19091c:
    cpu->regs[19] = 0ULL;
    goto L_1908b0;
L_190924:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x190930ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1908b0;
    /* nop */
    /* nop */
    /* nop */
}
