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

void ft_PyVectorcall_Call(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    cpu->regs[4] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 8));
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa62fcULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[7] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_a6354;
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[6] = cpu->regs[5] + cpu->regs[1];
    cpu->regs[2] = SP;
    FLAG_CMP(cpu->regs[6], cpu->regs[2]);
    if (FLAG_LS) goto L_a6330;
    cpu->regs[8] = SP + 8ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[8]);
    if (FLAG_LO) goto L_a6344;
L_a6330:
    FLAG_CMP(cpu->regs[6], cpu->regs[2]);
    if (FLAG_HS) goto L_a6348;
    cpu->regs[6] = cpu->regs[6] + 8ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[6]);
    if (FLAG_HS) goto L_a6348;
L_a6344:
    __builtin_trap();
L_a6348:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + cpu->regs[1]));
    PB_STR((SP + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6388;
L_a6354:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[7] + 24));
    cpu->regs[2] = cpu->regs[2] + 3384ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa6370ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x225d40ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a63b4;
    goto L_a63b0;
L_a6388:
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[6]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[6] = 0ULL;
    if (FLAG_NE) goto L_a63b0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 32));
    SP = SP + 48ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x1267a4ULL); return; };
L_a63b0:
    cpu->regs[30] = PB_BASE + 0xa63b4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a63b4:
    PB_LDR(cpu->regs[19], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_a63c8:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[0])!=0) goto L_a63f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa63f4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a6420;
L_a63f8:
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa6404ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a6428;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa6420ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_a6420:
    cpu->regs[20] = 0ULL;
    goto L_a6450;
L_a6428:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6430ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x208e6cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6450;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6450;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6450ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6450:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 47592ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa6490ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xa63c8ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_a64d4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a64b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a64b8;
    cpu->regs[30] = PB_BASE + 0xa64b8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a64b8:
    cpu->regs[0] = 47592ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_a63c8;
L_a64d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 39328ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa6510ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xa63c8ULL);
    if ((cpu->regs[0])!=0) goto L_a6520;
    cpu->regs[30] = PB_BASE + 0xa6518ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_a653c;
L_a6520:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6538;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6538;
    cpu->regs[30] = PB_BASE + 0xa6538ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6538:
    cpu->regs[20] = 0ULL;
L_a653c:
    cpu->regs[0] = 39328ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa6550ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xa63c8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[20])==0) goto L_a6584;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6560ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    if ((cpu->regs[19])==0) goto L_a6580;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a6580;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a6580;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6580ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6580:
    cpu->regs[19] = 0ULL;
L_a6584:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = 60928ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[3] = 54760ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = 44840ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 60984ULL;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 54920ULL;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 54864ULL;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 54712ULL;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 53456ULL;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_a63c8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 54664ULL;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_a63c8;
}
