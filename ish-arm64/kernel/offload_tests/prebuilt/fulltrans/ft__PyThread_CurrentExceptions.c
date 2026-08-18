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

void ft__PyThread_CurrentExceptions(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_a4074:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa4090ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_STR((SP + 64), cpu->regs[25]);
    if ((cpu->regs[0])!=0) goto L_a40c0;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 1432ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0xa40c0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x91ebcULL);
L_a40c0:
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3008ULL;
    cpu->regs[30] = PB_BASE + 0xa40d0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x181ea8ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a40dc;
L_a40d4:
    cpu->regs[19] = 0ULL;
    goto L_a41a4;
L_a40dc:
    cpu->regs[30] = PB_BASE + 0xa40e0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a40d4;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = 1ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    cpu->regs[30] = PB_BASE + 0xa4104ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[22], (cpu->regs[23] + 40));
L_a4108:
    if ((cpu->regs[22])==0) goto L_a419c;
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 72));
L_a4110:
    if ((cpu->regs[21])==0) goto L_a4174;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa411cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x21eda0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 136));
    cpu->regs[30] = PB_BASE + 0xa4128ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a417c;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 0));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xa4148ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a4168;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a4168;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa4168ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a4168:
    if (((cpu->regs[24] >> 31) & 1)) goto L_a417c;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 8));
    goto L_a4110;
L_a4174:
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 0));
    goto L_a4108;
L_a417c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a4198;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a4198;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa4198ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a4198:
    cpu->regs[19] = 0ULL;
L_a419c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    cpu->regs[30] = PB_BASE + 0xa41a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_a41a4:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    goto L_a4074;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 27464ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = cpu->regs[22] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xa41e8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xed3ccULL);
    if ((cpu->regs[0])==0) goto L_a4230;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 29) & 1)) goto L_a4238;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa4214ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a4230;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a4230;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa4230ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a4230:
    cpu->regs[20] = 0ULL;
    goto L_a42cc;
L_a4238:
    cpu->regs[1] = 26024ULL;
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa4244ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a4260;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a42b0;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_a42b0;
L_a4260:
    cpu->regs[30] = PB_BASE + 0xa4264ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a42b0;
    cpu->regs[30] = PB_BASE + 0xa426cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a42b0;
    cpu->regs[0] = 26024ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa4288ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a42ac;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a42b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a42b0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa42a8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a42b0;
L_a42ac:
    cpu->regs[20] = cpu->regs[21];
L_a42b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a42cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a42cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa42ccULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a42cc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = 27464ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xa4308ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xed3ccULL);
    if ((cpu->regs[0])==0) goto L_a43b8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 29) & 1)) goto L_a433c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa4338ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a4398;
L_a433c:
    if ((cpu->regs[19])==0) goto L_a4358;
    cpu->regs[3] = 26024ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa4350ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_a4398;
L_a4358:
    cpu->regs[1] = 26024ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa4364ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x197f6cULL);
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a4398;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa437cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a4398;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3104ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa4398ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_a4398:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a43bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a43bc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa43b4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a43bc;
L_a43b8:
    cpu->regs[19] = 4294967295ULL;
L_a43bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
